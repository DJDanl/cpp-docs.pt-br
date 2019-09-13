---
title: Aviso do compilador (nível 4) C4295
ms.date: 01/09/2018
f1_keywords:
- C4295
helpviewer_keywords:
- C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
ms.openlocfilehash: 5e8b546e4eb4b60197db504382b3230e779b1dec
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70924845"
---
# <a name="compiler-warning-level-4-c4295"></a>Aviso do compilador (nível 4) C4295

> '*array*': a matriz é muito pequena para incluir um caractere nulo de terminação

Uma matriz foi inicializada, mas o último caractere na matriz não é nulo; acessar a matriz como uma cadeia de caracteres pode produzir resultados inesperados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4295. Para corrigir esse problema, você pode declarar o tamanho da matriz maior, para manter um nulo de terminação da cadeia de caracteres do inicializador, ou pode usar uma lista de inicializadores de matriz para tornar a `char`intenção claro que essa é uma matriz de, não uma cadeia de caracteres terminada em nulo.

```C
// C4295.c
// compile with: /W4

int main() {
   char a[3] = "abc";           // C4295
   char b[3] = {'d', 'e', 'f'}; // No warning
   a[0] = b[2];
}
```
