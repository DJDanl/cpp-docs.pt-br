---
title: "Classe de CInternetException | Microsoft Docs"
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
  - "CInternetException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CInternetException"
  - "tratamento de exceção, Operações de Internet"
  - "exceções, Internet"
ms.assetid: 44fb3cbe-523e-4754-8843-a77909990b14
caps.latest.revision: 22
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CInternetException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma condição de exceção relacionada a uma operação da Internet.  
  
## Sintaxe  
  
```  
class CInternetException : public CException  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetException::CInternetException](../Topic/CInternetException::CInternetException.md)|Constrói um objeto de `CInternetException` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetException::m\_dwContext](../Topic/CInternetException::m_dwContext.md)|O valor de contexto associado com a operação que causou a exceção.|  
|[CInternetException::m\_dwError](../Topic/CInternetException::m_dwError.md)|o erro que causou a exceção.|  
  
## Comentários  
 A classe de `CInternetException` inclui dois membros públicos de dados: um mantém o código de erro associado com a exceção, e o outro contém o identificador do contexto do aplicativo da web associado com o erro.  
  
 Para obter mais informações sobre identificadores de contexto para aplicativos de Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CInternetException`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)