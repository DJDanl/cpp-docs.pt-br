---
title: Alocação de pilha | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 098e51f2-eda6-40d0-b149-0b618aa48b47
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: caa6d435db98c7177cbf55b866bb8e5a4a110c1d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="stack-allocation"></a>Alocação da pilha
Prólogo da função é responsável pela alocação de espaço de pilha para variáveis locais, registros salvos, parâmetros de pilha e registre os parâmetros.  
  
 A área de parâmetro é sempre na parte inferior da pilha (mesmo se alloca é usado), de modo que ele sempre será adjacente para o endereço de retorno durante qualquer chamada de função. Ele contém pelo menos quatro entradas, mas sempre espaço suficiente para conter todos os parâmetros necessários por qualquer função que pode ser chamada. Observe que sempre espaço é alocado para os parâmetros de registro, mesmo se os parâmetros se nunca são adaptadores de rede para a pilha; um receptor é garantido que tenha sido alocado espaço para todos os seus parâmetros. Endereços residenciais são necessários para os argumentos de registro para uma área contígua disponível no caso da função de chamada precisa obter o endereço da lista de argumentos (va_list) ou um argumento individual. Essa área também fornece um local conveniente para salvar o registro argumentos durante a execução de conversão e como uma opção de depuração (por exemplo, ele torna os argumentos fácil encontrar durante a depuração se eles são armazenados em seus endereços de base no código de prólogo). Mesmo se a função chamada tiver menos de 4 parâmetros, esses locais da 4 pilha efetivamente pertencentes a função chamada e podem ser usadas pela função chamada para outras finalidades além de economizar parâmetro valores do registro.  Assim, o chamador pode não salvar informações nessa região da pilha em uma chamada de função.  
  
 Se o espaço é alocado dinamicamente (alloca) em uma função, um registro não volátil deve ser usado como um ponteiro de quadro para marcar a base da parte fixa da pilha e esse registro deve ser salvo e inicializado no prólogo. Observe que, quando alloca é usado, chamadas para o mesmo receptor do mesmo chamador podem ter endereços residenciais diferentes para seus parâmetros de registro.  
  
 A pilha sempre será mantida 16 bytes alinhado, exceto no prólogo (por exemplo, depois que o endereço de retorno é enviada por push) e exceto quando indicado em [tipos de função](../build/function-types.md) para uma determinada classe de funções de quadro.  
  
 A seguir está um exemplo de como o layout de pilha não-folha de chamadas de função A função where prólogo B. função do já alocado espaço para todos os parâmetros de registro e a pilha exigidos por B na parte inferior da pilha. A chamada envia o endereço de retorno e prólogo do B aloca espaço para suas variáveis locais, os registros não volátil e o espaço necessário para que ele chamar funções. Se B usa alloca, o espaço é alocado entre o registro de variável/não volátil local salvar área e a área de pilha do parâmetro.  
  
 ![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_5.png "vcAmd_conv_ex_5")  
  
 Quando a função B chama outra função, o endereço do remetente está push logo abaixo do endereço residencial RCX.  
  
## <a name="see-also"></a>Consulte também  
 [Uso da pilha](../build/stack-usage.md)