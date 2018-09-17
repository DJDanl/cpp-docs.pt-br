---
title: struct UNWIND_INFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f0aee906-a1b9-44cc-a8ad-463637bd5411
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6b342aa89dd82f89b1318da3ab1acb610085a7e7
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717009"
---
# <a name="struct-unwindinfo"></a>struct UNWIND_INFO

A estrutura de informações de dados de desenrolamento é usada para registrar os efeitos de que uma função tem no ponteiro de pilha e onde os registros não voláteis são salvos na pilha:

|||
|-|-|
|UBYTE: 3|Versão|
|UBYTE: 5|Sinalizadores|
|UBYTE|Tamanho do prólogo|
|UBYTE|Contagem de códigos de desenrolamento|
|UBYTE: 4|Registre-se do quadro|
|UBYTE: 4|Deslocamento do quadro de registro (escalado)|
|USHORT \* n|Matriz de códigos de desenrolamento|
|variável|Qualquer um pode ser do formulário (1) ou (2) a seguir|

(1) manipulador de exceção

|||
|-|-|
|ULONG|Endereço do manipulador de exceção|
|variável|Dados de manipulador específico do idioma (opcional)|

(2) encadeadas informações de desenrolamento

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura UNWIND_INFO deve ser DWORD alinhado na memória. O significado de cada campo é da seguinte maneira:

- **Versão**

   Número de versão dos dados de desenrolamento, 1 no momento.

- **sinalizadores**

   Três sinalizadores são definidos no momento:

   |Sinalizador|Descrição|
   |-|-|
   |`UNW_FLAG_EHANDLER`| A função tem um manipulador de exceção que deve ser chamado durante a procura de funções que precisam examinar exceções.|
   |`UNW_FLAG_UHANDLER`| A função tem um manipulador de término deve ser chamado quando o desenrolamento de uma exceção.|
   |`UNW_FLAG_CHAININFO`| Essa estrutura não é a principal para o procedimento de informações de desenrolamento. Em vez disso, o encadeadas desenrolamento de informações de entrada é o conteúdo de uma entrada RUNTIME_FUNCTION anterior. Consulte o texto a seguir para obter uma explicação encadeadas estruturas de informações desenroladas. Se esse sinalizador estiver definido, os sinalizadores UNW_FLAG_EHANDLER e UNW_FLAG_UHANDLER devem ser limpo. Além disso, os campos de alocação de registro e a pilha fixa quadro devem ter os mesmos valores de primário informações de desenrolamento.|

- **Tamanho do prólogo**

   Comprimento do prólogo da função em bytes.

- **Contagem de códigos de desenrolamento**

   Este é o número de slots na matriz de códigos de desenrolamento. Observe que alguns códigos (por exemplo, UWOP_SAVE_NONVOL) de desenrolamento exigem mais de um slot na matriz.

- **Registre-se do quadro**

   Se diferente de zero, em seguida, a função usa um ponteiro de quadro e esse campo é o número do registro não volátil usado como o ponteiro de quadro, usando a mesma codificação para o campo de informações de operação de nós UNWIND_CODE.

- **Quadro registrar deslocamento (escalado)**

   Se o campo de registro do quadro é diferente de zero, isso é o deslocamento em escala do RSP é aplicada ao reg FP quando ela é estabelecida. O reg FP real é definido como RSP + 16 \* esse número, permitindo que os deslocamentos de 0 a 240. Isso permite que aponta para o reg FP no meio da alocação da pilha local dinâmico dos quadros de pilha, permitindo melhor densidade do código por meio de instruções mais curtas (mais instruções podem usar o formulário de deslocamento com sinal de 8 bits).

- **Matriz de códigos de desenrolamento**

   Isso é uma matriz de itens que explica o efeito de prólogo nos registros não voláteis e RSP. Consulte a seção sobre UNWIND_CODE para os significados dos itens individuais. Para fins de alinhamento, essa matriz sempre terá um número par de entradas, com a entrada final potencialmente não utilizada (nesse caso, a matriz será um maior que o indicado pela contagem de campo de códigos de desenrolamento).

- **Endereço do manipulador de exceção**

   Isso é um ponteiro de imagem relativo ao manipulador de exceção/encerramento específico do idioma da função (se o sinalizador UNW_FLAG_CHAININFO é clara e um dos sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER é definido).

- **Dados do manipulador específico do idioma**

   Isso é dados da função do manipulador de exceção específicos da linguagem. O formato desses dados é não for especificado e completamente determinado pelo manipulador de exceção específico em uso.

- **Encadeadas informações de desenrolamento**

   Se o sinalizador UNW_FLAG_CHAININFO estiver definido, em seguida, a estrutura UNWIND_INFO termina com três UWORDs.  Esses UWORDs representam as informações de RUNTIME_FUNCTION para a função do desenrolamento encadeada.

## <a name="see-also"></a>Consulte também

[Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)