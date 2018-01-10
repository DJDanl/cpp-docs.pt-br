---
title: "Compilador (nível 4) de aviso C4295 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4295
dev_langs: C++
helpviewer_keywords: C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1424302c5c109ff79f35c922d1e5051b15655554
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4295"></a>Compilador C4295 de aviso (nível 4)
  
> '*matriz*': matriz é muito pequena para incluir um caractere null de terminação  
  
 Uma matriz foi inicializada, mas o último caractere na matriz não é um valor nulo; acessar a matriz pode produzir resultados inesperados.  
  
## <a name="example"></a>Exemplo  
  
 O exemplo a seguir gera C4295. Para corrigir esse problema, você pode declarar o tamanho da matriz maior, para manter uma terminação nula do inicializador.  
  
```C  
// C4295.c  
// compile with: /W4  
  
int main() {  
   char a[3] = "abc";   // C4295  
}  
```