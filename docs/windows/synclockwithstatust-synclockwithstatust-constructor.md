---
title: 'Construtor synclockwithstatust:: Synclockwithstatust | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT
dev_langs: C++
helpviewer_keywords: SyncLockWithStatusT, constructor
ms.assetid: 5d2fb820-ae1b-495f-8084-ebb4fecc3104
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 00602992585e496a41a4ecea6d85ed798adac640
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="synclockwithstatustsynclockwithstatust-constructor"></a>Construtor SyncLockWithStatusT::SyncLockWithStatusT
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
SyncLockWithStatusT(  
   _Inout_ SyncLockWithStatusT&& other  
);  
  
explicit SyncLockWithStatusT(  
   typename SyncTraits::Type sync,  
   DWORD status  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `other`  
 Uma referência rvalue a outro objeto SyncLockWithStatusT.  
  
 `sync`  
 Uma referência a outro objeto SyncLockWithStatusT.  
  
 `status`  
 O valor da [status_](../windows/synclockwithstatust-status-data-member.md) membro de dados a `other` parâmetro ou o `sync` parâmetro.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância da classe SyncLockWithStatusT.  
  
 O primeiro construtor inicializa o objeto SyncLockWithStatusT atual de outro SyncLockWithStatusT especificado pelo parâmetro `other`e, em seguida, invalida o outro objeto SyncLockWithStatusT. É o segundo construtor `protected`e inicializa o objeto SyncLockWithStatusT atual para um estado inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)   
 [Método SyncLockWithStatusT::GetStatus](../windows/synclockwithstatust-getstatus-method.md)