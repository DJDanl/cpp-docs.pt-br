---
title: Aviso do compilador (nível 4) C4295
ms.date: 01/09/2018
f1_keywords:
- C4295
helpviewer_keywords:
- C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
ms.openlocfilehash: d960e5a5e2d7ad2d2b650095c42e9afea7bfe7fb
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219866"
---
# <a name="compiler-warning-level-4-c4295"></a>Aviso do compilador (nível 4) C4295

> '*array*': a matriz é muito pequena para incluir um caractere nulo de terminação

Uma matriz foi inicializada, mas o último caractere na matriz não é nulo; acessar a matriz como uma cadeia de caracteres pode produzir resultados inesperados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4295. Para corrigir esse problema, você pode declarar o tamanho da matriz maior, para manter um nulo de terminação da cadeia de caracteres do inicializador, ou pode usar uma lista de inicializadores de matriz para tornar a intenção claro que essa é uma matriz de **`char`** , não uma cadeia de caracteres terminada em nulo.

```C
// C4295.c
// compile with: /W4

int main() {
   char a[3] = "abc";           // C4295
   char b[3] = {'d', 'e', 'f'}; // No warning
   a[0] = b[2];
}
```
