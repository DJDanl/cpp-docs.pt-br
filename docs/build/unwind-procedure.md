---
title: Procedimento desenrolado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 82c5d0ca-70be-4d1a-a306-bfe01c29159f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 294353baf8c15818ba836bd3093226a78aa6e44c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45700643"
---
# <a name="unwind-procedure"></a>Procedimento desenrolado

A matriz de código de desenrolamento é classificada em ordem decrescente. Quando ocorre uma exceção, o contexto completo é armazenado pelo sistema operacional em um registro de contexto. A lógica de expedição de exceção é invocada, que é executada repetidamente as etapas a seguir para localizar um manipulador de exceção.

1. Use o RIP atual armazenado no registro de contexto para pesquisar uma entrada de tabela RUNTIME_FUNCTION que descreve a função atual (ou parte de função, no caso de entradas UNWIND_INFO encadeadas).

1. Se nenhuma entrada de tabela de função for encontrada, em seguida, ele está em uma função de folha e RSP diretamente abordarão o ponteiro retornado. O ponteiro retornado no [RSP] é armazenado no contexto atualizado, o RSP simulado é incrementado por 8 e a etapa 1 é repetida.

1. Se for encontrada uma entrada de tabela de função, RIP pode ficar em três regiões a) em um epílogo, b) no prólogo ou c) no código que pode ser coberto por um manipulador de exceção.

   - Caso um) se o RIP está dentro de um epílogo, em seguida, controle está deixando a função, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos de epílogo devem ser continuados para calcular o contexto da função do chamador. Para determinar se o RIP está dentro de um epílogo, o fluxo de código do RIP na é examinado. Se esse fluxo de código pode ser correspondido para a parte à direita de um epílogo legítimo, e em seguida, ele está em um epílogo e a parte restante do epílogo é simulada, com o registro de contexto atualizado como cada instrução é processado. Depois disso, a etapa 1 é repetida.

   - Caso b) se o RIP se encontra dentro do prólogo, em seguida, o controle não tem a função inserido, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos do prólogo devem ser desfeitos para calcular o contexto da função do chamador. O RIP está dentro do prólogo, se a distância do início da função para o RIP é menor ou igual ao tamanho do prólogo codificado nas informações de desenrolamento. Os efeitos do prólogo são desenrolados verificar para a frente por meio da matriz de códigos de desenrolamento para a primeira entrada com um deslocamento menor ou igual ao deslocamento do RIP desde o início da função e, em seguida, desfazendo o efeito de todos os itens restantes na matriz de código de desenrolamento. Etapa 1, em seguida, é repetida.

   - Caso c) se o RIP não está dentro do prólogo ou epílogo e a função tem um manipulador de exceção (UNW_FLAG_EHANDLER é definido) e, em seguida, o identificador específico da linguagem é chamado. O manipulador verifica seus dados e funções conforme apropriado de filtro de chamadas. O identificador específico da linguagem pode retornar que a exceção foi identificada ou que a pesquisa deve ser continuada. Ele também pode iniciar um desenrolamento diretamente.

1. Se o identificador específico da linguagem retorna um status manipulado, então a execução é continuada usando o registro de contexto original.

1. Se não há nenhum manipulador específico do idioma ou o manipulador retorna um status "continuar a pesquisa", o registro de contexto deve ser organizado para o estado do chamador. Isso é feito através do processamento de todos os elementos de matriz de código de desenrolamento, desfazendo o efeito de cada. Etapa 1, em seguida, é repetida.

Quando encadeado desenrolar informações estiver envolvida, estas etapas básicas ainda são seguidas. A única diferença é que, enquanto percorrer a matriz de código de desenrolamento para desenrolar efeitos do prólogo, após o final da matriz for atingido, que, em seguida, está vinculado às informações de desenrolamento de pai e a matriz de código de desenrolamento todo lá está sendo movimentada. Essa vinculação continua até que chegam a uma informação de desenrolamento sem o sinalizador UNW_CHAINED_INFO e concluir a movimentação de sua matriz de código de desenrolamento.

O menor conjunto de dados de desenrolamento é de 8 bytes. Isso representaria uma função que só alocada 128 bytes de pilha ou menos e, possivelmente, salvo um registro não volátil. Isso também é o tamanho de um encadeadas desenrolar a estrutura de informações para um prólogo de comprimento zero com nenhum códigos de desenrolamento.

## <a name="see-also"></a>Consulte também

[Tratamento de exceção (x64)](../build/exception-handling-x64.md)