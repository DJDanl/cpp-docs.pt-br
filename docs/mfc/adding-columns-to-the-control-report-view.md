---
title: Adicionando colunas ao controle (exibição de relatório) | Microsoft Docs
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
ms.openlocfilehash: 975d65119ba0ae24b236d96cbe67e73b70be6bac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341823"
---
# <a name="adding-columns-to-the-control-report-view"></a>Adicionando colunas ao controle (exibição de relatório)
> [!NOTE]
>  O procedimento a seguir aplica-se como um [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md) objeto.  
  
 Quando um controle de lista está no modo de exibição de relatório, as colunas são exibidas, fornecendo um método de organizar os subitens vários de cada item de controle de lista. Essa organização é implementada com uma correspondência entre uma coluna na lista de controle e subitem associado do item de controle de lista. Para obter mais informações sobre subitens, consulte [adicionando itens ao controle](../mfc/adding-items-to-the-control.md). Um exemplo de um controle de lista no modo de exibição de relatório é fornecido pela exibição de detalhes no Windows 95 e Windows 98 Explorer. A primeira coluna lista os rótulos, ícones de arquivo e pasta. Outras colunas listam o tamanho do arquivo, tipo de arquivo, data da última modificada e assim por diante.  
  
 Mesmo que as colunas podem ser adicionadas a um controle de lista a qualquer momento, as colunas são visíveis apenas quando o controle tem o `LVS_REPORT` bit de estilo ativado.  
  
 Cada coluna tem um item de cabeçalho associado (consulte [CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) objeto rótulos de coluna e permite que os usuários redimensionar a coluna.  
  
 Se o controle de lista dá suporte a um modo de exibição de relatório, você precisa adicionar uma coluna para cada subitem possíveis em um item de controle de lista. Adicionar uma coluna Preparando um [LV_COLUMN](http://msdn.microsoft.com/library/windows/desktop/bb774743) estrutura e, em seguida, fazer uma chamada para [InsertColumn](../mfc/reference/clistctrl-class.md#insertcolumn). Depois de adicionar as colunas necessárias (também conhecidas como itens de cabeçalho), você pode reorganizá-las usando funções de membro e estilos que pertencem ao controle de cabeçalho incorporado. Para obter mais informações, consulte [ordenando itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md).  
  
> [!NOTE]
>  Se o controle de lista é criado com o **LVS_NOCOLUMNHEADER** estilo, qualquer tentativa para inserir colunas será ignorado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

