---
title: Alinhamento de controles em um guia | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- DLUs (dialog units)
- controls [C++], aligning
- Dialog editor, snap to guides
- guides, tick mark interval
- dialog box controls, placement
- guides, aligning controls
- dialog units (DLUs)
- snap to guides (Dialog editor)
- controls [C++], sizing
- tick mark interval in Dialog editor
- controls [C++], snap to guides/grid
ms.assetid: 17db84ba-5288-4478-be57-afa748aa6447
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eed9acf533939d305e42478bb87307bc0a055d3e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aligning-controls-on-a-guide"></a>Alinhando controles em um guia
As alças de dimensionamento de controles ajustam às guias quando os controles são movidos e guias de ajustam a controles (se não existem controles anteriormente ajustados para o guia). Quando um guia é movido, controles que são ajustados movem também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.  
  
 As marcas de escala nas réguas que determinam o espaçamento de guias e controles são definidas pelas unidades de diálogo (DLUs). Um DLU é baseado no tamanho da fonte de caixa de diálogo, normalmente 8 pontos MS Shell Dlg. Um DLU horizontal é a largura média da fonte de caixa de diálogo dividida em quatro. Um DLU vertical é a altura média da fonte dividida por 8.  
  
### <a name="to-size-a-group-of-controls-with-guides"></a>Para dimensionar um grupo de controles com guias  
  
1.  Encaixe um lado do controle (ou controles) um guia.  
  
2.  Arraste um guia para o outro lado de controle (ou controles).  
  
     Se necessário, com vários controles, tamanho de cada para encaixar na segunda guia.  
  
3.  Mova a guia dimensionar o controle (ou controles).  
  
### <a name="to-change-the-intervals-of-the-tick-marks"></a>Para alterar os intervalos das marcas de escala  
  
1.  Do **formato** menu, escolha **guia Configurações**.  
  
2.  No [caixa de diálogo de configurações do guia](../windows/guide-settings-dialog-box.md), no **espaçamento da grade** , especifique uma nova largura e altura em DLUs.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Estados do Editor de caixa de diálogo (guias e grades)](../windows/dialog-editor-states-guides-and-grids.md)   
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)

