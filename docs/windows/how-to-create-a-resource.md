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
ms.openlocfilehash: d269dbc83c11fa4ece55d8df8f6629d1afd52c03
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42594507"
---
# <a name="how-to-create-a-resource"></a>Como criar um recurso

> [!NOTE]
> **Exibição de recurso** não tem suporte nas edições Express.

### <a name="to-create-a-new-resource-in-resource-view"></a>Para criar um novo recurso no modo de exibição de recurso

1. Com foco em seu arquivo. rc no [exibição de recurso](../windows/resource-view-window.md), clique no **editar** menu e escolha **adicionar recurso** (ou clique com botão direito no arquivo. rc no **domododeexibiçãoderecursos** e escolha **adicionar recurso** no menu de atalho).

   > [!NOTE] 
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.

### <a name="to-create-a-new-resource-in-solution-explorer"></a>Para criar um novo recurso no Gerenciador de soluções

1. Na **Gerenciador de soluções**, clique na pasta do projeto e escolha **Add**, em seguida, clique em **adicionar recurso** no menu de atalho.

   Se você ainda não tiver um arquivo. rc em seu projeto, esta etapa criará um. Você pode, em seguida, repita essa etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.

2. No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.

### <a name="to-create-a-new-resource-in-class-view"></a>Para criar um novo recurso no modo de exibição de classe

1. Na [Class View](http://msdn.microsoft.com/8d7430a9-3e33-454c-a9e1-a85e3d2db925), sua classe com o botão direito e escolha **Add**, em seguida, clique em **adicionar recurso** no menu de atalho.

2. No [caixa de diálogo Adicionar recurso](../windows/add-resource-dialog-box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.

### <a name="to-create-a-new-resource-from-the-project-menu"></a>Para criar um novo recurso no menu projeto

1. Dos **Project** menu, escolha **adicionar recurso**.

Quando você cria um novo recurso, Visual C++ atribui um nome exclusivo a ele, por exemplo, `IDD_Dialog1`. Você pode personalizar essa ID de recurso, editando as propriedades para o recurso no editor de recursos associado ou nos [janela de propriedades](/visualstudio/ide/reference/properties-window).

Você pode criar um recurso como um novo recurso de padrão (um recurso que não se baseia em um modelo) ou como um recurso em conformidade com um [modelo](../windows/how-to-use-resource-templates.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)  
[Caixa de diálogo Adicionar Recurso](../windows/add-resource-dialog-box.md)