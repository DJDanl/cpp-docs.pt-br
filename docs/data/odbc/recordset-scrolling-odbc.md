---
title: 'Conjunto de registros: Rolando (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 34dcfb9cb1d45710accba2ee6155e3c741b727be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recordset-scrolling-odbc"></a>Conjunto de registros: rolando (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Depois de abrir um conjunto de registros, você precisa para acessar os registros para exibir valores, cálculos, gerar relatórios e assim por diante. Permite que você mova de registro para registro em seu conjunto de registros de rolagem.  
  
 Este tópico explica:  
  
-   [Como rolar de um registro para outro em um conjunto de registros](#_core_scrolling_from_one_record_to_another).  
  
-   [Sob quais circunstâncias rolagem é e não há suporte para](#_core_when_scrolling_is_supported).  
  
##  <a name="_core_scrolling_from_one_record_to_another"></a>Rolagem de um registro para outro  
 Classe `CRecordset` fornece o **mover** funções de membro para rolar dentro de um conjunto de registros. Essas funções mover o registro atual por conjuntos de linhas. Se você tiver implementado em busca de linhas em massa, um **mover** operação reposiciona o conjunto de registros pelo tamanho do conjunto de linhas. Se você não tiver implementado linhas em massa buscar, uma chamada para um **mover** função reposiciona o conjunto de registros por um registro de cada vez. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
> [!NOTE]
>  Ao passar por meio de um conjunto de registros, registros excluídos não podem ser ignorados. Para obter mais informações, consulte o [IsDeleted](../../mfc/reference/crecordset-class.md#isdeleted) função de membro.  
  
 Além de **mover** funções, `CRecordset` fornece funções de membro para verificar se você percorreu após o final ou antes do início do seu conjunto de registros.  
  
 Para determinar se a rolagem é possível de registros, chame o `CanScroll` função de membro.  
  
#### <a name="to-scroll"></a>Para rolar  
  
1.  Encaminhar um registro ou um conjunto de linhas: chamar o [MoveNext](../../mfc/reference/crecordset-class.md#movenext) função de membro.  
  
2.  Um registro com versões anteriores ou um conjunto de linhas: chamar o [MovePrev](../../mfc/reference/crecordset-class.md#moveprev) função de membro.  
  
3.  Para o primeiro registro no conjunto de registros: chamar o [MoveFirst](../../mfc/reference/crecordset-class.md#movefirst) função de membro.  
  
4.  Para o último registro no conjunto de registros ou para o último conjunto de linhas: chamar o [MoveLast](../../mfc/reference/crecordset-class.md#movelast) função de membro.  
  
5.  *N* registros em relação à posição atual: chamar o [mover](../../mfc/reference/crecordset-class.md#move) função de membro.  
  
#### <a name="to-test-for-the-end-or-the-beginning-of-the-recordset"></a>Para testar o final ou início do conjunto de registros  
  
1.  Você percorreu além do último registro? Chamar o [IsEOF](../../mfc/reference/crecordset-class.md#iseof) função de membro.  
  
2.  Você percorreu antes do primeiro registro (Avançar)? Chamar o [IsBOF](../../mfc/reference/crecordset-class.md#isbof) função de membro.  
  
 O seguinte exemplo de código usa `IsBOF` e `IsEOF` para detectar os limites de um conjunto de registros durante a rolagem em qualquer direção.  
  
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
  
 `IsEOF`Retorna um valor diferente de zero se o conjunto de registros é posicionado após o último registro. `IsBOF`Retorna um valor diferente de zero se o conjunto de registros é posicionado antes do primeiro registro (antes de todos os registros). Em ambos os casos, não há nenhum registro atual para operar. Se você chamar `MovePrev` quando `IsBOF` já está **TRUE** ou chamar `MoveNext` quando `IsEOF` já **TRUE**, o framework lança uma `CDBException`. Você também pode usar `IsBOF` e `IsEOF` para verificar se há um conjunto de registros vazio.  
  
 Para obter mais informações sobre a navegação do conjunto de registros, consulte [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).  
  
##  <a name="_core_when_scrolling_is_supported"></a>Quando a rolagem é suportado  
 Como criado originalmente SQL fornecida roll-forward apenas, mas ODBC estende os recursos de rolagem. O nível de suporte para rolagem disponível depende de seu aplicativo funcione com nível de conformidade de ODBC API do driver, drivers de ODBC e se a biblioteca de cursores ODBC é carregada na memória. Para obter mais informações, consulte [ODBC](../../data/odbc/odbc-basics.md) e [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).  
  
> [!TIP]
>  Você pode controlar se a biblioteca de cursores é usada. Consulte o `bUseCursorLib` e `dwOptions` parâmetros para [CDatabase::Open](../../mfc/reference/cdatabase-class.md#open).  
  
> [!NOTE]
>  Ao contrário das classes DAO MFC, as classes MFC ODBC não fornecem um conjunto de **localizar** funções para localizar o registro seguinte (ou anterior) que atenda aos critérios especificados.  
  
## <a name="see-also"></a>Consulte também  
 [Conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md)   
 [CRecordset::CanScroll](../../mfc/reference/crecordset-class.md#canscroll)   
 [CRecordset::CheckRowsetError](../../mfc/reference/crecordset-class.md#checkrowseterror)   
 [Conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md)