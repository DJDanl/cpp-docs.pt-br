---
title: Adicionando um objeto simples da ATL
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.classes.adding.atl
helpviewer_keywords:
- ATL projects, adding objects
- objects [ATL]
- ATL, simple objects
ms.assetid: 9c57d2ef-0447-4c84-8982-3304b8e49847
ms.openlocfilehash: 85c19c483ff27bd34431ec163e3baadac1855236
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499348"
---
# <a name="adding-an-atl-simple-object"></a>Adicionando um objeto simples da ATL

Para adicionar um objeto ATL (Active Template Library) ao seu projeto, seu projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo MFC que contenha suporte ATL. Você pode usar o [Assistente de projeto do ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo MFC.

Você pode definir interfaces COM para o novo objeto ATL ao criá-lo pela primeira vez ou adicioná-los mais tarde usando o comando [implementar interface](../../ide/implementing-an-interface-visual-cpp.md#implement-interface-wizard) no menu de atalho **modo de exibição de classe** .

## <a name="to-add-an-atl-simple-object-to-your-atl-com-project"></a>Para adicionar um objeto simples ATL ao seu projeto COM ATL

1. Em qualquer **Gerenciador de soluções** ou [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar o objeto simples do ATL.

1. No menu de atalho, clique em **Adicionar**e em **Adicionar classe**.

1. Na caixa de diálogo [Adicionar classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box) , no painel **modelos** , clique em **objeto ATL simples**e, em seguida, clique em **abrir** para exibir o [Assistente de objeto simples do ATL](../../atl/reference/atl-simple-object-wizard.md).

1. Defina opções adicionais para seu projeto na página [Opções](../../atl/reference/options-atl-simple-object-wizard.md) do assistente de **objeto simples do ATL** .

1. Clique em **concluir** para adicionar o objeto ao seu projeto.

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma nova Interface em um projeto da ATL](../../atl/reference/adding-a-new-interface-in-an-atl-project.md)<br/>
[Adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md)<br/>
[Adicionando um método](../../ide/adding-a-method-visual-cpp.md)<br/>
[Classe MFC](../../mfc/reference/adding-an-mfc-class.md)<br/>
[Adicionando uma classe do C++ genérica](../../ide/adding-a-generic-cpp-class.md)
