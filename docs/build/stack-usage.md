---
title: uso de pilha de x64
ms.date: 12/17/2018
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
ms.openlocfilehash: 3318a3512f83e242496454ffa2dc4aa8d26e1fc3
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53627313"
---
# <a name="x64-stack-usage"></a>uso de pilha de x64

Toda a memória além do endereço atual do RSP é considerada voláteis: O sistema operacional ou um depurador, poderá substituir essa memória durante uma sessão de depuração do usuário ou um manipulador de interrupção. Assim, RSP sempre deve ser definido antes de tentar ler ou gravar valores em um quadro de pilha.

Esta seção discute a alocação de espaço de pilha para variáveis locais e o **alloca** intrínseco.

## <a name="stack-allocation"></a>Alocação da pilha

Prólogo da função é responsável por alocar o espaço de pilha para variáveis locais, os registros salvos, parâmetros de pilha e registre os parâmetros.

A área de parâmetro é sempre na parte inferior da pilha (mesmo se `alloca` é usado), de modo que ele sempre será adjacente para o endereço de retorno durante qualquer chamada de função. Ele contém pelo menos quatro entradas, mas sempre o espaço suficiente para conter todos os parâmetros necessários para qualquer função que pode ser chamada. Observe que sempre espaço é alocado para os parâmetros de registro, mesmo se os parâmetros em si nunca são adaptadores de rede para a pilha; um receptor é garantido que foi alocado espaço para todos os seus parâmetros. Endereços residenciais são necessários para os argumentos do registro para que uma área contígua esteja disponível no caso da função chamada precisa tomar o endereço de lista de argumentos (va_list) ou um argumento individual. Essa área também fornece um local conveniente para salvar os argumentos do registro durante a execução de conversão e como uma opção de depuração (por exemplo, ele torna os argumentos fáceis de encontrar durante a depuração se eles são armazenados em seus endereços base no código de prólogo). Mesmo se a função chamada tiver menos de 4 parâmetros, esses locais da pilha de 4 são de propriedade efetivamente pela função chamada e podem ser usados pela função chamada para outras finalidades além de economizar parâmetro valores do registro.  Assim, o chamador talvez não salve informações nessa região da pilha em uma chamada de função.

Se o espaço é alocado dinamicamente (`alloca`) em uma função, em seguida, um registro não volátil deve ser usado como um ponteiro de quadro para marcar a base da parte fixa da pilha e que o registro deve ser salvo e inicializado no prólogo. Observe que, quando `alloca` é usado, chamadas para o mesmo receptor do chamador mesmo podem ter diferentes endereços base para seus parâmetros de registro.

A pilha sempre será mantida 16 bytes alinhado, exceto dentro do prólogo (por exemplo, depois que o endereço de retorno é enviado por push) e, exceto quando indicado na [tipos de função](#function-types) para uma determinada classe de funções do quadro.

A seguir está um exemplo de como o layout de pilha não-folha de chamadas de função A função where prólogo da função de B. do já alocado espaço para todos os parâmetros de registro e a pilha exigidos por B na parte inferior da pilha. A chamada envia o endereço de retorno e prólogo do B aloca espaço para suas variáveis locais, os registros não voláteis e o espaço necessário para que ele chame funções. Se B usa `alloca`, o espaço é alocado entre o registro de variável/não-volátil local de salvamento área e a área de pilha do parâmetro.

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_5.png "exemplo de conversão AMD")

Quando a função B chama outra função, o endereço de retorno é enviado por push logo abaixo do endereço residencial para RCX.

## <a name="dynamic-parameter-stack-area-construction"></a>Construção de área de pilha do parâmetro dinâmico

Se for usado um ponteiro de quadro, existe a opção para criar dinamicamente a área de pilha do parâmetro. Isso não é feito no momento no x64 compilador.

## <a name="function-types"></a>Tipos de função

Existem basicamente dois tipos de funções. Uma função que requer um quadro de pilha é chamada um *função de quadro*. Uma função que não requer um quadro de pilha é chamada uma *função de folha*.

Uma função de quadro é uma função que aloca espaço em pilha, chama outras funções, salva os registros não voláteis ou usa o tratamento de exceção. Ele também requer uma entrada de tabela de função. Uma função de quadro requer um prólogo e um epílogo. Uma função de quadro pode alocar dinamicamente o espaço de pilha e pode empregar um ponteiro de quadro. Uma função de quadro tem os recursos completos disso de chamada padrão à sua disposição.

Se uma função de quadro não chama outra função, ele não é necessário para alinhar a pilha (mencionada na seção [alocação da pilha](#stack-allocation)).

Uma função de folha é aquele que não requer uma entrada de tabela de função. Ele não pode fazer alterações para todos os registros não voláteis, incluindo RSP, que significa que ele não é possível chamar quaisquer funções ou alocar o espaço de pilha. Ele tem permissão para deixar a pilha não alinhados enquanto ele é executado.

## <a name="malloc-alignment"></a>alinhamento de malloc

[malloc](../c-runtime-library/reference/malloc.md) é garantido que retornam uma memória que esteja alinhada corretamente para armazenar qualquer objeto que tenha um alinhamento fundamental e que poderia se ajustar à quantidade de memória é alocada. Um *alinhamento fundamental* é um alinhamento que é menor que ou igual ao alinhamento maior é suportado pela implementação sem uma especificação de alinhamento. (No Visual C++, isso é o alinhamento que é necessário para um `double`, ou 8 bytes. No código que direciona plataformas de 64 bits, ele tem 16 bytes.) Por exemplo, uma alocação de quatro bytes seria alinhada em um limite que dá suporte a qualquer objeto de quatro bytes ou menor.

Visual C++ permite tipos que têm *alinhamento estendido*, que também são conhecidos como *sobrealinhados* tipos. Por exemplo, os tipos SSE [__m128](../cpp/m128.md) e `__m256`e os tipos que são declarados usando `__declspec(align( n ))` onde `n` é maior que 8, têm alinhamento estendido. Alinhamento de memória em um limite que é adequado para um objeto que exija o alinhamento estendido não é garantido por `malloc`. Para alocar memória para tipos sobre-alinhados, use [aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.

## <a name="alloca"></a>alloca

[alloca](../c-runtime-library/reference/alloca.md) deve ser de 16 bytes alinhado e adicionalmente necessários para usar um ponteiro de quadro.

A pilha é alocada precisa incluir o espaço depois dela para parâmetros de funções chamados subsequentemente, conforme discutido em [alocação da pilha](#stack-allocation).

## <a name="see-also"></a>Consulte também

[x64 convenções de software](../build/x64-software-conventions.md)<br/>
[align](../cpp/align-cpp.md)<br/>
[__declspec](../cpp/declspec.md)