#pragma once
#ifndef PCH_H
#define PCH_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <optional>
#include <set>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <map> 
#include <array>
#include <chrono>
#include <math.h>
#include <cstdarg>
#include <unordered_map>
#include <memory>

#endif //!PCH_H