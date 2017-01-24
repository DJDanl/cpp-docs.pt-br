---
title: "Classe ModuleBase | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::Details::ModuleBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ModuleBase"
ms.assetid: edce7591-6893-46f7-94a7-382827775548
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ModuleBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura do WRL e não se destina a ser usada diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class ModuleBase;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa a classe base do [módulo](../windows/module-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor modulebase:: Modulebase](../windows/modulebase-modulebase-constructor.md)|Inicializa uma instância da classe de módulo.|  
|[ModuleBase:: ~ ModuleBase destruidor](../windows/modulebase-tilde-modulebase-destructor.md)|Deinitializes a instância atual da classe de módulo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Decrementobjectcount](../Topic/ModuleBase::DecrementObjectCount%20Method.md)|Quando implementada, diminui o número de objetos rastreados pelo módulo.|  
|[Método Incrementobjectcount](../windows/modulebase-incrementobjectcount-method.md)|Quando implementada, incrementa o número de objetos rastreados pelo módulo.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ModuleBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)