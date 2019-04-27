---
title: Classe CDaoRecordset
ms.date: 08/27/2018
f1_keywords:
- CDaoRecordset
- AFXDAO/CDaoRecordset
- AFXDAO/CDaoRecordset::CDaoRecordset
- AFXDAO/CDaoRecordset::AddNew
- AFXDAO/CDaoRecordset::CanAppend
- AFXDAO/CDaoRecordset::CanBookmark
- AFXDAO/CDaoRecordset::CancelUpdate
- AFXDAO/CDaoRecordset::CanRestart
- AFXDAO/CDaoRecordset::CanScroll
- AFXDAO/CDaoRecordset::CanTransact
- AFXDAO/CDaoRecordset::CanUpdate
- AFXDAO/CDaoRecordset::Close
- AFXDAO/CDaoRecordset::Delete
- AFXDAO/CDaoRecordset::DoFieldExchange
- AFXDAO/CDaoRecordset::Edit
- AFXDAO/CDaoRecordset::FillCache
- AFXDAO/CDaoRecordset::Find
- AFXDAO/CDaoRecordset::FindFirst
- AFXDAO/CDaoRecordset::FindLast
- AFXDAO/CDaoRecordset::FindNext
- AFXDAO/CDaoRecordset::FindPrev
- AFXDAO/CDaoRecordset::GetAbsolutePosition
- AFXDAO/CDaoRecordset::GetBookmark
- AFXDAO/CDaoRecordset::GetCacheSize
- AFXDAO/CDaoRecordset::GetCacheStart
- AFXDAO/CDaoRecordset::GetCurrentIndex
- AFXDAO/CDaoRecordset::GetDateCreated
- AFXDAO/CDaoRecordset::GetDateLastUpdated
- AFXDAO/CDaoRecordset::GetDefaultDBName
- AFXDAO/CDaoRecordset::GetDefaultSQL
- AFXDAO/CDaoRecordset::GetEditMode
- AFXDAO/CDaoRecordset::GetFieldCount
- AFXDAO/CDaoRecordset::GetFieldInfo
- AFXDAO/CDaoRecordset::GetFieldValue
- AFXDAO/CDaoRecordset::GetIndexCount
- AFXDAO/CDaoRecordset::GetIndexInfo
- AFXDAO/CDaoRecordset::GetLastModifiedBookmark
- AFXDAO/CDaoRecordset::GetLockingMode
- AFXDAO/CDaoRecordset::GetName
- AFXDAO/CDaoRecordset::GetParamValue
- AFXDAO/CDaoRecordset::GetPercentPosition
- AFXDAO/CDaoRecordset::GetRecordCount
- AFXDAO/CDaoRecordset::GetSQL
- AFXDAO/CDaoRecordset::GetType
- AFXDAO/CDaoRecordset::GetValidationRule
- AFXDAO/CDaoRecordset::GetValidationText
- AFXDAO/CDaoRecordset::IsBOF
- AFXDAO/CDaoRecordset::IsDeleted
- AFXDAO/CDaoRecordset::IsEOF
- AFXDAO/CDaoRecordset::IsFieldDirty
- AFXDAO/CDaoRecordset::IsFieldNull
- AFXDAO/CDaoRecordset::IsFieldNullable
- AFXDAO/CDaoRecordset::IsOpen
- AFXDAO/CDaoRecordset::Move
- AFXDAO/CDaoRecordset::MoveFirst
- AFXDAO/CDaoRecordset::MoveLast
- AFXDAO/CDaoRecordset::MoveNext
- AFXDAO/CDaoRecordset::MovePrev
- AFXDAO/CDaoRecordset::Open
- AFXDAO/CDaoRecordset::Requery
- AFXDAO/CDaoRecordset::Seek
- AFXDAO/CDaoRecordset::SetAbsolutePosition
- AFXDAO/CDaoRecordset::SetBookmark
- AFXDAO/CDaoRecordset::SetCacheSize
- AFXDAO/CDaoRecordset::SetCacheStart
- AFXDAO/CDaoRecordset::SetCurrentIndex
- AFXDAO/CDaoRecordset::SetFieldDirty
- AFXDAO/CDaoRecordset::SetFieldNull
- AFXDAO/CDaoRecordset::SetFieldValue
- AFXDAO/CDaoRecordset::SetFieldValueNull
- AFXDAO/CDaoRecordset::SetLockingMode
- AFXDAO/CDaoRecordset::SetParamValue
- AFXDAO/CDaoRecordset::SetParamValueNull
- AFXDAO/CDaoRecordset::SetPercentPosition
- AFXDAO/CDaoRecordset::Update
- AFXDAO/CDaoRecordset::m_bCheckCacheForDirtyFields
- AFXDAO/CDaoRecordset::m_nFields
- AFXDAO/CDaoRecordset::m_nParams
- AFXDAO/CDaoRecordset::m_pDAORecordset
- AFXDAO/CDaoRecordset::m_pDatabase
- AFXDAO/CDaoRecordset::m_strFilter
- AFXDAO/CDaoRecordset::m_strSort
helpviewer_keywords:
- CDaoRecordset [MFC], CDaoRecordset
- CDaoRecordset [MFC], AddNew
- CDaoRecordset [MFC], CanAppend
- CDaoRecordset [MFC], CanBookmark
- CDaoRecordset [MFC], CancelUpdate
- CDaoRecordset [MFC], CanRestart
- CDaoRecordset [MFC], CanScroll
- CDaoRecordset [MFC], CanTransact
- CDaoRecordset [MFC], CanUpdate
- CDaoRecordset [MFC], Close
- CDaoRecordset [MFC], Delete
- CDaoRecordset [MFC], DoFieldExchange
- CDaoRecordset [MFC], Edit
- CDaoRecordset [MFC], FillCache
- CDaoRecordset [MFC], Find
- CDaoRecordset [MFC], FindFirst
- CDaoRecordset [MFC], FindLast
- CDaoRecordset [MFC], FindNext
- CDaoRecordset [MFC], FindPrev
- CDaoRecordset [MFC], GetAbsolutePosition
- CDaoRecordset [MFC], GetBookmark
- CDaoRecordset [MFC], GetCacheSize
- CDaoRecordset [MFC], GetCacheStart
- CDaoRecordset [MFC], GetCurrentIndex
- CDaoRecordset [MFC], GetDateCreated
- CDaoRecordset [MFC], GetDateLastUpdated
- CDaoRecordset [MFC], GetDefaultDBName
- CDaoRecordset [MFC], GetDefaultSQL
- CDaoRecordset [MFC], GetEditMode
- CDaoRecordset [MFC], GetFieldCount
- CDaoRecordset [MFC], GetFieldInfo
- CDaoRecordset [MFC], GetFieldValue
- CDaoRecordset [MFC], GetIndexCount
- CDaoRecordset [MFC], GetIndexInfo
- CDaoRecordset [MFC], GetLastModifiedBookmark
- CDaoRecordset [MFC], GetLockingMode
- CDaoRecordset [MFC], GetName
- CDaoRecordset [MFC], GetParamValue
- CDaoRecordset [MFC], GetPercentPosition
- CDaoRecordset [MFC], GetRecordCount
- CDaoRecordset [MFC], GetSQL
- CDaoRecordset [MFC], GetType
- CDaoRecordset [MFC], GetValidationRule
- CDaoRecordset [MFC], GetValidationText
- CDaoRecordset [MFC], IsBOF
- CDaoRecordset [MFC], IsDeleted
- CDaoRecordset [MFC], IsEOF
- CDaoRecordset [MFC], IsFieldDirty
- CDaoRecordset [MFC], IsFieldNull
- CDaoRecordset [MFC], IsFieldNullable
- CDaoRecordset [MFC], IsOpen
- CDaoRecordset [MFC], Move
- CDaoRecordset [MFC], MoveFirst
- CDaoRecordset [MFC], MoveLast
- CDaoRecordset [MFC], MoveNext
- CDaoRecordset [MFC], MovePrev
- CDaoRecordset [MFC], Open
- CDaoRecordset [MFC], Requery
- CDaoRecordset [MFC], Seek
- CDaoRecordset [MFC], SetAbsolutePosition
- CDaoRecordset [MFC], SetBookmark
- CDaoRecordset [MFC], SetCacheSize
- CDaoRecordset [MFC], SetCacheStart
- CDaoRecordset [MFC], SetCurrentIndex
- CDaoRecordset [MFC], SetFieldDirty
- CDaoRecordset [MFC], SetFieldNull
- CDaoRecordset [MFC], SetFieldValue
- CDaoRecordset [MFC], SetFieldValueNull
- CDaoRecordset [MFC], SetLockingMode
- CDaoRecordset [MFC], SetParamValue
- CDaoRecordset [MFC], SetParamValueNull
- CDaoRecordset [MFC], SetPercentPosition
- CDaoRecordset [MFC], Update
- CDaoRecordset [MFC], m_bCheckCacheForDirtyFields
- CDaoRecordset [MFC], m_nFields
- CDaoRecordset [MFC], m_nParams
- CDaoRecordset [MFC], m_pDAORecordset
- CDaoRecordset [MFC], m_pDatabase
- CDaoRecordset [MFC], m_strFilter
- CDaoRecordset [MFC], m_strSort
ms.assetid: 2322067f-1027-4662-a5d7-aa2fc7488630
ms.openlocfilehash: 96118645aa656e97fcb93a0fd223045208ab03a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62206353"
---
# <a name="cdaorecordset-class"></a>Classe CDaoRecordset

Representa um conjunto de registros selecionados de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordset::CDaoRecordset](#cdaorecordset)|Constrói um objeto `CDaoRecordset`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordset::AddNew](#addnew)|Prepara para adicionar um novo registro. Chame [atualização](#update) para concluir a adição.|
|[CDaoRecordset::CanAppend](#canappend)|Retorna não zero, se novos registros podem ser adicionados ao conjunto de registros por meio de [AddNew](#addnew) função de membro.|
|[CDaoRecordset::CanBookmark](#canbookmark)|Retorna diferente de zero se o conjunto de registros dá suporte a indicadores.|
|[CDaoRecordset::CancelUpdate](#cancelupdate)|Cancela todas as atualizações pendentes devido a um [edite](#edit) ou [AddNew](#addnew) operação.|
|[CDaoRecordset::CanRestart](#canrestart)|Retorna se diferente de zero [Requery](#requery) pode ser chamado para executar a consulta do conjunto de registros novamente.|
|[CDaoRecordset::CanScroll](#canscroll)|Retorna diferente de zero se você pode percorrer os registros.|
|[CDaoRecordset::CanTransact](#cantransact)|Retorna diferente de zero se a fonte de dados oferece suporte a transações.|
|[CDaoRecordset::CanUpdate](#canupdate)|Retorna não zero se o conjunto de registros pode ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CDaoRecordset::Close](#close)|Fecha o conjunto de registros.|
|[CDaoRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Explicitamente, você deve rolar para outro registro após a exclusão.|
|[CDaoRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados do campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa DAO registra troca de campos (DFX).|
|[CDaoRecordset::Edit](#edit)|Prepara para as alterações no registro atual. Chamar `Update` para concluir a edição.|
|[CDaoRecordset::FillCache](#fillcache)|Preenchimentos todos ou parte de um cache local para um objeto recordset que contém os dados de uma fonte de dados ODBC.|
|[CDaoRecordset::Find](#find)|Localiza o primeiro, próximo, anterior, ou o último local de uma determinada cadeia de caracteres em um conjunto de registros do tipo dynaset que satisfaz os critérios especificados e torna esse registro o registro atual.|
|[CDaoRecordset::FindFirst](#findfirst)|Localiza o primeiro registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que satisfaz os critérios especificados e torna esse registro o registro atual.|
|[CDaoRecordset::FindLast](#findlast)|Localiza o último registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que satisfaz os critérios especificados e torna esse registro o registro atual.|
|[CDaoRecordset::FindNext](#findnext)|Localiza o próximo registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que satisfaz os critérios especificados e torna esse registro o registro atual.|
|[CDaoRecordset::FindPrev](#findprev)|Localiza o registro anterior em um tipo dynaset ou conjunto de registros do tipo de instantâneo que satisfaz os critérios especificados e torna esse registro o registro atual.|
|[CDaoRecordset::GetAbsolutePosition](#getabsoluteposition)|Retorna o número do registro de um conjunto de registros do objeto atual.|
|[CDaoRecordset::GetBookmark](#getbookmark)|Retorna um valor que representa o indicador em um registro.|
|[CDaoRecordset::GetCacheSize](#getcachesize)|Retorna um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenado em cache localmente de uma fonte de dados ODBC.|
|[CDaoRecordset::GetCacheStart](#getcachestart)|Retorna um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::GetCurrentIndex](#getcurrentindex)|Retorna um `CString` contendo o nome do índice mais recentemente usada em um tipo de tabela indexado, `CDaoRecordset`.|
|[CDaoRecordset::GetDateCreated](#getdatecreated)|Retorna a data e hora a tabela base subjacente um `CDaoRecordset` objeto foi criado|
|[CDaoRecordset::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e hora da alteração mais recente feita no design de uma tabela base subjacente um `CDaoRecordset` objeto.|
|[CDaoRecordset::GetDefaultDBName](#getdefaultdbname)|Retorna o nome da fonte de dados padrão.|
|[CDaoRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres SQL padrão para executar.|
|[CDaoRecordset::GetEditMode](#geteditmode)|Retorna um valor que indica o estado de edição para o registro atual.|
|[CDaoRecordset::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos em um conjunto de registros.|
|[CDaoRecordset::GetFieldInfo](#getfieldinfo)|Retorna os tipos específicos de informações sobre os campos no conjunto de registros.|
|[CDaoRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::GetIndexCount](#getindexcount)|Recupera o número de índices em uma tabela subjacente a um conjunto de registros.|
|[CDaoRecordset::GetIndexInfo](#getindexinfo)|Retorna a vários tipos de informações sobre um índice.|
|[CDaoRecordset::GetLastModifiedBookmark](#getlastmodifiedbookmark)|Usado para determinar o mais recentemente adicionado ou atualizavam do registro.|
|[CDaoRecordset::GetLockingMode](#getlockingmode)|Retorna um valor que indica o tipo de bloqueio que entra em vigor durante a edição.|
|[CDaoRecordset::GetName](#getname)|Retorna um `CString` que contém o nome do conjunto de registros.|
|[CDaoRecordset::GetParamValue](#getparamvalue)|Recupera o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.|
|[CDaoRecordset::GetPercentPosition](#getpercentposition)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|
|[CDaoRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros acessados em um objeto recordset.|
|[CDaoRecordset::GetSQL](#getsql)|Obtém a cadeia de caracteres SQL usada para selecionar registros do conjunto de registros.|
|[CDaoRecordset::GetType](#gettype)|Chamado para determinar o tipo de um conjunto de registros: tipo de tabela, tipo dynaset ou tipo de instantâneo.|
|[CDaoRecordset::GetValidationRule](#getvalidationrule)|Retorna um `CString` que contém o valor que valida os dados enquanto ele é inserido em um campo.|
|[CDaoRecordset::GetValidationText](#getvalidationtext)|Recupera o texto que é exibido quando uma regra de validação não for atendida.|
|[CDaoRecordset::IsBOF](#isbof)|Retorna diferente de zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.|
|[CDaoRecordset::IsDeleted](#isdeleted)|Retorna diferente de zero se o conjunto de registros é posicionado em um registro excluído.|
|[CDaoRecordset::IsEOF](#iseof)|Retorna diferente de zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.|
|[CDaoRecordset::IsFieldDirty](#isfielddirty)|Retorna diferente de zero se o campo especificado no registro atual foi alterado.|
|[CDaoRecordset::IsFieldNull](#isfieldnull)|Retorna diferente de zero se o campo especificado no registro atual é nulo (com nenhum valor).|
|[CDaoRecordset::IsFieldNullable](#isfieldnullable)|Retorna diferente de zero se o campo especificado no registro atual pode ser definido como Null (com nenhum valor).|
|[CDaoRecordset::IsOpen](#isopen)|Retorna se diferente de zero [abrir](#open) foi chamado anteriormente.|
|[CDaoRecordset::Move](#move)|Posiciona o conjunto de registros para um número especificado de registros do registro atual em qualquer direção.|
|[CDaoRecordset::MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros.|
|[CDaoRecordset::MoveLast](#movelast)|Posiciona o registro atual no último registro no conjunto de registros.|
|[CDaoRecordset::MoveNext](#movenext)|Posiciona o registro atual no próximo registro no conjunto de registros.|
|[CDaoRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior no conjunto de registros.|
|[CDaoRecordset::Open](#open)|Cria um novo conjunto de registros de uma tabela, dynaset ou instantâneo.|
|[CDaoRecordset::Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|
|[CDaoRecordset::Seek](#seek)|Localiza o registro em um objeto de conjunto de registros do tipo de tabela indexada que satisfaz os critérios especificados para o índice atual e torna esse registro o registro atual.|
|[CDaoRecordset::SetAbsolutePosition](#setabsoluteposition)|Define o número do registro de um conjunto de registros do objeto atual.|
|[CDaoRecordset::SetBookmark](#setbookmark)|Posiciona o conjunto de registros em um registro que contém o indicador especificado.|
|[CDaoRecordset::SetCacheSize](#setcachesize)|Define um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenado em cache localmente de uma fonte de dados ODBC.|
|[CDaoRecordset::SetCacheStart](#setcachestart)|Define um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::SetCurrentIndex](#setcurrentindex)|Chamado para definir um índice em um conjunto de registros do tipo de tabela.|
|[CDaoRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual, conforme tiver sido alterado.|
|[CDaoRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual para Null (com nenhum valor).|
|[CDaoRecordset::SetFieldValue](#setfieldvalue)|Define o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::SetFieldValueNull](#setfieldvaluenull)|Define o valor de um campo em um conjunto de registros como Null. (com nenhum valor).|
|[CDaoRecordset::SetLockingMode](#setlockingmode)|Define um valor que indica o tipo de bloqueio para que entrem em vigor durante a edição.|
|[CDaoRecordset::SetParamValue](#setparamvalue)|Define o valor atual do parâmetro especificado armazenado no objeto subjacente DAOParameter|
|[CDaoRecordset::SetParamValueNull](#setparamvaluenull)|Define o valor atual do parâmetro especificado como Null (com nenhum valor).|
|[CDaoRecordset::SetPercentPosition](#setpercentposition)|Define a posição do registro atual para um local correspondente para uma porcentagem do número total de registros em um conjunto de registros.|
|[CDaoRecordset::Update](#update)|Conclui uma `AddNew` ou `Edit` operação, salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordset::m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields)|Contém um sinalizador que indica se os campos são automaticamente marcados como alterada.|
|[CDaoRecordset::m_nFields](#m_nfields)|Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.|
|[CDaoRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro na classe de conjunto de registros — o número de parâmetros passados com a consulta do conjunto de registros|
|[CDaoRecordset::m_pDAORecordset](#m_pdaorecordset)|Um ponteiro para a interface base do objeto de conjunto de registros do DAO.|
|[CDaoRecordset::m_pDatabase](#m_pdatabase)|Banco de dados de origem para esse conjunto de resultados. Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.|
|[CDaoRecordset::m_strFilter](#m_strfilter)|Contém uma cadeia de caracteres usada para construir um SQL **onde** instrução.|
|[CDaoRecordset::m_strSort](#m_strsort)|Contém uma cadeia de caracteres usada para construir um SQL **ORDER BY** instrução.|

## <a name="remarks"></a>Comentários

Conhecido como "conjuntos de registros," `CDaoRecordset` objetos estão disponíveis nas três seguintes formas:

- Conjuntos de registros do tipo de tabela representam uma tabela base que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados individual.

- Conjuntos de registros do tipo dynaset são o resultado de uma consulta que pode ter registros atualizáveis. Esses conjuntos de registros são um conjunto de registros que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados subjacente ou tabelas. Conjuntos de registros do tipo dynaset podem conter campos de uma ou mais tabelas em um banco de dados.

- Conjuntos de registros do tipo de instantâneo são uma cópia estática de um conjunto de registros que você pode usar para localizar os dados ou gerar relatórios. Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados, mas não podem ser atualizados.

Cada formulário de conjunto de registros representa um conjunto de registros corrigidos no momento em que o conjunto de registros é aberto. Quando você rolar para um registro em um conjunto de registros do tipo de tabela ou um conjunto de registros do tipo dynaset, ela reflete as alterações feitas no registro depois que o conjunto de registros é aberto por outros usuários ou por outros conjuntos de registros em seu aplicativo. (Um conjunto de registros do tipo de instantâneo não pode ser atualizado.) Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de conjunto de registros específicos do aplicativo de `CDaoRecordset`. Em seguida, você pode:

- Percorra os registros.

- Definir um índice e procure registros usando rapidamente [busca](#seek) (apenas conjuntos de registros do tipo de tabela).

- Localizar registros com base em uma comparação de cadeia de caracteres: "<","\<=", "=", "> =", ou ">" (tipo dynaset e conjuntos de registros do tipo de instantâneo).

- Atualizar os registros e especificar um modo de bloqueio (exceto os conjuntos de registros do tipo de instantâneo).

- Filtre o conjunto de registros para restringir quais registros ele seleciona daqueles disponíveis na fonte de dados.

- Classifica o conjunto de registros.

- Parametrize o conjunto de registros para personalizar sua seleção com informações não são conhecidas até o tempo de execução.

Classe `CDaoRecordset` fornece uma interface semelhante da classe `CRecordset`. A principal diferença é que essa classe `CDaoRecordset` acessa dados por meio de uma Data Access Object (DAO) com base em OLE. Classe `CRecordset` acessa o DBMS por meio da conectividade aberta de banco de dados (ODBC) e um driver ODBC desse DBMS.

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de como eles são específicos para o mecanismo de banco de dados Microsoft Jet.

Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de `CDaoRecordset`. Para usar uma classe de conjunto de registros em ambos os casos, abrir um banco de dados e construir um objeto de conjunto de registros, passando ao construtor um ponteiro para sua `CDaoDatabase` objeto. Também é possível construir um `CDaoRecordset` do objeto e permitir que o MFC criar um temporário `CDaoDatabase` objeto para você. Em seguida, chame o conjunto de registros [abrir](#open) função de membro, especificando se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo. Chamar `Open` seleciona dados do banco de dados e recupera o primeiro registro.

Use os membros de dados e funções de membro do objeto para percorrer os registros e operar sobre elas. As operações disponíveis dependem se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo e se ele é atualizável ou somente leitura — isso depende da capacidade do banco de dados ou da conectividade aberta de banco de dados (ODBC) fonte de dados. Para atualizar os registros que podem foram alterados ou adicionados desde o `Open` chamar, chamar o objeto [Requery](#requery) função de membro. Chamar o objeto `Close` membro de função e destruir o objeto quando você terminar com ele.

`CDaoRecordset` usa a troca de campos de registro DAO (DFX) para dar suporte à leitura e atualização dos campos de registro por meio de membros de C++ fortemente tipada do seu `CDaoRecordset` ou `CDaoRecordset`-classe derivada. Você também pode implementar a associação dinâmica de colunas em um banco de dados sem usar o mecanismo DFX usando [GetFieldValue](#getfieldvalue) e [SetFieldValue](#setfieldvalue).

Para obter informações relacionadas, consulte o tópico "Objeto de conjunto de registros" na Ajuda do DAO.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

##  <a name="addnew"></a>  CDaoRecordset::AddNew

Chame essa função de membro para adicionar um novo registro em um conjunto de registros do tipo de tabela ou do tipo dynaset.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Os campos do registro são inicialmente nulos. (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é igual a NULL em C++.) Para concluir a operação, você deve chamar o [atualização](#update) função de membro. `Update` salva as alterações à fonte de dados.

> [!CAUTION]
>  Se você editar um registro e, em seguida, role até outro registro sem chamar `Update`, suas alterações serão perdidas sem aviso.

Se você adiciona um registro a um conjunto de registros do tipo dynaset chamando [AddNew](#addnew), o registro está visível no conjunto de registros e incluído na tabela subjacente em que ele se tornará visível para qualquer novo `CDaoRecordset` objetos.

A posição do novo registro depende do tipo de conjunto de registros:

- Em um tipo de dynaset conjunto de registros, em que o novo registro é inserido não é garantido. Esse comportamento foi alterado com o Microsoft Jet 3.0 por motivos de desempenho e simultaneidade. Se seu objetivo é tornar o registro recém-adicionado do registro atual, obter o indicador do último registro modificado e mova para esse indicador:

[!code-cpp[NVC_MFCDatabase#1](../../mfc/codesnippet/cpp/cdaorecordset-class_1.cpp)]

- Em um conjunto de registros de tipo de tabela para o qual foi especificado um índice, os registros são retornados em seus próprios lugares na ordem de classificação. Se nenhum índice tiver sido especificado, os novos registros são retornados no final do conjunto de registros.

O registro que foi atual antes do uso `AddNew` permaneçam atuais. Se você deseja tornar o novo registro atual e o conjunto de registros dá suporte a indicadores, chamada [SetBookmark](#setbookmark) para o indicador identificado pela configuração da propriedade LastModified do objeto de conjunto de registros DAO subjacente. Isso é útil para determinar o valor para campos de contador (incremento automático) em um registro adicional. Para obter mais informações, consulte [GetLastModifiedBookmark](#getlastmodifiedbookmark).

Se o banco de dados oferece suporte a transações, você pode fazer sua `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte a classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). Observe que você deve chamar [CDaoWorkspace::BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans) antes de chamar `AddNew`.

É ilegal chamar `AddNew` para um conjunto de registros cujo [aberto](#open) função de membro não foi chamada. Um `CDaoException` é lançada se você chamar `AddNew` para um conjunto de registros não pode ser anexado. Você pode determinar se o conjunto de registros é atualizável, chamando [CanAppend](#canappend).

As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados do mecanismo de troca (DFX) DAO campos de registro. Alterando o valor de um campo geralmente define o campo sujas automaticamente, portanto, você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas independentemente de qual valor é no membro de dados de campo. O mecanismo DFX também utiliza o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não está sendo usado, em seguida, alterando o valor do campo não define automaticamente o campo sujo. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

> [!NOTE]
> Se os registros são armazenados em buffer duplo (ou seja, a verificação automática de campo é habilitada), chamando `CancelUpdate` restaurará as variáveis de membro para os valores que tinham antes `AddNew` ou `Edit` foi chamado.

Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Método CancelUpdate", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.

##  <a name="canappend"></a>  CDaoRecordset::CanAppend

Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite a adição de novos registros, chamando o [AddNew](#addnew) função de membro.

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros permite a adição de novos registros; Caso contrário, 0. `CanAppend` retornará 0 se você abriu o conjunto de registros como somente leitura.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Acrescentar o método" na Ajuda do DAO.

##  <a name="canbookmark"></a>  CDaoRecordset::CanBookmark

Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite marcar individualmente usando indicadores de registros.

```
BOOL CanBookmark();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros dá suporte a indicadores, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você estiver usando conjuntos de registros com base inteiramente em tabelas de mecanismo de banco de dados Microsoft Jet, indicadores podem ser usados, exceto em conjuntos de registros do tipo de instantâneo marcados como somente de avanço conjuntos de registros de rolagem. Outros produtos de banco de dados (fontes de dados externas ODBC) podem não dar suporte a indicadores.

Para obter informações relacionadas, consulte o tópico "Propriedade possíveis de indicação" na Ajuda do DAO.

##  <a name="cancelupdate"></a>  CDaoRecordset::CancelUpdate

O `CancelUpdate` função de membro cancela todas as atualizações pendentes devido a um [edite](#edit) ou [AddNew](#addnew) operação.

```
virtual void CancelUpdate();
```

### <a name="remarks"></a>Comentários

Por exemplo, se um aplicativo chama o `Edit` ou `AddNew` função de membro e não tiver chamado [atualização](#update), `CancelUpdate` cancela todas as alterações feitas após `Edit` ou `AddNew` foi chamado.

> [!NOTE]
>  Se os registros são armazenados em buffer duplo (ou seja, a verificação automática de campo é habilitada), chamando `CancelUpdate` restaurará as variáveis de membro para os valores que tinham antes `AddNew` ou `Edit` foi chamado.

Se não houver nenhuma `Edit` ou `AddNew` operação pendente, `CancelUpdate` faz com que o MFC lançar uma exceção. Chame o [GetEditMode](#geteditmode) a função de membro para determinar se há uma operação pendente que pode ser cancelada.

Para obter informações relacionadas, consulte o tópico "Método CancelUpdate" na Ajuda do DAO.

##  <a name="canrestart"></a>  CDaoRecordset::CanRestart

Chame essa função de membro para determinar se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) chamando o `Requery` função de membro.

```
BOOL CanRestart();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se `Requery` pode ser chamado para executar consulta do conjunto de registros novamente, caso contrário, 0.

### <a name="remarks"></a>Comentários

Conjuntos de registros do tipo de tabela não oferecem suporte a `Requery`.

Se `Requery` não é tem suporte, chame [feche](#close) , em seguida, [abrir](#open) para atualizar os dados. Você pode chamar `Requery` atualizar um objeto recordset subjacente do consulta parâmetro depois que os valores de parâmetro foram alterados.

Para obter informações relacionadas, consulte o tópico "Propriedade reiniciáveis" na Ajuda do DAO.

##  <a name="canscroll"></a>  CDaoRecordset::CanScroll

Chame essa função de membro para determinar se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se você pode percorrer os registros, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você chamar [aberto](#open) com `dbForwardOnly`, o conjunto de registros só pode navegar para frente.

Para obter informações relacionadas, consulte o tópico "Posicionando o atual registro ponteiro com DAO" na Ajuda do DAO.

##  <a name="cantransact"></a>  CDaoRecordset::CanTransact

Chame essa função de membro para determinar se o conjunto de registros permite que as transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte de dados subjacente oferece suporte a transações, caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade Transactions" na Ajuda do DAO.

##  <a name="canupdate"></a>  CDaoRecordset::CanUpdate

Chame essa função de membro para determinar se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros pode ser atualizado (Adicionar, atualizar e excluir registros), caso contrário, 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser somente leitura se a fonte de dados subjacente é somente leitura ou se você tiver especificado `dbReadOnly` para *nOptions* quando você chamou [abrir](#open) para o conjunto de registros.

Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.

##  <a name="cdaorecordset"></a>  CDaoRecordset::CDaoRecordset

Constrói um objeto `CDaoRecordset`.

```
CDaoRecordset(CDaoDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDatabase*<br/>
Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto ou o valor NULL. Se não for NULL e o `CDaoDatabase` do objeto `Open` função de membro não tiver sido chamada para conectar-se à fonte de dados, o conjunto de registros tenta abri-lo para você durante a sua própria [abrir](#open) chamar. Se você passar NULL, uma `CDaoDatabase` objeto é construído e conectado para você usando as informações de fonte de dados especificado se você derivado de sua classe de conjunto de registros de `CDaoRecordset`.

### <a name="remarks"></a>Comentários

Você pode usar `CDaoRecordset` diretamente ou derivar uma classe específica do aplicativo de `CDaoRecordset`. Você pode usar o ClassWizard derivar suas classes de conjunto de registros.

> [!NOTE]
>  Se você derivar uma `CDaoRecordset` classe derivada classe deve fornecer seu próprio construtor. No construtor da classe derivada, chame o construtor `CDaoRecordset::CDaoRecordset`, passando os parâmetros apropriados ao longo para ele.

Transmitir NULL para o construtor de conjunto de registros para ter um `CDaoDatabase` objeto construído e conectado automaticamente para você. Esse é um atalho útil que não exige que você construa e conectar-se um `CDaoDatabase` objeto antes de construir o conjunto de registros. Se o `CDaoDatabase` objeto não estiver aberto, uma [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto também será criado para você que usa o espaço de trabalho padrão. Para obter mais informações, consulte [CDaoDatabase::CDaoDatabase](../../mfc/reference/cdaodatabase-class.md#cdaodatabase).

##  <a name="close"></a>  CDaoRecordset::Close

Fechando uma `CDaoRecordset` objeto remove da coleção de conjuntos de registros abertos no banco de dados associado.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Porque `Close` não destrói os `CDaoRecordset` do objeto, você pode reutilizar o objeto chamando `Open` na mesma fonte de dados ou outra fonte de dados.

Todas as pendentes [AddNew](#addnew) ou [editar](#edit) instruções são canceladas e todas as transações pendentes são revertidas. Se você quiser preservar adições ou edições pendentes, chame [atualização](#update) antes de chamar `Close` para cada conjunto de registros.

Você pode chamar `Open` novamente depois de chamar `Close`. Isso lhe permite reutilizar o objeto de conjunto de registros. Uma alternativa melhor é chamar [Requery](#requery), se possível.

Para obter informações relacionadas, consulte o tópico "Método Close" na Ajuda do DAO.

##  <a name="delete"></a>  CDaoRecordset::Delete

Chame essa função de membro para excluir o registro atual em um objeto de conjunto de registros aberto dynaset ou tipo de tabela.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após a exclusão de bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor Null, e você deve chamar explicitamente uma das funções de membro de navegação de conjunto de registros ( [mova](#move), [busca](#seek), [ SetBookmark](#setbookmark)e assim por diante) para deixar de usar o registro excluído. Quando você excluir registros de um conjunto de registros, deve haver um registro atual no conjunto de registros antes de chamar `Delete`; caso contrário, MFC gera uma exceção.

`Delete` Remove o registro atual e torna inacessível. Embora você não pode editar ou usar o registro excluído, ele permanece atual. Quando você move para outro registro, no entanto, você não pode fazer o registro excluído atual novamente.

> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve haver um registro válido atual no conjunto de registros ao chamar `Delete`. Por exemplo, se você excluir um registro, mas não rola para um novo registro antes de chamar `Delete` novamente, `Delete` lança uma [CDaoException](../../mfc/reference/cdaoexception-class.md).

Você pode restaurar um registro, se você usar transações e chamar o [CDaoWorkspace::Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) função de membro. Se a tabela base é a tabela primária em cascata Excluir relação, excluir o registro atual também pode excluir um ou mais registros em uma tabela externa. Para obter mais informações, consulte a definição "em cascata" excluir na Ajuda do DAO.

Diferentemente `AddNew` e `Edit`, uma chamada para `Delete` não é seguido por uma chamada para `Update`.

Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.

##  <a name="dofieldexchange"></a>  CDaoRecordset::DoFieldExchange

O framework chama essa função de membro para automaticamente trocar dados entre os membros de dados do campo de seu objeto de conjunto de registros e as colunas correspondentes do registro atual na fonte de dados.

```
virtual void DoFieldExchange(CDaoFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*pFX*<br/>
Contém um ponteiro para um `CDaoFieldExchange` objeto. A estrutura será já tiver configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Ele também associa os membros de dados de parâmetro, se houver espaços reservados de parâmetros na cadeia de caracteres de instrução SQL para a seleção do conjunto de registros. A troca de dados de campo, chamados de troca de campos de registro DAO (DFX) funciona em ambas as direções: de membros de dados de campo do objeto de conjunto de registros para os campos do registro na fonte de dados e de registro na fonte de dados para o objeto de conjunto de registros. Se você estiver associando colunas dinamicamente, não é necessário para implementar `DoFieldExchange`.

A única ação que você normalmente deve adotar para implementar `DoFieldExchange` para seu conjunto de registros derivado classe é criar a classe com ClassWizard e especificar os tipos de dados e nomes dos membros de dados de campo. Você também pode adicionar código para o que grava ClassWizard para especificar os membros de dados do parâmetro. Se todos os campos são vinculados dinamicamente, essa função será inativa, a menos que você especifique os membros de dados do parâmetro.

Quando você declarar sua classe derivada do conjunto de registros com ClassWizard, o assistente grava uma substituição do `DoFieldExchange` para você, que se parece com o exemplo a seguir:

[!code-cpp[NVC_MFCDatabase#2](../../mfc/codesnippet/cpp/cdaorecordset-class_2.cpp)]

##  <a name="edit"></a>  CDaoRecordset::Edit

Chame essa função de membro para permitir que as alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Depois de chamar o `Edit` função de membro, as alterações feitas aos campos do registro atual são copiados para o buffer de cópia. Depois de fazer as alterações desejadas no registro, chame `Update` para salvar suas alterações. `Edit` salva os valores do conjunto de registros membros de dados. Se você chamar `Edit`, faça alterações, em seguida, chame `Edit` novamente, os valores do registro são restaurados ao que eram antes da primeira `Edit` chamar.

> [!CAUTION]
>  Se você editar um registro e, em seguida, executar qualquer operação que se move para outro registro sem primeiro chamar `Update`, suas alterações serão perdidas sem aviso. Além disso, se você fechar o conjunto de registros ou banco de dados pai, seu registro editado é descartado sem aviso.

Em alguns casos, você talvez queira atualizar uma coluna, tornando a Null (que contém nenhum dado). Para fazer isso, chame `SetFieldNull` com um parâmetro de True para marcar o campo nulo; isso também faz com que a coluna a ser atualizada. Se você quiser que um campo para ser gravado para a fonte de dados, mesmo que seu valor não mudou, chame `SetFieldDirty` com um parâmetro de TRUE. Isso funciona mesmo se o campo tivesse o valor Null.

As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados do mecanismo de troca (DFX) DAO campos de registro. Alterando o valor de um campo geralmente define o campo sujas automaticamente, portanto, você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas independentemente de qual valor é no membro de dados de campo. O mecanismo DFX também utiliza o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não está sendo usado, em seguida, alterando o valor do campo não define automaticamente o campo sujo. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

Quando o objeto recordset pessimista é bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado a partir do momento `Edit` é usado até que a atualização seja concluída. Se o conjunto de registros suporá estiver bloqueado, o registro está bloqueado e em comparação com o registro anterior à edição antes que ele é atualizado no banco de dados. Se o registro foi alterado desde que você chamou `Edit`, o `Update` operação falhará e o MFC gera uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.

> [!NOTE]
>  Bloqueio otimista é sempre usado em formatos de banco de dados externo, como ODBC e ISAM instalável.

O registro atual permanece atual depois de chamar `Edit`. Para chamar `Edit`, deve haver um registro atual. Se não houver nenhum registro atual, ou se o conjunto de registros não faz referência a um tipo de tabela aberto ou objeto de conjunto de registros do tipo dynaset, ocorrerá uma exceção. Chamando `Edit` faz com que um `CDaoException` seja lançada sob as seguintes condições:

- Não há nenhum registro atual.

- O banco de dados ou conjunto de registros é somente leitura.

- Não há campos do registro são atualizáveis.

- O banco de dados ou conjunto de registros foi aberto para uso exclusivo por outro usuário.

- Outro usuário bloqueou a página que contém o registro.

Se a fonte de dados oferece suporte a transações, você pode fazer o `Edit` chamar parte de uma transação. Observe que você deve chamar `CDaoWorkspace::BeginTrans` antes de chamar `Edit` e depois que o conjunto de registros foi aberto. Observe também que a chamada `CDaoWorkspace::CommitTrans` não é um substituto para chamar `Update` para concluir o `Edit` operação. Para obter mais informações sobre transações, consulte a classe `CDaoWorkspace`.

Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.

##  <a name="fillcache"></a>  CDaoRecordset::FillCache

Chame essa função de membro para armazenar em cache um número especificado de registros do conjunto de registros.

```
void FillCache(
    long* pSize = NULL,
    COleVariant* pBookmark = NULL);
```

### <a name="parameters"></a>Parâmetros

*pSize*<br/>
Especifica o número de linhas para preencher o cache. Se você omitir esse parâmetro, o valor é determinado pela configuração da propriedade CacheSize do objeto DAO subjacente.

*pBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) especificando um indicador. O cache é preenchido a partir do registro indicado por esse indicador. Se você omitir esse parâmetro, o cache é preenchido a partir do registro indicado pela propriedade do objeto subjacente DAO CacheStart.

### <a name="remarks"></a>Comentários

Armazenamento em cache melhora o desempenho de um aplicativo que recupera ou busca, dados de um servidor remoto. Um cache é um espaço na memória local que contém os dados buscados mais recentemente do servidor na suposição de que os dados provavelmente serão ser solicitados novamente enquanto o aplicativo está em execução. Quando dados são solicitados, o mecanismo de banco de dados Microsoft Jet verifica o cache para os dados pela primeira vez em vez de buscá-la do servidor, o que leva mais tempo. Usar dados em cache em fontes de dados não-ODBC não surte efeito porque os dados não são salvos no cache.

Em vez de aguardar até que o cache a ser preenchido com registros conforme eles são encontrados, você pode preencher o cache explicitamente a qualquer momento chamando o `FillCache` função de membro. Essa é uma maneira mais rápida para preencher o cache porque `FillCache` busca vários registros ao mesmo tempo, em vez de um de cada vez. Por exemplo, enquanto cada tela cheia de registros está sendo exibida, você pode ter sua chamada do aplicativo `FillCache` para buscar a próxima tela cheia de registros.

Qualquer banco de dados ODBC acessado com objetos de conjunto de registros pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remoto e, em seguida, chame o `SetCacheSize` e `SetCacheStart` funções de membro do conjunto de registros. Se *lSize* e *lBookmark* criar um intervalo que é totalmente ou parcialmente fora do intervalo especificado por `SetCacheSize` e `SetCacheStart`, a parte do conjunto de registros fora desse intervalo é ignorada e não é carregados no cache. Se `FillCache` solicitar mais registros que permanecem na fonte de dados remoto, somente os registros restantes são buscados e nenhuma exceção é lançada.

Registros obtidos do cache não refletem as alterações feitas simultaneamente os dados de origem por outros usuários.

`FillCache` busca somente os registros que ainda não estiver armazenado em cache. Para forçar uma atualização de todos os dados armazenados em cache, chame o `SetCacheSize` função de membro com um *lSize* parâmetro igual a 0, chamada `SetCacheSize` novamente com o *lSize* parâmetro igual ao tamanho do cache foi originalmente solicitada e, em seguida, chamar `FillCache`.

Para obter informações relacionadas, consulte o tópico "FillCache Method" na Ajuda do DAO.

##  <a name="find"></a>  CDaoRecordset::Find

Chame essa função de membro para localizar uma cadeia de caracteres específica em um conjunto de registros do tipo dynaset ou instantâneo usando um operador de comparação.

```
virtual BOOL Find(
    long lFindType,
    LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lFindType*<br/>
Um valor que indica o tipo de operação de localização desejado. Os valores possíveis são:

- AFX_DAO_NEXT localizar o próximo local de uma cadeia de caracteres correspondente.

- AFX_DAO_PREV encontrar o local anterior de uma cadeia de caracteres correspondente.

- AFX_DAO_FIRST localizar o primeiro local de uma cadeia de caracteres correspondente.

- AFX_DAO_LAST localizar o último de uma cadeia de caracteres correspondente.

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro. Por exemplo:

[!code-cpp[NVC_MFCDatabase#3](../../mfc/codesnippet/cpp/cdaorecordset-class_3.cpp)]

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode encontrar o primeiro, próximo, anterior, ou a última ocorrência da cadeia de caracteres. `Find` é uma função virtual, portanto, você pode substituí-la e adicionar sua própria implementação. O `FindFirst`, `FindLast`, `FindNext`, e `FindPrev` funções membro chamam o `Find` função de membro, para que você possa usar `Find` para controlar o comportamento de todas as operações de localizar.

Para localizar um registro em um conjunto de registros do tipo de tabela, chame o [busca](#seek) função de membro.

> [!TIP]
>  Quanto menor o conjunto de registros tiver, mais eficazes `Find` será. Em geral e especialmente com dados ODBC, é melhor criar uma nova consulta que recupera apenas os registros que deseja.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.

##  <a name="findfirst"></a>  CDaoRecordset::FindFirst

Chame essa função de membro para localizar o primeiro registro que corresponde a uma condição especificada.

```
BOOL FindFirst(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

O `FindFirst` função de membro começa sua pesquisa desde o início do conjunto de registros e pesquisas ao final do conjunto de registros.

Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.

Se um registro que correspondem aos critérios não for localizado, o ponteiro de registro atual é indeterminado, e `FindFirst` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o `Update` antes de passar para outro registro de função de membro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.

O `Find` funções de membro de pesquisa do local e na direção especificada na tabela a seguir:

|As operações de localização|começar|Direção de pesquisa|
|---------------------|-----------|----------------------|
|`FindFirst`|Início do conjunto de registros|Fim do conjunto de registros|
|`FindLast`|Fim do conjunto de registros|Início do conjunto de registros|
|`FindNext`|Registro atual|Fim do conjunto de registros|
|`FindPrevious`|Registro atual|Início do conjunto de registros|

> [!NOTE]
>  Quando você chama `FindLast`, o mecanismo de banco de dados Microsoft Jet preenche totalmente seu conjunto de registros antes de iniciar a pesquisa, se isso já não foi feito. A primeira pesquisa pode levar mais de pesquisas subsequentes.

Usando uma das operações de localização não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode seguir uma operação de localização com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações de localização:

- Se `Find` retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro de registro atual para um registro válido.

- É possível usar uma operação de localização com um recordset do tipo de instantâneo de rolagem somente de encaminhamento.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.

- Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou `CDaoQuerydef` objetos que recuperam registros específicos indexados.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.

##  <a name="findlast"></a>  CDaoRecordset::FindLast

Chame essa função de membro para localizar o último registro que corresponde a uma condição especificada.

```
BOOL FindLast(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

O `FindLast` função de membro começa sua pesquisa no final do conjunto de registros e pesquisas com versões anteriores em direção ao início do conjunto de registros.

Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.

Se um registro que correspondem aos critérios não for localizado, o ponteiro de registro atual é indeterminado, e `FindLast` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência após a primeira ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o `Update` antes de passar para outro registro de função de membro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.

Usando uma das operações de localização não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode seguir uma operação de localização com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações de localização:

- Se `Find` retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro de registro atual para um registro válido.

- É possível usar uma operação de localização com um recordset do tipo de instantâneo de rolagem somente de encaminhamento.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.

- Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou `CDaoQuerydef` objetos que recuperam registros específicos indexados.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.

##  <a name="findnext"></a>  CDaoRecordset::FindNext

Chame essa função de membro para localizar o próximo registro que corresponde a uma condição especificada.

```
BOOL FindNext(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

O `FindNext` procura até o final do conjunto de registros e começa a sua pesquisa no registro atual de função de membro.

Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.

Se um registro que correspondem aos critérios não for localizado, o ponteiro de registro atual é indeterminado, e `FindNext` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o `Update` antes de passar para outro registro de função de membro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.

Usando uma das operações de localização não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode seguir uma operação de localização com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações de localização:

- Se `Find` retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro de registro atual para um registro válido.

- É possível usar uma operação de localização com um recordset do tipo de instantâneo de rolagem somente de encaminhamento.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.

- Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou `CDaoQuerydef` objetos que recuperam registros específicos indexados.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.

##  <a name="findprev"></a>  CDaoRecordset::FindPrev

Chame essa função de membro para localizar o registro anterior que corresponde a uma condição especificada.

```
BOOL FindPrev(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

O `FindPrev` função membro começa sua pesquisa no registro atual e a pesquisa para trás em direção ao início do conjunto de registros.

Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.

Se um registro que correspondem aos critérios não for localizado, o ponteiro de registro atual é indeterminado, e `FindPrev` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o `Update` antes de passar para outro registro de função de membro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.

Usando uma das operações de localização não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode seguir uma operação de localização com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações de localização:

- Se `Find` retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro de registro atual para um registro válido.

- É possível usar uma operação de localização com um recordset do tipo de instantâneo de rolagem somente de encaminhamento.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.

- Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou `CDaoQuerydef` objetos que recuperam registros específicos indexados.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.

##  <a name="getabsoluteposition"></a>  CDaoRecordset::GetAbsolutePosition

Retorna o número do registro de um conjunto de registros do objeto atual.

```
long GetAbsolutePosition();
```

### <a name="return-value"></a>Valor de retorno

Um inteiro de 0 ao número de registros no conjunto de registros. Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Você pode determinar o número de registros preenchidos no conjunto de registros chamando [GetRecordCount](#getrecordcount). Chamar `GetRecordCount` pode levar algum tempo, pois ele precisar acessar todos os registros para determinar a contagem.

Se não há nenhum registro atual, como quando não há registros no conjunto de registros, - 1 será retornado. Se o registro atual é excluído, o valor da propriedade AbsolutePosition não está definido, e MFC gera uma exceção se ela for referenciada. Para conjuntos de registros do tipo dynaset, novos registros são adicionados ao final da sequência.

> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro de substituto. Indicadores ainda são a maneira recomendada de reter e retornar para uma determinada posição e a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros. Em particular, a posição de um determinado registro é alterado quando o registro (s) precede é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado novamente porque a ordem dos registros individuais dentro de um conjunto de registros não é garantida, a menos que ele é criado com uma instrução SQL usando um  **ORDERBY** cláusula.

> [!NOTE]
>  Essa função de membro é válida somente para o tipo de dynaset e conjuntos de registros do tipo de instantâneo.

Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.

##  <a name="getbookmark"></a>  CDaoRecordset::GetBookmark

Chame essa função de membro para obter o valor do indicador em um determinado registro.

```
COleVariant GetBookmark();
```

### <a name="return-value"></a>Valor de retorno

Retorna um valor que representa o indicador no registro atual.

### <a name="remarks"></a>Comentários

Quando um objeto recordset é criado ou aberto, cada um dos seus registros já tem um indicador exclusivo se ele dá suporte a eles. Chamar `CanBookmark` para determinar se um conjunto de registros oferece suporte a indicadores.

Você pode salvar o indicador para o registro atual atribuindo o valor do indicador a um `COleVariant` objeto. Para retornar rapidamente a esse registro a qualquer momento após a mudança para um registro diferente, chame `SetBookmark` com um parâmetro que corresponde ao valor do que `COleVariant` objeto.

> [!NOTE]
>  Chamando [Requery](#requery) altera os indicadores DAO.

Para obter informações relacionadas, consulte o tópico "Propriedade Bookmark" na Ajuda do DAO.

##  <a name="getcachesize"></a>  CDaoRecordset::GetCacheSize

Chame essa função de membro para obter o número de registros armazenado em cache.

```
long GetCacheSize();
```

### <a name="return-value"></a>Valor de retorno

Um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenado em cache localmente de uma fonte de dados ODBC.

### <a name="remarks"></a>Comentários

Cache de dados melhoram o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Um cache é um espaço na memória local que contém os dados recentemente recuperados do servidor que os dados serão solicitados novamente enquanto o aplicativo está em execução. Quando dados são solicitados, o mecanismo de banco de dados Microsoft Jet verifica o cache para os dados solicitados pela primeira vez em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.

##  <a name="getcachestart"></a>  CDaoRecordset::GetCacheStart

Chame essa função de membro para obter o valor de indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
COleVariant GetCacheStart();
```

### <a name="return-value"></a>Valor de retorno

Um `COleVariant` que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

O mecanismo de banco de dados Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.

> [!NOTE]
>  Registros recuperados do cache não refletem as alterações feitas simultaneamente os dados de origem por outros usuários.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.

##  <a name="getcurrentindex"></a>  CDaoRecordset::GetCurrentIndex

Chame essa função de membro para determinar o índice atualmente em uso em um tipo de tabela indexado `CDaoRecordset` objeto.

```
CString GetCurrentIndex();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o nome do índice atualmente em uso com um conjunto de registros do tipo de tabela. Retorna uma cadeia de caracteres vazia se nenhum índice foi definido.

### <a name="remarks"></a>Comentários

Esse índice é a base para ordenar registros em um conjunto de registros do tipo de tabela e é usado pelas [busca](#seek) função de membro para localizar registros.

Um `CDaoRecordset` objeto pode ter mais de um índice, mas pode usar apenas um índice por vez (embora um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto pode ter vários índices definidos).

Para obter informações relacionadas, consulte o tópico "Objeto de índice" e a definição de "índice atual" na Ajuda do DAO.

##  <a name="getdatecreated"></a>  CDaoRecordset::GetDateCreated

Chame essa função de membro para recuperar a data e hora de que criação de uma tabela base.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor de retorno

Um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora de criação da tabela base.

### <a name="remarks"></a>Comentários

Configurações de data e hora são derivadas do computador no qual a tabela base foi criada.

Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

##  <a name="getdatelastupdated"></a>  CDaoRecordset::GetDateLastUpdated

Chame essa função de membro para recuperar a data e hora que o esquema foi atualizado pela última vez.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor de retorno

Um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora da última atualização da estrutura da tabela base (esquema).

### <a name="remarks"></a>Comentários

Configurações de data e hora são derivadas do computador em que a estrutura da tabela base (esquema) foi atualizada pela última vez.

Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.

##  <a name="getdefaultdbname"></a>  CDaoRecordset::GetDefaultDBName

Chame essa função de membro para determinar o nome do banco de dados para este conjunto de registros.

```
virtual CString GetDefaultDBName();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o caminho e nome do banco de dados do qual este conjunto de registros é derivado.

### <a name="remarks"></a>Comentários

Se um conjunto de registros for criado sem um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md), em seguida, esse caminho é usado pelo conjunto de registros para abrir o banco de dados padrão. Por padrão, essa função retorna uma cadeia de caracteres vazia. Quando o ClassWizard deriva um novo conjunto de registros de `CDaoRecordset`, ele criará essa função para você.

O exemplo a seguir ilustra o uso das duas barras invertidas (\\\\) na cadeia de caracteres, assim como é necessário para a cadeia de caracteres sejam interpretados corretamente.

[!code-cpp[NVC_MFCDatabase#4](../../mfc/codesnippet/cpp/cdaorecordset-class_4.cpp)]

##  <a name="getdefaultsql"></a>  CDaoRecordset::GetDefaultSQL

O framework chama essa função de membro para obter a instrução de SQL padrão no qual o conjunto de registros é baseado.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém a instrução SQL padrão.

### <a name="remarks"></a>Comentários

Isso pode ser um nome de tabela ou um SQL **selecionar** instrução.

Definir, indiretamente, a instrução SQL padrão, declarando a sua classe de conjunto de registros com ClassWizard e ClassWizard realiza essa tarefa para você.

Se você passar uma cadeia de caracteres SQL null para [abrir](#open), em seguida, essa função é chamada para determinar o nome da tabela ou o SQL para seu conjunto de registros.

##  <a name="geteditmode"></a>  CDaoRecordset::GetEditMode

Chame essa função de membro para determinar o estado de edição, que é um dos seguintes valores:

```
short GetEditMode();
```

### <a name="return-value"></a>Valor de retorno

Retorna um valor que indica o estado de edição para o registro atual.

### <a name="remarks"></a>Comentários

|Valor|Descrição|
|-----------|-----------------|
|`dbEditNone`|Nenhuma operação de edição está em andamento.|
|`dbEditInProgress`|O `Edit` foi chamado.|
|`dbEditAdd`|O `AddNew` foi chamado.|

Para obter informações relacionadas, consulte o tópico "Propriedade EditMode" na Ajuda do DAO.

##  <a name="getfieldcount"></a>  CDaoRecordset::GetFieldCount

Chame essa função de membro para recuperar o número de campos (colunas) definidas no conjunto de registros.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor de retorno

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade Count" na Ajuda do DAO.

##  <a name="getfieldinfo"></a>  CDaoRecordset::GetFieldInfo

Chame essa função de membro para obter informações sobre os campos em um conjunto de registros.

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
O índice baseado em zero do campo predefinido na coleção de campos do conjunto de registros, para a pesquisa por índice.

*fieldinfo*<br/>
Uma referência a um [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros a serem recuperados. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retorne. Para obter melhor desempenho, recupere apenas o nível de informações que você precisa:

- `AFX_DAO_PRIMARY_INFO` (Padrão) Nome, tipo, tamanho, atributos

- `AFX_DAO_SECONDARY_INFO` Informações principais, além de: Posição ordinal, obrigatória, permitir que o comprimento Zero, ordem de agrupamento, nome externa, campo de fonte de tabela de origem

- `AFX_DAO_ALL_INFO` Informações de primárias e secundárias, além de: Texto de validação de valor, a regra de validação padrão

*lpszName*<br/>
O nome do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um campo por índice. A outra versão permite pesquisar um campo por nome.

Para obter uma descrição das informações retornadas, consulte o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Quando você solicita informações em um nível, você pode obter informações de todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.

##  <a name="getfieldvalue"></a>  CDaoRecordset::GetFieldValue

Chame essa função de membro para recuperar dados em um conjunto de registros.

```
virtual void GetFieldValue(
    LPCTSTR lpszName,
    COleVariant& varValue);

virtual void GetFieldValue(
    int nIndex,
    COleVariant& varValue);

virtual COleVariant GetFieldValue(LPCTSTR lpszName);
virtual COleVariant GetFieldValue(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.

*varValue*<br/>
Uma referência a um `COleVariant` objeto que armazenará o valor de um campo.

*nIndex*<br/>
Um índice baseado em zero do campo na coleção de campos do conjunto de registros, para a pesquisa por índice.

### <a name="return-value"></a>Valor de retorno

As duas versões do `GetFieldValue` que retornam um valor de retorno um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor de um campo.

### <a name="remarks"></a>Comentários

Você pode pesquisar um campo por nome ou posição ordinal.

> [!NOTE]
>  É mais eficiente para chamada de uma das versões desta função de membro que usa um `COleVariant` referência de objeto como um parâmetro, em vez de chamar uma versão que retorna um `COleVariant` objeto. As versões mais recentes dessa função são mantidos para compatibilidade com versões anteriores.

Use `GetFieldValue` e [SetFieldValue](#setfieldvalue) vincular dinamicamente os campos no tempo de execução em vez de estaticamente colunas de associação usando a [DoFieldExchange](#dofieldexchange) mecanismo.

`GetFieldValue` e o `DoFieldExchange` mecanismo pode ser combinado para melhorar o desempenho. Por exemplo, use `GetFieldValue` para recuperar um valor que você precisa apenas sob demanda e atribuir essa chamada para um botão "Obter mais informações" na interface.

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Valor de propriedade" na Ajuda do DAO.

##  <a name="getindexcount"></a>  CDaoRecordset::GetIndexCount

Chame essa função de membro para determinar o número de índices disponíveis no conjunto de registros do tipo de tabela.

```
short GetIndexCount();
```

### <a name="return-value"></a>Valor de retorno

O número de índices no conjunto de registros do tipo de tabela.

### <a name="remarks"></a>Comentários

`GetIndexCount` é útil para executar um loop por meio de todos os índices no conjunto de registros. Para essa finalidade, use `GetIndexCount` em conjunto com [GetIndexInfo](#getindexinfo). Se você chamar essa função membro no tipo dynaset ou conjuntos de registros do tipo de instantâneo, o MFC gera uma exceção.

Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.

##  <a name="getindexinfo"></a>  CDaoRecordset::GetIndexInfo

Chame essa função de membro para obter vários tipos de informações sobre um índice definido na tabela base subjacente a um conjunto de registros.

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
O índice baseado em zero na coleção de índices da tabela, para a pesquisa por posição numérica.

*indexinfo*<br/>
Uma referência a um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura.

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis são listadas aqui, juntamente com o que eles fazem com que a função retorne. Para obter melhor desempenho, recupere apenas o nível de informações que você precisa:

- `AFX_DAO_PRIMARY_INFO` (Padrão) Campos de nome, informações de campo

- `AFX_DAO_SECONDARY_INFO` Informações principais, além de: Primário, clusterizado, exclusivo, ignorar, obrigatório, externo

- `AFX_DAO_ALL_INFO` Informações de primárias e secundárias, além de: Contagem distinta

*lpszName*<br/>
Um ponteiro para o nome do objeto index, para a pesquisa por nome.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.

Para obter uma descrição das informações retornadas, consulte o [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição da *dwInfoOptions*. Quando você solicita informações em um nível, você pode obter informações de todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Propriedade Attributes" na Ajuda do DAO.

##  <a name="getlastmodifiedbookmark"></a>  CDaoRecordset::GetLastModifiedBookmark

Chame essa função de membro para recuperar o indicador do registro mais recentemente adicionado ou atualizado.

```
COleVariant GetLastModifiedBookmark();
```

### <a name="return-value"></a>Valor de retorno

Um `COleVariant` que contém um indicador que indica mais recentemente adicionado ou alterado o registro.

### <a name="remarks"></a>Comentários

Quando um objeto recordset é criado ou aberto, cada um dos seus registros já tem um indicador exclusivo se ele dá suporte a eles. Chame [GetBookmark](#getbookmark) para determinar se o conjunto de registros dá suporte a indicadores. Se o conjunto de registros não dá suporte a indicadores, um `CDaoException` é gerada.

Quando você adiciona um registro, ele aparece no final do conjunto de registros e não é o registro atual. Para tornar o novo registro atual, chame `GetLastModifiedBookmark` e, em seguida, chame `SetBookmark` para retornar para o registro recém-adicionado.

Para obter informações relacionadas, consulte o tópico "Propriedade LastModified" na Ajuda do DAO.

##  <a name="getlockingmode"></a>  CDaoRecordset::GetLockingMode

Chame essa função de membro para determinar o tipo de bloqueio em vigor para o conjunto de registros.

```
BOOL GetLockingMode();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o tipo de bloqueio é pessimista, caso contrário, 0 para o bloqueio otimista registro.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista está em vigor, a página de dados que contém o registro que você está editando é bloqueado assim que você chame o [editar](#edit) função de membro. A página é desbloqueada quando você chama o [atualização](#update) ou [fechar](#close) função de membro ou qualquer uma das operações de movimentação ou localizar.

Quando otimista proteção está em vigor, a página de dados que contém o registro é bloqueada somente enquanto o registro está sendo atualizado com o `Update` função de membro.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

Para obter informações relacionadas, consulte os tópicos "Propriedade LockEdits" e "Comportamento de bloqueio no multiusuário aplicativos" na Ajuda do DAO.

##  <a name="getname"></a>  CDaoRecordset::GetName

Chame essa função de membro para recuperar o nome do conjunto de registros.

```
CString GetName();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o nome do conjunto de registros.

### <a name="remarks"></a>Comentários

O nome do conjunto de registros deve começar com uma letra e pode conter no máximo 40 caracteres. Ele pode incluir números e sublinhado caracteres, mas não pode incluir espaços ou pontuação.

Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

##  <a name="getparamvalue"></a>  CDaoRecordset::GetParamValue

Chame essa função de membro para recuperar o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.

```
virtual COleVariant GetParamValue(int nIndex);
virtual COleVariant GetParamValue(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
A posição numérica do parâmetro no objeto DAOParameter subjacente.

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja.

### <a name="return-value"></a>Valor de retorno

Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.

### <a name="remarks"></a>Comentários

Você pode acessar o parâmetro por nome ou por sua posição numérica na coleção.

Para obter informações relacionadas, consulte o tópico "Parâmetro de objeto" na Ajuda do DAO.

##  <a name="getpercentposition"></a>  CDaoRecordset::GetPercentPosition

Ao trabalhar com um tipo dynaset ou conjunto de registros do tipo de instantâneo, se você chamar `GetPercentPosition` antes de preencher completamente o conjunto de registros, a quantidade de movimentação é em relação ao número de registros acessado conforme indicado pela chamada [GetRecordCount](#getrecordcount).

```
float GetPercentPosition();
```

### <a name="return-value"></a>Valor de retorno

Um número entre 0 e 100 que indica a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.

### <a name="remarks"></a>Comentários

Você pode mover para o último registro chamando [MoveLast](#movelast) para completa a população de todos os conjuntos de registros, mas isso pode levar uma quantidade significativa de tempo.

Você pode chamar `GetPercentPosition` em todos os três tipos de objetos de conjunto de registros, incluindo as tabelas sem índices. No entanto, você não pode chamar `GetPercentPosition` em instantâneos de rolagem de somente avanço, ou em um conjunto de registros aberto a partir de uma consulta de passagem em um banco de dados externo. Se não há nenhum registro atual ou o registro atual do he tiver sido excluído, um `CDaoException` é gerada.

Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.

##  <a name="getrecordcount"></a>  CDaoRecordset::GetRecordCount

Chame essa função de membro para descobrir o número de registros em um conjunto de registros que tenha sido acessado.

```
long GetRecordCount();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de registros acessados em um objeto recordset.

### <a name="remarks"></a>Comentários

`GetRecordCount` não indica quantos registros estão contido em um tipo dynaset ou conjunto de registros do tipo de instantâneo, até que todos os registros que tenham sido acessados. Essa chamada de função de membro pode levar uma quantidade significativa de tempo para ser concluída.

Depois que o último registro tiver sido acessado, o valor de retorno indica o número total de registros com exclusão desfeita no conjunto de registros. Para forçar o último registro a ser acessado, chame o `MoveLast` ou `FindLast` a função de membro do conjunto de registros. Você também pode usar uma contagem de SQL para determinar o número aproximado de registros de que sua consulta retornará.

Como seu aplicativo exclui registros em um conjunto de registros do tipo dynaset, o valor de retorno `GetRecordCount` diminui. No entanto, os registros excluídos por outros usuários não serão refletidos por `GetRecordCount` até que o registro atual é posicionado em um registro excluído. Se você executar uma transação que afeta a contagem de registros e, subsequentemente, reverta a transação, `GetRecordCount` não refletirá o número real de registros restantes.

O valor de `GetRecordCount` de um conjunto de registros do tipo de instantâneo não é afetado por alterações nas tabelas subjacentes.

O valor de `GetRecordCount` de um tipo de tabela, o conjunto de registros reflete o número aproximado de registros na tabela e é afetado imediatamente conforme os registros da tabela são adicionados e excluídos.

Um conjunto de registros sem registros retorna um valor de 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retorna - 1. Chamar o `Requery` função de membro em um conjunto de registros redefine o valor de `GetRecordCount` como se a consulta fosse executada novamente.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na Ajuda do DAO.

##  <a name="getsql"></a>  CDaoRecordset::GetSQL

Chame essa função de membro para obter a instrução SQL que foi usada para selecionar registros do conjunto de registros quando ele foi aberto.

```
CString GetSQL() const;
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém a instrução SQL.

### <a name="remarks"></a>Comentários

Isso geralmente será um SQL **selecionar** instrução.

A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você pode já ter passado para o conjunto de registros na *lpszSQL* parâmetro para o [abrir](#open) função de membro. Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no passado para `Open`, o que você especificou com ClassWizard e o que você pode ter especificado nos [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) membros de dados.

> [!NOTE]
>  Chame essa função de membro somente depois de chamar `Open`.

Para obter informações relacionadas, consulte o tópico "Propriedade SQL" na Ajuda do DAO.

##  <a name="gettype"></a>  CDaoRecordset::GetType

Chame essa função de membro depois de abrir o conjunto de registros para determinar o tipo do objeto recordset.

```
short GetType();
```

### <a name="return-value"></a>Valor de retorno

Um dos valores a seguir que indica o tipo de um conjunto de registros:

- `dbOpenTable` Conjunto de registros do tipo de tabela

- `dbOpenDynaset` Conjunto de registros do tipo dynaset

- `dbOpenSnapshot` Conjunto de registros do tipo de instantâneo

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.

##  <a name="getvalidationrule"></a>  CDaoRecordset::GetValidationRule

Chame essa função de membro para determinar a regra usada para validar os dados.

```
CString GetValidationRule();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` objeto que contém um valor que valida os dados em um registro, conforme ele é alterado ou adicionado a uma tabela.

### <a name="remarks"></a>Comentários

Essa regra é baseado em texto e é aplicada sempre que a tabela subjacente é alterada. Se os dados não são válidos, o MFC gera uma exceção. A mensagem de erro retornado é o texto da propriedade de texto de validação do campo objeto subjacente, se especificado, ou o texto da expressão especificada pela propriedade de regra de validação do objeto subjacente do campo. Você pode chamar [GetValidationText](#getvalidationtext) para obter o texto da mensagem de erro.

Por exemplo, um campo em um registro que exige o dia do mês pode ter uma regra de validação, como "dia entre 1 e 31."

Para obter informações relacionadas, consulte o tópico "Propriedade de regra de validação" na Ajuda do DAO.

##  <a name="getvalidationtext"></a>  CDaoRecordset::GetValidationText

Chame essa função de membro para recuperar o texto da propriedade do objeto subjacente do campo de texto de validação.

```
CString GetValidationText();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` objeto que contém o texto da mensagem que será exibida se o valor de um campo não satisfaz a regra de validação do objeto subjacente do campo.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade do texto de validação" na Ajuda do DAO.

##  <a name="isbof"></a>  CDaoRecordset::IsBOF

Chame essa função de membro antes de você rolar de registro para o registro para saber se você passou antes do primeiro registro do conjunto de registros.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros não contiver registros ou se você percorreu para trás antes do primeiro registro; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também pode chamar `IsBOF` juntamente com `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver registros, `IsBOF` retorna não zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retornará 0.

Se o primeiro registro é o registro atual e você chamar `MovePrev`, `IsBOF` subsequentemente retornará diferente de zero. Se `IsBOF` retorna diferente de zero e você chamar `MovePrev`, uma exceção será lançada. Se `IsBOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.

Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:

- Chamando `Open*` internamente torna o primeiro registro no conjunto de registros do registro atual chamando `MoveFirst`. Portanto, chamar `Open` em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferentes de zero. (Consulte a tabela a seguir para o comportamento de uma falha na `MoveFirst` ou `MoveLast` chamar.)

- Todas as operações de movimentação que localizar com êxito um registro fazem com que `IsBOF` e `IsEOF` para retornar 0.

- Uma `AddNew` chamada seguido por um `Update` fará com que a chamada que insere com êxito um novo registro `IsBOF` retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterado. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio é no final de um arquivo, portanto, qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que ele remove o registro de restante somente de um conjunto de registros não alterará o valor da `IsBOF` ou `IsEOF`.

Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.

||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext,<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`=nonzero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`=0,<br /><br /> `IsEOF`=nonzero|Permitido|Permitido|Exceção|Exceção|
|Both nonzero|Exceção|Exceção|Exceção|Exceção|
|0|Permitido|Permitido|Permitido|Permitido|

Permitindo que uma operação de movimentação não significa que a operação com êxito será localizar um registro. Ela simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem mudar como resultado da tentativa de movimentação.

O efeito de operações de movimentação que não localize um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.

||IsBOF|IsEOF|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Nonzero|Nonzero|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Nonzero|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Nonzero|

Para obter informações relacionadas, consulte o tópico "BOF, EOF propriedades" na Ajuda do DAO.

##  <a name="isdeleted"></a>  CDaoRecordset::IsDeleted

Chame essa função de membro para determinar se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros é posicionado em um registro excluído; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para um registro e `IsDeleted` retorna TRUE (diferente de zero) e, em seguida, você deve rolar para outro registro antes de executar outras operações de conjunto de registros.

> [!NOTE]
>  Você não precisa verificar o status excluído por registros em um conjunto de registros de instantâneo ou tipo de tabela. Porque os registros não podem ser excluídos de um instantâneo, não é necessário chamar `IsDeleted`. Para conjuntos de registros do tipo de tabela, os registros excluídos são removidos do conjunto de registros. Depois que um registro tiver sido excluído por você, outro usuário, ou em outro conjunto de registros, que não é possível voltar a esse registro. Portanto, não há nenhuma necessidade de chamar `IsDeleted`.

Quando você exclui um registro de dynaset, ele é removido do conjunto de registros e você não é possível rolar de volta para esse registro. No entanto, se um registro em um dynaset é excluído por outro usuário ou em outro conjunto de registros com base na mesma tabela, `IsDeleted` retornará TRUE quando você rola posteriormente para esse registro.

Para obter informações relacionadas, consulte os tópicos "Método Delete", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.

##  <a name="iseof"></a>  CDaoRecordset::IsEOF

Chame essa função de membro conforme você rola do registro a registro para saber se você passou além do último registro do conjunto de registros.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros não contiver registros ou se você percorreu além do último registro; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também pode chamar `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver registros, `IsEOF` retorna não zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retornará 0.

Se o último registro é o registro atual quando você chama `MoveNext`, `IsEOF` subsequentemente retornará diferente de zero. Se `IsEOF` retorna diferente de zero e você chamar `MoveNext`, uma exceção será lançada. Se `IsEOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.

Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:

- Chamando `Open` internamente torna o primeiro registro no conjunto de registros do registro atual chamando `MoveFirst`. Portanto, chamar `Open` em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferentes de zero. (Consulte a tabela a seguir para o comportamento de uma falha na `MoveFirst` chamar.)

- Todas as operações de movimentação que localizar com êxito um registro fazem com que `IsBOF` e `IsEOF` para retornar 0.

- Uma `AddNew` chamada seguido por um `Update` fará com que a chamada que insere com êxito um novo registro `IsBOF` retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterado. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio é no final de um arquivo, portanto, qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que ele remove o registro de restante somente de um conjunto de registros não alterará o valor da `IsBOF` ou `IsEOF`.

Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.

||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext,<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`=nonzero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`=0,<br /><br /> `IsEOF`=nonzero|Permitido|Permitido|Exceção|Exceção|
|Both nonzero|Exceção|Exceção|Exceção|Exceção|
|0|Permitido|Permitido|Permitido|Permitido|

Permitindo que uma operação de movimentação não significa que a operação com êxito será localizar um registro. Ela simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem mudar como resultado da tentativa de movimentação.

O efeito de operações de movimentação que não localize um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.

||IsBOF|IsEOF|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Nonzero|Nonzero|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Nonzero|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Nonzero|

Para obter informações relacionadas, consulte o tópico "BOF, EOF propriedades" na Ajuda do DAO.

##  <a name="isfielddirty"></a>  CDaoRecordset::IsFieldDirty

Chame essa função de membro determinar se o membro de dados do campo especificado de dynaset foi sinalizado como "sujo" (alterado).

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos estão sujos.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o membro de dados do campo especificado é marcado como sujo; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados sujas do campo serão transferidos para o registro na fonte de dados quando o registro atual é atualizado por uma chamada para o `Update` função de membro `CDaoRecordset` (após uma chamada para `Edit` ou `AddNew`). Com esse conhecimento, você pode tomar mais medidas, como removendo a sinalização o membro de dados de campo para marcar a coluna para que ele não será gravado para a fonte de dados.

`IsFieldDirty` é implementado por meio de `DoFieldExchange`.

##  <a name="isfieldnull"></a>  CDaoRecordset::IsFieldNull

Chame essa função de membro para determinar se o membro de dados do campo especificado de um conjunto de registros foi sinalizado como Null.

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos serão Null.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o membro de dados do campo especificado é sinalizado como Null; Caso contrário, 0.

### <a name="remarks"></a>Comentários

(Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é igual a NULL em C++.) Se um membro de dados do campo for sinalizado como Null, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.

> [!NOTE]
>  Em determinadas situações, usando `IsFieldNull` pode ser ineficiente, como mostra o exemplo de código a seguir:

[!code-cpp[NVC_MFCDatabase#5](../../mfc/codesnippet/cpp/cdaorecordset-class_5.cpp)]

> [!NOTE]
>  Se você estiver usando a associação dinâmica de registro, sem derivar da `CDaoRecordset`, certifique-se de usar VT_NULL, conforme mostrado no exemplo.

##  <a name="isfieldnullable"></a>  CDaoRecordset::IsFieldNullable

Chame essa função de membro determinar se o membro de dados do campo especificado é "que permite valor nulo" (pode ser definido como um valor nulo; C++ nulo não é igual a Null, que, na terminologia de banco de dados, significa "having sem valor").

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos serão Null.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o membro de dados do campo especificado pode ser feito a Null; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Um campo que não pode ser Null deve ter um valor. Se você tentar definir um campo como Null quando adicionar ou atualizar um registro, a fonte de dados rejeita a adição ou atualização, e `Update` lançará uma exceção. A exceção ocorre quando você chama `Update`, não quando você chama `SetFieldNull`.

##  <a name="isopen"></a>  CDaoRecordset::IsOpen

Chame essa função de membro para determinar se o conjunto de registros é aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto de conjunto de registros `Open` ou `Requery` função membro foi chamada anteriormente e o conjunto de registros não foi fechado; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="m_bcheckcachefordirtyfields"></a>  CDaoRecordset::m_bCheckCacheForDirtyFields

Contém um sinalizador que indica se campos armazenados em cache são automaticamente marcados como sujos (alterados) e Null.

### <a name="remarks"></a>Comentários

O sinalizador assume TRUE como padrão. A configuração nesse membro de dados controla o mecanismo inteiro de buffer duplo. Se você definir o sinalizador como TRUE, você pode desativar o armazenamento em cache em uma base campo por campo usando o mecanismo DFX. Se você definir o sinalizador como FALSE, você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.

Definir este membro de dados antes de chamar `Open`. Esse mecanismo é principalmente para facilidade de uso. Desempenho pode ser mais lento devido ao buffer duplo de campos conforme as alterações são feitas.

##  <a name="m_nfields"></a>  CDaoRecordset::m_nFields

Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor da classe de conjunto de registros deve inicializar `m_nFields` com o número correto de campos associados estaticamente. ClassWizard grava essa inicialização para você quando você usá-lo para declarar sua classe de conjunto de registros. Você também pode escrevê-lo manualmente.

A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!NOTE]
>  Esse número deve corresponder ao número de colunas de saída registrado no `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro `CDaoFieldExchange::outputColumn`.

Você pode associar colunas dinamicamente por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue`. Se você fizer isso, você precisa incrementar a contagem na `m_nFields` para refletir o número da função DFX chama em seu `DoFieldExchange` função de membro.

##  <a name="m_nparams"></a>  CDaoRecordset::m_nParams

Contém o número de membros de dados de parâmetro na classe de conjunto de registros — o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se sua classe de conjunto de registros tem quaisquer membros de dados de parâmetro, o construtor da classe deve inicializar *m_nParams* com o número correto. O valor de *m_nParams* padrão é 0. Se você adicionar membros de dados de parâmetro — que deve ser feito manualmente — você também deverá adicionar manualmente uma inicialização no construtor da classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de ' espaços reservados em sua *m_strFilter*  ou *m_strSort* cadeia de caracteres).

A estrutura usa esse número quando ela parametriza a consulta do conjunto de registros.

> [!NOTE]
>  Esse número deve corresponder ao número de "parâmetros" registrados no `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro `CFieldExchange::param`.

Para obter informações relacionadas, consulte o tópico "Parâmetro de objeto" na Ajuda do DAO.

##  <a name="m_pdaorecordset"></a>  CDaoRecordset::m_pDAORecordset

Contém um ponteiro de interface do OLE para o objeto de conjunto de registros DAO subjacentes a `CDaoRecordset` objeto.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar a interface DAO diretamente.

Para obter informações relacionadas, consulte o tópico "Objeto de conjunto de registros" na Ajuda do DAO.

##  <a name="m_pdatabase"></a>  CDaoRecordset::m_pDatabase

Contém um ponteiro para o `CDaoDatabase` objeto por meio do qual o conjunto de registros é conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Essa variável é definida de duas maneiras. Normalmente, você passa um ponteiro para um já aberta `CDaoDatabase` ao construir o objeto de conjunto de registros do objeto. Se você passar NULL em vez disso, `CDaoRecordset` cria um `CDaoDatabase` objeto para você e o abre. Em ambos os casos, `CDaoRecordset` armazena o ponteiro nessa variável.

Normalmente você não diretamente precisará usar o ponteiro armazenado em `m_pDatabase`. Se você escrever suas próprias extensões para `CDaoRecordset`, no entanto, talvez você precise usar o ponteiro. Por exemplo, talvez seja necessário o ponteiro se você lançar sua própria `CDaoException`(s).

Para obter informações relacionadas, consulte o tópico "Objeto de banco de dados" na Ajuda do DAO.

##  <a name="m_strfilter"></a>  CDaoRecordset::m_strFilter

Contém uma cadeia de caracteres que é usada para construir o **onde** cláusula de uma instrução SQL.

### <a name="remarks"></a>Comentários

Ele não inclui a palavra reservada **onde** para filtrar o conjunto de registros. O uso desse membro de dados não é aplicável a conjuntos de registros do tipo de tabela. O uso de `m_strFilter` não tem nenhum efeito ao abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.

Use o formato de data dos EUA (mês-dia-ano) quando você filtrar os campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, os dados não podem ser filtrados conforme o esperado.

Para obter informações relacionadas, consulte o tópico "Propriedade de filtro" na Ajuda do DAO.

##  <a name="m_strsort"></a>  CDaoRecordset::m_strSort

Contém uma cadeia de caracteres que contém o **ORDERBY** cláusula de uma instrução SQL sem as palavras reservadas **ORDERBY**.

### <a name="remarks"></a>Comentários

Você pode classificar em objetos de conjunto de registros do tipo dynaset e snapshot.

Você não pode classificar os objetos de conjunto de registros do tipo de tabela. Para determinar a ordem de classificação de um conjunto de registros do tipo de tabela, chame [SetCurrentIndex](#setcurrentindex).

O uso de *m_strSort* não tem nenhum efeito ao abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.

Para obter informações relacionadas, consulte o tópico "Propriedade Sort" na Ajuda do DAO.

##  <a name="move"></a>  CDaoRecordset::Move

Chame essa função de membro para posicionar o conjunto de registros *lRows* registros do registro atual.

```
virtual void Move(long lRows);
```

### <a name="parameters"></a>Parâmetros

*lRows*<br/>
O número de registros para Avançar ou retroceder. Valores positivos movem para a frente, na direção do final do conjunto de registros. Valores negativos a movem para trás, até o início.

### <a name="remarks"></a>Comentários

Você pode mover para frente ou para trás. `Move( 1 )` é equivalente a `MoveNext`, e `Move( -1 )` é equivalente a `MovePrev`.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você percorreu após o início ou fim do conjunto de registros ( `IsBOF` ou `IsEOF` retorna não zero), uma chamada para `Move` lança um `CDaoException`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Quando você chama `Move` em um instantâneo de rolagem somente de encaminhamento, o *lRows* deve ser um inteiro positivo e não são permitidos indicadores, portanto, você pode mover para frente apenas.

Para tornar o nome, sobrenome, anterior ou seguinte registre em um conjunto de registros a chamada atual de registros, o `MoveFirst`, `MoveLast`, `MoveNext`, ou `MovePrev` função de membro.

Para obter informações relacionadas, consulte os tópicos "Método Move" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.

##  <a name="movefirst"></a>  CDaoRecordset::MoveFirst

Chame essa função de membro para tornar o primeiro registro no conjunto de registros (se houver) no registro atual.

```
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Você não precisa chamar `MoveFirst` imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Use o `Move` funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.

Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.

Se você chamar `MoveLast` em um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta é forçada a conclusão e o objeto recordset é totalmente preenchido.

Você não pode chamar o `MoveFirst` ou `MovePrev` a função de membro com um instantâneo de rolagem de somente avanço.

Para mover a posição atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "Método Move" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.

##  <a name="movelast"></a>  CDaoRecordset::MoveLast

Chame essa função de membro para tornar o último registro (se houver) no conjunto de registros do registro atual.

```
void MoveLast();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Use o `Move` funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.

Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.

Se você chamar `MoveLast` em um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta é forçada a conclusão e o objeto recordset é totalmente preenchido.

Para mover a posição atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "Método Move" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.

##  <a name="movenext"></a>  CDaoRecordset::MoveNext

Chame essa função de membro para tornar o próximo registro no conjunto de registros do registro atual.

```
void MoveNext();
```

### <a name="remarks"></a>Comentários

É recomendável que você chame `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará uma `CDaoException` se `IsBOF` retorna não zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados pelo conjunto de registros.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Use o `Move` funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.

Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.

Para mover a posição atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "Método Move" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.

##  <a name="moveprev"></a>  CDaoRecordset::MovePrev

Chame essa função de membro para tornar o registro anterior no conjunto de registros do registro atual.

```
void MovePrev();
```

### <a name="remarks"></a>Comentários

É recomendável que você chame `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará uma `CDaoException` se `IsBOF` retorna não zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados pelo conjunto de registros.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Use o `Move` funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.

Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.

Você não pode chamar o `MoveFirst` ou `MovePrev` a função de membro com um instantâneo de rolagem de somente avanço.

Para mover a posição atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "Método Move" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.

##  <a name="open"></a>  CDaoRecordset::Open

Você deve chamar essa função de membro para recuperar os registros do conjunto de registros.

```
virtual void Open(
    int nOpenType = AFX_DAO_USE_DEFAULT_TYPE,
    LPCTSTR lpszSQL = NULL,
    int nOptions = 0);

virtual void Open(
    CDaoTableDef* pTableDef,
    int nOpenType = dbOpenTable,
    int nOptions = 0);

virtual void Open(
    CDaoQueryDef* pQueryDef,
    int nOpenType = dbOpenDynaset,
    int nOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*nOpenType*<br/>
Um dos seguintes valores:

- `dbOpenDynaset` Um conjunto de registros do tipo dynaset com rolagem bidirecional. Esse é o padrão.

- `dbOpenTable` Um conjunto de registros do tipo de tabela com rolagem bidirecional.

- `dbOpenSnapshot` Um conjunto de registros do tipo de instantâneo com rolagem bidirecional.

*lpszSQL*<br/>
Um ponteiro de cadeia de caracteres que contém um dos seguintes:

- Um ponteiro nulo.

- O nome de um ou mais tabledefs e/ou querydefs (separados por vírgula).

- Um SQL **selecionar** instrução (opcionalmente com um SQL **onde** ou **ORDERBY** cláusula).

- Uma consulta de passagem.

*nOptions*<br/>
Um ou mais das opções listadas abaixo. O valor padrão é 0. Os valores possíveis são:

- `dbAppendOnly` Você apenas pode acrescentar novos registros (somente conjunto de registros do tipo dynaset). Essa opção, literalmente, significa que registros só podem ser acrescentados. As classes de banco de dados ODBC do MFC tem a opção somente de acréscimo que permite que os registros a serem recuperados e acrescentado.

- `dbForwardOnly` O conjunto de registros é um instantâneo de rolagem de somente avanço.

- `dbSeeChanges` Gere uma exceção se outro usuário está mudando de dados que você está editando.

- `dbDenyWrite` Outros usuários não podem modificar ou adicionar registros.

- `dbDenyRead` Outros usuários não podem exibir registros (somente conjunto de registros do tipo de tabela).

- `dbReadOnly` Você pode exibir somente os registros; outros usuários podem modificá-las.

- `dbInconsistent` Atualizações inconsistentes são permitidas (somente conjunto de registros do tipo dynaset).

- `dbConsistent` Somente atualizações consistentes são permitidas (somente conjunto de registros do tipo dynaset).

> [!NOTE]
>  As constantes `dbConsistent` e `dbInconsistent` são mutuamente exclusivos. Você pode usar um ou outro, mas não ambos em uma determinada instância do `Open`.

*pTableDef*<br/>
Um ponteiro para um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto. Esta versão é válido somente para conjuntos de registros do tipo de tabela. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não for usado; em vez disso, o banco de dados no qual reside o tabledef é usado.

*pQueryDef*<br/>
Um ponteiro para um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) objeto. Esta versão é válido somente para o tipo de dynaset e conjuntos de registros do tipo de instantâneo. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não for usado; em vez disso, o banco de dados no qual reside o querydef é usado.

### <a name="remarks"></a>Comentários

Antes de chamar `Open`, você deve construir o objeto de conjunto de registros. Há várias maneiras de fazer isso:

- Quando você constrói o objeto recordset, passe um ponteiro para um `CDaoDatabase` objeto que já está aberto.

- Quando você constrói o objeto recordset, passe um ponteiro para um `CDaoDatabase` objeto que não está aberto. O conjunto de registros é aberto um `CDaoDatabase` do objeto, mas não fechará-lo quando o objeto recordset é fechado.

- Quando você constrói o objeto recordset, passe um ponteiro NULL. As chamadas de objeto do conjunto de registros `GetDefaultDBName` para obter o nome do Microsoft Access. Arquivo MDB a ser aberto. O conjunto de registros, em seguida, abre um `CDaoDatabase` objeto e mantém ele aberto desde que o conjunto de registros é aberto. Quando você chama `Close` o conjunto de registros, o `CDaoDatabase` objeto também é fechado.

    > [!NOTE]
    >  Quando o conjunto de registros é aberto o `CDaoDatabase` do objeto, ele abre a fonte de dados com o acesso não exclusivo.

Para a versão do `Open` que usa o *lpszSQL* parâmetro, quando o conjunto de registros é aberto, você pode recuperar registros em uma das várias maneiras. A primeira opção é ter funções DFX no seu `DoFieldExchange`. A segunda opção é usar a associação dinâmica, chamando o `GetFieldValue` função de membro. Essas opções podem ser implementadas separadamente ou em combinação. Se eles são combinados, você terá que passar na instrução SQL por conta própria na chamada para `Open`.

Quando você usa a segunda versão do `Open` em que você passe uma `CDaoTableDef` do objeto, as colunas resultantes estarão disponíveis para que você possa associar `DoFieldExchange` e o mecanismo DFX, e/ou vincular dinamicamente por meio de `GetFieldValue`.

> [!NOTE]
>  Você só pode chamar `Open` usando um `CDaoTableDef` objeto para conjuntos de registros do tipo de tabela.

Quando você usa a terceira versão do `Open` em que você passe uma `CDaoQueryDef` do objeto, que consulta será executada e as colunas resultantes estarão disponíveis para que você possa associar `DoFieldExchange` e o mecanismo DFX, e/ou vincular dinamicamente por meio de `GetFieldValue`.

> [!NOTE]
>  Você só pode chamar `Open` usando um `CDaoQueryDef` objeto de tipo dynaset e conjuntos de registros do tipo de instantâneo.

Para a primeira versão do `Open` que usa o `lpszSQL` parâmetro, os registros são selecionados com base em critérios mostrado na tabela a seguir.

|Valor da `lpszSQL` parâmetro|Registros selecionados são determinados pelo|Exemplo|
|--------------------------------------|----------------------------------------|-------------|
|NULL|A cadeia de caracteres retornada por `GetDefaultSQL`.||
|Uma lista separada por vírgulas de tabledefs um ou mais e/ou nomes de querydef.|Todas as colunas são representados no `DoFieldExchange`.|`"Customer"`|
|**Selecione** lista de colunas **FROM** lista de tabelas|As colunas especificadas de e/ou o tabledef(s) especificado querydef(s).|`"SELECT CustId, CustName`<br /><br /> `FROM Customer"`|

O procedimento normal é passar NULL para `Open`; nesse caso, `Open` chamadas `GetDefaultSQL`, uma função de membro substituíveis ClassWizard gera durante a criação de um `CDaoRecordset`-classe derivada. Esse valor fornece o tabledef(s) e/ou querydef (s) especificado em ClassWizard. Em vez disso, você pode especificar outras informações na *lpszSQL* parâmetro.

Tudo o que você passa `Open` constrói uma cadeia de caracteres final SQL para a consulta (a cadeia de caracteres pode ter o SQL **onde** e **ORDERBY** cláusulas acrescentado ao *lpszSQL* cadeia de caracteres Você passada) e, em seguida, executa a consulta. Você pode examinar a cadeia de caracteres construída chamando `GetSQL` depois de chamar `Open`.

Os membros de dados do campo da sua classe de conjunto de registros são associados às colunas dos dados selecionados. Se todos os registros são retornados, o primeiro registro torna-se o registro atual.

Se você quiser definir opções para o conjunto de registros, como um filtro ou classificação, defina `m_strSort` ou `m_strFilter` depois de construir o objeto de conjunto de registros, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros após o conjunto de registros já estiver aberto, chame `Requery`.

Se você chamar `Open` em um tipo dynaset ou conjunto de registros do tipo de instantâneo, ou se a fonte de dados se refere a uma instrução SQL ou um que representa uma tabela anexada tabledef, será possível usar `dbOpenTable` para o argumento de tipo; se você fizer isso, o MFC gera uma exceção. Para determinar se um objeto tabledef representa uma tabela anexada, crie uma [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto e chame seu [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) função de membro.

Use o `dbSeeChanges` sinalizador se você quiser interceptar as alterações feitas por outro usuário ou outro programa em seu computador quando você está editando ou excluindo o mesmo registro. Por exemplo, se dois usuários começam a editar o mesmo registro, o primeiro usuário chamar o `Update` função de membro for bem-sucedida. Quando `Update` é chamado pelo segundo usuário, um `CDaoException` é gerada. Da mesma forma, se o segundo usuário tenta chamar `Delete` excluir o registro e ele já foi alterado pelo primeiro usuário, um `CDaoException` ocorre.

Normalmente, se o usuário obtém essa `CDaoException` durante a atualização, seu código deve atualizar o conteúdo dos campos e recuperar os valores modificados mais recentemente. Se a exceção ocorre no processo de exclusão, seu código pode exibir os dados de registro de novo para o usuário e uma mensagem indicando que os dados foram alterados recentemente. Neste ponto, seu código pode solicitar uma confirmação de que o usuário ainda deseja excluir o registro.

> [!TIP]
>  Use a opção de rolagem de somente avanço (`dbForwardOnly`) melhorar o desempenho quando o aplicativo faz uma única passagem por meio de um conjunto de registros aberto a partir de uma fonte de dados ODBC.

Para obter informações relacionadas, consulte o tópico "OpenRecordset Method" na Ajuda do DAO.

##  <a name="requery"></a>  CDaoRecordset::Requery

Chame essa função de membro para recompilar (Atualizar) um conjunto de registros.

```
virtual void Requery();
```

### <a name="remarks"></a>Comentários

Se todos os registros são retornados, o primeiro registro torna-se o registro atual.

Na ordem do conjunto de registros refletir as adições e exclusões que você ou outros usuários estão fazendo para a fonte de dados, você deve recompilar o conjunto de registros chamando `Requery`. Se o conjunto de registros for um dynaset, ela reflete automaticamente as atualizações que você ou outros usuários tornam seus registros existentes (mas não adições). Se o conjunto de registros é um instantâneo, você deve chamar `Requery` para refletir edições por outros usuários, bem como adições e exclusões.

Para um dynaset ou um instantâneo, chame `Requery` sempre que quiser para recriar o conjunto de registros usando valores de parâmetro. Defina o novo filtro ou classificação definindo [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) antes de chamar `Requery`. Definir novos parâmetros, atribuindo novos valores para membros de dados de parâmetro antes de chamar `Requery`.

Se a tentativa de recompilar o conjunto de registros falhar, o conjunto de registros é fechado. Antes de chamar `Requery`, você pode determinar se o conjunto de registros pode ser consultadas novamente chamando o [CanRestart](#canrestart) função de membro. `CanRestart` não garante que `Requery` terá êxito.

> [!CAUTION]
>  Chame `Requery` somente depois de ter chamado `Open`.

> [!NOTE]
>  Chamando [Requery](#requery) altera os indicadores DAO.

Você não pode chamar `Requery` em um tipo dynaset ou conjunto de registros do tipo de instantâneo se chamar `CanRestart` retorna 0, nem você usá-lo em um conjunto de registros do tipo de tabela.

Se os dois `IsBOF` e `IsEOF` de retorno diferente de zero depois de chamar `Requery`, a consulta não retornou nenhum registro e o conjunto de registros não conterão nenhum dado.

Para obter informações relacionadas, consulte o tópico "Método Requery" na Ajuda do DAO.

##  <a name="seek"></a>  CDaoRecordset::Seek

Chame essa função de membro para localizar o registro em um objeto de conjunto de registros de tipo de tabela indexada que satisfaz os critérios especificados para a atual de índice e verifique a gravar o registro atual.

```
BOOL Seek(
    LPCTSTR lpszComparison,
    COleVariant* pKey1,
    COleVariant* pKey2 = NULL,
    COleVariant* pKey3 = NULL);

BOOL Seek(
    LPCTSTR lpszComparison,
    COleVariant* pKeyArray,
    WORD nKeys);
```

### <a name="parameters"></a>Parâmetros

*lpszComparison*<br/>
Uma das seguintes expressões de cadeia de caracteres: "<","\<=", "=", "> =", ou ">".

*pKey1*<br/>
Um ponteiro para um [COleVariant](../../mfc/reference/colevariant-class.md) cujo valor corresponde ao primeiro campo no índice. Necessário.

*pKey2*<br/>
Um ponteiro para um `COleVariant` cujo valor corresponde ao segundo campo no índice, se houver. O padrão é NULL.

*pKey3*<br/>
Um ponteiro para um `COleVariant` cujo valor corresponde ao terceiro campo no índice, se houver. O padrão é NULL.

*pKeyArray*<br/>
Um ponteiro para uma matriz de variantes. O tamanho da matriz corresponde ao número de campos no índice.

*nKeys*<br/>
Um inteiro correspondente ao tamanho da matriz, que é o número de campos no índice.

> [!NOTE]
>  Não especifique caracteres curinga nas chaves. Fará com que os caracteres curinga `Seek` para retornar sem registros correspondentes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

Use a segunda versão (matriz) de `Seek` para lidar com índices de campos de quatro ou mais.

`Seek` Habilita o índice de alto desempenho, pesquisa em conjuntos de registros do tipo de tabela. Você deve definir o índice atual chamando `SetCurrentIndex` antes de chamar `Seek`. Se o índice identifica um campo de chave não exclusivo ou campos, `Seek` localiza o primeiro registro que satisfaça os critérios. Se você não definir um índice, uma exceção é lançada.

Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objetos devem ser declarados explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** *lpszSrc* **,** *vtSrc* **)**  formulário de construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando o `COleVariant` função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Quando você chama `Seek`, você passa um ou mais valores de chave e um operador de comparação ("<","\<=", "=", "> =", ou ">"). `Seek` pesquisa os campos de chave especificados e localiza o primeiro registro que satisfaz os critérios especificados por *lpszComparison* e *pKey1*. Uma vez encontrado, `Seek` retorna não zero e torna esse registro atual. Se `Seek` não conseguir localizar uma correspondência, `Seek` retorna zero, e o registro atual é indefinido. Ao usar DAO diretamente, você deve verificar explicitamente a propriedade NoMatch.

Se `lpszComparison` é "=", "> =", ou ">", `Seek` começa no início do índice. Se *lpszComparison* é "<" ou "< =", `Seek` inicia no final do índice e pesquisa para trás, a menos que haja entradas de índice duplicados no final. Nesse caso, `Seek` começa em uma entrada arbitrária entre as entradas de índice duplicados no final do índice.

Não deve haver um registro atual quando você usa `Seek`.

Para localizar um registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que satisfaz uma condição específica, use as operações de localização. Para incluir todos os registros, não apenas aqueles que satisfazem uma condição específica, use as operações de movimentação para mover de registro para registro.

Você não pode chamar `Seek` em uma tabela anexada de qualquer tipo, pois a tabelas anexadas devem ser abertas como tipo dynaset ou conjuntos de registros do tipo de instantâneo. No entanto, se você chamar `CDaoDatabase::Open` para abrir diretamente um banco de dados ISAM instalável, você pode chamar `Seek` em tabelas no banco de dados, embora o desempenho pode ser lenta.

Para obter informações relacionadas, consulte o tópico "Método Seek" na Ajuda do DAO.

##  <a name="setabsoluteposition"></a>  CDaoRecordset::SetAbsolutePosition

Define o número de registro relativo de registro de um conjunto de registros do objeto atual.

```
void SetAbsolutePosition(long lPosition);
```

### <a name="parameters"></a>Parâmetros

*lPosition*<br/>
Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

Chamar `SetAbsolutePosition` permite que você posicione o ponteiro de registro atual para um registro específico com base em sua posição ordinal em um tipo dynaset ou conjunto de registros do tipo de instantâneo. Você também pode determinar o número de registro atual chamando [GetAbsolutePosition](#getabsoluteposition).

> [!NOTE]
>  Essa função de membro é válida somente para o tipo de dynaset e conjuntos de registros do tipo de instantâneo.

O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Definir um valor maior que o número de causas de registros preenchidos MFC para lançar uma exceção. Você pode determinar o número de registros preenchidos no conjunto de registros chamando o `GetRecordCount` função de membro.

Se o registro atual é excluído, o valor da propriedade AbsolutePosition não está definido, e MFC gera uma exceção se ela for referenciada. Novos registros são adicionados ao final da sequência.

> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro de substituto. Indicadores ainda são a maneira recomendada de reter e retornar para uma determinada posição e a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros que dão suporte a indicadores. Em particular, a posição de um determinado registro é alterado quando o registro (s) precede é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado novamente porque a ordem dos registros individuais dentro de um conjunto de registros não é garantida, a menos que ele é criado com uma instrução SQL usando um  **ORDERBY** cláusula.

Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.

##  <a name="setbookmark"></a>  CDaoRecordset::SetBookmark

Chame essa função de membro para posicionar o conjunto de registros no registro que contém o indicador especificado.

```
void SetBookmark(COleVariant varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor de indicador para um registro específico.

### <a name="remarks"></a>Comentários

Quando um objeto recordset é criado ou aberto, cada um dos seus registros já tem um indicador exclusivo. Você pode recuperar o indicador para o registro atual chamando `GetBookmark` e salvar o valor a ser um `COleVariant` objeto. Você pode retornar posteriormente a esse registro chamando `SetBookmark` usando o valor de indicador salvo.

> [!NOTE]
>  Chamando [Requery](#requery) altera os indicadores DAO.

Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** *lpszSrc* **,** *vtSrc* **)**  formulário de construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando o `COleVariant` função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte os tópicos "Propriedade Bookmark" e possível de indicação de propriedade"na Ajuda do DAO.

##  <a name="setcachesize"></a>  CDaoRecordset::SetCacheSize

Chame essa função de membro para definir o número de registros a ser armazenado em cache.

```
void SetCacheSize(long lSize);
```

### <a name="parameters"></a>Parâmetros

*lSize*<br/>
Especifica o número de registros. Um valor típico é 100. Uma configuração de 0 desativa o cache. A configuração deve ser entre 5 e 1200 registros. O cache pode usar uma quantidade considerável de memória.

### <a name="remarks"></a>Comentários

Um cache é um espaço na memória local que contém os dados recentemente recuperados do servidor que os dados serão solicitados novamente enquanto o aplicativo está em execução. Cache de dados melhoram o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Quando dados são solicitados, o mecanismo de banco de dados Microsoft Jet verifica o cache para os dados solicitados pela primeira vez em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remotos, chamadas a `SetCacheSize` e `SetCacheStart` funções de membro e, em seguida, chame o `FillCache` percorrer os registros usando uma das operações de movimentação ou função de membro. O *lSize* parâmetro do `SetCacheSize` função de membro pode ser baseada no número de registros de seu aplicativo pode funcionar com ao mesmo tempo. Por exemplo, se você estiver usando um conjunto de registros como a fonte de dados a ser exibido na tela, você poderia passar a `SetCacheSize` *lSize* parâmetro como 20 para exibir 20 registros ao mesmo tempo.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.

##  <a name="setcachestart"></a>  CDaoRecordset::SetCacheStart

Chame essa função de membro para especificar o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
void SetCacheStart(COleVariant varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

Você pode usar o valor de indicador de qualquer registro para o *varBookmark* parâmetro do `SetCacheStart` função de membro. Tornar o registro que você deseja iniciar o cache com o registro atual, estabelecer um indicador para que o uso de registro [SetBookmark](#setbookmark)e passe o valor do indicador como o parâmetro para o `SetCacheStart` função de membro.

O mecanismo de banco de dados Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.

Registros recuperados do cache não refletem as alterações feitas simultaneamente os dados de origem por outros usuários.

Para forçar uma atualização de todos os dados armazenados em cache, passe o *lSize* parâmetro do `SetCacheSize` como 0, chame `SetCacheSize` novamente com o tamanho do cache foi originalmente solicitada e, em seguida, chame o `FillCache` função de membro.

Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** *lpszSrc* **,** *vtSrc* **)**  formulário de construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando o `COleVariant` função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte o tópico CacheSize, CacheStart propriedades "na Ajuda do DAO.

##  <a name="setcurrentindex"></a>  CDaoRecordset::SetCurrentIndex

Chame essa função de membro para definir um índice em um conjunto de registros do tipo de tabela.

```
void SetCurrentIndex(LPCTSTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
Um ponteiro que contém o nome do índice a ser definido.

### <a name="remarks"></a>Comentários

Registros nas tabelas base não são armazenados em uma ordem específica. Um índice de configuração altera a ordem dos registros retornados do banco de dados, mas não afeta a ordem na qual os registros são armazenados. O índice especificado já deve estar definido. Se você tentar usar um objeto de índice que não existe ou se o índice não é definido quando você chama [busca](#seek), MFC gera uma exceção.

Você pode criar um novo índice para a tabela chamando [CDaoTableDef::CreateIndex](../../mfc/reference/cdaotabledef-class.md#createindex) e anexando o novo índice na coleção de índices de tabledef subjacente chamando [CDaoTableDef::Append](../../mfc/reference/cdaotabledef-class.md#append), e em seguida, abrir novamente o conjunto de registros.

Registros retornados de um conjunto de registros do tipo de tabela podem ser ordenados somente pelos índices definidos para tabledef subjacente. Para classificar os registros em alguma outra ordem, você pode abrir um tipo dynaset ou conjunto de registros do tipo de instantâneo usando um SQL **ORDERBY** cláusula armazenado em [CDaoRecordset::m_strSort](#m_strsort).

Para obter informações relacionadas, consulte o tópico "Objeto de índice" e a definição de "índice atual" na Ajuda do DAO.

##  <a name="setfielddirty"></a>  CDaoRecordset::SetFieldDirty

Chame essa função de membro para sinalizar um membro de dados do campo do conjunto de registros como alterados ou como inalterada.

```
void SetFieldDirty(
    void* pv,
    BOOL bDirty = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
Contém o endereço de um membro de dados do campo no conjunto de registros ou NULL. Se for NULL, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ nulo não é igual a Null na terminologia de banco de dados, que significa "não tendo nenhum valor.")

*bDirty*<br/>
TRUE se o membro de dados do campo deve ser marcado como "sujo" (alterado). Caso contrário, FALSE se o membro de dados do campo deve ser sinalizado como "Limpar" (inalterado).

### <a name="remarks"></a>Comentários

Marcar campos conforme inalterado garante que o campo não é atualizado.

As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados do mecanismo de troca (DFX) DAO campos de registro. Alterando o valor de um campo geralmente define o campo sujas automaticamente, portanto, você raramente precisa chamar `SetFieldDirty` por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor dos dados de campo membro. O mecanismo DFX também utiliza o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não está sendo usado, em seguida, alterando o valor do campo não define automaticamente o campo sujo. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [edite](#edit) ou [AddNew](#addnew).

Usando NULL para o primeiro argumento da função se aplicam a função a todos `outputColumn` campos, não **param** campos no `CDaoFieldExchange`. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#6](../../mfc/codesnippet/cpp/cdaorecordset-class_6.cpp)]

será definido somente `outputColumn` campos como NULL; **param** campos não serão afetados.

Para trabalhar em um **param**, você deve fornecer o endereço real da pessoa **param** você deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#7](../../mfc/codesnippet/cpp/cdaorecordset-class_7.cpp)]

Isso significa que não é possível definir todos os **param** campos como NULL, como faria com `outputColumn` campos.

`SetFieldDirty` é implementado por meio de `DoFieldExchange`.

##  <a name="setfieldnull"></a>  CDaoRecordset::SetFieldNull

Chame essa função de membro para sinalizar um membro de dados do campo do conjunto de registros como Null (especificamente com nenhum valor) ou não nulo.

```
void SetFieldNull(
    void* pv,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pv*<br/>
Contém o endereço de um membro de dados do campo no conjunto de registros ou NULL. Se for NULL, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ nulo não é igual a Null na terminologia de banco de dados, que significa "não tendo nenhum valor.")

*bNull*<br/>
Diferente de zero se o membro de dados do campo deve ser sinalizada como não tendo nenhum valor (nulo). Caso contrário, 0 se o membro de dados do campo deve ser marcado como não-nulo.

### <a name="remarks"></a>Comentários

`SetFieldNull` é usado para campos associados no `DoFieldExchange` mecanismo.

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujo" (alterado). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou Null. Se ele não é adequado tornar um campo nulo, uma [CDaoException](../../mfc/reference/cdaoexception-class.md) é gerada.

Se você estiver usando o mecanismo de buffer duplo, por exemplo, se desejar designar um campo do registro atual como não tendo um valor, chamar especificamente `SetFieldNull` com *bNull* definido como TRUE para marcá-lo como Null. Se um campo foi marcado anteriormente Null, e agora você deseja dar a ela um valor, basta defina o novo valor. Não é necessário remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser Null, chame [IsFieldNullable](#isfieldnullable).

Se você não estiver usando o mecanismo de buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como suja e não nulo. Você precisa definir especificamente os campos suja e não nulo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

O mecanismo DFX emprega o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [edite](#edit) ou [AddNew](#addnew).

Usando NULL para o primeiro argumento da função será aplicada somente como a função `outputColumn` campos, não **param** campos no `CDaoFieldExchange`. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#8](../../mfc/codesnippet/cpp/cdaorecordset-class_8.cpp)]

será definido somente `outputColumn` campos como NULL; **param** campos não serão afetados.

##  <a name="setfieldvalue"></a>  CDaoRecordset::SetFieldValue

Chame essa função de membro para definir o valor de um campo, por posição ordinal ou alterando o valor da cadeia de caracteres.

```
virtual void SetFieldValue(
    LPCTSTR lpszName,
    const COleVariant& varValue);

virtual void SetFieldValue(
    int nIndex,
    const COleVariant& varValue);

void SetFieldValue(
    LPCTSTR lpszName,
    LPCTSTR lpszValue);

void SetFieldValue(
    int nIndex,
    LPCTSTR lpszValue);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.

*varValue*<br/>
Uma referência a um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor do conteúdo do campo.

*nIndex*<br/>
Um inteiro que representa a posição ordinal do campo na coleção de campos do conjunto de registros (baseado em zero).

*lpszValue*<br/>
Um ponteiro para uma cadeia de caracteres que contém o valor do conteúdo do campo.

### <a name="remarks"></a>Comentários

Use `SetFieldValue` e [GetFieldValue](#getfieldvalue) vincular dinamicamente os campos no tempo de execução em vez de estaticamente colunas de associação usando a [DoFieldExchange](#dofieldexchange) mecanismo.

Observe que se você não estiver criando um conjunto de registros UNICODE, você deve usar uma forma de `SetFieldValue` que não contém um `COleVariant` parâmetro, ou o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** *lpszSrc* **,** *vtSrc* **)**  formulário de construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando o `COleVariant` função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Valor de propriedade" na Ajuda do DAO.

##  <a name="setfieldvaluenull"></a>  CDaoRecordset::SetFieldValueNull

Chame essa função de membro para definir o campo como um valor nulo.

```
void SetFieldValueNull(int nIndex);
void SetFieldValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para pesquisa de índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para a pesquisa por nome.

### <a name="remarks"></a>Comentários

C++ nulo não é igual a Null, que, na terminologia de banco de dados, significa "não tendo nenhum valor."

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Valor de propriedade" na Ajuda do DAO.

##  <a name="setlockingmode"></a>  CDaoRecordset::SetLockingMode

Chame essa função de membro para definir o tipo de bloqueio para o conjunto de registros.

```
void SetLockingMode(BOOL bPessimistic);
```

### <a name="parameters"></a>Parâmetros

*bPessimistic*<br/>
Um sinalizador que indica o tipo de bloqueio.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista está em vigor, a página de 2K que contém o registro que você está editando é bloqueado assim que você chamar o `Edit` função de membro. A página é desbloqueada quando você chama o `Update` ou `Close` função de membro ou qualquer uma das operações de movimentação ou localizar.

Quando otimista proteção está em vigor, a página de 2K que contém o registro é bloqueada somente enquanto o registro está sendo atualizado com o `Update` função de membro.

Se uma página estiver bloqueada, nenhum outro usuário pode editar os registros na mesma página. Se você chamar `SetLockingMode` e passe um valor diferente de zero e outro usuário já tiver bloqueado a página, uma exceção é lançada quando você chama `Edit`. Outros usuários podem ler dados de páginas bloqueadas.

Se você chamar `SetLockingMode` com um valor igual a zero e posterior chamar `Update` enquanto a página está bloqueada por outro usuário, ocorrerá uma exceção. Para ver as alterações feitas ao seu registro por outro usuário (e perder as alterações), chame o `SetBookmark` a função de membro com o valor de indicador do registro atual.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

##  <a name="setparamvalue"></a>  CDaoRecordset::SetParamValue

Chame essa função de membro para definir o valor de um parâmetro de conjunto de registros em tempo de execução.

```
virtual void SetParamValue(
    int nIndex,
    const COleVariant& varValue);

virtual void SetParamValue(
    LPCTSTR lpszName,
    const COleVariant& varValue);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
A posição numérica do parâmetro na coleção de parâmetros do querydef.

*var*<br/>
O valor a ser definido; Consulte os comentários.

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja definir.

### <a name="remarks"></a>Comentários

O parâmetro deve já foram estabelecido como parte da cadeia de caracteres SQL do conjunto de registros. Você pode acessar o parâmetro por nome ou por sua posição de índice na coleção.

Especifique o valor a ser definido como um `COleVariant` objeto. Para obter informações sobre como definir o valor desejado e digite sua `COleVariant` de objeto, consulte a classe [COleVariant](../../mfc/reference/colevariant-class.md). Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** *lpszSrc* **,** *vtSrc* **)**  formulário de construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando o `COleVariant` função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

##  <a name="setparamvaluenull"></a>  CDaoRecordset::SetParamValueNull

Chame essa função de membro para definir o parâmetro como um valor nulo.

```
void SetParamValueNull(int nIndex);
void SetParamValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para pesquisa de índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para a pesquisa por nome.

### <a name="remarks"></a>Comentários

C++ nulo não é igual a Null, que, na terminologia de banco de dados, significa "não tendo nenhum valor."

##  <a name="setpercentposition"></a>  CDaoRecordset::SetPercentPosition

Chame essa função de membro para definir um valor que altera a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.

```
void SetPercentPosition(float fPosition);
```

### <a name="parameters"></a>Parâmetros

*fPosition*<br/>
Um número entre 0 e 100.

### <a name="remarks"></a>Comentários

Ao trabalhar com um tipo dynaset ou conjunto de registros do tipo de instantâneo, primeiro preencha o conjunto de registros, movendo para o último registro antes de chamar `SetPercentPosition`. Se você chamar `SetPercentPosition` antes de preencher completamente o conjunto de registros, a quantidade de movimentação é em relação ao número de registros acessado conforme indicado pelo valor da [GetRecordCount](#getrecordcount). Você pode mover para o último registro chamando `MoveLast`.

Depois de chamar `SetPercentPosition`, o registro na posição aproximada correspondente a esse valor se torna atual.

> [!NOTE]
>  Chamar `SetPercentPosition` para mover o registro atual para um registro específico em um conjunto de registros não é recomendado. Chame o [SetBookmark](#setbookmark) função de membro em vez disso.

Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.

##  <a name="update"></a>  CDaoRecordset::Update

Chame essa função de membro após uma chamada para o `AddNew` ou `Edit` função de membro.

```
virtual void Update();
```

### <a name="remarks"></a>Comentários

Essa chamada é necessária para concluir a `AddNew` ou `Edit` operação.

Ambos `AddNew` e `Edit` preparar um buffer de edição na qual os dados adicionados ou editados são colocados para salvá-lo a fonte de dados. `Update` salva os dados. Apenas os campos marcados ou detectado como alterado são atualizados.

Se a fonte de dados oferece suporte a transações, você pode fazer o `Update` chamar (e seus correspondentes `AddNew` ou `Edit` chamar) faz parte de uma transação.

> [!CAUTION]
> Se você chamar `Update` sem primeiro chamar `AddNew` ou `Edit`, `Update` lança um `CDaoException`. Se você chamar `AddNew` ou `Edit`, você deve chamar `Update` antes de chamar [MoveNext](#movenext) ou fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Quando o objeto recordset pessimista é bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado a partir do momento `Edit` é usado até que a atualização seja concluída. Se o conjunto de registros suporá estiver bloqueado, o registro está bloqueado e em comparação com o registro anterior à edição antes que ele é atualizado no banco de dados. Se o registro foi alterado desde que você chamou `Edit`, o `Update` operação falhará e o MFC gera uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.

> [!NOTE]
> Bloqueio otimista é sempre usado em formatos de banco de dados externo, como ODBC e ISAM instalável.

Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Método CancelUpdate", "Método Delete", "LastModified Property", "Método de atualização" e "Propriedade EditMode" na Ajuda do DAO.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
