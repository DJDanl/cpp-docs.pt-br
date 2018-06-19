---
title: C3383 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3383
dev_langs:
- C++
helpviewer_keywords:
- C3383
ms.assetid: ceb7f725-f417-4dc3-8496-0f413bb76687
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0b54eda0e29a9876da83b9e3da384a39b9345d5d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33251154"
---
# <a name="compiler-error-c3383"></a>C3383 de erro do compilador
'operator new' não é suportado com /CLR: safe  
  
 O arquivo de saída de um **/CLR: safe** compilação é um arquivo que é do tipo verificável seguro e ponteiros não são suportados.  
  
 Para obter mais informações, consulte  
  
-   [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3383.  
  
```  
// C3383.cpp  
// compile with: /clr:safe  
int main() {  
   char* pCharArray = new char[256];  // C3383  
}  
```