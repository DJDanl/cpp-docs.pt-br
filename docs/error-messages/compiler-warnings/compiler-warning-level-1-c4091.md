---
title: "Compilador (nível 1) de aviso C4091 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4091
dev_langs:
- C++
helpviewer_keywords:
- C4091
ms.assetid: 3a404967-ab42-49b0-b324-fd7ba1859d78
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9be40d65b657a7ac34fb105a2b1b16c702e4922c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4091"></a>Compilador C4091 de aviso (nível 1)
'palavra-chave': ignorado à esquerda de 'type' quando nenhuma variável é declarada  
  
 O compilador detectou uma situação em que o usuário provavelmente se destina a uma variável para ser declarada, mas o compilador não foi capaz de declarar a variável.  
  
## <a name="example"></a>Exemplo  
 Um `__declspec` atributo no início de uma declaração de tipo definido pelo usuário aplica-se a variável do tipo. C4091 indica que nenhuma variável é declarada. O exemplo a seguir gera C4091.  
  
```  
// C4091.cpp  
// compile with: /W1 /c  
__declspec(dllimport) class X {}; // C4091  
  
// __declspec attribute applies to varX  
__declspec(dllimport) class X2 {} varX;  
  
// __declspec attribute after the class or struct keyword   
// applies to user defined type  
class __declspec(dllimport) X3 {};  
```  
  
## <a name="example"></a>Exemplo  
 Se um identificador é um typedef, ele não pode ser também um nome de variável. O exemplo a seguir gera C4091.  
  
```  
// C4091_b.cpp  
// compile with: /c /W1 /WX  
#define LIST 4  
typedef struct _LIST {} LIST;   // C4091  
```