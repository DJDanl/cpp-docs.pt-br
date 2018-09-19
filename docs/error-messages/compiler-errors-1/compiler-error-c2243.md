---
title: Erro do compilador C2243 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2243
dev_langs:
- C++
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ef5d3a6c20ff147ac2a4b765c7779cec9f19627e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102223"
---
# <a name="compiler-error-c2243"></a>Erro do compilador C2243

conversão de 'tipo de conversão' de 'type1' em 'type2' existe, mas está inacessível

Proteção de acesso (`protected` ou `private`) impediu a conversão de um ponteiro para uma classe derivada em um ponteiro para a classe base.

O exemplo a seguir gera C2243:

```
// C2243.cpp
// compile with: /c
class B {};
class D : private B {};
class E : public B {};

D d;
B *p = &d;   // C2243

E e;
B *p2 = &e;
```

Classes com base `protected` ou `private` acesso não são acessíveis aos clientes da classe derivada. Esses níveis de controle de acesso são usados para indicar que a classe base é um detalhe de implementação deve ser invisível para os clientes. Use derivação pública se você deseja que os clientes da classe derivada tem acesso a conversão implícita de um ponteiro de classe derivada em um ponteiro para a classe base.