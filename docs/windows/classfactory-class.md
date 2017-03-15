---
title: "Classe ClassFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::ClassFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ClassFactory"
ms.assetid: f13e6bce-722b-4f18-b7cf-3ffa6345c1db
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ClassFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Implementa a funcionalidade básica da interface de IClassFactory.  
  
## Sintaxe  
  
```  
template <  
   typename I0 = Details::Nil,  
   typename I1 = Details::Nil,  
   typename I2 = Details::Nil  
>  
class ClassFactory : public Details::RuntimeClass<  
   typename Details::InterfaceListHelper<IClassFactory,   
   I0,   
   I1,   
   I2,   
   Details::Nil>::TypeT,   
   RuntimeClassFlags<ClassicCom | InhibitWeakReference>,   
      false>;  
```  
  
#### Parâmetros  
 `I0`  
 A interface de zeroth.  
  
 `I1`  
 A primeira interface.  
  
 `I2`  
 A segunda interface.  
  
## Comentários  
 Utilize `ClassFactory` para fornecer uma implementação definida pelo usuário da fábrica.  
  
 O seguinte padrão de programação demonstra como usar a estrutura de [Implementa](../Topic/Implements%20Structure.md) para especificar mais de três interfaces de uma fábrica da classe.  
  
 `struct MyFactory : ClassFactory<Implements<I1, I2, I3>, I4, I5>`  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor ClassFactory::ClassFactory](../Topic/ClassFactory::ClassFactory%20Constructor.md)||  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ClassFactory::AddRef](../Topic/ClassFactory::AddRef%20Method.md)|Incrementa a contagem de referência do objeto atual de ClassFactory.|  
|[Método ClassFactory::LockServer](../windows/classfactory-lockserver-method.md)|Incrementa ou diminui o número de objetos subjacentes que são rastreados pelo objeto atual de ClassFactory.|  
|[Método ClassFactory::QueryInterface](../windows/classfactory-queryinterface-method.md)|Recupera um ponteiro para a interface especificada pelo parâmetro.|  
|[Método ClassFactory::Release](../windows/classfactory-release-method.md)|Diminui a contagem de referência para o objeto atual de ClassFactory.|  
  
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
  
 `ClassFactory`  
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)   
 [Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md)