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
ms.openlocfilehash: 47a1bb434801c24ab8eee048d9ef8f93793101cc
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866644"
---
# <a name="database-macros-and-globals"></a>Macros e globais de banco de dados

As macros e globais listadas abaixo se aplicam a aplicativos de banco de dados baseados em ODBC. Eles não são usados com aplicativos baseados em DAO.

Antes do MFC 4,2, as macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` forneciam operações assíncronas a oportunidade de gerar tempo para outros processos. A partir do MFC 4,2, a implementação dessas macros mudou porque as classes ODBC do MFC usaram apenas operações síncronas. A macro `AFX_ODBC_CALL` era nova no MFC 4,2.

### <a name="database-macros"></a>Macros do banco de dados

|||
|-|-|
|[AFX_ODBC_CALL](#afx_odbc_call)|Chama uma função de API ODBC que retorna `SQL_STILL_EXECUTING`. `AFX_ODBC_CALL` chamará repetidamente a função até não retornar mais `SQL_STILL_EXECUTING`.|
|[AFX_SQL_ASYNC](#afx_sql_async)|Chama `AFX_ODBC_CALL`.|
|[AFX_SQL_SYNC](#afx_sql_sync)|Chama uma função de API ODBC que não retorna `SQL_STILL_EXECUTING`.|

### <a name="database-globals"></a>Globais do banco de dados

|||
|-|-|
|[AfxDbInitModule](#afxdbinitmodule)|Adiciona suporte a banco de dados para uma DLL do MFC regular que é vinculada dinamicamente ao MFC.|
|[AfxGetHENV](#afxgethenv)|Recupera um identificador para o ambiente ODBC atualmente em uso pelo MFC. Você pode usar esse identificador em chamadas diretas ODBC.|

## <a name="afxdbinitmodule"></a>AfxDbInitModule

Para suporte do banco de dados MFC (ou DAO) de uma DLL do MFC regular que é vinculada dinamicamente ao MFC, adicione uma chamada para essa função na função `CWinApp::InitInstance` da DLL do MFC regular para inicializar a DLL do banco de dados MFC.

### <a name="syntax"></a>Sintaxe

```
void AFXAPI AfxDbInitModule( );
```

### <a name="remarks"></a>Comentários

Certifique-se de que essa chamada ocorra antes de qualquer chamada de classe base ou qualquer código adicionado que acesse a DLL do banco de dados MFC. A DLL do banco de dados do MFC é uma DLL de extensão do MFC; para que uma DLL de extensão do MFC seja conectada a uma cadeia de `CDynLinkLibrary`, ela deve criar um objeto `CDynLinkLibrary` no contexto de cada módulo que a utilizará. `AfxDbInitModule` cria o objeto de `CDynLinkLibrary` no contexto da DLL do MFC regular para que ele seja conectado à cadeia de objetos `CDynLinkLibrary` da DLL do MFC regular.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** \<afxdll_. h >

##  <a name="afx_odbc_call"></a>AFX_ODBC_CALL

Use esta macro para chamar qualquer função da API ODBC que possa retornar `SQL_STILL_EXECUTING`.

```
AFX_ODBC_CALL(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função de API ODBC. Para obter mais informações sobre funções de API ODBC, consulte a SDK do Windows.

### <a name="remarks"></a>Comentários

`AFX_ODBC_CALL` chama repetidamente a função até não retornar mais `SQL_STILL_EXECUTING`.

Antes de invocar `AFX_ODBC_CALL`, você deve declarar uma variável, `nRetCode`, do tipo RETCODE.

Observe que as classes ODBC do MFC agora usam apenas o processamento síncrono. Para executar uma operação assíncrona, você deve chamar a função da API do ODBC `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "executando funções de forma assíncrona" no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo usa `AFX_ODBC_CALL` para chamar a função de API `SQLColumns` ODBC, que retorna uma lista das colunas na tabela nomeada por `strTableName`. Observe a declaração de `nRetCode` e o uso de membros de dados do conjunto de registros para passar parâmetros para a função. O exemplo também ilustra a verificação dos resultados da chamada com `Check`, uma função de membro da classe `CRecordset`. A variável `prs` é um ponteiro para um objeto `CRecordset`, declarado em outro lugar.

[!code-cpp[NVC_MFCDatabase#39](../../mfc/codesnippet/cpp/database-macros-and-globals_1.cpp)]

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDB. h

##  <a name="afx_sql_async"></a>AFX_SQL_ASYNC

A implementação dessa macro foi alterada no MFC 4,2.

```
AFX_SQL_ASYNC(prs, SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*PRS*<br/>
Um ponteiro para um objeto `CRecordset` ou um objeto `CDatabase`. A partir do MFC 4,2, esse valor de parâmetro é ignorado.

*SQLFunc*<br/>
Uma função de API ODBC. Para obter mais informações sobre funções de API ODBC, consulte a SDK do Windows.

### <a name="remarks"></a>Comentários

`AFX_SQL_ASYNC` simplesmente chama a macro [AFX_ODBC_CALL](#afx_odbc_call) e ignora o parâmetro *PRS* . Em versões do MFC anteriores a 4,2, `AFX_SQL_ASYNC` foi usada para chamar funções da API do ODBC que podem retornar `SQL_STILL_EXECUTING`. Se uma função de API ODBC retornar `SQL_STILL_EXECUTING`, `AFX_SQL_ASYNC` chamaria `prs->OnWaitForDataSource`.

> [!NOTE]
>  As classes ODBC do MFC agora usam apenas o processamento síncrono. Para executar uma operação assíncrona, você deve chamar a função da API do ODBC `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "executando funções de forma assíncrona" no SDK do Windows.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** AFXDB. h

##  <a name="afx_sql_sync"></a>AFX_SQL_SYNC

A macro `AFX_SQL_SYNC` simplesmente chama a função `SQLFunc`.

```
AFX_SQL_SYNC(SQLFunc)
```

### <a name="parameters"></a>Parâmetros

*SQLFunc*<br/>
Uma função de API ODBC. Para obter mais informações sobre essas funções, consulte a SDK do Windows.

### <a name="remarks"></a>Comentários

Use esta macro para chamar funções da API ODBC que não retornarão `SQL_STILL_EXECUTING`.

Antes de chamar `AFX_SQL_SYNC`, você deve declarar uma variável, `nRetCode`, do tipo RETCODE. Você pode verificar o valor de `nRetCode` após a chamada de macro.

Observe que a implementação de `AFX_SQL_SYNC` alterada no MFC 4,2. Como a verificação do status do servidor não era mais necessária, `AFX_SQL_SYNC` simplesmente atribui um valor a `nRetCode`. Por exemplo, em vez de fazer a chamada

[!code-cpp[NVC_MFCDatabase#40](../../mfc/codesnippet/cpp/database-macros-and-globals_2.cpp)]

Você pode simplesmente fazer a atribuição

[!code-cpp[NVC_MFCDatabase#41](../../mfc/codesnippet/cpp/database-macros-and-globals_3.cpp)]

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** AFXDB. h

##  <a name="afxgethenv"></a>AfxGetHENV

Você pode usar o identificador retornado em chamadas ODBC diretas, mas não deve fechar o identificador ou supor que o identificador ainda é válido e disponível depois que quaisquer objetos derivados de `CDatabase`ou `CRecordset`existentes tiverem sido destruídos.

```
HENV AFXAPI AfxGetHENV();
```

### <a name="return-value"></a>Valor retornado

O identificador para o ambiente ODBC atualmente em uso pelo MFC. Pode ser `SQL_HENV_NULL` se não houver nenhum objeto [CDatabase](../../mfc/reference/cdatabase-class.md) e nenhum objeto [CRecordset](../../mfc/reference/crecordset-class.md) em uso.

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

  **Cabeçalho** AFXDB. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
