import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import { ClickOutsideModule } from 'ng-click-outside';
import {MatCardModule} from '@angular/material/card';
import { RouterModule } from '@angular/router';
import {AppRoutes} from './app.routes';
import {AppComponent} from './app.component';
import {StatsComponent} from './component/stats/stats.component';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {MatButtonModule} from '@angular/material/button';

import {MatSidenavModule} from '@angular/material/sidenav';
import {MatToolbarModule} from '@angular/material/toolbar';
import {MatListModule} from '@angular/material/list';

import {MatIconModule} from '@angular/material/icon';

import {HttpClientModule} from '@angular/common/http';
import { SidenavComponent } from './component/sidenav/sidenav.component';
import { ToolbarComponent } from './component/toolbar/toolbar.component';
import { HomeComponent } from './component/home/home.component';
import { ChartsModule } from 'ng2-charts';
import {ChartComponent} from './component/chart/chart.component';
@NgModule({
  declarations: [
    AppComponent,
    StatsComponent,
    SidenavComponent,
    ToolbarComponent,
    HomeComponent,
    ChartComponent
  ],
  imports: [
    BrowserModule,
    MatSidenavModule,
    MatIconModule,
    BrowserAnimationsModule,
    HttpClientModule,
    MatToolbarModule,
    MatListModule,
    MatButtonModule,
    MatCardModule,
    ClickOutsideModule,
    ChartsModule,
    RouterModule.forRoot(AppRoutes)
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
}
