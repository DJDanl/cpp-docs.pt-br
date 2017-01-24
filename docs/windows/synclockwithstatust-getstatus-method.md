---
title: "M&#233;todo SyncLockWithStatusT::GetStatus | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT::GetStatus"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetStatus"
ms.assetid: d448b51d-a63d-40d9-a9ee-4aad3204118d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo SyncLockWithStatusT::GetStatus
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
DWORD GetStatus() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O resultado de uma operação de espera no objeto que é baseado na classe SyncLockWithStatusT, como um [Mutex](Mutex%20Class1.md) ou [semáforo](../windows/semaphore-class.md). Zero (0) indica que a operação de espera retornou o estado sinalizado. Caso contrário, outro estado ocorreu, como o valor de tempo limite decorrido.  
  
## <a name="remarks"></a>Comentários  
 Recupera o status de espera do objeto SyncLockWithStatusT atual.  
  
 A função getStatus () recupera o valor subjacente [status_](../windows/synclockwithstatust-status-data-member.md) membro de dados. Quando um objeto com base na classe SyncLockWithStatusT executa uma operação de bloqueio, o objeto aguarda pela primeira vez o objeto se torne disponível. O resultado dessa operação de espera é armazenado na `status_` membro de dados. Os possíveis valores a `status_` membro de dados são os valores de retorno da operação de espera. Para obter mais informações, consulte os valores de retorno de **WaitForSingleObjectEx()** função na biblioteca MSDN.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe SyncLockWithStatusT](../windows/synclockwithstatust-class.md)