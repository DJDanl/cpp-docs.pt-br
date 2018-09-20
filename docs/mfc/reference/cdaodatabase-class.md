---
title: Classe CDaoDatabase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoDatabase
- AFXDAO/CDaoDatabase
- AFXDAO/CDaoDatabase::CDaoDatabase
- AFXDAO/CDaoDatabase::CanTransact
- AFXDAO/CDaoDatabase::CanUpdate
- AFXDAO/CDaoDatabase::Close
- AFXDAO/CDaoDatabase::Create
- AFXDAO/CDaoDatabase::CreateRelation
- AFXDAO/CDaoDatabase::DeleteQueryDef
- AFXDAO/CDaoDatabase::DeleteRelation
- AFXDAO/CDaoDatabase::DeleteTableDef
- AFXDAO/CDaoDatabase::Execute
- AFXDAO/CDaoDatabase::GetConnect
- AFXDAO/CDaoDatabase::GetName
- AFXDAO/CDaoDatabase::GetQueryDefCount
- AFXDAO/CDaoDatabase::GetQueryDefInfo
- AFXDAO/CDaoDatabase::GetQueryTimeout
- AFXDAO/CDaoDatabase::GetRecordsAffected
- AFXDAO/CDaoDatabase::GetRelationCount
- AFXDAO/CDaoDatabase::GetRelationInfo
- AFXDAO/CDaoDatabase::GetTableDefCount
- AFXDAO/CDaoDatabase::GetTableDefInfo
- AFXDAO/CDaoDatabase::GetVersion
- AFXDAO/CDaoDatabase::IsOpen
- AFXDAO/CDaoDatabase::Open
- AFXDAO/CDaoDatabase::SetQueryTimeout
- AFXDAO/CDaoDatabase::m_pDAODatabase
- AFXDAO/CDaoDatabase::m_pWorkspace
dev_langs:
- C++
helpviewer_keywords:
- CDaoDatabase [MFC], CDaoDatabase
- CDaoDatabase [MFC], CanTransact
- CDaoDatabase [MFC], CanUpdate
- CDaoDatabase [MFC], Close
- CDaoDatabase [MFC], Create
- CDaoDatabase [MFC], CreateRelation
- CDaoDatabase [MFC], DeleteQueryDef
- CDaoDatabase [MFC], DeleteRelation
- CDaoDatabase [MFC], DeleteTableDef
- CDaoDatabase [MFC], Execute
- CDaoDatabase [MFC], GetConnect
- CDaoDatabase [MFC], GetName
- CDaoDatabase [MFC], GetQueryDefCount
- CDaoDatabase [MFC], GetQueryDefInfo
- CDaoDatabase [MFC], GetQueryTimeout
- CDaoDatabase [MFC], GetRecordsAffected
- CDaoDatabase [MFC], GetRelationCount
- CDaoDatabase [MFC], GetRelationInfo
- CDaoDatabase [MFC], GetTableDefCount
- CDaoDatabase [MFC], GetTableDefInfo
- CDaoDatabase [MFC], GetVersion
- CDaoDatabase [MFC], IsOpen
- CDaoDatabase [MFC], Open
- CDaoDatabase [MFC], SetQueryTimeout
- CDaoDatabase [MFC], m_pDAODatabase
- CDaoDatabase [MFC], m_pWorkspace
ms.assetid: 8ff5b342-964d-449d-bef1-d0ff56aadf6d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6cf84b2e5709a4ac31965501005b5260499a3213
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408798"
---
# <a name="cdaodatabase-class"></a>Classe CDaoDatabase

Representa uma conexão a um banco de dados por meio do qual você pode operar nos dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoDatabase : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CDaoDatabase](#cdaodatabase)|Constrói um objeto `CDaoDatabase`. Chamar `Open` para conectar-se o objeto para um banco de dados.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CanTransact](#cantransact)|Retorna diferente de zero se o banco de dados oferece suporte a transações.|
|[CDaoDatabase::CanUpdate](#canupdate)|Retorna se diferente de zero a `CDaoDatabase` objeto é atualizável (não somente leitura).|
|[CDaoDatabase::Close](#close)|Fecha a conexão de banco de dados.|
|[CDaoDatabase::Create](#create)|Cria o objeto de banco de dados DAO subjacente e inicializa o `CDaoDatabase` objeto.|
|[CDaoDatabase::CreateRelation](#createrelation)|Define uma nova relação entre as tabelas no banco de dados.|
|[CDaoDatabase::DeleteQueryDef](#deletequerydef)|Exclui um objeto querydef salvo na coleção QueryDefs do banco de dados.|
|[CDaoDatabase::DeleteRelation](#deleterelation)|Exclui uma relação existente entre as tabelas no banco de dados.|
|[CDaoDatabase::DeleteTableDef](#deletetabledef)|Exclui a definição de uma tabela no banco de dados. Isso exclui a tabela real e todos os seus dados.|
|[CDaoDatabase::Execute](#execute)|Executa uma consulta de ação. Chamar `Execute` para uma consulta que retorna resultados gera uma exceção.|
|[CDaoDatabase::GetConnect](#getconnect)|Retorna a cadeia de conexão usada para conectar-se a `CDaoDatabase` objeto para um banco de dados. Usado para ODBC.|
|[CDaoDatabase::GetName](#getname)|Retorna o nome do banco de dados atualmente em uso.|
|[CDaoDatabase::GetQueryDefCount](#getquerydefcount)|Retorna o número de consultas definidas para o banco de dados.|
|[CDaoDatabase::GetQueryDefInfo](#getquerydefinfo)|Retorna informações sobre uma consulta especificada no banco de dados.|
|[CDaoDatabase::GetQueryTimeout](#getquerytimeout)|Retorna o número de segundos após o qual banco de dados de operações de consulta atingirá o tempo limite. Afeta todos os próximos abrir, adicionar um novo, atualizar e editar operações e outras operações em fontes de dados ODBC (somente) como `Execute` chamadas.|
|[CDaoDatabase::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetado pela última atualização, editar ou Adicionar operação ou por uma chamada para `Execute`.|
|[CDaoDatabase::GetRelationCount](#getrelationcount)|Retorna o número de relações definidas entre tabelas no banco de dados.|
|[CDaoDatabase::GetRelationInfo](#getrelationinfo)|Retorna informações sobre uma relação especificada definida entre tabelas no banco de dados.|
|[Cdaodatabase:: Gettabledefcount](#gettabledefcount)|Retorna o número de tabelas definidas no banco de dados.|
|[Cdaodatabase:: Gettabledefinfo](#gettabledefinfo)|Retorna informações sobre uma tabela especificada no banco de dados.|
|[CDaoDatabase::GetVersion](#getversion)|Retorna a versão do mecanismo de banco de dados associado com o banco de dados.|
|[CDaoDatabase::IsOpen](#isopen)|Retorna se diferente de zero a `CDaoDatabase` objeto está atualmente conectado a um banco de dados.|
|[CDaoDatabase::Open](#open)|Estabelece uma conexão a um banco de dados.|
|[CDaoDatabase::SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual banco de dados de operações (em fontes de dados ODBC apenas) consulta atingirá o tempo limite. Afeta todos os próximos abre, adicionar um novo, atualiza e excluir operações.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::m_pDAODatabase](#m_pdaodatabase)|Um ponteiro para o objeto de banco de dados subjacente do DAO.|
|[CDaoDatabase::m_pWorkspace](#m_pworkspace)|Um ponteiro para o [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto que contém o banco de dados e define seu espaço de transação.|

## <a name="remarks"></a>Comentários

Para obter informações sobre os formatos de banco de dados com suporte, consulte o [GetName](../../mfc/reference/cdaoworkspace-class.md#getname) função de membro. Você pode ter um ou mais `CDaoDatabase` objetos ativos por vez em um determinado "espaço de trabalho," representado por um [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto. O espaço de trabalho mantém uma coleção de objetos de banco de dados aberto, chamados da coleção de bancos de dados.

> [!NOTE]
>  As classes de banco de dados MFC DAO são diferentes das classes de banco de dados MFC com base em ODBC. Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Classe `CDaoDatabase` fornece uma interface semelhante da classe ODBC [CDatabase](../../mfc/reference/cdatabase-class.md). A principal diferença é que `CDatabase` acessa o DBMS por meio da conectividade aberta de banco de dados (ODBC) e um driver ODBC desse DBMS. `CDaoDatabase` acessa os dados por meio de uma Data Access Object (DAO) baseado no mecanismo de banco de dados do Microsoft Jet. Em geral, as classes do MFC com base em DAO são mais capacitadas que as classes do MFC com base em ODBC; as classes com base em DAO podem acessar dados, incluindo por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. As classes com base em DAO também dão suporte a operações de linguagem de definição de dados (DDL), como adicionar tabelas por meio de classes, sem a necessidade de chamar diretamente o DAO.

## <a name="usage"></a>Uso

Você pode criar objetos de banco de dados implicitamente, quando você cria objetos de conjunto de registros. Mas você também pode criar objetos de banco de dados explicitamente. Para usar um banco de dados explicitamente com `CDaoDatabase`, siga um destes procedimentos:

- Construir uma `CDaoDatabase` objeto, passando um ponteiro para um aberto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto.

- Ou construir uma `CDaoDatabase` objeto sem especificar o espaço de trabalho (MFC cria um objeto de espaço de trabalho temporário).

Para criar um novo Microsoft Jet (. Banco de dados MDB), construir uma `CDaoDatabase` objeto e chame seu [criar](#create) função de membro. Fazer *não* chamar `Open` depois `Create`.

Para abrir o banco de dados existente, construir uma `CDaoDatabase` objeto e chame seu [abrir](#open) função de membro.

Qualquer uma dessas técnicas acrescenta o objeto de banco de dados DAO à coleção de bancos de dados do espaço de trabalho e abre uma conexão aos dados. Quando você constrói, em seguida, [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md), [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md), ou [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) objetos para a operação de banco de dados conectada, passe os construtores para esses objetos um ponteiro para sua `CDaoDatabase` objeto. Quando você terminar de usar a conexão, chame o [feche](#close) membro de função e destruir o `CDaoDatabase` objeto. `Close` Fecha a quaisquer conjuntos de registros que não tenha fechado anteriormente.

## <a name="transactions"></a>Transações

Processamento de transações do banco de dados é fornecido no nível do espaço de trabalho — consulte os [BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans), [CommitTrans](../../mfc/reference/cdaoworkspace-class.md#committrans), e [reversão](../../mfc/reference/cdaoworkspace-class.md#rollback) funções membro da classe `CDaoWorkspace` .

## <a name="odbc-connections"></a>Conexões ODBC

A maneira recomendada para trabalhar com fontes de dados ODBC é anexar tabelas externas para um Microsoft Jet (. Banco de dados MDB).

## <a name="collections"></a>Coleções

Cada banco de dados mantém seus próprio coleções de tabledef, querydef, conjunto de registros e objetos de relação. Classe `CDaoDatabase` fornece funções de membro para manipular esses objetos.

> [!NOTE]
>  Os objetos são armazenados em DAO, não está no objeto de banco de dados do MFC. MFC fornece classes para objetos tabledef, querydef e conjunto de registros, mas não para objetos de relação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoDatabase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

##  <a name="cantransact"></a>  CDaoDatabase::CanTransact

Chame essa função de membro para determinar se o banco de dados permite que as transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o banco de dados oferece suporte a transações; Caso contrário, 0.

### <a name="remarks"></a>Comentários

As transações são gerenciadas no espaço de trabalho do banco de dados.

##  <a name="canupdate"></a>  CDaoDatabase::CanUpdate

Chame essa função de membro para determinar se o `CDaoDatabase` objeto permite atualizações.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o `CDaoDatabase` objeto permite atualizações; caso contrário, 0, indicando que você passado verdadeira *bReadOnly* quando você abriu o `CDaoDatabase` objeto ou que o próprio banco de dados é somente leitura. Consulte a [abrir](#open) função de membro.

### <a name="remarks"></a>Comentários

Para obter informações sobre a capacidade de atualização do banco de dados, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.

##  <a name="cdaodatabase"></a>  CDaoDatabase::CDaoDatabase

Constrói um objeto `CDaoDatabase`.

```
CDaoDatabase(CDaoWorkspace* pWorkspace = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWorkspace*<br/>
Um ponteiro para o `CDaoWorkspace` objeto que contém o novo objeto de banco de dados. Se você aceitar o valor padrão de NULL, o construtor cria um temporário `CDaoWorkspace` objeto que usa o espaço de trabalho padrão DAO. Você pode obter um ponteiro para o objeto de espaço de trabalho por meio de [m_pWorkspace](#m_pworkspace) membro de dados.

### <a name="remarks"></a>Comentários

Depois de construir o objeto, se você estiver criando um novo Microsoft Jet (. MDB) do banco de dados, chame o objeto [criar](#create) função de membro. Se, em vez disso, a abertura de um banco de dados existente, chame o objeto [abrir](#open) função de membro.

Quando você terminar com o objeto, você deve chamar seu [feche](#close) membro de função e, em seguida, destrua o `CDaoDatabase` objeto.

Talvez seja conveniente para incorporar o `CDaoDatabase` objeto em sua classe de documento.

> [!NOTE]
>  Um `CDaoDatabase` objeto também é criado implicitamente se você abrir um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto sem passar um ponteiro para um existente `CDaoDatabase` objeto. Este objeto de banco de dados é fechado quando você fecha o objeto recordset.

##  <a name="close"></a>  CDaoDatabase::Close

Chame essa função de membro para desconectar de um banco de dados e feche quaisquer conjuntos de registros abertos, tabledefs e querydefs associado com o banco de dados.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

É recomendável fechar esses objetos por conta própria antes de chamar essa função de membro. Fechando uma `CDaoDatabase` objeto remove da coleção de bancos de dados associado ao [espaço de trabalho](../../mfc/reference/cdaoworkspace-class.md). Porque `Close` não destrói o `CDaoDatabase` do objeto, você pode reutilizar o objeto abrindo o mesmo banco de dados ou outro banco de dados.

> [!CAUTION]
>  Chame o [atualização](../../mfc/reference/cdaorecordset-class.md#update) função de membro (se houver edições pendentes) e o `Close` a função de membro em todos os objetos de conjunto de registros abertos antes de fechar um banco de dados. Se você sair de uma função que declara [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) ou `CDaoDatabase` objetos na pilha, o banco de dados é fechado, as alterações não salvas serão perdidas, todas as transações pendentes serão revertidas e todas as edições pendentes aos seus dados são perdidas.

> [!CAUTION]
>  Se você tentar fechar um objeto de banco de dados enquanto os objetos de conjunto de registros estão abertos, ou se você tentar fechar um objeto de espaço de trabalho enquanto quaisquer objetos de banco de dados que pertencem a esse espaço de trabalho específico estão abertos, esses objetos de conjunto de registros serão fechados e quaisquer atualizações ou edições pendentes serão revertida. Se você tentar fechar um objeto de espaço de trabalho enquanto quaisquer objetos de banco de dados que pertencem a ele estão abertos, a operação fecha todos os objetos de banco de dados que pertencem a esse objeto de espaço de trabalho específico, o que pode resultar em objetos de conjunto de registros não fechada que está sendo fechados. Se você não fechar o objeto de banco de dados, o MFC relata uma falha de asserção em compilações de depuração.

Se o objeto de banco de dados está definido fora do escopo de uma função e a função sair sem fechá-lo, o objeto de banco de dados permanecerá aberto até que explicitamente fechada ou o módulo no qual ele é definido está fora do escopo.

##  <a name="create"></a>  CDaoDatabase::Create

Para criar um novo Microsoft Jet (. MDB) do banco de dados, chame essa função membro depois que você construir um `CDaoDatabase` objeto.

```
virtual void Create(
    LPCTSTR lpszName,
    LPCTSTR lpszLocale = dbLangGeneral,
    int dwOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de cadeia de caracteres que é o nome do arquivo de banco de dados que você está criando. Ele pode ser o caminho completo e nome de arquivo, como "c:\\\MYDB. MDB". Você deve fornecer um nome. Se você não fornecer uma extensão de nome de arquivo. MDB é acrescentado. Se a rede oferecer suporte a uniform naming convention (UNC), você pode também especificar um caminho de rede, como "\\\\\\\MYSERVER\\\MYSHARE\\\MYDIR\\\MYDB". Somente o Microsoft Jet (. Arquivos de banco de dados do MDB) podem ser criados usando essa função de membro. (Barras invertidas duplas são necessárias em literais de cadeia de caracteres como "\\" é o caractere de escape do C++.)

*lpszLocale*<br/>
Uma expressão de cadeia de caracteres usada para especificar a ordem de agrupamento para criar o banco de dados. O valor padrão é `dbLangGeneral`. Os possíveis valores são:

- `dbLangGeneral` Inglês, alemão, francês, português, italiano e modernos espanhol

- `dbLangArabic` Árabe

- `dbLangCyrillic` Russo

- `dbLangCzech` Tcheco

- `dbLangDutch` Holandês

- `dbLangGreek` Grego

- `dbLangHebrew` Hebraico

- `dbLangHungarian` Húngaro

- `dbLangIcelandic` Islandês

- `dbLangNordic` Idiomas nórdicos (mecanismo Microsoft Jet banco de dados versão 1.0 somente)

- `dbLangNorwdan` Norueguês e dinamarquês

- `dbLangPolish` Polonês

- `dbLangSpanish` Espanhol tradicional

- `dbLangSwedfin` Sueco e finlandês

- `dbLangTurkish` Turco

*dwOptions*<br/>
Um inteiro que indica uma ou mais opções. Os possíveis valores são:

- `dbEncrypt` Crie um banco de dados criptografado.

- `dbVersion10` Crie um banco de dados com a versão de banco de dados Microsoft Jet 1.0.

- `dbVersion11` Crie um banco de dados com a versão de banco de dados Microsoft Jet 1.1.

- `dbVersion20` Crie um banco de dados com a versão de banco de dados Microsoft Jet 2.0.

- `dbVersion30` Crie um banco de dados com a versão de banco de dados Microsoft Jet 3.0.

Se você omitir a constante de criptografia, é criado um banco de dados não criptografado. Você pode especificar apenas uma constante de versão. Se você omitir uma constante de versão, um banco de dados que usa a versão do banco de dados Microsoft Jet 3.0 é criado.

> [!CAUTION]
>  Se um banco de dados não estiver criptografado, é possível, mesmo se você implementar a segurança de usuário e senha, para ler diretamente o arquivo de disco binário que constitui o banco de dados.

### <a name="remarks"></a>Comentários

`Create` cria o arquivo de banco de dados e o objeto de banco de dados DAO subjacente e inicializa o objeto de C++. O objeto é acrescentado à coleção de bancos de dados do espaço de trabalho associado. O objeto de banco de dados está em um estado aberto; Não chame `Open*` depois de `Create`.

> [!NOTE]
>  Com `Create`, você pode criar somente o Microsoft Jet (. Bancos de dados MDB). Você não pode criar bancos de dados ISAM ou bancos de dados ODBC.

##  <a name="createrelation"></a>  CDaoDatabase::CreateRelation

Chame essa função de membro para estabelecer uma relação entre um ou mais campos em uma tabela primária no banco de dados e um ou mais campos em uma tabela externa (outra tabela no banco de dados).

```
void CreateRelation(
    LPCTSTR lpszName,
    LPCTSTR lpszTable,
    LPCTSTR lpszForeignTable,
    long lAttributes,
    LPCTSTR lpszField,
    LPCTSTR lpszForeignField);

void CreateRelation(CDaoRelationInfo& relinfo);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome exclusivo do objeto relation. O nome deve começar com uma letra e pode conter no máximo 40 caracteres. Ele pode incluir números e sublinhado caracteres, mas não pode incluir espaços ou pontuação.

*lpszTable*<br/>
O nome da tabela primária na relação. Se a tabela não existir, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

*lpszForeignTable*<br/>
O nome da tabela externa na relação. Se a tabela não existir, o MFC gera uma exceção do tipo `CDaoException`.

*lAttributes*<br/>
Um valor longo que contém informações sobre o tipo de relação. Você pode usar esse valor para impor a integridade referencial, entre outras coisas. Você pode usar o operador OR bit a bit ( **&#124;**) para combinar qualquer um dos valores a seguir (desde que a combinação faz sentido):

- `dbRelationUnique` Relação é-para-um.

- `dbRelationDontEnforce` Relação não é imposta (não há integridade referencial).

- `dbRelationInherited` Existe uma relação em um banco de dados não atual que contém as duas tabelas anexadas.

- `dbRelationUpdateCascade` As atualizações ocorrerão em cascata (para obter mais informações sobre cascatas, consulte comentários).

- `dbRelationDeleteCascade` Exclusões ocorrerão em cascata.

*lpszField*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um campo na tabela primária (chamado por *lpszTable*).

*lpszForeignField*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um campo da tabela externa (chamado por *lpszForeignTable*).

*relinfo*<br/>
Uma referência a um [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto que contém informações sobre a relação que você deseja criar.

### <a name="remarks"></a>Comentários

A relação não pode envolver uma consulta ou uma tabela anexada de um banco de dados externa.

Use a primeira versão da função quando o parceiro envolve um campo em cada uma das duas tabelas. Use a segunda versão quando o parceiro envolve vários campos. O número máximo de campos em uma relação é 14.

Essa ação cria um objeto de relação subjacente do DAO, mas esse é um detalhe de implementação do MFC, pois o encapsulamento do MFC de objetos de relação está contido na classe `CDaoDatabase`. MFC não fornece uma classe para relações.

Se você definir a relação de atributos do objeto para ativar operações cascade, o mecanismo de banco de dados automaticamente atualiza ou exclui registros em uma ou mais tabelas quando são feitas alterações às tabelas de chave primárias relacionadas.

Por exemplo, suponha que você estabelecer uma relação de exclusão em cascata entre uma tabela clientes e uma tabela de pedidos. Quando você exclui registros da tabela de clientes, os registros na tabela de pedidos relacionados a esse cliente também serão excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela de pedidos e outras tabelas, registros dessas tabelas são excluídos automaticamente quando você exclui registros da tabela Customers.

Para obter informações relacionadas, consulte o tópico "CreateRelation Method" na Ajuda do DAO.

##  <a name="deletequerydef"></a>  CDaoDatabase::DeleteQueryDef

Chame essa função de membro para excluir querydef especificado — consulta salva — da `CDaoDatabase` QueryDefs de coleção objeto da.

```
void DeleteQueryDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da consulta salva para excluir.

### <a name="remarks"></a>Comentários

Depois disso, essa consulta não está mais definida no banco de dados.

Para obter informações sobre como criar objetos de querydef, consulte a classe [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Um objeto querydef passa a ser associado um determinado `CDaoDatabase` do objeto ao construir o `CDaoQueryDef` objeto, passando a ele um ponteiro para o objeto de banco de dados.

##  <a name="deleterelation"></a>  CDaoDatabase::DeleteRelation

Chame essa função de membro para excluir uma relação existente da coleção de relações do objeto de banco de dados.

```
void DeleteRelation(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do parceiro para excluir.

### <a name="remarks"></a>Comentários

Depois disso, a relação não existe.

Para obter informações relacionadas, consulte o tópico "Método Delete" na Ajuda do DAO.

##  <a name="deletetabledef"></a>  CDaoDatabase::DeleteTableDef

Chame essa função de membro para excluir a tabela especificada e todos os seus dados a partir de `CDaoDatabase` TableDefs de coleção objeto da.

```
void DeleteTableDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do tabledef para excluir.

### <a name="remarks"></a>Comentários

Depois disso, essa tabela não está mais definida no banco de dados.

> [!NOTE]
>  Tenha muito cuidado para não excluir tabelas do sistema.

Para obter informações sobre como criar objetos tabledef, consulte a classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md). Um objeto tabledef passa a ser associado um determinado `CDaoDatabase` do objeto ao construir o `CDaoTableDef` objeto, passando a ele um ponteiro para o objeto de banco de dados.

Para obter informações relacionadas, consulte o tópico "Método Delete" na Ajuda do DAO.

##  <a name="execute"></a>  CDaoDatabase::Execute

Chame essa função de membro para executar uma consulta de ação ou executar uma instrução SQL no banco de dados.

```
void Execute(
    LPCTSTR lpszSQL,
    int nOptions = dbFailOnError);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém um comando SQL válido seja executado.

*nOptions*<br/>
Um inteiro que especifica as opções relacionadas à integridade da consulta. Você pode usar o operador OR bit a bit ( **&#124;**) para combinar qualquer uma das seguintes constantes (desde que a combinação faz sentido — por exemplo, você não iria combinar `dbInconsistent` com `dbConsistent`):

- `dbDenyWrite` Nega a permissão de gravação a outros usuários.

- `dbInconsistent` (Padrão) Atualizações inconsistentes.

- `dbConsistent` Atualizações consistentes.

- `dbSQLPassThrough` Passagem SQL. Faz com que a instrução SQL a serem passados para uma fonte de dados ODBC para processamento.

- `dbFailOnError` Reverta atualizações se ocorrer um erro.

- `dbSeeChanges` Gere um erro de tempo de execução se outro usuário está mudando de dados que você está editando.

> [!NOTE]
>  Se os dois `dbInconsistent` e `dbConsistent` são incluídos ou se nenhuma for incluída, o resultado é o padrão. Para obter uma explicação das constantes, consulte o tópico "Executar o método" na Ajuda do DAO.

### <a name="remarks"></a>Comentários

`Execute` funciona somente para consultas de ação ou consultas de passagem de SQL que não retornam resultados. Ele não funciona para consultas select, que retornam registros.

Para obter uma definição e informações sobre consultas de ação, consulte os tópicos "Consulta de ação" e "Executar o método" na Ajuda do DAO.

> [!TIP]
>  Dada uma instrução SQL sintaticamente correta e permissões adequadas, o `Execute` função de membro não falhará, mesmo se não for uma única linha pode ser modificada ou excluída. Portanto, sempre use a `dbFailOnError` opção ao usar o `Execute` a função de membro para executar uma atualização ou consulta de exclusão. Essa opção faz com que o MFC lançar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) e reverte todas as alterações com êxito se qualquer um dos registros afetados estão bloqueados e não pode ser atualizada ou excluída. Observe que você sempre possa chamar `GetRecordsAffected` para ver quantos registros foram afetado.

Chame o [GetRecordsAffected](#getrecordsaffected) função de membro do objeto de banco de dados para determinar o número de registros afetados pela mais recente `Execute` chamar. Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos ao executar uma consulta de ação. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando cascade atualiza ou exclui estão em vigor.

`Execute` não retorna um conjunto de registros. Usando o `Execute` em uma consulta que seleciona os registros faz com que o MFC lançar uma exceção do tipo `CDaoException`. (Não há nenhuma `ExecuteSQL` análogo à função de membro `CDatabase::ExecuteSQL`.)

##  <a name="getconnect"></a>  CDaoDatabase::GetConnect

Chame essa função de membro para recuperar a cadeia de conexão usada para se conectar a `CDaoDatabase` objeto para um banco de dados ODBC ou ISAM.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor de retorno

A conexão de cadeia de caracteres se [abrir](#open) foi chamado com êxito em uma fonte de dados do ODBC; caso contrário, uma cadeia de caracteres vazia. Para um Microsoft Jet (. Banco de dados MDB), a cadeia de caracteres sempre está vazia, a menos que você pode defini-lo para uso com o `dbSQLPassThrough` opção usada com o [Execute](#execute) função de membro ou usada na abertura de um conjunto de registros.

### <a name="remarks"></a>Comentários

A cadeia de caracteres fornece informações sobre a origem de um banco de dados aberto ou um banco de dados usados em uma consulta de passagem. A cadeia de caracteres de conexão é composta de um especificador de tipo de banco de dados e zero ou mais parâmetros separados por ponto e vírgula.

> [!NOTE]
>  Usando as classes MFC DAO para se conectar a uma fonte de dados por meio de ODBC é menos eficiente do que conectar-se por meio de uma tabela anexada.

> [!NOTE]
>  A cadeia de caracteres de conexão é usada para passar informações adicionais para ODBC e alguns drivers ISAM conforme necessário. Ele não é usado para. Bancos de dados do MDB. Para tabelas base do banco de dados Microsoft Jet, a cadeia de caracteres de conexão é uma cadeia de caracteres vazia (""), exceto quando você usá-lo para uma consulta de passagem SQL conforme descrito em retornar valor acima.

Consulte a [abrir](#open) função de membro para obter uma descrição de como a cadeia de caracteres de conexão é criada. Depois que a cadeia de caracteres de conexão foi definida no `Open` chamada, você pode posteriormente usá-lo para verificar a configuração para determinar o tipo de fonte de dados ODBC, a senha ou a ID de usuário do banco de dados, de caminho.

##  <a name="getname"></a>  CDaoDatabase::GetName

Chame essa função de membro para recuperar o nome do que o banco de dados aberto no momento, o que é o nome de um arquivo de banco de dados existente ou o nome de uma fonte de dados ODBC registrada.

```
CString GetName();
```

### <a name="return-value"></a>Valor de retorno

O caminho completo e nome de arquivo do banco de dados se for bem-sucedido; Caso contrário, vazio [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Se a rede oferecer suporte a uniform naming convention (UNC), você também pode especificar um caminho de rede — por exemplo, "\\\\\\\MYSERVER\\\MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras invertidas duplas são necessárias em literais de cadeia de caracteres como "\\" é o caractere de escape do C++.)

Por exemplo, convém exibir esse nome em um título. Se ocorrer um erro enquanto o nome está sendo recuperado, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

> [!NOTE]
>  Para melhorar o desempenho quando os bancos de dados externos são acessados, é recomendável que você anexar tabelas de banco de dados externo para um banco de dados Microsoft Jet (. MDB) em vez de conectar diretamente à fonte de dados.

O tipo de banco de dados é indicado pelo arquivo ou diretório que o caminho aponta, da seguinte maneira:

|Nome de caminho aponta para...|Tipo de banco de dados|
|--------------------------|-------------------|
|. Arquivo MDB|Banco de dados Microsoft Jet (Microsoft Access)|
|Diretório que contém. Arquivos DBF|banco de dados do dBASE|
|Diretório que contém. Arquivo XLS|Banco de dados do Microsoft Excel|
|Diretório que contém. PDX arquivo (s)|Banco de dados Paradox|
|Diretório que contém os arquivos de banco de dados de texto formatado adequadamente|Banco de dados de formato de texto|

Para bancos de dados ODBC, como o SQL Server e Oracle, a cadeia de caracteres de conexão do banco de dados identifica um nome de fonte de dados (DSN) que é registrado pelo ODBC.

##  <a name="getquerydefcount"></a>  CDaoDatabase::GetQueryDefCount

Chame essa função de membro para recuperar o número de consultas definidas na coleção QueryDefs do banco de dados.

```
short GetQueryDefCount();
```

### <a name="return-value"></a>Valor de retorno

O número de consultas definidas no banco de dados.

### <a name="remarks"></a>Comentários

`GetQueryDefCount` é útil se você precisar executar um loop por meio de todos os querydefs na coleção QueryDefs. Para obter informações sobre uma determinada consulta na coleção, consulte [GetQueryDefInfo](#getquerydefinfo).

##  <a name="getquerydefinfo"></a>  CDaoDatabase::GetQueryDefInfo

Chame essa função de membro para obter vários tipos de informações sobre uma consulta definida no banco de dados.

```
void GetQueryDefInfo(
    int nIndex,
    CDaoQueryDefInfo& querydefinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);


void GetQueryDefInfo(
    LPCTSTR lpszName,
    CDaoQueryDefInfo& querydefinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice da consulta predefinido na coleção QueryDefs do banco de dados, para a pesquisa por índice.

*querydefinfo*<br/>
Uma referência a um [CDaoQueryDefInfo](../../mfc/reference/cdaoquerydefinfo-structure.md) objeto que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros a serem recuperados. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retorne sobre o conjunto de registros:

- Nome AFX_DAO_PRIMARY_INFO (padrão), digite

- Informações AFX_DAO_SECONDARY_INFO principal adição: data de criação, data da última atualização, retorna registros, atualizável

- AFX_DAO_ALL_INFO primário e secundárias informações de adição: SQL, conectar, ODBCTimeout

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome de uma consulta definida no banco de dados, para a pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma consulta por índice na coleção QueryDefs do banco de dados ou pelo nome da consulta.

Para obter uma descrição das informações retornadas em *querydefinfo*, consulte o [CDaoQueryDefInfo](../../mfc/reference/cdaoquerydefinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Se você solicitar um nível de informações, você obtém todos os níveis anteriores de informações também.

##  <a name="getquerytimeout"></a>  CDaoDatabase::GetQueryTimeout

Chame essa função de membro para recuperar o número atual de segundos permitido antes que as operações subsequentes no banco de dados conectado são atingiu o tempo limite.

```
short GetQueryTimeout();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro curto que contém o valor de tempo limite em segundos.

### <a name="remarks"></a>Comentários

Uma operação talvez o tempo limite devido a problemas de acesso de rede, o tempo de processamento de consulta excessiva e assim por diante. Enquanto a configuração estiver em vigor, ele afeta todos os abertos, adicionar um novo, atualizar e excluir operações em qualquer conjunto de registros associado a este `CDaoDatabase` objeto. Você pode alterar a configuração de tempo limite atual chamando [SetQueryTimeout](#setquerytimeout). Alterar o valor de tempo limite de consulta para um conjunto de registros após a abertura não altera o valor para o conjunto de registros. Por exemplo, subsequente [mover](../../mfc/reference/cdaorecordset-class.md#move) operações não usam o novo valor. O valor padrão é definido inicialmente quando o mecanismo de banco de dados é inicializado.

O valor padrão para tempos limite de consulta é obtido do registro do Windows. Se não houver nenhuma configuração do registro, o padrão é 60 segundos. Nem todos os bancos de dados dão suporte a capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta igual a 0, nenhum tempo limite ocorre; e a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a chamada falhar, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

Para obter informações relacionadas, consulte o tópico "Propriedade QueryTimeout" na Ajuda do DAO.

##  <a name="getrecordsaffected"></a>  CDaoDatabase::GetRecordsAffected

Chame essa função de membro para determinar o número de registros afetados pela chamada do mais recente do [Execute](#execute) função de membro.

```
long GetRecordsAffected();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro longo que contém o número de registros afetados.

### <a name="remarks"></a>Comentários

O valor retornado inclui o número de registros excluídos, atualizados ou inseridos por uma consulta de ação executar com `Execute`. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando cascade atualiza ou exclui estão em vigor.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordsAffected" na Ajuda do DAO.

##  <a name="getrelationcount"></a>  CDaoDatabase::GetRelationCount

Chame essa função de membro para obter o número de relações definidas entre tabelas no banco de dados.

```
short GetRelationCount();
```

### <a name="return-value"></a>Valor de retorno

O número de relações definidas entre tabelas no banco de dados.

### <a name="remarks"></a>Comentários

`GetRelationCount` é útil se você precisar executar um loop por meio de todas as relações definidas na coleção de relações do banco de dados. Para obter informações sobre uma determinada relação na coleção, consulte [GetRelationInfo](#getrelationinfo).

Para ilustrar o conceito de um parceiro, considere uma tabela fornecedores e uma tabela de produtos, que pode ter uma relação um-para-muitos. Nessa relação, um fornecedor pode fornecer mais de um produto. Outras relações são um para um e muitos-para-muitos.

##  <a name="getrelationinfo"></a>  CDaoDatabase::GetRelationInfo

Chame essa função de membro para obter informações sobre uma relação especificada na coleção de relações do banco de dados.

```
void GetRelationInfo(
    int nIndex,
    CDaoRelationInfo& relinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);


void GetRelationInfo(
    LPCTSTR lpszName,
    CDaoRelationInfo& relinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do objeto de relação na coleção de relações do banco de dados, para a pesquisa por índice.

*relinfo*<br/>
Uma referência a um [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a relação para recuperar. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retorne sobre a relação:

- Tabela externa do nome, tabela, AFX_DAO_PRIMARY_INFO (padrão)

- Atributos AFX_DAO_SECONDARY_INFO, informações de campo

As informações de campo é um [CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md) objeto que contém os campos da tabela primária envolvido na relação.

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome do objeto relation, para a pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões desta função fornecem acesso por índice ou por nome. Para obter uma descrição das informações retornadas em *relinfo*, consulte o [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Se você solicitar informações em um nível, você também obter informações em todos os níveis anteriores também.

> [!NOTE]
>  Se você definir a relação de atributos do objeto para ativar operações cascade (`dbRelationUpdateCascades` ou `dbRelationDeleteCascades`), o mecanismo de banco de dados Microsoft Jet automaticamente atualiza ou exclui registros em um ou mais outras tabelas quando são feitas alterações relacionam a chave primária tabelas. Por exemplo, suponha que você estabelecer uma relação de exclusão em cascata entre uma tabela clientes e uma tabela de pedidos. Quando você exclui registros da tabela de clientes, os registros na tabela de pedidos relacionados a esse cliente também serão excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela de pedidos e outras tabelas, registros dessas tabelas são excluídos automaticamente quando você exclui registros da tabela Customers.

##  <a name="gettabledefcount"></a>  Cdaodatabase:: Gettabledefcount

Chame essa função de membro para recuperar o número de tabelas definidas no banco de dados.

```
short GetTableDefCount();
```

### <a name="return-value"></a>Valor de retorno

O número de tabledefs definidos no banco de dados.

### <a name="remarks"></a>Comentários

`GetTableDefCount` é útil se você precisar executar um loop por meio de todos os tabledefs na coleção TableDefs do banco de dados. Para obter informações sobre uma determinada tabela na coleção, consulte [GetTableDefInfo](#gettabledefinfo).

##  <a name="gettabledefinfo"></a>  Cdaodatabase:: Gettabledefinfo

Chame essa função de membro para obter vários tipos de informações sobre uma tabela definida no banco de dados.

```
void GetTableDefInfo(
    int nIndex,
    CDaoTableDefInfo& tabledefinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);


void GetTableDefInfo(
    LPCTSTR lpszName,
    CDaoTableDefInfo& tabledefinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do objeto tabledef na coleção TableDefs do banco de dados, para a pesquisa por índice.

*tabledefinfo*<br/>
Uma referência a um [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) objeto que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a tabela para recuperar. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retorne sobre a relação:

- Atributos de nome AFX_DAO_PRIMARY_INFO (padrão), atualizável,

- Informações AFX_DAO_SECONDARY_INFO principal adição: data de criação, data da última atualização, nome de tabela de origem, conectar-se

- AFX_DAO_ALL_INFO primário e secundárias informações de adição: contagem de registros de regra de validação, o texto de validação

*lpszName*<br/>
O nome do objeto tabledef, pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma tabela por índice na coleção TableDefs do banco de dados ou pelo nome da tabela.

Para obter uma descrição das informações retornadas em *tabledefinfo*, consulte o [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Se você solicitar informações em um nível, você pode obter informações de todos os níveis anteriores também.

> [!NOTE]
>  A opção AFX_DAO_ALL_INFO fornece informações que podem demorar a obter. Nesse caso, os registros na tabela de contagem pode consumir muito tempo se houver muitos registros.

##  <a name="getversion"></a>  CDaoDatabase::GetVersion

Chame essa função de membro para determinar a versão do arquivo de banco de dados Microsoft Jet.

```
CString GetVersion();
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do arquivo de banco de dados associado ao objeto.

### <a name="remarks"></a>Comentários

O valor retornado representa o número de versão no formato "principal"; Por exemplo, "3.0". O número de versão do produto (por exemplo, 3.0) consiste no número de versão (3), um período e o número de versão (0). As versões à data são 1.0, 1.1, 2.0 e 3.0.

Para obter informações relacionadas, consulte o tópico "Propriedade Version" na Ajuda do DAO.

##  <a name="isopen"></a>  CDaoDatabase::IsOpen

Chame essa função de membro para determinar se o `CDaoDatabase` objeto está atualmente aberto em um banco de dados.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o `CDaoDatabase` objeto for aberto no momento; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="m_pdaodatabase"></a>  CDaoDatabase::m_pDAODatabase

Contém um ponteiro de interface do OLE para o objeto de banco de dados DAO subjacentes a `CDaoDatabase` objeto.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar a interface DAO diretamente.

Para obter informações sobre o chamando DAO diretamente, consulte [54 de observação técnica](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

##  <a name="m_pworkspace"></a>  CDaoDatabase::m_pWorkspace

Contém um ponteiro para o [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto que contém o objeto de banco de dados.

### <a name="remarks"></a>Comentários

Use esse ponteiro, se você precisar acessar o espaço de trabalho diretamente — por exemplo, para obter ponteiros para outros objetos de banco de dados da coleção de bancos de dados do espaço de trabalho.

##  <a name="open"></a>  CDaoDatabase::Open

Você deve chamar essa função de membro para inicializar um recentemente construído `CDaoDatabase` objeto que representa um banco de dados existente.

```
virtual void Open(
    LPCTSTR lpszName,
    BOOL bExclusive = FALSE,
    BOOL bReadOnly = FALSE,
    LPCTSTR lpszConnect = _T(""));
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de cadeia de caracteres que é o nome de um existente do Microsoft Jet (. Arquivo de banco de dados do MDB). Se o nome do arquivo tem uma extensão, é necessário. Se a rede oferecer suporte a uniform naming convention (UNC), você pode também especificar um caminho de rede, como "\\\\\\\MYSERVER\\\MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras invertidas duplas são necessárias em literais de cadeia de caracteres como "\\" é o caractere de escape do C++.)

Algumas considerações se aplicam ao usar *lpszName*. Se ele:

- Refere-se a um banco de dados que já está aberto para acesso exclusivo por outro usuário, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md). Interceptar essa exceção para informar o usuário que o banco de dados está indisponível.

- É uma cadeia de caracteres vazia ("") e *lpszConnect* é "ODBC;", uma caixa de diálogo listando todos os nomes de fonte de dados ODBC é exibida para que o usuário pode selecionar um banco de dados. Você deve evitar conexões diretas com fontes de dados ODBC; Use uma tabela anexada.

- Caso contrário, não faz referência a um banco de dados existente ou o nome da válido código-fonte de dados ODBC, MFC gera uma exceção do tipo `CDaoException`.

> [!NOTE]
>  Para obter detalhes sobre códigos de erro do DAO, consulte o DAOERR. Arquivo de H. Para obter informações relacionadas, consulte o tópico "Dados acesso erros interceptáveis" na Ajuda do DAO.

*bExclusive*<br/>
Um valor booliano que será TRUE se o banco de dados deve ser aberto para acesso exclusivo de (não compartilhado) e FALSE se o banco de dados a ser aberto para acesso compartilhado. Se você omitir esse argumento, o banco de dados é aberto para acesso compartilhado.

*bReadOnly*<br/>
Um valor booliano que será TRUE se o banco de dados deve ser aberto para acesso somente leitura e FALSE se o banco de dados a ser aberto para acesso de leitura/gravação. Se você omitir esse argumento, o banco de dados é aberto para acesso de leitura/gravação. Todos os conjuntos de registros dependentes herdam esse atributo.

*lpszConnect*<br/>
Uma expressão de cadeia de caracteres usada para abrir o banco de dados. Essa cadeia de caracteres constitui o ODBC para conectar-se de argumentos. Você deve fornecer os argumentos exclusivos e somente leitura para fornecer uma cadeia de caracteres de origem. Se o banco de dados é um banco de dados Microsoft Jet (. MDB), essa cadeia de caracteres está vazia (""). A sintaxe para o valor padrão — **t**("") — oferece portabilidade para Unicode, bem como ANSI compilações do seu aplicativo.

### <a name="remarks"></a>Comentários

`Open` associa o banco de dados com o objeto subjacente do DAO. Você não pode usar o objeto de banco de dados para construir o conjunto de registros, tabledef ou querydef objetos até que ele seja inicializado. `Open` acrescenta o objeto de banco de dados à coleção de bancos de dados do espaço de trabalho associado.

Use os parâmetros da seguinte maneira:

- Se você estiver abrindo um Microsoft Jet (. Banco de dados do MDB), use o *lpszName* parâmetro e passagem de cadeia de caracteres vazia para o *lpszConnect* parâmetro ou passar uma cadeia de caracteres de senha do formulário "; PWD = password "se o banco de dados estiver protegido por senha (. MDB somente bancos de dados).

- Se você está abrindo uma fonte de dados ODBC, passe uma cadeia de caracteres de conexão ODBC válida no *lpszConnect* e uma cadeia de caracteres vazia *lpszName*.

Para obter informações relacionadas, consulte o tópico "OpenDatabase Method" na Ajuda do DAO.

> [!NOTE]
>  Para obter melhor desempenho ao acessar bancos de dados externos, incluindo bancos de dados ISAM e fontes de dados ODBC, é recomendável que você anexar tabelas de banco de dados externo a um banco de dados do mecanismo do Microsoft Jet (. MDB) em vez de conectar diretamente à fonte de dados.

É possível que uma tentativa de conexão de tempo limite se, por exemplo, o host DBMS não está disponível. Se a tentativa de conexão falhar, `Open` gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

Os comentários restantes se aplicam somente a bancos de dados ODBC:

Se o banco de dados é um banco de dados ODBC e os parâmetros em seu `Open` chamada não contêm informações suficientes para fazer a conexão, o driver ODBC abre uma caixa de diálogo para obter as informações necessárias do usuário. Quando você chama `Open`, a cadeia de conexão *lpszConnect*, é armazenada em particular e está disponível por meio da chamada a [GetConnect](#getconnect) função de membro.

Se desejar, você pode abrir a caixa de diálogo antes de chamar `Open` para obter informações do usuário, como uma senha, em seguida, adicione essas informações para a cadeia de caracteres de conexão que você passa para `Open`. Ou talvez você queira salvar a cadeia de conexão que você passe (talvez o registro do Windows) para que você possa reutilizá-lo na próxima vez seu aplicativo chamará `Open` em um `CDaoDatabase` objeto.

Você também pode usar a cadeia de caracteres de conexão para vários níveis de autorização de logon (cada um para outro `CDaoDatabase` objeto) ou para transmitir a outras informações específicas do banco de dados.

##  <a name="setquerytimeout"></a>  CDaoDatabase::SetQueryTimeout

Chame essa função de membro para substituir o número padrão de segundos permitido antes do tempo limite de banco de dados conectado operações posteriores.

```
void SetQueryTimeout(short nSeconds);
```

### <a name="parameters"></a>Parâmetros

*nSegundos*<br/>
O número de segundos para permitir que uma tentativa de consulta antes de expirar.

### <a name="remarks"></a>Comentários

Uma operação talvez o tempo limite devido a problemas de acesso de rede, o tempo de processamento de consulta excessiva e assim por diante. Chame `SetQueryTimeout` antes de abrir seu conjunto de registros ou antes de chamar o conjunto de registros [AddNew](../../mfc/reference/cdaorecordset-class.md#addnew), [Update](../../mfc/reference/cdaorecordset-class.md#update), ou [excluir](../../mfc/reference/cdaorecordset-class.md#delete) funções de membro, se você quiser alterar a consulta valor de tempo limite. A configuração afeta todos os próximos [aberto](../../mfc/reference/cdaorecordset-class.md#open), `AddNew`, `Update`, e `Delete` chamadas para quaisquer conjuntos de registros associados a este `CDaoDatabase` objeto. Alterar o valor de tempo limite de consulta para um conjunto de registros após a abertura não altera o valor para o conjunto de registros. Por exemplo, subsequente [mover](../../mfc/reference/cdaorecordset-class.md#move) operações não usam o novo valor.

O valor padrão para tempos limite de consulta é 60 segundos. Nem todos os bancos de dados dão suporte a capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta igual a 0, nenhum tempo limite ocorre; a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento.

Para obter informações relacionadas, consulte o tópico "Propriedade QueryTimeout" na Ajuda do DAO.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
