---
title: "Classe de CDBException | Microsoft Docs"
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
  - "CDBException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDBException"
  - "exceções de banco de dados [C++]"
  - "erros [C++], Banco de dados"
  - "exceções [C++], Banco de dados"
  - "Classes ODBC [C++], exceções"
ms.assetid: eb9e1119-89f5-49a7-b9d4-b91cee1ccc82
caps.latest.revision: 23
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDBException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção que ocorre as classes de banco de dados.  
  
## Sintaxe  
  
```  
  
class CDBException : public CException  
  
```  
  
## Membros  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDBException::m\_nRetCode](../Topic/CDBException::m_nRetCode.md)|Contém um código de retorno Open Database Connectivity \(ODBC\), o tipo **RETCODE**.|  
|[CDBException::m\_strError](../Topic/CDBException::m_strError.md)|Contém uma cadeia de caracteres que descreve o erro em termos alfanuméricos.|  
|[CDBException::m\_strStateNativeOrigin](../Topic/CDBException::m_strStateNativeOrigin.md)|Contém uma cadeia de caracteres que descreve o erro em termos de códigos de erro retornados por ODBC.|  
  
## Comentários  
 A classe inclui dois membros públicos de dados que você pode usar para determinar a causa de exceção ou para exibir uma mensagem de texto que descreve a exceção.  Os objetos de`CDBException` são construídos e lançados por funções de membro das classes de banco de dados.  
  
> [!NOTE]
>  Essa classe é uma das classes Open Database Connectivity \(ODBC\) MFC.  Se você estiver usando ao acesso a dados mais recente objetos de classes \(DAO\), usa [CDaoException](../../mfc/reference/cdaoexception-class.md) em vez de isso.  Todos os nomes de classe de DAO têm “CDao” como um prefixo.  Para obter mais informações, consulte o artigo [visão geral: Programação do banco de dados](../../data/data-access-programming-mfc-atl.md).  
  
 As exceções são caso de execução anormal que envolvem condições fora do controle de programa, como a fonte de dados ou erros de E\/S de rede.  Os erros que você pode esperar ver no traço normal de executar o programa não são considerados geralmente exceções.  
  
 Você pode acessar esses objetos no escopo de uma expressão de **CATCH** .  Você também pode lançar objetos de `CDBException` do seu próprio código com a função global de `AfxThrowDBException` .  
  
 Para obter mais informações sobre manipulação de exceção em geral, ou sobre objetos de `CDBException` , consulte os artigos [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CDBException`  
  
## Requisitos  
 **Cabeçalho:** afxdb.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDatabase](../../mfc/reference/cdatabase-class.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)   
 [Classe de CFieldExchange](../../mfc/reference/cfieldexchange-class.md)   
 [AfxThrowDBException](../Topic/AfxThrowDBException.md)   
 [CRecordset::Update](../Topic/CRecordset::Update.md)   
 [CRecordset::Delete](../Topic/CRecordset::Delete.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)