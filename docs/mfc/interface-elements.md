---
title: Elementos da interface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- architecture [MFC], MFC Feature Pack
- MFC Feature Pack, architecture
ms.assetid: eead6827-9602-40a3-8038-8986e8207385
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0f8cb2a8f3ccb36f3fa1ed2bf3f81087691ce988
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404404"
---
# <a name="interface-elements"></a>Elementos da interface

Este documento descreve os elementos de interface que foram introduzidos no Visual Studio 2008 SP1 e também descreve as diferenças com a versão anterior da biblioteca.

A ilustração a seguir mostra um aplicativo que foi criado usando os novos elementos de interface.

![O aplicativo de exemplo do MFC Feature Pack](../mfc/media/mfc_featurepack.png "mfc_featurepack")

## <a name="window-docking"></a>Janela de encaixe

É semelhante a janela de encaixe que a interface gráfica do usuário do Visual Studio usa a funcionalidade de encaixe da janela.

## <a name="control-bars-are-now-panes"></a>Barras de controle são agora painéis

Barras de controle agora são conhecidas como painéis e derivam [classe CBasePane](../mfc/reference/cbasepane-class.md). Em versões anteriores do MFC, a classe base das barras de controle foi `CControlBar`.

A janela de quadro principal do aplicativo geralmente é representada pela [classe CFrameWndEx](../mfc/reference/cframewndex-class.md) ou o [classe CMDIFrameWndEx](../mfc/reference/cmdiframewndex-class.md). O quadro principal é chamado de *encaixar site*. Painéis podem ter um dos três tipos de pais: um local de encaixe, uma barra de encaixe ou uma janela com minimoldura.

Há dois tipos de painéis: redimensionáveis e não redimensionável. Painéis redimensionáveis, como barras de status e barras de ferramentas, podem ser redimensionados usando divisores ou controles deslizantes. Painéis redimensionáveis podem formar contêineres (um painel pode ser encaixado para outro painel, criando um divisor entre eles). No entanto, os painéis redimensionáveis não podem ser anexados (encaixado) para encaixar barras.

Se seu aplicativo usa os painéis não redimensionável, derivá-las de [classe CPane](../mfc/reference/cpane-class.md).  Se seu aplicativo usa painéis redimensionáveis, derivá-las de [classe CDockablePane](../mfc/reference/cdockablepane-class.md)

## <a name="dock-site"></a>Local de encaixe

O local de encaixe (ou a janela do quadro principal) possui todos os painéis e janelas com miniem moldura um aplicativo. O local de encaixe contém um [CDockingManager](../mfc/reference/cdockingmanager-class.md) membro. Esse membro mantém uma lista de todos os painéis que pertencem ao local de encaixe. A lista é ordenada para que os painéis criados nas bordas externas do local de encaixe são posicionados no início da lista. Quando o framework redesenha o local de encaixe, ele faz um loop sobre essa lista e ajusta o layout de cada painel para incluir o retângulo delimitador atual do site de encaixe. Você pode chamar `AdjustDockingLayout` ou `RecalcLayout` quando você precise ajustar o layout de encaixe e a estrutura redireciona essa chamada para o Gerenciador de encaixe.

## <a name="dock-bars"></a>Barras de encaixe

Cada janela de quadro principal pode posicionar *encaixar barras* ao longo de suas bordas. Uma barra de encaixe é um painel que pertence a um [classe CDockSite](../mfc/reference/cdocksite-class.md). Barras de encaixe podem aceitar objetos derivados de [CPane](../mfc/reference/cpane-class.md), como barras de ferramentas. Para criar barras de encaixe quando a janela do quadro principal é inicializada, chame `EnableDocking`. Para habilitar as barras de ocultar automaticamente, chame `EnableAutoHideBars`. `EnableAutoHideBars` cria [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md) objetos e posiciona-os ao lado de cada barra de encaixe.

Cada barra de encaixe é dividida em linhas de encaixe. Linhas de encaixe são representadas pela [classe CDockingPanesRow](../mfc/reference/cdockingpanesrow-class.md). Cada linha de encaixe contém uma lista das barras de ferramentas. Se um usuário se encaixa uma barra de ferramentas ou move a barra de ferramentas de uma linha para outra dentro da mesma barra de encaixe, o framework cria uma nova linha e redimensiona a barra de encaixe adequadamente, ou ele posiciona a barra de ferramentas em uma linha existente.

## <a name="mini-frame-windows"></a>Windows com minimoldura

Um painel flutuante reside em uma janela com minimoldura. Janelas com minisão moldura representadas por duas classes: [classe CMDITabInfo](../mfc/reference/cmditabinfo-class.md) (que pode conter somente um painel) e [classe CMultiPaneFrameWnd](../mfc/reference/cmultipaneframewnd-class.md) (que pode conter vários painéis). Para flutuar um painel em seu código, chame [CBasePane::FloatPane](../mfc/reference/cbasepane-class.md#floatpane). Depois que um painel flutua, o framework cria automaticamente uma janela com minimoldura e essa janela com minimoldura torna-se o pai do painel flutuante. Quando o painel flutuante encaixa, o framework redefine seu pai e o painel flutuante se torna uma barra de encaixe (para barras de ferramentas) ou um local de encaixe (para painéis redimensionáveis).

## <a name="pane-dividers"></a>Divisores de painel

Divisores de painel (também chamados de controles deslizantes ou divisores) são representados pela [classe CPaneDivider](../mfc/reference/cpanedivider-class.md). Quando um usuário encaixa um painel, a estrutura cria os divisores de painel, independentemente se o painel estiver encaixado no local de encaixe ou em outro painel. Quando um painel se encaixa o local de encaixe, o divisor do painel é chamado de *padrão divisor do painel*. O divisor do painel padrão é responsável pelo layout de todos os painéis de encaixe no local de encaixe. O Gerenciador de encaixe mantém uma lista de divisores de painel padrão e uma lista de painéis. Gerenciadores de encaixe são responsáveis pelo layout de todos os painéis de encaixe.

## <a name="containers"></a>Contêineres

Todos os painéis redimensionáveis quando encaixado uns aos outros, são mantidos em contêineres. Contêineres são representados pela [classe CPaneContainer](../mfc/reference/cpanecontainer-class.md). Cada contêiner tem ponteiros para seu painel esquerdo, painel direito, subcontêiner à esquerda, direita subcontêiner e o divisor entre as partes esquerdas e direita. (*Esquerda* e *direita* não se referem a lados físicos, mas em vez disso, identifique as ramificações de uma estrutura de árvore.) Dessa maneira, podemos construir uma árvore de painéis e divisores e, portanto, atingir layouts complexos de painéis que podem ser redimensionados juntos. O `CPaneContainer` classe mantém a árvore de contêineres; ele também mantém duas listas de painéis e controles deslizantes que residem nessa árvore. Gerenciadores de contêiner de painel geralmente são incorporadas controles deslizantes de padrão e windows com minimoldura que carregam vários painéis.

## <a name="auto-hide-control-bars"></a>Barras de controle de ocultar automaticamente

Por padrão, cada `CDockablePane` suporta o recurso de ocultar automaticamente. Quando um usuário clica no botão de pino na legenda do `CDockablePane`, o framework alterna o painel para o modo de ocultamento automático. Para lidar com o clique, o framework cria uma [classe CMFCAutoHideBar](../mfc/reference/cmfcautohidebar-class.md) e uma [classe CMFCAutoHideButton](../mfc/reference/cmfcautohidebutton-class.md) associado com o `CMFCAutoHideBar` objeto. O framework coloca o novo `CMFCAutoHideBar` sobre o [CAutoHideDockSite](../mfc/reference/cautohidedocksite-class.md). A estrutura também anexa o `CMFCAutoHideButton` à barra de ferramentas. O [classe CDockingManager](../mfc/reference/cdockingmanager-class.md) mantém o `CDockablePane`.

## <a name="tabbed-control-bars-and-outlook-bars"></a>Barras de controle com guias e barras de Outlook

O [classe CMFCBaseTabCtrl](../mfc/reference/cmfcbasetabctrl-class.md) implementa a funcionalidade básica de uma janela com guias com guias desanexáveis. Para usar um `CMFCBaseTabCtrl` do objeto, inicialize uma [classe CBaseTabbedPane](../mfc/reference/cbasetabbedpane-class.md) em seu aplicativo. `CBaseTabbedPane` é derivado de `CDockablePane` e mantém um ponteiro para um `CMFCBaseTabCtrl` objeto. O `CBaseTabbedPane` permite que os usuários Encaixar e redimensionar as barras de controle com guias. Use [CDockablePane::AttachToTabWnd](../mfc/reference/cdockablepane-class.md#attachtotabwnd) para criar dinamicamente as barras de controle que estão encaixadas e com guias.

O controle de barra do Outlook também se baseia nas barras com guias. O [classe CMFCOutlookBar](../mfc/reference/cmfcoutlookbar-class.md) é derivado de `CBaseTabbedPane`. Para obter mais informações sobre como usar a barra do Outlook, consulte [classe CMFCOutlookBar](../mfc/reference/cmfcoutlookbar-class.md).

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)

