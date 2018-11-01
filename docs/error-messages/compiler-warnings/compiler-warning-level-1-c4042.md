---
title: Compilador aviso (nível 1) C4042
ms.date: 11/04/2016
f1_keywords:
- C4042
helpviewer_keywords:
- C4042
ms.assetid: e4bd861b-1194-426b-bf79-68c5b021eb0a
ms.openlocfilehash: 99f4f45aad82aa9898dad4cffb60b8e3311ddc9f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576784"
---
# <a name="compiler-warning-level-1-c4042"></a>Compilador aviso (nível 1) C4042

'identifier': possui classe de armazenamento incorreta

A classe de armazenamento especificado não pode ser usada com este identificador neste contexto. Em vez disso, o compilador usa a classe de armazenamento padrão:

- `extern`, se *identificador* é uma função.

- **auto**, se *identificador* é um parâmetro formal ou uma variável local.

- Nenhum armazenamento de classe, se *identificador* é uma variável global.

Esse aviso pode ser provocado pela especificação de uma classe de armazenamento diferente de **registrar** em uma declaração de parâmetro.

O exemplo a seguir gera C4042

```
// C4042.cpp
// compile with: /W1 /LD
int func2( __declspec( thread ) int tls_i )    // C4042
// try the following line instead
// int func2( int tls_i )
{
   return tls_i;
}
```