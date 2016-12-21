---
title: "Processamento de exce&#231;&#227;o | Microsoft Docs"
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
  - "vc.mfc.macros.exceptions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DAO (Objetos de Acesso a Dados), exceções"
  - "macros de exceção"
  - "exceções, funções de lançamento MFC"
  - "exceções, processando"
  - "Macros , tratamento de exceção"
  - "MFC, exceções"
  - "Exceções OLE, Funções MFC"
  - "funções de encerramento, MFC"
ms.assetid: 26d4457c-8350-48f5-916e-78f919787c30
caps.latest.revision: 16
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processamento de exce&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando um programa, executa várias condições e anormais de erros chamado “exceções” podem ocorrer.  Isso inclui a execução da memória, de erros de atribuição de recursos, e de falha localizar arquivos.  
  
 A biblioteca de classes do Microsoft usa um esquema manipulação de exceções gerais que é modelado de perto uma alteração proposta pelo comitê de padrões ANSI para C\+\+.  Um manipulador de exceção deve ser configurado antes de chamar uma função que pode localizar uma situação anormal.  Se a função encontrar uma condição anormal, gerencie uma exceção e o controle é passado para o manipulador de exceção.  
  
 Vários macros incluídos na biblioteca de classes do Microsoft foundation configurará manipuladores de exceção.  Um número de outras funções globais ajudam a lançar exceções especializadas e a ser finalizado programas, se necessário.  Esses macros e funções globais se enquadram nas seguintes categorias:  
  
-   [Macros de exceção](#_mfc_exception_macros)estrutura, que o manipulador de exceção.  
  
-   [funções de reprodução](#_mfc_exception.2d.throwing_functions), que gerencia exceções de tipos específicos.  
  
-   [Funções de término](#_mfc_termination_functions), que fazem com que a fim do programa.  
  
 Para obter exemplos e mais detalhes, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).  
  
### Macros de exceção  
  
|||  
|-|-|  
|[TRY](../Topic/TRY.md)|Designa um bloco de código para o processamento da exceção.|  
|[CATCH](../Topic/CATCH.md)|Designa um bloco de código para capturar uma exceção do bloco anterior de **TRY** .|  
|[CATCH\_ALL](../Topic/CATCH_ALL.md)|Designa um bloco de código para capturar todas as exceções do bloco anterior de **TRY** .|  
|[AND\_CATCH](../Topic/AND_CATCH.md)|Designa um bloco de código para capturar tipos de exceção adicionais do bloco anterior de **TRY** .|  
|[AND\_CATCH\_ALL](../Topic/AND_CATCH_ALL.md)|Designa um bloco de código para capturar todos tipos de exceção adicionais restantes lançados em um bloco anterior de **TRY** .|  
|[END\_CATCH](../Topic/END_CATCH.md)|Termina **CATCH** ou o último bloco de código de `AND_CATCH` .|  
|[END\_CATCH\_ALL](../Topic/END_CATCH_ALL.md)|Termina o bloco de código de `CATCH_ALL` pela última vez.|  
|[THROW](../Topic/THROW%20\(MFC\).md)|Gerencie uma exceção especificada.|  
|[THROW\_LAST](../Topic/THROW_LAST.md)|Lança a exceção tratada atualmente para o manipulador externa seguir.|  
  
### Funções de reprodução  
  
|||  
|-|-|  
|[AfxThrowArchiveException](../Topic/AfxThrowArchiveException.md)|Gerencie uma exceção se o arquivo morto.|  
|[AfxThrowFileException](../Topic/AfxThrowFileException.md)|Gerencie uma exceção se o arquivo.|  
|[AfxThrowMemoryException](../Topic/AfxThrowMemoryException.md)|Gerencie uma exceção de memória.|  
|[AfxThrowNotSupportedException](../Topic/AfxThrowNotSupportedException.md)|Gerencie uma exceção que não tem suporte.|  
|[AfxThrowResourceException](../Topic/AfxThrowResourceException.md)|Gerencie uma exceção recurso\-não\- localizada o windows.|  
|[AfxThrowUserException](../Topic/AfxThrowUserException.md)|Gerencie uma exceção em uma ação iniciada pelo usuário do programa.|  
  
 MFC O fornece duas funções de reprodução especificamente para exceções do:  
  
### Funções com OLE DB de exceção  
  
|||  
|-|-|  
|[AfxThrowOleDispatchException](../Topic/AfxThrowOleDispatchException.md)|Gerencie uma exceção dentro de uma função de automação OLE.|  
|[AfxThrowOleException](../Topic/AfxThrowOleException.md)|Gerencie uma exceção OLE.|  
  
 Para suportar exceções da base de dados, as classes de base de dados fornecem duas classes de exceção, `CDBException` e `CDaoException`, funções e globais para dar suporte aos tipos de exceção:  
  
### Funções da exceção de DAO  
  
|||  
|-|-|  
|[AfxThrowDAOException](../Topic/AfxThrowDaoException.md)|Gerencie [CDaoException](../../mfc/reference/cdaoexception-class.md) de seu próprio código.|  
|[AfxThrowDBException](../Topic/AfxThrowDBException.md)|Gerencie [CDBException](../../mfc/reference/cdbexception-class.md) de seu próprio código.|  
  
 MFC O fornece a seguinte função de término:  
  
### Funções de término  
  
|||  
|-|-|  
|[AfxAbort](../Topic/AfxAbort.md)|Chamado para finalizar um aplicativo quando um erro fatal ocorrer.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)