---
title: Compilador (nível 1) de aviso C4744 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4744
dev_langs:
- C++
helpviewer_keywords:
- C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a45207f85575c8047f673b415ce802dbac24318
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282822"
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