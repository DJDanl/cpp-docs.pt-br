---
title: Criando regiões transparentes ou inversas em imagens de dispositivo (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- cursors [C++], screen regions
- inverse colors [C++], device images
- transparent regions, device images
- transparency, device images
- Image editor [C++], device images
- inverse regions, device images
- cursors [C++], transparent regions
- screen colors
- regions, transparent
- icons [C++], transparent regions
- display devices [C++], transparent and screen regions
- transparent regions in devices
- regions, inverse
- colors [C++], Image editor
- device projects [C++], transparent images
- icons [C++], screen regions
ms.assetid: a994954b-b039-4391-a535-58d1fa10fc3b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ab57df8151d02064b244212f28fe21628f0f3bb8
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44314840"
---
# <a name="creating-transparent-or-inverse-regions-in-device-images-image-editor-for-icons"></a>Criando regiões transparentes ou inversas em imagens de dispositivo (editor de imagens para ícones)

No [editor de imagens](../windows/image-editor-for-icons.md), a imagem de ícone ou cursor inicial tem um atributo transparente. Embora as imagens de ícone e cursor são retangulares, muitos não aparecem isso porque partes da imagem são transparentes; mostra a imagem subjacente na tela por meio do ícone ou cursor. Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida. Criar esse efeito, definindo a cor da tela e as cores invertidas na [janela de cores](../windows/colors-window-image-editor-for-icons.md).

As cores da tela e o inverso é aplicar a ícones e cursores da forma e a imagem derivada de cor ou designarem Inverter regiões. As cores indicam partes da imagem que possui os atributos. Você pode alterar as cores que representam os atributos de cor da tela e cor inverso no modo de edição. Essas alterações não afetam a aparência do ícone ou cursor em seu aplicativo.

> [!NOTE]
> As caixas de diálogo e os comandos de menu vistos podem ser diferentes daqueles descritos na **Ajuda**, dependendo da edição ou das configurações ativas. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

### <a name="to-create-transparent-or-inverse-regions"></a>Para criar regiões transparentes ou inversas

1. No **cores** janela, clique no **cor da tela** seletor ou o **inverso cor** seletor.

2. Aplique a tela ou cores invertidas em sua imagem usando uma ferramenta de desenho. Para obter mais informações sobre ferramentas de desenho, consulte [usando uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md).

### <a name="to-change-the-screen-or-inverse-color"></a>Para alterar a cor da tela ou inverso

1. Selecione o **cores da tela** seletor ou o **inverso cor** seletor.

2. Escolha uma cor na **cores** paleta na **cores** janela.

   A cor complementar é automaticamente designada para o seletor de outro.

   > [!TIP]
   > Se você clicar duas vezes o **cores da tela** ou **inverso cor** seletor, o [caixa de diálogo do seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) é exibida.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)  
[Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)