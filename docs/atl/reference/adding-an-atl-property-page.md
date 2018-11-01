---
title: Adicionando uma página de propriedades ATL
ms.date: 11/04/2016
helpviewer_keywords:
- property pages, adding
- ATL projects, adding property pages
- controls [ATL], property pages
ms.assetid: ddf92b49-42a2-46d2-b6b8-d37baedebeca
ms.openlocfilehash: ed715cd822aaf0f55b8898efc80b5514938ca8ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668059"
---
# <a name="adding-an-atl-property-page"></a>Adicionando uma página de propriedades ATL

Para adicionar uma página de propriedade da biblioteca ATL (Active Template) ao seu projeto, seu projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo do MFC que contém suporte ATL. Você pode usar o [ATL Project Wizard](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [adicionar um objeto ATL ao seu aplicativo do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo do MFC.

Se você estiver adicionando uma página de propriedades para um controle, seu controle deve oferecer suporte a [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) interface. Por padrão, essa interface é na lista de derivação de seu controle quando você [criar um controle ATL](../../atl/reference/adding-an-atl-control.md) usando o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md).

> [!NOTE]
> Se sua classe de controle não tem [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) em sua lista de derivação, você deve adicioná-lo manualmente.

## <a name="to-add-an-atl-property-page-to-your-project"></a>Para adicionar uma página de propriedades ATL ao seu projeto

1. Em ambos **Gerenciador de soluções** ou [exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique no nome do projeto ao qual você deseja adicionar a página de propriedades ATL.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar classe**.

1. No [Add Class](../../ide/add-class-dialog-box.md) na caixa a **modelos** painel, clique em **página de propriedades ATL** e, em seguida, clique em **abrir** para exibir o [Assistente de página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md).

Depois de criar uma página de propriedades para um controle, você deve fornecer o [PROP_PAGE](property-map-macros.md#prop_page) entrada no mapa de propriedade para o controle.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../../atl/atl-com-property-pages.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)
