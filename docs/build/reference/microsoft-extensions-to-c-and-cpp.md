---
title: Extensões da Microsoft para C e C++
ms.date: 06/14/2018
helpviewer_keywords:
- or_eq operator
- ~ operator, extensions to C/C++
- '& operator, extensions to C/C++'
- '&= operator'
- iso646.h header
- Xor operator, Microsoft extensions to C/C++
- '!= operator'
- '! operator, extension to C++'
- Or operator, Microsoft extensions to C/C++
- ^ operator, extensions to C/C++
- ^= operator, C++ extensions
- xor_eq operator
- and_eq operator
- Microsoft extensions to C/C++
- '|= operator'
- '|| operator'
- And operator, extensions to C/C++
- NOT operator
- '&& operator'
- extensions, C language
- Visual C++, extensions to C/C++
- '| operator, extensions'
- not_eq operator
- Visual C, Microsoft extensions
- extensions
- compl method
ms.assetid: e811a74a-45ba-4c00-b206-2f2321b8689a
ms.openlocfilehash: 77f2ed64a0c816d84e67f66b664141581a9fad51
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231501"
---
# <a name="microsoft-extensions-to-c-and-c"></a>Extensões da Microsoft para C e C++

Visual C++ estende os padrões ANSI C e ANSI C++ da seguinte maneira.

## <a name="keywords"></a>Palavras-chave

Várias palavras-chave são adicionadas. Na lista em [palavras-chave](../../cpp/keywords-cpp.md), as palavras-chave que têm dois sublinhados à esquerda são Visual C++ extensões.

## <a name="out-of-class-definition-of-static-const-integral-or-enum-members"></a>Definição fora de classe de membros de const integral (ou Enumeração) estáticos

Sob o padrão (**/za**), você deve fazer uma definição fora de classe para membros de dados, como mostrado aqui:

```cpp
class CMyClass  {
   static const int max = 5;
   int m_array[max];
}
// . . .
const int CMyClass::max;   // out of class definition
```

Em **/ze**, a definição fora de classe é opcional para membros de dados de enumeração static, const integral e const. Somente os integrantes e as enumerações que são static e const podem ter inicializadores em uma classe; a expressão de inicialização deve ser uma expressão const.

Para evitar erros quando uma definição fora de classe é fornecida em um arquivo de cabeçalho e o arquivo de cabeçalho está incluído em vários arquivos de origem, use [selectany](../../cpp/selectany.md). Por exemplo:

```cpp
__declspec(selectany) const int CMyClass::max = 5;
```

## <a name="casts"></a>Conversões

Tanto o compilador C++ quanto o compilador C dão suporte a esses tipos de conversões não-ANSI:

- Conversões não-ANSI para produzir valores l. Por exemplo:

   ```C
   char *p;
   (( int * ) p )++;
   ```

   > [!NOTE]
   > Essa extensão está disponível somente na linguagem C. Você pode usar o seguinte formulário padrão ANSI C no código C++ para modificar um ponteiro como se fosse um ponteiro para um tipo diferente.

   O exemplo anterior poderia ser reescrito da seguinte maneira para estar de acordo com o padrão ANSI C.

   ```C
   p = ( char * )(( int * )p + 1 );
   ```

- Conversões não-ANSI de um ponteiro de função para um ponteiro de dados. Por exemplo:

   ```C
   int ( * pfunc ) ();
   int *pdata;
   pdata = ( int * ) pfunc;
   ```

   Para executar a mesma conversão e também manter a compatibilidade com ANSI, você pode converter o ponteiro de função em um `uintptr_t` antes de convertê-lo em um ponteiro de dados:

   ```C
   pdata = ( int * ) (uintptr_t) pfunc;
   ```

## <a name="variable-length-argument-lists"></a>Listas de argumentos de comprimento variável

Tanto o compilador C++ quanto o compilador C dão suporte a um Declarador de função que especifica um número variável de argumentos, seguido por uma definição de função que fornece um tipo, em vez disso:

```cpp
void myfunc( int x, ... );
void myfunc( int x, char * c )
{ }
```

## <a name="single-line-comments"></a>Comentários de única linha

O compilador C dá suporte a comentários de linha única, que são introduzidos usando dois caracteres de barra (//):

```C
// This is a single-line comment.
```

## <a name="scope"></a>Escopo

O compilador C dá suporte aos seguintes recursos relacionados ao escopo.

- Redefinições de itens extern como estáticos:

   ```C
   extern int clip();
   static int clip()
   {}
   ```

- Uso de redefinições de typedef benignos dentro do mesmo escopo:

   ```C
   typedef int INT;
   typedef int INT;
   ```

- Os declaradores de função têm escopo de arquivo:

   ```C
   void func1()
   {
       extern int func2( double );
   }
   int main( void )
   {
       func2( 4 );    //  /Ze passes 4 as type double
   }                  //  /Za passes 4 as type int
   ```

- Uso de variáveis de escopo de bloco que são inicializadas usando expressões não constantes:

   ```C
   int clip( int );
   int bar( int );
   int main( void )
   {
       int array[2] = { clip( 2 ), bar( 4 ) };
   }
   int clip( int x )
   {
       return x;
   }
   int bar( int x )
   {
       return x;
   }
   ```

## <a name="data-declarations-and-definitions"></a>Definições e declarações de dados

O compilador C dá suporte à declaração de dados e aos recursos de definição a seguir.

- Caracteres mistos e constantes de cadeia de caracteres em um inicializador:

   ```C
   char arr[5] = {'a', 'b', "cde"};
   ```

- Campos de bits que têm tipos base diferentes de **`unsigned int`** ou **`signed int`** .

- Declaradores que não têm um tipo:

   ```C
   x;
   int main( void )
   {
       x = 1;
   }
   ```

- Matrizes não dimensionadas como o último campo em estruturas e uniões:

   ```C
   struct zero
   {
       char *c;
       int zarray[];
   };
   ```

- Estruturas não nomeadas (anônimas):

   ```C
   struct
   {
       int i;
       char *s;
   };
   ```

- Unnameed (anônimo) uniões:

   ```C
   union
   {
       int i;
       float fl;
   };
   ```

- Membros sem nome:

   ```C
   struct s
   {
      unsigned int flag : 1;
      unsigned int : 31;
   }
   ```

## <a name="intrinsic-floating-point-functions"></a>Funções intrínsecas de ponto flutuante

Tanto o compilador C++ x86 quanto o compilador C dão suporte à geração embutida das funções,,,,,,, `atan` `atan2` `cos` `exp` `log` `log10` `sin` `sqrt` e `tan` quando **/Oi** é especificado. Para o compilador C, a conformidade com ANSI é perdida quando esses intrínsecos são usados, pois eles não definem a `errno` variável.

## <a name="passing-a-non-const-pointer-parameter-to-a-function-that-expects-a-reference-to-a-const-pointer-parameter"></a>Passando um parâmetro de ponteiro não const para uma função que espera uma referência a um parâmetro de ponteiro const

Esta é uma extensão para C++. Este código será compilado com **/ze**:

```cpp
typedef   int   T;

const T  acT = 9;      // A constant of type 'T'
const T* pcT = &acT;   // A pointer to a constant of type 'T'

void func2 ( const T*& rpcT )   // A reference to a pointer to a constant of type 'T'
{
   rpcT = pcT;
}

T*   pT;               // A pointer to a 'T'

void func ()
{
   func2 ( pT );      // Should be an error, but isn't detected
   *pT   = 7;         // Invalidly overwrites the constant 'acT'
}
```

## <a name="iso646h-not-enabled"></a>ISO646. H não habilitado

Em **/ze**, você precisa incluir iso646. h se quiser usar as formas de texto dos seguintes operadores:

- && (e)

- &= (and_eq)

- & (bitand)

- &#124; (BITOR)

- ~ (compl)

- ! válido

- ! = (not_eq)

- &#124;&#124; (ou)

- &#124;= (or_eq)

- ^ (XOR)

- ^ = (xor_eq)

## <a name="address-of-string-literal-has-type-const-char--not-const-char--"></a>O endereço do literal da cadeia de caracteres tem o tipo const char [], não const char (*) []

O exemplo a seguir fará a saída `char const (*)[4]` em **/za**, mas `char const [4]` em **/ze**.

```cpp
#include <stdio.h>
#include <typeinfo>

int main()
{
    printf_s("%s\n", typeid(&"abc").name());
}
```

## <a name="see-also"></a>Confira também

- [/Za,/Ze (desabilitar extensões de linguagem)](za-ze-disable-language-extensions.md)
- [Opções do compilador MSVC](compiler-options.md)
- [Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
