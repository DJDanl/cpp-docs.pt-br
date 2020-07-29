---
title: Funções com listas de argumentos variáveis (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- arguments [C++], variable number of
- variable argument lists
- declarators, functions
- argument lists [C++], variable number of
- declaring functions [C++], variables
- function calls, variable number of arguments
ms.assetid: 27c2f83a-21dd-44c6-913c-2834cb944703
ms.openlocfilehash: 99f1f5cec2350f99bf2993947870f25e357ffc23
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213418"
---
# <a name="functions-with-variable-argument-lists--c"></a>Funções com listas de argumentos variáveis (C++)

Declarações de função em que o último membro de é reticências (...) podem usar um número variável de argumentos. Nesses casos, o C++ fornece verificação de tipo apenas para os argumentos explicitamente declarados. Você pode usar listas de argumentos variáveis quando precisar criar uma função tão geral que mesmo o número e os tipos de argumentos possam variar. A família de funções é um exemplo de funções que usam listas de argumentos variáveis. `printf` *declaração de argumento-lista*

## <a name="functions-with-variable-arguments"></a>Funções com argumentos variáveis

Para acessar argumentos depois daqueles declarados, use as macros contidas no arquivo de inclusão padrão, \<stdarg.h> conforme descrito abaixo.

**Específico da Microsoft**

O Microsoft C++ permite que as reticências sejam especificadas como um argumento se as reticências forem o último argumento e se forem precedidas por uma vírgula. Consequentemente, a declaração `int Func( int i, ... );` é válida, mas `int Func( int i ... );` não é.

**FINAL específico da Microsoft**

A declaração de uma função que pega um número variável de argumentos que requer pelo menos um argumento de espaço reservado, mesmo se não for usado. Se esse argumento de espaço reservado não for fornecido, não há como acessar os argumentos restantes.

Quando argumentos do tipo **`char`** são passados como argumentos variáveis, eles são convertidos em tipo **`int`** . Da mesma forma, quando argumentos do tipo **`float`** são passados como argumentos variáveis, eles são convertidos em tipo **`double`** . Os argumentos de outros tipos estão sujeitos às promoções integral e de ponto flutuante comuns. Consulte [conversões padrão](standard-conversions.md) para obter mais informações.

As funções que exigem listas de variáveis são declaradas usando as reticências (...) na lista de argumentos. Use os tipos e macros descritos no \<stdarg.h> arquivo include para acessar os argumentos que são passados por uma lista de variáveis. Para obter mais informações sobre essas macros, consulte [va_arg, va_copy, va_end va_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md). na documentação da biblioteca de tempo de execução do C.

O exemplo a seguir mostra como as macros funcionam em conjunto com o tipo (declarado em \<stdarg.h> ):

```cpp
// variable_argument_lists.cpp
#include <stdio.h>
#include <stdarg.h>

//  Declaration, but not definition, of ShowVar.
void ShowVar( char *szTypes, ... );
int main() {
   ShowVar( "fcsi", 32.4f, 'a', "Test string", 4 );
}

//  ShowVar takes a format string of the form
//   "ifcs", where each character specifies the
//   type of the argument in that position.
//
//  i = int
//  f = float
//  c = char
//  s = string (char *)
//
//  Following the format specification is a variable
//  list of arguments. Each argument corresponds to
//  a format character in the format string to which
// the szTypes parameter points
void ShowVar( char *szTypes, ... ) {
   va_list vl;
   int i;

   //  szTypes is the last argument specified; you must access
   //  all others using the variable-argument macros.
   va_start( vl, szTypes );

   // Step through the list.
   for( i = 0; szTypes[i] != '\0'; ++i ) {
      union Printable_t {
         int     i;
         float   f;
         char    c;
         char   *s;
      } Printable;

      switch( szTypes[i] ) {   // Type to expect.
         case 'i':
            Printable.i = va_arg( vl, int );
            printf_s( "%i\n", Printable.i );
         break;

         case 'f':
             Printable.f = va_arg( vl, double );
             printf_s( "%f\n", Printable.f );
         break;

         case 'c':
             Printable.c = va_arg( vl, char );
             printf_s( "%c\n", Printable.c );
         break;

         case 's':
             Printable.s = va_arg( vl, char * );
             printf_s( "%s\n", Printable.s );
         break;

         default:
         break;
      }
   }
   va_end( vl );
}
//Output:
// 32.400002
// a
// Test string
```

O exemplo anterior ilustra estes conceitos importantes:

1. Você deve estabelecer um marcador de lista como uma variável de tipo `va_list` antes que argumentos de variáveis sejam acessados. No exemplo anterior, o marcador é chamado `vl`.

1. Os argumentos individuais são acessados usando a macro `va_arg`. Você deve informar à macro `va_arg` o tipo de argumento a ser recuperado para que ela possa transferir o número de bytes correto da pilha. Se você especificar um tipo incorreto de um tamanho diferente do fornecido pelo programa de chamada para `va_arg`, os resultados serão imprevisíveis.

1. É necessário converter explicitamente o resultado obtido usando a macro `va_arg` no tipo desejado.

Você deve chamar a macro  para encerrar o processamento de argumento de variáveis.`va_end`
