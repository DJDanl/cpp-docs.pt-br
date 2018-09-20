---
title: Funções virtuais particulares | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- virtual functions, private
- derived classes, virtual functions
- access modifiers [C++], for class members
- member access [C++], virtual members
ms.assetid: 04448086-bf72-44be-9c1f-dfda1744949e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0058d023268fa4d9ca5abe802ff45856e9855dc7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46418067"
---
# <a name="private-virtual-functions"></a>Funções virtuais particulares

A maneira como funções virtuais particulares são tratadas em classes derivadas mudou de extensões gerenciadas para C++ para Visual C++.

Nas extensões gerenciadas, o nível de acesso de uma função virtual não restringe sua capacidade de ser substituído em uma classe derivada. Na nova sintaxe, uma função virtual não pode substituir uma função virtual de classe base que ela não pode acessar. Por exemplo:

```
__gc class MyBaseClass {
   // inaccessible to a derived class
   virtual void g();
};

__gc class MyDerivedClass : public MyBaseClass {
public:
   // okay in Managed Extensions; g() overrides MyBaseClass::g()
   // error in new syntax; cannot override: MyBaseClass::g() is inaccessible
   void g();
};
```

Não há nenhum mapeamento real desse tipo de design para a nova sintaxe. Simplesmente, é preciso tornar os membros da classe base acessível - ou seja, não privado. Os métodos herdados não tem que você deve ter o mesmo acesso. Neste exemplo, a alteração menos invasiva é tornar o membro MyBaseClass `protected`. Dessa maneira o acesso geral do programa para o método por meio de MyBaseClass ainda é proibido.

```
ref class MyBaseClass {
protected:
   virtual void g();
};

ref class MyDerivedClass : MyBaseClass {
public:
   virtual void g() override;
};
```

Observe que a ausência de explícito `virtual` palavra-chave na classe base, sob a nova sintaxe, gera uma mensagem de aviso.

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)
