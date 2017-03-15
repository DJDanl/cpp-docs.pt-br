---
title: Classe CDBException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDBException
dev_langs:
- C++
helpviewer_keywords:
- CDBException class
- exceptions [C++], database
- database exceptions [C++]
- ODBC classes [C++], exceptions
- errors [C++], database
ms.assetid: eb9e1119-89f5-49a7-b9d4-b91cee1ccc82
caps.latest.revision: 23
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: fc3bf7be273bf509dd1ee79fb42e69050070e830
ms.lasthandoff: 02/25/2017

---
# <a name="cdbexception-class"></a>Classe CDBException
Representa uma condição de exceção decorrentes de classes de banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDBException : public CException  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDBException::m_nRetCode](#m_nretcode)|Contém um código de retorno de conectividade de banco de dados aberto (ODBC), do tipo **RETCODE**.|  
|[CDBException::m_strError](#m_strerror)|Contém uma cadeia de caracteres que descreve o erro em termos de alfanuméricos.|  
|[CDBException::m_strStateNativeOrigin](#m_strstatenativeorigin)|Contém uma cadeia de caracteres que descreve o erro em termos de códigos de erro retornado pelo ODBC.|  
  
## <a name="remarks"></a>Comentários  
 A classe inclui dois membros de dados públicos que você pode usar para determinar a causa da exceção ou exibir uma mensagem de texto que descreve a exceção. `CDBException`objetos são construídos e gerados pelas funções de membro das classes de banco de dados.  
  
> [!NOTE]
>  Essa classe é uma das classes de conectividade de banco de dados aberto (ODBC) do MFC. Se você usar as classes de objetos de acesso de dados (DAO) mais recentes, use [CDaoException](../../mfc/reference/cdaoexception-class.md) em vez disso. Todos os nomes de classe do DAO têm "CDao" como um prefixo. Para obter mais informações, consulte o artigo [visão geral: programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 Exceções são casos de execução anormal que envolvem condições fora do controle do programa, como a fonte de dados ou erros de e/s de rede. Erros que você esperava ver no curso normal de executar o programa geralmente não são considerados exceções.  
  
 Você pode acessar esses objetos dentro do escopo de um **CATCH** expressão. Você também pode lançar `CDBException` objetos no seu próprio código com o `AfxThrowDBException` função global.  
  
 Para obter mais informações sobre o tratamento de exceções em geral ou sobre `CDBException` objetos, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CDBException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
##  <a name="a-namemnretcodea--cdbexceptionmnretcode"></a><a name="m_nretcode"></a>CDBException::m_nRetCode  
 Contém um código de erro ODBC do tipo **RETCODE** retornado por um função de API (interface) de programação de aplicativo de ODBC.  
  
### <a name="remarks"></a>Comentários  
 Esse tipo inclui prefixados SQL códigos definidos pelo ODBC e prefixado AFX_SQL definido pelas classes de banco de dados. Para um `CDBException`, esse membro podem conter um dos seguintes valores:  
  
- **AFX_SQL_ERROR_API_CONFORMANCE** o driver para uma `CDatabase::OpenEx` ou `CDatabase::Open` chamada não corresponde ao nível de compatibilidade de API de ODBC necessário 1 ( **SQL_OAC_LEVEL1 é**).  
  
- **AFX_SQL_ERROR_CONNECT_FAIL** Falha na Conexão à fonte de dados. É passado um **nulo** `CDatabase` ponteiro para o construtor do conjunto de registros e a tentativa subsequente para criar uma conexão com base em `GetDefaultConnect` falhou.  
  
- **AFX_SQL_ERROR_DATA_TRUNCATED** solicitado mais dados que você forneceu o armazenamento. Para obter informações sobre como aumentar o armazenamento de dados fornecidos para `CString` ou `CByteArray` tipos de dados, consulte o `nMaxLength` argumento [RFX_Text](http://msdn.microsoft.com/library/de3c7581-d26c-40cb-81f3-c492ef4809f6) e [RFX_Binary](http://msdn.microsoft.com/library/908ff945-3ad0-43a1-9932-cdcdc8b14915) em "Macros e globais."  
  
- **AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED** uma chamada para `CRecordset::Open` solicitar um dynaset falhou. Não há suporte para dynasets pelo driver.  
  
- **AFX_SQL_ERROR_EMPTY_COLUMN_LIST** você tentou abrir uma tabela (ou o que você forneceu não pôde ser identificado como uma chamada de procedimento ou **selecione** instrução), mas não existem colunas identificadas no campo registro exchange (RFX) chamadas de função em seu `DoFieldExchange` substituir.  
  
- **AFX_SQL_ERROR_FIELD_SCHEMA_MISMATCH** o tipo de uma função RFX em seu `DoFieldExchange` substituição não é compatível com o tipo de dados de coluna no conjunto de registros.  
  
- **AFX_SQL_ERROR_ILLEGAL_MODE** você chamado `CRecordset::Update` sem chamar anteriormente `CRecordset::AddNew` ou `CRecordset::Edit`.  
  
- **AFX_SQL_ERROR_LOCK_MODE_NOT_SUPPORTED** sua solicitação para registros de bloqueio de atualização não pôde ser atendida porque o driver ODBC não dá suporte a bloqueio.  
  
- **AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED** você chamado `CRecordset::Update` ou **excluir** para uma tabela sem chave exclusiva e vários registros alterados.  
  
- **AFX_SQL_ERROR_NO_CURRENT_RECORD** tentou editar ou excluir um registro excluído anteriormente. Você deve rolar para um novo registro atual após uma exclusão.  
  
- **AFX_SQL_ERROR_NO_POSITIONED_UPDATES** sua solicitação para um dynaset não pôde ser atendido porque o driver ODBC não suporta atualizações posicionadas.  
  
- **AFX_SQL_ERROR_NO_ROWS_AFFECTED** você chamado `CRecordset::Update` ou **excluir**, mas quando a operação começou o registro não pôde ser encontrado.  
  
- **AFX_SQL_ERROR_ODBC_LOAD_FAILED** uma tentativa de carregar o ODBC. Falha de DLL; O Windows não pôde localizar ou não foi possível carregar essa DLL. Esse erro é fatal.  
  
- **AFX_SQL_ERROR_ODBC_V2_REQUIRED** sua solicitação de dynaset não pôde ser atendida porque um driver ODBC compatível com 2 nível é necessário.  
  
- **AFX_SQL_ERROR_RECORDSET_FORWARD_ONLY** uma tentativa de rolar não teve êxito porque a fonte de dados não oferece suporte para trás.  
  
- **AFX_SQL_ERROR_SNAPSHOT_NOT_SUPPORTED** uma chamada para `CRecordset::Open` solicitar um instantâneo falhou. Instantâneos não são suportados pelo driver. (Isso só deve ocorrer quando a biblioteca de cursores ODBC â €"ODBCCURS. DLL â €"não está presente.)  
  
- **AFX_SQL_ERROR_SQL_CONFORMANCE** o driver para uma `CDatabase::OpenEx` ou `CDatabase::Open` chamada não está de acordo com o nível de compatibilidade do ODBC SQL necessário de "Mínimo" ( **SQL_OSC_MINIMUM é**).  
  
- **AFX_SQL_ERROR_SQL_NO_TOTAL** o ODBC driver não pôde especificar o tamanho total de um `CLongBinary` valor de dados. Provavelmente, a operação falhou porque não pôde ser pré-alocado um bloco de memória global.  
  
- **AFX_SQL_ERROR_RECORDSET_READONLY** tentou atualizar um conjunto de registros somente leitura ou a fonte de dados é somente leitura. Nenhuma operação de atualização pode ser executadas com o conjunto de registros ou `CDatabase` objeto está associado.  
  
- **SQL_ERROR** Falha na função. A mensagem de erro retornada pela função ODBC **SQLError** é armazenado na **m_strError** membro de dados.  
  
- **SQL_INVALID_HANDLE** função falhou devido a um identificador de ambiente inválida, o identificador de conexão ou o identificador de instrução. Isso indica um erro de programação. Nenhuma informação adicional está disponível da função ODBC **SQLError**.  
  
 Os códigos de prefixo de SQL são definidos pelo ODBC. Os códigos de prefixo AFX são definidos em AFXDB. H, localizado em MFC\INCLUDE.  
  
##  <a name="a-namemstrerrora--cdbexceptionmstrerror"></a><a name="m_strerror"></a>CDBException::m_strError  
 Contém uma cadeia de caracteres que descreve o erro que causou a exceção.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres descreve o erro em termos de alfanuméricos. Para obter mais informações e um exemplo, consulte **m_strStateNativeOrigin**.  
  
##  <a name="a-namemstrstatenativeorigina--cdbexceptionmstrstatenativeorigin"></a><a name="m_strstatenativeorigin"></a>CDBException::m_strStateNativeOrigin  
 Contém uma cadeia de caracteres que descreve o erro que causou a exceção.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres é do formulário "estado: % s, nativo: % ld, origem: % s", onde os códigos de formatação, em ordem, são substituídos pelos valores que descrevem:  
  
-   O **SQLSTATE**, uma cadeia de caracteres terminada em nulo que contém um código de erro de cinco caracteres retornado no *szSqlState* parâmetro da função ODBC **SQLError**. **SQLSTATE** valores estão listados no Apêndice A, [códigos de erro de ODBC](https://msdn.microsoft.com/library/ms714687.aspx), além de *referência do programador de ODBC*. Exemplo: "S0022".  
  
-   Retornou o código de erro nativo específico à fonte de dados, no *pfNativeError* parâmetro o **SQLError** função. Exemplo: 207.  
  
-   O texto da mensagem de erro retornado no *szErrorMsg* parâmetro o **SQLError** função. Essa mensagem consiste em vários nomes entre colchetes. Como um erro é passado da fonte para o usuário, cada componente do ODBC (fonte de dados, driver, o Gerenciador de Driver) acrescenta seu próprio nome. Essas informações ajudam a identificar a origem do erro. Exemplo: [Microsoft] [Driver do ODBC SQL Server] [SQL Server]  
  
 O framework interpreta a cadeia de caracteres de erro e coloca seus componentes em **m_strStateNativeOrigin**; se **m_strStateNativeOrigin** contém informações para mais de um erro, os erros são separados por novas linhas. O framework coloca o texto do erro alfanumérico no **m_strError**.  
  
 Para obter informações adicionais sobre os códigos usados para tornar essa cadeia de caracteres, consulte o [SQLError](https://msdn.microsoft.com/library/ms716312.aspx) funcionar a *referência do programador de ODBC*.  
  
### <a name="example"></a>Exemplo  
  De ODBC: "Estado: S0022, nativo:&207;, origem: [Microsoft] [Driver do ODBC SQL Server] [SQL Server] nome de coluna inválido 'ColName'"  
  
 Em **m_strStateNativeOrigin**: "estado: S0022, nativo:&207;, origem: [Microsoft] [Driver do ODBC SQL Server] [SQL Server]"  
  
 Em **m_strError**: "nome de coluna inválido 'ColName'"  
  
## <a name="see-also"></a>Consulte também  
 [Classe CException](../../mfc/reference/cexception-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)   
 [Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [CRecordset::Update](../../mfc/reference/crecordset-class.md#update)   
 [CRecordset::Delete](../../mfc/reference/crecordset-class.md#delete)   
 [Classe CException](../../mfc/reference/cexception-class.md)

