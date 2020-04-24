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
ms.openlocfilehash: adc31ccbf2be34aa1df1fa56111d1990701a6329
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754694"
---
# <a name="cdaotabledef-class"></a>Classe CDaoTableDef

Representa a definição armazenada de uma tabela base ou de uma tabela anexada.

## <a name="syntax"></a>Sintaxe

```
class CDaoTableDef : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoTableDef::CDaoTableDef](#cdaotabledef)|Constrói um objeto `CDaoTableDef`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoTableDef::Apêndice](#append)|Adiciona uma nova tabela ao banco de dados.|
|[CDaoTableDef::CanUpdate](#canupdate)|Retorna não zero se a tabela puder ser atualizada (você pode modificar a definição de campos ou propriedades da tabela).|
|[CDaoTableDef::Fechar](#close)|Fecha uma mesa aberta.|
|[CDaoTableDef::Criar](#create)|Cria uma tabela que pode ser adicionada ao banco de dados usando [o Apêndice](#append).|
|[CDaoTableDef::CreateField](#createfield)|Chamado para criar um campo para uma mesa.|
|[CDaoTableDef::CreateIndex](#createindex)|Chamado para criar um índice para uma tabela.|
|[CDaoTableDef::DeleteField](#deletefield)|Chamado para excluir um campo de uma mesa.|
|[CDaoTableDef::DeleteIndex](#deleteindex)|Chamado para excluir um índice de uma tabela.|
|[CDaoTableDef::GetAttributes](#getattributes)|Retorna um valor que indica uma `CDaoTableDef` ou mais características de um objeto.|
|[CDaoTableDef::GetConnect](#getconnect)|Retorna um valor que fornece informações sobre a fonte de uma tabela.|
|[CDaoTableDef::GetDateCriado](#getdatecreated)|Retorna a data e a hora `CDaoTableDef` em que a tabela base subjacente a um objeto foi criada.|
|[CDaoTableDef::GetDateÚltima atualização](#getdatelastupdated)|Retorna a data e a hora da mudança mais recente feita ao design da tabela base.|
|[CDaoTableDef::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos na tabela.|
|[CDaoTableDef::GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos na tabela.|
|[CDaoTableDef::GetIndexCount](#getindexcount)|Retorna o número de índices para a tabela.|
|[CDaoTableDef::GetIndexInfo](#getindexinfo)|Retorna tipos específicos de informações sobre os índices da tabela.|
|[CDaoTableDef::GetName](#getname)|Retorna o nome definido pelo usuário da tabela.|
|[CDaoTableDef::GetRecordCount](#getrecordcount)|Retorna o número de registros na tabela.|
|[CDaoTableDef::GetSourceTableName](#getsourcetablename)|Retorna um valor que especifica o nome da tabela anexada no banco de dados de origem.|
|[CDaoTableDef::GetValidationRule](#getvalidationrule)|Retorna um valor que valida os dados em um campo à medida que são alterados ou adicionados a uma tabela.|
|[CDaoTableDef::GetValidationText](#getvalidationtext)|Retorna um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto de campo não satisfazer a regra de validação especificada.|
|[CDaoTableDef::IsOpen](#isopen)|Retorna não zero se a mesa estiver aberta.|
|[CDaoTableDef::Aberto](#open)|Abre um tabledef existente armazenado na coleção tableDef do banco de dados.|
|[CDaoTableDef::RefreshLink](#refreshlink)|Atualiza as informações de conexão para uma tabela anexada.|
|[CDaoTableDef::SetAttributes](#setattributes)|Define um valor que indica uma `CDaoTableDef` ou mais características de um objeto.|
|[CDaoTableDef::SetConnect](#setconnect)|Define um valor que fornece informações sobre a fonte de uma tabela.|
|[CDaoTableDef::SetName](#setname)|Define o nome da mesa.|
|[CDaoTableDef::SetSourceTableName](#setsourcetablename)|Define um valor que especifica o nome de uma tabela anexada no banco de dados de origem.|
|[CDaoTableDef::SetValidationRule](#setvalidationrule)|Define um valor que valida os dados em um campo à medida que são alterados ou adicionados a uma tabela.|
|[CDaoTableDef::SetValidationText](#setvalidationtext)|Define um valor que especifica o texto da mensagem que seu aplicativo exibe se o valor de um objeto de campo não satisfazer a regra de validação especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoTableDef::m_pDAOTableDef](#m_pdaotabledef)|Um ponteiro para a interface DAO subjacente ao objeto tabledef.|
|[CDaoTableDef::m_pDatabase](#m_pdatabase)|Banco de dados de origem para esta tabela.|

## <a name="remarks"></a>Comentários

Cada objeto de banco de dados DAO mantém uma coleção, chamada TableDefs, que contém todos os objetos databela DAO salvos.

Você manipula uma definição `CDaoTableDef` de tabela usando um objeto. Por exemplo, você pode:

- Examine a estrutura de campo e índice de qualquer tabela local, anexa da mesa externa ou local em um banco de dados.

- Ligue `SetConnect` para `SetSourceTableName` as funções e o membro `RefreshLink` para as tabelas anexadas e use a função membro para atualizar conexões em tabelas anexadas.

- Ligue `CanUpdate` para a função membro para determinar se você pode editar definições de campo na tabela.

- Obtenha ou defina condições `SetValidationRule`de `GetValidationText` validação `SetValidationText` usando as `GetValidationRule` funções e e e membro.

- Use `Open` a função membro para criar um `CDaoRecordset` objeto tipo tabela, dynaset ou snapshot.

    > [!NOTE]
    >  As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque são específicas do mecanismo de banco de dados Microsoft Jet.

### <a name="to-use-tabledef-objects-either-to-work-with-an-existing-table-or-to-create-a-new-table"></a>Para usar objetos tabledef, seja para trabalhar com uma tabela existente ou para criar uma nova tabela

1. Em todos os casos, primeiro construa um `CDaoTableDef` objeto, fornecendo um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ao qual a tabela pertence.

1. Em seguida, faça o seguinte, dependendo do que você quiser:

   - Para usar uma tabela salva existente, ligue para a função de membro [Aberto](#open) do objeto tabledef, fornecendo o nome da tabela salva.

   - Para criar uma nova tabela, chame a função [Criar](#create) membro do objeto tabledef, fornecendo o nome da tabela. Ligue [para CreateField](#createfield) e [CreateIndex](#createindex) para adicionar campos e índices à tabela.

   - Ligue para o [Append](#append) para salvar a tabela anexando-a à coleção TableDefs do banco de dados. `Create`coloca o tabledef em um estado `Create` aberto, então `Open`depois de chamá-lo não ligue .

        > [!TIP]
        >  A maneira mais fácil de criar tabelas salvas é criá-las e armazená-las em seu banco de dados usando o Microsoft Access. Então você pode abri-los e usá-los em seu código MFC.

Para usar o objeto tabledef você abriu ou `CDaoRecordset` criou, crie e abra um objeto, `dbOpenTable` especificando o nome do tabledef com um valor no parâmetro *nOpenType.*

Para usar um objeto tabledef para criar um `CDaoRecordset` objeto, você normalmente cria ou abre uma tabledef conforme descrito acima e, em seguida, constrói um objeto de conjunto de registros, passando um ponteiro para o objeto tabledef quando você chama [CDaoRecordset::Open](../../mfc/reference/cdaorecordset-class.md#open). A tabela que você passar deve estar em estado aberto. Para obter mais informações, consulte [classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Quando terminar de usar um objeto tabledef, chame sua função De membro [Próximo;](../../mfc/reference/cdaorecordset-class.md#close) em seguida, destruir o objeto tabledef.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDaoTableDef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaotabledefappend"></a><a name="append"></a>CDaoTableDef::Apêndice

Ligue para esta função de membro depois de chamar [Criar](#create) para criar um novo objeto tabledef para salvar o tabledef no banco de dados.

```
virtual void Append();
```

### <a name="remarks"></a>Comentários

A função anexa o objeto à coleção TableDefs do banco de dados. Você pode usar o tabledef como um objeto temporário ao defini-lo não anexando-o, `Append`mas se você quiser salvá-lo e usá-lo, você deve chamar .

> [!NOTE]
> Se você tentar anexar um tabledef sem nome (contendo uma seqüência de string nula ou vazia), o MFC lançará uma exceção.

Para obter informações relacionadas, consulte o tópico "Método de apêndice" no DAO Help.

## <a name="cdaotabledefcanupdate"></a><a name="canupdate"></a>CDaoTableDef::CanUpdate

Chame esta função de membro para determinar se `CDaoTableDef` a definição da tabela subjacente a um objeto pode ser alterada.

```
BOOL CanUpdate();
```

### <a name="return-value"></a>Valor retornado

Não zero se a estrutura da tabela (esquema) puder ser modificada (adicionar ou excluir campos e índices), caso contrário 0.

### <a name="remarks"></a>Comentários

Por padrão, uma tabela recém-criada subjacente a um `CDaoTableDef` objeto pode ser `CDaoTableDef` atualizada e uma tabela anexada subjacente a um objeto não pode ser atualizada. Um `CDaoTableDef` objeto pode ser updatable, mesmo que o conjunto de registros resultante não seja updatable.

Para obter informações relacionadas, consulte o tópico "Updatable Property" no DAO Help.

## <a name="cdaotabledefcdaotabledef"></a><a name="cdaotabledef"></a>CDaoTableDef::CDaoTableDef

Constrói um objeto `CDaoTableDef`.

```
CDaoTableDef(CDaoDatabase* pDatabase);
```

### <a name="parameters"></a>Parâmetros

*pBanco de dados*<br/>
Um ponteiro para um objeto [CDaoDatabase.](../../mfc/reference/cdaodatabase-class.md)

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar a função [Criar](#create) ou [Abrir](#open) membro. Quando você terminar com o objeto, você deve `CDaoTableDef` chamar sua função de membro [próximo](#close) e destruir o objeto.

## <a name="cdaotabledefclose"></a><a name="close"></a>CDaoTableDef::Fechar

Chame esta função de membro para fechar e liberar o objeto tabledef.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Normalmente, `Close`depois de ligar, você exclui o objeto tabledef se ele foi alocado com **novo**.

Você pode [Open](#open) ligar para `Close`Open novamente depois de ligar. Isso permite que você reutilize o objeto tabledef.

Para obter informações relacionadas, consulte o tópico "Close Method" no DAO Help.

## <a name="cdaotabledefcreate"></a><a name="create"></a>CDaoTableDef::Criar

Chame esta função de membro para criar uma nova tabela salva.

```
virtual void Create(
    LPCTSTR lpszName,
    long lAttributes = 0,
    LPCTSTR lpszSrcTable = NULL,
    LPCTSTR lpszConnect = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma seqüência contendo o nome da tabela.

*lAtributos*<br/>
Um valor correspondente às características da tabela representada pelo objeto tabledef. Você pode usar o bitwise-OR para combinar qualquer uma das seguintes constantes:

|Constante|Descrição|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexaaberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que o ID do usuário e a senha da tabela anexada são salvos com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela de sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados Microsoft Jet.|

*lpszSrcTable*<br/>
Um ponteiro para uma seqüência contendo o nome da tabela de origem. Por padrão, esse valor é inicializado como NULL.

*lpszConnect*<br/>
Um ponteiro para uma seqüência contendo a seqüência de conexão padrão. Por padrão, esse valor é inicializado como NULL.

### <a name="remarks"></a>Comentários

Depois de nomear o tabledef, você pode então chamar [o Append](#append) para salvar o tabledef na coleção TableDefs do banco de dados. Depois `Append`de ligar, o tabledef está em um estado aberto e você pode usá-lo para criar um objeto [CDaoRecordset.](../../mfc/reference/cdaorecordset-class.md)

Para obter informações relacionadas, consulte o tópico "CreateTableDef Method" no DAO Help.

## <a name="cdaotabledefcreatefield"></a><a name="createfield"></a>CDaoTableDef::CreateField

Chame esta função de membro para adicionar um campo à tabela.

```cpp
void CreateField(
    LPCTSTR lpszName,
    short nType,
    long lSize,
    long lAttributes = 0);

void CreateField(CDaoFieldInfo& fieldinfo);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de string especificando o nome deste campo.

*nType*<br/>
Um valor que indica o tipo de dados do campo. A configuração pode ser um desses valores:

|Type|Tamanho (bytes)|Descrição|
|----------|--------------------|-----------------|
|`dbBoolean`|1 byte|BOOL|
|`dbByte`|BYTE|
|`dbInteger`|2|INT|
|`dbLong`|4|long|
|`dbCurrency`|8|Moeda [(COleCurrency)](../../mfc/reference/colecurrency-class.md)|
|`dbSingle`|4|FLOAT|
|`dbDouble`|8|double|
|`dbDate`|8|Data/hora [(COleDateTime)](../../atl-mfc-shared/reference/coledatetime-class.md)|
|`dbText`|1 - 255|Texto [(CString)](../../atl-mfc-shared/reference/cstringt-class.md)|
|`dbLongBinary`|0|Binário longo (objeto OLE), [CLongBinary](../../mfc/reference/clongbinary-class.md) ou [CByteArray](../../mfc/reference/cbytearray-class.md)|
|`dbMemo`|0|Memorando [(CString)](../../atl-mfc-shared/reference/cstringt-class.md)|

*Lsize*<br/>
Um valor que indica o tamanho máximo, em bytes, de um campo que contém texto, ou o tamanho fixo de um campo que contém texto ou valores numéricos. O parâmetro *lSize* é ignorado para todos, exceto campos de texto.

*lAtributos*<br/>
Um valor correspondente às características do campo e que pode ser combinado usando um bitwise-OR.

|Constante|Descrição|
|--------------|-----------------|
|`dbFixedField`|O tamanho do campo é fixo (padrão para campos numéricos).|
|`dbVariableField`|O tamanho do campo é variável (somente campos de texto).|
|`dbAutoIncrField`|O valor de campo para novos registros é automaticamente incrementado a um inteiro longo único que não pode ser alterado. Apenas suportado para tabelas de banco de dados do Microsoft Jet.|
|`dbUpdatableField`|O valor do campo pode ser alterado.|
|`dbDescending`|O campo é classificado em ordem descendente (Z - A ou 100 - 0) (aplica-se apenas a um objeto de campo em uma coleção de Campos de um objeto Índice). Se você omitir esta constante, o campo é classificado em ordem ascendente (A - Z ou 0 - 100) (padrão).|

*Fieldinfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md)

### <a name="remarks"></a>Comentários

Um `DAOField` objeto (OLE) é criado e anexado `DAOTableDef` à coleção Campos do objeto (OLE). Além de seu uso para examinar propriedades `CDaoFieldInfo` de objetos, você também pode usar para construir um parâmetro de entrada para criar novos campos em uma tabledef. A primeira `CreateField` versão do é mais simples de usar, mas se você `CreateField`quiser um `CDaoFieldInfo` controle mais fino, você pode usar a segunda versão de , que leva um parâmetro.

Se você usar `CreateField` a versão `CDaoFieldInfo` de que leva um parâmetro, você deve `CDaoFieldInfo` definir cuidadosamente cada um dos seguintes membros da estrutura:

- `m_strName`

- `m_nType`

- `m_lSize`

- `m_lAttributes`

- `m_bAllowZeroLength`

Os membros `CDaoFieldInfo` restantes devem ser definidos como **0**, FALSE ou uma `CDaoException` seqüência de cordas vazia, conforme apropriado para o membro, ou pode ocorrer.

Para obter informações relacionadas, consulte o tópico "CreateField Method" no DAO Help.

## <a name="cdaotabledefcreateindex"></a><a name="createindex"></a>CDaoTableDef::CreateIndex

Chame esta função para adicionar um índice a uma tabela.

```cpp
void CreateIndex(CDaoIndexInfo& indexinfo);
```

### <a name="parameters"></a>Parâmetros

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo.](../../mfc/reference/cdaoindexinfo-structure.md)

### <a name="remarks"></a>Comentários

Os índices especificam a ordem dos registros acessados nas tabelas do banco de dados e se os registros duplicados são aceitos ou não. Os índices também proporcionam acesso eficiente aos dados.

Você não precisa criar índices para tabelas, mas em tabelas grandes e não indexadas, acessar um registro específico ou criar um conjunto de registros pode levar muito tempo. Por outro lado, criar muitos índices retarda a atualização, o apêndice e exclui as operações à medida que todos os índices são atualizados automaticamente. Considere esses fatores à medida que você decide quais índices criar.

Os seguintes `CDaoIndexInfo` membros da estrutura devem ser definidos:

- `m_strName`Um nome deve ser fornecido.

- `m_pFieldInfos`Deve apontar para `CDaoIndexFieldInfo` uma matriz de estruturas.

- `m_nFields`Deve especificar o número de `CDaoFieldInfo` campos na matriz de estruturas.

Os membros restantes serão ignorados se definidos como FALSO. Além disso, `m_lDistinctCount` o membro é ignorado durante a criação do índice.

## <a name="cdaotabledefdeletefield"></a><a name="deletefield"></a>CDaoTableDef::DeleteField

Chame esta função de membro para remover um campo e torná-lo inacessível.

```cpp
void DeleteField(LPCTSTR lpszName);
void DeleteField(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de string que é o nome de um campo existente.

*nIndex*<br/>
O índice do campo na coleção campos baseados em zero da tabela, para busca por índice.

### <a name="remarks"></a>Comentários

Você pode usar essa função de membro em um novo objeto que não foi anexado ao banco de dados ou quando o [CanUpdate](#canupdate) retorna não zero.

Para obter informações relacionadas, consulte o tópico "Método de exclusão" na Ajuda da DAO.

## <a name="cdaotabledefdeleteindex"></a><a name="deleteindex"></a>CDaoTableDef::DeleteIndex

Chame esta função de membro para excluir um índice em uma tabela subjacente.

```cpp
void DeleteIndex(LPCTSTR lpszName);
void DeleteIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de string que é o nome de um índice existente.

*nIndex*<br/>
O índice de matriz do objeto de índice na coleção TableDefs baseada em zero do banco de dados, para busca por índice.

### <a name="remarks"></a>Comentários

Você pode usar essa função de membro em um novo objeto que não foi anexado ao banco de dados ou quando o [CanUpdate](#canupdate) retorna não zero.

Para obter informações relacionadas, consulte o tópico "Método de exclusão" na Ajuda da DAO.

## <a name="cdaotabledefgetattributes"></a><a name="getattributes"></a>CDaoTableDef::GetAttributes

Para `CDaoTableDef` um objeto, o valor de retorno especifica `CDaoTableDef` características da tabela representada pelo objeto e pode ser uma soma dessas constantes:

```
long GetAttributes();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que indica uma `CDaoTableDef` ou mais características de um objeto.

### <a name="remarks"></a>Comentários

|Constante|Descrição|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexaaberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que o ID do usuário e a senha da tabela anexada são salvos com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela de sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados Microsoft Jet.|
|`dbAttachedTable`|Indica que a tabela é uma tabela anexada de um banco de dados não ODBC, como um banco de dados Paradox.|
|`dbAttachedODBC`|Indica que a tabela é uma tabela anexada de um banco de dados ODBC, como o Microsoft SQL Server.|

Uma tabela de sistema é uma tabela criada pelo mecanismo de banco de dados Microsoft Jet para conter várias informações internas.

Uma tabela oculta é uma tabela criada para uso temporário pelo mecanismo de banco de dados Microsoft Jet.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaotabledefgetconnect"></a><a name="getconnect"></a>CDaoTableDef::GetConnect

Ligue para esta função de membro para obter a seqüência de conexão de uma fonte de dados.

```
CString GetConnect();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto contendo o tipo de caminho e banco de dados para a tabela.

### <a name="remarks"></a>Comentários

Para `CDaoTableDef` um objeto que representa uma `CString` tabela anexada, o objeto consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).

O caminho mostrado na tabela abaixo é o caminho completo para o diretório que contém os arquivos do banco de dados e deve ser precedido pelo identificador "DATABASE=". Em alguns casos (como nos bancos de dados Microsoft Jet e Microsoft Excel), um nome de arquivo específico é incluído no argumento de caminho do banco de dados.

A tabela em [CDaoTableDef::SetConnect](#setconnect) mostra possíveis tipos de banco de dados e seus correspondentes especificadores e caminhos de banco de dados:

Para as tabelas base de banco de dados do Microsoft Jet, o especificador é uma seqüência de string vazia (").").

Se uma senha for necessária, mas não for fornecida, o driver ODBC exibirá uma caixa de diálogo de login na primeira vez que uma tabela for acessada e novamente se a conexão for fechada e reaberta. Se uma tabela anexada tiver o atributo, `dbAttachSavePWD` o prompt de login não aparecerá quando a tabela for reaberta.

Para obter informações relacionadas, consulte o tópico "Conectar propriedade" no DAO Help.

## <a name="cdaotabledefgetdatecreated"></a><a name="getdatecreated"></a>CDaoTableDef::GetDateCriado

Ligue para esta função para determinar a `CDaoTableDef` data e a hora em que a tabela subjacente ao objeto foi criada.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um valor contendo a data e a hora da `CDaoTableDef` criação da tabela subjacente ao objeto.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizada pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de tempo "padrão" — talvez a partir de um servidor.

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaotabledefgetdatelastupdated"></a><a name="getdatelastupdated"></a>CDaoTableDef::GetDateÚltima atualização

Ligue para esta função para determinar a `CDaoTableDef` data e a hora em que a tabela subjacente ao objeto foi atualizada pela última vez.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um valor que contém a data e `CDaoTableDef` a hora que a tabela subjacente ao objeto foi atualizada pela última vez.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizada pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de tempo "padrão" — talvez a partir de um servidor.

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaotabledefgetfieldcount"></a><a name="getfieldcount"></a>CDaoTableDef::GetFieldCount

Ligue para esta função de membro para recuperar o número de campos definidos na tabela.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos na tabela.

### <a name="remarks"></a>Comentários

Se seu valor for 0, não há objetos na coleção.

Para obter informações relacionadas, consulte o tópico "Count Property" no DAO Help.

## <a name="cdaotabledefgetfieldinfo"></a><a name="getfieldinfo"></a>CDaoTableDef::GetFieldInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um campo definido no tabledef.

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

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do objeto de campo na coleção Campos baseados em zero da tabela, para busca por índice.

*Fieldinfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md)

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o campo a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne:

- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome, Tipo, Tamanho, Atributos. Use esta opção para obter um desempenho mais rápido.

- `AFX_DAO_SECONDARY_INFO`Informações primárias, além de: Posição ordinal, necessária, permitir comprimento zero, ordem de cooperação, nome estrangeiro, campo de origem, tabela de origem

- `AFX_DAO_ALL_INFO`Informações primárias e secundárias, além de: Regra de validação, texto de validação, valor padrão

*lpszName*<br/>
Um ponteiro para o nome do objeto de campo, para procurar pelo nome. O nome é uma string com até 64 caracteres que nomeiam exclusivamente o campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um campo por índice. A outra versão permite que você procure um campo pelo nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você recebe informações para quaisquer níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaotabledefgetindexcount"></a><a name="getindexcount"></a>CDaoTableDef::GetIndexCount

Ligue para esta função de membro para obter o número de índices de uma tabela.

```
short GetIndexCount();
```

### <a name="return-value"></a>Valor retornado

O número de índices para a tabela.

### <a name="remarks"></a>Comentários

Se o seu valor for 0, não há índices na coleção.

Para obter informações relacionadas, consulte o tópico "Count Property" no DAO Help.

## <a name="cdaotabledefgetindexinfo"></a><a name="getindexinfo"></a>CDaoTableDef::GetIndexInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um índice definido na tabeladef.

```cpp
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
O índice numérico do objeto Índice na coleção de Índices baseados em zero da tabela, para busca por sua posição na coleção.

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo.](../../mfc/reference/cdaoindexinfo-structure.md)

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne:

- `AFX_DAO_PRIMARY_INFO`Nome, Informações de Campo, Campos. Use esta opção para obter um desempenho mais rápido.

- `AFX_DAO_SECONDARY_INFO`Informações primárias, além de: Principal, Único, Agrupado, Ignorar Nulos, Obrigatório, Estrangeiro

- `AFX_DAO_ALL_INFO`Informações primárias e secundárias, além de: Contagem distinta

*lpszName*<br/>
Um ponteiro para o nome do objeto de índice, para procurar pelo nome.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um índice por sua posição na coleção. A outra versão permite que você procure um índice por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoIndexInfo.](../../mfc/reference/cdaoindexinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você recebe informações para quaisquer níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaotabledefgetname"></a><a name="getname"></a>CDaoTableDef::GetName

Chame esta função de membro para obter o nome definido pelo usuário da tabela subjacente.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

Um nome definido pelo usuário para uma tabela.

### <a name="remarks"></a>Comentários

Este nome começa com uma letra e pode conter um máximo de 64 caracteres. Ele pode incluir números e sublinhar caracteres, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

## <a name="cdaotabledefgetrecordcount"></a><a name="getrecordcount"></a>CDaoTableDef::GetRecordCount

Ligue para esta função de membro para `CDaoTableDef` descobrir quantos registros estão em um objeto.

```
long GetRecordCount();
```

### <a name="return-value"></a>Valor retornado

O número de registros acessados em um objeto tabledef.

### <a name="remarks"></a>Comentários

A `GetRecordCount` chamada de `CDaoTableDef` um objeto do tipo tabela reflete o número aproximado de registros na tabela e é afetada imediatamente à medida que os registros de tabela são adicionados e excluídos. As transações revertidas aparecerão como parte da contagem de registros até que você chame [CDaoWorkSpace::CompactDatabase](../../mfc/reference/cdaoworkspace-class.md#compactdatabase). Um `CDaoTableDef` objeto sem registros tem uma configuração de propriedade de contagem de registros de 0. Ao trabalhar com tabelas anexadas ou `GetRecordCount` bancos de dados ODBC, sempre retorna -1.

Para obter informações relacionadas, consulte o tópico "RecordCount Property" no DAO Help.

## <a name="cdaotabledefgetsourcetablename"></a><a name="getsourcetablename"></a>CDaoTableDef::GetSourceTableName

Ligue para esta função de membro para recuperar o nome de uma tabela anexada em um banco de dados de origem.

```
CString GetSourceTableName();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que especifica o nome de origem de uma tabela anexada ou uma seqüência de string vazia se uma tabela de dados nativa.

### <a name="remarks"></a>Comentários

Uma tabela anexada é uma tabela em outro banco de dados vinculado a um banco de dados do Microsoft Jet. Os dados para tabelas anexadas permanecem no banco de dados externo, onde podem ser manipulados por outros aplicativos.

Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na Ajuda da DAO.

## <a name="cdaotabledefgetvalidationrule"></a><a name="getvalidationrule"></a>CDaoTableDef::GetValidationRule

Chame esta função de membro para recuperar a regra de validação de um tabledef.

```
CString GetValidationRule();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que valida os dados em um campo à medida que são alterados ou adicionados a uma tabela.

### <a name="remarks"></a>Comentários

As regras de validação são usadas em conexão com operações de atualização. Se uma tabela desegurança contiver uma regra de validação, as atualizações dessa tabela devem corresponder a critérios pré-determinados antes que os dados sejam alterados. Se a alteração não corresponder aos critérios, uma exceção contendo o valor de [GetValidationText](#getvalidationtext) será lançada. Para `CDaoTableDef` um objeto, isso `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.

Para obter informações relacionadas, consulte o tópico "ValidationRule Property" no DAO Help.

## <a name="cdaotabledefgetvalidationtext"></a><a name="getvalidationtext"></a>CDaoTableDef::GetValidationText

Chame esta função para recuperar a seqüência a ser exibida quando um usuário insere dados que não correspondem à regra de validação.

```
CString GetValidationText();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que especifica o texto exibido se o usuário inserir dados que não correspondam à regra de validação.

### <a name="remarks"></a>Comentários

Para `CDaoTableDef` um objeto, isso `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.

Para obter informações relacionadas, consulte o tópico "ValidationText Property" no DAO Help.

## <a name="cdaotabledefisopen"></a><a name="isopen"></a>CDaoTableDef::IsOpen

Ligue para esta função `CDaoTableDef` de membro para determinar se o objeto está aberto no momento.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `CDaoTableDef` se o objeto estiver aberto; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cdaotabledefm_pdatabase"></a><a name="m_pdatabase"></a>CDaoTableDef::m_pDatabase

Contém um ponteiro para o objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) para esta tabela.

### <a name="remarks"></a>Comentários

## <a name="cdaotabledefm_pdaotabledef"></a><a name="m_pdaotabledef"></a>CDaoTableDef::m_pDAOTableDef

Contém um ponteiro para a interface OLE para o `CDaoTableDef` objeto DAO tabledef subjacente ao objeto.

### <a name="remarks"></a>Comentários

Use este ponteiro se precisar acessar diretamente a interface DAO.

## <a name="cdaotabledefopen"></a><a name="open"></a>CDaoTableDef::Aberto

Ligue para esta função de membro para abrir uma tabledef previamente salva na coleção do TableDef do banco de dados.

```
virtual void Open(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma seqüência que especifica um nome de tabela.

### <a name="remarks"></a>Comentários

## <a name="cdaotabledefrefreshlink"></a><a name="refreshlink"></a>CDaoTableDef::RefreshLink

Ligue para esta função de membro para atualizar as informações de conexão para uma tabela anexada.

```cpp
void RefreshLink();
```

### <a name="remarks"></a>Comentários

Você altera as informações de conexão para uma `CDaoTableDef` tabela anexada `RefreshLink` ligando para [SetConnect](#setconnect) no objeto correspondente e, em seguida, usando a função membro para atualizar as informações. Quando você `RefreshLink`chama, as propriedades da tabela anexada não são alteradas.

Para forçar que as informações de conexão modificadas entrem em vigor, todos os objetos [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) abertos com base neste tabledef devem ser fechados.

Para obter informações relacionadas, consulte o tópico "Método De AtualizaçãoLink" na Ajuda da DAO.

## <a name="cdaotabledefsetattributes"></a><a name="setattributes"></a>CDaoTableDef::SetAttributes

Define um valor que indica uma `CDaoTableDef` ou mais características de um objeto.

```cpp
void SetAttributes(long lAttributes);
```

### <a name="parameters"></a>Parâmetros

*lAtributos*<br/>
Características da tabela representada `CDaoTableDef` pelo objeto e pode ser uma soma dessas constantes:

|Constante|Descrição|
|--------------|-----------------|
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexaaberta para uso exclusivo.|
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que o ID do usuário e a senha da tabela anexada são salvos com as informações de conexão.|
|`dbSystemObject`|Indica que a tabela é uma tabela de sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|
|`dbHiddenObject`|Indica que a tabela é uma tabela oculta fornecida pelo mecanismo de banco de dados Microsoft Jet.|

### <a name="remarks"></a>Comentários

Ao definir vários atributos, você pode combiná-los somando as constantes apropriadas usando o operador bitwise-OR. A `dbAttachExclusive` configuração em uma tabela não anexada produz uma exceção. A combinação dos seguintes valores também produz uma exceção:

- **dbAttachExclusive &#124; dbAttachedODBC**

- **dbAttachSavePWD &#124; dbAttachedTable**

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaotabledefsetconnect"></a><a name="setconnect"></a>CDaoTableDef::SetConnect

Para `CDaoTableDef` um objeto que representa uma tabela anexada, o objeto de seqüência consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).

```cpp
void SetConnect(LPCTSTR lpszConnect);
```

### <a name="parameters"></a>Parâmetros

*lpszConnect*<br/>
Um ponteiro para uma expressão de string que especifica parâmetros adicionais para passar para drivers ISAM oDBC ou instaláveis.

### <a name="remarks"></a>Comentários

O caminho mostrado na tabela abaixo é o caminho completo para o diretório que contém os arquivos do banco de dados e deve ser precedido pelo identificador "DATABASE=". Em alguns casos (como nos bancos de dados Microsoft Jet e Microsoft Excel), um nome de arquivo específico é incluído no argumento de caminho do banco de dados.

> [!NOTE]
> Não inclua espaço em branco ao redor do sinal igual\\nas instruções de caminho do formulário "DATABASE=drive: \path". Isso resultará em uma exceção sendo lançada e a conexão falhando.

A tabela a seguir mostra possíveis tipos de banco de dados e seus correspondentes especificadores e caminhos de banco de dados:

|Tipo de banco de dados|Especificador|Caminho|
|-------------------|---------------|----------|
|Banco de dados usando o mecanismo de banco de dados Jet|"[ `database`];"|" `drive`\\\ : nome*do arquivo de**caminho*\\\ . MDB"|
|dBASE III|"dBASE III;"|" `drive`\\\ :*caminho*"|
|dBASE IV|"dBASE IV;"|" `drive`\\\ :*caminho*"|
|dBASE 5|"dBASE 5.0;"|" `drive`\\\ :*caminho*"|
|Paradoxo 3.x|"Paradoxo 3.x;"|" `drive`\\\ :*caminho*"|
|Paradoxo 4.x|"Paradoxo 4.x".|" `drive`\\\ :*caminho*"|
|Paradoxo 5.x|"Paradoxo 5.x;"|" `drive`\\\ :*caminho*"|
|Excel 3.0|"Excel 3.0;"|" `drive`\\\ : nome*do arquivo de**caminho*\\\ . XLS"|
|Excel 4.0|"Excel 4.0;"|" `drive`\\\ : nome*do arquivo de**caminho*\\\ . XLS"|
|Excel 5.0 ou Excel 95|"Excel 5.0;"|" `drive`\\\ : nome*do arquivo de**caminho*\\\ . XLS"|
|Excel 97|"Excel 8.0;"|" `drive`\\\ : nome*do arquivo de**caminho*\ . XLS"|
|Importação HTML|"Importação html;"|" `drive`\\\ : nome*do arquivo de**caminho*\ "|
|Exportação HTML|"Exportação HTML;"|" `drive`\\\ :*caminho*"|
|Texto|"Texto";|"unidade:\\\caminho"|
|ODBCODBC|"ODBC; BANCO `database`DE DADOS= ; UID= *usuário;* PWD= *senha;* DSN= *nome de origem de dados;* LOGINTIMEOUT= *segundos;*" (Esta pode não ser uma seqüência de conexão completa para todos os servidores; é apenas um exemplo. É muito importante não ter espaços entre os parâmetros.)|Nenhum|
|Exchange|"Troca;<br /><br /> MAPILEVEL= *pastacaminho;*<br /><br /> [TABLETYPE={ 0 &#124; 1 };]<br /><br /> [PERFIL= *perfil*;]<br /><br /> [PWD= *senha*;]<br /><br /> [BANCO `database`DE DADOS= ;]"|*"drive*\\\ :*nome do arquivo de**caminho*\\\ . MDB"|

> [!NOTE]
> Btrieve não é mais suportado a partir de DAO 3.5.

Você deve usar uma\\\\barra invertida dupla () nas strings de conexão. Se você modificou as propriedades de `SetConnect`uma conexão existente usando, você deve posteriormente chamar [RefreshLink](#refreshlink). Se você estiver inicializando `SetConnect`as propriedades de `RefreshLink`conexão usando, você não precisa ligar, mas se você optar por fazê-lo, primeiro anexar o tabledef.

Se uma senha for necessária, mas não for fornecida, o driver ODBC exibirá uma caixa de diálogo de login na primeira vez que uma tabela for acessada e novamente se a conexão for fechada e reaberta.

Você pode definir a `CDaoTableDef` seqüência de conexões `Create` para um objeto fornecendo um argumento de origem para a função de membro. Você pode verificar a configuração para determinar o tipo, caminho, ID do usuário, senha ou fonte de dados ODBC do banco de dados. Para obter mais informações, consulte a documentação do motorista específico.

Para obter informações relacionadas, consulte o tópico "Conectar propriedade" no DAO Help.

## <a name="cdaotabledefsetname"></a><a name="setname"></a>CDaoTableDef::SetName

Chame esta função de membro para definir um nome definido pelo usuário para uma tabela.

```cpp
void SetName(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma expressão de string que especifica um nome para uma tabela.

### <a name="remarks"></a>Comentários

O nome deve começar com uma letra e pode conter um máximo de 64 caracteres. Ele pode incluir números e sublinhar caracteres, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

## <a name="cdaotabledefsetsourcetablename"></a><a name="setsourcetablename"></a>CDaoTableDef::SetSourceTableName

Chame esta função de membro para especificar o nome de uma `CDaoTableDef` tabela anexada ou o nome da tabela base na qual o objeto está baseado, como ele existe na fonte original dos dados.

```cpp
void SetSourceTableName(LPCTSTR lpszSrcTableName);
```

### <a name="parameters"></a>Parâmetros

*lpszSrcTableName*<br/>
Um ponteiro para uma expressão de string que especifica um nome de tabela no banco de dados externo. Para uma tabela base, a configuração é uma string vazia ("").

### <a name="remarks"></a>Comentários

Em seguida, você deve chamar [RefreshLink](#refreshlink). Esta configuração de propriedade está vazia para uma tabela base e leitura/gravação para uma tabela anexada ou um objeto não anexado a uma coleção.

Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na Ajuda da DAO.

## <a name="cdaotabledefsetvalidationrule"></a><a name="setvalidationrule"></a>CDaoTableDef::SetValidationRule

Chame esta função de membro para definir uma regra de validação para um tabledef.

```cpp
void SetValidationRule(LPCTSTR lpszValidationRule);
```

### <a name="parameters"></a>Parâmetros

*lpszValidationRule*<br/>
Um ponteiro para uma expressão de string que valida uma operação.

### <a name="remarks"></a>Comentários

As regras de validação são usadas em conexão com operações de atualização. Se uma tabela desegurança contiver uma regra de validação, as atualizações dessa tabela devem corresponder a critérios pré-determinados antes que os dados sejam alterados. Se a alteração não corresponder aos critérios, uma exceção que contenha o texto de [GetValidationText](#getvalidationtext) será exibida.

A validação é suportada apenas para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet. A expressão não pode se referir a funções definidas pelo usuário, funções agregadas de domínio, funções agregadas sql ou consultas. Uma regra de `CDaoTableDef` validação para um objeto pode se referir a vários campos nesse objeto.

Por exemplo, para campos chamados *hire_date* e *termination_date,* uma regra de validação pode ser:

[!code-cpp[NVC_MFCDatabase#34](../../mfc/codesnippet/cpp/cdaotabledef-class_1.cpp)]

Para obter informações relacionadas, consulte o tópico "ValidationRule Property" no DAO Help.

## <a name="cdaotabledefsetvalidationtext"></a><a name="setvalidationtext"></a>CDaoTableDef::SetValidationText

Chame esta função de membro para definir o `CDaoTableDef` texto de exceção de uma regra de validação para um objeto com uma tabela base subjacente suportada pelo mecanismo de banco de dados Microsoft Jet.

```cpp
void SetValidationText(LPCTSTR lpszValidationText);
```

### <a name="parameters"></a>Parâmetros

*lpszValidaçãoTexto*<br/>
Um ponteiro para uma expressão de seqüência que especifica o texto exibido se os dados inseridos é inválido.

### <a name="remarks"></a>Comentários

Não é possível definir o texto de validação de uma tabela anexada.

Para obter informações relacionadas, consulte o tópico "ValidationText Property" no DAO Help.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
