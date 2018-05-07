---
title: C3005 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3005
dev_langs:
- C++
helpviewer_keywords:
- C3005
ms.assetid: 30bad565-e79f-4c3f-82cb-a74bd0baab8f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 80c0bdb0f17670c5acd178b7eadcbc6d3868637c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3005"></a>C3005 de erro do compilador
'error_text': token inesperado encontrado na diretiva de 'diretiva' OpenMP  
  
 Uma diretiva de OpenMP ill foi formada.  
  
 O exemplo a seguir gera C3005:  
  
```  
// C3005.c  
// compile with: /openmp  
int main()  
{  
   #pragma omp parallel + for   // C3005  
}  
```  
  
 C3005 também pode ocorrer se você colocar uma chave de abertura na mesma linha como o pragma.  
  
```  
// C3005b.c  
// compile with: /openmp  
int main() {  
   #pragma omp parallel {   // C3005 put open brace on next line  
   lbl2:;  
   }  
   goto lbl2;  
}  
```