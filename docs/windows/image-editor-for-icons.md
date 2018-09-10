---
title: Editor de imagens para ícones | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.cursor.F1
- vc.editors.icon.F1
- vc.editors.cursor
- vc.editors.bitmap.F1
dev_langs:
- C++
helpviewer_keywords:
- editors, images
- resource editors [C++], graphics
- Image editor [C++]
- resource editors [C++], Image editor
ms.assetid: 586d2b8b-0348-4883-a85d-1ff0ddbf14dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8d160a042263f783b88c7ff2d9dfd03c46759079
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44318805"
---
# <a name="image-editor-for-icons"></a>Editor de imagens para ícones

O Editor de Imagens possui um extenso conjunto de ferramentas para criar e editar imagens, bem como recursos para ajudar a criar bitmaps de barra de ferramentas. Além de bitmaps, ícones e cursores, você pode editar imagens no formato GIF ou JPEG usando os comandos a **imagem** menu e as ferramentas a **Editor de imagens** barra de ferramentas.

Com o Editor de Imagens, é possível:

- [Editar recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)

- [Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)

- [Trabalhar com ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)

- [Usar teclas aceleradoras para comandos do Editor de imagens](../windows/accelerator-keys-image-editor-for-icons.md)

O **Editor de imagens** janela mostra dois modos de exibição de uma imagem, com uma barra de divisão que separa os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção.

O **Editor de imagens** janela pode ser ajustada para atender às suas necessidades e preferências. Você pode [alterar o fator de ampliação](../windows/changing-the-magnification-factor-image-editor-for-icons.md) e [exibir ou ocultar a grade de pixels](../windows/displaying-or-hiding-the-pixel-grid-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

## <a name="visual-studio-image-library"></a>Biblioteca de Imagens do Visual Studio

Você pode fazer o download sem nenhum custo a **biblioteca de imagens do Visual Studio** que contém várias animações, bitmaps e ícones que você pode usar em seus aplicativos. Para obter mais informações sobre como baixar a biblioteca, consulte [a biblioteca de imagens do Visual Studio](/visualstudio/designers/the-visual-studio-image-library).

## <a name="managed-resources"></a>Recursos gerenciados

Você pode usar o **imagem** editor e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)  
[Ícones](https://msdn.microsoft.com/library/windows/desktop/ms646973.aspx)