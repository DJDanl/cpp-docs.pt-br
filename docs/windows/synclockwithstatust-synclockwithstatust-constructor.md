---
title: 'Construtor synclockwithstatust:: Synclockwithstatust | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::SyncLockWithStatusT
dev_langs:
- C++
helpviewer_keywords:
- SyncLockWithStatusT, constructor
ms.assetid: 5d2fb820-ae1b-495f-8084-ebb4fecc3104
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 21ce2054cabf257594cb3fa376236b9a1e504a59
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39647749"
---
# <a name="synclockwithstatustsynclockwithstatust-constructor"></a>Construtor SyncLockWithStatusT::SyncLockWithStatusT
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *other*  
 Uma referência rvalue para outro **SyncLockWithStatusT** objeto.  
  
 *sync*  
 Uma referência a outro **SyncLockWithStatusT** objeto.  
  
 *status*  
 O valor da [status _](../windows/synclockwithstatust-status-data-member.md) membro de dados a *outras* parâmetro ou o *sincronização* parâmetro.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância dos **SyncLockWithStatusT** classe.  
  
 O primeiro construtor inicializa o atual **SyncLockWithStatusT** objeto de outro **SyncLockWithStatusT** especificado pelo parâmetro *outros*e, em seguida, invalida a outra **SyncLockWithStatusT** objeto. É o segundo construtor **protegidos**e a inicializa atual **SyncLockWithStatusT** objeto para um estado inválido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)   
 [Método SyncLockWithStatusT::GetStatus](../windows/synclockwithstatust-getstatus-method.md)