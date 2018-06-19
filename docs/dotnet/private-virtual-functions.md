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
ms.openlocfilehash: 97b4d7d9f47901fa69aa50bfc6f405355cf378b8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33162332"
---
# <a name="private-virtual-functions"></a>Funções virtuais particulares
A maneira como funções virtuais particulares são tratadas em classes derivadas foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Extensões gerenciadas, o nível de acesso de uma função virtual não restringir sua capacidade de ser substituído em uma classe derivada. Na sintaxe de novo, uma função virtual não pode substituir uma função virtual de classe base que não pode acessar. Por exemplo:  
  
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
  
 Não há nenhum mapeamento real desse tipo de design para a nova sintaxe. Um simplesmente tem que disponibilizar os membros de classe base - ou seja, não particulares. Os métodos herdados não precisa ter o mesmo acesso. Neste exemplo, a alteração menos invasiva é tornar o membro MyBaseClass `protected`. Dessa forma o acesso geral do programa para o método por meio de MyBaseClass ainda é proibido.  
  
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
  
 Observe que a ausência de explícita `virtual` palavra-chave na classe base, sob a nova sintaxe, gera uma mensagem de aviso.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 