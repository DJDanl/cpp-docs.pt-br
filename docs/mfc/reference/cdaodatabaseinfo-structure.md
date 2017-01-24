---
title: "Estrutura CDaoDatabaseInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CDaoDatabaseInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CDaoDatabaseInfo"
  - "DAO (Objetos de Acesso a Dados), Coleção de bancos de dados"
ms.assetid: 68e9e0da-8382-4fc6-8115-1b1519392ddb
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CDaoDatabaseInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CDaoDatabaseInfo` contém informações sobre um objeto de base de dados definido para objetos \(DAO\) de acesso a dados.  
  
## Sintaxe  
  
```  
  
      struct CDaoDatabaseInfo  
{  
   CString m_strName;       // Primary  
   BOOL m_bUpdatable;       // Primary  
   BOOL m_bTransactions;    // Primary  
   CString m_strVersion;    // Secondary  
   long m_lCollatingOrder;  // Secondary  
   short m_nQueryTimeout;   // Secondary  
   CString m_strConnect;    // All  
};  
```  
  
#### Parâmetros  
 `m_strName`  
 Nomear exclusivamente o objeto de base de dados.  Para recuperar diretamente essa propriedade, chame [CDaoDatabase::GetName](../Topic/CDaoDatabase::GetName.md).  Para obter detalhes, consulte o tópico “propriedade nome” na ajuda de DAO.  
  
 `m_bUpdatable`  
 Indica se as alterações podem ser feitas no base de dados.  Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanUpdate](../Topic/CDaoDatabase::CanUpdate.md).  Para obter detalhes, consulte o tópico “propriedade atualizável” na ajuda de DAO.  
  
 *m\_bTransactions*  
 Indica se uma fonte de dados oferece suporte a transações — a gravação de uma série de alterações que podem ser revertidas \(cancelado\) ou ser confirmadas \(salvo\).  Se um base de dados é baseado no mecanismo de base de dados do Microsoft Jet, a propriedade de transações for diferente de zero e você pode usar transações.  Outros mecanismos de base de dados não podem suportar transações.  Para recuperar diretamente essa propriedade, chame [CDaoDatabase::CanTransact](../Topic/CDaoDatabase::CanTransact.md).  Para obter detalhes, consulte o tópico “propriedade das transações” na ajuda de DAO.  
  
 *m\_strVersion*  
 Indica a versão do mecanismo de base de dados do Microsoft Jet.  Para recuperar diretamente o valor dessa propriedade, chame a função de membro de [GetVersion](../Topic/CDaoDatabase::GetVersion.md) do objeto base de dados.  Para obter detalhes, consulte o tópico “property versão” na ajuda de DAO.  
  
 `m_lCollatingOrder`  
 Especifica a sequência de ordem de classificação em texto para a comparação de cadeia de caracteres ou classificação.  Os valores possíveis incluem:  
  
-   uso de**dbSortGeneral**espanhol \(inglês, francês, alemão, português, italiano, e moderno\) a ordem de classificação geral.  
  
-   uso de**dbSortArabic**a ordem de classificação árabe.  
  
-   uso de**dbSortCyrillic**a ordem de classificação de russo.  
  
-   uso de**dbSortCzech**a ordem de classificação tcheco.  
  
-   uso de**dbSortDutch** a ordem de classificação holandês.  
  
-   uso de**dbSortGreek**a ordem de classificação grego.  
  
-   uso de**dbSortHebrew**a ordem de classificação hebreu.  
  
-   uso de**dbSortHungarian**a ordem de classificação húngaro.  
  
-   uso de**dbSortIcelandic**a ordem de classificação islandês.  
  
-   uso de**dbSortNorwdan**a ordem de classificação norueguês ou dinamarquês.  
  
-   uso de**dbSortPDXIntl**a ordem de classificação do ISO de paradox.  
  
-   uso de**dbSortPDXNor**ordem de classificação norueguês ou dinamarquês de paradox.  
  
-   uso de**dbSortPDXSwe**ordem de classificação sueco ou finlandês de paradox.  
  
-   uso de**dbSortPolish**a ordem de classificação polonês.  
  
-   uso de**dbSortSpanish**a ordem de classificação espanhol.  
  
-   uso de**dbSortSwedFin**a ordem de classificação sueco ou finlandês.  
  
-   uso de**dbSortTurkish**a ordem de classificação turco.  
  
-   **dbSortUndefined** a ordem de classificação é desconhecido ou indefinido.  
  
 Para obter mais informações, consulte o tópico “a personalização de configurações do Registro do Windows para acesso a dados” na ajuda de DAO.  
  
 *m\_nQueryTimeout*  
 O número de segundos que o mecanismo de base de dados do Microsoft Jet espera antes que um erro de tempo limite ocorre quando uma consulta é executada em uma base de dados do ODBC.  O valor de tempo limite padrão é de 60 segundos.  QueryTimeout quando é definido como 0, nenhum tempo limite; isso pode fazer com que o programa pare de responder.  Para recuperar diretamente o valor dessa propriedade, chame a função de membro de [GetQueryTimeout](../Topic/CDaoDatabase::GetQueryTimeout.md) do objeto base de dados.  Para obter detalhes, consulte o tópico “propriedade QueryTimeout” na ajuda de DAO.  
  
 `m_strConnect`  
 Fornece informações sobre a origem de um base de dados aberto.  Para obter informações sobre como conectar cadeias de caracteres, e para obter informações sobre como recuperar o valor dessa propriedade diretamente, consulte a função de membro de [CDaoDatabase::GetConnect](../Topic/CDaoDatabase::GetConnect.md) .  Para obter mais informações, consulte o tópico “conectar\-se a propriedade” na ajuda de DAO.  
  
## Comentários  
 O base de dados é um objeto de DAO que é a base de um objeto MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md).  As referências à primário, secundário, e todas as anterior indicam como as informações são retornadas pela função de membro de [CDaoWorkspace::GetDatabaseInfo](../Topic/CDaoWorkspace::GetDatabaseInfo.md) .  
  
 As informações recuperadas pela função de membro de [CDaoWorkspace::GetDatabaseInfo](../Topic/CDaoWorkspace::GetDatabaseInfo.md) são armazenadas em uma estrutura de `CDaoDatabaseInfo` .  Chame `GetDatabaseInfo` para o objeto de `CDaoWorkspace` em cuja coleção de bases de dados do objeto base de dados é armazenado.  `CDaoDatabaseInfo` também define uma função de membro de `Dump` em construções de depuração.  Você pode usar para `Dump` despejar os conteúdos de um objeto de `CDaoDatabaseInfo` .  
  
## Requisitos  
 **Header:** afxdao.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe de CDaoWorkspace](../../mfc/reference/cdaoworkspace-class.md)   
 [Classe de CDaoDatabase](../../mfc/reference/cdaodatabase-class.md)   
 [CDaoWorkspace::GetDatabaseCount](../Topic/CDaoWorkspace::GetDatabaseCount.md)