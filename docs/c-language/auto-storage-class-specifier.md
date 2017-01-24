---
title: "Especificador de classe de armazenamento auto | Microsoft Docs"
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
  - "C"
ms.assetid: 8e73f57e-aa92-4e41-91ea-5c8ad2a2b332
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificador de classe de armazenamento auto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O especificador de classe de armazenamento **auto** declara uma variável automática, uma variável com um tempo de vida local.  Uma variável **auto** pode ser vista somente no bloco em que é declarada.  As declarações de variáveis **auto** podem incluir inicializadores, conforme discutido em [Inicialização](../c-language/initialization.md).  Como as variáveis com a classe de armazenamento **auto** não são inicializadas automaticamente, você deve inicializá\-las explicitamente ao declará\-las ou atribuir valores iniciais a elas em instruções no bloco.  Os valores das variáveis **auto** não inicializadas estão indefinidos. \(A variável local da classe de armazenamento **auto** ou **register** será inicializada sempre que aparecer no escopo, se um inicializador for fornecido.\)  
  
 Uma variável interna **static** \(uma variável estática com escopo local ou de bloco\) pode ser inicializada com o endereço de qualquer item externo ou **static**, mas não com o endereço de outro item **auto**, pois o endereço de um item **auto** não é uma constante.  
  
## Consulte também  
 [Palavra\-chave auto](../cpp/auto-keyword.md)