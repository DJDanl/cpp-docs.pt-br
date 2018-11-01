---
title: Abrindo um recurso para edição binária (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.binary
helpviewer_keywords:
- binary data, editing
- resources [C++], opening for binary editing
ms.assetid: d3cdb0e4-da66-410d-8e49-b29073ff2929
ms.openlocfilehash: cc66c9d06a8549984e9347af776c56883f8e22f2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491176"
---
# <a name="opening-a-resource-for-binary-editing-c"></a>Abrindo um recurso para edição binária (C++)

### <a name="to-open-a-windows-desktop-resource-for-binary-editing"></a>Para abrir um recurso de área de trabalho do Windows para edição binária

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o arquivo de recurso específico que você deseja editar.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. O recurso com o botão direito e clique em **abrir dados binários** no menu de atalho.

   > [!NOTE]
   > Se você usar o [exibição de recurso](../windows/resource-view-window.md) janela para abrir um recurso com um formato que o Visual Studio não reconhece (como RCDATA ou um recurso personalizado), o recurso é aberta automaticamente na **binário** editor.

### <a name="to-open-a-managed-resource-for-binary-editing"></a>Para abrir um recurso gerenciado para edição binária

1. Na **Gerenciador de soluções**, selecione o arquivo de recurso específico que você deseja editar.

2. O recurso de atalho e escolha **abrir com** no menu de atalho.

3. No **abrir com** diálogo caixa, escolha **Editor binário**.

   > [!NOTE]
   > Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

   > [!NOTE]
   > Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

![Editor binário](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")<br/>
Dados binários para uma caixa de diálogo exibida no Editor binário

Apenas determinados valores ASCII são representados no editor binário (0x20 por meio de 0x7E). Caracteres estendidos são exibidos como pontos na seção de valor ASCII do editor binário (painel direito). Os caracteres "imprimíveis" são valores ASCII 32 a 126.

> [!NOTE]
> Se você quiser usar o **binário** editor em um recurso já está sendo editado em outra janela do editor, feche a janela do editor primeiro.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor binário](binary-editor.md)