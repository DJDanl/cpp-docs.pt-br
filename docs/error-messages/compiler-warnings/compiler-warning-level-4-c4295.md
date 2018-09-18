---
title: Compilador aviso (nível 4) C4295 | Microsoft Docs
ms.custom: ''
ms.date: 1/09/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4295
dev_langs:
- C++
helpviewer_keywords:
- C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 36c6ac4d8c3e2899b744d1c456ae3079ec031698
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053566"
---
# <a name="compiler-warning-level-4-c4295"></a>Compilador aviso (nível 4) C4295

> '*matriz*': matriz é muito pequena para incluir um caractere nulo de terminação

Uma matriz foi inicializada, mas o último caractere na matriz não é um valor nulo; acessar a matriz como uma cadeia de caracteres pode produzir resultados inesperados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4295. Para corrigir esse problema, você poderia declarar o tamanho da matriz maior, para manter um nulo de terminação da cadeia de caracteres de inicializador, ou você pode usar uma lista de inicializadores de matriz para tornar a intenção não criptografado que essa é uma matriz de `char`, não uma cadeia terminada em nulo.

```C
// C4295.c
// compile with: /W4


int main() {
   char a[3] = "abc";           // C4295
   char b[3] = {'d', 'e', 'f'}; // No warning
   a[0] = b[2];
}
```
