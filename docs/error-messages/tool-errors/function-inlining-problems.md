---
title: "Problemas de Inlining da função | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
ms.openlocfilehash: 7f29cb8fb61dfc9f50cc5677e0d4f18f83627cdb
ms.lasthandoff: 02/25/2017

---
# <a name="function-inlining-problems"></a>Problemas de inlining da função
Se você estiver usando o inlining de função, você deve:  
  
-   Ter as funções embutidas implementadas no arquivo de cabeçalho que você incluir.  
  
-   Ter inlining ligados no arquivo de cabeçalho.  
  
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
  
 Se você estiver usando o `#pragma inline_depth` compilador diretiva, verifique se você tem um valor maior ou igual a 2 definido. Um valor de zero será desligado inlining. Verifique também se você estiver usando o **/Ob1** ou **/Ob2** opções do compilador.  
  
 Combinação de opções de compilação embutido e não embutida em módulos diferentes, às vezes, pode causar problemas. Se uma biblioteca C++ é criada pela função inlining ativada ([/Ob1](../../build/reference/ob-inline-function-expansion.md) ou [/Ob2](../../build/reference/ob-inline-function-expansion.md)), mas o correspondente arquivo de cabeçalho que descreve as funções tiver inlining desativado (nenhuma opção), você receberá o erro LNK2001. As funções não obter embutidas no código do arquivo de cabeçalho, mas uma vez que eles não estão no arquivo de biblioteca não há nenhum endereço para resolver a referência.  
  
 Da mesma forma, um projeto que usa a função inlining ainda define as funções em um arquivo. cpp em vez de no cabeçalho do arquivo também obterá LNK2019. O arquivo de cabeçalho é incluído em todos os lugares considerado apropriado, mas as funções são apenas embutida quando o arquivo. cpp passa pelo compilador. Portanto, o vinculador vê as funções como externos não resolvidos quando usados em outros módulos.  
  
```  
// LNK2019_FIP.h  
struct testclass {  
   void PublicStatMemFunc1(void);  
};  
```  
  
 e, em seguida,  
  
```  
// LNK2019_FIP.cpp  
// compile with: /c  
#include "LNK2019_FIP.h"  
inline void testclass::PublicStatMemFunc1(void) {}  
```  
  
 e, em seguida,  
  
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
