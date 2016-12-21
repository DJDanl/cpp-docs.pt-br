---
title: "Erro das Ferramentas de Vinculador LNK2013 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK2013"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2013"
ms.assetid: 21408e2d-3f56-4d1f-a031-00df70785ed4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2013
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

estouro de fixup do tipo de fixup.O destino “nome de símbolo” está fora do intervalo  
  
 O vinculador não pode ajustar o endereço ou o deslocamento necessário na instrução fornecida como o símbolo de destino for muito longe do local da instrução.  
  
 Você pode resolver esse problema criando várias imagens ou usando a opção de [\/ORDER](../../build/reference/order-put-functions-in-order.md) assim que a instrução e o destino são mais próximas umas.  
  
 Quando o nome de símbolo é um símbolo definido pelo usuário \(e não um símbolo completo gerado\), você também pode tentar as seguintes ações resolver o erro:  
  
-   Alterar a função estática para ser não estático.  
  
-   Renomeie a seção de código que contém a função estática para ser o mesmo que o chamador.  
  
 Use `DUMPBIN /SYMBOLS`, para ver se é uma função estática.