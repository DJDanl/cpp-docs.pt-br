---
title: Macros e globais de banco de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- AFXDB/AFX_ODBC_CALL
- AFXDB/AFX_SQL_ASYNC
- AFXDB/AFX_SQL_SYNC
- AFXDB/AfxGetHENV
dev_langs:
- C++
helpviewer_keywords:
- global database functions [MFC]
- database macros [MFC]
- database globals [MFC]
- global functions [MFC], database functions
- macros [MFC], MFC database
ms.assetid: 5b9b9e61-1cf9-4345-9f29-3807dd466488
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bcafff20ad79f68f2bb5d4195c38603da63b9d17
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33370767"
---
# <a name="database-macros-and-globals"></a>Macros e globais de banco de dados
As macros e globais listados a seguir se aplicam a aplicativos de banco de dados baseado em ODBC. Eles não são usados com aplicativos baseados em DAO.  
  
 Antes de MFC 4.2, as macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` forneceu uma oportunidade para produzir o tempo para outros processos de operações assíncronas. Começando com MFC 4.2, a implementação dessas macros alterado porque as classes MFC ODBC usado somente operações síncronas. A macro `AFX_ODBC_CALL` era nova para MFC 4.2.  
  
### <a name="database-macros"></a>Macros de banco de dados  
  
|||  
|-|-|  
|[AFX_ODBC_CALL](#afx_odbc_call)|Chama uma função de API de ODBC que retorna `SQL_STILL_EXECUTING`. `AFX_ODBC_CALL` repetidamente chamará a função até que ele não retorna `SQL_STILL_EXECUTING`.|  
|[AFX_SQL_ASYNC](#afx_sql_async)|Chama `AFX_ODBC_CALL`.|  
|[AFX_SQL_SYNC](#afx_sql_sync)|Chama uma função de API de ODBC que não retornam `SQL_STILL_EXECUTING`.|  
  
### <a name="database-globals"></a>Banco de dados globais  
  
|||  
|-|-| 
|[AfxDbInitModule](#afxdbinitmodule)|Adiciona suporte de banco de dados para uma DLL MFC regular vinculada dinamicamente a MFC.| 
|[AfxGetHENV](#afxgethenv)|Recupera um identificador para o ambiente de ODBC atualmente em uso pelo MFC. Você pode usar esse identificador em chamadas diretas de ODBC.|  


## <a name="afxdbinitmodule"></a> AfxDbInitModule
Banco de dados MFC (ou DAO) suporte de uma DLL MFC regular vinculada dinamicamente ao MFC, adicione uma chamada para essa função em seu MFC DLL regular **CWinApp::InitInstance** DLL de banco de dados de função para inicializar o MFC.  
   
### <a name="syntax"></a>Sintaxe    
```
void AFXAPI AfxDbInitModule( );    
```  
   
### <a name="remarks"></a>Comentários  
 Verifique se essa chamada ocorre antes de qualquer chamada de classe base ou qualquer código que acessa o banco de dados MFC DLL de adicionada. O banco de dados MFC DLL é uma extensão MFC DLL; em ordem para uma DLL de extensão do MFC para obter conectados com um **CDynLinkLibrary** cadeia, é necessário criar um **CDynLinkLibrary** objeto no contexto de cada módulo que estará usando. `AfxDbInitModule` cria o **CDynLinkLibrary** do objeto no contexto de seu MFC DLL regulares para que ele obtém conectado com o **CDynLinkLibrary** cadeia da DLL MFC regular do objeto.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** < afxdll_.h >  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)
 
  

##  <a name="afx_odbc_call"></a>  AFX_ODBC_CALL  
 Use esta macro para chamar qualquer função de API ODBC que pode retornar `SQL_STILL_EXECUTING`.  
  
```  
AFX_ODBC_CALL(SQLFunc)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre funções de API de ODBC, consulte o SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 `AFX_ODBC_CALL` chama repetidamente a função até que ele não retorna `SQL_STILL_EXECUTING`.  
  
 Antes de chamar `AFX_ODBC_CALL`, você deve declarar uma variável, `nRetCode`, do tipo **RETCODE**.  
  
 Observe que o ODBC MFC classes processamento síncrono somente de uso agora. Para executar uma operação assíncrona, você deve chamar a função de API ODBC **SQLSetConnectOption**. Para obter mais informações, consulte o tópico "Executando funções de forma assíncrona" no SDK do Windows.  

  
### <a name="example"></a>Exemplo  
 Este exemplo usa `AFX_ODBC_CALL` para chamar o **SQLColumns** função da API do ODBC, que retorna uma lista das colunas na tabela chamada por `strTableName`. Observe a declaração de `nRetCode` e o uso de membros de dados do conjunto de registros para passar parâmetros para a função. O exemplo também ilustra os resultados da chamada com a verificação **verificar**, uma função de membro de classe `CRecordset`. A variável `prs` é um ponteiro para um `CRecordset` objeto, declarado em outro lugar.  
  
 [!code-cpp[NVC_MFCDatabase#39](../../mfc/codesnippet/cpp/database-macros-and-globals_1.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb.h  

##  <a name="afx_sql_async"></a>  AFX_SQL_ASYNC  
 A implementação desta macro alterado no MFC 4.2.  
  
```   
AFX_SQL_ASYNC(prs, SQLFunc)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `prs`  
 Um ponteiro para um `CRecordset` objeto ou uma `CDatabase` objeto. A partir do MFC 4.2, esse valor de parâmetro é ignorado.  
  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre funções de API de ODBC, consulte o SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 `AFX_SQL_ASYNC` simplesmente chama a macro [AFX_ODBC_CALL](#afx_odbc_call) e ignora o `prs` parâmetro. Em versões do MFC antes 4.2, `AFX_SQL_ASYNC` foi usado para chamar funções API ODBC que podem retornar `SQL_STILL_EXECUTING`. Se uma função de API de ODBC retornou `SQL_STILL_EXECUTING`, em seguida, `AFX_SQL_ASYNC` chamaria `prs->OnWaitForDataSource`.  
  
> [!NOTE]
>  As classes MFC ODBC agora usam o processamento síncrono apenas. Para executar uma operação assíncrona, você deve chamar a função de API ODBC **SQLSetConnectOption**. Para obter mais informações, consulte o tópico "Executando funções de forma assíncrona" no SDK do Windows.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb.h  
  
##  <a name="afx_sql_sync"></a>  AFX_SQL_SYNC  
 O `AFX_SQL_SYNC` macro simplesmente chama a função `SQLFunc`.  
  
```   
AFX_SQL_SYNC(SQLFunc)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre essas funções, consulte o SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Use esta macro para chamar funções API ODBC não retornará `SQL_STILL_EXECUTING`.  
  
 Antes de chamar `AFX_SQL_SYNC`, você deve declarar uma variável, `nRetCode`, do tipo **RETCODE**. Você pode verificar o valor de `nRetCode` após a chamada de macro.  
  
 Observe que a implementação de `AFX_SQL_SYNC` alterado no MFC 4.2. Como verificar o status do servidor não era necessária, `AFX_SQL_SYNC` simplesmente atribui um valor para `nRetCode`. Por exemplo, em vez de fazer a chamada  
  
 [!code-cpp[NVC_MFCDatabase#40](../../mfc/codesnippet/cpp/database-macros-and-globals_2.cpp)]  
  
 Você pode simplesmente fazer a atribuição  
  
 [!code-cpp[NVC_MFCDatabase#41](../../mfc/codesnippet/cpp/database-macros-and-globals_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb.h  
  
##  <a name="afxgethenv"></a>  AfxGetHENV  
 Você pode usar o identificador retornado em chamadas diretas de ODBC, mas você não deve fechar o identificador ou suponha que o identificador seja ainda válido e disponível após qualquer existente `CDatabase`- ou `CRecordset`-objetos derivados tiverem sido destruídos.  
  
```   
HENV AFXAPI AfxGetHENV(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de ambiente ODBC atualmente em uso pelo MFC. Pode ser `SQL_HENV_NULL` se não houver nenhum [CDatabase](../../mfc/reference/cdatabase-class.md) objetos e nenhum [CRecordset](../../mfc/reference/crecordset-class.md) objetos em uso.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
