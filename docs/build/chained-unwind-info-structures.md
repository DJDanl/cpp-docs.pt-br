---
title: Encadeados estruturas de informações Desenroladas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 176835bf-f118-45d9-9128-9db4b7571864
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 87469a381c038462549d20b105b791ddb17b1656
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="chained-unwind-info-structures"></a>Estruturas de informações desenroladas encadeadas
Se o sinalizador UNW_FLAG_CHAININFO for definido, uma estrutura de informações de liberação é um secundário, e o campo de endereço de exceção-manipulador/encadeados-info compartilhada contém as informações de liberação principal. A código a seguir recupera informações sobre, supondo que o desenrolamento primário `unwindInfo` é a estrutura que tem o UNW_FLAG_CHAININFO o sinalizador será definido.  
  
```  
PRUNTIME_FUNCTION primaryUwindInfo = (PRUNTIME_FUNCTION)&(unwindInfo->UnwindCode[( unwindInfo->CountOfCodes + 1 ) & ~1]);  
```  
  
 Informações de cadeia são útil em duas situações. Primeiro, ele pode ser usado para segmentos de código não contíguas. Usando as informações de cadeia, você pode reduzir o tamanho das informações de desenrolamento necessária, porque não é necessário duplicar a matriz de códigos de desenrolamento de informações de liberação principal.  
  
 Você também pode usar informações encadeadas para agrupar registro volátil salva. O compilador pode atrasar a salvar alguns registros volátil até que ele está fora de prólogo de entrada da função. Você pode registrar isso, ter informações de liberação principal para a parte da função antes do código agrupado, e, em seguida, configurando encadeados informações com um tamanho diferente de zero de prólogo, onde os códigos de desenrolamento as informações encadeadas refletem salva dos registros não volátil. Nesse caso, os códigos de desenrolamento são todas as instâncias de UWOP_SAVE_NONVOL. Não há suporte para um agrupamento que salva não volátil registros usando um envio por PUSH ou modifica o registro RSP usando uma alocação de pilha fixa adicional.  
  
 Um item UNWIND_INFO que tem UNW_FLAG_CHAININFO definido pode conter uma entrada RUNTIME_FUNCTION item cujo UNWIND_INFO também tem UNW_FLAG_CHAININFO definido (várias shrink-wrapping). Por fim, o encadeadas desenrolar informações ponteiros chegará a um item UNWIND_INFO com UNW_FLAG_CHAININFO desmarcada. Este é o item UNWIND_INFO primário, que aponta para o ponto de entrada de procedimento real.  
  
## <a name="see-also"></a>Consulte também  
 [Desenrolar dados para tratamento de exceção, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)