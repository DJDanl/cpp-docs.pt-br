---
title: Controle de cabeçalho e de lista
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], with CHeaderCtrl
- CListCtrl class [MFC], header controls
- CHeaderCtrl class [MFC], with CListCtrl
- controls [MFC], header
- header controls [MFC]
- header controls [MFC], list controls used with
ms.assetid: b20194b1-1a6b-4e2f-b890-1b3cca6650bc
ms.openlocfilehash: 53dd6f1a7878d82a7f7ac48dd7082d791323941b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370468"
---
# <a name="header-control-and-list-control"></a>Controle de cabeçalho e de lista

Na maioria dos casos, você usará o controle de cabeçalho incorporado em um objeto [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView.](../mfc/reference/clistview-class.md) No entanto, há casos em que um objeto de controle de cabeçalho separado é desejável, como manipulação de dados, dispostos em colunas ou linhas, em um objeto derivado do [CView.](../mfc/reference/cview-class.md) Nesses casos, você precisa de maior controle sobre a aparência e o comportamento padrão de um controle de cabeçalho incorporado.

No caso comum de que você deseja um controle de cabeçalho para fornecer comportamento padrão padrão, você pode querer usar [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView](../mfc/reference/clistview-class.md) em vez disso. Use `CListCtrl` quando quiser a funcionalidade de um controle de cabeçalho padrão, incorporado em uma exibição de lista comum de controle. Use [CListView](../mfc/reference/clistview-class.md) quando quiser a funcionalidade de um controle de cabeçalho padrão, incorporado em um objeto de exibição.

> [!NOTE]
> Esses controles só incluem um controle de cabeçalho incorporado se o controle de exibição de lista for criado usando o estilo **LVS_REPORT.**

Na maioria dos casos, o aparecimento do controle de cabeçalho incorporado pode ser modificado alterando os estilos do controle de exibição de lista contendo. Além disso, informações sobre o controle de cabeçalho podem ser obtidas através das funções de membro do controle de exibição da lista dos pais. No entanto, para controle completo e acesso aos atributos e estilos do controle de cabeçalho incorporado, recomenda-se que um ponteiro para o objeto de controle de cabeçalho seja obtido.

O objeto de controle de cabeçalho incorporado pode ser acessado de qualquer um `CListCtrl` ou `CListView` com uma chamada para a função de membro da `GetHeaderCtrl` respectiva classe. O código a seguir demonstra isso:

[!code-cpp[NVC_MFCControlLadenDialog#14](../mfc/codesnippet/cpp/header-control-and-list-control_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Usando listas de imagens com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)

## <a name="see-also"></a>Confira também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
