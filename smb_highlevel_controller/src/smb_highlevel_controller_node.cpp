#include <ros/ros.h>
#include "smb_highlevel_controller/SmbHighlevelController.hpp"

int main(int argc, char** argv) {

  /* A função ros::init() precisa ver argc e argv para que possa executar 
  quaisquer argumentos ROS e remapeamento de nomes que foram fornecidos na linha de comando. 
  Para remapeamentos programáticos você pode usar uma versão diferente de init() que leva 
  remapeamentos diretamente, mas para a maioria dos programas de linha de comando, passar argc e argv é 
  a maneira mais fácil de fazer isso. O terceiro argumento para init() é o nome do nó.  
  Você deve chamar uma das versões de ros::init() antes de usar qualquer outra 
  parte do sistema ROS. 
  */ 
  ros::init(argc, argv, "smb_highlevel_controller");

  smb_highlevel_controller::SmbHighlevelController SmbHighlevelController();
  
  ros::spin();
  return 0;
}
