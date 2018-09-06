---
title: Classe CDaoTableDef | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c8b3772f556dd92694222e4f3d7d2e15deb051c5
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43766039"
---
# <a name="cdaotabledef-class"></a>Classe CDaoTableDef
Representa a definição armazenada de uma tabela base ou uma tabela anexada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoTableDef : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoTableDef::CDaoTableDef](#cdaotabledef)|Constrói um objeto `CDaoTableDef`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoTableDef::Append](#append)|Adiciona uma nova tabela no banco de dados.|  
|[CDaoTableDef::CanUpdate](#canupdate)|Retorna não zero se a tabela pode ser atualizada (você pode modificar a definição de campos ou propriedades da tabela).|  
|[CDaoTableDef::Close](#close)|Fecha um tabledef aberto.|  
|[CDaoTableDef::Create](#create)|Cria uma tabela que pode ser adicionada ao banco de dados usando [Append](#append).|  
|[CDaoTableDef::CreateField](#createfield)|Chamado para criar um campo para uma tabela.|  
|[CDaoTableDef::CreateIndex](#createindex)|Chamado para criar um índice para uma tabela.|  
|[CDaoTableDef::DeleteField](#deletefield)|Chamado para excluir um campo de uma tabela.|  
|[CDaoTableDef::DeleteIndex](#deleteindex)|Chamado para excluir um índice de uma tabela.|  
|[CDaoTableDef::GetAttributes](#getattributes)|Retorna um valor que indica uma ou mais características de um `CDaoTableDef` objeto.|  
|[CDaoTableDef::GetConnect](#getconnect)|Retorna um valor que fornece informações sobre a origem de uma tabela.|  
|[CDaoTableDef::GetDateCreated](#getdatecreated)|Retorna a data e hora a tabela base subjacente um `CDaoTableDef` objeto foi criado.|  
|[CDaoTableDef::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e hora da alteração mais recente feita no design da tabela base.|  
|[CDaoTableDef::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos na tabela.|  
|[CDaoTableDef::GetFieldInfo](#getfieldinfo)|Retorna os tipos específicos de informações sobre os campos na tabela.|  
|[CDaoTableDef::GetIndexCount](#getindexcount)|Retorna o número de índices da tabela.|  
|[CDaoTableDef::GetIndexInfo](#getindexinfo)|Retorna os tipos específicos de informações sobre os índices da tabela.|  
|[CDaoTableDef::GetName](#getname)|Retorna o nome da tabela definida pelo usuário.|  
|[CDaoTableDef::GetRecordCount](#getrecordcount)|Retorna o número de registros na tabela.|  
|[CDaoTableDef::GetSourceTableName](#getsourcetablename)|Retorna um valor que especifica o nome da tabela anexada no banco de dados de origem.|  
|[CDaoTableDef::GetValidationRule](#getvalidationrule)|Retorna um valor que valida os dados em um campo como ele é alterado ou adicionado a uma tabela.|  
|[CDaoTableDef::GetValidationText](#getvalidationtext)|Retorna um valor que especifica o texto da mensagem que seu aplicativo exibe o valor de um objeto de campo satisfaça a regra de validação especificado.|  
|[CDaoTableDef::IsOpen](#isopen)|Retorna diferente de zero se a tabela é aberta.|  
|[CDaoTableDef::Open](#open)|Abre um tabledef existente armazenado no banco de dados 's coleção do TableDef.|  
|[CDaoTableDef::RefreshLink](#refreshlink)|Atualiza as informações de conexão para uma tabela anexada.|  
|[CDaoTableDef::SetAttributes](#setattributes)|Define um valor que indica uma ou mais características de um `CDaoTableDef` objeto.|  
|[CDaoTableDef::SetConnect](#setconnect)|Define um valor que fornece informações sobre a origem de uma tabela.|  
|[CDaoTableDef::SetName](#setname)|Define o nome da tabela.|  
|[CDaoTableDef::SetSourceTableName](#setsourcetablename)|Define um valor que especifica o nome de uma tabela anexada no banco de dados de origem.|  
|[CDaoTableDef::SetValidationRule](#setvalidationrule)|Define um valor que valida os dados em um campo como ele é alterado ou adicionado a uma tabela.|  
|[CDaoTableDef::SetValidationText](#setvalidationtext)|Define um valor que especifica o texto da mensagem que seu aplicativo exibe o valor de um objeto de campo satisfaça a regra de validação especificado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoTableDef::m_pDAOTableDef](#m_pdaotabledef)|Um ponteiro para a interface base do objeto tabledef do DAO.|  
|[CDaoTableDef::m_pDatabase](#m_pdatabase)|Banco de dados de origem para essa tabela.|  
  
## <a name="remarks"></a>Comentários  
 Cada objeto de banco de dados DAO mantém uma coleção, chamada TableDefs, que contém todos os objetos salvos de tabledef DAO.  
  
 Manipular a uma definição de tabela usando um `CDaoTableDef` objeto. Por exemplo, você pode:  
  
-   Examine a estrutura de índice e o campo de qualquer tabela local, anexada ou externa em um banco de dados.  
  
-   Chame o `SetConnect` e `SetSourceTableName` funções de membro para tabelas anexadas e use o `RefreshLink` anexado de função de membro para atualizar conexões com tabelas.  
  
-   Chamar o `CanUpdate` a função de membro para determinar se você pode editar as definições de campo na tabela.  
  
-   Obter ou definir condições de validação usando o `GetValidationRule` e `SetValidationRule`e o `GetValidationText` e `SetValidationText` funções de membro.  
  
-   Use o `Open` função de membro para criar uma tabela, dynaset ou tipo de instantâneo `CDaoRecordset` objeto.  
  
    > [!NOTE]
    >  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de como eles são específicos para o mecanismo de banco de dados Microsoft Jet.  
  
### <a name="to-use-tabledef-objects-either-to-work-with-an-existing-table-or-to-create-a-new-table"></a>Para usar objetos tabledef para trabalhar com uma tabela existente ou criar uma nova tabela  
  
1.  Em todos os casos, primeiro criar uma `CDaoTableDef` objeto, fornecendo um ponteiro para uma [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) do objeto ao qual a tabela pertence.  
  
2.  Em seguida, faça o seguinte, dependendo do que você deseja:  
  
    -   Para usar um tabela salva existente, chame o objeto de tabledef [abrir](#open) função de membro, fornecendo o nome da tabela de dados salvo.  
  
    -   Para criar uma nova tabela, chame o objeto de tabledef [criar](#create) função de membro, fornecendo o nome da tabela. Chame [CreateField](#createfield) e [CreateIndex](#createindex) para adicionar campos e índices na tabela.  
  
    -   Chame [Append](#append) para salvar a tabela acrescentando-o à coleção TableDefs do banco de dados. `Create` coloca o tabledef em um estado aberto, portanto, depois de chamar `Create` você não chamar `Open`.  
  
        > [!TIP]
        >  A maneira mais fácil criar tabelas salvas é criá-los e armazená-los em seu banco de dados usando o Microsoft Access. Em seguida, você pode abrir e usá-los em seu código do MFC.  
  
 Para usar o objeto tabledef você ter aberto ou criado, criar e abrir um `CDaoRecordset` objeto, especificando o nome do tabledef com um `dbOpenTable` o valor a *nOpenType* parâmetro.  
  
 Usar um objeto tabledef para criar uma `CDaoRecordset` do objeto, você normalmente crie ou abra um tabledef conforme descrito acima e construir um objeto recordset, passando um ponteiro para seu objeto tabledef quando você chama [2&gt;cdaorecordset::Open&lt;2](../../mfc/reference/cdaorecordset-class.md#open). Tabledef que você passar deve ser em um estado aberto. Para obter mais informações, consulte a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Quando você terminar de usar um objeto tabledef, chame seu [fechar](../../mfc/reference/cdaorecordset-class.md#close) membro de função; em seguida, destrua o objeto tabledef.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDaoTableDef`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="append"></a>  CDaoTableDef::Append  
 Chame essa função de membro depois de chamar [criar](#create) para criar um novo objeto tabledef para salvar o tabledef no banco de dados.  
  
```  
virtual void Append();
```  
  
### <a name="remarks"></a>Comentários  
 A função acrescenta o objeto à coleção TableDefs do banco de dados. Você pode usar o tabledef como um objeto temporário ao defini-lo anexando-não, mas se você deseja salvar e usá-lo, você deve chamar `Append`.  
  
> [!NOTE]
>  Se você tentar anexar um tabledef sem nome (que contém uma cadeia de caracteres nula ou vazia), o MFC gera uma exceção.  
  
 Para obter informações relacionadas, consulte o tópico "Acrescentar o método" na Ajuda do DAO.  
  
##  <a name="canupdate"></a>  CDaoTableDef::CanUpdate  
 Chame essa função de membro para determinar se a definição da tabela subjacente um `CDaoTableDef` objeto pode ser alterado.  
  
```  
BOOL CanUpdate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a estrutura da tabela (esquema) pode ser modificada (Adicionar ou excluir campos e índices), caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, uma tabela recém-criada subjacente uma `CDaoTableDef` objeto pode ser atualizado e uma tabela anexada subjacente um `CDaoTableDef` objeto não pode ser atualizado. Um `CDaoTableDef` objeto pode ser atualizável, mesmo se o conjunto de registros resultante não é atualizável.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="cdaotabledef"></a>  CDaoTableDef::CDaoTableDef  
 Constrói um objeto `CDaoTableDef`.  
  
```  
CDaoTableDef(CDaoDatabase* pDatabase);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDatabase*  
 Um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Depois de construir o objeto, você deve chamar o [Create](#create) ou [abrir](#open) função de membro. Quando você terminar com o objeto, você deve chamar seu [feche](#close) membro de função e destruir o `CDaoTableDef` objeto.  
  
##  <a name="close"></a>  CDaoTableDef::Close  
 Chame essa função de membro para fechar e liberar o objeto tabledef.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, depois de chamar `Close`, exclua o objeto tabledef se ele foi alocado com **nova**.  
  
 Você pode chamar [aberto](#open) depois de chamar `Close`. Isso lhe permite reutilizar o objeto tabledef.  
  
 Para obter informações relacionadas, consulte o tópico "Método Close" na Ajuda do DAO.  
  
##  <a name="create"></a>  CDaoTableDef::Create  
 Chame essa função de membro para criar uma nova tabela salva.  
  
```  
virtual void Create(
    LPCTSTR lpszName,  
    long lAttributes = 0,  
    LPCTSTR lpszSrcTable = NULL,  
    LPCTSTR lpszConnect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma cadeia de caracteres que contém o nome da tabela.  
  
 *lAttributes*  
 Um valor que corresponde às características da tabela representada pelo objeto tabledef. Você pode usar o OR bit a bit para combinar qualquer uma das seguintes constantes:  
  
|Constante|Descrição|  
|--------------|-----------------|  
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|  
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a ID de usuário e senha para a tabela vinculada são salvos com as informações de conexão.|  
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
|`dbHiddenObject`|Indica que a tabela é uma tabela ocultada fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
  
 *lpszSrcTable*  
 Um ponteiro para uma cadeia de caracteres que contém o nome da tabela de origem. Por padrão, esse valor é inicializado como NULL.  
  
 *lpszConnect*  
 Um ponteiro para uma cadeia de caracteres que contém a cadeia de conexão padrão. Por padrão, esse valor é inicializado como NULL.  
  
### <a name="remarks"></a>Comentários  
 Depois que você tenha nomeado tabledef, em seguida, você pode chamar [Append](#append) salvar tabledef na coleção TableDefs do banco de dados. Depois de chamar `Append`tabledef está em um estado aberto e você pode usá-lo para criar um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto.  
  
 Para obter informações relacionadas, consulte o tópico "CreateTableDef Method" na Ajuda do DAO.  
  
##  <a name="createfield"></a>  CDaoTableDef::CreateField  
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
 *lpszName*  
 Um ponteiro para uma expressão de cadeia de caracteres especificando o nome desse campo.  
  
 *nType*  
 Um valor que indica o tipo de dados do campo. A configuração pode ser um destes valores:  
  
|Tipo|Tamanho (bytes)|Descrição|  
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
  
 *lSize*  
 Um valor que indica o tamanho máximo, em bytes, de um campo que contém texto, ou o tamanho fixo de um campo que contém os valores de texto ou numérica. O *lSize* parâmetro é ignorado para todos, exceto campos de texto.  
  
 *lAttributes*  
 Um valor que corresponde às características do campo e que pode ser combinado usando um OR bit a bit.  
  
|Constante|Descrição|  
|--------------|-----------------|  
|`dbFixedField`|O tamanho do campo é fixo (padrão para campos numéricos).|  
|`dbVariableField`|O tamanho do campo é variável (somente para campos de texto).|  
|`dbAutoIncrField`|O valor do campo para novos registros é incrementado automaticamente para um inteiro longo exclusivo que não pode ser alterado. Só tem suporte para tabelas de banco de dados Microsoft Jet.|  
|`dbUpdatableField`|O valor do campo pode ser alterado.|  
|`dbDescending`|O campo é classificado em decrescente (Z - A ou 0 a 100) ordem (aplica-se somente a um objeto de campo em uma coleção de campos de um objeto de índice). Se você omitir essa constante, o campo será classificado em crescente (A - Z ou 0 – 100) ordem (padrão).|  
  
 *FieldInfo*  
 Uma referência a um [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Um `DAOField` objeto (OLE) é criado e acrescentado à coleção de campos de `DAOTableDef` objeto (OLE). Além de seu uso para examinar as propriedades do objeto, você também pode usar `CDaoFieldInfo` para construir um parâmetro de entrada para a criação de novos campos em um tabledef. A primeira versão do `CreateField` é mais simples de usar, mas se você quiser um controle mais preciso, você pode usar a segunda versão do `CreateField`, que utiliza um `CDaoFieldInfo` parâmetro.  
  
 Se você usar a versão do `CreateField` que usa um `CDaoFieldInfo` parâmetro, você deve cuidadosamente definir cada um dos seguintes membros do `CDaoFieldInfo` estrutura:  
  
- `m_strName`  
  
- `m_nType`  
  
- `m_lSize`  
  
- `m_lAttributes`  
  
- `m_bAllowZeroLength`  
  
 Os membros restantes da `CDaoFieldInfo` deve ser definido como **0**, FALSE ou uma cadeia de caracteres vazia, conforme apropriado para o membro, ou um `CDaoException` pode ocorrer.  
  
 Para obter informações relacionadas, consulte o tópico "CreateField Method" na Ajuda do DAO.  
  
##  <a name="createindex"></a>  CDaoTableDef::CreateIndex  
 Chame essa função para adicionar um índice a uma tabela.  
  
```  
void CreateIndex(CDaoIndexInfo& indexinfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *indexinfo*  
 Uma referência a um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Índices de especificam a ordem dos registros acessados a partir de tabelas de banco de dados e ou não os registros duplicados são aceitos. Índices também fornecem acesso eficiente aos dados.  
  
 Você não precisa criar índices para tabelas, mas em tabelas grandes e não indexadas, acesso a um registro específico ou criar um conjunto de registros pode levar muito tempo. Por outro lado, a criação de muitos índices lentidão na atualização, acrescentar e excluir operações, como todos os índices são atualizados automaticamente. Considere estes fatores ao decidir quais índices criar.  
  
 Os seguintes membros do `CDaoIndexInfo` estrutura deve ser definida:  
  
- `m_strName` Um nome deve ser fornecido.  
  
- `m_pFieldInfos` Deve apontar para uma matriz de `CDaoIndexFieldInfo` estruturas.  
  
- `m_nFields` Especifique o número de campos na matriz de `CDaoFieldInfo` estruturas.  
  
 O restante de membros será ignorado se definido como FALSE. Além disso, o `m_lDistinctCount` membro será ignorado durante a criação do índice.  
  
##  <a name="deletefield"></a>  CDaoTableDef::DeleteField  
 Chame essa função de membro para remover um campo e torná-lo inacessível.  
  
```  
void DeleteField(LPCTSTR lpszName);  
void DeleteField(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma expressão de cadeia de caracteres que é o nome de um campo existente.  
  
 *nIndex*  
 O índice do campo na coleção de campos com base em zero da tabela, para a pesquisa por índice.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função de membro em um novo objeto que não foi acrescentado ao banco de dados ou quando [CanUpdate](#canupdate) retorna não zero.  
  
 Para obter informações relacionadas, consulte o tópico "Método Delete" na Ajuda do DAO.  
  
##  <a name="deleteindex"></a>  CDaoTableDef::DeleteIndex  
 Chame essa função de membro para excluir um índice em uma tabela base.  
  
```  
void DeleteIndex(LPCTSTR lpszName);  
void DeleteIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma expressão de cadeia de caracteres que é o nome de um índice existente.  
  
 *nIndex*  
 O índice de matriz do objeto de índice na coleção de TableDefs baseado em zero do banco de dados, para a pesquisa por índice.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função de membro em um novo objeto que ainda não foi acrescentado ao banco de dados ou quando [CanUpdate](#canupdate) retorna não zero.  
  
 Para obter informações relacionadas, consulte o tópico "Método Delete" na Ajuda do DAO.  
  
##  <a name="getattributes"></a>  CDaoTableDef::GetAttributes  
 Para um `CDaoTableDef` objeto, o valor de retorno Especifica as características da tabela representada pelo `CDaoTableDef` do objeto e pode ser uma soma das constantes:  
  
```  
long GetAttributes();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que indica uma ou mais características de um `CDaoTableDef` objeto.  
  
### <a name="remarks"></a>Comentários  
  
|Constante|Descrição|  
|--------------|-----------------|  
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|  
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a ID de usuário e senha para a tabela vinculada são salvos com as informações de conexão.|  
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
|`dbHiddenObject`|Indica que a tabela é uma tabela ocultada fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
|`dbAttachedTable`|Indica que a tabela é uma tabela anexada de um banco de dados não-ODBC, como um banco de dados Paradox.|  
|`dbAttachedODBC`|Indica que a tabela é uma tabela anexada de um banco de dados ODBC, como o Microsoft SQL Server.|  
  
 Uma tabela do sistema é uma tabela criada pelo mecanismo de banco de dados Microsoft Jet para conter várias informações internas.  
  
 Uma tabela ocultada é uma tabela criada para uso temporário pelo mecanismo de banco de dados Microsoft Jet.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.  
  
##  <a name="getconnect"></a>  CDaoTableDef::GetConnect  
 Chame essa função de membro para obter a cadeia de caracteres de conexão para uma fonte de dados.  
  
```  
CString GetConnect();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o tipo de banco de dados e o caminho para a tabela.  
  
### <a name="remarks"></a>Comentários  
 Para um `CDaoTableDef` objeto que representa uma tabela anexada, o `CString` objeto consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).  
  
 O caminho, conforme mostrado na tabela a seguir é o caminho completo para o diretório que contém os arquivos de banco de dados e deve ser precedido pelo identificador de "banco de dados =". Em alguns casos (como com o Microsoft Excel e o Microsoft Jet bancos de dados), um nome de arquivo específico está incluído no argumento de caminho do banco de dados.  
  
 A tabela no [CDaoTableDef::SetConnect](#setconnect) mostra os tipos possíveis de banco de dados e seus correspondentes especificadores de banco de dados e caminhos:  
  
 Para tabelas de base de banco de dados Microsoft Jet, o especificador é uma cadeia de caracteres vazia ("").  
  
 Se uma senha é necessária, mas não fornecida, o driver ODBC exibe uma logon caixa de diálogo na primeira vez uma tabela é acessada e novamente se a conexão é fechada e reaberta. Se tiver uma tabela anexada a `dbAttachSavePWD` atributo, o prompt de logon não será exibida quando a tabela é reaberta.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
##  <a name="getdatecreated"></a>  CDaoTableDef::GetDateCreated  
 Chame essa função para determinar a data e hora a tabela subjacente a `CDaoTableDef` objeto foi criado.  
  
```  
COleDateTime GetDateCreated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que contém a data e hora da criação da tabela subjacente a `CDaoTableDef` objeto.  
  
### <a name="remarks"></a>Comentários  
 As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de horário "padrão" — talvez de um servidor.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="getdatelastupdated"></a>  CDaoTableDef::GetDateLastUpdated  
 Chame essa função para determinar a data e hora a tabela subjacente a `CDaoTableDef` objeto foi atualizado pela última vez.  
  
```  
COleDateTime GetDateLastUpdated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que contém a data e hora a tabela subjacente a `CDaoTableDef` objeto foi atualizado pela última vez.  
  
### <a name="remarks"></a>Comentários  
 As configurações de data e hora são derivadas do computador no qual a tabela base foi criada ou atualizado pela última vez. Em um ambiente multiusuário, os usuários devem obter essas configurações diretamente do servidor de arquivos para evitar discrepâncias; ou seja, todos os clientes devem usar uma fonte de horário "padrão" — talvez de um servidor.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="getfieldcount"></a>  CDaoTableDef::GetFieldCount  
 Chame essa função de membro para recuperar o número de campos definidos na tabela.  
  
```  
short GetFieldCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de campos na tabela.  
  
### <a name="remarks"></a>Comentários  
 Não se o valor for 0, há nenhum objeto na coleção.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Count" na Ajuda do DAO.  
  
##  <a name="getfieldinfo"></a>  CDaoTableDef::GetFieldInfo  
 Chame essa função de membro para obter vários tipos de informações sobre um campo definido em tabledef.  
  
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
 *nIndex*  
 O índice do objeto de campo na coleção de campos com base em zero da tabela, para a pesquisa por índice.  
  
 *FieldInfo*  
 Uma referência a um [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura.  
  
 *dwInfoOptions*  
 Opções que especificam quais informações sobre o campo a recuperar. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO` (Padrão) Nome, tipo, tamanho, atributos. Use esta opção para desempenho mais rápido.  
  
- `AFX_DAO_SECONDARY_INFO` Informações principais, além de: posição Ordinal, obrigatório, permitir que a tabela de origem de nome externa, o campo de origem, Zero comprimento, a ordem de agrupamento,  
  
- `AFX_DAO_ALL_INFO` Informações de primárias e secundárias, além de: valor de padrão de regra de validação, o texto de validação  
  
 *lpszName*  
 Um ponteiro para o nome do objeto field, para a pesquisa por nome. O nome é uma cadeia de caracteres com até 64 caracteres que nomeia exclusivamente o campo.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um campo por índice. A outra versão permite pesquisar um campo por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Quando você solicita informações em um nível, você pode obter informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.  
  
##  <a name="getindexcount"></a>  CDaoTableDef::GetIndexCount  
 Chame essa função de membro para obter o número de índices para uma tabela.  
  
```  
short GetIndexCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de índices da tabela.  
  
### <a name="remarks"></a>Comentários  
 Não se o valor for 0, há nenhum índice na coleção.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Count" na Ajuda do DAO.  
  
##  <a name="getindexinfo"></a>  CDaoTableDef::GetIndexInfo  
 Chame essa função de membro para obter vários tipos de informações sobre um índice definido na tabledef.  
  
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
 *nIndex*  
 O índice numérico do objeto de índice na coleção de índices com base em zero da tabela, para a pesquisa por sua posição na coleção.  
  
 *indexinfo*  
 Uma referência a um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura.  
  
 *dwInfoOptions*  
 Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO` Campos de nome, informações de campo. Use esta opção para desempenho mais rápido.  
  
- `AFX_DAO_SECONDARY_INFO` Informações principais, além de: primário, Unique, Clustered, ignorar nulos, obrigatórios, estrangeiro  
  
- `AFX_DAO_ALL_INFO` Informações de primárias e secundárias, além de: contagem distinta  
  
 *lpszName*  
 Um ponteiro para o nome do objeto index, para a pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Quando você solicita informações em um nível, você pode obter informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.  
  
##  <a name="getname"></a>  CDaoTableDef::GetName  
 Chame essa função de membro para obter o nome definido pelo usuário da tabela subjacente.  
  
```  
CString GetName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um nome definido pelo usuário para uma tabela.  
  
### <a name="remarks"></a>Comentários  
 Esse nome começa com uma letra e pode conter no máximo 64 caracteres. Ele pode incluir números e sublinhado caracteres, mas não pode incluir espaços ou pontuação.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
##  <a name="getrecordcount"></a>  CDaoTableDef::GetRecordCount  
 Chame essa função de membro para descobrir quantos registros estão em um `CDaoTableDef` objeto.  
  
```  
long GetRecordCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de registros acessados em um objeto tabledef.  
  
### <a name="remarks"></a>Comentários  
 Chamando `GetRecordCount` para um tipo de tabela `CDaoTableDef` reflete o número aproximado de registros na tabela de objeto e é afetado imediatamente conforme os registros da tabela são adicionados e excluídos. Revertida transações serão exibido como parte do que a contagem de registros até que você chame [CDaoWorkSpace::CompactDatabase](../../mfc/reference/cdaoworkspace-class.md#compactdatabase). Um `CDaoTableDef` objeto sem registros tem uma configuração de propriedade de contagem de registros de 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retorna -1.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na Ajuda do DAO.  
  
##  <a name="getsourcetablename"></a>  CDaoTableDef::GetSourceTableName  
 Chame essa função de membro para recuperar o nome de uma tabela anexada em um banco de dados de origem.  
  
```  
CString GetSourceTableName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que especifica o nome da fonte de uma tabela anexada ou uma cadeia de caracteres vazia, se uma tabela de dados nativos.  
  
### <a name="remarks"></a>Comentários  
 Uma tabela anexada é uma tabela em outro banco de dados vinculada a um banco de dados Microsoft Jet. Os dados das tabelas anexadas permanecem no banco de dados externo, onde podem ser manipulado por outros aplicativos.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na Ajuda do DAO.  
  
##  <a name="getvalidationrule"></a>  CDaoTableDef::GetValidationRule  
 Chame essa função de membro para recuperar a regra de validação para um tabledef.  
  
```  
CString GetValidationRule();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que valida os dados em um campo como ele é alterado ou adicionado a uma tabela.  
  
### <a name="remarks"></a>Comentários  
 Regras de validação são usadas em conjunto com as operações de atualização. Se um tabledef contém uma regra de validação, as atualizações para esse tabledef devem corresponder aos predeterminado critérios antes dos dados são alterados. Se a alteração não corresponder aos critérios, uma exceção que contém o valor de [GetValidationText](#getvalidationtext) é gerada. Para um `CDaoTableDef` do objeto, isso `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de regra de validação" na Ajuda do DAO.  
  
##  <a name="getvalidationtext"></a>  CDaoTableDef::GetValidationText  
 Chame essa função para recuperar a cadeia de caracteres a ser exibido quando um usuário insere dados que não coincide com a regra de validação.  
  
```  
CString GetValidationText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que especifica o texto exibido se o usuário insere dados que não coincide com a regra de validação.  
  
### <a name="remarks"></a>Comentários  
 Para um `CDaoTableDef` do objeto, isso `CString` é somente leitura para uma tabela anexada e leitura/gravação para uma tabela base.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade do texto de validação" na Ajuda do DAO.  
  
##  <a name="isopen"></a>  CDaoTableDef::IsOpen  
 Chame essa função de membro para determinar se o `CDaoTableDef` objeto está aberto no momento.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CDaoTableDef` objeto está aberta; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_pdatabase"></a>  CDaoTableDef::m_pDatabase  
 Contém um ponteiro para o [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto para essa tabela.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_pdaotabledef"></a>  CDaoTableDef::m_pDAOTableDef  
 Contém um ponteiro de interface do OLE para DAO tabledef objeto subjacente de `CDaoTableDef` objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esse ponteiro se você precisar acessar a interface DAO diretamente.  
  
##  <a name="open"></a>  CDaoTableDef::Open  
 Essa função de membro para abrir um tabledef salvo anteriormente no banco de dados de chamada do conjunto do TableDef.  
  
```  
virtual void Open(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma cadeia de caracteres que especifica um nome de tabela.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="refreshlink"></a>  CDaoTableDef::RefreshLink  
 Chame essa função de membro para atualizar as informações de conexão para uma tabela anexada.  
  
```  
void RefreshLink();
```  
  
### <a name="remarks"></a>Comentários  
 Alterar as informações de conexão para uma tabela anexada chamando [SetConnect](#setconnect) em correspondente `CDaoTableDef` objeto e, em seguida, usando o `RefreshLink` a função de membro para atualizar as informações. Quando você chama `RefreshLink`, propriedades da tabela anexada não são alteradas.  
  
 Para forçar o modificado conectar informações entrem em vigor, todos os [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objetos com base nesse tabledef devem ser fechados.  
  
 Para obter informações relacionadas, consulte o tópico "RefreshLink Method" na Ajuda do DAO.  
  
##  <a name="setattributes"></a>  CDaoTableDef::SetAttributes  
 Define um valor que indica uma ou mais características de um `CDaoTableDef` objeto.  
  
```  
void SetAttributes(long lAttributes);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lAttributes*  
 Características da tabela representada pelo `CDaoTableDef` do objeto e pode ser uma soma das constantes:  
  
|Constante|Descrição|  
|--------------|-----------------|  
|`dbAttachExclusive`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a tabela é uma tabela anexada aberta para uso exclusivo.|  
|`dbAttachSavePWD`|Para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet, indica que a ID de usuário e senha para a tabela vinculada são salvos com as informações de conexão.|  
|`dbSystemObject`|Indica que a tabela é uma tabela do sistema fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
|`dbHiddenObject`|Indica que a tabela é uma tabela ocultada fornecida pelo mecanismo de banco de dados Microsoft Jet.|  
  
### <a name="remarks"></a>Comentários  
 Ao definir vários atributos, você pode combiná-los somando as constantes apropriadas usando o operador OR bit a bit. Definindo `dbAttachExclusive` em uma tabela não anexada gera uma exceção. Combinando os valores a seguir também produzir uma exceção:  
  
- **dbAttachExclusive &#124; dbAttachedODBC**  
  
- **dbAttachSavePWD &#124; dbAttachedTable**  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.  
  
##  <a name="setconnect"></a>  CDaoTableDef::SetConnect  
 Para um `CDaoTableDef` objeto que representa uma tabela anexada, o objeto de cadeia de caracteres consiste em uma ou duas partes (um especificador de tipo de banco de dados e um caminho para o banco de dados).  
  
```  
void SetConnect(LPCTSTR lpszConnect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszConnect*  
 Um ponteiro para uma expressão de cadeia de caracteres que especifica parâmetros adicionais passados para ODBC ou drivers ISAM instaláveis.  
  
### <a name="remarks"></a>Comentários  
 O caminho, conforme mostrado na tabela a seguir é o caminho completo para o diretório que contém os arquivos de banco de dados e deve ser precedido pelo identificador de "banco de dados =". Em alguns casos (como com o Microsoft Excel e o Microsoft Jet bancos de dados), um nome de arquivo específico está incluído no argumento de caminho do banco de dados.  
  
> [!NOTE]
>  Não inclua espaços em branco em torno do sinal de igual em instruções de caminho no formato "banco de dados = unidade:\\\path". Isso resultará em uma exceção é lançada e a falha de conexão.  
  
 A tabela a seguir mostra os tipos possíveis de banco de dados e seus correspondentes especificadores de banco de dados e caminhos:  
  
|Tipo de banco de dados|Especificador|Caminho|  
|-------------------|---------------|----------|  
|Banco de dados usando o mecanismo de banco de dados do Jet|"[ `database`];"|" `drive`:\\\ *caminho*\\\ *filename*. MDB"|  
|dBASE III|"dBASE III;"|" `drive`:\\\ *caminho*"|  
|dBASE IV|"dBASE IV;"|" `drive`:\\\ *caminho*"|  
|dBASE 5|"dBASE 5.0;"|" `drive`:\\\ *caminho*"|  
|Paradox 3. x|"Paradox 3. x;"|" `drive`:\\\ *caminho*"|  
|Paradox 4. x|"Paradox 4. x;"|" `drive`:\\\ *caminho*"|  
|Paradox 5. x|"Paradox 5. x;"|" `drive`:\\\ *caminho*"|  
|Excel 3.0|"Excel 3.0";|" `drive`:\\\ *caminho*\\\ *filename*. XLS"|  
|Excel 4.0|"Excel 4.0;"|" `drive`:\\\ *caminho*\\\ *filename*. XLS"|  
|O Excel 5.0 ou o Excel 95|"Excel 5.0;"|" `drive`:\\\ *caminho*\\\ *filename*. XLS"|  
|Excel 97|"Excel 8.0";|" `drive`:\\\ *caminho*\ *filename*. XLS"|  
|Importação de HTML|"HTML"importação;|" `drive`:\\\ *caminho*\ *filename*"|  
|Exportação de HTML|"Exportação de HTML;"|" `drive`:\\\ *caminho*"|  
|Texto|"Texto";|"unidade:\\\path"|  
|ODBC|"ODBC; Banco de dados = `database`; UID = *usuário*; PWD = *senha*; DSN = *datasourcename;* LOGINTIMEOUT = *segundos;*" (Isso pode não ser uma cadeia de caracteres de conexão completa para todos os servidores; ele é apenas um exemplo. É muito importante para não ter espaços entre os parâmetros.)|Nenhum|  
|Exchange|"Exchange;<br /><br /> MAPILEVEL = *folderpath*;<br /><br /> [TABLETYPE = {0 &AMP;#124; 1};]<br /><br /> [Perfil = *perfil*;]<br /><br /> [PWD = *senha*;]<br /><br /> [BANCO DE DADOS = `database`;] "|*"unidade*:\\\ *caminho*\\\ *filename*. MDB"|  
  
> [!NOTE]
>  Não há suporte para Btrieve a partir do DAO 3.5.  
  
 Você deve usar uma barra invertida dupla (\\\\) nas cadeias de conexão. Se você tiver modificado as propriedades de uma conexão existente usando `SetConnect`, você deve chamar subsequentemente [RefreshLink](#refreshlink). Se você estiver inicializando as propriedades de conexão usando `SetConnect`, você precisa não chamada `RefreshLink`, mas primeiro você deve optar por fazer isso, acrescente tabledef.  
  
 Se uma senha é necessária, mas não fornecida, o driver ODBC exibe uma logon caixa de diálogo na primeira vez uma tabela é acessada e novamente se a conexão é fechada e reaberta.  
  
 Você pode definir a cadeia de conexão para um `CDaoTableDef` objeto, fornecendo um argumento de origem para o `Create` função de membro. Você pode verificar a configuração para determinar o tipo, caminho, ID de usuário, senha ou a fonte de dados ODBC do banco de dados. Para obter mais informações, consulte a documentação do driver específico.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
##  <a name="setname"></a>  CDaoTableDef::SetName  
 Chame essa função de membro para definir um nome definido pelo usuário para uma tabela.  
  
```  
void SetName(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszName*  
 Um ponteiro para uma expressão de cadeia de caracteres que especifica um nome para uma tabela.  
  
### <a name="remarks"></a>Comentários  
 O nome deve começar com uma letra e pode conter no máximo 64 caracteres. Ele pode incluir números e sublinhado caracteres, mas não pode incluir espaços ou pontuação.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
##  <a name="setsourcetablename"></a>  CDaoTableDef::SetSourceTableName  
 Chame essa função de membro para especificar o nome de uma tabela anexada ou o nome da tabela base no qual o `CDaoTableDef` objeto baseia-se, como ela existe na fonte original dos dados.  
  
```  
void SetSourceTableName(LPCTSTR lpszSrcTableName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszSrcTableName*  
 Um ponteiro para uma expressão de cadeia de caracteres que especifica um nome de tabela no banco de dados externo. Para uma tabela base, a configuração é uma cadeia de caracteres vazia ("").  
  
### <a name="remarks"></a>Comentários  
 Em seguida, você deve chamar [RefreshLink](#refreshlink). A configuração dessa propriedade é vazia para uma tabela base e leitura/gravação para uma tabela anexada ou um objeto que não é acrescentado a uma coleção.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade SourceTableName" na Ajuda do DAO.  
  
##  <a name="setvalidationrule"></a>  CDaoTableDef::SetValidationRule  
 Chame essa função de membro para definir uma regra de validação para um tabledef.  
  
```  
void SetValidationRule(LPCTSTR lpszValidationRule);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszValidationRule*  
 Um ponteiro para uma expressão de cadeia de caracteres que valida uma operação.  
  
### <a name="remarks"></a>Comentários  
 Regras de validação são usadas em conjunto com as operações de atualização. Se um tabledef contém uma regra de validação, as atualizações para esse tabledef devem corresponder aos predeterminado critérios antes dos dados são alterados. Se a alteração não corresponder aos critérios, uma exceção que contém o texto da [GetValidationText](#getvalidationtext) é exibida.  
  
 Há suporte apenas para bancos de dados que usam o mecanismo de banco de dados Microsoft Jet de validação. A expressão não pode referenciar funções definidas pelo usuário, funções de agregação de domínio, as funções de agregação SQL ou consultas. Uma regra de validação para um `CDaoTableDef` objeto pode se referir a vários campos nesse objeto.  
  
 Por exemplo, para campos chamados *hire_date* e *termination_date*, uma regra de validação pode ser:  
  
 [!code-cpp[NVC_MFCDatabase#34](../../mfc/codesnippet/cpp/cdaotabledef-class_1.cpp)]  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de regra de validação" na Ajuda do DAO.  
  
##  <a name="setvalidationtext"></a>  CDaoTableDef::SetValidationText  
 Chame essa função de membro para definir o texto da exceção de uma regra de validação para um `CDaoTableDef` objeto com uma tabela base subjacente com suporte pelo mecanismo de banco de dados Microsoft Jet.  
  
```  
void SetValidationText(LPCTSTR lpszValidationText);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszValidationText*  
 Um ponteiro para uma expressão de cadeia de caracteres que especifica o texto exibido se inseriu dados é inválido.  
  
### <a name="remarks"></a>Comentários  
 Você não pode definir o texto de validação de uma tabela anexada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade do texto de validação" na Ajuda do DAO.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)
