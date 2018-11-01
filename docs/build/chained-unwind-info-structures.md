---
title: Estruturas de informações desenroladas encadeadas
ms.date: 11/04/2016
ms.assetid: 176835bf-f118-45d9-9128-9db4b7571864
ms.openlocfilehash: 19d0beb8c3438183fa594d7ec3cab4929b3a491a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502135"
---
# <a name="chained-unwind-info-structures"></a>Estruturas de informações desenroladas encadeadas

Se o sinalizador UNW_FLAG_CHAININFO for definido, em seguida, uma estrutura de informações de desenrolamento é um secundário, e o campo endereço de exceção-manipulador/encadeadas-info compartilhada contém as informações de desenrolamento primário. A código a seguir recupera informações sobre, supondo que o primário desenrolamento `unwindInfo` é a estrutura que tem o UNW_FLAG_CHAININFO sinalizador definido.

```
PRUNTIME_FUNCTION primaryUwindInfo = (PRUNTIME_FUNCTION)&(unwindInfo->UnwindCode[( unwindInfo->CountOfCodes + 1 ) & ~1]);
```

Informações encadeadas são úteis em duas situações. Primeiro, ele pode ser usado para segmentos de código não contíguos. Usando as informações encadeadas, você pode reduzir o tamanho das informações necessárias de desenrolamento, porque você não precisará duplicar a matriz de códigos de desenrolamento das informações de desenrolamento primário.

Você também pode usar informações encadeadas para agrupar os salvamentos voláteis. O compilador pode atrasar a salvar alguns registros voláteis até que ele esteja fora do prólogo da função de entrada. Você pode registrar isso fazendo com que as informações de desenrolamento primária para a parte da função antes do código agrupado e, em seguida, configurando encadeadas informações com um tamanho diferente de zero do prólogo, onde os códigos de desenrolamento nas informações encadeadas refletem os salvamentos de registros a não-volátil. Nesse caso, os códigos de desenrolamento são todas as instâncias de UWOP_SAVE_NONVOL. Não há suporte para um agrupamento que salva os registros não voláteis por meio de um envio por PUSH ou modifica o registro RSP por meio de uma alocação de pilha fixa adicional.

Um item UNWIND_INFO que tem UNW_FLAG_CHAININFO definido pode conter uma entrada RUNTIME_FUNCTION cujo item UNWIND_INFO também tem UNW_FLAG_CHAININFO definido (wrapping várias). Por fim, o encadeadas informações de desenrolamento ponteiros chegará a um item UNWIND_INFO com UNW_FLAG_CHAININFO desmarcada. Este é o item UNWIND_INFO primário, que aponta para o ponto de entrada do procedimento real.

## <a name="see-also"></a>Consulte também

[Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)