---
title: "Compilador aviso (nível 1) C4091 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4091
dev_langs:
- C++
helpviewer_keywords:
- C4091
ms.assetid: 3a404967-ab42-49b0-b324-fd7ba1859d78
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
ms.openlocfilehash: fa247ce7c76524bf2f6d339f6eee527be7e87ae1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4091"></a>Compilador C4091 de aviso (nível 1)
'palavra-chave': ignorado esquerda 'type' quando nenhuma variável é declarada  
  
 O compilador detectou uma situação em que o usuário provavelmente se destina a uma variável a ser declarado, mas o compilador não foi capaz de declarar a variável.  
  
## <a name="example"></a>Exemplo  
 Um `__declspec` atributo no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. C4091 indica que nenhuma variável é declarada. O exemplo a seguir gera C4091.  
  
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
 Se um identificador é um typedef, ela também não pode ser um nome de variável. O exemplo a seguir gera C4091.  
  
```  
// C4091_b.cpp  
// compile with: /c /W1 /WX  
#define LIST 4  
typedef struct _LIST {} LIST;   // C4091  
```
