---
title: "Tipos de fun&#231;&#227;o | Microsoft Docs"
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
ms.assetid: 7e33d5f4-dabb-406d-afb3-13777b995028
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tipos de fun&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há basicamente dois tipos de funções.  Uma função que requer um quadro de pilha é chamada uma função do quadro.  Uma função que não requer um quadro de pilha é chamada uma função de folha.  
  
 Uma função de quadro chave é uma função que atribui o espaço de pilha, chama outras funções, salva registros permanentes, ou use manipulação de exceção.  Também requer uma entrada de tabela de função.  Uma função de quadro requer um prólogo e um epílogo.  Uma função de quadro chave pode atribuir dinamicamente o espaço de pilha e pode usar um ponteiro de quadro.  Uma função de quadro possui recursos completos desse padrão de chamada em sua disposição.  
  
 Se uma função de quadro não chama outra função em seguida não é necessário alinhar a pilha \(referenciada na seção [Alocação da pilha](../build/stack-allocation.md)\).  
  
 Uma função de folha é uma que não requer uma entrada de tabela de função.  Não pode chamar qualquer funções, atribua o espaço, ou salvar os registros permanentes.  É permitida deixar a pilha unaligned quando executar.  
  
## Consulte também  
 [Uso da pilha](../build/stack-usage.md)