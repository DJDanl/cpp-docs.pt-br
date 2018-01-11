---
title: Classe ModuleBase | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::ModuleBase
dev_langs: C++
helpviewer_keywords: ModuleBase class
ms.assetid: edce7591-6893-46f7-94a7-382827775548
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b02efe3ee61234b2439c1cbbae07827d6a879b2a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulebase-class"></a>Classe ModuleBase
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class ModuleBase;  
```  
  
## <a name="remarks"></a>Comentários  
 Representa a classe base do [módulo](../windows/module-class.md) classes.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ModuleBase::ModuleBase](../windows/modulebase-modulebase-constructor.md)|Inicializa uma instância da classe de módulo.|  
|[Destruidor ModuleBase::~ModuleBase](../windows/modulebase-tilde-modulebase-destructor.md)|Deinitializes a instância atual da classe de módulo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ModuleBase::DecrementObjectCount](../windows/modulebase-decrementobjectcount-method.md)|Quando implementada, diminui o número de objetos rastreados pelo módulo.|  
|[Método ModuleBase::IncrementObjectCount](../windows/modulebase-incrementobjectcount-method.md)|Quando implementada, incrementa o número de objetos rastreados pelo módulo.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ModuleBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)