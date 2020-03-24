---
title: Resumo das regras de escopo
ms.date: 11/04/2016
helpviewer_keywords:
- class scope [C++], rules
- classes [C++], scope
- class names [C++], scope rules
- names [C++], class
- scope [C++], class names
ms.assetid: 47e26482-0111-466f-b857-598c15d05105
ms.openlocfilehash: 1f8b79c637662d79051b72e6aabefc99c450bdc5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160873"
---
# <a name="summary-of-scope-rules"></a>Resumo das regras de escopo

O uso de um nome deve ser inequívoco dentro de seu escopo (até o ponto onde a sobrecarga é determinada). Se o nome denota uma função, a função deve ser inequívoca em relação ao número e ao tipo de parâmetros. Se o nome permanecer inequívoca, as regras [de acesso de membro](../cpp/member-access-control-cpp.md) serão aplicadas.

## <a name="constructor-initializers"></a>Inicializadores de construtores

[Inicializadores de Construtor](constructors-cpp.md#member_init_list) são avaliados no escopo do bloco mais externo do construtor para o qual eles são especificados. Portanto, eles podem usar os nomes de parâmetro do construtor.

## <a name="global-names"></a>Nomes globais

Um nome de um objeto, função ou enumerador é global se introduzido fora de qualquer função ou classe, ou se prefixado pelo operador unário global de escopo (`::`), além de não usado junto a qualquer um desses operadores binários:

- Resolução do escopo (`::`)

- Seleção de membros para objetos e referências ( **.** )

- Seleção de membros para ponteiros ( **->** )

## <a name="qualified-names"></a>Nomes qualificados

Os nomes usados com o operador de resolução de escopo binário (`::`) são chamados de "nomes qualificados". O nome especificado depois do operador de resolução de escopo deve ser membro da classe especificada à esquerda do operador ou membro de sua classe base.

Nomes especificados após o operador de seleção de membro ( **.** ou **->** ) devem ser membros do tipo de classe do objeto especificado à esquerda do operador ou membros de sua classe base (es). Os nomes especificados à direita do operador de seleção de membro ( **->** ) também podem ser objetos de outro tipo de classe, desde que o lado esquerdo de **->** seja um objeto de classe e que a classe defina um operador de seleção de membro sobrecarregado ( **->** ) que seja avaliado como um ponteiro para algum outro tipo de classe. (Esse provisionamento é discutido em mais detalhes em [acesso de membro de classe](../cpp/member-access.md).)

O compilador pesquisa por nomes na seguinte ordem, parando quando o nome é encontrado:

1. Escopo do bloco atual se o nome for usado em uma função; caso contrário, o escopo global.

1. Fora de cada escopo de bloco delimitador, incluindo o escopo de função mais externo (que inclui parâmetros de função).

1. Se o nome for usado dentro de uma função de membro, o escopo da classe será pesquisado por nome.

1. As classes base da classe são pesquisadas sequencialmente pelo nome.

1. O escopo delimitador da classe aninhada (se houver) e suas bases são pesquisados. A pesquisa continua até que o escopo delimitador de classe externo ser pesquisado.

1. O escopo global é pesquisado.

No entanto, você pode modificar essa ordem de pesquisa como segue:

1. Os nomes precedidos por `::` forçam a pesquisa a iniciar no escopo global.

1. Os nomes precedidos pelas palavras-chave **Class**, **struct**e **Union** forçam o compilador a pesquisar somente nomes de **classe**, **struct**ou **Union** .

1. Os nomes no lado esquerdo do operador de resolução de escopo (`::`) podem ser somente nomes de **classe**, **struct**, **namespace**ou **União** .

Se o nome se refere a um membro não estático, mas é usado em uma função de membro estático, uma mensagem de erro é gerada. Da mesma forma, se o nome se referir a qualquer membro não estático em uma classe delimitadora, uma mensagem de erro será gerada porque as classes embutidas não têm **a** classe delimitadora de ponteiros.

## <a name="function-parameter-names"></a>Nomes de parâmetro de função

Os nomes de parâmetro de função nas definições de função são considerados no escopo do bloco mais externo da função. Portanto, eles são nomes locais e saem do escopo quando a função é encerrada.

Os nomes de parâmetro de função em declarações de função (protótipos) estão no escopo local da declaração e saem do escopo no final da declaração.

Os parâmetros padrão estão no escopo do parâmetro para o qual eles são o padrão, conforme descrito nos dois parágrafos anteriores. No entanto, eles não podem acessar variáveis locais nem membros de classes não estáticas. Os parâmetros padrão são avaliados no ponto da chamada de função, mas são avaliados no escopo original da declaração de função. Portanto, os parâmetros padrão para as funções de membro são sempre avaliados no escopo de classe.

## <a name="see-also"></a>Confira também

[Herança](../cpp/inheritance-cpp.md)
