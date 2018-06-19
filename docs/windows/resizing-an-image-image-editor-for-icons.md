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
ms.openlocfilehash: c6636e1f92907c301c6e66abd63f744375bffeb8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879042"
---
# <a name="resizing-an-image-image-editor-for-icons"></a>Redimensionando uma imagem (editor de imagens para ícones)
O comportamento do editor de imagem ao redimensionar uma imagem depende se você tiver [selecionado](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas uma parte dele.  
  
 Quando a seleção inclui somente a parte da imagem, o editor de imagem reduz a seleção excluindo as linhas ou colunas de pixels e preencha as regiões livres com a cor de plano de fundo atual, ou estende a seleção duplicando linhas ou colunas de pixels.  
  
 Quando a seleção inclui a imagem inteira, o editor de imagem seja reduz e expande a imagem ou corta e estende.  
  
 Existem dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e o [janela propriedades](/visualstudio/ide/reference/properties-window). Você pode arrastar as alças de dimensionamento para alterar o tamanho de todas ou parte de uma imagem. Alças de dimensionamento que você pode arrastar são sólidas. Você não pode arrastar os identificadores que estão vazios. Você pode usar a janela de propriedades para redimensionar a imagem inteira, não é uma parte selecionada.  
  
 ![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")  
Alças de dimensionamento  
  
> [!NOTE]
>  Se você tem a opção de bloco de grade selecionada no [caixa de diálogo Configurações de grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensionamento snapshots para a próxima linha de grade do bloco. Se somente a grade de pixels a opção é selecionada (a configuração padrão), redimensionamento de instantâneos para o próximo pixel disponível.  
  
-   [Redimensionando uma imagem inteira](../windows/resizing-an-entire-image-image-editor-for-icons.md)  
  
-   [Recortando ou estendendo uma imagem inteira](cropping-or-extending-an-entire-image-image-editor-for-icons.md)  
  
-   [Reduzindo ou alongando uma imagem inteira](../windows/shrinking-or-stretching-an-entire-image-image-editor-for-icons.md)  
  
-   [Reduzindo ou alongando parte de uma imagem](../windows/shrinking-or-stretching-part-of-an-image-image-editor-for-icons.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

