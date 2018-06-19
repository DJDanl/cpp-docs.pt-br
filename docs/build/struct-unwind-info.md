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
ms.openlocfilehash: 14b17a79905ffc7814e2aecf92e90f3db526453f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32383235"
---
# <a name="struct-unwindinfo"></a>struct UNWIND_INFO
A estrutura de informações de dados de desenrolamento é usada para registrar os efeitos de que uma função tem o ponteiro de pilha e onde os registros não volátil são salvos na pilha:  
  
|||  
|-|-|  
|UBYTE: 3|Versão|  
|UBYTE: 5|Sinalizadores|  
|UBYTE|Tamanho de prólogo|  
|UBYTE|Contagem de códigos de liberação|  
|UBYTE: 4|Registro de quadro|  
|UBYTE: 4|Deslocamento de quadro de registro (escala)|  
|USHORT * n|Desenrolar a matriz de códigos|  
|variável|Pode ser de formulário (1) ou (2) a seguir|  
  
 (1) manipulador de exceção  
  
|||  
|-|-|  
|ULONG|Endereço do manipulador de exceção|  
|variável|Dados de manipulador específico do idioma (opcionais)|  
  
 (2) encadeados desenrolar informações  
  
|||  
|-|-|  
|ULONG|Endereço inicial de função|  
|ULONG|Endereço de final de função|  
|ULONG|Endereço de informações de liberação|  
  
 A estrutura UNWIND_INFO deve ser DWORD alinhado na memória. O significado de cada campo é o seguinte:  
  
 **Versão**  
 Número de versão dos dados de desenrolamento, 1 no momento.  
  
 **Sinalizadores**  
 Três sinalizadores são definidos no momento:  
  
 UNW_FLAG_EHANDLER a função tem um manipulador de exceção deve ser chamado durante a procura de funções que precisa examinar exceções.  
  
 UNW_FLAG_UHANDLER a função tem um manipulador de término deve ser chamado quando o desenrolamento da exceção.  
  
 UNW_FLAG_CHAININFO isso desenrolar informações de estrutura não é a principal para o procedimento. Em vez disso, o encadeadas desenrolar informações de entrada é o conteúdo de uma entrada RUNTIME_FUNCTION anterior. Consulte o texto a seguir para obter uma explicação de encadeados estruturas de informações desenroladas. Se esse sinalizador estiver definido, os sinalizadores UNW_FLAG_EHANDLER e UNW_FLAG_UHANDLER devem ser removidos. Além disso, os campos de alocação de quadro registrar e pilha fixa devem ter os mesmos valores de primário desenrolar informações.  
  
 **Tamanho de prólogo**  
 Comprimento de prólogo da função em bytes.  
  
 **Contagem de códigos de liberação**  
 Este é o número de slots na matriz de códigos de desenrolamento. Observe que alguns desenrolar códigos (por exemplo, UWOP_SAVE_NONVOL) exigem mais de um slot na matriz.  
  
 **Registro de quadro**  
 Se for diferente de zero, a função usa um ponteiro de quadro e este campo é o número do registro não volátil usado como o ponteiro de quadro, usando a mesma codificação para o campo de informações de operação de nós UNWIND_CODE.  
  
 **Registrar o quadro de deslocamento (escala)**  
 Se o campo de registro do quadro é diferente de zero, isso é o deslocamento em escala do RSP é aplicada para o registro FP quando ela é estabelecida. O registro FP real é definido como RSP + 16 * esse número, permitindo que os deslocamentos de 0 a 240. Isso permite que aponte o registro FP no meio da alocação da pilha de local para os quadros de pilha dinâmico, permitindo que melhor densidade de código mais curto instruções (mais instruções podem usar o formulário de deslocamento assinado de 8 bits).  
  
 **Desenrolar a matriz de códigos**  
 Esta é uma matriz de itens que explica o efeito de prólogo nos registros não volátil e RSP. Consulte a seção sobre UNWIND_CODE para os significados de itens individuais. Para fins de alinhamento, essa matriz sempre terá um número par de entradas, com a entrada final potencialmente não utilizada (caso em que a matriz será um maior que o indicado pela contagem de campo de códigos de liberação).  
  
 **Endereço do manipulador de exceção**  
 Isso é um ponteiro de imagem relativo ao manipulador de exceção/encerramento específico do idioma da função (se o sinalizador UNW_FLAG_CHAININFO é clara e um dos sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER estiver definido).  
  
 **Dados de manipulador de idioma específico**  
 Isso é dados da função do manipulador de exceção específicos do idioma. O formato de dados é especificado e completamente determinado pelo manipulador de exceção específicos em uso.  
  
 **Encadeados desenrolar informações**  
 Se o sinalizador UNW_FLAG_CHAININFO for definido, em seguida, a estrutura UNWIND_INFO termina com três UWORDs.  Essas UWORDs representam as informações de RUNTIME_FUNCTION para a função do desenrolamento encadeadas.  
  
## <a name="see-also"></a>Consulte também  
 [Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)