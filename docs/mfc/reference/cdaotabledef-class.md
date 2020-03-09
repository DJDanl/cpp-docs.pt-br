---
title: Classe CDaoTableDef
ms.date: 11/04/2016
f1_keywords:
- CDaoTableDef
- AFXDAO/CDaoTableDef
- AFXDAO/CDaoTableDef::CDaoTableDef
- AFXDAO/CDaoTableDef::Append
- AFXDAO/CDaoTableDef::CanUpdate
- AFXDAO/CDaoTableDef::Close
- AFXDAO/CDaoTableDef::Create
- AFXDAO/CDaoTableDef::CreateField
- AFXDAO/CDaoTableDef::CreateIndex
- AFXDAO/CDaoTableDef::DeleteField
- AFXDAO/CDaoTableDef::DeleteIndex
- AFXDAO/CDaoTableDef::GetAttributes
- AFXDAO/CDaoTableDef::GetConnect
- AFXDAO/CDaoTableDef::GetDateCreated
- AFXDAO/CDaoTableDef::GetDateLastUpdated
- AFXDAO/CDaoTableDef::GetFieldCount
- AFXDAO/CDaoTableDef::GetFieldInfo
- AFXDAO/CDaoTableDef::GetIndexCount
- AFXDAO/CDaoTableDef::GetIndexInfo
- AFXDAO/CDaoTableDef::GetName
- AFXDAO/CDaoTableDef::GetRecordCount
- AFXDAO/CDaoTableDef::GetSourceTableName
- AFXDAO/CDaoTableDef::GetValidationRule
- AFXDAO/CDaoTableDef::GetValidationText
- AFXDAO/CDaoTableDef::IsOpen
- AFXDAO/CDaoTableDef::Open
- AFXDAO/CDaoTableDef::RefreshLink
- AFXDAO/CDaoTableDef::SetAttributes
- AFXDAO/CDaoTableDef::SetConnect
- AFXDAO/CDaoTableDef::SetName
- AFXDAO/CDaoTableDef::SetSourceTableName
- AFXDAO/CDaoTableDef::SetValidationRule
- AFXDAO/CDaoTableDef::SetValidationText
- AFXDAO/CDaoTableDef::m_pDAOTableDef
- AFXDAO/CDaoTableDef::m_pDatabase
helpviewer_keywords:
- CDaoTableDef [MFC], CDaoTableDef
- CDaoTableDef [MFC], Append
- CDaoTableDef [MFC], CanUpdate
- CDaoTableDef [MFC], Close
- CDaoTableDef [MFC], Create
- CDaoTableDef [MFC], CreateField
- CDaoTableDef [MFC], CreateIndex
- CDaoTableDef [MFC], DeleteField
- CDaoTableDef [MFC], DeleteIndex
- CDaoTableDef [MFC], GetAttributes
- CDaoTableDef [MFC], GetConnect
- CDaoTableDef [MFC], GetDateCreated
- CDaoTableDef [MFC], GetDateLastUpdated
- CDaoTableDef [MFC], GetFieldCount
- CDaoTableDef [MFC], GetFieldInfo
- CDaoTableDef [MFC], GetIndexCount
- CDaoTableDef [MFC], GetIndexInfo
- CDaoTableDef [MFC], GetName
- CDaoTableDef [MFC], GetRecordCount
- CDaoTableDef [MFC], GetSourceTableName
- CDaoTableDef [MFC], GetValidationRule
- CDaoTableDef [MFC], GetValidationText
- CDaoTableDef [MFC], IsOpen
- CDaoTableDef [MFC], Open
- CDaoTableDef [MFC], RefreshLink
- CDaoTableDef [MFC], SetAttributes
- CDaoTableDef [MFC], SetConnect
- CDaoTableDef [MFC], SetName
- CDaoTableDef [MFC], SetSourceTableName
- CDaoTableDef [MFC], SetValidationRule
- CDaoTableDef [MFC], SetValidationText
- CDaoTableDef [MFC], m_pDAOTableDef
- CDaoTableDef [MFC], m_pDatabase
ms.assetid: 7c5d2254-8475-43c4-8a6c-2d32ead194c9
ms.openlocfilehash: 485fe3533916e5e59bc87084f58acfb37368ac32
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883857"
---
# <a name="cdaotabledef-class"></a>Classe CDaoTableDef

Representa a definição armazenada de uma tabela base ou de uma tabela anexada.

## <a name="syntax"></a>Sintaxe

```
class CDaoTableDef : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoTableDef::CDaoTableDef](#cdaotabledef)|Constrói um objeto `CDaoTableDef`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoTableDef:: Append](#append)|Adiciona uma nova tabela ao banco de dados.|
|[CDaoTableDef:: CanUpdate](#canupdate)|Retornará zero se a tabela puder ser atualizada (você pode modificar a definição de campos ou as propriedades da tabela).|
|[CDaoTableDef:: fechar](#close)|Fecha um TableDef aberto.|
|[CDaoTableDef:: criar](#create)|Cria uma tabela que pode ser adicionada ao banco de dados usando [Append](#append).|
|[CDaoTableDef::](#createfield)|Chamado para criar um campo para uma tabela.|
|[CDaoTableDef::CreateIndex](#createindex)|Chamado para criar um índice para uma tabela.|
|[CDaoTableDef::D eleteField](#deletefield)|Chamado para excluir um campo de uma tabela.|
|[CDaoTableDef::D eleteIndex](#deleteindex)|Chamado para excluir um índice de uma tabela.|
|[CDaoTableDef:: GetAttributes](#getattributes)|Retorna um valor que indica uma ou mais características de um objeto `CDaoTableDef`.|
|[CDaoTableDef:: GetConnect](#getconnect)|Retorna um valor que fornece informações sobre a origem de uma tabela.|
|[CDaoTableDef::GetDateCreated](#getdatecreated)|Retorna a data e a hora em que a tabela base subjacente a um objeto de `CDaoTableDef` foi criada.|
|[CDaoTableDef::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e a hora da alteração mais recente feita no design da tabela base.|
|[CDaoTableDef::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos na tabela.|
|[CDaoTableDef:: GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos na tabela.|
|[CDaoTableDef::GetIndexCount](#getindexcount)|Retorna o número de índices para a tabela.|
|[CDaoTableDef::GetIndexInfo](#getindexinfo)|Retorna tipos específicos de informações sobre os índices da tabela.|
|[CDaoTableDef:: GetName](#getname)|Retorna o nome definido pelo usuário da tabela.|
|[CDaoTableDef::GetRecordCount](#getrecordcount)|Retorna o número de registros na tabela.|
|[CDaoTableDef::GetSourceTableName](#getsourcetablename)|Retorna um valor que especifica o nome da tabela anexada no banco de dados de origem.|
|[CDaoTableDef:: getregradevalidação](#getvalidationrule)|Retorna um valor que valida os dados em um campo à medida que eles são alterados ou adicionados a uma tabela.|
|[CDaoTableDef::GetValidationText](#getvalidationtext)|Retorna um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto Field não atender à regra de validação especificada.|
|[CDaoTableDef:: IsOpen](#isopen)|Retornará zero se a tabela estiver aberta.|
|[CDaoTableDef:: abrir](#open)|Abre um TableDef existente armazenado na coleção TableDef's do banco de dados.|
|[CDaoTableDef::RefreshLink](#refreshlink)|Atualiza as informações de conexão de uma tabela anexada.|
|[CDaoTableDef:: SetAttributes](#setattributes)|Define um valor que indica uma ou mais características de um objeto `CDaoTableDef`.|
|[CDaoTableDef:: SetConnect](#setconnect)|Define um valor que fornece informações sobre a origem de uma tabela.|
|[CDaoTableDef:: SetName](#setname)|Define o nome da tabela.|
|[CDaoTableDef::SetSourceTableName](#setsourcetablename)|Define um valor que especifica o nome de uma tabela anexada no banco de dados de origem.|
|[CDaoTableDef:: setregradevalidação](#setvalidationrule)|Define um valor que valida os dados em um campo à medida que eles são alterados ou adicionados a uma tabela.|
|[CDaoTableDef::SetValidationText](#setvalidationtext)|Define um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto Field não atender à regra de validação especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoTableDef:: m_pDAOTableDef](#m_pdaotabledef)|Um ponteiro para a interface DAO subjacente ao objeto tabledef.|
|[CDaoTableDef:: m_pDatabase](#m_pdatabase)|Banco de dados de origem desta tabela.|

## <a name="remarks"></a>Comentários

Cada objeto de banco de dados DAO mantém uma coleção, chamada TableDefs, que contém todos os objetos de TableDef do DAO salvos.

Você manipula uma definição de tabela usando um objeto `CDaoTableDef`. Por exemplo, você pode:

- Examine a estrutura de campo e índice de qualquer tabela local, anexada ou externa em um banco de dados.

- Chame as funções de membro `SetConnect` e `SetSourceTableName` para tabelas anexadas e use a função de membro `RefreshLink` para atualizar conexões com tabelas anexadas.

- Chame a função de membro `CanUpdate` para determinar se você pode editar definições de campo na tabela.

- Obter ou definir condições de validação usando o `GetValidationRule` e `SetValidationRule`e as funções de membro `GetValidationText` e `SetValidationText`.

- Use a função membro `Open` para criar um objeto de `CDaoRecordset` de tabela, dynaset ou tipo de instantâneo.

    > [!NOTE]
    >  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque são específicas do mecanismo de banco de dados do Microsoft Jet.

### <a name="to-use-tabledef-objects-either-to-work-with-an-existing-table-or-to-create-a-new-table"></a>Para usar objetos TableDef para trabalhar com uma tabela existente ou para criar uma nova tabela

1. Em todos os casos, primeiro Construa um objeto `CDaoTableDef`, fornecendo um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ao qual a tabela pertence.

1. Em seguida, faça o seguinte, dependendo do que você deseja:

   - Para usar uma tabela salva existente, chame a função de membro [Open](#open) do objeto tabledef, fornecendo o nome da tabela salva.

   - Para criar uma nova tabela, chame a função de membro [Create](#create) do objeto tabledef, fornecendo o nome da tabela. Chame [criarfield](#createfield) e [CreateIndex](#createindex) para adicionar campos e índices à tabela.

   - Chame [Append](#append) para salvar a tabela anexando-a à coleção TableDefs do banco de dados. `Create` coloca o TableDef em um estado aberto, portanto, depois de chamar `Create` você não chama `Open`.

        > [!TIP]
        >  A maneira mais fácil de criar tabelas salvas é criá-las e armazená-las em seu banco de dados usando o Microsoft Access. Em seguida, você pode abri-los e usá-los em seu código MFC.

Para usar o objeto tabledef que você abriu ou criou, crie e abra um objeto `CDaoRecordset`, especificando o nome do TableDef com um valor de `dbOpenTable` no parâmetro *nOpenType* .

Para usar um objeto tabledef para criar um objeto de `CDaoRecordset`, você normalmente cria ou abre um TableDef conforme descrito acima e, em seguida, constrói um objeto recordset, passando um ponteiro para o objeto tabledef quando você chama [CDaoRecordset:: Open](../../mfc/reference/cdaorecordset-class.md#open). O TableDef que você passa deve estar em um estado aberto. Para obter mais informações, consulte Class [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Quando você terminar de usar um objeto tabledef, chame sua função de membro [Close](../../mfc/reference/cdaorecordset-class.md#close) ; em seguida, destrua o objeto tabledef.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoTableDef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

##  <a name="append"></a>CDaoTableDef:: Append

Chame essa função de membro depois de chamar [Create](#create) para criar um novo objeto tabledef para salvar o TableDef no banco de dados.

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

A função anexa o objeto à coleção TableDefs do banco de dados. Você pode usar o TableDef como um objeto temporário ao defini-lo sem anexá-lo, mas se quiser salvá-lo e usá-lo, você deverá chamar `Append`.

> [!NOTE]
>  Se você tentar acrescentar um TableDef sem nome (contendo uma cadeia de caracteres nula ou vazia), o MFC lançará uma exceção.

Para obter informações relacionadas, consulte o tópico "Método Append" na ajuda do DAO.

##  <a name="canupdate"></a>CDaoTableDef:: CanUpdate

Chame essa função de membro para determinar se a definição da tabela subjacente a um objeto de `CDaoTableDef` pode ser alterada.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a estrutura de tabela (esquema) puder ser modificada (adicionar ou excluir campos e índices), caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, uma tabela recém-criada subjacente a um objeto `CDaoTableDef` pode ser atualizada e uma tabela anexada subjacente a um objeto `CDaoTableDef` não pode ser atualizada. Um objeto `CDaoTableDef` pode ser atualizável, mesmo que o conjunto de registros resultante não seja atualizável.

Para obter informações relacionadas, consulte o tópico "Propriedade atualizável" na ajuda do DAO.

##  <a name="cdaotabledef"></a>CDaoTableDef::CDaoTableDef

Constrói um objeto `CDaoTableDef`.

```
CDaoTableDef(CDaoDatabase* pDatabase);
```

### <a name="parameters"></a>Parâmetros

*pDatabase*<br/>
Um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) .

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar a função de membro [Create](#create) ou [Open](#open) . Quando terminar com o objeto, você deverá chamar sua função de membro de [fechamento](#close) e destruir o objeto de `CDaoTableDef`.

##  <a name="close"></a>CDaoTableDef:: fechar

Chame essa função de membro para fechar e liberar o objeto tabledef.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Normalmente, depois de chamar `Close`, você exclui o objeto tabledef se ele foi alocado com **New**.

Você pode chamar [Open](#open) novamente depois de chamar `Close`. Isso permite que você reutilize o objeto tabledef.

Para obter informações relacionadas, consulte o tópico "Close Method" na ajuda do DAO.

##  <a name="create"></a>CDaoTableDef:: criar

Chame essa função de membro para criar uma nova tabela salva.

```
virtual void Create(
    LPCTSTR lpszName,
    long lAttributes = 0,
    LPCTSTR lpszSrcTable = NULL,
    LPCTSTR lpszConnect = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome da tabela.

*lAttributes*<br/>
Um valor correspondente às características da tabela representada pelo objeto tabledef. Você pode usar o bit-a-ou para combinar qualquer uma das seguintes constantes:

|Constante|DESCRIÇÃO|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a ID de usuário e a senha da tabela anexada são salvas com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados do Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados do Microsoft Jet.|

*lpszSrcTable*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome da tabela de origem. Por padrão, esse valor é inicializado como nulo.

*lpszConnect*<br/>
Um ponteiro para uma cadeia de caracteres que contém a cadeia de conexão padrão. Por padrão, esse valor é inicializado como nulo.

### <a name="remarks"></a>Comentários

Depois de ter nomeado o TableDef, você pode chamar [Append](#append) para salvar o TableDef na coleção TableDefs do banco de dados. Depois de chamar `Append`, o TableDef está em um estado aberto e você pode usá-lo para criar um objeto [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) .

Para obter informações relacionadas, consulte o tópico "método CreateTableDef" na ajuda do DAO.

##  <a name="createfield"></a>CDaoTableDef::

Chame essa função de membro para adicionar um campo à tabela.

```
void CreateField(
    LPCTSTR lpszName,
    short nType,
    long lSize,
    long lAttributes = 0);

void CreateField(CDaoFieldInfo& fieldinfo);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de cadeia de caracteres especificando o nome desse campo.

*nType*<br/>
Um valor que indica o tipo de dados do campo. A configuração pode ser um destes valores:

|Tipo|Tamanho (bytes)|DESCRIÇÃO|
|----------|--------------------|-----------------|
|`dbBoolean`|1 byte|BOOL|
|`dbByte`|BYTE|
|`dbInteger`|2|int|
|`dbLong`|4|long|
|`dbCurrency`|8|Moeda ( [COleCurrency](../../mfc/reference/colecurrency-class.md))|
|`dbSingle`|4|float|
|`dbDouble`|8|double|
|`dbDate`|8|Data/hora ( [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md))|
|`dbText`|1 - 255|Texto ( [CString](../../atl-mfc-shared/reference/cstringt-class.md))|
|`dbLongBinary`|0|Binário longo (objeto OLE), [CLongBinary](../../mfc/reference/clongbinary-class.md) ou [CByteArray](../../mfc/reference/cbytearray-class.md)|
|`dbMemo`|0|Memorando ( [CString](../../atl-mfc-shared/reference/cstringt-class.md))|

*lSize*<br/>
Um valor que indica o tamanho máximo, em bytes, de um campo que contém texto ou o tamanho fixo de um campo que contém valores de texto ou numéricos. O parâmetro *lSize* é ignorado para todos os campos de texto, menos.

*lAttributes*<br/>
Um valor correspondente às características do campo e que pode ser combinado usando um bit-a-OR.

|Constante|DESCRIÇÃO|
|--------------|-----------------|
|`dbFixedField`|O tamanho do campo é fixo (padrão para campos numéricos).|
|`dbVariableField`|O tamanho do campo é variável (somente campos de texto).|
|`dbAutoIncrField`|O valor do campo para novos registros é incrementado automaticamente para um inteiro longo e exclusivo que não pode ser alterado. Com suporte apenas para tabelas de banco de dados Microsoft Jet.|
|`dbUpdatableField`|O valor do campo pode ser alterado.|
|`dbDescending`|O campo é classificado em ordem decrescente (Z-A ou 100-0) (aplica-se somente a um objeto Field em uma coleção Fields de um objeto index). Se você omitir essa constante, o campo será classificado em ordem crescente (A-Z ou 0-100) (padrão).|

*FieldInfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) .

### <a name="remarks"></a>Comentários

Um objeto `DAOField` (OLE) é criado e anexado à coleção Fields do objeto `DAOTableDef` (OLE). Além de seu uso para examinar as propriedades do objeto, você também pode usar `CDaoFieldInfo` para construir um parâmetro de entrada para criar novos campos em um TableDef. A primeira versão do `CreateField` é mais simples de usar, mas se você quiser um controle mais preciso, poderá usar a segunda versão do `CreateField`, que usa um parâmetro `CDaoFieldInfo`.

Se você usar a versão do `CreateField` que usa um parâmetro `CDaoFieldInfo`, deverá definir cuidadosamente cada um dos seguintes membros da estrutura `CDaoFieldInfo`:

- `m_strName`

- `m_nType`

- `m_lSize`

- `m_lAttributes`

- `m_bAllowZeroLength`

Os membros restantes de `CDaoFieldInfo` devem ser definidos como **0**, falso ou uma cadeia de caracteres vazia, conforme apropriado para o membro, ou um `CDaoException` pode ocorrer.

Para obter informações relacionadas, consulte o tópico "criar método" na ajuda do DAO.

##  <a name="createindex"></a>CDaoTableDef::CreateIndex

Chame essa função para adicionar um índice a uma tabela.

```
void CreateIndex(CDaoIndexInfo& indexinfo);
```

### <a name="parameters"></a>Parâmetros

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) .

### <a name="remarks"></a>Comentários

Os índices especificam a ordem dos registros acessados de tabelas de banco de dados e se os registros duplicados são aceitos ou não. Os índices também fornecem acesso eficiente aos dados.

Você não precisa criar índices para tabelas, mas em tabelas grandes, não indexadas, acessar um registro específico ou criar um conjunto de registros pode levar muito tempo. Por outro lado, a criação de muitos índices reduz a velocidade das operações de atualização, acréscimo e exclusão, pois todos os índices são atualizados automaticamente. Considere esses fatores ao decidir quais índices criar.

Os seguintes membros da estrutura de `CDaoIndexInfo` devem ser definidos:

- `m_strName` é necessário fornecer um nome.

- `m_pFieldInfos` deve apontar para uma matriz de estruturas de `CDaoIndexFieldInfo`.

- `m_nFields` deve especificar o número de campos na matriz de estruturas de `CDaoFieldInfo`.

Os membros restantes serão ignorados se forem definidos como FALSE. Além disso, o membro `m_lDistinctCount` é ignorado durante a criação do índice.

##  <a name="deletefield"></a>CDaoTableDef::D eleteField

Chame essa função de membro para remover um campo e torná-lo inacessível.

```
void DeleteField(LPCTSTR lpszName);
void DeleteField(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que é o nome de um campo existente.

*nIndex*<br/>
O índice do campo na coleção de campos com base em zero da tabela, para pesquisa por índice.

### <a name="remarks"></a>Comentários

Você pode usar essa função de membro em um novo objeto que não foi anexado ao banco de dados ou quando [CanUpdate](#canupdate) retorna zero.

Para obter informações relacionadas, consulte o tópico "Excluir método" na ajuda do DAO.

##  <a name="deleteindex"></a>CDaoTableDef::D eleteIndex

Chame essa função de membro para excluir um índice em uma tabela subjacente.

```
void DeleteIndex(LPCTSTR lpszName);
void DeleteIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que é o nome de um índice existente.

*nIndex*<br/>
O índice de matriz do objeto de índice na coleção de TableDefs com base em zero do banco de dados, para pesquisa por índice.

### <a name="remarks"></a>Comentários

Você pode usar essa função de membro em um novo objeto que não foi anexado ao banco de dados ou quando [CanUpdate](#canupdate) retorna zero.

Para obter informações relacionadas, consulte o tópico "Excluir método" na ajuda do DAO.

##  <a name="getattributes"></a>CDaoTableDef:: GetAttributes

Para um objeto `CDaoTableDef`, o valor de retorno especifica as características da tabela representada pelo objeto `CDaoTableDef` e pode ser uma soma dessas constantes:

```
long GetAttributes();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que indica uma ou mais características de um objeto `CDaoTableDef`.

### <a name="remarks"></a>Comentários

|Constante|DESCRIÇÃO|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a ID de usuário e a senha da tabela anexada são salvas com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados do Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados do Microsoft Jet.|
|`dbAttachedTable`|Indica que a tabela é uma tabela anexada de um banco de dados não ODBC, como um banco de dados do Paradox.|
|`dbAttachedODBC`|Indica que a tabela é uma tabela anexada de um banco de dados ODBC, como Microsoft SQL Server.|

Uma tabela do sistema é uma tabela criada pelo mecanismo de banco de dados do Microsoft Jet para conter várias informações internas.

Uma tabela oculta é uma tabela criada para uso temporário pelo mecanismo de banco de dados do Microsoft Jet.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getconnect"></a>CDaoTableDef:: GetConnect

Chame essa função de membro para obter a cadeia de conexão para uma fonte de dados.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que contém o caminho e o tipo de banco de dados para a tabela.

### <a name="remarks"></a>Comentários

Para um objeto `CDaoTableDef` que representa uma tabela anexada, o objeto `CString` consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).

O caminho, conforme mostrado na tabela abaixo, é o caminho completo para o diretório que contém os arquivos de banco de dados e deve ser precedido pelo identificador "DATABASE =". Em alguns casos (assim como acontece com os bancos de dados do Microsoft Jet e do Microsoft Excel), um nome de arquivo específico é incluído no argumento Database Path.

A tabela em [CDaoTableDef:: SetConnect](#setconnect) mostra os tipos de banco de dados possíveis e seus caminhos e especificadores de banco de dados correspondentes:

Para tabelas base do banco de dados Microsoft Jet, o especificador é uma cadeia de caracteres vazia ("").

Se uma senha for necessária, mas não for fornecida, o driver ODBC exibirá uma caixa de diálogo de logon na primeira vez que uma tabela for acessada e novamente se a conexão for fechada e reaberta. Se uma tabela anexada tiver o atributo `dbAttachSavePWD`, o prompt de logon não será exibido quando a tabela for reaberta.

Para obter informações relacionadas, consulte o tópico "conectar Propriedade" na ajuda do DAO.

##  <a name="getdatecreated"></a>CDaoTableDef::GetDateCreated

Chame essa função para determinar a data e a hora em que a tabela subjacente ao objeto de `CDaoTableDef` foi criada.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um valor que contém a data e a hora da criação da tabela subjacente ao objeto `CDaoTableDef`.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizada pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de tempo "padrão", talvez de um servidor.

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

##  <a name="getdatelastupdated"></a>CDaoTableDef::GetDateLastUpdated

Chame essa função para determinar a data e a hora em que a tabela subjacente ao objeto de `CDaoTableDef` foi atualizada pela última vez.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um valor que contém a data e a hora em que a tabela subjacente ao objeto de `CDaoTableDef` foi atualizada pela última vez.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizada pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de tempo "padrão", talvez de um servidor.

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

##  <a name="getfieldcount"></a>CDaoTableDef::GetFieldCount

Chame essa função de membro para recuperar o número de campos definidos na tabela.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos na tabela.

### <a name="remarks"></a>Comentários

Se seu valor for 0, não haverá nenhum objeto na coleção.

Para obter informações relacionadas, consulte o tópico "propriedade de contagem" na ajuda do DAO.

##  <a name="getfieldinfo"></a>CDaoTableDef:: GetFieldInfo

Chame essa função de membro para obter vários tipos de informações sobre um campo definido no TableDef.

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
O índice do objeto de campo na coleção de campos com base em zero da tabela, para pesquisa por índice.

*FieldInfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) .

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o campo a recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne:

- `AFX_DAO_PRIMARY_INFO` (padrão) nome, tipo, tamanho, atributos. Use essa opção para um desempenho mais rápido.

- `AFX_DAO_SECONDARY_INFO` informações primárias, mais: posição ordinal, obrigatório, permitir comprimento zero, ordem de agrupamento, nome estrangeiro, campo de origem, tabela de origem

- `AFX_DAO_ALL_INFO` informações primárias e secundárias, além: regra de validação, texto de validação, valor padrão

*lpszName*<br/>
Um ponteiro para o nome do objeto de campo, para pesquisa por nome. O nome é uma cadeia de caracteres com até 64 caracteres que nomeia exclusivamente o campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você pesquise um campo por índice. A outra versão permite pesquisar um campo por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você obtém informações para todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getindexcount"></a>CDaoTableDef::GetIndexCount

Chame essa função de membro para obter o número de índices de uma tabela.

```
short GetIndexCount();
```

### <a name="return-value"></a>Valor retornado

O número de índices para a tabela.

### <a name="remarks"></a>Comentários

Se seu valor for 0, não haverá nenhum índice na coleção.

Para obter informações relacionadas, consulte o tópico "propriedade de contagem" na ajuda do DAO.

##  <a name="getindexinfo"></a>CDaoTableDef::GetIndexInfo

Chame essa função de membro para obter vários tipos de informações sobre um índice definido no TableDef.

```
void GetIndexInfo(
    int nIndex,
    CDaoIndexInfo& indexinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);

void GetIndexInfo(
    LPCTSTR lpszName,
    CDaoIndexInfo& indexinfo,
    DWORD dwInfoOptions = AFX_DAO_PRIMARY_INFO);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice numérico do objeto de índice na coleção de índices com base em zero da tabela, para pesquisa por sua posição na coleção.

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) .

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o índice recuperar. As opções disponíveis são listadas aqui junto com o que fazem com que a função retorne:

- Nome do `AFX_DAO_PRIMARY_INFO`, informações do campo, campos. Use essa opção para um desempenho mais rápido.

- `AFX_DAO_SECONDARY_INFO` informações primárias, além de: primária, exclusiva, clusterizado, ignorar nulos, obrigatório, estrangeiro

- `AFX_DAO_ALL_INFO` informações primárias e secundárias, além: contagem distinta

*lpszName*<br/>
Um ponteiro para o nome do objeto de índice, para pesquisa por nome.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você obtém informações para todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getname"></a>CDaoTableDef:: GetName

Chame essa função de membro para obter o nome definido pelo usuário da tabela subjacente.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

Um nome definido pelo usuário para uma tabela.

### <a name="remarks"></a>Comentários

Esse nome começa com uma letra e pode conter no máximo 64 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

##  <a name="getrecordcount"></a>CDaoTableDef::GetRecordCount

Chame essa função de membro para descobrir quantos registros estão em um objeto de `CDaoTableDef`.

```
long GetRecordCount();
```

### <a name="return-value"></a>Valor retornado

O número de registros acessados em um objeto tabledef.

### <a name="remarks"></a>Comentários

A chamada de `GetRecordCount` para um objeto de `CDaoTableDef` de tipo de tabela reflete o número aproximado de registros na tabela e é afetada imediatamente à medida que os registros de tabela são adicionados e excluídos. As transações revertidas serão exibidas como parte da contagem de registros até que você chame [CDaoWorkspace:: CompactDatabase](../../mfc/reference/cdaoworkspace-class.md#compactdatabase). Um objeto `CDaoTableDef` sem registros tem uma configuração de propriedade contagem de registros 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retorna-1.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na ajuda do DAO.

##  <a name="getsourcetablename"></a>CDaoTableDef::GetSourceTableName

Chame essa função de membro para recuperar o nome de uma tabela anexada em um banco de dados de origem.

```
CString GetSourceTableName();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que especifica o nome de origem de uma tabela anexada ou uma cadeia de caracteres vazia se uma tabela de dados nativos.

### <a name="remarks"></a>Comentários

Uma tabela anexada é uma tabela em outro banco de dados vinculado a um banco de dados do Microsoft Jet. Os dados para tabelas anexadas permanecem no banco de dado externo, onde podem ser manipulados por outros aplicativos.

Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na ajuda do DAO.

##  <a name="getvalidationrule"></a>CDaoTableDef:: getregradevalidação

Chame essa função de membro para recuperar a regra de validação para um TableDef.

```
CString GetValidationRule();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que valida os dados em um campo à medida que eles são alterados ou adicionados a uma tabela.

### <a name="remarks"></a>Comentários

As regras de validação são usadas na conexão com as operações de atualização. Se um TableDef contiver uma regra de validação, as atualizações para esse TableDef deverão corresponder aos critérios predeterminados antes que os dados sejam alterados. Se a alteração não corresponder aos critérios, uma exceção contendo o valor de [GetValidationText](#getvalidationtext) será lançada. Para um objeto `CDaoTableDef`, esse `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.

Para obter informações relacionadas, consulte o tópico "Propriedade RegraDeValidação" na ajuda do DAO.

##  <a name="getvalidationtext"></a>CDaoTableDef::GetValidationText

Chame essa função para recuperar a cadeia de caracteres a ser exibida quando um usuário inserir dados que não correspondam à regra de validação.

```
CString GetValidationText();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que especifica o texto exibido se o usuário inserir dados que não correspondam à regra de validação.

### <a name="remarks"></a>Comentários

Para um objeto `CDaoTableDef`, esse `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.

Para obter informações relacionadas, consulte o tópico "Propriedade do TextoDeValidação" na ajuda do DAO.

##  <a name="isopen"></a>CDaoTableDef:: IsOpen

Chame essa função de membro para determinar se o objeto de `CDaoTableDef` está aberto no momento.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto de `CDaoTableDef` estiver aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="m_pdatabase"></a>CDaoTableDef:: m_pDatabase

Contém um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) para esta tabela.

### <a name="remarks"></a>Comentários

##  <a name="m_pdaotabledef"></a>CDaoTableDef:: m_pDAOTableDef

Contém um ponteiro para a interface OLE do objeto tabledef do DAO subjacente ao objeto `CDaoTableDef`.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar a interface DAO diretamente.

##  <a name="open"></a>CDaoTableDef:: abrir

Chame essa função de membro para abrir um TableDef salvo anteriormente na coleção TableDef's do banco de dados.

```
virtual void Open(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que especifica um nome de tabela.

### <a name="remarks"></a>Comentários

##  <a name="refreshlink"></a>CDaoTableDef::RefreshLink

Chame essa função de membro para atualizar as informações de conexão de uma tabela anexada.

```
void RefreshLink();
```

### <a name="remarks"></a>Comentários

Você altera as informações de conexão de uma tabela anexa chamando [SetConnect](#setconnect) no objeto de `CDaoTableDef` correspondente e, em seguida, usando a função de membro `RefreshLink` para atualizar as informações. Quando você chama `RefreshLink`, as propriedades da tabela anexada não são alteradas.

Para forçar as informações de conexão modificadas a entrarem em vigor, todos os objetos [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) abertos com base nesse TableDef devem ser fechados.

Para obter informações relacionadas, consulte o tópico "método RefreshLink" na ajuda do DAO.

##  <a name="setattributes"></a>CDaoTableDef:: SetAttributes

Define um valor que indica uma ou mais características de um objeto `CDaoTableDef`.

```
void SetAttributes(long lAttributes);
```

### <a name="parameters"></a>Parâmetros

*lAttributes*<br/>
Características da tabela representada pelo objeto `CDaoTableDef` e podem ser uma soma dessas constantes:

|Constante|DESCRIÇÃO|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados do Microsoft Jet, indica que a ID de usuário e a senha da tabela anexada são salvas com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados do Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados do Microsoft Jet.|

### <a name="remarks"></a>Comentários

Ao definir vários atributos, você pode combiná-los somando as constantes apropriadas usando o operador OR A configuração `dbAttachExclusive` em uma tabela não anexada produz uma exceção. A combinação dos seguintes valores também produz uma exceção:

- **dbAttachExclusive &#124; dbAttachedODBC**

- **dbAttachSavePWD &#124; dbAttachedTable**

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="setconnect"></a>CDaoTableDef:: SetConnect

Para um objeto `CDaoTableDef` que representa uma tabela anexada, o objeto String consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).

```
void SetConnect(LPCTSTR lpszConnect);
```

### <a name="parameters"></a>Parâmetros

*lpszConnect*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que especifica parâmetros adicionais a serem passados para drivers ISAM instaláveis ou ODBC.

### <a name="remarks"></a>Comentários

O caminho, conforme mostrado na tabela abaixo, é o caminho completo para o diretório que contém os arquivos de banco de dados e deve ser precedido pelo identificador "DATABASE =". Em alguns casos (assim como acontece com os bancos de dados do Microsoft Jet e do Microsoft Excel), um nome de arquivo específico é incluído no argumento Database Path.

> [!NOTE]
>  Não inclua espaço em branco em relação às instruções de caminho de sinal de igual no formato "DATABASE = Drive:\\\path". Isso fará com que uma exceção seja gerada e a conexão falhe.

A tabela a seguir mostra os tipos de banco de dados possíveis e seus caminhos e especificadores de banco de dados correspondentes:

|Tipo de banco de dados|Especificador|Caminho|
|-------------------|---------------|----------|
|Banco de dados usando o mecanismo de banco de dados Jet|"[`database`];"|"`drive`:\\\ *caminho*\\\ *nome do arquivo*. MDB|
|dBASE III|"dBASE III;"|"`drive`:\\*caminho*de \ "|
|dBASE IV|"dBASE IV;"|"`drive`:\\*caminho*de \ "|
|dBASE 5|"dBASE 5.0;"|"`drive`:\\*caminho*de \ "|
|Paradox 3. x|"Paradox 3.x;"|"`drive`:\\*caminho*de \ "|
|Paradox 4. x|"Paradox 4.x;"|"`drive`:\\*caminho*de \ "|
|Paradox 5.x|"Paradox 5.x;"|"`drive`:\\*caminho*de \ "|
|Excel 3,0|"Excel 3,0;"|"`drive`:\\\ *caminho*\\\ *nome do arquivo*. XLS|
|Excel 4,0|"Excel 4,0;"|"`drive`:\\\ *caminho*\\\ *nome do arquivo*. XLS|
|Excel 5,0 ou Excel 95|"Excel 5,0;"|"`drive`:\\\ *caminho*\\\ *nome do arquivo*. XLS|
|Excel 97|"Excel 8,0;"|"`drive`:\\*caminho* do \ \ *nome do arquivo*. XLS|
|Importação de HTML|"Importação de HTML;"|"`drive`:\\*caminho* do \ \ *nome do arquivo*"|
|Exportação de HTML|"Exportação de HTML;"|"`drive`:\\*caminho*de \ "|
|Texto|"Texto;"|"unidade:\\\path"|
|ODBC|Class BANCO de dados = `database`; UID = *usuário*; PWD = *senha*; DSN = *DataSourceName;* LOGINTIMEOUT = *segundos;* " (Essa não pode ser uma cadeia de conexão completa para todos os servidores; é apenas um exemplo. É muito importante não ter espaços entre os parâmetros.)|Nenhum|
|Exchange|Transferência<br /><br /> MAPILEVEL = *FolderPath*;<br /><br /> [TABLETYPE={ 0 &#124; 1 };]<br /><br /> [Perfil = *perfil*;]<br /><br /> [PWD = *senha*;]<br /><br /> [DATABASE = `database`;] "|*"drive*:\\\ *caminho*\\\ *nome do arquivo*. MDB|

> [!NOTE]
>  O Btrieve não tem mais suporte a partir do DAO 3,5.

Você deve usar uma barra invertida dupla (\\\\) nas cadeias de conexão. Se você tiver modificado as propriedades de uma conexão existente usando `SetConnect`, deverá chamar o [RefreshLink](#refreshlink)posteriormente. Se você estiver inicializando as propriedades de conexão usando `SetConnect`, não precisará chamar `RefreshLink`, mas deverá optar por fazer isso, primeiro anexe o TableDef.

Se uma senha for necessária, mas não for fornecida, o driver ODBC exibirá uma caixa de diálogo de logon na primeira vez que uma tabela for acessada e novamente se a conexão for fechada e reaberta.

Você pode definir a cadeia de conexão para um objeto `CDaoTableDef` fornecendo um argumento de origem para a função de membro `Create`. Você pode verificar a configuração para determinar o tipo, o caminho, a ID de usuário, a senha ou a fonte de dados ODBC do banco de dado. Para obter mais informações, consulte a documentação do driver específico.

Para obter informações relacionadas, consulte o tópico "conectar Propriedade" na ajuda do DAO.

##  <a name="setname"></a>CDaoTableDef:: SetName

Chame essa função de membro para definir um nome definido pelo usuário para uma tabela.

```
void SetName(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que especifica um nome para uma tabela.

### <a name="remarks"></a>Comentários

O nome deve começar com uma letra e pode conter no máximo 64 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

##  <a name="setsourcetablename"></a>CDaoTableDef::SetSourceTableName

Chame essa função de membro para especificar o nome de uma tabela anexada ou o nome da tabela base na qual o objeto de `CDaoTableDef` é baseado, como ele existe na fonte original dos dados.

```
void SetSourceTableName(LPCTSTR lpszSrcTableName);
```

### <a name="parameters"></a>Parâmetros

*lpszSrcTableName*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que especifica um nome de tabela no banco de dados externo. Para uma tabela base, a configuração é uma cadeia de caracteres vazia ("").

### <a name="remarks"></a>Comentários

Em seguida, você deve chamar [RefreshLink](#refreshlink). Essa configuração de propriedade está vazia para uma tabela base e leitura/gravação para uma tabela anexada ou um objeto não acrescentado a uma coleção.

Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na ajuda do DAO.

##  <a name="setvalidationrule"></a>CDaoTableDef:: setregradevalidação

Chame essa função de membro para definir uma regra de validação para um TableDef.

```
void SetValidationRule(LPCTSTR lpszValidationRule);
```

### <a name="parameters"></a>Parâmetros

*lpszValidationRule*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que valida uma operação.

### <a name="remarks"></a>Comentários

As regras de validação são usadas na conexão com as operações de atualização. Se um TableDef contiver uma regra de validação, as atualizações para esse TableDef deverão corresponder aos critérios predeterminados antes que os dados sejam alterados. Se a alteração não corresponder aos critérios, uma exceção contendo o texto de [GetValidationText](#getvalidationtext) será exibida.

A validação tem suporte apenas para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet. A expressão não pode se referir a funções definidas pelo usuário, funções de agregação de domínio, funções de agregação SQL ou consultas. Uma regra de validação para um objeto de `CDaoTableDef` pode se referir a vários campos nesse objeto.

Por exemplo, para campos chamados *hire_date* e *termination_date*, uma regra de validação pode ser:

[!code-cpp[NVC_MFCDatabase#34](../../mfc/codesnippet/cpp/cdaotabledef-class_1.cpp)]

Para obter informações relacionadas, consulte o tópico "Propriedade RegraDeValidação" na ajuda do DAO.

##  <a name="setvalidationtext"></a>CDaoTableDef::SetValidationText

Chame essa função de membro para definir o texto de exceção de uma regra de validação para um objeto de `CDaoTableDef` com uma tabela base subjacente com suporte do mecanismo de banco de dados Microsoft Jet.

```
void SetValidationText(LPCTSTR lpszValidationText);
```

### <a name="parameters"></a>Parâmetros

*lpszValidationText*<br/>
Um ponteiro para uma expressão de cadeia de caracteres que especifica o texto exibido se os dados inseridos forem inválidos.

### <a name="remarks"></a>Comentários

Não é possível definir o texto de validação de uma tabela anexada.

Para obter informações relacionadas, consulte o tópico "Propriedade do TextoDeValidação" na ajuda do DAO.

## <a name="see-also"></a>Veja também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
