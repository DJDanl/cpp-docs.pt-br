---
title: Exibindo e Edificando recursos em um Editor de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vs.resourceview
dev_langs:
- C++
helpviewer_keywords:
- resources [Visual Studio], viewing
- rc files, viewing resources
- Resource View pane
- layouts, previewing resource
- code, viewing resources
- resource editors, viewing resources
- .rc files, viewing resources
- resources [Visual Studio], editing
ms.assetid: ba8bdc07-3f60-43c7-aa5c-d5dd11f0966e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 97816db8075d04b6d05950bb65c25aa12382b728
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39646924"
---
# <a name="viewing-and-editing-resources-in-a-resource-editor"></a>Exibindo e edificando recursos em um Editor de Recurso
Cada tipo de recurso tem um editor de recursos específico para esse tipo de recurso. Você pode reorganizar, redimensionar, adicionar controles e recursos ou caso contrário, modificar os aspectos de um recurso usando o editor associado. Você também pode editar um recurso no [formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md) e [formato binário](../windows/opening-a-resource-for-binary-editing.md).  
  
 Alguns tipos de recurso são arquivos individuais que podem ser importados e usados de várias maneiras; Isso inclui bitmaps, ícones, cursores, barras de ferramentas e arquivos html. Esses recursos têm nomes de arquivo, bem como [identificadores de recurso](../windows/symbols-resource-identifiers.md). Outros, como caixas de diálogo, menus e tabelas de cadeia de caracteres em projetos do Win32, existem apenas como parte de um arquivo de script (. rc) do recurso ou o arquivo de modelo (. rct) do recurso.  
  
> [!NOTE]
>  Propriedades de um recurso [podem ser modificadas usando a janela propriedades](../windows/changing-the-properties-of-a-resource.md).  
  
## <a name="win32-resources"></a>Recursos do Win32  
 Você pode acessar os recursos do Win32 na [exibição de recurso](../windows/resource-view-window.md) painel.  
  
### <a name="to-view-a-win32-resource-in-a-resource-editor"></a>Para exibir um recurso do Win32 em um editor de recursos  
  
1.  Selecione **exibição de recurso** da **exibição** menu.  
  
2.  Se a janela de exibição de recurso não for a janela principal, clique o **exibição de recurso** guia para colocá-lo na parte superior.  
  
3.  De modo de exibição de recursos, expanda a pasta do projeto que contém os recursos que você deseja exibir. Por exemplo, se você quiser exibir um recurso de caixa de diálogo, expanda a pasta de caixa de diálogo.  
  
    > [!NOTE]
    >  Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
4.  Clique duas vezes o recurso, por exemplo, IDD_ABOUTBOX.  
  
     O recurso é aberto no editor apropriado. Por exemplo, para recursos de caixa de diálogo, o recurso é aberto dentro do editor de caixa de diálogo.  
  
     Você também pode [exibir recursos em um arquivo. RC (script de recurso) sem a necessidade de abrir um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
### <a name="to-delete-an-existing-win-32-resource"></a>Para excluir um recurso existente do Win 32  
  
1.  Na **exibição de recurso**, expanda o nó para um tipo de recurso.  
  
2.  Clique com botão direito no recurso que você deseja excluir e escolha **excluir** no menu de atalho.  
  
    > [!NOTE]
    >  Você pode excluir um recurso usando o mesmo comando de menu de atalho quando você tem o arquivo. rc abrir em uma janela de documento fora de um projeto.  
  
## <a name="resources-in-managed-projects"></a>Recursos em projetos gerenciados  
 Porque os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="to-view-a-managed-resource-in-a-resource-editor"></a>Para exibir um recurso gerenciado em um editor de recursos  
  
1.  Na **Gerenciador de soluções**, clique duas vezes no recurso, por exemplo, Bitmap1.bmp.  
  
     O recurso é aberto no editor apropriado.  
  
### <a name="to-delete-an-existing-managed-resource"></a>Para excluir um recurso gerenciado existente  
  
1.  Na **Gerenciador de soluções**, com o recurso que deseja excluir e escolha o botão direito **excluir** no menu de atalho.  
  
### <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)