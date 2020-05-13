---
title: 'Conjunto de registros: indicadores e posições absolutas (ODBC)'
ms.date: 11/04/2016
f1_keywords:
- SetAbsolutePosition
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
ms.openlocfilehash: 77c8bbaf7c0bc21dab62c3785364e72656287815
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367062"
---
# <a name="recordset-bookmarks-and-absolute-positions-odbc"></a>Conjunto de registros: indicadores e posições absolutas (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Ao navegar através de um conjunto de discos, muitas vezes você precisa de uma maneira de retornar a um determinado registro. O marcador de um registro e a posição absoluta fornecem dois métodos desse tipo.

Este tópico explica:

- [Como usar marcadores](#_core_bookmarks_in_mfc_odbc).

- [Como definir o recorde atual usando posições absolutas](#_core_absolute_positions_in_mfc_odbc).

## <a name="bookmarks-in-mfc-odbc"></a><a name="_core_bookmarks_in_mfc_odbc"></a>Marcadores em MFC ODBC

Um marcador identifica um registro com exclusividade. Quando você navega através de um conjunto de registros, nem sempre pode confiar na posição absoluta de um registro porque os registros podem ser excluídos do conjunto de registros. A maneira confiável de manter o controle da posição de um registro é usar seu marcador. A `CRecordset` classe fornece funções de membros para:

- Obtendo o marcador do registro atual, para que você possa salvá-lo em uma variável[(GetBookmark](../../mfc/reference/crecordset-class.md#getbookmark)).

- Movendo-se rapidamente para um determinado registro especificando seu marcador, que você salvou anteriormente em uma variável[(SetBookmark).](../../mfc/reference/crecordset-class.md#setbookmark)

O exemplo a seguir ilustra como usar essas funções de membro para marcar o registro atual e depois retornar a ele:

```cpp
// rs is a CRecordset or
// CRecordset-derived object

CDBVariant varRecordToReturnTo;
rs.GetBookmark( varRecordToReturnTo );

// More code in which you
// move to other records

rs.SetBookmark( varRecordToReturnTo );
```

Você não precisa extrair o tipo de dados subjacente do objeto [CDBVariant Class.](../../mfc/reference/cdbvariant-class.md) Atribuir o valor `GetBookmark` com e retornar `SetBookmark`a esse marcador com .

> [!NOTE]
> Dependendo do driver oDBC e do tipo de conjunto de registros, os marcadores podem não ser suportados. Você pode determinar facilmente se os marcadores são suportados chamando [CRecordset::CanBookmark](../../mfc/reference/crecordset-class.md#canbookmark). Além disso, se os marcadores forem suportados, você deve `CRecordset::useBookmarks` optar explicitamente por implementá-los especificando a opção na função [CRecordset::Open](../../mfc/reference/crecordset-class.md#open) member. Você também deve verificar a persistência de marcadores após certas operações de conjunto de registros. Por exemplo, `Requery` se você um conjunto de registros, os marcadores podem não ser mais válidos. Chamada [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se `SetBookmark`você pode ligar com segurança .

## <a name="absolute-positions-in-mfc-odbc"></a><a name="_core_absolute_positions_in_mfc_odbc"></a>Posições Absolutas no MFC ODBC

Além dos marcadores, a classe `CRecordset` permite que você defina o registro atual especificando uma posição ordinal. Isso é chamado de posicionamento absoluto.

> [!NOTE]
> O posicionamento absoluto não está disponível em conjuntos de registros somente para a frente. Para obter mais informações sobre conjuntos de registros somente para o futuro, consulte [Recordset (ODBC)](../../data/odbc/recordset-odbc.md).

Para mover o ponteiro de registro atual usando a posição absoluta, chame [CRecordset::SetAbsolutePosition](../../mfc/reference/crecordset-class.md#setabsoluteposition). Quando você passa `SetAbsolutePosition`um valor para , o registro correspondente a essa posição ordinal torna-se o registro atual.

> [!NOTE]
> A posição absoluta de um registro é potencialmente não confiável. Se o usuário excluir registros do conjunto de registros, a posição ordinal de quaisquer alterações de registro subseqüentes. Marcadores são o método recomendado para mover o registro atual. Para obter mais informações, consulte [Marcadores no MFC ODBC](#_core_bookmarks_in_mfc_odbc).

Para obter mais informações sobre navegação no conjunto de registros, consulte [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)
