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
ms.openlocfilehash: a68189c461453dc72585ff4034df5ba69bb41bd5
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464870"
---
# <a name="asyncstatusinternal-enumeration"></a>Enumeração AsyncStatusInternal
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
enum AsyncStatusInternal;  
```  
  
## <a name="remarks"></a>Comentários  
 Especifica um mapeamento entre enumerações internos para o estado das operações assíncronas e o `Windows::Foundation::AsyncStatus` enumeração.  
  
## <a name="members"></a>Membros  
 *Criados*  
 Equivalente a:: Windows::Foundation::AsyncStatus:: criado  
  
 *_Started*  
 Equivalente a:: Windows::Foundation::AsyncStatus:: iniciado  
  
 *_Completed*  
 Equivalente a:: Windows::Foundation::AsyncStatus:: concluída  
  
 *_Cancelled*  
 Equivalente a:: Windows::Foundation::AsyncStatus:: cancelada  
  
 *Erro*  
 Equivalente a:: Windows::Foundation::AsyncStatus::Error  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)