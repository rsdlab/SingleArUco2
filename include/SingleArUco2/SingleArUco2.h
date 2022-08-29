// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  SingleArUco2.h
 * @brief Single ArUco RT Component for RTM2.0
 *
 */
// </rtc-template>

#ifndef SINGLEARUCO2_H
#define SINGLEARUCO2_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "CameraCommonInterfaceStub.h"
#include "ArUcoStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

//Additional include file for ArUco marker
#include<opencv2/opencv.hpp>
#include<opencv2/aruco.hpp>

// <rtc-template block="component_description">
/*!
 * @class SingleArUco2
 * @brief Single ArUco RT Component for RTM2.0
 *
 */
// </rtc-template>
class SingleArUco2
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  SingleArUco2(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~SingleArUco2() override;

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  // <rtc-template block="activity">
  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onInitialize() override;

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onFinalize() override;

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id) override;

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id) override;

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id) override;

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id) override;

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onError(RTC::UniqueId ec_id) override;

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onReset(RTC::UniqueId ec_id) override;
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id) override;

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id) override;
  // </rtc-template>


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  Dictionary
   * - DefaultValue: ORIGINAL
   */
  std::string m_Dictionary;
  /*!
   * 
   * - Name:  MarkerSize
   * - DefaultValue: 0.05
   */
  double m_MarkerSize;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  Img::TimedCameraImage m_InImage;
  /*!
   */
  RTC::InPort<Img::TimedCameraImage> m_InImageIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  Img::TimedCameraImage m_OutImage;
  /*!
   */
  RTC::OutPort<Img::TimedCameraImage> m_OutImageOut;
  arUco::arUcoPoint2D m_ArUco2DPose;
  /*!
   */
  RTC::OutPort<arUco::arUcoPoint2D> m_ArUco2DPoseOut;
  arUco::arUcoPose3D m_ArUco3DPose;
  /*!
   */
  RTC::OutPort<arUco::arUcoPose3D> m_ArUco3DPoseOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>


 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>
  // <rtc-template block="private_attribute">
  int image_width;  //Image width
  int image_height; //Image height
  int nchannels;    //channels
  cv::Mat image;    
  std::vector<int> markerIds;
  std::vector<std::vector<cv::Point2f> >markerCorners, rejectedCandidates;//カメラ内のマーカのコーナ
  cv::Mat CameraParam=cv::Mat::zeros(3,3,CV_32F);
  cv::Mat distCoeffs;
  
  cv::Ptr<cv::aruco::DetectorParameters> parameters=cv::aruco::DetectorParameters::create();
  cv::Ptr<cv::aruco::Dictionary> dictionary;
};


extern "C"
{
  DLL_EXPORT void SingleArUco2Init(RTC::Manager* manager);
};

#endif // SINGLEARUCO2_H
