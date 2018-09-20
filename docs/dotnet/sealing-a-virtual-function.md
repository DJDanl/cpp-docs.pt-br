---
title: Selando uma função Virtual | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- sealed keyword [C++]
- derived classes, virtual functions
- virtual functions, sealing
- __sealed keyword
ms.assetid: 0e9fae03-6425-4512-9a24-8ccb6dc8a0d4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 69ac614d55ade10b94621da2a3eb1c43d25ebaf5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385177"
---
# <a name="sealing-a-virtual-function"></a>Selando uma função virtual

A sintaxe para selando uma função virtual foi alterado de extensões gerenciadas para C++ no Visual C++.

O `__sealed` palavra-chave é usada nas extensões gerenciadas para modificar qualquer um tipo de referência, desautorizando derivação subsequente dele (consulte [declaração de um tipo de classe gerenciada](../dotnet/declaration-of-a-managed-class-type.md)), ou para modificar uma função virtual, não permitindo substituindo subsequentes do método em uma classe derivada. Por exemplo:

```
__gc class base { public: virtual void f(); };
__gc class derived : public base {
public:
   __sealed void f();
};
```

Neste exemplo, `derived::f()` substitui o `base::f()` instância com base na correspondência exata do protótipo da função. O `__sealed` palavra-chave indica que uma classe subsequente herdada da classe derivada não pode fornecer uma substituição do `derived::f()`.

Na nova sintaxe, `sealed` é posicionado após a assinatura em vez de terem permissão para aparecer em qualquer lugar antes de protótipo da função real, que anteriormente era permitida. Além disso, o uso de `sealed` requer um uso explícito do `virtual` palavra-chave também. Ou seja, a tradução correta de `derived`, acima, é o seguinte:

```
ref class derived: public base {
public:
   virtual void f() override sealed;
};
```

A ausência do `virtual` palavra-chave nesta instância resulta em um erro. Na nova sintaxe, a palavra-chave contextual `abstract` pode ser usado em vez do `=0` para indicar uma função virtual pura. Isso não era compatível em extensões gerenciadas. Por exemplo:

```
__gc class base { public: virtual void f()=0; };
```

pode ser reescrita como

```
ref class base { public: virtual void f() abstract; };
```

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
[sealed](../windows/sealed-cpp-component-extensions.md)