#ifndef SASI_TOP_HPP
#define SASI_TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "traffic_light.hpp"
#include "commstop.hpp"

namespace cadmium::comms::example {
    struct topSystem : public Coupled {

            /**
             * Constructor function for the blinkySystem model.
             * @param id ID of the blinkySystem model.
             */
            topSystem(const std::string& id) : Coupled(id) {
                auto atomic_1 = addComponent<traffic_light>("traffic_light");
                auto atomic_2 = addComponent<commstop<RGB>>("commstop_tx");

                addCoupling(atomic_1->out, atomic_2->in);
            }
        };
}

#endif