---
title: Macros e globais de banco de dados | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.data
dev_langs:
- C++
helpviewer_keywords:
- global database functions [C++]
- database macros [C++]
- database globals [C++]
- global functions [C++], database functions
- macros [C++], MFC database
ms.assetid: 5b9b9e61-1cf9-4345-9f29-3807dd466488
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 9706c47d9bd5996c28873da6a15a687bf9b5e038
ms.lasthandoff: 02/25/2017

---
# <a name="database-macros-and-globals"></a>Macros e globais de banco de dados
As macros e globais listadas abaixo se aplicam a aplicativos de banco de dados baseado em ODBC. Eles não são usados com aplicativos baseados em DAO.  
  
 Antes de MFC 4.2, as macros `AFX_SQL_ASYNC` e `AFX_SQL_SYNC` forneceu uma oportunidade para produzir o tempo para outros processos de operações assíncronas. Começando com o MFC 4.2, a implementação dessas macros alterado porque as classes MFC ODBC usado somente operações síncronas. A macro `AFX_ODBC_CALL` era nova para MFC 4.2.  
  
### <a name="database-macros"></a>Macros de banco de dados  
  
|||  
|-|-|  
|[AFX_ODBC_CALL](#afx_odbc_call)|Chama uma função de API ODBC retorna `SQL_STILL_EXECUTING`. `AFX_ODBC_CALL`repetidamente chamará a função até que ele não retorna `SQL_STILL_EXECUTING`.|  
|[AFX_SQL_ASYNC](#afx_sql_async)|Chama `AFX_ODBC_CALL`.|  
|[AFX_SQL_SYNC](#afx_sql_sync)|Chama uma função de API de ODBC que não retorne `SQL_STILL_EXECUTING`.|  
  
### <a name="database-globals"></a>Banco de dados globais  
  
|||  
|-|-|  
|[AfxGetHENV](#afxgethenv)|Recupera um identificador de ambiente ODBC atualmente em uso pelo MFC. Você pode usar esse identificador em chamadas diretas de ODBC.|  
  
##  <a name="a-nameafxodbccalla--afxodbccall"></a><a name="afx_odbc_call"></a>AFX_ODBC_CALL  
 Usar essa macro para chamar qualquer função de API ODBC que pode retornar `SQL_STILL_EXECUTING`.  
  
```  
AFX_ODBC_CALL(SQLFunc)  
```  
  
### <a name="parameters"></a>Parâmetros  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre funções de API de ODBC, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 `AFX_ODBC_CALL`chama repetidamente a função até que ele não retorna `SQL_STILL_EXECUTING`.  
  
 Antes de chamar `AFX_ODBC_CALL`, você deve declarar uma variável, `nRetCode`, do tipo **RETCODE**.  
  
 Observe que o ODBC do MFC classes processamento síncrono apenas do uso agora. Para executar uma operação assíncrona, você deve chamar a função ODBC API **SQLSetConnectOption**. Para obter mais informações, consulte o tópico "Executando funções assincronamente" o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  

  
### <a name="example"></a>Exemplo  
 Este exemplo usa `AFX_ODBC_CALL` para chamar o **SQLColumns** função da API do ODBC, que retorna uma lista das colunas na tabela chamada por `strTableName`. Observe a declaração da `nRetCode` e o uso de membros de dados do conjunto de registros para passar parâmetros para a função. O exemplo também ilustra os resultados da chamada com a verificação **verificar**, uma função de membro da classe `CRecordset`. A variável `prs` é um ponteiro para um `CRecordset` objeto, declarado em outro lugar.  
  
 [!code-cpp[NVC_MFCDatabase&#39;](../../mfc/codesnippet/cpp/database-macros-and-globals_1.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  

##  <a name="a-nameafxsqlasynca--afxsqlasync"></a><a name="afx_sql_async"></a>AFX_SQL_ASYNC  
 A implementação dessa macro alterado no MFC 4.2.  
  
```   
AFX_SQL_ASYNC(prs, SQLFunc)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `prs`  
 Um ponteiro para um `CRecordset` objeto ou um `CDatabase` objeto. A partir do MFC 4.2, esse valor de parâmetro é ignorado.  
  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre funções de API de ODBC, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 `AFX_SQL_ASYNC`simplesmente chama a macro [AFX_ODBC_CALL](#afx_odbc_call) e ignora o `prs` parâmetro. Em versões do MFC antes 4.2, `AFX_SQL_ASYNC` foi usado para chamar funções de API de ODBC que podem retornar `SQL_STILL_EXECUTING`. Se uma função de API de ODBC retornou `SQL_STILL_EXECUTING`, em seguida, `AFX_SQL_ASYNC` chamaria `prs->OnWaitForDataSource`.  
  
> [!NOTE]
>  As classes ODBC MFC agora usam processamento síncrono apenas. Para executar uma operação assíncrona, você deve chamar a função ODBC API **SQLSetConnectOption**. Para obter mais informações, consulte o tópico "Executando funções assincronamente" o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb. h  
  
##  <a name="a-nameafxsqlsynca--afxsqlsync"></a><a name="afx_sql_sync"></a>AFX_SQL_SYNC  
 O `AFX_SQL_SYNC` macro simplesmente chama a função `SQLFunc`.  
  
```   
AFX_SQL_SYNC(SQLFunc)   
```  
  
### <a name="parameters"></a>Parâmetros  
 `SQLFunc`  
 Uma função de API de ODBC. Para obter mais informações sobre essas funções, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Usar essa macro para chamar funções de API de ODBC não retornará `SQL_STILL_EXECUTING`.  
  
 Antes de chamar `AFX_SQL_SYNC`, você deve declarar uma variável, `nRetCode`, do tipo **RETCODE**. Você pode verificar o valor de `nRetCode` após a chamada de macro.  
  
 Observe que a implementação de `AFX_SQL_SYNC` alterado no MFC 4.2. Como verificar o status do servidor não era necessária, `AFX_SQL_SYNC` simplesmente atribui um valor para `nRetCode`. Por exemplo, em vez de fazer a chamada  
  
 [!code-cpp[40 NVC_MFCDatabase](../../mfc/codesnippet/cpp/database-macros-and-globals_2.cpp)]  
  
 Você pode simplesmente fazer a atribuição  
  
 [!code-cpp[41 NVC_MFCDatabase](../../mfc/codesnippet/cpp/database-macros-and-globals_3.cpp)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb. h  
  
##  <a name="a-nameafxgethenva--afxgethenv"></a><a name="afxgethenv"></a>AfxGetHENV  
 Você pode usar o identificador retornado em chamadas diretas de ODBC, mas você não deve fechar o identificador ou supõem que o identificador é ainda válido e disponível após qualquer existente `CDatabase`- ou `CRecordset`-objetos derivados tiverem sido destruídos.  
  
```   
HENV AFXAPI AfxGetHENV(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de ambiente ODBC atualmente em uso pelo MFC. Pode ser `SQL_HENV_NULL` se não houver nenhum [CDatabase](../../mfc/reference/cdatabase-class.md) objetos e não [CRecordset](../../mfc/reference/crecordset-class.md) objetos em uso.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdb. h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

