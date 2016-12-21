---
title: "Criando um objeto CToolBarCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CToolBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CToolBarCtrl, criando barras de ferramentas"
  - "controles de barra de ferramentas [MFC], criando"
ms.assetid: a4f6bf0c-0195-4dbf-a09e-aee503e19dc3
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um objeto CToolBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

os objetos de[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) contêm várias estruturas de dados internas — uma lista de bitmaps da imagem do botão, uma lista de cadeias de caracteres do rótulo do botão, e uma lista de estruturas de `TBBUTTON` — aquele associado uma imagem e\/ou uma cadeia de caracteres com a posição, o estilo, o estado, e a ID de comando do botão.  Cada um dos elementos dessas estruturas de dados é referenciado por um índice de base zero.  Antes de usar um objeto de `CToolBarCtrl` , você deve configurar essas estruturas de dados.  Para obter uma lista das estruturas de dados, consulte [Controles da barra de ferramentas](https://msdn.microsoft.com/en-us/library/47xcww9x.aspx) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  A lista de cadeias de caracteres só pode ser usada para rótulos do botão; não é possível recuperar cadeias de caracteres da barra de ferramentas.  
  
 Para usar um objeto de `CToolBarCtrl` , normalmente você seguirá estas etapas:  
  
### Para usar um objeto de CToolBarCtrl  
  
1.  Construir o objeto de [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) .  
  
2.  Chame [Crie](../Topic/CToolBarCtrl::Create.md) para criar o controle comuns da barra de ferramentas do windows e anexá\-lo ao objeto de `CToolBarCtrl` .  Se você quiser imagens de bitmap para os botões, adicione os bitmaps no botão na barra de ferramentas [AddBitmap](../Topic/CToolBarCtrl::AddBitmap.md)chamando.  Se você quiser rótulos de cadeia de caracteres para os botões, adicione as cadeias de caracteres à barra de ferramentas chamando [AddString](../Topic/CToolBarCtrl::AddString.md) e\/ou [AddStrings](../Topic/CToolBarCtrl::AddStrings.md).  Depois de chamar `AddString` e\/ou `AddStrings`, você deve chamar [Dimensionamento automático](../Topic/CToolBarCtrl::AutoSize.md) para obter a cadeia de caracteres ou as cadeias de caracteres apareça.  
  
3.  Adicionar estruturas de botão na barra de ferramentas [AddButtons](../Topic/CToolBarCtrl::AddButtons.md)chamando.  
  
4.  Se você quiser dicas de ferramenta, tratar mensagens de **TTN\_NEEDTEXT** na janela do proprietário da barra de ferramentas como descrito em [Notificações de dica de ferramenta de manipulação](../mfc/handling-tool-tip-notifications.md).  
  
5.  Se você deseja que o usuário possam personalizar a barra de ferramentas, tratar notificações de personalização na janela do proprietário como descrito em [Notificações de personalização de manipulação](../Topic/Handling%20Customization%20Notifications.md).  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)