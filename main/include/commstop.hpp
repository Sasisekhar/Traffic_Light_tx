#ifndef COMMS_TOP_HPP
#define COMMS_TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "ME_tx.hpp"
#include "tcl.hpp"
#include "dll.hpp"

#ifndef RT_ESP32
using gpio_num_t = uint32_t;
#endif

namespace cadmium::comms {

    template<typename T>
    struct commstop : public Coupled {

        Port<T> in;
        Port<T> out;

        /**
         * Constructor function for the blinkySystem model.
         * @param id ID of the blinkySystem model.
         */
        commstop(const std::string& id) : Coupled(id) {
            in = this->template addInPort<T>("in");
            out = this->template addOutPort<T>("out");

            auto layer1 = addComponent<tcl<T>>("layer1");
            auto layer2 = addComponent<dll>("layer2");
            auto phy_tx = addComponent<ME_tx>("phy_tx", (gpio_num_t) 18, (uint32_t)80 * 1000 * 1000);

            addCoupling(in, layer1->upstream_in);
            addCoupling(layer1->downstream_out, layer2->upstream_in);
            addCoupling(layer2->downstream_out, phy_tx->in);
        }
    };
}

#endif