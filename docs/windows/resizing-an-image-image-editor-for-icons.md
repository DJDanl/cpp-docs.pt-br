---
title: Redimensionando uma imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.image.editing
dev_langs:
- C++
helpviewer_keywords:
- Image editor [C++], resizing images
- graphics [C++], resizing
- images [C++], resizing
- resizing images
ms.assetid: d83a02c4-4dfe-4586-a0df-51a50c2ba71d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 41494e8b88f41c4c842e95e9f8a9f5da0247739f
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39605637"
---
# <a name="resizing-an-image-image-editor-for-icons"></a>Redimensionando uma imagem (editor de imagens para ícones)
O comportamento do editor de imagem ao redimensionar uma imagem depende do fato de ter sido [selecionados](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas uma parte dele.  
  
 Quando a seleção inclui apenas a parte da imagem, o editor de imagens reduz a seleção excluindo linhas ou colunas de pixels e preenchendo as regiões vazias com a cor de plano de fundo atual, ou ela se estende a seleção duplicando linhas ou colunas de pixels.  
  
 Quando a seleção inclui toda a imagem, o editor de imagens tanto é reduzido e alonga a imagem, ou corta e estende-o.  
  
 Há dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e o [janela de propriedades](/visualstudio/ide/reference/properties-window). Você pode arrastar as alças de dimensionamento para alterar o tamanho de todos ou parte de uma imagem. Alças de dimensionamento que você pode arrastar são sólidas. Você não pode arrastar as alças que estão vazios. Você pode usar a janela de propriedades para redimensionar a imagem inteira, não é uma parte selecionada.  
  
 ![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")  
Alças de dimensionamento  
  
> [!NOTE]
>  Se você tem a opção de bloco de grade selecionada na [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensionamento, em seguida, se ajusta para a próxima linha de grade lado a lado. Se apenas a grade de pixels a opção é selecionada (a configuração padrão), redimensionamento de snaps de pixel para a próxima disponível.  
  
-   [Redimensionando uma imagem inteira](../windows/resizing-an-entire-image-image-editor-for-icons.md)  
  
-   [Recortando ou estendendo uma imagem inteira](cropping-or-extending-an-entire-image-image-editor-for-icons.md)  
  
-   [Reduzindo ou alongando uma imagem inteira](../windows/shrinking-or-stretching-an-entire-image-image-editor-for-icons.md)  
  
-   [Reduzindo ou alongando parte de uma imagem](../windows/shrinking-or-stretching-part-of-an-image-image-editor-for-icons.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)