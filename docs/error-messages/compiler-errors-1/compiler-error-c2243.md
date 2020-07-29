---
title: Erro do compilador C2243
ms.date: 11/04/2016
f1_keywords:
- C2243
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
ms.openlocfilehash: ab0dbe8c5595c18a01f78c22056803dce91a3f31
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212833"
---
# <a name="compiler-error-c2243"></a>Erro do compilador C2243

a conversão de ' tipo de conversão ' de ' type1 ' para ' type2 ' existe, mas está inacessível

A proteção de acesso ( **`protected`** ou **`private`** ) impediu a conversão de um ponteiro para uma classe derivada para um ponteiro para a classe base.

O exemplo a seguir gera C2243:

```cpp
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

As classes base com **`protected`** ou **`private`** acesso não estão acessíveis aos clientes da classe derivada. Esses níveis de controle de acesso são usados para indicar que a classe base é um detalhe de implementação que deve ser invisível para os clientes. Use derivação pública se você quiser que os clientes da classe derivada tenham acesso à conversão implícita de um ponteiro de classe derivada para um ponteiro para a classe base.
