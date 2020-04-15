---
title: Adicionando colunas ao controle (exibição de relatório)
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], adding columns
- report view in CListCtrl class [MFC]
- views [MFC], report
- columns [MFC], adding to CListCtrl
- CListCtrl class [MFC], report view
ms.assetid: 7392c0d7-f8a5-4e7b-9ae7-b53dc9dd80ae
ms.openlocfilehash: 34d7b62985748b9b9d741c083ec9b34fce06b309
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370869"
---
# <a name="adding-columns-to-the-control-report-view"></a>Adicionando colunas ao controle (exibição de relatório)

> [!NOTE]
> O procedimento a seguir se aplica a um objeto [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl.](../mfc/reference/clistctrl-class.md)

Quando um controle de lista está na exibição de relatórios, as colunas são exibidas, fornecendo um método de organização dos vários subitems de cada item de controle de lista. Essa organização é implementada com uma correspondência um-para-um entre uma coluna no controle de lista e o subitem associado do item de controle de lista. Para obter mais informações sobre subitens, consulte [Adicionar itens ao Controle](../mfc/adding-items-to-the-control.md). Um exemplo de um controle de lista na exibição de relatórios é fornecido pela exibição Detalhes no Windows 95 e windows 98 Explorer. A primeira coluna lista pasta, ícones de arquivo e rótulos. Outras colunas listam tamanho do arquivo, tipo de arquivo, data última modificada, e assim por diante.

Embora as colunas possam ser adicionadas a um controle de lista a `LVS_REPORT` qualquer momento, as colunas só são visíveis quando o controle tem o bit de estilo ligado.

Cada coluna tem um objeto de cabeçalho associado (ver [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) que rotula a coluna e permite que os usuários redimensionem a coluna.

Se o controle de lista suportar uma exibição de relatório, você precisa adicionar uma coluna para cada subitem possível em um item de controle de lista. Adicione uma coluna preparando uma estrutura [LVCOLUMN](/windows/win32/api/commctrl/ns-commctrl-lvcolumnw) e, em seguida, fazendo uma chamada para [InsertColumn](../mfc/reference/clistctrl-class.md#insertcolumn). Depois de adicionar as colunas necessárias (às vezes referidas como itens de cabeçalho), você pode reordena-las usando funções de membro e estilos pertencentes ao controle de cabeçalho incorporado. Para obter mais informações, consulte [Itens de encomenda no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md).

> [!NOTE]
> Se o controle de lista for criado com o estilo **LVS_NOCOLUMNHEADER,** qualquer tentativa de inserir colunas será ignorada.

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
