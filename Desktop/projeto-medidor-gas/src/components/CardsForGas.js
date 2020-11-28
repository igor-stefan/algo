import React from 'react'
import './Card.css'
import { TabLink, Tabs, TabContent } from 'react-tabs-redux'

const CardsForGas = ({name, ppmValue, ugmValue }) => {
    return(
      <div className="card br3 mt1 mb1 bw2 mr1 mr1 pl1 pr1">
            <div className="bg-light-yellow w-100 br3 mb0 dib v-mid">
                <h3>{name}</h3>
                <Tabs style = {{background: '#0898FD'}} className = "br3 br--bottom">
                  <TabLink to="tab1" className = "f5 w-50 br0 br pa2 button-a">PPM</TabLink>
                  <TabLink to="tab2" className = "f5 w-50 br0 bl pa2 button-a">ug/m³</TabLink>

                  <TabContent for="tab1" style = {{transition: '0.3s'}} className = "dib v-mid pa3">{ppmValue} PPM</TabContent>
                  <TabContent for="tab2" style = {{transition: '0.3s'}} className = "dib v-mid pa3">{ugmValue} ug/m³</TabContent>
                </Tabs>
                </div>              
        </div>
    )
}  
  
export default CardsForGas;