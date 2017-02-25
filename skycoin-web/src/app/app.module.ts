import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { HttpModule } from '@angular/http';
import { RouterModule } from '@angular/router';

import { AppComponent } from './app.component';

import { SkycoinHeaderComponent } from './components/skycoin-header/skycoin-header.component';
import { BlockChainTableComponent } from './components/block-chain-table/block-chain-table.component';
import { SkycoinPaginationComponent } from './components/skycoin-pagination/skycoin-pagination.component';
import { SkycoinSearchBarComponent } from './components/skycoin-search-bar/skycoin-search-bar.component';
import {BlockChainService} from "./components/block-chain-table/block-chain.service";
import { FooterComponent } from './components/footer/footer.component';
import { NumPagesPipe } from './components/skycoin-pagination/num-pages.pipe';
import {SkycoinBlockchainPaginationService} from "./components/skycoin-pagination/skycoin-blockchain-pagination.service";
import {CommonModule} from "@angular/common";
import {MomentModule} from "angular2-moment";
import { BlockDetailsComponent } from './components/block-details/block-details.component';


const ROUTES = [
  {
    path: '',
    redirectTo: 'blocks',
    pathMatch: 'full'
  },
  {
    path: 'blocks',
    component: BlockChainTableComponent
  },
  {
    path: 'block/:id',
    component: BlockDetailsComponent
  }
];

@NgModule({
  declarations: [
    AppComponent,
    SkycoinHeaderComponent,
    BlockChainTableComponent,
    SkycoinPaginationComponent,
    SkycoinSearchBarComponent,
    FooterComponent,
    NumPagesPipe,
    BlockDetailsComponent
  ],
  imports: [
    CommonModule,
    BrowserModule,
    FormsModule,
    HttpModule,
    MomentModule,
    RouterModule.forRoot(ROUTES)
  ],
  providers: [BlockChainService,SkycoinBlockchainPaginationService],
  bootstrap: [AppComponent]
})
export class AppModule { }