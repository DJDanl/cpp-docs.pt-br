---
title: Abrindo um recurso para edição binária | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.binary
dev_langs:
- C++
helpviewer_keywords:
- binary data, editing
- resources [Visual Studio], opening for binary editing
ms.assetid: d3cdb0e4-da66-410d-8e49-b29073ff2929
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4ad125c2931049fe912724b1391c8470f6cb4495
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589271"
---
# <a name="opening-a-resource-for-binary-editing"></a>Abrindo um recurso para edição binária

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

![Editor binário](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")  
Dados binários para uma caixa de diálogo exibida no Editor binário

Apenas determinados valores ASCII são representados no editor binário (0x20 por meio de 0x7E). Caracteres estendidos são exibidos como pontos na seção de valor ASCII do editor binário (painel direito). Os caracteres "imprimíveis" são valores ASCII 32 a 126.

> [!NOTE]
> Se você quiser usar o **binário** editor em um recurso já está sendo editado em outra janela do editor, feche a janela do editor primeiro.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor binário](binary-editor.md)