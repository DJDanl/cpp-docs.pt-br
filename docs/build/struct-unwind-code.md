---
title: struct UNWIND_CODE
ms.date: 11/04/2016
ms.assetid: 104955d8-7e33-4c5a-b0c6-3254648f0af3
ms.openlocfilehash: 1ba3cc76c521e158ba448ac2e4e1beda9b3da35a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643229"
---
# <a name="struct-unwindcode"></a>struct UNWIND_CODE

A matriz de código de desenrolamento é usada para registrar a sequência de operações no prólogo que afetam os registros não voláteis e RSP. Cada item de código tem o seguinte formato:

|||
|-|-|
|UBYTE|Deslocamento no prólogo|
|UBYTE: 4|Código de operação de desenrolamento|
|UBYTE: 4|Informações de operação|

A matriz é classificada por ordem decrescente de deslocamento no prólogo.

## <a name="offset-in-prolog"></a>Deslocamento no prólogo

Deslocamento do início do prólogo do fim da instrução que executa esta operação, além de 1 (ou seja, o deslocamento do início da próxima instrução).

## <a name="unwind-operation-code"></a>Código de operação de desenrolamento

Observação: Determinados códigos de operação exige um deslocamento não assinado com um valor no quadro de pilha local. Esse deslocamento é desde o início (endereço mais baixo) da alocação de pilha fixa. Se o campo quadro registrar o UNWIND_INFO for zero, esse deslocamento é from RSP. Se o campo de registrar o quadro for diferente de zero, este é o deslocamento a partir de onde RSP estava localizado quando o reg FP foi estabelecido. Isso é igual ao reg FP menos o deslocamento de reg FP (16 \* o quadro dimensionado e registrar o deslocamento no UNWIND_INFO). Se for usado um registro FP, em seguida, qualquer código de desenrolamento levando um deslocamento deve ser usado somente depois que o reg FP é estabelecido no prólogo.

Para todos os opcodes, exceto `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento será sempre um múltiplo de 8, porque a pilha de todos os valores de interesse são armazenados em limites de 8 bytes (a pilha em si é sempre alinhado de 16 bytes). Para códigos de operação que assumem um deslocamento curto (menos de 512K), o final USHORT em nós para este código mantém o deslocamento dividido por 8. Para códigos de operação que assumem um deslocamento longo (512K < = < 4GB de deslocamento), os dois nós USHORT finais para que esse código mantêm o deslocamento (no formato little-endian).

Para os opcodes `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento será sempre um múltiplo de 16, já que todas as operações MMX de 128 bits devem ocorrer em memória de 16 bytes alinhada. Portanto, um fator de escala de 16 é usado para `UWOP_SAVE_XMM128`, permitindo que os deslocamentos de menos de 1 M.

O código de operação de desenrolamento é um dos seguintes:

`UWOP_PUSH_NONVOL` (0) 1 nó

Enviar por push um registro inteiro não volátil, diminuindo RSP por 8. As informações de operação são o número do registro. Observe que, devido às restrições em epílogos, `UWOP_PUSH_NONVOL` códigos de desenrolamento deverão aparecer primeiros no prólogo e sobrenome do mesmo modo, na matriz de código de desenrolamento. Essa ordenação relativa se aplica a todos os outros códigos de desenrolamento, exceto `UWOP_PUSH_MACHFRAME`.

`UWOP_ALLOC_LARGE` (1) 2 ou 3 nós

Aloca uma área de grande porte na pilha. Há duas formas. Se as informações de operação for igual a 0 e, em seguida, o tamanho da alocação dividido por 8 é registrado no slot de Avançar, permitindo que uma alocação até 512 K - 8. Se as informações de operação é igual a 1, o tamanho de fora de escala da alocação é registrado nos próximos dois slots no formato little-endian, permitindo que as alocações de até 4GB - 8.

`UWOP_ALLOC_SMALL` (2) 1 nó

Aloca uma área de pequeno porte na pilha. O tamanho da alocação é o campo de informações de operação \* 8 + 8, permitindo que as alocações de 8 a 128 bytes.

O código de desenrolamento para uma alocação de pilha sempre deve usar a mais curta possível codificação:

|**Tamanho de alocação**|**Código de desenrolamento**|
|-|-|
|8 a 128 bytes|`UWOP_ALLOC_SMALL`|
|136 para 512K - 8 bytes|`UWOP_ALLOC_LARGE`, informações de operação = 0|
|G 512K para 4 – 8 bytes|`UWOP_ALLOC_LARGE`, informações de operação = 1|

`UWOP_SET_FPREG` (3) 1 nó

Estabelece o registro de ponteiro de quadro, definindo o registro para alguns deslocamento do RSP atual. O deslocamento é igual ao registrar o quadro deslocamento (escala) campo no UNWIND_INFO \* 16, permitindo que os deslocamentos de 0 a 240. O uso de um deslocamento permite estabelecer um ponteiro de quadro que aponta para o meio da alocação de pilha fixa, ajudando a densidade do código, permitindo que mais acessos a usar formulários de instrução curto. Observe que o campo de informações de operação é reservado e não deve ser usado.

`UWOP_SAVE_NONVOL` (4) 2 nós

Salve um registro não volátil inteiros na pilha usando uma MOV em vez de um envio por PUSH. Isso é usado principalmente para wrapping, onde um registro não volátil é salvo para a pilha em uma posição que foi alocada anteriormente. As informações de operação são o número do registro. O deslocamento de pilha dimensionado-by-8 é registrado nos próximos slot de código de operação de desenrolamento, conforme descrito na observação acima.

`UWOP_SAVE_NONVOL_FAR` (5) 3 nós

Salvar um registro não volátil inteiro na pilha com um deslocamento de tempo, usando um MOV em vez de um envio por PUSH. Isso é usado principalmente para wrapping, onde um registro não volátil é salvo para a pilha em uma posição que foi alocada anteriormente. As informações de operação são o número do registro. O deslocamento de pilha fora de escala é registrado nos próximos dois slots de código de operação de desenrolamento, conforme descrito na observação acima.

`UWOP_SAVE_XMM128` (8) nós 2

Salve todos os 128 bits de um não-volátil XMM registrar na pilha. As informações de operação são o número do registro. O deslocamento de pilha dimensionado por 16 é registrado no slot de Avançar.

`UWOP_SAVE_XMM128_FAR` (9) 3 nós

Salve todos os 128 bits de um não-volátil XMM registrar na pilha com um deslocamento de tempo. As informações de operação são o número do registro. O deslocamento de pilha fora de escala é registrado nos próximos dois slots.

`UWOP_PUSH_MACHFRAME` (10) o 1 nó

Enviar por push um quadro de máquina.  Isso é usado para registrar o efeito de uma exceção ou interrupção de hardware. Há duas formas. Se as informações de operação é igual a 0, o seguinte foi enviado na pilha:

|||
|-|-|
|RSP + 32|SS|
|RSP + 24|RSP antigo|
|RSP + 16|EFLAGS|
|RSP + 8|CS|
|RSP|RIP|

Se as informações de operação é igual a 1, em seguida, em vez disso, foi introduzido o seguinte:

|||
|-|-|
|RSP + 40|SS|
|RSP + 32|RSP antigo|
|RSP + 24|EFLAGS|
|RSP + 16|CS|
|RSP + 8|RIP|
|RSP|Código de erro|

Esse código de desenrolamento sempre serão exibidas em um prólogo fictício, que, na verdade, nunca é executado, mas em vez disso, é exibido antes do ponto de entrada real de uma rotina de interrupção e existe somente para fornecer um local para simular o envio por push de um quadro de máquina. `UWOP_PUSH_MACHFRAME` registra a simulação, que indica que a máquina conceitualmente tem feito o seguinte:

1. Pop-RIP endereço de retorno da parte superior da pilha em *Temp*

1. SS de envio por push

1. Enviar por push RSP antigo

1. Enviar por push EFLAGS

1. Enviar por push do CS

1. Enviar por push *Temp*

1. Enviar por push o código de erro (se as informações de operações é igual a 1)

Simulated `UWOP_PUSH_MACHFRAME` diminui de operação RSP em 40 (informações de operações é igual a 0) ou 48 (informações de operações é igual a 1).

## <a name="operation-info"></a>Informações de operação

O significado desses bits 4 depende do código da operação. Para codificar um registro de uso geral (inteiro), o seguinte mapeamento é usado:

|||
|-|-|
|0|RAX|
|1|RCX|
|2|RDX|
|3|RBX|
|4|RSP|
|5|RBP|
|6|RSI|
|7|RDI|
|8 a 15|R8 para R15|

## <a name="see-also"></a>Consulte também

[Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)
