---
title: "1.2 definições de termos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: fcaa8eb8-bbbf-4a24-ad0e-e299c442db79
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 21c4bcafe89fda7e09333b014da20e1d483125e2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="12-definition-of-terms"></a>1.2 Definições de termos
Os seguintes termos são usados neste documento:  
  
 barrier  
 Um ponto de sincronização que deve ser acessado por todos os threads em uma equipe.  Cada thread aguarda até que todos os threads da equipe de chegarem nesse ponto. Há barreiras explícitas identificadas por diretivas e implícitas barreiras criadas pela implementação.  
  
 Construir  
 Uma construção é uma instrução. Ele consiste em uma diretiva e o bloco estruturado subsequente. Observe que algumas diretivas não fazem parte de uma construção. (Consulte *diretiva de openmp* na [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md)).  
  
 Diretiva  
 C ou C++ **#pragma** seguido de **omp** identificador, outro texto e uma nova linha. A diretiva especifica o comportamento do programa.  
  
 extensão dinâmica  
 Todas as instruções no *extensão lexical*, além de qualquer instrução em uma função que é executada como resultado da execução de instruções dentro da extensão de léxica. Uma extensão dinâmica também é conhecida como um *região*.  
  
 extensão de léxico  
 Instruções lexicalmente contidas em um *bloco estruturado*.  
  
 thread mestre  
 O thread que cria uma equipe quando um *região parallel* é inserido.  
  
 região Parallel  
 Instruções que associar a uma construção paralela OpenMP e podem ser executadas por vários threads.  
  
 particulares  
 Uma variável privada nomeia um bloco de armazenamento que é exclusivo para o thread que faz a referência. Observe que há várias maneiras de especificar que uma variável particular: uma definição de dentro de uma região parallel, um **threadprivate** diretiva, um **privada**, **firstprivate**, **lastprivate**, ou **redução** cláusula ou uso da variável como um **para**variável de controle de loop em uma **para** loop imediatamente após um **para** ou **paralelo para** diretiva.  
  
 região  
 Uma extensão dinâmica.  
  
 região serial  
 Instruções executadas somente pelo *mestre thread* fora a extensão dinâmica de qualquer *região parallel*.  
  
 Serializar  
 Para executar uma construção paralela com uma equipe de threads que consiste em apenas um único thread (que é o thread principal para essa construção paralela), com serial ordem de execução para as instruções dentro do bloco estruturado (a mesma ordem como se o bloco não eram parte de uma construção paralela) e sem afetar o valor retornado por **omp_in_parallel()** (além dos efeitos de qualquer aninhado construções paralelas).  
  
 shared  
 Uma variável compartilhada nomeia um único bloco de armazenamento. Todos os threads em uma equipe que acessar essa variável acessarão este bloco único de armazenamento.  
  
 bloco estruturado  
 Um bloco estruturado é uma instrução (simples ou composta) que tem uma única entrada e uma única saída. Nenhuma instrução é um bloco estruturado se há um salto para dentro ou fora dessa instrução (incluindo uma chamada para **longjmp**(3C) ou o uso de **gerar**, mas uma chamada para **sair** é permitido). Uma instrução composta é um bloco estruturado se sua execução sempre começa na abertura **{** e sempre termina no fechamento **}**. Uma instrução de expressão, a instrução de seleção, a instrução de iteração, ou **tente** bloco é um bloco estruturado, se a instrução composta correspondente obtido por delimitador na **{** e **}** seria um bloco estruturado. Uma instrução de salto, a instrução rotulada ou a instrução de declaração não é um bloco estruturado.  
  
 Equipe  
 Um ou mais threads trabalhar de forma na execução de uma construção.  
  
 thread  
 Uma entidade de execução com um série fluxo de controle, um conjunto de variáveis privadas e acesso a variáveis compartilhadas.  
  
 variável  
 Um identificador, opcionalmente qualificado por nomes de namespace, que nomeia um objeto.