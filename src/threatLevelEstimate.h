#ifndef THREAT_LEVEL_ESTIMATE_H
#define THREAT_LEVEL_ESTIMATE_H

#include "Updatable.h"
#include <ecs/entity.h>
#include <functional>

class SpaceShip;
class ThreatLevelEstimate : public Updatable
{
private:
    typedef std::function<void()> func_t;

    static constexpr float threat_drop_off_time = 20.0f;
    static constexpr float threat_high_level = 700.0f;
    static constexpr float threat_low_level = 300.0f;

    float smoothed_threat_level;
    bool threat_high;

    func_t threat_low_func;
    func_t threat_high_func;
public:
    ThreatLevelEstimate();
    virtual ~ThreatLevelEstimate() = default;

    float getThreat() { return smoothed_threat_level; }
    void setCallbacks(func_t low, func_t high);

    virtual void update(float delta) override;
private:
    float getThreatFor(sp::ecs::Entity ship);
};

#endif//THREAT_LEVEL_ESTIMATE_H
