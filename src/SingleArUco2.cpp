// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  SingleArUco2.cpp
 * @brief Single ArUco RT Component for RTM2.0
 *
 */
// </rtc-template>

#include "SingleArUco2.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const singlearuco2_spec[] =
#else
static const char* singlearuco2_spec[] =
#endif
  {
    "implementation_id", "SingleArUco2",
    "type_name",         "SingleArUco2",
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
SingleArUco2::SingleArUco2(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_InImageIn("InImage", m_InImage),
    m_OutImageOut("OutImage", m_OutImage),
    m_ArUco2DPoseOut("ArUco2DPose", m_ArUco2DPose),
    m_ArUco3DPoseOut("ArUco3DPose", m_ArUco3DPose)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SingleArUco2::~SingleArUco2()
{
}



RTC::ReturnCode_t SingleArUco2::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("InImage", m_InImageIn);
  
  // Set OutPort buffer
  addOutPort("OutImage", m_OutImageOut);
  addOutPort("ArUco2DPose", m_ArUco2DPoseOut);
  addOutPort("ArUco3DPose", m_ArUco3DPoseOut);

  
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

RTC::ReturnCode_t SingleArUco2::onActivated(RTC::UniqueId /*ec_id*/)
{
  //Set dictionary based on configuration parameter
  if(m_Dictionary=="ORIGINAL")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
  }
  else if(m_Dictionary=="4x4_50")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
  }
  else if(m_Dictionary=="4x4_100")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_100);
  }
  else if(m_Dictionary=="4x4_250")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
  }
  else if(m_Dictionary=="4x4_1000")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_1000);
  }
  else if(m_Dictionary=="5x5_50")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_50);
  }
  else if(m_Dictionary=="5x5_100")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_100);
  }
  else if(m_Dictionary=="5x5_250")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_250);
  }
  else if(m_Dictionary=="5x5_1000")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_5X5_1000);
  }
  else if(m_Dictionary=="6x6_50")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_50);
  }
  else if(m_Dictionary=="6x6_100")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_100);
  }
  else if(m_Dictionary=="6x6_250")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  }
  else if(m_Dictionary=="6x6_1000")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_1000);
  }
  else if(m_Dictionary=="7x7_50")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_50);
  }
  else if(m_Dictionary=="7x7_100")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_100);
  }
  else if(m_Dictionary=="7x7_250")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_250);
  }
  else if(m_Dictionary=="7x7_1000")
  {
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_1000);
  }

  return RTC::RTC_OK;
}


RTC::ReturnCode_t SingleArUco2::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SingleArUco2::onExecute(RTC::UniqueId /*ec_id*/)
{
  //Data received check for InPort
  if(m_InImageIn.isNew())
  {
    m_InImageIn.read();

    image_width=m_InImage.data.image.width;
    image_height=m_InImage.data.image.height;
    nchannels=(m_InImage.data.image.format == Img::CF_GRAY) ? 1 :
			(m_InImage.data.image.format == Img::CF_RGB || m_InImage.data.image.format == Img::CF_PNG || m_InImage.data.image.format == Img::CF_JPEG) ? 3 :
	    (m_InImage.data.image.raw_data.length()/image_width/image_height);
    if(nchannels==3)
	    image.create(image_height,image_width,CV_8UC3);
    else
	    image.create(image_height,image_width,CV_8UC1);

    long data_length=m_InImage.data.image.raw_data.length();

    if(m_InImage.data.image.format==Img::CF_RGB||m_InImage.data.image.format==Img::CF_GRAY)
	  {
	    for(int i=0;i<image_height;++i)
	    {
	      memcpy(&image.data[i*image.step],&m_InImage.data.image.raw_data[i*image_width*nchannels],sizeof(unsigned char)*image_width*nchannels);
	    }
	    if(nchannels==3)
	    {
	      cv::cvtColor(image,image,cv::COLOR_RGB2BGR);
	    }
	  }
    else if(m_InImage.data.image.format==Img::CF_JPEG||m_InImage.data.image.format==Img::CF_PNG)
	  {
	    std::vector<uchar> compressed_image=std::vector<uchar>(data_length);
	    memcpy(&compressed_image[0], &m_InImage.data.image.raw_data[0], sizeof(unsigned char) * data_length);

      cv::Mat decode_image;
	    if(nchannels==3)
	    {
	      decode_image=cv::imdecode(cv::Mat(compressed_image),cv::IMREAD_COLOR);
	      cv::cvtColor(decode_image,image,cv::COLOR_RGB2BGR);
	    }
	    else
	    {
	      decode_image=cv::imdecode(cv::Mat(compressed_image),cv::IMREAD_GRAYSCALE);
	      image=decode_image;
	    }
	  }

    std::vector<cv::Vec3d> rvecs,tvecs;
      
    CameraParam.at<float>(0,0)=m_InImage.data.intrinsic.matrix_element[0];
    CameraParam.at<float>(0,2)=m_InImage.data.intrinsic.matrix_element[1];
    CameraParam.at<float>(1,1)=m_InImage.data.intrinsic.matrix_element[2];
    CameraParam.at<float>(1,2)=m_InImage.data.intrinsic.matrix_element[3];
    CameraParam.at<float>(2,2)=1;

    int distCoeffs_length=m_InImage.data.intrinsic.distortion_coefficient.length();
    distCoeffs=cv::Mat::zeros(1,distCoeffs_length,CV_32F);
	  for(int i=0;i<distCoeffs_length;i++)
	  {
	    distCoeffs.at<float>(0,i)=(float)m_InImage.data.intrinsic.distortion_coefficient[i];
	  }

  	//出力データポート用にカメラパラメータを格納
    m_OutImage.data.intrinsic.matrix_element[0]=m_InImage.data.intrinsic.matrix_element[0];
	  m_OutImage.data.intrinsic.matrix_element[1]=m_InImage.data.intrinsic.matrix_element[1];
	  m_OutImage.data.intrinsic.matrix_element[2]=m_InImage.data.intrinsic.matrix_element[2];
	  m_OutImage.data.intrinsic.matrix_element[3]=m_InImage.data.intrinsic.matrix_element[3];
	  m_OutImage.data.intrinsic.matrix_element[4]=1;

	  m_OutImage.data.intrinsic.distortion_coefficient.length(distCoeffs_length);
	  for(int i=0;i<distCoeffs_length;i++)
	  {
	    distCoeffs.at<float>(0,i)=(float)m_InImage.data.intrinsic.distortion_coefficient[i];
	    m_OutImage.data.intrinsic.distortion_coefficient[i]=m_InImage.data.intrinsic.distortion_coefficient[i];
	  }
	
    /////////////////////////////////////////////////////////////////
    //Main procedure for ArUco marker detection
    /////////////////////////////////////////////////////////////////
    //Actually, the parameter "distCoeffs" should be set on the detectMarkers. However, received image has already modified based on distCoeffs.
    cv::aruco::detectMarkers(image,dictionary,markerCorners,markerIds,parameters,rejectedCandidates/*,CameraParam,distCoeffs*/);
	  cv::aruco::drawDetectedMarkers(image,markerCorners,markerIds);
	  cv::aruco::estimatePoseSingleMarkers(markerCorners,m_MarkerSize,CameraParam,distCoeffs,rvecs,tvecs);

	  //出力時の動的配列の長さを確保
	  m_ArUco2DPose.ids.length(markerIds.size());
	  m_ArUco2DPose.markerCorners.length(markerIds.size());
	  m_ArUco3DPose.ids.length(markerIds.size());
	  m_ArUco3DPose.rotations.length(markerIds.size());
	  m_ArUco3DPose.translates.length(markerIds.size());
	
    //Store the 2D and 3D pose for corresponding data port
	  if(markerIds.size()>0)
	  {
	    for(int i=0;i<markerIds.size();i++)
	    {
		    cv::aruco::drawAxis(image,CameraParam,distCoeffs,rvecs[i],tvecs[i],0.1);
		    cv::Mat RMat=cv::Mat::zeros(3,3,CV_32F);
		    cv::Rodrigues(rvecs[i],RMat);
		    m_ArUco2DPose.ids[i]=markerIds[i];
		    m_ArUco3DPose.ids[i]=markerIds[i];

		    m_ArUco2DPose.markerCorners[i].point1.x=markerCorners[i][0].x;
		    m_ArUco2DPose.markerCorners[i].point1.y=markerCorners[i][0].y;
		    m_ArUco2DPose.markerCorners[i].point2.x=markerCorners[i][1].x;
		    m_ArUco2DPose.markerCorners[i].point2.y=markerCorners[i][1].y;
		    m_ArUco2DPose.markerCorners[i].point3.x=markerCorners[i][2].x;
		    m_ArUco2DPose.markerCorners[i].point3.y=markerCorners[i][2].y;
		    m_ArUco2DPose.markerCorners[i].point4.x=markerCorners[i][3].x;
		    m_ArUco2DPose.markerCorners[i].point4.y=markerCorners[i][3].y;

		    m_ArUco3DPose.rotations[i].R11=(double)RMat.at<float>(0,0);
		    m_ArUco3DPose.rotations[i].R12=(double)RMat.at<float>(0,1);
		    m_ArUco3DPose.rotations[i].R13=(double)RMat.at<float>(0,2);
		    m_ArUco3DPose.rotations[i].R21=(double)RMat.at<float>(1,0);
		    m_ArUco3DPose.rotations[i].R22=(double)RMat.at<float>(1,1);
		    m_ArUco3DPose.rotations[i].R23=(double)RMat.at<float>(1,2);
		    m_ArUco3DPose.rotations[i].R31=(double)RMat.at<float>(2,0);
		    m_ArUco3DPose.rotations[i].R32=(double)RMat.at<float>(2,1);
		    m_ArUco3DPose.rotations[i].R33=(double)RMat.at<float>(2,2);
		    m_ArUco3DPose.translates[i].x=(double)tvecs[i][0];
		    m_ArUco3DPose.translates[i].y=(double)tvecs[i][1];
		    m_ArUco3DPose.translates[i].z=(double)tvecs[i][2];
	    }
	    m_ArUco2DPoseOut.write();
	    m_ArUco3DPoseOut.write();
	  }
	
    //desplay the obtained image
    if(!image.empty())
	  {
	    m_OutImage.data.image.width=image_width;
	    m_OutImage.data.image.height=image_height;
	    m_OutImage.data.image.raw_data.length(image_width*image_height*nchannels);
	  
	    if(nchannels==3)
	    {
	      m_OutImage.data.image.format=Img::CF_RGB;	  
	      cv::cvtColor(image,image,cv::COLOR_RGB2BGR);
	  
	    }
	    else
	    {
	      m_OutImage.data.image.format=Img::CF_GRAY;
	    }
	    for( int i(0); i< image_height; ++i )
	    {
	      memcpy(&m_OutImage.data.image.raw_data[ i * image_width * nchannels], &image.data[ i * image.step ], image_width * nchannels);
	    }
	  }
    m_OutImageOut.write();
  }

  return RTC::RTC_OK;
}

extern "C"
{
 
  void SingleArUco2Init(RTC::Manager* manager)
  {
    coil::Properties profile(singlearuco2_spec);
    manager->registerFactory(profile,
                             RTC::Create<SingleArUco2>,
                             RTC::Delete<SingleArUco2>);
  }
  
}
