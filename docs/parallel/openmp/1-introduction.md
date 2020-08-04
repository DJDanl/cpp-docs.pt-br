---
title: 1. Introdução
ms.date: 01/16/2019
ms.assetid: c42e72bc-0e31-4b1c-b670-cd82673c0c5a
ms.openlocfilehash: e2857565f7838ae45ff88ea53ba714e1418116ff
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87521168"
---
# <a name="1-introduction"></a>1. Introdução

Este documento especifica uma coleção de diretivas de compilador, funções de biblioteca e variáveis de ambiente que você pode usar para especificar o paralelismo de memória compartilhada em programas C e C++. A funcionalidade descrita neste documento é conhecida coletivamente como a *API (interface de programa de aplicativo) de OpenMP C/C++*. O objetivo dessa especificação é fornecer um modelo para a programação paralela que permita que um programa seja portável entre arquiteturas de memória compartilhada de diferentes fornecedores. Os compiladores de muitos fornecedores dão suporte à API de OpenMP C/C++. Mais informações sobre o OpenMP, incluindo a *interface de programa de aplicativo Fortran OpenMP*, podem ser encontradas no seguinte site da Web:

[https://www.openmp.org](https://www.openmp.org)

As diretivas, as funções de biblioteca e as variáveis de ambiente definidas neste documento permitem criar e gerenciar programas paralelos e, ao mesmo tempo, permitir a portabilidade. As diretivas estendem o modelo de programação sequencial C e C++ com construções de SPMD (vários dados de programa único), construções de compartilhamento de trabalho e construções de sincronização. Eles também dão suporte ao compartilhamento e privatização de dados. Os compiladores que dão suporte à API de OpenMP C e C++ incluem uma opção de linha de comando para o compilador que ativa e permite a interpretação de todas as diretivas de compilação de OpenMP.

## <a name="11-scope"></a>1.1 Escopo

Essa especificação abrange apenas a paralelização direcionada pelo usuário, na qual você define explicitamente as ações que o compilador e o sistema de tempo de execução executam para executar o programa em paralelo. As implementações de OpenMP C e C++ não são necessárias para verificar dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução incorreta do programa. Você é responsável por garantir que o aplicativo usando as construções de API de OpenMP C e C++ seja executado corretamente. As diretivas e a paralelização automática geradas pelo compilador para o compilador para auxiliar essa paralelização não são abordadas neste documento.

## <a name="12-definition-of-terms"></a>1,2 definição de termos

Os seguintes termos são usados neste documento:

- barrier

  Um ponto de sincronização que todos os threads de uma equipe devem alcançar.  Cada thread aguarda até que todos os threads da equipe cheguem nesse ponto. Há barreiras explícitas identificadas pelas diretivas e barreiras implícitas criadas pela implementação.

- construct

  Um constructo é uma instrução. Ele consiste em uma diretiva, seguida por um bloco estruturado. Algumas diretivas não fazem parte de um constructo. (Consulte *a diretiva de OpenMP* no [Apêndice C](c-openmp-c-and-cpp-grammar.md)).

- Register

  Um C ou C++ `#pragma` seguido pelo `omp` identificador, outro texto e uma nova linha. A diretiva especifica o comportamento do programa.

- extensão dinâmica

  Todas as instruções na *extensão lexical*, além de qualquer instrução dentro de uma função que é executada como resultado da execução de instruções dentro da extensão lexical. Uma extensão dinâmica também é conhecida como *região*.

- extensão lexical

  As instruções são mantidas lexicalmente dentro de um *bloco estruturado*.

- thread mestre

  O thread que cria uma equipe quando uma *região paralela* é inserida.

- região paralela

  Instruções que se associam a uma construção paralela de OpenMP e podem ser executadas por vários threads.

- particulares

  Uma variável privada nomeia um bloco de armazenamento que é exclusivo para o thread que faz a referência. Há várias maneiras de especificar que uma variável é privada: uma definição em uma região paralela, uma `threadprivate` diretiva, uma cláusula,, `private` `firstprivate` `lastprivate` ou `reduction` , ou o uso da variável como uma variável de **`for`** controle de loop em um **`for`** loop imediatamente após uma `for` `parallel for` diretiva ou.

- region

  Uma extensão dinâmica.

- região serial

  Instruções executadas somente pelo *thread mestre* fora da extensão dinâmica de qualquer *região paralela*.

- serialize

  Para executar uma construção paralela com:

  - uma equipe de threads que consiste em apenas um único thread (que é o thread mestre para essa construção paralela),

  - ordem de série de execução para as instruções dentro do bloco estruturado (a mesma ordem que se o bloco não fosse parte de uma construção paralela) e

  - nenhum efeito sobre o valor retornado por `omp_in_parallel()` (além dos efeitos de qualquer construção paralela aninhada).

- shared

  Uma variável compartilhada nomeia um único bloco de armazenamento. Todos os threads em uma equipe que acessam essa variável também acessam esse único bloco de armazenamento.

- bloco estruturado

  Um bloco estruturado é uma instrução (única ou composta) que tem uma única entrada e uma única saída. Se houver um salto para dentro ou para fora de uma instrução, essa instrução será um bloco estruturado. (Essa regra inclui uma chamada para `longjmp` (3C) ou o uso de `throw` , embora uma chamada para `exit` seja permitida.) Se sua execução sempre começar na abertura `{` e sempre terminar no fechamento `}` , uma instrução composta será um bloco estruturado. Uma instrução de expressão, instrução de seleção, instrução de iteração ou **`try`** bloco é um bloco estruturado se a instrução composta correspondente obtida ao enfechá-la em `{` e `}` for um bloco estruturado. Uma instrução de salto, instrução rotulada ou instrução de declaração não é um bloco estruturado.

- equipe

  Um ou mais threads cooperam na execução de uma construção.

- thread

  Uma entidade de execução que tem um fluxo serial de controle, um conjunto de variáveis privadas e acesso a variáveis compartilhadas.

- variável

  Um identificador, opcionalmente qualificado por nomes de namespace, que nomeia um objeto.

## <a name="13-execution-model"></a>modelo de execução 1,3

O OpenMP usa o modelo de junção de bifurcação de execução paralela. Embora esse modelo de junção de bifurcação possa ser útil para resolver vários problemas, ele é adaptado para aplicativos grandes baseados em matriz. O OpenMP destina-se a oferecer suporte a programas que executam corretamente tanto como programas paralelos (muitos threads de execução e uma biblioteca de suporte de OpenMP completa). Ele também é para programas que são executados corretamente como programas sequenciais (diretivas ignoradas e uma biblioteca de stubs de OpenMP simples). No entanto, é possível e podem desenvolver um programa que não se comporte corretamente quando executado sequencialmente. Além disso, diferentes graus de paralelismo podem resultar em resultados numéricos diferentes devido a alterações na associação de operações numéricas. Por exemplo, uma redução de adição serial pode ter um padrão diferente de associações de adição do que uma redução paralela. Essas diferentes associações podem alterar os resultados da adição de ponto flutuante.

Um programa escrito com a API de OpenMP C/C++ começa a execução como um único thread de execução chamado *thread mestre*. O thread mestre é executado em uma região serial até que a primeira construção paralela seja encontrada. Na API de OpenMP C/C++, a `parallel` diretiva constitui uma construção paralela. Quando um constructo paralelo é encontrado, o thread mestre cria uma equipe de threads e o mestre torna-se mestre da equipe. Cada thread na equipe executa as instruções na extensão dinâmica de uma região paralela, exceto para as construções de compartilhamento de trabalho. Todos os threads na equipe devem encontrar constructos de compartilhamento de trabalho na mesma ordem, e um ou mais threads executam as instruções dentro do bloco estruturado associado. A barreira implícita no final de um constructo de compartilhamento de trabalho sem uma `nowait` cláusula é executada por todos os threads da equipe.

Se um thread Modificar um objeto compartilhado, ele afetará não apenas seu próprio ambiente de execução, mas também os outros threads do programa. A modificação é garantida para ser concluída, do ponto de vista de outro thread, no próximo ponto de sequência (conforme definido no idioma base) somente se o objeto for declarado como volátil. Caso contrário, a modificação terá a garantia de ser concluída após o primeiro thread de modificação. Os outros threads (ou simultaneamente) veem uma `flush` diretiva que especifica o objeto (implícita ou explicitamente). Quando as `flush` diretivas que são implícitas por outras diretivas de OpenMP não garantem a ordenação correta de efeitos colaterais, é responsabilidade do programador fornecer diretivas adicionais e explícitas `flush` .

Após a conclusão da construção paralela, os threads na equipe sincronizam em uma barreira implícita e somente o thread mestre continua a execução. Qualquer número de construções paralelas pode ser especificado em um único programa. Como resultado, um programa pode bifurcar e ingressar várias vezes durante a execução.

A API de OpenMP C/C++ permite que os programadores usem diretivas em funções chamadas de dentro de construções paralelas. As diretivas que não aparecem na extensão lexical de uma construção paralela, mas podem estar na extensão dinâmica são chamadas de diretivas *órfãs* . Com as diretivas órfãs, os programadores podem executar grandes partes de seu programa em paralelo, com apenas alterações mínimas no programa sequencial. Com essa funcionalidade, você pode codificar construções paralelas nos níveis superiores da árvore de chamada do programa e usar diretivas para controlar a execução em qualquer uma das funções chamadas.

Chamadas não sincronizadas para funções de saída C e C++ que gravam no mesmo arquivo podem resultar na saída em que os dados gravados por threads diferentes aparecem na ordem não determinística. Da mesma forma, chamadas não sincronizadas para funções de entrada que lêem do mesmo arquivo podem ler dados em uma ordem não determinística. O uso não sincronizado de e/s, de modo que cada thread acesse um arquivo diferente, produz os mesmos resultados que a execução serial das funções de e/s.

## <a name="14-compliance"></a>1.4 Conformidade

Uma implementação da API de OpenMP C/C++ será *compatível com OpenMP* se reconhecer e preservar a semântica de todos os elementos dessa especificação, conforme disposto nos capítulos 1, 2, 3, 4 e Apêndice C. os apêndices A, B, D, e e F são apenas para fins informativos e não fazem parte da especificação. As implementações que incluem apenas um subconjunto da API não são compatíveis com OpenMP.

A API de OpenMP C e C++ é uma extensão para o idioma base com suporte de uma implementação. Se o idioma base não oferecer suporte a uma construção ou extensão de linguagem que aparece neste documento, a implementação de OpenMP não será necessária para dar suporte a ela.

Todas as funções de biblioteca C e C++ padrão e funções internas (ou seja, funções das quais o compilador tem conhecimento específico) devem ser thread-safe. O uso não sincronizado de funções thread-safe por threads diferentes dentro de uma região paralela não produz um comportamento indefinido. No entanto, o comportamento pode não ser o mesmo que em uma região serial. (Uma função de geração de número aleatório é um exemplo.)

A API de OpenMP C/C++ especifica que determinado comportamento é *definido pela implementação.* Uma implementação de OpenMP em conformidade é necessária para definir e documentar seu comportamento nesses casos. Para obter uma lista de comportamentos definidos pela implementação, consulte o [Apêndice E](e-implementation-defined-behaviors-in-openmp-c-cpp.md).

## <a name="15-normative-references"></a>1,5 referências de normativas

- ISO/IEC 9899:1999, *tecnologia da informação-linguagens de programação-C*. Esta especificação de API de OpenMP refere-se ao ISO/IEC 9899:1999 como C99.

- ISO/IEC 9899:1990, *tecnologia da informação-linguagens de programação-C*. Esta especificação de API de OpenMP refere-se ao ISO/IEC 9899:1990 como C90.

- ISO/IEC 14882:1998, *tecnologia da informação-linguagens de programação-C++*. Esta especificação de API de OpenMP refere-se ao ISO/IEC 14882:1998 como C++.

Quando essa especificação de API de OpenMP se refere a C, a referência é feita ao idioma base suportado pela implementação.

## <a name="16-organization"></a>1.6 Organização

- [Funções da biblioteca em tempo de execução](3-run-time-library-functions.md)
- [Variáveis de ambiente](4-environment-variables.md)
- [Comportamentos definidos por implementação no OpenMP C/C++](e-implementation-defined-behaviors-in-openmp-c-cpp.md)
- [Novos recursos no OpenMP C/C++ versão 2,0](f-new-features-and-clarifications-in-version-2-0.md)
