---
title: Convertendo Bitmaps em barras de ferramentas (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.newtoolbarresource
helpviewer_keywords:
- bitmaps [C++], converting to toolbars
- Toolbar editor [C++], converting bitmaps
- toolbars [C++], converting bitmaps
- New Toolbar Resource dialog box [C++]
ms.assetid: 971c181b-40f5-44be-843d-677a7c235667
ms.openlocfilehash: 31b684ff72e970a6b09748b3925564b0b372d339
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702694"
---
# <a name="converting-bitmaps-to-toolbars-c"></a>Convertendo Bitmaps em barras de ferramentas (C++)

Você pode criar uma nova barra de ferramentas em um projeto C++, convertendo um bitmap. O gráfico a partir do bitmap que converte as imagens de botão para uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. Imagens podem ser de qualquer tamanho; o padrão é 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens do botão na **novos recursos da barra de ferramentas** caixa de diálogo quando você escolhe **barra de ferramentas do Editor** do **imagem** menu enquanto estiver no editor de imagens.

O **novos recursos da barra de ferramentas** caixa de diálogo permite que você especifique a largura e altura dos botões que você está adicionando a um recurso da barra de ferramentas em um projeto C++. O padrão é 16 × 15 pixels.

Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a **largura do botão** para 512, você só pode ter quatro botões. Se você definir a largura como 513, você só pode ter três botões.

A caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Largura do botão**|Fornece um espaço para que você insira a largura para os botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).|
|**Altura do botão**|Fornece um espaço para que você insira a altura dos botões de barra de ferramentas que você estiver convertendo a partir de um recurso de bitmap em um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).|

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-convert-bitmaps-to-a-toolbar"></a>Para converter os bitmaps em uma barra de ferramentas

1. Abra um recurso de bitmap existente na [editor de imagens](../windows/image-editor-for-icons.md). (Se o bitmap não estiver em seu arquivo. RC, clique com botão direito no arquivo. RC, escolha **importação** no menu de atalho, navegue até o bitmap que você deseja adicionar ao seu arquivo. RC, e selecione **abrir**.)

1. Dos **imagem** menu, escolha **Editor de barra de ferramentas**.

   O **novos recursos da barra de ferramentas** caixa de diálogo é exibida. Você pode alterar a largura e altura das imagens do ícone para coincidir com o bitmap. A imagem da barra de ferramentas, em seguida, é exibida no editor de barra de ferramentas.

1. Para concluir a conversão, altere o comando **identificação** do botão usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Digite o novo **identificação** ou selecione um **ID** na lista suspensa.

   > [!TIP]
   > O **propriedades** janela contém um botão de pino na barra de título. Selecione este botão habilita ou desabilita **ocultar automaticamente** para a janela. Para percorrer rapidamente todas as propriedades do botão de barra de ferramentas sem precisar reabrir janelas de propriedade individuais, ative **ocultar automaticamente** desativado para que o **propriedades** janela permaneça estacionário.

Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o [janela de propriedades](/visualstudio/ide/reference/properties-window). Para obter informações sobre como editar a nova barra de ferramentas, consulte [criando, movendo e editando botões da barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Criando novas barras de ferramentas](../windows/creating-new-toolbars.md)<br/>
[Editor de barra de ferramentas](../windows/toolbar-editor.md)<br/>
[Propriedades do botão de barra de ferramentas](../windows/toolbar-button-properties.md)<br/>
