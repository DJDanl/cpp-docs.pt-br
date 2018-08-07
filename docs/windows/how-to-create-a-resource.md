---
title: 'Como: criar um recurso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- toolbars [C++], resources
- resource toolbars
- resources [Visual Studio], creating
ms.assetid: aad44914-9145-45a3-a7d8-9de89b366716
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ff08e42ac1afe3954b485e11ed6433449a6ee2ff
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571464"
---
# <a name="how-to-create-a-resource"></a>Como criar um recurso
> [!NOTE]
>  Não há suporte para a exibição de recurso nas edições Express.  
  
### <a name="to-create-a-new-resource-in-resource-view"></a>Para criar um novo recurso no modo de exibição de recurso  
  
1.  Com foco em seu arquivo. rc no [exibição de recurso](../windows/resource-view-window.md), clique no **editar** menu e escolha **adicionar recurso** (ou clique com botão direito no arquivo. rc no modo de exibição de recurso e escolha  **Adicionar recurso** no menu de atalho).  
  
     **Observação** se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-in-solution-explorer"></a>Para criar um novo recurso no Gerenciador de soluções  
  
1.  Na **Gerenciador de soluções**, clique na pasta do projeto e escolha **Add**, em seguida, clique em **adicionar recurso** no menu de atalho.  
  
     Se você ainda não tiver um arquivo. rc em seu projeto, esta etapa criará um. Você pode, em seguida, repita essa etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-in-class-view"></a>Para criar um novo recurso no modo de exibição de classe  
  
1.  Na [Class View](http://msdn.microsoft.com/8d7430a9-3e33-454c-a9e1-a85e3d2db925), sua classe com o botão direito e escolha **Add**, em seguida, clique em **adicionar recurso** no menu de atalho.  
  
2.  No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### <a name="to-create-a-new-resource-from-the-project-menu"></a>Para criar um novo recurso no menu projeto  
  
1.  Dos **Project** menu, escolha **adicionar recurso**.  
  
 Quando você cria um novo recurso, o Visual C++ atribui um nome exclusivo a ele, por exemplo, IDD_Dialog1. Você pode personalizar essa ID de recurso, editando as propriedades para o recurso no editor de recursos associado ou nos [janela de propriedades](/visualstudio/ide/reference/properties-window).  
  
 Você pode criar um recurso como um novo recurso de padrão (um recurso que não se baseia em um modelo) ou como um recurso em conformidade com um [modelo](../windows/how-to-use-resource-templates.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.*


## <a name="requirements"></a>Requisitos  
  
Win32  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)   
 [Caixa de diálogo Adicionar Recurso](../windows/add-resource-dialog-box.md)
