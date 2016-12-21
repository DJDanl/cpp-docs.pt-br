---
title: "Classe de COleException | Microsoft Docs"
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
  - "COleException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleException"
  - "exceções, O OLE"
ms.assetid: 2571e9fe-26cc-42f0-9ad9-8ad5b4311ec1
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção relacionada a uma operação OLE.  
  
## Sintaxe  
  
```  
class COleException : public CException  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleException::Process](../Topic/COleException::Process.md)|Converte uma exceção capturada em um código de retorno OLE.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleException::m\_sc](../Topic/COleException::m_sc.md)|Contém código de status que indica a razão para a exceção.|  
  
## Comentários  
 A classe de `COleException` inclui um membro de dados públicos que contém o código de status que indica a razão para a exceção.  
  
 Geralmente, você não deve criar um objeto de `COleException` diretamente; em vez de isso, você deve chamar [AfxThrowOleException](../Topic/AfxThrowOleException.md).  
  
 Para obter mais informações sobre as exceções, consulte os artigos [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md) e [Exceções: exceções VELHOS](../Topic/Exceptions:%20OLE%20Exceptions.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `COleException`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Exemplo CALCDRIV MFC](../../top/visual-cpp-samples.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)