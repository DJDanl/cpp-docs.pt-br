---
title: Usando a paleta de 256 cores (editor de imagens para ícones)
ms.date: 11/04/2016
helpviewer_keywords:
- 256-color palette
- cursors [C++], color
- colors [C++], icons
- colors [C++], cursors
- icons, color
- colors [C++], icons and cursors
- color palettes, 256-color
- palettes, 256-color
ms.assetid: 2738089b-4fd3-4c45-96ae-6a15e4c6b780
ms.openlocfilehash: 4e2f2c9ce58799756137bb47db42e52c97a43d39
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702889"
---
# <a name="using-the-256-color-palette-image-editor-for-icons"></a>Usando a paleta de 256 cores (editor de imagens para ícones)

Usando o **imagem** editor, ícones e cursores podem ser dimensionados grandes (64 × 64) com uma paleta de 256 cores à sua escolha. Depois de criar o recurso, um estilo de imagem do dispositivo é selecionado.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-create-a-256-color-icon-or-cursor"></a>Para criar um ícone de 256 cores ou cursor

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**.

1. Sobre o **imagem** menu, selecione **nova imagem de dispositivo**.

1. Selecione o estilo de imagem de 256 cores que você deseja.

## <a name="to-choose-a-color-from-the-256-color-palette-for-large-icons"></a>Para escolher uma cor da paleta de 256 cores de ícones grandes

Para desenhar com uma seleção da paleta de 256 cores, você precisará selecionar as cores do **cores** paleta na [janela cores](../windows/colors-window-image-editor-for-icons.md).

1. Selecione o ícone grande ou cursor ou criar um novo ícone grande ou cursor.

1. Escolha uma cor de 256 cores exibidas nos **cores** paleta na **cores** janela.

   A cor selecionada se tornará a cor atual na **cores** paleta na **cores** janela.

   > [!NOTE]
   > A paleta inicial usada para imagens de 256 cores corresponde a paleta retornada pelo `CreateHalftonePalette` API do Windows. Todos os ícones destinados para o shell do Windows devem usar essa paleta para evitar a cintilação durante a realização da paleta.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Ícones e cursores: Recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)
