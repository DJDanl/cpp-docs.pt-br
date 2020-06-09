---
title: Grupos com guias MDI
ms.date: 11/04/2016
helpviewer_keywords:
- mdi [MFC], tabbed groups
- tabbed grous [MFC]
ms.assetid: 0a464f36-39b7-4e68-8b67-ec175de28377
ms.openlocfilehash: 0c1bf925003d5081b2cdc837012a57585b1ace60
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624356"
---
# <a name="mdi-tabbed-groups"></a>Grupos com guias MDI

O recurso de grupos com guias de interface de vários documentos (MDI) permite que os aplicativos de interface de vários documentos (MDI) exibam uma ou mais janelas com guias (ou grupos de janelas com guias, conhecidas como *grupos com guias*) na área do cliente MDI. As janelas com guias podem ser alinhadas vertical ou horizontalmente. Se um aplicativo hospedar mais de um grupo com guias MDI, os grupos serão separados por divisores.

## <a name="features"></a>Recursos

Estes são os recursos de grupos com guias MDI:

- Um aplicativo pode criar janelas com guias dinamicamente.

- Um aplicativo pode alinhar janelas com guias horizontal ou verticalmente.

- Grupos de janelas com guias são separados por divisores. O usuário pode redimensionar grupos com guias usando o divisor.

- O usuário pode arrastar guias individuais entre grupos.

- O usuário pode arrastar guias individuais para criar novos grupos.

- O usuário pode mover guias ou criar novos grupos usando um menu de atalho.

- Um aplicativo pode salvar e carregar o layout de janelas com guias.

- Um aplicativo pode salvar e carregar a lista de documentos MDI.

- Um aplicativo pode acessar grupos com guias individuais e modificar seus parâmetros.

### <a name="using-mdi-tabbed-groups"></a>Usando grupos com guias MDI

Veja a seguir as tarefas normalmente executadas com grupos com guias MDI:

- Para habilitar os grupos com guias MDI para uma janela de quadro principal, chame [CMDIFrameWndEx:: EnableMDITabbedGroups](reference/cmdiframewndex-class.md#enablemditabbedgroups). O segundo parâmetro desse método é uma instância da `CMDITabInfo` classe. Você pode usar os parâmetros padrão ou modificá-los antes de chamar `CMDIFrameWndEx::EnableMDITabbedGroups` .

- Para modificar as propriedades de um grupo com guias MDI em tempo de execução, crie ou modifique um `CMDITabInfo` objeto e chame `CMDIFrameWndEx::EnableMDITabbedGroups` novamente

- Para obter uma lista de janelas com guias MDI, chame `CMDIFrameWndEx::GetMDITabGroups` .

- Para criar um novo grupo com guias MDI ao lado de um grupo com guias ativo, chame `CMDIFrameWndEx::MDITabNewGroup` .

- Para deslocar o foco de entrada para a janela anterior ou próxima de um grupo com guias, chame `CMDIFrameWndEx::MDITabMoveToNextGroup` .

- Para determinar se uma janela é membro de uma chamada de grupo com guias MDI `CMDIFrameWndEx::IsMemberOfMDITabGroup` .

- Para determinar se as guias MDI ou os grupos com guias MDI estão habilitados para uma janela de quadro principal, chame `CMDIFrameWndEx::AreMDITabs` . Para determinar apenas se os grupos com guias MDI estão habilitados, chame `CMDIFrameWndEx::IsMDITabbedGroup` .

- Para exibir um menu de atalho quando o usuário clicar em uma guia ou arrastá-lo para outro grupo com guias MDI, substitua `CMDIFrameWndEx::OnShowMDITabContextMenu` na `CMDIFrameWndEx` classe derivada. Se você não implementar esse método, o aplicativo não exibirá o menu de atalho.

- Para salvar o layout de grupos com guias MDI em um aplicativo, chame `CMDIFrameWndEx::SaveMDIState` . Para carregar um perfil de grupo com guias MDI salvo anteriormente, chame `CMDIFrameWndEx::LoadMDIState` . Você também pode chamar esses métodos para carregar ou salvar a lista de documentos abertos em um aplicativo MDI. Para obter mais informações sobre como salvar e carregar o estado MDI, consulte [CMDIFrameWndEx:: LoadMDIState](reference/cmdiframewndex-class.md#loadmdistate).

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)<br/>
[Classe CMDIFrameWndEx](reference/cmdiframewndex-class.md)<br/>
[Classe CMDIChildWndEx](reference/cmdichildwndex-class.md)<br/>
[Classe CMDITabInfo](reference/cmditabinfo-class.md)
