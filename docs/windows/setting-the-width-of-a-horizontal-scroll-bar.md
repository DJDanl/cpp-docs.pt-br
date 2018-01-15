---
title: Definindo a largura de uma barra de rolagem Horizontal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- list controls, scroll bar width
- CListBox::SetHorizontalExtent
- controls [C++], scroll bar
- scroll bars, displaying in controls
- horizontal scroll bar width
- CListBox class, scroll bar width
- scroll bars, width
ms.assetid: 51dad141-aa0b-46a3-a82c-46b80d603d94
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7aeabed9eaa164a0c19fd6b425f36e68059a548d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setting-the-width-of-a-horizontal-scroll-bar"></a>Definindo a largura de uma barra de rolagem horizontal
Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando classes MFC, a barra de rolagem não aparecerão automaticamente em seu aplicativo.  
  
### <a name="to-make-the-scroll-bar-appear"></a>Para tornar a aparecer da barra de rolagem  
  
1.  Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código.  
  
     Sem este conjunto de valores, a barra de rolagem não aparecerá, mesmo quando os itens na caixa de listagem são mais largos do que a caixa.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

