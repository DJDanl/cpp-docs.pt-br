---
title: "Resumo das regras de escopo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "nomes de classe [C++], regras de escopo"
  - "escopo de classe [C++], regras"
  - "classes [C++], escopo"
  - "nomes [C++], classe"
  - "escopo [C++], nomes de classe"
ms.assetid: 47e26482-0111-466f-b857-598c15d05105
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Resumo das regras de escopo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso de um nome deve ser inequívoco dentro de seu escopo \(até o ponto onde a sobrecarga é determinada\).  Se o nome denota uma função, a função deve ser inequívoca em relação ao número e tipo de parâmetros.  Se o nome permanecer inequívoco, as regras [member\-access](../cpp/member-access-control-cpp.md) serão aplicadas.  
  
## Inicializadores de construtores  
 Os inicializadores de construtor \(descritos em [Inicializando bases e membros](http://msdn.microsoft.com/pt-br/2f71377e-2b6b-49da-9a26-18e9b40226a1)\) são avaliados no escopo do bloco externo do construtor para o qual são especificados.  Portanto, eles podem usar nomes de parâmetro do construtor.  
  
## Nomes globais  
 Um nome de um objeto, função ou enumerador é global se introduzido fora de qualquer função ou classe, ou se prefixado pelo operador unário global de escopo \(`::`\), além de não usado junto a qualquer um desses operadores binários:  
  
-   Resolução do escopo \(`::`\)  
  
-   Seleção de membro para objetos e referências \(**.**\)  
  
-   Seleção de membro para ponteiros \(**–\>**\)  
  
## Nomes qualificados  
 Os nomes usados com o operador de resolução de escopo binário \(`::`\) são chamados de "nomes qualificados". O nome especificado depois do operador de resolução de escopo deve ser membro da classe especificada à esquerda do operador ou membro de sua classe base.  
  
 Os nomes especificados após o operador de seleção de membro \(**.** ou **–\>**\) devem ser membros do tipo de classe do objeto especificado à esquerda do operador ou membros de suas classes base.  Os nomes especificados à direita do operador de seleção de membros \(**–\>**\) também podem ser objetos de outro tipo de classe, contanto que o lado esquerdo de **–\>** seja um objeto de classe e que a classe defina um operador de seleção de membro sobrecarregado \(**–\>**\) que é avaliado em um ponteiro para qualquer outro tipo de classe.  \(Esse provisionamento é abordado em mais detalhes em [Acesso de membros de classe](../Topic/Member%20Access.md).\)  
  
 O compilador pesquisa por nomes na seguinte ordem, parando quando o nome é encontrado:  
  
1.  Escopo do bloco atual se o nome for usado em uma função; caso contrário, o escopo global.  
  
2.  Para fora por meio de cada escopo de bloco delimitador, incluindo o escopo da função externa \(que inclui parâmetros de função\).  
  
3.  Se o nome for usado dentro de uma função de membro, o escopo da classe será pesquisado por nome.  
  
4.  As classes base da classe são pesquisadas sequencialmente pelo nome.  
  
5.  O escopo delimitador da classe aninhada \(se houver\) e suas bases são pesquisados.  A pesquisa continua até que o escopo delimitador de classe externo ser pesquisado.  
  
6.  O escopo global é pesquisado.  
  
 No entanto, você pode modificar essa ordem de pesquisa como segue:  
  
1.  Os nomes precedidos por `::` forçam a pesquisa a iniciar no escopo global.  
  
2.  Os nomes precedidos pelas palavras\-chave **class**, `struct` e **union** forçam o compilador a pesquisar somente pelos nomes **class**, `struct` ou **union**.  
  
3.  Os nomes no lado esquerdo do operador de resolução de escopo \(`::`\) podem ser apenas nomes **class**, `struct`, **namespace** ou **union**.  
  
 Se o nome se refere a um membro não estático, mas é usado em uma função de membro estático, uma mensagem de erro é gerada.  Da mesma forma, se o nome se referir a qualquer membro não estático em uma classe delimitadora, uma mensagem de erro será gerada, pois as classes incluídas não têm os ponteiros **this** da classe delimitadora.  
  
## Nomes de parâmetro de função  
 Nomes de parâmetro de função em definições de função são considerados no escopo do bloco externo da função.  Portanto, eles são nomes locais e saem do escopo quando a função é encerrada.  
  
 Nomes de parâmetro de função em declarações de função \(protótipos\) estão no escopo local da declaração e saem do escopo no final da declaração.  
  
 Parâmetros padrão estão no escopo do parâmetro para o qual eles são o padrão, conforme descrito nos dois parágrafos anteriores.  No entanto, eles não podem acessar variáveis locais nem membros de classes não estáticas.  Parâmetros padrão são avaliados no ponto da chamada de função, mas eles são avaliados no escopo original da declaração de função.  Portanto, os parâmetros padrão para funções de membro são sempre avaliados no escopo da classe.  
  
## Consulte também  
 [Herança](../cpp/inheritance-cpp.md)