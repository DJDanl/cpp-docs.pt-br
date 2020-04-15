---
title: Classe CDaoQueryDef
ms.date: 11/04/2016
f1_keywords:
- CDaoQueryDef
- AFXDAO/CDaoQueryDef
- AFXDAO/CDaoQueryDef::CDaoQueryDef
- AFXDAO/CDaoQueryDef::Append
- AFXDAO/CDaoQueryDef::CanUpdate
- AFXDAO/CDaoQueryDef::Close
- AFXDAO/CDaoQueryDef::Create
- AFXDAO/CDaoQueryDef::Execute
- AFXDAO/CDaoQueryDef::GetConnect
- AFXDAO/CDaoQueryDef::GetDateCreated
- AFXDAO/CDaoQueryDef::GetDateLastUpdated
- AFXDAO/CDaoQueryDef::GetFieldCount
- AFXDAO/CDaoQueryDef::GetFieldInfo
- AFXDAO/CDaoQueryDef::GetName
- AFXDAO/CDaoQueryDef::GetODBCTimeout
- AFXDAO/CDaoQueryDef::GetParameterCount
- AFXDAO/CDaoQueryDef::GetParameterInfo
- AFXDAO/CDaoQueryDef::GetParamValue
- AFXDAO/CDaoQueryDef::GetRecordsAffected
- AFXDAO/CDaoQueryDef::GetReturnsRecords
- AFXDAO/CDaoQueryDef::GetSQL
- AFXDAO/CDaoQueryDef::GetType
- AFXDAO/CDaoQueryDef::IsOpen
- AFXDAO/CDaoQueryDef::Open
- AFXDAO/CDaoQueryDef::SetConnect
- AFXDAO/CDaoQueryDef::SetName
- AFXDAO/CDaoQueryDef::SetODBCTimeout
- AFXDAO/CDaoQueryDef::SetParamValue
- AFXDAO/CDaoQueryDef::SetReturnsRecords
- AFXDAO/CDaoQueryDef::SetSQL
- AFXDAO/CDaoQueryDef::m_pDAOQueryDef
- AFXDAO/CDaoQueryDef::m_pDatabase
helpviewer_keywords:
- CDaoQueryDef [MFC], CDaoQueryDef
- CDaoQueryDef [MFC], Append
- CDaoQueryDef [MFC], CanUpdate
- CDaoQueryDef [MFC], Close
- CDaoQueryDef [MFC], Create
- CDaoQueryDef [MFC], Execute
- CDaoQueryDef [MFC], GetConnect
- CDaoQueryDef [MFC], GetDateCreated
- CDaoQueryDef [MFC], GetDateLastUpdated
- CDaoQueryDef [MFC], GetFieldCount
- CDaoQueryDef [MFC], GetFieldInfo
- CDaoQueryDef [MFC], GetName
- CDaoQueryDef [MFC], GetODBCTimeout
- CDaoQueryDef [MFC], GetParameterCount
- CDaoQueryDef [MFC], GetParameterInfo
- CDaoQueryDef [MFC], GetParamValue
- CDaoQueryDef [MFC], GetRecordsAffected
- CDaoQueryDef [MFC], GetReturnsRecords
- CDaoQueryDef [MFC], GetSQL
- CDaoQueryDef [MFC], GetType
- CDaoQueryDef [MFC], IsOpen
- CDaoQueryDef [MFC], Open
- CDaoQueryDef [MFC], SetConnect
- CDaoQueryDef [MFC], SetName
- CDaoQueryDef [MFC], SetODBCTimeout
- CDaoQueryDef [MFC], SetParamValue
- CDaoQueryDef [MFC], SetReturnsRecords
- CDaoQueryDef [MFC], SetSQL
- CDaoQueryDef [MFC], m_pDAOQueryDef
- CDaoQueryDef [MFC], m_pDatabase
ms.assetid: 9676a4a3-c712-44d4-8c5d-d1cc78288d3a
ms.openlocfilehash: 133746ff1e4a9453f9563347724a47855a8a3228
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368947"
---
# <a name="cdaoquerydef-class"></a>Classe CDaoQueryDef

Representa uma definição de consulta, ou "querydef", geralmente uma salva em um banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoQueryDef : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef::CDaoQueryDef](#cdaoquerydef)|Constrói um objeto `CDaoQueryDef`. Próxima `Open` chamada `Create`ou, dependendo de suas necessidades.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef::Apêndice](#append)|Anexa o consultadef à coleção QueryDefs do banco de dados como uma consulta salva.|
|[CDaoQueryDef::CanUpdate](#canupdate)|Retorna não zero se a consulta puder atualizar o banco de dados.|
|[CDaoQueryDef::Fechar](#close)|Fecha o objeto querydef. Destrua o objeto C++ quando terminar com ele.|
|[CDaoQueryDef::Criar](#create)|Cria o objeto DAO querydef subjacente. Use o consultadef como uma consulta `Append` temporária ou ligue para salvá-lo no banco de dados.|
|[CDaoQueryDef::Execute](#execute)|Executa a consulta definida pelo objeto querydef.|
|[CDaoQueryDef::GetConnect](#getconnect)|Retorna a seqüência de conexão associada ao querydef. A seqüência de conexões identifica a fonte de dados. (Apenas para consultas de passagem SQL; caso contrário, uma seqüência vazia.)|
|[CDaoQueryDef::GetDateCriado](#getdatecreated)|Retorna a data em que a consulta salva foi criada.|
|[CDaoQueryDef::GetDateÚltimaatualização](#getdatelastupdated)|Retorna a data em que a consulta salva foi atualizada pela última vez.|
|[CDaoQueryDef::GetFieldCount](#getfieldcount)|Retorna o número de campos definidos pelo querydef.|
|[CDaoQueryDef::GetFieldInfo](#getfieldinfo)|Retorna informações sobre um campo especificado definido na consulta.|
|[CDaoQueryDef::GetName](#getname)|Retorna o nome do consultardef.|
|[CDaoQueryDef::GetODBCTimeout](#getodbctimeout)|Retorna o valor de tempo usado pelo ODBC (para uma consulta ODBC) quando o consulta é executado. Isso determina quanto tempo para permitir que a ação da consulta seja concluída.|
|[CDaoQueryDef::GetParameterCount](#getparametercount)|Retorna o número de parâmetros definidos para a consulta.|
|[CDaoQueryDef::GetParameterInfo](#getparameterinfo)|Retorna informações sobre um parâmetro especificado para a consulta.|
|[CDaoQueryDef::GetParamValue](#getparamvalue)|Retorna o valor de um parâmetro especificado para a consulta.|
|[CDaoQueryDef::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetados por uma consulta de ação.|
|[CDaoQueryDef::GetReturnsRecords](#getreturnsrecords)|Retorna não zero se a consulta definida pelo querydef retornar registros.|
|[CDaoQueryDef::GetSQL](#getsql)|Retorna a seqüência sql que especifica a consulta definida pelo querydef.|
|[CDaoQueryDef::GetType](#gettype)|Retorna o tipo de consulta: excluir, atualizar, anexar, fazer tabela e assim por diante.|
|[CDaoQueryDef::IsOpen](#isopen)|Retorna não zero se o consultadef estiver aberto e puder ser executado.|
|[CDaoQueryDef::Aberto](#open)|Abre um consultadef existente armazenado na coleção QueryDefs do banco de dados.|
|[CDaoQueryDef::SetConnect](#setconnect)|Define a seqüência de conexões para uma consulta de passagem SQL em uma fonte de dados ODBC.|
|[CDaoQueryDef::SetName](#setname)|Define o nome da consulta salva, substituindo o nome em uso quando o consultafoi criado.|
|[CDaoQueryDef::SetODBCTimeout](#setodbctimeout)|Define o valor de tempo de tempo usado pelo ODBC (para uma consulta ODBC) quando o consulta é executado.|
|[CDaoQueryDef::SetParamValue](#setparamvalue)|Define o valor de um parâmetro especificado para a consulta.|
|[CDaoQueryDef::SetReturnsRecords](#setreturnsrecords)|Especifica se o consultardef retorna os registros. Definir este atributo como TRUE só é válido para consultas de passagem SQL.|
|[CDaoQueryDef::SetSQL](#setsql)|Define a seqüência sql que especifica a consulta definida pelo querydef.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef::m_pDAOQueryDef](#m_pdaoquerydef)|Um ponteiro para a interface OLE para o objeto DAO querydef subjacente.|
|[CDaoQueryDef::m_pDatabase](#m_pdatabase)|Um ponteiro `CDaoDatabase` para o objeto com o qual o querydef está associado. O consultapode ser salvo no banco de dados ou não.|

## <a name="remarks"></a>Comentários

Um consultadef é um objeto de acesso a dados que contém a declaração SQL que descreve uma consulta e suas propriedades, como "Data Created" e "ODBC Timeout". Você também pode criar objetos de consulta temporária sem salvá-los, mas é conveniente — e muito mais eficiente — salvar consultas comumente reutilizadas em um banco de dados. Um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) mantém uma coleção, chamada coleção QueryDefs, que contém seus querydefs salvos.

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO. Em geral, as classes de MFC baseadas em DAO são mais capazes do que as classes MFC baseadas no ODBC; as classes baseadas em DAO podem acessar dados, inclusive através de drivers ODBC, através de seu próprio mecanismo de banco de dados. As classes baseadas em DAO também suportam operações DDL (Data Definition Language, linguagem de definição de dados), como adicionar tabelas através das classes, sem ter que ligar diretamente para dao.

## <a name="usage"></a>Uso

Use objetos querydef para trabalhar com uma consulta salva existente ou para criar uma nova consulta salva ou consulta temporária:

1. Em todos os casos, primeiro construa um `CDaoQueryDef` objeto, fornecendo um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ao qual a consulta pertence.

1. Em seguida, faça o seguinte, dependendo do que você quiser:

   - Para usar uma consulta salva existente, chame a função de membro [aberto](#open) do objeto querydef, fornecendo o nome da consulta salva.

   - Para criar uma nova consulta salva, chame a função [Criar](#create) membro do objeto querydef, fornecendo o nome da consulta. Em [seguida,](#append) ligue para anexar a consulta, anexando-a à coleção QueryDefs do banco de dados. `Create`coloca o querydef em um estado `Create` aberto, então `Open`depois de chamá-lo não ligue .

   - Para criar uma consulta temporária, `Create`ligue . Passe uma seqüência vazia para o nome da consulta. Não chame `Append`.

Quando terminar de usar um objeto querydef, chame sua função De membro [Próximo;](#close) em seguida, destruir o objeto querydef.

> [!TIP]
> A maneira mais fácil de criar consultas salvas é criá-las e armazená-las em seu banco de dados usando o Microsoft Access. Então você pode abri-los e usá-los em seu código MFC.

## <a name="purposes"></a>Fins

Você pode usar um objeto querydef para qualquer um dos seguintes propósitos:

- Para criar `CDaoRecordset` um objeto

- Para chamar a `Execute` função de membro do objeto para executar diretamente uma consulta de ação ou uma consulta de passagem SQL

Você pode usar um objeto querydef para qualquer tipo de consulta, incluindo selecionar, ação, crosstab, excluir, atualizar, anexar, fazer tabela, definição de dados, passagem de SQL, união e consultas em massa. O tipo de consulta é determinado pelo conteúdo da declaração SQL que você fornece. Para obter informações sobre os `Execute` tipos de consulta, consulte as funções do membro [GetType.](#gettype) Os conjuntos de registros são comumente usados para consultas de retorno de linha, geralmente aquelas que usam o **SELECT ... Das** palavras-chave. `Execute`é mais comumente usado para operações em massa. Para obter mais informações, consulte [Execute](#execute) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

## <a name="querydefs-and-recordsets"></a>Querydefs e Recordsets

Para usar um objeto querydef para criar um `CDaoRecordset` objeto, você normalmente cria ou abre uma consulta conforme descrito acima. Em seguida, construa um objeto de conjunto de registros, passando um ponteiro para o objeto querydef quando você chamar [CDaoRecordset:::Abrir](../../mfc/reference/cdaorecordset-class.md#open). A consulta que você passar deve estar em estado aberto. Para obter mais informações, consulte [classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Você não pode usar um consultadef para criar um conjunto de registros (o uso mais comum para um consulta) a menos que esteja em um estado aberto. Coloque o consultaemem em estado aberto `Open` `Create`ligando para um ou .

## <a name="external-databases"></a>Bancos de dados externos

Objetos querydef são a maneira preferida de usar o dialeto SQL nativo de um mecanismo de banco de dados externo. Por exemplo, você pode criar uma consulta Transact SQL (como usado no Microsoft SQL Server) e armazená-la em um objeto querydef. Quando você precisa usar uma consulta SQL não baseada no mecanismo de banco de dados Microsoft Jet, você deve fornecer uma seqüência de conexão que aponta para a fonte de dados externo. Consultas com seqüências de conexão válidas contornam o mecanismo do banco de dados e passam a consulta diretamente para o servidor de banco de dados externo para processamento.

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um Microsoft Jet (. MDB) banco de dados.

Para obter informações relacionadas, consulte os tópicos "Objeto queryDef", "QueryDefs Collection" e "CdbDatabase Object" no DAO SDK.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDaoQueryDef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaoquerydefappend"></a><a name="append"></a>CDaoQueryDef::Apêndice

Ligue para esta função de membro depois de chamar [Criar](#create) para criar um novo objeto querydef.

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

`Append`salva o consultardef no banco de dados anexando o objeto à coleção QueryDefs do banco de dados. Você pode usar o consultacomo um objeto temporário sem apendice-o, mas `Append`se você quiser que ele persista, você deve chamar .

Se você tentar anexar um objeto de consulta temporária, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

## <a name="cdaoquerydefcanupdate"></a><a name="canupdate"></a>CDaoQueryDef::CanUpdate

Ligue para esta função de membro para determinar se você pode modificar o consultardef — como alterar seu nome ou seqüência de sql.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor retornado

Não zero se você tiver permissão para modificar o consultadef; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode modificar o consultardef se:

- Não se baseia em um banco de dados aberto somente para leitura.

- Você tem permissões de atualização para o banco de dados.

   Isso depende se você implementou recursos de segurança. O MFC não oferece suporte para segurança; você deve implementá-lo você mesmo ligando para dao diretamente ou usando o Microsoft Access. Consulte o tópico "Permissions Property" no DAO Help.

## <a name="cdaoquerydefcdaoquerydef"></a><a name="cdaoquerydef"></a>CDaoQueryDef::CDaoQueryDef

Constrói um objeto `CDaoQueryDef`.

```
CDaoQueryDef(CDaoDatabase* pDatabase);
```

### <a name="parameters"></a>Parâmetros

*pBanco de dados*<br/>
Um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) aberto.

### <a name="remarks"></a>Comentários

O objeto pode representar uma consulta existente armazenada na coleção QueryDefs do banco de dados, uma nova consulta a ser armazenada na coleção ou uma consulta temporária, para não ser armazenada. Seu próximo passo depende do tipo de consulta:

- Se o objeto representar um consultadef existente, chame a função de membro [Aberto](#open) do objeto para inicializá-lo.

- Se o objeto representar um novo consultadef a ser salvo, chame a função [Criar](#create) membro do objeto. Isso adiciona o objeto à coleção QueryDefs do banco de dados. Em `CDaoQueryDef` seguida, ligue para funções do membro para definir os atributos do objeto. Finalmente, ligue para [o Append](#append).

- Se o objeto representar uma consulta temporária (não ser salva `Create`no banco de dados), ligue, passando uma seqüência vazia para o nome da consulta. Após `Create`a chamada, inicialize o querydef definindo diretamente seus atributos. Não chame `Append`.

Para definir os atributos do consultardef, você pode usar as funções de membro [SetName,](#setname) [SetSQL,](#setsql) [SetConnect,](#setconnect) [SetODBCTimeout](#setodbctimeout)e [SetReturnsRecords.](#setreturnsrecords)

Quando terminar com o objeto querydef, chame sua função De membro [Próximo.](#close) Se você tiver um ponteiro para o querydef, use o operador **de exclusão** para destruir o objeto C++.

## <a name="cdaoquerydefclose"></a><a name="close"></a>CDaoQueryDef::Fechar

Chame esta função de membro quando terminar de usar o objeto querydef.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

O fechamento do consultadef libera o objeto DAO subjacente, mas não destrói o objeto `CDaoQueryDef` DAO querydef salvo ou o objeto C++. Isso não é o mesmo que [CDaoDatabase::DeleteQueryDef](../../mfc/reference/cdaodatabase-class.md#deletequerydef), que exclui o querydef da coleção QueryDefs do banco de dados no DAO (se não um consulta temporário).

## <a name="cdaoquerydefcreate"></a><a name="create"></a>CDaoQueryDef::Criar

Chame esta função de membro para criar uma nova consulta salva ou uma nova consulta temporária.

```
virtual void Create(
    LPCTSTR lpszName = NULL,
    LPCTSTR lpszSQL = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome único da consulta salvo no banco de dados. Para obter detalhes sobre a seqüência, consulte o tópico "CreateQueryDef Method" no DAO Help. Se você aceitar o valor padrão, uma seqüência de string vazia, uma consulta temporária será criada. Essa consulta não é salva na coleção QueryDefs.

*lpszSQL*<br/>
A seqüência SQL que define a consulta. Se você aceitar o valor padrão de NULL, você deve chamar [setSQL](#setsql) para definir a seqüência de string. Até lá, a consulta está indefinida. No entanto, você pode usar a consulta indefinida para abrir um conjunto de registros; ver Observações para detalhes. A declaração SQL deve ser definida antes de você poder anexar o consultaà coleção QueryDefs.

### <a name="remarks"></a>Comentários

Se você passar um nome em *lpszName,* você pode então chamar [Apêndice](#append) para salvar o consultardef na coleção QueryDefs do banco de dados. Caso contrário, o objeto é um consulta temporário e não é salvo. Em ambos os casos, o consultardef está em um estado aberto e você pode usá-lo para criar um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) ou chamar a função de membro [execute](#execute) do consultardef.

Se você não fornecer uma declaração SQL no *lpszSQL,* você não poderá executar a consulta com, `Execute` mas poderá usá-la para criar um conjunto de registros. Nesse caso, o MFC usa a declaração SQL padrão do conjunto de registros.

## <a name="cdaoquerydefexecute"></a><a name="execute"></a>CDaoQueryDef::Execute

Chame esta função de membro para executar a consulta definida pelo objeto querydef.

```
virtual void Execute(int nOptions = dbFailOnError);
```

### <a name="parameters"></a>Parâmetros

*nOpções*<br/>
Um inteiro que determina as características da consulta. Para obter informações relacionadas, consulte o tópico "Execute Method" no DAO Help. Você pode usar o operador bitwise-OR **(&#124;) **para combinar as seguintes constantes para este argumento:

- `dbDenyWrite`Negar permissão de gravação para outros usuários.

- `dbInconsistent`Atualizações inconsistentes.

- `dbConsistent`Atualizações consistentes.

- `dbSQLPassThrough`Passagem SQL. Faz com que a declaração SQL seja passada para um banco de dados ODBC para processamento.

- `dbFailOnError`Valor padrão. Reverter as atualizações se ocorrer um erro e reportar o erro ao usuário.

- `dbSeeChanges`Gerar um erro de tempo de execução se outro usuário estiver alterando os dados que você está editando.

> [!NOTE]
> Para obter uma explicação dos termos "inconsistente" e "consistente", consulte o tópico "Execute Method" no DAO Help.

### <a name="remarks"></a>Comentários

Os objetos querydef usados para execução desta maneira só podem representar um dos seguintes tipos de consulta:

- Consultas de ação

- Consultas de passagem SQL

`Execute`não funciona para consultas que retornam registros, como selecionar consultas. `Execute`é comumente usado para consultas de operação em massa, como **UPDATE,** **INSERT**ou **SELECT INTO,** ou para operações de linguagem de definição de dados (DDL).

> [!TIP]
> A maneira preferida de trabalhar com fontes de dados ODBC é anexar tabelas a um Microsoft Jet (. MDB) banco de dados. Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com DAO" no DAO Help.

Ligue para a função [getrecordsAffected](#getrecordsaffected) do objeto querydef para determinar `Execute` o número de registros afetados pela chamada mais recente. Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos ao executar uma consulta de ação. A contagem retornada não refletirá alterações nas tabelas relacionadas quando as atualizações ou exclusões em cascata estiverem em vigor.

Se você `dbInconsistent` incluir `dbConsistent` ambos e ou se você incluir `dbInconsistent`nenhum dos dois, o resultado é o padrão, .

`Execute`não retorna um conjunto de registros. O `Execute` uso em uma consulta que seleciona registros faz com que o MFC lance uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

## <a name="cdaoquerydefgetconnect"></a><a name="getconnect"></a>CDaoQueryDef::GetConnect

Ligue para esta função de membro para obter a seqüência de conexão associada à fonte de dados do querydef.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo a seqüência de conexão para o querydef.

### <a name="remarks"></a>Comentários

Esta função é usada apenas com fontes de dados ODBC e certos drivers ISAM. Não é usado com o Microsoft Jet (. MDB) bancos de dados; neste caso, `GetConnect` retorna uma seqüência vazia. Para obter mais informações, consulte [SetConnect](#setconnect).

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a uma . Banco de dados do MDB. Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com DAO" no DAO Help.

Para obter informações sobre strings de conexão, consulte o tópico "Connect Property" no DAO Help.

## <a name="cdaoquerydefgetdatecreated"></a><a name="getdatecreated"></a>CDaoQueryDef::GetDateCriado

Ligue para esta função de membro para obter a data em que o objeto querydef foi criado.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) contendo a data e a hora em que o consultafoi criado.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaoquerydefgetdatelastupdated"></a><a name="getdatelastupdated"></a>CDaoQueryDef::GetDateÚltimaatualização

Ligue para esta função de membro para obter a data em que o objeto querydef foi atualizado pela última vez — quando qualquer uma de suas propriedades foi alterada, como seu nome, sua seqüência de sql ou sua seqüência de conexão.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) contendo a data e a hora em que o consultafoi atualizado pela última vez.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaoquerydefgetfieldcount"></a><a name="getfieldcount"></a>CDaoQueryDef::GetFieldCount

Ligue para esta função de membro para recuperar o número de campos na consulta.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos definidos na consulta.

### <a name="remarks"></a>Comentários

`GetFieldCount`é útil para looping através de todos os campos no querydef. Para isso, `GetFieldCount` use em conjunto com [getfieldinfo](#getfieldinfo).

## <a name="cdaoquerydefgetfieldinfo"></a><a name="getfieldinfo"></a>CDaoQueryDef::GetFieldInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um campo definido no consultardef.

```
void GetFieldInfo(
    int nIndex,
    CDaoFieldInfo& fieldinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

void GetFieldInfo(
    LPCTSTR lpszName,
    CDaoFieldInfo& fieldinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do campo desejado na coleção Campos da consulta, para busca por índice.

*Fieldinfo*<br/>
Uma referência `CDaoFieldInfo` a um objeto que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o campo a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne:

- nome AFX_DAO_PRIMARY_INFO (Padrão), Tipo, Tamanho, Atributos

- AFX_DAO_SECONDARY_INFO informações primárias mais: Posição ordinal, necessária, permitir comprimento zero, campo de origem, nome estrangeiro, tabela de origem, ordem de cooperação

- AFX_DAO_ALL_INFO informações primárias e secundárias mais: Valor padrão, texto de validação, regra de validação

*lpszName*<br/>
Uma seqüência contendo o nome do campo desejado, para procurar pelo nome. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *fieldinfo,* consulte a estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md) Esta estrutura possui membros que correspondem às informações descritivas em *dwInfoOptions* acima. Se você solicitar um nível de informação, você também obterá níveis prévios de informação.

## <a name="cdaoquerydefgetname"></a><a name="getname"></a>CDaoQueryDef::GetName

Chame esta função de membro para recuperar o nome da consulta representada pelo consultardef.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

O nome da consulta.

### <a name="remarks"></a>Comentários

Nomes querydef são nomes únicos definidos pelo usuário. Para obter mais informações sobre nomes de consulta, consulte o tópico "Propriedade de nome" no DAO Help.

## <a name="cdaoquerydefgetodbctimeout"></a><a name="getodbctimeout"></a>CDaoQueryDef::GetODBCTimeout

Ligue para esta função de membro para recuperar o limite de tempo atual antes que uma consulta a uma fonte de dados ODBC seja reduzida.

```
short GetODBCTimeout();
```

### <a name="return-value"></a>Valor retornado

O número de segundos antes que uma consulta expire.

### <a name="remarks"></a>Comentários

Para obter informações sobre esse limite de tempo, consulte o tópico "ODBCTimeout Property" no DAO Help.

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um Microsoft Jet (. MDB) banco de dados. Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com DAO" no DAO Help.

## <a name="cdaoquerydefgetparametercount"></a><a name="getparametercount"></a>CDaoQueryDef::GetParameterCount

Ligue para esta função de membro para recuperar o número de parâmetros na consulta salva.

```
short GetParameterCount();
```

### <a name="return-value"></a>Valor retornado

O número de parâmetros definidos na consulta.

### <a name="remarks"></a>Comentários

`GetParameterCount`é útil para looping através de todos os parâmetros no querydef. Para isso, `GetParameterCount` use em conjunto com [getParameterInfo](#getparameterinfo).

Para obter informações relacionadas, consulte os tópicos "Objeto parâmetro", "Coleta de parâmetros" e "Declaração de PARÂMETROS (SQL)" na Ajuda da DAO.

## <a name="cdaoquerydefgetparameterinfo"></a><a name="getparameterinfo"></a>CDaoQueryDef::GetParameterInfo

Ligue para esta função de membro para obter informações sobre um parâmetro definido no consultardef.

```
void GetParameterInfo(
    int nIndex,
    CDaoParameterInfo& paraminfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

void GetParameterInfo(
    LPCTSTR lpszName,
    CDaoParameterInfo& paraminfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do parâmetro desejado na coleção parâmetros da consulta, para busca por índice.

*paraminfo*<br/>
Uma referência a um objeto [CDaoMeterInfo](../../mfc/reference/cdaoparameterinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o parâmetro a recuperar. A opção disponível está listada aqui junto com o que faz com que a função retorne:

- nome de AFX_DAO_PRIMARY_INFO (Padrão), Tipo

*lpszName*<br/>
Uma seqüência contendo o nome do parâmetro desejado, para procurar pelo nome. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *paraminfo,* consulte a estrutura [CDaoParameterInfo.](../../mfc/reference/cdaoparameterinfo-structure.md) Esta estrutura possui membros que correspondem às informações descritivas em *dwInfoOptions* acima.

Para obter informações relacionadas, consulte o tópico "Parameters Declaration (SQL)" no DAO Help.

## <a name="cdaoquerydefgetparamvalue"></a><a name="getparamvalue"></a>CDaoQueryDef::GetParamValue

Ligue para esta função de membro para recuperar o valor atual do parâmetro especificado armazenado na coleção Parâmetros da consulta.

```
virtual COleVariant GetParamValue(LPCTSTR lpszName);
virtual COleVariant GetParamValue(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do parâmetro cujo valor você quer, para procurar pelo nome.

*nIndex*<br/>
O índice baseado em zero do parâmetro na coleção parâmetros da consulta, para busca por índice. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).

### <a name="return-value"></a>Valor retornado

Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.

### <a name="remarks"></a>Comentários

Você pode acessar o parâmetro pelo nome ou pela sua posição ordinal na coleção.

Para obter informações relacionadas, consulte o tópico "Parameters Declaration (SQL)" no DAO Help.

## <a name="cdaoquerydefgetrecordsaffected"></a><a name="getrecordsaffected"></a>CDaoQueryDef::GetRecordsAffected

Ligue para esta função de membro para determinar quantos registros foram afetados pela última chamada de [Execute](#execute).

```
long GetRecordsAffected();
```

### <a name="return-value"></a>Valor retornado

O número de registros afetados.

### <a name="remarks"></a>Comentários

A contagem retornada não refletirá alterações nas tabelas relacionadas quando as atualizações ou exclusões em cascata estiverem em vigor.

Para obter informações relacionadas, consulte o tópico "Registrosde propriedade afetada" na Ajuda da DAO.

## <a name="cdaoquerydefgetreturnsrecords"></a><a name="getreturnsrecords"></a>CDaoQueryDef::GetReturnsRecords

Ligue para esta função de membro para determinar se o consultardef é baseado em uma consulta que retorna registros.

```
BOOL GetReturnsRecords();
```

### <a name="return-value"></a>Valor retornado

Não zero se o consultadef for baseado em uma consulta que retorna registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro é usada apenas para consultas de passagem SQL. Para obter mais informações sobre as consultas SQL, consulte a função [Executar](#execute) membro. Para obter mais informações sobre como trabalhar com consultas de passagem SQL, consulte a função de membro [SetReturnsRecord.](#setreturnsrecords)

Para obter informações relacionadas, consulte o tópico "ReturnsRecords Property" no DAO Help.

## <a name="cdaoquerydefgetsql"></a><a name="getsql"></a>CDaoQueryDef::GetSQL

Chame esta função de membro para recuperar a declaração SQL que define a consulta na qual o consultardef é baseado.

```
CString GetSQL();
```

### <a name="return-value"></a>Valor retornado

A declaração SQL que define a consulta na qual o consultardef é baseado.

### <a name="remarks"></a>Comentários

Você provavelmente analisará a seqüência de palavras-chave, nomes de mesa, e assim por diante.

Para obter informações relacionadas, consulte os tópicos "Propriedade SQL", "Comparação do Microsoft Jet Database Engine SQL e ANSI SQL" e "Consultando um banco de dados com SQL em Código" na Ajuda da DAO.

## <a name="cdaoquerydefgettype"></a><a name="gettype"></a>CDaoQueryDef::GetType

Ligue para esta função de membro para determinar o tipo de consulta do querydef.

```
short GetType();
```

### <a name="return-value"></a>Valor retornado

O tipo de consulta definida pelo querydef. Para valores, consulte Observações.

### <a name="remarks"></a>Comentários

O tipo de consulta é definido pelo que você especifica na seqüência SQL do querydef quando você cria o consultardef ou chama a função de membro [SetSQL](#setsql) de um consulta existente. O tipo de consulta retornado por esta função pode ser um dos seguintes valores:

- `dbQSelect`Selecione

- `dbQAction`Ação

- `dbQCrosstab`Guia cruzada

- `dbQDelete`Excluir

- `dbQUpdate` Update (atualizar)

- `dbQAppend`Acrescentar

- `dbQMakeTable`Make-table

- `dbQDDL`Definição de dados

- `dbQSQLPassThrough`Passagem

- `dbQSetOperation`União

- `dbQSPTBulk`Usado `dbQSQLPassThrough` para especificar uma consulta que não retorna registros.

> [!NOTE]
> Para criar uma consulta de passagem SQL, `dbSQLPassThrough` não defina a constante. Isso é definido automaticamente pelo mecanismo de banco de dados Microsoft Jet quando você cria um objeto querydef e define a seqüência de conexões.

Para obter informações sobre as strings SQL, consulte [GetSQL](#getsql). Para obter informações sobre os tipos de consulta, consulte [Executar](#execute).

## <a name="cdaoquerydefisopen"></a><a name="isopen"></a>CDaoQueryDef::IsOpen

Ligue para esta função `CDaoQueryDef` de membro para determinar se o objeto está aberto no momento.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `CDaoQueryDef` se o objeto estiver atualmente aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um consultadef deve estar em um estado aberto antes de usá-lo para chamar [Execute](#execute) ou para criar um objeto [CDaoRecordset.](../../mfc/reference/cdaorecordset-class.md) Para colocar um consultadef em uma chamada de estado [aberto, crie](#create) (para um novo consultadef) ou [Abra](#open) (para um consultadef existente).

## <a name="cdaoquerydefm_pdatabase"></a><a name="m_pdatabase"></a>CDaoQueryDef::m_pDatabase

Contém um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado ao objeto querydef.

### <a name="remarks"></a>Comentários

Use este ponteiro se você precisar acessar o banco de dados diretamente — por exemplo, para obter ponteiros para outros objetos de querydef ou recordset nas coleções do banco de dados.

## <a name="cdaoquerydefm_pdaoquerydef"></a><a name="m_pdaoquerydef"></a>CDaoQueryDef::m_pDAOQueryDef

Contém um ponteiro para a interface OLE para o objeto DAO querydef subjacente.

### <a name="remarks"></a>Comentários

Este ponteiro é fornecido para completude e consistência com as outras classes. No entanto, como o MFC encapsula totalmente as consultas da DAO, é improvável que você precise dele. Se você usá-lo, faça-o com cautela - em particular, não mude o valor do ponteiro a menos que você saiba o que está fazendo.

## <a name="cdaoquerydefopen"></a><a name="open"></a>CDaoQueryDef::Aberto

Ligue para esta função de membro para abrir um consultadef previamente salvo na coleção QueryDefs do banco de dados.

```
virtual void Open(LPCTSTR lpszName = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma string que contém o nome do consulta salvo para abrir. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Uma vez que o consultadef esteja aberto, você pode chamar sua função [execute](#execute) member ou usar o querydef para criar um objeto [CDaoRecordset.](../../mfc/reference/cdaorecordset-class.md)

## <a name="cdaoquerydefsetconnect"></a><a name="setconnect"></a>CDaoQueryDef::SetConnect

Ligue para esta função de membro para definir a seqüência de conexão do objeto querydef.

```
void SetConnect(LPCTSTR lpszConnect);
```

### <a name="parameters"></a>Parâmetros

*lpszConnect*<br/>
Uma string que contém uma seqüência de conexões para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado.

### <a name="remarks"></a>Comentários

A seqüência de conexões é usada para passar informações adicionais para o ODBC e certos drivers ISAM conforme necessário. Não é usado para Microsoft Jet (. BASES de dados do MDB.

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a uma . Banco de dados do MDB.

Antes de executar um consultadef que representa uma consulta de passagem SQL a uma fonte `SetConnect` de dados ODBC, defina a seqüência de conexões com e chame [SetReturnsRecords](#setreturnsrecords) para especificar se a consulta retorna registros.

Para obter mais informações sobre a estrutura da seqüência de conexão e exemplos de componentes de seqüência de conexão, consulte o tópico "Connect Property" no DAO Help.

## <a name="cdaoquerydefsetname"></a><a name="setname"></a>CDaoQueryDef::SetName

Chame esta função de membro se quiser alterar o nome de uma consulta que não seja temporária.

```
void SetName(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma seqüência que contém o novo nome para uma consulta não temporária no objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado.

### <a name="remarks"></a>Comentários

Os nomes de querydef são nomes únicos e definidos pelo usuário. Você pode `SetName` ligar antes que o objeto querydef seja anexado à coleção QueryDefs.

## <a name="cdaoquerydefsetodbctimeout"></a><a name="setodbctimeout"></a>CDaoQueryDef::SetODBCTimeout

Ligue para esta função de membro para definir o prazo antes de uma consulta a uma fonte de dados ODBC.

```
void SetODBCTimeout(short nODBCTimeout);
```

### <a name="parameters"></a>Parâmetros

*nODBCTimeout*<br/>
O número de segundos antes que uma consulta expire.

### <a name="remarks"></a>Comentários

Essa função de membro permite que você anule o número padrão de segundos antes das operações subseqüentes na fonte de dados conectada "time out". Uma operação pode ser deshorada devido a problemas de acesso à rede, tempo de processamento de consulta excessiva, e assim por diante. Ligue `SetODBCTimeout` antes de executar uma consulta com esta consultadef se quiser alterar o valor de tempo de consulta. (À medida que o ODBC reutiliza as conexões, o valor de tempo máximo é o mesmo para todos os clientes na mesma conexão.)

O valor padrão para intervalos de consulta é de 60 segundos.

## <a name="cdaoquerydefsetparamvalue"></a><a name="setparamvalue"></a>CDaoQueryDef::SetParamValue

Chame esta função de membro para definir o valor de um parâmetro no querydef no tempo de execução.

```
virtual void SetParamValue(
    LPCTSTR lpszName,
    const COleVariant& varValue);

virtual void SetParamValue(
    int nIndex,
    const COleVariant& varValue);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja definir.

*varValue*<br/>
O valor a ser definido; ver Observações.

*nIndex*<br/>
A posição ordinal do parâmetro na coleção de Parâmetros da consulta. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).

### <a name="remarks"></a>Comentários

O parâmetro já deve ter sido estabelecido como parte da seqüência SQL do querydef. Você pode acessar o parâmetro pelo nome ou pela sua posição ordinal na coleção.

Especifique o `COleVariant` valor a ser definido como um objeto. Para obter informações sobre como definir `COleVariant` o valor e o tipo desejados no objeto, consulte [classe COleVariant](../../mfc/reference/colevariant-class.md).

## <a name="cdaoquerydefsetreturnsrecords"></a><a name="setreturnsrecords"></a>CDaoQueryDef::SetReturnsRecords

Chame essa função de membro como parte do processo de configuração de uma consulta de passagem SQL para um banco de dados externo.

```
void SetReturnsRecords(BOOL bReturnsRecords);
```

### <a name="parameters"></a>Parâmetros

*bReturnsRecords*<br/>
Passe TRUE se a consulta em um banco de dados externo retornar registros; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Nesse caso, você deve criar o consultardef e `CDaoQueryDef` definir suas propriedades usando outras funções de membro. Para obter uma descrição de bancos de dados externos, consulte [SetConnect](#setconnect).

## <a name="cdaoquerydefsetsql"></a><a name="setsql"></a>CDaoQueryDef::SetSQL

Ligue para esta função de membro para definir a declaração SQL que o querydef executa.

```
void SetSQL(LPCTSTR lpszSQL);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Uma seqüência contendo uma declaração SQL completa, adequada para execução. A sintaxe dessa string depende do DBMS que sua consulta visa. Para uma discussão sobre a sintaxe usada no mecanismo de banco de dados do Microsoft Jet, consulte o tópico "Construindo declarações sql em código" no DAO Help.

### <a name="remarks"></a>Comentários

Um uso `SetSQL` típico de é configurar um objeto querydef para uso em uma consulta de passagem SQL. (Para obter a sintaxe das consultas de passagem SQL no seu DBMS de destino, consulte a documentação do seu DBMS.)

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
