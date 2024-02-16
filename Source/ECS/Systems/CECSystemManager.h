#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include <vector>
#include "CollisionSystem/CCollisionSystem.h"
#include "MovementSystem/CMovementSystem.h"
#include "SpriteSystem/CSpriteSystem.h"
#include "CameraSystem/CCameraSystem.h"
#include "MotionSystem/CMotionSystem.h"
#include "KeyInputSystem/CKeyInputSystem.h"
#include "SpawnSystem/CSpawnSystem.h"


class CEntity;
class AScene;
class AECSystem;

class CECSystemManager
{
private:
    CECSystemManager();
    static CECSystemManager                    *s_instance;
    std::vector<AECSystem*>                    m_systems;

    CMovementSystem                            m_movement_system;
    CCameraSystem                              m_camera_system;
    CMotionSystem                              m_motion_system;
    CCollisionSystem                           m_collision_system;
    CSpriteSystem                              m_render_system;
    CKeyInputSystem                            m_key_input_system;
    CSpawnSystem                               m_spawn_system;

public:
    static CECSystemManager *instance();

    void init(std::vector<CEntity*> &entities);
    void update(std::vector<CEntity*> &entities, float dt);
};


#endif // CECSYSTEMMANAGER_H
