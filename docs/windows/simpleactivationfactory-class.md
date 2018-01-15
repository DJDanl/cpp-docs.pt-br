---
title: Classe SimpleActivationFactory | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::SimpleActivationFactory
dev_langs: C++
helpviewer_keywords: SimpleActivationFactory class
ms.assetid: aff768e0-0038-4fd7-95d2-ad7d308da41c
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 991d428e90654fd29cfbb9c5c7e110708a05de01
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="simpleactivationfactory-class"></a>Classe SimpleActivationFactory
Fornece um mecanismo básico para criar um tempo de execução do Windows ou a classe de base COM clássico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename Base  
>  
class SimpleActivationFactory : public ActivationFactory<>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 Uma classe base.  
  
## <a name="remarks"></a>Comentários  
 A classe base deve fornecer um construtor padrão.  
  
 O exemplo de código a seguir demonstra como usar SimpleActivationFactory com o [ActivatableClassWithFactoryEx](../windows/activatableclass-macros.md) macro.  
  
 `ActivatableClassWithFactoryEx(MyClass, SimpleActivationFactory, MyServerName);`  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método SimpleActivationFactory::ActivateInstance](../windows/simpleactivationfactory-activateinstance-method.md)|Cria uma instância da interface especificada.|  
|[Método SimpleActivationFactory::GetRuntimeClassName](../windows/simpleactivationfactory-getruntimeclassname-method.md)|Obtém o nome de classe de tempo de execução de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.|  
|[Método SimpleActivationFactory::GetTrustLevel](../windows/simpleactivationfactory-gettrustlevel-method.md)|Obtém o nível de confiança de uma instância da classe especificada o `Base` parâmetro de modelo de classe.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `I0`  
  
 `ChainInterfaces`  
  
 `I0`  
  
 `RuntimeClassBase`  
  
 `ImplementsHelper`  
  
 `DontUseNewUseMake`  
  
 `RuntimeClassFlags`  
  
 `RuntimeClassBaseT`  
  
 `RuntimeClass`  
  
 `ActivationFactory`  
  
 `SimpleActivationFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)