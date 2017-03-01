---
title: "Compilador aviso (nível 3) C4191 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4191
dev_langs:
- C++
helpviewer_keywords:
- C4191
ms.assetid: 576d3bc6-95b7-448a-af31-5d798452df09
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0b0830225da8b837eace1029f8a2213717ca7b49
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4191"></a>C4191 do compilador aviso (nível 3)
' operator/operation': conversão não segura de 'tipo de expressão' para 'type required'  
  
 Diversas operações que envolvem ponteiros de função são consideradas seguras:  
  
-   Tipos de função com diferentes convenções de chamada.  
  
-   Tipos de função com diferentes convenções de retornos.  
  
-   Tipos de argumento ou retorno com classificações, categorias de tipos ou tamanhos diferentes.  
  
-   Tamanhos de lista de argumento diferentes (em `__cdecl`, somente na conversão de lista mais longa lista mais curto, mesmo se for mais curto é varargs).  
  
-   Ponteiro para dados (diferente de **void\***) com alias em relação a um ponteiro para função.  
  
-   Outra diferença de tipo que gerará um erro ou aviso em um `reinterpret_cast`.  
  
 Chamar essa função através do ponteiro de resultado pode causar o programa falhe.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4191:  
  
```  
// C4191.cpp  
// compile with: /W3 /clr  
#pragma warning(default: 4191)  
  
void __clrcall f1() { }  
void __cdecl   f2() { }  
  
typedef void (__clrcall * fnptr1)();  
typedef void (__cdecl   * fnptr2)();  
  
int main() {  
   fnptr1 fp1 = static_cast<fnptr1>(&f1);  
   fnptr2 fp2 = (fnptr2) &f2;  
  
   fnptr1 fp3 = (fnptr1) &f2;   // C4191  
   fnptr2 fp4 = (fnptr2) &f1;   // C4191  
};  
```
