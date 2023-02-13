#include <rtm/ByteDataStreamBase.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <coil/Factory.h>
#include <rtm/Manager.h>
#include <geometry_msgs/Pose.h>
#include"../../build-linux/idl/ArUcoSkel.h"
//#include "../idl/ArUco.idl"
#include"ROSMessageInfo.h"
#include"ROSSerializer.h"

//以下はシリアライザの実装
class TestSerializer : public RTC::ROSSerializerBase<arUco::arUcoPose3D>
{
public:
    TestSerializer(){};

    
 
    bool serialize(const arUco::arUcoPose3D& data) override
    {
        if (data.translates.length()!=0)
        {   
            geometry_msgs::Pose msg;
            msg.position.x = data.translates[0].x; 
            msg.position.y = data.translates[0].y; 
            msg.position.z = data.translates[0].z; 
            ROSSerializerBase<arUco::arUcoPose3D>::m_message = ros::serialization::serializeMessage<geometry_msgs::Pose>(msg);
            return true;
        }
    }
    bool deserialize(arUco::arUcoPose3D& data) override
{
    geometry_msgs::Pose msg;
    ros::serialization::deserializeMessage(ROSSerializerBase<arUco::arUcoPose3D>::m_message, msg);
    data.translates.length(1);
    data.translates[0].x = msg.position.x; 
    data.translates[0].y = msg.position.y; 
    data.translates[0].z = msg.position.z; 
    
    return false;
}
private:

};

extern "C"
{
    //以下はモジュールロード時に呼び出される関数
    DLL_EXPORT void TestSerializerInit(RTC::Manager* manager)
    {
        //以下のファクトリはデータ型ごとに登録する必要がある
        RTC::addSerializer<arUco::arUcoPose3D,TestSerializer>("marker");
        //ROSTransportにROSに送るメッセージ型を提示する
        RTC::GlobalROSMessageInfoList:: instance().addInfo("marker", new RTC::ROSMessageInfo<geometry_msgs::Pose>()); 
    };
}