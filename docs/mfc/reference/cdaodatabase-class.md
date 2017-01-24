---
title: "Classe de CDaoDatabase | Microsoft Docs"
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
  - "CDaoDatabase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoDatabase"
  - "Classe de CDaoDatabase, e o espaço de trabalho"
  - "Classe de CDaoDatabase, CONTRA. a classe de CDatabase"
  - "Classe de CDatabase, CONTRA. a classe de CDaoDatabase"
  - "banco de dados classes [C++], DAO"
ms.assetid: 8ff5b342-964d-449d-bef1-d0ff56aadf6d
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoDatabase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma conexão a um banco de dados através da qual você pode operar nos dados.  
  
## Sintaxe  
  
```  
class CDaoDatabase : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoDatabase::CDaoDatabase](../Topic/CDaoDatabase::CDaoDatabase.md)|Constrói um objeto de `CDaoDatabase` .  Chame **Abrir** o objeto para se conectar a um banco de dados.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoDatabase::CanTransact](../Topic/CDaoDatabase::CanTransact.md)|Retorna diferente de zero se as transações de suporte de banco de dados.|  
|[CDaoDatabase::CanUpdate](../Topic/CDaoDatabase::CanUpdate.md)|Retorna diferente de zero se o objeto de `CDaoDatabase` é não atualizável \(somente leitura\).|  
|[CDaoDatabase::Close](../Topic/CDaoDatabase::Close.md)|Fecha a conexão de banco de dados.|  
|[CDaoDatabase::Create](../Topic/CDaoDatabase::Create.md)|Cria o objeto de banco de dados subjacente de DAO e inicializa o objeto de `CDaoDatabase` .|  
|[CDaoDatabase::CreateRelation](../Topic/CDaoDatabase::CreateRelation.md)|Define um novo relacionamento entre as tabelas no banco de dados.|  
|[CDaoDatabase::DeleteQueryDef](../Topic/CDaoDatabase::DeleteQueryDef.md)|Exclui um objeto de querydef salvo na coleção de QueryDefs de banco de dados.|  
|[CDaoDatabase::DeleteRelation](../Topic/CDaoDatabase::DeleteRelation.md)|Exclui um relacionamento entre tabelas existente no banco de dados.|  
|[CDaoDatabase::DeleteTableDef](../Topic/CDaoDatabase::DeleteTableDef.md)|Exclui a definição de uma tabela no banco de dados.  Isso exclui a tabela real e todos os seus dados.|  
|[CDaoDatabase::Execute](../Topic/CDaoDatabase::Execute.md)|Executa uma consulta ação.  Chamada **Executar** para uma consulta que retorna os resultados gera uma exceção.|  
|[CDaoDatabase::GetConnect](../Topic/CDaoDatabase::GetConnect.md)|Retorna a cadeia de conexão usada para se conectar o objeto de `CDaoDatabase` a um banco de dados.  Usado para ODBC.|  
|[CDaoDatabase::GetName](../Topic/CDaoDatabase::GetName.md)|Retorna o nome do banco de dados atualmente em uso.|  
|[CDaoDatabase::GetQueryDefCount](../Topic/CDaoDatabase::GetQueryDefCount.md)|Retorna o número de consultas definidas para o banco de dados.|  
|[CDaoDatabase::GetQueryDefInfo](../Topic/CDaoDatabase::GetQueryDefInfo.md)|Retorna informações sobre uma consulta específicada definida no banco de dados.|  
|[CDaoDatabase::GetQueryTimeout](../Topic/CDaoDatabase::GetQueryTimeout.md)|Retorna o número de segundos após o qual de tempo limite do das operações consulta de banco de dados.  Afeta aberto qualquer subseqüente, adicione novo, atualização, e operações de edição e outras operações em fontes de dados ODBC \(somente\) como chamadas de **Executar** .|  
|[CDaoDatabase::GetRecordsAffected](../Topic/CDaoDatabase::GetRecordsAffected.md)|Retorna o número de registros afetados pela última atualização, editar, ou adicione a operação ou por uma chamada a **Executar**.|  
|[CDaoDatabase::GetRelationCount](../Topic/CDaoDatabase::GetRelationCount.md)|Retorna o número de relacionamentos entre tabelas definidas no banco de dados.|  
|[CDaoDatabase::GetRelationInfo](../Topic/CDaoDatabase::GetRelationInfo.md)|Retorna informações sobre uma relação especificada definida entre tabelas no banco de dados.|  
|[CDaoDatabase::GetTableDefCount](../Topic/CDaoDatabase::GetTableDefCount.md)|Retorna o número de tabelas definido no banco de dados.|  
|[CDaoDatabase::GetTableDefInfo](../Topic/CDaoDatabase::GetTableDefInfo.md)|Retorna informações sobre uma tabela especificada no banco de dados.|  
|[CDaoDatabase::GetVersion](../Topic/CDaoDatabase::GetVersion.md)|Retorna a versão do mecanismo de banco de dados associado com o banco de dados.|  
|[CDaoDatabase::IsOpen](../Topic/CDaoDatabase::IsOpen.md)|Retorna diferente de zero se o objeto de `CDaoDatabase` é atualmente conectado a um banco de dados.|  
|[CDaoDatabase::Open](../Topic/CDaoDatabase::Open.md)|Estabelece uma conexão a um banco de dados.|  
|[CDaoDatabase::SetQueryTimeout](../Topic/CDaoDatabase::SetQueryTimeout.md)|Define o número de segundos após o qual as operações de consulta de banco de dados \(em fontes de dados ODBC somente\) tempo limite.  Afeta aberto qualquer subseqüente, adicione novo, a atualização, e as operações de exclusão.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoDatabase::m\_pDAODatabase](../Topic/CDaoDatabase::m_pDAODatabase.md)|Um ponteiro para o objeto de banco de dados subjacente de DAO.|  
|[CDaoDatabase::m\_pWorkspace](../Topic/CDaoDatabase::m_pWorkspace.md)|Um ponteiro para o objeto de [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) que contém o banco de dados e define o espaço de transação.|  
  
## Comentários  
 Para obter mais informações sobre formatos de banco de dados compatíveis, consulte a função de membro de [GetName](../Topic/CDaoWorkspace::GetName.md) .  Você pode ter um ou mais objetos de `CDaoDatabase` ativos em uma hora em um determinado “espaço de trabalho,” representado por um objeto de [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) .  O espaço de trabalho mantém uma coleção de objetos de banco de dados abertos, chamada a coleção de bancos de dados.  
  
> [!NOTE]
>  As classes de banco de dados MFC DAO são distintas de classes do banco de dados MFC baseado em ODBC.  Todos os nomes de classe de banco de dados de DAO têm o prefixo “CDao”.  A classe `CDaoDatabase` fornece uma interface semelhante a da classe [CDatabase](../../mfc/reference/cdatabase-class.md)ODBC.  A principal diferença é que `CDatabase` acessa o DBMS através de Open Database Connectivity \(ODBC\) e um driver ODBC para esse DBMS.  Dados dos acessos de`CDaoDatabase` através de um objeto \(DAO\) de acesso a dados com base no mecanismo de banco de dados Microsoft Jet.  Em geral, as classes MFC com base em DAO mais são capazes das classes MFC baseado em ODBC; as classes base DAO\- podem acessar os dados, incluindo através dos drivers ODBC, através de seu próprio mecanismo de banco de dados.  As classes base DAO\- também suporta operações language \(DDL\) de definição de dados, como adicionar tabelas por meio de classes, sem precisar chamar diretamente DAO.  
  
## Uso  
 Você pode criar objetos de banco de dados, implicitamente quando você cria objetos do conjunto de registros.  Mas você também pode criar objetos de banco de dados explicitamente.  Para usar explicitamente um banco de dados existente com `CDaoDatabase`, faça qualquer um dos seguintes:  
  
-   Construir um objeto de `CDaoDatabase` , passando um ponteiro para um objeto de abertura de [CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md) .  
  
-   Ou construir um objeto de `CDaoDatabase` sem especificar o espaço de trabalho \(o MFC cria um objeto temporário de espaço de trabalho\).  
  
 Para criar um novo banco de dados do Microsoft Jet \(.MDB\), construir um objeto de `CDaoDatabase` e chamar a função de membro de [Criar](../Topic/CDaoDatabase::Create.md) .  *Não* chamar **Abrir** após **Criar**.  
  
 Para abrir um banco de dados existente, construir um objeto de `CDaoDatabase` e chamar a função de membro de [Abrir](../Topic/CDaoDatabase::Open.md) .  
  
 Qualquer uma de essas técnicas acrescentam o objeto de banco de dados de DAO a bancos de dados coleção de espaço de trabalho e abrir uma conexão a dados.  Quando você constrói em objetos de [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md), de [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md), ou de [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) para operar no banco de dados de rede, passar os construtores para esses objetos um ponteiro para seu objeto de `CDaoDatabase` .  Quando você terminar usar a conexão, chame a função de membro de [Fechar](../Topic/CDaoDatabase::Close.md) e destrua o objeto de `CDaoDatabase` .  **Fechar** fecha todos os conjuntos de registros que não se você fechar anteriormente.  
  
## Transações  
 O processamento de transações de banco de dados é fornecido no nível de espaço de trabalho — consulte as funções de membro de [BeginTrans](../Topic/CDaoWorkspace::BeginTrans.md), de [CommitTrans](../Topic/CDaoWorkspace::CommitTrans.md), e de [Rollback](../Topic/CDaoWorkspace::Rollback.md) da classe `CDaoWorkspace`.  
  
## Conexões ODBC  
 A maneira recomendada para trabalhar com fontes de dados ODBC é anexar externos tabelas em um banco de dados Microsoft Jet \(.MDB\).  
  
## Coleções  
 Cada banco de dados mantém suas próprias coleções de tabledef, de querydef, o conjunto de registros, e objetos de relacionamento.  A classe `CDaoDatabase` fornece funções de membro para manipular esses objetos.  
  
> [!NOTE]
>  Os objetos são armazenados em DAO, não no objeto de banco de dados MFC.  O MFC fornece classes para o tabledef, o querydef, e objetos do recordset mas não para objetos de relacionamento.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDaoDatabase`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe de CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe de CDaoException](../../mfc/reference/cdaoexception-class.md)