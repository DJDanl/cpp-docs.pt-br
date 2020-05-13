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
ms.openlocfilehash: 931051296dff495939fcbd894102a1b00e48ee90
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366935"
---
# <a name="recordset-scrolling-odbc"></a>Conjunto de registros: rolando (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Depois de abrir um conjunto de registros, você precisa acessar os registros para exibir valores, fazer cálculos, gerar relatórios e assim por diante. A rolagem permite que você se mova do registro para o registro dentro do seu conjunto de registros.

Este tópico explica:

- [Como rolar de um disco para outro em um conjunto de discos](#_core_scrolling_from_one_record_to_another).

- [Sob quais circunstâncias a rolagem é e não é suportada.](#_core_when_scrolling_is_supported)

## <a name="scrolling-from-one-record-to-another"></a><a name="_core_scrolling_from_one_record_to_another"></a>Rolando de um registro para outro

A `CRecordset` classe `Move` fornece as funções do membro para rolagem dentro de um conjunto de registros. Essas funções movem o registro atual por conjuntos de linhas. Se você tiver implementado a `Move` busca em linha em massa, uma operação reposicionará o conjunto de registros pelo tamanho do conjunto de linhas. Se você não tiver implementado a busca `Move` de linha em massa, uma chamada para uma função reposiciona o conjunto de registros por um registro cada vez. Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!NOTE]
> Ao passar por um conjunto de registros, os registros excluídos podem não ser ignorados. Para obter mais informações, consulte a função [membro IsDeleted.](../../mfc/reference/crecordset-class.md#isdeleted)

Além das `Move` funções, `CRecordset` fornece funções de membro para verificar se você já rolou além do final ou antes do início do seu conjunto de registros.

Para determinar se a rolagem é possível `CanScroll` no seu conjunto de registros, ligue para a função membro.

#### <a name="to-scroll"></a>Para rolar

1. Adiante um registro ou um conjunto de linhas: chame a função de membro [MoveNext.](../../mfc/reference/crecordset-class.md#movenext)

1. Para trás um registro ou um conjunto de linhas: chame a função de membro [do MovePrev.](../../mfc/reference/crecordset-class.md#moveprev)

1. Para o primeiro registro no conjunto de registros: chame a função de membro [MoveFirst.](../../mfc/reference/crecordset-class.md#movefirst)

1. Até o último registro no conjunto de registros ou no último conjunto de linhas: chame a função de membro [MoverLast.](../../mfc/reference/crecordset-class.md#movelast)

1. *N* registros relativos à posição atual: ligue para a função [Mover](../../mfc/reference/crecordset-class.md#move) membro.

#### <a name="to-test-for-the-end-or-the-beginning-of-the-recordset"></a>Para testar para o final ou o início do conjunto de registros

1. Você passou pelo último disco? Ligue para a função de membro [IsEOF.](../../mfc/reference/crecordset-class.md#iseof)

1. Você já rolou à frente do primeiro disco (movendo-se para trás)? Ligue para a função de membro [IsBOF.](../../mfc/reference/crecordset-class.md#isbof)

O exemplo de `IsBOF` `IsEOF` código a seguir usa e para detectar os limites de um conjunto de registros ao rolar em qualquer direção.

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

`IsEOF`retorna um valor não zero se o conjunto de registros estiver posicionado após o último registro. `IsBOF`retorna um valor não zero se o conjunto de registros estiver posicionado antes do primeiro registro (antes de todos os registros). Em ambos os casos, não há registro atual para operar. Se você `MovePrev` `IsBOF` ligar quando já `MoveNext` `IsEOF` é TRUE ou chamar `CDBException`quando já é TRUE, a estrutura lança um . Você também `IsBOF` pode `IsEOF` usar e verificar se há um conjunto de registros vazio.

Para obter mais informações sobre navegação no conjunto de registros, consulte [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

## <a name="when-scrolling-is-supported"></a><a name="_core_when_scrolling_is_supported"></a>Quando a rolagem é suportada

Como originalmente projetado, o SQL forneceu apenas rolagem para frente, mas o ODBC estende os recursos de rolagem. O nível de suporte disponível para rolagem depende dos drivers ODBC com os que seu aplicativo trabalha, do nível de conformidade da API oDBC do driver e se a Biblioteca Cursor ODBC está carregada na memória. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [ODBC: The ODBC Cursor Library](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!TIP]
> Você pode controlar se a biblioteca do cursor é usada. Consulte os parâmetros *bUseCursorLib* e *dwOptions* em [CDatabase::Open](../../mfc/reference/cdatabase-class.md#open).

> [!NOTE]
> Ao contrário das classes DaO do MFC, as classes `Find` MFC ODBC não fornecem um conjunto de funções para localizar o próximo (ou anterior) registro que atenda aos critérios especificados.

## <a name="see-also"></a>Confira também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[Configuração de registro de c::CanScroll](../../mfc/reference/crecordset-class.md#canscroll)<br/>
[CRecordset::Verificação'sRow'sError](../../mfc/reference/crecordset-class.md#checkrowseterror)<br/>
[Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)
