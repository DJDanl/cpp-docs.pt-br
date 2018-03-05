---
title: Procedimento desenrolado | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 82c5d0ca-70be-4d1a-a306-bfe01c29159f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8b8caa2be1528c26cf374637f3d0357847721de9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="unwind-procedure"></a>Procedimento desenrolado
A matriz de código de desenrolamento é classificada em ordem decrescente. Quando ocorre uma exceção, o contexto completo é armazenado pelo sistema operacional em um registro de contexto. A lógica de expedição de exceção é invocada, que executa repetidamente as etapas a seguir para localizar um manipulador de exceção.  
  
1.  Use o RIP atual armazenado no registro do contexto para pesquisar uma entrada de tabela RUNTIME_FUNCTION que descreve a função atual (ou parte de função, no caso de entradas UNWIND_INFO encadeadas).  
  
2.  Se nenhuma entrada de tabela de função for encontrada, em seguida, ele está em uma função de folha e RSP diretamente solucionará o ponteiro de retorno. O ponteiro de retorno no [RSP] é armazenado no contexto de atualizado, o RSP simulado é incrementado por 8 e etapa 1 é repetida.  
  
3.  Se for encontrada uma entrada de tabela de função, RIP pode permanecer em três regiões a) em um epílogo, b) no prólogo ou c) no código que pode ser coberto por um manipulador de exceção.  
  
    -   Caso um) se o RIP está dentro de um epílogo e controle está deixando a função, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos de epílogo devem continuar para calcular o contexto da função do chamador. Para determinar se o RIP está dentro de um epílogo, o fluxo de código de RIP em é examinado. Se esse fluxo de código pode ser correspondido à parte posterior de um epílogo legítimo, em seguida, está em um epílogo e a parte restante do epílogo é simulada, com o registro de contexto atualizado como cada instrução é processado. Depois disso, a etapa 1 é repetida.  
  
    -   Caso b) se o RIP permanecerá no prólogo, em seguida, o controle não tem a função inserido, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos de prólogo devem ser desfeitos para calcular o contexto da função do chamador. O RIP está no prólogo se a distância entre o início da função e o RIP é menor ou igual ao tamanho de prólogo codificado em informações de liberação. Os efeitos de prólogo são retornou verificar para a frente por meio da matriz de códigos de desenrolamento da primeira entrada com um deslocamento menor que ou igual ao deslocamento do RIP desde o início da função, em seguida, desfazendo o efeito de todos os itens restantes na matriz de código de desenrolamento. Etapa 1 é repetida.  
  
    -   Caso c) se o RIP não estiver dentro de um prólogo ou epílogo e a função tem um manipulador de exceção (UNW_FLAG_EHANDLER é definido), em seguida, o identificador específico da linguagem é chamado. O manipulador examina seus dados e chamadas de filtragem funções conforme apropriado. O identificador específico da linguagem pode retornar que a exceção foi tratada ou se a pesquisa está para ser contínua. Ele também pode iniciar um desenrolamento diretamente.  
  
4.  Se o identificador específico da linguagem retorna um status manipulado, a execução continua usando o registro de contexto original.  
  
5.  Se há um manipulador específico do idioma ou o manipulador retorna um status "continuar a pesquisa de", o registro de contexto deve ser organizado para o estado do chamador. Isso é feito com o processamento de todos os elementos de matriz de código de desenrolamento, desfazendo o efeito de cada. Etapa 1 é repetida.  
  
 Quando encadeados desenrolar informações estão envolvidas, estas etapas básicas ainda são seguidas. A única diferença é que, ao percorrer a matriz de código de desenrolamento para liberar os efeitos do prólogo, após o final da matriz é atingido, ele é vinculado às informações de liberação pai e a matriz de código de desenrolamento todo encontrada é movimentada. Essa vinculação continua até que chegam a uma informação de desenrolamento sem o sinalizador UNW_CHAINED_INFO e concluir a movimentação de sua matriz de código de desenrolamento.  
  
 O menor conjunto de dados de desenrolamento é de 8 bytes. Isso pode representar uma função que apenas alocado de 128 bytes de pilha ou menos e possivelmente salvo um registro não volátil. Isso também é o tamanho de uma cadeia desenrolar a estrutura de informações para um prólogo de comprimento zero com nenhum código de desenrolamento.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceção (x64)](../build/exception-handling-x64.md)