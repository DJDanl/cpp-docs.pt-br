---
title: "Classe de CDatabase | Microsoft Docs"
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
  - "CDatabase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDatabase"
  - "banco de dados classes [C++], ODBC"
  - "conexões de banco de dados [C++], Classe de CDatabase"
  - "MFC [C++], ODBC"
  - "ODBC [C++], Classe de CDatabase"
  - "Classe de banco de dados ODBC"
ms.assetid: bd0de70a-e3c3-4441-bcaa-bbf434426ca8
caps.latest.revision: 24
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDatabase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma conexão a uma fonte de dados, com o qual você pode operar na fonte de dados.  
  
## Sintaxe  
  
```  
  
class CDatabase : public CObject  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDatabase::CDatabase](../Topic/CDatabase::CDatabase.md)|Constrói um objeto de `CDatabase` .  Você deve inicializar o objeto chamando `OpenEx` ou **Abrir**.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDatabase::BeginTrans](../Topic/CDatabase::BeginTrans.md)|Inicia uma transação “” — uma série de chamadas reversíveis a `AddNew`, a **Editar**, a **Excluir**, e funções de membro de **Atualizar** da classe `CRecordset` — na fonte de dados conectados.  A fonte de dados deve suportar transações para que **BeginTrans** tem qualquer efeito.|  
|[CDatabase::BindParameters](../Topic/CDatabase::BindParameters.md)|Permite que você posicione os parâmetros de associadas antes de chamar `CDatabase::ExecuteSQL`.|  
|[CDatabase::Cancel](../Topic/CDatabase::Cancel.md)|Cancela uma operação assíncrona ou processo de um segundo segmento.|  
|[CDatabase::CanTransact](../Topic/CDatabase::CanTransact.md)|Retorna diferente de zero se a fonte de dados suportar transações.|  
|[CDatabase::CanUpdate](../Topic/CDatabase::CanUpdate.md)|Retorna diferente de zero se o objeto de `CDatabase` é não atualizável \(somente leitura\).|  
|[CDatabase::Close](../Topic/CDatabase::Close.md)|Fecha a conexão da fonte de dados.|  
|[CDatabase::CommitTrans](../Topic/CDatabase::CommitTrans.md)|Termina uma transação iniciada por **BeginTrans**.  Os comandos na transação que modificam a fonte de dados é realizado.|  
|[CDatabase::ExecuteSQL](../Topic/CDatabase::ExecuteSQL.md)|Executa uma instrução SQL.  Nenhum registro de dados é retornado.|  
|[CDatabase::GetBookmarkPersistence](../Topic/CDatabase::GetBookmarkPersistence.md)|Identifica as operações com que os indicadores persistem em objetos do conjunto de registros.|  
|[: Getconnect](../Topic/CDatabase::GetConnect.md)|Retorna a cadeia de conexão ODBC usada para conectar o objeto de `CDatabase` a uma fonte de dados.|  
|[CDatabase::GetCursorCommitBehavior](../Topic/CDatabase::GetCursorCommitBehavior.md)|Identifica o efeito de enviar uma transação em um objeto de abertura do conjunto de registros.|  
|[CDatabase::GetCursorRollbackBehavior](../Topic/CDatabase::GetCursorRollbackBehavior.md)|Identifica o efeito de reverter uma transação em um objeto de abertura do conjunto de registros.|  
|[CDatabase::GetDatabaseName](../Topic/CDatabase::GetDatabaseName.md)|Retorna o nome do banco de dados atualmente em uso.|  
|[CDatabase::IsOpen](../Topic/CDatabase::IsOpen.md)|Retorna diferente de zero se o objeto de `CDatabase` é atualmente conectado a uma fonte de dados.|  
|[CDatabase::OnSetOptions](../Topic/CDatabase::OnSetOptions.md)|Chamado pela estrutura para definir opções de conexão padrão.  A implementação padrão define o valor de tempo limite de consulta.  Você pode estabelecer essas opções antemão chamando `SetQueryTimeout`.|  
|[CDatabase::Open](../Topic/CDatabase::Open.md)|Estabelece uma conexão a uma fonte de dados \(por meio de um driver ODBC\).|  
|[CDatabase::OpenEx](../Topic/CDatabase::OpenEx.md)|Estabelece uma conexão a uma fonte de dados \(por meio de um driver ODBC\).|  
|[CDatabase::Rollback](../Topic/CDatabase::Rollback.md)|Inverte de alterações feitas durante a transação atual.  A fonte de dados retorna ao seu estado anterior, conforme definido na chamada de **BeginTrans** , inalterado.|  
|[CDatabase::SetLoginTimeout](../Topic/CDatabase::SetLoginTimeout.md)|Define o número de segundos após o qual de um tempo limite do da tentativa de conexão da fonte de dados.|  
|[CDatabase::SetQueryTimeout](../Topic/CDatabase::SetQueryTimeout.md)|Define o número de segundos após o qual de tempo limite do das operações consulta de banco de dados.  Afeta todo o conjunto de registros subseqüentes **Abrir**, `AddNew`, **Editar**, e chamadas de **Excluir** .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDatabase::m\_hdbc](../Topic/CDatabase::m_hdbc.md)|Identificador de conexão Open Database Connectivity \(ODBC\) para uma fonte de dados.  Tipo **HDBC**.|  
  
## Comentários  
 Uma fonte de dados é uma instância específica de dados hospedados por qualquer sistema de gerenciamento de banco de dados \(DBMS\).  Os exemplos incluem o dBASE Microsoft SQL Server, Microsoft Access, de Borland, e o xBASE.  Você pode ter um ou mais objetos de `CDatabase` ativos em vez de no seu aplicativo.  
  
> [!NOTE]
>  Se você estiver trabalhando com acesso a dados objetos de classes \(DAO\) em vez das classes Open Database Connectivity \(ODBC\), use a classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) em vez de isso.  Para obter mais informações, consulte o artigo [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 Para usar `CDatabase`, construir um objeto de `CDatabase` e chamar a função de membro de `OpenEx` .  Isso abre uma conexão.  Quando você constrói em objetos de `CRecordset` para operar na fonte de dados conectado, passe o construtor do recordset um ponteiro para seu objeto de `CDatabase` .  Quando você terminar usar a conexão, chame a função de membro de **Fechar** e destrua o objeto de `CDatabase` .  **Fechar** fecha todos os conjuntos de registros que não se você fechar anteriormente.  
  
 Para obter mais informações sobre `CDatabase`, consulte os artigos [A fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md) e [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDatabase`  
  
## Requisitos  
 **Cabeçalho:** afxdb.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)