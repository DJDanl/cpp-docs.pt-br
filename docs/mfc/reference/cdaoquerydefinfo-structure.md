---
title: Estrutura CDaoQueryDefInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoQueryDefInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), QueryDefs collection
- CDaoQueryDefInfo structure [MFC]
ms.assetid: e20837dc-e78d-4171-a195-1b4075fb5d2a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e0b3e5834aa8b338448c2024603783cedb6f6cae
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33367224"
---
# <a name="cdaoquerydefinfo-structure"></a>Estrutura CDaoQueryDefInfo
O `CDaoQueryDefInfo` estrutura contém informações sobre um objeto querydef definida para os objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoQueryDefInfo  
{  
    CString m_strName;               // Primary  
    short m_nType;   // Primary  
    COleDateTime m_dateCreated;      // Secondary  
    COleDateTime m_dateLastUpdated;  // Secondary  
    BOOL m_bUpdatable;               // Secondary  
    BOOL m_bReturnsRecords;          // Secondary  
    CString m_strSQL;                // All  
    CString m_strConnect;            // All  
    short m_nODBCTimeout;            // All  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Nomes de objeto querydef exclusivamente. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO. Chamar [CDaoQueryDef::GetName](../../mfc/reference/cdaoquerydef-class.md#getname) para recuperar esta propriedade diretamente.  
  
 `m_nType`  
 Um valor que indica o tipo de operacional de um objeto querydef. O valor pode ser um dos seguintes:  
  
- **dbQSelect** selecione — a consulta Selecionar registros.  
  
- **dbQAction** ação — a consulta se move ou altera os dados, mas não retorna registros.  
  
- **dbQCrosstab** tabela de referência cruzada, a consulta retorna dados em um formato de planilha.  
  
- **dbQDelete** excluir — a consulta exclui um conjunto de linhas especificados.  
  
- **dbQUpdate** atualização — um conjunto de registros a consulta é alterada.  
  
- **dbQAppend** acrescentar — a consulta adiciona novos registros ao final de uma tabela ou consulta.  
  
- **dbQMakeTable** criar tabela, a consulta cria uma nova tabela de um conjunto de registros.  
  
- **dbQDDL** definição de dados, a consulta afeta a estrutura de tabelas ou suas partes.  
  
- **dbQSQLPassThrough** passagem — a instrução SQL é passada diretamente para o banco de dados back-end, sem processamento intermediário.  
  
- **dbQSetOperation** união, a consulta cria um objeto de conjunto de registros do tipo de instantâneo que contém dados de registros de todos os especificados em duas ou mais tabelas com registros duplicados removidos. Para incluir as duplicatas, adicione a palavra-chave **todos os** na instrução de SQL do querydef.  
  
- **dbQSPTBulk** usado com **dbQSQLPassThrough** para especificar uma consulta que não retorna registros.  
  
> [!NOTE]
>  Para criar uma consulta de passagem, você não definir a **dbQSQLPassThrough** constante. Isso é definido automaticamente pelo mecanismo de banco de dados Microsoft Jet quando você cria um objeto querydef e defina a propriedade de conexão.  
  
 Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
 `m_dateCreated`  
 A data e hora que QueryDef foi criado. Para recuperar diretamente a data querydef foi criada, chame o [GetDateCreated](../../mfc/reference/cdaotabledef-class.md#getdatecreated) função de membro a `CDaoTableDef` objeto associado à tabela. Consulte os comentários abaixo para obter mais informações. Também consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
 `m_dateLastUpdated`  
 A data e hora da alteração mais recente feita para querydef. Para recuperar diretamente a data da última atualização de tabela, chame o [GetDateLastUpdated](../../mfc/reference/cdaoquerydef-class.md#getdatelastupdated) a função de membro de querydef. Consulte os comentários abaixo para obter mais informações. E consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
 `m_bUpdatable`  
 Indica se podem ser feitas alterações para um objeto querydef. Se essa propriedade for **TRUE**, querydef é atualizável; caso contrário, não é. Atualizável significa a que definição de consulta do objeto pode ser alterada. A propriedade atualizável de um objeto querydef é definida como **TRUE** se a definição de consulta pode ser atualizada, mesmo que o conjunto de registros resultante não é atualizável. Para recuperar esta propriedade diretamente, chame o querydef [CanUpdate](../../mfc/reference/cdaoquerydef-class.md#canupdate) função de membro. Para obter mais informações, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.  
  
 *m_bReturnsRecords*  
 Indica se uma consulta de passagem para um banco de dados externo retorna registros. Se essa propriedade for **TRUE**, a consulta retorna registros. Para recuperar diretamente essa propriedade, chame [CDaoQueryDef::GetReturnsRecords](../../mfc/reference/cdaoquerydef-class.md#getreturnsrecords). Nem todas as consultas de passagem de SQL para bancos de dados externos retornam registros. Por exemplo, um SQL **atualização** instrução atualiza os registros sem retornar registros, enquanto um SQL **selecione** instrução retornar registros. Para obter mais informações, consulte o tópico "Propriedade ReturnsRecords" na Ajuda do DAO.  
  
 *m_strSQL*  
 A instrução SQL que define a consulta executada por um objeto querydef. A propriedade SQL contém a instrução SQL que determina como os registros são selecionados, agrupados e classificados quando você executar a consulta. Você pode usar a consulta para selecionar registros a serem incluídos em um objeto de conjunto de registros do tipo dynaset ou instantâneo. Você também pode definir consultas em massa para modificar os dados sem retornar registros. Você pode recuperar o valor dessa propriedade chamando o querydef [GetSQL](../../mfc/reference/cdaoquerydef-class.md#getsql) função de membro.  
  
 `m_strConnect`  
 Fornece informações sobre a origem de um banco de dados usado em uma consulta de passagem. Essas informações assumem a forma de uma cadeia de caracteres de conexão. Para obter mais informações sobre conexão cadeias de caracteres e para obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte o [CDaoDatabase::GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) função de membro.  
  
 *m_nODBCTimeout*  
 O número de segundos que o mecanismo de banco de dados Microsoft Jet aguarda antes de um erro de tempo limite ocorre quando uma consulta é executada em um banco de dados ODBC. Quando você estiver usando um banco de dados ODBC, como o Microsoft SQL Server, pode haver atrasos devido à rede tráfego ou ao uso intenso do servidor ODBC. Em vez de esperar indefinidamente, você pode especificar quanto tempo o Microsoft Jet aguarda antes de ele produz um erro. O valor de tempo limite padrão é 60 segundos. Você pode recuperar o valor dessa propriedade chamando o querydef [GetODBCTimeout](../../mfc/reference/cdaoquerydef-class.md#getodbctimeout) função de membro. Para obter mais informações, consulte o tópico "Propriedade ODBCTimeout" na Ajuda do DAO.  
  
## <a name="remarks"></a>Comentários  
 Querydef é um objeto da classe [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). As referências para o primário, secundário e todos os acima indicam como as informações são retornadas pelo [GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) a função de membro na classe `CDaoDatabase`.  
  
 As informações recuperadas pelo [CDaoDatabase::GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) função de membro é armazenada em um `CDaoQueryDefInfo` estrutura. Chamar `GetQueryDefInfo` para o objeto de banco de dados cuja coleção QueryDefs objeto querydef é armazenado. `CDaoQueryDefInfo` também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoQueryDefInfo` objeto. Classe `CDaoDatabase` também fornece funções de membro para acessar todas as propriedades retornadas em diretamente um `CDaoQueryDefInfo` do objeto, portanto você provavelmente raramente precisa chamar `GetQueryDefInfo`.  
  
 Quando você adicionar um novo campo ou o objeto parameter à coleção de campos ou parâmetros de um objeto querydef, uma exceção é gerada se o banco de dados subjacente não suporta o tipo de dados especificado para o novo objeto.  
  
 As configurações de data e hora são derivadas do computador no qual o querydef foi criado ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos usando o **net tempo** comando para evitar discrepâncias nas configurações de propriedade DateCreated e LastUpdated.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
