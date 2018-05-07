---
title: Compilador (nível 4) de aviso C4295 | Microsoft Docs
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
ms.openlocfilehash: 815a669bc359121b13b1d636009cad81dc332304
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4295"></a>Compilador C4295 de aviso (nível 4)
  
> '*matriz*': matriz é muito pequena para incluir um caractere null de terminação  
  
Uma matriz foi inicializada, mas o último caractere na matriz não é um valor nulo; acessar a matriz como uma cadeia de caracteres pode produzir resultados inesperados.  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir gera C4295. Para corrigir esse problema, você pode declarar o tamanho da matriz maior, para manter um encerramento nulo de cadeia de caracteres de inicializador ou pode usar uma lista de inicializadores de matriz para fazer a intenção clear que esta é uma matriz de `char`, não uma cadeia terminada em nulo.  
  
```C  
// C4295.c
// compile with: /W4


int main() {
   char a[3] = "abc";           // C4295
   char b[3] = {'d', 'e', 'f'}; // No warning
   a[0] = b[2];
}
```
