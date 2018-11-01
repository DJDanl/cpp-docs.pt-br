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
ms.openlocfilehash: d3df96c92c39b9fdc05a019ed1ada033dc36d05e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536546"
---
# <a name="database-macros-and-globals"></a>Macros e globais de banco de dados

As macros e globals listados abaixo se aplicam a aplicativos de banco de dados baseado em ODBC. Eles não são usados com aplicativos baseados em DAO.

Antes de MFC 4.2, as macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` deu uma oportunidade para produzir o tempo para outros processos de operações assíncronas. Começando com o 4.2 do MFC, a implementação dessas macros alterado porque as classes MFC ODBC usado somente operações síncronas. A macro `AFX_ODBC_CALL` era novato 4.2 do MFC.

### <a name="database-macros"></a>Macros de banco de dados

|||
|-|-|
|[AFX_ODBC_CALL](#afx_odbc_call)|Chama uma função de API do ODBC que retorna `SQL_STILL_EXECUTING`. `AFX_ODBC_CALL` repetidamente chamará a função até que ele não retorna `SQL_STILL_EXECUTING`.|
|[AFX_SQL_ASYNC](#afx_sql_async)|Chama `AFX_ODBC_CALL`.|
|[AFX_SQL_SYNC](#afx_sql_sync)|Chama uma função de API do ODBC que não retorna `SQL_STILL_EXECUTING`.|

### <a name="database-globals"></a>Banco de dados globais

|||
|-|-|
|[AfxDbInitModule](#afxdbinitmodule)|Adiciona o suporte de banco de dados para uma DLL MFC regular vinculada dinamicamente ao MFC.|
|[AfxGetHENV](#afxgethenv)|Recupera um identificador para o ambiente de ODBC atualmente em uso pelo MFC. Você pode usar esse identificador em chamadas diretas de ODBC.|

## <a name="afxdbinitmodule"></a> AfxDbInitModule

Para suporte do banco de dados MFC (ou DAO) de uma DLL MFC regular vinculada dinamicamente ao MFC, adicione uma chamada para essa função em seu MFC DLL regular `CWinApp::InitInstance` função para inicializar o MFC DLL de banco de dados.

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxDbInitModule( );
```

### <a name="remarks"></a>Comentários

Verifique se essa chamada ocorre antes de qualquer chamada de classe base ou qualquer adicionou o código que acessa o banco de dados do MFC DLL. O banco de dados do MFC DLL é uma extensão MFC DLL; para que uma DLL de extensão do MFC obter conectados com um `CDynLinkLibrary` cadeia, ele deve criar um `CDynLinkLibrary` objeto no contexto de cada módulo que irá usá-lo. `AfxDbInitModule` cria o `CDynLinkLibrary` do objeto no contexto de seu MFC DLL regulares, de modo que ele obtém conectados com o `CDynLinkLibrary` cadeia da DLL da MFC regular do objeto.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** \<afxdll_.h >

### <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)

##  <a name="afx_odbc_call"></a>  AFX_ODBC_CALL

Usar essa macro para chamar qualquer função de API ODBC que pode retornar `SQL_STILL_EXECUTING`.

```
AFX_ODBC_CALL(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função de API do ODBC. Para obter mais informações sobre as funções de API do ODBC, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

`AFX_ODBC_CALL` repetidamente chama a função até que ele não retorna `SQL_STILL_EXECUTING`.

Antes de invocar `AFX_ODBC_CALL`, você deve declarar uma variável, `nRetCode`, do tipo RETCODE.

Observe que o ODBC do MFC classes processamento síncrono somente de uso agora. Para executar uma operação assíncrona, você deve chamar a função ODBC API `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "Executando funções assincronamente" no SDK do Windows.

### <a name="example"></a>Exemplo

Este exemplo usa `AFX_ODBC_CALL` para chamar o `SQLColumns` função de API do ODBC, que retorna uma lista das colunas na tabela chamada pelo `strTableName`. Observe a declaração da `nRetCode` e o uso de membros de dados do conjunto de registros para passar parâmetros para a função. O exemplo também ilustra os resultados da chamada com a verificação `Check`, uma função de membro de classe `CRecordset`. A variável `prs` é um ponteiro para um `CRecordset` objeto, declarado em outro lugar.

[!code-cpp[NVC_MFCDatabase#39](../../mfc/codesnippet/cpp/database-macros-and-globals_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb. h

##  <a name="afx_sql_async"></a>  AFX_SQL_ASYNC

A implementação dessa macro alterado no MFC 4.2.

```
AFX_SQL_ASYNC(prs, SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*solicitações de pull*<br/>
Um ponteiro para um `CRecordset` objeto ou um `CDatabase` objeto. Começando com o MFC 4.2, esse valor de parâmetro é ignorado.

*SQLFunc*<br/>
Uma função de API do ODBC. Para obter mais informações sobre as funções de API do ODBC, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

`AFX_SQL_ASYNC` simplesmente chama a macro [AFX_ODBC_CALL](#afx_odbc_call) e ignora a *prs* parâmetro. Em versões do MFC anteriores 4.2, `AFX_SQL_ASYNC` foi usado para chamar funções API ODBC que podem retornar `SQL_STILL_EXECUTING`. Se uma função de API ODBC retornou `SQL_STILL_EXECUTING`, em seguida, `AFX_SQL_ASYNC` chamaria `prs->OnWaitForDataSource`.

> [!NOTE]
>  As classes ODBC MFC agora usam processamento síncrono apenas. Para executar uma operação assíncrona, você deve chamar a função ODBC API `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "Executando funções assincronamente" no SDK do Windows.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb. h

##  <a name="afx_sql_sync"></a>  AFX_SQL_SYNC

O `AFX_SQL_SYNC` macro simplesmente chama a função `SQLFunc`.

```
AFX_SQL_SYNC(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função de API do ODBC. Para obter mais informações sobre essas funções, consulte o SDK do Windows.

### <a name="remarks"></a>Comentários

Usar essa macro para chamar funções API ODBC que não retornará `SQL_STILL_EXECUTING`.

Antes de chamar `AFX_SQL_SYNC`, você deve declarar uma variável, `nRetCode`, do tipo RETCODE. Você pode verificar o valor de `nRetCode` após a chamada de macro.

Observe que a implementação de `AFX_SQL_SYNC` alterado no MFC 4.2. Porque não era necessária, verificar o status do servidor `AFX_SQL_SYNC` simplesmente atribui um valor a ser `nRetCode`. Por exemplo, em vez de fazer a chamada

[!code-cpp[NVC_MFCDatabase#40](../../mfc/codesnippet/cpp/database-macros-and-globals_2.cpp)]

Você pode simplesmente fazer a atribuição

[!code-cpp[NVC_MFCDatabase#41](../../mfc/codesnippet/cpp/database-macros-and-globals_3.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb. h

##  <a name="afxgethenv"></a>  AfxGetHENV

Você pode usar o identificador retornado em chamadas diretas de ODBC, mas você não deve fechar o identificador ou pressupõem que o identificador ainda é válido e disponível depois de todos os existentes `CDatabase`- ou `CRecordset`-objetos derivados tenham sido destruídos.

```
HENV AFXAPI AfxGetHENV();
```

### <a name="return-value"></a>Valor de retorno

O identificador para o ambiente de ODBC atualmente em uso pelo MFC. Pode ser `SQL_HENV_NULL` se não houver nenhum [CDatabase](../../mfc/reference/cdatabase-class.md) objetos e nenhum [CRecordset](../../mfc/reference/crecordset-class.md) objetos em uso.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdb. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
