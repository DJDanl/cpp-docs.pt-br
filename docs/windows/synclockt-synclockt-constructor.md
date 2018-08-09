---
title: 'Construtor synclockt:: Synclockt | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockT::SyncLockT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockT, constructor
ms.assetid: 713dfd9f-7369-4d86-b4a0-8b32c184d89b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6d4ff3393e30e72bc3378837ff11c41927249d1f
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014177"
---
# <a name="synclocktsynclockt-constructor"></a>Construtor SyncLockT::SyncLockT
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
SyncLockT(  
   _Inout_ SyncLockT&& other  
);  
  
explicit SyncLockT(  
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *other*  
 Uma referência rvalue para outro **SyncLockT** objeto.  
  
 *sync*  
 Uma referência a outro `SyncLockWithStatusT` objeto.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância dos **SyncLockT** classe.  
  
 O primeiro construtor inicializa o atual **SyncLockT** objeto de outro **SyncLockT** objeto especificado pelo parâmetro *outros*e, em seguida, invalida as outras  **SyncLockT** objeto. É o segundo construtor **protegidos**e a inicializa atual **SyncLockT** objeto para um estado inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockT](../windows/synclockt-class.md)