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
ms.openlocfilehash: a9d4f941298159b8a3ea1aa3fe37efd1e6dc68ab
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="if-elif-else-and-endif-directives-cc"></a>Diretivas #if, #elif, #else e #endif (C/C++)
A política `#if`, com as políticas `#elif`, `#else` e `#endif`, controla a compilação de partes de um arquivo de origem. Se a expressão escrita (após `#if`) tiver um valor diferente de zero, o grupo de linhas imediatamente após a política `#if` será mantido na unidade de tradução.  
  
## <a name="grammar"></a>Gramática  
 *condicional* :  
 *Se partes elif partes*aceitar*parte else*aceitar*linha endif*  
  
 *Se partes* :  
 *texto da linha se*  
  
 *Se-linha* :  
 **#if**  *constant-expression*  
  
 **#ifdef**  *identifier*  
  
 **#ifndef**  *identifier*  
  
 *partes elif* :  
 *texto da linha de elif*  
  
 *texto da linha de elif partes elif*  
  
 *linha elif* :  
 **#elif**  *constant-expression*  
  
 *parte Else* :  
 *outra linha de texto*  
  
 *outra linha* :  
 `#else`  
  
 *linha endif* :  
 `#endif`  
  
 Cada política `#if` em um arquivo de origem deve ser correspondida pela política de fechamento `#endif`. Qualquer número de políticas `#elif` pode aparecer entre as políticas `#if` e `#endif`, mas no máximo uma política `#else` é permitida. A política `#else`, se presente, deverá ser a última política antes de `#endif`.  
  
 As políticas `#if`, `#elif`, `#else` e `#endif` podem ser aninhadas nas partes de texto de outras políticas `#if`. Cada política aninhada `#else`, `#elif` ou `#endif` pertence à política `#if` precedente mais próxima.  
  
 Todas as diretivas de compilação condicional, tais como `#if` e **#ifdef**, deverá ser correspondido com fechamento `#endif` diretivas antes do final do arquivo; caso contrário, uma mensagem de erro será gerada. Quando as políticas de compilação condicional estão contidas em arquivos de inclusão, elas devem satisfazer às mesmas circunstâncias: não deve haver nenhuma política de compilação condicional sem correspondência no fim do arquivo de inclusão.  
  
 Substituição de macro é executada em parte da linha de comando que segue um `#elif` de comando, para uma chamada de macro pode ser usada no *expressão constante*.  
  
 O pré-processador seleciona uma das ocorrências de determinada *texto* para processamento adicional. Um bloco especificado na *texto* pode ser qualquer sequência de texto. Ele pode ocupar mais de uma linha. Geralmente *texto* é o texto de programa que tem um significado para o compilador ou o pré-processador.  
  
 O pré-processador processa selecionado *texto* e passa para o compilador. Se *texto* contém diretivas de pré-processador, a realiza essas diretivas de pré-processador. Somente os blocos de texto selecionados pelo pré-processador são compilados.  
  
 O pré-processador seleciona um único *texto* item avaliando a expressão de constante após cada `#if` ou `#elif` diretiva até encontrar uma expressão de constante true (diferente de zero). Ele seleciona todo o texto (incluindo outros começando com as diretivas de pré-processador **#**) até seu associado `#elif`, `#else`, ou `#endif`.  
  
 Se todas as ocorrências de *expressão constante* são false, ou se nenhum `#elif` diretivas aparecem, o pré-processador seleciona o bloco de texto após o `#else` cláusula. Se o `#else` cláusula for omitida e todas as instâncias de *expressão constante* no `#if` bloco são false, nenhum bloco de texto é selecionado.  
  
 O *expressão constante* é uma expressão de constante de número inteiro com essas restrições adicionais:  
  
-   Expressões devem ter tipo integral e pode incluir apenas constantes inteiras, constantes de caractere e o **definido** operador.  
  
-   A expressão não pode usar `sizeof` ou um operador de conversão de tipos.  
  
-   O ambiente de destino talvez não consiga representar todos os intervalos de inteiros.  
  
-   A conversão representa o tipo `int` o mesmo tipo **longo**, e `unsigned int` igual `unsigned long`.  
  
-   O tradutor pode traduzir a constante de caracteres como um conjunto de valores de código diferentes do conjunto para o ambiente de destino. Para determinar as propriedades do ambiente de destino, verifique os valores das macros de LIMITS.H em um aplicativo compilado para o ambiente de destino.  
  
-   A expressão não deve executar consultas ambientais e deve permanecer isolada de detalhes da implementação no computador de destino.  

## <a name="defined"></a>definido  
 O operador de pré-processador **definido** pode ser usado em expressões de constantes especiais, como mostra a seguinte sintaxe:  
  
 defined( `identifier` )  
  
 defined `identifier`  
  
 Esta expressão constante é considerado verdadeiro (diferente de zero) se o *identificador* está definido atualmente; caso contrário, a condição for false (0). Um identificador definido como texto vazio é considerado definido. O **definido** diretiva pode ser usada em uma `#if` e um `#elif` diretiva, mas em nenhum outro lugar.  
  
 No exemplo a seguir, as políticas `#if` e `#endif` controlam a compilação de uma de três chamadas de função:  
  
```  
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
  
```  
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
  
 O primeiro bloco `#if` mostra dois conjuntos de políticas `#if`, `#else` e `#endif` aninhadas. O primeiro conjunto de políticas será processado somente se `DLEVEL > 5` for verdadeiro. Caso contrário, as instruções depois #**else** são processados.  
  
 As políticas `#elif` e `#else` do segundo exemplo são usadas para fazer uma de quatro escolhas, com base no valor de `DLEVEL`. A constante `STACK` é definida como 0, 100 ou 200, dependendo da definição de `DLEVEL`. Se `DLEVEL` for maior que 5, a declaração  
  
```  
#elif DLEVEL > 5  
display(debugptr);  
```  
  
 será compilada e `STACK` não será definido.  
  
 A compilação condicional é usada normalmente para evitar várias inclusões do mesmo arquivo de cabeçalho. No C++, em que classes são definidas com frequência em arquivos de cabeçalho, construtores como os seguintes podem ser usados para impedir várias definições:  
  
```  
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
**Visual Studio 2017 versão posterior e 15,3**: determina se um cabeçalho de biblioteca está disponível para inclusão:  

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