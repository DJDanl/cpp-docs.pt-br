---
title: Controles rebar e bandas
ms.date: 11/04/2016
helpviewer_keywords:
- rebar controls [MFC], working with bands in
- bands, in rebar controls
ms.assetid: b647e7a5-9ea7-48b1-8e5f-096d104748f0
ms.openlocfilehash: 4bb7b4aeab1478138aa2b52649f41ca943b5daa4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378149"
---
# <a name="rebar-controls-and-bands"></a>Controles rebar e bandas

O objetivo principal de um controle rebar é atuar como um contêiner para janelas filho, controles comuns da caixa de diálogo, menus, barras de ferramentas e assim por diante. Essa contenção é compatível com o conceito de "banda". Cada faixa de rebar pode conter qualquer combinação de uma barra de garra, um bitmap, um rótulo de texto e uma janela filho.

Classe `CReBarCtrl` tem muitas funções de membro que você pode usar para recuperar e manipular informações para uma faixa de rebar específico:

- [GetBandCount](../mfc/reference/crebarctrl-class.md#getbandcount) recupera o número de faixas atuais no controle rebar.

- [GetBandInfo](../mfc/reference/crebarctrl-class.md#getbandinfo) inicializa um **REBARBANDINFO** estrutura com informações da banda especificada. Não há um correspondente [SetBandInfo](../mfc/reference/crebarctrl-class.md#setbandinfo) função de membro.

- [GetRect](../mfc/reference/crebarctrl-class.md#getrect) recupera o retângulo delimitador de uma faixa especificada.

- [GetRowCount](../mfc/reference/crebarctrl-class.md#getrowcount) recupera o número de linhas de banda em um controle rebar.

- [IDToIndex](../mfc/reference/crebarctrl-class.md#idtoindex) recupera o índice de uma faixa especificada.

- [GetBandBorders](../mfc/reference/crebarctrl-class.md#getbandborders) recupera as bordas de uma faixa.

Além de manipulação de várias funções de membro são fornecida que permite que você opere em bandas rebar específico.

[InsertBand](../mfc/reference/crebarctrl-class.md#insertband) e [DeleteBand](../mfc/reference/crebarctrl-class.md#deleteband) adicionar e remover bandas rebar. [MinimizeBand](../mfc/reference/crebarctrl-class.md#minimizeband) e [MaximizeBand](../mfc/reference/crebarctrl-class.md#maximizeband) afetam o tamanho atual de uma faixa de rebar específico. [MoveBand](../mfc/reference/crebarctrl-class.md#moveband) altera o índice de uma faixa de rebar específico. [ShowBand](../mfc/reference/crebarctrl-class.md#showband) mostra ou oculta uma faixa de rebar do usuário.

O exemplo a seguir demonstra como adicionar uma faixa da barra de ferramentas (*m_wndToolBar*) para um controle rebar existente (*m_wndReBar*). A faixa é descrita por inicializar o `rbi` estrutura e, em seguida, chamar o `InsertBand` função de membro:

[!code-cpp[NVC_MFCControlLadenDialog#27](../mfc/codesnippet/cpp/rebar-controls-and-bands_1.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CReBarCtrl](../mfc/using-crebarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
