---
title: Classe CDaoQueryDef | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- QueryDef objects
- CDaoQueryDef class
- queries [Visual Studio], defining
ms.assetid: 9676a4a3-c712-44d4-8c5d-d1cc78288d3a
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 0bf06c68bb7072aa1907e4c730848cca9ff5e7d0
ms.lasthandoff: 02/25/2017

---
# <a name="cdaoquerydef-class"></a>Classe CDaoQueryDef
Representa uma definição de consulta, ou "querydef", normalmente um salvos em um banco de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoQueryDef : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoQueryDef::CDaoQueryDef](#cdaoquerydef)|Constrói uma **CDaoQueryDef** objeto. Em seguida chame **abrir** ou **criar**, dependendo de suas necessidades.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoQueryDef::Append](#append)|Acrescenta querydef à coleção QueryDefs do banco de dados como uma consulta salva.|  
|[CDaoQueryDef::CanUpdate](#canupdate)|Retorna zero se a consulta pode atualizar o banco de dados.|  
|[CDaoQueryDef::Close](#close)|Fecha o objeto querydef. Destrua o objeto C++ quando você terminar com ele.|  
|[CDaoQueryDef::Create](#create)|Cria o objeto subjacente de querydef do DAO. Usar querydef como uma consulta temporária ou chamada **Append** salvá-lo no banco de dados.|  
|[CDaoQueryDef::Execute](#execute)|Executa a consulta definida pelo objeto querydef.|  
|[CDaoQueryDef::GetConnect](#getconnect)|Retorna a cadeia de conexão associada querydef. A cadeia de caracteres de conexão identifica a fonte de dados. (Para SQL passagem consulta; caso contrário, uma cadeia de caracteres vazia.)|  
|[CDaoQueryDef::GetDateCreated](#getdatecreated)|Retorna a data em que a consulta salva foi criada.|  
|[CDaoQueryDef::GetDateLastUpdated](#getdatelastupdated)|Retorna a data que da última atualização consulta salva.|  
|[CDaoQueryDef::GetFieldCount](#getfieldcount)|Retorna o número de campos definidos pelo querydef.|  
|[CDaoQueryDef::GetFieldInfo](#getfieldinfo)|Retorna informações sobre um campo especificado definido na consulta.|  
|[CDaoQueryDef::GetName](#getname)|Retorna o nome de querydef.|  
|[CDaoQueryDef::GetODBCTimeout](#getodbctimeout)|Retorna o valor de tempo limite usado pelo ODBC (para uma consulta ODBC) quando querydef é executada. Isso determina quanto tempo permitir a conclusão da ação da consulta.|  
|[CDaoQueryDef::GetParameterCount](#getparametercount)|Retorna o número de parâmetros definido para a consulta.|  
|[CDaoQueryDef::GetParameterInfo](#getparameterinfo)|Retorna informações sobre um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::GetParamValue](#getparamvalue)|Retorna o valor de um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::GetRecordsAffected](#getrecordsaffected)|Retorna o número de registros afetados por uma consulta de ação.|  
|[CDaoQueryDef::GetReturnsRecords](#getreturnsrecords)|Retorna zero se a consulta definida pela querydef retorna registros.|  
|[CDaoQueryDef::GetSQL](#getsql)|Retorna a cadeia de caracteres SQL que especifica a consulta definida pela querydef.|  
|[CDaoQueryDef::GetType](#gettype)|Retorna o tipo de consulta: excluir, atualizar, acréscimo, criar tabela e assim por diante.|  
|[CDaoQueryDef::IsOpen](#isopen)|Retorna zero se querydef está aberto e pode ser executado.|  
|[CDaoQueryDef::Open](#open)|Abre uma querydef existente armazenado na coleção QueryDefs do banco de dados.|  
|[CDaoQueryDef::SetConnect](#setconnect)|Define a cadeia de conexão para uma consulta de passagem em uma fonte de dados ODBC.|  
|[CDaoQueryDef::SetName](#setname)|Define o nome da consulta salva, substituindo o nome em uso quando querydef foi criado.|  
|[CDaoQueryDef::SetODBCTimeout](#setodbctimeout)|Define o valor de tempo limite usado pelo ODBC (para uma consulta ODBC) quando querydef é executada.|  
|[CDaoQueryDef::SetParamValue](#setparamvalue)|Define o valor de um parâmetro especificado para a consulta.|  
|[CDaoQueryDef::SetReturnsRecords](#setreturnsrecords)|Especifica se querydef retorna registros. Definir esse atributo como **TRUE** só é válida para consultas passagem SQL.|  
|[CDaoQueryDef::SetSQL](#setsql)|Define a cadeia de caracteres SQL que especifica a consulta definida pela querydef.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoQueryDef::m_pDAOQueryDef](#m_pdaoquerydef)|Um ponteiro para a interface OLE para o objeto subjacente de querydef do DAO.|  
|[CDaoQueryDef::m_pDatabase](#m_pdatabase)|Um ponteiro para o `CDaoDatabase` objeto ao qual querydef está associado. Querydef pode ser salvos no banco de dados ou não.|  
  
## <a name="remarks"></a>Comentários  
 Querydef é um objeto de acesso a dados que contém a instrução SQL que descreve uma consulta e suas propriedades, como "Data de criação" e "ODBC Timeout". Você também pode criar objetos temporários querydef sem salvá-los, mas é conveniente — e muito mais eficiente — salvar reutilizado consultas em um banco de dados. A [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto mantém a coleção, chamada coleção QueryDefs, que contém seu querydefs salvo.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO. Em geral, as classes do MFC com base em DAO são mais capacitadas que as classes do MFC com base em ODBC; as classes com base em DAO podem acessar dados, inclusive por meio de drivers ODBC, por meio de seu próprio mecanismo de banco de dados. As classes com base em DAO também dão suporte a operações de linguagem de definição de dados (DDL), como adicionar tabelas por meio de classes, sem a necessidade de chamar diretamente o DAO.  
  
## <a name="usage"></a>Uso  
 Use objetos querydef para trabalhar com uma consulta salva existente ou criar um novo salva a consulta ou temporário:  
  
1.  Em todos os casos, primeiro construa um `CDaoQueryDef` objeto, fornecendo um ponteiro para o [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) do objeto ao qual pertence a consulta.  
  
2.  Em seguida, faça o seguinte, dependendo do que você deseja:  
  
    -   Para usar uma consulta salva existente, chame o objeto querydef [abrir](#open) função de membro, fornecendo o nome da consulta salva.  
  
    -   Para criar uma nova consulta salva, chamar o objeto querydef [criar](#create) função de membro, fornecendo o nome da consulta. Em seguida, chame [Append](#append) para salvar a consulta por acrescentá-lo à coleção QueryDefs do banco de dados. **Criar** coloca querydef no estado aberto, então, depois de chamar **criar** você não chamar **abrir**.  
  
    -   Para criar um querydef temporário, chame **criar**. Passe uma cadeia de caracteres vazia para o nome da consulta. Não chame **Append**.  
  
 Quando você terminar de usar um objeto querydef, chame seu [fechar](#close) membro de função; em seguida, destrua o objeto querydef.  
  
> [!TIP]
>  A maneira mais fácil de criar consultas salvas é criá-los e armazená-los no banco de dados usando o Microsoft Access. Em seguida, você pode abrir e usá-las em seu código do MFC.  
  
## <a name="purposes"></a>Finalidades  
 Você pode usar um objeto querydef para qualquer uma das seguintes finalidades:  
  
-   Para criar um `CDaoRecordset` objeto  
  
-   Para chamar o objeto **Execute** função de membro para executar diretamente uma consulta de ação ou uma consulta de passagem  
  
 Você pode usar um objeto querydef para qualquer tipo de consulta, incluindo select, ação, tabela de referência cruzada, exclusão, atualização, acréscimo, criar tabela, definição de dados, passagem SQL, union e consultas em massa. O tipo de consulta é determinado pelo conteúdo da instrução SQL que você fornecer. Para obter informações sobre tipos de consulta, consulte o **Execute** e [GetType](#gettype) funções de membro. Conjuntos de registros são comumente usados para retornar a linha consultas, geralmente os que usam o **selecione... DE** palavras-chave. **Executar** é mais comumente usado para operações em massa. Para obter mais informações, consulte [Execute](#execute) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
## <a name="querydefs-and-recordsets"></a>QueryDefs e conjuntos de registros  
 Usar um objeto querydef para criar um `CDaoRecordset` do objeto, você normalmente cria ou abre um querydef conforme descrito acima. Então, construir um objeto recordset, passando um ponteiro para o objeto querydef ao chamar [cdaorecordset:: Open](../../mfc/reference/cdaorecordset-class.md#open). Querydef que você passar deve estar no estado aberto. Para obter mais informações, consulte a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Você não pode usar um querydef para criar um conjunto de registros (o uso mais comum para querydef), a menos que ele está em um estado aberto. Colocar querydef em um estado aberto chamando **abrir** ou **criar**.  
  
## <a name="external-databases"></a>Bancos de dados externos  
 Objetos QueryDef são a melhor maneira de usar o dialeto SQL nativo de um mecanismo de banco de dados externo. Por exemplo, você pode criar uma consulta Transact SQL (conforme usado no Microsoft SQL Server) e armazená-lo em um objeto querydef. Quando você precisar usar uma consulta SQL não se baseia no mecanismo de banco de dados Microsoft Jet, você deve fornecer uma cadeia de caracteres de conexão que aponta para a fonte de dados externa. Consultas com cadeias de caracteres de conexão válidas ignoram o mecanismo de banco de dados e passam a consulta diretamente para o servidor de banco de dados externo para processamento.  
  
> [!TIP]
>  A melhor maneira de trabalhar com tabelas ODBC é anexá-los a um Microsoft Jet (. Banco de dados MDB).  
  
 Para obter informações relacionadas, consulte os tópicos "QueryDef objetos", "Coleção QueryDefs" e "CdbDatabase" no SDK do DAO.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDaoQueryDef`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="append"></a>CDaoQueryDef::Append  
 Chame essa função de membro depois de você chamar [criar](#create) para criar um novo objeto querydef.  
  
```  
virtual void Append();
```  
  
### <a name="remarks"></a>Comentários  
 **Acrescente** salva querydef no banco de dados, anexando o objeto à coleção de QueryDefs do banco de dados. Você pode usar querydef como um objeto temporário sem acrescentá-lo, mas se você deseja manter, você deve chamar **Append**.  
  
 Se você tentar anexar um objeto querydef temporária, MFC lança uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).  
  
##  <a name="canupdate"></a>CDaoQueryDef::CanUpdate  
 Chame essa função de membro para determinar se é possível modificar querydef — como alterar seu nome ou uma cadeia de caracteres SQL.  
  
```  
BOOL CanUpdate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se você tem permissão para modificar querydef; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode modificar querydef se:  
  
-   Ele não é baseado em um banco de dados é aberto como somente leitura.  
  
-   Você tem permissões de atualização para o banco de dados.  
  
     Isso depende se você implementou os recursos de segurança. MFC não fornece suporte de segurança. Você deve implementá-lo por conta própria chamando DAO diretamente ou usando o Microsoft Access. Consulte o tópico "Propriedade permissões" na Ajuda do DAO.  
  
##  <a name="cdaoquerydef"></a>CDaoQueryDef::CDaoQueryDef  
 Constrói uma **CDaoQueryDef** objeto.  
  
```  
CDaoQueryDef(CDaoDatabase* pDatabase);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDatabase`  
 Um ponteiro para um aberto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O objeto pode representar uma querydef existente armazenado na coleção QueryDefs do banco de dados, uma nova consulta a ser armazenado na coleção ou uma consulta temporária, não devem ser armazenados. A próxima etapa depende do tipo de querydef:  
  
-   Se o objeto representa uma querydef existente, chame o objeto [abrir](#open) função de membro para inicializá-lo.  
  
-   Se o objeto representa um novo querydef seja salvo, chame o objeto [criar](#create) função de membro. Isso adiciona o objeto à coleção de QueryDefs do banco de dados. Em seguida, chame `CDaoQueryDef` funções de membro para definir os atributos do objeto. Finalmente, chame [Append](#append).  
  
-   Se o objeto representa um querydef temporário (não deve ser salvo no banco de dados), chame **criar**, passando uma cadeia de caracteres vazia para o nome da consulta. Depois de chamar **criar**, inicializar querydef definindo diretamente seus atributos. Não chame **Append**.  
  
 Para definir os atributos de querydef, você pode usar o [SetName](#setname), [SetSQL](#setsql), [SetConnect](#setconnect), [SetODBCTimeout](#setodbctimeout), e [SetReturnsRecords](#setreturnsrecords) funções de membro.  
  
 Quando terminar com o objeto querydef, chame seu [fechar](#close) função de membro. Se você tiver um ponteiro para querydef, use o **excluir** operador para destruir o objeto C++.  
  
##  <a name="close"></a>CDaoQueryDef::Close  
 Quando você terminar de usar o objeto querydef, chame essa função de membro.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Fechar querydef libera o objeto DAO subjacente, mas não destrói o objeto salvo de querydef do DAO ou C++ `CDaoQueryDef` objeto. Isso não é o mesmo que [CDaoDatabase::DeleteQueryDef](../../mfc/reference/cdaodatabase-class.md#deletequerydef), que exclui querydef da coleção QueryDefs do banco de dados no DAO (se não for um querydef temporário).  
  
##  <a name="create"></a>CDaoQueryDef::Create  
 Chame essa função de membro para criar uma nova consulta salva ou uma nova consulta temporária.  
  
```  
virtual void Create(
    LPCTSTR lpszName = NULL,  
    LPCTSTR lpszSQL = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 O nome exclusivo da consulta salva no banco de dados. Para obter detalhes sobre a cadeia de caracteres, consulte o tópico "Método CreateQueryDef" na Ajuda do DAO. Se você aceitar o valor padrão, uma cadeia de caracteres vazia, um querydef temporário é criado. Essa consulta não é salvo na coleção QueryDefs.  
  
 `lpszSQL`  
 A cadeia de caracteres SQL que define a consulta. Se você aceitar o valor padrão de **nulo**, você deve chamar [SetSQL](#setsql) para definir a cadeia de caracteres. Até lá, a consulta é indefinida. No entanto, você pode usar a consulta de indefinido para abrir um conjunto de registros; Consulte comentários para obter detalhes. A instrução SQL deve ser definida antes de acrescentar querydef à coleção QueryDefs.  
  
### <a name="remarks"></a>Comentários  
 Se você passar um nome em `lpszName`, você pode chamar [Append](#append) salvar querydef na coleção QueryDefs do banco de dados. Caso contrário, o objeto é um querydef temporário e não será salvo. Em ambos os casos, querydef está em um estado aberto e você pode usá-la para criar um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) de objeto ou chamar o querydef [Execute](#execute) função de membro.  
  
 Se você não fornecer uma instrução SQL na `lpszSQL`, você não pode executar a consulta com **Execute** , mas você pode usá-lo para criar um conjunto de registros. Nesse caso, o MFC usa instrução de SQL padrão do conjunto de registros.  
  
##  <a name="execute"></a>CDaoQueryDef::Execute  
 Chame essa função de membro para executar a consulta definida pelo objeto querydef.  
  
```  
virtual void Execute(int nOptions = dbFailOnError);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nOptions`  
 Um inteiro que determina as características da consulta. Para obter informações relacionadas, consulte o tópico "Executar o método" na Ajuda do DAO. Você pode usar o operador OR bit a bit ( **|**) para combinar as seguintes constantes para esse argumento:  
  
- **dbDenyWrite** negar a permissão de gravação para outros usuários.  
  
- **dbInconsistent** atualizações inconsistentes.  
  
- **dbConsistent** atualizações consistentes.  
  
- **dbSQLPassThrough** passagem SQL. Faz com que a instrução SQL para ser passado para um banco de dados ODBC para processamento.  
  
- **dbFailOnError** valor padrão. Reverta atualizações se ocorrer um erro e o relatório de erro para o usuário.  
  
- **dbSeeChanges** gerar um erro de tempo de execução, se outro usuário está alterando dados que você está editando.  
  
> [!NOTE]
>  Para obter uma explicação dos termos "inconsistente" e "consistente", consulte o tópico "Executar o método" na Ajuda do DAO.  
  
### <a name="remarks"></a>Comentários  
 Objetos de QueryDef usados para a execução dessa maneira podem representar apenas um dos seguintes tipos de consultas:  
  
-   Consultas de ação  
  
-   Consultas passagem SQL  
  
 **Executar** não funciona para consultas que retornam registros, como consultas select. **Executar** normalmente é usado para consultas de operação em massa, como **atualização**, **inserir**, ou **SELECT INTO**, ou para operações de DDL (linguagem) de definição de dados.  
  
> [!TIP]
>  A melhor maneira de trabalhar com fontes de dados ODBC é anexar tabelas para um Microsoft Jet (. Banco de dados MDB). Para obter mais informações, consulte o tópico "Acessando externo bancos de dados com DAO" na Ajuda do DAO.  
  
 Chamar o [GetRecordsAffected](#getrecordsaffected) a função de membro do objeto querydef para determinar o número de registros afetados pelo mais recente **Execute** chamar. Por exemplo, `GetRecordsAffected` retorna informações sobre o número de registros excluídos, atualizados ou inseridos durante a execução de uma consulta ação. A contagem retornada não refletirá as alterações nas tabelas relacionadas quando cascade atualiza ou exclui estão em vigor.  
  
 Se você incluir **dbInconsistent** e **dbConsistent** ou se você não incluir nenhum, o resultado é o padrão, **dbInconsistent**.  
  
 **Executar** não retorna um conjunto de registros. Usando **Execute** em uma consulta que seleciona registros faz com que o MFC acionar uma exceção do tipo [CDaoException](../../mfc/reference/cdaoexception-class.md).  
  
##  <a name="getconnect"></a>CDaoQueryDef::GetConnect  
 Chame essa função de membro para obter a cadeia de conexão associada à fonte de dados do querydef.  
  
```  
CString GetConnect();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo a cadeia de conexão para querydef.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada somente com fontes de dados ODBC e alguns drivers ISAM. Não é usado com o Microsoft Jet (. Bancos de dados MDB); Nesse caso, `GetConnect` retorna uma cadeia de caracteres vazia. Para obter mais informações, consulte [SetConnect](#setconnect).  
  
> [!TIP]
>  É a melhor maneira de trabalhar com tabelas ODBC de anexá-los para um. Banco de dados MDB. Para obter mais informações, consulte o tópico "Acessando externo bancos de dados com DAO" na Ajuda do DAO.  
  
 Para obter informações sobre cadeias de conexão, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
##  <a name="getdatecreated"></a>CDaoQueryDef::GetDateCreated  
 Chame essa função de membro para obter a data em que o objeto querydef foi criado.  
  
```  
COleDateTime GetDateCreated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora querydef foi criado.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="getdatelastupdated"></a>CDaoQueryDef::GetDateLastUpdated  
 Chamada para essa função de membro para obter a data do objeto querydef foi atualizado pela última vez — quando uma de suas propriedades foram alterada, como seu nome, sua cadeia de caracteres SQL ou sua cadeia de caracteres de conexão.  
  
```  
COleDateTime GetDateLastUpdated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora da última atualização querydef.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="getfieldcount"></a>CDaoQueryDef::GetFieldCount  
 Chame essa função de membro para recuperar o número de campos na consulta.  
  
```  
short GetFieldCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de campos definidos na consulta.  
  
### <a name="remarks"></a>Comentários  
 `GetFieldCount`é útil para percorrer todos os campos em querydef. Para essa finalidade, use `GetFieldCount` em conjunto com [GetFieldInfo](#getfieldinfo).  
  
##  <a name="getfieldinfo"></a>CDaoQueryDef::GetFieldInfo  
 Chame essa função de membro para obter vários tipos de informações sobre um campo definido em querydef.  
  
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
 `nIndex`  
 O índice baseado em zero do campo desejado na coleção de campos do querydef, para a pesquisa por índice.  
  
 `fieldinfo`  
 Uma referência a um `CDaoFieldInfo` objeto que retorna as informações solicitadas.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o campo a ser recuperado. As opções disponíveis são listadas aqui com o que elas causam a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome, tipo, tamanho, atributos  
  
- `AFX_DAO_SECONDARY_INFO`Adição de informações principais: posição Ordinal, necessários, Permitir comprimento Zero, o campo de origem, nome externo, tabela de origem, ordem de agrupamento  
  
- `AFX_DAO_ALL_INFO`Informações principais e secundárias mais: regra de validação do valor padrão, o texto de validação  
  
 `lpszName`  
 Uma cadeia de caracteres que contém o nome do campo desejado, para a pesquisa por nome. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição das informações retornadas em `fieldinfo`, consulte o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem às informações descritivas em `dwInfoOptions` acima. Se você solicitar um nível de informações, você obterá quaisquer níveis anteriores de informações também.  
  
##  <a name="getname"></a>CDaoQueryDef::GetName  
 Chame essa função de membro para recuperar o nome da consulta representado por querydef.  
  
```  
CString GetName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da consulta.  
  
### <a name="remarks"></a>Comentários  
 Nomes de QueryDef são nomes exclusivos definidos pelo usuário. Para obter mais informações sobre nomes de querydef, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
##  <a name="getodbctimeout"></a>CDaoQueryDef::GetODBCTimeout  
 Chame essa função de membro para recuperar o limite de tempo atual antes de uma consulta a uma fonte de dados ODBC expire.  
  
```  
short GetODBCTimeout();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de segundos antes que uma consulta expire.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações sobre esse limite de tempo, consulte o tópico "Propriedade ODBCTimeout" na Ajuda do DAO.  
  
> [!TIP]
>  A melhor maneira de trabalhar com tabelas ODBC é anexá-los a um Microsoft Jet (. Banco de dados MDB). Para obter mais informações, consulte o tópico "Acessando externo bancos de dados com DAO" na Ajuda do DAO.  
  
##  <a name="getparametercount"></a>CDaoQueryDef::GetParameterCount  
 Chame essa função de membro para recuperar o número de parâmetros na consulta salva.  
  
```  
short GetParameterCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de parâmetros definidos na consulta.  
  
### <a name="remarks"></a>Comentários  
 `GetParameterCount`é útil para percorrer todos os parâmetros de querydef. Para essa finalidade, use `GetParameterCount` em conjunto com [GetParameterInfo](#getparameterinfo).  
  
 Para obter informações relacionadas, consulte os tópicos "Parâmetro Object", "Coleção Parameters" e "parâmetros de declaração (SQL)" na Ajuda do DAO.  
  
##  <a name="getparameterinfo"></a>CDaoQueryDef::GetParameterInfo  
 Chame essa função de membro para obter informações sobre um parâmetro definido em querydef.  
  
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
 `nIndex`  
 O índice baseado em zero do parâmetro desejado na coleção de parâmetros do querydef, para a pesquisa por índice.  
  
 `paraminfo`  
 Uma referência a um [CDaoParameterInfo](../../mfc/reference/cdaoparameterinfo-structure.md) objeto que retorna as informações solicitadas.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o parâmetro para recuperar. A opção disponível é listada aqui juntamente com o que faz com que a função retornar:  
  
- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome e tipo  
  
 `lpszName`  
 Uma cadeia de caracteres que contém o nome do parâmetro desejado, para a pesquisa por nome. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição das informações retornadas em `paraminfo`, consulte o [CDaoParameterInfo](../../mfc/reference/cdaoparameterinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem às informações descritivas em `dwInfoOptions` acima.  
  
 Para obter informações relacionadas, consulte o tópico "parâmetros de declaração (SQL)" na Ajuda do DAO.  
  
##  <a name="getparamvalue"></a>CDaoQueryDef::GetParamValue  
 Chame essa função de membro para recuperar o valor atual do parâmetro especificado armazenado na coleção de parâmetros do querydef.  
  
```  
virtual COleVariant GetParamValue(LPCTSTR lpszName);  
virtual COleVariant GetParamValue(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 O nome do parâmetro cujo valor você deseja para a pesquisa por nome.  
  
 `nIndex`  
 O índice baseado em zero do parâmetro na coleção de parâmetros do querydef, para a pesquisa por índice. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Você pode acessar o parâmetro por nome ou por sua posição ordinal na coleção.  
  
 Para obter informações relacionadas, consulte o tópico "parâmetros de declaração (SQL)" na Ajuda do DAO.  
  
##  <a name="getrecordsaffected"></a>CDaoQueryDef::GetRecordsAffected  
 Chame essa função de membro para determinar quantos registros foram afetados pela última chamada de [Execute](#execute).  
  
```  
long GetRecordsAffected();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de registros afetados.  
  
### <a name="remarks"></a>Comentários  
 A contagem retornada não refletirá as alterações nas tabelas relacionadas quando cascade atualiza ou exclui estão em vigor.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade RecordsAffected" na Ajuda do DAO.  
  
##  <a name="getreturnsrecords"></a>CDaoQueryDef::GetReturnsRecords  
 Chame essa função de membro para determinar se querydef é baseada em uma consulta que retorna registros.  
  
```  
BOOL GetReturnsRecords();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se querydef é baseado em uma consulta que retorna registros. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada apenas para consultas passagem SQL. Para obter mais informações sobre consultas SQL, consulte o [Execute](#execute) função de membro. Para obter mais informações sobre como trabalhar com consultas passagem SQL, consulte o [SetReturnsRecords](#setreturnsrecords) função de membro.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade ReturnsRecords" na Ajuda do DAO.  
  
##  <a name="getsql"></a>CDaoQueryDef::GetSQL  
 Chame essa função de membro para recuperar a instrução SQL que define a consulta na qual querydef se baseia.  
  
```  
CString GetSQL();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A instrução SQL que define a consulta na qual querydef se baseia.  
  
### <a name="remarks"></a>Comentários  
 Você então provavelmente analisará a cadeia de caracteres para palavras-chave, os nomes de tabela e assim por diante.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedade SQL", "Comparação de banco de dados do mecanismo de SQL e ANSI SQL do Microsoft Jet" e "Consultando um banco de dados com o SQL em código" na Ajuda do DAO.  
  
##  <a name="gettype"></a>CDaoQueryDef::GetType  
 Chame essa função de membro para determinar o tipo de consulta de querydef.  
  
```  
short GetType();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tipo de consulta definida pelo querydef. Para valores, consulte comentários.  
  
### <a name="remarks"></a>Comentários  
 O tipo de consulta é definido pelo que você especificar na cadeia de caracteres do querydef SQL quando você cria querydef ou chamar um querydef existente [SetSQL](#setsql) função de membro. O tipo de consulta retornado por essa função pode ser um dos seguintes valores:  
  
- **dbQSelect** selecione  
  
- **dbQAction** ação  
  
- **dbQCrosstab** tabela de referência cruzada  
  
- **dbQDelete** excluir  
  
- **dbQUpdate** atualização  
  
- **dbQAppend** Append  
  
- **dbQMakeTable** criar tabela  
  
- **dbQDDL** definição de dados  
  
- **dbQSQLPassThrough** passagem  
  
- **dbQSetOperation** Union  
  
- **dbQSPTBulk** usado com **dbQSQLPassThrough** para especificar uma consulta que não retorna registros.  
  
> [!NOTE]
>  Para criar uma consulta de passagem, não defina o **dbSQLPassThrough** constante. Isso é definido automaticamente pelo mecanismo de banco de dados Microsoft Jet, quando você cria um objeto querydef e defina a cadeia de conexão.  
  
 Para obter informações sobre cadeias de caracteres SQL, consulte [GetSQL](#getsql). Para obter informações sobre tipos de consulta, consulte [Execute](#execute).  
  
##  <a name="isopen"></a>CDaoQueryDef::IsOpen  
 Chame essa função de membro para determinar se o `CDaoQueryDef` objeto está aberto.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CDaoQueryDef` objeto for aberto; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Querydef deve estar no estado aberto antes de usá-lo para chamar [Execute](#execute) ou para criar um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto. Para colocar um querydef em uma chamada de estado aberto ou [criar](#create) (para um novo querydef) ou [abrir](#open) (para uma querydef existente).  
  
##  <a name="m_pdatabase"></a>CDaoQueryDef::m_pDatabase  
 Contém um ponteiro para o [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto associado ao objeto querydef.  
  
### <a name="remarks"></a>Comentários  
 Use esse ponteiro se você precisar acessar diretamente o banco de dados — por exemplo obter ponteiros para outros recordset ou querydef objetos nas coleções do banco de dados.  
  
##  <a name="m_pdaoquerydef"></a>CDaoQueryDef::m_pDAOQueryDef  
 Contém um ponteiro para a interface OLE para o objeto subjacente de querydef do DAO.  
  
### <a name="remarks"></a>Comentários  
 Esse ponteiro é fornecido para a integridade e a consistência com as outras classes. No entanto, porque MFC bastante totalmente encapsula querydefs DAO for improvável que você precisa. Se você usá-lo, faça isso com cuidado — em particular, não altere o valor do ponteiro, a menos que você sabe o que está fazendo.  
  
##  <a name="open"></a>CDaoQueryDef::Open  
 Chame essa função de membro para abrir querydef salvo anteriormente na coleção QueryDefs do banco de dados.  
  
```  
virtual void Open(LPCTSTR lpszName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Uma cadeia de caracteres que contém o nome de querydef salvo para abrir. Você pode usar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).  
  
### <a name="remarks"></a>Comentários  
 Quando querydef for aberta, você pode chamar seu [Execute](#execute) função de membro ou use querydef para criar um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto.  
  
##  <a name="setconnect"></a>CDaoQueryDef::SetConnect  
 Chame essa função de membro para definir a cadeia de caracteres de conexão do objeto.  
  
```  
void SetConnect(LPCTSTR lpszConnect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszConnect`  
 Uma cadeia de caracteres que contém uma cadeia de conexão associado [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A cadeia de caracteres de conexão é usada para passar informações adicionais para ODBC e alguns drivers ISAM conforme necessário. Não é usado para o Microsoft Jet (. Bancos de dados MDB).  
  
> [!TIP]
>  É a melhor maneira de trabalhar com tabelas ODBC de anexá-los para um. Banco de dados MDB.  
  
 Antes de executar um querydef que representa uma consulta de passagem a uma fonte de dados ODBC, defina a cadeia de conexão com `SetConnect` e chamar [SetReturnsRecords](#setreturnsrecords) para especificar se a consulta retorna registros.  
  
 Para obter mais informações sobre a estrutura e exemplos de componentes de cadeia de caracteres de conexão a cadeia de caracteres de conexão, consulte o tópico "Propriedade conectar" na Ajuda do DAO.  
  
##  <a name="setname"></a>CDaoQueryDef::SetName  
 Chame essa função de membro, se você quiser alterar o nome de um querydef não é temporário.  
  
```  
void SetName(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Uma cadeia de caracteres que contém o novo nome de uma consulta nontemporary a ele associada [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Nomes de QueryDef são nomes exclusivos, definidos pelo usuário. Você pode chamar `SetName` antes de querydef objeto é acrescentado à coleção QueryDefs.  
  
##  <a name="setodbctimeout"></a>CDaoQueryDef::SetODBCTimeout  
 Chame essa função de membro para definir o tempo limite antes de uma consulta a uma fonte de dados ODBC expire.  
  
```  
void SetODBCTimeout(short nODBCTimeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nODBCTimeout*  
 O número de segundos antes que uma consulta expire.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro permite que você substitua o número padrão de segundos antes que as operações subsequentes na fonte de dados conectada "tempo limite". Uma operação pode expirar devido a problemas de acesso à rede, tempo de processamento de consulta excessiva e assim por diante. Chame `SetODBCTimeout` antes de executar uma consulta com este querydef se você quiser alterar o valor de tempo limite de consulta. (Como ODBC reutiliza conexões, o valor de tempo limite é o mesmo para todos os clientes a mesma conexão.)  
  
 O valor padrão de tempo limite de consulta é 60 segundos.  
  
##  <a name="setparamvalue"></a>CDaoQueryDef::SetParamValue  
 Chame essa função de membro para definir o valor de um parâmetro em querydef em tempo de execução.  
  
```  
virtual void SetParamValue(
    LPCTSTR lpszName,  
    const COleVariant& varValue);

 
virtual void SetParamValue(
    int nIndex,  
    const COleVariant& varValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 O nome do parâmetro cujo valor você deseja definir.  
  
 `varValue`  
 O valor a ser definido; Consulte comentários.  
  
 `nIndex`  
 A posição ordinal do parâmetro na coleção de parâmetros do querydef. Você pode obter esse valor com chamadas para [GetParameterCount](#getparametercount) e [GetParameterInfo](#getparameterinfo).  
  
### <a name="remarks"></a>Comentários  
 O parâmetro deve já foram estabelecido como parte da cadeia de caracteres do querydef SQL. Você pode acessar o parâmetro por nome ou por sua posição ordinal na coleção.  
  
 Especifique o valor a ser definido como um `COleVariant` objeto. Para obter informações sobre como definir o valor desejado e digite sua `COleVariant` de objeto, consulte a classe [COleVariant](../../mfc/reference/colevariant-class.md).  
  
##  <a name="setreturnsrecords"></a>CDaoQueryDef::SetReturnsRecords  
 Chame essa função de membro como parte do processo de configuração de uma consulta de passagem para um banco de dados externo.  
  
```  
void SetReturnsRecords(BOOL bReturnsRecords);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bReturnsRecords*  
 Passar **TRUE** se a consulta em um banco de dados externo retorna registros; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Nesse caso, você deve criar querydef e defina suas propriedades usando outros `CDaoQueryDef` funções de membro. Para obter uma descrição dos bancos de dados externos, consulte [SetConnect](#setconnect).  
  
##  <a name="setsql"></a>CDaoQueryDef::SetSQL  
 Chame essa função de membro para definir a instrução SQL que executa querydef.  
  
```  
void SetSQL(LPCTSTR lpszSQL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSQL`  
 Uma cadeia de caracteres que contém uma declaração completa de SQL, conveniente para a execução. A sintaxe da cadeia de caracteres depende do DBMS que suas metas de consulta. Para obter uma discussão sobre a sintaxe utilizada no mecanismo de banco de dados Microsoft Jet, consulte o tópico "Criando instruções no código SQL" na Ajuda do DAO.  
  
### <a name="remarks"></a>Comentários  
 Um uso típico de `SetSQL` é a configuração de um objeto querydef para uso em uma consulta de passagem. (Para a sintaxe de consultas passagem SQL no DBMS de destino, consulte a documentação do DBMS).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoException](../../mfc/reference/cdaoexception-class.md)

