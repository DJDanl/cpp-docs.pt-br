---
title: Adicionando um controle da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- ATL projects, adding controls
- controls [ATL], adding to projects
ms.assetid: 10223e7e-fdb7-4163-80c6-44aeafa8e6ce
ms.openlocfilehash: fac1efeb3d373a8324828a8b10f0570f253f6103
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499293"
---
# <a name="adding-an-atl-control"></a>Adicionando um controle da ATL

Use este assistente para adicionar um objeto de interface do usuário a um projeto que dá suporte a interfaces para todos os contêineres em potencial. Para dar suporte a essas interfaces, o projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo MFC que contenha suporte para ATL. Você pode usar o [Assistente de projeto do ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo MFC.

## <a name="to-add-an-atl-control-to-your-project"></a>Para adicionar um controle ATL ao seu projeto

1. Em qualquer **Gerenciador de soluções** ou [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar o objeto simples do ATL.

1. Clique em **Adicionar** no menu de atalho e, em seguida, clique em **Adicionar classe**.

1. Na caixa de diálogo [Adicionar classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box) , no painel modelos, clique em **controle ATL**e, em seguida, clique em **Adicionar** para exibir o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md).

Usando o **Assistente de controle ATL**, você pode criar um dos três tipos de controles:

- Um controle padrão

- Um controle composto

- Um controle DHTML

Além disso, você pode reduzir o tamanho do controle e remover interfaces que não são usadas pela maioria dos contêineres selecionando **controle mínimo** na página **Opções** do assistente.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade ao controle composto](../../atl/adding-functionality-to-the-composite-control.md)<br/>
[Conceitos básicos de objetos COM ATL](../../atl/fundamentals-of-atl-com-objects.md)
