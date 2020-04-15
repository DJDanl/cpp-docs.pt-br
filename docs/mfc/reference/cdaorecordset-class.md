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
ms.openlocfilehash: 5b4b2919405696c748ce01217ac82afeac316de2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377158"
---
# <a name="cdaorecordset-class"></a>Classe CDaoRecordset

Representa um conjunto de registros selecionados a partir de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CDaoRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Conjunto CDaoRecord::CDaoRecordset](#cdaorecordset)|Constrói um objeto `CDaoRecordset`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDaoRecordset::AddNew](#addnew)|Prepara-se para adicionar um novo recorde. Atualização [de chamada](#update) para completar a adição.|
|[CDaoRecordset::CanAppend](#canappend)|Retorna não zero se novos registros puderem ser adicionados ao conjunto de registros através da função [AddNew](#addnew) member.|
|[CDaoRecordset::CanBookmark](#canbookmark)|Retorna não zero se o conjunto de registros suportar marcadores.|
|[CDaoRecordset::CancelUpdate](#cancelupdate)|Cancela quaisquer atualizações pendentes devido a uma operação [Editar](#edit) ou [AdicionarNew.](#addnew)|
|[CDaoRecordset::CanRestart](#canrestart)|Retorna não zero se [Requery](#requery) puder ser chamado para executar a consulta do conjunto de registros novamente.|
|[CDaoRecordset::CanScroll](#canscroll)|Retorna não zero se você puder percorrer os registros.|
|[CDaoRecordset::CanTransact](#cantransact)|Retorna não zero se a fonte de dados suportar transações.|
|[CDaoRecordset::CanUpdate](#canupdate)|Retorna não zero se o conjunto de registros puder ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CDaoRecordset::Fechar](#close)|Fecha o conjunto de registros.|
|[CDaoRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Você deve rolar explicitamente para outro registro após a exclusão.|
|[CDaoRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa a troca de campo de registro DAO (DFX).|
|[Conjunto CDaoRecord::Edição](#edit)|Prepara-se para mudanças no registro atual. Ligue `Update` para completar a edição.|
|[CDaoRecordset::FillCache](#fillcache)|Preenche tudo ou uma parte de um cache local para um objeto de conjunto de registros que contém dados de uma fonte de dados ODBC.|
|[CDaoRecordset::Encontrar](#find)|Localiza a primeira, próxima, anterior ou última localização de uma seqüência de string específica em um conjunto de registros do tipo dynaset que satisfaz os critérios especificados e faz com que esse registro registre o registro atual.|
|[CDaoRecordset::FindFirst](#findfirst)|Localiza o primeiro registro em um conjunto de registros tipo dynaset ou snapshot que satisfaz os critérios especificados e faz com que esse registro registre o registro atual.|
|[CDaoRecordset::FindLast](#findlast)|Localiza o último registro em um conjunto de registros tipo dynaset ou snapshot que satisfaz os critérios especificados e faz com que esse registro registre o registro atual.|
|[CDaoRecordset::FindNext](#findnext)|Localiza o próximo registro em um conjunto de registros tipo dynaset ou snapshot que satisfaz os critérios especificados e faz com que esse registro registre o registro atual.|
|[Conjunto CDaoRecord::FindPrev](#findprev)|Localiza o registro anterior em um conjunto de registros tipo dynaset ou snapshot que satisfaz os critérios especificados e faz com que esse registro registre o registro atual.|
|[CDaoRecordset::GetAbsolutePosition](#getabsoluteposition)|Retorna o número recorde do registro atual de um objeto de conjunto de registros.|
|[CDaoRecordset::GetBookmark](#getbookmark)|Retorna um valor que representa o marcador em um registro.|
|[Configuração cDaoRecord::GetCacheSize](#getcachesize)|Retorna um valor que especifica o número de registros em um conjunto de registros do tipo dynaset contendo dados a serem armazenados localmente em cache a partir de uma fonte de dados ODBC.|
|[CDaoRecordset::GetCacheStart](#getcachestart)|Retorna um valor que especifica o marcador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::GetCurrentIndex](#getcurrentindex)|Retorna `CString` um contendo o nome do índice mais recentemente usado `CDaoRecordset`em um tipo de tabela indexado .|
|[CDaoRecordset::GetDateCriado](#getdatecreated)|Retorna a data e a hora `CDaoRecordset` em que a tabela base subjacente a um objeto foi criada|
|[CDaoRecordset::GetDateUpdatedAtualizado](#getdatelastupdated)|Retorna a data e a hora da alteração mais recente feita `CDaoRecordset` ao design de uma tabela base subjacente a um objeto.|
|[CDaoRecordset::GetDefaultDBName](#getdefaultdbname)|Retorna o nome da fonte de dados padrão.|
|[CDaoRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a seqüência SQL padrão para executar.|
|[CDaoRecordset::GetEditMode](#geteditmode)|Retorna um valor que indica o estado de edição para o registro atual.|
|[CDaoRecordset::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos em um conjunto de registros.|
|[CDaoRecordset::GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos no conjunto de registros.|
|[CDaoRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::GetIndexCount](#getindexcount)|Recupera o número de índices em uma tabela subjacente a um conjunto de registros.|
|[CDaoRecordset::GetIndexInfo](#getindexinfo)|Retorna vários tipos de informações sobre um índice.|
|[CDaoRecordset::GetLastModifiedBookmark](#getlastmodifiedbookmark)|Usado para determinar o registro mais recente adicionado ou atualizado.|
|[CDaoRecordset::GetLockingMode](#getlockingmode)|Retorna um valor que indica o tipo de bloqueio que está em vigor durante a edição.|
|[CDaoRecordset::GetName](#getname)|Retorna `CString` um contendo o nome do conjunto de registros.|
|[Conjunto CDaoRecord::GetParamValue](#getparamvalue)|Recupera o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.|
|[CDaoRecordset::GetPercentPosition](#getpercentposition)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|
|[CDaoRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros acessados em um objeto de conjunto de registros.|
|[Conjunto CDaoRecord::GetSQL](#getsql)|Obtém a seqüência SQL usada para selecionar registros para o conjunto de registros.|
|[CDaoRecordset::GetType](#gettype)|Chamado para determinar o tipo de conjunto de registros: tipo tabela, tipo dynaset ou tipo de instantâneo.|
|[CDaoRecordset::GetValidationRule](#getvalidationrule)|Retorna `CString` um contendo o valor que valida os dados à medida que são inseridos em um campo.|
|[CDaoRecordset::GetValidationText](#getvalidationtext)|Recupera o texto exibido quando uma regra de validação não está satisfeita.|
|[Conjunto CDaoRecord::IsBOF](#isbof)|Retorna não zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.|
|[Conjunto CDaoRecord::IsDedeleted](#isdeleted)|Retorna não zero se o conjunto de registros estiver posicionado em um registro excluído.|
|[Conjunto CDaoRecord::IsEOF](#iseof)|Retorna não zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.|
|[CDaoRecordset::IsFieldDirty](#isfielddirty)|Retorna não zero se o campo especificado no registro atual tiver sido alterado.|
|[CDaoRecordset::IsFieldNull](#isfieldnull)|Retorna não zero se o campo especificado no registro atual for Nulo (sem valor).|
|[CDaoRecordset::IsFieldNullable](#isfieldnullable)|Retorna não zero se o campo especificado no registro atual pode ser definido como Nulo (sem valor).|
|[CDaoRecordset::IsOpen](#isopen)|Retorna não zero se [Open](#open) tiver sido chamado anteriormente.|
|[CDaoRecordset::Mover](#move)|Posiciona o conjunto de registros a um número especificado de registros do registro atual em qualquer direção.|
|[CDaoRecordset::MoveFirst](#movefirst)|Posiciona o recorde atual no primeiro registro no conjunto de discos.|
|[CDaoRecordset::MoveLast](#movelast)|Posiciona o recorde atual no último registro no conjunto de registros.|
|[CDaoRecordset::MoveNext](#movenext)|Posiciona o recorde atual no próximo registro no conjunto de discos.|
|[CDaoRecordset::MovePrev](#moveprev)|Posiciona o recorde atual no registro anterior no conjunto de registros.|
|[CDaoRecordset::Abrir](#open)|Cria um novo conjunto de registros a partir de uma tabela, dynaset ou snapshot.|
|[Conjunto CDaoRecord::Requery](#requery)|Executa novamente a consulta do conjunto de registros para atualizar os registros selecionados.|
|[CDaoRecordset::Buscar](#seek)|Localiza o registro em um objeto de conjunto de registros indexado do tipo tabela que satisfaz os critérios especificados para o índice atual e faz com que esse registro registre o registro atual.|
|[CDaoRecordset::SetAbsolutePosition](#setabsoluteposition)|Define o número recorde do registro atual de um objeto de recordset.|
|[Conjunto CDaoRecord::SetBookmark](#setbookmark)|Posiciona o conjunto de registros em um registro contendo o marcador especificado.|
|[Configuração de gravação de CDaoRecord::SetCacheSize](#setcachesize)|Define um valor que especifica o número de registros em um conjunto de registros do tipo dynaset contendo dados a serem armazenados localmente em cache a partir de uma fonte de dados ODBC.|
|[CDaoRecordset::SetCacheStart](#setcachestart)|Define um valor que especifica o marcador do primeiro registro no conjunto de registros a ser armazenado em cache.|
|[CDaoRecordset::SetCurrentIndex](#setcurrentindex)|Chamado para definir um índice em um conjunto de registros do tipo tabela.|
|[CDaoRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|
|[CDaoRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual como Nulo (sem valor).|
|[Configuração cDaoRecord::SetFieldValue](#setfieldvalue)|Define o valor de um campo em um conjunto de registros.|
|[CDaoRecordset::SetFieldValueNull](#setfieldvaluenull)|Define o valor de um campo em um conjunto de registros para Nulo. (sem valor).|
|[CDaoRecordset::SetLockingMode](#setlockingmode)|Define um valor que indica o tipo de bloqueio a ser colocado em prática durante a edição.|
|[Conjunto CDaoRecord::SetParamValue](#setparamvalue)|Define o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente|
|[CDaoRecordset::SetParamValueNull](#setparamvaluenull)|Define o valor atual do parâmetro especificado como Nulo (sem valor).|
|[Conjunto CDaoRecord::SetPercentPosition](#setpercentposition)|Define a posição do registro atual para um local correspondente a uma porcentagem do número total de registros em um conjunto de registros.|
|[CDaoRecordset::Atualização](#update)|Completa uma `AddNew` `Edit` operação ou salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Conjunto CDaoRecord::m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields)|Contém uma bandeira indicando se os campos são automaticamente marcados como alterados.|
|[Conjunto CDaoRecord::m_nFields](#m_nfields)|Contém o número de membros de dados de campo na classe recordset e o número de colunas selecionadas pelo conjunto de registros a partir da fonte de dados.|
|[Conjunto CDaoRecord::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetros na classe recordset — o número de parâmetros passados com a consulta do conjunto de registros|
|[Conjunto CDaoRecord::m_pDAORecordset](#m_pdaorecordset)|Um ponteiro para a interface DAO subjacente ao objeto recordset.|
|[Conjunto CDaoRecord::m_pDatabase](#m_pdatabase)|Banco de dados de origem para este conjunto de resultados. Contém um ponteiro para um objeto [CDaoDatabase.](../../mfc/reference/cdaodatabase-class.md)|
|[Conjunto CDaoRecord::m_strFilter](#m_strfilter)|Contém uma seqüência usada para construir uma declaração SQL **WHERE.**|
|[Conjunto CDaoRecord::m_strSort](#m_strsort)|Contém uma string usada para construir uma declaração SQL **ORDER BY.**|

## <a name="remarks"></a>Comentários

Conhecidos como "conjuntos de registros", `CDaoRecordset` os objetos estão disponíveis nas três formas a seguir:

- Os conjuntos de registros do tipo tabela representam uma tabela base que você pode usar para examinar, adicionar, alterar ou excluir registros de uma única tabela de banco de dados.

- Os conjuntos de registros do tipo Dynaset são o resultado de uma consulta que pode ter registros atualizáveis. Esses conjuntos de registros são um conjunto de registros que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela ou tabela de banco de dados subjacente. Os conjuntos de registros do tipo Dynaset podem conter campos de uma ou mais tabelas em um banco de dados.

- Os conjuntos de registros do tipo snapshot são uma cópia estática de um conjunto de registros que você pode usar para encontrar dados ou gerar relatórios. Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados, mas não podem ser atualizados.

Cada forma de conjunto de registros representa um conjunto de registros fixos no momento em que o conjunto de discos é aberto. Quando você rola para um registro em um conjunto de registros de tipo de tabela ou um conjunto de registros do tipo dynaset, ele reflete as alterações feitas no registro após a abertura do conjunto de registros, seja por outros usuários ou por outros conjuntos de registros em seu aplicativo. (Um conjunto de registros do tipo de instantâneo não pode ser atualizado.) Você pode `CDaoRecordset` usar diretamente ou derivar uma `CDaoRecordset`classe de conjunto de registros específica do aplicativo a partir de . Em seguida, você pode:

- Perdoe os registros.

- Defina um índice e procure rapidamente registros usando [o Seek](#seek) (somente conjuntos de registros do tipo tabela).

- Encontre registros com base em uma\<comparação de cordas: "<", "=", "=", ">=", ou ">" (conjuntos de registros do tipo dynaset e snapshot).

- Atualize os registros e especifique um modo de bloqueio (exceto conjuntos de registros do tipo snapshot).

- Filtre o conjunto de registros para restringir quais registros ele seleciona daqueles disponíveis na fonte de dados.

- Classifique o conjunto de discos.

- Parametrizar o conjunto de registros para personalizar sua seleção com informações não conhecidas até o tempo de execução.

A `CDaoRecordset` classe fornece uma interface `CRecordset`semelhante à da classe . A principal diferença `CDaoRecordset` é que a classe acessa dados através de um DAO (Data Access Object, objeto de acesso a dados) com base no OLE. A `CRecordset` classe acessa o DBMS através da Open Database Connectivity (ODBC) e um driver ODBC para esse DBMS.

> [!NOTE]
> As classes de banco de dados DAO são distintas das classes de banco de dados MFC baseadas em Conectividade de Banco de Dados Aberto (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados oDBC com as classes DAO; as classes DAO geralmente oferecem recursos superiores porque são específicas do mecanismo de banco de dados Microsoft Jet.

Você pode `CDaoRecordset` usar diretamente ou `CDaoRecordset`derivar uma classe de . Para usar uma classe de conjunto de registros em ambos os casos, abra um `CDaoDatabase` banco de dados e construa um objeto de conjunto de registros, passando ao construtor um ponteiro para o objeto. Você também pode `CDaoRecordset` construir um objeto e `CDaoDatabase` deixar o MFC criar um objeto temporário para você. Em seguida, chame a função de membro [Aberto](#open) do conjunto de registros, especificando se o objeto é um conjunto de registros do tipo tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo snapshot. A `Open` chamada seleciona dados do banco de dados e recupera o primeiro registro.

Use as funções de membro do objeto e os membros de dados para percorrer os registros e operá-los. As operações disponíveis dependem se o objeto é um conjunto de registros do tipo tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo snapshot, e se ele é atualizável ou somente leitura — isso depende da capacidade do banco de dados ou da fonte de dados ODBC (Open Database Connectivity). Para atualizar registros que podem ter `Open` sido alterados ou adicionados desde a chamada, ligue para a função [requery](#requery) do objeto. Chame a função `Close` de membro do objeto e destrua o objeto quando terminar com ele.

`CDaoRecordset`usa o DFX (Record Field Exchange, troca de registros da OO) para `CDaoRecordset` `CDaoRecordset`suportar a leitura e a atualização de campos de gravação através de membros C++ seguros de tipo da sua classe ou derivado. Você também pode implementar a vinculação dinâmica de colunas em um banco de dados sem usar o mecanismo DFX usando [GetFieldValue](#getfieldvalue) e [SetFieldValue](#setfieldvalue).

Para obter informações relacionadas, consulte o tópico "Recordset Object" no DAO Help.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDaoRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="cdaorecordsetaddnew"></a><a name="addnew"></a>CDaoRecordset::AddNew

Ligue para esta função de membro para adicionar um novo registro a um conjunto de registros tipo tabela ou dynaset.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Os campos do registro são inicialmente nulos. (Na terminologia do banco de dados, Nulo significa "não ter valor" e não é o mesmo que NULL em C++.) Para concluir a operação, você deve chamar a função de membro [atualizar.](#update) `Update`salva suas alterações na fonte de dados.

> [!CAUTION]
> Se você editar um registro e, `Update`em seguida, rolar para outro registro sem chamar, suas alterações serão perdidas sem aviso.

Se você adicionar um registro a um conjunto de registros do tipo dynaset chamando [AddNew,](#addnew)o registro será `CDaoRecordset` visível no conjunto de registros e incluído na tabela subjacente onde ele se torna visível para quaisquer novos objetos.

A posição do novo registro depende do tipo de registro:

- Em um conjunto de registros do tipo dynaset, onde o novo registro é inserido não é garantido. Esse comportamento mudou com o Microsoft Jet 3.0 por razões de desempenho e concorrência. Se o seu objetivo é fazer com que o registro recém-adicionado seja o registro atual, obtenha o marcador do último registro modificado e mova-se para esse marcador:

[!code-cpp[NVC_MFCDatabase#1](../../mfc/codesnippet/cpp/cdaorecordset-class_1.cpp)]

- Em um conjunto de registros do tipo tabela para o qual um índice foi especificado, os registros são devolvidos em seu devido lugar na ordem de classificação. Se nenhum índice tiver sido especificado, novos registros serão retornados no final do conjunto de registros.

O registro que estava `AddNew` atual antes de você usar permanece atual. Se você quiser tornar a nova corrente de registro e o conjunto de registros suportar marcadores, chame [SetBookmark](#setbookmark) para o marcador identificado pela configuração de propriedade LastModified do objeto conjunto de registros DAO subjacente. Fazer isso é útil para determinar o valor para campos de contador (auto-incremento) em um registro adicional. Para obter mais informações, consulte [GetLastModifiedBookmark](#getlastmodifiedbookmark).

Se o banco de dados suportar `AddNew` transações, você pode fazer sua chamada parte de uma transação. Para obter mais informações sobre transações, consulte [classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). Observe que você deve ligar para [cDaoWorkspace::BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans) antes de ligar `AddNew`.

É ilegal chamar `AddNew` para um conjunto de registros cuja função de membro [aberto](#open) não foi chamada. A `CDaoException` é jogado `AddNew` se você chamar para um conjunto de registros que não pode ser anexado. Você pode determinar se o conjunto de registros é atualizável ligando para [O CanAppend](#canappend).

As marcas-quadro alteraram os membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo Detroca de campo de registro DAO (DFX). Alterar o valor de um campo geralmente define o campo sujo automaticamente, então você raramente precisará chamar [SetFieldDirty](#setfielddirty) você mesmo, mas às vezes você pode querer garantir que as colunas serão explicitamente atualizadas ou inseridas independentemente do valor do membro de dados de campo. O mecanismo DFX também emprega o uso de **PSEUDO NULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, então alterar o valor do campo não definirá automaticamente o campo como sujo. Neste caso, será necessário explicitamente definir o campo sujo. A bandeira contida no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla esta verificação automática de campo.

> [!NOTE]
> Se os registros forem tamponados duplos (ou `CancelUpdate` seja, a verificação automática de `AddNew` campo `Edit` estiver ativada), a chamada restaurará as variáveis de membro aos valores que tinham antes ou foram chamadas.

Para obter informações relacionadas, consulte os tópicos "AddNew Method", "CancelUpdate Method", "LastModified Property" e "EditMode Property" na Ajuda DAO.

## <a name="cdaorecordsetcanappend"></a><a name="canappend"></a>CDaoRecordset::CanAppend

Ligue para esta função de membro para determinar se o conjunto de registros aberto anteriormente permite adicionar novos registros chamando a função [addnew](#addnew) membro.

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros permitir a adição de novos registros; caso contrário, 0. `CanAppend`retornará 0 se você abriu o conjunto de registros como somente leitura.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Método de apêndice" no DAO Help.

## <a name="cdaorecordsetcanbookmark"></a><a name="canbookmark"></a>CDaoRecordset::CanBookmark

Ligue para esta função de membro para determinar se o conjunto de registros aberto anteriormente permite marcar registros individualmente usando marcadores.

```
BOOL CanBookmark();
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros suportar marcadores, caso contrário 0.

### <a name="remarks"></a>Comentários

Se você estiver usando conjuntos de registros baseados inteiramente nas tabelas de mecanismos do banco de dados do Microsoft Jet, os marcadores podem ser usados, exceto em conjuntos de registros de tipo de instantâneo sinalizados como conjuntos de registros de rolagem somente para frente. Outros produtos de banco de dados (fontes de dados externas do ODBC) podem não suportar marcadores.

Para obter informações relacionadas, consulte o tópico "Propriedade emarcavel" na Ajuda da DAO.

## <a name="cdaorecordsetcancelupdate"></a><a name="cancelupdate"></a>CDaoRecordset::CancelUpdate

A `CancelUpdate` função membro cancela quaisquer atualizações pendentes devido a uma operação [Editar](#edit) ou [AdicionarNew.](#addnew)

```
virtual void CancelUpdate();
```

### <a name="remarks"></a>Comentários

Por exemplo, se um `Edit` `AddNew` aplicativo chamar a função ou membro e `Edit` não `AddNew` tiver chamado [Atualizar,](#update) `CancelUpdate` cancele quaisquer alterações feitas depois ou foi chamada.

> [!NOTE]
> Se os registros forem tamponados duplos (ou `CancelUpdate` seja, a verificação automática de `AddNew` campo `Edit` estiver ativada), a chamada restaurará as variáveis de membro aos valores que tinham antes ou foram chamadas.

Se não `Edit` houver `AddNew` ou `CancelUpdate` operação pendente, faz com que o MFC lance uma exceção. Ligue para a função de membro [GetEditMode](#geteditmode) para determinar se há uma operação pendente que pode ser cancelada.

Para obter informações relacionadas, consulte o tópico "CancelUpdate Method" no DAO Help.

## <a name="cdaorecordsetcanrestart"></a><a name="canrestart"></a>CDaoRecordset::CanRestart

Ligue para esta função de membro para determinar se o conjunto de registros `Requery` permite reiniciar sua consulta (atualizar seus registros) chamando a função de membro.

```
BOOL CanRestart();
```

### <a name="return-value"></a>Valor retornado

Não zero `Requery` se pode ser chamado para executar a consulta do conjunto de registros novamente, caso contrário 0.

### <a name="remarks"></a>Comentários

Os conjuntos de registros `Requery`do tipo tabela não suportam .

Se `Requery` não for suportado, ligue para [Fechar](#close) e [abrir](#open) para atualizar os dados. Você pode `Requery` ligar para atualizar a consulta de parâmetro subjacente de um objeto de conjunto de registros depois que os valores dos parâmetros forem alterados.

Para obter informações relacionadas, consulte o tópico "Propriedade Reinicializável" na Ajuda da DAO.

## <a name="cdaorecordsetcanscroll"></a><a name="canscroll"></a>CDaoRecordset::CanScroll

Ligue para esta função de membro para determinar se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se você pode rolar através dos registros, caso contrário 0.

### <a name="remarks"></a>Comentários

Se você [Open](#open) chamar `dbForwardOnly`Abrir com , o conjunto de registros só pode rolar para a frente.

Para obter informações relacionadas, consulte o tópico "Posicionando o ponteiro de registro atual com DAO" no DAO Help.

## <a name="cdaorecordsetcantransact"></a><a name="cantransact"></a>CDaoRecordset::CanTransact

Ligue para esta função de membro para determinar se o conjunto de registros permite transações.

```
BOOL CanTransact();
```

### <a name="return-value"></a>Valor retornado

Não zero se a fonte de dados subjacente suportar transações, caso contrário 0.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Propriedade de transações" no DAO Help.

## <a name="cdaorecordsetcanupdate"></a><a name="canupdate"></a>CDaoRecordset::CanUpdate

Ligue para esta função de membro para determinar se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros puder ser atualizado (adicionar, atualizar e excluir registros), caso contrário 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser lido somente se a fonte de `dbReadOnly` dados subjacente for somente leitura ou se você tiver especificado para *nOptions* quando você chamou [Abrir](#open) para o conjunto de registros.

Para obter informações relacionadas, consulte os tópicos "AddNew Method", "Edit Method", "Delete Method", "Update Method" e "Updatable Property" na Ajuda da DAO.

## <a name="cdaorecordsetcdaorecordset"></a><a name="cdaorecordset"></a>Conjunto CDaoRecord::CDaoRecordset

Constrói um objeto `CDaoRecordset`.

```
CDaoRecordset(CDaoDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBanco de dados*<br/>
Contém um ponteiro para um objeto [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou o valor NULL. Se não for `CDaoDatabase` NULA `Open` e a função de membro do objeto não tiver sido chamada para conectá-la à fonte de dados, o conjunto de registros tentará abri-lo para você durante sua própria chamada [Open.](#open) Se você passar `CDaoDatabase` NULL, um objeto será construído e conectado para você usando as informações `CDaoRecordset`de origem de dados especificadas se você derivar sua classe de conjunto de registros de .

### <a name="remarks"></a>Comentários

Você pode `CDaoRecordset` usar diretamente ou derivar `CDaoRecordset`uma classe específica de aplicativo de . Você pode usar o ClassWizard para derivar suas classes de conjunto de registros.

> [!NOTE]
> Se você `CDaoRecordset` deriva ruma classe, sua classe derivada deve fornecer seu próprio construtor. Na construtora de sua classe derivada, `CDaoRecordset::CDaoRecordset`chame o construtor, passando os parâmetros apropriados ao longo dele.

Passe NULL para o construtor do `CDaoDatabase` conjunto de registros para ter um objeto construído e conectado automaticamente para você. Este é um atalho útil que não exige `CDaoDatabase` que você construa e conecte um objeto antes de construir seu conjunto de registros. Se `CDaoDatabase` o objeto não estiver aberto, um objeto [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) também será criado para você que usa o espaço de trabalho padrão. Para obter mais informações, consulte [CDaoDatabase::CDaoDatabase](../../mfc/reference/cdaodatabase-class.md#cdaodatabase).

## <a name="cdaorecordsetclose"></a><a name="close"></a>CDaoRecordset::Fechar

O `CDaoRecordset` fechamento de um objeto remove-o da coleção de conjuntos de registros abertos no banco de dados associado.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Como `Close` não destrói `CDaoRecordset` o objeto, você pode `Open` reutilizar o objeto ligando para a mesma fonte de dados ou uma fonte de dados diferente.

Todas as declarações de [AddNew](#addnew) ou [Edit](#edit) pendentes são canceladas e todas as transações pendentes são revertidas. Se você quiser preservar adições ou [Update](#update) edições pendentes, `Close` ligue para atualização antes de chamar para cada conjunto de registros.

Você pode `Open` ligar `Close`de novo depois de ligar. Isso permite que você reutilize o objeto recordset. Uma alternativa melhor é chamar [Requery,](#requery)se possível.

Para obter informações relacionadas, consulte o tópico "Close Method" no DAO Help.

## <a name="cdaorecordsetdelete"></a><a name="delete"></a>CDaoRecordset::Delete

Chame esta função de membro para excluir o registro atual em um objeto de conjunto de gravação de tipo dynaset aberto ou tipo tabela.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após uma exclusão bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor nulo, e você deve explicitamente chamar uma das funções de membro de navegação do conjunto de registros [(Mover,](#move) [Buscar,](#seek) [SetBookmark](#setbookmark)e assim por diante) para mover o registro excluído. Quando você exclui registros de um conjunto de registros, deve haver `Delete`um registro atual no conjunto de registros antes de chamar; caso contrário, mfc lança uma exceção.

`Delete`remove o registro atual e o torna inacessível. Embora você não possa editar ou usar o registro excluído, ele permanece atual. Uma vez que você passar para outro registro, no entanto, você não pode fazer o registro excluído atual novamente.

> [!CAUTION]
> O conjunto de registros deve ser updatable e deve haver uma `Delete`corrente de registro válida no conjunto de registros quando você ligar . Por exemplo, se você excluir um registro, mas não `Delete` rolar `Delete` para um novo registro antes de chamar novamente, jogará um [CDaoException](../../mfc/reference/cdaoexception-class.md).

Você pode desexcluir um registro se usar transações e chamar a função de membro [CDaoWorkspace:::Reversão.](../../mfc/reference/cdaoworkspace-class.md#rollback) Se a tabela base for a tabela principal em uma relação de exclusão em cascata, a exclusão do registro atual também pode excluir um ou mais registros em uma tabela estrangeira. Para obter mais informações, consulte a definição "cascade delete" no DAO Help.

Ao `AddNew` `Edit`contrário e `Delete` , uma chamada para `Update`não é seguida por uma chamada para .

Para obter informações relacionadas, consulte os tópicos "AddNew Method", "Edit Method", "Delete Method", "Update Method" e "Updatable Property" na Ajuda da DAO.

## <a name="cdaorecordsetdofieldexchange"></a><a name="dofieldexchange"></a>CDaoRecordset::DoFieldExchange

A função framework chama essa função de membro para trocar automaticamente dados entre os membros de dados de campo do objeto do conjunto de registros e as colunas correspondentes do registro atual na fonte de dados.

```
virtual void DoFieldExchange(CDaoFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Contém um ponteiro `CDaoFieldExchange` para um objeto. O framework já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Ele também vincula os membros dos dados do parâmetro, se houver, a espaços reservados de parâmetros na seqüência de declaração SQL para a seleção do conjunto de registros. A troca de dados de campo, chamada DEO record field exchange (DFX), funciona em ambas as direções: desde os membros de dados de campo do objeto recordset até os campos do registro na fonte de dados e do registro na fonte de dados até o objeto recordset. Se você estiver vinculando colunas dinamicamente, você não será obrigado a implementar `DoFieldExchange`.

A única ação que você `DoFieldExchange` normalmente deve tomar para implementar para sua classe de conjunto de registros derivado é criar a classe com o ClassWizard e especificar os nomes e tipos de dados dos membros de dados de campo. Você também pode adicionar código ao que o ClassWizard grava para especificar membros de dados de parâmetros. Se todos os campos forem vinculados dinamicamente, esta função ficará inativa, a menos que você especifique membros de dados de parâmetros.

Quando você declara sua classe de conjunto de gravações derivada com o ClassWizard, o assistente grava uma substituição de `DoFieldExchange` para você, que se assemelha ao seguinte exemplo:

[!code-cpp[NVC_MFCDatabase#2](../../mfc/codesnippet/cpp/cdaorecordset-class_2.cpp)]

## <a name="cdaorecordsetedit"></a><a name="edit"></a>Conjunto CDaoRecord::Edição

Chame esta função de membro para permitir alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Uma vez `Edit` chamada a função membro, as alterações feitas nos campos do registro atual são copiadas para o buffer de cópia. Depois de fazer as alterações desejadas no registro, ligue `Update` para salvar suas alterações. `Edit`salva os valores dos membros de dados do conjunto de registros. Se você `Edit`ligar, fazer `Edit` alterações, então chamar novamente, os valores `Edit` do registro são restaurados ao que eram antes da primeira chamada.

> [!CAUTION]
> Se você editar um registro e executar qualquer operação `Update`que se mova para outro registro sem antes chamar, suas alterações serão perdidas sem aviso. Além disso, se você fechar o conjunto de registros ou o banco de dados pai, seu registro editado será descartado sem aviso prévio.

Em alguns casos, você pode querer atualizar uma coluna tornando-a nula (sem dados). Para isso, ligue `SetFieldNull` com um parâmetro de TRUE para marcar o campo Nulo; isso também faz com que a coluna seja atualizada. Se você quiser que um campo seja gravado na fonte de `SetFieldDirty` dados, mesmo que seu valor não tenha sido alterado, ligue com um parâmetro de TRUE. Isso funciona mesmo que o campo tivesse o valor nulo.

As marcas-quadro alteraram os membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo Detroca de campo de registro DAO (DFX). Alterar o valor de um campo geralmente define o campo sujo automaticamente, então você raramente precisará chamar [SetFieldDirty](#setfielddirty) você mesmo, mas às vezes você pode querer garantir que as colunas serão explicitamente atualizadas ou inseridas independentemente do valor do membro de dados de campo. O mecanismo DFX também emprega o uso de **PSEUDO NULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, então alterar o valor do campo não definirá automaticamente o campo como sujo. Neste caso, será necessário explicitamente definir o campo sujo. A bandeira contida no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla esta verificação automática de campo.

Quando o objeto do conjunto de registros é bloqueado pessimicamente `Edit` em um ambiente multiusuário, o registro permanece bloqueado a partir do momento em que é usado até que a atualização seja concluída. Se o conjunto de registros estiver bloqueado com otimismo, o registro será bloqueado e comparado com o registro pré-editado pouco antes de ser atualizado no banco de dados. Se o registro mudou `Edit`desde `Update` que você ligou, a operação falha e o MFC abre uma exceção. Você pode alterar o `SetLockingMode`modo de bloqueio com .

> [!NOTE]
> O bloqueio otimista é sempre usado em formatos de banco de dados externos, como ODBC e ISAM instalável.

O registro atual permanece `Edit`atual após a chamada . Para `Edit`ligar, deve haver um registro atual. Se não houver registro atual ou se o conjunto de registros não se referir a um objeto de conjunto de gravação de tipo de tabela aberta ou dynaset, uma exceção ocorrerá. A `Edit` chamada `CDaoException` faz com que um seja jogado sob as seguintes condições:

- Não há nenhum registro atual.

- O banco de dados ou conjunto de registros é somente leitura.

- Nenhum campo no registro é updatable.

- O banco de dados ou conjunto de registros foi aberto para uso exclusivo por outro usuário.

- Outro usuário bloqueou a página que contém seu registro.

Se a fonte de dados suportar transações, você pode fazer a `Edit` chamada parte de uma transação. Observe que você `CDaoWorkspace::BeginTrans` deve `Edit` ligar antes de ligar e depois que o conjunto de registros tiver sido aberto. Observe também `CDaoWorkspace::CommitTrans` que a convocação `Update` não `Edit` é um substituto para a convocação para concluir a operação. Para obter mais informações sobre `CDaoWorkspace`transações, consulte a classe .

Para obter informações relacionadas, consulte os tópicos "AddNew Method", "Edit Method", "Delete Method", "Update Method" e "Updatable Property" na Ajuda da DAO.

## <a name="cdaorecordsetfillcache"></a><a name="fillcache"></a>CDaoRecordset::FillCache

Chame esta função de membro para armazenar um número especificado de registros do conjunto de registros.

```
void FillCache(
    long* pSize = NULL,
    COleVariant* pBookmark = NULL);
```

### <a name="parameters"></a>Parâmetros

*Psize*<br/>
Especifica o número de linhas para preencher o cache. Se você omiti-lo este parâmetro, o valor será determinado pela configuração de propriedade CacheSize do objeto DAO subjacente.

*pBookmark*<br/>
Um [COleVariant](../../mfc/reference/colevariant-class.md) especificando um marcador. O cache é preenchido a partir do registro indicado por este marcador. Se você omitiar esse parâmetro, o cache será preenchido a partir do registro indicado pela propriedade CacheStart do objeto DAO subjacente.

### <a name="remarks"></a>Comentários

O cache melhora o desempenho de um aplicativo que recupera ou busca dados de um servidor remoto. Um cache é espaço na memória local que contém os dados mais recentemente obtidos do servidor na suposição de que os dados provavelmente serão solicitados novamente enquanto o aplicativo estiver em execução. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica o cache dos dados primeiro, em vez de buscá-los no servidor, o que leva mais tempo. O uso de cache de dados em fontes de dados não ODBC não tem efeito, pois os dados não são salvos no cache.

Em vez de esperar que o cache seja preenchido com registros à medida que eles são `FillCache` buscados, você pode preencher explicitamente o cache a qualquer momento, chamando a função de membro. Esta é uma maneira mais `FillCache` rápida de preencher o cache porque busca vários registros ao mesmo tempo em vez de um de cada vez. Por exemplo, enquanto cada tela cheia de registros está `FillCache` sendo exibida, você pode ter sua chamada de aplicativo para buscar a próxima tela cheia de registros.

Qualquer banco de dados ODBC acessado com objetos de conjunto de registros pode ter um cache local. Para criar o cache, abra um objeto de conjunto de `SetCacheSize` `SetCacheStart` registros a partir da fonte de dados remota e, em seguida, ligue para as funções e do membro do conjunto de registros. Se *o iSize* e *o lBookmark* criarem um intervalo que `SetCacheSize` `SetCacheStart`esteja parcialmente ou totalmente fora do intervalo especificado por e , a parte do conjunto de registros fora deste intervalo será ignorada e não será carregada no cache. Se `FillCache` as solicitações de mais registros do que permanecerna fonte remota de dados, apenas os registros restantes são buscados, e nenhuma exceção é lançada.

Os registros obtidos no cache não refletem as alterações feitas simultaneamente aos dados de origem por outros usuários.

`FillCache`busca apenas registros já não armazenados. Para forçar uma atualização de todos os `SetCacheSize` dados armazenados em cache, ligue `SetCacheSize` para a função de membro com um parâmetro *lSize* igual a 0, ligue novamente com o parâmetro *lSize* igual ao tamanho do cache que você solicitou originalmente e, em seguida, ligue `FillCache`.

Para obter informações relacionadas, consulte o tópico "FillCache Method" no DAO Help.

## <a name="cdaorecordsetfind"></a><a name="find"></a>CDaoRecordset::Encontrar

Ligue para esta função de membro para localizar uma seqüência de caracteres em um conjunto de registros do tipo dynaset ou snapshot usando um operador de comparação.

```
virtual BOOL Find(
    long lFindType,
    LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lFindType*<br/>
Um valor que indique o tipo de operação Encontrar desejado. Os valores possíveis são:

- AFX_DAO_NEXT Encontre a próxima localização de uma seqüência de string correspondente.

- AFX_DAO_PREV Encontre a localização anterior de uma seqüência de string correspondente.

- AFX_DAO_FIRST Encontre a primeira localização de uma seqüência de string correspondente.

- AFX_DAO_LAST Encontre a última localização de uma seqüência de string correspondente.

*lpszFilter*<br/>
Uma expressão de string (como a cláusula **WHERE** em uma declaração SQL sem a palavra **WHERE**) usada para localizar o registro. Por exemplo:

[!code-cpp[NVC_MFCDatabase#3](../../mfc/codesnippet/cpp/cdaorecordset-class_3.cpp)]

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

Você pode encontrar a primeira, próxima, anterior ou última instância da string. `Find`é uma função virtual, para que você possa substituí-la e adicionar sua própria implementação. As `FindFirst` `FindLast`funções de `FindNext`membro `FindPrev` e `Find` membro chamam a função `Find` de membro, para que você possa usar para controlar o comportamento de todas as operações Find.

Para localizar um registro em um conjunto de registros do tipo tabela, ligue para a função ['Membro Buscar'.](#seek)

> [!TIP]
> Quanto menor o conjunto de recordes que `Find` você tem, mais eficaz será. Em geral, e especialmente com os dados do ODBC, é melhor criar uma nova consulta que recupere apenas os registros que você deseja.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious Methods" no DAO Help.

## <a name="cdaorecordsetfindfirst"></a><a name="findfirst"></a>CDaoRecordset::FindFirst

Ligue para esta função de membro para encontrar o primeiro registro que corresponda a uma condição especificada.

```
BOOL FindFirst(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de string (como a cláusula **WHERE** em uma declaração SQL sem a palavra **WHERE**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

A `FindFirst` função membro inicia sua busca desde o início do conjunto de registros e busca até o final do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica) use uma das operações Move para passar de registro para registro. Para localizar um registro em um conjunto `Seek` de registros do tipo tabela, ligue para a função membro.

Se um registro que corresponda aos critérios não for localizado, o ponteiro de registro atual é indeterminado e `FindFirst` retorna zero. Se o conjunto de registros contiver mais de `FindFirst` um registro que `FindNext` satisfaça os critérios, localize a primeira ocorrência, localize a próxima ocorrência, e assim por diante.

> [!CAUTION]
> Se você editar o registro atual, certifique-se `Update` de salvar as alterações chamando a função de membro antes de passar para outro registro. Se você passar para outro registro sem atualização, suas alterações serão perdidas sem aviso.

O `Find` membro funciona a pesquisa a partir do local e na direção especificada na tabela a seguir:

|Encontrar operações|Begin|Direção de busca|
|---------------------|-----------|----------------------|
|`FindFirst`|Início do conjunto de registros|Fim do conjunto de registros|
|`FindLast`|Fim do conjunto de registros|Início do conjunto de registros|
|`FindNext`|Recorde atual|Fim do conjunto de registros|
|`FindPrevious`|Recorde atual|Início do conjunto de registros|

> [!NOTE]
> Quando você `FindLast`liga, o mecanismo de banco de dados microsoft jet preenche totalmente o seu conjunto de registros antes de iniciar a pesquisa, se isso ainda não tiver sido feito. A primeira pesquisa pode levar mais tempo do que as pesquisas subseqüentes.

Usar uma das operações Find não `MoveFirst` `MoveNext`é o mesmo que ligar ou, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode acompanhar uma operação Find com uma operação Move.

Tenha em mente o seguinte ao usar as operações Find:

- Se `Find` o retorno não for zero, o registro atual não será definido. Neste caso, você deve posicionar o ponteiro de registro atual de volta a um registro válido.

- Não é possível usar uma operação Encontrar com um conjunto de gravação de snapshot de rolagem somente para frente.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando pesquisar campos contendo datas, mesmo que você não esteja usando a versão americana do mecanismo de banco de dados Microsoft Jet; caso contrário, registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações Find é lento, especialmente quando se trabalha com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com **orderby** personalizado ou `CDaoQuerydef` **ONDE** cláusulas, consultas de parâmetros ou objetos que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious Methods" no DAO Help.

## <a name="cdaorecordsetfindlast"></a><a name="findlast"></a>CDaoRecordset::FindLast

Ligue para esta função de membro para encontrar o último registro que corresponda a uma condição especificada.

```
BOOL FindLast(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de string (como a cláusula **WHERE** em uma declaração SQL sem a palavra **WHERE**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

A `FindLast` função membro inicia sua busca no final do conjunto de registros e pesquisa para trás no início do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica) use uma das operações Move para passar de registro para registro. Para localizar um registro em um conjunto `Seek` de registros do tipo tabela, ligue para a função membro.

Se um registro que corresponda aos critérios não for localizado, o ponteiro de registro atual é indeterminado e `FindLast` retorna zero. Se o conjunto de registros contiver mais de `FindFirst` um registro que `FindNext` satisfaça os critérios, localize a primeira ocorrência, localize a próxima ocorrência após a primeira ocorrência, e assim por diante.

> [!CAUTION]
> Se você editar o registro atual, certifique-se `Update` de salvar as alterações chamando a função de membro antes de passar para outro registro. Se você passar para outro registro sem atualização, suas alterações serão perdidas sem aviso.

Usar uma das operações Find não `MoveFirst` `MoveNext`é o mesmo que ligar ou, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode acompanhar uma operação Find com uma operação Move.

Tenha em mente o seguinte ao usar as operações Find:

- Se `Find` o retorno não for zero, o registro atual não será definido. Neste caso, você deve posicionar o ponteiro de registro atual de volta a um registro válido.

- Não é possível usar uma operação Encontrar com um conjunto de gravação de snapshot de rolagem somente para frente.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando pesquisar campos contendo datas, mesmo que você não esteja usando a versão americana do mecanismo de banco de dados Microsoft Jet; caso contrário, registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações Find é lento, especialmente quando se trabalha com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com **orderby** personalizado ou `CDaoQuerydef` **ONDE** cláusulas, consultas de parâmetros ou objetos que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious Methods" no DAO Help.

## <a name="cdaorecordsetfindnext"></a><a name="findnext"></a>CDaoRecordset::FindNext

Ligue para esta função de membro para encontrar o próximo registro que corresponda a uma condição especificada.

```
BOOL FindNext(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de string (como a cláusula **WHERE** em uma declaração SQL sem a palavra **WHERE**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

A `FindNext` função membro inicia sua busca no registro atual e busca até o final do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica) use uma das operações Move para passar de registro para registro. Para localizar um registro em um conjunto `Seek` de registros do tipo tabela, ligue para a função membro.

Se um registro que corresponda aos critérios não for localizado, o ponteiro de registro atual é indeterminado e `FindNext` retorna zero. Se o conjunto de registros contiver mais de `FindFirst` um registro que `FindNext` satisfaça os critérios, localize a primeira ocorrência, localize a próxima ocorrência, e assim por diante.

> [!CAUTION]
> Se você editar o registro atual, certifique-se `Update` de salvar as alterações chamando a função de membro antes de passar para outro registro. Se você passar para outro registro sem atualização, suas alterações serão perdidas sem aviso.

Usar uma das operações Find não `MoveFirst` `MoveNext`é o mesmo que ligar ou, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode acompanhar uma operação Find com uma operação Move.

Tenha em mente o seguinte ao usar as operações Find:

- Se `Find` o retorno não for zero, o registro atual não será definido. Neste caso, você deve posicionar o ponteiro de registro atual de volta a um registro válido.

- Não é possível usar uma operação Encontrar com um conjunto de gravação de snapshot de rolagem somente para frente.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando pesquisar campos contendo datas, mesmo que você não esteja usando a versão americana do mecanismo de banco de dados Microsoft Jet; caso contrário, registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações Find é lento, especialmente quando se trabalha com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com **orderby** personalizado ou `CDaoQuerydef` **ONDE** cláusulas, consultas de parâmetros ou objetos que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious Methods" no DAO Help.

## <a name="cdaorecordsetfindprev"></a><a name="findprev"></a>Conjunto CDaoRecord::FindPrev

Ligue para esta função de membro para encontrar o registro anterior que corresponde a uma condição especificada.

```
BOOL FindPrev(LPCTSTR lpszFilter);
```

### <a name="parameters"></a>Parâmetros

*lpszFilter*<br/>
Uma expressão de string (como a cláusula **WHERE** em uma declaração SQL sem a palavra **WHERE**) usada para localizar o registro.

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

A `FindPrev` função membro inicia sua busca no registro atual e busca para trás no início do conjunto de registros.

Se você quiser incluir todos os registros em sua pesquisa (não apenas aqueles que atendem a uma condição específica) use uma das operações Move para passar de registro para registro. Para localizar um registro em um conjunto `Seek` de registros do tipo tabela, ligue para a função membro.

Se um registro que corresponda aos critérios não for localizado, o ponteiro de registro atual é indeterminado e `FindPrev` retorna zero. Se o conjunto de registros contiver mais de `FindFirst` um registro que `FindNext` satisfaça os critérios, localize a primeira ocorrência, localize a próxima ocorrência, e assim por diante.

> [!CAUTION]
> Se você editar o registro atual, certifique-se `Update` de salvar as alterações chamando a função de membro antes de passar para outro registro. Se você passar para outro registro sem atualização, suas alterações serão perdidas sem aviso.

Usar uma das operações Find não `MoveFirst` `MoveNext`é o mesmo que ligar ou, no entanto, o que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode acompanhar uma operação Find com uma operação Move.

Tenha em mente o seguinte ao usar as operações Find:

- Se `Find` o retorno não for zero, o registro atual não será definido. Neste caso, você deve posicionar o ponteiro de registro atual de volta a um registro válido.

- Não é possível usar uma operação Encontrar com um conjunto de gravação de snapshot de rolagem somente para frente.

- Você deve usar o formato de data dos EUA (mês-dia-ano) quando pesquisar campos contendo datas, mesmo que você não esteja usando a versão americana do mecanismo de banco de dados Microsoft Jet; caso contrário, registros correspondentes podem não ser encontrados.

- Ao trabalhar com bancos de dados ODBC e grandes dynasets, você pode descobrir que o uso das operações Find é lento, especialmente quando se trabalha com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com **orderby** personalizado ou `CDaoQuerydef` **ONDE** cláusulas, consultas de parâmetros ou objetos que recuperam registros indexados específicos.

Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext, FindPrevious Methods" no DAO Help.

## <a name="cdaorecordsetgetabsoluteposition"></a><a name="getabsoluteposition"></a>CDaoRecordset::GetAbsolutePosition

Retorna o número recorde do registro atual de um objeto de conjunto de registros.

```
long GetAbsolutePosition();
```

### <a name="return-value"></a>Valor retornado

Um inteiro de 0 para o número de registros no conjunto de registros. Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

O valor de propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se ao primeiro registro no conjunto de registros. Você pode determinar o número de registros preenchidos no conjunto de registros chamando [GetRecordCount](#getrecordcount). Ligar `GetRecordCount` pode levar algum tempo porque deve acessar todos os registros para determinar a contagem.

Se não houver registro atual, como quando não há registros no conjunto de discos, - 1 é devolvido. Se o registro atual for excluído, o valor da propriedade AbsolutePosition não será definido e o MFC abrirá uma exceção se for referenciado. Para conjuntos de discos do tipo dynaset, novos registros são adicionados ao final da seqüência.

> [!NOTE]
> Esta propriedade não se destina a ser usada como um número de registro de substituto. Os marcadores ainda são a maneira recomendada de reter e retornar a uma determinada posição e são a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros. Em particular, a posição de um determinado registro muda quando os registros anteriores são excluídos. Também não há garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem de registros individuais dentro de um conjunto de registros não é garantida a menos que seja criada com uma declaração SQL usando uma cláusula **ORDERBY.**

> [!NOTE]
> Esta função de membro é válida apenas para conjuntos de registros do tipo dynaset e do tipo snapshot.

Para obter informações relacionadas, consulte o tópico "AbsolutePosition Property" no DAO Help.

## <a name="cdaorecordsetgetbookmark"></a><a name="getbookmark"></a>CDaoRecordset::GetBookmark

Chame esta função de membro para obter o valor do marcador em um registro específico.

```
COleVariant GetBookmark();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor representando o marcador no registro atual.

### <a name="remarks"></a>Comentários

Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já tem um marcador único se ele os suporta. Ligue `CanBookmark` para determinar se um conjunto de registros suporta marcadores.

Você pode salvar o marcador para o registro atual atribuindo `COleVariant` o valor do marcador a um objeto. Para retornar rapidamente a esse registro a qualquer momento `SetBookmark` após a mudança para um `COleVariant` registro diferente, ligue com um parâmetro correspondente ao valor desse objeto.

> [!NOTE]
> Chamar [requery](#requery) altera marcadores DAO.

Para obter informações relacionadas, consulte o tópico "Bookmark Property" no DAO Help.

## <a name="cdaorecordsetgetcachesize"></a><a name="getcachesize"></a>Configuração cDaoRecord::GetCacheSize

Ligue para esta função de membro para obter o número de registros armazenados em cache.

```
long GetCacheSize();
```

### <a name="return-value"></a>Valor retornado

Um valor que especifica o número de registros em um conjunto de registros do tipo dynaset contendo dados a serem armazenados localmente em cache a partir de uma fonte de dados ODBC.

### <a name="remarks"></a>Comentários

O cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto através de objetos do conjunto de registros do tipo dynaset. Um cache é um espaço na memória local que contém os dados mais recentemente recuperados do servidor no caso de os dados serem solicitados novamente enquanto o aplicativo estiver em execução. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica o cache dos dados solicitados primeiro, em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na Ajuda da DAO.

## <a name="cdaorecordsetgetcachestart"></a><a name="getcachestart"></a>CDaoRecordset::GetCacheStart

Chame esta função de membro para obter o valor do marcador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
COleVariant GetCacheStart();
```

### <a name="return-value"></a>Valor retornado

A `COleVariant` que especifica o marcador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

O mecanismo de banco de dados do Microsoft Jet solicita registros dentro do cache que variam do cache, e ele solicita registros fora da faixa de cache do servidor.

> [!NOTE]
> Os registros recuperados do cache não refletem alterações feitas simultaneamente aos dados de origem por outros usuários.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na Ajuda da DAO.

## <a name="cdaorecordsetgetcurrentindex"></a><a name="getcurrentindex"></a>CDaoRecordset::GetCurrentIndex

Chame esta função de membro para determinar o índice atualmente em uso em um objeto indexado do tipo `CDaoRecordset` tabela.

```
CString GetCurrentIndex();
```

### <a name="return-value"></a>Valor retornado

Um `CString` contendo o nome do índice atualmente em uso com um conjunto de registros do tipo tabela. Retorna uma seqüência vazia se nenhum índice tiver sido definido.

### <a name="remarks"></a>Comentários

Este índice é a base para encomendar registros em um conjunto de registros do tipo tabela, e é usado pela função [Membro Seek](#seek) para localizar registros.

Um `CDaoRecordset` objeto pode ter mais de um índice, mas pode usar apenas um índice por vez (embora um objeto [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) possa ter vários índices definidos nele).

Para obter informações relacionadas, consulte o tópico "Objeto de Índice" e a definição "índice atual" na Ajuda da DAO.

## <a name="cdaorecordsetgetdatecreated"></a><a name="getdatecreated"></a>CDaoRecordset::GetDateCriado

Ligue para esta função de membro para recuperar a data e a hora em que uma tabela base foi criada.

```
COleDateTime GetDateCreated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) contendo a data e a hora em que a tabela base foi criada.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a tabela base foi criada.

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaorecordsetgetdatelastupdated"></a><a name="getdatelastupdated"></a>CDaoRecordset::GetDateUpdatedAtualizado

Ligue para esta função de membro para recuperar a data e a hora em que o esquema foi atualizado pela última vez.

```
COleDateTime GetDateLastUpdated();
```

### <a name="return-value"></a>Valor retornado

Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) contendo a data e a hora que a estrutura da tabela base (esquema) foi atualizada pela última vez.

### <a name="remarks"></a>Comentários

As configurações de data e hora são derivadas do computador no qual a estrutura da tabela base (esquema) foi atualizada pela última vez.

Para obter informações relacionadas, consulte o tópico "DataCreated, LastUpdated Properties" em DAO Help.

## <a name="cdaorecordsetgetdefaultdbname"></a><a name="getdefaultdbname"></a>CDaoRecordset::GetDefaultDBName

Ligue para esta função de membro para determinar o nome do banco de dados para este conjunto de registros.

```
virtual CString GetDefaultDBName();
```

### <a name="return-value"></a>Valor retornado

A `CString` que contém o caminho e o nome do banco de dados do qual este conjunto de registros é derivado.

### <a name="remarks"></a>Comentários

Se um conjunto de registros for criado sem um ponteiro para um [CDaoDatabase,](../../mfc/reference/cdaodatabase-class.md)então esse caminho será usado pelo conjunto de registros para abrir o banco de dados padrão. Por padrão, esta função retorna uma seqüência de string vazia. Quando o ClassWizard deriva rum novo conjunto de `CDaoRecordset`discos, ele criará essa função para você.

O exemplo a seguir ilustra o uso\\\\da barra invertida dupla ( ) na seqüência de string, como é necessário para que a seqüência seja interpretada corretamente.

[!code-cpp[NVC_MFCDatabase#4](../../mfc/codesnippet/cpp/cdaorecordset-class_4.cpp)]

## <a name="cdaorecordsetgetdefaultsql"></a><a name="getdefaultsql"></a>CDaoRecordset::GetDefaultSQL

O framework chama essa função de membro para obter a declaração SQL padrão na qual o conjunto de registros é baseado.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor retornado

A `CString` que contém a declaração SQL padrão.

### <a name="remarks"></a>Comentários

Isso pode ser um nome de tabela ou uma declaração SQL **SELECT.**

Você define indiretamente a declaração SQL padrão declarando sua classe de conjunto de discos com o ClassWizard, e o ClassWizard executa essa tarefa para você.

Se você passar uma seqüência sql nula para [abrir,](#open)então esta função será chamada para determinar o nome da tabela ou SQL para o seu conjunto de registros.

## <a name="cdaorecordsetgeteditmode"></a><a name="geteditmode"></a>CDaoRecordset::GetEditMode

Ligue para esta função de membro para determinar o estado de edição, que é um dos seguintes valores:

```
short GetEditMode();
```

### <a name="return-value"></a>Valor retornado

Retorna um valor que indica o estado de edição para o registro atual.

### <a name="remarks"></a>Comentários

|Valor|Descrição|
|-----------|-----------------|
|`dbEditNone`|Nenhuma operação de edição está em andamento.|
|`dbEditInProgress`|O `Edit` foi chamado.|
|`dbEditAdd`|O `AddNew` foi chamado.|

Para obter informações relacionadas, consulte o tópico "EditMode Property" na Ajuda da DAO.

## <a name="cdaorecordsetgetfieldcount"></a><a name="getfieldcount"></a>CDaoRecordset::GetFieldCount

Ligue para esta função de membro para recuperar o número de campos (colunas) definido no conjunto de registros.

```
short GetFieldCount();
```

### <a name="return-value"></a>Valor retornado

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Count Property" no DAO Help.

## <a name="cdaorecordsetgetfieldinfo"></a><a name="getfieldinfo"></a>CDaoRecordset::GetFieldInfo

Ligue para esta função de membro para obter informações sobre os campos em um conjunto de registros.

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
O índice baseado em zero do campo predefinido na coleção Fields do conjunto de registros, para busca por índice.

*Fieldinfo*<br/>
Uma referência a uma estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md)

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o conjunto de registros a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne. Para obter o melhor desempenho, recupere apenas o nível de informação necessário:

- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome, tipo, tamanho, atributos

- `AFX_DAO_SECONDARY_INFO`Informações primárias, além de: Posição ordinal, necessária, permitir comprimento zero, ordem de cooperação, nome estrangeiro, campo de origem, tabela de origem

- `AFX_DAO_ALL_INFO`Informações primárias e secundárias, além de: Valor padrão, regra de validação, texto de validação

*lpszName*<br/>
O nome do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um campo por índice. A outra versão permite que você procure um campo pelo nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você recebe informações para quaisquer níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaorecordsetgetfieldvalue"></a><a name="getfieldvalue"></a>CDaoRecordset::GetFieldValue

Ligue para esta função de membro para recuperar dados em um conjunto de registros.

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
Um ponteiro para uma seqüência que contém o nome de um campo.

*varValue*<br/>
Uma referência `COleVariant` a um objeto que armazenará o valor de um campo.

*nIndex*<br/>
Um índice baseado em zero do campo na coleção Fields do conjunto de registros, para busca por índice.

### <a name="return-value"></a>Valor retornado

As duas `GetFieldValue` versões desse retorno um valor retornam um objeto [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor de um campo.

### <a name="remarks"></a>Comentários

Você pode procurar um campo pelo nome ou por posição ordinal.

> [!NOTE]
> É mais eficiente chamar uma das versões desta `COleVariant` função de membro que toma uma referência `COleVariant` de objeto como parâmetro, em vez de chamar uma versão que retorna um objeto. As últimas versões desta função são mantidas para compatibilidade retrógrada.

Use `GetFieldValue` e [SetFieldValue](#setfieldvalue) para vincular dinamicamente campos em tempo de execução, em vez de colunas de vinculação estática usando o mecanismo [DoFieldExchange.](#dofieldexchange)

`GetFieldValue`e `DoFieldExchange` o mecanismo pode ser combinado para melhorar o desempenho. Por exemplo, `GetFieldValue` use para recuperar um valor que você precisa apenas sob demanda e atribua essa chamada a um botão "Mais Informações" na interface.

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Propriedade de valor" na Ajuda da DAO.

## <a name="cdaorecordsetgetindexcount"></a><a name="getindexcount"></a>CDaoRecordset::GetIndexCount

Ligue para esta função de membro para determinar o número de índices disponíveis no conjunto de registros do tipo tabela.

```
short GetIndexCount();
```

### <a name="return-value"></a>Valor retornado

O número de índices no conjunto de registros do tipo tabela.

### <a name="remarks"></a>Comentários

`GetIndexCount`é útil para looping através de todos os índices no conjunto de registros. Para isso, `GetIndexCount` use em conjunto com [getindexInfo](#getindexinfo). Se você chamar essa função de membro em conjuntos de registros do tipo dynaset ou do tipo snapshot, o MFC abrirá uma exceção.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaorecordsetgetindexinfo"></a><a name="getindexinfo"></a>CDaoRecordset::GetIndexInfo

Ligue para esta função de membro para obter vários tipos de informações sobre um índice definido na tabela base subjacente a um conjunto de registros.

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
O índice baseado em zero na coleção de Índices da tabela, para busca por posição numérica.

*indexinfo*<br/>
Uma referência a uma estrutura [CDaoIndexInfo.](../../mfc/reference/cdaoindexinfo-structure.md)

*dwInfoOptions*<br/>
Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis estão listadas aqui junto com o que fazem com que a função retorne. Para obter o melhor desempenho, recupere apenas o nível de informação necessário:

- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome, Informações de Campo, Campos

- `AFX_DAO_SECONDARY_INFO`Informações primárias, além de: Principal, Único, Agrupado, Ignorado, Obrigatório, Estrangeiro

- `AFX_DAO_ALL_INFO`Informações primárias e secundárias, além de: Contagem distinta

*lpszName*<br/>
Um ponteiro para o nome do objeto de índice, para procurar pelo nome.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um índice por sua posição na coleção. A outra versão permite que você procure um índice por nome.

Para obter uma descrição das informações retornadas, consulte a estrutura [CDaoIndexInfo.](../../mfc/reference/cdaoindexinfo-structure.md) Esta estrutura possui membros que correspondem aos itens de informação listados acima na descrição do *dwInfoOptions*. Quando você solicita informações em um nível, você recebe informações para quaisquer níveis anteriores também.

Para obter informações relacionadas, consulte o tópico "Atribui propriedade" na Ajuda da DAO.

## <a name="cdaorecordsetgetlastmodifiedbookmark"></a><a name="getlastmodifiedbookmark"></a>CDaoRecordset::GetLastModifiedBookmark

Ligue para esta função de membro para recuperar o marcador do registro adicionado ou atualizado mais recentemente.

```
COleVariant GetLastModifiedBookmark();
```

### <a name="return-value"></a>Valor retornado

Um `COleVariant` contendo um marcador que indica o registro adicionado ou alterado mais recentemente.

### <a name="remarks"></a>Comentários

Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já tem um marcador único se ele os suporta. Ligue para [o GetBookmark](#getbookmark) para determinar se o conjunto de registros suporta marcadores. Se o conjunto de registros não `CDaoException` suportar marcadores, um será lançado.

Quando você adiciona um disco, ele aparece no final do conjunto de discos, e não é o registro atual. Para tornar o novo `GetLastModifiedBookmark` registro atual, ligue e ligue `SetBookmark` para retornar ao registro recém-adicionado.

Para obter informações relacionadas, consulte o tópico "LastModified Property" no DAO Help.

## <a name="cdaorecordsetgetlockingmode"></a><a name="getlockingmode"></a>CDaoRecordset::GetLockingMode

Ligue para esta função de membro para determinar o tipo de bloqueio em vigor para o conjunto de registros.

```
BOOL GetLockingMode();
```

### <a name="return-value"></a>Valor retornado

Não zero se o tipo de bloqueio for pessimista, caso contrário 0 para bloqueio de registro otimista.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista estiver em vigor, a página de dados que contém o registro que você está editando é bloqueada assim que você chamar a função [Editar](#edit) membro. A página é desbloqueada quando você chama a função [Atualizar](#update) ou [Fechar](#close) membro ou qualquer uma das operações Mover ou Encontrar.

Quando o bloqueio otimista estiver em vigor, a página de dados que `Update` contém o registro é bloqueada apenas enquanto o registro estiver sendo atualizado com a função do membro.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

Para obter informações relacionadas, consulte os tópicos "LockEdits Property" e "Locking Behavior in Multiuser Applications" no DAO Help.

## <a name="cdaorecordsetgetname"></a><a name="getname"></a>CDaoRecordset::GetName

Ligue para esta função de membro para recuperar o nome do conjunto de registros.

```
CString GetName();
```

### <a name="return-value"></a>Valor retornado

Um `CString` contendo o nome do conjunto de discos.

### <a name="remarks"></a>Comentários

O nome do conjunto de registros deve começar com uma letra e pode conter um máximo de 40 caracteres. Ele pode incluir números e sublinhar caracteres, mas não pode incluir pontuação ou espaços.

Para obter informações relacionadas, consulte o tópico "Propriedade de nome" no DAO Help.

## <a name="cdaorecordsetgetparamvalue"></a><a name="getparamvalue"></a>Conjunto CDaoRecord::GetParamValue

Chame esta função de membro para recuperar o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.

```
virtual COleVariant GetParamValue(int nIndex);
virtual COleVariant GetParamValue(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
A posição numérica do parâmetro no objeto DAOParametro subjacente.

*lpszName*<br/>
O nome do parâmetro cujo valor você quer.

### <a name="return-value"></a>Valor retornado

Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.

### <a name="remarks"></a>Comentários

Você pode acessar o parâmetro pelo nome ou por sua posição numérica na coleção.

Para obter informações relacionadas, consulte o tópico "Objeto parâmetro" na Ajuda da DAO.

## <a name="cdaorecordsetgetpercentposition"></a><a name="getpercentposition"></a>CDaoRecordset::GetPercentPosition

Ao trabalhar com um conjunto de registros tipo dynaset `GetPercentPosition` ou snapshot, se você ligar antes de preencher totalmente o conjunto de registros, a quantidade de movimento é relativa ao número de registros acessados conforme indicado pela chamada [GetRecordCount](#getrecordcount).

```
float GetPercentPosition();
```

### <a name="return-value"></a>Valor retornado

Um número entre 0 e 100 que indica a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.

### <a name="remarks"></a>Comentários

Você pode passar para o último registro ligando para [o MoveLast](#movelast) para completar a população de todos os conjuntos de registros, mas isso pode levar um tempo significativo.

Você pode `GetPercentPosition` chamar todos os três tipos de objetos de conjunto de registros, incluindo tabelas sem índices. No entanto, `GetPercentPosition` você não pode chamar em instantâneos de rolagem somente para frente ou em um conjunto de registros aberto a partir de uma consulta de passagem contra um banco de dados externo. Se não houver registro atual, ou o registro `CDaoException` atual tiver sido apagado, um será jogado.

Para obter informações relacionadas, consulte o tópico "PercentPosition Property" no DAO Help.

## <a name="cdaorecordsetgetrecordcount"></a><a name="getrecordcount"></a>CDaoRecordset::GetRecordCount

Ligue para esta função de membro para descobrir quantos registros em um conjunto de registros foram acessados.

```
long GetRecordCount();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de registros acessados em um objeto de conjunto de registros.

### <a name="remarks"></a>Comentários

`GetRecordCount`não indica quantos registros estão contidos em um conjunto de registros do tipo dynaset ou do tipo snapshot até que todos os registros tenham sido acessados. Esta chamada de função de membro pode levar um tempo significativo para ser concluída.

Uma vez que o último registro tenha sido acessado, o valor de retorno indica o número total de registros não excluídos no conjunto de registros. Para forçar o último registro a `MoveLast` ser `FindLast` acessado, ligue para a função ou membro para o conjunto de registros. Você também pode usar uma contagem de SQL para determinar o número aproximado de registros que sua consulta retornará.

À medida que seu aplicativo exclui registros em um conjunto `GetRecordCount` de registros do tipo dynaset, o valor de retorno diminui. No entanto, os registros excluídos `GetRecordCount` por outros usuários não são refletidos até que o registro atual esteja posicionado em um registro excluído. Se você executar uma transação que afete a `GetRecordCount` contagem de registros e, posteriormente, reverter a transação, não refletirá o número real de registros restantes.

O valor `GetRecordCount` de um conjunto de registros do tipo snapshot não é afetado por alterações nas tabelas subjacentes.

O valor `GetRecordCount` de um conjunto de registros do tipo tabela reflete o número aproximado de registros na tabela e é afetado imediatamente à medida que os registros de tabela são adicionados e excluídos.

Um conjunto de registros sem registros retorna um valor de 0. Ao trabalhar com tabelas anexadas ou `GetRecordCount` bancos de dados ODBC, sempre retorna - 1. Chamar `Requery` a função de membro em um `GetRecordCount` conjunto de registros redefine o valor de como se a consulta fosse reexecutada.

Para obter informações relacionadas, consulte o tópico "RecordCount Property" no DAO Help.

## <a name="cdaorecordsetgetsql"></a><a name="getsql"></a>Conjunto CDaoRecord::GetSQL

Ligue para esta função de membro para obter a declaração SQL que foi usada para selecionar os registros do conjunto de registros quando ele foi aberto.

```
CString GetSQL() const;
```

### <a name="return-value"></a>Valor retornado

A `CString` que contém a declaração SQL.

### <a name="remarks"></a>Comentários

Esta será geralmente uma declaração SQL **SELECT.**

A seqüência `GetSQL` retornada é tipicamente diferente de qualquer string que você pode ter passado para o conjunto de registros no parâmetro *lpszSQL* para a função [membro Aberto.](#open) Isso porque o conjunto de registros constrói uma declaração SQL completa com base no que você `Open`passou, o que você especificou com o ClassWizard e o que você pode ter especificado no [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) membros de dados.

> [!NOTE]
> Ligue para esta função `Open`de membro somente depois de ligar .

Para obter informações relacionadas, consulte o tópico "Propriedade SQL" no DAO Help.

## <a name="cdaorecordsetgettype"></a><a name="gettype"></a>CDaoRecordset::GetType

Ligue para esta função de membro após abrir o conjunto de registros para determinar o tipo de objeto do conjunto de registros.

```
short GetType();
```

### <a name="return-value"></a>Valor retornado

Um dos seguintes valores que indica o tipo de conjunto de registros:

- `dbOpenTable`Conjunto de registros do tipo tabela

- `dbOpenDynaset`Conjunto de registros do tipo Dynaset

- `dbOpenSnapshot`Conjunto de registros do tipo snapshot

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "Tipo propriedade" no DAO Help.

## <a name="cdaorecordsetgetvalidationrule"></a><a name="getvalidationrule"></a>CDaoRecordset::GetValidationRule

Ligue para esta função de membro para determinar a regra usada para validar dados.

```
CString GetValidationRule();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto contendo um valor que valida os dados em um registro à medida que são alterados ou adicionados a uma tabela.

### <a name="remarks"></a>Comentários

Esta regra é baseada em texto e é aplicada cada vez que a tabela subjacente é alterada. Se os dados não forem legais, o MFC abre uma exceção. A mensagem de erro retornada é o texto da propriedade ValidationText do objeto de campo subjacente, se especificado, ou o texto da expressão especificada pela propriedade ValidationRule do objeto de campo subjacente. Você pode chamar [GetValidationText](#getvalidationtext) para obter o texto da mensagem de erro.

Por exemplo, um campo em um registro que exija o dia do mês pode ter uma regra de validação como "DIA ENTRE 1 E 31".

Para obter informações relacionadas, consulte o tópico "ValidationRule Property" no DAO Help.

## <a name="cdaorecordsetgetvalidationtext"></a><a name="getvalidationtext"></a>CDaoRecordset::GetValidationText

Chame esta função de membro para recuperar o texto da propriedade ValidationText do objeto de campo subjacente.

```
CString GetValidationText();
```

### <a name="return-value"></a>Valor retornado

Um `CString` objeto contendo o texto da mensagem que é exibido se o valor de um campo não satisfaça a regra de validação do objeto de campo subjacente.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte o tópico "ValidationText Property" no DAO Help.

## <a name="cdaorecordsetisbof"></a><a name="isbof"></a>Conjunto CDaoRecord::IsBOF

Ligue para esta função de membro antes de rolar de registro para gravar para saber se você já foi antes do primeiro registro do conjunto de discos.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros não contiver registros ou se você tiver rolado para trás antes do primeiro registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também `IsBOF` pode `IsEOF` ligar para determinar se o conjunto de registros contém registros ou está vazio. Imediatamente após a `Open`chamada, se o conjunto `IsBOF` de registros não contiver registros, retorna não zero. Quando você abre um conjunto de discos que tem pelo menos `IsBOF` um disco, o primeiro disco é o disco atual e retorna 0.

Se o primeiro registro for o `MovePrev` `IsBOF` registro atual e você ligar, posteriormente retornará sem zero. Se `IsBOF` retornar não zero `MovePrev`e você chamar, uma exceção será lançada. Se `IsBOF` o retorno não for zero, o registro atual é indefinido e qualquer ação que exija um registro atual resultará em uma exceção.

Efeito de métodos `IsBOF` `IsEOF` específicos sobre e configurações:

- Chamar `Open*` internamente faz o primeiro registro no registrodefinir o registro atual chamando `MoveFirst`. Portanto, chamar `Open` um conjunto vazio `IsBOF` de `IsEOF` registros causa e retornar não zero. (Veja a tabela a seguir `MoveFirst` para `MoveLast` o comportamento de uma falha ou chamada.)

- Todas as operações move que `IsBOF` `IsEOF` localizam com sucesso um registro causam ambos e retornam 0.

- Uma `AddNew` chamada seguida `Update` de uma chamada que insere com sucesso um novo registro fará com que `IsBOF` retorne 0, mas somente se `IsEOF` já estiver não zerado. O estado `IsEOF` de vontade permanecerá sempre inalterado. Como definido pelo mecanismo de banco de dados Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio está no final de um arquivo, de modo que qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que remova o único registro restante de um `IsBOF` conjunto `IsEOF`de registros, não mudará o valor ou .

Esta tabela mostra quais operações move `IsBOF` /  `IsEOF`são permitidas com diferentes combinações de .

||MoveFirst, MoveLast|Moveprev<br /><br /> Mover < 0|Mova-se 0|Movenext<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`=não zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`=0,<br /><br /> `IsEOF`=não zero|Permitido|Permitido|Exceção|Exceção|
|Ambos não zero|Exceção|Exceção|Exceção|Exceção|
|Ambos 0|Permitido|Permitido|Permitido|Permitido|

Permitir uma operação Move não significa que a operação localizará com sucesso um registro. Ele apenas indica que uma tentativa de executar a operação Mover especificada é permitida e não gerará uma exceção. O valor `IsBOF` das `IsEOF` funções e do membro pode mudar como resultado da tentativa de movimento.

O efeito das operações Move que não `IsBOF` localizam um registro sobre o valor e `IsEOF` as configurações é mostrado na tabela a seguir.

||Isbof|Iseof|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Zero|Zero|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Zero|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Zero|

Para obter informações relacionadas, consulte o tópico "BOF, Propriedades EOF" no DAO Help.

## <a name="cdaorecordsetisdeleted"></a><a name="isdeleted"></a>Conjunto CDaoRecord::IsDedeleted

Ligue para esta função de membro para determinar se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros estiver posicionado em um registro excluído; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para `IsDeleted` um registro e retornar TRUE (não zero), então você deve rolar para outro registro antes de executar quaisquer outras operações de conjunto de discos.

> [!NOTE]
> Você não precisa verificar o status excluído para registros em um conjunto de registros instantâneo ou tipo tabela. Como os registros não podem ser excluídos de `IsDeleted`um instantâneo, não há necessidade de chamar . Para conjuntos de registros de tipo de tabela, os registros excluídos são realmente removidos do conjunto de registros. Uma vez que um registro tenha sido excluído, seja por você, outro usuário ou em outro conjunto de registros, você não poderá voltar a esse registro. Portanto, não há necessidade `IsDeleted`de ligar.

Quando você exclui um registro de um dynaset, ele é removido do conjunto de registros e você não pode rolar de volta para esse registro. No entanto, se um registro em um dynaset for excluído por outro `IsDeleted` usuário ou em outro conjunto de registros com base na mesma tabela, retornará TRUE quando você rolar posteriormente para esse registro.

Para obter informações relacionadas, consulte os tópicos "Método de exclusão", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda da DAO.

## <a name="cdaorecordsetiseof"></a><a name="iseof"></a>Conjunto CDaoRecord::IsEOF

Chame esta função de membro enquanto você rola de registro para registro para saber se você foi além do último registro do conjunto de discos.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros não contiver registros ou se você tiver rolado além do último registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você também `IsEOF` pode ligar para determinar se o conjunto de registros contém registros ou está vazio. Imediatamente após a `Open`chamada, se o conjunto `IsEOF` de registros não contiver registros, retorna não zero. Quando você abre um conjunto de discos que tem pelo menos `IsEOF` um disco, o primeiro disco é o disco atual e retorna 0.

Se o último registro for o `MoveNext` `IsEOF` registro atual quando você ligar, posteriormente retornará não zero. Se `IsEOF` retornar não zero `MoveNext`e você chamar, uma exceção será lançada. Se `IsEOF` o retorno não for zero, o registro atual é indefinido e qualquer ação que exija um registro atual resultará em uma exceção.

Efeito de métodos `IsBOF` `IsEOF` específicos sobre e configurações:

- Chamar `Open` internamente faz o primeiro registro no registrodefinir o registro atual chamando `MoveFirst`. Portanto, chamar `Open` um conjunto vazio `IsBOF` de `IsEOF` registros causa e retornar não zero. (Veja a tabela a seguir `MoveFirst` para o comportamento de uma chamada falha.)

- Todas as operações move que `IsBOF` `IsEOF` localizam com sucesso um registro causam ambos e retornam 0.

- Uma `AddNew` chamada seguida `Update` de uma chamada que insere com sucesso um novo registro fará com que `IsBOF` retorne 0, mas somente se `IsEOF` já estiver não zerado. O estado `IsEOF` de vontade permanecerá sempre inalterado. Como definido pelo mecanismo de banco de dados Microsoft Jet, o ponteiro de registro atual de um conjunto de registros vazio está no final de um arquivo, de modo que qualquer novo registro é inserido após o registro atual.

- Qualquer `Delete` chamada, mesmo que remova o único registro restante de um `IsBOF` conjunto `IsEOF`de registros, não mudará o valor ou .

Esta tabela mostra quais operações move `IsBOF` /  `IsEOF`são permitidas com diferentes combinações de .

||MoveFirst, MoveLast|Moveprev<br /><br /> Mover < 0|Mova-se 0|Movenext<br /><br /> Mover > 0|
|------|-------------------------|-----------------------------|------------|-----------------------------|
|`IsBOF`=não zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|
|`IsBOF`=0,<br /><br /> `IsEOF`=não zero|Permitido|Permitido|Exceção|Exceção|
|Ambos não zero|Exceção|Exceção|Exceção|Exceção|
|Ambos 0|Permitido|Permitido|Permitido|Permitido|

Permitir uma operação Move não significa que a operação localizará com sucesso um registro. Ele apenas indica que uma tentativa de executar a operação Mover especificada é permitida e não gerará uma exceção. O valor `IsBOF` das `IsEOF` funções e do membro pode mudar como resultado da tentativa de Movimento.

O efeito das operações Move que não `IsBOF` localizam um registro sobre o valor e `IsEOF` as configurações é mostrado na tabela a seguir.

||Isbof|Iseof|
|------|-----------|-----------|
|`MoveFirst`, `MoveLast`|Zero|Zero|
|`Move` 0|Nenhuma alteração|Nenhuma alteração|
|`MovePrev`, `Move` < 0|Zero|Nenhuma alteração|
|`MoveNext`, `Move` > 0|Nenhuma alteração|Zero|

Para obter informações relacionadas, consulte o tópico "BOF, Propriedades EOF" no DAO Help.

## <a name="cdaorecordsetisfielddirty"></a><a name="isfielddirty"></a>CDaoRecordset::IsFieldDirty

Ligue para esta função de membro para determinar se o membro de dados de campo especificado de um dynaset foi sinalizado como "sujo" (alterado).

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos está sujo.

### <a name="return-value"></a>Valor retornado

Não zero se o membro de dados de campo especificado for sinalizado como sujo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados de campo sujo serão transferidos para `Update` o registro `CDaoRecordset` na fonte `Edit` de `AddNew`dados quando o registro atual for atualizado por uma chamada para a função de membro de (após uma chamada para ou ). Com esse conhecimento, você pode dar passos adicionais, como desmarcar o membro de dados de campo para marcar a coluna para que ela não seja escrita na fonte de dados.

`IsFieldDirty`é implementado `DoFieldExchange`através de .

## <a name="cdaorecordsetisfieldnull"></a><a name="isfieldnull"></a>CDaoRecordset::IsFieldNull

Ligue para esta função de membro para determinar se o membro de dados de campo especificado de um conjunto de registros foi sinalizado como Nulo.

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é Nulo.

### <a name="return-value"></a>Valor retornado

Não zero se o membro de dados de campo especificado for sinalizado como Nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

(Na terminologia do banco de dados, Nulo significa "não ter valor" e não é o mesmo que NULL em C++.) Se um membro de dados de campo for sinalizado como Nulo, ele será interpretado como uma coluna do registro atual para o qual não há valor.

> [!NOTE]
> Em certas situações, o uso `IsFieldNull` pode ser ineficiente, como ilustra o seguinte exemplo de código:

[!code-cpp[NVC_MFCDatabase#5](../../mfc/codesnippet/cpp/cdaorecordset-class_5.cpp)]

> [!NOTE]
> Se você estiver usando a vinculação `CDaoRecordset`de registro dinâmico, sem derivar, certifique-se de usar VT_NULL como mostrado no exemplo.

## <a name="cdaorecordsetisfieldnullable"></a><a name="isfieldnullable"></a>CDaoRecordset::IsFieldNullable

Ligue para esta função de membro para determinar se o membro de dados de campo especificado é "nulo" (pode ser definido como um valor nulo; C++ NULL não é o mesmo que Null, que, na terminologia do banco de dados, significa "não ter valor").

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é Nulo.

### <a name="return-value"></a>Valor retornado

Não zero se o membro de dados de campo especificado pode ser tornado nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um campo que não pode ser nulo deve ter um valor. Se você tentar definir tal campo como Nulo ao adicionar ou atualizar um registro, a fonte de dados rejeitará a adição ou atualização e `Update` lançará uma exceção. A exceção ocorre `Update`quando você `SetFieldNull`chama, não quando você chama .

## <a name="cdaorecordsetisopen"></a><a name="isopen"></a>CDaoRecordset::IsOpen

Ligue para esta função de membro para determinar se o conjunto de registros está aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a função `Open` `Requery` do objeto ou membro do conjunto de registros tiver sido previamente chamada e o conjunto de registros não tiver sido fechado; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cdaorecordsetm_bcheckcachefordirtyfields"></a><a name="m_bcheckcachefordirtyfields"></a>Conjunto CDaoRecord::m_bCheckCacheForDirtyFields

Contém um sinalizador indicando se os campos armazenados em cache são automaticamente marcados como sujos (alterados) e Nulos.

### <a name="remarks"></a>Comentários

O sinalizador é padrão para TRUE. A configuração neste membro de dados controla todo o mecanismo de buffer duplo. Se você definir o sinalizador como TRUE, poderá desativar o cache em campo por campo usando o mecanismo DFX. Se você definir a bandeira como `SetFieldDirty` `SetFieldNull` FALSA, você deve chamar e a si mesmo.

Defina este membro `Open`de dados antes de ligar . Este mecanismo é principalmente para facilitar o uso. O desempenho pode ser mais lento devido ao buffer duplo dos campos à medida que as alterações são feitas.

## <a name="cdaorecordsetm_nfields"></a><a name="m_nfields"></a>Conjunto CDaoRecord::m_nFields

Contém o número de membros de dados de campo na classe recordset e o número de colunas selecionadas pelo conjunto de registros a partir da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor para a classe recordset deve inicializar `m_nFields` com o número correto de campos estáticamente ligados. ClassWizard grava essa inicialização para você quando você a usa para declarar sua classe de conjunto de registros. Você também pode escrevê-lo manualmente.

O framework usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!NOTE]
> Este número deve corresponder ao número de `DoFieldExchange` colunas de `SetFieldType` saída registradas após uma chamada com o parâmetro `CDaoFieldExchange::outputColumn`.

Você pode vincular colunas dinamicamente por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue`. Se você fizer isso, você não precisa `m_nFields` incrementar a contagem para refletir `DoFieldExchange` o número de chamadas de função DFX na função de membro.

## <a name="cdaorecordsetm_nparams"></a><a name="m_nparams"></a>Conjunto CDaoRecord::m_nParams

Contém o número de membros de dados de parâmetros na classe recordset — o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se a sua classe de conjunto de registros tiver algum membro de dados de parâmetro, o construtor da classe deve inicializar *m_nParams* com o número correto. O valor de *m_nParams* é padrão para 0. Se você adicionar membros de dados de parâmetros — o que você deve fazer manualmente — você também deve adicionar manualmente uma inicialização no construtor de classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de espaços reservados '' em sua *m_strFilter* ou *m_strSort* string).

O framework usa esse número quando parametriza a consulta do conjunto de registros.

> [!NOTE]
> Este número deve corresponder ao número de "params" registrados `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro `CFieldExchange::param`.

Para obter informações relacionadas, consulte o tópico "Objeto parâmetro" na Ajuda da DAO.

## <a name="cdaorecordsetm_pdaorecordset"></a><a name="m_pdaorecordset"></a>Conjunto CDaoRecord::m_pDAORecordset

Contém um ponteiro para a interface OLE para o `CDaoRecordset` objeto conjunto de registros DAO subjacente ao objeto.

### <a name="remarks"></a>Comentários

Use este ponteiro se precisar acessar diretamente a interface DAO.

Para obter informações relacionadas, consulte o tópico "Recordset Object" no DAO Help.

## <a name="cdaorecordsetm_pdatabase"></a><a name="m_pdatabase"></a>Conjunto CDaoRecord::m_pDatabase

Contém um ponteiro `CDaoDatabase` para o objeto através do qual o conjunto de registros está conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Esta variável é definida de duas maneiras. Normalmente, você passa um ponteiro `CDaoDatabase` para um objeto já aberto quando você constrói o objeto recordset. Se você passar `CDaoRecordset` NULL `CDaoDatabase` em vez disso, cria um objeto para você e o abre. Em ambos `CDaoRecordset` os casos, armazena o ponteiro nesta variável.

Normalmente você não precisará usar diretamente `m_pDatabase`o ponteiro armazenado em . Se você escrever suas `CDaoRecordset`próprias extensões para, no entanto, você pode precisar usar o ponteiro. Por exemplo, você pode precisar do `CDaoException`ponteiro se você jogar o seu próprio (s).

Para obter informações relacionadas, consulte o tópico "Objeto de banco de dados" na Ajuda da DAO.

## <a name="cdaorecordsetm_strfilter"></a><a name="m_strfilter"></a>Conjunto CDaoRecord::m_strFilter

Contém uma string que é usada para construir a cláusula **WHERE** de uma declaração SQL.

### <a name="remarks"></a>Comentários

Ele não inclui a palavra reservada **ONDE** filtrar o conjunto de registros. O uso deste membro de dados não se aplica a conjuntos de registros de tipo de tabela. O uso `m_strFilter` de não tem efeito ao `CDaoQueryDef` abrir um conjunto de registros usando um ponteiro.

Use o formato de data dos EUA (mês-dia-ano) quando filtrar campos contendo datas, mesmo que você não esteja usando a versão americana do mecanismo de banco de dados Microsoft Jet; caso contrário, os dados podem não ser filtrados como você espera.

Para obter informações relacionadas, consulte o tópico "Filter Property" no DAO Help.

## <a name="cdaorecordsetm_strsort"></a><a name="m_strsort"></a>Conjunto CDaoRecord::m_strSort

Contém uma seqüência contendo a cláusula **ORDERBY** de uma declaração SQL sem as palavras reservadas **ORDERBY**.

### <a name="remarks"></a>Comentários

Você pode classificar em objetos de conjunto de gravação dynaset e snapshot.

Não é possível classificar objetos de conjunto de registros de tipo de tabela. Para determinar a ordem de tipo de um conjunto de registros de tipo de tabela, chame [SetCurrentIndex](#setcurrentindex).

O uso de *m_strSort* não tem efeito `CDaoQueryDef` ao abrir um conjunto de registros usando um ponteiro.

Para obter informações relacionadas, consulte o tópico "Sort Property" no DAO Help.

## <a name="cdaorecordsetmove"></a><a name="move"></a>CDaoRecordset::Mover

Chame esta função de membro para posicionar os registros *de linhas* de gravação do registro atual.

```
virtual void Move(long lRows);
```

### <a name="parameters"></a>Parâmetros

*LRows*<br/>
O número de registros para avançar ou retroceder. Valores positivos avançam, no final do conjunto de registros. Valores negativos se movem para trás, em direção ao início.

### <a name="remarks"></a>Comentários

Você pode ir para frente ou para trás. `Move( 1 )`é equivalente `MoveNext`a `Move( -1 )` , `MovePrev`e é equivalente a .

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Em geral, `IsBOF` ligue `IsEOF` para ambos e antes de uma operação Mover para determinar se o conjunto de registros tem algum registro. Depois de `Open` `Requery`ligar ou `IsBOF` `IsEOF`ligar ou.

> [!NOTE]
> Se você tiver passado o início ou o `IsBOF` `IsEOF` fim do conjunto de `Move` registros `CDaoException`(ou retorna não zero), uma chamada para lançar um .

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Quando você `Move` chama um instantâneo de rolagem somente para a frente, o parâmetro *lRows* deve ser um inteiro positivo e marcadores não são permitidos, para que você possa avançar apenas.

Para fazer o primeiro, último, próximo ou registro anterior em `MoveFirst`um `MoveLast` `MoveNext`registro `MovePrev` definido o registro atual, chame a função , ou membro.

Para obter informações relacionadas, consulte os tópicos "Move Method" e "MoveFirst, MoveLast, MoveNext, MovePrevious Methods" no DAO Help.

## <a name="cdaorecordsetmovefirst"></a><a name="movefirst"></a>CDaoRecordset::MoveFirst

Chame esta função de membro para fazer o primeiro registro no conjunto de registros (se houver) o registro atual.

```
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Você não precisa `MoveFirst` ligar imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Em geral, `IsBOF` ligue `IsEOF` para ambos e antes de uma operação Mover para determinar se o conjunto de registros tem algum registro. Depois de `Open` `Requery`ligar ou `IsBOF` `IsEOF`ligar ou.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Use `Move` as funções para mover de registro para registro sem aplicar uma condição. Use as operações Localizar para localizar registros em um objeto de conjunto de gravação tipo dynaset ou snapshot que satisfaça uma determinada condição. Para localizar um registro em um objeto `Seek`de conjunto de registros de tabela, chame .

Se o conjunto de registros se referir a um conjunto de registros do tipo tabela, o movimento seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade Index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Se você `MoveLast` chamar um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta será forçada a ser concluída e o objeto do conjunto de registros será totalmente preenchido.

Não é `MoveFirst` possível `MovePrev` chamar a função ou membro com um instantâneo de rolagem somente para a frente.

Para mover a posição do registro atual em um objeto de conjunto `Move`de registros, um número específico de registros para frente ou para trás, chame .

Para obter informações relacionadas, consulte os tópicos "Move Method" e "MoveFirst, MoveLast, MoveNext, MovePrevious Methods" no DAO Help.

## <a name="cdaorecordsetmovelast"></a><a name="movelast"></a>CDaoRecordset::MoveLast

Chame esta função de membro para fazer o último registro (se houver) no registrodefinir o registro atual.

```
void MoveLast();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Em geral, `IsBOF` ligue `IsEOF` para ambos e antes de uma operação Mover para determinar se o conjunto de registros tem algum registro. Depois de `Open` `Requery`ligar ou `IsBOF` `IsEOF`ligar ou.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Use `Move` as funções para mover de registro para registro sem aplicar uma condição. Use as operações Localizar para localizar registros em um objeto de conjunto de gravação tipo dynaset ou snapshot que satisfaça uma determinada condição. Para localizar um registro em um objeto `Seek`de conjunto de registros de tabela, chame .

Se o conjunto de registros se referir a um conjunto de registros do tipo tabela, o movimento seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade Index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Se você `MoveLast` chamar um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta será forçada a ser concluída e o objeto do conjunto de registros será totalmente preenchido.

Para mover a posição do registro atual em um objeto de conjunto `Move`de registros, um número específico de registros para frente ou para trás, chame .

Para obter informações relacionadas, consulte os tópicos "Move Method" e "MoveFirst, MoveLast, MoveNext, MovePrevious Methods" no DAO Help.

## <a name="cdaorecordsetmovenext"></a><a name="movenext"></a>CDaoRecordset::MoveNext

Chame esta função de membro para fazer o próximo registro no registrodo registro do registro atual.

```
void MoveNext();
```

### <a name="remarks"></a>Comentários

Recomenda-se que você `IsBOF` ligue antes de tentar passar para o registro anterior. Uma chamada `MovePrev` para `CDaoException` lançar `IsBOF` um não zero, indicando que você já rolou antes do primeiro registro ou que nenhum registro foi selecionado pelo conjunto de registros.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Em geral, `IsBOF` ligue `IsEOF` para ambos e antes de uma operação Mover para determinar se o conjunto de registros tem algum registro. Depois de `Open` `Requery`ligar ou `IsBOF` `IsEOF`ligar ou.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Use `Move` as funções para mover de registro para registro sem aplicar uma condição. Use as operações Localizar para localizar registros em um objeto de conjunto de gravação tipo dynaset ou snapshot que satisfaça uma determinada condição. Para localizar um registro em um objeto `Seek`de conjunto de registros de tabela, chame .

Se o conjunto de registros se referir a um conjunto de registros do tipo tabela, o movimento seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade Index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Para mover a posição do registro atual em um objeto de conjunto `Move`de registros, um número específico de registros para frente ou para trás, chame .

Para obter informações relacionadas, consulte os tópicos "Move Method" e "MoveFirst, MoveLast, MoveNext, MovePrevious Methods" no DAO Help.

## <a name="cdaorecordsetmoveprev"></a><a name="moveprev"></a>CDaoRecordset::MovePrev

Chame esta função de membro para fazer o registro anterior no registro do registro do registro atual.

```
void MovePrev();
```

### <a name="remarks"></a>Comentários

Recomenda-se que você `IsBOF` ligue antes de tentar passar para o registro anterior. Uma chamada `MovePrev` para `CDaoException` lançar `IsBOF` um não zero, indicando que você já rolou antes do primeiro registro ou que nenhum registro foi selecionado pelo conjunto de registros.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Em geral, `IsBOF` ligue `IsEOF` para ambos e antes de uma operação Mover para determinar se o conjunto de registros tem algum registro. Depois de `Open` `Requery`ligar ou `IsBOF` `IsEOF`ligar ou.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Use `Move` as funções para mover de registro para registro sem aplicar uma condição. Use as operações Localizar para localizar registros em um objeto de conjunto de gravação tipo dynaset ou snapshot que satisfaça uma determinada condição. Para localizar um registro em um objeto `Seek`de conjunto de registros de tabela, chame .

Se o conjunto de registros se referir a um conjunto de registros do tipo tabela, o movimento seguirá o índice atual da tabela. Você pode definir o índice atual usando a propriedade Index do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.

Não é `MoveFirst` possível `MovePrev` chamar a função ou membro com um instantâneo de rolagem somente para a frente.

Para mover a posição do registro atual em um objeto de conjunto `Move`de registros, um número específico de registros para frente ou para trás, chame .

Para obter informações relacionadas, consulte os tópicos "Move Method" e "MoveFirst, MoveLast, MoveNext, MovePrevious Methods" no DAO Help.

## <a name="cdaorecordsetopen"></a><a name="open"></a>CDaoRecordset::Abrir

Você deve chamar esta função de membro para recuperar os registros para o conjunto de registros.

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

- `dbOpenDynaset`Um conjunto de registros do tipo dynaset com rolagem bidirecional. Esse é o padrão.

- `dbOpenTable`Um conjunto de registros tipo tabela com rolagem bidirecional.

- `dbOpenSnapshot`Um conjunto de registros do tipo snapshot com rolagem bidirecional.

*lpszSQL*<br/>
Um ponteiro de string contendo um dos seguintes:

- Um ponteiro NULL.

- O nome de uma ou mais tabledefs e/ou querydefs (separados por comma).

- Uma declaração SQL **SELECT** (opcionalmente com uma cláusula SQL **WHERE** ou **ORDERBY).**

- Uma consulta de passagem.

*nOpções*<br/>
Uma ou mais opções listadas abaixo. O valor padrão é 0. Os valores possíveis são:

- `dbAppendOnly`Você só pode anexar novos registros (somente um conjunto de discos do tipo dynaset). Esta opção significa literalmente que os registros só podem ser anexados. As classes de banco de dados MFC ODBC têm uma opção somente de apêndice que permite que os registros sejam recuperados e anexados.

- `dbForwardOnly`O conjunto de registros é um instantâneo de rolagem somente para a frente.

- `dbSeeChanges`Gere uma exceção se outro usuário estiver alterando dados que você está editando.

- `dbDenyWrite`Outros usuários não podem modificar ou adicionar registros.

- `dbDenyRead`Outros usuários não podem exibir registros (somente conjunto de registros do tipo tabela).

- `dbReadOnly`Você só pode visualizar registros; outros usuários podem modificá-los.

- `dbInconsistent`Atualizações inconsistentes são permitidas (somente conjunto de registros do tipo dynaset).

- `dbConsistent`Somente atualizações consistentes são permitidas (somente conjunto de registros do tipo dynaset).

> [!NOTE]
> As constantes `dbInconsistent` são mutuamente exclusivas. `dbConsistent` Você pode usar um ou outro, mas não `Open`ambos em uma dada instância de .

*pTableDef*<br/>
Um ponteiro para um objeto [CDaoTableDef.](../../mfc/reference/cdaotabledef-class.md) Esta versão é válida apenas para conjuntos de registros do tipo tabela. Ao usar esta `CDaoDatabase` opção, o `CDaoRecordset` ponteiro usado para construir o não é usado; em vez disso, o banco de dados em que o tabledef reside é usado.

*pQueryDef*<br/>
Um ponteiro para um objeto [CDaoQueryDef.](../../mfc/reference/cdaoquerydef-class.md) Esta versão é válida apenas para conjuntos de registros do tipo dynaset e do tipo snapshot. Ao usar esta `CDaoDatabase` opção, o `CDaoRecordset` ponteiro usado para construir o não é usado; em vez disso, o banco de dados no qual o querydef reside é usado.

### <a name="remarks"></a>Comentários

Antes `Open`de chamar, você deve construir o objeto recordset. Há várias maneiras de fazer isso:

- Quando você constrói o objeto recordset, `CDaoDatabase` passe um ponteiro para um objeto que já está aberto.

- Quando você constrói o objeto do conjunto `CDaoDatabase` de registros, passe um ponteiro para um objeto que não esteja aberto. O conjunto de `CDaoDatabase` registros abre um objeto, mas não o fecha quando o objeto do conjunto de registros se fecha.

- Quando você constrói o objeto do conjunto de registros, passe um ponteiro NULL. O objeto do `GetDefaultDBName` conjunto de registros chama para obter o nome do Microsoft Access . MDB para abrir. O conjunto de `CDaoDatabase` gravações então abre um objeto e o mantém aberto enquanto o conjunto de registros estiver aberto. Quando você `Close` chama no conjunto `CDaoDatabase` de registros, o objeto também é fechado.

    > [!NOTE]
    >  Quando o conjunto `CDaoDatabase` de registros abre o objeto, ele abre a fonte de dados com acesso não exclusivo.

Para a `Open` versão do que usa o parâmetro *lpszSQL,* uma vez que o conjunto de registros está aberto, você pode recuperar registros de várias maneiras. A primeira opção é ter funções `DoFieldExchange`DFX em seu . A segunda opção é usar a `GetFieldValue` vinculação dinâmica chamando a função de membro. Essas opções podem ser implementadas separadamente ou em combinação. Se eles forem combinados, você terá que passar na declaração SQL você mesmo na chamada para `Open`.

Quando você usa a `Open` segunda versão `CDaoTableDef` de onde você passa em um objeto, `DoFieldExchange` as colunas resultantes estarão disponíveis `GetFieldValue`para você vincular via e o mecanismo DFX, e/ou vincular dinamicamente via .

> [!NOTE]
> Você só `Open` pode `CDaoTableDef` ligar usando um objeto para conjuntos de registros do tipo tabela.

Quando você usa a `Open` terceira versão `CDaoQueryDef` de onde você passa em um objeto, essa consulta será executada, `DoFieldExchange` e as colunas resultantes estarão `GetFieldValue`disponíveis para você vincular via e o mecanismo DFX, e/ou vincular dinamicamente via .

> [!NOTE]
> Você só `Open` pode `CDaoQueryDef` ligar usando um objeto para gravar do tipo dynaset e do tipo snapshot.

Para a primeira `Open` versão `lpszSQL` do que usa o parâmetro, os registros são selecionados com base nos critérios mostrados na tabela a seguir.

|Valor do `lpszSQL` parâmetro|Os registros selecionados são determinados por|Exemplo|
|--------------------------------------|----------------------------------------|-------------|
|NULO|A corda voltou `GetDefaultSQL`por .||
|Uma lista separada por comma de um ou mais nomes de tabledefs e/ou querydef.|Todas as colunas `DoFieldExchange`representadas no .|`"Customer"`|
|**Selecione** lista de **colunasDA** lista de tabela|As colunas especificadas das tabelas especificadas e/ou querydef(s).|`"SELECT CustId, CustName`<br /><br /> `FROM Customer"`|

O procedimento usual é `Open`passar NULL para; nesse caso, `Open` `GetDefaultSQL`chamadas , uma função de membro superridível que o ClassWizard gera ao criar uma `CDaoRecordset`classe derivada. Esse valor dá aos nomes tabledef(s) e/ou querydef especificados no ClassWizard. Em vez disso, você pode especificar outras informações no parâmetro *lpszSQL.*

O que `Open` quer que você passe, constrói uma seqüência final de SQL para a consulta (a seqüência pode ter cláusulas SQL **WHERE** e **ORDERBY** anexadas à seqüência *lpszSQL* que você passou) e, em seguida, executa a consulta. Você pode examinar a seqüência construída ligando `GetSQL` depois de chamar `Open`.

Os membros de dados de campo da sua classe de conjunto de registros estão vinculados às colunas dos dados selecionados. Se algum registro for devolvido, o primeiro registro se torna o registro atual.

Se você quiser definir opções para o conjunto de `m_strSort` registros, como um filtro ou classificar, definir ou `m_strFilter` depois de construir o objeto do conjunto de registros, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros `Requery`após o conjunto de registros já estar aberto, ligue .

Se você `Open` chamar um conjunto de registros tipo dynaset ou snapshot, ou se a fonte de dados se referir a uma declaração SQL ou a uma tabela que represente uma tabela anexada, você não poderá usar `dbOpenTable` para o argumento do tipo; se você fizer isso, MFC lança uma exceção. Para determinar se um objeto tabledef representa uma tabela anexada, crie um objeto [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) e chame sua função de membro [GetConnect.](../../mfc/reference/cdaotabledef-class.md#getconnect)

Use `dbSeeChanges` o sinalizador se desejar capturar alterações feitas por outro usuário ou outro programa em sua máquina quando estiver editando ou excluindo o mesmo registro. Por exemplo, se dois usuários começarem a editar o `Update` mesmo registro, o primeiro usuário a chamar a função de membro será bem sucedido. Quando `Update` é chamado pelo segundo `CDaoException` usuário, um é jogado. Da mesma forma, se o `Delete` segundo usuário tentar ligar para excluir o registro, `CDaoException` e ele já tiver sido alterado pelo primeiro usuário, um ocorrerá.

Normalmente, se o `CDaoException` usuário recebe isso durante a atualização, seu código deve atualizar o conteúdo dos campos e recuperar os valores recém-modificados. Se a exceção ocorrer no processo de exclusão, seu código poderá exibir os novos dados de registro para o usuário e uma mensagem indicando que os dados foram alterados recentemente. Neste ponto, seu código pode solicitar uma confirmação de que o usuário ainda quer excluir o registro.

> [!TIP]
> Use a opção de rolagem somente para frente (`dbForwardOnly`) para melhorar o desempenho quando seu aplicativo fizer uma única passagem através de um conjunto de registros aberto a partir de uma fonte de dados ODBC.

Para obter informações relacionadas, consulte o tópico "Método OpenRecordset" na Ajuda da DAO.

## <a name="cdaorecordsetrequery"></a><a name="requery"></a>Conjunto CDaoRecord::Requery

Chame esta função de membro para reconstruir (atualizar) um conjunto de registros.

```
virtual void Requery();
```

### <a name="remarks"></a>Comentários

Se algum registro for devolvido, o primeiro registro se torna o registro atual.

Para que o conjunto de registros reflita as adições e exclusões que você ou outros usuários `Requery`estão fazendo para a fonte de dados, você deve reconstruir o conjunto de registros ligando . Se o conjunto de registros for um dynaset, ele reflete automaticamente as atualizações que você ou outros usuários fazem aos seus registros existentes (mas não adições). Se o conjunto de registros for `Requery` um instantâneo, você deve ligar para refletir edições de outros usuários, bem como adições e exclusões.

Para um dynaset ou um `Requery` snapshot, ligue quando quiser reconstruir o conjunto de registros usando valores de parâmetros. Defina o novo filtro ou classifique definindo [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) antes de chamar `Requery`. Defina novos parâmetros atribuindo novos valores `Requery`aos membros de dados de parâmetros antes de chamar .

Se a tentativa de reconstruir o conjunto de registros falhar, o conjunto de registros será fechado. Antes de `Requery`ligar, você pode determinar se o conjunto de registros pode ser reiniciado ligando para a função de membro [canrestart.](#canrestart) `CanRestart`não garante `Requery` que terá sucesso.

> [!CAUTION]
> Ligue `Requery` só depois `Open`de ter ligado.

> [!NOTE]
> Chamar [requery](#requery) altera marcadores DAO.

Você não pode `Requery` chamar um conjunto de registros tipo dynaset ou snapshot se chamar `CanRestart` retorna 0, nem pode usá-lo em um conjunto de registros do tipo tabela.

Se `IsBOF` ambos `IsEOF` e retornar em `Requery`não zero após a chamada, a consulta não retornou nenhum registro e o conjunto de registros não conterá nenhum dado.

Para obter informações relacionadas, consulte o tópico "Requery Method" no DAO Help.

## <a name="cdaorecordsetseek"></a><a name="seek"></a>CDaoRecordset::Buscar

Chame esta função de membro para localizar o registro em um objeto de conjunto de registros indexado do tipo tabela que satisfaça os critérios especificados para o índice atual e faça com que esse registro registre o registro atual.

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

*lpszComparação*<br/>
Uma das seguintes expressões de\<cordas: "<", "=", "=", ">=", ou ">".

*pKey1*<br/>
Um ponteiro para uma [COleVariant](../../mfc/reference/colevariant-class.md) cujo valor corresponde ao primeiro campo do índice. Obrigatórios.

*pKey2*<br/>
Um ponteiro `COleVariant` para um cujo valor corresponde ao segundo campo no índice, se houver. Padrão para NULL.

*pKey3*<br/>
Um ponteiro `COleVariant` para um cujo valor corresponde ao terceiro campo no índice, se houver. Padrão para NULL.

*pKeyArray*<br/>
Um ponteiro para uma matriz de variantes. O tamanho da matriz corresponde ao número de campos no índice.

*nKeys*<br/>
Um inteiro correspondente ao tamanho da matriz, que é o número de campos no índice.

> [!NOTE]
> Não especifique curingas nas chaves. Curingas `Seek` farão com que não retornem registros correspondentes.

### <a name="return-value"></a>Valor retornado

Não zero se os registros correspondentes forem encontrados, caso contrário 0.

### <a name="remarks"></a>Comentários

Use a segunda versão `Seek` (matriz) de para lidar com índices de quatro campos ou mais.

`Seek`permite a pesquisa de índice de alto desempenho em conjuntos de registros do tipo tabela. Você deve definir o `SetCurrentIndex` índice `Seek`atual ligando antes de ligar . Se o índice identificar um campo ou `Seek` campo de chave não único, localize o primeiro registro que satisfaça os critérios. Se você não definir um índice, uma exceção será lançada.

Observe que se você não estiver criando `COleVariant` um conjunto de registros UNICODE, os objetos devem ser explicitamente declarados ANSI. Isso pode ser feito usando a forma [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant) `VT_BSTRT` `VT_BSTRT` `COleVariant` **)** *(lpszSrc* **,** *vtSrc* ) de construtor com *vtSrc* definido para (ANSI) ou usando a função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *(lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido para .**(**

Quando você `Seek`liga, você passa um ou mais valores-chave e um operador de comparação ("<", "=",\<"=", ">=" ou ">"). `Seek`pesquisa através dos campos-chave especificados e localiza o primeiro registro que satisfaz os critérios especificados por *lpszCompare* e *pKey1*. Uma vez `Seek` encontrado, retorna não zero, e faz esse registro atual. Se `Seek` não localizar uma `Seek` correspondência, retorna zero e o registro atual é indefinido. Ao usar o DAO diretamente, você deve verificar explicitamente a propriedade NoMatch.

Se `lpszComparison` for "=", ">=", `Seek` ou ">", começa no início do índice. Se *lpszComparison* for "<" ou `Seek` "<=", começa no final do índice e pesquisa para trás, a menos que haja entradas de índice duplicadas no final. Neste caso, `Seek` começa em uma entrada arbitrária entre as entradas de índice duplicado no final do índice.

Não precisa haver um registro atual `Seek`quando você usa .

Para localizar um registro em um conjunto de registros tipo dynaset ou snapshot que satisfaça uma condição específica, use as operações Find. Para incluir todos os registros, não apenas aqueles que satisfazem uma condição específica, use as operações move para passar de registro para registro.

Não é `Seek` possível chamar uma tabela anexada de qualquer tipo porque as tabelas anexadas devem ser abertas como conjuntos de registros do tipo dynaset ou do tipo snapshot. No entanto, `CDaoDatabase::Open` se você ligar para abrir diretamente `Seek` um banco de dados ISAM instalado, você pode chamar tabelas nesse banco de dados, embora o desempenho possa ser lento.

Para obter informações relacionadas, consulte o tópico "Buscar método" no DAO Help.

## <a name="cdaorecordsetsetabsoluteposition"></a><a name="setabsoluteposition"></a>CDaoRecordset::SetAbsolutePosition

Define o número de registro relativo do registro atual de um objeto de conjunto de registros.

```
void SetAbsolutePosition(long lPosition);
```

### <a name="parameters"></a>Parâmetros

*lPosição*<br/>
Corresponde à posição ordinal do registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

A `SetAbsolutePosition` chamada permite que você posicione o ponteiro de gravação atual em um registro específico com base em sua posição ordinal em um conjunto de registros tipo dynaset ou snapshot. Você também pode determinar o número de registro atual ligando para [GetAbsolutePosition](#getabsoluteposition).

> [!NOTE]
> Esta função de membro é válida apenas para conjuntos de registros do tipo dynaset e do tipo snapshot.

O valor de propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se ao primeiro registro no conjunto de registros. Definir um valor maior do que o número de registros preenchidos faz com que o MFC lance uma exceção. Você pode determinar o número de registros preenchidos `GetRecordCount` no conjunto de registros chamando a função membro.

Se o registro atual for excluído, o valor da propriedade AbsolutePosition não será definido e o MFC abrirá uma exceção se for referenciado. Novos registros são adicionados ao final da sequência.

> [!NOTE]
> Esta propriedade não se destina a ser usada como um número de registro de substituto. Os marcadores ainda são a maneira recomendada de reter e retornar a uma determinada posição e são a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros que suportam marcadores. Em particular, a posição de um determinado registro muda quando os registros anteriores são excluídos. Também não há garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem de registros individuais dentro de um conjunto de registros não é garantida a menos que seja criada com uma declaração SQL usando uma cláusula **ORDERBY.**

Para obter informações relacionadas, consulte o tópico "AbsolutePosition Property" no DAO Help.

## <a name="cdaorecordsetsetbookmark"></a><a name="setbookmark"></a>Conjunto CDaoRecord::SetBookmark

Chame esta função de membro para posicionar o conjunto de registros no registro que contém o marcador especificado.

```
void SetBookmark(COleVariant varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Um objeto [COleVariant](../../mfc/reference/colevariant-class.md) contendo o valor do marcador para um registro específico.

### <a name="remarks"></a>Comentários

Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já tem um marcador único. Você pode recuperar o marcador para `GetBookmark` o registro atual `COleVariant` chamando e salvando o valor para um objeto. Mais tarde, você pode `SetBookmark` retornar a esse registro ligando usando o valor de marcador salvo.

> [!NOTE]
> Chamar [requery](#requery) altera marcadores DAO.

Observe que se você não estiver criando `COleVariant` um conjunto de registros UNICODE, o objeto deve ser explicitamente declarado ANSI. Isso pode ser feito usando a forma [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant) `VT_BSTRT` `VT_BSTRT` `COleVariant` **)** *(lpszSrc* **,** *vtSrc* ) de construtor com *vtSrc* definido para (ANSI) ou usando a função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *(lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido para .**(**

Para obter informações relacionadas, consulte os tópicos "Propriedade de marcadores" e propriedade de marcadores" na Ajuda da DAO.

## <a name="cdaorecordsetsetcachesize"></a><a name="setcachesize"></a>Configuração de gravação de CDaoRecord::SetCacheSize

Ligue para esta função de membro para definir o número de registros a serem armazenados em cache.

```
void SetCacheSize(long lSize);
```

### <a name="parameters"></a>Parâmetros

*Lsize*<br/>
Especifica o número de registros. Um valor típico é 100. Um ajuste de 0 desliga o cache. A configuração deve estar entre 5 e 1200 registros. O cache pode usar uma quantidade considerável de memória.

### <a name="remarks"></a>Comentários

Um cache é um espaço na memória local que contém os dados mais recentemente recuperados do servidor no caso de os dados serem solicitados novamente enquanto o aplicativo estiver em execução. O cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto através de objetos do conjunto de registros do tipo dynaset. Quando os dados são solicitados, o mecanismo de banco de dados do Microsoft Jet verifica o cache dos dados solicitados primeiro, em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.

Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local. Para criar o cache, abra um objeto de conjunto `SetCacheSize` `SetCacheStart` de registros a partir `FillCache` da fonte de dados remota, ligue para as funções e o membro e, em seguida, ligue para a função de membro ou passe pelos registros usando uma das operações Mover. O parâmetro *lSize* `SetCacheSize` da função membro pode ser baseado no número de registros com os qual seu aplicativo pode trabalhar ao mesmo tempo. Por exemplo, se você estiver usando um conjunto de registros como a fonte `SetCacheSize` dos dados a serem exibidos na tela, você pode passar o parâmetro *lSize* como 20 para exibir 20 registros ao mesmo tempo.

Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart Properties" na Ajuda da DAO.

## <a name="cdaorecordsetsetcachestart"></a><a name="setcachestart"></a>CDaoRecordset::SetCacheStart

Ligue para esta função de membro para especificar o marcador do primeiro registro no conjunto de registros a ser armazenado em cache.

```
void SetCacheStart(COleVariant varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma [COleVariant](../../mfc/reference/colevariant-class.md) que especifica o marcador do primeiro registro no conjunto de registros a ser armazenado em cache.

### <a name="remarks"></a>Comentários

Você pode usar o valor do marcador de qualquer registro `SetCacheStart` para o parâmetro *varBookmark* da função membro. Faça o registro que deseja iniciar o cache com o registro atual, estabeleça um marcador para esse registro usando `SetCacheStart` [SetBookmark](#setbookmark)e passe o valor do marcador como parâmetro para a função de membro.

O mecanismo de banco de dados do Microsoft Jet solicita registros dentro do cache que variam do cache, e ele solicita registros fora da faixa de cache do servidor.

Os registros recuperados do cache não refletem alterações feitas simultaneamente aos dados de origem por outros usuários.

Para forçar uma atualização de todos os dados armazenados `SetCacheSize` em cache, passe o parâmetro *lSize* de 0, ligue `FillCache` `SetCacheSize` novamente com o tamanho do cache que você solicitou originalmente e, em seguida, ligue para a função de membro.

Observe que se você não estiver criando `COleVariant` um conjunto de registros UNICODE, o objeto deve ser explicitamente declarado ANSI. Isso pode ser feito usando a forma [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant) `VT_BSTRT` `VT_BSTRT` `COleVariant` **)** *(lpszSrc* **,** *vtSrc* ) de construtor com *vtSrc* definido para (ANSI) ou usando a função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *(lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido para .**(**

Para obter informações relacionadas, consulte o tópico CacheSize, CacheStart Properties" na Ajuda da DAO.

## <a name="cdaorecordsetsetcurrentindex"></a><a name="setcurrentindex"></a>CDaoRecordset::SetCurrentIndex

Ligue para esta função de membro para definir um índice em um conjunto de registros do tipo tabela.

```
void SetCurrentIndex(LPCTSTR lpszIndex);
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
Um ponteiro contendo o nome do índice a ser definido.

### <a name="remarks"></a>Comentários

Os registros nas tabelas base não são armazenados em nenhuma ordem específica. A definição de um índice altera a ordem dos registros retornados do banco de dados, mas não afeta a ordem em que os registros são armazenados. O índice especificado já deve ser definido. Se você tentar usar um objeto de índice que não existe, ou se o índice não for definido quando você chamar [Seek,](#seek)o MFC lançará uma exceção.

Você pode criar um novo índice para a tabela [chamando CDaoTableDef::CreateIndex](../../mfc/reference/cdaotabledef-class.md#createindex) e anexando o novo índice para a coleção De índices da tabela subjacente, [chamando CDaoTableDef::Apêndice](../../mfc/reference/cdaotabledef-class.md#append)e, em seguida, reabrindo o conjunto de registros.

Os registros retornados de um conjunto de registros do tipo tabela podem ser ordenados apenas pelos índices definidos para a tabela subjacente. Para classificar registros em algum outro pedido, você pode abrir um conjunto de registros tipo dynaset ou snapshot usando uma cláusula SQL **ORDERBY** armazenada em [CDaoRecordset::m_strSort](#m_strsort).

Para obter informações relacionadas, consulte o tópico "Objeto de Índice" e a definição "índice atual" na Ajuda da DAO.

## <a name="cdaorecordsetsetfielddirty"></a><a name="setfielddirty"></a>CDaoRecordset::SetFieldDirty

Chame esta função de membro para sinalizar um membro de dados de campo do conjunto de registros como alterado ou inalterado.

```
void SetFieldDirty(
    void* pv,
    BOOL bDirty = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou NULL. Se NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que Nulo na terminologia do banco de dados, o que significa "não ter valor".

*Bdirty*<br/>
TRUE se o membro de dados de campo for sinalizado como "sujo" (alterado). Caso contrário, FALSO se o membro de dados de campo for sinalizado como "limpo" (inalterado).

### <a name="remarks"></a>Comentários

A marcação de campos como inalterados garante que o campo não seja atualizado.

As marcas-quadro alteraram os membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo Detroca de campo de registro DAO (DFX). Alterar o valor de um campo geralmente define o campo sujo automaticamente, `SetFieldDirty` então você raramente precisará se chamar, mas às vezes você pode querer garantir que as colunas serão explicitamente atualizadas ou inseridas independentemente do valor no membro de dados de campo. O mecanismo DFX também emprega o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

Se o mecanismo de buffer duplo não estiver sendo usado, então alterar o valor do campo não definirá automaticamente o campo como sujo. Neste caso, será necessário explicitamente definir o campo como sujo. A bandeira contida no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla esta verificação automática de campo.

> [!NOTE]
> Chame esta função de membro somente depois de ter chamado [Edit](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função `outputColumn` aplicará a função `CDaoFieldExchange`a todos os campos, não aos campos de **param** em . Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#6](../../mfc/codesnippet/cpp/cdaorecordset-class_6.cpp)]

definirá `outputColumn` apenas campos para NULA; **campos de param** não serão afetados.

Para trabalhar em um **param,** você deve fornecer o endereço real do **param** individual que você deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#7](../../mfc/codesnippet/cpp/cdaorecordset-class_7.cpp)]

Isso significa que você não pode definir todos `outputColumn` os campos de **param** como NULO, como você pode com campos.

`SetFieldDirty`é implementado `DoFieldExchange`através de .

## <a name="cdaorecordsetsetfieldnull"></a><a name="setfieldnull"></a>CDaoRecordset::SetFieldNull

Chame esta função de membro para sinalizar um membro de dados de campo do conjunto de registros como Nulo (especificamente sem valor) ou como não-nulo.

```
void SetFieldNull(
    void* pv,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou NULL. Se NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que Nulo na terminologia do banco de dados, o que significa "não ter valor".

*bNull*<br/>
Não zero se o membro de dados de campo for sinalizado como sem valor (Nulo). Caso contrário, 0 se o membro de dados de campo for sinalizado como não-nulo.

### <a name="remarks"></a>Comentários

`SetFieldNull`é usado para campos `DoFieldExchange` ligados no mecanismo.

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujos" (alterados). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou são Nulas. Se não for apropriado fazer um campo Nulo, um [CDaoException](../../mfc/reference/cdaoexception-class.md) será lançado.

Se você estiver usando o mecanismo de buffer duplo, por exemplo, se desejar especificamente designar `SetFieldNull` um campo do registro atual como não tendo um valor, ligue com *bNull* definido como TRUE para desincordá-lo como Nulo. Se um campo foi previamente marcado como Nulo e agora você quer dar-lhe um valor, basta definir seu novo valor. Você não tem que remover `SetFieldNull`a bandeira nula com . Para determinar se o campo pode ser nulo, ligue para [IsFieldNullable](#isfieldnullable).

Se você não estiver usando o mecanismo de buffer duplo, então alterar o valor do campo não definirá automaticamente o campo como sujo e não nulo. Você deve definir especificamente os campos sujos e não nulos. A bandeira contida no [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla esta verificação automática de campo.

O mecanismo DFX emprega o uso de PSEUDONULL. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).

> [!NOTE]
> Chame esta função de membro somente depois de ter chamado [Edit](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função `outputColumn` aplicará a função `CDaoFieldExchange`apenas aos campos, não aos campos de **param** em . Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#8](../../mfc/codesnippet/cpp/cdaorecordset-class_8.cpp)]

definirá `outputColumn` apenas campos para NULA; **campos de param** não serão afetados.

## <a name="cdaorecordsetsetfieldvalue"></a><a name="setfieldvalue"></a>Configuração cDaoRecord::SetFieldValue

Chame esta função de membro para definir o valor de um campo, seja por posição ordinal ou alterando o valor da string.

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
Um ponteiro para uma seqüência contendo o nome de um campo.

*varValue*<br/>
Uma referência a um objeto [COleVariant](../../mfc/reference/colevariant-class.md) contendo o valor do conteúdo do campo.

*nIndex*<br/>
Um inteiro que representa a posição ordinal do campo na coleção Fields do conjunto de registros (baseado em zero).

*Lpszvalue*<br/>
Um ponteiro para uma seqüência contendo o valor do conteúdo do campo.

### <a name="remarks"></a>Comentários

Use `SetFieldValue` e [getFieldValue](#getfieldvalue) para vincular dinamicamente campos em tempo de execução, em vez de colunas de vinculação estática usando o mecanismo [DoFieldExchange.](#dofieldexchange)

Observe que se você não estiver criando um conjunto de `SetFieldValue` registros UNICODE, `COleVariant` você deve `COleVariant` usar uma forma de que não contenha um parâmetro, ou o objeto deve ser explicitamente declarado ANSI. Isso pode ser feito usando a forma [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant) `VT_BSTRT` `VT_BSTRT` `COleVariant` **)** *(lpszSrc* **,** *vtSrc* ) de construtor com *vtSrc* definido para (ANSI) ou usando a função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *(lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido para .**(**

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Propriedade de valor" na Ajuda da DAO.

## <a name="cdaorecordsetsetfieldvaluenull"></a><a name="setfieldvaluenull"></a>CDaoRecordset::SetFieldValueNull

Chame esta função de membro para definir o campo como um valor nulo.

```
void SetFieldValueNull(int nIndex);
void SetFieldValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para a busca por índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para procurar pelo nome.

### <a name="remarks"></a>Comentários

C++ NULL não é o mesmo que Null, o que, na terminologia do banco de dados, significa "não ter valor".

Para obter informações relacionadas, consulte os tópicos "Objeto de campo" e "Propriedade de valor" na Ajuda da DAO.

## <a name="cdaorecordsetsetlockingmode"></a><a name="setlockingmode"></a>CDaoRecordset::SetLockingMode

Ligue para esta função de membro para definir o tipo de bloqueio para o conjunto de registros.

```
void SetLockingMode(BOOL bPessimistic);
```

### <a name="parameters"></a>Parâmetros

*bPessimista*<br/>
Uma bandeira que indica o tipo de bloqueio.

### <a name="remarks"></a>Comentários

Quando o bloqueio pessimista estiver em vigor, a página 2K contendo o `Edit` registro que você está editando é bloqueada assim que você chamar a função de membro. A página é desbloqueada `Update` `Close` quando você chama a função ou membro ou qualquer uma das operações Mover ou Encontrar.

Quando o bloqueio otimista estiver em vigor, a página 2K que contém `Update` o registro é bloqueada apenas enquanto o registro estiver sendo atualizado com a função de membro.

Se uma página estiver bloqueada, nenhum outro usuário poderá editar registros na mesma página. Se você `SetLockingMode` ligar e passar um valor não zero e outro usuário já `Edit`tiver a página bloqueada, uma exceção será jogada quando você chamar . Outros usuários podem ler dados de páginas bloqueadas.

Se você `SetLockingMode` ligar com um `Update` valor zero e depois ligar enquanto a página estiver bloqueada por outro usuário, uma exceção ocorrerá. Para ver as alterações feitas no seu registro por `SetBookmark` outro usuário (e perder suas alterações), ligue para a função membro com o valor do marcador do registro atual.

Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.

## <a name="cdaorecordsetsetparamvalue"></a><a name="setparamvalue"></a>Conjunto CDaoRecord::SetParamValue

Chame esta função de membro para definir o valor de um parâmetro no conjunto de registros em tempo de execução.

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
A posição numérica do parâmetro na coleção de Parâmetros da consulta.

*Var*<br/>
O valor a ser definido; ver Observações.

*lpszName*<br/>
O nome do parâmetro cujo valor você deseja definir.

### <a name="remarks"></a>Comentários

O parâmetro já deve ter sido estabelecido como parte da seqüência SQL do conjunto de registros. Você pode acessar o parâmetro pelo nome ou pela posição de índice na coleção.

Especifique o `COleVariant` valor a ser definido como um objeto. Para obter informações sobre como definir `COleVariant` o valor e o tipo desejados no objeto, consulte [classe COleVariant](../../mfc/reference/colevariant-class.md). Observe que se você não estiver criando `COleVariant` um conjunto de registros UNICODE, o objeto deve ser explicitamente declarado ANSI. Isso pode ser feito usando a forma [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant) `VT_BSTRT` `VT_BSTRT` `COleVariant` **)** *(lpszSrc* **,** *vtSrc* ) de construtor com *vtSrc* definido para (ANSI) ou usando a função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** *(lpszSrc* **,** *vtSrc* **)** com *vtSrc* definido para .**(**

## <a name="cdaorecordsetsetparamvaluenull"></a><a name="setparamvaluenull"></a>CDaoRecordset::SetParamValueNull

Ligue para esta função de membro para definir o parâmetro como um valor nulo.

```
void SetParamValueNull(int nIndex);
void SetParamValueNull(LPCTSTR lpszName);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do campo no conjunto de registros, para a busca por índice baseado em zero.

*lpszName*<br/>
O nome do campo no conjunto de registros, para procurar pelo nome.

### <a name="remarks"></a>Comentários

C++ NULL não é o mesmo que Null, o que, na terminologia do banco de dados, significa "não ter valor".

## <a name="cdaorecordsetsetpercentposition"></a><a name="setpercentposition"></a>Conjunto CDaoRecord::SetPercentPosition

Chame essa função de membro para definir um valor que altera a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.

```
void SetPercentPosition(float fPosition);
```

### <a name="parameters"></a>Parâmetros

*fPosição*<br/>
Um número entre 0 e 100.

### <a name="remarks"></a>Comentários

Ao trabalhar com um conjunto de registros tipo dynaset ou snapshot, primeiro preencha o `SetPercentPosition`conjunto de registros movendo-se para o último registro antes de chamar . Se você `SetPercentPosition` ligar antes de preencher totalmente o conjunto de registros, a quantidade de movimento será relativa ao número de registros acessados conforme indicado pelo valor de [GetRecordCount](#getrecordcount). Você pode passar para o `MoveLast`último registro ligando.

Uma vez `SetPercentPosition`chamada, o registro na posição aproximada correspondente a esse valor torna-se atual.

> [!NOTE]
> Não `SetPercentPosition` é recomendado ligar para mover o registro atual para um registro específico em um conjunto de registros. Em vez disso, ligue para a função de membro [SetBookmark.](#setbookmark)

Para obter informações relacionadas, consulte o tópico "PercentPosition Property" no DAO Help.

## <a name="cdaorecordsetupdate"></a><a name="update"></a>CDaoRecordset::Atualização

Ligue para esta função de `AddNew` `Edit` membro após uma chamada para a função ou membro.

```
virtual void Update();
```

### <a name="remarks"></a>Comentários

Esta chamada é necessária `AddNew` `Edit` para completar a operação.

Ambos `AddNew` `Edit` e preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar a fonte de dados. `Update`salva os dados. Somente os campos marcados ou detectados conforme alterados são atualizados.

Se a fonte de dados suportar transações, você pode fazer a `Update` chamada (e sua correspondente `AddNew` ou `Edit` chamada) parte de uma transação.

> [!CAUTION]
> Se você `Update` ligar sem `Edit` `Update` antes `CDaoException`ligar `AddNew` ou jogar um . Se você `AddNew` `Edit`ligar ou `Update` , você deve ligar antes de chamar [O MoveNext](#movenext) ou fechar o conjunto de registros ou a conexão de origem de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Quando o objeto do conjunto de registros é bloqueado pessimicamente `Edit` em um ambiente multiusuário, o registro permanece bloqueado a partir do momento em que é usado até que a atualização seja concluída. Se o conjunto de registros estiver bloqueado com otimismo, o registro será bloqueado e comparado com o registro pré-editado pouco antes de ser atualizado no banco de dados. Se o registro mudou `Edit`desde `Update` que você ligou, a operação falha e o MFC abre uma exceção. Você pode alterar o `SetLockingMode`modo de bloqueio com .

> [!NOTE]
> O bloqueio otimista é sempre usado em formatos de banco de dados externos, como ODBC e ISAM instalável.

Para obter informações relacionadas, consulte os tópicos "AddNew Method", "CancelUpdate Method", "Delete Method", "LastModified Property", "Update Method" e "EditMode Property" na Ajuda da DAO.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)<br/>
[Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)<br/>
[Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)<br/>
