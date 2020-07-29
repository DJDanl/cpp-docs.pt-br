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
ms.openlocfilehash: fabb8e957ffaf8ab8d9d57bca8e7835d366ac390
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231813"
---
# <a name="cdaoquerydef-class"></a>Classe CDaoQueryDef

Representa uma definição de consulta, ou "QueryDef", geralmente uma salva em um banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoQueryDef : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef::CDaoQueryDef](#cdaoquerydef)|Constrói um objeto `CDaoQueryDef`. Próxima chamada `Open` ou `Create` , dependendo de suas necessidades.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef:: Append](#append)|Anexa o querydef à coleção QueryDefs do banco de dados como uma consulta salva.|
|[CDaoQueryDef:: CanUpdate](#canupdate)|Retornará zero se a consulta puder atualizar o banco de dados.|
|[CDaoQueryDef:: fechar](#close)|Fecha o objeto QueryDef. Destrua o objeto C++ quando terminar com ele.|
|[CDaoQueryDef:: criar](#create)|Cria o objeto de QueryDef do DAO subjacente. Use o querydef como uma consulta temporária ou chame `Append` para salvá-lo no banco de dados.|
|[CDaoQueryDef:: execute](#execute)|Executa a consulta definida pelo objeto QueryDef.|
|[CDaoQueryDef:: GetConnect](#getconnect)|Retorna a cadeia de conexão associada ao QueryDef. A cadeia de conexão identifica a fonte de dados. (Somente para consultas de passagem SQL; caso contrário, uma cadeia de caracteres vazia.)|
|[CDaoQueryDef::GetDateCreated](#getdatecreated)|Retorna a data em que a consulta salva foi criada.|
|[CDaoQueryDef::GetDateLastUpdated](#getdatelastupdated)|Retorna a data em que a consulta salva foi atualizada pela última vez.|
|[CDaoQueryDef::GetFieldCount](#getfieldcount)|Retorna o número de campos definidos pelo QueryDef.|
|[CDaoQueryDef:: GetFieldInfo](#getfieldinfo)|Retorna informações sobre um campo especificado definido na consulta.|
|[CDaoQueryDef:: GetName](#getname)|Retorna o nome do QueryDef.|
|[CDaoQueryDef::GetODBCTimeout](#getodbctimeout)|Retorna o valor de tempo limite usado pelo ODBC (para uma consulta ODBC) quando o querydef é executado. Isso determina por quanto tempo permitir que a ação da consulta seja concluída.|
|[CDaoQueryDef:: GetParameterCount](#getparametercount)|Retorna o número de parâmetros definidos para a consulta.|
|[CDaoQueryDef:: GetParameterInfo](#getparameterinfo)|Retorna informações sobre um parâmetro especificado para a consulta.|
|[CDaoQueryDef:: GetParamValue](#getparamvalue)|Retorna o valor de um parâmetro especificado para a consulta.|
|[CDaoQueryDef::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetados por uma consulta de ação.|
|[CDaoQueryDef::GetReturnsRecords](#getreturnsrecords)|Retornará zero se a consulta definida pelo QueryDef retornar registros.|
|[CDaoQueryDef::GetSQL](#getsql)|Retorna a cadeia de caracteres SQL que especifica a consulta definida pelo QueryDef.|
|[CDaoQueryDef:: GetType](#gettype)|Retorna o tipo de consulta: excluir, atualizar, acrescentar, criar-tabela e assim por diante.|
|[CDaoQueryDef:: IsOpen](#isopen)|Retornará zero se o querydef estiver aberto e puder ser executado.|
|[CDaoQueryDef:: abrir](#open)|Abre um QueryDef existente armazenado na coleção QueryDefs do banco de dados.|
|[CDaoQueryDef:: SetConnect](#setconnect)|Define a cadeia de conexão para uma consulta de passagem SQL em uma fonte de dados ODBC.|
|[CDaoQueryDef:: SetName](#setname)|Define o nome da consulta salva, substituindo o nome em uso quando o querydef foi criado.|
|[CDaoQueryDef::SetODBCTimeout](#setodbctimeout)|Define o valor de tempo limite usado pelo ODBC (para uma consulta ODBC) quando o querydef é executado.|
|[CDaoQueryDef:: SetParamValue](#setparamvalue)|Define o valor de um parâmetro especificado para a consulta.|
|[CDaoQueryDef::SetReturnsRecords](#setreturnsrecords)|Especifica se o querydef retorna registros. A definição desse atributo como TRUE só é válida para consultas de passagem do SQL.|
|[CDaoQueryDef::SetSQL](#setsql)|Define a cadeia de caracteres SQL que especifica a consulta definida pelo QueryDef.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoQueryDef:: m_pDAOQueryDef](#m_pdaoquerydef)|Um ponteiro para a interface OLE para o objeto de QueryDef do DAO subjacente.|
|[CDaoQueryDef:: m_pDatabase](#m_pdatabase)|Um ponteiro para o `CDaoDatabase` objeto ao qual o querydef está associado. O querydef pode ser salvo no banco de dados ou não.|

## <a name="remarks"></a>Comentários

Um QueryDef é um objeto de acesso a dados que contém a instrução SQL que descreve uma consulta e suas propriedades, como "data de criação" e "tempo limite do ODBC". Você também pode criar objetos QueryDef temporários sem salvá-los, mas é conveniente — e muito mais eficiente — para salvar consultas comumente reutilizadas em um banco de dados. Um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) mantém uma coleção, chamada de coleção QueryDefs, que contém seu QueryDefs salvo.

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC baseadas no DAO são mais compatíveis do que as classes do MFC baseadas no ODBC; as classes baseadas em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. As classes baseadas em DAO também oferecem suporte a operações DDL (linguagem de definição de dados), como a adição de tabelas por meio de classes, sem a necessidade de chamar o DAO diretamente.

## <a name="usage"></a>Uso

Use os objetos querydef para trabalhar com uma consulta salva existente ou para criar uma nova consulta salva ou uma consulta temporária:

1. Em todos os casos, primeiro Construa um `CDaoQueryDef` objeto, fornecendo um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ao qual a consulta pertence.

1. Em seguida, faça o seguinte, dependendo do que você deseja:

   - Para usar uma consulta salva existente, chame a função de membro [Open](#open) do objeto QueryDef, fornecendo o nome da consulta salva.

   - Para criar uma nova consulta salva, chame a função de membro [Create](#create) do objeto QueryDef, fornecendo o nome da consulta. Em seguida, chame [Append](#append) para salvar a consulta anexando-a à coleção QueryDefs do banco de dados. `Create`coloca a QueryDef em um estado aberto, portanto, depois de chamar `Create` você não chama `Open` .

   - Para criar um QueryDef temporário, chame `Create` . Passe uma cadeia de caracteres vazia para o nome da consulta. Não chame `Append`.

Quando você terminar de usar um objeto QueryDef, chame sua função de membro de [fechamento](#close) ; em seguida, destrua o objeto QueryDef.

> [!TIP]
> A maneira mais fácil de criar consultas salvas é criá-las e armazená-las em seu banco de dados usando o Microsoft Access. Em seguida, você pode abri-los e usá-los em seu código MFC.

## <a name="purposes"></a>Metas

Você pode usar um objeto querydef para qualquer uma das seguintes finalidades:

- Para criar um `CDaoRecordset` objeto

- Para chamar a função de `Execute` membro do objeto para executar diretamente uma consulta de ação ou uma consulta de passagem SQL

Você pode usar um objeto querydef para qualquer tipo de consulta, incluindo seleção, ação, tabela de referência cruzada, exclusão, atualização, acréscimo, marca-tabelas, definição de dados, passagem SQL, União e consultas em massa. O tipo da consulta é determinado pelo conteúdo da instrução SQL que você fornece. Para obter informações sobre tipos de consulta, consulte as `Execute` funções de membro e [GetType](#gettype) . Os conjuntos de registros são comumente usados para consultas de retorno de linha, geralmente aqueles que usam **Select... DE** palavras-chave. `Execute`é mais comumente usado para operações em massa. Para obter mais informações, consulte [Execute](#execute) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

## <a name="querydefs-and-recordsets"></a>QueryDefs e conjuntos de registros

Para usar um objeto querydef para criar um `CDaoRecordset` objeto, você normalmente cria ou abre um QueryDef conforme descrito acima. Em seguida, construa um objeto recordset, passando um ponteiro para o objeto QueryDef quando você chamar [CDaoRecordset:: Open](../../mfc/reference/cdaorecordset-class.md#open). O querydef que você passa deve estar em um estado aberto. Para obter mais informações, consulte Class [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Você não pode usar um querydef para criar um conjunto de registros (o uso mais comum para um QueryDef), a menos que esteja em um estado aberto. Coloque o querydef em um estado aberto chamando `Open` ou `Create` .

## <a name="external-databases"></a>Bancos de dados externos

Os objetos QueryDef são a maneira preferida de usar o dialeto SQL nativo de um mecanismo de banco de dados externo. Por exemplo, você pode criar uma consulta Transact SQL (conforme usado em Microsoft SQL Server) e armazená-la em um objeto QueryDef. Quando você precisa usar uma consulta SQL não baseada no mecanismo de banco de dados do Microsoft Jet, você deve fornecer uma cadeia de conexão que aponte para a fonte de dados externa. As consultas com cadeias de conexão válidas ignoram o mecanismo de banco de dados e passam a consulta diretamente para o servidor de banco de dados externo para processamento.

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um Microsoft Jet (. MDB).

Para obter informações relacionadas, consulte os tópicos "objeto QueryDef", "coleção QueryDefs" e "objeto CdbDatabase" no SDK do DAO.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoQueryDef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="cdaoquerydefappend"></a><a name="append"></a>CDaoQueryDef:: Append

Chame essa função de membro depois de chamar [Create](#create) para criar um novo objeto QueryDef.

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

`Append`salva o querydef no banco de dados acrescentando o objeto à coleção QueryDefs do banco de dados. Você pode usar o querydef como um objeto temporário sem acrescentá-lo, mas se quiser que ele persista, você deve chamar `Append` .

Se você tentar acrescentar um objeto QueryDef temporário, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

## <a name="cdaoquerydefcanupdate"></a><a name="canupdate"></a>CDaoQueryDef:: CanUpdate

Chame essa função de membro para determinar se você pode modificar o querydef — como alterar seu nome ou a cadeia de caracteres SQL.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se você tiver permissão para modificar o querydef; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode modificar o querydef se:

- Ele não se baseia em um banco de dados que está aberto como somente leitura.

- Você tem permissões de atualização para o banco de dados.

   Isso depende se você implementou recursos de segurança. O MFC não oferece suporte à segurança; Você mesmo deve implementá-lo chamando o DAO diretamente ou usando o Microsoft Access. Consulte o tópico "Propriedade Permissions" na ajuda do DAO.

## <a name="cdaoquerydefcdaoquerydef"></a><a name="cdaoquerydef"></a>CDaoQueryDef::CDaoQueryDef

Constrói um objeto `CDaoQueryDef`.

```
CDaoQueryDef(CDaoDatabase* pDatabase);
```

### <a name="parameters"></a>parâmetros

*pDatabase*<br/>
Um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) aberto.

### <a name="remarks"></a>Comentários

O objeto pode representar um QueryDef existente armazenado na coleção QueryDefs do banco de dados, uma nova consulta a ser armazenada na coleção ou uma consulta temporária, não a ser armazenada. A próxima etapa depende do tipo de QueryDef:

- Se o objeto representar um QueryDef existente, chame a função de membro [Open](#open) do objeto para inicializá-lo.

- Se o objeto representar um novo QueryDef a ser salvo, chame a função de membro [Create](#create) do objeto. Isso adiciona o objeto à coleção QueryDefs do banco de dados. Em seguida, chame `CDaoQueryDef` as funções de membro para definir os atributos do objeto. Por fim, chame [Append](#append).

- Se o objeto representar um QueryDef temporário (não deve ser salvo no banco de dados), chame `Create` , passando uma cadeia de caracteres vazia para o nome da consulta. Depois de chamar `Create` , inicialize o querydef definindo diretamente seus atributos. Não chame `Append`.

Para definir os atributos de QueryDef, você pode usar as funções de membro [SetName](#setname), [SetSQL](#setsql), [SetConnect](#setconnect), [SetODBCTimeout](#setodbctimeout)e [SetReturnsRecords](#setreturnsrecords) .

Quando terminar com o objeto QueryDef, chame sua função de membro de [fechamento](#close) . Se você tiver um ponteiro para o querydef, use o **`delete`** operador para destruir o objeto C++.

## <a name="cdaoquerydefclose"></a><a name="close"></a>CDaoQueryDef:: fechar

Chame essa função de membro quando terminar de usar o objeto QueryDef.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Fechar o querydef libera o objeto DAO subjacente, mas não destrói o objeto DAO QueryDef salvo ou o `CDaoQueryDef` objeto C++. Isso não é o mesmo que [CDaoDatabase::D eletequerydef](../../mfc/reference/cdaodatabase-class.md#deletequerydef), que exclui o querydef da coleção QueryDefs do banco de dados no DAO (se não for um QueryDef temporário).

## <a name="cdaoquerydefcreate"></a><a name="create"></a>CDaoQueryDef:: criar

Chame essa função de membro para criar uma nova consulta salva ou uma nova consulta temporária.

```
virtual void Create(
    LPCTSTR lpszName = NULL,
    LPCTSTR lpszSQL = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
O nome exclusivo da consulta salva no banco de dados. Para obter detalhes sobre a cadeia de caracteres, consulte o tópico "método CreateQueryDef" na ajuda do DAO. Se você aceitar o valor padrão, uma cadeia de caracteres vazia, um QueryDef temporário será criado. Essa consulta não é salva na coleção QueryDefs.

*lpszSQL*<br/>
A cadeia de caracteres SQL que define a consulta. Se você aceitar o valor padrão de NULL, deverá chamar [SetSQL](#setsql) posteriormente para definir a cadeia de caracteres. Até lá, a consulta é indefinida. No entanto, você pode usar a consulta indefinida para abrir um conjunto de registros; consulte comentários para obter detalhes. A instrução SQL deve ser definida antes que você possa acrescentar a QueryDef à coleção QueryDefs.

### <a name="remarks"></a>Comentários

Se você passar um nome em *lpszName*, poderá chamar [Append](#append) para salvar o querydef na coleção QueryDefs do banco de dados. Caso contrário, o objeto será um QueryDef temporário e não será salvo. Em ambos os casos, o querydef está em um estado aberto e você pode usá-lo para criar um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) ou chamar a função de membro [Execute](#execute) de QueryDef.

Se você não fornecer uma instrução SQL em *lpszSQL*, não poderá executar a consulta com `Execute` , mas poderá usá-la para criar um conjunto de registros. Nesse caso, o MFC usa a instrução SQL padrão do conjunto de registros.

## <a name="cdaoquerydefexecute"></a><a name="execute"></a>CDaoQueryDef:: execute

Chame essa função de membro para executar a consulta definida pelo objeto QueryDef.

```
virtual void Execute(int nOptions = dbFailOnError);
```

### <a name="parameters"></a>parâmetros

*nOptions*<br/>
Um inteiro que determina as características da consulta. Para obter informações relacionadas, consulte o tópico "executar método" na ajuda do DAO. Você pode usar o operador-OR-bit-a-OR ( **&#124;**) para combinar as seguintes constantes para este argumento:

- `dbDenyWrite`Negar permissão de gravação para outros usuários.

- `dbInconsistent`Atualizações inconsistentes.

- `dbConsistent`Atualizações consistentes.

- `dbSQLPassThrough`Passagem SQL. Faz com que a instrução SQL seja passada para um banco de dados ODBC para processamento.

- `dbFailOnError`Valor padrão. Reverter atualizações se ocorrer um erro e relatar o erro ao usuário.

- `dbSeeChanges`Gerar um erro de tempo de execução se outro usuário estiver alterando os dados que você está editando.

> [!NOTE]
> Para obter uma explicação dos termos "inconsistentes" e "consistente", consulte o tópico "executar método" na ajuda do DAO.

### <a name="remarks"></a>Comentários

Os objetos QueryDef usados para execução dessa maneira só podem representar um dos seguintes tipos de consulta:

- Consultas de ação

- Consultas de passagem do SQL

`Execute`Não funciona para consultas que retornam registros, como consultas SELECT. `Execute`normalmente é usado para consultas de operação em massa, como **Atualizar**, **Inserir**ou **selecionar em**, ou para operações DDL (linguagem de definição de dados).

> [!TIP]
> A maneira preferida de trabalhar com fontes de dados ODBC é anexar tabelas a um Microsoft Jet (. MDB). Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com o DAO" na ajuda do DAO.

Chame a função membro [GetRecordsAffected](#getrecordsaffected) do objeto querydef para determinar o número de registros afetados pela chamada mais recente `Execute` . Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos ao executar uma consulta de ação. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando atualizações ou exclusões em cascata estiverem em vigor.

Se você incluir `dbInconsistent` e `dbConsistent` ou se você não incluir nenhum, o resultado será o padrão, `dbInconsistent` .

`Execute`Não retorna um conjunto de registros. `Execute`O uso de em uma consulta que seleciona registros faz com que o MFC lance uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

## <a name="cdaoquerydefgetconnect"></a><a name="getconnect"></a>CDaoQueryDef:: GetConnect

Chame essa função de membro para obter a cadeia de conexão associada à fonte de dados de QueryDef.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém a cadeia de conexão para o querydef.

### <a name="remarks"></a>Comentários

Essa função é usada somente com fontes de dados ODBC e determinados drivers ISAM. Ele não é usado com o Microsoft Jet (. MDB) bancos de dados; Nesse caso, `GetConnect` retorna uma cadeia de caracteres vazia. Para obter mais informações, consulte [SetConnect](#setconnect).

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um. Banco de dados MDB. Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com o DAO" na ajuda do DAO.

Para obter informações sobre cadeias de conexão, consulte o tópico "conectar Propriedade" na ajuda do DAO.

## <a name="cdaoquerydefgetdatecreated"></a><a name="getdatecreated"></a>CDaoQueryDef::GetDateCreated

Chame essa função de membro para obter a data em que o objeto QueryDef foi criado.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data e a hora em que o querydef foi criado.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

## <a name="cdaoquerydefgetdatelastupdated"></a><a name="getdatelastupdated"></a>CDaoQueryDef::GetDateLastUpdated

Chame essa função de membro para obter a data em que o objeto QueryDef foi atualizado pela última vez — quando qualquer uma de suas propriedades foi alterada, como seu nome, sua cadeia de caracteres SQL ou sua cadeia de conexão.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data e a hora em que o querydef foi atualizado pela última vez.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

## <a name="cdaoquerydefgetfieldcount"></a><a name="getfieldcount"></a>CDaoQueryDef::GetFieldCount

Chame essa função de membro para recuperar o número de campos na consulta.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos definidos na consulta.

### <a name="remarks"></a>Comentários

`GetFieldCount`é útil para executar um loop por todos os campos no QueryDef. Para essa finalidade, use `GetFieldCount` em conjunto com [GetFieldInfo](#getfieldinfo).

## <a name="cdaoquerydefgetfieldinfo"></a><a name="getfieldinfo"></a>CDaoQueryDef:: GetFieldInfo

Chame essa função de membro para obter vários tipos de informações sobre um campo definido em QueryDef.

```cpp
void GetFieldInfo(
    int nIndex,
    CDaoFieldInfo& fieldinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

void GetFieldInfo(
    LPCTSTR lpszName,
    CDaoFieldInfo& fieldinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do campo desejado na coleção de campos de QueryDef, para pesquisa por índice.

*FieldInfo*<br/>
Uma referência a um `CDaoFieldInfo` objeto que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o campo a recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne:

- AFX_DAO_PRIMARY_INFO (padrão) nome, tipo, tamanho, atributos

- AFX_DAO_SECONDARY_INFO Informações primárias mais: posição ordinal, obrigatória, permitir comprimento zero, campo de origem, nome estrangeiro, tabela de origem, ordem de agrupamento

- AFX_DAO_ALL_INFO Informações primárias e secundárias mais: valor padrão, texto de validação, regra de validação

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome do campo desejado, para pesquisa por nome. Você pode usar uma [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *FieldInfo*, consulte a estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) . Essa estrutura tem membros que correspondem às informações descritivas em *dwInfoOptions* acima. Se você solicitar um nível de informação, obterá quaisquer níveis de informações anteriores também.

## <a name="cdaoquerydefgetname"></a><a name="getname"></a>CDaoQueryDef:: GetName

Chame essa função de membro para recuperar o nome da consulta representada pelo QueryDef.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

O nome da consulta.

### <a name="remarks"></a>Comentários

Os nomes de QueryDef são nomes exclusivos definidos pelo usuário. Para obter mais informações sobre nomes de QueryDef, consulte o tópico "Name Property" na ajuda do DAO.

## <a name="cdaoquerydefgetodbctimeout"></a><a name="getodbctimeout"></a>CDaoQueryDef::GetODBCTimeout

Chame essa função de membro para recuperar o limite de tempo atual antes que uma consulta a uma fonte de dados ODBC expire.

```
short GetODBCTimeout();
```

### <a name="return-value"></a>Valor retornado

O número de segundos antes que uma consulta expire.

### <a name="remarks"></a>Comentários

Para obter informações sobre esse limite de tempo, consulte o tópico "Propriedade ODBCTimeout" na ajuda do DAO.

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um Microsoft Jet (. MDB). Para obter mais informações, consulte o tópico "Acessando bancos de dados externos com o DAO" na ajuda do DAO.

## <a name="cdaoquerydefgetparametercount"></a><a name="getparametercount"></a>CDaoQueryDef:: GetParameterCount

Chame essa função de membro para recuperar o número de parâmetros na consulta salva.

```
short GetParameterCount();
```

### <a name="return-value"></a>Valor retornado

O número de parâmetros definidos na consulta.

### <a name="remarks"></a>Comentários

`GetParameterCount`é útil para executar um loop por todos os parâmetros em QueryDef. Para essa finalidade, use `GetParameterCount` em conjunto com [GetParameterInfo](#getparameterinfo).

Para obter informações relacionadas, consulte os tópicos "objeto de parâmetro", "coleção de parâmetros" e "declaração de parâmetros (SQL)" na ajuda do DAO.

## <a name="cdaoquerydefgetparameterinfo"></a><a name="getparameterinfo"></a>CDaoQueryDef:: GetParameterInfo

Chame essa função de membro para obter informações sobre um parâmetro definido em QueryDef.

```cpp
void GetParameterInfo(
    int nIndex,
    CDaoParameterInfo& paraminfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

void GetParameterInfo(
    LPCTSTR lpszName,
    CDaoParameterInfo& paraminfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do parâmetro desejado na coleção de parâmetros do QueryDef, para pesquisa por índice.

*paraminfo*<br/>
Uma referência a um objeto [CDaoParameterInfo](../../mfc/reference/cdaoparameterinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o parâmetro a recuperar. A opção disponível está listada aqui, junto com o que faz com que a função retorne:

- AFX_DAO_PRIMARY_INFO (padrão) nome, tipo

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome do parâmetro desejado, para pesquisa por nome. Você pode usar uma [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Para obter uma descrição das informações retornadas em *paraminfo*, consulte a estrutura [CDaoParameterInfo](../../mfc/reference/cdaoparameterinfo-structure.md) . Essa estrutura tem membros que correspondem às informações descritivas em *dwInfoOptions* acima.

Para obter informações relacionadas, consulte o tópico "declaração de parâmetros (SQL)" na ajuda do DAO.

## <a name="cdaoquerydefgetparamvalue"></a><a name="getparamvalue"></a>CDaoQueryDef:: GetParamValue

Chame essa função de membro para recuperar o valor atual do parâmetro especificado armazenado na coleção de parâmetros do QueryDef.

```
virtual COleVariant GetParamValue(LPCTSTR lpszName);
virtual COleVariant GetParamValue(int nIndex);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja, para pesquisa por nome.

*nIndex*<br/>
O índice de base zero do parâmetro na coleção de parâmetros do QueryDef, para pesquisa por índice. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).

### <a name="return-value"></a>Valor retornado

Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.

### <a name="remarks"></a>Comentários

Você pode acessar o parâmetro por nome ou pela sua posição ordinal na coleção.

Para obter informações relacionadas, consulte o tópico "declaração de parâmetros (SQL)" na ajuda do DAO.

## <a name="cdaoquerydefgetrecordsaffected"></a><a name="getrecordsaffected"></a>CDaoQueryDef::GetRecordsAffected

Chame essa função de membro para determinar quantos registros foram afetados pela última chamada de [Execute](#execute).

```
long GetRecordsAffected();
```

### <a name="return-value"></a>Valor retornado

O número de registros afetados.

### <a name="remarks"></a>Comentários

A contagem retornada não refletirá as alterações nas tabelas relacionadas quando atualizações ou exclusões em cascata estiverem em vigor.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordsAffected" na ajuda do DAO.

## <a name="cdaoquerydefgetreturnsrecords"></a><a name="getreturnsrecords"></a>CDaoQueryDef::GetReturnsRecords

Chame essa função de membro para determinar se o querydef se baseia em uma consulta que retorna registros.

```
BOOL GetReturnsRecords();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o querydef for baseado em uma consulta que retorna registros; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é usada somente para consultas de passagem SQL. Para obter mais informações sobre consultas SQL, consulte a função [executar](#execute) membro. Para obter mais informações sobre como trabalhar com consultas de passagem do SQL, consulte a função membro [SetReturnsRecords](#setreturnsrecords) .

Para obter informações relacionadas, consulte o tópico "Propriedade ReturnsRecords" na ajuda do DAO.

## <a name="cdaoquerydefgetsql"></a><a name="getsql"></a>CDaoQueryDef::GetSQL

Chame essa função de membro para recuperar a instrução SQL que define a consulta na qual o querydef se baseia.

```
CString GetSQL();
```

### <a name="return-value"></a>Valor retornado

A instrução SQL que define a consulta na qual o querydef se baseia.

### <a name="remarks"></a>Comentários

Em seguida, você provavelmente analisará a cadeia de caracteres para palavras-chave, nomes de tabela e assim por diante.

Para obter informações relacionadas, consulte os tópicos "Propriedade SQL", "comparação do Microsoft Jet Mecanismo de Banco de Dados SQL e ANSI SQL" e "consultando um banco de dados com SQL no código" na ajuda do DAO.

## <a name="cdaoquerydefgettype"></a><a name="gettype"></a>CDaoQueryDef:: GetType

Chame essa função de membro para determinar o tipo de consulta de QueryDef.

```
short GetType();
```

### <a name="return-value"></a>Valor retornado

O tipo da consulta definida pelo QueryDef. Para valores, consulte comentários.

### <a name="remarks"></a>Comentários

O tipo de consulta é definido pelo que você especificar na cadeia de caracteres SQL do QueryDef ao criar o querydef ou chamar uma função de membro [SetSQL](#setsql) de QueryDef existente. O tipo de consulta retornado por essa função pode ser um dos seguintes valores:

- `dbQSelect`Não

- `dbQAction`Action

- `dbQCrosstab`Referência cruzada

- `dbQDelete` Delete (excluir)

- `dbQUpdate` Update (atualizar)

- `dbQAppend`Anexar

- `dbQMakeTable`Criar tabela

- `dbQDDL`Definição de dados

- `dbQSQLPassThrough`Passagem

- `dbQSetOperation`Unida

- `dbQSPTBulk`Usado com `dbQSQLPassThrough` para especificar uma consulta que não retorna registros.

> [!NOTE]
> Para criar uma consulta de passagem SQL, não defina a `dbSQLPassThrough` constante. Isso é definido automaticamente pelo mecanismo de banco de dados do Microsoft Jet quando você cria um objeto QueryDef e define a cadeia de conexão.

Para obter informações sobre cadeias de caracteres SQL, consulte [GetSQL](#getsql). Para obter informações sobre tipos de consulta, consulte [Execute](#execute).

## <a name="cdaoquerydefisopen"></a><a name="isopen"></a>CDaoQueryDef:: IsOpen

Chame essa função de membro para determinar se o `CDaoQueryDef` objeto está aberto no momento.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o `CDaoQueryDef` objeto estiver aberto no momento; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um QueryDef deve estar em um estado aberto antes de você usá-lo para chamar [Execute](#execute) ou para criar um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) . Para colocar um QueryDef em uma chamada de estado aberto, [crie](#create) (para um novo QueryDef) ou [abra](#open) (para um QueryDef existente).

## <a name="cdaoquerydefm_pdatabase"></a><a name="m_pdatabase"></a>CDaoQueryDef:: m_pDatabase

Contém um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado ao objeto QueryDef.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar o banco de dados diretamente — por exemplo, para obter ponteiros para outros objetos QueryDef ou Recordset nas coleções do banco de dados.

## <a name="cdaoquerydefm_pdaoquerydef"></a><a name="m_pdaoquerydef"></a>CDaoQueryDef:: m_pDAOQueryDef

Contém um ponteiro para a interface OLE para o objeto de QueryDef do DAO subjacente.

### <a name="remarks"></a>Comentários

Esse ponteiro é fornecido para fins de integridade e consistência com as outras classes. No entanto, como o MFC encapsula totalmente o DAO QueryDefs, é improvável que você precise dele. Se você usá-lo, faça isso com cautela – em particular, não altere o valor do ponteiro, a menos que você saiba o que está fazendo.

## <a name="cdaoquerydefopen"></a><a name="open"></a>CDaoQueryDef:: abrir

Chame essa função de membro para abrir um QueryDef salvo anteriormente na coleção QueryDefs do banco de dados.

```
virtual void Open(LPCTSTR lpszName = NULL);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome do QueryDef salvo a ser aberto. Você pode usar uma [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Quando o querydef estiver aberto, você poderá chamar sua função [executar](#execute) membro ou usar o querydef para criar um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) .

## <a name="cdaoquerydefsetconnect"></a><a name="setconnect"></a>CDaoQueryDef:: SetConnect

Chame essa função de membro para definir a cadeia de conexão do objeto QueryDef.

```cpp
void SetConnect(LPCTSTR lpszConnect);
```

### <a name="parameters"></a>parâmetros

*lpszConnect*<br/>
Uma cadeia de caracteres que contém uma cadeia de conexão para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado.

### <a name="remarks"></a>Comentários

A cadeia de conexão é usada para transmitir informações adicionais ao ODBC e a determinados drivers ISAM, conforme necessário. Ele não é usado para o Microsoft Jet (. MDB).

> [!TIP]
> A maneira preferida de trabalhar com tabelas ODBC é anexá-las a um. Banco de dados MDB.

Antes de executar um QueryDef que representa uma consulta de passagem SQL para uma fonte de dados ODBC, defina a cadeia de conexão com `SetConnect` e chame [SetReturnsRecords](#setreturnsrecords) para especificar se a consulta retorna registros.

Para obter mais informações sobre a estrutura da cadeia de conexão e exemplos de componentes de cadeia de conexão, consulte o tópico "conectar Propriedade" na ajuda do DAO.

## <a name="cdaoquerydefsetname"></a><a name="setname"></a>CDaoQueryDef:: SetName

Chame essa função de membro se desejar alterar o nome de um QueryDef que não seja temporário.

```cpp
void SetName(LPCTSTR lpszName);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Uma cadeia de caracteres que contém o novo nome para uma consulta não temporária no objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) associado.

### <a name="remarks"></a>Comentários

Os nomes de QueryDef são nomes exclusivos definidos pelo usuário. Você pode chamar `SetName` antes que o objeto QueryDef seja acrescentado à coleção QueryDefs.

## <a name="cdaoquerydefsetodbctimeout"></a><a name="setodbctimeout"></a>CDaoQueryDef::SetODBCTimeout

Chame essa função de membro para definir o limite de tempo antes que uma consulta a uma fonte de dados ODBC expire.

```cpp
void SetODBCTimeout(short nODBCTimeout);
```

### <a name="parameters"></a>parâmetros

*nODBCTimeout*<br/>
O número de segundos antes que uma consulta expire.

### <a name="remarks"></a>Comentários

Essa função de membro permite que você substitua o número padrão de segundos antes das operações subsequentes na fonte de dados conectada "tempo limite". Uma operação pode atingir o tempo limite devido a problemas de acesso à rede, tempo excessivo de processamento de consultas e assim por diante. Chame `SetODBCTimeout` antes de executar uma consulta com este QueryDef se você quiser alterar o valor de tempo limite da consulta. (Como o ODBC reutiliza conexões, o valor de tempo limite é o mesmo para todos os clientes na mesma conexão.)

O valor padrão para tempos limite de consulta é de 60 segundos.

## <a name="cdaoquerydefsetparamvalue"></a><a name="setparamvalue"></a>CDaoQueryDef:: SetParamValue

Chame essa função de membro para definir o valor de um parâmetro em QueryDef em tempo de execução.

```
virtual void SetParamValue(
    LPCTSTR lpszName,
    const COleVariant& varValue);

virtual void SetParamValue(
    int nIndex,
    const COleVariant& varValue);
```

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja definir.

*varValue*<br/>
O valor a ser definido; consulte comentários.

*nIndex*<br/>
A posição ordinal do parâmetro na coleção de parâmetros do QueryDef. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).

### <a name="remarks"></a>Comentários

O parâmetro já deve ter sido estabelecido como parte da cadeia de caracteres SQL de QueryDef. Você pode acessar o parâmetro por nome ou pela sua posição ordinal na coleção.

Especifique o valor a ser definido como um `COleVariant` objeto. Para obter informações sobre como definir o valor desejado e o tipo em seu `COleVariant` objeto, consulte classe [COleVariant](../../mfc/reference/colevariant-class.md).

## <a name="cdaoquerydefsetreturnsrecords"></a><a name="setreturnsrecords"></a>CDaoQueryDef::SetReturnsRecords

Chame essa função de membro como parte do processo de configuração de uma consulta de passagem SQL para um banco de dados externo.

```cpp
void SetReturnsRecords(BOOL bReturnsRecords);
```

### <a name="parameters"></a>parâmetros

*bReturnsRecords*<br/>
Passe TRUE se a consulta em um banco de dados externo retornar registros; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Nesse caso, você deve criar o querydef e definir suas propriedades usando outras funções de `CDaoQueryDef` membro. Para obter uma descrição dos bancos de dados externos, consulte [SetConnect](#setconnect).

## <a name="cdaoquerydefsetsql"></a><a name="setsql"></a>CDaoQueryDef::SetSQL

Chame essa função de membro para definir a instrução SQL que o querydef executa.

```cpp
void SetSQL(LPCTSTR lpszSQL);
```

### <a name="parameters"></a>parâmetros

*lpszSQL*<br/>
Uma cadeia de caracteres que contém uma instrução SQL completa, adequada para execução. A sintaxe dessa cadeia de caracteres depende do DBMS que sua consulta tem como destino. Para obter uma discussão sobre a sintaxe usada no mecanismo de banco de dados do Microsoft Jet, consulte o tópico "criando instruções SQL no código" na ajuda do DAO.

### <a name="remarks"></a>Comentários

Um uso típico do `SetSQL` é a configuração de um objeto querydef para uso em uma consulta de passagem do SQL. (Para obter a sintaxe de consultas de passagem do SQL em seu DBMS de destino, consulte a documentação do DBMS.)

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
