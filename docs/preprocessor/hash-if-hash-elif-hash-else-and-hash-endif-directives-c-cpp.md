---
title: '#Se, #elif, #else e # #endif (C/C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#else'
- '#endif'
- '#if'
- '#elif'
- defined
- __has_include
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8dcacaab21ca763a9ce45a9ab6eb503cd6fc7b74
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43753835"
---
# <a name="if-elif-else-and-endif-directives-cc"></a>Diretivas #if, #elif, #else e #endif (C/C++)

O **#if** diretiva, com o **#elif**, **#else**, e **#endif** diretivas de compilação de controles de partes de um arquivo de origem. Se a expressão escrita (após o **#if**) tem um valor diferente de zero, o grupo de linhas imediatamente após o **#if** diretiva é mantida na unidade de tradução.

## <a name="grammar"></a>Gramática

*condicional* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Se-part elif-partes*<sub>opt</sub> *parte else*<sub>aceitação</sub> *Part&lt;3}{4&gt;opt&lt;4}{5&gt;endif-line&lt;5*

*Se parte* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*texto if-line*

*if-line* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#if***expressão constante* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifdef***identificador* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#ifndef***identificador* 

*elif partes* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*texto de linha elif*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*texto de linha elif partes elif*

*linha elif* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#elif***expressão constante* 

*outra parte* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*texto Else-line*

*outra linha* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#else**

*linha endif* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**#endif**

Cada **#if** diretiva em um arquivo de origem deve ser correspondida por um fechamento **#endif** diretiva. Qualquer número de **#elif** diretivas podem aparecer entre as **#if** e **#endif** diretivas, mas no máximo uma **#else** diretiva é permitida. O **#else** diretiva, se presente, deve ser a última política antes **#endif**.

O **#if**, **#elif**, **#else**, e **#endif** diretivas podem ser aninhadas nas partes de texto de outro **#if**diretivas. Cada aninhados **#else**, **#elif**, ou **#endif** pertence precedente mais próxima diretiva **#if** diretiva.

Todas as diretivas de compilação condicional, tal como **#if** e **#ifdef**, devem ser correspondidas com fechamento **#endif** diretivas antes do final do arquivo; caso contrário, um erro mensagem é gerada. Quando as políticas de compilação condicional estão contidas em arquivos de inclusão, elas devem satisfazer às mesmas circunstâncias: não deve haver nenhuma política de compilação condicional sem correspondência no fim do arquivo de inclusão.

Substituição de macro é executada na parte da linha de comando que segue uma **#elif** de comando, portanto, uma chamada de macro pode ser usada na *expressão de constante*.

O pré-processador seleciona uma das ocorrências de determinada *texto* para processamento adicional. Um bloco especificado na *texto* pode ser qualquer sequência de texto. Ele pode ocupar mais de uma linha. Geralmente *texto* é o texto do programa que tem um significado para o compilador ou o pré-processador.

O pré-processador processa selecionado *texto* e o passa para o compilador. Se *texto* contém diretivas de pré-processador, o pré-processador executa essas políticas. Somente os blocos de texto selecionados pelo pré-processador são compilados.

O pré-processador seleciona um único *texto* item avaliando a expressão de constante após cada **#if** ou **#elif** diretiva até encontrar uma constante de true (diferente de zero) expressão. Ele seleciona todo o texto (incluindo outras diretivas de pré-processador que começam com **#**) até seu associado **#elif**, **#else**, ou **#endif** .

Se todas as ocorrências de *expressão-constante* forem falsas, ou se nenhum **#elif** diretivas é exibido, o pré-processador seleciona o bloco de texto após o **#else** cláusula. Se o **#else** cláusula for omitida e todas as instâncias do *expressão de constante* no **#if** bloco forem falsas, nenhum bloco de texto é selecionado.

O *expressão-constante* é uma expressão de constante inteira com estas restrições adicionais:

- Expressões deve ter tipo integral e podem incluir apenas constantes de inteiros, constantes de caractere e o **definidas** operador.

- A expressão não pode usar `sizeof` ou um operador de conversão de tipos.

- O ambiente de destino talvez não consiga representar todos os intervalos de inteiros.

- A tradução representa o tipo **int** o mesmo tipo **longo**, e **unsigned int** igual **unsigned long**.

- O tradutor pode traduzir a constante de caracteres como um conjunto de valores de código diferentes do conjunto para o ambiente de destino. Para determinar as propriedades do ambiente de destino, verifique os valores das macros de LIMITS.H em um aplicativo compilado para o ambiente de destino.

- A expressão não deve executar consultas ambientais e deve permanecer isolada de detalhes da implementação no computador de destino.

## <a name="defined"></a>definido

O operador de pré-processador **definidas** pode ser usado em expressões de constantes especiais, conforme mostrado pela seguinte sintaxe:

defined( `identifier` )

defined `identifier`

Esta expressão constante é considerada verdadeira (diferente de zero) se o *identificador* estiver definido; caso contrário, a condição for false (0). Um identificador definido como texto vazio é considerado definido. O **definidos** diretiva pode ser usada em um **#if** e um **#elif** diretiva, mas nenhum outro lugar.

No exemplo a seguir, o **#if** e **#endif** diretivas controlam a compilação de um dos três chamadas de função:

```C
#if defined(CREDIT)
    credit();
#elif defined(DEBIT)
    debit();
#else
    printerror();
#endif
```

A chamada de função para `credit` será compilada se o identificador `CREDIT` estiver definido. Se o identificador `DEBIT` estiver definido, a chamada de função para `debit` será compilada. Se nenhum identificador for definido, a chamada para `printerror` será compilada. Observe que `CREDIT` e `credit` são identificadores distintos em C e C++ porque seus casos são diferentes.

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

A primeira **#if** bloco mostra dois conjuntos de aninhada **#if**, **#else**, e **#endif** diretivas. O primeiro conjunto de políticas será processado somente se `DLEVEL > 5` for verdadeiro. Caso contrário, as instruções após **#else** são processados.

O **#elif** e **#else** diretivas no segundo exemplo são usadas para fazer uma das quatro opções, com base no valor de `DLEVEL`. A constante `STACK` é definida como 0, 100 ou 200, dependendo da definição de `DLEVEL`. Se `DLEVEL` for maior que 5, a declaração

```C
#elif DLEVEL > 5
display(debugptr);
```

será compilada e `STACK` não será definido.

A compilação condicional é usada normalmente para evitar várias inclusões do mesmo arquivo de cabeçalho. No C++, em que classes são definidas com frequência em arquivos de cabeçalho, construtores como os seguintes podem ser usados para impedir várias definições:

```cpp
/*  EXAMPLE.H - Example header file  */
#if !defined( EXAMPLE_H )
#define EXAMPLE_H

class Example
{
...
};

#endif // !defined( EXAMPLE_H )
```

O código acima verifica se a constante `EXAMPLE_H` foi definida. Em caso afirmativo, o arquivo já foi incluído e não precisa ser reprocessado. Caso contrário, a constante `EXAMPLE_H` será definida para marcar EXAMPLE.H como já processado.

## <a name="hasinclude"></a>__has_include

**Visual Studio 2017 versão 15.3 e posterior**: determina se um cabeçalho de biblioteca está disponível para inclusão:

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

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)