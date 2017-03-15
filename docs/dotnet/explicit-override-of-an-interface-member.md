---
title: "Substitui&#231;&#227;o expl&#237;cita de um membro de interface | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "substituição explícita de função virtual"
  - "funções [C++], substituição"
  - "membros de interface, substituições explícitas"
  - "substituindo funções"
  - "funções virtuais, substituições explícitas"
ms.assetid: 46f1f536-bf43-4311-9a17-ff2282e528a9
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Substitui&#231;&#227;o expl&#237;cita de um membro de interface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para declarar uma substituição explícita de um membro da interface em uma classe foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Com frequência você deseja fornecer duas instâncias de um membro da interface em uma classe que implementa a interface – uma que é usada quando os objetos da classe são manipulados por meio de um identificador da interface, e uma que é usada quando os objetos da classe são usados na interface da classe.  Por exemplo:  
  
```  
public __gc class R : public ICloneable {  
   // to be used through ICloneable  
   Object* ICloneable::Clone();  
  
   // to be used through an R  
   R* Clone();  
};  
```  
  
 Extensões gerenciadas em nós faça isso fornecendo uma declaração explícita do método da interface do nome do método qualificado com o nome da interface.  A classe é instância específica não qualificado.  Isso eliminar a necessidade de entrada aérea do valor de retorno de `Clone`, neste exemplo, quando chamado explícito em uma instância de `R`.  
  
 Na nova sintaxe, substituindo um mecanismo geral foi introduzido que substitui a sintaxe gerenciado das extensões.  Nosso exemplo seria reescrito como segue:  
  
```  
public ref class R : public ICloneable {  
public:  
   // to be used through ICloneable  
   virtual Object^ InterfaceClone() = ICloneable::Clone;  
  
   // to be used through an R  
   virtual R^ Clone();  
};  
```  
  
 Essa análise requer que o membro da interface que está sendo substituído explicitamente foi fornecido um nome exclusivo dentro da classe.  Aqui, eu forneci o nome de `InterfaceClone`inadequado.  O comportamento ainda é o mesmo – uma invocação por meio da interface de `ICloneable` invoca `InterfaceClone,` renomeados quando uma chamada por meio de um objeto do tipo `R` invocar a segunda instância de `Clone` .  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [Explicit Overrides](../windows/explicit-overrides-cpp-component-extensions.md)