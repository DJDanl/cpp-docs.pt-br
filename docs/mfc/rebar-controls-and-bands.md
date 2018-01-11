---
title: Controles rebar e bandas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- rebar controls [MFC], working with bands in
- bands, in rebar controls
ms.assetid: b647e7a5-9ea7-48b1-8e5f-096d104748f0
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6426a25746858ed5bd7c0d8ef70575e029453bae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rebar-controls-and-bands"></a>Controles rebar e bandas
A principal finalidade de um controle rebar é atuar como um contêiner para janelas filho, controles de caixa de diálogo comuns, menus, barras de ferramentas e assim por diante. Essa contenção é suportada pelo conceito de "banda". Cada faixa rebar pode conter qualquer combinação de uma barra dupla, um bitmap, um rótulo de texto e uma janela filho.  
  
 Classe `CReBarCtrl` tem muitas funções de membro que você pode usar para recuperar e manipular informações de uma faixa de rebar específico:  
  
-   [GetBandCount](../mfc/reference/crebarctrl-class.md#getbandcount) recupera o número de faixas atuais no controle rebar.  
  
-   [GetBandInfo](../mfc/reference/crebarctrl-class.md#getbandinfo) inicializa um **REBARBANDINFO** estrutura de informações da banda especificada. Há um correspondente [SetBandInfo](../mfc/reference/crebarctrl-class.md#setbandinfo) função de membro.  
  
-   [GetRect](../mfc/reference/crebarctrl-class.md#getrect) recupera o retângulo delimitador de uma faixa especificada.  
  
-   [GetRowCount](../mfc/reference/crebarctrl-class.md#getrowcount) recupera o número de linhas de banda em um controle rebar.  
  
-   [IDToIndex](../mfc/reference/crebarctrl-class.md#idtoindex) recupera o índice de uma faixa especificada.  
  
-   [GetBandBorders](../mfc/reference/crebarctrl-class.md#getbandborders) recupera as bordas de uma faixa.  
  
 Além de manipulação, várias funções de membro são contanto que permitem que você a operar bandas rebar específico.  
  
 [InsertBand](../mfc/reference/crebarctrl-class.md#insertband) e [DeleteBand](../mfc/reference/crebarctrl-class.md#deleteband) adicionar e remover bandas rebar. [MinimizeBand](../mfc/reference/crebarctrl-class.md#minimizeband) e [MaximizeBand](../mfc/reference/crebarctrl-class.md#maximizeband) afeta o tamanho atual de uma faixa de rebar específico. [MoveBand](../mfc/reference/crebarctrl-class.md#moveband) altera o índice de uma faixa de rebar específico. [ShowBand](../mfc/reference/crebarctrl-class.md#showband) mostra ou oculta uma faixa de rebar do usuário.  
  
 O exemplo a seguir demonstra como adicionar uma faixa da barra de ferramentas (`m_wndToolBar`) para um controle rebar existente (`m_wndReBar`). A faixa é descrita por inicializar o `rbi` estrutura e, em seguida, chamar o `InsertBand` função de membro:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#27](../mfc/codesnippet/cpp/rebar-controls-and-bands_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

