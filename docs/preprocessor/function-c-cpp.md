---
title: função (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- function_CPP
- vc-pragma.function
dev_langs:
- C++
helpviewer_keywords:
- function pragma
- pragmas, function
ms.assetid: cbd1bd60-fabf-4b5a-9c3d-2d9f4b871365
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1e24dac191e05cc3b47192cb6ec7fb0fc48dd447
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849477"
---
# <a name="function-cc"></a>function (C/C++)
Especifica as chamadas para as funções especificadas na lista de argumentos de pragma que serão geradas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma function( function1 [, function2, ...] )  
```  
  
## <a name="remarks"></a>Comentários  
 Se você usar o **intrínseco** pragma (ou /Oi) para informar ao compilador para gerar funções intrínsecas (funções intrínsecas são geradas como código embutido, não como chamadas de função), você pode usar o **função** pragma para forçar explicitamente uma chamada de função. Após um pragma da função ser considerado, ele entre em vigor na primeira definição de função que contém uma função intrínseca especificada. O efeito continuará até o final do arquivo de origem ou a aparência de um **intrínseco** pragma especificando a mesma função intrínseca. O **função** pragma pode ser usado fora de uma função — no nível global.  
  
 Para obter listas das funções que têm formulários intrínsecos, consulte [#pragma intrínseco](../preprocessor/intrinsic.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// pragma_directive_function.cpp  
#include <ctype.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
// use intrinsic forms of memset and strlen  
#pragma intrinsic(memset, strlen)  
  
// Find first word break in string, and set remaining  
// chars in string to specified char value.  
char *set_str_after_word(char *string, char ch) {  
   int i;  
   int len = strlen(string);  /* NOTE: uses intrinsic for strlen */  
  
   for(i = 0; i < len; i++) {  
      if (isspace(*(string + i)))   
         break;  
   }  
  
   for(; i < len; i++)   
      *(string + i) = ch;  
  
   return string;  
}  
  
// do not use strlen intrinsic  
#pragma function(strlen)  
  
// Set all chars in string to specified char value.  
char *set_str(char *string, char ch) {  
   // Uses intrinsic for memset, but calls strlen library function  
   return (char *) memset(string, ch, strlen(string));  
}  
  
int main() {  
   char *str = (char *) malloc(20 * sizeof(char));  
  
   strcpy_s(str, sizeof("Now is the time"), "Now is the time");  
   printf("str is '%s'\n", set_str_after_word(str, '*'));  
   printf("str is '%s'\n", set_str(str, '!'));  
}  
```  
  
```Output  
str is 'Now************'  
str is '!!!!!!!!!!!!!!!'  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)