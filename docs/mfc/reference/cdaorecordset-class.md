---
title: "Classe de CDaoRecordset | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CDaoRecordset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoRecordset"
  - "registros, CDaoRecordSet"
  - "conjuntos de registros, tipos"
ms.assetid: 2322067f-1027-4662-a5d7-aa2fc7488630
caps.latest.revision: 26
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoRecordset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa um conjunto de registros selecionados de uma fonte de dados.  
  
## Sintaxe  
  
```  
  
class CDaoRecordset : public CObject  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoRecordset::CDaoRecordset](../Topic/CDaoRecordset::CDaoRecordset.md)|Constrói um objeto de `CDaoRecordset` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoRecordset::AddNew](../Topic/CDaoRecordset::AddNew.md)|Prepara\-se adicionando um novo registro.  Chamada [Atualizar](../Topic/CDaoRecordset::Update.md) para concluir a adição.|  
|[CDaoRecordset::CanAppend](../Topic/CDaoRecordset::CanAppend.md)|Retorna diferente de zero se os novos registros podem ser adicionados ao conjunto de registros através da função de membro de [AddNew](../Topic/CDaoRecordset::AddNew.md) .|  
|[CDaoRecordset::CanBookmark](../Topic/CDaoRecordset::CanBookmark.md)|Retorna diferente de zero se o recordset suporta indicadores.|  
|[CDaoRecordset::CancelUpdate](../Topic/CDaoRecordset::CancelUpdate.md)|Cancela todas as atualizações pendentes devido a uma operação de [Editar](../Topic/CDaoRecordset::Edit.md) ou de [AddNew](../Topic/CDaoRecordset::AddNew.md) .|  
|[CDaoRecordset::CanRestart](../Topic/CDaoRecordset::CanRestart.md)|Retorna diferente de zero se [Requery](../Topic/CDaoRecordset::Requery.md) pode ser chamado para executar novamente a consulta ao conjunto de registros.|  
|[CDaoRecordset::CanScroll](../Topic/CDaoRecordset::CanScroll.md)|Retorna diferente de zero se você pode percorrer os registros.|  
|[CDaoRecordset::CanTransact](../Topic/CDaoRecordset::CanTransact.md)|Retorna diferente de zero se a fonte de dados suportar transações.|  
|[CDaoRecordset::CanUpdate](../Topic/CDaoRecordset::CanUpdate.md)|Retorna diferente de zero se o recordset pode ser atualizado \(você pode adicionar, atualizar ou excluir registros,\).|  
|[CDaoRecordset::Close](../Topic/CDaoRecordset::Close.md)|Fecha o conjunto de registros.|  
|[CDaoRecordset::Delete](../Topic/CDaoRecordset::Delete.md)|Exclui o registro atual do conjunto de registros.  Você deve explicitamente rolar outro registro após a exclusão.|  
|[CDaoRecordset::DoFieldExchange](../Topic/CDaoRecordset::DoFieldExchange.md)|Chamado para trocar dados \(em ambas as direções\) entre os membros de dados do campo do conjunto de registros e o registro correspondente na fonte de dados.  Troca do campo do registro DAO implements \(DFX\).|  
|[CDaoRecordset::Edit](../Topic/CDaoRecordset::Edit.md)|Para prepara\-se alterações para o registro atual.  Chamada **Atualizar** para concluir a edição.|  
|[CDaoRecordset::FillCache](../Topic/CDaoRecordset::FillCache.md)|Preenche todo o ou parte cache local para um objeto do conjunto de registros que contém dados de uma fonte de dados ODBC.|  
|[CDaoRecordset::Find](../Topic/CDaoRecordset::Find.md)|Localiza o primeiro, próximo local, ou anterior, o último de uma cadeia de caracteres específica em um conjunto de registros de dynaset\- tipo que satisfaz os critérios específicos e o torna que registra o registro atual.|  
|[CDaoRecordset::FindFirst](../Topic/CDaoRecordset::FindFirst.md)|Localiza o primeiro registro em um conjunto de registros de dynaset\- tipo ou de instantâneo\- tipo que satisfaz os critérios específicos e o torna que registra o registro atual.|  
|[CDaoRecordset::FindLast](../Topic/CDaoRecordset::FindLast.md)|Localize o último registro em um conjunto de registros de dynaset\- tipo ou de instantâneo\- tipo que satisfaz os critérios específicos e o torna que registra o registro atual.|  
|[CDaoRecordset::FindNext](../Topic/CDaoRecordset::FindNext.md)|Localiza o registro a seguir em um conjunto de registros de dynaset\- tipo ou de instantâneo\- tipo que satisfaz os critérios específicos e o torna que registra o registro atual.|  
|[CDaoRecordset::FindPrev](../Topic/CDaoRecordset::FindPrev.md)|Localiza o registro anterior em um conjunto de registros de dynaset\- tipo ou de instantâneo\- tipo que satisfaz os critérios específicos e o torna que registra o registro atual.|  
|[CDaoRecordset::GetAbsolutePosition](../Topic/CDaoRecordset::GetAbsolutePosition.md)|Retorna o número de registro do registro atual de um objeto do conjunto de registros.|  
|[CDaoRecordset::GetBookmark](../Topic/CDaoRecordset::GetBookmark.md)|Retorna um valor que representa o indexador em um registro.|  
|[CDaoRecordset::GetCacheSize](../Topic/CDaoRecordset::GetCacheSize.md)|Retorna um valor que especifica o número de registros em um conjunto de registros de dynaset\- tipo que contém os dados a serem armazenados em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::GetCacheStart](../Topic/CDaoRecordset::GetCacheStart.md)|Retorna um valor que especifica o indicador do primeiro registro no conjunto de registros a serem armazenados em cache.|  
|[CDaoRecordset::GetCurrentIndex](../Topic/CDaoRecordset::GetCurrentIndex.md)|Retorna `CString` que contém o nome do índice usou recentemente em um indexado, com tipo `CDaoRecordset`.|  
|[CDaoRecordset::GetDateCreated](../Topic/CDaoRecordset::GetDateCreated.md)|Retorna a data e a hora que a tabela de base subjacente um objeto de `CDaoRecordset` foi criada|  
|[CDaoRecordset::GetDateLastUpdated](../Topic/CDaoRecordset::GetDateLastUpdated.md)|Retorna a data e hora da alteração mais recente feita ao design de uma tabela de base subjacente um objeto de `CDaoRecordset` .|  
|[CDaoRecordset::GetDefaultDBName](../Topic/CDaoRecordset::GetDefaultDBName.md)|Retorna o nome da fonte de dados padrão.|  
|[CDaoRecordset::GetDefaultSQL](../Topic/CDaoRecordset::GetDefaultSQL.md)|Chamado para obter a cadeia de caracteres SQL padrão para executar.|  
|[CDaoRecordset::GetEditMode](../Topic/CDaoRecordset::GetEditMode.md)|Retorna um valor que indica o estado de edição para o registro atual.|  
|[CDaoRecordset::GetFieldCount](../Topic/CDaoRecordset::GetFieldCount.md)|Retorna um valor que representa o número de campos em um conjunto de registros.|  
|[CDaoRecordset::GetFieldInfo](../Topic/CDaoRecordset::GetFieldInfo.md)|Retorna tipos específicos de informações sobre os campos no conjunto de registros.|  
|[CDaoRecordset::GetFieldValue](../Topic/CDaoRecordset::GetFieldValue.md)|Retorna o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::GetIndexCount](../Topic/CDaoRecordset::GetIndexCount.md)|Retorna o número de índices em uma tabela que é a base de um conjunto de registros.|  
|[CDaoRecordset::GetIndexInfo](../Topic/CDaoRecordset::GetIndexInfo.md)|Retorna vários tipos de informações sobre um índice.|  
|[CDaoRecordset::GetLastModifiedBookmark](../Topic/CDaoRecordset::GetLastModifiedBookmark.md)|Usado para determinar o registro recentemente adicionados ou atualizado.|  
|[CDaoRecordset::GetLockingMode](../Topic/CDaoRecordset::GetLockingMode.md)|Retorna um valor que indica o tipo de bloqueio que é aplicado durante a edição.|  
|[CDaoRecordset::GetName](../Topic/CDaoRecordset::GetName.md)|Retorna `CString` que contém o nome do conjunto de registros.|  
|[CDaoRecordset::GetParamValue](../Topic/CDaoRecordset::GetParamValue.md)|Recupera o valor do parâmetro atual especificado armazenado no objeto subjacente de DAOParameter.|  
|[CDaoRecordset::GetPercentPosition](../Topic/CDaoRecordset::GetPercentPosition.md)|Retorna a posição do registro atual como uma porcentagem do número total de registros.|  
|[CDaoRecordset::GetRecordCount](../Topic/CDaoRecordset::GetRecordCount.md)|Retorna o número de registros acessados em um objeto do conjunto de registros.|  
|[CDaoRecordset::GetSQL](../Topic/CDaoRecordset::GetSQL.md)|Obtém a cadeia de caracteres SQL usada para selecionar registros para o conjunto de registros.|  
|[CDaoRecordset::GetType](../Topic/CDaoRecordset::GetType.md)|Chamado para determinar o tipo de um conjunto de registros: com tipo, dynaset\- tipo, ou instantâneo\- tipo.|  
|[CDaoRecordset::GetValidationRule](../Topic/CDaoRecordset::GetValidationRule.md)|Retorna `CString` que contém o valor que valida os dados enquanto é inserido em um campo.|  
|[CDaoRecordset::GetValidationText](../Topic/CDaoRecordset::GetValidationText.md)|Recupera o texto que é exibido quando uma regra de validação não é satisfeita.|  
|[CDaoRecordset::IsBOF](../Topic/CDaoRecordset::IsBOF.md)|Retorna diferente de zero se o conjunto de registros está posicionado antes do primeiro registro.  Não há nenhum registro atual.|  
|[CDaoRecordset::IsDeleted](../Topic/CDaoRecordset::IsDeleted.md)|Retorna diferente de zero se o conjunto de registros é posicionado em um registro excluído.|  
|[CDaoRecordset::IsEOF](../Topic/CDaoRecordset::IsEOF.md)|Retorna diferente de zero se o recordset foi posicionado após o último registro.  Não há nenhum registro atual.|  
|[CDaoRecordset::IsFieldDirty](../Topic/CDaoRecordset::IsFieldDirty.md)|Retorna diferente de zero se o campo especificado no registro atual foi alterado.|  
|[CDaoRecordset::IsFieldNull](../Topic/CDaoRecordset::IsFieldNull.md)|Retorna diferente de zero se o campo especificado no registro atual é zero \(não ter nenhum valor\).|  
|[CDaoRecordset::IsFieldNullable](../Topic/CDaoRecordset::IsFieldNullable.md)|Retorna diferente de zero se o campo especificado no registro atual pode ser definido como nulo \(não ter nenhum valor\).|  
|[CDaoRecordset::IsOpen](../Topic/CDaoRecordset::IsOpen.md)|Retorna diferente de zero se [Abrir](../Topic/CDaoRecordset::Open.md) tiver sido chamado anteriormente.|  
|[CDaoRecordset::Move](../Topic/CDaoRecordset::Move.md)|Posiciona o conjunto de registros a um número de registros especificado do registro atual em ambas as direções.|  
|[CDaoRecordset::MoveFirst](../Topic/CDaoRecordset::MoveFirst.md)|Posiciona o registro atual no primeiro registro no conjunto de registros.|  
|[CDaoRecordset::MoveLast](../Topic/CDaoRecordset::MoveLast.md)|Posiciona o registro atual no último registro no conjunto de registros.|  
|[CDaoRecordset::MoveNext](../Topic/CDaoRecordset::MoveNext.md)|Posiciona o registro atual no próximo registro no conjunto de registros.|  
|[CDaoRecordset::MovePrev](../Topic/CDaoRecordset::MovePrev.md)|Posiciona o registro atual no registro anterior no conjunto de registros.|  
|[CDaoRecordset::Open](../Topic/CDaoRecordset::Open.md)|Cria um novo conjunto de registros de uma tabela, um dynaset, ou um instantâneo.|  
|[CDaoRecordset::Requery](../Topic/CDaoRecordset::Requery.md)|Executa a consulta ao conjunto de registros novamente para atualizar os registros selecionados.|  
|[CDaoRecordset::Seek](../Topic/CDaoRecordset::Seek.md)|Localiza o registro em um objeto indexado do conjunto de registros da tabela de tipo que satisfaz os critérios específicos para o índice atual e o torna que registra o registro atual.|  
|[CDaoRecordset::SetAbsolutePosition](../Topic/CDaoRecordset::SetAbsolutePosition.md)|Define o número de registro do registro atual de um objeto do conjunto de registros.|  
|[CDaoRecordset::SetBookmark](../Topic/CDaoRecordset::SetBookmark.md)|Posiciona o conjunto de registros em um registro que contém o indexador especificado.|  
|[CDaoRecordset::SetCacheSize](../Topic/CDaoRecordset::SetCacheSize.md)|Define um valor que especifica o número de registros em um conjunto de registros de dynaset\- tipo que contém os dados a serem armazenados em cache localmente de uma fonte de dados ODBC.|  
|[CDaoRecordset::SetCacheStart](../Topic/CDaoRecordset::SetCacheStart.md)|Define um valor que especifica o indicador do primeiro registro no conjunto de registros a serem armazenados em cache.|  
|[CDaoRecordset::SetCurrentIndex](../Topic/CDaoRecordset::SetCurrentIndex.md)|Chamado para definir um índice em um conjunto de registros da tabela de tipo.|  
|[CDaoRecordset::SetFieldDirty](../Topic/CDaoRecordset::SetFieldDirty.md)|Marca o campo especificado no registro atual como modificado.|  
|[CDaoRecordset::SetFieldNull](../Topic/CDaoRecordset::SetFieldNull.md)|Define o valor do campo especificado no registro atual como nulo \(não ter nenhum valor\).|  
|[CDaoRecordset::SetFieldValue](../Topic/CDaoRecordset::SetFieldValue.md)|Defina o valor de um campo em um conjunto de registros.|  
|[CDaoRecordset::SetFieldValueNull](../Topic/CDaoRecordset::SetFieldValueNull.md)|Defina o valor de um campo em um conjunto de registros como nulo.  \(não ter nenhum valor\).|  
|[CDaoRecordset::SetLockingMode](../Topic/CDaoRecordset::SetLockingMode.md)|Define um valor que indica o tipo de bloqueio para colocar em efeito durante a edição.|  
|[CDaoRecordset::SetParamValue](../Topic/CDaoRecordset::SetParamValue.md)|Defina o valor do parâmetro atual especificado armazenado no objeto subjacente de DAOParameter|  
|[CDaoRecordset::SetParamValueNull](../Topic/CDaoRecordset::SetParamValueNull.md)|Defina o valor do parâmetro atual especificado como nulo \(não ter nenhum valor\).|  
|[CDaoRecordset::SetPercentPosition](../Topic/CDaoRecordset::SetPercentPosition.md)|Define a posição do registro atual para um local que corresponde a uma porcentagem do número total de registros em um conjunto de registros.|  
|[CDaoRecordset::Update](../Topic/CDaoRecordset::Update.md)|Termina uma operação de `AddNew` ou de **Editar** salvando os novos dados ou editados na fonte de dados.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoRecordset::m\_bCheckCacheForDirtyFields](../Topic/CDaoRecordset::m_bCheckCacheForDirtyFields.md)|Contém um sinalizador que indica se campos são marcadas automaticamente como alterados.|  
|[CDaoRecordset::m\_nFields](../Topic/CDaoRecordset::m_nFields.md)|Contém o número de membros de dados do campo na classe do conjunto de registros e o número de colunas selecionadas pelo conjunto de registros da fonte de dados.|  
|[CDaoRecordset::m\_nParams](../Topic/CDaoRecordset::m_nParams.md)|Contém o número de membros de dados do parâmetro na classe do conjunto de registros — o número de parâmetros passados com a consulta ao conjunto de registros|  
|[CDaoRecordset::m\_pDAORecordset](../Topic/CDaoRecordset::m_pDAORecordset.md)|Um ponteiro para a interface de DAO que é subjacente ao objeto do conjunto de registros.|  
|[CDaoRecordset::m\_pDatabase](../Topic/CDaoRecordset::m_pDatabase.md)|O banco de dados de origem para este conjunto de resultados.  Contém um ponteiro para um objeto de [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) .|  
|[CDaoRecordset::m\_strFilter](../Topic/CDaoRecordset::m_strFilter.md)|Contém uma cadeia de caracteres usada para construir uma instrução SQL **WHERE** .|  
|[CDaoRecordset::m\_strSort](../Topic/CDaoRecordset::m_strSort.md)|Contém uma cadeia de caracteres usada para construir uma instrução SQL **ORDENAR POR** .|  
  
## Comentários  
 Conhecido como “conjuntos de registros,” os objetos de `CDaoRecordset` estão disponíveis em três formas:  
  
-   Os conjuntos de registros de tipo representam uma tabela com base que você pode usar para examinar, adicionar, modificar, ou excluir registros de uma única tabela de banco de dados.  
  
-   Os conjuntos de registros de Dynaset\- tipo é o resultado de uma consulta que pode ter registros atualizável.  Esses conjuntos de registros são um conjunto de registros que você pode usar para examinar, adicionar, modificar, ou excluir registros de uma tabela de banco de dados ou das tabelas subjacentes.  Os conjuntos de registros de Dynaset\- tipo podem conter campos de uma ou mais tabelas em um banco de dados.  
  
-   Os conjuntos de registros de Instantâneo\- tipo são uma cópia estática de um conjunto de registros que você pode usar para localizar dados ou gerar relatórios.  Esses conjuntos de registros podem conter campos de uma ou mais tabelas em um banco de dados mas não podem ser atualizados.  
  
 Cada formulário do recordset representa um conjunto de registros corrigidos no conjunto de registros é aberto.  Quando você colocar um registro em um conjunto de registros da tabela ou tipo em um conjunto de registros de dynaset\- tipo, reflete as alterações feitas ao registro depois que o conjunto de registros é aberto, por outros usuários ou por outros conjuntos de registros em seu aplicativo.  \(O conjunto de registros de instantâneo\- de tipo não pode ser atualizado.\) Você pode usar `CDaoRecordset` diretamente ou derivar uma classe específica do aplicativo do conjunto de registros de `CDaoRecordset`.  Você pode então:  
  
-   Scroll através dos registros.  
  
-   Definir um índice e procura por registros rapidamente usando [Pesquisa](../Topic/CDaoRecordset::Seek.md) \(conjuntos de registros de tipo com somente\).  
  
-   Localizar registros com base em uma comparação de cadeias de caracteres: "\<", "\<\=", "\=", "\>\=", ou "\>" \(conjuntos de registros de dynaset\- tipo e tipo de instantâneo\-\).  
  
-   Atualizar os registros e especificar um modo de bloqueio \(exceto conjuntos de registros de instantâneo\- tipo\).  
  
-   Filtrar o conjunto de registros para restringir esse os registros ele selecione de esses disponíveis na fonte de dados.  
  
-   Classificar o conjunto de registros.  
  
-   Parametrizar o conjunto de registros para personalizar sua seleção com informações não conhecido até o tempo de execução.  
  
 As fontes de `CDaoRecordset` uma interface semelhante a da classe `CRecordset`.  A principal diferença é que os dados dos acessos de `CDaoRecordset` da classe com um acesso a dados \(DAO\) objeto com base no OLE.  A classe `CRecordset` acessa o DBMS através de Open Database Connectivity \(ODBC\) e um driver ODBC para esse DBMS.  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  Você ainda pode acessar fontes de dados ODBC com as classes de DAO; as classes de DAO geralmente oferecem recursos superiores como são específicas para o mecanismo de banco de dados Microsoft Jet.  
  
 Você pode usar `CDaoRecordset` diretamente ou derivar uma classe de `CDaoRecordset`.  Para usar em ambos os casos uma classe de conjunto de registros, abra um banco de dados e crie um objeto do conjunto de registros, passando o construtor um ponteiro para seu objeto de `CDaoDatabase` .  Você também pode criar um objeto de `CDaoRecordset` e permitir que o MFC criar um objeto temporário de `CDaoDatabase` para você.  Chame a função de membro de [Abrir](../Topic/CDaoRecordset::Open.md) do conjunto de registros, especificando se o objeto é um conjunto de registros de tipo, com um conjunto de registros de dynaset\- tipo, ou um conjunto de registros de instantâneo\- tipo.  A chamada **Abrir** seleciona dados do banco de dados e retorna o primeiro registro.  
  
 Use os membros das funções de membro e dados de objeto a rolagem pelos registros e opere\-os sobre.  As operações disponíveis dependem se o objeto é um conjunto de registros de tipo, com um conjunto de registros de dynaset\- tipo, ou um conjunto de registros de instantâneo\- tipo, e se é ou atualizável somente leitura — isso depende do recurso de banco de dados ou da fonte de dados ODBC \(ODBC\).  Para atualizar registros que podem ter sido adicionado ou modificados desde que a chamada de **Abrir** , chama a função de membro de [Requery](../Topic/CDaoRecordset::Requery.md) do objeto.  Chame a função de membro de **Fechar** do objeto e destrua o objeto quando você terminar com ele.  
  
 Troca do campo do registro do  usa DAO de`CDaoRecordset` \(DFX\) para oferecer suporte à leitura e atualização de campos do registro através de membros tipo seguro C\+\+ do seu `CDaoRecordset` ou de `CDaoRecordset`\- classe derivada.  Você também pode implementar a associação dinâmica de colunas em um banco de dados sem usar o mecanismo de DFX usando [GetFieldValue](../Topic/CDaoRecordset::GetFieldValue.md) e [SetFieldValue](../Topic/CDaoRecordset::SetFieldValue.md).  
  
 Para informações relacionadas, consulte o tópico “object conjunto de registros” na ajuda de DAO.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDaoRecordset`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe de CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)