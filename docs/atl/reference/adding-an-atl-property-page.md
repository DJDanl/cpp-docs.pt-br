---
title: Adicionando uma página de propriedades ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- property pages, adding
- ATL projects, adding property pages
- controls [ATL], property pages
ms.assetid: ddf92b49-42a2-46d2-b6b8-d37baedebeca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c84cdabddb96d2deeecd09f26101e37d9c99d0ce
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357060"
---
# <a name="adding-an-atl-property-page"></a>Adicionando uma página de propriedades ATL
Para adicionar uma página de propriedades ATL Active Template Library () ao seu projeto, o projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo MFC que contém suporte ATL. Você pode usar o [Assistente de projeto de ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [adicionar um objeto ATL ao seu aplicativo do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo do MFC.  
  
 Se você estiver adicionando uma página de propriedades para um controle, o controle deve oferecer suporte a [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) interface. Por padrão, essa interface é na lista de derivação de seu controle quando você [criar um controle ATL](../../atl/reference/adding-an-atl-control.md) usando o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md).  
  
> [!NOTE]
>  Se sua classe de controle não tem [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) em sua lista de derivação, você deve adicioná-la manualmente.  
  
### <a name="to-add-an-atl-property-page-to-your-project"></a>Para adicionar uma página de propriedades ATL ao seu projeto  
  
1.  No **Solution Explorer** ou [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto ao qual você deseja adicionar a página de propriedades ATL.  
  
2.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
3.  No [Adicionar classe](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel modelos, clique em **página de propriedades ATL** e, em seguida, clique em **abrir** para exibir o [Assistente de página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md).  
  
 Depois de criar uma página de propriedades para um controle, você deve fornecer o [PROP_PAGE](property-map-macros.md#prop_page) entrada no mapa de propriedade para o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../../atl/atl-com-property-pages.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)

