---
title: 'Método Synclockt: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::IsLocked
dev_langs:
- C++
helpviewer_keywords:
- IsLocked method
ms.assetid: a81fea43-f99a-4708-812a-7fd6af500d3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 067b3763e10b2bbb310b213f7d748e953ba2a902
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33888469"
---
# <a name="synclocktislocked-method"></a>Método SyncLockT::IsLocked
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
bool IsLocked() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se o objeto SyncLockT estiver bloqueada; caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 Indica se o objeto SyncLockT atual possui um recurso. ou seja, é o objeto SyncLockT *bloqueado*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockT](../windows/synclockt-class.md)