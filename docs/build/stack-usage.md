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

Toda a memória além do endereço atual do RSP é considerada volátil: o sistema operacional ou um depurador pode substituir essa memória durante uma sessão de depuração do usuário ou um manipulador de interrupção. Portanto, RSP deve sempre ser definido antes de tentar ler ou gravar valores em um quadro de pilha.

Esta seção discute a alocação de espaço de pilha para variáveis locais e o **alloca** intrínseco.

## <a name="stack-allocation"></a>Alocação da pilha

O prólogo de uma função é responsável por alocar espaço de pilha para variáveis locais, registros salvos, parâmetros de pilha e parâmetros de registro.

A área de parâmetros é sempre na parte inferior da pilha (mesmo se `alloca` for usada), para que ela sempre seja adjacente ao endereço de retorno durante qualquer chamada de função. Ele contém pelo menos quatro entradas, mas sempre há espaço suficiente para manter todos os parâmetros necessários para qualquer função que possa ser chamada. Observe que o espaço sempre é alocado para os parâmetros de registro, mesmo que os próprios parâmetros nunca sejam hospedados na pilha; um receptor é garantido que o espaço foi alocado para todos os seus parâmetros. Os endereços residenciais são necessários para os argumentos de registro para que uma área contígua esteja disponível no caso de a função chamada precisar pegar o endereço da lista de argumentos (va_list) ou um argumento individual. Essa área também fornece um local conveniente para salvar os argumentos de registro durante a execução da conversão e como uma opção de depuração (por exemplo, torna os argumentos fáceis de encontrar durante a depuração, se forem armazenados em seus endereços residenciais no código de prólogo). Mesmo se a função chamada tiver menos de 4 parâmetros, esses quatro locais de pilha serão efetivamente pertencentes à função chamada e poderão ser usados pela função chamada para outros fins, além de salvar os valores de registro de parâmetro.  Portanto, o chamador não pode salvar informações nessa região de pilha em uma chamada de função.

Se o espaço for alocado dinamicamente`alloca`() em uma função, um registro não volátil deverá ser usado como um ponteiro de quadro para marcar a base da parte fixa da pilha e esse registro deverá ser salvo e inicializado no prólogo. Observe que quando `alloca` é usado, as chamadas para o mesmo receptor do mesmo chamador podem ter endereços base diferentes para seus parâmetros de registro.

A pilha sempre será mantida em 16 bytes alinhada, exceto no prólogo (por exemplo, depois que o endereço de retorno for enviado por push) e, exceto quando indicado em [tipos de função](#function-types) para uma determinada classe de funções de quadro.

Veja a seguir um exemplo de layout de pilha em que a função A chama uma função B sem folha. A função A prólogo já alocou espaço para todos os parâmetros de registro e de pilha exigidos por B na parte inferior da pilha. A chamada envia por push o endereço de retorno e o prólogo de B aloca espaço para suas variáveis locais, registros não voláteis e o espaço necessário para que ele chame funções. Se B usar `alloca`, o espaço será alocado entre a área de salvamento de registro de variável local/não volátil e a área da pilha de parâmetros.

![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_5.png "Exemplo de conversão AMD")

Quando a função B chama outra função, o endereço de retorno é enviado logo abaixo do endereço principal para RCX.

## <a name="dynamic-parameter-stack-area-construction"></a>Construção da área da pilha de parâmetros dinâmico

Se um ponteiro de quadro for usado, a opção existirá para criar dinamicamente a área da pilha de parâmetros. Isso não é feito atualmente no compilador x64.

## <a name="function-types"></a>Tipos de função

Há basicamente dois tipos de funções. Uma função que requer um quadro de pilha é chamada de *função de quadro*. Uma função que não requer um quadro de pilha é chamada de *função de folha*.

Uma função frame é uma função que aloca espaço de pilha, chama outras funções, salva registros não voláteis ou usa manipulação de exceção. Ele também requer uma entrada de tabela de função. Uma função frame requer um prólogo e um epílogo. Uma função frame pode alocar dinamicamente o espaço de pilha e pode empregar um ponteiro de quadro. Uma função frame tem os recursos completos desse padrão de chamada em sua disposição.

Se uma função de quadro não chamar outra função, não será necessário alinhar a pilha (referenciada em [alocação de pilha](#stack-allocation)de seção).

Uma função folha é aquela que não requer uma entrada de tabela de função. Ele não pode fazer alterações em nenhum registro não volátil, incluindo RSP, o que significa que ele não pode chamar nenhuma função nem alocar espaço de pilha. É permitido deixar a pilha desalinhada enquanto ela é executada.

## <a name="malloc-alignment"></a>alinhamento de malloc

a [malloc](../c-runtime-library/reference/malloc.md) é garantida para retornar a memória que está adequadamente alinhada para armazenar qualquer objeto que tenha um alinhamento fundamental e que possa se ajustar à quantidade de memória alocada. Um *alinhamento fundamental* é um alinhamento menor ou igual ao maior alinhamento que é suportado pela implementação sem uma especificação de alinhamento. (Em Visual C++, esse é o alinhamento necessário para um `double`ou 8 bytes. No código que tem como destino plataformas de 64 bits, é 16 bytes.) Por exemplo, uma alocação de quatro bytes seria alinhada em um limite que dá suporte a qualquer objeto de quatro bytes ou menor.

Visual C++ permite tipos com *alinhamento estendido*, que também são conhecidos como tipos *alinhados* . Por exemplo, os tipos de [__m128](../cpp/m128.md) SSE __m128 `__m256`e, e os tipos declarados `__declspec(align( n ))` usando `n` WHERE é maior que 8, têm o alinhamento estendido. O alinhamento de memória em um limite adequado para um objeto que requer o alinhamento estendido não é `malloc`garantido pelo. Para alocar memória para tipos com alinhamento excessivo, use [_aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.

## <a name="alloca"></a>alloca

[_alloca](../c-runtime-library/reference/alloca.md) deve ser alinhado em 16 bytes e, além disso, necessário para usar um ponteiro de quadro.

A pilha que é alocada precisa incluir o espaço após ele para os parâmetros das funções subsequentemente chamadas, conforme discutido em [alocação de pilha](#stack-allocation).

## <a name="see-also"></a>Confira também

[Convenções de software x64](../build/x64-software-conventions.md)<br/>
[alinha](../cpp/align-cpp.md)<br/>
[__declspec](../cpp/declspec.md)
