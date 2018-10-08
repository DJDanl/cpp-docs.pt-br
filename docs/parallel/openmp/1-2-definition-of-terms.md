---
title: 1.2 definições de termos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: fcaa8eb8-bbbf-4a24-ad0e-e299c442db79
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66cbf25324b71c3fd28bdd344c7a217348cdb5d9
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861610"
---
# <a name="12-definition-of-terms"></a>1.2 Definições de termos

Os seguintes termos são usados neste documento:

- barrier

   Um ponto de sincronização que deve ser acessado por todos os threads em uma equipe.  Cada thread aguarda até que todos os threads da equipe chegarem nesse ponto. Não há barreiras explícitas identificadas por diretivas e barreiras implícitas criadas pela implementação.

- Construir

   Uma construção é uma instrução. Ele consiste em uma diretiva e o bloco estruturado subsequente. Observe que algumas políticas não são parte de uma construção. (Consulte *diretiva de openmp* na [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md)).

- Diretiva

   Um C ou C++ **#pragma** seguido de **omp** identificador, outros tipos de texto e uma nova linha. A diretiva especifica o comportamento do programa.

- extensão dinâmico

   Todas as instruções na *extensão de léxico*, além de qualquer instrução dentro de uma função que é executada como resultado da execução de instruções dentro a extensão de léxica. Uma extensão dinâmica também é conhecida como um *região*.

- extensão de léxico

   Instruções lexicalmente contidas em uma *bloco estruturado*.

- thread mestre

   O thread que cria uma equipe quando um *região paralela* é inserido.

- região paralela

   Instruções que se associar a um constructo de paralela OpenMP e podem ser executadas por vários threads.

- particulares

   Uma variável privada nomeia um bloco de armazenamento que é exclusivo para o thread que faz a referência. Observe que há várias maneiras para especificar que uma variável é privada: uma definição em uma região paralela, um **threadprivate** diretiva, um **privada**, **firstprivate**, **lastprivate**, ou **redução** cláusula ou uso da variável como um **para**variável de controle de loop em um **para** loop imediatamente após um **para** ou **paralela para** diretiva.

- região

   Uma extensão dinâmica.

- região serial

   Instruções executadas apenas pelo *dominar thread* fora a extensão dinâmica de qualquer *região paralela*.

- Serializar

   Para executar uma construção paralela com uma equipe de threads que consiste em apenas um único thread (que é o thread mestre para essa construção paralela), com ordem serial de execução para as instruções dentro do bloco estruturado (a mesma ordem como se o bloco não eram parte de uma construção paralela) e sem afetar o valor retornado por **omp_in_parallel()** (além dos efeitos de qualquer aninhada construções paralelas).

- shared

   Uma variável compartilhada nomeia um único bloco de armazenamento. Todos os threads que acessam essa variável em uma equipe poderão acessar esse único bloco de armazenamento.

- bloco estruturado

   Um bloco estruturado é uma instrução (única ou composta) que tem uma única entrada e uma única saída. Nenhuma instrução é um bloco estruturado, se houver um salto para dentro ou fora dessa instrução (incluindo uma chamada para **longjmp**(3C) ou o uso de **throw**, mas uma chamada para **sair** é permitido). Uma instrução composta é um bloco estruturado, se sua execução sempre começa na abertura **{** e sempre termina no fechamento **}**. Uma instrução de expressão, a instrução de seleção, a instrução de iteração, ou **tente** bloco é um bloco estruturado, se a instrução composta correspondente é obtido, colocando-o no **{** e **}** seria um bloco estruturado. Uma instrução de salto, a instrução rotulada ou a instrução de declaração não é um bloco estruturado.

- Equipe

   Um ou mais threads cooperativas na execução de uma construção.

- thread

   Uma entidade de execução com um fluxo serial de controle, um conjunto de variáveis privadas e acesso a variáveis compartilhadas.

- variável

   Um identificador, opcionalmente qualificado por nomes de namespace que nomeia um objeto.
