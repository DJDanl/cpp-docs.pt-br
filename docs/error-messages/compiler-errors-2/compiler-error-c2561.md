---
title: C2561 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2561
dev_langs:
- C++
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f8ece9a3d9347a5179844cbfca3425870c25e2f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33230897"
---
# <a name="compiler-error-c2561"></a>C2561 de erro do compilador
'Identificador': função deve retornar um valor  
  
 A função foi declarada como retornar um valor, mas a definição da função não tem um `return` instrução.  
  
 Esse erro pode ser causado por um protótipo de função incorreto:  
  
1.  Se a função não retorna um valor, declare a função com o tipo de retorno [void](../../cpp/void-cpp.md).  
  
2.  Verifique se todas as possíveis ramificações da função retornam um valor do tipo declarado no protótipo.  
  
3.  Funções C++ que contém rotinas de assembly embutido que armazena o valor de retorno de `AX` registro terá uma instrução return. Copie o valor no `AX` em uma variável temporária e variável de retorno da função.  
  
 O exemplo a seguir gera C2561:  
  
```  
// C2561.cpp  
int Test(int x) {  
   if (x) {  
      return;   // C2561  
      // try the following line instead  
      // return 1;  
   }  
   return 0;  
}  
  
int main() {  
   Test(1);  
}  
```