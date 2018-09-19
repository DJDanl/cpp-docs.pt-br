---
title: Alterando propriedades da imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- images [C++], properties
- Image editor [C++], Properties window
- Properties window, image editor
ms.assetid: f6172bf1-08c4-4dfd-b542-dd8749e83fe6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e3b85faff95e3053ea46edcedef7443cdab445d3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422216"
---
# <a name="changing-image-properties-image-editor-for-icons"></a>Alterando propriedades da imagem (editor de imagens para ícones)

Você pode definir ou modificar propriedades de uma imagem usando o [janela de propriedades](/visualstudio/ide/reference/properties-window).

### <a name="to-change-an-images-properties"></a>Para alterar as propriedades da imagem

1. Abra a imagem na **imagem** editor.

2. No **propriedades** janela, altere uma ou todas as propriedades para a sua imagem.

   |Propriedade|Descrição|
   |--------------|-----------------|
   |**Cores**|Especifica o esquema de cores para a imagem. Selecione **monocromático**, **16**, ou **256**, ou **True Color**. Se você já desenhou a imagem com uma paleta de cores de 16, selecionando **monocromático** faz com que as substituições de preto e branco para as cores da imagem. Contraste não seja sempre mantido: por exemplo, nas áreas adjacentes de vermelho e verde são ambos convertidas em preto.|
   |**Filename**|Especifica o nome do arquivo de imagem. Por padrão, o Visual Studio atribui um nome de arquivo base criada ao remover os primeiros quatro caracteres ("IDB_") o identificador de recurso padrão (IDB_BITMAP1) além de incluir a extensão apropriada. O nome de arquivo para a imagem neste exemplo seria `BITMAP1.bmp`. Você pode renomeá-la `MYBITMAP1.bmp`.|
   |**Altura**|Define a altura da imagem (em pixels). O valor padrão é 48. A imagem é cortada ou espaço em branco é adicionado abaixo da imagem existente.|
   |**ID**|Define o identificador do recurso. Para uma imagem, Microsoft Visual Studio, por padrão, atribui o próximo identificador disponível em uma série: IDB_BITMAP1, IDB_BITMAP2, e assim por diante. Nomes semelhantes são usados para ícones e cursores.|
   |**Paleta**|Alterações de propriedades de cor. Clique duas vezes para selecionar uma cor e exibir o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Defina a cor, digitando valores RGB ou HSL nas caixas de texto apropriado.|
   |**SaveCompressed**|Indica se a imagem está em um formato compactado. Esta propriedade é somente para leitura. Visual Studio não permite que você salve imagens em um formato compactado, portanto, para todas as imagens criadas no Visual Studio, essa propriedade serão **falsos**. Se você abrir uma imagem compactada (criada em outro programa) no Visual Studio, essa propriedade será **verdadeira**. Se você salvar uma imagem compactada usando o Visual Studio, ele será descompactado e essa propriedade será revertido para **falsos**.|
   |**Largura**|Define a largura da imagem (em pixels). O valor padrão para bitmaps é 48. A imagem é cortada ou espaço em branco é adicionado à direita da imagem existente.|

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)