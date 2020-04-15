---
title: Uso da pilha x64
ms.date: 12/17/2018
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
ms.openlocfilehash: b598c33fbdd56630ca3e5ef0da551f38a73baa26
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335528"
---
# <a name="x64-stack-usage"></a>Uso da pilha x64

Toda a memória além do endereço atual do RSP é considerada volátil: o SISTEMA OPERACIONAL, ou um depurador, pode substituir essa memória durante uma sessão de depuração do usuário ou um manipulador de interrupção. Assim, o RSP deve ser sempre definido antes de tentar ler ou escrever valores em um quadro de pilha.

Esta seção discute a alocação de espaço de pilha para variáveis locais e a **aloca** intrínseca.

## <a name="stack-allocation"></a>Alocação da pilha

O prólogo de uma função é responsável por alocar espaço de pilha para variáveis locais, registros salvos, parâmetros de pilha e parâmetros de registro.

A área do parâmetro está sempre na parte `alloca` inferior da pilha (mesmo que seja usada), de modo que ela esteja sempre adjacente ao endereço de retorno durante qualquer chamada de função. Contém pelo menos quatro entradas, mas sempre espaço suficiente para manter todos os parâmetros necessários por qualquer função que possa ser chamada. Observe que o espaço é sempre alocado para os parâmetros de registro, mesmo que os parâmetros em si nunca estejam abrigados na pilha; uma callee é garantida que o espaço foi alocado para todos os seus parâmetros. Os endereços residenciais são necessários para os argumentos de registro para que uma área contígua esteja disponível no caso de a chamada função precisar tomar o endereço da lista de argumentos (va_list) ou um argumento individual. Essa área também fornece um lugar conveniente para salvar argumentos de registro durante a execução do thunk e como uma opção de depuração (por exemplo, torna os argumentos fáceis de encontrar durante a depuração se eles estiverem armazenados em seus endereços residenciais no código de prólog). Mesmo que a função chamada tenha menos de 4 parâmetros, esses 4 locais de pilha são efetivamente de propriedade da chamada função, e podem ser usados pela chamada função para outros fins, além de salvar valores de registro de parâmetros.  Assim, o chamador não pode salvar informações nesta região de pilha em uma chamada de função.

Se o espaço for`alloca`alocado dinamicamente () em uma função, então um registro não volátil deve ser usado como ponteiro de quadro para marcar a base da parte fixa da pilha e esse registro deve ser salvo e inicializado no prólogo. Observe que, quando `alloca` usado, chamadas para o mesmo chamador do mesmo chamador podem ter endereços residenciais diferentes para seus parâmetros de registro.

A pilha será sempre mantida alinhada a 16 bytes, exceto dentro do prólogo (por exemplo, depois que o endereço de retorno for empurrado), e exceto quando indicado em [Tipos de Função](#function-types) para uma determinada classe de funções de quadro.

A seguir, um exemplo do layout de pilha onde a função A chama uma função não-folha B. O prólogo da função A já alocou espaço para todos os parâmetros de registro e pilha exigidos por B na parte inferior da pilha. A chamada empurra o endereço de retorno e o prólogo de B aloca espaço para suas variáveis locais, registros não voláteis e o espaço necessário para que ele chame funções. Se B `alloca`usar, o espaço será alocado entre a área de salvamento de registro local/não volátil e a área de pilha de parâmetros.

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_5.png "Exemplo de conversão AMD")

Quando a função B chama outra função, o endereço de retorno é empurrado logo abaixo do endereço inicial do RCX.

## <a name="dynamic-parameter-stack-area-construction"></a>Construção da área de pilha de parâmetros dinâmicos

Se um ponteiro de quadro for usado, a opção existirá para criar dinamicamente a área de pilha de parâmetros. Isso não é feito atualmente no compilador x64.

## <a name="function-types"></a>Tipos de função

Existem basicamente dois tipos de funções. Uma função que requer um quadro de pilha é chamada de *função de quadro*. Uma função que não requer um quadro de pilha é chamada de *função folha*.

Uma função de quadro é uma função que aloca espaço de pilha, chama outras funções, salva registros não voláteis ou usa o manuseio de exceções. Também requer uma entrada de tabela de funções. Uma função de quadro requer um prólogo e um epílogo. Uma função de quadro pode alocar dinamicamente o espaço da pilha e pode empregar um ponteiro de quadro. Uma função de quadro tem todas as capacidades deste padrão de chamada à sua disposição.

Se uma função de quadro não chamar outra função, então não é necessário alinhar a pilha (referenciada na [alocação de pilha de seção](#stack-allocation)).

Uma função folha é aquela que não requer uma entrada de tabela de funções. Ele não pode fazer alterações em nenhum registro não volátil, incluindo RSP, o que significa que ele não pode chamar nenhuma função ou alocar espaço de pilha. É permitido deixar a pilha desalinhada enquanto ela é executada.

## <a name="malloc-alignment"></a>alinhamento malloc

[malloc](../c-runtime-library/reference/malloc.md) é garantido para retornar a memória que está adequadamente alinhada para armazenar qualquer objeto que tenha um alinhamento fundamental e que poderia caber na quantidade de memória que é alocada. Um *alinhamento fundamental* é um alinhamento menor ou igual ao maior alinhamento que é apoiado pela implementação sem uma especificação de alinhamento. (No Visual C++, este é o alinhamento `double`necessário para um , ou 8 bytes. Em código que tem como alvo plataformas de 64 bits, são 16 bytes.) Por exemplo, uma alocação de quatro bytes seria alinhada em um limite que suporta qualquer objeto de quatro bytes ou menor.

O Visual C++ permite tipos que tenham *alinhamento estendido,* que também são conhecidos como tipos *superalinhados.* Por exemplo, os [__m128](../cpp/m128.md) tipos `__m256`de SSE __m128 e `__declspec(align( n ))` , `n` e tipos que são declarados usando onde é maior que 8, têm alinhamento estendido. O alinhamento da memória em um limite adequado para um `malloc`objeto que requer alinhamento prolongado não é garantido por . Para alocar memória para tipos superalinhados, use [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.

## <a name="alloca"></a>alloca

[_alloca](../c-runtime-library/reference/alloca.md) é necessário estar alinhado com 16 bytes e adicionalmente necessário para usar um ponteiro de quadro.

A pilha alocada precisa incluir espaço depois dele para parâmetros de funções posteriormente chamadas, conforme discutido na [Alocação de Pilha](#stack-allocation).

## <a name="see-also"></a>Confira também

[Convenções de software x64](../build/x64-software-conventions.md)<br/>
[Alinhar](../cpp/align-cpp.md)<br/>
[__declspec](../cpp/declspec.md)
