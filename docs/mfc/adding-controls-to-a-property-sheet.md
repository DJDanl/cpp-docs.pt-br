---
title: Adicionando controles a uma folha de propriedades | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- controls [MFC], adding to property sheets
- property sheets, adding controls
ms.assetid: 24ad4c0b-c1db-4850-b9f0-34aae8d74571
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2acbbed1a253a502aea8b19af6fd16ddb343e3ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-controls-to-a-property-sheet"></a>Adicionando controles a uma folha de propriedades
Por padrão, uma folha de propriedades aloca área da janela para as páginas de propriedade, o índice de tabulação e os botões Okey, cancelar e aplicar. (Uma folha de propriedades sem janela restrita não tem Okey, cancelar e aplicar botões.) Você pode adicionar outros controles para a folha de propriedades. Por exemplo, você pode adicionar uma janela de visualização à direita da área da página de propriedade para mostrar ao usuário a aparência as configurações atuais se aplicado a um objeto externo.  
  
 É possível adicionar controles para a caixa de diálogo de folha de propriedade no `OnCreate` manipulador. Acomodar controles adicionais normalmente requer aumentar o tamanho da caixa de diálogo de folha de propriedade. Depois de chamar a classe base **CPropertySheet::OnCreate**, chame [GetWindowRect](../mfc/reference/cwnd-class.md#getwindowrect) para obter a largura e altura da janela de folha de propriedade atualmente alocados, expanda o retângulo dimensões e chamada [MoveWindow](../mfc/reference/cwnd-class.md#movewindow) para alterar o tamanho da janela de folha de propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)   
 [Classe CPropertyPage](../mfc/reference/cpropertypage-class.md)   
 [Classe CPropertySheet](../mfc/reference/cpropertysheet-class.md)
