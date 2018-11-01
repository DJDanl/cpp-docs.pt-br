---
title: Estrutura CDaoQueryDefInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoQueryDefInfo
helpviewer_keywords:
- DAO (Data Access Objects), QueryDefs collection
- CDaoQueryDefInfo structure [MFC]
ms.assetid: e20837dc-e78d-4171-a195-1b4075fb5d2a
ms.openlocfilehash: f3c8b464a84bd33d15a19f24010b942bdea59620
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602989"
---
# <a name="cdaoquerydefinfo-structure"></a>Estrutura CDaoQueryDefInfo

O `CDaoQueryDefInfo` estrutura contém informações sobre um objeto querydef definida para objetos de acesso de dados (DAO).

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

*m_strName*<br/>
Nomes de objeto querydef exclusivamente. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO. Chame [CDaoQueryDef::GetName](../../mfc/reference/cdaoquerydef-class.md#getname) para recuperar essa propriedade diretamente.

*m_nType*<br/>
Um valor que indica o tipo de operacional de um objeto querydef. O valor pode ser um dos seguintes:

- `dbQSelect` Selecione — a consulta seleciona os registros.

- `dbQAction` Ação — a consulta se move ou altera os dados, mas não retorna registros.

- `dbQCrosstab` Tabela de referência cruzada — a consulta retorna dados em um formato de planilha.

- `dbQDelete` Excluir — a consulta exclui um conjunto de linhas especificados.

- `dbQUpdate` Atualização — a consulta é alterada a um conjunto de registros.

- `dbQAppend` De acréscimo — a consulta adiciona novos registros ao final de uma tabela ou consulta.

- `dbQMakeTable` Criar tabela — a consulta cria uma nova tabela de um conjunto de registros.

- `dbQDDL` Definição de dados — a consulta afeta a estrutura de tabelas ou suas partes.

- `dbQSQLPassThrough` Passagem — a instrução SQL é passada diretamente para o back-end de banco de dados, sem processamento intermediário.

- `dbQSetOperation` A consulta de união — cria um objeto de conjunto de registros do tipo de instantâneo que contém dados de registros de todos os especificados em duas ou mais tabelas com registros duplicados removidos. Para incluir as duplicatas, adicione a palavra-chave **todos os** na instrução de SQL do querydef.

- `dbQSPTBulk` Usado com `dbQSQLPassThrough` para especificar uma consulta que não retorna registros.

> [!NOTE]
>  Para criar uma consulta de passagem, você não definir o `dbQSQLPassThrough` constante. Isso é definido automaticamente pelo mecanismo de banco de dados Microsoft Jet, quando você cria um objeto querydef e define a propriedade Connect.

Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.

*m_dateCreated*<br/>
A data e hora que QueryDef foi criado. Para recuperar diretamente a data querydef foi criado, chame o [GetDateCreated](../../mfc/reference/cdaotabledef-class.md#getdatecreated) função de membro do `CDaoTableDef` objeto associado à tabela. Consulte os comentários abaixo para obter mais informações. Também consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

*m_dateLastUpdated*<br/>
A data e hora da alteração mais recente feita querydef. Para recuperar diretamente a data em que a tabela foi atualizada pela última vez, chame o [GetDateLastUpdated](../../mfc/reference/cdaoquerydef-class.md#getdatelastupdated) a função de membro de querydef. Consulte os comentários abaixo para obter mais informações. E consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

*m_bUpdatable*<br/>
Indica se as alterações podem ser feitas a um objeto querydef. Se essa propriedade for TRUE, querydef é atualizável; Caso contrário, ele não é. Atualizável significa que a definição de consulta do objeto pode ser alterada. A propriedade atualizável de um objeto querydef é definida como TRUE se a definição de consulta pode ser atualizada, mesmo se o conjunto de registros resultante não é atualizável. Para recuperar essa propriedade diretamente, chame o querydef [CanUpdate](../../mfc/reference/cdaoquerydef-class.md#canupdate) função de membro. Para obter mais informações, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.

*m_bReturnsRecords*<br/>
Indica se uma consulta de passagem para um banco de dados externo retorna registros. Se essa propriedade for TRUE, a consulta retorna registros. Para recuperar diretamente essa propriedade, chame [CDaoQueryDef::GetReturnsRecords](../../mfc/reference/cdaoquerydef-class.md#getreturnsrecords). Nem todas as consultas de passagem de SQL para bancos de dados externos retornam registros. Por exemplo, um SQL **atualização** instrução atualiza registros sem retornar registros, enquanto um SQL **selecione** instrução retornar registros. Para obter mais informações, consulte o tópico "Propriedade ReturnsRecords" na Ajuda do DAO.

*m_strSQL*<br/>
A instrução SQL que define a consulta executada por um objeto querydef. A propriedade SQL contém a instrução SQL que determina como registros são selecionados, agrupados e classificados quando você executa a consulta. Você pode usar a consulta para selecionar registros a serem incluídos em um objeto de conjunto de registros do tipo dynaset ou instantâneo. Você também pode definir consultas em massa para modificar os dados sem retornar registros. Você pode recuperar o valor dessa propriedade chamando o querydef [GetSQL](../../mfc/reference/cdaoquerydef-class.md#getsql) função de membro.

*m_strConnect*<br/>
Fornece informações sobre a origem de um banco de dados usado em uma consulta de passagem. Essas informações assumem a forma de uma cadeia de caracteres de conexão. Para obter mais informações sobre o connect cadeias de caracteres e para obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte o [CDaoDatabase::GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) função de membro.

*m_nODBCTimeout*<br/>
O número de segundos que o mecanismo de banco de dados Microsoft Jet aguarda antes de um erro de tempo limite ocorre quando uma consulta é executada em um banco de dados ODBC. Quando você estiver usando um banco de dados ODBC, como o Microsoft SQL Server, pode haver atrasos devido ao uso de tráfego ou com uso intenso de rede do servidor ODBC. Em vez de esperar indefinidamente, você pode especificar quanto tempo o mecanismo Microsoft Jet aguarda antes de produzir um erro. O valor de tempo limite padrão é 60 segundos. Você pode recuperar o valor dessa propriedade chamando o querydef [GetODBCTimeout](../../mfc/reference/cdaoquerydef-class.md#getodbctimeout) função de membro. Para obter mais informações, consulte o tópico "Propriedade ODBCTimeout" na Ajuda do DAO.

## <a name="remarks"></a>Comentários

Querydef é um objeto da classe [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). As referências ao primário, secundário e todos acima indicam como as informações são retornadas pela [GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) função de membro na classe `CDaoDatabase`.

As informações recuperadas pelo [CDaoDatabase::GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) função de membro é armazenada em um `CDaoQueryDefInfo` estrutura. Chamar `GetQueryDefInfo` para o objeto de banco de dados cuja coleção QueryDefs o objeto querydef é armazenado. `CDaoQueryDefInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoQueryDefInfo` objeto. Classe `CDaoDatabase` também fornece funções de membro para acessar diretamente todas as propriedades retornadas em uma `CDaoQueryDefInfo` do objeto, portanto, você provavelmente raramente precisará chamar `GetQueryDefInfo`.

Quando você acrescentar um novo campo ou um objeto parameter à coleção de campos ou parâmetros de um objeto querydef, uma exceção é lançada se o banco de dados subjacente não dá suporte para o tipo de dados especificado para o novo objeto.

As configurações de data e hora são derivadas do computador no qual o querydef foi criado ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos usando o **net tempo** comando para evitar discrepâncias nas configurações das propriedades DateCreated e LastUpdated.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
