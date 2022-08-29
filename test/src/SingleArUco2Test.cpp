// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  SingleArUco2Test.cpp
 * @brief Single ArUco RT Component for RTM2.0 (test code)
 *
 */
// </rtc-template>

#include "SingleArUco2Test.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const singlearuco2_spec[] =
#else
static const char* singlearuco2_spec[] =
#endif
  {
    "implementation_id", "SingleArUco2Test",
    "type_name",         "SingleArUco2Test",
    "description",       "Single ArUco RT Component for RTM2.0",
    "version",           "1.0.0",
    "vendor",            "Robot System Design Laboratory, Meijo University",
    "category",          "ImageProcessing",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Dictionary", "ORIGINAL",
    "conf.default.MarkerSize", "0.05",

    // Widget
    "conf.__widget__.Dictionary", "radio",
    "conf.__widget__.MarkerSize", "text",
    // Constraints
    "conf.__constraints__.Dictionary", "(ORIGINAL,4x4_50,4x4_100,4x4_250,4x4_1000,5x5_50,5x5_100,5x5_250,5x5_1000,6x6_50,6x6_100,6x6_250,6x6_1000,7x7_50,7x7_100,7x7_250,7x7_1000)",

    "conf.__type__.Dictionary", "string",
    "conf.__type__.MarkerSize", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SingleArUco2Test::SingleArUco2Test(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_InImageOut("InImage", m_InImage),
    m_OutImageIn("OutImage", m_OutImage),
    m_ArUco2DPoseIn("ArUco2DPose", m_ArUco2DPose),
    m_ArUco3DPoseIn("ArUco3DPose", m_ArUco3DPose)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SingleArUco2Test::~SingleArUco2Test()
{
}



RTC::ReturnCode_t SingleArUco2Test::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("OutImage", m_OutImageIn);
  addInPort("ArUco2DPose", m_ArUco2DPoseIn);
  addInPort("ArUco3DPose", m_ArUco3DPoseIn);
  
  // Set OutPort buffer
  addOutPort("InImage", m_InImageOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Dictionary", m_Dictionary, "ORIGINAL");
  bindParameter("MarkerSize", m_MarkerSize, "0.05");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SingleArUco2Test::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t SingleArUco2Test::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SingleArUco2Test::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t SingleArUco2Test::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SingleArUco2Test::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SingleArUco2Test::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t SingleArUco2Test::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SingleArUco2Test::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SingleArUco2Test::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SingleArUco2Test::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t SingleArUco2Test::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool SingleArUco2Test::runTest()
{
    return true;
}


extern "C"
{
 
  void SingleArUco2TestInit(RTC::Manager* manager)
  {
    coil::Properties profile(singlearuco2_spec);
    manager->registerFactory(profile,
                             RTC::Create<SingleArUco2Test>,
                             RTC::Delete<SingleArUco2Test>);
  }
  
}
