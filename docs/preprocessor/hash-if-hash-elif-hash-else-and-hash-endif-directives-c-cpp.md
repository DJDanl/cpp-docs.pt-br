---
title: '#Diretivas if, #elif, #else e #endif (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#else'
- '#endif'
- '#if'
- '#elif'
- defined
- __has_include
helpviewer_keywords:
- '#elif directive'
- conditional compilation, directives
- endif directive (#endif)
- preprocessor, directives
- '#else directive'
- '#endif directive'
- if directive (#if)
- else directive (#else)
- '#if directive'
- elif directive (#elif)
- defined directive
ms.assetid: c77a175f-6ca8-47d4-8df9-7bac5943d01b
ms.openlocfilehash: 2b7ed4733dcafda793b9a945c3f40739b52e040a
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220347"
---
# <a name="if-elif-else-and-endif-directives-cc"></a>#if, #elif, #else e diretivas de #endif (C/C++)

A diretiva **#if** , com as diretivas **#elif**, **#else**e **#endif** , controla a compilação de partes de um arquivo de origem. Se a expressão que você escreve (depois da **#if**) tiver um valor diferente de zero, o grupo de linhas imediatamente após a diretiva de **#if** será mantido na unidade de tradução.

## <a name="grammar"></a>Gramática

*condicional* : \
&nbsp;&nbsp;&nbsp;&nbsp;*elementos de If-Part elif-Parts* <sub>aceitar</sub> *parte else* <sub>aceitar</sub> *endif-linha*

*If-Part* : \
&nbsp;&nbsp;&nbsp;&nbsp;*texto de If-line*

*If-line* : \
&nbsp;&nbsp;&nbsp;&nbsp; **#if** *expressão de constante*\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifdef** *identificador* do\
&nbsp;&nbsp;&nbsp;&nbsp; **#ifndef** *identifier*

*elif-partes* : \
&nbsp;&nbsp;&nbsp;&nbsp;*elif-texto de linha*\
&nbsp;&nbsp;&nbsp;&nbsp;*elif-Parts elif-texto da linha*

*elif-linha* : \
&nbsp;&nbsp;&nbsp;&nbsp; **#elif**  *constant-expression*

*else-parte* : \
&nbsp;&nbsp;&nbsp;&nbsp;*texto de linha else*

*else-linha* : \
&nbsp;&nbsp;&nbsp;&nbsp; **#else**

*endif-linha* : \
&nbsp;&nbsp;&nbsp;&nbsp; **#endif**

## <a name="remarks"></a>Comentários

Cada diretiva de **#if** em um arquivo de origem deve ser correspondida por uma diretiva de **#endif** de fechamento. Qualquer número de diretivas de **#elif** pode aparecer entre as diretivas **#if** e **#endif** , mas no máximo uma diretiva **#else** é permitida. A diretiva **#else** , se presente, deve ser a última diretiva antes de **#endif**.

As diretivas **#if**, **#elif**, **#else**e **#endif** podem se aninhar nas partes de *texto* de outras diretivas de **#if** . Cada diretiva **#else**aninhada, **#elif**ou **#endif** pertence à diretiva **#if** anterior mais próxima.

Todas as diretivas de compilação condicional, como **#if** e **#ifdef**, devem corresponder a uma diretiva de fechamento **#endif** antes do final do arquivo. Caso contrário, uma mensagem de erro será gerada. Quando as diretivas de compilação condicional estão contidas nos arquivos de inclusão, elas devem atender às mesmas condições: Não deve haver diretivas de compilação condicional sem correspondência no final do arquivo de inclusão.

A substituição de macro é feita dentro da parte da linha que segue um comando **#elif** , portanto, uma chamada de macro pode ser usada na *expressão Constant*.

O pré-processador seleciona uma das ocorrências de *texto* determinadas para processamento adicional. Um bloco especificado no *texto* pode ser qualquer sequência de texto. Ele pode ocupar mais de uma linha. Normalmente, o *texto* é um texto de programa que tem significado para o compilador ou o pré-processador.

O pré-processador processa o *texto* selecionado e o passa para o compilador. Se o *texto* contiver diretivas de pré-processador, o pré-processador executará essas diretivas. Somente os blocos de texto selecionados pelo pré-processador são compilados.

O pré-processador seleciona um único item de *texto* , avaliando a expressão constante seguindo cada **#if** ou diretiva de **#elif** até encontrar uma expressão constante verdadeira (diferente de zero). Ele seleciona todo o texto (incluindo as demais diretivas de pré-processador começando **#** com) até seu **#elif**associado, **#else**ou **#endif**.

Se todas as ocorrências de *expressão de constante* forem false ou se nenhuma **#elif** diretivas aparecer, o pré-processador selecionará o bloco de texto após a cláusula **#else** . Quando não há nenhuma cláusula **#else** e todas as instâncias de *expressão constante* no bloco de **#if** são false, nenhum bloco de texto é selecionado.

A *expressão de constante* é uma expressão de constante inteira com estas restrições adicionais:

- As expressões devem ter um tipo integral e podem incluir apenas constantes de inteiro, constantes de caractere e o operador **definido** .

- A expressão não pode `sizeof` usar ou um operador de conversão de tipo.

- O ambiente de destino pode não ser capaz de representar todos os intervalos de inteiros.

- A tradução representa o tipo **int** da mesma maneira que o tipo **Long**, e o **int não assinado** da mesma maneira que o **Long não assinado**.

- O tradutor pode traduzir a constante de caracteres como um conjunto de valores de código diferentes do conjunto para o ambiente de destino. Para determinar as propriedades do ambiente de destino, use um aplicativo criado para esse ambiente para verificar os valores dos *limites.* Macros H.

- A expressão não deve consultar o ambiente e deve permanecer isolado dos detalhes de implementação no computador de destino.

## <a name="preprocessor-operators"></a>Operadores do pré-processador

### <a name="defined"></a>definido

O operador de pré-processador **definido** pode ser usado em expressões de constantes especiais, conforme mostrado pela seguinte sintaxe:

> **definido (** *identificador* **)** \
> **definido** *identificador* do

Essa expressão constante é considerada true (diferente de zero) se o *identificador* estiver definido no momento. Caso contrário, a condição será false (0). Um identificador definido como texto vazio é considerado definido. O operador **definido** pode ser usado em um **#if** e uma diretiva de **#elif** , mas em outro lugar.

No exemplo a seguir, as diretivas **#if** e **#endif** controlam a compilação de uma das três chamadas de função:

```C
#if defined(CREDIT)
    credit();
#elif defined(DEBIT)
    debit();
#else
    printerror();
#endif
```

A chamada de função para `credit` será compilada se o identificador `CREDIT` estiver definido. Se o identificador `DEBIT` estiver definido, a chamada de função para `debit` será compilada. Se nenhum identificador for definido, a chamada para `printerror` será compilada. Ambos `CREDIT` e `credit` são identificadores distintos em C C++ e porque seus casos são diferentes.

As instruções de compilação condicional no exemplo a seguir pressupõem uma constante simbólica definida anteriormente denominada `DLEVEL`.

```C
#if DLEVEL > 5
    #define SIGNAL  1
    #if STACKUSE == 1
        #define STACK   200
    #else
        #define STACK   100
    #endif
#else
    #define SIGNAL  0
    #if STACKUSE == 1
        #define STACK   100
    #else
        #define STACK   50
    #endif
#endif
#if DLEVEL == 0
    #define STACK 0
#elif DLEVEL == 1
    #define STACK 100
#elif DLEVEL > 5
    display( debugptr );
#else
    #define STACK 200
#endif
```

O primeiro bloco **#if** mostra dois conjuntos de diretivas aninhadas **#if**, **#else**e **#endif** . O primeiro conjunto de políticas será processado somente se `DLEVEL > 5` for verdadeiro. Caso contrário, as instruções após **#else** são processadas.

As diretivas **#elif** e **#else** no segundo exemplo são usadas para fazer uma das quatro opções, com base no valor de `DLEVEL`. A constante `STACK` é definida como 0, 100 ou 200, dependendo da definição de `DLEVEL`. Se `DLEVEL` for maior que 5, a declaração

```C
#elif DLEVEL > 5
display(debugptr);
```

é compilado e `STACK` não é definido.

A compilação condicional é usada normalmente para evitar várias inclusões do mesmo arquivo de cabeçalho. No C++, onde as classes geralmente são definidas em arquivos de cabeçalho, construções como esta podem ser usadas para impedir várias definições:

```cpp
/*  EXAMPLE.H - Example header file  */
#if !defined( EXAMPLE_H )
#define EXAMPLE_H

class Example
{
    //...
};

#endif // !defined( EXAMPLE_H )
```

O código acima verifica se a constante `EXAMPLE_H` foi definida. Nesse caso, o arquivo já foi incluído e não precisa ser reprocessado. Caso contrário, a constante `EXAMPLE_H` será definida para marcar EXAMPLE.H como já processado.

### <a name="__has_include"></a>__has_include

**Visual Studio 2017 versão 15.3 e posteriores**:  Determina se um cabeçalho de biblioteca está disponível para inclusão:

```cpp
#ifdef __has_include
#  if __has_include(<filesystem>)
#    include <filesystem>
#    define have_filesystem 1
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
#    define have_filesystem 1
#    define experimental_filesystem
#  else
#    define have_filesystem 0
#  endif
#endif
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
