---
title: Adicionando colunas ao controle (exibição de relatórios) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CListCtrl class [MFC], adding columns
- report view in CListCtrl class [MFC]
- views [MFC], report
- columns [MFC], adding to CListCtrl
- CListCtrl class [MFC], report view
ms.assetid: 7392c0d7-f8a5-4e7b-9ae7-b53dc9dd80ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3e81de52856d67760ffe58f29e4c39ac79213c4
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221938"
---
# <a name="adding-columns-to-the-control-report-view"></a>Adicionando colunas ao controle (exibição de relatório)
> [!NOTE]
>  O procedimento a seguir aplica-se como um [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md) objeto.  
  
 Quando um controle de lista está no modo de exibição de relatório, as colunas são exibidas, fornecendo um método de organizar vários subitens de cada item de controle de lista. Essa organização é implementada com uma correspondência direta entre uma coluna no controle de lista e subitem do item da lista de controle associado. Para obter mais informações sobre os subitens, consulte [adicionando itens ao controle](../mfc/adding-items-to-the-control.md). Um exemplo de um controle de lista no modo de exibição de relatório é fornecido pela exibição de detalhes no Windows 95 e Windows 98 Explorer. A primeira coluna lista os rótulos, ícones de arquivo e pasta. Outras colunas listam o tamanho do arquivo, tipo de arquivo, data da última modificada e assim por diante.  
  
 Mesmo que as colunas podem ser adicionadas a um controle de lista a qualquer momento, as colunas são visíveis apenas quando o controle tem o `LVS_REPORT` bit de estilo ativado.  
  
 Cada coluna tem um item de cabeçalho associado (consulte [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) objeto que a coluna de rótulos e permite que os usuários redimensionar a coluna.  
  
 Se seu controle lista dá suporte a uma exibição de relatório, você precisará adicionar uma coluna para cada subitem possíveis em um item de controle de lista. Adicione uma coluna, preparando um [LV_COLUMN](/windows/desktop/api/commctrl/ns-commctrl-taglvcolumna) estrutura e, em seguida, fazer uma chamada a [InsertColumn](../mfc/reference/clistctrl-class.md#insertcolumn). Depois de adicionar as colunas necessárias (também conhecidas como itens de cabeçalho), reordená-las usando funções de membro e estilos que pertencem ao controle de cabeçalho incorporado. Para obter mais informações, consulte [ordenação de itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md).  
  
> [!NOTE]
>  Se o controle de lista for criado com o **LVS_NOCOLUMNHEADER** estilo, qualquer tentativa de inserir colunas será ignorado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

