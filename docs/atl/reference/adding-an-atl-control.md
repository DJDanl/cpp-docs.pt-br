---
title: Adicionando um controle da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- ATL projects, adding controls
- controls [ATL], adding to projects
ms.assetid: 10223e7e-fdb7-4163-80c6-44aeafa8e6ce
ms.openlocfilehash: 836b19cef38549bcdf6cddeeda5bbb7fee08a1c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261358"
---
# <a name="adding-an-atl-control"></a>Adicionando um controle da ATL

Use este assistente para adicionar um objeto de interface do usuário a um projeto que oferece suporte a interfaces para todos os contêineres potenciais. Para dar suporte a essas interfaces, o projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo do MFC que contém suporte ATL. Use o [Assistente de Projeto ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

## <a name="to-add-an-atl-control-to-your-project"></a>Para adicionar um controle ATL ao seu projeto

1. Em ambos **Gerenciador de soluções** ou [exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique no nome do projeto ao qual você deseja adicionar objeto ATL simples.

1. Clique em **Add** do menu de atalho e clique **Adicionar classe**.

1. No [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel modelos, clique em **controle ATL**e, em seguida, clique em **Add** para exibir o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md).

Usando o **Assistente de controle ATL**, você pode criar um dos três tipos de controles:

- Um controle padrão

- Um controle de composição

- Um controle DHTML

Além disso, você pode reduzir o tamanho do controle e remover interfaces que não são usados pela maioria dos contêineres, selecionando **controle mínimo** sobre o **opções** página do assistente.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade ao controle de composição](../../atl/adding-functionality-to-the-composite-control.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)
