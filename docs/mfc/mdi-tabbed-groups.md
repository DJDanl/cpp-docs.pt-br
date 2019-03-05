---
title: Grupos com guias MDI
ms.date: 11/04/2016
helpviewer_keywords:
- mdi [MFC], tabbed groups
- tabbed grous [MFC]
ms.assetid: 0a464f36-39b7-4e68-8b67-ec175de28377
ms.openlocfilehash: 6b68d1bc06a6827ca94b05fa2760206f424d40fe
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57289514"
---
# <a name="mdi-tabbed-groups"></a>Grupos com guias MDI

O recurso de grupos com guias vários documentos (interface MDI) permite que vários aplicativos MDI (interface MDI) de documento exibir um ou mais janelas com guias (ou grupos de janelas com guias, conhecidos como *grupos com guias*) na área de cliente do MDI. As janelas com guias podem ser alinhadas vertical ou horizontalmente. Se um aplicativo hospeda mais de um grupo MDI com guias, os grupos são separados por divisores.

## <a name="features"></a>Recursos

A seguir está os recursos do MDI tabbed groups:

- Um aplicativo pode criar janelas com guias dinamicamente.

- Um aplicativo pode alinhar janelas com guias horizontal ou verticalmente.

- Grupos de janelas com guias são separados por divisores. O usuário pode redimensionar a grupos com guias usando o divisor.

- O usuário pode arrastar guias individuais entre grupos.

- O usuário pode arrastar guias individuais para criar novos grupos.

- O usuário pode mover guias ou criar novos grupos por meio de um menu de atalho.

- Um aplicativo pode salvar e carregar o layout de janelas com guias.

- Um aplicativo pode salvar e carregar a lista de documentos MDI.

- Um aplicativo pode acessar os grupos com guias individuais e modificar seus parâmetros.

### <a name="using-mdi-tabbed-groups"></a>Grupos usar MDI com guias

A seguir estão as tarefas normalmente executadas com grupos de MDI com guias:

- Para habilitar grupos MDI com guias para uma janela de quadro principal, chame [CMDIFrameWndEx::EnableMDITabbedGroups](../mfc/reference/cmdiframewndex-class.md#enablemditabbedgroups). O segundo parâmetro desse método é uma instância da `CMDITabInfo` classe. Você pode usar os parâmetros padrão ou modificá-las antes de chamar `CMDIFrameWndEx::EnableMDITabbedGroups`.

- Para modificar as propriedades de um grupo MDI com guias em tempo de execução, criar ou modificar uma `CMDITabInfo` objeto e chame `CMDIFrameWndEx::EnableMDITabbedGroups` novamente

- Para obter uma lista de MDI janelas com guias, chame `CMDIFrameWndEx::GetMDITabGroups`.

- Para criar um novo grupo com guias MDI ao lado de um grupo com guias Active Directory, chame `CMDIFrameWndEx::MDITabNewGroup`.

- Para deslocar o foco de entrada para a janela anterior ou próxima de um grupo com guias, chame `CMDIFrameWndEx::MDITabMoveToNextGroup`.

- Para determinar se uma janela é um membro de um MDI com guias chamada grupo `CMDIFrameWndEx::IsMemberOfMDITabGroup`.

- Para determinar se as guias MDI ou MDI tabbed groups estão habilitados para uma janela de quadro principal, chame `CMDIFrameWndEx::AreMDITabs`. Para determinar somente se os grupos MDI com guias são habilitados, chame `CMDIFrameWndEx::IsMDITabbedGroup`.

- Para exibir um menu de atalho quando o usuário clica em uma guia ou arrasta-o para outro grupo MDI com guias, substitua `CMDIFrameWndEx::OnShowMDITabContextMenu` no `CMDIFrameWndEx`-classe derivada. Se você não implementar esse método, o aplicativo não exibirá o menu de atalho.

- Para salvar o layout do MDI tabbed groups em um aplicativo, chame `CMDIFrameWndEx::SaveMDIState`. Para carregar um salva anteriormente MDI com guias perfil de grupo, chame `CMDIFrameWndEx::LoadMDIState`. Você também pode chamar esses métodos para carregar ou salvar a lista de documentos abertos em um aplicativo MDI. Para obter mais informações sobre como salvar e carregar o estado MDI, consulte [CMDIFrameWndEx::LoadMDIState](../mfc/reference/cmdiframewndex-class.md#loadmdistate).

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Classe CMDIFrameWndEx](../mfc/reference/cmdiframewndex-class.md)<br/>
[Classe CMDIChildWndEx](../mfc/reference/cmdichildwndex-class.md)<br/>
[Classe CMDITabInfo](../mfc/reference/cmditabinfo-class.md)
