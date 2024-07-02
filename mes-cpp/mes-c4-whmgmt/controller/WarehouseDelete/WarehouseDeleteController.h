#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xinye
 @Date: 2024/5/22 23:00:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _WAREHOUSE_DELETE_CONTROLLER_
#define _WAREHOUSE_DELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/WarehouseDelete/WarehouseDeleteDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen oatpp::List<UInt64>

/**
 * 删除单据（支持批量删除）
 */
class WarehouseDeleteController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(WarehouseDeleteController);
    // 3 定义接口
public:

    // 3.1 定义修改接口描述，审批通过
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("wm_item_recpt.delete.summary"), removeWmItemRecpt, Uint64JsonVO::Wrapper);
    // 3.2 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/whmgmt/purchase/delete2/{recpt_id}", removeWmItemRecpt, BODY_DTO(WarehouseDeleteDTO::Wrapper, dto), execWarehouseDelete(dto));

private:

    // 3.3 演示删除数据
    Uint64JsonVO::Wrapper execWarehouseDelete(const WarehouseDeleteDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WAREHOUSE_DELETE_CONTROLLER_