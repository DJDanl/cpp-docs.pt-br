---
title: "Classe de CException | Microsoft Docs"
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
  - "CException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CArchiveException, classe base"
  - "Classe de CDaoException, classe base"
  - "Classe de CDBException, classe base"
  - "Classe de CException"
  - "Classe de CFileException, classe base"
  - "Classe de CInternetException, classe base"
  - "Classe de CMemoryException, classe base"
  - "Classe de CNotSupportedException, classe base"
  - "Classe de COleDispatchException, classe base"
  - "Classe de COleException, classe base"
  - "Classe de CResourceException, classe base"
  - "Classe de CUserException"
  - "exceções, para classes"
  - "macros, tratamento de exceção"
ms.assetid: cfacf14d-bfe4-4666-a5c7-38b800512920
caps.latest.revision: 22
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para todas as exceções na biblioteca de classes da Microsoft foundation.  
  
## Sintaxe  
  
```  
class AFX_NOVTABLE CException : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CException::CException](../Topic/CException::CException.md)|Constrói um objeto de `CException` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CException::Delete](../Topic/CException::Delete.md)|Exclui um objeto de `CException` .|  
|[CException::ReportError](../Topic/CException::ReportError.md)|Reportar uma mensagem de erro em uma caixa de mensagem para o usuário.|  
  
## Comentários  
 Porque `CException` é uma classe base abstrata você não pode criar objetos de `CException` diretamente; você deve criar objetos de classes derivadas.  Se você precisa criar seu próprio `CException`\- estilize a classe, use uma das classes derivadas listadas acima como um modelo.  Certifique\-se de que sua classe derivada também usa `IMPLEMENT_DYNAMIC`.  
  
 Classes derivadas e suas descrições listadas abaixo:  
  
|||  
|-|-|  
|[CSimpleException](../../mfc/reference/csimpleexception-class.md)|Uma classe base para exceções recurso críticos MFC|  
|[CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Condição de exceção inválido de argumento|  
|[CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de Para fora de memória|  
|[CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitação para uma operação sem suporte|  
|[CArchiveException](../../mfc/reference/carchiveexception-class.md)|Arquivo morto\- exceção específica|  
|[CFileException](../../mfc/reference/cfileexception-class.md)|Com exceção específica|  
|[CResourceException](../../mfc/reference/cresourceexception-class.md)|Recurso do windows não foi encontrado ou não creatable|  
|[COleException](../../mfc/reference/coleexception-class.md)|Exceção OLE|  
|[CDBException](../../mfc/reference/cdbexception-class.md)|Exceção de banco de dados \(isto é, condições de exceções que ocorrem para as classes de banco de dados MFC baseado em ODBC\)|  
|[COleDispatchException](../Topic/COleDispatchException%20Class.md)|Exceção OLE de distribuição \(automação\)|  
|[CUserException](../../mfc/reference/cuserexception-class.md)|Exceção que indica que um recurso não pôde ser encontrado|  
|[CDaoException](../../mfc/reference/cdaoexception-class.md)|Exceção do objeto de acesso a dados \(isto é, condições de exceções que ocorrem para classes de DAO\)|  
|[CInternetException](../../mfc/reference/cinternetexception-class.md)|Exceção da Internet \(isto é, condições de exceções que ocorrem para classes da Internet\).|  
  
 Essas exceções sejam usadas com macros de [LANCE](../Topic/THROW%20\(MFC\).md), de [THROW\_LAST](../Topic/THROW_LAST.md), de [TENTATIVA](../Topic/TRY.md), de [CAPTURA](../Topic/CATCH.md), de [AND\_CATCH](../Topic/AND_CATCH.md), e de [END\_CATCH](../Topic/END_CATCH.md) .  Para obter mais informações sobre as exceções, consulte [Processamento de exceção](../../mfc/reference/exception-processing.md), ou consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
 Para capturar uma exceção específica, use a classe derivada apropriada.  Para capturar todos os tipos de exceções, use `CException`em seguida, use [CObject::IsKindOf](../Topic/CObject::IsKindOf.md) para diferenciar entre `CException`\- classes derivadas.  Observe que o trabalho de `CObject::IsKindOf` somente para classes declarados com a macro de [IMPLEMENT\_DYNAMIC](../Topic/IMPLEMENT_DYNAMIC.md) , para tirar proveito de verificação de tipo dinâmico.  Qualquer `CException`\- a classe derivada que você cria deve usar a macro de `IMPLEMENT_DYNAMIC` , também.  
  
 Você pode relatar detalhes sobre exceções para o usuário chamando [GetErrorMessage](../Topic/CFileException::GetErrorMessage.md) ou [ReportError](../Topic/CException::ReportError.md), duas funções de membro que funcionam com quaisquer das classes derivadas de `CException`.  
  
 Se uma exceção é detectada por um de macros, o objeto de `CException` é excluído automaticamente; o não excluir você mesmo.  Se uma exceção é detectada usando uma palavra\-chave de **catch** , não será excluída automaticamente.  Consulte o artigo [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md) para obter mais informações sobre quando excluir um objeto de exeption.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Processamento de exceção](../../mfc/reference/exception-processing.md)   
 [Como: eu faço Crie minhas próprias classes de exceção personalizada?](http://go.microsoft.com/fwlink/?LinkId=128045)