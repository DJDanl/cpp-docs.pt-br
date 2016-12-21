---
title: "Classe SimpleActivationFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::SimpleActivationFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SimpleActivationFactory"
ms.assetid: aff768e0-0038-4fd7-95d2-ad7d308da41c
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe SimpleActivationFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece um mecanismo fundamental para criar Tempo de Execução do Windows ou uma classe base clássica COM.  
  
## Sintaxe  
  
```  
template<  
   typename Base  
>  
class SimpleActivationFactory : public ActivationFactory<>;  
```  
  
#### Parâmetros  
 `Base`  
 Uma classe base.  
  
## Comentários  
 A classe base deve fornecer um construtor padrão.  
  
 O exemplo de código a seguir demonstra como usar SimpleActivationFactory com a macro de [ActivatableClassWithFactoryEx](../Topic/ActivatableClass%20Macros.md) .  
  
 `ActivatableClassWithFactoryEx(MyClass, SimpleActivationFactory, MyServerName);`  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SimpleActivationFactory::ActivateInstance](../windows/simpleactivationfactory-activateinstance-method.md)|Cria uma instância da interface especificada.|  
|[Método SimpleActivationFactory::GetRuntimeClassName](../windows/simpleactivationfactory-getruntimeclassname-method.md)|Obtém o nome da classe de tempo de execução de uma instância da classe especificada pelo parâmetro do modelo da classe de `Base` .|  
|[Método SimpleActivationFactory::GetTrustLevel](../Topic/SimpleActivationFactory::GetTrustLevel%20Method.md)|Obtém o nível de confiança de uma instância da classe especificada pelo parâmetro do modelo da classe de `Base` .|  
  
## Hierarquia de Herança  
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
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)