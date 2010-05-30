// MESSAGE GPS_POSITION PACKING

#define MAVLINK_MSG_ID_GPS_POSITION 32

typedef struct __mavlink_gps_position_t 
{
	uint64_t usec; ///< Timestamp (microseconds since unix epoch)
	float lat; ///< X Position
	float lon; ///< Y Position
	float alt; ///< Z Position
	float vx; ///< X Speed
	float vy; ///< Y Speed
	float vz; ///< Z Speed

} mavlink_gps_position_t;



/**
 * @brief Send a gps_position message
 *
 * @param usec Timestamp (microseconds since unix epoch)
 * @param lat X Position
 * @param lon Y Position
 * @param alt Z Position
 * @param vx X Speed
 * @param vy Y Speed
 * @param vz Z Speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, float lat, float lon, float alt, float vx, float vy, float vz)
{
	msg->msgid = MAVLINK_MSG_ID_GPS_POSITION;
	uint16_t i = 0;

	i += put_uint64_t_by_index(usec, i, msg->payload); //Timestamp (microseconds since unix epoch)
	i += put_float_by_index(lat, i, msg->payload); //X Position
	i += put_float_by_index(lon, i, msg->payload); //Y Position
	i += put_float_by_index(alt, i, msg->payload); //Z Position
	i += put_float_by_index(vx, i, msg->payload); //X Speed
	i += put_float_by_index(vy, i, msg->payload); //Y Speed
	i += put_float_by_index(vz, i, msg->payload); //Z Speed

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_gps_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_position_t* gps_position)
{
	return mavlink_msg_gps_position_pack(system_id, component_id, msg, gps_position->usec, gps_position->lat, gps_position->lon, gps_position->alt, gps_position->vx, gps_position->vy, gps_position->vz);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_position_send(mavlink_channel_t chan, uint64_t usec, float lat, float lon, float alt, float vx, float vy, float vz)
{
	mavlink_message_t msg;
	mavlink_msg_gps_position_pack(mavlink_system.sysid, mavlink_system.compid, &msg, usec, lat, lon, alt, vx, vy, vz);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE GPS_POSITION UNPACKING

/**
 * @brief Get field usec from gps_position message
 *
 * @return Timestamp (microseconds since unix epoch)
 */
static inline uint64_t mavlink_msg_gps_position_get_usec(const mavlink_message_t* msg)
{
	generic_64bit r;
	r.b[7] = (msg->payload)[0];
	r.b[6] = (msg->payload)[1];
	r.b[5] = (msg->payload)[2];
	r.b[4] = (msg->payload)[3];
	r.b[3] = (msg->payload)[4];
	r.b[2] = (msg->payload)[5];
	r.b[1] = (msg->payload)[6];
	r.b[0] = (msg->payload)[7];
	return (uint64_t)r.ll;
}

/**
 * @brief Get field lat from gps_position message
 *
 * @return X Position
 */
static inline float mavlink_msg_gps_position_get_lat(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t))[3];
	return (float)r.f;
}

/**
 * @brief Get field lon from gps_position message
 *
 * @return Y Position
 */
static inline float mavlink_msg_gps_position_get_lon(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field alt from gps_position message
 *
 * @return Z Position
 */
static inline float mavlink_msg_gps_position_get_alt(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field vx from gps_position message
 *
 * @return X Speed
 */
static inline float mavlink_msg_gps_position_get_vx(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field vy from gps_position message
 *
 * @return Y Speed
 */
static inline float mavlink_msg_gps_position_get_vy(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field vz from gps_position message
 *
 * @return Z Speed
 */
static inline float mavlink_msg_gps_position_get_vz(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

static inline void mavlink_msg_gps_position_decode(const mavlink_message_t* msg, mavlink_gps_position_t* gps_position)
{
	gps_position->usec = mavlink_msg_gps_position_get_usec(msg);
	gps_position->lat = mavlink_msg_gps_position_get_lat(msg);
	gps_position->lon = mavlink_msg_gps_position_get_lon(msg);
	gps_position->alt = mavlink_msg_gps_position_get_alt(msg);
	gps_position->vx = mavlink_msg_gps_position_get_vx(msg);
	gps_position->vy = mavlink_msg_gps_position_get_vy(msg);
	gps_position->vz = mavlink_msg_gps_position_get_vz(msg);
}
