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
ms.openlocfilehash: e41b526b86922bafd1d923fa5848a5ef8ed4825e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50579578"
---
# <a name="recordset-scrolling-odbc"></a>Conjunto de registros: rolando (ODBC)

Este tópico se aplica às classes ODBC do MFC.

Depois de abrir um conjunto de registros, você precisa para acessar os registros para exibir os valores, fazer cálculos, gerar relatórios e assim por diante. Rolagem permite que mover de registro para registro em seu conjunto de registros.

Este tópico explica:

- [Como rolar de um registro para outro em um conjunto de registros](#_core_scrolling_from_one_record_to_another).

- [Sob quais circunstâncias de rolagem é e não há suporte para](#_core_when_scrolling_is_supported).

##  <a name="_core_scrolling_from_one_record_to_another"></a> Rolagem de um registro para outro

Classe `CRecordset` fornece o `Move` funções de membro para rolagem dentro de um conjunto de registros. Essas funções mover conjuntos de linhas do registro atual. Se você tiver implementado a busca de linhas em massa, um `Move` operação reposiciona o conjunto de registros pelo tamanho do conjunto de linhas. Se você não tiver implementado linhas em massa buscando uma chamada para um `Move` função reposiciona o conjunto de registros por um registro de cada vez. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!NOTE]
>  Ao mover por meio de um conjunto de registros, registros excluídos não podem ser ignorados. Para obter mais informações, consulte o [IsDeleted](../../mfc/reference/crecordset-class.md#isdeleted) função de membro.

Além de `Move` funções, `CRecordset` fornece funções de membro para verificar se você percorreu após o término ou à frente do início do seu conjunto de registros.

Para determinar se a rolagem é possível no seu conjunto de registros, chame o `CanScroll` função de membro.

#### <a name="to-scroll"></a>Para rolar

1. Encaminhar um registro ou um conjunto de linhas: chamar o [MoveNext](../../mfc/reference/crecordset-class.md#movenext) função de membro.

1. Um registro com versões anteriores ou um conjunto de linhas: chamar o [MovePrev](../../mfc/reference/crecordset-class.md#moveprev) função de membro.

1. Para o primeiro registro no conjunto de registros: chamar o [MoveFirst](../../mfc/reference/crecordset-class.md#movefirst) função de membro.

1. Para o último registro no conjunto de registros ou para o último conjunto de linhas: chamar o [MoveLast](../../mfc/reference/crecordset-class.md#movelast) função de membro.

1. *N* registros em relação à posição atual: chamar o [mover](../../mfc/reference/crecordset-class.md#move) função de membro.

#### <a name="to-test-for-the-end-or-the-beginning-of-the-recordset"></a>Para testar se o final ou início do conjunto de registros

1. Você percorreu além do último registro? Chame o [IsEOF](../../mfc/reference/crecordset-class.md#iseof) função de membro.

1. Você percorreu à frente do primeiro registro (mover para trás)? Chame o [IsBOF](../../mfc/reference/crecordset-class.md#isbof) função de membro.

O seguinte exemplo de código usa `IsBOF` e `IsEOF` para detectar os limites de um conjunto de registros ao rolar em qualquer direção.

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

`IsEOF` Retorna um valor diferente de zero se o conjunto de registros é posicionado após o último registro. `IsBOF` Retorna um valor diferente de zero se o conjunto de registros é posicionado antes do primeiro registro (antes de todos os registros). Em ambos os casos, não há nenhum registro atual no qual operar. Se você chamar `MovePrev` quando `IsBOF` é já TRUE ou chamar `MoveNext` quando `IsEOF` já for TRUE, o framework lança uma `CDBException`. Você também pode usar `IsBOF` e `IsEOF` para verificar se há um conjunto de registros vazio.

Para obter mais informações sobre navegação de conjunto de registros, consulte [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

##  <a name="_core_when_scrolling_is_supported"></a> Quando a rolagem é suportada

Como foi criado originalmente, SQL fornecido apenas roll-forward, mas ODBC estende os recursos de rolagem. O nível de suporte para rolagem disponível depende dos drivers ODBC, o aplicativo funciona com nível de conformidade do seu driver ODBC API, e se a biblioteca de cursores ODBC é carregada na memória. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

> [!TIP]
>  Você pode controlar se a biblioteca de cursores é usada. Consulte a *bUseCursorLib* e *dwOptions* parâmetros a serem [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open).

> [!NOTE]
>  Ao contrário das classes DAO MFC, as classes MFC ODBC não fornecem um conjunto de `Find` funções para localizar o registro seguinte (ou anterior) que atenda aos critérios especificados.

## <a name="see-also"></a>Consulte também

[Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)<br/>
[CRecordset::CanScroll](../../mfc/reference/crecordset-class.md#canscroll)<br/>
[CRecordset::CheckRowsetError](../../mfc/reference/crecordset-class.md#checkrowseterror)<br/>
[Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)