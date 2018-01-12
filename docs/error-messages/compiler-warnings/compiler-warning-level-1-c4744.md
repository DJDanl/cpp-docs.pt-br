---
title: "Compilador (nível 1) de aviso C4744 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4744
dev_langs: C++
helpviewer_keywords: C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0b6fa95f8477f889aa8664d2b6d99c753cb9848d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4744"></a>Compilador C4744 de aviso (nível 1)
'var' possui tipo diferente em 'file1' e 'file2': 'type1' e 'type2'  
  
 Uma variável externa referenciado ou definidos em dois arquivos tem diferentes tipos nesses arquivos.  Para resolver, verifique as definições de tipo a mesma ou alterar o nome da variável em um dos arquivos.  
  
 C4744 é emitido somente quando arquivos são compilados com /GL.  Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).  
  
> [!NOTE]
>  C4744 normalmente ocorre em arquivos de C (C++ não), como em C++, um nome de variável é decorado com informações de tipo.  Quando o exemplo (abaixo) é compilado como C++, você terá erros de vinculador LNK2019.  
  
## <a name="example"></a>Exemplo  
 Este exemplo contém a primeira definição.  
  
```  
// C4744.c  
// compile with: /c /GL  
int global;  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4744.  
  
```  
// C4744b.c  
// compile with: C4744.c /GL /W1  
// C4744 expected  
#include <stdio.h>  
  
extern unsigned global;  
  
main()   
{  
    printf_s("%d\n", global);  
}  
```