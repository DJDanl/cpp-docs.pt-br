---
title: Erro do compilador C2243
ms.date: 11/04/2016
f1_keywords:
- C2243
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
ms.openlocfilehash: ded5a3d459e4b5d1412998aadbaa385864f505a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388848"
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