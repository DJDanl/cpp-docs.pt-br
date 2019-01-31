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
- size [C++], images
- images [C++], cropping
- images [C++], extending
- Image editor [C++], cropping or extending images
- Image editor [C++], shrinking and stretching images
- images [C++], stretching
- images [C++], shrinking
- bitmaps [C++], shrinking
- bitmaps [C++], stretching
ms.assetid: d83a02c4-4dfe-4586-a0df-51a50c2ba71d
ms.openlocfilehash: d88a4cccff5b9b7b6303329782b7367cb953b13d
ms.sourcegitcommit: 5270117dbecc4c49bca0cf10b927bae3c9930038
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/31/2019
ms.locfileid: "55484962"
---
# <a name="resizing-an-image-image-editor-for-icons"></a>Redimensionando uma imagem (editor de imagens para ícones)

O comportamento do **imagem** editor ao redimensionar uma imagem depende do fato de ter sido [selecionado](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) a imagem inteira ou apenas uma parte dele.

Quando a seleção inclui apenas a parte da imagem, o **imagem** editor reduz a seleção de exclusão de linhas ou colunas de pixels e preenchendo as regiões vazias com a cor de plano de fundo atual. Ele também pode estender a seleção duplicando linhas ou colunas de pixels.

Quando a seleção inclui toda a imagem, o **imagem** editor seja é reduzido e alonga a imagem, ou corta e estende-o.

Há dois mecanismos para redimensionar uma imagem: as alças de dimensionamento e o [janela de propriedades](/visualstudio/ide/reference/properties-window). Você arrastar as alças de dimensionamento para alterar o tamanho de todos ou parte de uma imagem. Alças de dimensionamento que você pode arrastar são sólidas. Você não pode arrastar as alças que estão vazios. Use o **propriedades** somente, de janela para redimensionar toda a imagem não é uma parte selecionada.

![Alças de dimensionamento em um bitmap](../mfc/media/vcimageeditorsizinghandles.gif "vcImageEditorSizingHandles")<br/>
Alças de dimensionamento

> [!NOTE]
> Se você tiver o **grade lado a lado** opção selecionada na [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md), redimensionamento, em seguida, se ajusta para a próxima linha de grade lado a lado. Se apenas a **grade de pixels** opção é selecionada (a configuração padrão), redimensionamento de snaps de pixel para a próxima disponível.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-resize-an-entire-image-using-the-properties-window"></a>Para redimensionar uma imagem inteira usando a janela Propriedades

1. Abra a imagem cujas propriedades você deseja alterar.

1. No **largura** e **altura** nas caixas de [janela propriedades](/visualstudio/ide/reference/properties-window), digite as dimensões que você deseja.

   Se você aumentar o tamanho da imagem, o **imagem** editor estende a imagem à direita, para baixo, ou ambos e preenche a nova região com a cor de plano de fundo atual. A imagem não está esticada.

   Se você reduzir o tamanho da imagem, o **imagem** editor corta a imagem na borda direita ou inferior, ou ambos.

   > [!NOTE]
   > Você pode usar o **largura** e **altura** propriedades redimensionar somente a imagem inteira, não para redimensionar uma seleção parcial.

## <a name="to-crop-or-extend-an-entire-image"></a>Para cortar ou estender uma imagem inteira

1. Selecione a imagem inteira.

   Se parte da imagem está selecionado no momento, e você deseja selecionar a imagem inteira, selecione qualquer lugar na imagem de fora da borda da seleção atual.

1. Arraste uma alça de dimensionamento até que a imagem é o tamanho correto.

Normalmente, o **imagem** editor corta ou amplia uma imagem quando você redimensioná-la ao mover uma alça de dimensionamento. Se você mantiver pressionada a **Shift** chave conforme você move uma alça de dimensionamento, o **imagem** editor reduz ou alonga a imagem.

## <a name="to-shrink-or-stretch-an-entire-image"></a>Para reduzir ou alongar uma imagem inteira

1. Selecione a imagem inteira.

   Se uma parte da imagem está selecionada no momento e você deseja selecionar a imagem inteira, selecione qualquer lugar na imagem de fora da borda da seleção atual.

1. Mantenha pressionada a **Shift** da chave e arrastar uma alça de dimensionamento até que a imagem é o tamanho correto.

## <a name="to-shrink-or-stretch-part-of-an-image"></a>Para reduzir ou ampliar parte de uma imagem

1. Selecione a parte da imagem que você deseja redimensionar. Para obter mais informações, consulte [selecionando uma área da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md).

1. Arraste uma das alças de dimensionamento até que a seleção é o tamanho correto.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)