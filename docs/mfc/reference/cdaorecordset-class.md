---
title: Classe CDaoRecordset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 603cd1658af417dfbb7f2d8aa8022275e866a706
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33378898"
---
# <a name="cdaorecordset-class"></a>Classe CDaoRecordset
Representa um conjunto de registros selecionados de uma fonte de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDaoRecordset : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoRecordset::CDaoRecordset](#cdaorecordset)|Constrói um objeto `CDaoRecordset`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoRecordset::AddNew](#addnew)|Prepara para adicionar um novo registro. Chamar [atualização](#update) para concluir a adição.|  
|[CDaoRecordset::CanAppend](#canappend)|Retorna zero se novos registros podem ser adicionados ao conjunto de registros por meio de [AddNew](#addnew) função de membro.|  
|[CDaoRecordset::CanBookmark](#canbookmark)|Retorna zero se o conjunto de registros dá suporte a indicadores.|  
|[CDaoRecordset::CancelUpdate](#cancelupdate)|Cancela todas as atualizações pendentes devido a um [editar](#edit) ou [AddNew](#addnew) operação.|  
|[CDaoRecordset::CanRestart](#canrestart)|Retornará zero se [Requery](#requery) pode ser chamado para executar a consulta do conjunto de registros novamente.|  
|[CDaoRecordset::CanScroll](#canscroll)|Retorna zero se você pode percorrer os registros.|  
|[CDaoRecordset::CanTransact](#cantransact)|Retorna zero se a fonte de dados oferece suporte a transações.|  
|[CDaoRecordset::CanUpdate](#canupdate)|Retorna zero se o conjunto de registros pode ser atualizado (você pode adicionar, atualizar ou excluir registros).|  
|[CDaoRecordset::Close](#close)|Fecha o conjunto de registros.|  
|[CDaoRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Explicitamente, você deve rolar para outro registro após a exclusão.|  
|[CDaoRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados do campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa DAO registra troca de campos (DFX).|  
|[CDaoRecordset::Edit](#edit)|Prepara para as alterações no registro atual. Chamar **atualização** para concluir a edição.|  
|[CDaoRecordset::FillCache](#fillcache)|Preenchimentos todos ou parte de um cache local para um objeto de conjunto de registros que contém dados de uma fonte de dados ODBC.|  
|[CDaoRecordset::Find](#find)|Localiza o primeiro, próximo, anterior, ou o último local de uma cadeia de caracteres específica em um conjunto de registros do tipo dynaset que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindFirst](#findfirst)|Localiza o primeiro registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindLast](#findlast)|Localiza o último registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindNext](#findnext)|Localiza o próximo registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindPrev](#findprev)|Localiza o registro anterior em um tipo dynaset ou conjunto de registros do tipo de instantâneo que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::GetAbsolutePosition](#getabsoluteposition)|Retorna o número do registro de um objeto conjunto de registros atual.|  
|[CDaoRecordset::GetBookmark](#getbookmark)|Retorna um valor que representa o indicador em um registro.|  
|[CDaoRecordset::GetCacheSize](#getcachesize)|Retorna um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenada em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::GetCacheStart](#getcachestart)|Retorna um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|  
|[CDaoRecordset::GetCurrentIndex](#getcurrentindex)|Retorna um `CString` contendo o nome do índice mais recentemente usada em um tipo de tabela indexado, `CDaoRecordset`.|  
|[CDaoRecordset::GetDateCreated](#getdatecreated)|Retorna a data e hora a tabela base subjacente um `CDaoRecordset` objeto foi criado|  
|[CDaoRecordset::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e hora da alteração mais recente feita para o design de uma tabela base subjacente um `CDaoRecordset` objeto.|  
|[CDaoRecordset::GetDefaultDBName](#getdefaultdbname)|Retorna o nome da fonte de dados padrão.|  
|[CDaoRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres padrão SQL para executar.|  
|[CDaoRecordset::GetEditMode](#geteditmode)|Retorna um valor que indica o estado de edição para o registro atual.|  
|[CDaoRecordset::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos em um conjunto de registros.|  
|[CDaoRecordset::GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos no conjunto de registros.|  
|[CDaoRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::GetIndexCount](#getindexcount)|Recupera o número de índices em uma tabela subjacente de um conjunto de registros.|  
|[CDaoRecordset::GetIndexInfo](#getindexinfo)|Retorna a vários tipos de informações sobre um índice.|  
|[CDaoRecordset::GetLastModifiedBookmark](#getlastmodifiedbookmark)|Usado para determinar a mais recentemente adicionado ou atualizavam do registro.|  
|[CDaoRecordset::GetLockingMode](#getlockingmode)|Retorna um valor que indica o tipo de bloqueio que está em vigor durante a edição.|  
|[CDaoRecordset::GetName](#getname)|Retorna um `CString` que contém o nome do conjunto de registros.|  
|[CDaoRecordset::GetParamValue](#getparamvalue)|Recupera o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.|  
|[CDaoRecordset::GetPercentPosition](#getpercentposition)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|  
|[CDaoRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros acessados em um objeto de conjunto de registros.|  
|[CDaoRecordset::GetSQL](#getsql)|Obtém a cadeia de caracteres SQL usada para selecionar registros do conjunto de registros.|  
|[CDaoRecordset::GetType](#gettype)|Chamado para determinar o tipo de um conjunto de registros: tipo de tabela, tipo dynaset ou tipo de instantâneo.|  
|[CDaoRecordset::GetValidationRule](#getvalidationrule)|Retorna um `CString` que contém o valor que valida os dados enquanto ele é inserido em um campo.|  
|[CDaoRecordset::GetValidationText](#getvalidationtext)|Recupera o texto que é exibido quando uma regra de validação não for atendida.|  
|[CDaoRecordset::IsBOF](#isbof)|Retorna zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.|  
|[CDaoRecordset::IsDeleted](#isdeleted)|Retorna zero se o conjunto de registros é posicionado em um registro excluído.|  
|[CDaoRecordset::IsEOF](#iseof)|Retorna zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.|  
|[CDaoRecordset::IsFieldDirty](#isfielddirty)|Retorna zero se o campo especificado no registro atual tiver sido alterado.|  
|[CDaoRecordset::IsFieldNull](#isfieldnull)|Retorna zero se o campo especificado no registro atual é Null (não ter nenhum valor).|  
|[CDaoRecordset::IsFieldNullable](#isfieldnullable)|Retorna zero se o campo especificado no registro atual pode ser definido como Null (não ter nenhum valor).|  
|[CDaoRecordset::IsOpen](#isopen)|Retornará zero se [abrir](#open) foi chamado anteriormente.|  
|[CDaoRecordset::Move](#move)|Posiciona o conjunto de registros para um número especificado de registros do registro atual em qualquer direção.|  
|[CDaoRecordset::MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros.|  
|[CDaoRecordset::MoveLast](#movelast)|Posiciona o registro atual no último registro no conjunto de registros.|  
|[CDaoRecordset::MoveNext](#movenext)|Posiciona o registro atual no próximo registro no conjunto de registros.|  
|[CDaoRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior no conjunto de registros.|  
|[CDaoRecordset::Open](#open)|Cria um novo conjunto de registros de uma tabela, dynaset ou instantâneo.|  
|[CDaoRecordset::Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|  
|[CDaoRecordset::Seek](#seek)|Localiza o registro em um objeto de conjunto de registros do tipo de tabela indexada que atenda aos critérios especificados para o índice atual e torna esse registro o registro atual.|  
|[CDaoRecordset::SetAbsolutePosition](#setabsoluteposition)|Define o número do registro de um objeto conjunto de registros atual.|  
|[CDaoRecordset::SetBookmark](#setbookmark)|Posiciona o conjunto de registros em um registro que contém o indicador especificado.|  
|[CDaoRecordset::SetCacheSize](#setcachesize)|Define um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenada em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::SetCacheStart](#setcachestart)|Define um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|  
|[CDaoRecordset::SetCurrentIndex](#setcurrentindex)|Chamado para definir um índice em um conjunto de registros do tipo de tabela.|  
|[CDaoRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|  
|[CDaoRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual para Null (não ter nenhum valor).|  
|[CDaoRecordset::SetFieldValue](#setfieldvalue)|Define o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::SetFieldValueNull](#setfieldvaluenull)|Define o valor de um campo em um conjunto de registros como Null. (com nenhum valor).|  
|[CDaoRecordset::SetLockingMode](#setlockingmode)|Define um valor que indica o tipo de bloqueio para colocar em vigor durante a edição.|  
|[CDaoRecordset::SetParamValue](#setparamvalue)|Define o valor atual do parâmetro especificado armazenado no objeto subjacente DAOParameter|  
|[CDaoRecordset::SetParamValueNull](#setparamvaluenull)|Define o valor atual do parâmetro especificado como Null (não ter nenhum valor).|  
|[CDaoRecordset::SetPercentPosition](#setpercentposition)|Define a posição do registro atual para um local que corresponde a uma porcentagem do número total de registros em um conjunto de registros.|  
|[CDaoRecordset::Update](#update)|Conclui uma `AddNew` ou **editar** operação salvando os dados novos ou editados na fonte de dados.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoRecordset::m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields)|Contém um sinalizador que indica se os campos são automaticamente marcados como alterada.|  
|[CDaoRecordset::m_nFields](#m_nfields)|Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas, o conjunto de registros da fonte de dados.|  
|[CDaoRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro na classe de conjunto de registros, o número de parâmetros passados com a consulta do conjunto de registros|  
|[CDaoRecordset::m_pDAORecordset](#m_pdaorecordset)|Um ponteiro para a interface DAO base do objeto de conjunto de registros.|  
|[CDaoRecordset::m_pDatabase](#m_pdatabase)|Banco de dados de origem para este conjunto de resultados. Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.|  
|[CDaoRecordset::m_strFilter](#m_strfilter)|Contém uma cadeia de caracteres usada para construir um SQL **onde** instrução.|  
|[CDaoRecordset::m_strSort](#m_strsort)|Contém uma cadeia de caracteres usada para construir um SQL **ORDER BY** instrução.|  
  
## <a name="remarks"></a>Comentários  
 Conhecido como "conjunto de registros," `CDaoRecordset` objetos estão disponíveis em três formas a seguir:  
  
-   Conjuntos de registros do tipo de tabela representam uma tabela base que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados único.  
  
-   Conjuntos de registros do tipo dynaset são o resultado de uma consulta que pode ter registros atualizáveis. Esses conjuntos de registros são um conjunto de registros que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados subjacente ou tabelas. Conjuntos de registros do tipo dynaset podem conter campos de uma ou mais tabelas em um banco de dados.  
  
-   Conjuntos de registros do tipo de instantâneo são uma cópia estática de um conjunto de registros que você pode usar para encontrar dados ou gerar relatórios. Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados, mas não podem ser atualizados.  
  
 Cada formulário de conjunto de registros representa um conjunto de registros de determinada no momento em que o conjunto de registros é aberto. Quando você rolar para um registro em um conjunto de registros do tipo de tabela ou um conjunto de registros do tipo dynaset, ele reflete as alterações feitas no registro depois que o conjunto de registros é aberto por outros usuários ou por outros conjuntos de registros em seu aplicativo. (Um conjunto de registros do tipo de instantâneo não pode ser atualizado.) Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de conjunto de registros específicos do aplicativo de `CDaoRecordset`. Em seguida, você pode:  
  
-   Percorrer os registros.  
  
-   Definir um índice e procurar registros usando rapidamente [busca](#seek) (apenas conjuntos de registros do tipo de tabela).  
  
-   Localizar registros com base em uma comparação de cadeia de caracteres: "<","\<=", "=" "> =", ou ">" (tipo dynaset e conjuntos de registros do tipo de instantâneo).  
  
-   Atualizar os registros e especificar um modo de bloqueio (exceto os conjuntos de registros do tipo de instantâneo).  
  
-   Filtre o conjunto de registros para limitar os registros que ele seleciona entre os disponíveis na fonte de dados.  
  
-   Classifica o conjunto de registros.  
  
-   Parametrize o conjunto de registros para personalizar sua seleção com informações que não são conhecidas até o tempo de execução.  
  
 Classe `CDaoRecordset` fornece uma interface semelhante da classe `CRecordset`. A principal diferença é a classe `CDaoRecordset` acessa dados por meio de uma Data Access Object (DAO) com base em OLE. Classe `CRecordset` acessa o DBMS por meio da conectividade aberta de banco de dados (ODBC) e um driver ODBC para que DBMS.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de porque elas são específicas para o mecanismo de banco de dados Microsoft Jet.  
  
 Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de `CDaoRecordset`. Para usar uma classe de conjunto de registros em ambos os casos, abra um banco de dados e construir um objeto de conjunto de registros, passando ao construtor um ponteiro para o `CDaoDatabase` objeto. Você também pode construir um `CDaoRecordset` de objeto e permitir que o MFC criar um temporário `CDaoDatabase` objeto para você. Em seguida, chame o conjunto de registros [abrir](#open) função de membro, especificando se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo. Chamando **abrir** seleciona os dados do banco de dados e recupera o primeiro registro.  
  
 Use os membros de funções e os dados de membro do objeto para percorrer os registros e operar sobre elas. As operações disponíveis dependem se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo e se ela é atualizável ou somente leitura — isso depende da capacidade do banco de dados ou da conectividade aberta de banco de dados (ODBC) fonte de dados. Para atualizar os registros que podem foram alterados ou adicionados desde o **abrir** chamar, chame o objeto [Requery](#requery) função de membro. Chamar o objeto **fechar** membro de função e destruir o objeto quando você terminar com ele.  
  
 `CDaoRecordset` usa a troca de campos de registro DAO (DFX) para dar suporte ao ler e atualizar campos de registro por meio de membros de C++ de tipo seguro de sua `CDaoRecordset` ou `CDaoRecordset`-classe derivada. Você também pode implementar a associação dinâmica de colunas em um banco de dados sem usar o mecanismo DFX usando [GetFieldValue](#getfieldvalue) e [SetFieldValue](#setfieldvalue).  
  
 Para obter informações relacionadas, consulte o tópico "Objeto Recordset" na Ajuda do DAO.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDaoRecordset`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="addnew"></a>  CDaoRecordset::AddNew  
 Chame essa função de membro para adicionar um novo registro para um conjunto de registros do tipo de tabela ou do tipo dynaset.  
  
```  
virtual void AddNew();
```  
  
### <a name="remarks"></a>Comentários  
 Campos de registro são inicialmente nulos. (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é o mesmo que **nulo** em C++.) Para concluir a operação, você deve chamar o [atualização](#update) função de membro. **Atualização** salva as alterações para a fonte de dados.  
  
> [!CAUTION]
>  Se você editar um registro e, em seguida, role até outro registro sem chamar **atualização**, suas alterações serão perdidas sem aviso.  
  
 Se você adicionar um registro para um conjunto de registros do tipo dynaset chamando [AddNew](#addnew), o registro está visível no conjunto de registros e incluído na tabela base onde se torna visível para qualquer novo `CDaoRecordset` objetos.  
  
 A posição do novo registro depende do tipo de conjunto de registros:  
  
-   Um tipo dynaset recordset, onde o novo registro é inserido não é garantida. Esse comportamento foi alterado com o Microsoft Jet 3.0 por motivos de desempenho e a simultaneidade. Se seu objetivo é fazer o registro adicionado recentemente o registro atual, obtenha o indicador do último registro modificado e mover para esse indicador:  
  
 [!code-cpp[NVC_MFCDatabase#1](../../mfc/codesnippet/cpp/cdaorecordset-class_1.cpp)]  
  
-   Em um conjunto de registros de tipo de tabela para a qual um índice foi especificado, os registros são retornados em seu lugar adequado na ordem de classificação. Se nenhum índice foi especificado, novos registros são retornados no final do conjunto de registros.  
  
 O registro atual antes de você usou `AddNew` permanece atual. Se você deseja tornar o novo registro atual e o conjunto de registros dá suporte a indicadores, chamada [SetBookmark](#setbookmark) para o indicador identificado pela configuração da propriedade LastModified do objeto de conjunto de registros DAO subjacente. Isso é útil para determinar o valor para campos de contador (incremento automático) em um registro adicional. Para obter mais informações, consulte [GetLastModifiedBookmark](#getlastmodifiedbookmark).  
  
 Se o banco de dados oferece suporte a transações, você pode fazer seu `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte a classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). Observe que você deve chamar [CDaoWorkspace::BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans) antes de chamar `AddNew`.  
  
 Não é possível chamar `AddNew` para um conjunto de registros cujo [abrir](#open) função de membro não foi chamada. Um `CDaoException` é gerada se você chamar `AddNew` para um conjunto de registros que não pode ser anexado. Você pode determinar se o conjunto de registros é atualizável chamando [CanAppend](#canappend).  
  
 As marcas de framework alterado membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, para que você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas independentemente qual é o valor é no membro de dados do campo. O mecanismo DFX emprega o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como sujos. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática campo.  
  
> [!NOTE]
>  Se os registros são armazenados em buffer duplo (ou seja, a verificação automática campo está habilitada), chamando `CancelUpdate` restaurará as variáveis de membro para os valores que tinham antes `AddNew` ou **editar** foi chamado.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Método CancelUpdate", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="canappend"></a>  CDaoRecordset::CanAppend  
 Chamar essa função de membro para determinar se o conjunto de registros aberto anteriormente permite adicionar novos registros, chamando o [AddNew](#addnew) função de membro.  
  
```  
BOOL CanAppend() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros permite adicionar novos registros. Caso contrário, 0. `CanAppend` retornará 0 se você abriu o conjunto de registros como somente leitura.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Acrescentar Method" na Ajuda do DAO.  
  
##  <a name="canbookmark"></a>  CDaoRecordset::CanBookmark  
 Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite marcar individualmente registros usando indicadores.  
  
```  
BOOL CanBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros dá suporte a indicadores, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver usando conjuntos de registros inteiramente baseados em tabelas do mecanismo de banco de dados Microsoft Jet, indicadores podem ser usados exceto em conjuntos de registros do tipo de instantâneo marcados como somente de encaminhamento conjuntos de registros de rolagem. Outros produtos de banco de dados (fontes de dados externas ODBC) podem não oferecer suporte a indicadores.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Bookmarkable" na Ajuda do DAO.  
  
##  <a name="cancelupdate"></a>  CDaoRecordset::CancelUpdate  
 O `CancelUpdate` função membro cancela todas as atualizações pendentes devido a um [editar](#edit) ou [AddNew](#addnew) operação.  
  
```  
virtual void CancelUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se um aplicativo chamar o **editar** ou `AddNew` função de membro e não chamado [atualização](#update), `CancelUpdate` cancela qualquer alteração feita após **editar**ou `AddNew` foi chamado.  
  
> [!NOTE]
>  Se os registros são armazenados em buffer duplo (ou seja, a verificação automática campo está habilitada), chamando `CancelUpdate` restaurará as variáveis de membro para os valores que tinham antes `AddNew` ou **editar** foi chamado.  
  
 Se não houver nenhum **editar** ou `AddNew` operação pendente, `CancelUpdate` faz com que o MFC lançar uma exceção. Chamar o [GetEditMode](#geteditmode) a função de membro para determinar se há uma operação pendente que pode ser cancelada.  
  
 Para obter informações relacionadas, consulte o tópico "Método CancelUpdate" na Ajuda do DAO.  
  
##  <a name="canrestart"></a>  CDaoRecordset::CanRestart  
 Chamar essa função de membro para determinar se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) ao chamar o **Requery** função de membro.  
  
```  
BOOL CanRestart();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se **Requery** pode ser chamado para executar consulta do conjunto de registros novamente, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Não oferecem suporte a conjuntos de registros do tipo de tabela **Requery**.  
  
 Se **Requery** não é tem suporte, chame [fechar](#close) , em seguida, [abrir](#open) para atualizar os dados. Você pode chamar **Requery** atualizar um objeto de conjunto de registros de base do consulta parâmetro depois que os valores de parâmetro foram alterados.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade reiniciáveis" na Ajuda do DAO.  
  
##  <a name="canscroll"></a>  CDaoRecordset::CanScroll  
 Chame essa função de membro para determinar se o conjunto de registros permite rolagem.  
  
```  
BOOL CanScroll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se você pode percorrer os registros, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [abrir](#open) com **dbForwardOnly**, o conjunto de registros só pode rolar para frente.  
  
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
 Um conjunto de registros pode ser somente leitura se a fonte de dados é somente leitura ou se você tiver especificado **dbReadOnly** para `nOptions` quando você chamou [abrir](#open) para o conjunto de registros.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="cdaorecordset"></a>  CDaoRecordset::CDaoRecordset  
 Constrói um objeto `CDaoRecordset`.  
  
```  
CDaoRecordset(CDaoDatabase* pDatabase = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDatabase`  
 Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto ou o valor **nulo**. Se não **nulo** e `CDaoDatabase` do objeto **abrir** a função de membro não foi chamada para conectar-se à fonte de dados, o conjunto de registros tenta abri-lo para você durante a sua própria [abrir ](#open) chamar. Se você passar **nulo**, um `CDaoDatabase` objeto é construído e conectado usando as informações da fonte de dados especificado se você derivado sua classe de conjunto de registros de `CDaoRecordset`.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `CDaoRecordset` diretamente ou derivar uma classe específica de aplicativo de `CDaoRecordset`. Você pode usar ClassWizard para derivar as classes de conjunto de registros.  
  
> [!NOTE]
>  Se você derivar uma `CDaoRecordset` classe derivada classe deve fornecer seu próprio construtor. No construtor de classe derivada, chame o construtor `CDaoRecordset::CDaoRecordset`, passando os parâmetros apropriados ao longo para ela.  
  
 Passar **nulo** para o construtor de conjunto de registros para ter um `CDaoDatabase` objeto construído e conectado automaticamente para você. Esse é um atalho útil que não exige que você criar e conectar-se um `CDaoDatabase` objeto antes de construir o conjunto de registros. Se o `CDaoDatabase` objeto não estiver aberto, uma [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto também será criado para você que usa o espaço de trabalho padrão. Para obter mais informações, consulte [CDaoDatabase::CDaoDatabase](../../mfc/reference/cdaodatabase-class.md#cdaodatabase).  
  
##  <a name="close"></a>  CDaoRecordset::Close  
 Fechando uma `CDaoRecordset` objeto remove da coleção de conjuntos de registros abertos no banco de dados associado.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Porque **fechar** não destrói o `CDaoRecordset` do objeto, você pode reutilizar o objeto chamando **abrir** na mesma fonte de dados ou outra fonte de dados.  
  
 Todas as pendentes [AddNew](#addnew) ou [editar](#edit) instruções são canceladas, e todas as transações pendentes serão revertidas. Se você quiser preservar adições ou edições pendentes, chame [atualização](#update) antes de chamar **fechar** para cada conjunto de registros.  
  
 Você pode chamar **abrir** novamente depois de chamar **fechar**. Isso lhe permite reutilizar o objeto de conjunto de registros. É uma alternativa melhor chamar [Requery](#requery), se possível.  
  
 Para obter informações relacionadas, consulte o tópico "Método Close" na Ajuda do DAO.  
  
##  <a name="delete"></a>  CDaoRecordset::Delete  
 Chame essa função de membro para excluir o registro atual em um objeto de conjunto de registros do tipo dynaset ou tipo de tabela aberto.  
  
```  
virtual void Delete();
```  
  
### <a name="remarks"></a>Comentários  
 Após a exclusão bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor Null, e você deve chamar explicitamente uma das funções de membro de navegação de conjunto de registros ( [mover](#move), [busca](#seek), [ SetBookmark](#setbookmark), e assim por diante) para sair do registro excluído. Quando você excluir registros de um conjunto de registros, deve haver um registro atual no conjunto de registros antes de chamar **excluir**; caso contrário, MFC lança uma exceção.  
  
 **Excluir** remove o registro atual e a torna inacessível. Embora você não pode editar ou usar o registro excluído, ele permanece atual. Quando você move para outro registro, no entanto, você não pode fazer o registro excluído atual novamente.  
  
> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve ter um registro válido atual no conjunto de registros ao chamar **excluir**. Por exemplo, se você excluir um registro, mas não rolam para um novo registro antes de chamar **excluir** novamente, **excluir** lança um [CDaoException](../../mfc/reference/cdaoexception-class.md).  
  
 Você pode cancelar a exclusão de um registro se você usar transações e você chamar o [CDaoWorkspace::Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) função de membro. Se a tabela base é a tabela primária em cascata Excluir relação, excluir o registro atual também pode excluir um ou mais registros em uma tabela externa. Para obter mais informações, consulte a definição "em cascata" excluir na Ajuda do DAO.  
  
 Ao contrário de `AddNew` e **editar**, uma chamada para **excluir** não é seguido por uma chamada para **atualização**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="dofieldexchange"></a>  CDaoRecordset::DoFieldExchange  
 O framework chama esta função de membro para automaticamente trocar dados entre os membros de dados do campo de seu objeto de conjunto de registros e as colunas correspondentes do registro atual na fonte de dados.  
  
```  
virtual void DoFieldExchange(CDaoFieldExchange* pFX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Contém um ponteiro para um `CDaoFieldExchange` objeto. A estrutura serão já configurou esse objeto para especificar um contexto para a operação de troca de campos.  
  
### <a name="remarks"></a>Comentários  
 Ele também associa os membros de dados de parâmetro, se houver, aos espaços reservados de parâmetros na cadeia de instrução SQL para a seleção do conjunto de registros. A troca de dados de campo, chamados de troca de campos de registro DAO (DFX) funciona em ambas as direções: de membros de dados de campo do objeto de conjunto de registros para os campos do registro na fonte de dados e de registro na fonte de dados para o objeto de conjunto de registros. Se você estiver associando colunas dinamicamente, não são necessários para implementar `DoFieldExchange`.  
  
 A única ação que você normalmente deve adotar para implementar `DoFieldExchange` para o conjunto de registros derivado classe é criar a classe com ClassWizard e especifique os nomes e tipos de dados dos membros de dados do campo. Você também pode adicionar código para o que grava ClassWizard para especificar membros de dados do parâmetro. Se todos os campos devem ser vinculados dinamicamente, essa função será inativa, a menos que você especifique os membros de dados de parâmetro.  
  
 Quando você declara a classe derivada do conjunto de registros com ClassWizard, o assistente grava uma substituição de `DoFieldExchange` , que se parece com o exemplo a seguir:  
  
 [!code-cpp[NVC_MFCDatabase#2](../../mfc/codesnippet/cpp/cdaorecordset-class_2.cpp)]  
  
##  <a name="edit"></a>  CDaoRecordset::Edit  
 Chame essa função de membro para permitir que as alterações no registro atual.  
  
```  
virtual void Edit();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de você chamar o **editar** função de membro, as alterações feitas nos campos do registro atual são copiados para o buffer de cópia. Depois de fazer as alterações desejadas para o registro, chame **atualização** para salvar suas alterações. **Editar** salva os valores do conjunto de registros membros de dados. Se você chamar **editar**, fazer alterações, em seguida, chame **editar** novamente, os valores do registro são restaurados para o que eram antes da primeira **editar** chamar.  
  
> [!CAUTION]
>  Se você editar um registro e, em seguida, executar qualquer operação que é movido para outro registro sem primeiro chamar **atualização**, suas alterações serão perdidas sem aviso. Além disso, se você fechar o conjunto de registros ou banco de dados pai, seu registro editado será descartado sem aviso.  
  
 Em alguns casos, convém atualizar uma coluna, tornando Null (não contendo a nenhum dado). Para fazer isso, chame `SetFieldNull` com um parâmetro de **TRUE** para marcar o campo nulo; isso também faz com que a coluna a ser atualizada. Se você deseja um campo a ser gravado para a fonte de dados, mesmo que seu valor não foi alterado, chame `SetFieldDirty` com um parâmetro de **TRUE**. Isso funciona mesmo se o campo tiver o valor Null.  
  
 As marcas de framework alterado membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, para que você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas independentemente qual é o valor é no membro de dados do campo. O mecanismo DFX emprega o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como sujos. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática campo.  
  
 Quando o objeto de conjunto de registros pessimistically está bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado da hora **editar** é usado até que a atualização for concluída. Se o conjunto de registros de modo otimista é bloqueado, o registro está bloqueado e comparado com o registro anterior à edição antes que ele seja atualizado no banco de dados. Se o registro foi alterado desde que você chamou **editar**, o **atualização** operação falha e MFC lança uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.  
  
> [!NOTE]
>  Bloqueio otimista é sempre usado em formatos de banco de dados externo, como ODBC e ISAM instalável.  
  
 O registro atual permanece atual depois de chamar **editar**. Para chamar **editar**, deve haver um registro atual. Se não houver nenhum registro atual ou se o conjunto de registros não faz referência a um tipo de tabela aberto ou objeto de conjunto de registros do tipo dynaset, ocorrerá uma exceção. Chamando **editar** faz com que um `CDaoException` a ser lançado sob as seguintes condições:  
  
-   Não há nenhum registro atual.  
  
-   O banco de dados ou conjunto de registros é somente leitura.  
  
-   Não há campos do registro são atualizáveis.  
  
-   O banco de dados ou conjunto de registros foi aberto para uso exclusivo por outro usuário.  
  
-   Outro usuário bloqueou a página que contém o registro.  
  
 Se a fonte de dados oferece suporte a transações, você pode fazer o **editar** chamar parte de uma transação. Observe que você deve chamar `CDaoWorkspace::BeginTrans` antes de chamar **editar** e depois que o conjunto de registros foi aberto. Observe também que a chamada `CDaoWorkspace::CommitTrans` não é um substituto para chamar **atualização** para concluir o **editar** operação. Para obter mais informações sobre transações, consulte a classe `CDaoWorkspace`.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="fillcache"></a>  CDaoRecordset::FillCache  
 Chame essa função de membro para armazenar em cache um número especificado de registros do conjunto de registros.  
  
```  
void FillCache(
    long* pSize = NULL,  
    COleVariant* pBookmark = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSize`  
 Especifica o número de linhas para preencher o cache. Se você omitir esse parâmetro, o valor é determinado pela configuração da propriedade CacheSize do objeto DAO subjacente.  
  
 `pBookmark`  
 Um [COleVariant](../../mfc/reference/colevariant-class.md) especificando um indicador. O cache será preenchido a partir do registro indicado por esse indicador. Se você omitir esse parâmetro, o cache será preenchido a partir do registro indicado pela propriedade CacheStart do objeto DAO subjacente.  
  
### <a name="remarks"></a>Comentários  
 O cache melhora o desempenho de um aplicativo que recupera ou busca, dados de um servidor remoto. Um cache é um espaço na memória local que mantém os dados buscados mais recentemente do servidor na suposição de que os dados provavelmente seja solicitados novamente enquanto o aplicativo está em execução. Quando dados são solicitados, o mecanismo de banco de dados do Microsoft Jet primeiro verifica o cache para os dados em vez de buscá-lo do servidor, o que leva mais tempo. Usar dados em cache em fontes de dados ODBC não tem nenhum efeito como os dados não são salvos no cache.  
  
 Em vez de esperar o cache a ser preenchida com registros conforme elas são encontradas, você pode preencher o cache explicitamente a qualquer momento chamando o `FillCache` função de membro. Essa é uma maneira mais rápida para preencher o cache porque `FillCache` busca vários registros de uma só vez, em vez de um de cada vez. Por exemplo, enquanto uma tela cheia de registros está sendo exibida, você pode ter sua chamada de aplicativo `FillCache` para buscar a próxima tela cheia de registros.  
  
 Qualquer banco de dados ODBC acessado com objetos de conjunto de registros pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remoto e, em seguida, chame o `SetCacheSize` e `SetCacheStart` funções de membro do conjunto de registros. Se `lSize` e *lBookmark* criar um intervalo que é parcialmente ou totalmente fora do intervalo especificado por `SetCacheSize` e `SetCacheStart`, a parte do conjunto de registros fora desse intervalo é ignorada e não está carregada no cache. Se `FillCache` solicita mais registros que permanecem na fonte de dados remoto, somente os registros restantes são buscados e nenhuma exceção é lançada.  
  
 Registros obtidos do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.  
  
 `FillCache` busca somente os registros que não esteja armazenado em cache. Para forçar uma atualização de todos os dados armazenados em cache, chame o `SetCacheSize` função membro com um `lSize` parâmetro igual a 0, chamada `SetCacheSize` novamente com o `lSize` parâmetro igual ao tamanho do cache você originalmente solicitada e, em seguida, chamar `FillCache`.  
  
 Para obter informações relacionadas, consulte o tópico "FillCache Method" na Ajuda do DAO.  
  
##  <a name="find"></a>  CDaoRecordset::Find  
 Chame essa função de membro para localizar uma cadeia de caracteres específica em um conjunto de registros do tipo dynaset ou snapshot usando um operador de comparação.  
  
```  
virtual BOOL Find(
    long lFindType,  
    LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lFindType*  
 Um valor que indica o tipo de operação de localização desejado. Os valores possíveis são:  
  
- **AFX_DAO_NEXT** Localizar próximo local de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_PREV** encontrar o local anterior de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_FIRST** localizar o primeiro local de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_LAST** encontrar o último local de uma cadeia de caracteres correspondente.  
  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro. Por exemplo:  
  
 [!code-cpp[NVC_MFCDatabase#3](../../mfc/codesnippet/cpp/cdaorecordset-class_3.cpp)]  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode encontrar o primeiro, próximo, anterior, ou a última ocorrência da cadeia de caracteres. **Localizar** é uma função virtual, para que você pode substituí-la e adicionar sua própria implementação. O `FindFirst`, `FindLast`, `FindNext`, e `FindPrev` chamada de funções de membro de **localizar** função de membro, para que você possa usar **localizar** para controlar o comportamento de todas as operações de localização .  
  
 Para localizar um registro em um conjunto de registros do tipo de tabela, chame o [busca](#seek) função de membro.  
  
> [!TIP]
>  Quanto menor o conjunto de registros tiver, mais eficaz **localizar** será. Em geral e especialmente com dados ODBC, é melhor criar uma nova consulta que recupera apenas os registros que você deseja.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="findfirst"></a>  CDaoRecordset::FindFirst  
 Chame essa função de membro para localizar o primeiro registro que corresponde a uma condição especificada.  
  
```  
BOOL FindFirst(LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `FindFirst` função membro começa a pesquisa do início do conjunto de registros e pesquisas no final do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro correspondente aos critérios não for localizado, o ponteiro do registro atual é determinado, e `FindFirst` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaz os critérios de `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função membro antes de passar para outro registro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.  
  
 O **localizar** funções de membro Pesquisar do local e na direção especificada na tabela a seguir:  
  
|As operações de localização|Começar|Direção de pesquisa|  
|---------------------|-----------|----------------------|  
|`FindFirst`|Início do conjunto de registros|Fim do conjunto de registros|  
|`FindLast`|Fim do conjunto de registros|Início do conjunto de registros|  
|`FindNext`|Registro atual|Fim do conjunto de registros|  
|**FindPrevious**|Registro atual|Início do conjunto de registros|  
  
> [!NOTE]
>  Quando você chama `FindLast`, o mecanismo de banco de dados Microsoft Jet popula completamente o conjunto de registros antes de iniciar a pesquisa, se isso já não foi feito. A primeira pesquisa pode demorar mais pesquisas subsequentes.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha em mente o seguinte ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização está lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho por meio de consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetros, ou **CDaoQuerydef** objetos recuperar específico registros indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="findlast"></a>  CDaoRecordset::FindLast  
 Chame essa função de membro para encontrar o último registro que corresponde a uma condição especificada.  
  
```  
BOOL FindLast(LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `FindLast` função membro começa a pesquisa no final do conjunto de registros e pesquisas com versões anteriores em direção ao início do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro correspondente aos critérios não for localizado, o ponteiro do registro atual é determinado, e `FindLast` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaz os critérios de `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência após a primeira ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função membro antes de passar para outro registro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha em mente o seguinte ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização está lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho por meio de consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetros, ou **CDaoQuerydef** objetos recuperar específico registros indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="findnext"></a>  CDaoRecordset::FindNext  
 Chame essa função de membro para localizar o próximo registro que corresponde a uma condição especificada.  
  
```  
BOOL FindNext(LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `FindNext` procura até o final do conjunto de registros e começa a pesquisa no registro atual de função de membro.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro correspondente aos critérios não for localizado, o ponteiro do registro atual é determinado, e `FindNext` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaz os critérios de `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função membro antes de passar para outro registro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha em mente o seguinte ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização está lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho por meio de consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetros, ou **CDaoQuerydef** objetos recuperar específico registros indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="findprev"></a>  CDaoRecordset::FindPrev  
 Chame essa função de membro para localizar o registro anterior que corresponde a uma condição especificada.  
  
```  
BOOL FindPrev(LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `FindPrev` função membro começa a pesquisa no registro atual e pesquisa para trás em direção ao início do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro correspondente aos critérios não for localizado, o ponteiro do registro atual é determinado, e `FindPrev` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaz os critérios de `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função membro antes de passar para outro registro. Se você mover para outro registro sem atualizar, suas alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, no entanto, que simplesmente torna o primeiro ou o próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha em mente o seguinte ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando você procura campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; Caso contrário, registros correspondentes não podem ser encontrados.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grandes, você pode descobrir que usar as operações de localização está lento, especialmente ao trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho por meio de consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetros, ou **CDaoQuerydef** objetos recuperar específico registros indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="getabsoluteposition"></a>  CDaoRecordset::GetAbsolutePosition  
 Retorna o número do registro de um objeto conjunto de registros atual.  
  
```  
long GetAbsolutePosition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro de 0 ao número de registros no conjunto de registros. Corresponde à posição ordinal do registro atual no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Você pode determinar o número de registros preenchidos no conjunto de registros chamando [GetRecordCount](#getrecordcount). Chamando `GetRecordCount` pode levar algum tempo, pois ele precisar acessar todos os registros para determinar a contagem.  
  
 Se não há nenhum registro atual, como quando não há nenhum registro no conjunto de registros, - 1 será retornado. Se o registro atual é excluído, o valor da propriedade AbsolutePosition não está definido e MFC lança uma exceção se ele é referenciado. Conjuntos de registros do tipo dynaset, novos registros são adicionados ao final da sequência.  
  
> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro de substitutos. Indicadores ainda são a maneira recomendada de reter e retornar para a posição especificada e a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros. Em particular, a posição de um determinado registro muda quando o registro (s) anterior é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado novamente porque a ordem de registros individuais dentro de um conjunto de registros não é garantida, a menos que ela é criada com uma instrução SQL usando um  **ORDERBY** cláusula.  
  
> [!NOTE]
>  Essa função de membro é válida somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.  
  
##  <a name="getbookmark"></a>  CDaoRecordset::GetBookmark  
 Chame essa função de membro para obter o valor do indicador em um determinado registro.  
  
```  
COleVariant GetBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que representa o indicador no registro atual.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já possui um indicador exclusivo se ele oferece suporte a eles. Chamar `CanBookmark` para determinar se um conjunto de registros suporta indicadores.  
  
 Você pode salvar o indicador para o registro atual atribuindo o valor do indicador para um `COleVariant` objeto. Para retornar rapidamente a esse registro a qualquer momento depois de mover para um registro diferente, chame `SetBookmark` com um parâmetro que corresponde ao valor do `COleVariant` objeto.  
  
> [!NOTE]
>  Chamando [Requery](#requery) indicadores DAO é alterado.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Bookmark" na Ajuda do DAO.  
  
##  <a name="getcachesize"></a>  CDaoRecordset::GetCacheSize  
 Chame essa função de membro para obter o número de registros armazenado em cache.  
  
```  
long GetCacheSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém dados a ser armazenada em cache localmente de uma fonte de dados ODBC.  
  
### <a name="remarks"></a>Comentários  
 Cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Um cache é um espaço na memória local que mantém os dados recuperados mais recentemente do servidor que os dados serem solicitados novamente enquanto o aplicativo está em execução. Quando dados são solicitados, o mecanismo de banco de dados do Microsoft Jet primeiro verifica o cache para os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.  
  
 Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local.  
  
 Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.  
  
##  <a name="getcachestart"></a>  CDaoRecordset::GetCacheStart  
 Chame essa função de membro para obter o valor do indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
```  
COleVariant GetCacheStart();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COleVariant` que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
### <a name="remarks"></a>Comentários  
 O mecanismo de banco de dados Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.  
  
> [!NOTE]
>  Registros recuperados do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.  
  
 Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.  
  
##  <a name="getcurrentindex"></a>  CDaoRecordset::GetCurrentIndex  
 Chamar essa função de membro para determinar o índice atualmente em uso em um tipo de tabela indexado `CDaoRecordset` objeto.  
  
```  
CString GetCurrentIndex();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o nome do índice atualmente em uso com um conjunto de registros do tipo de tabela. Retorna uma cadeia de caracteres vazia se nenhum índice foi definido.  
  
### <a name="remarks"></a>Comentários  
 Esse índice é a base para ordenar registros em um conjunto de registros do tipo de tabela e é usado pelo [busca](#seek) função de membro para localizar registros.  
  
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
 Chame essa função de membro para recuperar a data e hora que da última atualização do esquema.  
  
```  
COleDateTime GetDateLastUpdated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora da última atualização a estrutura da tabela base (esquema).  
  
### <a name="remarks"></a>Comentários  
 Configurações de data e hora são derivadas do computador no qual a estrutura da tabela base (esquema) foi atualizada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="getdefaultdbname"></a>  CDaoRecordset::GetDefaultDBName  
 Chame essa função de membro para determinar o nome do banco de dados para este conjunto de registros.  
  
```  
virtual CString GetDefaultDBName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o caminho e o nome do banco de dados da qual deriva este conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Se um conjunto de registros é criado sem um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md), em seguida, esse caminho é usado pelo conjunto de registros para abrir o banco de dados padrão. Por padrão, essa função retorna uma cadeia de caracteres vazia. Quando ClassWizard deriva um novo conjunto de registros de `CDaoRecordset`, ele cria essa função para você.  
  
 O exemplo a seguir ilustra o uso das duas barras invertidas (\\\\) na cadeia de caracteres, como é necessário para a cadeia de caracteres para serem interpretados corretamente.  
  
 [!code-cpp[NVC_MFCDatabase#4](../../mfc/codesnippet/cpp/cdaorecordset-class_4.cpp)]  
  
##  <a name="getdefaultsql"></a>  CDaoRecordset::GetDefaultSQL  
 O framework chama esta função de membro para obter a instrução SQL padrão na qual o conjunto de registros é baseado.  
  
```  
virtual CString GetDefaultSQL();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém a instrução SQL padrão.  
  
### <a name="remarks"></a>Comentários  
 Isso pode ser um nome de tabela ou um SQL **selecione** instrução.  
  
 Definir, indiretamente, a instrução SQL padrão declarando a classe de conjunto de registros com ClassWizard e ClassWizard executa essa tarefa para você.  
  
 Se você passar uma cadeia de caracteres nula do SQL para [abrir](#open), em seguida, essa função é chamada para determinar o nome da tabela ou o SQL para o conjunto de registros.  
  
##  <a name="geteditmode"></a>  CDaoRecordset::GetEditMode  
 Chame essa função de membro para determinar o estado de edição, o que é um dos seguintes valores:  
  
```  
short GetEditMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que indica o estado de edição para o registro atual.  
  
### <a name="remarks"></a>Comentários  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**dbEditNone**|Nenhuma operação de edição está em andamento.|  
|**dbEditInProgress**|**Editar** foi chamado.|  
|**dbEditAdd**|O `AddNew` foi chamado.|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="getfieldcount"></a>  CDaoRecordset::GetFieldCount  
 Chame essa função de membro para recuperar o número de campos (colunas) definidos no conjunto de registros.  
  
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
 `nIndex`  
 O índice de base zero do campo predefinido na coleção de campos do conjunto de registros, pesquisa por índice.  
  
 `fieldinfo`  
 Uma referência a um [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o conjunto de registros a serem recuperados. As opções disponíveis são listadas aqui, junto com o que eles fazer com que a função retornar. Para melhor desempenho, recupere apenas o nível de informações que você precisa:  
  
- `AFX_DAO_PRIMARY_INFO` (Padrão) Nome, tipo, tamanho, atributos  
  
- `AFX_DAO_SECONDARY_INFO` As informações primárias, além de: permitir a posição Ordinal, obrigatório, Zero tabela de origem externa nome, o campo de origem, comprimento, a ordem de agrupamento,  
  
- `AFX_DAO_ALL_INFO` Informações principais e secundárias, além de: valor padrão, a regra de validação, texto de validação  
  
 `lpszName`  
 O nome do campo.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um campo por índice. A outra versão permite pesquisar um campo por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição do `dwInfoOptions`. Quando você solicita informações em um nível, você obtém informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
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
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.  
  
 `varValue`  
 Uma referência a um `COleVariant` objeto que armazena o valor de um campo.  
  
 `nIndex`  
 Um índice com base em zero do campo na coleção de campos do conjunto de registros, pesquisa por índice.  
  
### <a name="return-value"></a>Valor de retorno  
 As duas versões do `GetFieldValue` que retornam um valor de retorno um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor de um campo.  
  
### <a name="remarks"></a>Comentários  
 Você pode procurar um campo por nome ou pela posição ordinal.  
  
> [!NOTE]
>  É mais eficiente para chamada de uma das versões desta função de membro que usa um `COleVariant` referência de objeto como um parâmetro, em vez de chamar uma versão que retorna um `COleVariant` objeto. As versões mais recentes dessa função são mantidas para compatibilidade com versões anteriores.  
  
 Use `GetFieldValue` e [SetFieldValue](#setfieldvalue) vincular dinamicamente os campos no tempo de execução em vez de estaticamente colunas de associação usando o [DoFieldExchange](#dofieldexchange) mecanismo.  
  
 `GetFieldValue` e o `DoFieldExchange` mecanismo pode ser combinado para melhorar o desempenho. Por exemplo, use `GetFieldValue` para recuperar um valor que você precisa apenas sob demanda e atribuir essa chamada a um botão "Mais informações" na interface.  
  
 Para obter informações relacionadas, consulte os tópicos "Objeto Field" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="getindexcount"></a>  CDaoRecordset::GetIndexCount  
 Chame essa função de membro para determinar o número de índices disponíveis no conjunto de registros do tipo de tabela.  
  
```  
short GetIndexCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de índices no conjunto de registros do tipo de tabela.  
  
### <a name="remarks"></a>Comentários  
 `GetIndexCount` é útil para efetuar loop através de todos os índices no conjunto de registros. Para essa finalidade, use `GetIndexCount` em conjunto com [GetIndexInfo](#getindexinfo). Se você chamar esta função de membro no tipo dynaset ou conjuntos de registros do tipo de instantâneo, MFC gera uma exceção.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
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
 `nIndex`  
 O índice baseado em zero na coleção de índices da tabela, pesquisa por posição numérica.  
  
 `indexinfo`  
 Uma referência a um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis são listadas aqui, junto com o que eles fazer com que a função retornar. Para melhor desempenho, recupere apenas o nível de informações que você precisa:  
  
- `AFX_DAO_PRIMARY_INFO` (Padrão) Campos de nome, informações de campo  
  
- `AFX_DAO_SECONDARY_INFO` As informações primárias, mais: primário, Unique, Clustered, ignorar, obrigatório, externo  
  
- `AFX_DAO_ALL_INFO` Informações principais e secundárias, além de: contagem distinta  
  
 `lpszName`  
 Um ponteiro para o nome do objeto index, pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas acima na descrição do `dwInfoOptions`. Quando você solicita informações em um nível, você obtém informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
##  <a name="getlastmodifiedbookmark"></a>  CDaoRecordset::GetLastModifiedBookmark  
 Chame essa função de membro para recuperar o indicador do registro mais recentemente adicionado ou atualizado.  
  
```  
COleVariant GetLastModifiedBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COleVariant` contendo um indicador que indica mais recentemente adicionado ou alterado de registro.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já possui um indicador exclusivo se ele oferece suporte a eles. Chamar [GetBookmark](#getbookmark) para determinar se o conjunto de registros suporta indicadores. Se o conjunto de registros não oferece suporte a indicadores, um `CDaoException` é gerada.  
  
 Quando você adiciona um registro, ele aparece no fim do conjunto de registros e não é o registro atual. Para tornar o novo registro atual, chame `GetLastModifiedBookmark` e, em seguida, chame `SetBookmark` para retornar para o registro recém-adicionada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade LastModified" na Ajuda do DAO.  
  
##  <a name="getlockingmode"></a>  CDaoRecordset::GetLockingMode  
 Chame essa função de membro para determinar o tipo de bloqueio em vigor para o conjunto de registros.  
  
```  
BOOL GetLockingMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o tipo de bloqueio pessimista, caso contrário, 0 para bloqueio de registro otimista.  
  
### <a name="remarks"></a>Comentários  
 Quando o bloqueio pessimista está em vigor, a página de dados que contém o registro que você está editando é bloqueado assim que você chamar o [editar](#edit) função de membro. A página está desbloqueada quando você chamar o [atualização](#update) ou [fechar](#close) função de membro ou qualquer uma das operações de mover ou localizar.  
  
 Quando otimista proteção está em vigor, a página de dados que contém o registro é bloqueada somente enquanto o registro está sendo atualizado com o **atualização** função de membro.  
  
 Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedade LockEdits" e "Bloqueio comportamento multiusuário aplicativos" na Ajuda do DAO.  
  
##  <a name="getname"></a>  CDaoRecordset::GetName  
 Chame essa função de membro para recuperar o nome do conjunto de registros.  
  
```  
CString GetName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o nome do conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 O nome do conjunto de registros deve começar com uma letra e pode conter um máximo de 40 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir espaços ou pontuação.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
##  <a name="getparamvalue"></a>  CDaoRecordset::GetParamValue  
 Chame essa função de membro para recuperar o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.  
  
```  
virtual COleVariant GetParamValue(int nIndex);  
virtual COleVariant GetParamValue(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 A posição numérica do parâmetro no objeto DAOParameter subjacente.  
  
 `lpszName`  
 O nome do parâmetro cujo valor você deseja.  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto da classe [COleVariant](../../mfc/reference/colevariant-class.md) que contém o valor do parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Você pode acessar o parâmetro por nome ou por sua posição numérica na coleção.  
  
 Para obter informações relacionadas, consulte o tópico "Objeto de parâmetro" na Ajuda do DAO.  
  
##  <a name="getpercentposition"></a>  CDaoRecordset::GetPercentPosition  
 Ao trabalhar com um tipo dynaset ou conjunto de registros do tipo de instantâneo, se você chamar `GetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimentação é em relação ao número de registros acessado conforme indicado chamando [GetRecordCount](#getrecordcount).  
  
```  
float GetPercentPosition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um número entre 0 e 100 que indica a localização aproximada do registro atual no objeto de conjunto de registros com base em uma porcentagem dos registros no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Você pode mover para o último registro chamando [MoveLast](#movelast) para concluir a população de todos os conjuntos de registros, mas isso pode levar uma quantidade significativa de tempo.  
  
 Você pode chamar `GetPercentPosition` em todos os três tipos de objetos de conjunto de registros, inclusive tabelas sem índices. No entanto, você não pode chamar `GetPercentPosition` em instantâneos de rolagem de somente avanço, ou em um conjunto de registros aberto a partir de uma consulta de passagem em um banco de dados externo. Se não há nenhum registro atual ou o registro atual foi excluído, um `CDaoException` é gerada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.  
  
##  <a name="getrecordcount"></a>  CDaoRecordset::GetRecordCount  
 Chame essa função de membro para descobrir o número de registros em um conjunto de registros que tenha sido acessado.  
  
```  
long GetRecordCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de registros acessados em um objeto de conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 `GetRecordCount` não indica quantos registros estão contidos em um tipo dynaset ou conjunto de registros do tipo de instantâneo, até que todos os registros que tenham sido acessados. Essa chamada de função de membro pode levar uma quantidade significativa de tempo para concluir.  
  
 Depois que o último registro tiver sido acessado, o valor de retorno indica o número total de registros de mensagem no conjunto de registros. Para forçar o último registro para ser acessado, chame o `MoveLast` ou `FindLast` a função de membro do conjunto de registros. Você também pode usar uma contagem de SQL para determinar o número aproximado de registros de que sua consulta retornará.  
  
 Como seu aplicativo exclui registros em um conjunto de registros do tipo dynaset, o valor de retorno `GetRecordCount` diminui. No entanto, os registros excluídos por outros usuários não são refletidos pelo `GetRecordCount` até que o registro atual é posicionado em um registro excluído. Se você executar uma transação que afeta a contagem de registros e subsequentemente reverter a transação, `GetRecordCount` não refletirá o número real de registros restantes.  
  
 O valor de `GetRecordCount` de um conjunto de registros do tipo de instantâneo não é afetado por alterações nas tabelas base.  
  
 O valor de `GetRecordCount` de um tipo de tabela, o conjunto de registros reflete o número aproximado de registros na tabela e é afetado imediatamente conforme os registros da tabela são adicionados e excluídos.  
  
 Um conjunto de registros sem registros retorna um valor de 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retornará - 1. Chamando o **Requery** função de membro em um conjunto de registros redefine o valor de `GetRecordCount` como se a consulta foi executada novamente.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na Ajuda do DAO.  
  
##  <a name="getsql"></a>  CDaoRecordset::GetSQL  
 Chame essa função de membro para obter a instrução SQL que foi usada para selecionar registros do conjunto de registros quando ele foi aberto.  
  
```  
CString GetSQL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém a instrução SQL.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente será um SQL **selecione** instrução.  
  
 A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você pode ter passado para o conjunto de registros a `lpszSQL` parâmetro para o [abrir](#open) função de membro. Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no que é passado para **abrir**, o que você especificou com ClassWizard e o que você pode ter especificado no [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) membros de dados.  
  
> [!NOTE]
>  Chamar essa função de membro somente depois de chamar **abrir**.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade SQL" na Ajuda do DAO.  
  
##  <a name="gettype"></a>  CDaoRecordset::GetType  
 Chame essa função de membro depois de abrir o conjunto de registros para determinar o tipo do objeto de conjunto de registros.  
  
```  
short GetType();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores a seguir que indica o tipo de um conjunto de registros:  
  
- **dbOpenTable** conjunto de registros do tipo de tabela  
  
- **dbOpenDynaset** tipo Dynaset  
  
- **dbOpenSnapshot** conjunto de registros do tipo de instantâneo  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
##  <a name="getvalidationrule"></a>  CDaoRecordset::GetValidationRule  
 Chame essa função de membro para determinar a regra usada para validar dados.  
  
```  
CString GetValidationRule();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém um valor que valida os dados em um registro, como ele é alterado nem adicionado a uma tabela.  
  
### <a name="remarks"></a>Comentários  
 Essa regra é baseado em texto e é aplicada a cada vez que a tabela subjacente é alterada. Se os dados não são válidos, MFC gera uma exceção. A mensagem de erro retornado é o texto da propriedade de texto de validação do campo objeto subjacente, se especificado, ou o texto da expressão especificada pela propriedade de regra de validação do objeto subjacente do campo. Você pode chamar [GetValidationText](#getvalidationtext) para obter o texto da mensagem de erro.  
  
 Por exemplo, um campo em um registro que exige o dia do mês pode ter uma regra de validação, como "dia entre 1 e 31."  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade ValidationRule" na Ajuda do DAO.  
  
##  <a name="getvalidationtext"></a>  CDaoRecordset::GetValidationText  
 Chame essa função de membro para recuperar o texto da propriedade do objeto subjacente do campo de texto de validação.  
  
```  
CString GetValidationText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto da mensagem que será exibida se o valor de um campo não atendem à regra de validação do objeto subjacente do campo.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade de texto de validação" na Ajuda do DAO.  
  
##  <a name="isbof"></a>  CDaoRecordset::IsBOF  
 Chame essa função de membro antes de você rola do registro para o registro para saber se você tiver feito antes do primeiro registro do conjunto de registros.  
  
```  
BOOL IsBOF() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros não contiver registros ou se você tiver revertido antes do primeiro registro; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você também pode chamar `IsBOF` juntamente com `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar **abrir**, se o conjunto de registros não contém registros, `IsBOF` retorna zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retornará 0.  
  
 Se o primeiro registro é o registro atual e você chamar `MovePrev`, `IsBOF` subsequentemente retornará zero. Se `IsBOF` retorna zero e você chamar `MovePrev`, uma exceção será lançada. Se `IsBOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.  
  
 Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:  
  
-   Chamando **abrir** internamente torna o primeiro registro no conjunto de registros a atual chamando **MoveFirst**. Portanto, ao chamar **abrir** em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferente de zero. (Consulte a tabela a seguir para o comportamento de uma falha **MoveFirst** ou `MoveLast` chame.)  
  
-   Todas as operações de movimentação com êxito, localizar um registro de fazer com que `IsBOF` e `IsEOF` para retornar 0.  
  
-   Um `AddNew` chamada seguido por um **atualização** fará com que a chamada que insere com êxito um novo registro `IsBOF` para retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterada. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, é o ponteiro do registro atual de um conjunto de registros vazio ao final de um arquivo, para que qualquer novo registro é inserido após o registro atual.  
  
-   Qualquer **excluir** chamada, mesmo se ele remove o registro de restante somente de um conjunto de registros não alterará o valor de `IsBOF` ou `IsEOF`.  
  
 Esta tabela mostra as operações de movimentação permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.  
  
||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext,<br /><br /> Mover > 0|  
|------|-------------------------|-----------------------------|------------|-----------------------------|  
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|  
|`IsBOF`=0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|  
|Ambos diferente de zero|Exceção|Exceção|Exceção|Exceção|  
|0|Permitido|Permitido|Permitido|Permitido|  
  
 Permitindo que uma operação de movimentação não significa que a operação com êxito localizará um registro. Ele simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem ser alterado como resultado da tentativa de movimentação.  
  
 O efeito de operações de movimentação não localizar um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.  
  
||IsBOF|IsEOF|  
|------|-----------|-----------|  
|**MoveFirst**, `MoveLast`|Diferente de zero|Diferente de zero|  
|**Mover** 0|Nenhuma alteração|Nenhuma alteração|  
|`MovePrev`, **Mover** < 0|Diferente de zero|Nenhuma alteração|  
|`MoveNext`, **Mover** > 0|Nenhuma alteração|Diferente de zero|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades BOF e EOF" na Ajuda do DAO.  
  
##  <a name="isdeleted"></a>  CDaoRecordset::IsDeleted  
 Chame essa função de membro para determinar se o registro atual foi excluído.  
  
```  
BOOL IsDeleted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros é posicionado em um registro excluído. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você rolar para um registro e `IsDeleted` retorna **TRUE** (diferente de zero), em seguida, é necessário rolar para outro registro antes de executar outras operações de conjunto de registros.  
  
> [!NOTE]
>  Você não precisa verificar o status excluído por registros em um conjunto de registros do tipo de tabela ou de instantâneo. Porque os registros não podem ser excluídos de um instantâneo, não é necessário chamar `IsDeleted`. Para conjuntos de registros do tipo de tabela, os registros excluídos realmente são removidos do conjunto de registros. Depois que um registro foi excluído, por você, outro usuário, ou em outro conjunto de registros, não é possível rolar para esse registro. Portanto, não é necessário chamar `IsDeleted`.  
  
 Quando você exclui um registro de dynaset, ele é removido do conjunto de registros e você não é possível rolar para esse registro. No entanto, se um registro em um dynaset é excluído por outro usuário ou em outro conjunto de registros com base na mesma tabela, `IsDeleted` retornará **TRUE** quando você mais tarde rola para esse registro.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Delete", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="iseof"></a>  CDaoRecordset::IsEOF  
 Chame essa função de membro enquanto você rola do registro para o registro para saber se você tiver ido além do último registro do conjunto de registros.  
  
```  
BOOL IsEOF() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros não contém registros ou se você percorreu além do último registro; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você também pode chamar `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar **abrir**, se o conjunto de registros não contém registros, `IsEOF` retorna zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retornará 0.  
  
 Se o último registro é o registro atual quando você chama `MoveNext`, `IsEOF` subsequentemente retornará zero. Se `IsEOF` retorna zero e você chamar `MoveNext`, uma exceção será lançada. Se `IsEOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.  
  
 Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:  
  
-   Chamando **abrir** internamente torna o primeiro registro no conjunto de registros a atual chamando **MoveFirst**. Portanto, ao chamar **abrir** em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferente de zero. (Consulte a tabela a seguir para o comportamento de uma falha **MoveFirst** chame.)  
  
-   Todas as operações de movimentação com êxito, localizar um registro de fazer com que `IsBOF` e `IsEOF` para retornar 0.  
  
-   Um `AddNew` chamada seguido por um **atualização** fará com que a chamada que insere com êxito um novo registro `IsBOF` para retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterada. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, é o ponteiro do registro atual de um conjunto de registros vazio ao final de um arquivo, para que qualquer novo registro é inserido após o registro atual.  
  
-   Qualquer **excluir** chamada, mesmo se ele remove o registro de restante somente de um conjunto de registros não alterará o valor de `IsBOF` ou `IsEOF`.  
  
 Esta tabela mostra as operações de movimentação permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.  
  
||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover < 0|Mover 0|MoveNext,<br /><br /> Mover > 0|  
|------|-------------------------|-----------------------------|------------|-----------------------------|  
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|  
|`IsBOF`=0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|  
|Ambos diferente de zero|Exceção|Exceção|Exceção|Exceção|  
|0|Permitido|Permitido|Permitido|Permitido|  
  
 Permitindo que uma operação de movimentação não significa que a operação com êxito localizará um registro. Ele simplesmente indica que uma tentativa de executar a operação de movimentação especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem ser alterado como resultado da tentativa de movimentação.  
  
 O efeito de operações de movimentação não localizar um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.  
  
||IsBOF|IsEOF|  
|------|-----------|-----------|  
|**MoveFirst**, `MoveLast`|Diferente de zero|Diferente de zero|  
|**Mover** 0|Nenhuma alteração|Nenhuma alteração|  
|`MovePrev`, **Mover** < 0|Diferente de zero|Nenhuma alteração|  
|`MoveNext`, **Mover** > 0|Nenhuma alteração|Diferente de zero|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades BOF e EOF" na Ajuda do DAO.  
  
##  <a name="isfielddirty"></a>  CDaoRecordset::IsFieldDirty  
 Chame essa função de membro determinar se o membro de dados do campo especificado de dynaset foi sinalizado como "sujos" (alterado).  
  
```  
BOOL IsFieldDirty(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos estão sujos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado está marcado como sujo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os dados em todos os membros de dados sujas do campo serão transferidos para o registro na fonte de dados quando o registro atual é atualizado por uma chamada para o **atualização** função membro de `CDaoRecordset` (após uma chamada para **editar**ou `AddNew`). Com esse conhecimento, você pode tomar mais medidas, como unflagging o membro de dados de campo para marcar a coluna para que ele não será gravado para a fonte de dados.  
  
 `IsFieldDirty` é implementado por meio de `DoFieldExchange`.  
  
##  <a name="isfieldnull"></a>  CDaoRecordset::IsFieldNull  
 Chame essa função de membro para determinar se o membro de um conjunto de registros de dados de campo especificado foi sinalizado como Null.  
  
```  
BOOL IsFieldNull(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos são Null.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado é sinalizado como nulo. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é o mesmo que **nulo** em C++.) Se um membro de dados do campo é sinalizado como Null, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.  
  
> [!NOTE]
>  Em determinadas situações, usando `IsFieldNull` pode ser ineficiente, como mostra o exemplo de código a seguir:  
  
 [!code-cpp[NVC_MFCDatabase#5](../../mfc/codesnippet/cpp/cdaorecordset-class_5.cpp)]  
  
> [!NOTE]
>  Se você estiver usando a associação dinâmica de registro, sem derivando de `CDaoRecordset`, certifique-se de usar **VT_NULL** conforme mostrado no exemplo.  
  
##  <a name="isfieldnullable"></a>  CDaoRecordset::IsFieldNullable  
 Chamar essa função de membro determinar se o membro de dados do campo especificado é "nulo" (pode ser definido como um valor Null; C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa que "não ter nenhum valor").  
  
```  
BOOL IsFieldNullable(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos são Null.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado pode ser feito como nulo. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um campo que não pode ser Null deve ter um valor. Se você tentar definir esse campo como Null ao adicionar ou atualizar um registro, a fonte de dados rejeitará a adição ou a atualização, e **atualizar** lançará uma exceção. A exceção ocorre quando você chamar **atualização**, não quando você chamar `SetFieldNull`.  
  
##  <a name="isopen"></a>  CDaoRecordset::IsOpen  
 Chame essa função de membro para determinar se o conjunto de registros é aberto.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto de conjunto de registros **abrir** ou **Requery** função membro anteriormente foi chamada e o conjunto de registros não foi fechado; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bcheckcachefordirtyfields"></a>  CDaoRecordset::m_bCheckCacheForDirtyFields  
 Contém um sinalizador que indica se campos em cache são automaticamente marcados como sujos (alterados) e Null.  
  
### <a name="remarks"></a>Comentários  
 O sinalizador assume como padrão **TRUE**. A configuração nesse membro de dados controla o mecanismo de armazenamento em buffer duplo inteiro. Se você definir o sinalizador como **TRUE**, você pode desativar o armazenamento em cache em uma base por um campo usando o mecanismo DFX. Se você definir o sinalizador como **FALSE**, você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
 Definir este membro de dados antes de chamar **abrir**. Esse mecanismo é principalmente para facilidade de uso. Desempenho pode ser mais lento devido o buffer duplo de campos como as alterações são feitas.  
  
##  <a name="m_nfields"></a>  CDaoRecordset::m_nFields  
 Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas, o conjunto de registros da fonte de dados.  
  
### <a name="remarks"></a>Comentários  
 O construtor para a classe de conjunto de registros deve inicializar `m_nFields` com o número correto de campos associados estaticamente. ClassWizard grava essa inicialização para você quando você usá-lo para declarar a classe de conjunto de registros. Você também pode escrevê-lo manualmente.  
  
 A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.  
  
> [!NOTE]
>  Esse número deve corresponder ao número de colunas de saída registrado no `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro **CDaoFieldExchange::outputColumn**.  
  
 Você pode associar colunas dinamicamente por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue`. Se você fizer isso, você não precisa incrementa a contagem em `m_nFields` para refletir o número de função DFX chamadas seu `DoFieldExchange` função de membro.  
  
##  <a name="m_nparams"></a>  CDaoRecordset::m_nParams  
 Contém o número de membros de dados de parâmetro na classe de conjunto de registros, o número de parâmetros passados com a consulta do conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Se sua classe de conjunto de registros tem quaisquer membros de dados de parâmetro, o construtor da classe deve inicializar `m_nParams` com o número correto. O valor de `m_nParams` padrão é 0. Se você adicionar membros de dados do parâmetro — que deve ser feito manualmente, você também deverá adicionar manualmente uma inicialização do construtor de classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de ' espaços reservados na sua **m_strFilter**  ou `m_strSort` cadeia de caracteres).  
  
 A estrutura usa esse número quando ela parametriza a consulta do conjunto de registros.  
  
> [!NOTE]
>  Esse número deve corresponder ao número de "parâmetros" registrados em `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro **CFieldExchange::param**.  
  
 Para obter informações relacionadas, consulte o tópico "Objeto de parâmetro" na Ajuda do DAO.  
  
##  <a name="m_pdaorecordset"></a>  CDaoRecordset::m_pDAORecordset  
 Contém um ponteiro para a interface OLE para o objeto de conjunto de registros DAO base o `CDaoRecordset` objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esse ponteiro se você precisar acessar a interface DAO diretamente.  
  
 Para obter informações relacionadas, consulte o tópico "Objeto Recordset" na Ajuda do DAO.  
  
##  <a name="m_pdatabase"></a>  CDaoRecordset::m_pDatabase  
 Contém um ponteiro para o `CDaoDatabase` objeto por meio do qual o conjunto de registros é conectado a uma fonte de dados.  
  
### <a name="remarks"></a>Comentários  
 Essa variável é definida de duas maneiras. Normalmente, você transmitir um ponteiro para um já aberto `CDaoDatabase` quando você construir o objeto de conjunto de registros do objeto. Se você passar **nulo** em vez disso, **CDaoRecordset** cria um `CDaoDatabase` objeto para você e abri-lo. Em ambos os casos, `CDaoRecordset` armazena o ponteiro nessa variável.  
  
 Normalmente você não diretamente precisará usar o ponteiro armazenado em **m_pDatabase**. Se você escrever suas próprias extensões para `CDaoRecordset`, no entanto, você talvez precise usar o ponteiro. Por exemplo, talvez seja necessário o ponteiro se você gerar sua própria `CDaoException`(s).  
  
 Para obter informações relacionadas, consulte o tópico "Objeto de banco de dados" na Ajuda do DAO.  
  
##  <a name="m_strfilter"></a>  CDaoRecordset::m_strFilter  
 Contém uma cadeia de caracteres que é usada para construir o **onde** cláusula de uma instrução SQL.  
  
### <a name="remarks"></a>Comentários  
 Ele não inclui a palavra reservada **onde** para filtrar o conjunto de registros. O uso desse membro de dados não é aplicável ao conjunto de registros do tipo de tabela. O uso de **m_strFilter** não tem efeito quando abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.  
  
 Use o formato de data dos EUA (mês-dia-ano) quando você filtrar os campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados do Microsoft Jet; Caso contrário, os dados não podem ser filtrados conforme o esperado.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de filtro" na Ajuda do DAO.  
  
##  <a name="m_strsort"></a>  CDaoRecordset::m_strSort  
 Contém uma cadeia de caracteres que contém o **ORDERBY** cláusula de uma instrução SQL sem as palavras reservadas **ORDERBY**.  
  
### <a name="remarks"></a>Comentários  
 Você pode classificar em objetos de conjunto de registros do tipo dynaset e snapshot.  
  
 Não é possível classificar os objetos de conjunto de registros do tipo de tabela. Para determinar a ordem de classificação de um conjunto de registros do tipo de tabela, chame [SetCurrentIndex](#setcurrentindex).  
  
 O uso de `m_strSort` não tem efeito quando abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de classificação" na Ajuda do DAO.  
  
##  <a name="move"></a>  CDaoRecordset::Move  
 Chamar essa função de membro para posicionar o conjunto de registros `lRows` registros do registro atual.  
  
```  
virtual void Move(long lRows);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lRows`  
 O número de registros para Avançar ou recuar. Valores positivos Avançar, até o final do conjunto de registros. Valores negativos para trás, movem para o início.  
  
### <a name="remarks"></a>Comentários  
 Você pode mover para frente ou para trás. `Move( 1 )` é equivalente a `MoveNext`, e `Move( -1 )` é equivalente a `MovePrev`.  
  
> [!CAUTION]
>  Chamar qualquer o **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chamar `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você percorreu após o início ou fim do conjunto de registros ( `IsBOF` ou `IsEOF` retorna zero), uma chamada para **mover** lança um `CDaoException`.  
  
> [!NOTE]
>  Se você chamar qualquer uma da **mover** funções enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Quando você chama **mover** em um instantâneo de rolagem somente de encaminhamento, o `lRows` parâmetro deve ser um inteiro positivo e não são permitidos indicadores, para que você possa mover forward somente.  
  
 Para fazer a primeira, última, anterior ou seguinte gravar em um conjunto de registros chamada de registro, o **MoveFirst**, `MoveLast`, `MoveNext`, ou `MovePrev` função de membro.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="movefirst"></a>  CDaoRecordset::MoveFirst  
 Chamar essa função de membro para tornar o primeiro registro no conjunto de registros (se houver) do registro atual.  
  
```  
void MoveFirst();
```  
  
### <a name="remarks"></a>Comentários  
 Você não precisa chamar **MoveFirst** imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.  
  
> [!CAUTION]
>  Chamar qualquer o **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chamar `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer uma da **mover** funções enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de um registro para outro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.  
  
 Se você chamar `MoveLast` em um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto de conjunto de registros é totalmente preenchido.  
  
 Não é possível chamar o **MoveFirst** ou `MovePrev` função membro com um instantâneo de rolagem de somente avanço.  
  
 Para mover a posição do atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="movelast"></a>  CDaoRecordset::MoveLast  
 Chame essa função de membro para tornar o último registro (se houver) no conjunto de registros do registro atual.  
  
```  
void MoveLast();
```  
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Chamar qualquer o **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chamar `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer uma da **mover** funções enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de um registro para outro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.  
  
 Se você chamar `MoveLast` em um objeto de conjunto de registros com base em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto de conjunto de registros é totalmente preenchido.  
  
 Para mover a posição do atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="movenext"></a>  CDaoRecordset::MoveNext  
 Chame essa função de membro para tornar o próximo registro no conjunto de registros do registro atual.  
  
```  
void MoveNext();
```  
  
### <a name="remarks"></a>Comentários  
 É recomendável que você chamar `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará um `CDaoException` se `IsBOF` retorna diferente de zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados, o conjunto de registros.  
  
> [!CAUTION]
>  Chamar qualquer o **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chamar `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer uma da **mover** funções enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de um registro para outro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.  
  
 Para mover a posição do atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="moveprev"></a>  CDaoRecordset::MovePrev  
 Chame essa função de membro para tornar o registro anterior no conjunto de registros do registro atual.  
  
```  
void MovePrev();
```  
  
### <a name="remarks"></a>Comentários  
 É recomendável que você chamar `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará um `CDaoException` se `IsBOF` retorna diferente de zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados, o conjunto de registros.  
  
> [!CAUTION]
>  Chamar qualquer o **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chamar `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer uma da **mover** funções enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de um registro para outro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou o objeto de conjunto de registros do tipo de instantâneo que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem de registros retornados é indefinida.  
  
 Não é possível chamar o **MoveFirst** ou `MovePrev` função membro com um instantâneo de rolagem de somente avanço.  
  
 Para mover a posição do atual gravar em um objeto de conjunto de registros de um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Mover" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="open"></a>  CDaoRecordset::Open  
 Você deve chamar esta função de membro para recuperar os registros do conjunto de registros.  
  
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
 `nOpenType`  
 Um dos seguintes valores:  
  
- **dbOpenDynaset** um conjunto de registros do tipo dynaset com rolagem bidirecional. Esse é o padrão.  
  
- **dbOpenTable** um conjunto de registros do tipo de tabela com rolagem bidirecional.  
  
- **dbOpenSnapshot** um conjunto de registros do tipo de instantâneo com rolagem bidirecional.  
  
 `lpszSQL`  
 Um ponteiro de cadeia de caracteres que contém um dos seguintes:  
  
-   Um **nulo** ponteiro.  
  
-   O nome de um ou mais tabledefs e/ou querydefs (separados por vírgula).  
  
-   Um SQL **selecione** instrução (opcionalmente com um SQL **onde** ou **ORDERBY** cláusula).  
  
-   Uma consulta de passagem.  
  
 `nOptions`  
 Uma ou mais das opções listadas abaixo. O valor padrão é 0. Os valores possíveis são:  
  
- **dbAppendOnly** você apenas pode acrescentar novos registros (somente conjunto de registros do tipo dynaset). Esta opção significa literalmente registros só podem ser acrescentados. As classes de banco de dados MFC ODBC tem uma opção somente de acréscimo que permite que os registros a serem recuperados e anexado.  
  
- **dbForwardOnly** o conjunto de registros é um instantâneo de rolagem de somente avanço.  
  
- **dbSeeChanges** gerar uma exceção se outro usuário está alterando os dados que você está editando.  
  
- **dbDenyWrite** outros usuários não podem modificar ou adicionar registros.  
  
- **dbDenyRead** outros usuários não podem exibir registros (somente conjunto de registros do tipo de tabela).  
  
- **dbReadOnly** só pode exibir registros; outros usuários possam modificá-los.  
  
- **dbInconsistent** atualizações inconsistentes são permitidas (somente conjunto de registros do tipo dynaset).  
  
- **dbConsistent** apenas atualizações consistentes são permitidas (somente conjunto de registros do tipo dynaset).  
  
> [!NOTE]
>  As constantes **dbConsistent** e **dbInconsistent** são mutuamente exclusivos. Você pode usar um ou outro, mas não ambos em uma determinada instância do **abrir**.  
  
 *pTableDef*  
 Um ponteiro para um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto. Esta versão é válido somente para conjuntos de registros do tipo de tabela. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não é utilizado; em vez disso, o banco de dados no qual reside o tabledef é usado.  
  
 *pQueryDef*  
 Um ponteiro para um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) objeto. Esta versão é válido somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não é utilizado; em vez disso, o banco de dados no qual reside o querydef é usado.  
  
### <a name="remarks"></a>Comentários  
 Antes de chamar **abrir**, você deve construir o objeto de conjunto de registros. Há várias maneiras de fazer isso:  
  
-   Quando você construir o objeto de conjunto de registros, passe um ponteiro para um `CDaoDatabase` objeto que já está aberto.  
  
-   Quando você construir o objeto de conjunto de registros, passe um ponteiro para um `CDaoDatabase` objeto que não está aberto. O conjunto de registros é aberto um `CDaoDatabase` do objeto, mas não fechará-lo quando fecha o objeto de conjunto de registros.  
  
-   Quando você construir o objeto de conjunto de registros, passar um **nulo** ponteiro. As chamadas do objeto de conjunto de registros `GetDefaultDBName` para obter o nome do Microsoft Access. Arquivo MDB a ser aberto. O conjunto de registros, em seguida, abre um `CDaoDatabase` objeto e mantém, abra o como o conjunto de registros é aberto. Quando você chama **fechar** no conjunto de registros, o `CDaoDatabase` objeto também é fechado.  
  
    > [!NOTE]
    >  Quando o conjunto de registros é aberto o `CDaoDatabase` do objeto, ele abre a fonte de dados com acesso não exclusivo.  
  
 Para obter a versão de **abrir** que usa o `lpszSQL` parâmetro, quando o conjunto de registros é aberto, você pode recuperar registros de várias maneiras. A primeira opção é ter funções DFX no seu `DoFieldExchange`. A segunda opção é usar a associação dinâmica chamando o `GetFieldValue` função de membro. Essas opções podem ser implementadas separadamente ou em conjunto. Se eles são combinados, você precisará passar na instrução SQL por conta própria na chamada a **abrir**.  
  
 Quando você usar a segunda versão do **abrir** onde você transmitir um `CDaoTableDef` do objeto, as colunas resultantes estarão disponíveis para a ligação por meio de `DoFieldExchange` e o mecanismo DFX e/ou vincular dinamicamente por meio `GetFieldValue`.  
  
> [!NOTE]
>  Você só pode chamar **abrir** usando um `CDaoTableDef` objeto para conjuntos de registros do tipo de tabela.  
  
 Quando você usa a terceira versão do **abrir** onde você transmitir um `CDaoQueryDef` do objeto, que a consulta será executada, e as colunas resultantes estarão disponíveis para a ligação por meio `DoFieldExchange` e o mecanismo DFX, e/ou vincular dinamicamente por meio de `GetFieldValue`.  
  
> [!NOTE]
>  Você só pode chamar **abrir** usando um `CDaoQueryDef` objeto tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 Para a primeira versão do **abrir** que usa o `lpszSQL` parâmetro, os registros são com base em critérios selecionados, mostrados na tabela a seguir.  
  
|O valor da `lpszSQL` parâmetro|Registros selecionados são determinados por|Exemplo|  
|--------------------------------------|----------------------------------------|-------------|  
|**NULL**|A cadeia de caracteres retornada por `GetDefaultSQL`.||  
|Uma lista separada por vírgulas de um ou mais tabledefs e/ou querydef nomes.|Todas as colunas são representadas no `DoFieldExchange`.|`"Customer"`|  
|**Selecione** lista de colunas **FROM** lista tabela|As colunas especificadas de e/ou o especificado tabledef(s) querydef(s).|`"SELECT CustId, CustName`<br /><br /> `FROM Customer"`|  
  
 O procedimento normal é passar **nulo** para **abrir**; nesse caso, **abrir** chamadas `GetDefaultSQL`, uma função de membro substituíveis ClassWizard gera ao criar um `CDaoRecordset`-classe derivada. Esse valor fornece os nomes de tabledef(s) e/ou querydef especificado em ClassWizard. Em vez disso, você pode especificar outras informações no `lpszSQL` parâmetro.  
  
 Tudo o que você passar **abrir** constrói uma cadeia de caracteres final do SQL para a consulta (a cadeia de caracteres pode ter o SQL **onde** e **ORDERBY** cláusulas anexado ao `lpszSQL` de cadeia de caracteres você passado) e, em seguida, executa a consulta. Você pode examinar a cadeia de caracteres construída chamando `GetSQL` depois de chamar **abrir**.  
  
 Os membros de sua classe de conjunto de registros de dados de campo são associados às colunas de dados selecionados. Se nenhum registro for retornado, o primeiro registro se torna o registro atual.  
  
 Se você quiser definir opções para o conjunto de registros, como um filtro ou uma classificação, defina `m_strSort` ou **m_strFilter** depois de construir o objeto de conjunto de registros, mas antes de chamar **abrir**. Se você deseja atualizar os registros no conjunto de registros após o conjunto de registros já está aberto, chame **Requery**.  
  
 Se você chamar **abrir** em um tipo dynaset ou conjunto de registros do tipo de instantâneo, ou se a fonte de dados se refere a uma instrução SQL ou um tabledef que representa uma tabela anexada, você não pode usar **dbOpenTable** para o tipo argumento; Se você fizer isso, o MFC gera uma exceção. Para determinar se um objeto tabledef representa uma tabela anexada, crie um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto e chame seu [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) função de membro.  
  
 Use o **dbSeeChanges** sinalizador se você quiser que as alterações feitas por outro usuário ou outro programa em seu computador quando você está editando ou excluindo o mesmo registro de interceptação. Por exemplo, se dois usuários começam a editar o mesmo registro, o primeiro usuário chamar o **atualização** bem-sucedida de função de membro. Quando **atualização** é chamado pelo segundo usuário, um `CDaoException` é gerada. Da mesma forma, se o segundo usuário tentar chamar **excluir** excluir o registro e já foi alterado pelo usuário primeiro, um `CDaoException` ocorre.  
  
 Normalmente, se o usuário obtém essa `CDaoException` durante a atualização, seu código deve atualizar o conteúdo dos campos e recuperar os valores modificados recentemente. Se a exceção ocorre no processo de exclusão, seu código pode exibir os novos dados de registro para o usuário e uma mensagem indicando que os dados foram alterados recentemente. Neste ponto, seu código pode solicitar uma confirmação de que o usuário ainda deseja excluir o registro.  
  
> [!TIP]
>  Use a opção de rolagem de somente avanço ( **dbForwardOnly**) melhorar o desempenho quando o aplicativo faz uma única passagem por meio de um conjunto de registros aberto de uma fonte de dados ODBC.  
  
 Para obter informações relacionadas, consulte o tópico "Método OpenRecordset" na Ajuda do DAO.  
  
##  <a name="requery"></a>  CDaoRecordset::Requery  
 Chame essa função de membro para reconstruir (Atualizar) um conjunto de registros.  
  
```  
virtual void Requery();
```  
  
### <a name="remarks"></a>Comentários  
 Se nenhum registro for retornado, o primeiro registro se torna o registro atual.  
  
 Na ordem do conjunto de registros refletir as adições e exclusões que você ou outros usuários estão fazendo à fonte de dados, você deve recriar o conjunto de registros chamando **Requery**. Se o conjunto de registros é dynaset, ele reflete automaticamente atualizações que você ou outros usuários façam seu registros existentes (mas não adições). Se o conjunto de registros é um instantâneo, você deve chamar **Requery** para refletir edições por outros usuários, bem como adições e exclusões.  
  
 Para um dynaset ou um instantâneo, chame **Requery** sempre que quiser para recriar o conjunto de registros com valores de parâmetros. Defina o filtro novo ou classificação definindo [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) antes de chamar **Requery**. Definir novos parâmetros ao atribuir novos valores para membros de dados de parâmetro antes de chamar **Requery**.  
  
 Se a tentativa de recriar o conjunto de registros falhar, o conjunto de registros é fechado. Antes de chamar **Requery**, você pode determinar se o conjunto de registros pode ser novamente consultado chamando o [CanRestart](#canrestart) função de membro. `CanRestart` não garante que **Requery** terá êxito.  
  
> [!CAUTION]
>  Chamar **Requery** somente depois de ter chamado **abrir**.  
  
> [!NOTE]
>  Chamando [Requery](#requery) indicadores DAO é alterado.  
  
 Não é possível chamar **Requery** em um tipo dynaset ou conjunto de registros do tipo de instantâneo se chamar `CanRestart` retorna 0, nem você usá-lo em um conjunto de registros do tipo de tabela.  
  
 Se ambos os `IsBOF` e `IsEOF` retornar zero depois de chamar **Requery**, a consulta não retornou nenhum registro e o conjunto de registros não contém nenhum dado.  
  
 Para obter informações relacionadas, consulte o tópico "Método Requery" na Ajuda do DAO.  
  
##  <a name="seek"></a>  CDaoRecordset::Seek  
 Chame essa função de membro para localizar o registro em um objeto de conjunto de registros do tipo de tabela indexada que atenda aos critérios especificados para a atual de índice e verifique a gravar o registro atual.  
  
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
 `lpszComparison`  
 Uma das expressões de cadeia de caracteres a seguir: "<","\<=", "=" "> =", ou ">".  
  
 `pKey1`  
 Um ponteiro para um [COleVariant](../../mfc/reference/colevariant-class.md) cujo valor corresponde para o primeiro campo no índice. Necessário.  
  
 *pKey2*  
 Um ponteiro para um `COleVariant` cujo valor corresponde ao segundo campo no índice, se houver. O padrão será a **nulo**.  
  
 *pKey3*  
 Um ponteiro para um `COleVariant` cujo valor corresponde para o terceiro campo no índice, se houver. O padrão será a **nulo**.  
  
 *pKeyArray*  
 Um ponteiro para uma matriz de variantes. O tamanho da matriz corresponde ao número de campos no índice.  
  
 *nKeys*  
 Um inteiro que corresponde ao tamanho da matriz, que é o número de campos no índice.  
  
> [!NOTE]
>  Não especifique caracteres curinga nas chaves. Curingas fará com que `Seek` para retornar sem registros correspondentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use a segunda versão (matriz) de `Seek` para lidar com índices de campos de quatro ou mais.  
  
 `Seek` Habilita o índice de alto desempenho que pesquisa em conjuntos de registros do tipo de tabela. Você deve definir o índice atual chamando `SetCurrentIndex` antes de chamar `Seek`. Se o índice identifica campos, ou um campo de chave não exclusivo `Seek` localiza o primeiro registro que satisfaz os critérios. Se você não definir um índice, uma exceção será lançada.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objetos devem ser declarados explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário de construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definido como `VT_BSTRT`.  
  
 Quando você chama `Seek`, passar um ou mais valores de chave e um operador de comparação ("<","\<=", "=" "> =", ou ">"). `Seek` pesquisa os campos de chave especificados e localiza o primeiro registro que satisfaz os critérios especificados pela `lpszComparison` e `pKey1`. Uma vez encontrada, `Seek` retorna zero e torna esse registro atual. Se `Seek` não conseguir localizar uma correspondência, `Seek` retorna zero, e o registro atual é indefinido. Ao usar DAO diretamente, você deve verificar explicitamente a propriedade NoMatch.  
  
 Se `lpszComparison` é "=" "> =", ou ">", `Seek` começa no início do índice. Se `lpszComparison` é "<" ou "< =", `Seek` inicia no final do índice e pesquisa para trás, a menos que existam entradas de índice duplicadas no final. Nesse caso, `Seek` começa com uma entrada arbitrária entre as entradas de índice duplicadas no final do índice.  
  
 Não deve haver um registro atual quando você usar `Seek`.  
  
 Para localizar um registro em um tipo dynaset ou conjunto de registros do tipo de instantâneo que atenda a uma condição específica, use as operações de localização. Para incluir todos os registros, não apenas aqueles que satisfazem uma condição específica, use as operações de movimentação para mover de um registro para outro.  
  
 Não é possível chamar `Seek` em uma tabela anexada de qualquer tipo, pois tabelas anexadas devem ser abertas como tipo dynaset ou conjuntos de registros do tipo de instantâneo. No entanto, se você chamar `CDaoDatabase::Open` para abrir diretamente um banco de dados ISAM instalável, você pode chamar `Seek` em tabelas no banco de dados, embora o desempenho pode ser lenta.  
  
 Para obter informações relacionadas, consulte o tópico "Método de busca" na Ajuda do DAO.  
  
##  <a name="setabsoluteposition"></a>  CDaoRecordset::SetAbsolutePosition  
 Define o número de registro relativo de registro de um objeto conjunto de registros atual.  
  
```  
void SetAbsolutePosition(long lPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lPosition*  
 Corresponde à posição ordinal do registro atual no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Chamando `SetAbsolutePosition` permite que você posicione o ponteiro de registro atual para um registro específico com base em sua posição ordinal em um tipo dynaset ou conjunto de registros do tipo de instantâneo. Você também pode determinar o número de registro atual chamando [GetAbsolutePosition](#getabsoluteposition).  
  
> [!NOTE]
>  Essa função de membro é válida somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseado em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Definir um valor maior que o número de causas de registros preenchidos MFC para lançar uma exceção. Você pode determinar o número de registros preenchidos no conjunto de registros chamando o `GetRecordCount` função de membro.  
  
 Se o registro atual é excluído, o valor da propriedade AbsolutePosition não está definido e MFC lança uma exceção se ele é referenciado. Novos registros são adicionados ao final da sequência.  
  
> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro de substitutos. Indicadores ainda são a maneira recomendada de reter e retornar para a posição especificada e a única maneira de posicionar o registro atual em todos os tipos de objetos de conjunto de registros que dão suporte a indicadores. Em particular, a posição de um determinado registro muda quando o registro (s) anterior é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado novamente porque a ordem de registros individuais dentro de um conjunto de registros não é garantida, a menos que ela é criada com uma instrução SQL usando um  **ORDERBY** cláusula.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.  
  
##  <a name="setbookmark"></a>  CDaoRecordset::SetBookmark  
 Chame essa função de membro para posicionar o conjunto de registros no registro que contém o indicador especificado.  
  
```  
void SetBookmark(COleVariant varBookmark);
```  
  
### <a name="parameters"></a>Parâmetros  
 `varBookmark`  
 Um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor do indicador para um registro específico.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto de conjunto de registros é criado ou aberto, cada um de seus registros já possui um indicador exclusivo. Você pode recuperar o indicador para o registro atual chamando `GetBookmark` e salvar o valor para um `COleVariant` objeto. Você possa retornar posteriormente para esse registro chamando `SetBookmark` usando o valor do indicador salvo.  
  
> [!NOTE]
>  Chamando [Requery](#requery) indicadores DAO é alterado.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário de construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definido como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedades de indicador" e Bookmarkable"na Ajuda do DAO.  
  
##  <a name="setcachesize"></a>  CDaoRecordset::SetCacheSize  
 Chame essa função de membro para definir o número de registros a ser armazenado em cache.  
  
```  
void SetCacheSize(long lSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lSize`  
 Especifica o número de registros. Um valor típico é 100. Uma configuração de 0 desativa o cache. A configuração deve estar entre 5 e 1200 registros. O cache pode usar uma quantidade considerável de memória.  
  
### <a name="remarks"></a>Comentários  
 Um cache é um espaço na memória local que mantém os dados recuperados mais recentemente do servidor que os dados serem solicitados novamente enquanto o aplicativo está em execução. Cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Quando dados são solicitados, o mecanismo de banco de dados do Microsoft Jet primeiro verifica o cache para os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não vêm de uma fonte de dados ODBC não são salvos no cache.  
  
 Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remotos, chamada de `SetCacheSize` e `SetCacheStart` funções de membro e, em seguida, chame o `FillCache` percorrer os registros usando uma das operações de movimentação ou função de membro. O `lSize` parâmetro o `SetCacheSize` função de membro pode basear-se no número de registros de seu aplicativo pode funcionar com ao mesmo tempo. Por exemplo, se você estiver usando um conjunto de registros como a fonte de dados a ser exibido na tela, você poderia passar a `SetCacheSize` `lSize` parâmetro como 20 para exibir 20 registros de uma só vez.  
  
 Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.  
  
##  <a name="setcachestart"></a>  CDaoRecordset::SetCacheStart  
 Chame essa função de membro para especificar o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
```  
void SetCacheStart(COleVariant varBookmark);
```  
  
### <a name="parameters"></a>Parâmetros  
 `varBookmark`  
 Um [COleVariant](../../mfc/reference/colevariant-class.md) que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o valor do indicador de qualquer registro para o `varBookmark` parâmetro o `SetCacheStart` função de membro. Verifique o registro que você deseja iniciar o cache com o registro atual, estabelecer um indicador para esse registro usando [SetBookmark](#setbookmark)e passe o valor do indicador como o parâmetro para o `SetCacheStart` função de membro.  
  
 O mecanismo de banco de dados Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.  
  
 Registros recuperados do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.  
  
 Para forçar uma atualização de todos os dados armazenados em cache, passe o `lSize` parâmetro `SetCacheSize` como 0, chame `SetCacheSize` novamente com o tamanho do cache você originalmente solicitada e, em seguida, chame o `FillCache` função de membro.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário de construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definido como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte o tópico CacheSize, CacheStart propriedades "na Ajuda do DAO.  
  
##  <a name="setcurrentindex"></a>  CDaoRecordset::SetCurrentIndex  
 Chame essa função de membro para definir um índice em um conjunto de registros do tipo de tabela.  
  
```  
void SetCurrentIndex(LPCTSTR lpszIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIndex`  
 Um ponteiro que contém o nome do índice a ser definido.  
  
### <a name="remarks"></a>Comentários  
 Registros nas tabelas base não são armazenados em uma ordem específica. Um índice de configuração altera a ordem de registros retornados do banco de dados, mas ele não afeta a ordem na qual os registros são armazenados. O índice especificado já deve estar definido. Se você tentar usar um índice de um objeto que não existe, ou se o índice não é definido quando você chamar [busca](#seek), MFC lança uma exceção.  
  
 Você pode criar um novo índice para a tabela chamando [CDaoTableDef::CreateIndex](../../mfc/reference/cdaotabledef-class.md#createindex) e anexar o novo índice para a coleção de índices de tabledef subjacente chamando [CDaoTableDef::Append](../../mfc/reference/cdaotabledef-class.md#append), e em seguida, abrir novamente o conjunto de registros.  
  
 Registros retornados de um conjunto de registros do tipo de tabela podem ser ordenados somente pelos índices definidos para tabledef subjacente. Para classificar registros em alguma outra ordem, você pode abrir um dynaset ou conjunto de registros do tipo de instantâneo usando um SQL **ORDERBY** cláusula armazenados em [CDaoRecordset::m_strSort](#m_strsort).  
  
 Para obter informações relacionadas, consulte o tópico "Objeto de índice" e a definição de "índice atual" na Ajuda do DAO.  
  
##  <a name="setfielddirty"></a>  CDaoRecordset::SetFieldDirty  
 Chame essa função de membro para sinalizar um membro de dados do campo do conjunto de registros como alterados ou como inalterado.  
  
```  
void SetFieldDirty(
    void* pv,  
    BOOL bDirty = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Contém o endereço de um membro de dados do campo no conjunto de registros ou **nulo**. Se **nulo**, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ **nulo** não é o mesmo que Null na terminologia de banco de dados, que significa "não ter nenhum valor.")  
  
 `bDirty`  
 **TRUE** se o membro de dados do campo é sinalizada como "sujos" (alterados). Caso contrário, **FALSE** se o membro de dados do campo é sinalizada como "Limpar" (inalterados).  
  
### <a name="remarks"></a>Comentários  
 Marcar campos como inalterado garante que o campo não é atualizado.  
  
 As marcas de framework alterado membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, para que você raramente precisa chamar `SetFieldDirty` por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor está nos dados do campo membro. O mecanismo DFX emprega o uso de **PSEUDONULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como sujos. Nesse caso, será necessário definir explicitamente o campo como sujos. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática campo.  
  
> [!NOTE]
>  Chamar essa função de membro somente depois de ter chamado [editar](#edit) ou [AddNew](#addnew).  
  
 Usando **nulo** para o primeiro argumento da função serão aplicadas a função para todos os **outputColumn** campos não **param** campos `CDaoFieldExchange`. Por exemplo, a chamada  
  
 [!code-cpp[NVC_MFCDatabase#6](../../mfc/codesnippet/cpp/cdaorecordset-class_6.cpp)]  
  
 será definido somente **outputColumn** campos **nulo**; **param** campos não serão afetados.  
  
 Para trabalhar em um **param**, você deve fornecer o endereço real da pessoa **param** você deseja trabalhar, como:  
  
 [!code-cpp[NVC_MFCDatabase#7](../../mfc/codesnippet/cpp/cdaorecordset-class_7.cpp)]  
  
 Isso significa que você não pode definir todos os **param** campos **nulo**, como faria com **outputColumn** campos.  
  
 `SetFieldDirty` é implementado por meio de `DoFieldExchange`.  
  
##  <a name="setfieldnull"></a>  CDaoRecordset::SetFieldNull  
 Chame essa função de membro para sinalizar um membro de dados do campo do conjunto de registros como Null (especificamente com nenhum valor) ou não nulo.  
  
```  
void SetFieldNull(
    void* pv,  
    BOOL bNull = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Contém o endereço de um membro de dados do campo no conjunto de registros ou **nulo**. Se **nulo**, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ **nulo** não é o mesmo que Null na terminologia de banco de dados, que significa "não ter nenhum valor.")  
  
 `bNull`  
 Diferente de zero se o membro de dados do campo a ser sinalizada como não tendo nenhum valor (Null). Caso contrário, 0 se o membro de dados do campo é sinalizado como não nulo.  
  
### <a name="remarks"></a>Comentários  
 `SetFieldNull` é usado para campos vinculados a `DoFieldExchange` mecanismo.  
  
 Quando você adiciona um novo registro para um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e marcados como "sujos" (alterados). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou são Null. Se não for apropriado para um campo nulo, uma [CDaoException](../../mfc/reference/cdaoexception-class.md) é gerada.  
  
 Se você estiver usando o mecanismo de armazenamento em buffer duplo, por exemplo, se desejar especificamente designar um campo do registro atual como não tendo um valor, chame `SetFieldNull` com `bNull` definida como **TRUE** para marcá-lo como Null. Se um campo anteriormente foi marcado como Null, e agora você deseja atribuir a ela um valor, basta defina o novo valor. Você não precisa remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser Null, chame [IsFieldNullable](#isfieldnullable).  
  
 Se você não estiver usando o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como sujo e não nulo. Especificamente, você deve definir os campos incorreto e não nulo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação automática campo.  
  
 O mecanismo DFX emprega o uso de **PSEUDONULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
> [!NOTE]
>  Chamar essa função de membro somente depois de ter chamado [editar](#edit) ou [AddNew](#addnew).  
  
 Usando **nulo** para o primeiro argumento da função serão aplicadas apenas para a função **outputColumn** campos não **param** campos `CDaoFieldExchange`. Por exemplo, a chamada  
  
 [!code-cpp[NVC_MFCDatabase#8](../../mfc/codesnippet/cpp/cdaorecordset-class_8.cpp)]  
  
 será definido somente **outputColumn** campos **nulo**; **param** campos não serão afetados.  
  
##  <a name="setfieldvalue"></a>  CDaoRecordset::SetFieldValue  
 Chame essa função de membro para definir o valor de um campo, pela posição ordinal ou alterando o valor da cadeia de caracteres.  
  
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
 `lpszName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome de um campo.  
  
 `varValue`  
 Uma referência a um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor do conteúdo do campo.  
  
 `nIndex`  
 Um inteiro que representa a posição ordinal do campo na coleção de campos do conjunto de registros (com base em zero).  
  
 `lpszValue`  
 Um ponteiro para uma cadeia de caracteres que contém o valor do conteúdo do campo.  
  
### <a name="remarks"></a>Comentários  
 Use `SetFieldValue` e [GetFieldValue](#getfieldvalue) vincular dinamicamente os campos no tempo de execução em vez de estaticamente colunas de associação usando o [DoFieldExchange](#dofieldexchange) mecanismo.  
  
 Observe que se você não estiver criando um conjunto de registros UNICODE, você deve usar uma forma de `SetFieldValue` que não contenha um `COleVariant` parâmetro, ou o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário de construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definido como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte os tópicos "Objeto Field" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="setfieldvaluenull"></a>  CDaoRecordset::SetFieldValueNull  
 Chame essa função de membro para definir o campo como um valor nulo.  
  
```  
void SetFieldValueNull(int nIndex);  
void SetFieldValueNull(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do campo no conjunto de registros, pesquisa por índice de base zero.  
  
 `lpszName`  
 O nome do campo no conjunto de registros, pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa que "não ter nenhum valor".  
  
 Para obter informações relacionadas, consulte os tópicos "Objeto Field" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="setlockingmode"></a>  CDaoRecordset::SetLockingMode  
 Chame essa função de membro para definir o tipo de bloqueio para o conjunto de registros.  
  
```  
void SetLockingMode(BOOL bPessimistic);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bPessimistic*  
 Um sinalizador que indica o tipo de bloqueio.  
  
### <a name="remarks"></a>Comentários  
 Quando o bloqueio pessimista está em vigor, a página de 2K que contém o registro que você está editando é bloqueado assim que você chamar o **editar** função de membro. A página está desbloqueada quando você chamar o **atualização** ou **fechar** função de membro ou qualquer uma das operações de mover ou localizar.  
  
 Quando otimista proteção está em vigor, a página de 2K que contém o registro é bloqueada somente enquanto o registro está sendo atualizado com o **atualização** função de membro.  
  
 Se uma página estiver bloqueada, nenhum outro usuário pode editar registros na mesma página. Se você chamar `SetLockingMode` e passe um valor diferente de zero e outro usuário já tiver bloqueado a página, uma exceção é gerada quando você chamar **editar**. Outros usuários podem ler dados de páginas bloqueadas.  
  
 Se você chamar `SetLockingMode` chamada com um valor igual a zero e posterior **atualização** enquanto a página está bloqueada por outro usuário, ocorrerá uma exceção. Para ver as alterações feitas em seu registro por outro usuário (e perder as alterações), chame o `SetBookmark` função membro com o valor do indicador do registro atual.  
  
 Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.  
  
##  <a name="setparamvalue"></a>  CDaoRecordset::SetParamValue  
 Chame essa função de membro para definir o valor de um parâmetro no conjunto de registros em tempo de execução.  
  
```  
virtual void SetParamValue(
    int nIndex,  
    const COleVariant& varValue);

 
virtual void SetParamValue(
    LPCTSTR lpszName,  
    const COleVariant& varValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 A posição numérica do parâmetro na coleção de parâmetros do querydef.  
  
 `var`  
 O valor a ser definido; Consulte comentários.  
  
 `lpszName`  
 O nome do parâmetro cujo valor você deseja definir.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro deve já foram estabelecido como parte da cadeia de caracteres SQL do conjunto de registros. Você pode acessar o parâmetro por nome ou por sua posição de índice na coleção.  
  
 Especifique o valor a ser definido como um `COleVariant` objeto. Para obter informações sobre como definir o valor desejado e digite sua `COleVariant` de objeto, consulte a classe [COleVariant](../../mfc/reference/colevariant-class.md). Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário de construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definido como `VT_BSTRT`.  
  
##  <a name="setparamvaluenull"></a>  CDaoRecordset::SetParamValueNull  
 Chame essa função de membro para definir o parâmetro para um valor nulo.  
  
```  
void SetParamValueNull(int nIndex);  
void SetParamValueNull(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do campo no conjunto de registros, pesquisa por índice de base zero.  
  
 `lpszName`  
 O nome do campo no conjunto de registros, pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa que "não ter nenhum valor".  
  
##  <a name="setpercentposition"></a>  CDaoRecordset::SetPercentPosition  
 Chame essa função de membro para definir um valor que altera a localização aproximada do registro atual no objeto de conjunto de registros com base em uma porcentagem dos registros no conjunto de registros.  
  
```  
void SetPercentPosition(float fPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fPosition*  
 Um número entre 0 e 100.  
  
### <a name="remarks"></a>Comentários  
 Ao trabalhar com um tipo dynaset ou conjunto de registros do tipo de instantâneo, primeiro preencher o conjunto de registros ao mover para o último registro antes de chamar `SetPercentPosition`. Se você chamar `SetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimentação é em relação ao número de registros acessado conforme indicado pelo valor de [GetRecordCount](#getrecordcount). Você pode mover para o último registro chamando `MoveLast`.  
  
 Depois de você chamar `SetPercentPosition`, o registro na posição aproximado correspondente a esse valor é atualizado.  
  
> [!NOTE]
>  Chamando `SetPercentPosition` para mover o registro atual para um registro específico em um conjunto de registros não é recomendado. Chamar o [SetBookmark](#setbookmark) função de membro em vez disso.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.  
  
##  <a name="update"></a>  CDaoRecordset::Update  
 Chamar essa função de membro após uma chamada para o `AddNew` ou **editar** função de membro.  
  
```  
virtual void Update();
```  
  
### <a name="remarks"></a>Comentários  
 Esta chamada é necessária para concluir o `AddNew` ou **editar** operação.  
  
 Ambos `AddNew` e **editar** preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar a fonte de dados. **Atualização** salva os dados. Apenas os campos marcados ou detectado como alterado são atualizados.  
  
 Se a fonte de dados oferece suporte a transações, você pode fazer o **atualização** chamar (e correspondente `AddNew` ou **editar** chamar) faz parte de uma transação.  
  
> [!CAUTION]
>  Se você chamar **atualização** sem primeiro chamar `AddNew` ou **editar**, **atualização** lança um `CDaoException`. Se você chamar `AddNew` ou **editar**, você deve chamar **atualização** antes de chamar [MoveNext](#movenext) ou fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, as alterações serão perdidas sem notificação.  
  
 Quando o objeto de conjunto de registros pessimistically está bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado da hora **editar** é usado até que a atualização for concluída. Se o conjunto de registros de modo otimista é bloqueado, o registro está bloqueado e comparado com o registro anterior à edição antes que ele seja atualizado no banco de dados. Se o registro foi alterado desde que você chamou **editar**, o **atualização** operação falha e MFC lança uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.  
  
> [!NOTE]
>  Bloqueio otimista é sempre usado em formatos de banco de dados externo, como ODBC e ISAM instalável.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Método CancelUpdate", "Método Delete", "Propriedade LastModified", "Método de atualização" e "Propriedade EditMode" na Ajuda do DAO.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)
