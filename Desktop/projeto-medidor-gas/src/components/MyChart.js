import React from 'react'
import Highcharts from 'highcharts/highstock'
import HighchartsReact from 'highcharts-react-official'

const MyChart = ({options}) => 

<HighchartsReact
  highcharts = {Highcharts}
  constructorType = {'chart'}
  options = {options}
/>

export default MyChart