---
title: pragma de função
ms.date: 08/29/2019
f1_keywords:
- function_CPP
- vc-pragma.function
helpviewer_keywords:
- function pragma
- pragmas, function
ms.assetid: cbd1bd60-fabf-4b5a-9c3d-2d9f4b871365
ms.openlocfilehash: f99f3c878789a6c47fdb0d48e0a8690d65fa8062
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220130"
---
# <a name="function-pragma"></a>pragma de função

Instrui o compilador a gerar chamadas para funções especificadas na lista de argumentos do pragma, em vez de informá-las.

## <a name="syntax"></a>Sintaxe

> **função #pragma (** *function1* [ **,** *function2* ...] **)**

## <a name="remarks"></a>Comentários

Normalmente, as funções intrínsecas são geradas como código embutido, não como chamadas de função. Se você usar o [pragma intrínseco](intrinsic.md) ou a opção de compilador [/Oi](../build/reference/oi-generate-intrinsic-functions.md) para instruir o compilador a gerar funções intrínsecas, poderá usar a **função** pragma para forçar explicitamente uma chamada de função. Depois que uma **função** pragma é vista, ela entra em vigor na primeira definição de função que contém uma função intrínseca especificada. O efeito continua no final do arquivo de origem ou na aparência de um `intrinsic` pragma especificando a mesma função intrínseca. Você só pode usar a **função** pragma fora de uma função, no nível global.

Para obter listas das funções que têm formulários intrínsecos, consulte [pragma intrínseco](intrinsic.md).

## <a name="example"></a>Exemplo

```cpp
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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
