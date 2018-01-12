---
title: "Conjunto de registros: Indicadores e posições absolutas (ODBC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: SetAbsolutePosition
dev_langs: C++
helpviewer_keywords:
- CDBVariant class, bookmarks
- absolute positions, ODBC recordsets
- bookmarks, CDBVariant
- bookmarks, ODBC recordsets
- ODBC recordsets, absolute positions
- ODBC recordsets, bookmarks
- cursors [ODBC], absolute position in recordsets
- recordsets, bookmarks
- bookmarks
- SetAbsolutePosition method
- recordsets, absolute positions
- positioning records
- SetBookmark method
- record positioning
- GetBookmark method
- SetAbsolutePosition method, bookmarks
ms.assetid: 189788d6-33c1-41c5-9265-97db2a5d43cc
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4b206e5d09d86613af0585df7510b0f88397984a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-bookmarks-and-absolute-positions-odbc"></a>Conjunto de registros: indicadores e posições absolutas (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Ao navegar por meio de um conjunto de registros, muitas vezes precisa de uma maneira de retornar a um determinado registro. Um registro de um indicador e posição absoluta fornecem dois desses métodos.  
  
 Este tópico explica:  
  
-   [Como usar indicadores](#_core_bookmarks_in_mfc_odbc).  
  
-   [Como definir o registro atual usando posições absolutas](#_core_absolute_positions_in_mfc_odbc).  
  
##  <a name="_core_bookmarks_in_mfc_odbc"></a>Indicadores em MFC ODBC  
 Um indicador identifica exclusivamente um registro. Quando você navega por meio de um conjunto de registros, você não pode sempre depender de posição absoluta de um registro porque os registros podem ser excluídos do conjunto de registros. O modo seguro para controlar a posição de um registro é usar seu indicador. Classe `CRecordset` fornece funções de membro para:  
  
-   Obtendo o indicador do registro atual, portanto você pode salvá-lo em uma variável ([GetBookmark](../../mfc/reference/crecordset-class.md#getbookmark)).  
  
-   Mover rapidamente para um determinado registro especificando seu indicador, o que você salvou anteriormente em uma variável ([SetBookmark](../../mfc/reference/crecordset-class.md#setbookmark)).  
  
 O exemplo a seguir ilustra como usar essas funções de membro para marcar o registro atual e retornar posteriormente a ele:  
  
```  
// rs is a CRecordset or  
// CRecordset-derived object  
  
CDBVariant varRecordToReturnTo;  
rs.GetBookmark( varRecordToReturnTo );  
  
// More code in which you  
// move to other records  
  
rs.SetBookmark( varRecordToReturnTo );  
```  
  
 Não é necessário extrair o tipo de dados subjacente do [classe CDBVariant](../../mfc/reference/cdbvariant-class.md) objeto. Atribuir o valor com `GetBookmark` e retornar para esse indicador com `SetBookmark`.  
  
> [!NOTE]
>  Dependendo do driver ODBC e o tipo de conjunto de registros, os indicadores podem não ter suporte. Você pode determinar facilmente se indicadores têm suporte chamando [CRecordset::CanBookmark](../../mfc/reference/crecordset-class.md#canbookmark). Além disso, se houver suporte para indicadores, deve especificar explicitamente para implementá-las especificando o **CRecordset::useBookmarks** opção o [CRecordset::Open](../../mfc/reference/crecordset-class.md#open) função de membro. Você também deve verificar a persistência de indicadores após determinadas operações de conjunto de registros. Por exemplo, se você **Requery** um conjunto de registros, indicadores podem ser mais válidos. Chamar [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar com segurança `SetBookmark`.  
  
##  <a name="_core_absolute_positions_in_mfc_odbc"></a>Posições absolutas em MFC ODBC  
 Além de indicadores, classe `CRecordset` permite que você defina o registro atual especificando uma posição ordinal. Isso é chamado de posicionamento absoluto.  
  
> [!NOTE]
>  O posicionamento absoluto não está disponível em conjuntos de registros somente de encaminhamento. Para obter mais informações sobre conjuntos de registros somente de encaminhamento, consulte [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md).  
  
 Para mover o ponteiro do registro atual usando a posição absoluta, chame [CRecordset::SetAbsolutePosition](../../mfc/reference/crecordset-class.md#setabsoluteposition). Quando você passar um valor para `SetAbsolutePosition`, o registro correspondente a posição ordinal torna-se o registro atual.  
  
> [!NOTE]
>  A posição absoluta de um registro é potencialmente não confiável. Se o usuário exclui registros do conjunto de registros, a posição ordinal de quaisquer alterações subsequentes de registro. Os indicadores são o método recomendado para mover o registro atual. Para obter mais informações, consulte [indicadores em MFC ODBC](#_core_bookmarks_in_mfc_odbc).  
  
 Para obter mais informações sobre a navegação do conjunto de registros, consulte [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)