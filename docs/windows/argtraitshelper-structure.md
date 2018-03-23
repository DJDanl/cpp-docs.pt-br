---
title: Estrutura ArgTraitsHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::ArgTraitsHelper
dev_langs:
- C++
helpviewer_keywords:
- ArgTraitsHelper structure
ms.assetid: e3f798da-0aef-4a57-95d3-d38c34c47d72
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4df7e9fe3823e3dbb84b09863e6de5178ab44d18
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="argtraitshelper-structure"></a>Estrutura ArgTraitsHelper
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename TDelegateInterface>  
struct ArgTraitsHelper;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TDelegateInterface`  
 Uma interface de delegado.  
  
## <a name="remarks"></a>Comentários  
 Ajuda a define as características comuns dos argumentos do delegado.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`methodType`|Um sinônimo de `decltype(&TDelegateInterface::Invoke)`.|  
|`Traits`|Um sinônimo de `ArgTraits<methodType>`.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante ArgTraitsHelper::args](../windows/argtraitshelper-args-constant.md)|Ajuda a [argtraits:: args](../windows/argtraits-args-constant.md) manter a contagem do número de parâmetros no método Invoke de uma interface de delegado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ArgTraitsHelper`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)