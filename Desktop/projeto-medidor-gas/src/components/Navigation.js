import React from 'react'

const Navigation = ({onRouteChange}) => {  
        return(
             <nav className = 'flex w-100' style = {{background: '#00AA34'}}>
               <p onClick={() => onRouteChange('home')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    Inicio
                </p>
                <p onClick={() => onRouteChange('co')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    CO
                </p>
                <p onClick={() => onRouteChange('co2')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    CO2
                </p>
                <p onClick={() => onRouteChange('o3')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    O3
                </p>
                <p onClick={() => onRouteChange('no2')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    NO2
                </p>
                <p onClick={() => onRouteChange('so2')}
                    className='f4 dim link black underline mt1 mb0 ml1 pr2 pt1 pb1 pointer b'>
                    SO2
                </p>
            </nav>  
        )    
}

export default Navigation;