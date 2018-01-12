---
title: "Compilador (nível 4) de aviso C4764 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4764
dev_langs: C++
helpviewer_keywords: C4764
ms.assetid: 7bd4296f-966b-484c-bf73-8dbc8e85b4a9
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2d669fca9decf792501025b85d0ed15a8eec8e66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4764"></a>Compilador C4764 de aviso (nível 4)
Não é possível alinhar objetos catch maiores que 16 bytes  
  
 Foi especificado um alinhamento maior do que 16, mas em algumas plataformas, se a função gera uma exceção, a pilha forçará um alinhamento de não mais de 16.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4764:  
  
```  
// C4764.cpp  
// compile with: /W4 /EHsc  
// processor: x64 IPF  
#include <stdio.h>  
  
class A   
{  
public:  
    int x;  
};  
  
typedef __declspec(align(32)) A ALIGNEDA;  
  
int main()   
{  
    ALIGNEDA a;  
    try   
    {  
        a.x = 15;  
        throw a;  
    }  
    catch (ALIGNEDA b) // can’t align b to > 16 bytes  
    {  
        printf_s("%d\n", b.x);  
    }  
}   // C4764  
```