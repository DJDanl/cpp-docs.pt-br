---
title: Aviso do compilador (nível 1) C4042
ms.date: 11/04/2016
f1_keywords:
- C4042
helpviewer_keywords:
- C4042
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
ms.openlocfilehash: cd8d8addb8441bd32d242c4f4858104048f7a62e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197066"
---
# <a name="compiler-warning-level-1-c4042"></a>Aviso do compilador (nível 1) C4042

' identifier ': tem uma classe de armazenamento inadequada

A classe de armazenamento especificada não pode ser usada com este identificador neste contexto. Em vez disso, o compilador usa a classe de armazenamento padrão:

- **`extern`**, se o *identificador* for uma função.

- **`auto`**, se o *identificador* for um parâmetro formal ou uma variável local.

- Nenhuma classe de armazenamento, se o *identificador* for uma variável global.

Esse aviso pode ser causado pela especificação de uma classe de armazenamento diferente de **`register`** em uma declaração de parâmetro.

O exemplo a seguir gera C4042

```cpp
// C4042.cpp
// compile with: /W1 /LD
int func2( __declspec( thread ) int tls_i )    // C4042
// try the following line instead
// int func2( int tls_i )
{
   return tls_i;
}
```
