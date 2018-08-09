---
title: Alinhando controles em um guia | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a1a586a3a17e829d883dff96c12f6a2fdabe669f
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643852"
---
# <a name="aligning-controls-on-a-guide"></a>Alinhando controles em um guia
As alças de dimensionamento de controles de ajustam-se às guias de quando os controles são movidos e guias de ajustam-se aos controles (se não houver nenhum controle ajustado anteriormente para o guia). Quando um guia é movido, controles que são ajustados para que ele é mover também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.  
  
 As marcas de escala em que determinam o espaçamento entre controles e guias de réguas são definidas pelas unidades de caixa de diálogo (DLUs). Um DLU baseia-se no tamanho da fonte de caixa de diálogo, normalmente de 8 pontas MS Shell Dlg. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro. Um DLU vertical é a média altura da fonte dividida por oito.  
  
### <a name="to-size-a-group-of-controls-with-guides"></a>Para dimensionar um grupo de controles com guias  
  
1.  Ajuste um dos lados do controle (ou controles) a uma guia.  
  
2.  Arraste um guia para o outro lado do controle (ou controles).  
  
     Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.  
  
3.  Mova um guia para dimensionar o controle (ou controles).  
  
### <a name="to-change-the-intervals-of-the-tick-marks"></a>Alterar os intervalos das marcas de escala  
  
1.  Dos **formato** menu, escolha **guia de configurações**.  
  
2.  No [guia de caixa de diálogo de configurações](../windows/guide-settings-dialog-box.md), no **espaçamento da grade** , especifique uma nova largura e altura em DLUs.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Estados do Editor de caixa de diálogo (guias e grades)](../windows/dialog-editor-states-guides-and-grids.md)   
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)