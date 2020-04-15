---
title: Estrutura CDaoQueryDefInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoQueryDefInfo
helpviewer_keywords:
- DAO (Data Access Objects), QueryDefs collection
- CDaoQueryDefInfo structure [MFC]
ms.assetid: e20837dc-e78d-4171-a195-1b4075fb5d2a
ms.openlocfilehash: e2f0325237a30989637821464c63a4d8b8000b1e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368934"
---
# <a name="cdaoquerydefinfo-structure"></a>Estrutura CDaoQueryDefInfo

A `CDaoQueryDefInfo` estrutura contém informações sobre um objeto querydef definido para objetos de acesso a dados (DAO).

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
Nomeie exclusivamente o objeto querydef. Para obter mais informações, consulte o tópico "Propriedade de nome" no DAO Help. Ligue para [cdaoQueryDef::GetName](../../mfc/reference/cdaoquerydef-class.md#getname) para recuperar essa propriedade diretamente.

*m_nType*<br/>
Um valor que indica o tipo operacional de um objeto querydef. O valor pode ser um dos seguintes:

- `dbQSelect`Selecionar — a consulta seleciona registros.

- `dbQAction`Action — a consulta move ou altera dados, mas não retorna registros.

- `dbQCrosstab`Crosstab — a consulta retorna dados em um formato semelhante a uma planilha.

- `dbQDelete`Excluir — a consulta exclui um conjunto de linhas especificadas.

- `dbQUpdate`Atualização — a consulta altera um conjunto de registros.

- `dbQAppend`Apêndice — a consulta adiciona novos registros ao final de uma tabela ou consulta.

- `dbQMakeTable`Make-table — a consulta cria uma nova tabela a partir de um conjunto de registros.

- `dbQDDL`Definição de dados — a consulta afeta a estrutura das tabelas ou suas partes.

- `dbQSQLPassThrough`Pass-through — a declaração SQL é passada diretamente para o backend do banco de dados, sem processamento intermediário.

- `dbQSetOperation`União — a consulta cria um objeto de conjunto de registros de tipo de instantâneo contendo dados de todos os registros especificados em duas ou mais tabelas com quaisquer registros duplicados removidos. Para incluir as duplicatas, adicione a palavra-chave **ALL** na declaração SQL do querydef.

- `dbQSPTBulk`Usado `dbQSQLPassThrough` para especificar uma consulta que não retorna registros.

> [!NOTE]
> Para criar uma consulta de passagem SQL, `dbQSQLPassThrough` você não define a constante. Isso é definido automaticamente pelo mecanismo de banco de dados Microsoft Jet quando você cria um objeto querydef e define a propriedade Connect.

Para obter mais informações, consulte o tópico "Tipo propriedade" no DAO Help.

*m_dateCreated*<br/>
A data e a hora em que o consultafoi criado. Para recuperar diretamente a data em que o consultadef foi criado, `CDaoTableDef` chame a função [membro GetDateCreated](../../mfc/reference/cdaotabledef-class.md#getdatecreated) do objeto associado à tabela. Veja Os comentários abaixo para obter mais informações. Veja também o tópico "DateCreated, LastUpdated Properties" no DAO Help.

*m_dateLastUpdated*<br/>
A data e a hora da alteração mais recente feita para o consultadef. Para recuperar diretamente a data em que a tabela foi atualizada pela última vez, ligue para a função membro [GetDateLastUpdated](../../mfc/reference/cdaoquerydef-class.md#getdatelastupdated) do querydef. Veja Os comentários abaixo para obter mais informações. E veja o tópico "DateCreated, LastUpdated Properties" no DAO Help.

*m_bUpdatable*<br/>
Indica se alterações podem ser feitas em um objeto querydef. Se esta propriedade for TRUE, a consultaé updatable; caso contrário, não é. Updatable significa que a definição de consulta do objeto querydef pode ser alterada. A propriedade Updatable de um objeto querydef é definida como TRUE se a definição de consulta puder ser atualizada, mesmo que o conjunto de registros resultante não seja atualizável. Para recuperar essa propriedade diretamente, ligue para a função de membro [CanUpdate](../../mfc/reference/cdaoquerydef-class.md#canupdate) do consultardef. Para obter mais informações, consulte o tópico "Updatable Property" no DAO Help.

*m_bReturnsRecords*<br/>
Indica se uma consulta de passagem de SQL para um banco de dados externo retorna registros. Se esta propriedade for TRUE, a consulta retorna registros. Para recuperar diretamente essa propriedade, ligue para [CDaoQueryDef::GetReturnsRecords](../../mfc/reference/cdaoquerydef-class.md#getreturnsrecords). Nem todas as consultas de passagem sql para bancos de dados externos retornam registros. Por exemplo, uma declaração sql **UPDATE** atualiza registros sem retornar registros, enquanto uma declaração SQL **SELECT** faz registros de retorno. Para obter mais informações, consulte o tópico "ReturnsRecords Property" no DAO Help.

*m_strSQL*<br/>
A declaração SQL que define a consulta executada por um objeto querydef. A propriedade SQL contém a declaração SQL que determina como os registros são selecionados, agrupados e ordenados quando você executa a consulta. Você pode usar a consulta para selecionar registros para incluir em um objeto de conjunto de gravação dynaset ou snapshot. Você também pode definir consultas em massa para modificar dados sem retornar registros. Você pode recuperar o valor desta propriedade diretamente ligando para a função de membro [GetSQL](../../mfc/reference/cdaoquerydef-class.md#getsql) do consultardef.

*m_strConnect*<br/>
Fornece informações sobre a origem de um banco de dados usado em uma consulta de passagem. Essas informações assumem a forma de uma seqüência de conexão. Para obter mais informações sobre conexão de strings e para obter informações sobre como recuperar o valor desta propriedade diretamente, consulte a função [cDaoDatabase::GetConnect](../../mfc/reference/cdaodatabase-class.md#getconnect) member.

*m_nODBCTimeout*<br/>
O número de segundos que o mecanismo de banco de dados do Microsoft Jet espera antes que ocorra um erro de tempo quando uma consulta é executada em um banco de dados ODBC. Quando você está usando um banco de dados ODBC, como o Microsoft SQL Server, pode haver atrasos devido ao tráfego de rede ou ao uso intenso do servidor ODBC. Em vez de esperar indefinidamente, você pode especificar quanto tempo o motor Microsoft Jet espera antes de produzir um erro. O valor de tempo de tempo padrão é de 60 segundos. Você pode recuperar o valor desta propriedade diretamente chamando a função de membro [GetODBCTimeout](../../mfc/reference/cdaoquerydef-class.md#getodbctimeout) do consultardef. Para obter mais informações, consulte o tópico "ODBCTimeout Property" no DAO Help.

## <a name="remarks"></a>Comentários

O querydef é um objeto da classe [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). As referências a Principal, Secundário e Tudo acima indicam como as informações são retornadas `CDaoDatabase`pela função de membro [GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) em classe .

As informações recuperadas pela função de membro [CDaoDatabase::GetQueryDefInfo](../../mfc/reference/cdaodatabase-class.md#getquerydefinfo) são armazenadas em uma `CDaoQueryDefInfo` estrutura. Chamada `GetQueryDefInfo` para o objeto de banco de dados em cuja coleção QueryDefs o objeto querydef é armazenado. `CDaoQueryDefInfo`também define `Dump` uma função de membro em compilações de depuração. Você pode `Dump` usar para despejar `CDaoQueryDefInfo` o conteúdo de um objeto. A `CDaoDatabase` classe também fornece funções de membro para acessar `CDaoQueryDefInfo` diretamente todas as propriedades devolvidas em `GetQueryDefInfo`um objeto, então você provavelmente raramente precisará ligar .

Quando você anexa um novo objeto de campo ou parâmetro à coleta de campos ou parâmetros de um objeto querydef, uma exceção é lançada se o banco de dados subjacente não suportar o tipo de dados especificado para o novo objeto.

As configurações de data e hora são derivadas do computador no qual o consultardef foi criado ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos usando o comando **net time** para evitar discrepâncias nas configurações de propriedade DateCreated e LastUpdated.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)
