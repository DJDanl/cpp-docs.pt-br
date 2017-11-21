---
title: "Compilador (nível 4) de aviso C4202 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4202
dev_langs: C++
helpviewer_keywords: C4202
ms.assetid: 253293aa-97a3-4878-a2e8-c6cc9e20b1cb
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d23d417b89f2b810fcf78c141bd51eb7ef4b311d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4202"></a>Compilador C4202 de aviso (nível 4)
extensão não padrão usada: '...': parâmetro de protótipo na lista de nomes inválido  
  
 Uma definição de função de estilo antigo contém argumentos de variável. Essas definições de geram um erro em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).  
  
## <a name="example"></a>Exemplo  
  
```  
// C4202.c  
// compile with: /W4  
void func( a, b, ...)   // C4202  
int a, b;  
{}  
  
int main()  
{  
}  
```