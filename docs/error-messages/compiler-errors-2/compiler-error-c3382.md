---
title: C3382 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3382
dev_langs:
- C++
helpviewer_keywords:
- C3382
ms.assetid: a7603abd-ac4e-4ae6-a02b-3bdc6d1908a6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f8bcca58aecc3d5a5e7b621f45e102690c9f138c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33254531"
---
# <a name="compiler-error-c3382"></a>C3382 de erro do compilador
'sizeof' não é suportado com /CLR: safe  
  
 O arquivo de saída de um **/CLR: safe** compilação é um arquivo que é do tipo verificável seguro e sizeof não tem suporte porque o valor de retorno do operador sizeof é size_t, cujo tamanho varia dependendo do sistema operacional.  
  
 Para obter mais informações, consulte  
  
-   [Operador sizeof](../../cpp/sizeof-operator.md)  
  
-   [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3382.  
  
```  
// C3382.cpp  
// compile with: /clr:safe  
int main() {  
   sizeof( char );   // C3382  
}  
```