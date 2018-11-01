---
title: Redimensionando uma imagem (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.image.editing
helpviewer_keywords:
- Image editor [C++], resizing images
- graphics [C++], resizing
- images [C++], resizing
- resizing images
ms.assetid: d83a02c4-4dfe-4586-a0df-51a50c2ba71d
ms.openlocfilehash: 721a8f1de511c105df5d72bbe60685d210ad5a94
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576092"
---
# <a name="resizing-an-image-image-editor-for-icons"></a>Redimensionando uma imagem (editor de imagens para ícones)

O comportamento do **imagem** editor ao redimensionar uma imagem depende do fato de ter sido [selecionado](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas uma parte dele.

Quando a seleção inclui apenas a parte da imagem, o **imagem** editor reduz a seleção de exclusão de linhas ou colunas de pixels e preenchendo as regiões vazias com a cor de plano de fundo atual, ou que ele se estende a seleção por Duplicar linhas ou colunas de pixels.

Quando a seleção inclui toda a imagem, o **imagem** editor seja é reduzido e alonga a imagem, ou corta e estende-o.

Há dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e o [janela de propriedades](/visualstudio/ide/reference/properties-window). Você pode arrastar as alças de dimensionamento para alterar o tamanho de todos ou parte de uma imagem. Alças de dimensionamento que você pode arrastar são sólidas. Você não pode arrastar as alças que estão vazios. Você pode usar o **propriedades** somente, de janela para redimensionar toda a imagem não é uma parte selecionada.

![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")<br/>
Alças de dimensionamento

> [!NOTE]
> Se você tiver o **grade lado a lado** opção selecionada na [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensionamento, em seguida, se ajusta para a próxima linha de grade lado a lado. Se apenas a **grade de pixels** opção é selecionada (a configuração padrão), redimensionamento de snaps de pixel para a próxima disponível.

- [Redimensionando uma imagem inteira](../windows/resizing-an-entire-image-image-editor-for-icons.md)

- [Recortando ou estendendo uma imagem inteira](cropping-or-extending-an-entire-image-image-editor-for-icons.md)

- [Reduzindo ou alongando uma imagem inteira](../windows/shrinking-or-stretching-an-entire-image-image-editor-for-icons.md)

- [Reduzindo ou alongando parte de uma imagem](../windows/shrinking-or-stretching-part-of-an-image-image-editor-for-icons.md)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)