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
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418786"
---
# <a name="cdaorecordset-class"></a>Classe CDaoRecordset

Representa um conjunto de registros selecionados de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoRecordset::CDaoRecordset](#cdaorecordset)|Constrói um objeto `CDaoRecordset`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoRecordset:: AddNew](#addnew)|Prepara para adicionar um novo registro. Chame [Update](#update) para concluir a adição.|
|[CDaoRecordset:: CanAppend](#canappend)|Retornará zero se novos registros puderem ser adicionados ao conjunto de registros por meio da função de membro [AddNew](#addnew) .|
|[CDaoRecordset:: CanBookmark](#canbookmark)|Retornará zero se o conjunto de registros der suporte a indicadores.|
|[CDaoRecordset:: CancelUpdate](#cancelupdate)|Cancela todas as atualizações pendentes devido a uma operação de [edição](#edit) ou [AddNew](#addnew) .|
|[CDaoRecordset:: Restart](#canrestart)|Retorna zero se [Requery](#requery) pode ser chamado para executar a consulta do conjunto de registros novamente.|
|[CDaoRecordset:: canrole](#canscroll)|Retornará zero se você puder percorrer os registros.|
|[CDaoRecordset:: CanTransact](#cantransact)|Retornará zero se a fonte de dados der suporte a transações.|
|[CDaoRecordset:: CanUpdate](#canupdate)|Retornará zero se o conjunto de registros puder ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CDaoRecordset:: fechar](#close)|Fecha o conjunto de registros.|
|[CDaoRecordset::D excluir](#delete)|Exclui o registro atual do conjunto de registros. Você deve rolar explicitamente para outro registro após a exclusão.|
|[CDaoRecordset::D oFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa o DFX (registro de campo de registros DAO).|
|[CDaoRecordset:: editar](#edit)|Prepara para alterações no registro atual. Chame `Update` para concluir a edição.|
|[CDaoRecordset:: FillCache](#fillcache)|Preenche toda ou parte de um cache local para um objeto Recordset que contém dados de uma fonte de dados ODBC.|
|[CDaoRecordset:: find](#find)|Localiza o primeiro, próximo, anterior ou último local de uma cadeia de caracteres específica em um conjunto de registros de tipo dynaset que cumpre os critérios especificados e faz com que esse registro seja o registro atual.|
|[CDaoRecordset:: FindFirst](#findfirst)|Localiza o primeiro registro em um conjunto de registros de tipo dynaset ou de instantâneo que satisfaz os critérios especificados e faz com que ele registre o registro atual.|
|[CDaoRecordset:: FindLast](#findlast)|Localiza o último registro em um conjunto de registros de tipo dynaset ou de instantâneo que satisfaz os critérios especificados e faz com que esse registro seja o registro atual.|
|[CDaoRecordset:: LocalizarPróximo](#findnext)|Localiza o próximo registro em um conjunto de registros de tipo dynaset ou de instantâneo que satisfaz os critérios especificados e faz com que ele registre o registro atual.|
|[CDaoRecordset::FindPrev](#findprev)|Localiza o registro anterior em um conjunto de registros de tipo dynaset ou de instantâneo que satisfaz os critérios especificados e faz com que ele registre o registro atual.|
|[CDaoRecordset::GetAbsolutePosition](#getabsoluteposition)|Retorna o número de registro do registro atual de um objeto Recordset.|
|[CDaoRecordset:: GetBookmark](#getbookmark)|Retorna um valor que representa o indicador em um registro.|
|[CDaoRecordset::GetCacheSize](#getcachesize)|Retorna um valor que especifica o número de registros em um conjunto de registros de tipo dynaset que contém dados a serem armazenados localmente em cache de uma fonte de dados ODBC.|
|[CDaoRecordset::GetCacheStart](#getcachestart)|Retorna um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::GetCurrentIndex](#getcurrentindex)|Retorna um `CString` que contém o nome do índice usado mais recentemente em uma `CDaoRecordset`indexada e de tipo de tabela.|
|[CDaoRecordset::GetDateCreated](#getdatecreated)|Retorna a data e a hora em que a tabela base subjacente a um objeto de `CDaoRecordset` foi criada|
|[CDaoRecordset::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e a hora da alteração mais recente feita no design de uma tabela base subjacente a um objeto `CDaoRecordset`.|
|[CDaoRecordset::GetDefaultDBName](#getdefaultdbname)|Retorna o nome da fonte de dados padrão.|
|[CDaoRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres SQL padrão a ser executada.|
|[CDaoRecordset:: GetEditMode](#geteditmode)|Retorna um valor que indica o estado de edição para o registro atual.|
|[CDaoRecordset::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos em um conjunto de registros.|
|[CDaoRecordset:: GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos no conjunto de registros.|
|[CDaoRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::GetIndexCount](#getindexcount)|Recupera o número de índices em uma tabela subjacente a um conjunto de registros.|
|[CDaoRecordset::GetIndexInfo](#getindexinfo)|Retorna vários tipos de informações sobre um índice.|
|[CDaoRecordset::GetLastModifiedBookmark](#getlastmodifiedbookmark)|Usado para determinar o registro mais recentemente adicionado ou atualizado.|
|[CDaoRecordset:: getlockmode](#getlockingmode)|Retorna um valor que indica o tipo de bloqueio que está em vigor durante a edição.|
|[CDaoRecordset:: GetName](#getname)|Retorna um `CString` que contém o nome do conjunto de registros.|
|[CDaoRecordset:: GetParamValue](#getparamvalue)|Recupera o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.|
|[CDaoRecordset::GetPercentPosition](#getpercentposition)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|
|[CDaoRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros acessados em um objeto Recordset.|
|[CDaoRecordset::GetSQL](#getsql)|Obtém a cadeia de caracteres SQL usada para selecionar registros para o conjunto de registros.|
|[CDaoRecordset:: GetType](#gettype)|Chamado para determinar o tipo de um conjunto de registros: tabela-tipo, tipo dynaset ou tipo de instantâneo.|
|[CDaoRecordset:: getregradevalidação](#getvalidationrule)|Retorna um `CString` que contém o valor que valida os dados conforme eles são inseridos em um campo.|
|[CDaoRecordset::GetValidationText](#getvalidationtext)|Recupera o texto que é exibido quando uma regra de validação não é satisfeita.|
|[CDaoRecordset::IsBOF](#isbof)|Retornará zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há registro atual.|
|[CDaoRecordset:: IsDeleted](#isdeleted)|Retornará zero se o conjunto de registros estiver posicionado em um registro excluído.|
|[CDaoRecordset::IsEOF](#iseof)|Retornará zero se o conjunto de registros tiver sido posicionado após o último registro. Não há registro atual.|
|[CDaoRecordset::IsFieldDirty](#isfielddirty)|Retornará zero se o campo especificado no registro atual tiver sido alterado.|
|[CDaoRecordset::IsFieldNull](#isfieldnull)|Retornará zero se o campo especificado no registro atual for nulo (sem valor).|
|[CDaoRecordset::IsFieldNullable](#isfieldnullable)|Retornará zero se o campo especificado no registro atual puder ser definido como nulo (sem valor).|
|[CDaoRecordset:: IsOpen](#isopen)|Retornará zero se [abrir](#open) tiver sido chamado anteriormente.|
|[CDaoRecordset:: mover](#move)|Posiciona o conjunto de registros em um número especificado de registos do registro atual em qualquer direção.|
|[CDaoRecordset:: MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros.|
|[CDaoRecordset:: MoveLast](#movelast)|Posiciona o registro atual no último registro no conjunto de registros.|
|[CDaoRecordset:: MoveNext](#movenext)|Posiciona o registro atual no próximo registro no conjunto de registros.|
|[CDaoRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior no conjunto de registros.|
|[CDaoRecordset:: abrir](#open)|Cria um novo conjunto de registros de uma tabela, dynaset ou instantâneo.|
|[CDaoRecordset:: Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|
|[CDaoRecordset:: Seek](#seek)|Localiza o registro em um objeto Recordset do tipo tabela indexado que atende aos critérios especificados para o índice atual e torna esse registro o registro atual.|
|[CDaoRecordset::SetAbsolutePosition](#setabsoluteposition)|Define o número de registro do registro atual de um objeto Recordset.|
|[CDaoRecordset:: SetBookmark](#setbookmark)|Posiciona o conjunto de registros em um registro que contém o indicador especificado.|
|[CDaoRecordset::SetCacheSize](#setcachesize)|Define um valor que especifica o número de registros em um conjunto de registros de tipo dynaset que contém dados a serem armazenados localmente em cache de uma fonte de dados ODBC.|
|[CDaoRecordset::SetCacheStart](#setcachestart)|Define um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::SetCurrentIndex](#setcurrentindex)|Chamado para definir um índice em um conjunto de registros de tipo tabela.|
|[CDaoRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|
|[CDaoRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual como nulo (sem valor).|
|[CDaoRecordset:: SetFieldValue](#setfieldvalue)|Define o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::SetFieldValueNull](#setfieldvaluenull)|Define o valor de um campo em um conjunto de registros como nulo. (sem valor).|
|[CDaoRecordset:: setlockmode](#setlockingmode)|Define um valor que indica o tipo de bloqueio a ser colocado em vigor durante a edição.|
|[CDaoRecordset:: SetParamValue](#setparamvalue)|Define o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente|
|[CDaoRecordset::SetParamValueNull](#setparamvaluenull)|Define o valor atual do parâmetro especificado como nulo (sem valor).|
|[CDaoRecordset::SetPercentPosition](#setpercentposition)|Define a posição do registro atual como um local correspondente a uma porcentagem do número total de registros em um conjunto de registros.|
|[CDaoRecordset:: atualizar](#update)|Conclui uma operação de `AddNew` ou `Edit` salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDaoRecordset:: m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields)|Contém um sinalizador que indica se os campos são marcados automaticamente como alterados.|
|[CDaoRecordset:: m_nFields](#m_nfields)|Contém o número de membros de dados de campo na classe recordset e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.|
|[CDaoRecordset:: m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro na classe recordset — o número de parâmetros passados com a consulta do conjunto de registros|
|[CDaoRecordset:: m_pDAORecordset](#m_pdaorecordset)|Um ponteiro para a interface DAO subjacente ao objeto Recordset.|
|[CDaoRecordset:: m_pDatabase](#m_pdatabase)|Banco de dados de origem para este conjunto de resultados. Contém um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) .|
|[CDaoRecordset:: m_strFilter](#m_strfilter)|Contém uma cadeia de caracteres usada para construir uma instrução SQL **Where** .|
|[CDaoRecordset:: m_strSort](#m_strsort)|Contém uma cadeia de caracteres usada para construir uma instrução SQL **order by** .|

## <a name="remarks"></a>Comentários

Conhecidos como "conjuntos de registros", os objetos `CDaoRecordset` estão disponíveis nas três formas a seguir:

- Os conjuntos de registros de tipo de tabela representam uma tabela base que você pode usar para examinar, adicionar, alterar ou excluir registros de uma única tabela de banco de dados.

- Os conjuntos de registros de tipo dynaset são o resultado de uma consulta que pode ter registros atualizáveis. Esses Recordsets são um conjunto de registros que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela ou tabelas de banco de dados subjacentes. Os conjuntos de registros de tipo dynaset podem conter campos de uma ou mais tabelas em um banco de dados.

- Conjuntos de registros do tipo instantâneo são uma cópia estática de um conjunto de registros que você pode usar para localizar dados ou gerar relatórios. Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados, mas não podem ser atualizados.

Cada formulário de conjunto de registros representa um conjunto de registros corrigidos no momento em que o conjunto de registros é aberto. Quando você rola para um registro em um conjunto de registros de tipo de tabela ou um conjunto de registros de tipo dynaset, ele reflete as alterações feitas no registro após o conjunto de registros ser aberto, seja por outros usuários ou por outros conjuntos de registros em seu aplicativo. (Não é possível atualizar um conjunto de registros do tipo instantâneo.) Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de conjunto de registros específica do aplicativo de `CDaoRecordset`. Em seguida, você pode:

- Percorra os registros.

- Definir um índice e procurar rapidamente os registros usando [Seek](#seek) (somente conjuntos de registros de tipo de tabela).

- Localizar registros com base em uma comparação de cadeia de caracteres: "<", "\<=", "=", "> =" ou ">" (conjuntos de registros tipo dynaset e tipo instantâneo).

- Atualize os registros e especifique um modo de bloqueio (exceto conjuntos de registros do tipo instantâneo).

- Filtre o conjunto de registros para restringir os registros que ele seleciona entre os disponíveis na fonte de dados.

- Classificar o conjunto de registros.

- Parametrizar o conjunto de registros para personalizar sua seleção com informações não conhecidas até o tempo de execução.

A classe `CDaoRecordset` fornece uma interface semelhante à da classe `CRecordset`. A principal diferença é que a classe `CDaoRecordset` acessa dados por meio de um DAO (objeto de acesso a dados) com base em OLE. A classe `CRecordset` acessa o DBMS por meio de ODBC (Open Database Connectivity) e um driver ODBC para esse DBMS.

> [!NOTE]
> As classes de banco de dados DAO são diferentes das classes de banco de dados MFC baseadas em ODBC (Open Database Connectivity). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque são específicas do mecanismo de banco de dados do Microsoft Jet.

Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de `CDaoRecordset`. Para usar uma classe Recordset em ambos os casos, abra um banco de dados e construa um objeto recordset, passando o construtor de um ponteiro para o objeto `CDaoDatabase`. Você também pode construir um objeto de `CDaoRecordset` e permitir que o MFC crie um objeto de `CDaoDatabase` temporário para você. Em seguida, chame a função de membro [Open](#open) do conjunto de registros, especificando se o objeto é um conjunto de registros de tabela, um conjunto de registros de tipo dynaset ou um conjunto de registros do tipo instantâneo. A chamada de `Open` seleciona os dados do banco e recupera o primeiro registro.

Use as funções de membro do objeto e os membros de dados para percorrer os registros e operar neles. As operações disponíveis dependem se o objeto é um conjunto de registros de tipo de tabela, um conjunto de registros de tipo dynaset ou um conjunto de registros do tipo instantâneo, e se ele é atualizável ou somente leitura — isso depende da capacidade do banco de dados ou do ODBC (Open Database Connectivity) fonte de dados. Para atualizar os registros que podem ter sido alterados ou adicionados desde a chamada de `Open`, chame a função de membro [Requery](#requery) do objeto. Chame a função de membro `Close` do objeto e destrua o objeto quando terminar com ele.

`CDaoRecordset` usa o DFX (registro do DAO Record Field) para dar suporte à leitura e à atualização de campos C++ de registro por meio de membros de tipo seguro de sua `CDaoRecordset` ou de sua classe derivada de `CDaoRecordset`. Você também pode implementar a vinculação dinâmica de colunas em um banco de dados sem usar o mecanismo DFX usando [GetFieldValue](#getfieldvalue) e [setfielvalue](#setfieldvalue).

Para obter informações relacionadas, consulte o tópico "objeto recordset" na ajuda do DAO.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDaoRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

##  <a name="addnew"></a>CDaoRecordset:: AddNew

Chame essa função de membro para adicionar um novo registro a um conjunto de registros de tipo de tabela ou tipo dynaset.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Os campos do registro são inicialmente nulos. (Na terminologia do banco de dados, NULL significa "sem valor" e não é o mesmo que NULL C++em.) Para concluir a operação, você deve chamar a função de membro de [atualização](#update) . `Update` salva as alterações na fonte de dados.

> [!CAUTION]
>  Se você editar um registro e, em seguida, rolar para outro registro sem chamar `Update`, suas alterações serão perdidas sem aviso.

Se você adicionar um registro a um conjunto de registros de tipo dynaset chamando [AddNew](#addnew), o registro será visível no conjunto de registros e incluído na tabela subjacente, onde ficará visível para todos os novos objetos `CDaoRecordset`.

A posição do novo registro depende do tipo de conjunto de registros:

- Em um conjunto de registros de tipo dynaset, em que o novo registro é inserido não é garantido. Esse comportamento mudou com o Microsoft Jet 3,0 por motivos de desempenho e simultaneidade. Se o seu objetivo é fazer com que o registro recentemente seja registrado no registro atual, obtenha o indicador do último registro modificado e mova para esse indicador:

[!code-cpp[NVC_MFCDatabase#1](../../mfc/codesnippet/cpp/cdaorecordset-class_1.cpp)]

- Em um conjunto de registros de tipo tabela para o qual um índice foi especificado, os registros são retornados em seu local apropriado na ordem de classificação. Se nenhum índice tiver sido especificado, novos registros serão retornados no final do conjunto de registros.

O registro que era atual antes de você usar `AddNew` permanece atualizado. Se você quiser tornar o novo registro atual e o conjunto de registros oferecer suporte a indicadores, chame [SetBookmark](#setbookmark) para o indicador identificado pela configuração de propriedade LastModified do objeto RECORDSET do DAO subjacente. Fazer isso é útil para determinar o valor dos campos contador (incremento automático) em um registro adicionado. Para obter mais informações, consulte [GetLastModifiedBookmark](#getlastmodifiedbookmark).

Se o banco de dados oferecer suporte a transações, você poderá fazer seu `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte Class [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). Observe que você deve chamar [CDaoWorkspace:: BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans) antes de chamar `AddNew`.

É ilegal chamar `AddNew` para um conjunto de registros cuja função de membro [aberto](#open) não foi chamada. Uma `CDaoException` será gerada se você chamar `AddNew` para um conjunto de registros que não pode ser anexado. Você pode determinar se o conjunto de registros é atualizável chamando [CanAppend](#canappend).

A estrutura marca os membros de dados de campo alterados para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo de intercâmbio de campo de registro do DAO (DFX). A alteração do valor de um campo geralmente define o campo sujo automaticamente, portanto, raramente você precisará chamar o [SetFieldDirty](#setfielddirty) , mas, às vezes, você pode querer garantir que as colunas sejam explicitamente atualizadas ou inseridas, independentemente de qual valor está no membro de dados do campo. O mecanismo DFX também emprega o uso de **pseudo NULL**. Para obter mais informações, consulte [CDaoFieldExchange:: m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, a alteração do valor do campo não definirá automaticamente o campo como sujo. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

> [!NOTE]
> Se os registros forem de buffer duplo (ou seja, a verificação automática de campos estiver habilitada), a chamada a `CancelUpdate` irá restaurar as variáveis de membro para os valores que eles tinham antes `AddNew` ou `Edit` foi chamado.

Para obter informações relacionadas, consulte os tópicos "método AddNew", "método CancelUpdate", "propriedade LastModified" e "Propriedade EditMode" na ajuda do DAO.

##  <a name="canappend"></a>CDaoRecordset:: CanAppend

Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite que você adicione novos registros chamando a função de membro [AddNew](#addnew) .

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros permitir a adição de novos registros; caso contrário, 0. `CanAppend` retornará 0 se você tiver aberto o conjunto de registros como somente leitura.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Método Append" na ajuda do DAO.

##  <a name="canbookmark"></a>CDaoRecordset:: CanBookmark

Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite que você marque individualmente os registros usando indicadores.

```
BOOL CanBookmark();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros der suporte a indicadores, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você estiver usando conjuntos de registros baseados inteiramente em tabelas do mecanismo de banco de dados do Microsoft Jet, os indicadores poderão ser usados, exceto nos conjuntos de registros do tipo instantâneo, sinalizados como conjuntos de registros de rolagem somente de encaminhamento. Outros produtos de banco de dados (fontes ODBC externas) podem não dar suporte a indicadores.

Para obter informações relacionadas, consulte o tópico "propriedade de Indicadorable" na ajuda do DAO.

##  <a name="cancelupdate"></a>CDaoRecordset:: CancelUpdate

A função membro `CancelUpdate` cancela as atualizações pendentes devido a uma operação [Editar](#edit) ou [AddNew](#addnew) .

```
virtual void CancelUpdate();
```

### <a name="remarks"></a>Comentários

Por exemplo, se um aplicativo chama a função de membro `Edit` ou `AddNew` e não chamou [Update](#update), `CancelUpdate` cancela as alterações feitas após `Edit` ou `AddNew` ser chamado.

> [!NOTE]
>  Se os registros forem de buffer duplo (ou seja, a verificação automática de campos estiver habilitada), a chamada a `CancelUpdate` irá restaurar as variáveis de membro para os valores que eles tinham antes `AddNew` ou `Edit` foi chamado.

Se não houver nenhuma operação de `Edit` ou `AddNew` pendente, `CancelUpdate` fará com que o MFC lance uma exceção. Chame a função de membro [GetEditMode](#geteditmode) para determinar se há uma operação pendente que pode ser cancelada.

Para obter informações relacionadas, consulte o tópico "método CancelUpdate" na ajuda do DAO.

##  <a name="canrestart"></a>CDaoRecordset:: Restart

Chame essa função de membro para determinar se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) chamando a função membro `Requery`.

```
BOOL CanRestart();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se `Requery` puder ser chamado para executar a consulta do conjunto de registros novamente, caso contrário 0.

### <a name="remarks"></a>Comentários

Conjuntos de registros de tipo de tabela não dão suporte a `Requery`.

Se não houver suporte para `Requery`, chame [Close](#close) e [abra](#open) para atualizar os dados. Você pode chamar `Requery` para atualizar a consulta de parâmetro subjacente de um objeto Recordset depois que os valores de parâmetro tiverem sido alterados.

Para obter informações relacionadas, consulte o tópico "Propriedade reiniciável" na ajuda do DAO.

##  <a name="canscroll"></a>CDaoRecordset:: canrole

Chame essa função de membro para determinar se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se você puder percorrer os registros, caso contrário 0.

### <a name="remarks"></a>Comentários

Se você chamar [abrir](#open) com `dbForwardOnly`, o conjunto de registros só poderá rolar para frente.

Para obter informações relacionadas, consulte o tópico "posicionando o ponteiro de registro atual com o DAO" na ajuda do DAO.

##  <a name="cantransact"></a>CDaoRecordset:: CanTransact

Chame essa função de membro para determinar se o conjunto de registros permite transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a fonte de dados subjacente der suporte a transações, caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade Transactions" na ajuda do DAO.

##  <a name="canupdate"></a>CDaoRecordset:: CanUpdate

Chame essa função de membro para determinar se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros puder ser atualizado (adicionar, atualizar e excluir registros), caso contrário, 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser somente leitura se a fonte de dados subjacente for somente leitura ou se você tiver especificado `dbReadOnly` para *nOptions* quando você tiver chamado [Open](#open) para o conjunto de registros.

Para obter informações relacionadas, consulte os tópicos "método AddNew", "Editar método", "Excluir método", "método de atualização" e "Propriedade atualizável" na ajuda do DAO.

##  <a name="cdaorecordset"></a>CDaoRecordset::CDaoRecordset

Constrói um objeto `CDaoRecordset`.

```
CDaoRecordset(CDaoDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>parâmetros

*pDatabase*<br/>
Contém um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou o valor NULL. Se não for nulo e a função de membro `Open` do objeto de `CDaoDatabase` não tiver sido chamada para conectá-lo à fonte de dados, o conjunto de registros tentará abri-lo para você durante sua própria chamada [aberta](#open) . Se você passar NULL, um objeto `CDaoDatabase` será construído e conectado para você usando as informações da fonte de dados que você especificou se tiver derivado a classe recordset de `CDaoRecordset`.

### <a name="remarks"></a>Comentários

Você pode usar o `CDaoRecordset` diretamente ou derivar uma classe específica do aplicativo do `CDaoRecordset`. Você pode usar ClassWizard para derivar suas classes do conjunto de registros.

> [!NOTE]
>  Se você derivar uma classe de `CDaoRecordset`, sua classe derivada deverá fornecer seu próprio construtor. No construtor de sua classe derivada, chame o Construtor `CDaoRecordset::CDaoRecordset`, passando os parâmetros apropriados junto com ele.

Passe NULL para o construtor do conjunto de registros para ter um objeto `CDaoDatabase` construído e conectado para você automaticamente. Esse é um atalho útil que não exige que você construa e conecte um objeto `CDaoDatabase` antes de construir seu conjunto de registros. Se o objeto `CDaoDatabase` não estiver aberto, um objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) também será criado para você que usa o espaço de trabalho padrão. Para obter mais informações, consulte [CDaoDatabase:: CDaoDatabase](../../mfc/reference/cdaodatabase-class.md#cdaodatabase).

##  <a name="close"></a>CDaoRecordset:: fechar

Fechar um `CDaoRecordset` objeto remove-o da coleção de conjuntos de registros abertos no banco de dados associado.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Como `Close` não destrói o objeto `CDaoRecordset`, você pode reutilizar o objeto chamando `Open` na mesma fonte de dados ou em uma fonte de dados diferente.

Todas as instruções [AddNew](#addnew) ou [Edit](#edit) pendentes são canceladas e todas as transações pendentes são revertidas. Se você quiser preservar inclusões ou edições pendentes, chame [Update](#update) antes de chamar `Close` para cada conjunto de registros.

Você pode chamar `Open` novamente após a chamada de `Close`. Isso permite que você reutilize o objeto Recordset. Uma alternativa melhor é chamar [Requery](#requery), se possível.

Para obter informações relacionadas, consulte o tópico "Close Method" na ajuda do DAO.

##  <a name="delete"></a>CDaoRecordset::D excluir

Chame essa função de membro para excluir o registro atual em um objeto Open tipo dynaset ou Recordset do tipo Table.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após uma exclusão bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor nulo e você deve chamar explicitamente uma das funções de membro de navegação do conjunto de registros ( [mover](#move), [buscar](#seek), [SetBookmark](#setbookmark)e assim por diante) para sair do registro excluído. Quando você exclui registros de um conjunto de registros, deve haver um registro atual no conjunto de registros antes de chamar `Delete`; caso contrário, o MFC lançará uma exceção.

`Delete` remove o registro atual e o torna inacessível. Embora você não possa editar ou usar o registro excluído, ele permanece atualizado. No entanto, quando você passa para outro registro, não é possível tornar o registro excluído atual novamente.

> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve haver um registro válido atual no conjunto de registros quando você chama `Delete`. Por exemplo, se você excluir um registro, mas não rolar para um novo registro antes de chamar `Delete` novamente, `Delete` lançará um [CDaoException](../../mfc/reference/cdaoexception-class.md).

Você pode desfazer a exclusão de um registro se usar transações e chamar a função de membro [CDaoWorkspace:: Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) . Se a tabela base for a tabela primária em uma relação de exclusão em cascata, excluir o registro atual também poderá excluir um ou mais registros em uma tabela estrangeira. Para obter mais informações, consulte a definição "exclusão em cascata" na ajuda do DAO.

Ao contrário de `AddNew` e `Edit`, uma chamada para `Delete` não é seguida por uma chamada para `Update`.

Para obter informações relacionadas, consulte os tópicos "método AddNew", "Editar método", "Excluir método", "método de atualização" e "Propriedade atualizável" na ajuda do DAO.

##  <a name="dofieldexchange"></a>CDaoRecordset::D oFieldExchange

A estrutura chama essa função de membro para trocar dados automaticamente entre os membros de dados de campo do seu objeto Recordset e as colunas correspondentes do registro atual na fonte de dados.

```
virtual void DoFieldExchange(CDaoFieldExchange* pFX);
```

### <a name="parameters"></a>parâmetros

*pFX*<br/>
Contém um ponteiro para um objeto `CDaoFieldExchange`. A estrutura já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Ele também associa seus membros de dados de parâmetro, se houver, aos espaços reservados de parâmetro na cadeia de caracteres da instrução SQL para a seleção do conjunto de registros. A troca de dados de campo, chamada de DFX (registro de campo de registros DAO), funciona em ambas as direções: dos membros de dados de campo do objeto Recordset para os campos do registro na fonte de dados e do registro na fonte de dados para o objeto Recordset. Se você estiver associando colunas dinamicamente, não será necessário implementar `DoFieldExchange`.

A única ação que você deve executar normalmente para implementar `DoFieldExchange` para sua classe de conjunto de registros derivada é criar a classe com ClassWizard e especificar os nomes e tipos de dados dos membros de dados de campo. Você também pode adicionar código ao que ClassWizard escreve para especificar membros de dados de parâmetro. Se todos os campos forem vinculados dinamicamente, essa função ficará inativa, a menos que você especifique membros de dados de parâmetro.

Quando você declara sua classe de conjunto de registros derivada com ClassWizard, o assistente grava uma substituição de `DoFieldExchange` para você, que se assemelha ao exemplo a seguir:

[!code-cpp[NVC_MFCDatabase#2](../../mfc/codesnippet/cpp/cdaorecordset-class_2.cpp)]

##  <a name="edit"></a>CDaoRecordset:: editar

Chame essa função de membro para permitir alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Depois de chamar a função de membro `Edit`, as alterações feitas nos campos do registro atual são copiadas para o buffer de cópia. Depois de fazer as alterações desejadas no registro, chame `Update` para salvar suas alterações. `Edit` salva os valores dos membros de dados do conjunto de registros. Se você chamar `Edit`, fazer alterações e, em seguida, chamar `Edit` novamente, os valores do registro serão restaurados para o que estavam antes da primeira chamada de `Edit`.

> [!CAUTION]
>  Se você editar um registro e, em seguida, executar qualquer operação que se mova para outro registro sem primeiro chamar `Update`, suas alterações serão perdidas sem aviso. Além disso, se você fechar o conjunto de registros ou o banco de dados pai, seu registro editado será descartado sem aviso.

Em alguns casos, talvez você queira atualizar uma coluna tornando-a nula (que não contém dados). Para fazer isso, chame `SetFieldNull` com um parâmetro de TRUE para marcar o campo como nulo; Isso também faz com que a coluna seja atualizada. Se você quiser que um campo seja gravado na fonte de dados, mesmo que seu valor não tenha sido alterado, chame `SetFieldDirty` com um parâmetro de TRUE. Isso funciona mesmo que o campo tenha o valor NULL.

A estrutura marca os membros de dados de campo alterados para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo de intercâmbio de campo de registro do DAO (DFX). A alteração do valor de um campo geralmente define o campo sujo automaticamente, portanto, raramente você precisará chamar o [SetFieldDirty](#setfielddirty) , mas, às vezes, você pode querer garantir que as colunas sejam explicitamente atualizadas ou inseridas, independentemente de qual valor está no membro de dados do campo. O mecanismo DFX também emprega o uso de **pseudo NULL**. Para obter mais informações, consulte [CDaoFieldExchange:: m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, a alteração do valor do campo não definirá automaticamente o campo como sujo. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

Quando o objeto Recordset é pessimistically bloqueado em um ambiente multiusuário, o registro permanece bloqueado da hora `Edit` é usado até que a atualização seja concluída. Se o conjunto de registros estiver bloqueado de forma otimista, o registro será bloqueado e comparado com o registro previamente editado antes de ser atualizado no banco de dados. Se o registro tiver sido alterado desde que você chamou `Edit`, a operação de `Update` falhará e o MFC lançará uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.

> [!NOTE]
>  O bloqueio otimista sempre é usado em formatos de banco de dados externos, como ODBC e ISAM instalável.

O registro atual permanece atual depois que você chama `Edit`. Para chamar `Edit`, deve haver um registro atual. Se não houver registro atual ou se o conjunto de registros não se referir a um objeto Open Table-Type ou Recordset do tipo dynaset, ocorrerá uma exceção. Chamar `Edit` faz com que uma `CDaoException` seja lançada sob as seguintes condições:

- Não há registro atual.

- O banco de dados ou conjunto de registros é somente leitura.

- Nenhum campo no registro é atualizável.

- O banco de dados ou conjunto de registros foi aberto para uso exclusivo por outro usuário.

- Outro usuário bloqueou a página que contém o registro.

Se a fonte de dados der suporte a transações, você poderá fazer com que o `Edit` chame parte de uma transação. Observe que você deve chamar `CDaoWorkspace::BeginTrans` antes de chamar `Edit` e depois que o conjunto de registros tiver sido aberto. Observe também que a chamada de `CDaoWorkspace::CommitTrans` não é um substituto para a chamada de `Update` para concluir a operação de `Edit`. Para obter mais informações sobre transações, consulte classe `CDaoWorkspace`.

Para obter informações relacionadas, consulte os tópicos "método AddNew", "Editar método", "Excluir método", "método de atualização" e "Propriedade atualizável" na ajuda do DAO.

##  <a name="fillcache"></a>CDaoRecordset:: FillCache

Chame essa função de membro para armazenar em cache um número especificado de registros do conjunto de registros.

```
void FillCache(
    long* pSize = NULL,
    COleVariant* pBookmark = NULL);
```

### <a name="parameters"></a>parâmetros

*pSize*<br/>
Especifica o número de linhas para preencher o cache. Se você omitir esse parâmetro, o valor será determinado pela configuração da propriedade CacheSize do objeto DAO subjacente.

*pBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) que especifica um indicador. O cache é preenchido a partir do registro indicado por este indicador. Se você omitir esse parâmetro, o cache será preenchido a partir do registro indicado pela propriedade CacheStart do objeto DAO subjacente.

### <a name="remarks"></a>Comentários

O Caching melhora o desempenho de um aplicativo que recupera ou busca dados de um servidor remoto. Um cache é o espaço na memória local que contém os dados buscados mais recentemente do servidor na suposição de que os dados provavelmente serão solicitados novamente enquanto o aplicativo estiver em execução. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica o cache primeiro para os dados em vez de obtê-lo do servidor, o que leva mais tempo. O uso do cache de dados em fontes de dados não-ODBC não tem nenhum efeito, pois os dados não são salvos no cache.

Em vez de esperar que o cache seja preenchido com registros à medida que eles são buscados, você pode preencher explicitamente o cache a qualquer momento chamando a função membro `FillCache`. Essa é uma maneira mais rápida de preencher o cache porque `FillCache` busca vários registros ao mesmo tempo, em vez de um de cada vez. Por exemplo, enquanto cada tela de registros está sendo exibida, você pode fazer com que seu aplicativo chame `FillCache` para buscar a próxima tela de registros.

Qualquer banco de dados ODBC acessado com objetos Recordset pode ter um cache local. Para criar o cache, abra um objeto Recordset da fonte de dados remota e, em seguida, chame as funções de membro `SetCacheSize` e `SetCacheStart` do conjunto de registros. Se *lSize* e *lBookmark* criarem um intervalo que está parcialmente ou totalmente fora do intervalo especificado por `SetCacheSize` e `SetCacheStart`, a parte do conjunto de registros fora desse intervalo será ignorada e não será carregada no cache. Se `FillCache` solicitar mais registros do que o restante na fonte de dados remota, somente os registros restantes serão buscados e nenhuma exceção será lançada.

Os registros obtidos do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.

`FillCache` busca somente registros que ainda não estão em cache. Para forçar uma atualização de todos os dados armazenados em cache, chame a função membro `SetCacheSize` com um parâmetro *lSize* igual a 0, chame `SetCacheSize` novamente com o parâmetro *lSize* igual ao tamanho do cache que você solicitou originalmente e, em seguida, chame `FillCache`.

Para obter informações relacionadas, consulte o tópico "método FillCache" na ajuda do DAO.

##  <a name="find"></a>CDaoRecordset:: find

Chame essa função de membro para localizar uma cadeia de caracteres específica em um conjunto de registros de tipo dynaset ou instantâneo usando um operador de comparação.

```
virtual BOOL Find(
    long lFindType,
    LPCTSTR lpszFilter);
```

### <a name="parameters"></a>parâmetros

*lFindType*<br/>
Um valor que indica o tipo de operação de localização desejado. Os valores possíveis são:

- AFX_DAO_NEXT encontrar o próximo local de uma cadeia de caracteres correspondente.

- AFX_DAO_PREV localizar o local anterior de uma cadeia de caracteres correspondente.

- AFX_DAO_FIRST localizar o primeiro local de uma cadeia de caracteres correspondente.

- AFX_DAO_LAST encontrar o último local de uma cadeia de caracteres correspondente.

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como a cláusula **Where** em uma instrução SQL sem a palavra **Where**) usada para localizar o registro. Por exemplo:

[!code-cpp[NVC_MFCDatabase#3](../../mfc/codesnippet/cpp/cdaorecordset-class_3.cpp)]

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode encontrar a primeira, próxima, anterior ou última instância da cadeia de caracteres. `Find` é uma função virtual, para que você possa substituí-la e adicionar sua própria implementação. As funções de membro `FindFirst`, `FindLast`, `FindNext`e `FindPrev` chamam a função membro `Find`, para que você possa usar `Find` para controlar o comportamento de todas as operações de localização.

Para localizar um registro em um conjunto de registros de tipo tabela, chame a função de membro [Seek](#seek) .

> [!TIP]
>  Quanto menor o conjunto de registros que você tem, mais efetivo `Find` será. Em geral, e especialmente com dados ODBC, é melhor criar uma nova consulta que recupere apenas os registros desejados.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious methods" na ajuda do DAO.

##  <a name="findfirst"></a>CDaoRecordset:: FindFirst

Chame essa função de membro para localizar o primeiro registro que corresponde a uma condição especificada.

```
BOOL FindFirst(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como a cláusula **Where** em uma instrução SQL sem a palavra **Where**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

A função membro `FindFirst` começa sua pesquisa desde o início do conjunto de registros e pesquisa até o final do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica), use uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros de tipo tabela, chame a função membro `Seek`.

Se um registro correspondente aos critérios não estiver localizado, o ponteiro de registro atual não será determinado e `FindFirst` retornará zero. Se o conjunto de registros contiver mais de um registro que satisfaça os critérios, `FindFirst` localizar a primeira ocorrência, `FindNext` localizará a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações chamando a função de membro `Update` antes de mover para outro registro. Se você mover para outro registro sem Atualizar, suas alterações serão perdidas sem aviso.

O `Find` funções membro pesquisa a partir do local e na direção especificada na tabela a seguir:

|Operações de localização|Begin|Direção da pesquisa|
|---------------------|-----------|----------------------|
|`FindFirst`|Início do conjunto de registros|Fim do conjunto de registros|
|`FindLast`|Fim do conjunto de registros|Início do conjunto de registros|
|`FindNext`|Registro atual|Fim do conjunto de registros|
|`FindPrevious`|Registro atual|Início do conjunto de registros|

> [!NOTE]
>  Quando você chama `FindLast`, o mecanismo de banco de dados do Microsoft Jet preenche totalmente o conjunto de registros antes de iniciar a pesquisa, caso isso ainda não tenha sido feito. A primeira pesquisa pode levar mais tempo do que as pesquisas subsequentes.

O uso de uma das operações localizar não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode seguir uma operação Localizar com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações localizar:

- Se `Find` retornar zero, o registro atual não será definido. Nesse caso, você deve posicionar o ponteiro de registro atual de volta para um registro válido.

- Não é possível usar uma operação Localizar com um conjunto de registros de deslocamento de tipo instantâneo de somente avanço.

- Você deve usar o formato de data dos EUA (mês-dia-ano) ao Pesquisar campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; caso contrário, os registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações localizar é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com cláusulas **ORDERBY** ou **Where** personalizadas, consultas de parâmetro ou objetos `CDaoQuerydef` que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious methods" na ajuda do DAO.

##  <a name="findlast"></a>CDaoRecordset:: FindLast

Chame essa função de membro para localizar o último registro que corresponde a uma condição especificada.

```
BOOL FindLast(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como a cláusula **Where** em uma instrução SQL sem a palavra **Where**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

A função membro `FindLast` começa sua pesquisa no final do conjunto de registros e pesquisa para trás até o início do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica), use uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros de tipo tabela, chame a função membro `Seek`.

Se um registro correspondente aos critérios não estiver localizado, o ponteiro de registro atual não será determinado e `FindLast` retornará zero. Se o conjunto de registros contiver mais de um registro que satisfaça os critérios, `FindFirst` localizar a primeira ocorrência, `FindNext` localizará a próxima ocorrência após a primeira ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações chamando a função de membro `Update` antes de mover para outro registro. Se você mover para outro registro sem Atualizar, suas alterações serão perdidas sem aviso.

O uso de uma das operações localizar não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode seguir uma operação Localizar com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações localizar:

- Se `Find` retornar zero, o registro atual não será definido. Nesse caso, você deve posicionar o ponteiro de registro atual de volta para um registro válido.

- Não é possível usar uma operação Localizar com um conjunto de registros de deslocamento de tipo instantâneo de somente avanço.

- Você deve usar o formato de data dos EUA (mês-dia-ano) ao Pesquisar campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; caso contrário, os registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações localizar é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com cláusulas **ORDERBY** ou **Where** personalizadas, consultas de parâmetro ou objetos `CDaoQuerydef` que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious methods" na ajuda do DAO.

##  <a name="findnext"></a>CDaoRecordset:: LocalizarPróximo

Chame essa função de membro para localizar o próximo registro que corresponde a uma condição especificada.

```
BOOL FindNext(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como a cláusula **Where** em uma instrução SQL sem a palavra **Where**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

A função membro `FindNext` começa sua pesquisa no registro atual e pesquisa até o final do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica), use uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros de tipo tabela, chame a função membro `Seek`.

Se um registro correspondente aos critérios não estiver localizado, o ponteiro de registro atual não será determinado e `FindNext` retornará zero. Se o conjunto de registros contiver mais de um registro que satisfaça os critérios, `FindFirst` localizar a primeira ocorrência, `FindNext` localizará a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações chamando a função de membro `Update` antes de mover para outro registro. Se você mover para outro registro sem Atualizar, suas alterações serão perdidas sem aviso.

O uso de uma das operações localizar não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode seguir uma operação Localizar com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações localizar:

- Se `Find` retornar zero, o registro atual não será definido. Nesse caso, você deve posicionar o ponteiro de registro atual de volta para um registro válido.

- Não é possível usar uma operação Localizar com um conjunto de registros de deslocamento de tipo instantâneo de somente avanço.

- Você deve usar o formato de data dos EUA (mês-dia-ano) ao Pesquisar campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; caso contrário, os registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações localizar é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com cláusulas **ORDERBY** ou **Where** personalizadas, consultas de parâmetro ou objetos `CDaoQuerydef` que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious methods" na ajuda do DAO.

##  <a name="findprev"></a>CDaoRecordset::FindPrev

Chame essa função de membro para localizar o registro anterior que corresponde a uma condição especificada.

```
BOOL FindPrev(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>parâmetros

*lpszFilter*<br/>
Uma expressão de cadeia de caracteres (como a cláusula **Where** em uma instrução SQL sem a palavra **Where**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

A função membro `FindPrev` começa sua pesquisa no registro atual e pesquisa para trás até o início do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica), use uma das operações de movimentação para mover de registro para registro. Para localizar um registro em um conjunto de registros de tipo tabela, chame a função membro `Seek`.

Se um registro correspondente aos critérios não estiver localizado, o ponteiro de registro atual não será determinado e `FindPrev` retornará zero. Se o conjunto de registros contiver mais de um registro que satisfaça os critérios, `FindFirst` localizar a primeira ocorrência, `FindNext` localizará a próxima ocorrência e assim por diante.

> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações chamando a função de membro `Update` antes de mover para outro registro. Se você mover para outro registro sem Atualizar, suas alterações serão perdidas sem aviso.

O uso de uma das operações localizar não é o mesmo que chamar `MoveFirst` ou `MoveNext`, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode seguir uma operação Localizar com uma operação de movimentação.

Tenha em mente o seguinte ao usar as operações localizar:

- Se `Find` retornar zero, o registro atual não será definido. Nesse caso, você deve posicionar o ponteiro de registro atual de volta para um registro válido.

- Não é possível usar uma operação Localizar com um conjunto de registros de deslocamento de tipo instantâneo de somente avanço.

- Você deve usar o formato de data dos EUA (mês-dia-ano) ao Pesquisar campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; caso contrário, os registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações localizar é lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com cláusulas **ORDERBY** ou **Where** personalizadas, consultas de parâmetro ou objetos `CDaoQuerydef` que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious methods" na ajuda do DAO.

##  <a name="getabsoluteposition"></a>CDaoRecordset::GetAbsolutePosition

Retorna o número de registro do registro atual de um objeto Recordset.

```
long GetAbsolutePosition();
```

### <a name="return-value"></a>Valor retornado

Um número inteiro de 0 até o número de registros no conjunto de registros. Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se ao primeiro registro no conjunto de registros. Você pode determinar o número de registros populados no conjunto de registros chamando [GetRecordCount](#getrecordcount). Chamar `GetRecordCount` pode levar algum tempo porque ele deve acessar todos os registros para determinar a contagem.

Se não houver registro atual, como quando não houver registros no conjunto de registros,-1 será retornado. Se o registro atual for excluído, o valor da propriedade AbsolutePosition não será definido e o MFC gerará uma exceção se ela for referenciada. Para conjuntos de registros de tipo dynaset, novos registros são adicionados ao final da sequência.

> [!NOTE]
>  Esta propriedade não deve ser usada como um número de registro substituto. Os indicadores ainda são a maneira recomendada de reter e retornar a uma determinada posição e são a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros. Em particular, a posição de um determinado registro é alterada quando os registros anteriores a ele são excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem dos registros individuais em um conjunto de registros não é garantida, a menos que ele seja criado com uma instrução SQL usando uma cláusula **ORDERBY** .

> [!NOTE]
>  Essa função de membro é válida somente para conjuntos de registros tipo dynaset e tipo de instantâneo.

Para obter informações relacionadas, consulte o tópico "propriedade AbsolutePosition" na ajuda do DAO.

##  <a name="getbookmark"></a>CDaoRecordset:: GetBookmark

Chame essa função de membro para obter o valor de indicador em um registro específico.

```
COleVariant GetBookmark();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que representa o indicador no registro atual.

### <a name="remarks"></a>Comentários

Quando um objeto Recordset for criado ou aberto, cada um de seus registros já terá um indicador exclusivo se ele der suporte a eles. Chame `CanBookmark` para determinar se um conjunto de registros dá suporte a indicadores.

Você pode salvar o indicador para o registro atual atribuindo o valor do indicador a um objeto `COleVariant`. Para retornar rapidamente a esse registro a qualquer momento após a mudança para um registro diferente, chame `SetBookmark` com um parâmetro correspondente ao valor desse objeto `COleVariant`.

> [!NOTE]
>  Chamar as alterações de [repetição](#requery) altera os indicadores do DAO.

Para obter informações relacionadas, consulte o tópico "propriedade de indicador" na ajuda do DAO.

##  <a name="getcachesize"></a>CDaoRecordset::GetCacheSize

Chame essa função de membro para obter o número de registros armazenados em cache.

```
long GetCacheSize();
```

### <a name="return-value"></a>Valor retornado

Um valor que especifica o número de registros em um conjunto de registros de tipo dynaset que contém dados a serem armazenados localmente em cache de uma fonte de dados ODBC.

### <a name="remarks"></a>Comentários

O cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos Recordset do tipo dynaset. Um cache é um espaço na memória local que contém os dados recuperados mais recentemente do servidor, caso os dados sejam solicitados novamente enquanto o aplicativo estiver em execução. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica primeiro os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Os dados que não são provenientes de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na ajuda do DAO.

##  <a name="getcachestart"></a>CDaoRecordset::GetCacheStart

Chame essa função de membro para obter o valor de indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
COleVariant GetCacheStart();
```

### <a name="return-value"></a>Valor retornado

Um `COleVariant` que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

O mecanismo de banco de dados do Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.

> [!NOTE]
>  Os registros recuperados do cache não refletem as alterações feitas simultaneamente para os dados de origem por outros usuários.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na ajuda do DAO.

##  <a name="getcurrentindex"></a>CDaoRecordset::GetCurrentIndex

Chame essa função de membro para determinar o índice em uso no momento em um objeto de `CDaoRecordset` de tipo de tabela indexada.

```
CString GetCurrentIndex();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém o nome do índice em uso no momento com um conjunto de registros de tipo de tabela. Retorna uma cadeia de caracteres vazia se nenhum índice tiver sido definido.

### <a name="remarks"></a>Comentários

Esse índice é a base para ordenar registros em um conjunto de registros de tipo de tabela e é usado pela função de membro [Seek](#seek) para localizar registros.

Um objeto `CDaoRecordset` pode ter mais de um índice, mas pode usar apenas um índice por vez (embora um objeto [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) possa ter vários índices definidos nele).

Para obter informações relacionadas, consulte o tópico "objeto de índice" e a definição "índice atual" na ajuda do DAO.

##  <a name="getdatecreated"></a>CDaoRecordset::GetDateCreated

Chame essa função de membro para recuperar a data e a hora em que uma tabela base foi criada.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data e a hora em que a tabela base foi criada.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada.

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

##  <a name="getdatelastupdated"></a>CDaoRecordset::GetDateLastUpdated

Chame essa função de membro para recuperar a data e a hora em que o esquema foi atualizado pela última vez.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data e a hora em que a estrutura da tabela base (esquema) foi atualizada pela última vez.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a estrutura de tabela base (esquema) foi atualizada pela última vez.

Para obter informações relacionadas, consulte o tópico "DateCreated, Propriedades LastUpdated" na ajuda do DAO.

##  <a name="getdefaultdbname"></a>CDaoRecordset::GetDefaultDBName

Chame essa função de membro para determinar o nome do banco de dados para este conjunto de registros.

```
virtual CString GetDefaultDBName();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém o caminho e o nome do banco de dados do qual este conjunto de registros é derivado.

### <a name="remarks"></a>Comentários

Se um conjunto de registros for criado sem um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md), esse caminho será usado pelo conjunto de registros para abrir o banco de dados padrão. Por padrão, essa função retorna uma cadeia de caracteres vazia. Quando ClassWizard deriva um novo conjunto de registros de `CDaoRecordset`, ele criará essa função para você.

O exemplo a seguir ilustra o uso da barra invertida dupla (\\\\) na cadeia de caracteres, conforme necessário para que a cadeia de caracteres seja interpretada corretamente.

[!code-cpp[NVC_MFCDatabase#4](../../mfc/codesnippet/cpp/cdaorecordset-class_4.cpp)]

##  <a name="getdefaultsql"></a>CDaoRecordset::GetDefaultSQL

A estrutura chama essa função de membro para obter a instrução SQL padrão na qual o conjunto de registros é baseado.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém a instrução SQL padrão.

### <a name="remarks"></a>Comentários

Pode ser um nome de tabela ou uma instrução SQL **Select** .

Você define indiretamente a instrução SQL padrão declarando sua classe recordset com ClassWizard e ClassWizard executa essa tarefa para você.

Se você passar uma cadeia de caracteres SQL nula para [abrir](#open), essa função será chamada para determinar o nome da tabela ou o SQL do conjunto de registros.

##  <a name="geteditmode"></a>CDaoRecordset:: GetEditMode

Chame essa função de membro para determinar o estado de edição, que é um dos seguintes valores:

```
short GetEditMode();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que indica o estado de edição para o registro atual.

### <a name="remarks"></a>Comentários

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|`dbEditNone`|Nenhuma operação de edição está em andamento.|
|`dbEditInProgress`|O `Edit` foi chamado.|
|`dbEditAdd`|O `AddNew` foi chamado.|

Para obter informações relacionadas, consulte o tópico "Propriedade EditMode" na ajuda do DAO.

##  <a name="getfieldcount"></a>CDaoRecordset::GetFieldCount

Chame essa função de membro para recuperar o número de campos (colunas) definidos no conjunto de registros.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "propriedade de contagem" na ajuda do DAO.

##  <a name="getfieldinfo"></a>CDaoRecordset:: GetFieldInfo

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

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do campo predefinido na coleção Fields do conjunto de registros, para pesquisa por índice.

*FieldInfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) .

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros recuperar. As opções disponíveis são listadas aqui junto com o que fazem a função retornar. Para obter o melhor desempenho, recupere apenas o nível de informações de que você precisa:

- `AFX_DAO_PRIMARY_INFO` (padrão) nome, tipo, tamanho, atributos

- `AFX_DAO_SECONDARY_INFO` informações primárias, mais: posição ordinal, obrigatório, permitir comprimento zero, ordem de agrupamento, nome estrangeiro, campo de origem, tabela de origem

- `AFX_DAO_ALL_INFO` informações primárias e secundárias, mais: valor padrão, regra de validação, texto de validação

*lpszName*<br/>
O nome do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você pesquise um campo por índice. A outra versão permite pesquisar um campo por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você obtém informações para todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getfieldvalue"></a>CDaoRecordset::GetFieldValue

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

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.

*varValue*<br/>
Uma referência a um objeto `COleVariant` que armazenará o valor de um campo.

*nIndex*<br/>
Um índice de base zero do campo na coleção de campos do conjunto de registros, para pesquisa por índice.

### <a name="return-value"></a>Valor retornado

As duas versões de `GetFieldValue` que retornam um valor retornam um objeto [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor de um campo.

### <a name="remarks"></a>Comentários

Você pode procurar um campo por nome ou pela posição ordinal.

> [!NOTE]
>  É mais eficiente chamar uma das versões dessa função de membro que usa uma referência de objeto `COleVariant` como um parâmetro, em vez de chamar uma versão que retorna um objeto `COleVariant`. As últimas versões dessa função são mantidas para compatibilidade com versões anteriores.

Use `GetFieldValue` e [Setfielvalue](#setfieldvalue) para vincular dinamicamente campos em tempo de execução em vez de fazer a ligação estática de colunas usando o mecanismo [DoFieldExchange](#dofieldexchange) .

`GetFieldValue` e o mecanismo de `DoFieldExchange` podem ser combinados para melhorar o desempenho. Por exemplo, use `GetFieldValue` para recuperar um valor que você precisa apenas sob demanda e atribua essa chamada a um botão "mais informações" na interface.

Para obter informações relacionadas, consulte os tópicos "objeto de campo" e "propriedade de valor" na ajuda do DAO.

##  <a name="getindexcount"></a>CDaoRecordset::GetIndexCount

Chame essa função de membro para determinar o número de índices disponíveis no conjunto de registros de tipo de tabela.

```
short GetIndexCount();
```

### <a name="return-value"></a>Valor retornado

O número de índices no conjunto de registros de tipo de tabela.

### <a name="remarks"></a>Comentários

`GetIndexCount` é útil para executar um loop por todos os índices no conjunto de registros. Para essa finalidade, use `GetIndexCount` em conjunto com [GetIndexInfo](#getindexinfo). Se você chamar essa função de membro nos conjuntos de registros tipo dynaset ou instantâneo, o MFC lançará uma exceção.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getindexinfo"></a>CDaoRecordset::GetIndexInfo

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

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero na coleção de índices da tabela, para pesquisa por posição numérica.

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) .

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o índice recuperar. As opções disponíveis são listadas aqui junto com o que fazem a função retornar. Para obter o melhor desempenho, recupere apenas o nível de informações de que você precisa:

- `AFX_DAO_PRIMARY_INFO` (padrão) nome, informações do campo, campos

- `AFX_DAO_SECONDARY_INFO` informações primárias, além de: primário, exclusivo, clusterizado, IgnoreNulls, obrigatório, estrangeiro

- `AFX_DAO_ALL_INFO` informações primárias e secundárias, além: contagem distinta

*lpszName*<br/>
Um ponteiro para o nome do objeto de índice, para pesquisa por nome.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) . Essa estrutura tem membros que correspondem aos itens de informações listados acima na descrição de *dwInfoOptions*. Ao solicitar informações em um nível, você obtém informações para todos os níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "propriedade Attributes" na ajuda do DAO.

##  <a name="getlastmodifiedbookmark"></a>CDaoRecordset::GetLastModifiedBookmark

Chame essa função de membro para recuperar o indicador do registro mais recentemente adicionado ou atualizado.

```
COleVariant GetLastModifiedBookmark();
```

### <a name="return-value"></a>Valor retornado

Uma `COleVariant` que contém um indicador que indica o registro adicionado ou alterado mais recentemente.

### <a name="remarks"></a>Comentários

Quando um objeto Recordset for criado ou aberto, cada um de seus registros já terá um indicador exclusivo se ele der suporte a eles. Chame [GetBookmark](#getbookmark) para determinar se o conjunto de registros dá suporte a indicadores. Se o conjunto de registros não oferecer suporte a indicadores, um `CDaoException` será gerado.

Quando você adiciona um registro, ele é exibido no final do conjunto de registros e não é o registro atual. Para tornar o novo registro atual, chame `GetLastModifiedBookmark` e, em seguida, chame `SetBookmark` para retornar ao registro recém-adicionado.

Para obter informações relacionadas, consulte o tópico "propriedade LastModified" na ajuda do DAO.

##  <a name="getlockingmode"></a>CDaoRecordset:: getlockmode

Chame essa função de membro para determinar o tipo de bloqueio em vigor para o conjunto de registros.

```
BOOL GetLockingMode();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o tipo de bloqueio for pessimista, caso contrário 0 para o bloqueio de registro otimista.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista estiver em vigor, a página de dados que contém o registro que você está editando será bloqueada assim que você chamar a função [Editar](#edit) membro. A página é desbloqueada quando você chama a função de membro [Update](#update) ou [Close](#close) ou qualquer uma das operações de movimentação ou localização.

Quando o bloqueio otimista está em vigor, a página de dados que contém o registro é bloqueada somente enquanto o registro está sendo atualizado com a função membro `Update`.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

Para obter informações relacionadas, consulte os tópicos "Propriedade do LockEdits" e "comportamento de bloqueio em aplicativos multiusuário" na ajuda do DAO.

##  <a name="getname"></a>CDaoRecordset:: GetName

Chame essa função de membro para recuperar o nome do conjunto de registros.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém o nome do conjunto de registros.

### <a name="remarks"></a>Comentários

O nome do conjunto de registros deve começar com uma letra e pode conter no máximo 40 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "propriedade de nome" na ajuda do DAO.

##  <a name="getparamvalue"></a>CDaoRecordset:: GetParamValue

Chame essa função de membro para recuperar o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.

```
virtual COleVariant GetParamValue(int nIndex);
virtual COleVariant GetParamValue(LPCTSTR lpszName);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
A posição numérica do parâmetro no objeto DAOParameter subjacente.

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja.

### <a name="return-value"></a>Valor retornado

Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.

### <a name="remarks"></a>Comentários

Você pode acessar o parâmetro por nome ou por sua posição numérica na coleção.

Para obter informações relacionadas, consulte o tópico "objeto de parâmetro" na ajuda do DAO.

##  <a name="getpercentposition"></a>CDaoRecordset::GetPercentPosition

Ao trabalhar com um conjunto de registros de tipo dynaset ou de instantâneo, se você chamar `GetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimentação será relativa ao número de registros acessados conforme indicado chamando [GetRecordCount](#getrecordcount).

```
float GetPercentPosition();
```

### <a name="return-value"></a>Valor retornado

Um número entre 0 e 100 que indica o local aproximado do registro atual no objeto Recordset com base em uma porcentagem dos registros no conjunto de registros.

### <a name="remarks"></a>Comentários

Você pode mover para o último registro chamando [MoveLast](#movelast) para concluir a população de todos os conjuntos de registros, mas isso pode levar um tempo significativo.

Você pode chamar `GetPercentPosition` em todos os três tipos de objetos recordset, incluindo tabelas sem índices. No entanto, você não pode chamar `GetPercentPosition` em instantâneos de rolagem somente de encaminhamento ou em um conjunto de registros aberto de uma consulta de passagem em um banco de dados externo. Se não houver registro atual ou se o registro atual tiver sido excluído, um `CDaoException` será lançado.

Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na ajuda do DAO.

##  <a name="getrecordcount"></a>CDaoRecordset::GetRecordCount

Chame essa função de membro para descobrir quantos registros em um conjunto de registros foram acessados.

```
long GetRecordCount();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de registros acessados em um objeto Recordset.

### <a name="remarks"></a>Comentários

`GetRecordCount` não indica quantos registros estão contidos em um conjunto de registros de tipo dynaset ou instantâneo, até que todos os registros tenham sido acessados. Essa chamada de função de membro pode levar uma quantidade significativa de tempo para ser concluída.

Depois que o último registro tiver sido acessado, o valor de retorno indicará o número total de registros não excluídos no conjunto de registros. Para forçar o acesso do último registro, chame a função de membro `MoveLast` ou `FindLast` para o conjunto de registros. Você também pode usar uma contagem SQL para determinar o número aproximado de registros que sua consulta retornará.

Como seu aplicativo exclui registros em um conjunto de registros de tipo dynaset, o valor de retorno de `GetRecordCount` diminui. No entanto, os registros excluídos por outros usuários não são refletidos pelo `GetRecordCount` até que o registro atual seja posicionado em um registro excluído. Se você executar uma transação que afeta a contagem de registros e, subsequentemente, reverter a transação, `GetRecordCount` não refletirá o número real de registros restantes.

O valor de `GetRecordCount` de um conjunto de registros do tipo instantâneo não é afetado pelas alterações nas tabelas subjacentes.

O valor de `GetRecordCount` de um conjunto de registros de tabela reflete o número aproximado de registros na tabela e é afetado imediatamente, pois os registros de tabela são adicionados e excluídos.

Um conjunto de registros sem registros retorna um valor de 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retorna-1. Chamar a função de membro `Requery` em um conjunto de registros redefine o valor de `GetRecordCount` como se a consulta fosse executada novamente.

Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na ajuda do DAO.

##  <a name="getsql"></a>CDaoRecordset::GetSQL

Chame essa função de membro para obter a instrução SQL que foi usada para selecionar os registros do conjunto de registros quando ele foi aberto.

```
CString GetSQL() const;
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém a instrução SQL.

### <a name="remarks"></a>Comentários

Isso geralmente será uma instrução SQL **Select** .

A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você tenha passado para o conjunto de registros no parâmetro *lpszSQL* para a função de membro [Open](#open) . Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no que você passou para `Open`, o que você especificou com ClassWizard e o que você pode ter especificado no [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) membros de dados.

> [!NOTE]
>  Chame essa função de membro somente depois de chamar `Open`.

Para obter informações relacionadas, consulte o tópico "Propriedade SQL" na ajuda do DAO.

##  <a name="gettype"></a>CDaoRecordset:: GetType

Chame essa função de membro depois de abrir o conjunto de registros para determinar o tipo do objeto Recordset.

```
short GetType();
```

### <a name="return-value"></a>Valor retornado

Um dos seguintes valores que indica o tipo de um conjunto de registros:

- conjunto de registros de `dbOpenTable` tipo de tabela

- conjunto de registros de tipo dynaset `dbOpenDynaset`

- conjunto de registros do tipo instantâneo `dbOpenSnapshot`

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Type Property" na ajuda do DAO.

##  <a name="getvalidationrule"></a>CDaoRecordset:: getregradevalidação

Chame essa função de membro para determinar a regra usada para validar os dados.

```
CString GetValidationRule();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que contém um valor que valida os dados em um registro à medida que eles são alterados ou adicionados a uma tabela.

### <a name="remarks"></a>Comentários

Essa regra é baseada em texto e é aplicada toda vez que a tabela subjacente é alterada. Se os dados não forem legais, o MFC lançará uma exceção. A mensagem de erro retornada é o texto da propriedade TextoDeValidação do objeto de campo subjacente, se especificado, ou o texto da expressão especificada pela Propriedade RegraDeValidação do objeto de campo subjacente. Você pode chamar [GetValidationText](#getvalidationtext) para obter o texto da mensagem de erro.

Por exemplo, um campo em um registro que requer o dia do mês pode ter uma regra de validação, como "dia entre 1 e 31".

Para obter informações relacionadas, consulte o tópico "Propriedade RegraDeValidação" na ajuda do DAO.

##  <a name="getvalidationtext"></a>CDaoRecordset::GetValidationText

Chame essa função de membro para recuperar o texto da propriedade TextoDeValidação do objeto de campo subjacente.

```
CString GetValidationText();
```

### <a name="return-value"></a>Valor retornado

Um objeto `CString` que contém o texto da mensagem que será exibido se o valor de um campo não atender à regra de validação do objeto de campo subjacente.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade do TextoDeValidação" na ajuda do DAO.

##  <a name="isbof"></a>CDaoRecordset::IsBOF

Chame essa função de membro antes de rolar de registro para registro para saber se você já passou antes do primeiro registro do conjunto de registros.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros não contiver nenhum registro ou se você tiver rolado para trás antes do primeiro registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também pode chamar `IsBOF` junto com `IsEOF` para determinar se o conjunto de registros contém algum registro ou se está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver nenhum registro, `IsBOF` retornará zero. Quando você abre um conjunto de registros que tem pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retorna 0.

Se o primeiro registro for o registro atual e você chamar `MovePrev`, `IsBOF` retornará subseqüentemente diferente de zero. Se `IsBOF` retornar zero e você chamar `MovePrev`, uma exceção será lançada. Se `IsBOF` retornar zero, o registro atual será indefinido e qualquer ação que exigir um registro atual resultará em uma exceção.

Efeito de métodos específicos nas configurações de `IsBOF` e `IsEOF`:

- Chamar `Open*` internamente torna o primeiro registro no conjunto de registros o registro atual chamando `MoveFirst`. Portanto, chamar `Open` em um conjunto vazio de registros faz com que `IsBOF` e `IsEOF` retornem diferente de zero. (Consulte a tabela a seguir para obter o comportamento de uma chamada com falha `MoveFirst` ou `MoveLast`.)

- Todas as operações de movimentação que localizam com êxito um registro causam `IsBOF` e `IsEOF` retornar 0.

- Uma chamada de `AddNew` seguida por uma chamada de `Update` que insere com êxito um novo registro fará com que `IsBOF` retorne 0, mas somente se `IsEOF` já estiver diferente de zero. O estado de `IsEOF` permanecerá sempre inalterado. Conforme definido pelo mecanismo de banco de dados do Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio está no final de um arquivo, portanto, qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que remova o único registro restante de um conjunto de registros, não alterará o valor de `IsBOF` ou `IsEOF`.

Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF`/ `IsEOF`.

||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`= 0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`= 0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|
|Ambos diferentes de zero|Exceção|Exceção|Exceção|Exceção|
|Ambos 0|Permitido|Permitido|Permitido|Permitido|

Permitir uma operação de movimentação não significa que a operação localizará um registro com êxito. Ele simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor das funções de membro `IsBOF` e `IsEOF` pode ser alterado como resultado da tentativa de movimentação.

O efeito das operações de movimentação que não localizam um registro no valor de `IsBOF` e `IsEOF` configurações é mostrado na tabela a seguir.

||IsBOF|IsEOF|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Diferente|Diferente|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Diferente|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Diferente|

Para obter informações relacionadas, consulte o tópico "BOF, propriedades de EOF" na ajuda do DAO.

##  <a name="isdeleted"></a>CDaoRecordset:: IsDeleted

Chame essa função de membro para determinar se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros estiver posicionado em um registro excluído; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para um registro e `IsDeleted` retornar TRUE (diferente de zero), você deverá rolar para outro registro antes de executar qualquer outra operação de conjunto de registros.

> [!NOTE]
>  Você não precisa verificar o status excluído de registros em um instantâneo ou conjunto de registros de tipo de tabela. Como os registros não podem ser excluídos de um instantâneo, não é necessário chamar `IsDeleted`. Para conjuntos de registros de tipo de tabela, os registros excluídos são realmente removidos do conjunto de registros. Depois que um registro tiver sido excluído, por você, por um outro usuário ou em outro conjunto de registros, você não poderá rolar de volta para esse registro. Portanto, não há necessidade de chamar `IsDeleted`.

Quando você exclui um registro de um dynaset, ele é removido do conjunto de registros e não é possível rolar de volta para esse registro. No entanto, se um registro em um dynaset for excluído por outro usuário ou em outro conjunto de registros com base na mesma tabela, `IsDeleted` retornará TRUE quando você rolar posteriormente para esse registro.

Para obter informações relacionadas, consulte os tópicos "Excluir método", "propriedade LastModified" e "Propriedade EditMode" na ajuda do DAO.

##  <a name="iseof"></a>CDaoRecordset::IsEOF

Chame essa função de membro à medida que você rolar de registro para registro para saber se você ultrapassou o último registro do conjunto de registros.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros não contiver nenhum registro ou se você tiver rolado para além do último registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também pode chamar `IsEOF` para determinar se o conjunto de registros contém registros ou se está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver nenhum registro, `IsEOF` retornará zero. Quando você abre um conjunto de registros que tem pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retorna 0.

Se o último registro for o registro atual quando você chamar `MoveNext`, `IsEOF` retornará subseqüentemente diferente de zero. Se `IsEOF` retornar zero e você chamar `MoveNext`, uma exceção será lançada. Se `IsEOF` retornar zero, o registro atual será indefinido e qualquer ação que exigir um registro atual resultará em uma exceção.

Efeito de métodos específicos nas configurações de `IsBOF` e `IsEOF`:

- Chamar `Open` internamente torna o primeiro registro no conjunto de registros o registro atual chamando `MoveFirst`. Portanto, chamar `Open` em um conjunto vazio de registros faz com que `IsBOF` e `IsEOF` retornem diferente de zero. (Consulte a tabela a seguir para obter o comportamento de uma chamada de `MoveFirst` com falha.)

- Todas as operações de movimentação que localizam com êxito um registro causam `IsBOF` e `IsEOF` retornar 0.

- Uma chamada de `AddNew` seguida por uma chamada de `Update` que insere com êxito um novo registro fará com que `IsBOF` retorne 0, mas somente se `IsEOF` já estiver diferente de zero. O estado de `IsEOF` permanecerá sempre inalterado. Conforme definido pelo mecanismo de banco de dados do Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio está no final de um arquivo, portanto, qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que remova o único registro restante de um conjunto de registros, não alterará o valor de `IsBOF` ou `IsEOF`.

Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF`/ `IsEOF`.

||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`= 0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`= 0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|
|Ambos diferentes de zero|Exceção|Exceção|Exceção|Exceção|
|Ambos 0|Permitido|Permitido|Permitido|Permitido|

Permitir uma operação de movimentação não significa que a operação localizará um registro com êxito. Ele simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor das funções de membro `IsBOF` e `IsEOF` pode ser alterado como resultado da tentativa de movimentação.

O efeito das operações de movimentação que não localizam um registro no valor de `IsBOF` e `IsEOF` configurações é mostrado na tabela a seguir.

||IsBOF|IsEOF|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Diferente|Diferente|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Diferente|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Diferente|

Para obter informações relacionadas, consulte o tópico "BOF, propriedades de EOF" na ajuda do DAO.

##  <a name="isfielddirty"></a>CDaoRecordset::IsFieldDirty

Chame essa função de membro para determinar se o membro de dados de campo especificado de um dynaset foi sinalizado como "sujo" (alterado).

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos está sujo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o membro de dados do campo especificado for sinalizado como sujo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados de campo sujos serão transferidos para o registro na fonte de dados quando o registro atual for atualizado por uma chamada para a função membro `Update` de `CDaoRecordset` (seguindo uma chamada para `Edit` ou `AddNew`). Com esse conhecimento, você pode executar outras etapas, como a desmarcação do membro de dados de campo para marcar a coluna para que ela não seja gravada na fonte de dados.

o `IsFieldDirty` é implementado por meio de `DoFieldExchange`.

##  <a name="isfieldnull"></a>CDaoRecordset::IsFieldNull

Chame essa função de membro para determinar se o membro de dados de campo especificado de um conjunto de registros foi sinalizado como nulo.

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o membro de dados do campo especificado for sinalizado como nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

(Na terminologia do banco de dados, NULL significa "sem valor" e não é o mesmo que NULL C++em.) Se um membro de dados de campo for sinalizado como nulo, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.

> [!NOTE]
>  Em determinadas situações, o uso de `IsFieldNull` pode ser ineficiente, uma vez que o exemplo de código a seguir ilustra:

[!code-cpp[NVC_MFCDatabase#5](../../mfc/codesnippet/cpp/cdaorecordset-class_5.cpp)]

> [!NOTE]
>  Se você estiver usando a associação de registro dinâmico, sem derivar de `CDaoRecordset`, certifique-se de usar VT_NULL conforme mostrado no exemplo.

##  <a name="isfieldnullable"></a>CDaoRecordset::IsFieldNullable

Chame essa função de membro para determinar se o membro de dados de campo especificado é "Nullable" (pode ser definido como um valor nulo; C++ NULL não é o mesmo que NULL, que, na terminologia do banco de dados, significa "sem valor").

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o membro de dados de campo especificado puder se tornar nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um campo que não pode ser nulo deve ter um valor. Se você tentar definir um campo como nulo ao adicionar ou atualizar um registro, a fonte de dados rejeitará a adição ou atualização e `Update` gerará uma exceção. A exceção ocorre quando você chama `Update`, não quando você chama `SetFieldNull`.

##  <a name="isopen"></a>CDaoRecordset:: IsOpen

Chame essa função de membro para determinar se o conjunto de registros está aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função de membro `Open` ou `Requery` do objeto Recordset tiver sido chamada anteriormente e o conjunto de registros não tiver sido fechado; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="m_bcheckcachefordirtyfields"></a>CDaoRecordset:: m_bCheckCacheForDirtyFields

Contém um sinalizador que indica se os campos armazenados em cache são automaticamente marcados como sujos (alterados) e nulos.

### <a name="remarks"></a>Comentários

O sinalizador padrão é TRUE. A configuração nesse membro de dados controla todo o mecanismo de buffer duplo. Se você definir o sinalizador como TRUE, poderá desativar o cache em uma base de campo por campo usando o mecanismo DFX. Se você definir o sinalizador como FALSE, deverá chamar `SetFieldDirty` e `SetFieldNull` você mesmo.

Defina esse membro de dados antes de chamar `Open`. Esse mecanismo é basicamente para facilitar o uso. O desempenho pode ser mais lento devido ao buffer duplo de campos conforme são feitas alterações.

##  <a name="m_nfields"></a>CDaoRecordset:: m_nFields

Contém o número de membros de dados de campo na classe recordset e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor para a classe do conjunto de registros deve inicializar `m_nFields` com o número correto de campos vinculados estaticamente. ClassWizard grava essa inicialização para você quando você a usa para declarar a classe do conjunto de registros. Você também pode escrevê-lo manualmente.

A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!NOTE]
>  Esse número deve corresponder ao número de colunas de saída registradas em `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro `CDaoFieldExchange::outputColumn`.

Você pode associar colunas dinamicamente por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue`. Se você fizer isso, não será necessário incrementar a contagem em `m_nFields` para refletir o número de chamadas de função DFX em sua função de membro de `DoFieldExchange`.

##  <a name="m_nparams"></a>CDaoRecordset:: m_nParams

Contém o número de membros de dados de parâmetro na classe recordset — o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se a classe do conjunto de registros tiver quaisquer membros de dados de parâmetro, o construtor para a classe deverá inicializar *m_nParams* com o número correto. O valor de *m_nParams* usa como padrão 0. Se você adicionar membros de dados de parâmetro — que você deve fazer manualmente — você também deve adicionar manualmente uma inicialização no construtor de classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de ' ' espaços reservados em sua *m_strFilter* ou *m_strSort* cadeia de caracteres).

A estrutura usa esse número quando parametriza a consulta do conjunto de registros.

> [!NOTE]
>  Esse número deve corresponder ao número de "params" registrado no `DoFieldExchange` depois de uma chamada para `SetFieldType` com o parâmetro `CFieldExchange::param`.

Para obter informações relacionadas, consulte o tópico "objeto de parâmetro" na ajuda do DAO.

##  <a name="m_pdaorecordset"></a>CDaoRecordset:: m_pDAORecordset

Contém um ponteiro para a interface OLE do objeto Recordset do DAO subjacente ao objeto `CDaoRecordset`.

### <a name="remarks"></a>Comentários

Use esse ponteiro se você precisar acessar a interface DAO diretamente.

Para obter informações relacionadas, consulte o tópico "objeto recordset" na ajuda do DAO.

##  <a name="m_pdatabase"></a>CDaoRecordset:: m_pDatabase

Contém um ponteiro para o objeto `CDaoDatabase` por meio do qual o conjunto de registros está conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Essa variável é definida de duas maneiras. Normalmente, você passa um ponteiro para um objeto de `CDaoDatabase` já aberto ao construir o objeto Recordset. Se você passar NULL em vez disso, `CDaoRecordset` criará um objeto `CDaoDatabase` para você e o abrirá. Em ambos os casos, `CDaoRecordset` armazena o ponteiro nessa variável.

Normalmente, você não precisará usar diretamente o ponteiro armazenado em `m_pDatabase`. No entanto, se você escrever suas próprias extensões para `CDaoRecordset`, talvez seja necessário usar o ponteiro. Por exemplo, talvez você precise do ponteiro se lançar suas próprias `CDaoException`.

Para obter informações relacionadas, consulte o tópico "objeto de banco de dados" na ajuda do DAO.

##  <a name="m_strfilter"></a>CDaoRecordset:: m_strFilter

Contém uma cadeia de caracteres que é usada para construir a cláusula **Where** de uma instrução SQL.

### <a name="remarks"></a>Comentários

Ele não inclui a palavra reservada **onde** filtrar o conjunto de registros. O uso deste membro de dados não é aplicável a conjuntos de registros de tipo de tabela. O uso de `m_strFilter` não tem nenhum efeito ao abrir um conjunto de registros usando um ponteiro de `CDaoQueryDef`.

Use o formato de data dos EUA (mês-dia-ano) ao filtrar campos que contêm datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; caso contrário, os dados podem não ser filtrados conforme o esperado.

Para obter informações relacionadas, consulte o tópico "propriedade de filtro" na ajuda do DAO.

##  <a name="m_strsort"></a>CDaoRecordset:: m_strSort

Contém uma cadeia de caracteres que contém a cláusula **OrderBy** de uma instrução SQL sem as palavras reservadas **OrderBy**.

### <a name="remarks"></a>Comentários

Você pode classificar objetos Recordset do tipo dynaset e snapshot.

Não é possível classificar objetos Recordset do tipo tabela. Para determinar a ordem de classificação de um conjunto de registros de tipo tabela, chame [SetCurrentIndex](#setcurrentindex).

O uso de *m_strSort* não tem nenhum efeito ao abrir um conjunto de registros usando um ponteiro de `CDaoQueryDef`.

Para obter informações relacionadas, consulte o tópico "classificar Propriedade" na ajuda do DAO.

##  <a name="move"></a>CDaoRecordset:: mover

Chame essa função de membro para posicionar os registros do conjunto de *lRows* do registro atual.

```
virtual void Move(long lRows);
```

### <a name="parameters"></a>parâmetros

*lRows*<br/>
O número de registros a serem movidos para frente ou para trás. Os valores positivos avançam para o final do conjunto de registros. Valores negativos se movem para trás, em direção ao início.

### <a name="remarks"></a>Comentários

Você pode avançar ou retroceder. `Move( 1 )` é equivalente a `MoveNext`e `Move( -1 )` é equivalente a `MovePrev`.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Em geral, chame `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem algum registro. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você tiver rolado para cima do início ou término do conjunto de registros (`IsBOF` ou `IsEOF` retorna zero), uma chamada para `Move` lançará uma `CDaoException`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Quando você chama `Move` em um instantâneo de rolagem somente de encaminhamento, o parâmetro *lRows* deve ser um inteiro positivo e indicadores não são permitidos, para que você possa avançar somente para frente.

Para tornar o registro primeiro, último, próximo ou anterior em um conjunto de registros o registro atual, chame o `MoveFirst`, `MoveLast`, `MoveNext`ou `MovePrev` função membro.

Para obter informações relacionadas, consulte os tópicos "método mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious" na ajuda do DAO.

##  <a name="movefirst"></a>CDaoRecordset:: MoveFirst

Chame essa função de membro para tornar o primeiro registro no conjunto de registros (se houver) o registro atual.

```
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Você não precisa chamar `MoveFirst` imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Em geral, chame `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem algum registro. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Use as funções `Move` para mover de registro para registro sem aplicar uma condição. Use as operações localizar para localizar registros em um tipo dynaset ou objeto Recordset tipo snapshot que atenda a uma determinada condição. Para localizar um registro em um objeto Recordset do tipo tabela, chame `Seek`.

Se o conjunto de registros se referir a um conjunto de registros de tipo tabela, a movimentação seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Se você chamar `MoveLast` em um objeto Recordset com base em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto Recordset estará totalmente populado.

Você não pode chamar a função de membro `MoveFirst` ou `MovePrev` com um instantâneo de rolagem somente de encaminhamento.

Para mover a posição do registro atual em um objeto Recordset um número específico de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "método mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious" na ajuda do DAO.

##  <a name="movelast"></a>CDaoRecordset:: MoveLast

Chame essa função de membro para tornar o último registro (se houver) no conjunto de registros o registro atual.

```
void MoveLast();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Em geral, chame `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem algum registro. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Use as funções `Move` para mover de registro para registro sem aplicar uma condição. Use as operações localizar para localizar registros em um tipo dynaset ou objeto Recordset tipo snapshot que atenda a uma determinada condição. Para localizar um registro em um objeto Recordset do tipo tabela, chame `Seek`.

Se o conjunto de registros se referir a um conjunto de registros de tipo tabela, a movimentação seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Se você chamar `MoveLast` em um objeto Recordset com base em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto Recordset estará totalmente populado.

Para mover a posição do registro atual em um objeto Recordset um número específico de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "método mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious" na ajuda do DAO.

##  <a name="movenext"></a>CDaoRecordset:: MoveNext

Chame essa função de membro para tornar o próximo registro no conjunto de registros o registro atual.

```
void MoveNext();
```

### <a name="remarks"></a>Comentários

É recomendável chamar `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará uma `CDaoException` se `IsBOF` retornar um valor diferente de zero, indicando que você já rolou antes do primeiro registro ou que nenhum registro foi selecionado pelo conjunto de registros.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Em geral, chame `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem algum registro. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Use as funções `Move` para mover de registro para registro sem aplicar uma condição. Use as operações localizar para localizar registros em um tipo dynaset ou objeto Recordset tipo snapshot que atenda a uma determinada condição. Para localizar um registro em um objeto Recordset do tipo tabela, chame `Seek`.

Se o conjunto de registros se referir a um conjunto de registros de tipo tabela, a movimentação seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Para mover a posição do registro atual em um objeto Recordset um número específico de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "método mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious" na ajuda do DAO.

##  <a name="moveprev"></a>CDaoRecordset::MovePrev

Chame essa função de membro para tornar o registro anterior no conjunto de registros o registro atual.

```
void MovePrev();
```

### <a name="remarks"></a>Comentários

É recomendável chamar `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará uma `CDaoException` se `IsBOF` retornar um valor diferente de zero, indicando que você já rolou antes do primeiro registro ou que nenhum registro foi selecionado pelo conjunto de registros.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Em geral, chame `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem algum registro. Depois de chamar `Open` ou `Requery`, chame `IsBOF` ou `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Use as funções `Move` para mover de registro para registro sem aplicar uma condição. Use as operações localizar para localizar registros em um tipo dynaset ou objeto Recordset tipo snapshot que atenda a uma determinada condição. Para localizar um registro em um objeto Recordset do tipo tabela, chame `Seek`.

Se o conjunto de registros se referir a um conjunto de registros de tipo tabela, a movimentação seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Você não pode chamar a função de membro `MoveFirst` ou `MovePrev` com um instantâneo de rolagem somente de encaminhamento.

Para mover a posição do registro atual em um objeto Recordset um número específico de registros para frente ou para trás, chame `Move`.

Para obter informações relacionadas, consulte os tópicos "método mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious" na ajuda do DAO.

##  <a name="open"></a>CDaoRecordset:: abrir

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

### <a name="parameters"></a>parâmetros

*nOpenType*<br/>
Um dos seguintes valores:

- `dbOpenDynaset` um conjunto de registros de tipo dynaset com rolagem bidirecional. Esse é o padrão.

- `dbOpenTable` um conjunto de registros de tipo tabela com rolagem bidirecional.

- `dbOpenSnapshot` um conjunto de registros do tipo instantâneo com rolagem bidirecional.

*lpszSQL*<br/>
Um ponteiro de cadeia de caracteres que contém um dos seguintes:

- Um ponteiro nulo.

- O nome de um ou mais TableDefs e/ou QueryDefs (separados por vírgula).

- Uma instrução SQL **Select** (opcionalmente com uma cláusula SQL **Where** ou **ORDERBY** ).

- Uma consulta de passagem.

*nOptions*<br/>
Uma ou mais das opções listadas abaixo. O valor padrão é 0. Os valores possíveis são:

- `dbAppendOnly` você só pode acrescentar novos registros (somente conjunto de registros de tipo dynaset). Essa opção significa literalmente que os registros só podem ser acrescentados. As classes de banco de dados ODBC do MFC têm uma opção somente de acréscimo que permite que os registros sejam recuperados e acrescentados.

- `dbForwardOnly` o conjunto de registros é um instantâneo de rolagem somente de encaminhamento.

- `dbSeeChanges` gerar uma exceção se outro usuário estiver alterando os dados que você está editando.

- `dbDenyWrite` outros usuários não podem modificar ou adicionar registros.

- `dbDenyRead` outros usuários não podem exibir registros (somente conjunto de tabelas com tipo de tabela).

- `dbReadOnly` você só pode exibir registros; outros usuários podem modificá-los.

- `dbInconsistent` atualizações inconsistentes são permitidas (somente conjunto de registros de tipo dynaset).

- `dbConsistent` apenas atualizações consistentes são permitidas (somente Recordset do tipo dynaset).

> [!NOTE]
>  As constantes `dbConsistent` e `dbInconsistent` são mutuamente exclusivas. Você pode usar um ou outro, mas não ambos em uma determinada instância do `Open`.

*pTableDef*<br/>
Um ponteiro para um objeto [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) . Esta versão é válida somente para conjuntos de registros de tipo de tabela. Ao usar essa opção, o ponteiro de `CDaoDatabase` usado para construir o `CDaoRecordset` não é usado; em vez disso, o banco de dados no qual o TableDef reside é usado.

*pQueryDef*<br/>
Um ponteiro para um objeto [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) . Esta versão é válida somente para conjuntos de registros tipo dynaset e tipo de instantâneo. Ao usar essa opção, o ponteiro de `CDaoDatabase` usado para construir o `CDaoRecordset` não é usado; em vez disso, o banco de dados no qual o querydef reside é usado.

### <a name="remarks"></a>Comentários

Antes de chamar `Open`, você deve construir o objeto Recordset. Há várias maneiras de fazer isso:

- Quando você constrói o objeto recordset, passa um ponteiro para um objeto `CDaoDatabase` que já está aberto.

- Quando você constrói o objeto recordset, passa um ponteiro para um objeto `CDaoDatabase` que não está aberto. O conjunto de registros abre um objeto `CDaoDatabase`, mas não o fechará quando o objeto Recordset for fechado.

- Ao construir o objeto recordset, passe um ponteiro NULL. O objeto Recordset chama `GetDefaultDBName` para obter o nome do Microsoft Access. Arquivo MDB a ser aberto. Em seguida, o conjunto de registros abre um objeto `CDaoDatabase` e o mantém aberto, desde que o conjunto de registros esteja aberto. Quando você chama `Close` no conjunto de registros, o objeto `CDaoDatabase` também é fechado.

    > [!NOTE]
    >  Quando o conjunto de registros abre o objeto `CDaoDatabase`, ele abre a fonte de dados com acesso não exclusivo.

Para a versão do `Open` que usa o parâmetro *lpszSQL* , depois que o conjunto de registros é aberto, você pode recuperar registros de várias maneiras. A primeira opção é ter as funções DFX em seu `DoFieldExchange`. A segunda opção é usar a associação dinâmica chamando a função membro `GetFieldValue`. Essas opções podem ser implementadas separadamente ou em combinação. Se eles forem combinados, você terá que passar a instrução SQL por conta própria na chamada para `Open`.

Quando você usa a segunda versão do `Open` em que você passa um objeto `CDaoTableDef`, as colunas resultantes estarão disponíveis para você associar via `DoFieldExchange` e o mecanismo DFX e/ou associar dinamicamente via `GetFieldValue`.

> [!NOTE]
>  Você só pode chamar `Open` usando um objeto `CDaoTableDef` para conjuntos de registros de tipo tabela.

Ao usar a terceira versão do `Open` em que você passa um objeto `CDaoQueryDef`, essa consulta será executada e as colunas resultantes estarão disponíveis para você associar por meio de `DoFieldExchange` e o mecanismo DFX e/ou associar dinamicamente via `GetFieldValue`.

> [!NOTE]
>  Você só pode chamar `Open` usando um objeto `CDaoQueryDef` para conjuntos de registros tipo dynaset e tipo instantâneo.

Para a primeira versão do `Open` que usa o parâmetro `lpszSQL`, os registros são selecionados com base nos critérios mostrados na tabela a seguir.

|Valor do parâmetro `lpszSQL`|Os registros selecionados são determinados por|Exemplo|
|--------------------------------------|----------------------------------------|-------------|
|NULO|A cadeia de caracteres retornada por `GetDefaultSQL`.||
|Uma lista separada por vírgulas de um ou mais nomes de TableDefs e/ou de QueryDef.|Todas as colunas representadas no `DoFieldExchange`.|`"Customer"`|
|**Selecione** a lista **de colunas na lista de** tabelas|As colunas especificadas dos TableDef (s) especificados e/ou querydef (s).|`"SELECT CustId, CustName`<br /><br /> `FROM Customer"`|

O procedimento habitual é passar NULL para `Open`; Nesse caso, `Open` chama `GetDefaultSQL`, uma função de membro substituível que ClassWizard gera ao criar uma classe derivada de `CDaoRecordset`. Esse valor fornece os nomes de TableDef (s) e/ou querydef que você especificou em ClassWizard. Em vez disso, você pode especificar outras informações no parâmetro *lpszSQL* .

Seja qual for a sua passagem, `Open` construirá uma cadeia de caracteres SQL final para a consulta (a cadeia de caracteres poderá ter as cláusulas SQL **Where** e **ORDERBY** anexadas à cadeia de caracteres *lpszSQL* que você aprovou) e, em seguida, executará a consulta. Você pode examinar a cadeia de caracteres construída chamando `GetSQL` depois de chamar `Open`.

Os membros de dados de campo da classe do conjunto de registros estão associados às colunas dos dados selecionados. Se qualquer registro for retornado, o primeiro registro se tornará o registro atual.

Se você quiser definir opções para o conjunto de registros, como um filtro ou uma classificação, defina `m_strSort` ou `m_strFilter` depois de construir o objeto recordset, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros depois que o conjunto de registros já estiver aberto, chame `Requery`.

Se você chamar `Open` em um conjunto de registros de tipo dynaset ou de instantâneo, ou se a fonte de dados se referir a uma instrução SQL ou a um TableDef que representa uma tabela anexada, você não poderá usar `dbOpenTable` para o argumento de tipo; Se você fizer isso, o MFC lançará uma exceção. Para determinar se um objeto tabledef representa uma tabela anexada, crie um objeto [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) e chame sua função de membro [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) .

Use o sinalizador `dbSeeChanges` se desejar interceptar as alterações feitas por outro usuário ou outro programa em seu computador quando você estiver editando ou excluindo o mesmo registro. Por exemplo, se dois usuários começarem a editar o mesmo registro, o primeiro usuário a chamar a função de membro `Update` terá sucesso. Quando `Update` é chamado pelo segundo usuário, um `CDaoException` é gerado. Da mesma forma, se o segundo usuário tentar chamar `Delete` para excluir o registro e ele já tiver sido alterado pelo primeiro usuário, ocorrerá uma `CDaoException`.

Normalmente, se o usuário receber essa `CDaoException` durante a atualização, seu código deverá atualizar o conteúdo dos campos e recuperar os valores recém modificados. Se a exceção ocorrer no processo de exclusão, o código poderá exibir os novos dados de registro para o usuário e uma mensagem indicando que os dados foram alterados recentemente. Neste ponto, seu código pode solicitar uma confirmação de que o usuário ainda deseja excluir o registro.

> [!TIP]
>  Use a opção de rolagem somente de encaminhamento (`dbForwardOnly`) para melhorar o desempenho quando seu aplicativo fizer uma passagem única de um conjunto de registros aberto a partir de uma fonte de dados ODBC.

Para obter informações relacionadas, consulte o tópico "método OpenRecordset" na ajuda do DAO.

##  <a name="requery"></a>CDaoRecordset:: Requery

Chame essa função de membro para recompilar (atualizar) um conjunto de registros.

```
virtual void Requery();
```

### <a name="remarks"></a>Comentários

Se qualquer registro for retornado, o primeiro registro se tornará o registro atual.

Para que o conjunto de registros reflita as adições e exclusões que você ou outros usuários estão fazendo na fonte de dados, você deve recompilar o conjunto de registros chamando `Requery`. Se o conjunto de registros for um dynaset, ele refletirá automaticamente as atualizações que você ou outros usuários fazem em seus registros existentes (mas não em adições). Se o conjunto de registros for um instantâneo, você deverá chamar `Requery` para refletir edições por outros usuários, bem como adições e exclusões.

Para um dynaset ou um instantâneo, chame `Requery` sempre que desejar recriar o conjunto de registros usando valores de parâmetro. Defina o novo filtro ou classificar definindo [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) antes de chamar `Requery`. Defina novos parâmetros atribuindo novos valores aos membros de dados de parâmetro antes de chamar `Requery`.

Se a tentativa de recriar o conjunto de registros falhar, o conjunto de registros será fechado. Antes de chamar `Requery`, você pode determinar se o conjunto de registros pode ser consultado chamando a função de membro [Restart](#canrestart) . `CanRestart` não garante que `Requery` terá sucesso.

> [!CAUTION]
>  Chame `Requery` somente depois de ter chamado `Open`.

> [!NOTE]
>  Chamar as alterações de [repetição](#requery) altera os indicadores do DAO.

Você não pode chamar `Requery` em um conjunto de registros de tipo dynaset ou de instantâneo se chamar `CanRestart` retornar 0, nem poderá usá-lo em um conjunto de registros de tipo de tabela.

Se `IsBOF` e `IsEOF` retornar diferentes de zero depois de chamar `Requery`, a consulta não retornará nenhum registro e o conjunto de registros não conterá dados.

Para obter informações relacionadas, consulte o tópico "Requery Method" na ajuda do DAO.

##  <a name="seek"></a>CDaoRecordset:: Seek

Chame essa função de membro para localizar o registro em um objeto de conjunto de registros de tabela-tipo indexado que satisfaça os critérios especificados para o índice atual e transforme esse registro no registro atual.

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

### <a name="parameters"></a>parâmetros

*lpszComparison*<br/>
Uma das seguintes expressões de cadeia de caracteres: "<", "\<=", "=", "> =" ou ">".

*pKey1*<br/>
Um ponteiro para um [COleVariant](../../mfc/reference/colevariant-class.md) cujo valor corresponde ao primeiro campo no índice. Obrigatórios.

*pKey2*<br/>
Um ponteiro para um `COleVariant` cujo valor corresponde ao segundo campo no índice, se houver. O padrão é NULL.

*pKey3*<br/>
Um ponteiro para um `COleVariant` cujo valor corresponde ao terceiro campo no índice, se houver. O padrão é NULL.

*pKeyArray*<br/>
Um ponteiro para uma matriz de variantes. O tamanho da matriz corresponde ao número de campos no índice.

*nKeys*<br/>
Um inteiro correspondente ao tamanho da matriz, que é o número de campos no índice.

> [!NOTE]
>  Não especifique curingas nas chaves. Os curingas farão com que `Seek` não retorne nenhum registro correspondente.

### <a name="return-value"></a>Valor retornado

Diferente de zero se os registros correspondentes forem encontrados, caso contrário, 0.

### <a name="remarks"></a>Comentários

Use a segunda versão (matriz) do `Seek` para lidar com índices de quatro campos ou mais.

`Seek` permite a pesquisa de índice de alto desempenho em conjuntos de registros de tipo de tabela. Você deve definir o índice atual chamando `SetCurrentIndex` antes de chamar `Seek`. Se o índice identificar um ou mais campos de chave não exclusivos, `Seek` localizará o primeiro registro que satisfaz os critérios. Se você não definir um índice, uma exceção será lançada.

Observe que, se você não estiver criando um conjunto de registros UNICODE, os objetos `COleVariant` devem ser explicitamente declarados como ANSI. Isso pode ser feito usando a forma [COleVariant:: COleVariant](../../mfc/reference/colevariant-class.md#colevariant) **(** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando a função `COleVariant` [SetString](../../mfc/reference/colevariant-class.md#setstring) **(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Ao chamar `Seek`, você passa um ou mais valores de chave e um operador de comparação ("<", "\<=", "=", "> =" ou ">"). `Seek` pesquisa os campos de chave especificados e localiza o primeiro registro que satisfaz os critérios especificados por *lpszComparison* e *pKey1*. Uma vez encontrado, `Seek` retorna zero e torna o registro atual. Se `Seek` falhar ao localizar uma correspondência, `Seek` retornará zero e o registro atual será indefinido. Ao usar o DAO diretamente, você deve verificar explicitamente a propriedade NoMatch.

Se `lpszComparison` for "=", "> =" ou ">", `Seek` começará no início do índice. Se *lpszComparison* for "<" ou "< =", `Seek` será iniciado no final do índice e pesquisará retroativamente, a menos que haja entradas de índice duplicadas no final. Nesse caso, `Seek` inicia em uma entrada arbitrária entre as entradas de índice duplicadas no final do índice.

Não é necessário que haja um registro atual ao usar `Seek`.

Para localizar um registro em um conjunto de registros de tipo dynaset ou de instantâneo que atenda a uma condição específica, use as operações localizar. Para incluir todos os registros, não apenas aqueles que atendem a uma condição específica, use as operações de movimentação para mover de registro para registro.

Você não pode chamar `Seek` em uma tabela anexada de qualquer tipo porque as tabelas anexadas devem ser abertas como conjuntos de registros de tipo dynaset ou de instantâneo. No entanto, se você chamar `CDaoDatabase::Open` para abrir diretamente um banco de dados ISAM instalável, poderá chamar `Seek` em tabelas nesse banco de dados, embora o desempenho possa ser lento.

Para obter informações relacionadas, consulte o tópico "método de busca" na ajuda do DAO.

##  <a name="setabsoluteposition"></a>CDaoRecordset::SetAbsolutePosition

Define o número de registro relativo do registro atual de um objeto Recordset.

```
void SetAbsolutePosition(long lPosition);
```

### <a name="parameters"></a>parâmetros

*lPosition*<br/>
Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

Chamar `SetAbsolutePosition` permite posicionar o ponteiro de registro atual para um registro específico com base em sua posição ordinal em um conjunto de registros de tipo dynaset ou de instantâneo. Você também pode determinar o número do registro atual chamando [GetAbsolutePosition](#getabsoluteposition).

> [!NOTE]
>  Essa função de membro é válida somente para conjuntos de registros tipo dynaset e tipo de instantâneo.

O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se ao primeiro registro no conjunto de registros. Definir um valor maior que o número de registros populados faz com que o MFC lance uma exceção. Você pode determinar o número de registros populados no conjunto de registros chamando a função membro `GetRecordCount`.

Se o registro atual for excluído, o valor da propriedade AbsolutePosition não será definido e o MFC gerará uma exceção se ela for referenciada. Novos registros são adicionados ao final da sequência.

> [!NOTE]
>  Esta propriedade não deve ser usada como um número de registro substituto. Os indicadores ainda são a maneira recomendada de reter e retornar a uma determinada posição e são a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros que dão suporte a indicadores. Em particular, a posição de um determinado registro é alterada quando os registros anteriores a ele são excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem dos registros individuais em um conjunto de registros não é garantida, a menos que ele seja criado com uma instrução SQL usando uma cláusula **ORDERBY** .

Para obter informações relacionadas, consulte o tópico "propriedade AbsolutePosition" na ajuda do DAO.

##  <a name="setbookmark"></a>CDaoRecordset:: SetBookmark

Chame essa função de membro para posicionar o conjunto de registros no registro que contém o indicador especificado.

```
void SetBookmark(COleVariant varBookmark);
```

### <a name="parameters"></a>parâmetros

*varBookmark*<br/>
Um objeto [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor de indicador para um registro específico.

### <a name="remarks"></a>Comentários

Quando um objeto Recordset é criado ou aberto, cada um de seus registros já tem um indicador exclusivo. Você pode recuperar o indicador para o registro atual chamando `GetBookmark` e salvando o valor em um objeto `COleVariant`. Posteriormente, você poderá retornar a esse registro chamando `SetBookmark` usando o valor de indicador salvo.

> [!NOTE]
>  Chamar as alterações de [repetição](#requery) altera os indicadores do DAO.

Observe que, se você não estiver criando um conjunto de registros UNICODE, o objeto `COleVariant` deverá ser declarado explicitamente como ANSI. Isso pode ser feito usando a forma [COleVariant:: COleVariant](../../mfc/reference/colevariant-class.md#colevariant) **(** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando a função `COleVariant` [SetString](../../mfc/reference/colevariant-class.md#setstring) **(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte os tópicos "propriedade de indicador" e propriedade de Indicadorable "na ajuda do DAO.

##  <a name="setcachesize"></a>CDaoRecordset::SetCacheSize

Chame essa função de membro para definir o número de registros a serem armazenados em cache.

```
void SetCacheSize(long lSize);
```

### <a name="parameters"></a>parâmetros

*lSize*<br/>
Especifica o número de registros. Um valor típico é 100. Uma configuração de 0 desativa o cache. A configuração deve ter entre 5 e 1200 registros. O cache pode usar uma quantidade considerável de memória.

### <a name="remarks"></a>Comentários

Um cache é um espaço na memória local que contém os dados recuperados mais recentemente do servidor, caso os dados sejam solicitados novamente enquanto o aplicativo estiver em execução. O cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos Recordset do tipo dynaset. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica primeiro os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Os dados que não são provenientes de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local. Para criar o cache, abra um objeto Recordset da fonte de dados remota, chame as funções de membro `SetCacheSize` e `SetCacheStart` e, em seguida, chame a função membro `FillCache` ou percorra os registros usando uma das operações de movimentação. O parâmetro *lSize* da função membro `SetCacheSize` pode ser baseado no número de registros com os quais seu aplicativo pode trabalhar ao mesmo tempo. Por exemplo, se você estiver usando um conjunto de registros como a origem dos dados a serem exibidos na tela, poderá passar o parâmetro `SetCacheSize` *lSize* como 20 para exibir 20 registros ao mesmo tempo.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na ajuda do DAO.

##  <a name="setcachestart"></a>CDaoRecordset::SetCacheStart

Chame essa função de membro para especificar o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
void SetCacheStart(COleVariant varBookmark);
```

### <a name="parameters"></a>parâmetros

*varBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

Você pode usar o valor de indicador de qualquer registro para o parâmetro *varBookmark* da função membro `SetCacheStart`. Faça o registro que você deseja iniciar o cache com o registro atual, estabeleça um indicador para esse registro usando [SetBookmark](#setbookmark)e passe o valor do indicador como o parâmetro para a função de membro `SetCacheStart`.

O mecanismo de banco de dados do Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.

Os registros recuperados do cache não refletem as alterações feitas simultaneamente para os dados de origem por outros usuários.

Para forçar uma atualização de todos os dados armazenados em cache, passe o parâmetro *lSize* de `SetCacheSize` como 0, chame `SetCacheSize` novamente com o tamanho do cache que você solicitou originalmente e, em seguida, chame a função de membro `FillCache`.

Observe que, se você não estiver criando um conjunto de registros UNICODE, o objeto `COleVariant` deverá ser declarado explicitamente como ANSI. Isso pode ser feito usando a forma [COleVariant:: COleVariant](../../mfc/reference/colevariant-class.md#colevariant) **(** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando a função `COleVariant` [SetString](../../mfc/reference/colevariant-class.md#setstring) **(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte o tópico CacheSize, CacheStart Properties "na ajuda do DAO.

##  <a name="setcurrentindex"></a>CDaoRecordset::SetCurrentIndex

Chame essa função de membro para definir um índice em um conjunto de registros de tipo de tabela.

```
void SetCurrentIndex(LPCTSTR lpszIndex);
```

### <a name="parameters"></a>parâmetros

*lpszIndex*<br/>
Um ponteiro que contém o nome do índice a ser definido.

### <a name="remarks"></a>Comentários

Os registros nas tabelas base não são armazenados em nenhuma ordem específica. Definir um índice altera a ordem dos registros retornados do banco de dados, mas não afeta a ordem em que os registros são armazenados. O índice especificado já deve estar definido. Se você tentar usar um objeto de índice que não existe, ou se o índice não estiver definido quando você chamar [Seek](#seek), o MFC lançará uma exceção.

Você pode criar um novo índice para a tabela chamando [CDaoTableDef:: CreateIndex](../../mfc/reference/cdaotabledef-class.md#createindex) e anexando o novo índice à coleção de índices do TableDef subjacente chamando [CDaoTableDef:: Append](../../mfc/reference/cdaotabledef-class.md#append)e, em seguida, reabrindo o conjunto de registros.

Os registros retornados de um conjunto de registros do tipo tabela podem ser ordenados somente pelos índices definidos para o TableDef subjacente. Para classificar os registros em alguma outra ordem, você pode abrir um conjunto de registros de tipo dynaset ou de instantâneo usando uma cláusula **ORDERBY** SQL armazenada em [CDaoRecordset:: m_strSort](#m_strsort).

Para obter informações relacionadas, consulte o tópico "objeto de índice" e a definição "índice atual" na ajuda do DAO.

##  <a name="setfielddirty"></a>CDaoRecordset::SetFieldDirty

Chame essa função de membro para sinalizar um membro de dados de campo do conjunto de registros como alterado ou inalterado.

```
void SetFieldDirty(
    void* pv,
    BOOL bDirty = TRUE);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou nulo. Se for NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que NULL na terminologia do banco de dados, o que significa "sem valor".)

*bDirty*<br/>
TRUE se o membro de dados de campo for sinalizado como "sujo" (alterado). Caso contrário, FALSE se o membro de dados de campo for sinalizado como "limpo" (inalterado).

### <a name="remarks"></a>Comentários

Marcar campos como inalterados garante que o campo não seja atualizado.

A estrutura marca os membros de dados de campo alterados para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo de intercâmbio de campo de registro do DAO (DFX). A alteração do valor de um campo geralmente define o campo sujo automaticamente, portanto, raramente será necessário chamar `SetFieldDirty` você mesmo, mas às vezes você desejará garantir que as colunas sejam explicitamente atualizadas ou inseridas, independentemente de qual valor está no membro de dados do campo. O mecanismo DFX também emprega o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange:: m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, a alteração do valor do campo não definirá automaticamente o campo como sujo. Nesse caso, será necessário definir explicitamente o campo como sujo. O sinalizador contido no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [Editar](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função aplicará a função a todos os campos de `outputColumn`, não aos campos **param** em `CDaoFieldExchange`. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#6](../../mfc/codesnippet/cpp/cdaorecordset-class_6.cpp)]

definirá somente campos `outputColumn` como nulos; os campos **param** não serão afetados.

Para trabalhar em um **param**, você deve fornecer o endereço real do **parâmetro** individual no qual você deseja trabalhar, como:

[!code-cpp[NVC_MFCDatabase#7](../../mfc/codesnippet/cpp/cdaorecordset-class_7.cpp)]

Isso significa que você não pode definir todos os campos **param** como NULL, como é possível com `outputColumn` campos.

o `SetFieldDirty` é implementado por meio de `DoFieldExchange`.

##  <a name="setfieldnull"></a>CDaoRecordset::SetFieldNull

Chame essa função de membro para sinalizar um membro de dados de campo do conjunto de registros como nulo (especificamente sem valor) ou como não nulo.

```
void SetFieldNull(
    void* pv,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>parâmetros

*PV*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou nulo. Se for NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que NULL na terminologia do banco de dados, o que significa "sem valor".)

*bNull*<br/>
Diferente de zero se o membro de dados de campo for sinalizado como sem valor (nulo). Caso contrário, 0 se o membro de dados do campo for sinalizado como não nulo.

### <a name="remarks"></a>Comentários

`SetFieldNull` é usado para campos vinculados ao mecanismo de `DoFieldExchange`.

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujos" (alterados). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou são nulas. Se não for apropriado tornar um campo nulo, um [CDaoException](../../mfc/reference/cdaoexception-class.md) será gerado.

Se você estiver usando o mecanismo de buffer duplo, por exemplo, se desejar especificamente designar um campo do registro atual como não tendo um valor, chame `SetFieldNull` com *bNull* definido como true para sinalizá-lo como nulo. Se um campo tiver sido marcado como nulo anteriormente e você quiser dar a ele um valor, basta definir seu novo valor. Não é necessário remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser nulo, chame [IsFieldNullable](#isfieldnullable).

Se você não estiver usando o mecanismo de buffer duplo, a alteração do valor do campo não definirá automaticamente o campo como sujo e não nulo. Você deve definir especificamente os campos sujos e não nulos. O sinalizador contido no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática de campo.

O mecanismo DFX emprega o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange:: m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [Editar](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função aplicará a função somente a `outputColumn` campos, não aos campos **param** em `CDaoFieldExchange`. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#8](../../mfc/codesnippet/cpp/cdaorecordset-class_8.cpp)]

definirá somente campos `outputColumn` como nulos; os campos **param** não serão afetados.

##  <a name="setfieldvalue"></a>CDaoRecordset:: SetFieldValue

Chame essa função de membro para definir o valor de um campo, seja por posição ordinal ou alterando o valor da cadeia de caracteres.

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

### <a name="parameters"></a>parâmetros

*lpszName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.

*varValue*<br/>
Uma referência a um objeto [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do conteúdo do campo.

*nIndex*<br/>
Um inteiro que representa a posição ordinal do campo na coleção de campos do conjunto de registros (com base em zero).

*lpszValue*<br/>
Um ponteiro para uma cadeia de caracteres que contém o valor do conteúdo do campo.

### <a name="remarks"></a>Comentários

Use `SetFieldValue` e [GetFieldValue](#getfieldvalue) para vincular dinamicamente os campos em tempo de execução, em vez de fazer a ligação estática de colunas usando o mecanismo [DoFieldExchange](#dofieldexchange) .

Observe que, se você não estiver criando um conjunto de registros UNICODE, deverá usar uma forma de `SetFieldValue` que não contenha um parâmetro `COleVariant`, ou o objeto `COleVariant` deve ser declarado explicitamente como ANSI. Isso pode ser feito usando a forma [COleVariant:: COleVariant](../../mfc/reference/colevariant-class.md#colevariant) **(** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando a função `COleVariant` [SetString](../../mfc/reference/colevariant-class.md#setstring) **(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

Para obter informações relacionadas, consulte os tópicos "objeto de campo" e "propriedade de valor" na ajuda do DAO.

##  <a name="setfieldvaluenull"></a>CDaoRecordset::SetFieldValueNull

Chame essa função de membro para definir o campo como um valor nulo.

```
void SetFieldValueNull(int nIndex);
void SetFieldValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para pesquisa por índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para pesquisa por nome.

### <a name="remarks"></a>Comentários

C++NULL não é o mesmo que NULL, que, na terminologia do banco de dados, significa "sem valor".

Para obter informações relacionadas, consulte os tópicos "objeto de campo" e "propriedade de valor" na ajuda do DAO.

##  <a name="setlockingmode"></a>CDaoRecordset:: setlockmode

Chame essa função de membro para definir o tipo de bloqueio para o conjunto de registros.

```
void SetLockingMode(BOOL bPessimistic);
```

### <a name="parameters"></a>parâmetros

*bPessimistic*<br/>
Um sinalizador que indica o tipo de bloqueio.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista estiver em vigor, a página de 2K que contém o registro que você está editando será bloqueada assim que você chamar a função de membro `Edit`. A página é desbloqueada quando você chama a função de membro `Update` ou `Close` ou qualquer uma das operações de mover ou localizar.

Quando o bloqueio otimista estiver em vigor, a página de 2K que contém o registro será bloqueada somente enquanto o registro estiver sendo atualizado com a função membro `Update`.

Se uma página estiver bloqueada, nenhum outro usuário poderá editar os registros na mesma página. Se você chamar `SetLockingMode` e passar um valor diferente de zero e outro usuário já tiver a página bloqueada, uma exceção será lançada quando você chamar `Edit`. Outros usuários podem ler dados de páginas bloqueadas.

Se você chamar `SetLockingMode` com um valor zero e uma chamada posterior `Update` enquanto a página estiver bloqueada por outro usuário, ocorrerá uma exceção. Para ver as alterações feitas no registro por outro usuário (e perder as alterações), chame a função membro `SetBookmark` com o valor de indicador do registro atual.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

##  <a name="setparamvalue"></a>CDaoRecordset:: SetParamValue

Chame essa função de membro para definir o valor de um parâmetro no conjunto de registros em tempo de execução.

```
virtual void SetParamValue(
    int nIndex,
    const COleVariant& varValue);

virtual void SetParamValue(
    LPCTSTR lpszName,
    const COleVariant& varValue);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
A posição numérica do parâmetro na coleção de parâmetros do QueryDef.

*var*<br/>
O valor a ser definido; consulte comentários.

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja definir.

### <a name="remarks"></a>Comentários

O parâmetro já deve ter sido estabelecido como parte da cadeia de caracteres SQL do conjunto de registros. Você pode acessar o parâmetro por nome ou pela sua posição de índice na coleção.

Especifique o valor a ser definido como um objeto de `COleVariant`. Para obter informações sobre como definir o valor desejado e o tipo no objeto `COleVariant`, consulte classe [COleVariant](../../mfc/reference/colevariant-class.md). Observe que, se você não estiver criando um conjunto de registros UNICODE, o objeto `COleVariant` deverá ser declarado explicitamente como ANSI. Isso pode ser feito usando a forma [COleVariant:: COleVariant](../../mfc/reference/colevariant-class.md#colevariant) **(** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como `VT_BSTRT` (ANSI) ou usando a função `COleVariant` [SetString](../../mfc/reference/colevariant-class.md#setstring) **(** *lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido como `VT_BSTRT`.

##  <a name="setparamvaluenull"></a>CDaoRecordset::SetParamValueNull

Chame essa função de membro para definir o parâmetro como um valor nulo.

```
void SetParamValueNull(int nIndex);
void SetParamValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para pesquisa por índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para pesquisa por nome.

### <a name="remarks"></a>Comentários

C++NULL não é o mesmo que NULL, que, na terminologia do banco de dados, significa "sem valor".

##  <a name="setpercentposition"></a>CDaoRecordset::SetPercentPosition

Chame essa função de membro para definir um valor que altere o local aproximado do registro atual no objeto Recordset com base em uma porcentagem dos registros no conjunto de registros.

```
void SetPercentPosition(float fPosition);
```

### <a name="parameters"></a>parâmetros

*fPosition*<br/>
Um número entre 0 e 100.

### <a name="remarks"></a>Comentários

Ao trabalhar com um conjunto de registros de tipo dynaset ou de instantâneo, primeiro preencha o conjunto de registros movendo para o último registro antes de chamar `SetPercentPosition`. Se você chamar `SetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimentação será relativa ao número de registros acessados conforme indicado pelo valor de [GetRecordCount](#getrecordcount). Você pode mover para o último registro chamando `MoveLast`.

Depois de chamar `SetPercentPosition`, o registro na posição aproximada correspondente a esse valor se tornará atual.

> [!NOTE]
>  Não é recomendável chamar `SetPercentPosition` para mover o registro atual para um registro específico em um conjunto de registros. Em vez disso, chame a função de membro [SetBookmark](#setbookmark) .

Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na ajuda do DAO.

##  <a name="update"></a>CDaoRecordset:: atualizar

Chame essa função de membro após uma chamada para a função de membro `AddNew` ou `Edit`.

```
virtual void Update();
```

### <a name="remarks"></a>Comentários

Essa chamada é necessária para concluir a operação de `AddNew` ou `Edit`.

Ambos `AddNew` e `Edit` preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar na fonte de dados. `Update` salva os dados. Somente os campos marcados ou detectados como alterados são atualizados.

Se a fonte de dados der suporte a transações, você poderá fazer com que o `Update` chame (e sua parte correspondente `AddNew` ou `Edit` chamada) de uma transação.

> [!CAUTION]
> Se você chamar `Update` sem primeiro chamar `AddNew` ou `Edit`, o `Update` lançará um `CDaoException`. Se você chamar `AddNew` ou `Edit`, deverá chamar `Update` antes de chamar [MoveNext](#movenext) ou fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Quando o objeto Recordset é pessimistically bloqueado em um ambiente multiusuário, o registro permanece bloqueado da hora `Edit` é usado até que a atualização seja concluída. Se o conjunto de registros estiver bloqueado de forma otimista, o registro será bloqueado e comparado com o registro previamente editado antes de ser atualizado no banco de dados. Se o registro tiver sido alterado desde que você chamou `Edit`, a operação de `Update` falhará e o MFC lançará uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.

> [!NOTE]
> O bloqueio otimista sempre é usado em formatos de banco de dados externos, como ODBC e ISAM instalável.

Para obter informações relacionadas, consulte os tópicos "método AddNew", "método CancelUpdate", "Excluir método", "propriedade LastModified", "método de atualização" e "Propriedade EditMode" na ajuda do DAO.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
