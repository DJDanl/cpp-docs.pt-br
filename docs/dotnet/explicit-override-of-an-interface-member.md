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
ms.openlocfilehash: 57c26c1185eff0e88e18ef23cb8506fb1fed407a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46409019"
---
# <a name="explicit-override-of-an-interface-member"></a>Substituição explícita de um membro de interface

A sintaxe para declarar uma substituição explícita de um membro de interface dentro de uma classe foi alterado de extensões gerenciadas para C++ no Visual C++.

Você geralmente deseja fornecer duas instâncias de um membro de interface dentro de uma classe que implementa a interface - um que é usado quando os objetos de classe são manipulados por meio de um identificador de interface e que é usada quando os objetos de classe são usados por meio da interface de classe. Por exemplo:

```
public __gc class R : public ICloneable {
   // to be used through ICloneable
   Object* ICloneable::Clone();

   // to be used through an R
   R* Clone();
};
```

Nas extensões gerenciadas fazemos isso fornecendo uma declaração explícita do método de interface com o nome do método qualificado com o nome da interface. A instância específica da classe não é qualificada. Isso elimina a necessidade para baixá-los, o valor de retorno `Clone`, neste exemplo, quando uma chamada explícita por meio de uma instância de `R`.

Na nova sintaxe, um mecanismo geral de substituição foi introduzido que substitui a sintaxe de extensões gerenciadas. Nosso exemplo poderia ser reescrito da seguinte maneira:

```
public ref class R : public ICloneable {
public:
   // to be used through ICloneable
   virtual Object^ InterfaceClone() = ICloneable::Clone;

   // to be used through an R
   virtual R^ Clone();
};
```

Esta revisão requer que o membro de interface explicitamente que está sendo substituído seja atribuído um nome exclusivo dentro da classe. Aqui, eu forneci o nome estranho do `InterfaceClone`. O comportamento ainda é o mesmo - uma invocação por meio de `ICloneable` interface invoca renomeadas `InterfaceClone`, enquanto uma chamada por meio de um objeto do tipo `R` invoca o segundo `Clone` instância.

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
[Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md)