---
title: Erro do compilador C2518
ms.date: 11/04/2016
f1_keywords:
- C2518
helpviewer_keywords:
- C2518
ms.assetid: a7895b47-da90-4851-ac97-18e81479595a
ms.openlocfilehash: 894167fce43147b98af6603cba3102e5714b850e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746481"
---
# <a name="compiler-error-c2518"></a>Erro do compilador C2518

palavra-chave ' keyword ' inválida na lista de classes base; aceita

As palavras-chave `class` e `struct` não devem aparecer em uma lista de classes base.

O exemplo a seguir gera C2518:

```cpp
// C2518.cpp
// compile with: /c
class B {};
class C : public class B {};   // C2518
class D: public B {};   // OK
```
