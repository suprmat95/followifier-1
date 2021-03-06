const express = require("express");
const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

// Connection URL
const url = 'mongodb://localhost:27017';

// Database Name
const dbName = 'followifier';

// Number of devices time interval (in seconds)
const numDevicesTimeInterval = 1 * 60;

// Time window within which devices must be shown in the radar (scatter chart) (in seconds)
const devicesRadarTimeWindows = 1 * 60;

const app = express();


app.listen(8000, () => {
  console.log('Server started!')
})
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});


// Create a new MongoClient
const client = new MongoClient(url);

app.route('/api/device/number').get((req, res) => {
  var resultArray = [];
  client.connect(function (err) {
    assert.equal(null, err);

    let date = Date.now()/1000;
    date = parseInt(date);
    const db = client.db(dbName);
    var coll = db.collection("messages");
    //I first aggregate by mac and time window of 10 seconds and then I aggregate by mac and count the number of windows it appeared in
    coll.aggregate([
      {$match:{timestamp:{$gte:date-numDevicesTimeInterval*5}}},
      {$group:{_id:{
        "interval":
          {
            "$subtract":[
              { "$toLong": {"$toDate": "$timestamp"} },
              { "$mod": [{"$toLong": {"$toDate": "$timestamp"}}, numDevicesTimeInterval] }
            ]
          },
        "mac": "$mac"
      }}},
      {$group:{
        _id:{
          "mac": "$_id.mac"
        },
        count: {"$sum": 1}
      }}]).toArray(function (err, result) {
  if (err) {
    res.send(err);
  } else {
    let count = 0;
    result.forEach(r=> {
      if(r.count==5)
        count++;
    });
    console.log(result);
    res.send(JSON.stringify({number: count}))
  }
  })
  });
});

app.route('/api/devices').get((req, res) => {
  var resultArray = [];
  client.connect(function (err) {
    assert.equal(null, err);

    let date = Date.now()/1000;
    date = parseInt(date);
    const db = client.db(dbName);
    var coll = db.collection("messages");
    coll.aggregate([
                    {$match:{timestamp:{$gt:date-devicesRadarTimeWindows}}},
                    {$group:{_id:"$mac",   x: {$avg: '$x'}, y: {$avg: '$y'}}},
                    {$sort: {_id: 1}},
                    ]).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        res.send(JSON.stringify(result));
      }
    })
  });
});
app.route('/api/devices/all').get((req, res) => {
  client.connect(function (err) {
    assert.equal(null, err);
    const db = client.db(dbName);
    var coll = db.collection("messages");
    coll.aggregate([
      {$group:{_id:"$mac"}},
      {$sort: {total: -1}},
    ]).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        console.log('devices: ' + JSON.stringify(result));
        res.send(JSON.stringify(result));
      }
    })
  });
});
app.route('/api/devices/historical').get((req, res)  => {
  client.connect(function (err) {
    assert.equal(null, err);
    let date = Date.now() / 1000;
    date = parseInt(date);
    const db = client.db(dbName);
    var coll = db.collection("messages");
    console.log(req.query.start)
    coll.aggregate([
      {$match: {timestamp: {$gt:  parseInt(req.query.start),$lt: parseInt(req.query.end)}}},
      {$unwind: "$mac"
      },
      {$group: {
        _id: {
          "mac": "$mac",
          "timestamp": "$timestamp"
        }
      }},
      {$group: {_id: "$_id.mac",  n: { $sum: 1}}},
      {$sort: {n: -1, _id: 1}},
    ]).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        res.send(JSON.stringify(result));
        console.log('de')
        console.log(result);
      }
    })
  });
});
app.route('/api/device/intervalls').get((req, res)  => {
  client.connect(function (err) {
    assert.equal(null, err);
    
    const db = client.db(dbName);
    var coll = db.collection("messages");
    console.log(req.query.start)
    coll.aggregate([
      {$match: {timestamp: {$gt:  parseInt(req.query.start),$lt: parseInt(req.query.end)}, mac: {$eq: req.query.mac}}},
      {$unwind: "$mac"
      },
      {$group: {
          _id: {
            "mac": "$mac",
            "timestamp": "$timestamp"
          }
        }},
      
    ]).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        res.send(JSON.stringify(result));
        console.log('de')
        console.log(result);
      }
    })
  });
});
app.route('/api/devices/position').get((req, res)  => {
  console.log('POSITION ' + req.query.mac);
  client.connect(function (err) {
    assert.equal(null, err);
    let date = Date.now() / 1000;
    date = parseInt(date);
    const db = client.db(dbName);
    var coll = db.collection("messages");
    coll.aggregate([
      {$match: {mac: {$eq: req.query.mac}}},
      {$group:{
        _id:"$timestamp",
        x: {$avg: '$x'}, y: {$avg: '$y'}
      }},
      {$sort: {_id: 1}},
    ]).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        console.log('devices: ' + JSON.stringify(result));
        res.send(JSON.stringify(result));
      }
    })
  });
});
app.route('/api/boards').get((req, res) => {
  client.connect(function(err) {
    assert.equal(null, err);
    console.log("Connected successfully to server db");
    const db = client.db(dbName);
    var coll = db.collection("boards")

    coll.find({}).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {

        res.send(JSON.stringify(result));
      }
    })
  });
});

app.route('/api/room').get((req, res) => {
  client.connect(function(err) {
    assert.equal(null, err);
    console.log("Connected successfully to server db");
    const db = client.db(dbName);
    var coll = db.collection("room")
    coll.find({}).toArray(function (err, result) {
      if (err) {
        res.send(err);
      } else {
        console.log('ROOM: ' + JSON.stringify(result));
        res.send(JSON.stringify(result));
      }
    })
  });
});
