---
title: "Classes DAO | Microsoft Docs"
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
  - "vc.classes.data"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO [C++], Classes "
  - "classes de banco de dados [C++], DAO"
ms.assetid: b15d0cd6-328b-4288-9c19-d037a795db57
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes DAO
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes funcionam com as outras classes da estrutura de aplicativo para fornecer acesso fácil a bases de dados \(DAO\) de objeto de acesso a dados, que usa o mesmo mecanismo de base de dados que o Microsoft Visual Basic e o Microsoft Access.  As classes de DAO também podem acessar uma ampla variedade de bases de dados dos drivers de ODBC estão disponíveis.  
  
 Programas que usam bases de dados de DAO terá pelo menos um objeto de `CDaoDatabase` e um objeto de `CDaoRecordset` .  
  
> [!NOTE]
>  A partir do Visual C\+\+ .NET, o ambiente e os assistentes do Visual C\+\+ não dão suporte a DAO \(embora as classes de DAO são incluídas e você ainda pode usar o\).  A Microsoft recomenda que você use ODBC para novos projetos MFC.  Você só deve usar DAO manter os aplicativos existentes.  
  
 [CDaoWorkspace](../mfc/reference/cdaoworkspace-class.md)  
 Gerencia uma sessão nomeada, protegida por senha da base de dados de logon para fazer logoff.  A maioria de programas usam o espaço de trabalho padrão.  
  
 [CDaoDatabase](../mfc/reference/cdaodatabase-class.md)  
 Uma conexão a um base de dados através da qual você pode operar com os dados.  
  
 [CDaoRecordset](../mfc/reference/cdaorecordset-class.md)  
 Representa um conjunto de registros selecionado de uma fonte de dados.  
  
 [CDaoRecordView](../mfc/reference/cdaorecordview-class.md)  
 Um modo de exibição que mostra os registros do banco de dados nos controles.  
  
 [CDaoQueryDef](../mfc/reference/cdaoquerydef-class.md)  
 Representa uma definição de consulta, geralmente uma salva em um base de dados.  
  
 [CDaoTableDef](../mfc/reference/cdaotabledef-class.md)  
 Representa a definição armazenada de uma tabela base ou de uma tabela anexada.  
  
 [CDaoException](../mfc/reference/cdaoexception-class.md)  
 Representa uma condição de exceção que ocorre classes de DAO.  
  
 [CDaoFieldExchange](../mfc/reference/cdaofieldexchange-class.md)  
 Dá suporte a rotinas de troca de campo de registro \(DFX\) DAO usadas pelas classes de banco de dados DAO.  Normalmente não usará diretamente essa classe.  
  
## Classes relacionadas  
 [CLongBinary](../mfc/reference/clongbinary-class.md)  
 Encapsula um identificador para o armazenamento de um objeto binário grande \(BLOB\), como um bitmap.  os objetos de`CLongBinary` são usados para gerenciar os objetos grandes de dados armazenados em tabelas de base de dados.  
  
 [COleCurrency](../Topic/COleCurrency%20Class.md)  
 Wrapper do tipo OLE **CURRENCY**de automação, um tipo aritmética de ponto fixo, com 15 dígitos antes do ponto decimal e 4 dígitos em seguida.  
  
 [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md)  
 Wrapper do tipo **DATA**de automação OLE.  Representa a data e hora.  
  
 [COleVariant](../mfc/reference/colevariant-class.md)  
 Wrapper do tipo **VARIANT**de automação OLE.  Os dados em **VARIANT**s podem ser armazenados em diversos formatos.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)