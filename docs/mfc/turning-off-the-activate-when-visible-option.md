---
title: "Desativando a op&#231;&#227;o Ativar Quando Vis&#237;vel | Microsoft Docs"
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
helpviewer_keywords: 
  - "Opção Ativar Quando Visível"
  - "Controles ActiveX MFC [C++], ativar opções"
ms.assetid: 8f7ddc5a-a7a6-4da8-bcb9-1b569f0ecb48
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Desativando a op&#231;&#227;o Ativar Quando Vis&#237;vel
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle tem dois estados básicos: ativa e inativo.  Tradicionalmente, esses estados foram distinguidos pelo se o controle tiver uma janela.  Um controle ativa tinha uma janela; um controle inativa não fez.  Com a introdução de ativação sem o windows, essa distinção não é mais universal, mas ainda se aplica a muitos controles.  
  
 Comparado com o restante da inicialização executada normalmente por um controle ActiveX, a criação de uma janela é uma operação muito dispendiosa.  De modo ideal, um controle adiaria a criação da janela até que seja absolutamente necessário.  
  
 Muitos controles não precisam estar ativas no momento que inteiros são visíveis em um contêiner.  Frequentemente, um controle pode permanecer no estado inativo até que o usuário executa uma operação que o requer se tornar ativa \(por exemplo, clique com o mouse ou pressionando a tecla TAB\).  Para fazer com que um controle permanece inativo até o contêiner precisa ativá\-lo ou desativá\-lo, remove o sinalizador de **OLEMISC\_ACTIVATEWHENVISIBLE** de diversos sinalizadores de controle:  
  
 [!code-cpp[NVC_MFC_AxOpt#9](../mfc/codesnippet/CPP/turning-off-the-activate-when-visible-option_1.cpp)]  
  
 O sinalizador de **OLEMISC\_ACTIVATEWHENVISIBLE** é omitido automaticamente se você desativar a opção de **Activate When Visible** na página de [Controle configurações](../mfc/reference/control-settings-mfc-activex-control-wizard.md) do assistente do controle ActiveX MFC quando você cria o controle.  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)