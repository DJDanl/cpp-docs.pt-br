---
title: 1. Introdução
ms.date: 01/16/2019
ms.assetid: c42e72bc-0e31-4b1c-b670-cd82673c0c5a
ms.openlocfilehash: 99020e9cf8c38bcfaeefdf5c31663b3e66352556
ms.sourcegitcommit: 2ebbf8093fadb9a1b78a4381439bcd5c01a89267
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/18/2019
ms.locfileid: "54397297"
---
# <a name="1-introduction"></a>1. Introdução

Este documento especifica uma coleção de variáveis de ambiente que você pode usar para especificar paralelismo de memória compartilhada em programas C e C++, funções de biblioteca e diretivas de compilador. A funcionalidade descrita neste documento é conhecida coletivamente como o *OpenMP Interface de programa de aplicativo C/C++ (API)*. O objetivo dessa especificação é fornecer um modelo de programação paralela, que permite que um programa como portáteis entre arquiteturas de memória compartilhada de diferentes fornecedores. Compiladores de vários fornecedores oferecem suporte a API de C/C++ do OpenMP. Para obter mais informações sobre o OpenMP, incluindo o *Interface de programa de aplicativo do OpenMP Fortran*, podem ser encontradas no seguinte site da web:

[https://www.openmp.org](https://www.openmp.org)

As diretivas, funções de biblioteca e variáveis de ambiente definidas neste documento permitem criar e gerenciar programas em paralelo, permitindo que a portabilidade. As diretivas de estendem o modelo C e C++ para programação sequencial com único programa, que vários dados (SPMD) constrói, construções de compartilhamento de trabalho e construções de sincronização. Eles também dão suporte a compartilhamento e a privatização de dados. Compiladores que dão suporte a OpenMP C e C++ API incluem uma opção de linha de comando para o compilador que ativa e permite que a interpretação de todas as diretivas de compilador OpenMP.

## <a name="11-scope"></a>1.1 Escopo

Essa especificação aborda apenas usuário direcionado a paralelização, no qual você deve definir explicitamente as ações que o compilador e tirar do sistema de tempo de execução para executar o programa em paralelo. Implementações de OpenMP C e C++ não são necessárias para verificar se há dependências, conflitos, deadlocks, condições de corrida ou outros problemas que resultam na execução do programa incorreto. Você é responsável por garantir que o aplicativo usando as construções OpenMP C e C++ API é executado corretamente. Paralelização automática gerado pelo compilador e diretivas para o compilador para ajudá-lo tal paralelização não são abordadas neste documento.

## <a name="12-definition-of-terms"></a>1.2 definições de termos

Os seguintes termos são usados neste documento:

- barrier

  Um ponto de sincronização que devem atingir, todos os threads em uma equipe.  Cada thread aguarda até que todos os threads da equipe chegarem nesse ponto. Não há barreiras explícitas identificadas por diretivas e barreiras implícitas criadas pela implementação.

- Construir

  Uma construção é uma instrução. Ele consiste em uma diretiva, seguido por um bloco estruturado. Algumas políticas não fazem parte de uma construção. (Consulte *diretiva de openmp* na [Apêndice C](c-openmp-c-and-cpp-grammar.md)).

- Diretiva

  Um C ou C++ `#pragma` seguido de `omp` identificador, outros tipos de texto e uma nova linha. A diretiva especifica o comportamento do programa.

- extensão dinâmico

  Todas as instruções na *extensão de léxico*, além de qualquer instrução dentro de uma função que é executada como resultado da execução de instruções dentro a extensão de léxica. Uma extensão dinâmica também é conhecida como um *região*.

- extensão de léxico

  Instruções lexicalmente mantido em uma *bloco estruturado*.

- thread mestre

  O thread que cria uma equipe quando um *região paralela* é inserido.

- região paralela

  Instruções que se associar a um constructo de paralela OpenMP e podem ser executadas por muitos threads.

- particulares

  Uma variável privada nomeia um bloco de armazenamento que é exclusivo para o thread que faz a referência. Há várias maneiras para especificar que uma variável é privada: uma definição em uma região paralela, um `threadprivate` diretiva, uma `private`, `firstprivate`, `lastprivate`, ou `reduction` cláusula ou uso da variável como um `for`loop variável de controle em uma `for` loop imediatamente após uma `for` ou `parallel for` diretiva.

- região

  Uma extensão dinâmica.

- região serial

  Instruções executadas apenas pelo *dominar thread* fora a extensão dinâmica de qualquer *região paralela*.

- Serializar

  Para executar uma construção paralela com:

  - uma equipe de threads que consiste em apenas um único thread (que é o thread mestre para essa construção paralela),

  - serial ordem de execução para as instruções dentro do bloco estruturado (a mesma ordem como se o bloco não eram parte de uma construção paralela), e

  - nenhum efeito sobre o valor retornado por `omp_in_parallel()` (além dos efeitos de qualquer aninhada construções paralelas).

- shared

  Uma variável compartilhada nomeia um único bloco de armazenamento. Todos os threads que acessam essa variável em uma equipe também acessem esse único bloco de armazenamento.

- bloco estruturado

  Um bloco estruturado é uma instrução (única ou composta) que tem uma única entrada e uma única saída. Se houver um salto para dentro ou fora de uma instrução, essa instrução é um bloco estruturado. (Essa regra inclui uma chamada para `longjmp`(3C) ou o uso de `throw`, embora uma chamada para `exit` é permitida.) Se sua execução sempre começa na abertura `{` e sempre termina no fechamento `}`, uma instrução composta é um bloco estruturado. Uma instrução de expressão, a instrução de seleção, a instrução de iteração, ou `try` bloco é um bloco estruturado, se a instrução composta correspondente é obtido, colocando-o na `{` e `}` seria um bloco estruturado. Uma instrução de salto, a instrução rotulada ou a instrução de declaração não é um bloco estruturado.

- Equipe

  Um ou mais threads cooperativas na execução de uma construção.

- thread

  Uma entidade de execução com um fluxo serial de controle, um conjunto de variáveis privadas e acesso a variáveis compartilhadas.

- variável

  Um identificador, opcionalmente qualificado por nomes de namespace que nomeia um objeto.

## <a name="13-execution-model"></a>1.3 modelo de execução

O OpenMP usa o modelo de execução paralela de bifurcação-junção. Embora esse modelo de bifurcação-junção pode ser útil para solucionar vários problemas, ele é projetado para grandes aplicativos baseados em matriz. OpenMP destina-se para dar suporte a programas que são executados corretamente como programas paralelos (biblioteca de suporte de muitos threads de execução e um completo OpenMP). Também é para programas que executam programas corretamente sequenciais (diretivas ignoradas e uma biblioteca de stubs de OpenMP simples). No entanto, é possível e tem permissão para desenvolver um programa que não se comporta corretamente quando executado em sequência. Além disso, diferentes graus de paralelismo podem resultar em resultados numéricos diferentes devido às alterações na associação de operações numéricas. Por exemplo, uma redução serial adição pode ter um padrão diferente de associações de adição de uma redução em paralela. Essas associações diferentes podem alterar os resultados da adição de ponto flutuante.

Um programa escrito com a API de C/C++ do OpenMP inicia a execução como um único thread de execução chamada a *dominar thread*. O thread mestre executa em uma região serial até que a primeira construção paralela é encontrada. Na API OpenMP C/C++, o `parallel` diretiva constitui uma construção paralela. Quando um constructo parallel for encontrado, o thread mestre cria uma equipe de threads e o mestre se torna o mestre da equipe. Cada thread em que a equipe executa as instruções na extensão dinâmica de uma região paralela, exceto para as construções de compartilhamento de trabalho. Todos os threads da equipe devem encontrar constructos de compartilhamento de trabalho na mesma ordem, e um ou mais threads executa as instruções dentro do bloco estruturado associado. A barreira implícita no final de uma construção de compartilhamento de trabalho sem um `nowait` cláusula é executada por todos os threads da equipe.

Se um thread modificar um objeto compartilhado, ele afeta não apenas seu próprio ambiente de execução, mas também aqueles de outros threads no programa. A modificação é garantida para ser concluída, do ponto de vista de outro thread, no próximo ponto de sequência (conforme definido no idioma base) somente se o objeto é declarado como volátil. Caso contrário, a modificação é garantida para ser concluída após o primeiro a modificação de thread. Consulte os outros threads, em seguida, (ou simultaneamente) um `flush` diretiva que especifica o objeto (implícita ou explicitamente). Quando o `flush` diretivas são deduzidas por outras diretivas de OpenMP não garantem a ordenação correta de efeitos colaterais, é responsabilidade do programador para fornecer adicionais e explícitas `flush` diretivas.

Após a conclusão da construção paralela, os threads da equipe sincronizar em uma barreira implícita e somente o thread mestre continua a execução. Qualquer número de construções paralelas pode ser especificado em um único programa. Como resultado, um programa pode criar fork e unir várias vezes durante a execução.

A API de C/C++ do OpenMP permite aos programadores usar diretivas em funções, chamadas de dentro de construções paralelas. As diretivas que não aparecem na extensão de léxico de uma construção paralela, mas podem estar na extensão dinâmica são chamadas *órfãos* diretivas. Com diretivas órfãos, os programadores podem executar as principais partes do programa de em paralelo, com apenas alterações mínimas para o programa sequencial. Com essa funcionalidade, você pode codificar construções paralelas em níveis superiores da árvore de chamadas do programa e usar diretivas para controlar a execução em qualquer uma das funções chamadas.

Funções que gravam no mesmo arquivo podem resultar em saída na qual os dados gravados por threads diferentes aparecem em ordem não determinística de saída de chamadas não sincronizadas para C e C++. Da mesma forma, não sincronizadas chamadas para funções que leiam do mesmo arquivo de entrada podem ler os dados em ordem não determinística. Uso não sincronizado de e/s, de modo que cada thread acessa um arquivo diferente, produz os mesmos resultados de execução serial das funções de e/s.

## <a name="14-compliance"></a>1.4 Conformidade

É uma implementação da API de C/C++ do OpenMP *compatível com o OpenMP* se ele reconhece e preserva a semântica de todos os elementos dessa especificação, conforme dispostos em capítulos 1, 2, 3, 4, e o Apêndice C. apêndices A, B, D, E e F destinam-se informações de fins apenas e não fazem parte da especificação. Implementações que incluam somente um subconjunto da API não são compatíveis com o OpenMP.

O OpenMP C e C++ API é uma extensão para o idioma base que é compatível com uma implementação. Se o idioma base não dá suporte a um constructo de linguagem ou a extensão que aparece neste documento, a implementação de OpenMP não é necessário para dar suporte a ele.

Todas as funções da biblioteca C e C++ padrão e funções internas (ou seja, funções das quais o compilador não tem conhecimento específico) deve ser thread-safe. Uso não sincronizado de funções thread-safe por threads diferentes dentro de uma região paralela não produz um comportamento indefinido. No entanto, o comportamento não pode ser igual uma região de serial. (É um exemplo de uma função de geração de número aleatório.)

A API de C/C++ do OpenMP Especifica que determinado comportamento *definido pela implementação.* Uma implementação em conformidade do OpenMP é necessária para definir e documentar seu comportamento nesses casos. Para obter uma lista de comportamentos definidos por implementação, consulte [Apêndice E](e-implementation-defined-behaviors-in-openmp-c-cpp.md).

## <a name="15-normative-references"></a>1.5 referências normativas

- ISO/IEC 9899:1999 *informações tecnologia - linguagens de programação - C*. Essa especificação API OpenMP se refere a ISO/IEC 9899:1999 como C99.

- 9899:1990 ISO/IEC *informações tecnologia - linguagens de programação - C*. Essa especificação API OpenMP se refere a ISO/IEC 9899:1990 como C90.

- 14882:1998 ISO/IEC *informações tecnologia - linguagens de programação - C++*. Essa especificação API OpenMP se refere a ISO/IEC 14882:1998 como C++.

Onde essa especificação API OpenMP refere-se para o C, a referência é feita para o idioma base suportado pela implementação.

## <a name="16-organization"></a>1.6 Organização

- [Funções da biblioteca em tempo de execução](3-run-time-library-functions.md)
- [Variáveis de ambiente](4-environment-variables.md)
- [Comportamentos definidos por implementação no OpenMP C/C++](e-implementation-defined-behaviors-in-openmp-c-cpp.md)
- [Novos recursos na versão 2.0 do OpenMP C/C++](f-new-features-and-clarifications-in-version-2-0.md)
