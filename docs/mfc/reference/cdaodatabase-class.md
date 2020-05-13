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
ms.openlocfilehash: 0fbc4ee3f2033f7507a1ed68493fa7e48bc62c51
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754746"
---
# <a name="cdaodatabase-class"></a>Classe CDaoDatabase

Representa uma conexão com um banco de dados de acesso usando DAO (Data Access Objects, objetos de acesso a dados). O DAO é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

## <a name="syntax"></a>Sintaxe

```
class CDaoDatabase : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CDaoDatabase](#cdaodatabase)|Constrói um objeto `CDaoDatabase`. Chamada `Open` para conectar o objeto a um banco de dados.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::CanTransact](#cantransact)|Retorna não zero se o banco de dados suportar transações.|
|[CDaoDatabase::CanUpdate](#canupdate)|Retorna não zero `CDaoDatabase` se o objeto for updatable (não somente leitura).|
|[CDaoDatabase::Close](#close)|Fecha a conexão do banco de dados.|
|[CDaoDatabase::Criar](#create)|Cria o objeto de banco de dados `CDaoDatabase` DAO subjacente e inicializa o objeto.|
|[CDaoDatabase::CreateRelation](#createrelation)|Define uma nova relação entre as tabelas no banco de dados.|
|[CDaoDatabase::DeleteQueryDef](#deletequerydef)|Exclui um objeto querydef salvo na coleção QueryDefs do banco de dados.|
|[CDaoDatabase::DeleteRelation](#deleterelation)|Exclui uma relação existente entre tabelas no banco de dados.|
|[CDaoDatabase::DeleteTableDef](#deletetabledef)|Exclui a definição de uma tabela no banco de dados. Isso exclui a tabela real e todos os seus dados.|
|[CDaoDatabase::Execute](#execute)|Executa uma consulta de ação. Pedir `Execute` uma consulta que retorne resultados abre uma exceção.|
|[CDaoDatabase::GetConnect](#getconnect)|Retorna a seqüência `CDaoDatabase` de conexões usada para conectar o objeto a um banco de dados. Usado para ODBC.|
|[CDaoDatabase::GetName](#getname)|Retorna o nome do banco de dados atualmente em uso.|
|[CDaoDatabase::GetQueryDefCount](#getquerydefcount)|Retorna o número de consultas definidas para o banco de dados.|
|[CDaoDatabase::GetQueryDefInfo](#getquerydefinfo)|Retorna informações sobre uma consulta especificada definida no banco de dados.|
|[CDaoDatabase::GetQueryTimeout](#getquerytimeout)|Retorna o número de segundos após o qual as operações de consulta de banco de dados serão demoradas. Afeta todas as operações de abertura subsequentes, adicionar novas, atualizar e editar `Execute` operações e outras operações em fontes de dados ODBC (apenas) como chamadas.|
|[CDaoDatabase::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetados pela última atualização, edição `Execute`ou adicionar operação ou por uma chamada para .|
|[CDaoDatabase::GetRelationCount](#getrelationcount)|Retorna o número de relações definidas entre as tabelas no banco de dados.|
|[CDaoDatabase::GetRelationInfo](#getrelationinfo)|Retorna informações sobre uma relação especificada definida entre tabelas no banco de dados.|
|[CDaoDatabase::GetTableDefCount](#gettabledefcount)|Retorna o número de tabelas definidas no banco de dados.|
|[CDaoDatabase::GetTableDefInfo](#gettabledefinfo)|Retorna informações sobre uma tabela especificada no banco de dados.|
|[CDaoDatabase::GetVersion](#getversion)|Retorna a versão do mecanismo de banco de dados associado ao banco de dados.|
|[CDaoDatabase::IsOpen](#isopen)|Retorna não zero `CDaoDatabase` se o objeto estiver atualmente conectado a um banco de dados.|
|[CDaoDatabase::Open](#open)|Estabelece uma conexão com um banco de dados.|
|[CDaoDatabase::SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual as operações de consulta de banco de dados (apenas em fontes de dados ODBC) serão desatualizados. Afeta todas as operações de abertura subsequentes, adicione novas, atualize e exclua as operações.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoDatabase::m_pDAODatabase](#m_pdaodatabase)|Um ponteiro para o objeto de banco de dados DAO subjacente.|
|[CDaoDatabase::m_pWorkspace](#m_pworkspace)|Um ponteiro para o objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) que contém o banco de dados e define seu espaço de transação.|

## <a name="remarks"></a>Comentários

Para obter informações sobre os formatos de banco de dados suportados, consulte a função [getname](../../mfc/reference/cdaoworkspace-class.md#getname) member. Você pode ter `CDaoDatabase` um ou mais objetos ativos de cada vez em um determinado "espaço de trabalho", representado por um objeto [CDaoWorkspace.](../../mfc/reference/cdaoworkspace-class.md) O espaço de trabalho mantém uma coleção de objetos de banco de dados abertos, chamado de coleção de bancos de dados.

## <a name="usage"></a>Uso

Você pode criar objetos de banco de dados implicitamente, quando você cria objetos de conjunto de registros. Mas você também pode criar objetos de banco de dados explicitamente. Para usar um banco de `CDaoDatabase`dados existente explicitamente com , faça qualquer um dos seguintes:

- Construa `CDaoDatabase` um objeto, passando um ponteiro para um objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) aberto.

- Ou construa um `CDaoDatabase` objeto sem especificar o espaço de trabalho (o MFC cria um objeto de espaço de trabalho temporário).

Para criar um novo Microsoft Jet (. MDB) banco de `CDaoDatabase` dados, construa um objeto e chame sua função de membro [criar.](#create) *Não* ligue `Open` `Create`depois .

Para abrir um banco de `CDaoDatabase` dados existente, construa um objeto e chame sua função de membro [Aberto.](#open)

Qualquer uma dessas técnicas anexa o objeto do banco de dados DAO à coleta de bancos de dados do espaço de trabalho e abre uma conexão com os dados. Ao construir objetos [CDaoRecordset,](../../mfc/reference/cdaorecordset-class.md) [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)ou [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) para operar no banco de dados conectado, `CDaoDatabase` passe aos construtores para esses objetos um ponteiro para o objeto. Quando terminar de usar a conexão, ligue `CDaoDatabase` para a função [Close](#close) member e destrua o objeto. `Close`fecha todos os conjuntos de registros que você não fechou anteriormente.

## <a name="transactions"></a>Transactions

O processamento de transações de banco de dados é fornecido no nível do espaço de trabalho — consulte as funções de membro [BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans), [CommitTrans](../../mfc/reference/cdaoworkspace-class.md#committrans) e [Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) da classe `CDaoWorkspace`.

## <a name="odbc-connections"></a>Conexões ODBC

A maneira recomendada de trabalhar com fontes de dados ODBC é anexar tabelas externas a um Microsoft Jet (. MDB) banco de dados.

## <a name="collections"></a>Coleções

Cada banco de dados mantém suas próprias coleções de objetos tabledef, querydef, recordset e relationrelation. A `CDaoDatabase` classe fornece funções de membros para manipular esses objetos.

> [!NOTE]
> Os objetos são armazenados em DAO, não no objeto de banco de dados MFC. O MFC fornece classes para objetos tabledef, querydef e recordset, mas não para objetos de relação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDaoDatabase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaodatabasecantransact"></a><a name="cantransact"></a>Banco de dados cdao::CanTransact

Ligue para esta função de membro para determinar se o banco de dados permite transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor retornado

Não zero se o banco de dados suportar transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

As transações são gerenciadas no espaço de trabalho do banco de dados.

## <a name="cdaodatabasecanupdate"></a><a name="canupdate"></a>CDaoDatabase::CanUpdate

Ligue para esta função `CDaoDatabase` de membro para determinar se o objeto permite atualizações.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor retornado

Não zero `CDaoDatabase` se o objeto permitir atualizações; caso contrário 0, indicando que você passou TRUE em `CDaoDatabase` *bReadOnly* quando você abriu o objeto ou que o próprio banco de dados é somente leitura. Consulte a função De membro [Aberto.](#open)

### <a name="remarks"></a>Comentários

Para obter informações sobre a updatability do banco de dados, consulte o tópico "Updatable Property" no DAO Help.

## <a name="cdaodatabasecdaodatabase"></a><a name="cdaodatabase"></a>Banco de dados cdao::CDaoDatabase

Constrói um objeto `CDaoDatabase`.

```
CDaoDatabase(CDaoWorkspace* pWorkspace = NULL);
```

### <a name="parameters"></a>Parâmetros

*pWorkspace*<br/>
Um ponteiro `CDaoWorkspace` para o objeto que conterá o novo objeto do banco de dados. Se você aceitar o valor padrão de NULL, o construtor criará um objeto temporário `CDaoWorkspace` que usa o espaço de trabalho DAO padrão. Você pode obter um ponteiro para o objeto do espaço de trabalho através do membro de dados [m_pWorkspace.](#m_pworkspace)

### <a name="remarks"></a>Comentários

Depois de construir o objeto, se você estiver criando um novo Microsoft Jet (. MDB) banco de dados, chame a função de membro [Criar](#create) do objeto. Se você estiver, em vez disso, abrindo um banco de dados existente, chame a função de membro [Aberto](#open) do objeto.

Quando você terminar com o objeto, você deve chamar `CDaoDatabase` sua função de membro [próximo](#close) e, em seguida, destruir o objeto.

Você pode achar conveniente incorporar `CDaoDatabase` o objeto em sua classe de documentos.

> [!NOTE]
> Um `CDaoDatabase` objeto também é criado implicitamente se você abrir um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) sem passar um ponteiro para um objeto existente. `CDaoDatabase` Este objeto de banco de dados é fechado quando você fecha o objeto recordset.

## <a name="cdaodatabaseclose"></a><a name="close"></a>CDaoDatabase::Fechar

Ligue para essa função de membro para desconectar-se de um banco de dados e fechar quaisquer conjuntos de registros abertos, tabelas e consultas associadas ao banco de dados.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

É uma boa prática fechar esses objetos você mesmo antes de chamar essa função de membro. O `CDaoDatabase` fechamento de um objeto remove-o da coleção Desbancos no [espaço de trabalho](../../mfc/reference/cdaoworkspace-class.md)associado . Como `Close` não destrói `CDaoDatabase` o objeto, você pode reutilizar o objeto abrindo o mesmo banco de dados ou um banco de dados diferente.

> [!CAUTION]
> Ligue para a função [membro Update](../../mfc/reference/cdaorecordset-class.md#update) (se `Close` houver edições pendentes) e a função do membro em todos os objetos de conjunto de registros abertos antes de fechar um banco de dados. Se você sair de uma função que `CDaoDatabase` declare [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) ou objetos na pilha, o banco de dados será fechado, quaisquer alterações não salvas serão perdidas, todas as transações pendentes serão revertidas e quaisquer edições pendentes de seus dados serão perdidas.

> [!CAUTION]
> Se você tentar fechar um objeto de banco de dados enquanto quaisquer objetos de conjunto de registros estiverem abertos ou se você tentar fechar um objeto de espaço de trabalho enquanto quaisquer objetos de banco de dados pertencentes a esse espaço de trabalho específico estiverem abertos, esses objetos do conjunto de registros serão fechados e quaisquer atualizações ou edições pendentes serão revertidas. Se você tentar fechar um objeto de espaço de trabalho enquanto quaisquer objetos de banco de dados pertencentes a ele estiverem abertos, a operação fechará todos os objetos de banco de dados pertencentes a esse objeto de espaço de trabalho específico, o que pode resultar em objetos de conjunto de registros não fechados sendo fechados. Se você não fechar o objeto do banco de dados, o MFC relatará uma falha de afirmação nas compilações de depuração.

Se o objeto do banco de dados for definido fora do escopo de uma função e você sair da função sem fechá-la, o objeto do banco de dados permanecerá aberto até que seja explicitamente fechado ou o módulo no qual ele é definido está fora do escopo.

## <a name="cdaodatabasecreate"></a><a name="create"></a>CDaoDatabase::Criar

Para criar um novo Microsoft Jet (. MDB) banco de dados, chame `CDaoDatabase` essa função de membro depois de construir um objeto.

```
virtual void Create(
    LPCTSTR lpszName,
    LPCTSTR lpszLocale = dbLangGeneral,
    int dwOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de string que é o nome do arquivo de banco de dados que você está criando. Pode ser o caminho completo e o nome\\do arquivo, como "C: \MYDB. MDB". Você deve fornecer um nome. Se você não fornecer uma extensão de nome de arquivo, . MDB é anexado. Se sua rede suportar a convenção de nomeação uniforme (UNC),\\\\\\você também\\poderá\\especificar\\um caminho de rede, como " \MYSERVER \MYSHARE \MYDIR \MYDB". Apenas o Microsoft Jet (. MDB) arquivos de banco de dados podem ser criados usando esta função membro. (Barras duplas são necessárias em literais de seqüência porque "\\" é o caractere de fuga C++.)

*lpszLocale*<br/>
Uma expressão de string usada para especificar ordem de coletânea para criar o banco de dados. O valor padrão é `dbLangGeneral`. Os valores possíveis são:

- `dbLangGeneral`Inglês, alemão, francês, português, italiano e espanhol moderno

- `dbLangArabic`Árabe

- `dbLangCyrillic`Russo

- `dbLangCzech`Tcheco

- `dbLangDutch`Holandês

- `dbLangGreek`Grego

- `dbLangHebrew`Hebraico

- `dbLangHungarian`Húngaro

- `dbLangIcelandic`Islandês

- `dbLangNordic`Idiomas nórdicos (apenas a versão 1.0 do mecanismo de banco de dados microsoft jet)

- `dbLangNorwdan`Norueguês e dinamarquês

- `dbLangPolish`Polonês

- `dbLangSpanish`Espanhol tradicional

- `dbLangSwedfin`Sueco e finlandês

- `dbLangTurkish`Turco

*dwOptions*<br/>
Um inteiro que indica uma ou mais opções. Os valores possíveis são:

- `dbEncrypt`Crie um banco de dados criptografado.

- `dbVersion10`Crie um banco de dados com o banco de dados microsoft jet versão 1.0.

- `dbVersion11`Crie um banco de dados com o banco de dados microsoft jet versão 1.1.

- `dbVersion20`Crie um banco de dados com o banco de dados Microsoft Jet versão 2.0.

- `dbVersion30`Crie um banco de dados com o banco de dados microsoft jet versão 3.0.

Se você omite a constante de criptografia, um banco de dados não criptografado será criado. Você pode especificar apenas uma constante de versão. Se você omitir uma constante de versão, um banco de dados que usa o banco de dados do Microsoft Jet versão 3.0 é criado.

> [!CAUTION]
> Se um banco de dados não for criptografado, é possível, mesmo que você implemente a segurança de usuário/senha, ler diretamente o arquivo de disco binário que constitui o banco de dados.

### <a name="remarks"></a>Comentários

`Create`cria o arquivo de banco de dados e o objeto de banco de dados DAO subjacente e inicializa o objeto C++. O objeto é anexado à coleção de bancos de dados do espaço de trabalho associado. O objeto do banco de dados está em estado aberto; não ligue `Open*` `Create`depois .

> [!NOTE]
> Com `Create`, você pode criar apenas Microsoft Jet (. BASES de dados do MDB. Não é possível criar bancos de dados ISAM ou bancos de dados ODBC.

## <a name="cdaodatabasecreaterelation"></a><a name="createrelation"></a>CDaoDatabase::CreateRelation

Chame essa função de membro para estabelecer uma relação entre um ou mais campos em uma tabela primária no banco de dados e um ou mais campos em uma tabela estrangeira (outra tabela no banco de dados).

```cpp
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
O nome único do objeto de relação. O nome deve começar com uma letra e pode conter um máximo de 40 caracteres. Ele pode incluir números e sublinhar caracteres, mas não pode incluir pontuação ou espaços.

*lpszTable*<br/>
O nome da tabela primária na relação. Se a tabela não existir, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

*lpszForeignTable*<br/>
O nome da tabela estrangeira na relação. Se a tabela não existir, o MFC lança uma exceção do tipo `CDaoException`.

*lAtributos*<br/>
Um valor longo que contém informações sobre o tipo de relacionamento. Você pode usar esse valor para impor a integridade referencial, entre outras coisas. Você pode usar o operador bitwise-OR **(&#124;) **para combinar qualquer um dos seguintes valores (desde que a combinação faça sentido):

- `dbRelationUnique`Relacionamento é um para um.

- `dbRelationDontEnforce`A relação não é imposta (sem integridade referencial).

- `dbRelationInherited`A relação existe em um banco de dados não atual que contém as duas tabelas anexadas.

- `dbRelationUpdateCascade`As atualizações serão em cascata (para mais sobre cascatas, veja Observações).

- `dbRelationDeleteCascade`As exclusões vão cair.

*lpszField*<br/>
Um ponteiro para uma seqüência de terminadas nula contendo o nome de um campo na tabela primária (nomeado por *lpszTable*).

*lpszForeignField*<br/>
Um ponteiro para uma seqüência de terminadas nula contendo o nome de um campo na tabela estrangeira (nomeado por *lpszForeignTable*).

*relinfo*<br/>
Uma referência a um objeto [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) que contém informações sobre a relação que você deseja criar.

### <a name="remarks"></a>Comentários

A relação não pode envolver uma consulta ou uma tabela anexada de um banco de dados externo.

Use a primeira versão da função quando a relação envolver um campo em cada uma das duas tabelas. Use a segunda versão quando a relação envolver vários campos. O número máximo de campos em uma relação é 14.

Esta ação cria um objeto de relação DAO subjacente, mas este é um detalhe de implementação do MFC, uma vez que o encapsulamento de objetos de relação do MFC está contido dentro da classe `CDaoDatabase`. MFC não fornece uma classe para relações.

Se você definir os atributos do objeto de relação para ativar operações em cascata, o mecanismo de banco de dados atualizará ou excluirá automaticamente registros em uma ou mais outras tabelas quando forem feitas alterações nas tabelas-chave primárias relacionadas.

Por exemplo, suponha que você estabeleça uma relação de exclusão em cascata entre uma tabela Clientes e uma tabela de Pedidos. Quando você exclui registros da tabela Clientes, os registros na tabela Pedidos relacionados a esse cliente também são excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela Pedidos e outras tabelas, os registros dessas tabelas serão automaticamente excluídos quando você exclui registros da tabela Clientes.

Para obter informações relacionadas, consulte o tópico "CreateRelation Method" no DAO Help.

## <a name="cdaodatabasedeletequerydef"></a><a name="deletequerydef"></a>CDaoDatabase::DeleteQueryDef

Ligue para esta função de membro para excluir o consulta `CDaoDatabase` especificado — consulta salva — da coleção QueryDefs do objeto.

```cpp
void DeleteQueryDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da consulta salva para excluir.

### <a name="remarks"></a>Comentários

Posteriormente, essa consulta não é mais definida no banco de dados.

Para obter informações sobre como criar objetos querydef, consulte a classe [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md). Um objeto querydef torna-se associado a um objeto específico `CDaoDatabase` quando você constrói o `CDaoQueryDef` objeto, passando-o um ponteiro para o objeto do banco de dados.

## <a name="cdaodatabasedeleterelation"></a><a name="deleterelation"></a>CDaoDatabase::DeleteRelation

Chame essa função de membro para excluir uma relação existente da coleção relações do objeto de banco de dados.

```cpp
void DeleteRelation(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da relação para excluir.

### <a name="remarks"></a>Comentários

Depois, a relação não existe mais.

Para obter informações relacionadas, consulte o tópico "Método de exclusão" na Ajuda da DAO.

## <a name="cdaodatabasedeletetabledef"></a><a name="deletetabledef"></a>CDaoDatabase::DeleteTableDef

Chame esta função de membro para excluir a tabela `CDaoDatabase` especificada e todos os seus dados da coleção TableDefs do objeto.

```cpp
void DeleteTableDef(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome da mesa para excluir.

### <a name="remarks"></a>Comentários

Posteriormente, essa tabela não é mais definida no banco de dados.

> [!NOTE]
> Tenha muito cuidado para não excluir tabelas do sistema.

Para obter informações sobre a criação de objetos tabledef, consulte a classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md). Um objeto tabledef torna-se associado a um objeto específico `CDaoDatabase` quando você constrói o `CDaoTableDef` objeto, passando-o um ponteiro para o objeto do banco de dados.

Para obter informações relacionadas, consulte o tópico "Método de exclusão" na Ajuda da DAO.

## <a name="cdaodatabaseexecute"></a><a name="execute"></a>CDaoDatabase::Execute

Chame essa função de membro para executar uma consulta de ação ou executar uma declaração SQL no banco de dados.

```cpp
void Execute(
    LPCTSTR lpszSQL,
    int nOptions = dbFailOnError);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Ponteiro para uma seqüência de terminadas nula contendo um comando SQL válido para executar.

*nOpções*<br/>
Um inteiro que especifica opções relacionadas à integridade da consulta. Você pode usar o operador bitwise-OR **(&#124;) **para combinar qualquer uma das seguintes constantes `dbInconsistent` (desde que a combinação faça sentido — por exemplo, você não combinaria com `dbConsistent`):

- `dbDenyWrite`Negar permissão de gravação para outros usuários.

- `dbInconsistent`(Padrão) Atualizações inconsistentes.

- `dbConsistent`Atualizações consistentes.

- `dbSQLPassThrough`Passagem SQL. Faz com que a declaração SQL seja passada para uma fonte de dados ODBC para processamento.

- `dbFailOnError`Reverter as atualizações se ocorrer um erro.

- `dbSeeChanges`Gerar um erro de tempo de execução se outro usuário estiver alterando os dados que você está editando.

> [!NOTE]
> Se `dbInconsistent` ambos `dbConsistent` e estiverem incluídos ou se nenhum deles estiver incluído, o resultado será o padrão. Para uma explicação dessas constantes, consulte o tópico "Execute Method" no DAO Help.

### <a name="remarks"></a>Comentários

`Execute`funciona apenas para consultas de ação ou consultas de passagem SQL que não retornam resultados. Ele não funciona para consultas selecionadas, que retornam registros.

Para obter uma definição e informações sobre consultas de ação, consulte os tópicos "Consulta de ação" e "Método executar" no DAO Help.

> [!TIP]
> Dada uma declaração SQL sintáticamente `Execute` correta e permissões adequadas, a função do membro não falhará mesmo que nenhuma linha possa ser modificada ou excluída. Portanto, use sempre `dbFailOnError` a opção `Execute` ao usar a função membro para executar uma consulta de atualização ou exclusão. Essa opção faz com que o MFC lance uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md) e reverta todas as alterações bem sucedidas se algum dos registros afetados estiver bloqueado e não puder ser atualizado ou excluído. Note que você `GetRecordsAffected` sempre pode ligar para ver quantos registros foram afetados.

Ligue para a função de membro [GetRecordsAffected](#getrecordsaffected) do objeto do `Execute` banco de dados para determinar o número de registros afetados pela chamada mais recente. Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos ao executar uma consulta de ação. A contagem retornada não refletirá alterações nas tabelas relacionadas quando as atualizações ou exclusões em cascata estiverem em vigor.

`Execute`não retorna um conjunto de registros. O `Execute` uso de uma consulta que seleciona registros faz `CDaoException`com que o MFC lance uma exceção do tipo . (Não há `ExecuteSQL` função de membro `CDatabase::ExecuteSQL`análoga a .)

## <a name="cdaodatabasegetconnect"></a><a name="getconnect"></a>Banco de dados CDao:GetConnect

Ligue para esta função de membro para `CDaoDatabase` recuperar a seqüência de conexão usada para conectar o objeto a um banco de dados ODBC ou ISAM.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor retornado

A seqüência de conexões se [Open](#open) foi chamada com sucesso em uma fonte de dados ODBC; caso contrário, uma corda vazia. Para um Microsoft Jet (. MDB) banco de dados, a seqüência está `dbSQLPassThrough` sempre vazia, a menos que você configure-a para uso com a opção usada com a função [Executar](#execute) membro ou usada na abertura de um conjunto de registros.

### <a name="remarks"></a>Comentários

A string fornece informações sobre a origem de um banco de dados aberto ou de um banco de dados usado em uma consulta de passagem. A seqüência de conexões é composta por um especificador de tipo de banco de dados e zero ou mais parâmetros separados por ponto e vírgula.

> [!NOTE]
> Usar as classes DaO do MFC para se conectar a uma fonte de dados via ODBC é menos eficiente do que conectar-se através de uma tabela anexada.

> [!NOTE]
> A seqüência de conexões é usada para passar informações adicionais para o ODBC e certos drivers ISAM conforme necessário. Não é usado para . Bancos de dados do MDB. Para as tabelas base do banco de dados do Microsoft Jet, a seqüência de conexões é uma seqüência de string vazia (""), exceto quando você a usa para uma consulta de passagem SQL conforme descrito em Valor de Retorno acima.

Consulte a função De membro [Aberto](#open) para obter uma descrição de como a seqüência de conexões é criada. Uma vez que a seqüência de conexões tenha sido definida na `Open` chamada, você pode usá-la posteriormente para verificar a configuração para determinar o tipo, caminho, ID do usuário, Senha ou fonte de dados ODBC do banco de dados.

## <a name="cdaodatabasegetname"></a><a name="getname"></a>CDaoDatabase::GetName

Ligue para esta função de membro para recuperar o nome do banco de dados atualmente aberto, que é o nome de um arquivo de banco de dados existente ou o nome de uma fonte de dados ODBC registrada.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

O caminho completo e o nome do arquivo do banco de dados se forem bem sucedidos; caso contrário, um [CString](../../atl-mfc-shared/reference/cstringt-class.md)vazio .

### <a name="remarks"></a>Comentários

Se sua rede suportar a convenção de nomeação uniforme (UNC), você\\\\\\também\\poderá especificar um caminho de rede — por exemplo, \MYSERVER \MYSHARE\\\MYDIR\\\MYDB. MDB". (Barras duplas são necessárias em literais de seqüência porque "\\" é o caractere de fuga C++.)

Você pode, por exemplo, querer exibir esse nome em um título. Se ocorrer um erro enquanto o nome estiver sendo recuperado, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

> [!NOTE]
> Para um melhor desempenho quando os bancos de dados externos estão sendo acessados, recomendamos que você conecte tabelas de banco de dados externas a um banco de dados Microsoft Jet (. MDB) em vez de se conectar diretamente à fonte de dados.

O tipo de banco de dados é indicado pelo arquivo ou diretório que o caminho aponta, da seguinte forma:

|Pathname aponta para..|Tipo de banco de dados|
|--------------------------|-------------------|
|. Arquivo MDB|Banco de dados Microsoft Jet (Microsoft Access)|
|Diretório que contém . Arquivos DBF(s)|banco de dados dBASE|
|Diretório que contém . Arquivo XLS|Banco de dados Microsoft Excel|
|Diretório que contém . PDX file(s)|Banco de dados Paradoxo|
|Diretório que contém arquivos de banco de dados de texto formatados adequadamente|Banco de dados de formato de texto|

Para bancos de dados ODBC como SQL Server e Oracle, a seqüência de conexões do banco de dados identifica um nome de origem de dados (DSN) registrado pelo ODBC.

## <a name="cdaodatabasegetquerydefcount"></a><a name="getquerydefcount"></a>CDaoDatabase::GetQueryDefCount

Ligue para esta função de membro para recuperar o número de consultas definidas na coleção QueryDefs do banco de dados.

```
short GetQueryDefCount();
```

### <a name="return-value"></a>Valor retornado

O número de consultas definidas no banco de dados.

### <a name="remarks"></a>Comentários

`GetQueryDefCount`é útil se você precisar fazer loop através de todas as consultas na coleção QueryDefs. Para obter informações sobre uma determinada consulta na coleção, consulte [GetQueryDefInfo](#getquerydefinfo).

## <a name="cdaodatabasegetquerydefinfo"></a><a name="getquerydefinfo"></a>CDaoDatabase::GetQueryDefInfo

Ligue para esta função de membro para obter vários tipos de informações sobre uma consulta definida no banco de dados.

```cpp
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
O índice da consulta predefinida na coleção QueryDefs do banco de dados, para busca por índice.

*querydefinfo*<br/>
Uma referência a um objeto [CDaoQueryDefInfo](../../mfc/reference/cdaoquerydefinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne sobre o conjunto de registros:

- nome de AFX_DAO_PRIMARY_INFO (Padrão), Tipo

- AFX_DAO_SECONDARY_INFO informações primárias mais: Data criada, data da última atualização, registros de retorno, updatable

- AFX_DAO_ALL_INFO informações primárias e secundárias mais: SQL, Connect, ODBCTimeout

*lpszName*<br/>
Uma seqüência contendo o nome de uma consulta definida no banco de dados, para procurar pelo nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma consulta por índice na coleção QueryDefs do banco de dados ou pelo nome da consulta.

Para obter uma descrição das informações retornadas em *consultadefinfo,* consulte a estrutura [CDaoQueryDefInfo.](../../mfc/reference/cdaoquerydefinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Se você solicitar um nível de informação, você também obterá níveis prévios de informação.

## <a name="cdaodatabasegetquerytimeout"></a><a name="getquerytimeout"></a>CDaoDatabase::GetQueryTimeout

Ligue para esta função de membro para recuperar o número atual de segundos para permitir antes que as operações subseqüentes no banco de dados conectado sejam cronometradas.

```
short GetQueryTimeout();
```

### <a name="return-value"></a>Valor retornado

Um inteiro curto contendo o valor de tempo em segundos.

### <a name="remarks"></a>Comentários

Uma operação pode ser deshorada devido a problemas de acesso à rede, tempo de processamento de consulta excessiva, e assim por diante. Enquanto a configuração estiver em vigor, ela afeta todas as operações abertas, `CDaoDatabase` adiciona novas, atualizae e exclui em quaisquer conjuntos de registros associados a este objeto. Você pode alterar a configuração de tempo mais atual chamando [SetQueryTimeout](#setquerytimeout). Alterar o valor de tempo de consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, as operações [subsequentes do Move](../../mfc/reference/cdaorecordset-class.md#move) não usam o novo valor. O valor padrão é definido inicialmente quando o mecanismo do banco de dados é inicializado.

O valor padrão para tempos de consulta é retirado do registro do Windows. Se não houver configuração de registro, o padrão é de 60 segundos. Nem todos os bancos de dados suportam a capacidade de definir um valor de tempo de consulta. Se você definir um valor de tempo de consulta de 0, não haverá intervalo; e a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a chamada falhar, o MFC lançará uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

Para obter informações relacionadas, consulte o tópico "QueryTimeout Property" no DAO Help.

## <a name="cdaodatabasegetrecordsaffected"></a><a name="getrecordsaffected"></a>CDaoDatabase::GetRecordsAffected

Ligue para esta função de membro para determinar o número de registros afetados pela chamada mais recente da função [Executar](#execute) membro.

```
long GetRecordsAffected();
```

### <a name="return-value"></a>Valor retornado

Um inteiro longo contendo o número de registros afetados.

### <a name="remarks"></a>Comentários

O valor retornado inclui o número de registros excluídos, atualizados ou `Execute`inseridos por uma consulta de ação executada com . A contagem retornada não refletirá alterações nas tabelas relacionadas quando as atualizações ou exclusões em cascata estiverem em vigor.

Para obter informações relacionadas, consulte o tópico "Registrosde propriedade afetada" na Ajuda da DAO.

## <a name="cdaodatabasegetrelationcount"></a><a name="getrelationcount"></a>CDaoDatabase::GetRelationCount

Ligue para esta função membro para obter o número de relações definidas entre as tabelas no banco de dados.

```
short GetRelationCount();
```

### <a name="return-value"></a>Valor retornado

O número de relações definidas entre tabelas no banco de dados.

### <a name="remarks"></a>Comentários

`GetRelationCount`é útil se você precisar fazer loop através de todas as relações definidas na coleção de Relações do banco de dados. Para obter informações sobre uma determinada relação na coleção, consulte [GetRelationInfo](#getrelationinfo).

Para ilustrar o conceito de uma relação, considere uma tabela de Fornecedores e uma tabela de Produtos, que pode ter uma relação de um a muitos. Nessa relação, um fornecedor pode fornecer mais de um produto. Outras relações são um-para-um e muitos para muitos.

## <a name="cdaodatabasegetrelationinfo"></a><a name="getrelationinfo"></a>CDaoDatabase::GetRelationInfo

Ligue para esta função membro para obter informações sobre uma relação especificada na coleção de Relações do banco de dados.

```cpp
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
O índice do objeto de relação na coleção relações da base de dados, para busca por índice.

*relinfo*<br/>
Uma referência a um objeto [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a relação a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne sobre a relação:

- AFX_DAO_PRIMARY_INFO nome (Padrão), Tabela, Tabela Estrangeira

- atributos de AFX_DAO_SECONDARY_INFO, informações de campo

As Informações de Campo são um objeto [CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md) contendo os campos da tabela principal envolvida na relação.

*lpszName*<br/>
Uma seqüência contendo o nome do objeto de relação, para procurar pelo nome.

### <a name="remarks"></a>Comentários

Duas versões desta função fornecem acesso por índice ou por nome. Para obter uma descrição das informações retornadas em *relinfo,* consulte a estrutura [CDaoRelationInfo.](../../mfc/reference/cdaorelationinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Se você solicitar informações em um nível, você também obterá informações em qualquer nível anterior.

> [!NOTE]
> Se você definir os atributos do objeto`dbRelationUpdateCascades` de `dbRelationDeleteCascades`relação para ativar operações em cascata (ou ), o mecanismo de banco de dados Microsoft Jet atualiza ou exclui automaticamente registros em uma ou mais outras tabelas quando alterações são feitas em tabelas-chave principais relacionadas. Por exemplo, suponha que você estabeleça uma relação de exclusão em cascata entre uma tabela Clientes e uma tabela de Pedidos. Quando você exclui registros da tabela Clientes, os registros na tabela Pedidos relacionados a esse cliente também são excluídos. Além disso, se você estabelecer relações de exclusão em cascata entre a tabela Pedidos e outras tabelas, os registros dessas tabelas serão automaticamente excluídos quando você exclui registros da tabela Clientes.

## <a name="cdaodatabasegettabledefcount"></a><a name="gettabledefcount"></a>CDaoDatabase::GetTableDefCount

Ligue para esta função de membro para recuperar o número de tabelas definidas no banco de dados.

```
short GetTableDefCount();
```

### <a name="return-value"></a>Valor retornado

O número de tabelas definidas no banco de dados.

### <a name="remarks"></a>Comentários

`GetTableDefCount`é útil se você precisar fazer loop através de todas as tabledefs na coleção TableDefs do banco de dados. Para obter informações sobre uma determinada tabela na coleção, consulte [GetTableDefInfo](#gettabledefinfo).

## <a name="cdaodatabasegettabledefinfo"></a><a name="gettabledefinfo"></a>CDaoDatabase::GetTableDefInfo

Ligue para esta função de membro para obter vários tipos de informações sobre uma tabela definida no banco de dados.

```cpp
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
O índice do objeto tabledef na coleção TableDefs da base de dados, para busca por índice.

*tabledefinfo*<br/>
Uma referência a um objeto [CDaoTableDefInfo](../../mfc/reference/cdaotabledefinfo-structure.md) que retorna as informações solicitadas.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre a tabela a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne sobre a relação:

- nome AFX_DAO_PRIMARY_INFO (Padrão), Updatable, Atributos

- AFX_DAO_SECONDARY_INFO informações primárias mais: Data criada, data última atualizada, nome da tabela de origem, conectar

- AFX_DAO_ALL_INFO informações primárias e secundárias mais: Regra de validação, texto de validação, contagem de registros

*lpszName*<br/>
O nome do objeto tabledef, para procurar pelo nome.

### <a name="remarks"></a>Comentários

Duas versões da função são fornecidas para que você possa selecionar uma tabela por índice na coleção TableDefs do banco de dados ou pelo nome da tabela.

Para obter uma descrição das informações retornadas no *tabledefinfo,* consulte a estrutura [CDaoTableDefInfo.](../../mfc/reference/cdaotabledefinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Se você solicitar informações em um nível, você obterá informações para quaisquer níveis anteriores também.

> [!NOTE]
> A AFX_DAO_ALL_INFO opção fornece informações que podem demorar a obter. Neste caso, contar os registros na tabela pode ser muito demorado se houver muitos registros.

## <a name="cdaodatabasegetversion"></a><a name="getversion"></a>CDaoDatabase::GetVersion

Ligue para esta função de membro para determinar a versão do arquivo de banco de dados do Microsoft Jet.

```
CString GetVersion();
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que indica a versão do arquivo de banco de dados associado ao objeto.

### <a name="remarks"></a>Comentários

O valor retornado representa o número da versão no formulário "major.minor"; por exemplo, "3.0". O número da versão do produto (por exemplo, 3.0) consiste no número da versão (3), um período, e no número de lançamento (0). As versões até o momento são 1.0, 1.1, 2.0 e 3.0.

Para obter informações relacionadas, consulte o tópico "Version Property" no DAO Help.

## <a name="cdaodatabaseisopen"></a><a name="isopen"></a>Banco de dados CDao:IsOpen

Ligue para esta função `CDaoDatabase` de membro para determinar se o objeto está aberto no momento em um banco de dados.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `CDaoDatabase` se o objeto estiver atualmente aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cdaodatabasem_pdaodatabase"></a><a name="m_pdaodatabase"></a>CDaoDatabase::m_pDAODatabase

Contém um ponteiro para a interface OLE para `CDaoDatabase` o objeto de banco de dados DAO subjacente ao objeto.

### <a name="remarks"></a>Comentários

Use este ponteiro se precisar acessar diretamente a interface DAO.

Para obter informações sobre como ligar diretamente para o DAO, consulte [nota técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).

## <a name="cdaodatabasem_pworkspace"></a><a name="m_pworkspace"></a>CDaoDatabase::m_pWorkspace

Contém um ponteiro para o objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) que contém o objeto do banco de dados.

### <a name="remarks"></a>Comentários

Use este ponteiro se você precisar acessar o espaço de trabalho diretamente — por exemplo, para obter ponteiros para outros objetos de banco de dados na coleção de bancos de dados do espaço de trabalho.

## <a name="cdaodatabaseopen"></a><a name="open"></a>CDaoDatabase::Aberto

Você deve chamar essa função de membro `CDaoDatabase` para inicializar um objeto recém-construído que representa um banco de dados existente.

```
virtual void Open(
    LPCTSTR lpszName,
    BOOL bExclusive = FALSE,
    BOOL bReadOnly = FALSE,
    LPCTSTR lpszConnect = _T(""));
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Uma expressão de string que é o nome de um Microsoft Jet existente (. MDB) arquivo de banco de dados. Se o nome do arquivo tiver uma extensão, é necessário. Se sua rede suportar a convenção de nomeação uniforme (UNC),\\\\\\você também\\poderá\\especificar\\um caminho de rede, como " \MYSERVER \MYSHARE \MYDIR \MYDB. MDB". (Barras duplas são necessárias em literais de seqüência porque "\\" é o caractere de fuga C++.)

Algumas considerações se aplicam ao usar *lpszName*. Se:

- Refere-se a um banco de dados que já está aberto para acesso exclusivo por outro usuário, o MFC lança uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md). Prenda essa exceção para que seu usuário saiba que o banco de dados não está disponível.

- É uma string vazia (""" e *lpszConnect* é "ODBC;", uma caixa de diálogo que lista todos os nomes de origem de dados ODBC registrados é exibida para que o usuário possa selecionar um banco de dados. Você deve evitar conexões diretas com fontes de dados ODBC; use uma tabela anexada em vez disso.

- Caso contrário, não se refere a um banco de dados existente ou nome `CDaoException`de origem de dados ODBC válido, MFC lança uma exceção do tipo .

> [!NOTE]
> Para obter detalhes sobre códigos de erro DAO, consulte o DAOERR. Arquivo H. Para obter informações relacionadas, consulte o tópico "Erros de acesso a dados trappable" na Ajuda da DAO.

*bExclusivo*<br/>
Um valor booleano que é VERDADEIRO se o banco de dados for aberto para acesso exclusivo (não compartilhado) e FALSO se o banco de dados for aberto para acesso compartilhado. Se você omiti-lo esse argumento, o banco de dados será aberto para acesso compartilhado.

*bReadOnly*<br/>
Um valor booleano que é VERDADEIRO se o banco de dados for aberto para acesso somente leitura e FALSO se o banco de dados for aberto para acesso à leitura/gravação. Se você omiti-lo esse argumento, o banco de dados será aberto para acesso a leitura/gravação. Todos os conjuntos de registros dependentes herdam esse atributo.

*lpszConnect*<br/>
Uma expressão de string usada para abrir o banco de dados. Esta seqüência constitui os argumentos de conexão ODBC. Você deve fornecer os argumentos exclusivos e somente leitura para fornecer uma seqüência de origem. Se o banco de dados for um banco de dados do Microsoft Jet (. MDB), essa corda está vazia ("). A sintaxe para o valor padrão — **_T**("") — fornece portabilidade para Unicode, bem como compilações ANSI do seu aplicativo.

### <a name="remarks"></a>Comentários

`Open`associa o banco de dados com o objeto DAO subjacente. Não é possível usar o objeto de banco de dados para construir conjunto de registros, tabledef ou querydef objetos até que ele seja inicializado. `Open`anexa o objeto do banco de dados à coleção de bancos de dados do espaço de trabalho associado.

Use os parâmetros da seguinte forma:

- Se você está abrindo um Microsoft Jet (. MDB) banco de dados, use o parâmetro *lpszName* e passe uma seqüência vazia para o parâmetro *lpszConnect* ou passe uma seqüência de senha do formulário "; PWD=senha" se o banco de dados estiver protegido por senha (. Apenas bancos de dados do MDB).

- Se você estiver abrindo uma fonte de dados ODBC, passe uma seqüência de conexão ODBC válida no *lpszConnect* e uma string vazia no *lpszName*.

Para obter informações relacionadas, consulte o tópico "Método OpenDatabase" no DAO Help.

> [!NOTE]
> Para obter um melhor desempenho ao acessar bancos de dados externos, incluindo bancos de dados ISAM e fontes de dados ODBC, recomenda-se anexar tabelas de banco de dados externas a um banco de dados do Microsoft Jet (. MDB) em vez de se conectar diretamente à fonte de dados.

É possível para uma tentativa de conexão de tempo se, por exemplo, o host DBMS não estiver disponível. Se a tentativa `Open` de conexão falhar, será lançada uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).

As observações restantes se aplicam apenas aos bancos de dados ODBC:

Se o banco de dados for um `Open` banco de dados ODBC e os parâmetros da sua chamada não contiverem informações suficientes para fazer a conexão, o driver ODBC abrirá uma caixa de diálogo para obter as informações necessárias do usuário. Quando você `Open`chama , sua seqüência de conexão, *lpszConnect*, é armazenado em particular e está disponível ligando para a função de membro [GetConnect.](#getconnect)

Se desejar, você pode abrir sua própria `Open` caixa de diálogo antes de ligar para obter informações do usuário, `Open`como uma senha, e adicionar essas informações à seqüência de conexão para a que você passa . Ou você pode querer salvar a seqüência de conexão que você passa (talvez no `Open` registro `CDaoDatabase` do Windows) para que você possa reutilizá-la na próxima vez que seu aplicativo chamar um objeto.

Você também pode usar a seqüência de conexões `CDaoDatabase` para vários níveis de autorização de login (cada um para um objeto diferente) ou para transmitir outras informações específicas do banco de dados.

## <a name="cdaodatabasesetquerytimeout"></a><a name="setquerytimeout"></a>CDaoDatabase::SetQueryTimeout

Ligue para esta função de membro para substituir o número padrão de segundos para permitir antes das operações subseqüentes no tempo de tempo do banco de dados conectado.

```cpp
void SetQueryTimeout(short nSeconds);
```

### <a name="parameters"></a>Parâmetros

*nSeconds*<br/>
O número de segundos a serem permitidos antes de uma tentativa de consulta é eliminado.

### <a name="remarks"></a>Comentários

Uma operação pode ser deshorada por causa de problemas de acesso à rede, tempo de processamento de consulta excessiva, e assim por diante. Ligue `SetQueryTimeout` antes de abrir seu conjunto de registros ou antes de chamar as funções [addnew,](../../mfc/reference/cdaorecordset-class.md#addnew) [update](../../mfc/reference/cdaorecordset-class.md#update)ou [delete do](../../mfc/reference/cdaorecordset-class.md#delete) membro do conjunto de registros se quiser alterar o valor de tempo de consulta. A configuração afeta todas `AddNew` `Update`as `Delete` [chamadas de Open](../../mfc/reference/cdaorecordset-class.md#open), `CDaoDatabase` e chamadas subseqüentes para quaisquer conjuntos de registros associados a este objeto. Alterar o valor de tempo de consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, as operações [subsequentes do Move](../../mfc/reference/cdaorecordset-class.md#move) não usam o novo valor.

O valor padrão para intervalos de consulta é de 60 segundos. Nem todos os bancos de dados suportam a capacidade de definir um valor de tempo de consulta. Se você definir um valor de tempo de consulta de 0, não haverá intervalo; a comunicação com o banco de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento.

Para obter informações relacionadas, consulte o tópico "QueryTimeout Property" no DAO Help.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CDaoException](../../mfc/reference/cdaoexception-class.md)
