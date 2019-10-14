---
title: Classe CDaoDatabase
ms.date: 09/17/2019
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
ms.openlocfilehash: 683f3f9ebb09d69461e4f9026841363c452f4793
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096167"
---
# <a name="cdaodatabase-class"></a>Classe CDaoDatabase

Representa uma conexão com um banco de dados do Access usando o DAO (Data Access Objects). O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

## <a name="syntax"></a>Sintaxe

```
class CDaoDatabase : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CDaoDatabase](#cdaodatabase)|Constrói um objeto `CDaoDatabase`. Chame `Open` para conectar o objeto a um banco de dados.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CanTransact](#cantransact)|Retornará zero se o banco de dados oferecer suporte a transações.|
|[CDaoDatabase::CanUpdate](#canupdate)|Retornará zero se o `CDaoDatabase` objeto for atualizável (não somente leitura).|
|[CDaoDatabase::Close](#close)|Fecha a conexão de banco de dados.|
|[CDaoDatabase:: criar](#create)|Cria o objeto de banco de dados DAO subjacente `CDaoDatabase` e inicializa o objeto.|
|[CDaoDatabase::CreateRelation](#createrelation)|Define uma nova relação entre as tabelas no banco de dados.|
|[CDaoDatabase::DeleteQueryDef](#deletequerydef)|Exclui um objeto QueryDef salvo na coleção QueryDefs do banco de dados.|
|[CDaoDatabase::DeleteRelation](#deleterelation)|Exclui uma relação existente entre tabelas no banco de dados.|
|[CDaoDatabase::DeleteTableDef](#deletetabledef)|Exclui a definição de uma tabela no banco de dados. Isso exclui a tabela real e todos os seus dados.|
|[CDaoDatabase:: execute](#execute)|Executa uma consulta de ação. Chamar `Execute` para uma consulta que retorna resultados gera uma exceção.|
|[CDaoDatabase::GetConnect](#getconnect)|Retorna a cadeia de conexão usada para conectar `CDaoDatabase` o objeto a um banco de dados. Usado para ODBC.|
|[CDaoDatabase::GetName](#getname)|Retorna o nome do banco de dados em uso no momento.|
|[CDaoDatabase::GetQueryDefCount](#getquerydefcount)|Retorna o número de consultas definidas para o banco de dados.|
|[CDaoDatabase::GetQueryDefInfo](#getquerydefinfo)|Retorna informações sobre uma consulta especificada definida no banco de dados.|
|[CDaoDatabase::GetQueryTimeout](#getquerytimeout)|Retorna o número de segundos após o qual as operações de consulta do banco de dados atingirão o tempo limite. Afeta todas as operações abertas, adicionar novas, atualizar e editar subsequentes e outras operações em fontes de dados ODBC (somente) `Execute` , como chamadas.|
|[CDaoDatabase::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetados pela última operação de atualização, edição ou adição ou por uma chamada para `Execute`.|
|[CDaoDatabase::GetRelationCount](#getrelationcount)|Retorna o número de relações definidas entre as tabelas no banco de dados.|
|[CDaoDatabase::GetRelationInfo](#getrelationinfo)|Retorna informações sobre uma relação especificada definida entre as tabelas no banco de dados.|
|[CDaoDatabase::GetTableDefCount](#gettabledefcount)|Retorna o número de tabelas definidas no banco de dados.|
|[CDaoDatabase::GetTableDefInfo](#gettabledefinfo)|Retorna informações sobre uma tabela especificada no banco de dados.|
|[CDaoDatabase::GetVersion](#getversion)|Retorna a versão do mecanismo de banco de dados associado ao banco de dados.|
|[CDaoDatabase::IsOpen](#isopen)|Retornará zero se o `CDaoDatabase` objeto estiver conectado atualmente a um banco de dados.|
|[CDaoDatabase::Open](#open)|Estabelece uma conexão com um banco de dados.|
|[CDaoDatabase::SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual as operações de consulta do banco de dados (somente em fontes de dado ODBC) atingirão o tempo limite. Afeta todas as operações abertas, adicionar novas, atualizar e excluir subsequentes.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::m_pDAODatabase](#m_pdaodatabase)|Um ponteiro para o objeto de banco de dados DAO subjacente.|
|[CDaoDatabase::m_pWorkspace](#m_pworkspace)|Um ponteiro para o objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) que contém o banco de dados e define seu espaço de transação.|

## <a name="remarks"></a>Comentários

Para obter informações sobre os formatos de banco de dados com suporte, consulte a função membro [GetName](../../mfc/reference/cdaoworkspace-class.md#getname) . Você pode ter um ou mais `CDaoDatabase` objetos ativos por vez em um determinado "espaço de trabalho", representado por um objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) . O espaço de trabalho mantém uma coleção de objetos de banco de dados abertos, chamada de coleção Databases.

## <a name="usage"></a>Uso

Você pode criar objetos de banco de dados implicitamente, ao criar objetos Recordset. Mas você também pode criar objetos de banco de dados explicitamente. Para usar um banco de dados existente `CDaoDatabase`explicitamente com o, siga um destes procedimentos:

- Construa um `CDaoDatabase` objeto, passando um ponteiro para um objeto Open [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) .

- Ou Construa um `CDaoDatabase` objeto sem especificar o espaço de trabalho (o MFC cria um objeto de espaço de trabalho temporário).

Para criar um novo Microsoft Jet (. MDB), construa um `CDaoDatabase` objeto e chame sua função [criar](#create) membro. `Open` Não *chame após* . `Create`

Para abrir um banco de dados existente, `CDaoDatabase` Construa um objeto e chame sua função de membro [aberta](#open) .

Qualquer uma dessas técnicas acrescenta o objeto de banco de dados DAO à coleção de bancos de dados do espaço de trabalho e abre uma conexão com os mesmos. Quando você cria objetos [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md), [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)ou [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) para operar no banco de dados conectado, passe os construtores para esses objetos um ponteiro para o `CDaoDatabase` objeto. Quando você terminar de usar a conexão, chame a função de membro [Close](#close) e `CDaoDatabase` destrua o objeto. `Close`Fecha os conjuntos de registros que você não fechou anteriormente.

## <a name="transactions"></a>Transações

O processamento de transações de banco de dados é fornecido no nível do espaço de trabalho — consulte as funções de membro [BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans), [CommitTrans](../../mfc/reference/cdaoworkspace-class.md#committrans) e [Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) da classe `CDaoWorkspace`.

## <a name="odbc-connections"></a>Conexões ODBC

A maneira recomendada para trabalhar com fontes de dados ODBC é anexar tabelas externas a um Microsoft Jet (. MDB).

## <a name="collections"></a>Coleções

Cada banco de dados mantém suas próprias coleções de objetos TableDef, QueryDef, Recordset e relation. A `CDaoDatabase` classe fornece funções de membro para manipular esses objetos.

> [!NOTE]
>  Os objetos são armazenados no DAO, não no objeto de banco de dados do MFC. O MFC fornece classes para objetos TableDef, QueryDef e Recordset, mas não para objetos de relação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoDatabase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

##  <a name="cantransact"></a>  CDaoDatabase::CanTransact

Chame essa função de membro para determinar se o banco de dados permite transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o banco de dados oferecer suporte a transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

As transações são gerenciadas no espaço de trabalho do banco de dados.

##  <a name="canupdate"></a>  CDaoDatabase::CanUpdate

Chame essa função de membro para determinar se `CDaoDatabase` o objeto permite atualizações.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero `CDaoDatabase` se o objeto permitir atualizações; caso contrário, 0, indicando que você passou true em *bReadOnly* quando `CDaoDatabase` você abriu o objeto ou que o próprio banco de dados é somente leitura. Consulte a função de membro [Open](#open) .

### <a name="remarks"></a>Comentários

Para obter informações sobre a capacidade de atualização do banco de dados, consulte o tópico "Propriedade atualizável" na ajuda do DAO.

##  <a name="cdaodatabase"></a>CDaoDatabase::CDaoDatabase

Constrói um objeto `CDaoDatabase`.

```
CDaoDatabase(CDaoWorkspace* pWorkspace = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWorkspace*<br/>
Um ponteiro para o `CDaoWorkspace` objeto que conterá o novo objeto de banco de dados. Se você aceitar o valor padrão de NULL, o Construtor criará um `CDaoWorkspace` objeto temporário que usa o espaço de trabalho padrão do DAO. Você pode obter um ponteiro para o objeto de espaço de trabalho por meio do membro de dados [m_pWorkspace](#m_pworkspace) .

### <a name="remarks"></a>Comentários

Depois de construir o objeto, se você estiver criando um novo Microsoft Jet (. MDB), chame a função de membro [Create](#create) do objeto. Se você estiver, em vez disso, abrindo um banco de dados existente, chame a função de membro [Open](#open) do objeto.

Quando terminar com o objeto, você deverá chamar sua função de membro de [fechamento](#close) e, em `CDaoDatabase` seguida, destruir o objeto.

Talvez você ache conveniente inserir o `CDaoDatabase` objeto em sua classe de documento.

> [!NOTE]
>  Um `CDaoDatabase` objeto também é criado implicitamente se você abrir um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) sem passar um ponteiro para um objeto `CDaoDatabase` existente. Esse objeto de banco de dados é fechado quando você fecha o objeto Recordset.

##  <a name="close"></a>CDaoDatabase:: fechar

Chame essa função de membro para se desconectar de um banco de dados e fechar todos os conjuntos de registros, TableDefs e QueryDefs abertos associados ao banco de dados.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

É uma boa prática fechar esses objetos por conta própria antes de chamar essa função de membro. Fechar um `CDaoDatabase` objeto o Remove da coleção de bancos de dados no espaço de [trabalho](../../mfc/reference/cdaoworkspace-class.md)associado. Como `Close` o não destrói o `CDaoDatabase` objeto, você pode reutilizar o objeto abrindo o mesmo banco de dados ou um banco de dados diferente.

> [!CAUTION]
>  Chame a função de membro [Update](../../mfc/reference/cdaorecordset-class.md#update) (se houver edições pendentes) e a `Close` função de membro em todos os objetos Recordset abertos antes de fechar um banco de dados. Se você sair de uma função que declara [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) ou `CDaoDatabase` objetos na pilha, o banco de dados será fechado, todas as alterações não salvas serão perdidas, todas as transações pendentes serão revertidas e todas as edições pendentes em seus dados serão perdidas.

> [!CAUTION]
>  Se você tentar fechar um objeto de banco de dados enquanto todos os objetos de conjunto de registros estiverem abertos, ou se tentar fechar um objeto de espaço de trabalho enquanto quaisquer objetos de banco de dados pertencentes a esse espaço de trabalho específico estiverem abertos, esses objetos serão fechados e as atualizações ou edições pendentes serão revertida. Se você tentar fechar um objeto de espaço de trabalho enquanto todos os objetos de banco de dados pertencentes a ele estiverem abertos, a operação fechará todos os objetos de banco de dados pertencentes a esse objeto de espaço de trabalho específico, o que pode resultar em um fechamento de objetos Recordset não fechados. Se você não fechar o objeto de banco de dados, o MFC relatará uma falha de asserção nas compilações de depuração.

Se o objeto de banco de dados for definido fora do escopo de uma função e você sair da função sem fechá-lo, o objeto de banco de dados permanecerá aberto até ser fechado explicitamente ou o módulo no qual ele está definido estará fora do escopo.

##  <a name="create"></a>CDaoDatabase:: criar

Para criar um novo Microsoft Jet (. MDB), chame essa função de membro depois de construir um `CDaoDatabase` objeto.

```
virtual void Create(
    LPCTSTR lpszName,
    LPCTSTR lpszLocale = dbLangGeneral,
    int dwOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de cadeia de caracteres que é o nome do arquivo de banco de dados que você está criando. Pode ser o caminho completo e o nome do arquivo, como "C\\: \MYDB. MDB ". Você deve fornecer um nome. Se você não fornecer uma extensão de nome de arquivo,. O MDB é acrescentado. Se sua rede der suporte à UNC (Convenção de nomenclatura uniforme), você também poderá especificar um caminho de rede,\\como\\"\\\\\\\MYSERVER\\\MYSHARE \MYDIR \MYDB". Somente o Microsoft Jet (. MDB) os arquivos de banco de dados podem ser criados usando essa função de membro. (As barras invertidas duplas são necessárias em literais\\de cadeia de C++ caracteres porque "" é o caractere de escape.)

*lpszLocale*<br/>
Uma expressão de cadeia de caracteres usada para especificar a ordem de agrupamento para criar o banco de dados. O valor padrão é `dbLangGeneral`. Os possíveis valores são:

- `dbLangGeneral`Inglês, alemão, francês, Português, italiano e espanhol moderno

- `dbLangArabic`Árabe

- `dbLangCyrillic`Russo

- `dbLangCzech`Tcheco

- `dbLangDutch`Holandês

- `dbLangGreek`Grego

- `dbLangHebrew`Hebraico

- `dbLangHungarian`Húngaro

- `dbLangIcelandic`Islandês

- `dbLangNordic`Idiomas nórdico (somente versão 1,0 do mecanismo de banco de dados do Microsoft Jet)

- `dbLangNorwdan`Norueguês e dinamarquês

- `dbLangPolish`Polonês

- `dbLangSpanish`Espanhol tradicional

- `dbLangSwedfin`Sueco e finlandês

- `dbLangTurkish`Turco

*dwOptions*<br/>
Um inteiro que indica uma ou mais opções. Os possíveis valores são:

- `dbEncrypt`Criar um banco de dados criptografado.

- `dbVersion10`Crie um banco de dados com o banco de dados do Microsoft Jet versão 1,0.

- `dbVersion11`Crie um banco de dados com o banco de dados do Microsoft Jet versão 1,1.

- `dbVersion20`Crie um banco de dados com o banco de dados do Microsoft Jet versão 2,0.

- `dbVersion30`Crie um banco de dados com o banco de dados do Microsoft Jet versão 3,0.

Se você omitir a constante de criptografia, um banco de dados não criptografado será criado. Você pode especificar apenas uma constante de versão. Se você omitir uma constante de versão, um banco de dados que usa o banco de dados Microsoft Jet versão 3,0 será criado.

> [!CAUTION]
>  Se um banco de dados não estiver criptografado, é possível, mesmo se você implementar a segurança de usuário/senha, para ler diretamente o arquivo de disco binário que constitui o banco de dados.

### <a name="remarks"></a>Comentários

`Create`cria o arquivo de banco de dados e o objeto de banco de C++ dados DAO subjacente e inicializa o objeto. O objeto é anexado à coleção de bancos de dados do espaço de trabalho associado. O objeto de banco de dados está em um estado aberto; Não chame `Open*` após `Create`.

> [!NOTE]
>  Com `Create`o, você pode criar somente o Microsoft Jet (. MDB). Você não pode criar bancos de dados ISAM ou bancos de dados ODBC.

##  <a name="createrelation"></a>  CDaoDatabase::CreateRelation

Chame essa função de membro para estabelecer uma relação entre um ou mais campos em uma tabela primária no banco de dados e um ou mais campos em uma tabela estrangeira (outra tabela no banco de dados).

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
O nome exclusivo do objeto de relação. O nome deve começar com uma letra e pode conter no máximo 40 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir pontuação ou espaços.

*lpszTable*<br/>
O nome da tabela primária na relação. Se a tabela não existir, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

*lpszForeignTable*<br/>
O nome da tabela estrangeira na relação. Se a tabela não existir, o MFC lançará uma exceção do `CDaoException`tipo.

*lAttributes*<br/>
Um valor longo que contém informações sobre o tipo de relação. Você pode usar esse valor para impor a integridade referencial, entre outras coisas. Você pode usar o operador OR-bit ( **&#124;** ) para combinar qualquer um dos seguintes valores (desde que a combinação faça sentido):

- `dbRelationUnique`A relação é um-para-um.

- `dbRelationDontEnforce`A relação não é imposta (sem integridade referencial).

- `dbRelationInherited`A relação existe em um banco de dados não atual que contém as duas tabelas anexadas.

- `dbRelationUpdateCascade`As atualizações serão colocadas em cascata (para obter mais informações em cascata, consulte comentários).

- `dbRelationDeleteCascade`As exclusões serão colocadas em cascata.

*lpszField*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um campo na tabela primária (chamado por *lpszTable*).

*lpszForeignField*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que contém o nome de um campo na tabela estrangeira (chamado por *lpszForeignTable*).

*relinfo*<br/>
Uma referência a um objeto [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) que contém informações sobre a relação que você deseja criar.

### <a name="remarks"></a>Comentários

A relação não pode envolver uma consulta ou uma tabela anexada de um banco de dados externo.

Use a primeira versão da função quando a relação envolver um campo em cada uma das duas tabelas. Use a segunda versão quando a relação envolver vários campos. O número máximo de campos em uma relação é 14.

Essa ação cria um objeto de relação DAO subjacente, mas esse é um detalhe de implementação do MFC, pois o encapsulamento de objetos de relação `CDaoDatabase`do MFC está contido na classe. O MFC não fornece uma classe para relações.

Se você definir os atributos do objeto relation para ativar as operações em cascata, o mecanismo de banco de dados atualizará ou excluirá automaticamente os registros em uma ou mais tabelas quando forem feitas alterações nas tabelas de chave primária relacionadas.

Por exemplo, suponha que você estabeleça uma relação de exclusão em cascata entre uma tabela de clientes e uma tabela de pedidos. Quando você exclui registros da tabela Customers, os registros na tabela Orders relacionados a esse cliente também são excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela Orders e outras tabelas, os registros dessas tabelas serão excluídos automaticamente quando você excluir registros da tabela Customers.

Para obter informações relacionadas, consulte o tópico "método CreateRelation" na ajuda do DAO.

##  <a name="deletequerydef"></a>  CDaoDatabase::DeleteQueryDef

Chame essa função de membro para excluir a consulta QueryDef-Save especificada — da `CDaoDatabase` coleção QueryDefs do objeto.

```
void DeleteQueryDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da consulta salva a ser excluída.

### <a name="remarks"></a>Comentários

Posteriormente, essa consulta não será mais definida no banco de dados.

Para obter informações sobre como criar objetos QueryDef, consulte Class [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Um objeto QueryDef se torna associado a um `CDaoDatabase` objeto específico quando você constrói `CDaoQueryDef` o objeto, passando-o um ponteiro para o objeto de banco de dados.

##  <a name="deleterelation"></a>  CDaoDatabase::DeleteRelation

Chame essa função de membro para excluir uma relação existente da coleção de relações do objeto de banco de dados.

```
void DeleteRelation(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da relação a ser excluída.

### <a name="remarks"></a>Comentários

Posteriormente, a relação não existe mais.

Para obter informações relacionadas, consulte o tópico "Excluir método" na ajuda do DAO.

##  <a name="deletetabledef"></a>  CDaoDatabase::DeleteTableDef

Chame essa função de membro para excluir a tabela especificada e todos os seus dados da `CDaoDatabase` coleção TableDefs do objeto.

```
void DeleteTableDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome do TableDef a ser excluído.

### <a name="remarks"></a>Comentários

Posteriormente, essa tabela não será mais definida no banco de dados.

> [!NOTE]
>  Tenha cuidado para não excluir tabelas do sistema.

Para obter informações sobre como criar objetos TableDef, consulte Class [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md). Um objeto tabledef se torna associado a um `CDaoDatabase` objeto específico quando você constrói `CDaoTableDef` o objeto, passando-o um ponteiro para o objeto de banco de dados.

Para obter informações relacionadas, consulte o tópico "Excluir método" na ajuda do DAO.

##  <a name="execute"></a>CDaoDatabase:: execute

Chame essa função de membro para executar uma consulta de ação ou executar uma instrução SQL no banco de dados.

```
void Execute(
    LPCTSTR lpszSQL,
    int nOptions = dbFailOnError);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém um comando SQL válido a ser executado.

*nOptions*<br/>
Um inteiro que especifica as opções relacionadas à integridade da consulta. Você pode usar o operador OR-bit ( **&#124;** ) para combinar qualquer uma das constantes a seguir (desde que a combinação faça sentido — por exemplo, você não `dbInconsistent` combinará com `dbConsistent`):

- `dbDenyWrite`Negar permissão de gravação para outros usuários.

- `dbInconsistent`Os Atualizações inconsistentes.

- `dbConsistent`Atualizações consistentes.

- `dbSQLPassThrough`Passagem SQL. Faz com que a instrução SQL seja passada para uma fonte de dados ODBC para processamento.

- `dbFailOnError`Reverter atualizações se ocorrer um erro.

- `dbSeeChanges`Gerar um erro de tempo de execução se outro usuário estiver alterando os dados que você está editando.

> [!NOTE]
>  Se ambos `dbInconsistent` e `dbConsistent` estiverem incluídos ou se nenhum for incluído, o resultado será o padrão. Para obter uma explicação dessas constantes, consulte o tópico "executar método" na ajuda do DAO.

### <a name="remarks"></a>Comentários

`Execute`funciona somente para consultas de ação ou consultas de passagem SQL que não retornam resultados. Ele não funciona para consultas SELECT, que retornam registros.

Para obter uma definição e informações sobre consultas de ação, consulte os tópicos "consulta de ação" e "executar método" na ajuda do DAO.

> [!TIP]
>  Dada uma instrução SQL sintaticamente correta e as permissões adequadas, a `Execute` função de membro não falhará mesmo que não seja possível modificar ou excluir uma única linha. Portanto, sempre use a `dbFailOnError` opção ao usar a `Execute` função de membro para executar uma consulta Update ou Delete. Essa opção faz com que o MFC lance uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) e reverta todas as alterações bem-sucedidas se algum dos registros afetados estiver bloqueado e não puder ser atualizado ou excluído. Observe que você sempre pode chamar `GetRecordsAffected` para ver quantos registros foram afetados.

Chame a função de membro [GetRecordsAffected](#getrecordsaffected) do objeto de banco de dados para determinar o número de registros afetados pela `Execute` chamada mais recente. Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos ao executar uma consulta de ação. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando atualizações ou exclusões em cascata estiverem em vigor.

`Execute`Não retorna um conjunto de registros. O `Execute` uso de em uma consulta que seleciona registros faz com que o MFC lance `CDaoException`uma exceção do tipo. (Não há nenhuma `ExecuteSQL` função de membro análoga `CDatabase::ExecuteSQL`a.)

##  <a name="getconnect"></a>CDaoDatabase:: GetConnect

Chame essa função de membro para recuperar a cadeia de conexão usada para `CDaoDatabase` conectar o objeto a um ODBC ou banco de dados ISAM.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor de retorno

A cadeia de conexão se [abrir](#open) tiver sido chamado com êxito em uma fonte de dados ODBC; caso contrário, uma cadeia de caracteres vazia. Para um Microsoft Jet (. MDB), a cadeia de caracteres estará sempre vazia, a menos que você a defina `dbSQLPassThrough` para uso com a opção usada com a função [executar](#execute) membro ou usada na abertura de um conjunto de registros.

### <a name="remarks"></a>Comentários

A cadeia de caracteres fornece informações sobre a origem de um banco de dados aberto ou de um banco de dados usado em uma consulta de passagem. A cadeia de conexão é composta por um especificador de tipo de banco de dados e zero ou mais parâmetros separados por ponto e vírgula.

> [!NOTE]
>  Usar as classes do MFC DAO para se conectar a uma fonte de dados via ODBC é menos eficiente do que conectar-se por meio de uma tabela anexada.

> [!NOTE]
>  A cadeia de conexão é usada para transmitir informações adicionais ao ODBC e a determinados drivers ISAM, conforme necessário. Ele não é usado para o. Bancos de dados MDB. Para tabelas base do banco de dados Microsoft Jet, a cadeia de conexão é uma cadeia de caracteres vazia (""), exceto quando você a usa para uma consulta de passagem SQL, conforme descrito em valor de retorno acima.

Consulte a função de membro [Open](#open) para obter uma descrição de como a cadeia de conexão é criada. Depois que a cadeia de conexão tiver sido definida `Open` na chamada, você poderá usá-la posteriormente para verificar a configuração a fim de determinar o tipo, o caminho, a ID de usuário, a senha ou a fonte de dados ODBC.

##  <a name="getname"></a>  CDaoDatabase::GetName

Chame essa função de membro para recuperar o nome do banco de dados aberto no momento, que é o nome de um arquivo de banco de dado existente ou o nome de uma fonte do ODBC registrada.

```
CString GetName();
```

### <a name="return-value"></a>Valor de retorno

O caminho completo e o nome do arquivo do banco de dados se for bem-sucedido; caso contrário, uma [CString](../../atl-mfc-shared/reference/cstringt-class.md)vazia.

### <a name="remarks"></a>Comentários

Se sua rede der suporte à UNC (Convenção de nomenclatura uniforme), você também poderá especificar um caminho de rede — por\\exemplo\\,\\"\\\\\\\MYSERVER \MYSHARE \MYDIR \MYDB. MDB ". (As barras invertidas duplas são necessárias em literais\\de cadeia de C++ caracteres porque "" é o caractere de escape.)

Você pode, por exemplo, querer exibir esse nome em um título. Se ocorrer um erro enquanto o nome está sendo recuperado, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

> [!NOTE]
>  Para obter melhor desempenho quando bancos de dados externos estão sendo acessados, recomendamos que você anexe tabelas de banco de dados externas a um banco de dados do Microsoft Jet (. MDB) em vez de conectar-se diretamente à fonte de dados.

O tipo de banco de dados é indicado pelo arquivo ou diretório para o qual o caminho aponta, da seguinte maneira:

|Nome de caminho aponta para..|Tipo de banco de dados|
|--------------------------|-------------------|
|. Arquivo MDB|Banco de dados Microsoft Jet (Microsoft Access)|
|Diretório que contém. Arquivo (s) DBF|banco de dados do dBASE|
|Diretório que contém. Arquivo XLS|Banco de dados do Microsoft Excel|
|Diretório que contém. Arquivo (s) PDX|Banco de dados do Paradox|
|Diretório que contém arquivos de banco de dados de texto formatados adequadamente|Banco de dados de formato de texto|

Para bancos de dados ODBC, como o SQL Server e o Oracle, a cadeia de conexão do banco de dado identifica um nome de fonte (DSN) que é registrado pelo ODBC.

##  <a name="getquerydefcount"></a>  CDaoDatabase::GetQueryDefCount

Chame essa função de membro para recuperar o número de consultas definidas na coleção QueryDefs do banco de dados.

```
short GetQueryDefCount();
```

### <a name="return-value"></a>Valor de retorno

O número de consultas definidas no banco de dados.

### <a name="remarks"></a>Comentários

`GetQueryDefCount`será útil se você precisar executar um loop em todos os QueryDefs na coleção QueryDefs. Para obter informações sobre uma determinada consulta na coleção, consulte [GetQueryDefInfo](#getquerydefinfo).

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
O índice da consulta predefinida na coleção QueryDefs do banco de dados, para pesquisa por índice.

*querydefinfo*<br/>
Uma referência a um objeto [CDaoQueryDefInfo](../../mfc/reference/cdaoquerydefinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne sobre o conjunto de registros:

- AFX_DAO_PRIMARY_INFO (padrão) nome, tipo

- AFX_DAO_SECONDARY_INFO Informações primárias mais: Data de criação, data da última atualização, retorna registros, atualizáveis

- AFX_DAO_ALL_INFO Informações primárias e secundárias mais: SQL, Connect, ODBCTimeout

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome de uma consulta definida no banco de dados, para pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma consulta por índice na coleção QueryDefs do banco de dados ou pelo nome da consulta.

Para obter uma descrição das informações retornadas em *querydefinfo*, consulte a estrutura [CDaoQueryDefInfo](../../mfc/reference/cdaoquerydefinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Se você solicitar um nível de informação, obterá quaisquer níveis de informações anteriores também.

##  <a name="getquerytimeout"></a>  CDaoDatabase::GetQueryTimeout

Chame essa função de membro para recuperar o número atual de segundos a serem permitidos antes que as operações subsequentes no banco de dados conectado tenham atingido o tempo limite.

```
short GetQueryTimeout();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro curto que contém o valor de tempo limite em segundos.

### <a name="remarks"></a>Comentários

Uma operação pode atingir o tempo limite devido a problemas de acesso à rede, tempo excessivo de processamento de consultas e assim por diante. Embora a configuração esteja em vigor, ela afeta todas as operações abrir, Adicionar nova, atualizar e excluir em todos os conjuntos de registros associados `CDaoDatabase` a esse objeto. Você pode alterar a configuração de tempo limite atual chamando [SetQueryTimeout](#setquerytimeout). Alterar o valor de tempo limite da consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, as operações de [movimentação](../../mfc/reference/cdaorecordset-class.md#move) subsequentes não usam o novo valor. O valor padrão é inicialmente definido quando o mecanismo de banco de dados é inicializado.

O valor padrão para tempos limite de consulta é obtido do registro do Windows. Se não houver nenhuma configuração do registro, o padrão será 60 segundos. Nem todos os bancos de dados dão suporte à capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta de 0, nenhum tempo limite ocorrerá; e a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a chamada falhar, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

Para obter informações relacionadas, consulte o tópico "Propriedade QueryTimeout" na ajuda do DAO.

##  <a name="getrecordsaffected"></a>  CDaoDatabase::GetRecordsAffected

Chame essa função de membro para determinar o número de registros afetados pela chamada mais recente da função de membro [Execute](#execute) .

```
long GetRecordsAffected();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro longo que contém o número de registros afetados.

### <a name="remarks"></a>Comentários

O valor retornado inclui o número de registros excluídos, atualizados ou inseridos por uma consulta de ação executada `Execute`com. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando atualizações ou exclusões em cascata estiverem em vigor.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordsAffected" na ajuda do DAO.

##  <a name="getrelationcount"></a>  CDaoDatabase::GetRelationCount

Chame essa função de membro para obter o número de relações definidas entre as tabelas no banco de dados.

```
short GetRelationCount();
```

### <a name="return-value"></a>Valor de retorno

O número de relações definidas entre as tabelas no banco de dados.

### <a name="remarks"></a>Comentários

`GetRelationCount`será útil se você precisar executar um loop por todas as relações definidas na coleção de relações do banco de dados. Para obter informações sobre uma determinada relação na coleção, consulte [GetRelationInfo](#getrelationinfo).

Para ilustrar o conceito de uma relação, considere uma tabela fornecedores e uma tabela produtos, que pode ter uma relação um-para-muitos. Nessa relação, um fornecedor pode fornecer mais de um produto. Outras relações são um-para-um e muitos para muitos.

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
O índice do objeto de relação na coleção de relações do banco de dados, para pesquisa por índice.

*relinfo*<br/>
Uma referência a um objeto [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a relação recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne sobre a relação:

- AFX_DAO_PRIMARY_INFO (padrão) nome, tabela, tabela estrangeira

- Atributos AFX_DAO_SECONDARY_INFO, informações de campo

As informações de campo são um objeto [CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md) que contém os campos da tabela primária envolvida na relação.

*lpszName*<br/>
Uma cadeia de caracteres que contém o nome do objeto de relação, para pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões dessa função fornecem acesso por índice ou por nome. Para obter uma descrição das informações retornadas em *relinfo*, consulte a estrutura [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Se você solicitar informações em um nível, também obterá informações em todos os níveis anteriores.

> [!NOTE]
>  Se você definir os atributos do objeto relation para ativar operações em cascata (`dbRelationUpdateCascades` ou `dbRelationDeleteCascades`), o mecanismo de banco de dados do Microsoft Jet atualizará ou excluirá automaticamente os registros em uma ou mais tabelas quando forem feitas alterações na chave primária relacionada tabelas. Por exemplo, suponha que você estabeleça uma relação de exclusão em cascata entre uma tabela de clientes e uma tabela de pedidos. Quando você exclui registros da tabela Customers, os registros na tabela Orders relacionados a esse cliente também são excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela Orders e outras tabelas, os registros dessas tabelas serão excluídos automaticamente quando você excluir registros da tabela Customers.

##  <a name="gettabledefcount"></a>  CDaoDatabase::GetTableDefCount

Chame essa função de membro para recuperar o número de tabelas definidas no banco de dados.

```
short GetTableDefCount();
```

### <a name="return-value"></a>Valor de retorno

O número de TableDefs definidos no banco de dados.

### <a name="remarks"></a>Comentários

`GetTableDefCount`será útil se você precisar executar um loop em todos os TableDefs na coleção TableDefs do banco de dados. Para obter informações sobre uma determinada tabela na coleção, consulte [GetTableDefInfo](#gettabledefinfo).

##  <a name="gettabledefinfo"></a>  CDaoDatabase::GetTableDefInfo

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
O índice do objeto tabledef na coleção TableDefs do banco de dados, para pesquisa por índice.

*tabledefinfo*<br/>
Uma referência a um objeto [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a tabela recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne sobre a relação:

- AFX_DAO_PRIMARY_INFO (padrão) nome, atualizável, atributos

- AFX_DAO_SECONDARY_INFO Informações primárias mais: Data de criação, data da última atualização, nome da tabela de origem, conectar

- AFX_DAO_ALL_INFO Informações primárias e secundárias mais: Regra de validação, texto de validação, contagem de registros

*lpszName*<br/>
O nome do objeto tabledef, para pesquisa por nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma tabela por índice na coleção TableDefs do banco de dados ou pelo nome da tabela.

Para obter uma descrição das informações retornadas em *tabledefinfo*, consulte a estrutura [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Se você solicitar informações em um nível, obterá informações para todos os níveis anteriores também.

> [!NOTE]
>  A opção AFX_DAO_ALL_INFO fornece informações que podem ser lentas para obter. Nesse caso, a contagem dos registros na tabela pode ser muito demorada se houver muitos registros.

##  <a name="getversion"></a>  CDaoDatabase::GetVersion

Chame essa função de membro para determinar a versão do arquivo de banco de dados do Microsoft Jet.

```
CString GetVersion();
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do arquivo de banco de dados associada ao objeto.

### <a name="remarks"></a>Comentários

O valor retornado representa o número de versão no formato "Major. Minor"; por exemplo, "3,0". O número de versão do produto (por exemplo, 3,0) consiste no número de versão (3), em um ponto e no número de versão (0). As versões até a data são 1,0, 1,1, 2,0 e 3,0.

Para obter informações relacionadas, consulte o tópico "propriedade da versão" na ajuda do DAO.

##  <a name="isopen"></a>CDaoDatabase:: IsOpen

Chame essa função de membro para determinar se `CDaoDatabase` o objeto está aberto no momento em um banco de dados.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero `CDaoDatabase` se o objeto estiver aberto no momento; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="m_pdaodatabase"></a>  CDaoDatabase::m_pDAODatabase

Contém um ponteiro para a interface OLE do objeto de banco de dados DAO `CDaoDatabase` subjacente ao objeto.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar a interface DAO diretamente.

Para obter informações sobre como chamar o DAO diretamente, consulte a [Nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

##  <a name="m_pworkspace"></a>  CDaoDatabase::m_pWorkspace

Contém um ponteiro para o objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) que contém o objeto de banco de dados.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar o espaço de trabalho diretamente, por exemplo, para obter ponteiros para outros objetos de banco de dados na coleção de bancos dos dados do espaço de trabalho.

##  <a name="open"></a>CDaoDatabase:: abrir

Você deve chamar essa função de membro para inicializar um `CDaoDatabase` objeto recém-criado que representa um banco de dados existente.

```
virtual void Open(
    LPCTSTR lpszName,
    BOOL bExclusive = FALSE,
    BOOL bReadOnly = FALSE,
    LPCTSTR lpszConnect = _T(""));
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de cadeia de caracteres que é o nome de um Microsoft Jet existente (. MDB) arquivo de banco de dados. Se o nome do arquivo tiver uma extensão, será necessário. Se sua rede der suporte à UNC (Convenção de nomenclatura uniforme), você também poderá especificar um caminho de rede,\\como\\"\\\\\\\MYSERVER\\\MYSHARE \MYDIR \MYDB. MDB ". (As barras invertidas duplas são necessárias em literais\\de cadeia de C++ caracteres porque "" é o caractere de escape.)

Algumas considerações se aplicam ao usar o *lpszName*. Se:

- Refere-se a um banco de dados que já está aberto para acesso exclusivo por outro usuário, o MFC gera uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md). Interceptar essa exceção para permitir que o usuário saiba que o banco de dados está indisponível.

- É uma cadeia de caracteres vazia ("") e *lpszConnect* é "ODBC;", uma caixa de diálogo listando todos os nomes de fonte de dados ODBC registrados é exibida para que o usuário possa selecionar um banco de dado. Você deve evitar conexões diretas com fontes de dados ODBC; em vez disso, use uma tabela anexada.

- Caso contrário, não faz referência a um banco de dados existente ou a um nome de fonte de dado ODBC `CDaoException`válido, o MFC gera uma exceção do tipo.

> [!NOTE]
>  Para obter detalhes sobre os códigos de erro do DAO, consulte o DAOERR. Arquivo H. Para obter informações relacionadas, consulte o tópico "erros de acesso a dados interceptáveis" na ajuda do DAO.

*bExclusive*<br/>
Um valor booliano que será TRUE se o banco de dados for aberto para acesso exclusivo (não compartilhado) e FALSE se o banco de dados for aberto para acesso compartilhado. Se você omitir esse argumento, o banco de dados será aberto para acesso compartilhado.

*bReadOnly*<br/>
Um valor booliano que será TRUE se o banco de dados for aberto para acesso somente leitura e FALSE se o banco de dados deve ser aberto para acesso de leitura/gravação. Se você omitir esse argumento, o banco de dados será aberto para acesso de leitura/gravação. Todos os conjuntos de registros dependentes herdam este atributo.

*lpszConnect*<br/>
Uma expressão de cadeia de caracteres usada para abrir o banco de dados. Essa cadeia de caracteres constitui os argumentos de conexão ODBC. Você deve fornecer os argumentos exclusivo e somente leitura para fornecer uma cadeia de caracteres de origem. Se o banco de dados for um banco de dados Microsoft Jet (. MDB), essa cadeia de caracteres está vazia (""). A sintaxe para o valor padrão — **_T**("") — fornece portabilidade para Unicode, bem como compilações ANSI de seu aplicativo.

### <a name="remarks"></a>Comentários

`Open`associa o banco de dados ao objeto DAO subjacente. Você não pode usar o objeto Database para construir objetos recordset, TableDef ou querydef até que ele seja inicializado. `Open`anexa o objeto Database à coleção de bancos de dados do espaço de trabalho associado.

Use os parâmetros da seguinte maneira:

- Se você estiver abrindo um Microsoft Jet (. MDB), use o parâmetro *lpszName* e passe uma cadeia de caracteres vazia para o parâmetro *lpszConnect* ou passe uma cadeia de caracteres de senha no formato "; PWD = password "se o banco de dados for protegido por senha (. Somente bancos de dados MDB).

- Se você estiver abrindo uma fonte de dados ODBC, passe uma cadeia de conexão ODBC válida em *lpszConnect* e uma cadeia de caracteres vazia em *lpszName*.

Para obter informações relacionadas, consulte o tópico "método OpenDatabase" na ajuda do DAO.

> [!NOTE]
>  Para obter um melhor desempenho ao acessar bancos de dados externos, incluindo bancos de dados ISAM e fontes ODBC, é recomendável anexar tabelas de banco de dados externas a um banco de dados do mecanismo do Microsoft Jet (. MDB) em vez de conectar-se diretamente à fonte de dados.

É possível que uma tentativa de conexão expire o tempo se, por exemplo, o host do DBMS não estiver disponível. Se a tentativa de conexão falhar `Open` , o lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

Os comentários restantes se aplicam somente a bancos de dados ODBC:

Se o banco de dados for um banco de dados ODBC e `Open` os parâmetros em sua chamada não contiverem informações suficientes para fazer a conexão, o driver ODBC abrirá uma caixa de diálogo para obter as informações necessárias do usuário. Quando você chama `Open`, sua cadeia de conexão, *lpszConnect*, é armazenada em modo privado e está disponível chamando a função de membro [GetConnect](#getconnect) .

Se desejar, você pode abrir sua própria caixa de diálogo antes de chamar `Open` para obter informações do usuário, como uma senha, e adicionar essas informações à cadeia de conexão que você passa para. `Open` Ou talvez você queira salvar a cadeia de conexão que você passa (talvez no registro do Windows) para poder reutilizá-la na próxima vez em `Open` que o `CDaoDatabase` aplicativo chamar um objeto.

Você também pode usar a cadeia de conexão para vários níveis de autorização de logon (cada um `CDaoDatabase` para um objeto diferente) ou para transmitir outras informações específicas do banco de dados.

##  <a name="setquerytimeout"></a>  CDaoDatabase::SetQueryTimeout

Chame essa função de membro para substituir o número padrão de segundos a permitir antes que as operações subsequentes no banco de dados conectado expirem o tempo limite.

```
void SetQueryTimeout(short nSeconds);
```

### <a name="parameters"></a>Parâmetros

*nSeconds*<br/>
O número de segundos para permitir antes que uma tentativa de consulta expire.

### <a name="remarks"></a>Comentários

Uma operação pode atingir o tempo limite devido a problemas de acesso à rede, tempo excessivo de processamento de consultas e assim por diante. Chame `SetQueryTimeout` antes de abrir o conjunto de registros ou antes de chamar as funções de membro [AddNew](../../mfc/reference/cdaorecordset-class.md#addnew), [Update](../../mfc/reference/cdaorecordset-class.md#update)ou [delete](../../mfc/reference/cdaorecordset-class.md#delete) do conjunto de registros se você quiser alterar o valor de tempo limite da consulta. A configuração afeta todas as chamadas [abrir](../../mfc/reference/cdaorecordset-class.md#open), `AddNew`, `Update`, e `Delete` subsequentes para todos os conjuntos de registros associados a esse objeto `CDaoDatabase`. Alterar o valor de tempo limite da consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, as operações de [movimentação](../../mfc/reference/cdaorecordset-class.md#move) subsequentes não usam o novo valor.

O valor padrão para tempos limite de consulta é de 60 segundos. Nem todos os bancos de dados dão suporte à capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta de 0, nenhum tempo limite ocorrerá; a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento.

Para obter informações relacionadas, consulte o tópico "Propriedade QueryTimeout" na ajuda do DAO.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
