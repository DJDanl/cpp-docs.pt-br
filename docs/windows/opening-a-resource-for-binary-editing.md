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
ms.openlocfilehash: c09cd825a5974422eaf757419f4ce890f5123100
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="opening-a-resource-for-binary-editing"></a>Abrindo um recurso para edição binária
### <a name="to-open-a-windows-desktop-resource-for-binary-editing"></a>Para abrir um recurso de área de trabalho do Windows para edição binária  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), selecione o arquivo de recurso específico que você deseja editar.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  O recurso de atalho e clique em **abrir dados binários** no menu de atalho.  
  
    > [!NOTE]
    >  Se você usar o [exibição recursos](../windows/resource-view-window.md) janela a abrir um recurso com um formato que o Visual Studio não reconhece (como RCDATA ou um recurso personalizado), o recurso é aberta automaticamente no editor binário.  
  
### <a name="to-open-a-managed-resource-for-binary-editing"></a>Para abrir um recurso gerenciado para edição binária  
  
1.  No Solution Explorer, selecione o arquivo de recurso específico que você deseja editar.  
  
2.  O recurso de atalho e escolha **abrir com** no menu de atalho.  
  
3.  No **abrir com** caixa de diálogo caixa, escolha **Editor binário**.  
  
    > [!NOTE]
    >  Você pode usar o [editor de imagem](../windows/image-editor-for-icons.md) e [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.  
  
    > [!NOTE]
    >  Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).   
  
 ![Editor binário](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")  
Dados binários de uma caixa de diálogo exibida no Editor binário  
  
 Somente determinados valores ASCII são representados no editor binário (0x20 por meio de 0x7E). Caracteres estendidos são exibidos como períodos na seção de valor ASCII de editor binário (painel direito). Os caracteres "imprimíveis" são valores ASCII de 32 a 126.  
  
> [!NOTE]
>  Se você quiser usar o editor binário em um recurso já está sendo editado em outra janela do editor, feche a janela do editor primeiro.  
  
 **Requisitos**  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Editor binário](binary-editor.md)

