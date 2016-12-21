---
title: "Troca de dados para exibi&#231;&#245;es de registro (Acesso a dados MFC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DDX (troca de dados da caixa de diálogo), exibições de registro"
  - "DFX (troca de campos de registro DAO)"
  - "DFX (troca de campos de registro DAO), mecanismo de troca de dados"
  - "DFX (troca de campos de registro DAO), exibições de registro"
  - "exibições de registro, troca de dados"
  - "RFX (troca de campos de registro)"
  - "RFX (troca de campos de registro), mecanismo de troca de dados"
  - "RFX (troca de campos de registro), exibições de registro"
ms.assetid: abc52ca7-6997-47a7-98f3-f347f52b1f72
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Troca de dados para exibi&#231;&#245;es de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você usa [Adicionar Classe](../mfc/reference/adding-an-mfc-odbc-consumer.md) para mapear controles no recurso de modelo de diálogo de uma exibição de registro para campos de um conjunto de registros, a estrutura gerencia a troca de dados em ambas as direções – do conjunto de registros para controles e dos controles para o conjunto de registros.  O uso do mecanismo DDX significa que você não precisa escrever o código para transferir os dados de um para outro lado por conta própria.  
  
 DDX para exibições de registros funciona com:  
  
-   [RFX](../data/odbc/record-field-exchange-rfx.md) para conjuntos de registros de classe `CRecordset` \(ODBC\).  
  
-   DFX para conjuntos de registros de classe `CDaoRecordset` \(DAO\).  
  
 Embora sejam diferentes na implementação, na interface de nível RFX e DFX são mecanismos de troca de dados muito semelhantes.  A versão do DAO, DFX, é modelada estreitamente na versão anterior do ODBC, RFX.  Se você souber como usar RFX, saberá como usar o DFX.  
  
 RFX e DFX movem dados entre o registro atual da fonte de dados e os membros de dados de campo de um objeto de conjunto de registro.  DDX move os dados de membros de dados de campo para os controles no formulário.  Essa combinação preenche os controles do formulário inicialmente e conforme o usuário é movido de registro em registro.  Ela também pode mover dados atualizados de volta ao conjunto de registros e, em seguida, para a fonte de dados.  
  
 A figura a seguir mostra a relação entre DDX e RFX \(ou DFX\) para exibições de registro.  
  
 ![Troca de campo de registro do diálogo dados Exchange](../data/media/vc37xt1.png "vc37XT1")  
Troca de dados de diálogo e troca de campos de registro  
  
 Para obter mais informações sobre DDX, consulte [Troca e validação de dados de diálogo](../mfc/dialog-data-exchange-and-validation.md).  Para obter mais informações sobre RFX, consulte [RFX \(Record Field Exchange\)](../data/odbc/record-field-exchange-rfx.md).  
  
## Consulte também  
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)