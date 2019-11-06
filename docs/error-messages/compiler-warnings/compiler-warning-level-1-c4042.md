---
title: Aviso do compilador (nível 1) C4042
ms.date: 11/04/2016
f1_keywords:
- C4042
helpviewer_keywords:
- C4042
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
ms.openlocfilehash: db7f0425c3752c20ca8c5d4b6c95845ff64475c5
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627031"
---
# <a name="compiler-warning-level-1-c4042"></a>Aviso do compilador (nível 1) C4042

' identifier ': tem uma classe de armazenamento inadequada

A classe de armazenamento especificada não pode ser usada com este identificador neste contexto. Em vez disso, o compilador usa a classe de armazenamento padrão:

- `extern`, se o *identificador* for uma função.

- **auto**, se o *identificador* for um parâmetro formal ou uma variável local.

- Nenhuma classe de armazenamento, se o *identificador* for uma variável global.

Esse aviso pode ser causado pela especificação de uma classe de armazenamento diferente de **registro** em uma declaração de parâmetro.

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