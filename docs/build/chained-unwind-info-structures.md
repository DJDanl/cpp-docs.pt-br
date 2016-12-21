---
title: "Estruturas de informa&#231;&#245;es desenroladas encadeadas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 176835bf-f118-45d9-9128-9db4b7571864
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estruturas de informa&#231;&#245;es desenroladas encadeadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o sinalizador de UNW\_FLAG\_CHAININFO é definido, uma estrutura de informações de desenrolamento é new, e o campo de endereço compartilhado de exceção manipulador\/informações contém o principal desenrola informações.  O código a seguir recupera o principal desenrola informações, supondo que `unwindInfo` é a estrutura que tem o sinalizador de UNW\_FLAG\_CHAININFO definido.  
  
```  
PRUNTIME_FUNCTION primaryUwindInfo = (PRUNTIME_FUNCTION)&(unwindInfo->UnwindCode[( unwindInfo->CountOfCodes + 1 ) & ~1]);  
```  
  
 Informações encadeada é útil em duas situações.  Primeiro, podem ser usadas para segmentos de código não contígua.  Usando informações encadeada, você pode reduzir o tamanho de necessário desenrola informações, porque você não tem que duplicar os códigos de desenrolamento a matriz de primária desenrola informações.  
  
 Você também pode usar informações encadeada para agrupar o registro temporário salva.  O compilador pode atrasar salvar alguns registros voláteis até que está fora de prólogo de entrada da função.  Você pode registrar este tendo primária desenrola informações para a parte da função antes que o código agrupados, e então configurar informações encadeada com um tamanho diferente de zero de prólogo, onde os códigos de desenrolamento nas informações encadeada refletem a salvar os registros permanentes.  Nesse caso, os códigos de desenrolamento são todas as instâncias de UWOP\_SAVE\_NONVOL.  Um agrupamento que salva permanentes registros usando um ENVIO ou modifique o registro de RSP usando uma alocação de pilha fixa adicional não é suportado.  
  
 Um item de UNWIND\_INFO que tenha definido UNW\_FLAG\_CHAININFO pode conter uma entrada de RUNTIME\_FUNCTION cujo item de UNWIND\_INFO também tem UNW\_FLAG\_CHAININFO definido \(várias que envolve\).  Se houver, encadeados desenrolam ponteiros de informações chegarão em um item de UNWIND\_INFO que tem UNW\_FLAG\_CHAININFO desmarcado; este é o item primária de UNWIND\_INFO, que aponta para o ponto de entrada real do procedimento.  
  
## Consulte também  
 [Dados desenrolados para tratamento de exceções, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)