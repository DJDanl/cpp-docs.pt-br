---
title: "Classe SyncLockWithStatusT | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::Details::SyncLockWithStatusT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SyncLockWithStatusT"
ms.assetid: 4832fd93-0ac8-4168-9404-b43fefea7476
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe SyncLockWithStatusT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename SyncTraits  
>  
class SyncLockWithStatusT : public SyncLockT<SyncTraits>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `SyncTraits`  
 Um tipo que pode levar exclusivo ou compartilhado a propriedade de um recurso.  
  
## <a name="remarks"></a>Comentários  
 Representa um tipo que pode levar exclusivo ou compartilhado a propriedade de um recurso.  
  
 A classe SyncLockWithStatusT é usada para implementar o [Mutex](../Topic/Mutex%20Class1.md) e [semáforo](../windows/semaphore-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor synclockwithstatust:: Synclockwithstatust](../Topic/SyncLockWithStatusT::SyncLockWithStatusT%20Constructor.md)|Inicializa uma nova instância da classe SyncLockWithStatusT.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor synclockwithstatust:: Synclockwithstatust](../Topic/SyncLockWithStatusT::SyncLockWithStatusT%20Constructor.md)|Inicializa uma nova instância da classe SyncLockWithStatusT.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Synclockwithstatust::](../windows/synclockwithstatust-getstatus-method.md)|Recupera o status de espera do objeto SyncLockWithStatusT atual.|  
|[Método Synclockwithstatust::](../windows/synclockwithstatust-islocked-method.md)|Indica se o objeto SyncLockWithStatusT atual possui um recurso; Isto é, se o objeto SyncLockWithStatusT *bloqueado*.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados SyncLockWithStatusT::status_](../windows/synclockwithstatust-status-data-member.md)|Armazena o resultado da operação após uma operação de bloqueio de espera em um objeto com base no objeto SyncLockWithStatusT atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `SyncLockT`  
  
 `SyncLockWithStatusT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)