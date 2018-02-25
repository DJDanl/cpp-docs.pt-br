---
title: Variadic Macros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- variadic macros [C++]
- __VA_ARGS__ variadic macro specifier
ms.assetid: 51e757dc-0134-4bb2-bb74-64ea5ad75134
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a0e3832ab334d31b50edbe0cc1fd5dccbffb61bf
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="variadic-macros"></a>Macros variadic
Macros variadic são macros do tipo função que contêm um número variável de argumentos.  
  
## <a name="remarks"></a>Comentários  
 Para usar macros variadic, no botão de reticências pode ser especificado como o argumento formal final na definição da macro e o identificador de substituição `__VA_ARGS__` pode ser usado na definição de inserir os argumentos adicionais.  `__VA_ARGS__` é substituído por todos os argumentos que correspondem a reticências, incluindo vírgulas entre eles.  
  
 O padrão C especifica que pelo menos um argumento deve ser passado às reticências, para assegurar que a macro não seja resolvida em uma expressão com uma vírgula à direita.  A implementação do Visual C++ suprimirá uma vírgula à direita se nenhum argumento for passado às reticências.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// variadic_macros.cpp  
#include <stdio.h>  
#define EMPTY  
  
#define CHECK1(x, ...) if (!(x)) { printf(__VA_ARGS__); }  
#define CHECK2(x, ...) if ((x)) { printf(__VA_ARGS__); }  
#define CHECK3(...) { printf(__VA_ARGS__); }  
#define MACRO(s, ...) printf(s, __VA_ARGS__)  
  
int main() {  
    CHECK1(0, "here %s %s %s", "are", "some", "varargs1(1)\n");  
    CHECK1(1, "here %s %s %s", "are", "some", "varargs1(2)\n");   // won't print  
  
    CHECK2(0, "here %s %s %s", "are", "some", "varargs2(3)\n");   // won't print  
    CHECK2(1, "here %s %s %s", "are", "some", "varargs2(4)\n");  
  
    // always invokes printf in the macro  
    CHECK3("here %s %s %s", "are", "some", "varargs3(5)\n");  
  
    MACRO("hello, world\n");  
  
    MACRO("error\n", EMPTY); // would cause error C2059, except VC++   
                             // suppresses the trailing comma  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
here are some varargs1(1)  
here are some varargs2(4)  
here are some varargs3(5)  
hello, world  
error  
```  
  
## <a name="see-also"></a>Consulte também  
 [Macros (C/C++)](../preprocessor/macros-c-cpp.md)