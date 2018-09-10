---
title: Editores de recursos (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vs.editors.resource
- vc.resvw.resource.editors
- vs.resvw.resource.editors
dev_langs:
- C++
helpviewer_keywords:
- editors [C++], resource
- editors [C++]
- resource editors
- Windows [C++], application resource editing
ms.assetid: e20a29ec-d6fb-4ead-98f3-431a0e23aaaf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a4dab1ce421582d865895fcec0d55685bdbf30db
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315217"
---
# <a name="resource-editors"></a>Editores de recursos

Um **recurso** editor é um ambiente especializado para criar ou modificar os recursos que estão incluídos em um projeto do Visual Studio. Os editores de recursos do Visual Studio compartilham técnicas e interfaces para ajudá-lo a criar e modificar recursos do aplicativo de forma rápida e fácil. Editores de recursos permitem que você [exibir e editar os recursos no editor apropriado](../windows/viewing-and-editing-resources-in-a-resource-editor.md) e [visualizar recursos](../windows/previewing-resources.md).

O editor apropriado é aberto automaticamente quando você criar ou abrir um recurso.

**Observação** porque os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

|Use o...|Para editar...|
|----------------|----------------|
|[Editor de aceleradores](../windows/accelerator-editor.md)|Tabelas de aceleradores em projetos do Visual C++.|
|[Editor binário](binary-editor.md)|Informações de dados binários e recursos personalizados em projetos do Visual C++, Visual Basic ou Visual c#.|
|[Editor de caixa de diálogo](../windows/dialog-editor.md)|Caixas de diálogo em projetos do Visual C++.|
|[Editor de Imagens](../windows/image-editor-for-icons.md)|Bitmaps, ícones, cursores e outros arquivos de imagem em projetos do Visual C++, Visual Basic ou Visual c#.|
|[Editor de Menu](../windows/menu-editor.md)|Recursos de menu em projetos do Visual C++.|
|[Editor da faixa de opções](../mfc/ribbon-designer-mfc.md)|Recursos de faixa de opções em projetos MFC.|
|[Editor de cadeias de caracteres](../windows/string-editor.md)|Tabelas em projetos do Visual C++ de cadeia de caracteres.|
|[Editor de barra de ferramentas](../windows/toolbar-editor.md)|Recursos da barra de ferramentas em projetos do Visual C++. O editor de barra de ferramentas é parte do editor de imagens.|
|[Editor de informações de versão](../windows/version-information-editor.md)|Informações de versão em projetos do Visual C++.|

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)  
[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)  
[Menus e outros recursos](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)