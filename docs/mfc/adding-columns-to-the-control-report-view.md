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
ms.openlocfilehash: 119f0f9cb92d724058ce97fbf477143739ec111e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617307"
---
# <a name="adding-columns-to-the-control-report-view"></a>Adicionando colunas ao controle (exibição de relatório)

> [!NOTE]
> O procedimento a seguir aplica-se a um objeto [CListView](reference/clistview-class.md) ou [CListCtrl](reference/clistctrl-class.md) .

Quando um controle de lista está no modo de exibição de relatório, as colunas são exibidas, fornecendo um método de organizar os vários subitens de cada item de controle de lista. Essa organização é implementada com uma correspondência um-para-um entre uma coluna no controle de lista e o subitem associado do item de controle de lista. Para obter mais informações sobre subitens, consulte [adicionando itens ao controle](adding-items-to-the-control.md). Um exemplo de um controle de lista na exibição de relatório é fornecido pelo modo de exibição de detalhes no Windows 95 e no Windows 98 Explorer. A primeira coluna lista os ícones de pasta, arquivo e rótulos. Outras colunas listar tamanho do arquivo, tipo de arquivo, data da última modificação e assim por diante.

Embora as colunas possam ser adicionadas a um controle de lista a qualquer momento, as colunas ficam visíveis somente quando o controle tem o `LVS_REPORT` tipo de bit ativado.

Cada coluna tem um objeto de cabeçalho associado (consulte [CHeaderCtrl](reference/cheaderctrl-class.md)) que rotula a coluna e permite que os usuários redimensionem a coluna.

Se o controle de lista oferecer suporte a uma exibição de relatório, você precisará adicionar uma coluna para cada subitem possível em um item de controle de lista. Adicione uma coluna preparando uma estrutura [LVCOLUMN](/windows/win32/api/commctrl/ns-commctrl-lvcolumnw) e, em seguida, fazendo uma chamada para [InsertColumn](reference/clistctrl-class.md#insertcolumn). Depois de adicionar as colunas necessárias (às vezes chamadas de itens de cabeçalho), você pode reordená-las usando funções de membro e estilos que pertencem ao controle de cabeçalho incorporado. Para obter mais informações, consulte [ordenando itens no controle de cabeçalho](ordering-items-in-the-header-control.md).

> [!NOTE]
> Se o controle de lista for criado com o estilo de **LVS_NOCOLUMNHEADER** , qualquer tentativa de inserir colunas será ignorada.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
