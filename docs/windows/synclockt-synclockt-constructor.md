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
ms.openlocfilehash: c3353df1a73821a2009aeba2367f1892b06aba5b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889832"
---
# <a name="synclocktsynclockt-constructor"></a>Construtor SyncLockT::SyncLockT
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLockT(  
   _Inout_ SyncLockT&& other  
);  
  
explicit SyncLockT(  
   typename SyncTraits::Type sync = SyncTraits::GetInvalidValue()  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `other`  
 Uma referência rvalue a outro objeto SyncLockT.  
  
 `sync`  
 Uma referência a outro objeto SyncLockWithStatusT.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância da classe SyncLockT.  
  
 O primeiro construtor inicializa o objeto SyncLockT atual de outro objeto SyncLockT especificado pelo parâmetro `other`e, em seguida, invalida o outro objeto SyncLockT. É o segundo construtor `protected`e inicializa o objeto SyncLockT atual para um estado inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockT](../windows/synclockt-class.md)