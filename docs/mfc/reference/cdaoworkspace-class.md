---
title: "Classe de CDaoWorkspace | Microsoft Docs"
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
  - "CDaoWorkspace"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDaoWorkspace"
  - "Espaços de trabalho DAO [C++]"
  - "Espaços de trabalho DAO [C++], Classe de CDaoWorkspace"
  - "mecanismo de banco de dados [C++], acessar através do espaço de trabalho"
  - "DDLs [C++]"
  - "espaços de trabalho padrão [C++]"
  - "espaços de trabalho padrão [C++], DAO"
  - "opções [C++], os espaços de trabalho"
  - "Classes ODBC [C++], CONTRA. classes de DAO"
  - "persistência [C++], o espaço de trabalho de DAO"
  - "segurança [MFC]"
  - "segurança [MFC], Espaços de trabalho DAO"
  - "sessões [C++], o espaço de trabalho de DAO"
  - "espaços de transação [C++]"
  - "espaços de transação [C++], o espaço de trabalho de DAO"
  - "Classe do espaço de trabalho"
  - "espaços de trabalho [C++], DAO"
  - "espaços de trabalho [C++], Padrão"
  - "espaços de trabalho [C++], interface para o mecanismo de banco de dados"
  - "espaços de trabalho [C++], persistência"
  - "Coleção de espaços de trabalho"
ms.assetid: 64f60de6-4df1-4d4a-a65b-c489b5257d52
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDaoWorkspace
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia uma sessão denominada, senha\- protegida de banco de dados de logon para fazer logoff, um único usuário.  
  
## Sintaxe  
  
```  
class CDaoWorkspace : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoWorkspace::CDaoWorkspace](../Topic/CDaoWorkspace::CDaoWorkspace.md)|Constrói um objeto de espaço de trabalho.  Posteriormente, chamada **Criar** ou **Abrir**.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoWorkspace::Append](../Topic/CDaoWorkspace::Append.md)|Acrescenta um espaço de trabalho recém\-criado à coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::BeginTrans](../Topic/CDaoWorkspace::BeginTrans.md)|Iniciar uma nova transação, que se aplica a todos os bancos de dados abertos no espaço de trabalho.|  
|[CDaoWorkspace::Close](../Topic/CDaoWorkspace::Close.md)|Fecha o espaço de trabalho e todos os objetos que ele contém.  Durante transações são revertidos.|  
|[CDaoWorkspace::CommitTrans](../Topic/CDaoWorkspace::CommitTrans.md)|Termina a transação atual e salva as alterações.|  
|[CDaoWorkspace::CompactDatabase](../Topic/CDaoWorkspace::CompactDatabase.md)|Compacta \(ou duplica\) um banco de dados.|  
|[CDaoWorkspace::Create](../Topic/CDaoWorkspace::Create.md)|Cria um novo objeto de espaço de trabalho de DAO.|  
|[CDaoWorkspace::GetDatabaseCount](../Topic/CDaoWorkspace::GetDatabaseCount.md)|Retorna o número de objetos de banco de dados de DAO na coleção de bancos de dados do espaço de trabalho.|  
|[CDaoWorkspace::GetDatabaseInfo](../Topic/CDaoWorkspace::GetDatabaseInfo.md)|Retorna informações sobre um banco de dados especificado de DAO definido na coleção de bancos de dados do espaço de trabalho.|  
|[CDaoWorkspace::GetIniPath](../Topic/CDaoWorkspace::GetIniPath.md)|Retorna o local das configurações de inicialização do mecanismo de banco de dados Microsoft Jet no Registro do Windows.|  
|[CDaoWorkspace::GetIsolateODBCTrans](../Topic/CDaoWorkspace::GetIsolateODBCTrans.md)|Retorna um valor que indica se várias transações envolvendo a mesma fonte de dados ODBC são isolados por várias conexões forçadas para a fonte de dados.|  
|[CDaoWorkspace::GetLoginTimeout](../Topic/CDaoWorkspace::GetLoginTimeout.md)|Retorna o número de segundos antes que um erro ocorre quando o usuário tenta logon em um banco de dados ODBC.|  
|[CDaoWorkspace::GetName](../Topic/CDaoWorkspace::GetName.md)|Retorna o nome definido pelo usuário para o objeto de espaço de trabalho.|  
|[CDaoWorkspace::GetUserName](../Topic/CDaoWorkspace::GetUserName.md)|Retorna o nome de usuário especificado quando o espaço de trabalho foi criado.  Este é o nome do proprietário do espaço de trabalho.|  
|[CDaoWorkspace::GetVersion](../Topic/CDaoWorkspace::GetVersion.md)|Retorna uma cadeia de caracteres que contém a versão do mecanismo de banco de dados associado ao espaço de trabalho.|  
|[CDaoWorkspace::GetWorkspaceCount](../Topic/CDaoWorkspace::GetWorkspaceCount.md)|Retorna o número de objetos de espaço de trabalho de DAO na coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::GetWorkspaceInfo](../Topic/CDaoWorkspace::GetWorkspaceInfo.md)|Retorna informações sobre um espaço de trabalho especificado de DAO definido na coleção de espaços de trabalho do mecanismo de banco de dados.|  
|[CDaoWorkspace::Idle](../Topic/CDaoWorkspace::Idle.md)|Permite que o mecanismo de banco de dados execute tarefas em segundo plano.|  
|[CDaoWorkspace::IsOpen](../Topic/CDaoWorkspace::IsOpen.md)|Retorna diferente de zero se o espaço de trabalho está aberto.|  
|[CDaoWorkspace::Open](../Topic/CDaoWorkspace::Open.md)|Abre explicitamente um objeto de espaço de trabalho associados com o espaço de trabalho de opção de DAO.|  
|[CDaoWorkspace::RepairDatabase](../Topic/CDaoWorkspace::RepairDatabase.md)|Tentativas de reparar um banco de dados corrompido.|  
|[CDaoWorkspace::Rollback](../Topic/CDaoWorkspace::Rollback.md)|Termina a transação atual e não salvar as alterações.|  
|[CDaoWorkspace::SetDefaultPassword](../Topic/CDaoWorkspace::SetDefaultPassword.md)|Define a senha que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem uma senha específica.|  
|[CDaoWorkspace::SetDefaultUser](../Topic/CDaoWorkspace::SetDefaultUser.md)|Define o nome do usuário que o mecanismo de banco de dados usa quando um objeto de espaço de trabalho é criado sem um nome de usuário específico.|  
|[CDaoWorkspace::SetIniPath](../Topic/CDaoWorkspace::SetIniPath.md)|Defina o local das configurações de inicialização do mecanismo de banco de dados Microsoft Jet no Registro do Windows.|  
|[CDaoWorkspace::SetIsolateODBCTrans](../Topic/CDaoWorkspace::SetIsolateODBCTrans.md)|Especifica se várias transações envolvendo a mesma fonte de dados ODBC são isolado forçando várias conexões para a fonte de dados.|  
|[CDaoWorkspace::SetLoginTimeout](../Topic/CDaoWorkspace::SetLoginTimeout.md)|Define o número de segundos antes que um erro ocorre quando o usuário tentar inserir a uma fonte de dados ODBC.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDaoWorkspace::m\_pDAOWorkspace](../Topic/CDaoWorkspace::m_pDAOWorkspace.md)|Aponta para o objeto subjacente de espaço de trabalho de DAO.|  
  
## Comentários  
 Em a maioria dos casos, você não precisará vários espaços de trabalho e, você não precisará criar objetos explícitos de espaço de trabalho; quando você abre objetos de banco de dados e conjunto de registros, use o espaço de trabalho padrão de DAO.  Em o entanto, se necessário, você pode executar várias sessões por vez criando objetos adicionais de espaço de trabalho.  Cada objeto de espaço de trabalho podem conter objetos de banco de dados de vários abertos em sua própria coleção de bancos de dados.  Em o MFC, um espaço de trabalho é basicamente um gerenciador de transações, especificando todo um conjunto de bancos de dados abertos no mesmo espaço de “transação.”  
  
> [!NOTE]
>  As classes de banco de dados de DAO são distintas de classes do banco de dados MFC baseado em Open Database Connectivity \(ODBC\).  Todos os nomes de classe de banco de dados de DAO têm um prefixo “CDao”.  Em geral, as classes MFC com base em DAO mais são capazes das classes MFC baseado em ODBC.  Os dados com base DAO\- de acesso das classes pelo mecanismo de banco de dados Microsoft Jet, incluindo drivers ODBC.  Também suporta operações language \(DDL\) de definição de dados, como a criação de bancos de dados e adicionar tabelas e campos por meio de classes, sem precisar chamar diretamente DAO.  
  
## Recursos  
 A classe fornece `CDaoWorkspace` o seguinte:  
  
-   Acesso explícito, se necessário, para um espaço de trabalho padrão criado, inicializando o mecanismo de banco de dados.  Geralmente você o espaço de trabalho de opção de uso DAO implicitamente criando objetos de banco de dados e conjunto de registros.  
  
-   Um espaço de transação em que as transações se aplicam a todos os bancos de dados abertos no espaço de trabalho.  Você pode criar espaços de trabalho adicionais para gerenciar os espaços separados de transação.  
  
-   Uma interface a muitas propriedades do mecanismo de banco de dados subjacente da Microsoft Jet \(consulte as funções de membro estático\).  Abrir ou criar um espaço de trabalho, ou chamar uma função de membro estático ou aberto antes de criar a serem inicializados, o mecanismo de banco de dados.  
  
-   Acesso à coleção de espaços de trabalho do mecanismo de banco de dados, que armazena todos os espaços de trabalho ativos que lhe foram anexados.  Você também pode criar e trabalhar com espaços de trabalho sem acrescentar\-los à coleção.  
  
## Segurança  
 O MFC não implementa os usuários e não agrupa coleções em DAO, que são usados para o controle de segurança.  Se você precisar os aspectos de DAO, você deve programá\-lo você mesmo entre chamadas diretas às interfaces de DAO.  Para mais informações, consulte [Observe técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
## Uso  
 Você pode usar a classe `CDaoWorkspace` :  
  
-   Abra explicitamente o espaço de trabalho padrão.  
  
     Geralmente o uso de espaço de trabalho padrão é implícito — quando você abre novos objetos de [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) ou de [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) .  Mas você pode precisar acessá\-lo explicitamente — por exemplo, para acessar propriedades do mecanismo de banco de dados ou a coleção de espaços de trabalho.  Consulte “uso implícito de espaço de trabalho padrão” abaixo.  
  
-   Crie novos espaços de trabalho.  Chame [acrescentar](../Topic/CDaoWorkspace::Append.md) se você deseja adicionar à coleção dos espaços de trabalho.  
  
-   Abra um espaço de trabalho existente na coleção de espaços de trabalho.  
  
 Criar um novo espaço de trabalho que não existe na coleção de espaços de trabalho é descrita na função de membro de [Criar](../Topic/CDaoWorkspace::Create.md) .  Os objetos de espaço de trabalho não persistem de nenhuma forma entre sessões do mecanismo de datababase.  Se os links de aplicativo MFC estaticamente, encerrando o aplicativo uninitializes o mecanismo de banco de dados.  Se os links de aplicativo com o MFC dinamicamente, o mecanismo de banco de dados são não inicializado quando o DLL MFC é descarregado.  
  
 Explicitamente abra o espaço de trabalho padrão, ou abrir um espaço de trabalho existente em espaços de trabalho coleção, são descritas na função de membro de [Abrir](../Topic/CDaoWorkspace::Open.md) .  
  
 Termine uma sessão de espaço de trabalho do espaço de trabalho com a função de membro de [Fechar](../Topic/CDaoWorkspace::Close.md) .  **Fechar** fecha todos os bancos de dados que não se você fechar anteriormente, revertendo as transações descomprometidos.  
  
## Transações  
 DAO gerencia transações no nível de espaço de trabalho; portanto, as transações em um espaço de trabalho abertos com bancos de dados de vários aplicam\-se a todos os bancos de dados.  Por exemplo, se dois bancos de dados têm atualizações descomprometidos e você chama [CommitTrans](../Topic/CDaoWorkspace::CommitTrans.md), todas as atualizações são confirmadas.  Se você desejar limitar a transações um único banco de dados, você precisa de um objeto separado do espaço de trabalho para ele.  
  
## Uso implícito de espaço de trabalho padrão  
 O espaço de trabalho padrão do usa DAO MFC implicitamente sob as seguintes circunstâncias:  
  
-   Se você criar um novo objeto de `CDaoDatabase` mas não o faz isso através de um objeto existente de `CDaoWorkspace` , o MFC cria um objeto temporário de espaço de trabalho para você, que corresponde ao espaço de trabalho de opção de DAO.  Se você fizer para vários bancos de dados, todos os objetos de banco de dados estão associados ao espaço de trabalho padrão.  Você pode acessar o espaço de trabalho de um banco de dados através de um membro de dados de `CDaoDatabase` .  
  
-   De a mesma forma, se você criar um objeto de `CDaoRecordset` sem fornecer um ponteiro para um objeto de `CDaoDatabase` , o MFC cria um objeto de banco de dados temporário, e pela extensão, um objeto temporário de espaço de trabalho.  Você pode acessar o banco de dados de um conjunto de registros, e indiretamente o seu espaço de trabalho, através de um membro de dados de `CDaoRecordset` .  
  
## Outras operações  
 Outras operações de banco de dados também são fornecidas, como reparar um banco de dados ou corrompido compactar um banco de dados.  
  
 Para obter informações sobre como chamar DAO diretamente e sobre segurança de DAO, consulte [Observe técnica 54](../../mfc/tn054-calling-dao-directly-while-using-mfc-dao-classes.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDaoWorkspace`  
  
## Requisitos  
 **Cabeçalho:** afxdao.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [Classe de CDaoRecordset](../../mfc/reference/cdaorecordset-class.md)   
 [Classe de CDaoTableDef](../../mfc/reference/cdaotabledef-class.md)   
 [Classe de CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)   
 [Classe de CDaoException](../../mfc/reference/cdaoexception-class.md)