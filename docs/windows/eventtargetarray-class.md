---
title: "Classe EventTargetArray | Microsoft Docs"
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
  - "event/Microsoft::WRL::Details::EventTargetArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe EventTargetArray"
ms.assetid: e3cadb7c-2160-4cbb-a2f8-c28733d1e96d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe EventTargetArray
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class EventTargetArray : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<ClassicCom>, IUnknown>;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa uma matriz de manipuladores de eventos.  
  
 Os manipuladores de eventos que são associados com um [EventSource](../windows/eventsource-class.md) objeto são armazenados em um membro de dados EventTargetArray protegido.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor eventtargetarray:: Eventtargetarray](../windows/eventtargetarray-eventtargetarray-constructor.md)|Inicializa uma nova instância da classe EventTargetArray.|  
|[EventTargetArray:: ~ EventTargetArray destruidor](../Topic/EventTargetArray::~EventTargetArray%20Destructor.md)|Deinitializes a classe EventTargetArray atual.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Eventtargetarray::](../windows/eventtargetarray-addtail-method.md)|Acrescenta o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.|  
|[Método Eventtargetarray::](../windows/eventtargetarray-begin-method.md)|Obtém o endereço do primeiro elemento da matriz interna de manipuladores de eventos.|  
|[Método Eventtargetarray::](../windows/eventtargetarray-end-method.md)|Obtém o endereço do último elemento da matriz interna de manipuladores de eventos.|  
|[Método Eventtargetarray::](../windows/eventtargetarray-length-method.md)|Obtém o número atual de elementos da matriz interna de manipuladores de eventos.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `EventTargetArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)