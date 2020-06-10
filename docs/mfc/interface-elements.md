---
title: Elementos da interface
ms.date: 11/19/2018
helpviewer_keywords:
- architecture [MFC], MFC Feature Pack
- MFC Feature Pack, architecture
ms.assetid: eead6827-9602-40a3-8038-8986e8207385
ms.openlocfilehash: 4d4d81287cb30a7d3608025085cdb3f9a208147a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619988"
---
# <a name="interface-elements"></a>Elementos da interface

Este documento descreve os elementos de interface que foram introduzidos no Visual Studio 2008 SP1 e também descreve as diferenças com a versão anterior da biblioteca.

A ilustração a seguir mostra um aplicativo que foi criado usando os novos elementos de interface.

![Aplicativo de exemplo do MFC Feature Pack](../mfc/media/mfc_featurepack.png "Aplicativo de exemplo do MFC Feature Pack")

## <a name="window-docking"></a>Encaixe da janela

A funcionalidade de encaixe da janela é semelhante ao encaixe da janela que a interface gráfica do usuário do Visual Studio usa.

## <a name="control-bars-are-now-panes"></a>Barras de controle agora são painéis

Barras de controle agora são conhecidas como painéis e são derivadas da [Classe CBasePane](reference/cbasepane-class.md). Nas versões anteriores do MFC, a classe base das barras de controle era `CControlBar` .

A janela do quadro principal do aplicativo geralmente é representada pela [Classe CFrameWndEx](reference/cframewndex-class.md) ou pela [Classe CMDIFrameWndEx](reference/cmdiframewndex-class.md). O quadro principal é chamado de *site de encaixe*. Os painéis podem ter um dos três tipos de pais: um site de encaixe, uma barra de encaixe ou uma janela de mini-moldura.

Há dois tipos de painéis: não redimensionável e redimensionável. Painéis redimensionáveis, como barras de status e barras de ferramentas, podem ser redimensionados usando divisores ou controles deslizantes. Os painéis redimensionáveis podem formar Contêineres (um painel pode ser encaixado em outro painel, criando um divisor entre eles). No entanto, os painéis redimensionáveis não podem ser anexados (encaixados) às barras de encaixe.

Se seu aplicativo usar painéis não redimensionáveis, derive-os da [Classe CPane](reference/cpane-class.md).  Se seu aplicativo usar painéis redimensionáveis, derive-os da [Classe CDockablePane](reference/cdockablepane-class.md)

## <a name="dock-site"></a>Encaixar site

O site de encaixe (ou a janela de quadro principal) possui todos os painéis e janelas de mini quadros em um aplicativo. O site Dock contém um membro [CDockingManager](reference/cdockingmanager-class.md) . Esse membro mantém uma lista de todos os painéis que pertencem ao site de encaixe. A lista é ordenada para que os painéis criados nas bordas externas do site de encaixe sejam posicionados no início da lista. Quando a estrutura redesenha o site de encaixe, ele percorre essa lista e ajusta o layout de cada painel para incluir o retângulo delimitador atual do site de encaixe. Você pode chamar `AdjustDockingLayout` ou `RecalcLayout` quando você precisa ajustar o layout de encaixe, e a estrutura redireciona essa chamada para o Gerenciador de encaixe.

## <a name="dock-bars"></a>Barras de encaixe

Cada janela de quadro principal pode posicionar *barras de encaixe* ao longo de suas bordas. Uma barra de encaixe é um painel que pertence a uma [Classe CDockSite](reference/cdocksite-class.md). As barras de encaixe podem aceitar objetos derivados de [CPane](reference/cpane-class.md), como barras de ferramentas. Para criar barras de encaixe quando a janela do quadro principal for inicializada, chame `EnableDocking` . Para habilitar as barras de ocultar automaticamente, chame `EnableAutoHideBars` . `EnableAutoHideBars`cria objetos [CAutoHideDockSite](reference/cautohidedocksite-class.md) e os posiciona ao lado de cada barra de encaixe.

Cada barra de encaixe é dividida em linhas de encaixe. Linhas de encaixe são representadas pela [classe CDockingPanesRow](reference/cdockingpanesrow-class.md). Cada linha de encaixe contém uma lista de barras de ferramentas. Se um usuário encaixar uma barra de ferramentas ou mover a barra de ferramentas de uma linha para outra na mesma barra de encaixe, a estrutura criará uma nova linha e redimensionará a barra de encaixe adequadamente ou posicionará a barra de ferramentas em uma linha existente.

## <a name="mini-frame-windows"></a>Janelas de mini quadros

Um painel flutuante reside em uma janela de mini-quadro. As janelas de mini-frame são representadas por duas classes: [CMDITabInfo classe](reference/cmditabinfo-class.md) (que pode conter apenas um painel) e a [classe CMultiPaneFrameWnd](reference/cmultipaneframewnd-class.md) (que pode conter vários painéis). Para flutuar um painel em seu código, chame [CBasePane:: FloatPane](reference/cbasepane-class.md#floatpane). Depois que um painel flutua, a estrutura cria automaticamente uma janela de mini-quadro e essa janela de mini-quadro se torna o pai do painel flutuante. Quando o painel flutuante se encaixa, a estrutura redefine seu pai e o painel flutuante se torna uma barra de encaixe (para barras de ferramentas) ou um site de encaixe (para painéis redimensionáveis).

## <a name="pane-dividers"></a>Divisores de painel

Os divisores de painel (também chamados de controles deslizantes ou divisores) são representados pela [Classe CPaneDivider](reference/cpanedivider-class.md). Quando um usuário encaixa um painel, a estrutura cria os divisores de painel, independentemente de o painel estar encaixado no site de encaixe ou em outro painel. Quando um painel se encaixa no site de encaixe, o divisor de painel é chamado de *divisor de painel padrão*. O divisor de painel padrão é responsável pelo layout de todos os painéis de encaixe no site de encaixe. O Dock Manager mantém uma lista de divisores de painel padrão e uma lista de painéis. Os Dock Managers são responsáveis pelo layout de todos os painéis de encaixe.

## <a name="containers"></a>Contêineres

Todos os painéis redimensionáveis, quando encaixados entre si, são mantidos em contêineres. Os contêineres são representados pela [Classe CPaneContainer](reference/cpanecontainer-class.md). Cada contêiner tem ponteiros para o painel esquerdo, para o painel direito, para o subcontêiner esquerdo, para o subcontêiner direito e para o divisor entre as partes esquerda e direita. (*Esquerda* e *direita* não fazem referência a lados físicos, mas sim identificar as ramificações de uma estrutura de árvore.) Dessa maneira, podemos criar uma árvore de painéis e divisores e, portanto, obter layouts complexos de painéis que podem ser redimensionados juntos. A `CPaneContainer` classe mantém a árvore de contêineres; ela também mantém duas listas de painéis e controles deslizantes que residem nessa árvore. Os gerenciadores de contêineres de painel geralmente são inseridos em controles deslizantes padrão e de mini quadros que contêm vários painéis.

## <a name="auto-hide-control-bars"></a>Ocultar barras de controle automaticamente

Por padrão, cada um `CDockablePane` dá suporte ao recurso de ocultar automaticamente. Quando um usuário clica no botão fixar na legenda do `CDockablePane` , a estrutura alterna o painel para ocultar o modo automaticamente. Para manipular o clique, a estrutura cria uma [classe CMFCAutoHideBar](reference/cmfcautohidebar-class.md) e uma [Classe CMFCAutoHideButton](reference/cmfcautohidebutton-class.md) associada ao `CMFCAutoHideBar` objeto. A estrutura coloca a novidade `CMFCAutoHideBar` no [CAutoHideDockSite](reference/cautohidedocksite-class.md). A estrutura também anexa o `CMFCAutoHideButton` à barra de ferramentas. A [classe CDockingManager](reference/cdockingmanager-class.md) mantém o `CDockablePane` .

## <a name="tabbed-control-bars-and-outlook-bars"></a>Barras de controle com guias e barras do Outlook

A [Classe CMFCBaseTabCtrl](reference/cmfcbasetabctrl-class.md) implementa a funcionalidade base de uma janela com guias com guias desanexáveis. Para usar um `CMFCBaseTabCtrl` objeto, inicialize uma [classe CBaseTabbedPane](reference/cbasetabbedpane-class.md) em seu aplicativo. `CBaseTabbedPane`é derivado de `CDockablePane` e mantém um ponteiro para um `CMFCBaseTabCtrl` objeto. O `CBaseTabbedPane` permite que os usuários encaixem e redimensionem barras de controle com guias. Use [CDockablePane:: AttachToTabWnd](reference/cdockablepane-class.md#attachtotabwnd) para criar barras de controle dinamicamente que são encaixadas e tabuladas.

O controle da barra do Outlook também se baseia em barras com guias. A [Classe CMFCOutlookBar](reference/cmfcoutlookbar-class.md) é derivada de `CBaseTabbedPane` . Para obter mais informações sobre como usar a barra do Outlook, consulte [Classe CMFCOutlookBar](reference/cmfcoutlookbar-class.md).

## <a name="see-also"></a>Consulte também

[Conceitos](mfc-concepts.md)
