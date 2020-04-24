---
title: Macros e globais de banco de dados
ms.date: 11/04/2016
f1_keywords:
- AFXDB/AFX_ODBC_CALL
- AFXDB/AFX_SQL_ASYNC
- AFXDB/AFX_SQL_SYNC
- AFXDB/AfxGetHENV
helpviewer_keywords:
- global database functions [MFC]
- database macros [MFC]
- database globals [MFC]
- global functions [MFC], database functions
- macros [MFC], MFC database
ms.assetid: 5b9b9e61-1cf9-4345-9f29-3807dd466488
ms.openlocfilehash: 6d8bd56c0bfe4f9b35e34d067dd1042ed11066d5
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751663"
---
# <a name="database-macros-and-globals"></a>Macros e globais de banco de dados

As macros e os globais listados abaixo aplicam-se a aplicativos de banco de dados baseados em ODBC. Eles não são usados com aplicativos baseados em DAO.

Antes do MFC 4.2, as macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` deram às operações assíncronas uma oportunidade de dar tempo a outros processos. A partir do MFC 4.2, a implementação dessas macros mudou porque as classes MFC ODBC usavam apenas operações síncronas. A `AFX_ODBC_CALL` macro era nova no MFC 4.2.

### <a name="database-macros"></a>Macros de banco de dados

|||
|-|-|
|[AFX_ODBC_CALL](#afx_odbc_call)|Chama uma função De PiPi `SQL_STILL_EXECUTING`ODBC que retorna . `AFX_ODBC_CALL`chamará repetidamente a função até `SQL_STILL_EXECUTING`que ela não retorne.|
|[AFX_SQL_ASYNC](#afx_sql_async)|Chama `AFX_ODBC_CALL`.|
|[AFX_SQL_SYNC](#afx_sql_sync)|Chama uma função API ODBC `SQL_STILL_EXECUTING`que não retorna .|

### <a name="database-globals"></a>Globals de banco de dados

|||
|-|-|
|[AfxDbInitModule](#afxdbinitmodule)|Adiciona suporte ao banco de dados para um DLL MFC regular que está dinamicamente ligado ao MFC.|
|[AfxGetHENV](#afxgethenv)|Recupera uma alça para o ambiente ODBC atualmente em uso pelo MFC. Você pode usar esta alça em chamadas Diretas ODBC.|

## <a name="afxdbinitmodule"></a><a name="afxdbinitmodule"></a>Módulo AfxDbInit

Para o suporte de banco de dados MFC (ou DAO) de uma DLL MFC regular que está dinamicamente ligada ao MFC, adicione uma chamada a esta função na função de `CWinApp::InitInstance` DLL do MFC regular para inicializar o DLL do banco de dados MFC.

### <a name="syntax"></a>Sintaxe

```cpp
void AFXAPI AfxDbInitModule( );
```

### <a name="remarks"></a>Comentários

Certifique-se de que essa chamada ocorra antes de qualquer chamada de classe base ou qualquer código adicionado que acesse o DLL do banco de dados MFC. O DLL do banco de dados MFC é uma DLL de extensão MFC; para que uma DLL de extensão `CDynLinkLibrary` MFC seja conectada `CDynLinkLibrary` a uma cadeia, ela deve criar um objeto no contexto de cada módulo que irá usá-lo. `AfxDbInitModule`cria `CDynLinkLibrary` o objeto no contexto do DLL MFC regular para `CDynLinkLibrary` que ele seja conectado à cadeia de objetos do DLL MFC regular.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** \<afxdll_.h>

## <a name="afx_odbc_call"></a><a name="afx_odbc_call"></a>Afx_odbc_call

Use esta macro para chamar qualquer função De `SQL_STILL_EXECUTING`PiA ODBC que possa retornar .

```
AFX_ODBC_CALL(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função API ODBC. Para obter mais informações sobre as funções da API do ODBC, consulte o Windows SDK.

### <a name="remarks"></a>Comentários

`AFX_ODBC_CALL`chama repetidamente a função até `SQL_STILL_EXECUTING`que ela não retorne mais .

Antes de `AFX_ODBC_CALL`invocar, você deve `nRetCode`declarar uma variável, do tipo RETCODE.

Observe que as classes MFC ODBC agora usam apenas processamento síncrono. Para realizar uma operação assíncrona, você deve chamar `SQLSetConnectOption`a função API oDBC . Para obter mais informações, consulte o tópico "Executando funções assíncronas" no SDK do Windows.

### <a name="example"></a>Exemplo

Este exemplo `AFX_ODBC_CALL` usa `SQLColumns` para chamar a função API ODBC, que retorna `strTableName`uma lista das colunas na tabela nomeada por . Observe a `nRetCode` declaração e o uso de membros de dados do conjunto de registros para passar parâmetros para a função. O exemplo também ilustra a verificação `Check`dos resultados da `CRecordset`chamada com , uma função membro de classe . A `prs` variável é um `CRecordset` ponteiro para um objeto, declarado em outro lugar.

[!code-cpp[NVC_MFCDatabase#39](../../mfc/codesnippet/cpp/database-macros-and-globals_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="afx_sql_async"></a><a name="afx_sql_async"></a>Afx_sql_async

A implementação desta macro mudou no MFC 4.2.

```
AFX_SQL_ASYNC(prs, SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*Prs*<br/>
Um ponteiro `CRecordset` para um `CDatabase` objeto ou um objeto. A partir do MFC 4.2, esse valor de parâmetro é ignorado.

*SQLFunc*<br/>
Uma função API ODBC. Para obter mais informações sobre as funções da API do ODBC, consulte o Windows SDK.

### <a name="remarks"></a>Comentários

`AFX_SQL_ASYNC`simplesmente chama o [macro AFX_ODBC_CALL](#afx_odbc_call) e ignora o parâmetro *prs.* Em versões de MFC `AFX_SQL_ASYNC` antes do 4.2, foi usado para `SQL_STILL_EXECUTING`chamar funções de API ODBC que poderiam retornar . Se uma função API ODBC retornasse, `SQL_STILL_EXECUTING`então `AFX_SQL_ASYNC` ligaria para `prs->OnWaitForDataSource`.

> [!NOTE]
> As classes MFC ODBC agora usam apenas processamento síncrono. Para realizar uma operação assíncrona, você deve chamar `SQLSetConnectOption`a função API oDBC . Para obter mais informações, consulte o tópico "Executando funções assíncronas" no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb.h

## <a name="afx_sql_sync"></a><a name="afx_sql_sync"></a>Afx_sql_sync

A `AFX_SQL_SYNC` macro simplesmente `SQLFunc`chama a função .

```
AFX_SQL_SYNC(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função API ODBC. Para obter mais informações sobre essas funções, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

Use esta macro para chamar funções de API ODBC que não retornarão `SQL_STILL_EXECUTING`.

Antes `AFX_SQL_SYNC`de ligar, você `nRetCode`deve declarar uma variável, do tipo RETCODE. Você pode verificar `nRetCode` o valor de após a chamada de macro.

Observe que a `AFX_SQL_SYNC` implementação do alterado no MFC 4.2. Como a verificação do status `AFX_SQL_SYNC` do servidor não `nRetCode`era mais necessária, basta atribuir um valor a . Por exemplo, em vez de fazer a chamada

[!code-cpp[NVC_MFCDatabase#40](../../mfc/codesnippet/cpp/database-macros-and-globals_2.cpp)]

você pode simplesmente fazer a atribuição

[!code-cpp[NVC_MFCDatabase#41](../../mfc/codesnippet/cpp/database-macros-and-globals_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb.h

## <a name="afxgethenv"></a><a name="afxgethenv"></a>AfxGetHENV

Você pode usar a alça retornada em chamadas Diretas ODBC, mas não deve fechar a `CDatabase`alça `CRecordset`ou assumir que a alça ainda está válida e disponível depois que quaisquer objetos existentes - ou derivados foram destruídos.

```
HENV AFXAPI AfxGetHENV();
```

### <a name="return-value"></a>Valor retornado

A alça para o ambiente ODBC atualmente em uso pelo MFC. Pode `SQL_HENV_NULL` ser se não houver objetos [CDatabase](../../mfc/reference/cdatabase-class.md) e nenhum [objeto CRecordset](../../mfc/reference/crecordset-class.md) em uso.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
