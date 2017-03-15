---
title: "Adicionando uma página de propriedades ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- property pages, adding
- ATL projects, adding property pages
- controls [ATL], property pages
ms.assetid: ddf92b49-42a2-46d2-b6b8-d37baedebeca
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: 7b6a6220a33890d99e6fb2bd81ce832b38720c50
ms.lasthandoff: 02/25/2017

---
# <a name="adding-an-atl-property-page"></a>Adicionando uma página de propriedades ATL
Para adicionar uma página de propriedade da biblioteca ATL (Active Template) ao seu projeto, o projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo do MFC que contém suporte ATL. Você pode usar o [ATL Project Wizard](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [adicionar um objeto ATL ao seu aplicativo do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte do ATL para um aplicativo MFC.  
  
 Se você estiver adicionando uma página de propriedades para um controle, seu controle deve oferecer suporte a [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) interface. Por padrão, essa interface é na lista de derivação de seu controle quando você [criar um controle ATL](../../atl/reference/adding-an-atl-control.md) usando o [Assistente de controle ATL](../../atl/reference/atl-control-wizard.md).  
  
> [!NOTE]
>  Se sua classe de controle não tem [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) em sua lista de derivação, você deve adicioná-lo manualmente.  
  
### <a name="to-add-an-atl-property-page-to-your-project"></a>Para adicionar uma página de propriedades ATL ao seu projeto  
  
1.  No **Solution Explorer** ou [Class View](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto para o qual você deseja adicionar a página de propriedades ATL.  
  
2.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
3.  No [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel de modelos, clique em **página de propriedades ATL** e, em seguida, clique em **abrir** para exibir o [Assistente de página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md).  
  
 Depois de criar uma página de propriedades para um controle, você deve fornecer o [PROP_PAGE](http://msdn.microsoft.com/library/2155973e-b96c-4385-bf85-5d6112c969b8) entrada no mapa de propriedade para o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../../atl/atl-com-property-pages.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Exemplo: Implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)


