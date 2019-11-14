const express = require("express");
const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

// Connection URL
const url = 'mongodb://localhost:27017';

// Database Name
const dbName = 'followifier';

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

// Use connect method to connect to the Server


app.route('/api/boards').get((req, res) => {
  var resultArray = [];
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
})
