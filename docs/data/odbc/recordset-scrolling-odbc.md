---
title: 'Conjunto de registros: rolando (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- recordsets [C++], end of
- recordsets [C++], beginning of
- navigation [C++], recordsets
- recordsets [C++], moving to records
- ODBC recordsets, scrolling
- recordsets [C++], navigating
- scrolling [C++], recordsets
- Move method (recordsets)
ms.assetid: f38d2dcb-1e88-4e41-af25-98b00c276be4
ms.openlocfilehash: 8a8305d2acacc79f5d7fe395087a0bd13dcbd196
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212765"
---
# <a name="recordset-scrolling-odbc"></a>Conjunto de registros: rolando (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Depois de abrir um conjunto de registros, você precisará acessar os registros para exibir valores, fazer cálculos, gerar relatórios e assim por diante. A rolagem permite que você mova de registro para registro dentro do conjunto de registros.

Este tópico explica:

- [Como rolar de um registro para outro em um conjunto de registros](#_core_scrolling_from_one_record_to_another).

- [Em que circunstâncias a rolagem é e não tem suporte](#_core_when_scrolling_is_supported).

##  <a name="scrolling-from-one-record-to-another"></a><a name="_core_scrolling_from_one_record_to_another"></a>Rolando de um registro para outro

A classe `CRecordset` fornece as funções de membro de `Move` para rolar dentro de um conjunto de registros. Essas funções movem o registro atual por conjuntos de linhas. Se você tiver implementado a busca de linha em massa, uma operação `Move` reposicionará o conjunto de registros pelo tamanho do conjunto de linhas. Se você não tiver implementado a busca de linha em massa, uma chamada para uma função `Move` reposicionará o conjunto de registros por um registro a cada vez. Para obter mais informações sobre a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!NOTE]
>  Ao se mover por um conjunto de registros, os registros excluídos podem não ser ignorados. Para obter mais informações, consulte a função membro [IsDeleted](../../mfc/reference/crecordset-class.md#isdeleted) .

Além das funções de `Move`, `CRecordset` fornece funções de membro para verificar se você rolou após o final ou antes do início do conjunto de registros.

Para determinar se a rolagem é possível em seu conjunto de registros, chame a função de membro `CanScroll`.

#### <a name="to-scroll"></a>Para rolar

1. Encaminhar um registro ou um conjunto de linhas: chame a função de membro [MoveNext](../../mfc/reference/crecordset-class.md#movenext) .

1. Um registro ou um conjunto de linhas para trás: chame a função membro [MovePrev](../../mfc/reference/crecordset-class.md#moveprev) .

1. Para o primeiro registro no conjunto de registros: chame a função de membro [MoveFirst](../../mfc/reference/crecordset-class.md#movefirst) .

1. Para o último registro no conjunto de registros ou para o último conjunto de linhas: chame a função de membro [MoveLast](../../mfc/reference/crecordset-class.md#movelast) .

1. *N* registros relativos à posição atual: chame a função de membro [move](../../mfc/reference/crecordset-class.md#move) .

#### <a name="to-test-for-the-end-or-the-beginning-of-the-recordset"></a>Para testar o final ou o início do conjunto de registros

1. Você rolou para depois do último registro? Chame a função de membro [IsEOF](../../mfc/reference/crecordset-class.md#iseof) .

1. Você rolou para frente do primeiro registro (movendo para trás)? Chame a função de membro [IsBOF](../../mfc/reference/crecordset-class.md#isbof) .

O exemplo de código a seguir usa `IsBOF` e `IsEOF` para detectar os limites de um conjunto de registros durante a rolagem em qualquer direção.

```
// Open a recordset; first record is current
CCustSet rsCustSet( NULL );
rsCustSet.Open( );

if( rsCustSet.IsBOF( ) )
    return;
    // The recordset is empty

// Scroll to the end of the recordset, past
// the last record, so no record is current
while ( !rsCustSet.IsEOF( ) )
    rsCustSet.MoveNext( );

// Move to the last record
rsCustSet.MoveLast( );

// Scroll to beginning of the recordset, before
// the first record, so no record is current
while( !rsCustSet.IsBOF( ) )
    rsCustSet.MovePrev( );

// First record is current again
rsCustSet.MoveFirst( );
```

`IsEOF` retornará um valor diferente de zero se o conjunto de registros estiver posicionado após o último registro. `IsBOF` retornará um valor diferente de zero se o conjunto de registros estiver posicionado antes do primeiro registro (antes de todos os registros). Em ambos os casos, não há nenhum registro atual no qual operar. Se você chamar `MovePrev` quando `IsBOF` já for TRUE ou chamar `MoveNext` quando `IsEOF` já for TRUE, a estrutura lançará uma `CDBException`. Você também pode usar `IsBOF` e `IsEOF` para verificar um conjunto de registros vazio.

Para obter mais informações sobre a navegação do conjunto de registros, consulte [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

##  <a name="when-scrolling-is-supported"></a><a name="_core_when_scrolling_is_supported"></a>Quando há suporte para rolagem

Como originalmente criado, o SQL fornecia apenas rolagem posterior, mas o ODBC estende os recursos de rolagem. O nível de suporte disponível para rolagem depende dos drivers ODBC com os quais seu aplicativo funciona, o nível de conformidade da API ODBC do driver e se a biblioteca de cursores ODBC está carregada na memória. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!TIP]
>  Você pode controlar se a biblioteca de cursores é usada. Consulte os parâmetros *bUseCursorLib* e *dwOptions* para [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open).

> [!NOTE]
>  Ao contrário das classes do MFC DAO, as classes ODBC do MFC não fornecem um conjunto de funções `Find` para localizar o próximo registro (ou anterior) que atenda aos critérios especificados.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[CRecordset:: canrole](../../mfc/reference/crecordset-class.md#canscroll)<br/>
[CRecordset::CheckRowsetError](../../mfc/reference/crecordset-class.md#checkrowseterror)<br/>
[Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
