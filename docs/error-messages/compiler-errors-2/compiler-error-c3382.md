---
title: C3382 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3382
dev_langs:
- C++
helpviewer_keywords:
- C3382
ms.assetid: a7603abd-ac4e-4ae6-a02b-3bdc6d1908a6
caps.latest.revision: 3
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
ms.openlocfilehash: 878c506765af9c7c0284546984b04371ad92d407
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3382"></a>C3382 de erro do compilador
'sizeof' não é suportado com /clr:safe  
  
 O arquivo de saída de um **/CLR: safe** compilação é um arquivo que é comprovadamente fortemente tipado e sizeof não tem suporte porque o valor de retorno do operador sizeof é size_t, cujo tamanho varia dependendo do sistema operacional.  
  
 Para obter mais informações, consulte  
  
-   [Operador sizeof](../../cpp/sizeof-operator.md)  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C++](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3382.  
  
```  
// C3382.cpp  
// compile with: /clr:safe  
int main() {  
   sizeof( char );   // C3382  
}  
```
