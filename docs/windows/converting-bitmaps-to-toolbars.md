---
title: Convertendo Bitmaps em barras de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- bitmaps [C++], converting to toolbars
- Toolbar editor, converting bitmaps
- toolbars [C++], converting bitmaps
ms.assetid: 971c181b-40f5-44be-843d-677a7c235667
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d5524b1d5ecb3fa4de38f46706f26d2a318fe5ef
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42602394"
---
# <a name="converting-bitmaps-to-toolbars"></a>Convertendo bitmaps em barras de ferramentas

Você pode criar uma nova barra de ferramentas, convertendo um bitmap. O gráfico a partir do bitmap que converte as imagens de botão para uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. Imagens podem ser de qualquer tamanho; o padrão é 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens do botão na [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md) quando você escolhe **barra de ferramentas do Editor** do **imagem** menu enquanto estiver no editor de imagens.

### <a name="to-convert-bitmaps-to-a-toolbar"></a>Para converter os bitmaps em uma barra de ferramentas

1. Abra um recurso de bitmap existente na [editor de imagens](../windows/image-editor-for-icons.md). (Se o bitmap não estiver mais em seu arquivo. RC, clique com botão direito no arquivo. RC, escolha **importação** no menu de atalho, navegue até o bitmap que você deseja adicionar ao seu arquivo. RC e clique em **abrir**.)

2. Dos **imagem** menu, escolha **Editor de barra de ferramentas**.

   O [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md) é exibida. Você pode alterar a largura e altura das imagens do ícone para coincidir com o bitmap. A imagem da barra de ferramentas, em seguida, é exibida no editor de barra de ferramentas.

3. Para concluir a conversão, altere o comando **identificação** do botão usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Digite o novo **identificação** ou selecione um **ID** na lista suspensa.

   > [!TIP]
   > O **propriedades** janela contém um botão de pino na barra de título. Clicar neste botão ativa ou desativa **ocultar automaticamente** para a janela. Para percorrer rapidamente todas as propriedades do botão de barra de ferramentas sem precisar reabrir janelas de propriedade individuais, ative **ocultar automaticamente** desativado para que o **propriedades** janela permaneça estacionário.

Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o [janela de propriedades](/visualstudio/ide/reference/properties-window). Para obter informações sobre como editar a nova barra de ferramentas, consulte [criando, movendo e editando botões da barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Criando novas barras de ferramentas](../windows/creating-new-toolbars.md)  
[Editor de barra de ferramentas](../windows/toolbar-editor.md)