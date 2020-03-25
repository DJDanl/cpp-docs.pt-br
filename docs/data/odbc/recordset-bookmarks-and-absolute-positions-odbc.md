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
ms.openlocfilehash: 9a25c0fe4c1f08d376824fbc02211d22c7c14435
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212960"
---
# <a name="recordset-bookmarks-and-absolute-positions-odbc"></a>Conjunto de registros: indicadores e posições absolutas (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Ao navegar por um conjunto de registros, muitas vezes você precisa de uma maneira de retornar a um registro específico. O indicador e A posição absoluta de um registro fornecem dois métodos desse tipo.

Este tópico explica:

- [Como usar indicadores](#_core_bookmarks_in_mfc_odbc).

- [Como definir o registro atual usando posições absolutas](#_core_absolute_positions_in_mfc_odbc).

##  <a name="bookmarks-in-mfc-odbc"></a><a name="_core_bookmarks_in_mfc_odbc"></a>Indicadores no MFC ODBC

Um indicador identifica exclusivamente um registro. Quando você navega por um conjunto de registros, nem sempre depende da posição absoluta de um registro, pois os registros podem ser excluídos do conjunto de registros. A maneira confiável de controlar a posição de um registro é usar seu indicador. A classe `CRecordset` fornece funções de membro para:

- Obter o indicador do registro atual, para que você possa salvá-lo em uma variável ([GetBookmark](../../mfc/reference/crecordset-class.md#getbookmark)).

- Movendo rapidamente para um determinado registro especificando seu indicador, que você salvou anteriormente em uma variável ([SetBookmark](../../mfc/reference/crecordset-class.md#setbookmark)).

O exemplo a seguir ilustra como usar essas funções de membro para marcar o registro atual e retornar para ele mais tarde:

```cpp
// rs is a CRecordset or
// CRecordset-derived object

CDBVariant varRecordToReturnTo;
rs.GetBookmark( varRecordToReturnTo );

// More code in which you
// move to other records

rs.SetBookmark( varRecordToReturnTo );
```

Você não precisa extrair o tipo de dados subjacente do objeto de [classe CDBVariant](../../mfc/reference/cdbvariant-class.md) . Atribua o valor com `GetBookmark` e retorne a esse indicador com `SetBookmark`.

> [!NOTE]
>  Dependendo do seu driver ODBC e do tipo do conjunto de registros, os indicadores podem não ter suporte. Você pode determinar facilmente se há suporte para indicadores chamando [CRecordset:: CanBookmark](../../mfc/reference/crecordset-class.md#canbookmark). Além disso, se houver suporte para indicadores, você deverá optar por implementá-los explicitamente especificando a opção `CRecordset::useBookmarks` na função de membro [CRecordset:: Open](../../mfc/reference/crecordset-class.md#open) . Você também deve verificar a persistência de indicadores após determinadas operações de conjunto de registros. Por exemplo, se você `Requery` um conjunto de registros, os indicadores podem não ser mais válidos. Chame [CDatabase:: GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar `SetBookmark`com segurança.

##  <a name="absolute-positions-in-mfc-odbc"></a><a name="_core_absolute_positions_in_mfc_odbc"></a>Posições absolutas no MFC ODBC

Além dos indicadores, a classe `CRecordset` permite que você defina o registro atual especificando uma posição ordinal. Isso é chamado de posicionamento absoluto.

> [!NOTE]
>  O posicionamento absoluto não está disponível em conjuntos de registros somente de encaminhamento. Para obter mais informações sobre conjuntos de registros somente de encaminhamento, consulte [Recordset (ODBC)](../../data/odbc/recordset-odbc.md).

Para mover o ponteiro de registro atual usando a posição absoluta, chame [CRecordset:: SetAbsolutePosition](../../mfc/reference/crecordset-class.md#setabsoluteposition). Quando você passa um valor para `SetAbsolutePosition`, o registro correspondente a essa posição ordinal se torna o registro atual.

> [!NOTE]
>  A posição absoluta de um registro é potencialmente não confiável. Se o usuário excluir registros do conjunto de registros, a posição ordinal de qualquer registro subsequente será alterada. Indicadores são o método recomendado para mover o registro atual. Para obter mais informações, consulte [indicadores no MFC ODBC](#_core_bookmarks_in_mfc_odbc).

Para obter mais informações sobre a navegação do conjunto de registros, consulte [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)
