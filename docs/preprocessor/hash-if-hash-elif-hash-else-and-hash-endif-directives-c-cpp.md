---
title: "Diretivas #if, #elif, #else e #endif (C/C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "#else"
  - "#endif"
  - "#if"
  - "#elif"
  - "Defined"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Diretiva #elif"
  - "Diretiva #else"
  - "Diretiva #endif"
  - "Diretiva #if"
  - "compilação condicional, Diretivas ()"
  - "diretiva definida"
  - "diretiva elif (#elif)"
  - "diretiva else (#else)"
  - "diretiva endif (#endif)"
  - "diretiva if (#if)"
  - "pré-processador, Diretivas ()"
ms.assetid: c77a175f-6ca8-47d4-8df9-7bac5943d01b
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas #if, #elif, #else e #endif (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A política `#if`, com as políticas `#elif`, `#else` e `#endif`, controla a compilação de partes de um arquivo de origem.  Se a expressão escrita \(após `#if`\) tiver um valor diferente de zero, o grupo de linhas imediatamente após a política `#if` será mantido na unidade de tradução.  
  
## Gramática  
 *conditional* :  
 *if\-part elif\-parts* opt *else\-part*opt *endif\-line*  
  
 *if\-part* :  
 *texto if\-line*  
  
 *if\-line* :  
 **\#if**  *constant\-expression*  
  
 **\#ifdef**  *identifier*  
  
 **\#ifndef**  *identifier*  
  
 *elif\-parts* :  
 *elif\-line text*  
  
 *elif\-parts elif\-line text*  
  
 *elif\-line* :  
 **\#elif**  *constant\-expression*  
  
 *else\-part* :  
 *texto else\-line*  
  
 *else\-line* :  
 `#else`  
  
 *endif\-line* :  
 `#endif`  
  
 Cada política `#if` em um arquivo de origem deve ser correspondida pela política de fechamento `#endif`.  Qualquer número de políticas `#elif` pode aparecer entre as políticas `#if` e `#endif`, mas no máximo uma política `#else` é permitida.  A política `#else`, se presente, deverá ser a última política antes de `#endif`.  
  
 As políticas `#if`, `#elif`, `#else` e `#endif` podem ser aninhadas nas partes de texto de outras políticas `#if`.  Cada política aninhada `#else`, `#elif` ou `#endif` pertence à política `#if` precedente mais próxima.  
  
 Todas as políticas de compilação condicionais, como `#if` e **\#ifdef**, devem ser correspondidas com políticas de fechamento `#endif` antes do fim do arquivo; caso contrário, uma mensagem de erro será gerada.  Quando as políticas de compilação condicional estão contidas em arquivos de inclusão, elas devem satisfazer às mesmas circunstâncias: não deve haver nenhuma política de compilação condicional sem correspondência no fim do arquivo de inclusão.  
  
 A substituição de macro é executada na parte de linha de comando após um comando `#elif`, para que uma chamada de macro possa ser usada em *expressão constante*.  
  
 O pré\-processador seleciona uma das ocorrências do *texto* fornecidas para processamento adicional.  Um bloco especificado no *texto* pode ser qualquer sequência de texto.  Ele pode ocupar mais de uma linha.  Normalmente, *texto* é o texto de programa que possui significado para o compilador ou o pré\-processador.  
  
 O pré\-processador processa o *texto* selecionado e o passa para o compilador.  Se o *texto* contiver políticas de pré\-processamento, o pré\-processador executa essas políticas.  Somente os blocos de texto selecionados pelo pré\-processador são compilados.  
  
 O pré\-processador seleciona um único item de *texto* avaliando a expressão de constante após cada política `#if` ou `#elif` até encontrar uma expressão de constante verdadeira \(diferente de zero\).  Ele seleciona todo o texto \(incluindo outras políticas de pré\-processamento que começam com **\#**\) até a `#elif`, a `#else` ou a `#endif`associada.  
  
 Se todas as ocorrências de *expressão constante* forem falsas, ou se nenhuma política `#elif` aparecer, o pré\-processador selecionará o bloco de texto após a cláusula `#else`.  Se a cláusula `#else` for omitida e todas as instâncias de *expressão constante* no bloco `#if` forem falsas, nenhum bloco de texto será selecionado.  
  
 A *expressão constante* é uma expressão constante inteira com estas restrições adicionais:  
  
-   As expressões devem ter o tipo integral e podem incluir apenas constantes de inteiros, constantes de caracteres e o operador **defined**.  
  
-   A expressão não pode usar `sizeof` ou um operador de conversão de tipos.  
  
-   O ambiente de destino talvez não consiga representar todos os intervalos de inteiros.  
  
-   A tradução representa os tipos `int`, como **long** e `unsigned int` e como `unsigned long`.  
  
-   O tradutor pode traduzir a constante de caracteres como um conjunto de valores de código diferentes do conjunto para o ambiente de destino.  Para determinar as propriedades do ambiente de destino, verifique os valores das macros de LIMITS.H em um aplicativo compilado para o ambiente de destino.  
  
-   A expressão não deve executar consultas ambientais e deve permanecer isolada de detalhes da implementação no computador de destino.  
  
 O operador do pré\-processador **defined** pode ser usado em expressões de constantes especiais, como mostrado pela seguinte sintaxe:  
  
 defined\( `identifier` \)  
  
 defined `identifier`  
  
 Essa expressão constante será considerada verdadeira \(diferente de zero\) se o *identificador* estiver definido; caso contrário, a condição será falsa \(0\).  Um identificador definido como texto vazio é considerado definido.  A política **defined** pode ser usada em `#if` e em uma política `#elif`, mas em nenhum outro lugar.  
  
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
  
 A chamada de função para `credit` será compilada se o identificador `CREDIT` estiver definido.  Se o identificador `DEBIT` estiver definido, a chamada de função para `debit` será compilada.  Se nenhum identificador for definido, a chamada para `printerror` será compilada.  Observe que `CREDIT` e `credit` são identificadores distintos em C e C\+\+ porque seus casos são diferentes.  
  
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
  
 O primeiro bloco `#if` mostra dois conjuntos de políticas `#if`, `#else` e `#endif` aninhadas.  O primeiro conjunto de políticas será processado somente se `DLEVEL > 5` for verdadeiro.  Caso contrário, as instruções após \#**else** serão processadas.  
  
 As políticas `#elif` e `#else` do segundo exemplo são usadas para fazer uma de quatro escolhas, com base no valor de `DLEVEL`.  A constante `STACK` é definida como 0, 100 ou 200, dependendo da definição de `DLEVEL`.  Se `DLEVEL` for maior que 5, a declaração  
  
```  
#elif DLEVEL > 5  
display(debugptr);  
```  
  
 será compilada e `STACK` não será definido.  
  
 A compilação condicional é usada normalmente para evitar várias inclusões do mesmo arquivo de cabeçalho.  No C\+\+, em que classes são definidas com frequência em arquivos de cabeçalho, construtores como os seguintes podem ser usados para impedir várias definições:  
  
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
  
 O código acima verifica se a constante `EXAMPLE_H` foi definida.  Em caso afirmativo, o arquivo já foi incluído e não precisa ser reprocessado.  Caso contrário, a constante `EXAMPLE_H` será definida para marcar EXAMPLE.H como já processado.  
  
## Consulte também  
 [Diretivas de pré\-processador](../preprocessor/preprocessor-directives.md)