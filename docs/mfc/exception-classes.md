---
title: "Classes de exce&#231;&#227;o | Microsoft Docs"
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
  - "vc.classes.exception"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de exceção"
  - "tratamento de exceção, classes de exceção"
  - "MFC, exceções"
ms.assetid: 1a2caf12-b3e9-4189-86d2-bf7a595bf025
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de exce&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classe fornece um mecanismo manipulação de exceções gerais com base na classe `CException`.  A estrutura de aplicativo usa exceções no seu código; você também pode usá\-los em vossos.  Para obter mais informações, consulte o artigo [Exceções](../mfc/exception-handling-in-mfc.md).  Você pode derivar seus próprios tipos de exceção de `CException`.  
  
 MFC O fornece uma classe de exceção de que você pode derivar suas próprias exceção bem como classes de exceção para todas as exceções que oferece suporte.  
  
 [CException](../mfc/reference/cexception-class.md)  
 A classe base para exceções.  
  
 [CArchiveException](../mfc/reference/carchiveexception-class.md)  
 Uma exceção de arquivo morto.  
  
 [CDaoException](../mfc/reference/cdaoexception-class.md)  
 Uma exceção resultante de uma falha em uma operação de base de dados de DAO.  
  
 [CDBException](../mfc/reference/cdbexception-class.md)  
 Uma exceção resultante de uma falha no processamento da base de dados do ODBC.  
  
 [CFileException](../mfc/reference/cfileexception-class.md)  
 Uma exceção com orientada.  
  
 [CMemoryException](../mfc/reference/cmemoryexception-class.md)  
 Uma exceção de memória insuficiente.  
  
 [CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)  
 Uma exceção resultante de usar um recurso sem suporte.  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento OLE.  Esta classe é usada por contêineres e por servidores.  
  
 [COleDispatchException](../Topic/COleDispatchException%20Class.md)  
 Uma exceção resultante de um erro durante a automação.  As exceções de automação são geradas por servidores de automação e capturadas pelos clientes de automação.  
  
 [CResourceException](../mfc/reference/cresourceexception-class.md)  
 Uma exceção resultante de uma falha ao carregar um recurso do windows.  
  
 [CUserException](../mfc/reference/cuserexception-class.md)  
 Uma exceção usada para parar uma operação iniciada pelo usuário.  Normalmente, o usuário esteve notificado do problema antes que essa exceção seja gerada.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)