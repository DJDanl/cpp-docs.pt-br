---
title: Enumeração AsyncStatusInternal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::Details::AsyncStatusInternal
dev_langs:
- C++
helpviewer_keywords:
- AsyncStatusInternal enumeration
ms.assetid: b783923f-3f1c-4487-9384-be572cbc62d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 150169442aa68395b4dc8a4f4c74951e877f18f5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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