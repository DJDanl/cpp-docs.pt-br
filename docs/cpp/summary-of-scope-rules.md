---
title: Resumo das regras de escopo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- class scope [C++], rules
- classes [C++], scope
- class names [C++], scope rules
- names [C++], class
- scope [C++], class names
ms.assetid: 47e26482-0111-466f-b857-598c15d05105
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 2e4a728d23dc9a04b62c9852823f359c3a7cb150
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="summary-of-scope-rules"></a>Resumo das regras de escopo
O uso de um nome deve ser inequívoco dentro de seu escopo (até o ponto onde a sobrecarga é determinada). Se o nome indica que uma função, a função deve ser ambígua em relação ao número e tipo de parâmetros. Se o nome permanecerá inequívoco, [acesso de membro](../cpp/member-access-control-cpp.md) as regras são aplicadas.  
  
## <a name="constructor-initializers"></a>Inicializadores de construtores  
 Inicializadores de construtor (descrito na [Inicializando Bases e membros](http://msdn.microsoft.com/en-us/2f71377e-2b6b-49da-9a26-18e9b40226a1)) são avaliados no escopo do bloco mais externo do construtor para o qual eles são especificados. Portanto, ele podem usar nomes de parâmetro do construtor.  
  
## <a name="global-names"></a>Nomes globais  
 Um nome de um objeto, função ou enumerador é global se introduzido fora de qualquer função ou classe, ou se prefixado pelo operador unário global de escopo (`::`), além de não usado junto a qualquer um desses operadores binários:  
  
-   Resolução do escopo (`::`)  
  
-   Seleção de membro de objetos e referências (**.**)  
  
-   Seleção de membro para ponteiros (**->**)  
  
## <a name="qualified-names"></a>Nomes qualificados  
 Os nomes usados com o operador de resolução de escopo binário (`::`) são chamados de "nomes qualificados". O nome especificado depois do operador de resolução de escopo deve ser membro da classe especificada à esquerda do operador ou membro de sua classe base.  
  
 Nomes especificados depois do operador de seleção de membro (**.** ou ** -> **) devem ser membros do tipo de classe do objeto especificado à esquerda do operador ou membros de sua classe base (s). Nomes especificados à direita do operador de seleção de membro (**->**) também podem ser objetos de outro tipo de classe, contanto que o lado esquerdo da ** -> ** é um objeto de classe e a classe define um operador de seleção de membro sobrecarregado (**->**) que é avaliada como um ponteiro para outro tipo de classe. (Esta disposição é discutida em mais detalhes em [acesso de membro de classe](../cpp/member-access.md).)  
  
 O compilador pesquisa por nomes na seguinte ordem, parando quando o nome é encontrado:  
  
1.  Escopo do bloco atual se o nome for usado em uma função; caso contrário, o escopo global.  
  
2.  Para fora através de cada escopo de bloco delimitador, inclusive o escopo de função mais externa (que inclui parâmetros de função).  
  
3.  Se o nome for usado dentro de uma função de membro, o escopo da classe será pesquisado por nome.  
  
4.  As classes base da classe são pesquisadas sequencialmente pelo nome.  
  
5.  O escopo delimitador da classe aninhada (se houver) e suas bases são pesquisados. A pesquisa continua até que o escopo delimitador de classe externo ser pesquisado.  
  
6.  O escopo global é pesquisado.  
  
 No entanto, você pode modificar essa ordem de pesquisa como segue:  
  
1.  Os nomes precedidos por `::` forçam a pesquisa a iniciar no escopo global.  
  
2.  Nomes precedido pelo **classe**, `struct`, e **união** palavras-chave forçar o compilador a pesquisa apenas **classe**, `struct`, ou **union ** nomes.  
  
3.  Nomes no lado esquerdo do operador de resolução do escopo (`::`) pode ser apenas **classe**, `struct`, **namespace**, ou **união** nomes.  
  
 Se o nome se refere a um membro não estático, mas é usado em uma função de membro estático, uma mensagem de erro é gerada. Da mesma forma, se o nome se refere a qualquer membro não estático em uma classe de delimitador, uma mensagem de erro será gerada porque classes contidas não tem classe delimitador **isso** ponteiros.  
  
## <a name="function-parameter-names"></a>Nomes de parâmetro de função  
 Nomes de parâmetro de função em definições de função são considerados no escopo do bloco da função mais externo. Portanto, eles são nomes locais e saem do escopo quando a função é encerrada.  
  
 Nomes de parâmetro de função em declarações de função (protótipos) estejam no escopo local da declaração e saiam do escopo no fim da declaração.  
  
 Parâmetros padrão estão no escopo do parâmetro para o qual eles são o padrão, conforme descrito nos parágrafos anteriores dois. No entanto, eles não podem acessar variáveis locais nem membros de classes não estáticas. Parâmetros padrão são avaliados no ponto de chamada de função, mas eles são avaliados no escopo original da declaração da função. Portanto, os parâmetros padrão para funções de membro são sempre avaliados no escopo de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Herança](../cpp/inheritance-cpp.md)
