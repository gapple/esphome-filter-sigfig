
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_ACCURACY,
)
from esphome.components.sensor import FILTER_REGISTRY

sensor_ns = cg.esphome_ns.namespace("sensor")
RoundSigfigFilter = sensor_ns.class_("RoundSigfigFilter", Filter)

@FILTER_REGISTRY.register(
    "round_to_sigfig",
    RoundSigfigFilter,
    cv.maybe_simple_value(
        {
            cv.Required(CONF_ACCURACY): cv.positive_not_null_int,
        },
        key=CONF_ACCURACY,
    ),
)

async def round_sigfig_filter_to_code(config, filter_id):
    return cg.new_Pvariable(
        filter_id,
        config[CONF_ACCURACY],
    )
