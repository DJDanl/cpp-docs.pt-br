---
title: Adição de uma página de propriedades da ATL
ms.date: 05/09/2019
helpviewer_keywords:
- property pages, adding
- ATL projects, adding property pages
- controls [ATL], property pages
ms.assetid: ddf92b49-42a2-46d2-b6b8-d37baedebeca
ms.openlocfilehash: 4cd7444d18d26124f8c3c642bba55fb7592f5c8b
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499313"
---
# <a name="adding-an-atl-property-page"></a>Adição de uma página de propriedades da ATL

> [!NOTE]
> O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

Para adicionar uma página de propriedades ATL (Active Template Library) ao seu projeto, ele deve ter sido criado como um aplicativo ATL ou como um aplicativo MFC compatível com ATL. Use o [Assistente de Projeto ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [adicione um objeto ATL ao aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

Se estiver adicionando uma página de propriedades para um controle, este deverá ser compatível com a interface [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md). Por padrão, essa interface está na lista de derivação da sua classe de controle quando você [cria um controle de ATL](../../atl/reference/adding-an-atl-control.md) usando o [Assistente de Controle de ATL](../../atl/reference/atl-control-wizard.md).

> [!NOTE]
> Se sua classe de controle não tiver [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) na própria lista de derivação, você deverá adicioná-la manualmente.

## <a name="to-add-an-atl-property-page-to-your-project"></a>Adição de uma página de propriedades da ATL ao seu projeto

1. No **Gerenciador de Soluções** ou no [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual deseja adicionar a página de propriedades da ATL.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

1. Na caixa de diálogo [Adicionar Classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box), no painel **Modelos**, clique em **Página de Propriedades da ATL** e em **Abrir** para exibir o [Assistente da Página de Propriedades da ATL](../../atl/reference/atl-property-page-wizard.md).

Depois de criar uma página de propriedades para um controle, você deve fornecer a entrada [PROP_PAGE](property-map-macros.md#prop_page) no mapa de propriedades do controle.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../../atl/atl-com-property-pages.md)<br/>
[Conceitos básicos de objetos COM ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)
