---
title: "Usando CSpinButtonCtrl | Microsoft Docs"
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
  - "CSpinButtonCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CSpinButtonCtrl, usando"
  - "controle de botão de rotação"
  - "controles para cima-para baixo"
  - "controles para cima-para baixo, controle de botão de rotação"
ms.assetid: a91db36b-e11e-42ef-8e89-51915cc486d2
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CSpinButtonCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O controle *de botão de rotação* \(também conhecido como um controle *de up\-down* \) fornece um par de seta que um usuário pode clicar para ajustar um valor.  Esse valor é conhecido como *a posição atual*.  A posição permanecerá dentro do intervalo do botão de rotação.  Quando o usuário clica na seta para cima, a posição será movido para o máximo; e quando o usuário clica na seta para baixo, a posição será movido para o mínimo.  
  
 O controle de botão de rotação é representado em MFC pela classe de [CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md) .  
  
> [!NOTE]
>  Por padrão, o intervalo para o botão de rotação tem o máximo definido como zero \(0\) e o mínimo definido como 100.  Como o valor máximo é menor que o valor mínimo, clique na seta para cima diminui a posição e clique na seta para baixo aumenta\-a.  Use [CSpinButtonCtrl::SetRange](../Topic/CSpinButtonCtrl::SetRange.md) para ajustar estes valores.  
  
 Normalmente, a posição atual é exibido em um controle complementar.  O controle complementar é conhecido como *a janela de amigo*.  Para obter uma ilustração de um controle de botão de rotação, consulte [Sobre controles de Up\-Down](http://msdn.microsoft.com/library/windows/desktop/bb759889) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Para criar um retorno controle e uma janela de amigo de controle de edição, no Visual Studio, arraste primeiro um controle de edição na caixa de diálogo ou na janela, e arraste um controle de rotação.  Selecione o controle de rotação e define as propriedades de **Buddy Automático** e de **Definir Inteiro Buddy** a **Retifique**.  Também definir a propriedade de **Alinhamento** ; **Alinhar à direita** é o mais comum.  Com essas configurações, o controle de edição é definido como a janela de amigo como precede diretamente o controle de edição na ordem da guia.  Integers do controle de edição e o controle de rotação são inseridos no lado direito de controle de edição.  Opcionalmente, você pode definir o intervalo válido de controle de rotação usando o método de [CSpinButtonCtrl::SetRange](../Topic/CSpinButtonCtrl::SetRange.md) .  Nenhum manipulador de eventos é necessário para se comunicar entre o controle de rotação e a janela de amigo porque ele troca de dados diretamente.  Se você usar um controle de rotação para qualquer outra finalidade, por exemplo, pesquise em uma sequência do windows ou caixas de diálogo, adicione um manipulador para a mensagem de `UDN_DELTAPOS` e executar a ação personalizada lá.  
  
## Que você deseja saber mais?  
  
-   [Estilos de botão Girar](../mfc/spin-button-styles.md)  
  
-   [Funções de membro do botão Girar](../Topic/Spin%20Button%20Member%20Functions.md)  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)