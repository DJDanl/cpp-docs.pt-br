---
title: Problemas de Inlining da função | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- /Ob1 C++ compiler option
- inline functions, problems
- -Ob1 C++ compiler option
- /Ob2 C++ compiler option
- -Ob2 C++ compiler option
- function inlining problems
ms.assetid: 65d59943-4b3c-4a43-aeb6-dccbf7686740
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 97ffa56fc748eea8f65f5fe79c7a9defa7238f82
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="function-inlining-problems"></a>Problemas de inlining da função
Se você estiver usando inlining de função, você deve:  
  
-   Ter as funções embutidas implementadas no arquivo de cabeçalho que você incluir.  
  
-   Ter inlining ativadas no arquivo de cabeçalho.  
  
```  
// LNK2019_function_inline.cpp  
// compile with: /c   
// post-build command: lib LNK2019_function_inline.obj  
#include <stdio.h>  
struct _load_config_used {  
   void Test();  
   void Test2() { printf("in Test2\n"); }  
};  
  
void _load_config_used::Test() { printf("in Test\n"); }  
```  
  
 E, em seguida,  
  
```  
// LNK2019_function_inline_2.cpp  
// compile with: LNK2019_function_inline.lib  
struct _load_config_used {  
   void Test();  
   void Test2();  
};  
  
int main() {  
   _load_config_used x;  
   x.Test();  
   x.Test2();   // LNK2019  
}  
```  
  
 Se você estiver usando o `#pragma inline_depth` compilador diretiva, não se esqueça você tiver um valor maior ou igual a 2 definida. Um valor de zero desativa inlining. Verifique também se você estiver usando o **/Ob1** ou **/Ob2** opções do compilador.  
  
 Combinação de opções de compilação embutido e não embutido em módulos diferentes pode causar problemas. Se uma biblioteca C++ é criada com a função inlining ativada ([/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md)), mas o arquivo de cabeçalho que descrevem as funções tiver inlining desativado (nenhuma opção), você receberá o erro LNK2001. As funções não obter embutidas no código do arquivo de cabeçalho, mas como eles não estão no arquivo de biblioteca não há nenhum endereço para resolver a referência.  
  
 Da mesma forma, um projeto que usa a função inlining ainda define as funções em um arquivo. cpp em vez de no cabeçalho de arquivo também obterá LNK2019. O arquivo de cabeçalho é incluído em todos os lugares for apropriado, mas as funções são apenas embutida quando o arquivo. cpp passa pelo compilador; Portanto, o vinculador considera as funções não resolvidos externos quando usada em outros módulos.  
  
```  
// LNK2019_FIP.h  
struct testclass {  
   void PublicStatMemFunc1(void);  
};  
```  
  
 E, em seguida,  
  
```  
// LNK2019_FIP.cpp  
// compile with: /c  
#include "LNK2019_FIP.h"  
inline void testclass::PublicStatMemFunc1(void) {}  
```  
  
 E, em seguida,  
  
```  
// LNK2019_FIP_2.cpp  
// compile with: LNK2019_FIP.cpp  
// LNK2019 expected  
#include "LNK2019_FIP.h"  
int main() {  
   testclass testclsObject;  
  
   // module cannot see the implementation of PublicStatMemFunc1  
   testclsObject.PublicStatMemFunc1();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md)