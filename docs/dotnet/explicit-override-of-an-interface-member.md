---
title: Substituição explícita de um membro de Interface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- virtual functions, explicit overrides
- overriding functions
- interface members, explicit overrides
- functions [C++], overriding
- explicit override of virtual function
ms.assetid: 46f1f536-bf43-4311-9a17-ff2282e528a9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 811112d2721edccede6c7b4a278189fdec874523
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="explicit-override-of-an-interface-member"></a>Substituição explícita de um membro de interface
A sintaxe para declarar uma substituição explícita de um membro de interface dentro de uma classe foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Você geralmente deseja fornecer duas instâncias de um membro de interface dentro de uma classe que implementa a interface - que é usado quando os objetos de classe são manipulados por meio de um identificador de interface e que é usada quando os objetos de classe são usados por meio da interface de classe. Por exemplo:  
  
```  
public __gc class R : public ICloneable {  
   // to be used through ICloneable  
   Object* ICloneable::Clone();  
  
   // to be used through an R  
   R* Clone();  
};  
```  
  
 Em extensões gerenciadas fazemos isso fornecendo uma declaração explícita do método de interface com o nome do método qualificado com o nome da interface. A instância de classe específica não é qualificada. Isso elimina a necessidade de baixá-los o valor de retorno `Clone`, neste exemplo, quando uma chamada explícita por meio de uma instância de `R`.  
  
 Na nova sintaxe, um mecanismo de substituição geral foi introduzido que substitui a sintaxe das extensões gerenciadas. Nosso exemplo poderia ser reescrito da seguinte maneira:  
  
```  
public ref class R : public ICloneable {  
public:  
   // to be used through ICloneable  
   virtual Object^ InterfaceClone() = ICloneable::Clone;  
  
   // to be used through an R  
   virtual R^ Clone();  
};  
```  
  
 Esta revisão requer que o membro de interface que está sendo substituído explicitamente ser fornecido um nome exclusivo dentro da classe. Aqui, você forneceu o nome inadequado de `InterfaceClone`. O comportamento ainda é o mesmo - uma chamada por meio de `ICloneable` interface invoca renomeadas `InterfaceClone`, enquanto uma chamada por meio de um objeto do tipo `R` invoca o segundo `Clone` instância.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou Interface (C + + CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md)