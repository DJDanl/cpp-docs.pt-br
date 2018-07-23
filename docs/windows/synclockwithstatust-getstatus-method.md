---
title: 'Método Synclockwithstatust: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus
dev_langs:
- C++
helpviewer_keywords:
- GetStatus method
ms.assetid: d448b51d-a63d-40d9-a9ee-4aad3204118d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 03addd8d89c54eddb5deb721ab47d46e8b945edd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889756"
---
# <a name="synclockwithstatustgetstatus-method"></a>Método SyncLockWithStatusT::GetStatus
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
DWORD GetStatus() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado de uma operação de espera no objeto que é baseado em classe SyncLockWithStatusT, como um [Mutex](../windows/mutex-class1.md) ou [semáforo](../windows/semaphore-class.md). Zero (0) indica que a operação de espera retornado do estado sinalizado; Caso contrário, outro estado ocorreu, como o valor de tempo limite decorrido.  
  
## <a name="remarks"></a>Comentários  
 Recupera o status de espera do objeto SyncLockWithStatusT atual.  
  
 A função getStatus () recupera o valor subjacente [status_](../windows/synclockwithstatust-status-data-member.md) membro de dados. Quando um objeto com base na classe SyncLockWithStatusT executa uma operação de bloqueio, o objeto de espera primeiro o objeto ficar disponível. O resultado dessa operação de espera é armazenado no `status_` membro de dados. Os possíveis valores a `status_` membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte os valores de retorno de **WaitForSingleObjectEx()** função na biblioteca MSDN.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)