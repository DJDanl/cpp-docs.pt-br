---
title: Erro do compilador C2593 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2593
dev_langs:
- C++
helpviewer_keywords:
- C2593
ms.assetid: 4a0fe9bb-2163-447d-91f6-1890ed8250f6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1a3b0d1a8574aa5c05bbca023a1209cf1801f57e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042722"
---
# <a name="compiler-error-c2593"></a>Erro do compilador C2593

'operador identifier' é ambíguo

Mais de um operador possíveis é definido para um operador sobrecarregado.

Esse erro pode ser corrigido se você usar uma conversão explícita em uma ou mais parâmetros reais.

O exemplo a seguir gera C2593:

```
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

Esse erro pode ser causado pela serialização de um ponto flutuante variável usando um `CArchive` objeto. O compilador identifica o `<<` operador como ambígua. O C++ apenas primitivos tipos aos quais `CArchive` pode serializar os tipos de tamanho fixo `BYTE`, `WORD`, `DWORD`, e `LONG`. Todos os tipos de inteiro devem ser convertidos em um desses tipos para serialização. Tipos de ponto flutuante devem ser arquivados usando o `CArchive::Write()` função de membro.

O exemplo a seguir mostra como arquivar uma variável de ponto flutuante (`f`) para o arquivo morto `ar`:

```
ar.Write(&f, sizeof( float ));
```