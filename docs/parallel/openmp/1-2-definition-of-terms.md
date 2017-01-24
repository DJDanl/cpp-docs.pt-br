---
title: "1.2 Definition of Terms | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: fcaa8eb8-bbbf-4a24-ad0e-e299c442db79
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 1.2 Definition of Terms
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os seguintes termos são usados neste documento:  
  
 barreira  
 Um ponto de sincronização que deve ser alcançado por todos os threads de uma equipe.  Cada segmento espera até que todos os threads na equipe chegarem neste ponto.  Há barreiras explícitas identificadas por diretivas e barreiras implícitas criadas pela implementação.  
  
 Construir  
 Uma construção é uma declaração.  Ele consiste em uma diretiva e o bloco estruturado subseqüente.  Observe que algumas diretivas não são parte de uma construção.  \(Consulte  *diretiva do openmp*  na  [Apêndice C](../Topic/C.%20OpenMP%20C%20and%20C++%20Grammar.md)\).  
  
 diretiva  
 Uma c ou C\+\+  **\# pragma** seguido de  **omp** identificador, outro texto e uma nova linha.  A diretiva especifica o comportamento do programa.  
  
 extensão dinâmica  
 Todas as instruções na  *lexical extensão*, além de qualquer instrução dentro de uma função que é executada como resultado da execução de instruções dentro do rigor lexical.  Uma extensão dinâmica também é conhecida como um  *região*.  
  
 extensão lexical  
 Instruções lexicalmente contidas em um  *estruturado bloco*.  
  
 thread mestre  
 O segmento que cria uma equipe quando um  *região paralela*  for inserido.  
  
 região paralela  
 Instruções que vincular a uma construção de paralela OpenMP e podem ser executadas por vários segmentos.  
  
 Particular  
 Uma variável privada nomeia um bloco de armazenamento que é exclusivo para o segmento de fazer a referência.  Observe que há várias maneiras para especificar que uma variável privada: a definição de dentro de uma região paralela, uma  **threadprivate** diretiva, um  **particular**,  **firstprivate**,  **lastprivate**, ou  **redução**  cláusula ou uso da variável como um  **para**variável de controle de loop em um  **para**  loop imediatamente após um  **para**  ou  **paralela para**  diretiva.  
  
 região  
 Uma extensão dinâmica.  
  
 região serial  
 Instruções executadas somente pelo  *segmento mestre*  fora da extensão dinâmica de qualquer  *região paralela*.  
  
 serializar  
 Para executar uma construção paralela com uma equipe de threads consiste em apenas um único thread \(que é o segmento principal para essa construção paralela\), com serial ordem de execução para as instruções dentro do bloco estruturado \(o mesmo pedido como se o bloco não fossem parte de uma construção paralela\) e sem afetar o valor retornado por  **omp\_in\_parallel\(\)** \(além dos efeitos de qualquer aninhada construções paralelas\).  
  
 compartilhado  
 Uma variável compartilhada nomeia um único bloco de armazenamento.  Todos os threads de uma equipe que acessam essa variável acessará esse único bloco de armazenamento.  
  
 bloco estruturado  
 Um bloco estruturado é uma declaração \(simples ou composta\) que tem uma única entrada e uma saída única.  Nenhuma instrução é um bloco de estruturado, se houver um salto dentro ou fora dessa instrução \(incluindo uma chamada para  **longjmp**\(3C\) ou o uso de  **lança**, mas uma chamada para  **Sair** é permitido\).  Uma declaração composta é um bloco de estruturado se sua execução sempre começa na abertura  **{** e sempre termina no fechamento  **}**.  Uma instrução de expressão, a instrução de seleção, a instrução de iteração, ou  **tente** bloco é um bloco de estruturado, se a instrução composta correspondente obtido colocando\-o em  **{** e  **}**seria um bloco estruturado.  Uma instrução de salto, rotulada de instrução ou instrução de declaração não é um bloco estruturado.  
  
 equipe  
 Um ou mais threads cooperando na execução de uma construção.  
  
 thread  
 Uma entidade de execução tendo um fluxo serial de controle, um conjunto de variáveis particulares e o acesso a variáveis compartilhadas.  
  
 variable  
 Um identificador, opcionalmente qualificado pelos nomes de namespace, que nomeia um objeto.