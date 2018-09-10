---
title: Trabalhando com cor (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.image.color
dev_langs:
- C++
helpviewer_keywords:
- images [C++], background colors
- Image editor [C++], Colors Palette
- colors [C++], image
- Colors Palette, Image editor
- palettes, Image editor colors
- foreground colors [C++], Image editor
- colors [C++]
ms.assetid: d34ff96f-241d-494f-abdd-13811ada8cd3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 200c71b6d2196251c8db3542b2b1b2ce88fdff85
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315529"
---
# <a name="working-with-color-image-editor-for-icons"></a>Trabalhando com cor (editor de imagens para ícones)

O **Editor de imagens** contém muitos recursos que especificamente a lidar com e personalizar as cores. Você pode definir uma cor de primeiro plano ou segundo plano, preencher as áreas limitadas com cor ou selecione uma cor em uma imagem para usar como a cor de primeiro plano ou segundo plano atual. Você pode usar ferramentas o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) junto com a paleta de cores na [janela cores](../windows/colors-window-image-editor-for-icons.md) para criar imagens.

Todas as cores para imagens de 16 cores e monocromático são mostradas na **cores** paleta na **cores** janela. Além de 16 cores padrão, você pode criar suas próprias cores personalizadas. Alteração de qualquer uma das cores na paleta de alterar imediatamente a cor correspondente na imagem.

Ao trabalhar com o ícone de 256 cores e imagens de cursor, o **cores** propriedade no [janela propriedades](/visualstudio/ide/reference/properties-window) é usado. Para obter mais informações, consulte [criando um ícone de 256 cores ou cursor](creating-a-256-color-icon-or-cursor-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

True color imagens também podem ser criadas. No entanto, amostras de cores true não aparecem na paleta completa na **cores** janela; eles aparecem somente na área de indicador de cor do primeiro plano ou segundo plano. Cores True são criadas usando o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Para obter mais informações, consulte [personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md).

Você pode salvar paletas de cores personalizada no disco e recarregá-los conforme necessário. A paleta de cores usado mais recentemente é salva no registro e carregada automaticamente na próxima vez que iniciar o Visual Studio.

- [Selecionando cores de plano de fundo ou primeiro plano](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md)

- [Preenchendo uma área limitada de uma imagem com uma cor](../windows/filling-a-bounded-area-of-an-image-with-a-color-image-editor-for-icons.md)

- [Escolhendo uma cor na imagem para uso em outro lugar](../windows/picking-up-a-color-from-an-image-to-use-elsewhere-image-editor-for-icons.md)

- [Escolher um plano de fundo transparente ou opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md)

- [Invertendo as cores em uma seleção](../windows/inverting-the-colors-in-a-selection-image-editor-for-icons.md)

- [Personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md)

- [Salvando e carregando paletas de cores diferentes](../windows/saving-and-loading-different-color-palettes-image-editor-for-icons.md)

- [Janela cores](../windows/colors-window-image-editor-for-icons.md)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)  