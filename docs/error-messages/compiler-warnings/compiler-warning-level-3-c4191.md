---
title: Compilador aviso (nível 3) C4191 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4191
dev_langs:
- C++
helpviewer_keywords:
- C4191
ms.assetid: 576d3bc6-95b7-448a-af31-5d798452df09
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 892bf76a8480e573a71e768fbe24778e7e66f88b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33291486"
---
# <a name="compiler-warning-level-3-c4191"></a>Compilador C4191 de aviso (nível 3)
' operador/operação': conversão não segura de 'tipo de expressão' para 'tipo necessário'  
  
 Várias operações envolvendo ponteiros de função são consideradas inseguras:  
  
-   Tipos de função com as convenções de chamada diferentes.  
  
-   Tipos de função com as convenções de retorno diferentes.  
  
-   Tipos de argumento ou retorno com classificações, categorias de tipos ou tamanhos diferentes.  
  
-   Comprimentos diferentes de lista de argumento (em `__cdecl`, somente na conversão da lista mais longa para a lista mais curto, mesmo se for mais curto é varargs).  
  
-   Ponteiro para dados (diferente de **void\***) um alias em relação a um ponteiro para função.  
  
-   Outra diferença de tipo que gerará um erro ou aviso em um `reinterpret_cast`.  
  
 Chamar essa função através do ponteiro resultante pode causar a falha do programa.  
  
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