---
title: Alocação da pilha
ms.date: 11/04/2016
ms.assetid: 098e51f2-eda6-40d0-b149-0b618aa48b47
ms.openlocfilehash: 23b22491a6eeac078f551a6513a7ecad4be43fe9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478811"
---
# <a name="stack-allocation"></a>Alocação da pilha

Prólogo da função é responsável por alocar o espaço de pilha para variáveis locais, os registros salvos, parâmetros de pilha e registre os parâmetros.

A área de parâmetro é sempre na parte inferior da pilha (mesmo se alloca for usada), de modo que ele sempre será adjacente para o endereço de retorno durante qualquer chamada de função. Ele contém pelo menos quatro entradas, mas sempre o espaço suficiente para conter todos os parâmetros necessários para qualquer função que pode ser chamada. Observe que sempre espaço é alocado para os parâmetros de registro, mesmo se os parâmetros em si nunca são adaptadores de rede para a pilha; um receptor é garantido que foi alocado espaço para todos os seus parâmetros. Endereços residenciais são necessários para os argumentos do registro para que uma área contígua esteja disponível no caso da função chamada precisa tomar o endereço de lista de argumentos (va_list) ou um argumento individual. Essa área também fornece um local conveniente para salvar os argumentos do registro durante a execução de conversão e como uma opção de depuração (por exemplo, ele torna os argumentos fáceis de encontrar durante a depuração se eles são armazenados em seus endereços base no código de prólogo). Mesmo se a função chamada tiver menos de 4 parâmetros, esses locais da pilha de 4 são de propriedade efetivamente pela função chamada e podem ser usados pela função chamada para outras finalidades além de economizar parâmetro valores do registro.  Assim, o chamador talvez não salve informações nessa região da pilha em uma chamada de função.

Se o espaço é alocado dinamicamente (alloca) em uma função, um registro não volátil deve ser usado como um ponteiro de quadro para marcar a base da parte fixa da pilha e esse registro deve ser salvo e inicializado no prólogo. Observe que, quando alloca é usado, chamadas para o mesmo receptor do chamador mesmo podem ter diferentes endereços base para seus parâmetros de registro.

A pilha sempre será mantida 16 bytes alinhado, exceto dentro do prólogo (por exemplo, depois que o endereço de retorno é enviado por push) e, exceto quando indicado na [tipos de função](../build/function-types.md) para uma determinada classe de funções do quadro.

A seguir está um exemplo de como o layout de pilha não-folha de chamadas de função A função where prólogo da função de B. do já alocado espaço para todos os parâmetros de registro e a pilha exigidos por B na parte inferior da pilha. A chamada envia o endereço de retorno e prólogo do B aloca espaço para suas variáveis locais, os registros não voláteis e o espaço necessário para que ele chame funções. Se B usa alloca, o espaço é alocado entre o registro de variável/não-volátil local de salvamento área e a área de pilha do parâmetro.

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_5.png "exemplo de conversão AMD")

Quando a função B chama outra função, o endereço de retorno é enviado por push logo abaixo do endereço residencial para RCX.

## <a name="see-also"></a>Consulte também

[Uso da pilha](../build/stack-usage.md)