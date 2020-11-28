import React from 'react'
import MyChart from './MyChart.js'
import CardsForGas from './CardsForGas'


const verify_sit = (ppmValue) =>{
    // console.log("ppmvalue = ", ppmValue);
    if(ppmValue < 600)
        return "OK";
    else
        return "NOT OK"
}

const GasPage = ({ppmValue, ugmValue, opt }) => {
    let a = ['Atual', 'Média','Máximo', 'Mínimo'];
    return(
    <div>
    <div className = "Live">
      <MyChart 
        options = {opt}
      />
      </div>
    <div className = "AllCards" style = {{margin: '0px 10px 0px'}}>
      {
        a.map((x) => {
            return(
            <CardsForGas 
                name = {x}
                ppmValue = {ppmValue}
                ugmValue = {ugmValue}
            />
            )
        })
      }
      <div className = "card br3 mt1 mb1 bw2 mr1 mr1 pl1 pr1">
        <div className="bg-light-yellow w-100 br3 mb0 dib v-mid">
            <h3>Situação:</h3>
            <div className = "indicative">
                {verify_sit(ppmValue)}   
            </div>
      </div>
      </div>
    </div>
    </div>
    )
}  
  
export default GasPage;