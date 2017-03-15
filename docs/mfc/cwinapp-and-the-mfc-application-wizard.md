---
title: "CWinApp e o Assistente de Aplicativo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CWinApp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assistentes de aplicativo [C++], e CWinApp"
  - "Classe CWinApp, e Assistente de Aplicativo MFC"
  - "MFC [C++], assistentes"
ms.assetid: f8ac0491-3302-4e46-981d-0790624eb8a2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CWinApp e o Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando cria um aplicativo do esqueleto, o assistente de aplicativo MFC declara uma classe derivada do aplicativo de [CWinApp](../mfc/reference/cwinapp-class.md).  O assistente de aplicativo MFC também gerencia um arquivo de implementação que contém os seguintes itens:  
  
-   Um mapa de mensagem para a classe do aplicativo.  
  
-   Um construtor vazia da classe.  
  
-   Uma variável que declare aquela e o único objeto da classe.  
  
-   Uma implementação padrão da função de membro de `InitInstance` .  
  
 A classe de aplicativo é colocada nos arquivos de origem do cabeçalho e do main do projeto.  Os nomes da classe e os arquivos são criados com base no nome de projeto que você fornece no assistente de aplicativo MFC.  A maneira mais fácil de exibir o código para essas classes é com [Exibição da classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
 As implementações e o mapa padrão da mensagem fornecido são suficientes para muitos propósitos, mas você pode alterá\-las quando necessário.  O mais interessante dessas implementações é a função de membro de `InitInstance` .  Normalmente, você adicionará código para a implementação esqueletal de `InitInstance`.  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)   
 [Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)   
 [Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)