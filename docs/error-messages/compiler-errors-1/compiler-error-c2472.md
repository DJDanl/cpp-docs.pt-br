---
title: C2472 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2472
dev_langs:
- C++
helpviewer_keywords:
- C2472
ms.assetid: 3b36bcdc-2ba5-4357-ab88-7545ba0551cd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5267f20aaed4ebf1c320d3d960684376e29814ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2472"></a>C2472 de erro do compilador
'function' não pode ser gerada no código gerenciado: 'da mensagem'; Compile com /clr para gerar uma imagem mista  
  
 Este erro ocorre quando são usados tipos não compatíveis com o código gerenciado em um ambiente common language runtime (CLR) puro. Compilar com **/clr** para resolver o erro.  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2472.  
  
```  
// C2472.cpp  
// compile with: /clr:pure  
// C2472 expected  
  
#include <cstdlib>  
  
int main()  
{  
   int * __ptr32 p32;  
   int * __ptr64 p64;  
  
   p32 = (int * __ptr32)malloc(4);  
   p64 = p32;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)