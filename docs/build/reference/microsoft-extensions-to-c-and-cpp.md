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
ms.openlocfilehash: dab8ac23be8b66ca84c57514c6c04e94dddebaae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321183"
---
# <a name="microsoft-extensions-to-c-and-c"></a>Extensões da Microsoft para C e C++

Visual C++ estende os padrões ANSI C e C++ ANSI da seguinte maneira.

## <a name="keywords"></a>Palavras-chave

Várias palavras-chave são adicionadas. Na lista na [palavras-chave](../../cpp/keywords-cpp.md), as palavras-chave que têm dois sublinhados iniciais são extensões do Visual C++.

## <a name="out-of-class-definition-of-static-const-integral-or-enum-members"></a>Fora da definição de classe de const integral (ou enum) os membros estáticos

Sob o padrão (**/Za**), você deve fazer uma definição fora da classe para membros de dados, como mostrado aqui:

```cpp
class CMyClass  {
   static const int max = 5;
   int m_array[max];
}
// . . .
const int CMyClass::max;   // out of class definition
```

Sob **/Ze**, a definição de fora da classe é opcional para membros de dados static, const integral e const enum. Somente integrais e enumerações que são estáticos e const podem ter inicializadores em uma classe; a expressão de inicialização deve ser uma expressão de constante.

Para evitar erros quando uma definição fora da classe é fornecida em um cabeçalho de arquivo e o arquivo de cabeçalho é incluído em vários arquivos de origem, use [selectany](../../cpp/selectany.md). Por exemplo:

```cpp
__declspec(selectany) const int CMyClass::max = 5;
```

## <a name="casts"></a>Conversões

O compilador C++ e o compilador C dão suporte a esses tipos de conversões de não-ANSI:

- Conversões de não-ANSI para produzir um l-values. Por exemplo:

   ```C
   char *p;
   (( int * ) p )++;
   ```

   > [!NOTE]
   > Esta extensão está disponível na linguagem C somente. Você pode usar o seguinte formato de padrão ANSI C em código C++ para modificar um ponteiro como se fosse um ponteiro para um tipo diferente.

   O exemplo anterior poderia ser reescrito da seguinte maneira para estar de acordo com o padrão ANSI C.

   ```C
   p = ( char * )(( int * )p + 1 );
   ```

- Conversões de não-ANSI de um ponteiro de função para um ponteiro de dados. Por exemplo:

   ```C
   int ( * pfunc ) ();
   int *pdata;
   pdata = ( int * ) pfunc;
   ```

   Para executar a mesma conversão e também manter a compatibilidade com ANSI, você pode converter o ponteiro de função para um `uintptr_t` antes de convertê-lo em um ponteiro de dados:

   ```C
   pdata = ( int * ) (uintptr_t) pfunc;
   ```

## <a name="variable-length-argument-lists"></a>Listas de argumentos de comprimento variável

O compilador C++ e o compilador C dão suporte a um Declarador de função que especifica um número variável de argumentos, seguido por uma definição de função que fornece um tipo em vez disso:

```cpp
void myfunc( int x, ... );
void myfunc( int x, char * c )
{ }
```

## <a name="single-line-comments"></a>Comentários de linha única

O compilador C oferece suporte a comentários de linha única, que são apresentados usando dois barra invertida (/ /) caracteres:

```C
// This is a single-line comment.
```

## <a name="scope"></a>Escopo

O compilador de C suporta os seguintes recursos de escopo.

- Redefinições de itens de extern como estática:

   ```C
   extern int clip();
   static int clip()
   {}
   ```

- Uso de redefinições de typedef benigno dentro do mesmo escopo:

   ```C
   typedef int INT;
   typedef int INT;
   ```

- Declaradores de função têm escopo de arquivo:

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

- Uso de variáveis de escopo de bloco que são inicializados usando expressões não constantes:

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

O compilador de C suporta os seguintes recursos de declaração e a definição de dados.

- Constantes de caractere e cadeia de caracteres mistos em um inicializador:

   ```C
   char arr[5] = {'a', 'b', "cde"};
   ```

- Que têm tipos base diferentes de campos de bits **int sem sinal** ou **assinado int**.

- Declaradores que não têm um tipo:

   ```C
   x;
   int main( void )
   {
       x = 1;
   }
   ```

- Matrizes sem dimensões como o último campo em estruturas e uniões:

   ```C
   struct zero
   {
       char *c;
       int zarray[];
   };
   ```

- Estruturas (anônimas) sem nome:

   ```C
   struct
   {
       int i;
       char *s;
   };
   ```

- Uniões (anônimas) sem nome:

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

## <a name="intrinsic-floating-point-functions"></a>Funções intrínsecas de ponto flutuantes

Ambos os x86 compilador C++ e o compilador C dão suporte à geração de embutido do `atan`, `atan2`, `cos`, `exp`, `log`, `log10`, `sin`, `sqrt`, e `tan` funções quando **/Oi** for especificado. Para o compilador C, conformidade com ANSI é perdida quando esses intrínsecos são usados, porque eles não definirem o `errno` variável.

## <a name="passing-a-non-const-pointer-parameter-to-a-function-that-expects-a-reference-to-a-const-pointer-parameter"></a>Passando um parâmetro de ponteiro não const para uma função que espera uma referência a um parâmetro de ponteiro const

Isso é uma extensão do C++. Esse código será compilado com **/Ze**:

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

Sob **/Ze**, você tem que incluir lt;iso646.h&gt Se você quiser usar formas de texto dos seguintes operadores:

- & & (e)

- & = (and_eq)

- & (bitand)

- &#124;(bitor)

- ~ (compl)

- ! (não)

- != (not_eq)

- &#124;&#124;(ou)

- &#124;= (or_eq)

- ^ (xor)

- ^= (xor_eq)

## <a name="address-of-string-literal-has-type-const-char--not-const-char--"></a>Endereço da cadeia de caracteres literal tem tipo const char [], não const char (*)]

O exemplo a seguir produzirá `char const (*)[4]` sob **/Za**, mas `char const [4]` sob **/Ze**.

```cpp
#include <stdio.h>
#include <typeinfo>

int main()
{
    printf_s("%s\n", typeid(&"abc").name());
}
```

## <a name="see-also"></a>Consulte também

- [/Za, /Ze (desabilitar extensões de linguagem)](za-ze-disable-language-extensions.md)
- [Opções do compilador MSVC](compiler-options.md)
- [Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
