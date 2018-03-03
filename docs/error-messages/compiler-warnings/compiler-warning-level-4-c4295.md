---
title: "Compilador (nível 4) de aviso C4295 | Microsoft Docs"
ms.custom: 
ms.date: 1/09/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4295
dev_langs:
- C++
helpviewer_keywords:
- C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 56ffdce8c2790a3944a8f79753177bc80e249778
ms.sourcegitcommit: bc086a7acbe2d9fd77d115f269cc2a0dbeeb5b88
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/10/2018
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
