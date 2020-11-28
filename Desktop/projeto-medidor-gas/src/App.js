import React, {Component} from 'react';
import Navigation from './components/Navigation'
import Card from './components/Card'
import './App.css';
import MyChart from './components/MyChart.js'
import GasPage from './components/GasPage';
import {optionsCO, optionsCO2, optionsO3, optionsNO2, optionsSO2} from './All_ops'

// console.log('Options = ', optionsCO);

class App extends Component{
  constructor(){
    super();
    this.state = {
      route: 'home',
    }
  }

  onRouteChange = (place) => {
    this.setState({route:place})
  }

  renderElement(){
    if (this.state.route === 'home'){
      return(
      <div>
        <div className = "AllCards">
          <Card 
            title={'CO'} 
            ppmValue = {200} 
          />
          <Card 
            title={'CO2'} 
            ppmValue = {200} 
          />
          <Card 
            title={'O3'} 
            ppmValue = {200} 
          />
            <Card 
            title={'NO2'} 
            ppmValue = {200} 
          />
            <Card 
            title={'SH2'} 
            ppmValue = {200} 
          />
        </div>
        <div className = "Live">
          <MyChart
            options = {optionsCO}
          />
          <MyChart
            options = {optionsCO2}
          />
          <MyChart
            options = {optionsO3}
          />
          <MyChart  
            options = {optionsNO2}
          />
         <MyChart
            options = {optionsSO2}
        />
        </div>
      </div>
      )
    }
    else if(this.state.route === 'co'){
      return(
        <div>
          <GasPage 
            ppmValue = {700}
            ugmValue = {300}
            opt = {optionsCO}
          />
        </div>
      )
    }
    else if(this.state.route === 'co2'){
      return(
        <div>
          <GasPage 
            ppmValue = {100}
            ugmValue = {300}
            opt = {optionsCO2}
          />
        </div>
      )
    }
    else if(this.state.route === 'o3'){
      return(
        <div>
          <GasPage 
            ppmValue = {100}
            ugmValue = {300}
            opt = {optionsO3}
          />
        </div>
      )
    }
    else if(this.state.route === 'no2'){
      return(
        <div>
          <GasPage 
            ppmValue = {100}
            ugmValue = {300}
            opt = {optionsNO2}
          />
        </div>
      )
    }
    else if(this.state.route === 'so2'){
      return(
        <div>
          <GasPage 
            ppmValue = {100}
            ugmValue = {300}
            opt = {optionsSO2}
          />
        </div>
      )
    }
 }

  render(){
    return (
      <div className = "App" >
      <Navigation onRouteChange = {this.onRouteChange}/>
      { this.renderElement() }
    </div>
    )
  } 
}

export default App;
