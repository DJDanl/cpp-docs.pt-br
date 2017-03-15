---
title: "Compilador aviso (nível 1) C4744 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4744
dev_langs:
- C++
helpviewer_keywords:
- C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ab7a85e939218aab16c9ccced831f0b3dba64bf5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4744"></a>Compilador C4744 de aviso (nível 1)
'var' tem um tipo diferente de 'file1' e 'file2': 'type1' e 'type2'  
  
 Uma variável externa referenciado ou definido em dois arquivos tem diferentes tipos desses arquivos.  Para resolver, verifique as definições de tipo a mesma ou alterar o nome da variável em um dos arquivos.  
  
 C4744 é emitido apenas quando os arquivos são compilados com /GL.  Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).  
  
> [!NOTE]
>  C4744 geralmente ocorre em arquivos C (C++ não), como em C++, um nome de variável é decorado com informações de tipo.  Quando o exemplo (abaixo) é compilado c++, você obterá um erro de vinculador LNK2019.  
  
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
