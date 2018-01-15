---
title: 'Como: criar um recurso | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- toolbars [C++], resources
- resource toolbars
- resources [Visual Studio], creating
ms.assetid: aad44914-9145-45a3-a7d8-9de89b366716
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dbf538940bab76559e7cec5a5737ab7661dac1f8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-create-a-resource"></a>Como criar um recurso
> [!NOTE]
>  Não há suporte para o modo de exibição de recursos em edições Express.  
  
### <a name="to-create-a-new-resource-in-resource-view"></a>Para criar um novo recurso no modo de exibição de recursos  
  
1.  Com foco em seu arquivo. rc [exibição recursos](../windows/resource-view-window.md), clique no **editar** menu e escolha **adicionar recurso** (ou clique no arquivo. rc no modo de exibição de recursos e escolha  **Adicionar recurso** no menu de atalho).  
  
     **Observação** se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-in-solution-explorer"></a>Para criar um novo recurso no Gerenciador de soluções  
  
1.  Em **Solution Explorer**, com o botão direito na pasta do projeto e escolha **adicionar**, em seguida, clique em **adicionar recurso** no menu de atalho.  
  
     Se você não tiver um arquivo. rc em seu projeto, esta etapa será criar um. Você pode repetir esta etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-in-class-view"></a>Para criar um novo recurso no modo de exibição de classe  
  
1.  Em [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com botão direito sua classe e escolha **adicionar**, em seguida, clique em **adicionar recurso** no menu de atalho.  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-from-the-project-menu"></a>Para criar um novo recurso no menu projeto  
  
1.  Do **projeto** menu, escolha **adicionar recurso**.  
  
 Quando você cria um novo recurso, o Visual C++ atribuirá um nome exclusivo a ele, por exemplo, IDD_Dialog1. Você pode personalizar essa ID de recurso, editando as propriedades para o recurso no editor de recursos associado ou no [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
 Você pode criar um recurso como um novo recurso de padrão (um recurso que não seja baseado em um modelo) ou como um recurso em conformidade com um [modelo](../windows/how-to-use-resource-templates.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.*  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)   
 [Caixa de diálogo Adicionar Recurso](../windows/add-resource-dialog-box.md)