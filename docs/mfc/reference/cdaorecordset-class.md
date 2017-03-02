---
title: Classe CDaoRecordset | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDaoRecordset
dev_langs:
- C++
helpviewer_keywords:
- recordsets, types
- CDaoRecordset class
- records, CDaoRecordSet
ms.assetid: 2322067f-1027-4662-a5d7-aa2fc7488630
caps.latest.revision: 26
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
ms.openlocfilehash: 3d3d830a7d423a2653819e9cbf160538e486cfb0
ms.lasthandoff: 02/25/2017

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
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoRecordset::AddNew](#addnew)|Prepara para adicionar um novo registro. Chamar [atualização](#update) para concluir a adição.|  
|[CDaoRecordset::CanAppend](#canappend)|Retorna zero se novos registros podem ser adicionados ao conjunto de registros por meio de [AddNew](#addnew) função de membro.|  
|[CDaoRecordset::CanBookmark](#canbookmark)|Retorna zero se o conjunto de registros oferece suporte a indicadores.|  
|[CDaoRecordset::CancelUpdate](#cancelupdate)|Cancela todas as atualizações pendentes devido a um [editar](#edit) ou [AddNew](#addnew) operação.|  
|[CDaoRecordset::CanRestart](#canrestart)|Retorna zero se [Requery](#requery) pode ser chamado para executar a consulta do conjunto de registros novamente.|  
|[CDaoRecordset::CanScroll](#canscroll)|Retorna zero se você pode percorrer os registros.|  
|[CDaoRecordset::CanTransact](#cantransact)|Retorna zero se a fonte de dados oferece suporte a transações.|  
|[CDaoRecordset::CanUpdate](#canupdate)|Retorna zero se o conjunto de registros pode ser atualizado (você pode adicionar, atualizar ou excluir registros).|  
|[CDaoRecordset::Close](#close)|Fecha o conjunto de registros.|  
|[CDaoRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Você deve explicitamente rolar para outro registro após a exclusão.|  
|[CDaoRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa DAO campo troca de registro (DFX).|  
|[CDaoRecordset::Edit](#edit)|Prepara para as alterações no registro atual. Chamar **atualização** para concluir a edição.|  
|[CDaoRecordset::FillCache](#fillcache)|Todos os preenchimentos ou parte de um cache local para um objeto recordset que contém dados de uma fonte de dados ODBC.|  
|[CDaoRecordset::Find](#find)|Localiza o primeiro, próximo, anterior, ou o último local de uma cadeia de caracteres específica em um conjunto de registros do tipo dynaset que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindFirst](#findfirst)|Localiza o primeiro registro em um tipo dynaset ou recordset tipo snapshot que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindLast](#findlast)|Localiza o último registro em um tipo dynaset ou recordset tipo snapshot que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindNext](#findnext)|Localiza o próximo registro em um tipo dynaset ou recordset tipo snapshot que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::FindPrev](#findprev)|Localiza o registro anterior em um tipo dynaset ou recordset tipo snapshot que atenda aos critérios especificados e torna esse registro o registro atual.|  
|[CDaoRecordset::GetAbsolutePosition](#getabsoluteposition)|Retorna o número do registro atual de um objeto conjunto de registros.|  
|[CDaoRecordset::GetBookmark](#getbookmark)|Retorna um valor que representa o indicador em um registro.|  
|[CDaoRecordset::GetCacheSize](#getcachesize)|Retorna um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém os dados sejam armazenados em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::GetCacheStart](#getcachestart)|Retorna um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|  
|[CDaoRecordset::GetCurrentIndex](#getcurrentindex)|Retorna um `CString` contendo o nome do índice mais recentemente usada em um tipo de tabela indexado, `CDaoRecordset`.|  
|[CDaoRecordset::GetDateCreated](#getdatecreated)|Retorna a data e hora a tabela base subjacente uma `CDaoRecordset` objeto foi criado|  
|[CDaoRecordset::GetDateLastUpdated](#getdatelastupdated)|Retorna a data e hora da alteração mais recente feita no design de uma tabela base subjacente uma `CDaoRecordset` objeto.|  
|[CDaoRecordset::GetDefaultDBName](#getdefaultdbname)|Retorna o nome da fonte de dados padrão.|  
|[CDaoRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres padrão SQL para executar.|  
|[CDaoRecordset::GetEditMode](#geteditmode)|Retorna um valor que indica o estado de edição do registro atual.|  
|[CDaoRecordset::GetFieldCount](#getfieldcount)|Retorna um valor que representa o número de campos em um conjunto de registros.|  
|[CDaoRecordset::GetFieldInfo](#getfieldinfo)|Retorna tipos específicos de informações sobre os campos no conjunto de registros.|  
|[CDaoRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::GetIndexCount](#getindexcount)|Recupera o número de índices em uma tabela base de um conjunto de registros.|  
|[CDaoRecordset::GetIndexInfo](#getindexinfo)|Retorna a vários tipos de informações sobre um índice.|  
|[CDaoRecordset::GetLastModifiedBookmark](#getlastmodifiedbookmark)|Usado para determinar os mais recentemente adicionado ou atualizavam do registro.|  
|[CDaoRecordset::GetLockingMode](#getlockingmode)|Retorna um valor que indica o tipo de bloqueio que está em vigor durante a edição.|  
|[CDaoRecordset::GetName](#getname)|Retorna um `CString` que contém o nome do conjunto de registros.|  
|[CDaoRecordset::GetParamValue](#getparamvalue)|Recupera o valor atual do parâmetro especificado armazenado no objeto DAOParameter subjacente.|  
|[CDaoRecordset::GetPercentPosition](#getpercentposition)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|  
|[CDaoRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros acessados em um objeto recordset.|  
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
|[CDaoRecordset::IsOpen](#isopen)|Retorna zero se [abrir](#open) tiver sido chamado anteriormente.|  
|[CDaoRecordset::Move](#move)|Posiciona o conjunto de registros para um número especificado de registros do registro atual em qualquer direção.|  
|[CDaoRecordset::MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros.|  
|[CDaoRecordset::MoveLast](#movelast)|Posiciona o registro atual no último registro no conjunto de registros.|  
|[CDaoRecordset::MoveNext](#movenext)|Posiciona o registro atual no próximo registro no conjunto de registros.|  
|[CDaoRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior no conjunto de registros.|  
|[Cdaorecordset:: Open](#open)|Cria um novo conjunto de registros de uma tabela, dynaset ou instantâneo.|  
|[CDaoRecordset::Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|  
|[CDaoRecordset::Seek](#seek)|Localiza o registro em um objeto recordset de tipo de tabela indexada que atenda aos critérios especificados para o índice atual e torna esse registro o registro atual.|  
|[CDaoRecordset::SetAbsolutePosition](#setabsoluteposition)|Define o número do registro atual de um objeto conjunto de registros.|  
|[CDaoRecordset::SetBookmark](#setbookmark)|Posiciona o conjunto de registros em um registro que contém o indicador especificado.|  
|[CDaoRecordset::SetCacheSize](#setcachesize)|Define um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém os dados sejam armazenados em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::SetCacheStart](#setcachestart)|Define um valor que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.|  
|[CDaoRecordset::SetCurrentIndex](#setcurrentindex)|Chamado para definir um índice em um conjunto de registros do tipo de tabela.|  
|[CDaoRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|  
|[CDaoRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual para Null (não ter nenhum valor).|  
|[CDaoRecordset::SetFieldValue](#setfieldvalue)|Define o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::SetFieldValueNull](#setfieldvaluenull)|Define o valor de um campo em um conjunto de registros como Null. (com nenhum valor).|  
|[CDaoRecordset::SetLockingMode](#setlockingmode)|Define um valor que indica o tipo de bloqueio para colocar em vigor durante a edição.|  
|[CDaoRecordset::SetParamValue](#setparamvalue)|Define o valor atual do parâmetro especificado armazenado no objeto subjacente DAOParameter|  
|[CDaoRecordset::SetParamValueNull](#setparamvaluenull)|Define o valor atual do parâmetro especificado como Null (não ter nenhum valor).|  
|[CDaoRecordset::SetPercentPosition](#setpercentposition)|Define a posição do registro atual para um local correspondente para uma porcentagem do número total de registros em um conjunto de registros.|  
|[CDaoRecordset::Update](#update)|Conclui uma `AddNew` ou **editar** operação salvando os dados novos ou editados na fonte de dados.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDaoRecordset::m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields)|Contém um sinalizador que indica se os campos são marcados automaticamente como alterado.|  
|[CDaoRecordset::m_nFields](#m_nfields)|Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.|  
|[CDaoRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro na classe de conjunto de registros, o número de parâmetros passados com a consulta do conjunto de registros|  
|[CDaoRecordset::m_pDAORecordset](#m_pdaorecordset)|Um ponteiro para a interface do DAO base do objeto recordset.|  
|[CDaoRecordset::m_pDatabase](#m_pdatabase)|Banco de dados de origem para o conjunto de resultados. Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.|  
|[CDaoRecordset::m_strFilter](#m_strfilter)|Contém uma cadeia de caracteres usada para construir um SQL **onde** instrução.|  
|[CDaoRecordset::m_strSort](#m_strsort)|Contém uma cadeia de caracteres usada para construir um SQL **ORDER BY** instrução.|  
  
## <a name="remarks"></a>Comentários  
 Conhecido como "conjunto de registros," `CDaoRecordset` objetos estão disponíveis nas seguintes três formas:  
  
-   Conjuntos de registros do tipo de tabela representam uma tabela base que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados único.  
  
-   Conjuntos de registros do tipo dynaset são o resultado de uma consulta que pode ter registros atualizáveis. Esses conjuntos de registros são um conjunto de registros que você pode usar para examinar, adicionar, alterar ou excluir registros de uma tabela de banco de dados subjacente ou tabelas. Conjuntos de registros do tipo dynaset podem conter campos de uma ou mais tabelas em um banco de dados.  
  
-   Conjuntos de registros do tipo de instantâneo são uma cópia estática de um conjunto de registros que você pode usar para encontrar dados ou gerar relatórios. Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados, mas não podem ser atualizados.  
  
 Cada formulário de conjunto de registros representa um conjunto de registros determinada no momento em que o conjunto de registros é aberto. Quando você rola para um registro em um conjunto de registros do tipo de tabela ou um conjunto de registros do tipo dynaset, ele reflete as alterações feitas no registro depois que o conjunto de registros é aberto, por outros usuários ou outros conjuntos de registros em seu aplicativo. (Um conjunto de registros do tipo de instantâneo não pode ser atualizado.) Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de conjunto de registros específicos do aplicativo de `CDaoRecordset`. Em seguida, você pode:  
  
-   Percorrer os registros.  
  
-   Definir um índice e rapidamente procurar registros usando [busca](#seek) (apenas conjuntos de registros do tipo de tabela).  
  
-   Localizar registros com base em uma comparação de cadeia de caracteres: "<",></",>\<=", "=", "> =", ou ">" (tipo dynaset e conjuntos de registros do tipo de instantâneo).  
  
-   Atualizar os registros e especificar um modo de bloqueio (exceto os conjuntos de registros do tipo de instantâneo).  
  
-   Filtre o conjunto de registros para restringir quais registros seleciona entre os disponíveis na fonte de dados.  
  
-   Classificar o conjunto de registros.  
  
-   Parametrize o conjunto de registros para personalizar sua seleção com informações não são conhecidas até o tempo de execução.  
  
 Classe `CDaoRecordset` fornece uma interface semelhante da classe `CRecordset`. A principal diferença é a classe `CDaoRecordset` acessa dados por meio de um acesso de dados objeto (DAO) com base em OLE. Classe `CRecordset` acessa o DBMS por meio de conectividade aberta de banco de dados (ODBC) e um driver ODBC desse DBMS.  
  
> [!NOTE]
>  As classes de banco de dados DAO são diferentes das classes de banco de dados MFC com base em conectividade aberta de banco de dados (ODBC). Todos os nomes de classe de banco de dados DAO têm o prefixo "CDao". Você ainda pode acessar fontes de dados ODBC com as classes DAO; as classes DAO geralmente oferecem recursos avançados de como eles são específicos para o mecanismo de banco de dados Microsoft Jet.  
  
 Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de `CDaoRecordset`. Para usar uma classe de conjunto de registros em ambos os casos, abra um banco de dados e construir um objeto recordset, passando ao construtor um ponteiro para o `CDaoDatabase` objeto. Também é possível construir um `CDaoRecordset` de objeto e permitir que o MFC criar um temporário `CDaoDatabase` objeto para você. Em seguida, chame o conjunto de registros [abrir](#open) função de membro, especificando se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo. Chamando **abrir** seleciona os dados do banco de dados e recupera o primeiro registro.  
  
 Use os membros de dados e funções de membro do objeto para percorrer os registros e operar sobre elas. As operações disponíveis dependem de se o objeto é um conjunto de registros do tipo de tabela, um conjunto de registros do tipo dynaset ou um conjunto de registros do tipo de instantâneo e seja atualizável ou somente leitura — isso depende da capacidade do banco de dados ou fonte de dados de conectividade de banco de dados aberto (ODBC). Para atualizar os registros que podem foram alterados ou adicionados desde o **abrir** chamar, chamar o objeto [Requery](#requery) função de membro. Chamar o objeto **fechar** membro de função e destruir o objeto quando você terminar com ele.  
  
 `CDaoRecordset`usa troca de campos de registro DAO (DFX) para oferecer suporte a ler e atualizar campos de registro por meio de membros do tipo seguro C++ de sua `CDaoRecordset` ou `CDaoRecordset`-classe derivada. Você também pode implementar a vinculação dinâmica de colunas em um banco de dados sem usar o mecanismo DFX usando [GetFieldValue](#getfieldvalue) e [SetFieldValue](#setfieldvalue).  
  
 Para obter informações relacionadas, consulte o tópico "Recordset Object" na Ajuda do DAO.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDaoRecordset`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
##  <a name="a-nameaddnewa--cdaorecordsetaddnew"></a><a name="addnew"></a>CDaoRecordset::AddNew  
 Chame essa função de membro para adicionar um novo registro para um conjunto de registros do tipo de tabela ou do tipo dynaset.  
  
```  
virtual void AddNew();
```  
  
### <a name="remarks"></a>Comentários  
 Campos de registro são inicialmente nulos. (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é o mesmo que **nulo** em C++.) Para concluir a operação, você deve chamar o [atualização](#update) função de membro. **Atualização** salva as alterações para a fonte de dados.  
  
> [!CAUTION]
>  Se você editar um registro e, em seguida, role até outro registro sem chamar **atualização**, suas alterações serão perdidas sem aviso.  
  
 Se você adiciona um registro a um conjunto de registros do tipo dynaset chamando [AddNew](#addnew), o registro está visível no conjunto de registros e incluído na tabela base onde se torna visível para qualquer novo `CDaoRecordset` objetos.  
  
 A posição do novo registro depende do tipo de conjunto de registros:  
  
-   Um tipo dynaset recordset, onde o novo registro é inserido não é garantida. Esse comportamento foi alterado com o Microsoft Jet 3.0 por motivos de desempenho e simultaneidade. Se seu objetivo é tornar o registro adicionado recentemente o registro atual, obtenha o indicador do último registro modificado e mover para esse indicador:  
  
 [!code-cpp[NVC_MFCDatabase n º&1;](../../mfc/codesnippet/cpp/cdaorecordset-class_1.cpp)]  
  
-   Em um conjunto de registros de tipo de tabela para a qual um índice foi especificado, os registros são retornados em seus próprios lugares na ordem de classificação. Se nenhum índice foi especificado, novos registros são retornados no final do conjunto de registros.  
  
 O registro que era atual antes do uso `AddNew` permaneçam atuais. Se você deseja tornar o novo registro atual e o conjunto de registros oferece suporte a indicadores, chamada [SetBookmark](#setbookmark) para o indicador identificado pela configuração da propriedade LastModified do objeto de conjunto de registros DAO subjacente. Isso é útil para determinar o valor para campos de contador (incremento automático) em um registro adicionado. Para obter mais informações, consulte [GetLastModifiedBookmark](#getlastmodifiedbookmark).  
  
 Se o banco de dados oferece suporte a transações, você poderá tornar seu `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte a classe [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md). Observe que você deve chamar [CDaoWorkspace::BeginTrans](../../mfc/reference/cdaoworkspace-class.md#begintrans) antes de chamar `AddNew`.  
  
 Não é possível chamar `AddNew` para um conjunto de registros cujo [abrir](#open) função de membro não foi chamada. A `CDaoException` é lançada se você chamar `AddNew` para um conjunto de registros não pode ser anexado. Você pode determinar se o conjunto de registros é atualizável chamando [CanAppend](#canappend).  
  
 As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, portanto você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor no membro de dados do campo. O mecanismo DFX emprega o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como suja. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação de campo automáticas.  
  
> [!NOTE]
>  Se os registros são armazenados em buffer duplo (ou seja, verificação de campo automática é habilitada), chamar `CancelUpdate` irá restaurar as variáveis de membro para os valores que tinham antes `AddNew` ou **editar** foi chamado.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Método CancelUpdate", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="a-namecanappenda--cdaorecordsetcanappend"></a><a name="canappend"></a>CDaoRecordset::CanAppend  
 Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite adicionar novos registros chamando o [AddNew](#addnew) função de membro.  
  
```  
BOOL CanAppend() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros permite adicionar novos registros. Caso contrário, 0. `CanAppend`retornará 0 se você abriu o conjunto de registros somente leitura.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Acrescentar o método" na Ajuda do DAO.  
  
##  <a name="a-namecanbookmarka--cdaorecordsetcanbookmark"></a><a name="canbookmark"></a>CDaoRecordset::CanBookmark  
 Chame essa função de membro para determinar se o conjunto de registros aberto anteriormente permite marcar individualmente registros usando indicadores.  
  
```  
BOOL CanBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros oferece suporte a indicadores, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver usando conjuntos de registros baseados inteiramente em tabelas do mecanismo de banco de dados Microsoft Jet, indicadores podem ser usados exceto em conjuntos de registros do tipo instantâneo sinalizados como conjuntos de registros rolagem somente de encaminhamento. Outros produtos de banco de dados (fontes de dados ODBC externas) podem não oferecer suporte a indicadores.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade possíveis de indicação" na Ajuda do DAO.  
  
##  <a name="a-namecancelupdatea--cdaorecordsetcancelupdate"></a><a name="cancelupdate"></a>CDaoRecordset::CancelUpdate  
 O `CancelUpdate` função de membro cancela todas as atualizações pendentes devido a um [editar](#edit) ou [AddNew](#addnew) operação.  
  
```  
virtual void CancelUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se um aplicativo chamar o **editar** ou `AddNew` função de membro e não chamado [atualização](#update), `CancelUpdate` cancela todas as alterações feitas depois **editar** ou `AddNew` foi chamado.  
  
> [!NOTE]
>  Se os registros são armazenados em buffer duplo (ou seja, verificação de campo automática é habilitada), chamar `CancelUpdate` irá restaurar as variáveis de membro para os valores que tinham antes `AddNew` ou **editar** foi chamado.  
  
 Se não houver nenhum **editar** ou `AddNew` operação pendente, `CancelUpdate` faz com que o MFC lançar uma exceção. Chamar o [GetEditMode](#geteditmode) a função de membro para determinar se há uma operação pendente que pode ser cancelada.  
  
 Para obter informações relacionadas, consulte o tópico "Método CancelUpdate" na Ajuda do DAO.  
  
##  <a name="a-namecanrestarta--cdaorecordsetcanrestart"></a><a name="canrestart"></a>CDaoRecordset::CanRestart  
 Chame essa função de membro para determinar se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) chamando o **Requery** função de membro.  
  
```  
BOOL CanRestart();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se **Requery** pode ser chamado para executar consulta do conjunto de registros novamente, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Não oferecem suporte a conjuntos de registros do tipo de tabela **Requery**.  
  
 Se **Requery** não é suportado, chame [fechar](#close) , em seguida, [abrir](#open) para atualizar os dados. Você pode chamar **Requery** atualizar um objeto recordset subjacente do consulta parâmetro depois que os valores de parâmetro foram alterados.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade reinicializável" na Ajuda do DAO.  
  
##  <a name="a-namecanscrolla--cdaorecordsetcanscroll"></a><a name="canscroll"></a>CDaoRecordset::CanScroll  
 Chame essa função de membro para determinar se o conjunto de registros permite rolagem.  
  
```  
BOOL CanScroll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se você pode percorrer os registros, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você chamar [abrir](#open) com **dbForwardOnly**, o conjunto de registros só pode rolar para frente.  
  
 Para obter informações relacionadas, consulte o tópico "Posicionando o atual registro ponteiro com DAO" na Ajuda do DAO.  
  
##  <a name="a-namecantransacta--cdaorecordsetcantransact"></a><a name="cantransact"></a>CDaoRecordset::CanTransact  
 Chame essa função de membro para determinar se o conjunto de registros permite que as transações.  
  
```  
BOOL CanTransact();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte de dados subjacente oferece suporte a transações, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade Transactions" na Ajuda do DAO.  
  
##  <a name="a-namecanupdatea--cdaorecordsetcanupdate"></a><a name="canupdate"></a>CDaoRecordset::CanUpdate  
 Chame essa função de membro para determinar se o conjunto de registros pode ser atualizado.  
  
```  
BOOL CanUpdate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros pode ser atualizado (Adicionar, atualizar e excluir registros), caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um conjunto de registros pode ser somente leitura se a fonte de dados é somente leitura ou se você especificou **dbReadOnly** para `nOptions` quando você chamou [abrir](#open) do conjunto de registros.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="a-namecdaorecordseta--cdaorecordsetcdaorecordset"></a><a name="cdaorecordset"></a>CDaoRecordset::CDaoRecordset  
 Constrói um objeto `CDaoRecordset`.  
  
```  
CDaoRecordset(CDaoDatabase* pDatabase = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDatabase`  
 Contém um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto ou o valor **nulo**. Se não **nulo** e `CDaoDatabase` do objeto **abrir** a função de membro não foi chamada para conectar-se à fonte de dados, o conjunto de registros tenta abri-lo para você durante a sua própria [abrir](#open) chamar. Se você passar **nulo**, um `CDaoDatabase` objeto é construído e conectado usando as informações da fonte de dados especificado se você derivado sua classe de conjunto de registros da `CDaoRecordset`.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar `CDaoRecordset` diretamente ou derivar uma classe específica do aplicativo de `CDaoRecordset`. Você pode usar ClassWizard para derivar classes seu conjunto de registros.  
  
> [!NOTE]
>  Se você derivar um `CDaoRecordset` classe derivada classe deve fornecer seu próprio construtor. No construtor da sua classe derivada, chame o construtor `CDaoRecordset::CDaoRecordset`, passando os parâmetros apropriados ao longo para ele.  
  
 Passar **nulo** para seu construtor de conjunto de registros para ter uma `CDaoDatabase` objeto construído e conectado automaticamente para você. Esse é um atalho útil que não exige que você criar e conectar-se um `CDaoDatabase` objeto antes de construir o conjunto de registros. Se o `CDaoDatabase` objeto não estiver aberto, uma [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) objeto também será criado para você que usa o espaço de trabalho padrão. Para obter mais informações, consulte [CDaoDatabase::CDaoDatabase](../../mfc/reference/cdaodatabase-class.md#cdaodatabase).  
  
##  <a name="a-nameclosea--cdaorecordsetclose"></a><a name="close"></a>CDaoRecordset::Close  
 Fechando uma `CDaoRecordset` objeto remove da coleção de conjuntos de registros abertos no banco de dados associado.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Porque **fechar** não destrói o `CDaoRecordset` do objeto, você pode reutilizar o objeto chamando **abrir** na mesma fonte de dados ou outra fonte de dados.  
  
 Todas as pendentes [AddNew](#addnew) ou [editar](#edit) instruções são canceladas e todas as transações pendentes serão revertidas. Se você quiser preservar as adições ou edições pendentes, chame [atualização](#update) antes de chamar **fechar** para cada conjunto de registros.  
  
 Você pode chamar **abrir** novamente depois de chamar **fechar**. Isso lhe permite reutilizar o objeto recordset. Uma alternativa melhor é chamar [Requery](#requery), se possível.  
  
 Para obter informações relacionadas, consulte o tópico "Método Close" na Ajuda do DAO.  
  
##  <a name="a-namedeletea--cdaorecordsetdelete"></a><a name="delete"></a>CDaoRecordset::Delete  
 Chame essa função de membro para excluir o registro atual em um objeto recordset tipo dynaset ou tipo de tabela.  
  
```  
virtual void Delete();
```  
  
### <a name="remarks"></a>Comentários  
 Após a exclusão bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor nulo, e você deve chamar explicitamente uma das funções de membro de navegação do conjunto de registros ( [mover](#move), [busca](#seek), [SetBookmark](#setbookmark), e assim por diante) para deixar o registro excluído. Quando você exclui registros de um conjunto de registros, deve haver um registro atual no conjunto de registros antes de chamar **excluir**; caso contrário, MFC lança uma exceção.  
  
 **Excluir** remove o registro atual e a torna inacessível. Embora você não pode editar ou usar o registro excluído, ele permanece atual. Quando você move para outro registro, no entanto, você não pode fazer o registro excluído atual novamente.  
  
> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve haver um registro válido atual no conjunto de registros ao chamar **excluir**. Por exemplo, se você excluir um registro, mas não rolam para um novo registro antes de chamar **excluir** novamente, **excluir** lança um [CDaoException](../../mfc/reference/cdaoexception-class.md).  
  
 Você pode cancelar a exclusão um registro se você usar transações e você chamar o [CDaoWorkspace::Rollback](../../mfc/reference/cdaoworkspace-class.md#rollback) função de membro. Se a tabela base é a tabela primária em cascata Excluir relação, excluir o registro atual também pode excluir um ou mais registros em uma tabela externa. Para obter mais informações, consulte definição "cascata" excluir na Ajuda do DAO.  
  
 Ao contrário de `AddNew` e **editar**, uma chamada para **excluir** não é seguido por uma chamada para **atualização**.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="a-namedofieldexchangea--cdaorecordsetdofieldexchange"></a><a name="dofieldexchange"></a>CDaoRecordset::DoFieldExchange  
 O framework chama essa função de membro para automaticamente trocar dados entre os membros de dados de campo do objeto recordset e as colunas correspondentes do registro atual na fonte de dados.  
  
```  
virtual void DoFieldExchange(CDaoFieldExchange* pFX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFX`  
 Contém um ponteiro para um `CDaoFieldExchange` objeto. A estrutura será já configurou esse objeto para especificar um contexto para a operação de troca de campo.  
  
### <a name="remarks"></a>Comentários  
 Ele também associa os membros de dados de parâmetro, se houver, aos espaços reservados de parâmetros na cadeia de caracteres de instrução SQL para a seleção do conjunto de registros. A troca de dados de campo, chamados de troca de campos de registro DAO (DFX) funciona em ambas as direções: de membros de dados de campo do objeto recordset para os campos do registro na fonte de dados e de registro na fonte de dados para o objeto recordset. Se você estiver associando colunas dinamicamente, não é necessário para implementar `DoFieldExchange`.  
  
 A única ação que você normalmente deve realizar para implementar `DoFieldExchange` para registros derivado classe é criar a classe com ClassWizard e especifique os nomes e tipos de dados dos membros de dados de campo. Você também pode adicionar código para o que ClassWizard grava para especificar os membros de dados de parâmetro. Se todos os campos são vinculados dinamicamente, essa função ficará inativa, a menos que você especifique os membros de dados de parâmetro.  
  
 Quando você declarar sua classe derivada do conjunto de registros com ClassWizard, o assistente grava uma substituição de `DoFieldExchange` , que se parece com o exemplo a seguir:  
  
 [!code-cpp[NVC_MFCDatabase n º&2;](../../mfc/codesnippet/cpp/cdaorecordset-class_2.cpp)]  
  
##  <a name="a-nameedita--cdaorecordsetedit"></a><a name="edit"></a>CDaoRecordset::Edit  
 Chame essa função de membro para permitir que as alterações no registro atual.  
  
```  
virtual void Edit();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar o **editar** função de membro, as alterações feitas nos campos do registro atual são copiados para o buffer de cópia. Depois de fazer as alterações desejadas no registro, chamar **atualização** para salvar suas alterações. **Editar** salva os valores dos membros de dados do conjunto de registros. Se você chamar **editar**, fazer alterações, em seguida, chame **editar** novamente, os valores do registro são restaurados para o que eram antes da primeira **editar** chamar.  
  
> [!CAUTION]
>  Se você editar um registro e, em seguida, executar qualquer operação que se move para outro registro sem primeiro chamar **atualização**, suas alterações serão perdidas sem aviso. Além disso, se você fechar o conjunto de registros ou banco de dados, seu registro editado será descartado sem aviso.  
  
 Em alguns casos, convém atualizar uma coluna, tornando Null (não contendo a nenhum dado). Para fazer isso, chame `SetFieldNull` com um parâmetro de **TRUE** para marcar o campo nulo; isso também faz com que a coluna a ser atualizada. Se você quiser um campo para ser gravado para a fonte de dados, embora seu valor não mudou, chame `SetFieldDirty` com um parâmetro de **TRUE**. Isso funciona mesmo se o campo tiver o valor Null.  
  
 As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, portanto você raramente precisa chamar [SetFieldDirty](#setfielddirty) por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor no membro de dados do campo. O mecanismo DFX emprega o uso de **PSEUDO nulo**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como suja. Nesse caso, será necessário definir explicitamente o campo sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação de campo automáticas.  
  
 Quando o objeto recordset pessimistically está bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado da hora **editar** é usado até que a atualização for concluída. Se o conjunto de registros suporá estiver bloqueado, o registro está bloqueado e comparado com o registro anterior à edição antes que ele seja atualizado no banco de dados. Se o registro foi alterado desde que você chamou **editar**, o **atualização** Falha na operação e MFC lança uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.  
  
> [!NOTE]
>  Bloqueio otimista é sempre usado em formatos de banco de dados externo, como ODBC e ISAM instalável.  
  
 O registro atual permanece atual depois de você chamar **editar**. Para chamar **editar**, deve haver um registro atual. Se não houver nenhum registro atual ou se o conjunto de registros não faz referência a um tipo de tabela aberto ou objeto recordset tipo dynaset, ocorre uma exceção. Chamando **editar** faz com que um `CDaoException` seja lançada sob as seguintes condições:  
  
-   Não há nenhum registro atual.  
  
-   O banco de dados ou conjunto de registros é somente leitura.  
  
-   Não há campos no registro são atualizáveis.  
  
-   O conjunto de registros ou banco de dados foi aberto para uso exclusivo por outro usuário.  
  
-   Outro usuário bloqueou a página que contém o registro.  
  
 Se a fonte de dados oferece suporte a transações, você pode fazer o **editar** chamar parte de uma transação. Observe que você deve chamar `CDaoWorkspace::BeginTrans` antes de chamar **editar** e depois o conjunto de registros tiver sido aberto. Observe também que a chamada `CDaoWorkspace::CommitTrans` não é um substituto para chamar **atualização** para concluir o **editar** operação. Para obter mais informações sobre transações, consulte a classe `CDaoWorkspace`.  
  
 Para obter informações relacionadas, consulte os tópicos "Método AddNew", "Editar método", "Método Delete", "Método de atualização" e "Propriedade atualizável" na Ajuda do DAO.  
  
##  <a name="a-namefillcachea--cdaorecordsetfillcache"></a><a name="fillcache"></a>CDaoRecordset::FillCache  
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
 A [COleVariant](../../mfc/reference/colevariant-class.md) especificando um indicador. O cache está preenchido a partir do registro indicado por esse indicador. Se você omitir esse parâmetro, o cache está preenchido a partir do registro indicado pela propriedade CacheStart do objeto DAO subjacente.  
  
### <a name="remarks"></a>Comentários  
 O cache melhora o desempenho de um aplicativo que recupera ou busca, dados de um servidor remoto. Um cache é um espaço na memória local que mantém os dados buscados mais recentemente do servidor na suposição de que os dados serão provavelmente solicitados novamente enquanto o aplicativo é executado. Quando os dados são solicitados, o mecanismo de banco de dados Microsoft Jet primeiro verifica o cache para os dados em vez de buscá-la do servidor, o que leva mais tempo. Usar dados em cache em fontes de dados ODBC não tem nenhum efeito como os dados não são salvos no cache.  
  
 Em vez de aguardar até que o cache seja preenchido com registros conforme eles são encontrados, você pode preencher o cache explicitamente a qualquer momento chamando o `FillCache` função de membro. Essa é uma maneira mais rápida de preencher o cache porque `FillCache` busca vários registros de uma só vez, em vez de um de cada vez. Por exemplo, enquanto cada tela cheia de registros está sendo exibida, você pode ter sua chamada de aplicativo `FillCache` para buscar a próxima tela cheia de registros.  
  
 Qualquer banco de dados ODBC acessado com objetos de conjunto de registros pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remota e, em seguida, chame o `SetCacheSize` e `SetCacheStart` funções de membro do conjunto de registros. Se `lSize` e *lBookmark* criar um intervalo que seja totalmente ou parcialmente fora do intervalo especificado por `SetCacheSize` e `SetCacheStart`, parte do conjunto de registros fora desse intervalo é ignorada e não é carregado no cache. Se `FillCache` solicita mais registros que permanecem na fonte de dados remota, somente os registros restantes são buscados e nenhuma exceção é lançada.  
  
 Registros encontrados do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.  
  
 `FillCache`busca somente os registros que não esteja armazenado em cache. Para forçar uma atualização de todos os dados armazenados em cache, chame o `SetCacheSize` a função de membro com um `lSize` parâmetro igual a 0, chamada `SetCacheSize` novamente com o `lSize` parâmetro igual ao tamanho do cache originalmente solicitada e em seguida, chame `FillCache`.  
  
 Para obter informações relacionadas, consulte o tópico "FillCache método" na Ajuda do DAO.  
  
##  <a name="a-namefinda--cdaorecordsetfind"></a><a name="find"></a>CDaoRecordset::Find  
 Chame essa função de membro para localizar uma cadeia de caracteres específica em um conjunto de registros do tipo dynaset ou snapshot usando um operador de comparação.  
  
```  
virtual BOOL Find(
    long lFindType,  
    LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lFindType*  
 Um valor que indica o tipo de operação de localização desejado. Os valores possíveis são:  
  
- **AFX_DAO_NEXT** localizar o próximo local de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_PREV** encontrar o local anterior de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_FIRST** localizar o primeiro local de uma cadeia de caracteres correspondente.  
  
- **AFX_DAO_LAST** localizar o último local de uma cadeia de caracteres correspondente.  
  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro. Por exemplo:  
  
 [!code-cpp[NVC_MFCDatabase n º&3;](../../mfc/codesnippet/cpp/cdaorecordset-class_3.cpp)]  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode encontrar o primeiro, próximo, anterior, ou a última ocorrência da cadeia de caracteres. **Localizar** é uma função virtual, você pode substituí-lo e adicionar sua própria implementação. O `FindFirst`, `FindLast`, `FindNext`, e `FindPrev` chamada de funções de membro de **localizar** função de membro, portanto, você pode usar **localizar** para controlar o comportamento de todas as operações de localização.  
  
 Para localizar um registro em um conjunto de registros do tipo de tabela, chame o [busca](#seek) função de membro.  
  
> [!TIP]
>  Quanto menor o conjunto de registros tiver, mais eficaz **localizar** será. Em geral e especialmente com dados ODBC, é melhor criar uma nova consulta que recupera apenas os registros que deseja.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namefindfirsta--cdaorecordsetfindfirst"></a><a name="findfirst"></a>CDaoRecordset::FindFirst  
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
 O `FindFirst` começa a função de membro pesquisas ao final do conjunto de registros e a pesquisa do início do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro que correspondem aos critérios não for localizado, o ponteiro do registro atual é indeterminado, e `FindFirst` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios, `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função de membro antes de passar para outro registro. Se você mover para um outro registro sem atualizar, as alterações serão perdidas sem aviso.  
  
 O **localizar** funções de membro de pesquisa do local e na direção especificada na tabela a seguir:  
  
|As operações de localização|Começar|Direção da pesquisa|  
|---------------------|-----------|----------------------|  
|`FindFirst`|Início do conjunto de registros|Fim do conjunto de registros|  
|`FindLast`|Fim do conjunto de registros|Início do conjunto de registros|  
|`FindNext`|Registro atual|Fim do conjunto de registros|  
|**FindPrevious**|Registro atual|Início do conjunto de registros|  
  
> [!NOTE]
>  Quando você chama `FindLast`, o mecanismo de banco de dados Microsoft Jet totalmente preenche o conjunto de registros antes de iniciar a pesquisa, se isso já não foi feito. A primeira pesquisa pode demorar mais que pesquisas subsequentes.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, entretanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha o seguinte em mente ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando procurar registros que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes podem não ser encontrado.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grande, você pode descobrir que usar as operações de localização é lento, especialmente ao se trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou **CDaoQuerydef** objetos que recuperam registros específicos indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namefindlasta--cdaorecordsetfindlast"></a><a name="findlast"></a>CDaoRecordset::FindLast  
 Chame essa função de membro para localizar o último registro que corresponde a uma condição especificada.  
  
```  
BOOL FindLast(LPCTSTR lpszFilter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilter`  
 Uma expressão de cadeia de caracteres (como o **onde** cláusula em uma instrução SQL sem a palavra **onde**) usado para localizar o registro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `FindLast` função de membro começa a pesquisa no final do conjunto de registros e pesquisas com versões anteriores em direção ao início do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro que correspondem aos critérios não for localizado, o ponteiro do registro atual é indeterminado, e `FindLast` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios, `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência após a primeira ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função de membro antes de passar para outro registro. Se você mover para um outro registro sem atualizar, as alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, entretanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha o seguinte em mente ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando procurar registros que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes podem não ser encontrado.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grande, você pode descobrir que usar as operações de localização é lento, especialmente ao se trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou **CDaoQuerydef** objetos que recuperam registros específicos indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namefindnexta--cdaorecordsetfindnext"></a><a name="findnext"></a>CDaoRecordset::FindNext  
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
 O `FindNext` função de membro começa sua pesquisa no registro atual e pesquisa no final do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro que correspondem aos critérios não for localizado, o ponteiro do registro atual é indeterminado, e `FindNext` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios, `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função de membro antes de passar para outro registro. Se você mover para um outro registro sem atualizar, as alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, entretanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha o seguinte em mente ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando procurar registros que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes podem não ser encontrado.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grande, você pode descobrir que usar as operações de localização é lento, especialmente ao se trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou **CDaoQuerydef** objetos que recuperam registros específicos indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namefindpreva--cdaorecordsetfindprev"></a><a name="findprev"></a>CDaoRecordset::FindPrev  
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
 O `FindPrev` função de membro começa a pesquisa no registro atual e procurará em direção ao início do conjunto de registros.  
  
 Se você deseja incluir todos os registros na pesquisa (não apenas aqueles que atendem a uma condição específica) usam uma das operações de movimentação para mover de um registro para outro. Para localizar um registro em um conjunto de registros do tipo de tabela, chame o `Seek` função de membro.  
  
 Se um registro que correspondem aos critérios não for localizado, o ponteiro do registro atual é indeterminado, e `FindPrev` retorna zero. Se o conjunto de registros contém mais de um registro que satisfaça os critérios, `FindFirst` localiza a primeira ocorrência, `FindNext` localiza a próxima ocorrência e assim por diante.  
  
> [!CAUTION]
>  Se você editar o registro atual, certifique-se de salvar as alterações ao chamar o **atualização** função de membro antes de passar para outro registro. Se você mover para um outro registro sem atualizar, as alterações serão perdidas sem aviso.  
  
 Usar uma das operações de localização não é o mesmo que chamar **MoveFirst** ou `MoveNext`, entretanto, que simplesmente torna o primeiro ou próximo registro atual sem especificar uma condição. Você pode executar uma operação de localização com uma operação de movimentação.  
  
 Tenha o seguinte em mente ao usar as operações de localização:  
  
-   Se **localizar** retorna diferente de zero, o registro atual não está definido. Nesse caso, você deve posicionar o ponteiro do registro atual para um registro válido.  
  
-   Você não pode usar uma operação de localização com um recordset do tipo snapshot rolagem somente de encaminhamento.  
  
-   Você deve usar o formato de data dos EUA (mês-dia-ano) quando procurar registros que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, registros correspondentes podem não ser encontrado.  
  
-   Ao trabalhar com bancos de dados ODBC e dynasets grande, você pode descobrir que usar as operações de localização é lento, especialmente ao se trabalhar com grandes conjuntos de registros. Você pode melhorar o desempenho usando consultas SQL com personalizado **ORDERBY** ou **onde** cláusulas, consultas de parâmetro, ou **CDaoQuerydef** objetos que recuperam registros específicos indexados.  
  
 Para obter informações relacionadas, consulte o tópico "FindFirst, FindLast, FindNext e FindPrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namegetabsolutepositiona--cdaorecordsetgetabsoluteposition"></a><a name="getabsoluteposition"></a>CDaoRecordset::GetAbsolutePosition  
 Retorna o número do registro atual de um objeto conjunto de registros.  
  
```  
long GetAbsolutePosition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro de 0 ao número de registros no conjunto de registros. Corresponde à posição ordinal do registro atual no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseada em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Você pode determinar o número de registros preenchidos no conjunto de registros chamando [GetRecordCount](#getrecordcount). Chamando `GetRecordCount` pode levar algum tempo, porque ele deve acessar todos os registros para determinar a contagem.  
  
 Se há um registro atual, como quando não há nenhum registro no conjunto de registros – 1 é retornado. Se o registro atual for excluído, o valor da propriedade AbsolutePosition não está definido, e MFC lança uma exceção se ela é referenciada. Para conjuntos de registros do tipo dynaset, novos registros são adicionados ao final da sequência.  
  
> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro alternativo. Indicadores ainda são a maneira recomendada de reter e retornar para uma determinada posição e são a única forma de posicionar o registro atual em todos os tipos de objetos de conjunto de registros. Em particular, a posição de um determinado registro muda quando o registro anterior é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado porque a ordem de registros individuais em um conjunto de registros não é garantida, a menos que ela é criada com uma instrução SQL usando um **ORDERBY** cláusula.  
  
> [!NOTE]
>  Essa função de membro é válida somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.  
  
##  <a name="a-namegetbookmarka--cdaorecordsetgetbookmark"></a><a name="getbookmark"></a>CDaoRecordset::GetBookmark  
 Chame essa função de membro para obter o valor do indicador em um registro específico.  
  
```  
COleVariant GetBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que representa o indicador do registro atual.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto recordset é criado ou aberto, cada um de seus registros já possui um indicador exclusivo se ele dá suporte a ele. Chamar `CanBookmark` para determinar se um conjunto de registros oferece suporte a indicadores.  
  
 Você pode salvar o indicador do registro atual atribuindo o valor do indicador a um `COleVariant` objeto. Para retornar rapidamente a esse registro a qualquer momento depois de mover para um registro diferente, chamar `SetBookmark` com um parâmetro que corresponde ao valor do `COleVariant` objeto.  
  
> [!NOTE]
>  Chamando [Requery](#requery) altera marcadores do DAO.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Bookmark" na Ajuda do DAO.  
  
##  <a name="a-namegetcachesizea--cdaorecordsetgetcachesize"></a><a name="getcachesize"></a>CDaoRecordset::GetCacheSize  
 Chame essa função de membro para obter o número de registros armazenado em cache.  
  
```  
long GetCacheSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica o número de registros em um conjunto de registros do tipo dynaset que contém os dados sejam armazenados em cache localmente de uma fonte de dados ODBC.  
  
### <a name="remarks"></a>Comentários  
 Cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Um cache é um espaço na memória local que mantém os dados recuperados mais recentemente do servidor que os dados serem solicitados novamente enquanto o aplicativo é executado. Quando os dados são solicitados, o mecanismo de banco de dados Microsoft Jet primeiro verifica o cache para os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não seja proveniente de uma fonte de dados ODBC não são salvos no cache.  
  
 Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local.  
  
 Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.  
  
##  <a name="a-namegetcachestarta--cdaorecordsetgetcachestart"></a><a name="getcachestart"></a>CDaoRecordset::GetCacheStart  
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
  
##  <a name="a-namegetcurrentindexa--cdaorecordsetgetcurrentindex"></a><a name="getcurrentindex"></a>CDaoRecordset::GetCurrentIndex  
 Chame essa função de membro para determinar o índice atualmente em uso em um tipo de tabela indexado `CDaoRecordset` objeto.  
  
```  
CString GetCurrentIndex();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o nome do índice atualmente em uso com um conjunto de registros do tipo de tabela. Retorna uma cadeia de caracteres vazia se nenhum índice foi definido.  
  
### <a name="remarks"></a>Comentários  
 Este índice é a base para ordenar registros em um conjunto de registros do tipo de tabela e é usado pelo [busca](#seek) função de membro para localizar registros.  
  
 A `CDaoRecordset` objeto pode ter mais de um índice, mas pode usar apenas um índice por vez (embora um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto pode ter vários índices definidos).  
  
 Para obter informações relacionadas, consulte o tópico "Índice Object" e a definição de "índice atual" na Ajuda do DAO.  
  
##  <a name="a-namegetdatecreateda--cdaorecordsetgetdatecreated"></a><a name="getdatecreated"></a>CDaoRecordset::GetDateCreated  
 Chame essa função de membro para recuperar a data e hora de que criação de uma tabela base.  
  
```  
COleDateTime GetDateCreated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora de criação da tabela base.  
  
### <a name="remarks"></a>Comentários  
 Configurações de data e hora são derivadas do computador no qual a tabela base foi criada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="a-namegetdatelastupdateda--cdaorecordsetgetdatelastupdated"></a><a name="getdatelastupdated"></a>CDaoRecordset::GetDateLastUpdated  
 Chame essa função de membro para recuperar a data e hora que da última atualização do esquema.  
  
```  
COleDateTime GetDateLastUpdated();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a data e hora da última atualização a estrutura da tabela base (esquema).  
  
### <a name="remarks"></a>Comentários  
 Configurações de data e hora são derivadas do computador no qual a estrutura da tabela base (esquema) foi atualizada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades DateCreated e LastUpdated" na Ajuda do DAO.  
  
##  <a name="a-namegetdefaultdbnamea--cdaorecordsetgetdefaultdbname"></a><a name="getdefaultdbname"></a>CDaoRecordset::GetDefaultDBName  
 Chame essa função de membro para determinar o nome do banco de dados para este conjunto de registros.  
  
```  
virtual CString GetDefaultDBName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o caminho e o nome do banco de dados do qual este conjunto de registros é derivado.  
  
### <a name="remarks"></a>Comentários  
 Se um conjunto de registros é criado sem um ponteiro para um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md), em seguida, esse caminho é usado pelo conjunto de registros para abrir o banco de dados padrão. Por padrão, essa função retorna uma cadeia de caracteres vazia. Quando ClassWizard deriva um novo conjunto de registros de `CDaoRecordset`, ele criará essa função para você.  
  
 O exemplo a seguir ilustra o uso de uma barra invertida dupla (\\\\) na cadeia de caracteres, como é necessário para a cadeia de caracteres devem ser interpretados corretamente.  
  
 [!code-cpp[NVC_MFCDatabase n º&4;](../../mfc/codesnippet/cpp/cdaorecordset-class_4.cpp)]  
  
##  <a name="a-namegetdefaultsqla--cdaorecordsetgetdefaultsql"></a><a name="getdefaultsql"></a>CDaoRecordset::GetDefaultSQL  
 O framework chama essa função de membro para obter a instrução SQL padrão no qual o conjunto de registros se baseia.  
  
```  
virtual CString GetDefaultSQL();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém a instrução SQL padrão.  
  
### <a name="remarks"></a>Comentários  
 Isso pode ser um nome de tabela ou um SQL **selecione** instrução.  
  
 Você definir indiretamente a instrução SQL padrão, declarando sua classe de conjunto de registros com ClassWizard e ClassWizard realiza essa tarefa para você.  
  
 Se você passar uma cadeia de caracteres SQL nula para [abrir](#open), em seguida, essa função é chamada para determinar o nome da tabela ou o SQL para o conjunto de registros.  
  
##  <a name="a-namegeteditmodea--cdaorecordsetgeteditmode"></a><a name="geteditmode"></a>CDaoRecordset::GetEditMode  
 Chame essa função de membro para determinar o estado de edição, que é um dos seguintes valores:  
  
```  
short GetEditMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor que indica o estado de edição do registro atual.  
  
### <a name="remarks"></a>Comentários  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**dbEditNone**|Nenhuma operação de edição está em andamento.|  
|**dbEditInProgress**|**Editar** foi chamado.|  
|**dbEditAdd**|`AddNew`foi chamado.|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="a-namegetfieldcounta--cdaorecordsetgetfieldcount"></a><a name="getfieldcount"></a>CDaoRecordset::GetFieldCount  
 Chame essa função de membro para recuperar o número de campos (colunas) definidos no conjunto de registros.  
  
```  
short GetFieldCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de campos no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade Count" na Ajuda do DAO.  
  
##  <a name="a-namegetfieldinfoa--cdaorecordsetgetfieldinfo"></a><a name="getfieldinfo"></a>CDaoRecordset::GetFieldInfo  
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
 O índice baseado em zero do campo predefinido na coleção de campos do conjunto de registros, para a pesquisa por índice.  
  
 `fieldinfo`  
 Uma referência a um [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o conjunto de registros a recuperar. As opções disponíveis são listadas aqui, junto com o que elas causam a função retornar. Para melhor desempenho, recupere apenas o nível de informações que você precisa:  
  
- `AFX_DAO_PRIMARY_INFO`(Padrão) Nome, tipo, tamanho, atributos  
  
- `AFX_DAO_SECONDARY_INFO`Informações principais, além de: posição Ordinal, necessária, permitir Zero tabela de origem externa nome, o campo de origem, comprimento, ordem de agrupamento  
  
- `AFX_DAO_ALL_INFO`Informações principais e secundárias, além de: valor padrão, a regra de validação, texto de validação  
  
 `lpszName`  
 O nome do campo.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um campo por índice. A outra versão permite pesquisar um campo por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas na descrição do `dwInfoOptions`. Quando você solicitar informações em um nível, você obtém informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
##  <a name="a-namegetfieldvaluea--cdaorecordsetgetfieldvalue"></a><a name="getfieldvalue"></a>CDaoRecordset::GetFieldValue  
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
 Uma referência a um `COleVariant` objeto que irá armazenar o valor de um campo.  
  
 `nIndex`  
 Um índice baseado em zero do campo na coleção de campos do conjunto de registros, para a pesquisa por índice.  
  
### <a name="return-value"></a>Valor de retorno  
 As duas versões do `GetFieldValue` retornam um valor de retorno um [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor de um campo.  
  
### <a name="remarks"></a>Comentários  
 Você pode pesquisar um campo por nome ou posição ordinal.  
  
> [!NOTE]
>  É mais eficiente para chamada de uma das versões dessa função de membro que leva um `COleVariant` referência de objeto como um parâmetro, em vez de chamar uma versão que retorna um `COleVariant` objeto. As versões mais recentes dessa função são mantidas para compatibilidade com versões anteriores.  
  
 Use `GetFieldValue` e [SetFieldValue](#setfieldvalue) para vincular campos dinamicamente no tempo de execução em vez de estaticamente colunas de associação usando o [DoFieldExchange](#dofieldexchange) mecanismo.  
  
 `GetFieldValue`e o `DoFieldExchange` mecanismo pode ser combinado para melhorar o desempenho. Por exemplo, use `GetFieldValue` para recuperar um valor que você precisa apenas sob demanda e atribuir essa chamada a um botão "Mais informações" na interface.  
  
 Para obter informações relacionadas, consulte os tópicos "Campo Object" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="a-namegetindexcounta--cdaorecordsetgetindexcount"></a><a name="getindexcount"></a>CDaoRecordset::GetIndexCount  
 Chame essa função de membro para determinar o número de índices disponíveis no conjunto de registros do tipo de tabela.  
  
```  
short GetIndexCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de índices no conjunto de registros do tipo de tabela.  
  
### <a name="remarks"></a>Comentários  
 `GetIndexCount`é útil para percorrer todos os índices no conjunto de registros. Para essa finalidade, use `GetIndexCount` em conjunto com [GetIndexInfo](#getindexinfo). Se você chamar essa função membro no tipo dynaset ou conjunto de registros do tipo de instantâneo, o MFC lança uma exceção.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
##  <a name="a-namegetindexinfoa--cdaorecordsetgetindexinfo"></a><a name="getindexinfo"></a>CDaoRecordset::GetIndexInfo  
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
 O índice baseado em zero na coleção de índices da tabela, para pesquisa por posição numérica.  
  
 `indexinfo`  
 Uma referência a um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura.  
  
 `dwInfoOptions`  
 Opções que especificam quais informações sobre o índice a recuperar. As opções disponíveis são listadas aqui, junto com o que elas causam a função retornar. Para melhor desempenho, recupere apenas o nível de informações que você precisa:  
  
- `AFX_DAO_PRIMARY_INFO`(Padrão) Campos de nome, informações de campo  
  
- `AFX_DAO_SECONDARY_INFO`Informações principais, além de: primário, Unique, Clustered, ignorar, necessária, externo  
  
- `AFX_DAO_ALL_INFO`Informações principais e secundárias, além de: contagem distinta  
  
 `lpszName`  
 Um ponteiro para o nome do objeto index, para a pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 Uma versão da função permite pesquisar um índice por sua posição na coleção. A outra versão permite pesquisar um índice por nome.  
  
 Para obter uma descrição das informações retornadas, consulte o [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) estrutura. Essa estrutura tem membros que correspondem aos itens de informações listadas na descrição do `dwInfoOptions`. Quando você solicitar informações em um nível, você obtém informações de todos os níveis anteriores também.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade atributos" na Ajuda do DAO.  
  
##  <a name="a-namegetlastmodifiedbookmarka--cdaorecordsetgetlastmodifiedbookmark"></a><a name="getlastmodifiedbookmark"></a>CDaoRecordset::GetLastModifiedBookmark  
 Chame essa função de membro para recuperar o indicador do registro mais recentemente adicionado ou atualizado.  
  
```  
COleVariant GetLastModifiedBookmark();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COleVariant` contendo um indicador que indica mais recentemente adicionado ou alterado o registro.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto recordset é criado ou aberto, cada um de seus registros já possui um indicador exclusivo se ele dá suporte a ele. Chamar [GetBookmark](#getbookmark) para determinar se o conjunto de registros oferece suporte a indicadores. Se o conjunto de registros não oferece suporte a indicadores, um `CDaoException` é lançada.  
  
 Quando você adicionar um registro, ele aparece no final do conjunto de registros e não é o registro atual. Para criar o novo registro atual, chame `GetLastModifiedBookmark` e, em seguida, chame `SetBookmark` para retornar para o registro recém-adicionada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade LastModified" na Ajuda do DAO.  
  
##  <a name="a-namegetlockingmodea--cdaorecordsetgetlockingmode"></a><a name="getlockingmode"></a>CDaoRecordset::GetLockingMode  
 Chame essa função de membro para determinar o tipo de bloqueio em vigor para o conjunto de registros.  
  
```  
BOOL GetLockingMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o tipo de bloqueio pessimista, caso contrário, 0 para bloqueio de registro otimista.  
  
### <a name="remarks"></a>Comentários  
 Quando o bloqueio pessimista está em vigor, a página de dados que contém o registro que você está editando é bloqueada assim que você chamar o [editar](#edit) função de membro. A página é desbloqueada quando você chama o [atualização](#update) ou [fechar](#close) função de membro ou qualquer uma das operações de mover ou localizar.  
  
 Quando otimista proteção está em vigor, a página de dados que contém o registro está bloqueada somente enquanto o registro estiver sendo atualizado com o **atualização** função de membro.  
  
 Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedade LockEdits" e "Comportamento de bloqueio no multiusuário aplicativos" na Ajuda do DAO.  
  
##  <a name="a-namegetnamea--cdaorecordsetgetname"></a><a name="getname"></a>CDaoRecordset::GetName  
 Chame essa função de membro para recuperar o nome do conjunto de registros.  
  
```  
CString GetName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém o nome do conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 O nome do conjunto de registros deve começar com uma letra e pode conter um máximo de 40 caracteres. Ele pode incluir números e caracteres de sublinhado, mas não pode incluir espaços ou pontuação.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
##  <a name="a-namegetparamvaluea--cdaorecordsetgetparamvalue"></a><a name="getparamvalue"></a>CDaoRecordset::GetParamValue  
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
  
 Para obter informações relacionadas, consulte o tópico "Objeto Parameter" na Ajuda do DAO.  
  
##  <a name="a-namegetpercentpositiona--cdaorecordsetgetpercentposition"></a><a name="getpercentposition"></a>CDaoRecordset::GetPercentPosition  
 Ao trabalhar com um tipo dynaset ou recordset tipo snapshot, se você chamar `GetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimento é em relação ao número de registros acessados conforme indicado chamando [GetRecordCount](#getrecordcount).  
  
```  
float GetPercentPosition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um número entre 0 e 100 que indica a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Você pode mover para o último registro chamando [MoveLast](#movelast) para concluir a população de todos os conjuntos de registros, mas isso pode levar uma quantidade significativa de tempo.  
  
 Você pode chamar `GetPercentPosition` em todos os três tipos de objetos de conjunto de registros, inclusive tabelas sem índices. No entanto, você não pode chamar `GetPercentPosition` em instantâneos de rolagem somente de encaminhamento ou em um conjunto de registros aberto a partir de uma consulta passagem em um banco de dados externo. Se há um registro atual ou registro atual foi excluído, um `CDaoException` é lançada.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.  
  
##  <a name="a-namegetrecordcounta--cdaorecordsetgetrecordcount"></a><a name="getrecordcount"></a>CDaoRecordset::GetRecordCount  
 Chame essa função de membro para descobrir o número de registros em um conjunto de registros foram acessado.  
  
```  
long GetRecordCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de registros acessados em um objeto recordset.  
  
### <a name="remarks"></a>Comentários  
 `GetRecordCount`não indica quantos registros estão contidos em um tipo dynaset ou recordset tipo snapshot até que todos os registros tenham sido acessados. Essa chamada de função de membro pode levar uma quantidade significativa de tempo para concluir.  
  
 Depois que o último registro tiver sido acessado, o valor de retorno indica o número total de registros de mensagem no conjunto de registros. Para forçar o último registro para ser acessado, chame o `MoveLast` ou `FindLast` a função de membro do conjunto de registros. Você também pode usar uma contagem de SQL para determinar o número aproximado de registros que a consulta retornará.  
  
 Como seu aplicativo exclui registros em um conjunto de registros do tipo dynaset, o valor de retorno `GetRecordCount` diminui. No entanto, os registros excluídos por outros usuários não serão refletidos por `GetRecordCount` até o registro atual está localizado em um registro excluído. Se você executar uma transação que afeta a contagem de registros e subsequentemente reverter a transação, `GetRecordCount` não refletirá o número real de registros restantes.  
  
 O valor de `GetRecordCount` de um conjunto de registros do tipo de instantâneo não é afetado por alterações nas tabelas base.  
  
 O valor de `GetRecordCount` de um tipo de tabela, o conjunto de registros reflete o número aproximado de registros na tabela e é afetado imediatamente como registros da tabela são adicionados e excluídos.  
  
 Um conjunto de registros sem registros retorna um valor de 0. Ao trabalhar com tabelas anexadas ou bancos de dados ODBC, `GetRecordCount` sempre retorna – 1. Chamando o **Requery** função de membro em um conjunto de registros redefine o valor de `GetRecordCount` como se a consulta fosse executada novamente.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade RecordCount" na Ajuda do DAO.  
  
##  <a name="a-namegetsqla--cdaorecordsetgetsql"></a><a name="getsql"></a>CDaoRecordset::GetSQL  
 Chame essa função de membro para obter a instrução SQL que foi usada para selecionar registros do conjunto de registros quando ele foi aberto.  
  
```  
CString GetSQL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` que contém a instrução SQL.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente será um SQL **selecione** instrução.  
  
 A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você pode ter passado para o conjunto de registros a `lpszSQL` parâmetro para o [abrir](#open) função de membro. Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no que é passado para **abrir**, que você especificou com ClassWizard e o que você pode ter especificado no [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) membros de dados.  
  
> [!NOTE]
>  Chame essa função de membro somente depois de chamar **abrir**.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade SQL" na Ajuda do DAO.  
  
##  <a name="a-namegettypea--cdaorecordsetgettype"></a><a name="gettype"></a>CDaoRecordset::GetType  
 Chame essa função de membro depois de abrir o conjunto de registros para determinar o tipo do objeto recordset.  
  
```  
short GetType();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores a seguir que indica o tipo de um conjunto de registros:  
  
- **dbOpenTable** conjunto de registros do tipo de tabela  
  
- **dbOpenDynaset** tipo Dynaset  
  
- **dbOpenSnapshot** recordset do tipo Snapshot  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
##  <a name="a-namegetvalidationrulea--cdaorecordsetgetvalidationrule"></a><a name="getvalidationrule"></a>CDaoRecordset::GetValidationRule  
 Chame essa função de membro para determinar a regra usada para validar dados.  
  
```  
CString GetValidationRule();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém um valor que valida os dados em um registro à medida que esses são alterados ou adicionado a uma tabela.  
  
### <a name="remarks"></a>Comentários  
 Essa regra é baseado em texto e é aplicada a cada vez que a tabela subjacente é alterada. Se os dados não forem válidos, o MFC lança uma exceção. A mensagem de erro retornado é o texto da propriedade texto de validação do campo objeto subjacente, se especificado, ou o texto da expressão especificada pela propriedade ValidationRule do objeto subjacente do campo. Você pode chamar [GetValidationText](#getvalidationtext) para obter o texto da mensagem de erro.  
  
 Por exemplo, um campo em um registro que exige o dia do mês pode ter uma regra de validação, como "dia entre 1 e 31."  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade ValidationRule" na Ajuda do DAO.  
  
##  <a name="a-namegetvalidationtexta--cdaorecordsetgetvalidationtext"></a><a name="getvalidationtext"></a>CDaoRecordset::GetValidationText  
 Chame essa função de membro para recuperar o texto da propriedade texto de validação do objeto subjacente do campo.  
  
```  
CString GetValidationText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto da mensagem que será exibida se o valor de um campo não atendem à regra de validação do objeto subjacente do campo.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações relacionadas, consulte o tópico "Propriedade texto de validação" na Ajuda do DAO.  
  
##  <a name="a-nameisbofa--cdaorecordsetisbof"></a><a name="isbof"></a>CDaoRecordset::IsBOF  
 Chame essa função de membro antes de rolagem de registro para registro para saber se você tiver feito antes do primeiro registro do conjunto de registros.  
  
```  
BOOL IsBOF() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros não contém registros ou se você percorreu para trás antes do primeiro registro; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você também pode chamar `IsBOF` juntamente com `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de você chamar **abrir**, se o conjunto de registros não contém registros, `IsBOF` retorna zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retornará 0.  
  
 Se o primeiro registro é o registro atual e você chamar `MovePrev`, `IsBOF` subsequentemente retornará zero. Se `IsBOF` retorna zero e você chamar `MovePrev`, uma exceção é lançada. Se `IsBOF` retorna zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.  
  
 Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:  
  
-   Chamando **abrir** internamente torna o primeiro registro no conjunto de registros do registro atual chamando **MoveFirst**. Portanto, chamar **abrir** em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferente de zero. (Consulte a tabela a seguir para o comportamento de uma falha na **MoveFirst** ou `MoveLast` chamar.)  
  
-   Todas as operações de movimentação com êxito, localize um registro de fazer com que `IsBOF` e `IsEOF` para retornar 0.  
  
-   Um `AddNew` chamada seguido por um **atualização** fará com que a chamada que insere um novo registro com êxito `IsBOF` para retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterada. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, é o ponteiro do registro atual de um conjunto de registros vazio ao final de um arquivo, para que qualquer novo registro é inserido após o registro atual.  
  
-   Qualquer **excluir** chamada, mesmo que ele remove o único registro restante de um conjunto de registros não alterará o valor de `IsBOF` ou `IsEOF`.  
  
 Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.  
  
||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover< 0></ 0>|Mover 0|MoveNext,<br /><br /> Mover > 0|  
|------|-------------------------|-----------------------------|------------|-----------------------------|  
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|  
|`IsBOF`=0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|  
|Ambos diferente de zero|Exceção|Exceção|Exceção|Exceção|  
|0|Permitido|Permitido|Permitido|Permitido|  
  
 Permitindo que uma operação de movimentação não significa que a operação com êxito localizará um registro. Ela simplesmente indica que uma tentativa de executar a operação de transferência especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem ser alterado como resultado da tentativa mudança.  
  
 O efeito de operações de movimentação que não localizar um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.  
  
||IsBOF|IsEOF|  
|------|-----------|-----------|  
|**MoveFirst**,`MoveLast`|Diferente de zero|Diferente de zero|  
|**Mover** 0|Nenhuma alteração|Nenhuma alteração|  
|`MovePrev`, **Move**< 0></ 0>|Diferente de zero|Nenhuma alteração|  
|`MoveNext`, **Move** > 0|Nenhuma alteração|Diferente de zero|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades BOF e EOF" na Ajuda do DAO.  
  
##  <a name="a-nameisdeleteda--cdaorecordsetisdeleted"></a><a name="isdeleted"></a>CDaoRecordset::IsDeleted  
 Chame essa função de membro para determinar se o registro atual foi excluído.  
  
```  
BOOL IsDeleted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros é posicionado em um registro excluído; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você rolar para um registro e `IsDeleted` retorna **TRUE** (diferente de zero), em seguida, você precisa rolar para outro registro antes de executar outras operações de conjunto de registros.  
  
> [!NOTE]
>  Não é necessário verificar o status excluído por registros em um conjunto de registros de instantâneo ou tipo de tabela. Porque os registros não podem ser excluídos de um instantâneo, não é necessário chamar `IsDeleted`. Para conjuntos de registros do tipo de tabela, registros excluídos são removidos realmente do conjunto de registros. Depois que um registro foi excluído, por você, outro usuário, ou em outro conjunto de registros, você não é possível rolar de volta para esse registro. Portanto, não é necessário chamar `IsDeleted`.  
  
 Quando você exclui um registro de um dynaset, ele é removido do conjunto de registros e você não é possível rolar de volta para esse registro. No entanto, se um registro em um dynaset é excluído por outro usuário ou em outro conjunto de registros com base na mesma tabela, `IsDeleted` retornará **TRUE** quando você posteriormente rolar para esse registro.  
  
 Para obter informações relacionadas, consulte os tópicos "Método Delete", "Propriedade LastModified" e "Propriedade EditMode" na Ajuda do DAO.  
  
##  <a name="a-nameiseofa--cdaorecordsetiseof"></a><a name="iseof"></a>CDaoRecordset::IsEOF  
 Chame essa função de membro enquanto você rola de registro para registro para saber se você tiver ido além do último registro do conjunto de registros.  
  
```  
BOOL IsEOF() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conjunto de registros não contém registros ou se você percorreu além do último registro; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você também pode chamar `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de você chamar **abrir**, se o conjunto de registros não contém registros, `IsEOF` retorna zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retornará 0.  
  
 Se o último registro é o registro atual ao chamar `MoveNext`, `IsEOF` subsequentemente retornará zero. Se `IsEOF` retorna zero e você chamar `MoveNext`, uma exceção é lançada. Se `IsEOF` retorna zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em uma exceção.  
  
 Efeito de métodos específicos em `IsBOF` e `IsEOF` configurações:  
  
-   Chamando **abrir** internamente torna o primeiro registro no conjunto de registros do registro atual chamando **MoveFirst**. Portanto, chamar **abrir** em um conjunto vazio de causas de registros `IsBOF` e `IsEOF` para retornar diferente de zero. (Consulte a tabela a seguir para o comportamento de uma falha na **MoveFirst** chamar.)  
  
-   Todas as operações de movimentação com êxito, localize um registro de fazer com que `IsBOF` e `IsEOF` para retornar 0.  
  
-   Um `AddNew` chamada seguido por um **atualização** fará com que a chamada que insere um novo registro com êxito `IsBOF` para retornar 0, mas somente se `IsEOF` já é diferente de zero. O estado do `IsEOF` sempre permanecerá inalterada. Conforme definido pelo mecanismo de banco de dados Microsoft Jet, é o ponteiro do registro atual de um conjunto de registros vazio ao final de um arquivo, para que qualquer novo registro é inserido após o registro atual.  
  
-   Qualquer **excluir** chamada, mesmo que ele remove o único registro restante de um conjunto de registros não alterará o valor de `IsBOF` ou `IsEOF`.  
  
 Esta tabela mostra quais operações de movimentação são permitidas com diferentes combinações de `IsBOF` /  `IsEOF`.  
  
||MoveFirst, MoveLast|MovePrev,<br /><br /> Mover< 0></ 0>|Mover 0|MoveNext,<br /><br /> Mover > 0|  
|------|-------------------------|-----------------------------|------------|-----------------------------|  
|`IsBOF`= diferente de zero,<br /><br /> `IsEOF`=0|Permitido|Exceção|Exceção|Permitido|  
|`IsBOF`=0,<br /><br /> `IsEOF`= diferente de zero|Permitido|Permitido|Exceção|Exceção|  
|Ambos diferente de zero|Exceção|Exceção|Exceção|Exceção|  
|0|Permitido|Permitido|Permitido|Permitido|  
  
 Permitindo que uma operação de movimentação não significa que a operação com êxito localizará um registro. Ela simplesmente indica que uma tentativa de executar a operação de transferência especificada é permitida e não gerará uma exceção. O valor de `IsBOF` e `IsEOF` funções de membro podem ser alterado como resultado da tentativa mudança.  
  
 O efeito de operações de movimentação que não localizar um registro no valor de `IsBOF` e `IsEOF` configurações é mostrada na tabela a seguir.  
  
||IsBOF|IsEOF|  
|------|-----------|-----------|  
|**MoveFirst**,`MoveLast`|Diferente de zero|Diferente de zero|  
|**Mover** 0|Nenhuma alteração|Nenhuma alteração|  
|`MovePrev`, **Move**< 0></ 0>|Diferente de zero|Nenhuma alteração|  
|`MoveNext`, **Move** > 0|Nenhuma alteração|Diferente de zero|  
  
 Para obter informações relacionadas, consulte o tópico "Propriedades BOF e EOF" na Ajuda do DAO.  
  
##  <a name="a-nameisfielddirtya--cdaorecordsetisfielddirty"></a><a name="isfielddirty"></a>CDaoRecordset::IsFieldDirty  
 Chame essa função de membro determinar se o membro de dados do campo especificado de dynaset foi sinalizado como "sujos" (alterado).  
  
```  
BOOL IsFieldDirty(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos são sujo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado estiver marcado como sujo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Os dados em todos os membros de dados sujas do campo serão transferidos para o registro na fonte de dados quando o registro atual é atualizado por uma chamada para o **atualização** função de membro `CDaoRecordset` (após uma chamada para **editar** ou `AddNew`). Com esse conhecimento, você pode tomar mais medidas, como removendo a sinalização do membro de dados de campo para marcar a coluna para que ele não será gravado para a fonte de dados.  
  
 `IsFieldDirty`é implementada por meio de `DoFieldExchange`.  
  
##  <a name="a-nameisfieldnulla--cdaorecordsetisfieldnull"></a><a name="isfieldnull"></a>CDaoRecordset::IsFieldNull  
 Chame essa função de membro para determinar se o membro de um conjunto de registros de dados de campo especificado foi sinalizado como Null.  
  
```  
BOOL IsFieldNull(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos serão Null.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado estiver marcado como Null; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é o mesmo que **nulo** em C++.) Se um membro de dados do campo é marcado como Null, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.  
  
> [!NOTE]
>  Em determinadas situações, usando `IsFieldNull` pode ser ineficiente, como mostra o exemplo de código a seguir:  
  
 [!code-cpp[NVC_MFCDatabase n º&5;](../../mfc/codesnippet/cpp/cdaorecordset-class_5.cpp)]  
  
> [!NOTE]
>  Se você estiver usando associação dinâmica de registro, sem derivar de `CDaoRecordset`, certifique-se de usar **VT_NULL** conforme mostrado no exemplo.  
  
##  <a name="a-nameisfieldnullablea--cdaorecordsetisfieldnullable"></a><a name="isfieldnullable"></a>CDaoRecordset::IsFieldNullable  
 Chame essa função de membro determinar se o membro de dados do campo especificado é "nulo" (pode ser definido como um valor Null; C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa "não ter nenhum valor").  
  
```  
BOOL IsFieldNullable(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 Um ponteiro para o membro de dados do campo cujo status você deseja verificar, ou **nulo** para determinar se qualquer um dos campos serão Null.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o membro de dados do campo especificado pode ser feito Null; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um campo que não pode ser Null deve ter um valor. Se você tentar definir um campo como nulo ao adicionar ou atualizar um registro, a fonte de dados rejeita a adição ou a atualização, e **atualização** lançará uma exceção. A exceção ocorre quando você chamar **atualização**, não quando você chamar `SetFieldNull`.  
  
##  <a name="a-nameisopena--cdaorecordsetisopen"></a><a name="isopen"></a>CDaoRecordset::IsOpen  
 Chame essa função de membro para determinar se o conjunto de registros é aberto.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto recordset **abrir** ou **Requery** função de membro anteriormente foi chamada e o conjunto de registros não foi fechado; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namembcheckcachefordirtyfieldsa--cdaorecordsetmbcheckcachefordirtyfields"></a><a name="m_bcheckcachefordirtyfields"></a>CDaoRecordset::m_bCheckCacheForDirtyFields  
 Contém um sinalizador que indica se os campos em cache são marcados automaticamente como sujos (alterados) e Null.  
  
### <a name="remarks"></a>Comentários  
 O sinalizador padrão **TRUE**. A configuração nesse membro de dados controla o mecanismo inteiro de buffer duplo. Se você definir o sinalizador como **TRUE**, você pode desativar o cache em uma base por um campo usando o mecanismo DFX. Se você definir o sinalizador como **FALSE**, você deve chamar `SetFieldDirty` e `SetFieldNull` por conta própria.  
  
 Defina este membro de dados antes de chamar **abrir**. Esse mecanismo é usada principalmente para facilidade de uso. Desempenho pode ser mais lento devido o buffer duplo de campos como as alterações são feitas.  
  
##  <a name="a-namemnfieldsa--cdaorecordsetmnfields"></a><a name="m_nfields"></a>CDaoRecordset::m_nFields  
 Contém o número de membros de dados do campo na classe de conjunto de registros e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.  
  
### <a name="remarks"></a>Comentários  
 O construtor da classe de conjunto de registros deve inicializar `m_nFields` com o número correto de campos associados estaticamente. ClassWizard grava essa inicialização para você quando você usá-lo para declarar sua classe de conjunto de registros. Você também pode escrevê-lo manualmente.  
  
 A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.  
  
> [!NOTE]
>  Esse número deve corresponder ao número de colunas de saída registrada no `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro **CDaoFieldExchange::outputColumn**.  
  
 Você pode associar colunas dinamicamente por meio de `CDaoRecordset::GetFieldValue` e `CDaoRecordset::SetFieldValue`. Se você fizer isso, não é necessário aumentar a contagem em `m_nFields` para refletir o número da função DFX chamadas seu `DoFieldExchange` função de membro.  
  
##  <a name="a-namemnparamsa--cdaorecordsetmnparams"></a><a name="m_nparams"></a>CDaoRecordset::m_nParams  
 Contém o número de membros de dados de parâmetro na classe de conjunto de registros, o número de parâmetros passados com a consulta do conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Se sua classe de conjunto de registros tiver quaisquer membros de dados de parâmetro, o construtor da classe deve inicializar `m_nParams` com o número correto. O valor de `m_nParams` padrão é 0. Se você adicionar membros de dados de parâmetro — que deve ser feito manualmente — você também deverá adicionar manualmente uma inicialização no construtor da classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de ' espaços reservados em sua **m_strFilter** ou `m_strSort` cadeia de caracteres).  
  
 A estrutura usa esse número quando ela parametriza a consulta do conjunto de registros.  
  
> [!NOTE]
>  Esse número deve corresponder ao número de "parâmetros" registrados no `DoFieldExchange` após uma chamada para `SetFieldType` com o parâmetro **CFieldExchange::param**.  
  
 Para obter informações relacionadas, consulte o tópico "Objeto Parameter" na Ajuda do DAO.  
  
##  <a name="a-namempdaorecordseta--cdaorecordsetmpdaorecordset"></a><a name="m_pdaorecordset"></a>CDaoRecordset::m_pDAORecordset  
 Contém um ponteiro para a interface OLE para o objeto de conjunto de registros DAO base o `CDaoRecordset` objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esse ponteiro se você precisar acessar a interface do DAO diretamente.  
  
 Para obter informações relacionadas, consulte o tópico "Recordset Object" na Ajuda do DAO.  
  
##  <a name="a-namempdatabasea--cdaorecordsetmpdatabase"></a><a name="m_pdatabase"></a>CDaoRecordset::m_pDatabase  
 Contém um ponteiro para o `CDaoDatabase` objeto por meio do qual o conjunto de registros é conectado a uma fonte de dados.  
  
### <a name="remarks"></a>Comentários  
 Essa variável é definida de duas maneiras. Normalmente, você passa um ponteiro para um já aberto `CDaoDatabase` objeto quando você construir o objeto recordset. Se você passar **nulo** em vez disso, **CDaoRecordset** cria um `CDaoDatabase` objeto para você e o abre. Em ambos os casos, `CDaoRecordset` armazena o ponteiro nessa variável.  
  
 Normalmente você não diretamente precisará usar o ponteiro é armazenado no **m_pDatabase**. Se você escrever suas próprias extensões para `CDaoRecordset`, no entanto, talvez seja necessário usar o ponteiro. Por exemplo, talvez seja necessário o ponteiro se você acionar seu próprio `CDaoException`(s).  
  
 Para obter informações relacionadas, consulte o tópico "Objeto de banco de dados" na Ajuda do DAO.  
  
##  <a name="a-namemstrfiltera--cdaorecordsetmstrfilter"></a><a name="m_strfilter"></a>CDaoRecordset::m_strFilter  
 Contém uma cadeia de caracteres que é usada para construir o **onde** cláusula de uma instrução SQL.  
  
### <a name="remarks"></a>Comentários  
 Ele não inclui a palavra reservada **onde** para filtrar o conjunto de registros. O uso desse membro de dados não é aplicável a conjuntos de registros do tipo de tabela. O uso de **m_strFilter** não tem efeito quando abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.  
  
 Use o formato de data dos EUA (mês-dia-ano) quando filtrar campos que contenham datas, mesmo se você não estiver usando a versão dos EUA do mecanismo de banco de dados Microsoft Jet; Caso contrário, os dados não podem ser filtrados conforme o esperado.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade Filter" na Ajuda do DAO.  
  
##  <a name="a-namemstrsorta--cdaorecordsetmstrsort"></a><a name="m_strsort"></a>CDaoRecordset::m_strSort  
 Contém uma cadeia de caracteres que contém o **ORDERBY** cláusula de uma instrução SQL sem as palavras reservadas **ORDERBY**.  
  
### <a name="remarks"></a>Comentários  
 Você pode classificar em objetos de conjunto de registros do tipo dynaset e snapshot.  
  
 Não é possível classificar objetos de conjunto de registros do tipo de tabela. Para determinar a ordem de classificação de um conjunto de registros do tipo de tabela, chame [SetCurrentIndex](#setcurrentindex).  
  
 O uso de `m_strSort` não tem efeito quando abrir um conjunto de registros usando um `CDaoQueryDef` ponteiro.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade de classificação" na Ajuda do DAO.  
  
##  <a name="a-namemovea--cdaorecordsetmove"></a><a name="move"></a>CDaoRecordset::Move  
 Chame essa função de membro para posicionar o conjunto de registros `lRows` registros do registro atual.  
  
```  
virtual void Move(long lRows);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lRows`  
 O número de registros para mover para frente ou para trás. Valores positivos movem para frente, até o final do conjunto de registros. Valores negativos a movem para trás, em direção ao início.  
  
### <a name="remarks"></a>Comentários  
 Você pode mover para frente ou para trás. `Move( 1 )`é equivalente a `MoveNext`, e `Move( -1 )` é equivalente a `MovePrev`.  
  
> [!CAUTION]
>  Chamar qualquer do **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de você chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você percorreu após o início ou fim do conjunto de registros ( `IsBOF` ou `IsEOF` retorna zero), uma chamada para **mover** lança um `CDaoException`.  
  
> [!NOTE]
>  Se você chamar qualquer um do **mover** funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Quando você chama **mover** em um instantâneo de rolagem somente de encaminhamento, o `lRows` deve ser um inteiro positivo e indicadores não são permitidos, para poder prosseguir somente.  
  
 Para tornar o nome, sobrenome, anterior ou próximo registro em um conjunto de registros a chamada atual de registro, o **MoveFirst**, `MoveLast`, `MoveNext`, ou `MovePrev` função de membro.  
  
 Para obter informações relacionadas, consulte os tópicos "Mover método" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namemovefirsta--cdaorecordsetmovefirst"></a><a name="movefirst"></a>CDaoRecordset::MoveFirst  
 Chame essa função de membro para tornar o primeiro registro no conjunto de registros (se houver) do registro atual.  
  
```  
void MoveFirst();
```  
  
### <a name="remarks"></a>Comentários  
 Você não precisa chamar **MoveFirst** imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.  
  
> [!CAUTION]
>  Chamar qualquer do **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de você chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer um do **mover** funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou objeto recordset do tipo snapshot que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.  
  
 Se você chamar `MoveLast` em um objeto recordset baseado em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto recordset é totalmente preenchido.  
  
 Você não pode chamar o **MoveFirst** ou `MovePrev` a função de membro com um instantâneo de rolagem somente de encaminhamento.  
  
 Para mover a posição do atual gravar em um objeto recordset um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Mover método" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namemovelasta--cdaorecordsetmovelast"></a><a name="movelast"></a>CDaoRecordset::MoveLast  
 Chame essa função de membro para tornar o último registro (se houver) no conjunto de registros do registro atual.  
  
```  
void MoveLast();
```  
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Chamar qualquer do **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de você chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer um do **mover** funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou objeto recordset do tipo snapshot que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.  
  
 Se você chamar `MoveLast` em um objeto recordset baseado em uma consulta SQL ou querydef, a consulta será forçada a conclusão e o objeto recordset é totalmente preenchido.  
  
 Para mover a posição do atual gravar em um objeto recordset um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Mover método" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namemovenexta--cdaorecordsetmovenext"></a><a name="movenext"></a>CDaoRecordset::MoveNext  
 Chame essa função de membro para tornar o próximo registro no conjunto de registros do registro atual.  
  
```  
void MoveNext();
```  
  
### <a name="remarks"></a>Comentários  
 É recomendável que você chame `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará um `CDaoException` se `IsBOF` retorna diferente de zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados pelo conjunto de registros.  
  
> [!CAUTION]
>  Chamar qualquer do **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de você chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer um do **mover** funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou objeto recordset do tipo snapshot que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.  
  
 Para mover a posição do atual gravar em um objeto recordset um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Mover método" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-namemovepreva--cdaorecordsetmoveprev"></a><a name="moveprev"></a>CDaoRecordset::MovePrev  
 Chame essa função de membro para tornar o registro anterior no conjunto de registros do registro atual.  
  
```  
void MovePrev();
```  
  
### <a name="remarks"></a>Comentários  
 É recomendável que você chame `IsBOF` antes de tentar mover para o registro anterior. Uma chamada para `MovePrev` lançará um `CDaoException` se `IsBOF` retorna diferente de zero, indicando que você já tenha acessado antes do primeiro registro ou que não há registros selecionados pelo conjunto de registros.  
  
> [!CAUTION]
>  Chamar qualquer do **mover** funções lança uma exceção se o conjunto de registros não contém registros. Em geral, chame ambos `IsBOF` e `IsEOF` antes de uma operação de movimentação para determinar se o conjunto de registros tem todos os registros. Depois de você chamar **abrir** ou **Requery**, chame o `IsBOF` ou `IsEOF`.  
  
> [!NOTE]
>  Se você chamar qualquer um do **mover** funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.  
  
 Use o **mover** funções para mover de registro para registro sem aplicar uma condição. Use as operações de localizar para localizar registros em um tipo dynaset ou objeto recordset do tipo snapshot que atendem a uma determinada condição. Para localizar um registro em um objeto de conjunto de registros do tipo de tabela, chame `Seek`.  
  
 Se o conjunto de registros se refere a um conjunto de registros do tipo de tabela, o movimento segue o índice atual da tabela. Você pode definir o índice atual usando a propriedade de índice do objeto DAO subjacente. Se você não definir o índice atual, a ordem dos registros retornados será indefinida.  
  
 Você não pode chamar o **MoveFirst** ou `MovePrev` a função de membro com um instantâneo de rolagem somente de encaminhamento.  
  
 Para mover a posição do atual gravar em um objeto recordset um determinado número de registros para frente ou para trás, chame **mover**.  
  
 Para obter informações relacionadas, consulte os tópicos "Mover método" e "MoveFirst, MoveLast, MoveNext e MovePrevious métodos" na Ajuda do DAO.  
  
##  <a name="a-nameopena--cdaorecordsetopen"></a><a name="open"></a>Cdaorecordset:: Open  
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
 `nOpenType`  
 Um dos seguintes valores:  
  
- **dbOpenDynaset** um conjunto de registros do tipo dynaset com rolagem bidirecional. Esse é o padrão.  
  
- **dbOpenTable** um conjunto de registros do tipo de tabela com rolagem bidirecional.  
  
- **dbOpenSnapshot** um conjunto de registros do tipo de instantâneo com rolagem bidirecional.  
  
 `lpszSQL`  
 Um ponteiro de cadeia de caracteres que contém um dos seguintes:  
  
-   A **nulo** ponteiro.  
  
-   O nome de um ou mais tabledefs e/ou querydefs (separados por vírgulas).  
  
-   Um SQL **selecione** instrução (opcionalmente com um SQL **onde** ou **ORDERBY** cláusula).  
  
-   Uma consulta de passagem.  
  
 `nOptions`  
 Uma ou mais das opções listadas abaixo. O valor padrão é 0. Os valores possíveis são:  
  
- **dbAppendOnly** você apenas pode acrescentar novos registros (recordset do tipo dynaset apenas). Esta opção significa literalmente registros só podem ser acrescentados. As classes de banco de dados ODBC MFC tem uma opção somente de acréscimo que permite que os registros a serem recuperados e anexados.  
  
- **dbForwardOnly** o conjunto de registros é um instantâneo de rolagem somente de encaminhamento.  
  
- **dbSeeChanges** gerar uma exceção se outro usuário está alterando dados que você está editando.  
  
- **dbDenyWrite** não é possível modificar ou adicionar registros de outros usuários.  
  
- **dbDenyRead** outros usuários não podem exibir registros (recordset do tipo table somente).  
  
- **dbReadOnly** você só pode exibir registros, outros usuários podem modificá-las.  
  
- **dbInconsistent** atualizações inconsistentes são permitidas (conjunto de registros do tipo dynaset apenas).  
  
- **dbConsistent** somente atualizações consistentes são permitidas (conjunto de registros do tipo dynaset apenas).  
  
> [!NOTE]
>  As constantes **dbConsistent** e **dbInconsistent** são mutuamente exclusivos. Você pode usar um ou outro, mas não ambos em uma determinada instância do **abrir**.  
  
 *pTableDef*  
 Um ponteiro para um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto. Esta versão é válido somente para conjuntos de registros do tipo de tabela. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não é utilizado; em vez disso, o banco de dados no qual reside o tabledef é usado.  
  
 *pQueryDef*  
 Um ponteiro para um [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) objeto. Esta versão é válido somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo. Ao usar essa opção, o `CDaoDatabase` ponteiro usado para construir o `CDaoRecordset` não é utilizado; em vez disso, o banco de dados no qual reside o querydef é usado.  
  
### <a name="remarks"></a>Comentários  
 Antes de chamar **abrir**, você deve construir o objeto recordset. Há várias maneiras de fazer isso:  
  
-   Quando você cria o objeto recordset, passe um ponteiro para um `CDaoDatabase` objeto que já está aberto.  
  
-   Quando você cria o objeto recordset, passe um ponteiro para um `CDaoDatabase` objeto que não está aberto. O conjunto de registros é aberto um `CDaoDatabase` do objeto, mas não fechará-lo quando o objeto recordset é fechado.  
  
-   Quando você cria o objeto recordset, passe uma **nulo** ponteiro. As chamadas do objeto recordset `GetDefaultDBName` para obter o nome do Microsoft Access. Arquivo MDB para abrir. O conjunto de registros, em seguida, abre uma `CDaoDatabase` objeto e evita que ele abra desde que o conjunto de registros é aberto. Quando você chama **fechar** no conjunto de registros, o `CDaoDatabase` objeto também é fechado.  
  
    > [!NOTE]
    >  Quando o conjunto de registros é aberto o `CDaoDatabase` do objeto, ele abre a fonte de dados com acesso não exclusivo.  
  
 Para a versão do **abrir** que usa o `lpszSQL` parâmetro, quando o conjunto de registros é aberto, você pode recuperar registros de várias maneiras. A primeira opção é ter funções DFX em seu `DoFieldExchange`. A segunda opção é usar a vinculação dinâmica chamando o `GetFieldValue` função de membro. Essas opções podem ser implementadas separadamente ou em conjunto. Se elas são combinadas, você precisará passar na instrução SQL por conta própria na chamada para **abrir**.  
  
 Quando você usa a segunda versão do **abrir** onde você passar um `CDaoTableDef` do objeto, as colunas resultantes estarão disponíveis para a ligação por meio de `DoFieldExchange` e o mecanismo DFX e/ou vincular dinamicamente por meio de `GetFieldValue`.  
  
> [!NOTE]
>  Você só pode chamar **abrir** usando um `CDaoTableDef` objeto para conjuntos de registros do tipo de tabela.  
  
 Quando você usa a terceira versão do **abrir** onde você passar um `CDaoQueryDef` do objeto, que consulta será executada, e as colunas resultantes estarão disponíveis para a ligação por meio de `DoFieldExchange` e o mecanismo DFX e/ou vincular dinamicamente por meio de `GetFieldValue`.  
  
> [!NOTE]
>  Você só pode chamar **abrir** usando um `CDaoQueryDef` objeto de tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 Para a primeira versão do **abrir** que usa o `lpszSQL` parâmetro, os registros são com base em critérios selecionados, mostrados na tabela a seguir.  
  
|Valor da `lpszSQL` parâmetro|Registros selecionados são determinados por|Exemplo|  
|--------------------------------------|----------------------------------------|-------------|  
|**NULL**|A cadeia de caracteres retornada por `GetDefaultSQL`.||  
|Uma lista separada por vírgulas de um ou mais tabledefs e/ou querydef nomes.|Todas as colunas são representadas na `DoFieldExchange`.|`"Customer"`|  
|**Selecione** lista de colunas **FROM** lista tabela|As colunas especificadas do tabledef(s) especificado e/ou querydef(s).|`"SELECT CustId, CustName`<br /><br /> `FROM Customer"`|  
  
 O procedimento normal é passar **nulo** para **abrir**; nesse caso, **abrir** chamadas `GetDefaultSQL`, uma função de membro substituíveis ClassWizard gera durante a criação de um `CDaoRecordset`-classe derivada. Esse valor fornece o nome tabledef(s) e/ou querydef especificado em ClassWizard. Em vez disso, você pode especificar outras informações de `lpszSQL` parâmetro.  
  
 Tudo o que você passe **abrir** constrói uma cadeia de caracteres final SQL para a consulta (a cadeia de caracteres pode ter o SQL **onde** e **ORDERBY** cláusulas anexado ao `lpszSQL` cadeia de caracteres passada por você) e, em seguida, executa a consulta. Você pode examinar a cadeia de caracteres criada chamando `GetSQL` depois de chamar **abrir**.  
  
 Os membros de sua classe de conjunto de registros de dados de campo são vinculados às colunas de dados selecionados. Se todos os registros são retornados, o primeiro registro se tornará o registro atual.  
  
 Se você desejar definir opções para o conjunto de registros, um filtro ou uma classificação, defina `m_strSort` ou **m_strFilter** depois de construir o objeto recordset, mas antes de chamar **abrir**. Se você quiser atualizar os registros no conjunto de registros após o conjunto de registros já estiver aberto, chame **Requery**.  
  
 Se você chamar **abrir** em um tipo dynaset ou recordset tipo snapshot, ou se a fonte de dados se refere a uma instrução SQL ou um tabledef que representa uma tabela anexada, você não pode usar **dbOpenTable** para o argumento de tipo; nesse caso, o MFC lança uma exceção. Para determinar se um objeto tabledef representa uma tabela anexada, crie um [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) objeto e chamar seu [GetConnect](../../mfc/reference/cdaotabledef-class.md#getconnect) função de membro.  
  
 Use o **dbSeeChanges** sinalizador para interceptar as alterações feitas por outro usuário ou outro programa em seu computador quando você está editando ou excluindo o mesmo registro. Por exemplo, se dois usuários começar a editar o mesmo registro, o primeiro usuário chamar o **atualização** função de membro for bem-sucedida. Quando **atualização** é chamado pelo segundo usuário, um `CDaoException` é lançada. Da mesma forma, se o segundo usuário tentar chamar **excluir** excluir o registro e já foi alterado pelo primeiro usuário, um `CDaoException` ocorre.  
  
 Normalmente, se o usuário obtém essa `CDaoException` durante a atualização, seu código deve atualizar o conteúdo dos campos e recuperar os valores modificados recentemente. Se a exceção ocorre no processo de exclusão, seu código pode exibir os novos dados de registro para o usuário e uma mensagem indicando que os dados foram alterados recentemente. Neste ponto, seu código pode solicitar uma confirmação de que o usuário ainda deseja excluir o registro.  
  
> [!TIP]
>  Use a opção de rolagem de somente avanço ( **dbForwardOnly**) melhorar o desempenho quando seu aplicativo faz uma passagem por um conjunto de registros aberto a partir de uma fonte de dados ODBC.  
  
 Para obter informações relacionadas, consulte o tópico "Método OpenRecordset" na Ajuda do DAO.  
  
##  <a name="a-namerequerya--cdaorecordsetrequery"></a><a name="requery"></a>CDaoRecordset::Requery  
 Chame essa função de membro para reconstruir (Atualizar) um conjunto de registros.  
  
```  
virtual void Requery();
```  
  
### <a name="remarks"></a>Comentários  
 Se todos os registros são retornados, o primeiro registro se tornará o registro atual.  
  
 Na ordem do conjunto de registros refletir as adições e exclusões que você ou outros usuários estão fazendo para a fonte de dados, você deve recriar o conjunto de registros chamando **Requery**. Se o conjunto de registros é um dynaset, ele refletirá automaticamente as atualizações que você ou outros usuários para seus registros existentes (mas não adições). Se o conjunto de registros é um instantâneo, você deve chamar **Requery** para refletir edições por outros usuários, bem como adições e exclusões.  
  
 Para um dynaset ou um instantâneo, chame **Requery** sempre que quiser para recriar o conjunto de registros usando valores de parâmetro. Defina o novo filtro ou classificação definindo [m_strFilter](#m_strfilter) e [m_strSort](#m_strsort) antes de chamar **Requery**. Definir novos parâmetros ao atribuir novos valores para membros de dados de parâmetro antes de chamar **Requery**.  
  
 Se a tentativa de recriar o conjunto de registros falhar, o conjunto de registros é fechado. Antes de chamar **Requery**, você pode determinar se o conjunto de registros pode ser novamente consultado chamando o [CanRestart](#canrestart) função de membro. `CanRestart`não garante que **Requery** terá êxito.  
  
> [!CAUTION]
>  Chamar **Requery** somente depois de ter chamado **abrir**.  
  
> [!NOTE]
>  Chamando [Requery](#requery) altera marcadores do DAO.  
  
 Não é possível chamar **Requery** em um tipo dynaset ou recordset tipo snapshot se chamar `CanRestart` retorna 0, nem você usá-lo em um conjunto de registros do tipo de tabela.  
  
 Se ambos os `IsBOF` e `IsEOF` de retorno diferente de zero depois de você chamar **Requery**, a consulta não retornou nenhum registro e o conjunto de registros não contém nenhum dado.  
  
 Para obter informações relacionadas, consulte o tópico "Método Requery" na Ajuda do DAO.  
  
##  <a name="a-nameseeka--cdaorecordsetseek"></a><a name="seek"></a>CDaoRecordset::Seek  
 Chame essa função de membro para localizar o registro em um objeto recordset de tipo de tabela indexada que atenda aos critérios especificados para a atual de índice e verifique a registro o atual.  
  
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
 Uma das expressões de cadeia de caracteres a seguir: "<",></",>\<=", "=", "> =", ou ">".  
  
 `pKey1`  
 Um ponteiro para um [COleVariant](../../mfc/reference/colevariant-class.md) cujo valor corresponde ao primeiro campo no índice. Necessário.  
  
 *pKey2*  
 Um ponteiro para um `COleVariant` cujo valor corresponde ao segundo campo no índice, se houver. O padrão é **nulo**.  
  
 *pKey3*  
 Um ponteiro para um `COleVariant` cujo valor corresponde ao terceiro campo no índice, se houver. O padrão é **nulo**.  
  
 *pKeyArray*  
 Um ponteiro para uma matriz de variantes. O tamanho da matriz corresponde ao número de campos no índice.  
  
 *nKeys*  
 Um inteiro correspondente para o tamanho da matriz, que é o número de campos no índice.  
  
> [!NOTE]
>  Não especifique caracteres curinga nas chaves. Curingas causará `Seek` para retornar sem registros correspondentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se registros correspondentes forem encontrados, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use a segunda versão (matriz) `Seek` para lidar com índices de campos de quatro ou mais.  
  
 `Seek`Habilita o índice de alto desempenho que pesquisa em conjuntos de registros do tipo de tabela. Você deve definir o índice atual chamando `SetCurrentIndex` antes de chamar `Seek`. Se o índice identifica um campo de chave exclusivo ou campos, `Seek` localiza o primeiro registro que satisfaz os critérios. Se você não definir um índice, uma exceção é lançada.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objetos devem ser declarados explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definida como `VT_BSTRT`.  
  
 Quando você chama `Seek`, você passa um ou mais valores de chave e um operador de comparação ("<",></",>\<=", "=", "> =", ou ">"). `Seek`Localiza os campos de chave especificados e localiza o primeiro registro que satisfaz os critérios especificados por `lpszComparison` e `pKey1`. Uma vez encontrado, `Seek` retorna zero e torna esse registro atual. Se `Seek` não conseguir localizar uma correspondência, `Seek` retorna zero, e o registro atual é indefinido. Ao usar o DAO diretamente, você deve verificar explicitamente a propriedade NoMatch.  
  
 Se `lpszComparison` é "=", "> =", ou ">", `Seek` começa no início do índice. Se `lpszComparison` é "<" or=""> </"> <=",> </=",> `Seek` começa no final do índice e procurará a menos que haja entradas de índice duplicadas no final. Nesse caso, `Seek` começa com uma entrada arbitrária entre as entradas de índice duplicadas no final do índice.  
  
 Não deve haver um registro atual ao usar `Seek`.  
  
 Para localizar um registro em um tipo dynaset ou recordset tipo snapshot que satisfaça uma condição específica, use as operações de localização. Para incluir todos os registros, não apenas aqueles que atendem a uma condição específica, use as operações de movimentação para mover de um registro para outro.  
  
 Não é possível chamar `Seek` em uma tabela anexada de qualquer tipo, pois a tabelas anexadas devem ser abertas como tipo dynaset ou conjunto de registros do tipo de instantâneo. No entanto, se você chamar `CDaoDatabase::Open` para abrir um banco de dados ISAM instalável diretamente, você pode chamar `Seek` em tabelas no banco de dados, embora o desempenho pode ser lenta.  
  
 Para obter informações relacionadas, consulte o tópico "Método de busca" na Ajuda do DAO.  
  
##  <a name="a-namesetabsolutepositiona--cdaorecordsetsetabsoluteposition"></a><a name="setabsoluteposition"></a>CDaoRecordset::SetAbsolutePosition  
 Define o número de registro relativo do registro de um objeto conjunto de registros atual.  
  
```  
void SetAbsolutePosition(long lPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lPosition*  
 Corresponde à posição ordinal do registro atual no conjunto de registros.  
  
### <a name="remarks"></a>Comentários  
 Chamando `SetAbsolutePosition` permite que você posicione o ponteiro de registro atual para um registro específico com base em sua posição ordinal em um tipo dynaset ou recordset tipo snapshot. Você também pode determinar o número do registro atual chamando [GetAbsolutePosition](#getabsoluteposition).  
  
> [!NOTE]
>  Essa função de membro é válida somente para o tipo dynaset e conjuntos de registros do tipo de instantâneo.  
  
 O valor da propriedade AbsolutePosition do objeto DAO subjacente é baseada em zero; uma configuração de 0 refere-se para o primeiro registro no conjunto de registros. Definir um valor maior que o número de registros preenchidos causas MFC lançar uma exceção. Você pode determinar o número de registros preenchidos no conjunto de registros chamando o `GetRecordCount` função de membro.  
  
 Se o registro atual for excluído, o valor da propriedade AbsolutePosition não está definido, e MFC lança uma exceção se ela é referenciada. Novos registros são adicionados ao final da sequência.  
  
> [!NOTE]
>  Essa propriedade não se destina a ser usado como um número de registro alternativo. Indicadores ainda são a maneira recomendada de reter e retornar para uma determinada posição e são a única forma de posicionar o registro atual em todos os tipos de objetos de conjunto de registros que oferecem suporte a indicadores. Em particular, a posição de um determinado registro muda quando o registro anterior é excluídos. Também não há nenhuma garantia de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado porque a ordem de registros individuais em um conjunto de registros não é garantida, a menos que ela é criada com uma instrução SQL usando um **ORDERBY** cláusula.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade AbsolutePosition" na Ajuda do DAO.  
  
##  <a name="a-namesetbookmarka--cdaorecordsetsetbookmark"></a><a name="setbookmark"></a>CDaoRecordset::SetBookmark  
 Chame essa função de membro para posicionar o conjunto de registros no registro que contém o indicador especificado.  
  
```  
void SetBookmark(COleVariant varBookmark);
```  
  
### <a name="parameters"></a>Parâmetros  
 `varBookmark`  
 A [COleVariant](../../mfc/reference/colevariant-class.md) objeto que contém o valor do indicador para um registro específico.  
  
### <a name="remarks"></a>Comentários  
 Quando um objeto recordset é criado ou aberto, cada um de seus registros já possui um indicador exclusivo. Você pode recuperar o indicador para o registro atual chamando `GetBookmark` e salvar o valor para um `COleVariant` objeto. Você pode retornar posteriormente para esse registro chamando `SetBookmark` usando o valor do indicador salvo.  
  
> [!NOTE]
>  Chamando [Requery](#requery) altera marcadores do DAO.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definida como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte os tópicos "Propriedades de indicador" e possíveis de indicação"na Ajuda do DAO.  
  
##  <a name="a-namesetcachesizea--cdaorecordsetsetcachesize"></a><a name="setcachesize"></a>CDaoRecordset::SetCacheSize  
 Chame essa função de membro para definir o número de registros a ser armazenado em cache.  
  
```  
void SetCacheSize(long lSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lSize`  
 Especifica o número de registros. Um valor típico é 100. Uma configuração de 0 desativa o armazenamento em cache. A configuração deve estar entre 5 e 1200 registros. O cache pode usar uma quantidade considerável de memória.  
  
### <a name="remarks"></a>Comentários  
 Um cache é um espaço na memória local que mantém os dados recuperados mais recentemente do servidor que os dados serem solicitados novamente enquanto o aplicativo é executado. Cache de dados melhora o desempenho de um aplicativo que recupera dados de um servidor remoto por meio de objetos de conjunto de registros do tipo dynaset. Quando os dados são solicitados, o mecanismo de banco de dados Microsoft Jet primeiro verifica o cache para os dados solicitados em vez de recuperá-los do servidor, o que leva mais tempo. Dados que não seja proveniente de uma fonte de dados ODBC não são salvos no cache.  
  
 Qualquer fonte de dados ODBC, como uma tabela anexada, pode ter um cache local. Para criar o cache, abra um objeto de conjunto de registros da fonte de dados remota, chamada de `SetCacheSize` e `SetCacheStart` funções de membro e, em seguida, chame o `FillCache` função de membro ou percorra os registros usando uma das operações de movimentação. O `lSize` parâmetro o `SetCacheSize` função de membro pode basear-se no número de registros de seu aplicativo pode trabalhar com uma vez. Por exemplo, se você estiver usando um conjunto de registros como fonte de dados a ser exibido na tela, você pode passar o `SetCacheSize``lSize` parâmetro como 20 para exibir 20 registros ao mesmo tempo.  
  
 Para obter informações relacionadas, consulte o tópico "CacheSize, CacheStart propriedades" na Ajuda do DAO.  
  
##  <a name="a-namesetcachestarta--cdaorecordsetsetcachestart"></a><a name="setcachestart"></a>CDaoRecordset::SetCacheStart  
 Chame essa função de membro para especificar o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
```  
void SetCacheStart(COleVariant varBookmark);
```  
  
### <a name="parameters"></a>Parâmetros  
 `varBookmark`  
 A [COleVariant](../../mfc/reference/colevariant-class.md) que especifica o indicador do primeiro registro no conjunto de registros a ser armazenado em cache.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o valor do indicador de qualquer registro para o `varBookmark` parâmetro o `SetCacheStart` função de membro. Tornar o registro que você deseja iniciar o cache com o registro atual, estabelecer um indicador para esse registro usando [SetBookmark](#setbookmark)e passe o valor do indicador como o parâmetro para o `SetCacheStart` função de membro.  
  
 O mecanismo de banco de dados Microsoft Jet solicita registros dentro do intervalo de cache do cache e solicita registros fora do intervalo de cache do servidor.  
  
 Registros recuperados do cache não refletem as alterações feitas simultaneamente nos dados de origem por outros usuários.  
  
 Para forçar uma atualização de todos os dados armazenados em cache, passe o `lSize` parâmetro do `SetCacheSize` como 0, chame `SetCacheSize` novamente com o tamanho do cache foi originalmente solicitada e, em seguida, chame o `FillCache` função de membro.  
  
 Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definida como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte o tópico CacheSize, CacheStart propriedades"na Ajuda do DAO.  
  
##  <a name="a-namesetcurrentindexa--cdaorecordsetsetcurrentindex"></a><a name="setcurrentindex"></a>CDaoRecordset::SetCurrentIndex  
 Chame essa função de membro para definir um índice em um conjunto de registros do tipo de tabela.  
  
```  
void SetCurrentIndex(LPCTSTR lpszIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIndex`  
 Um ponteiro que contém o nome do índice a ser definido.  
  
### <a name="remarks"></a>Comentários  
 Registros nas tabelas base não são armazenados em uma ordem específica. Definir um índice altera a ordem dos registros retornados do banco de dados, mas não afeta a ordem na qual os registros são armazenados. O índice especificado já deve estar definido. Se você tentar usar um objeto de índice não existir ou se o índice não está definido ao chamar [busca](#seek), MFC lança uma exceção.  
  
 Você pode criar um novo índice para a tabela chamando [CDaoTableDef::CreateIndex](../../mfc/reference/cdaotabledef-class.md#createindex) e acrescentar o novo índice para a coleção de índices de base tabledef chamando [CDaoTableDef::Append](../../mfc/reference/cdaotabledef-class.md#append)e reabrindo o conjunto de registros.  
  
 Registros retornados de um conjunto de registros do tipo de tabela podem ser solicitados somente pelos índices definidos para tabledef subjacente. Para classificar registros em alguma outra ordem, você pode abrir um tipo dynaset ou recordset tipo snapshot usando um SQL **ORDERBY** cláusula armazenados em [CDaoRecordset::m_strSort](#m_strsort).  
  
 Para obter informações relacionadas, consulte o tópico "Índice Object" e a definição de "índice atual" na Ajuda do DAO.  
  
##  <a name="a-namesetfielddirtya--cdaorecordsetsetfielddirty"></a><a name="setfielddirty"></a>CDaoRecordset::SetFieldDirty  
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
 **TRUE** se o membro de dados do campo deve ser marcados como "sujos" (alterado). Caso contrário, **FALSE** se o membro de dados do campo é sinalizada como "Limpar" (inalterada).  
  
### <a name="remarks"></a>Comentários  
 Marcar campos como inalterados garante que o campo não é atualizado.  
  
 As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo DAO campos de registro (DFX) do exchange. Alterar o valor de um campo geralmente define o campo sujas automaticamente, portanto você raramente precisa chamar `SetFieldDirty` por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor no membro de dados do campo. O mecanismo DFX emprega o uso de **PSEUDONULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
 Se não estiver sendo usado o mecanismo de armazenamento em buffer duplo, em seguida, alterando o valor do campo não define automaticamente o campo como suja. Nesse caso, será necessário definir o campo explicitamente como sujo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação de campo automáticas.  
  
> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [editar](#edit) ou [AddNew](#addnew).  
  
 Usando **nulo** para o primeiro argumento da função serão aplicadas a função a todos **outputColumn** campos não **param** campos `CDaoFieldExchange`. Por exemplo, a chamada  
  
 [!code-cpp[NVC_MFCDatabase n º&6;](../../mfc/codesnippet/cpp/cdaorecordset-class_6.cpp)]  
  
 será definido somente **outputColumn** campos **nulo**; **param** campos não serão afetados.  
  
 Para trabalhar em um **param**, você deve fornecer o endereço real da pessoa **param** você deseja trabalhar, como:  
  
 [!code-cpp[NVC_MFCDatabase&#7;](../../mfc/codesnippet/cpp/cdaorecordset-class_7.cpp)]  
  
 Isso significa que você não pode definir todos os **param** campos **nulo**, como faria com **outputColumn** campos.  
  
 `SetFieldDirty`é implementada por meio de `DoFieldExchange`.  
  
##  <a name="a-namesetfieldnulla--cdaorecordsetsetfieldnull"></a><a name="setfieldnull"></a>CDaoRecordset::SetFieldNull  
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
 Diferente de zero se o membro de dados do campo deve ser sinalizada como não tendo nenhum valor (Null). Caso contrário, 0 se o membro de dados do campo deve ser marcado como não-nulo.  
  
### <a name="remarks"></a>Comentários  
 `SetFieldNull`é usado para campos ligados a `DoFieldExchange` mecanismo.  
  
 Quando você adiciona um novo registro para um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e marcados como "sujos" (alterado). Quando você recupera um registro de uma fonte de dados, suas colunas ou já tem valores ou forem nulos. Se não for apropriado para um campo nulo, uma [CDaoException](../../mfc/reference/cdaoexception-class.md) é lançada.  
  
 Se você estiver usando o mecanismo de armazenamento em buffer duplo, por exemplo, se desejar designar um campo do registro atual como não tendo um valor, chamar especificamente `SetFieldNull` com `bNull` definida como **TRUE** sinalizá-la como Null. Se um campo foi marcado anteriormente Null e agora você deseja dar a ela um valor, basta defina seu novo valor. Não é necessário remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser Null, chame [IsFieldNullable](#isfieldnullable).  
  
 Se você não estiver usando o mecanismo de armazenamento em buffer duplo, alterando o valor do campo não define automaticamente o campo como sujas e não nulo. Especificamente, você deve definir os campos anormal e não nulo. O sinalizador contido em [m_bCheckCacheForDirtyFields](#m_bcheckcachefordirtyfields) controla essa verificação de campo automáticas.  
  
 O mecanismo DFX emprega o uso de **PSEUDONULL**. Para obter mais informações, consulte [CDaoFieldExchange::m_nOperation](../../mfc/reference/cdaofieldexchange-class.md#m_noperation).  
  
> [!NOTE]
>  Chame essa função de membro somente depois de ter chamado [editar](#edit) ou [AddNew](#addnew).  
  
 Usando **nulo** para o primeiro argumento da função serão aplicadas somente a função **outputColumn** campos não **param** campos `CDaoFieldExchange`. Por exemplo, a chamada  
  
 [!code-cpp[NVC_MFCDatabase n º&8;](../../mfc/codesnippet/cpp/cdaorecordset-class_8.cpp)]  
  
 será definido somente **outputColumn** campos **nulo**; **param** campos não serão afetados.  
  
##  <a name="a-namesetfieldvaluea--cdaorecordsetsetfieldvalue"></a><a name="setfieldvalue"></a>CDaoRecordset::SetFieldValue  
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
 Use `SetFieldValue` e [GetFieldValue](#getfieldvalue) para vincular campos dinamicamente no tempo de execução em vez de estaticamente colunas de associação usando o [DoFieldExchange](#dofieldexchange) mecanismo.  
  
 Observe que se você não estiver criando um conjunto de registros do UNICODE, você deve usar um formulário de `SetFieldValue` que não contenha um `COleVariant` parâmetro, ou o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definida como `VT_BSTRT`.  
  
 Para obter informações relacionadas, consulte os tópicos "Campo Object" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="a-namesetfieldvaluenulla--cdaorecordsetsetfieldvaluenull"></a><a name="setfieldvaluenull"></a>CDaoRecordset::SetFieldValueNull  
 Chame essa função de membro para definir o campo como um valor nulo.  
  
```  
void SetFieldValueNull(int nIndex);  
void SetFieldValueNull(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do campo no conjunto de registros, para pesquisa de índice baseado em zero.  
  
 `lpszName`  
 O nome do campo no conjunto de registros, pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa "não ter nenhum valor."  
  
 Para obter informações relacionadas, consulte os tópicos "Campo Object" e "Valor de propriedade" na Ajuda do DAO.  
  
##  <a name="a-namesetlockingmodea--cdaorecordsetsetlockingmode"></a><a name="setlockingmode"></a>CDaoRecordset::SetLockingMode  
 Chame essa função de membro para definir o tipo de bloqueio do conjunto de registros.  
  
```  
void SetLockingMode(BOOL bPessimistic);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bPessimistic*  
 Um sinalizador que indica o tipo de bloqueio.  
  
### <a name="remarks"></a>Comentários  
 Quando o bloqueio pessimista está em vigor, a página de 2K que contém o registro que você está editando é bloqueada assim que você chamar o **editar** função de membro. A página é desbloqueada quando você chama o **atualização** ou **fechar** função de membro ou qualquer uma das operações de mover ou localizar.  
  
 Quando otimista proteção está em vigor, a página de 2K que contém o registro está bloqueada somente enquanto o registro estiver sendo atualizado com o **atualização** função de membro.  
  
 Se uma página estiver bloqueada, nenhum outro usuário poderá editar registros na mesma página. Se você chamar `SetLockingMode` e passar um valor diferente de zero e outro usuário já tiver bloqueado a página, uma exceção é gerada quando você chamar **editar**. Outros usuários podem ler dados de páginas bloqueadas.  
  
 Se você chamar `SetLockingMode` com um valor zero e posterior chamar **atualização** enquanto a página está bloqueada por outro usuário, ocorre uma exceção. Para ver as alterações feitas ao seu registro por outro usuário (e perder as alterações), chame o `SetBookmark` a função de membro com o valor do indicador do registro atual.  
  
 Ao trabalhar com fontes de dados ODBC, o modo de bloqueio é sempre otimista.  
  
##  <a name="a-namesetparamvaluea--cdaorecordsetsetparamvalue"></a><a name="setparamvalue"></a>CDaoRecordset::SetParamValue  
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
  
 Especifique o valor a ser definido como um `COleVariant` objeto. Para obter informações sobre como definir o valor desejado e digite sua `COleVariant` de objeto, consulte a classe [COleVariant](../../mfc/reference/colevariant-class.md). Observe que, se você não estiver criando um conjunto de registros UNICODE, o `COleVariant` objeto deve ser declarado explicitamente ANSI. Isso pode ser feito usando o [COleVariant::COleVariant](../../mfc/reference/colevariant-class.md#colevariant)**(** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou usando o **COleVariant** função [SetString](../../mfc/reference/colevariant-class.md#setstring)**(** `lpszSrc` **,** `vtSrc` **)** com `vtSrc` definida como `VT_BSTRT`.  
  
##  <a name="a-namesetparamvaluenulla--cdaorecordsetsetparamvaluenull"></a><a name="setparamvaluenull"></a>CDaoRecordset::SetParamValueNull  
 Chame essa função de membro para definir o parâmetro como um valor nulo.  
  
```  
void SetParamValueNull(int nIndex);  
void SetParamValueNull(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do campo no conjunto de registros, para pesquisa de índice baseado em zero.  
  
 `lpszName`  
 O nome do campo no conjunto de registros, pesquisa por nome.  
  
### <a name="remarks"></a>Comentários  
 C++ **nulo** não é o mesmo como Null, que, na terminologia de banco de dados, significa "não ter nenhum valor."  
  
##  <a name="a-namesetpercentpositiona--cdaorecordsetsetpercentposition"></a><a name="setpercentposition"></a>CDaoRecordset::SetPercentPosition  
 Chame essa função de membro para definir um valor que altera a localização aproximada do registro atual no objeto recordset com base em uma porcentagem dos registros no conjunto de registros.  
  
```  
void SetPercentPosition(float fPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fPosition*  
 Um número entre 0 e 100.  
  
### <a name="remarks"></a>Comentários  
 Ao trabalhar com um tipo dynaset ou recordset tipo snapshot, primeiro preencher o conjunto de registros, movendo para o último registro antes de chamar `SetPercentPosition`. Se você chamar `SetPercentPosition` antes de preencher totalmente o conjunto de registros, a quantidade de movimento é em relação ao número de registros acessados conforme indicado pelo valor do [GetRecordCount](#getrecordcount). Você pode mover para o último registro chamando `MoveLast`.  
  
 Depois de você chamar `SetPercentPosition`, o registro na posição aproximada correspondente a esse valor se torna atual.  
  
> [!NOTE]
>  Chamando `SetPercentPosition` para mover o registro atual para um registro específico em um conjunto de registros não é recomendado. Chamar o [SetBookmark](#setbookmark) função do membro em vez disso.  
  
 Para obter informações relacionadas, consulte o tópico "Propriedade PercentPosition" na Ajuda do DAO.  
  
##  <a name="a-nameupdatea--cdaorecordsetupdate"></a><a name="update"></a>CDaoRecordset::Update  
 Chame essa função de membro após uma chamada para o `AddNew` ou **editar** função de membro.  
  
```  
virtual void Update();
```  
  
### <a name="remarks"></a>Comentários  
 Essa chamada é necessária para concluir o `AddNew` ou **editar** operação.  
  
 Ambos `AddNew` e **editar** preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar a fonte de dados. **Atualização** salva os dados. Apenas os campos marcados ou detectado como alterado são atualizados.  
  
 Se a fonte de dados oferece suporte a transações, você pode fazer o **atualização** chamar (e seu correspondente `AddNew` ou **editar** chamar) faz parte de uma transação.  
  
> [!CAUTION]
>  Se você chamar **atualização** sem primeiro chamar `AddNew` ou **editar**, **atualização** lança um `CDaoException`. Se você chamar `AddNew` ou **editar**, você deve chamar **atualização** antes de chamar [MoveNext](#movenext) ou fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.  
  
 Quando o objeto recordset pessimistically está bloqueado em um ambiente multiusuário, o registro permanecerá bloqueado da hora **editar** é usado até que a atualização for concluída. Se o conjunto de registros suporá estiver bloqueado, o registro está bloqueado e comparado com o registro anterior à edição antes que ele seja atualizado no banco de dados. Se o registro foi alterado desde que você chamou **editar**, o **atualização** Falha na operação e MFC lança uma exceção. Você pode alterar o modo de bloqueio com `SetLockingMode`.  
  
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

