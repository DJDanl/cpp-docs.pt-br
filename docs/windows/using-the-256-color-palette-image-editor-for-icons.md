---
title: Usando a paleta de 256 cores (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- 256-color palette
- colors [C++], icons and cursors
- cursors [C++], color
- color palettes, 256-color
- palettes, 256-color
- icons, color
ms.assetid: 1506ed00-669b-4a21-b1a4-39b6a84a78bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d9a8952ccdf4477f263a2fb960020e7abba19546
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46418145"
---
# <a name="using-the-256-color-palette-image-editor-for-icons"></a>Usando a paleta de 256 cores (editor de imagens para ícones)

Para desenhar com uma seleção da paleta de 256 cores, você precisará selecionar as cores do **cores** paleta na [janela cores](../windows/colors-window-image-editor-for-icons.md).

### <a name="to-choose-a-color-from-the-256-color-palette-for-large-icons"></a>Para escolher uma cor da paleta de 256 cores de ícones grandes

1. Selecione o ícone grande ou cursor ou criar um novo ícone grande ou cursor.

2. Escolha uma cor de 256 cores exibidas nos **cores** paleta na **cores** janela.

   A cor selecionada se tornará a cor atual na **cores** paleta na **cores** janela.

   > [!NOTE]
   > A paleta inicial usada para imagens de 256 cores corresponde a paleta retornada pelo `CreateHalftonePalette` API do Windows. Todos os ícones destinados para o shell do Windows devem usar essa paleta para evitar a cintilação durante a realização da paleta.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Criando um ícone de 256 cores ou um Cursor](creating-a-256-color-icon-or-cursor-image-editor-for-icons.md)<br/>
[Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)