---
title: Dimensionando controles individuais | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Size to Content command
- size, controls
- text, autosizing controls to fit text
- controls [C++], sizing
ms.assetid: 14ccba02-7171-463a-a121-7018cf1e2e5a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b019cd2bbf68a4321bafd6dd960ffbcdba2dddf7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sizing-individual-controls"></a>Dimensionando controles individuais
Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as instruções no qual o controle pode ser redimensionado. Alças de dimensionamento ativo são sólidas; Se uma alça de dimensionamento estiver vazia, o controle não pode ser redimensionado ao longo desse eixo.  
  
 Você também pode alterar o tamanho de um controle, ajuste o controle para guias ou margens ou movendo um ajustado guia longe outro e controle.  
  
### <a name="to-size-a-control"></a>Para dimensionar um controle  
  
1.  Selecione o controle.  
  
2.  Arraste as alças de dimensionamento para alterar o tamanho do controle:  
  
    -   Alças de dimensionamento na parte superior e lados alterar o tamanho horizontal ou vertical.  
  
    -   Alças de dimensionamento nos cantos alteram tamanho horizontal e vertical.  
  
    > [!TIP]
    >  Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a tecla SHIFT e usando as teclas de seta para baixo à direita.  
  
### <a name="to-automatically-size-a-control-to-fit-the-text-within-it"></a>Para dimensionar automaticamente um controle para ajustar o texto dentro dele  
  
1.  Escolha **tamanho ao conteúdo** do **formato** menu.  
  
 \- ou -  
  
-   Clique com botão direito do controle e escolha **tamanho ao conteúdo** no menu de atalho.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

