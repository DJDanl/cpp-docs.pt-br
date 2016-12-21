---
title: "Classe de CArchiveException | Microsoft Docs"
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
  - "CArchiveException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exceções do arquivamento [C++]"
  - "Classe de CArchiveException"
  - "exceções [C++], o arquivamento"
  - "exceções [C++], serialização"
  - "serialização [C++], exceções"
ms.assetid: da31a127-e86c-41d1-b0b6-bed0865b1b49
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CArchiveException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção de serialização  
  
## Sintaxe  
  
```  
class CArchiveException : public CException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchiveException::CArchiveException](../Topic/CArchiveException::CArchiveException.md)|Constrói um objeto de `CArchiveException` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchiveException::m\_cause](../Topic/CArchiveException::m_cause.md)|Indica a causa de exceção.|  
|[CArchiveException::m\_strFileName](../Topic/CArchiveException::m_strFileName.md)|Especifica o nome do arquivo para essa condição de exceção.|  
  
## Comentários  
 A classe de `CArchiveException` inclui um membro de dados públicos que indica a causa de exceção.  
  
 Os objetos de`CArchiveException` são construídos e funções de membro internas lançadas de [CArchive](../../mfc/reference/carchive-class.md) .  Você pode acessar esses objetos no escopo de uma expressão de **CATCH** .  O código causa de é independente do sistema operacional.  Para obter mais informações sobre o processamento de exceção, consulte [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CArchiveException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CArchive](../../mfc/reference/carchive-class.md)   
 [AfxThrowArchiveException](../Topic/AfxThrowArchiveException.md)   
 [Processamento de exceção](../../mfc/reference/exception-processing.md)