---
title: "Compilador aviso (nível 1) C4600 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4600
dev_langs:
- C++
helpviewer_keywords:
- C4600
ms.assetid: f023a2a1-7fc4-463f-a434-dc93fcd3f4e9
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
ms.openlocfilehash: 4c4bef003c613cb1f38b8fa26486b19777b69ea1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4600"></a>Compilador C4600 de aviso (nível 1)
\#pragma 'nome da macro': espera-se uma cadeia de caracteres não vazia  
  
 Você não pode especificar uma cadeia de caracteres vazia quando você enviar por push ou inserir um nome de macro com qualquer um de [pop_macro](../../preprocessor/pop-macro.md) ou [push_macro](../../preprocessor/push-macro.md).  
  
 O exemplo a seguir gera C4600:  
  
```  
// C4600.cpp  
// compile with: /W1  
int main()  
{  
   #pragma push_macro("")   // C4600 passing an empty string  
}  
```
