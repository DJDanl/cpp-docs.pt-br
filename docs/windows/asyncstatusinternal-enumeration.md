---
title: "Enumeração AsyncStatusInternal | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::AsyncStatusInternal
dev_langs:
- C++
helpviewer_keywords:
- AsyncStatusInternal enumeration
ms.assetid: b783923f-3f1c-4487-9384-be572cbc62d7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bd277fecb0bc63d5ee823af98df8aa298b285964
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncstatusinternal-enumeration"></a>Enumeração AsyncStatusInternal
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum AsyncStatusInternal;  
```  
  
## <a name="remarks"></a>Comentários  
 Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o **Windows::Foundation::AsyncStatus** enumeração.  
  
## <a name="members"></a>Membros  
 `_Created`  
 Equivalente a:: Windows::Foundation::AsyncStatus:: criado  
  
 `_Started`  
 Equivalente a:: Windows::Foundation::AsyncStatus:: Introdução  
  
 `_Completed`  
 Equivalente a:: Windows::Foundation::AsyncStatus:: concluída  
  
 `_Cancelled`  
 Equivalente a:: Windows::Foundation::AsyncStatus:: cancelada  
  
 `_Error`  
 Equivalente a:: Windows::Foundation::AsyncStatus::Error  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)