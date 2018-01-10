---
title: "Selando uma função Virtual | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- sealed keyword [C++]
- derived classes, virtual functions
- virtual functions, sealing
- __sealed keyword
ms.assetid: 0e9fae03-6425-4512-9a24-8ccb6dc8a0d4
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 48d52a2697289197555438847ba2fcb86aeb3235
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sealing-a-virtual-function"></a>Selando uma função virtual
A sintaxe para lacrar uma função virtual foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 O `__sealed` palavra-chave é usada das extensões gerenciadas para modificar ou um tipo de referência, a desabilitação de derivação subsequente dele (consulte [declaração de um tipo de classe gerenciada](../dotnet/declaration-of-a-managed-class-type.md)), ou para modificar uma função virtual, não permitindo substituindo subsequentes do método em uma classe derivada. Por exemplo:  
  
```  
__gc class base { public: virtual void f(); };  
__gc class derived : public base {  
public:  
   __sealed void f();  
};  
```  
  
 Neste exemplo, `derived::f()` substitui o `base::f()` instância com base na correspondência exata do protótipo de função. O `__sealed` palavra-chave indica que uma classe subsequente herdada da classe derivada não pode fornecer uma substituição de `derived::f()`.  
  
 Na sintaxe de novo, `sealed` é posicionada após a assinatura em vez de terem permissão para aparecer em qualquer lugar antes do protótipo de função real, que anteriormente era permitida. Além disso, o uso de `sealed` exige um uso explícito do `virtual` palavra-chave também. Ou seja, a tradução correta de `derived`acima, é o seguinte:  
  
```  
ref class derived: public base {  
public:  
   virtual void f() override sealed;  
};  
```  
  
 A ausência de `virtual` palavra-chave nesta instância resulta em um erro. Na sintaxe de novo, a palavra-chave contextual `abstract` pode ser usado em vez do `=0` para indicar uma função virtual pura. Isso não era suportado dentro das extensões gerenciadas. Por exemplo:  
  
```  
__gc class base { public: virtual void f()=0; };  
```  
  
 pode ser reescrita como  
  
```  
ref class base { public: virtual void f() abstract; };  
```  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou Interface (C + + CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [sealed](../windows/sealed-cpp-component-extensions.md)