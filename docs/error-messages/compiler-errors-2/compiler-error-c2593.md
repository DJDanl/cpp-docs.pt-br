---
title: Erro do compilador C2593
ms.date: 11/04/2016
f1_keywords:
- C2593
helpviewer_keywords:
- C2593
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
ms.openlocfilehash: 2a385e35376ddce528678980705595bfb98aca95
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759341"
---
# <a name="compiler-error-c2593"></a>Erro do compilador C2593

' identificador do operador ' é ambíguo

Mais de um operador possível é definido para um operador sobrecarregado.

Esse erro pode ser corrigido se você usar uma conversão explícita em um ou mais parâmetros reais.

O exemplo a seguir gera C2593:

```cpp
// C2593.cpp
struct A {};
struct B : A {};
struct X {};
struct D : B, X {};
void operator+( X, X );
void operator+( A, B );
D d;

int main() {
   d +  d;         // C2593, D has an A, B, and X
   (X)d + (X)d;    // OK, uses operator+( X, X )
}
```

Esse erro pode ser causado pela serialização de uma variável de ponto flutuante usando um objeto `CArchive`. O compilador identifica o operador de `<<` como ambíguo. Os únicos tipos C++ primitivos que `CArchive` podem serializar são os tipos de tamanho fixo `BYTE`, `WORD`, `DWORD`e `LONG`. Todos os tipos inteiros devem ser convertidos em um desses tipos para serialização. Os tipos de ponto flutuante devem ser arquivados usando a função de membro `CArchive::Write()`.

O exemplo a seguir mostra como arquivar uma variável de ponto flutuante (`f`) para arquivar `ar`:

```
ar.Write(&f, sizeof( float ));
```
