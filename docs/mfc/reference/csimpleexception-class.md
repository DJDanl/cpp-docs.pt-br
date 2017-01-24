---
title: "Classe de CSimpleException | Microsoft Docs"
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
  - "CSimpleException"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleException"
ms.assetid: be0eb8ef-e5b9-47d6-b0fb-efaff2d1e666
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleException
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é uma classe base para exceções recurso críticos MFC.  
  
## Sintaxe  
  
```  
  
class AFX_NOVTABLE CSimpleException : public CException  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleException::CSimpleException](../Topic/CSimpleException::CSimpleException.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleException::GetErrorMessage](../Topic/CSimpleException::GetErrorMessage.md)|Fornece o texto sobre um erro que ocorreu.|  
  
## Comentários  
 `CSimpleException` é a classe base para exceções recurso críticos MFC e trata a propriedade e a inicialização de uma mensagem de erro.  As seguintes classes usam `CSimpleException` como sua classe base:  
  
|||  
|-|-|  
|[Classe de CMemoryException](../../mfc/reference/cmemoryexception-class.md)|Exceção de Para fora de memória|  
|[Classe de CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)|Solicitações para uma operação sem suporte|  
|[Classe de CResourceException](../../mfc/reference/cresourceexception-class.md)|Recurso do windows não foi encontrado ou não creatable|  
|[Classe de CUserException](../../mfc/reference/cuserexception-class.md)|A exceção que indica um recurso não pode ser encontrada|  
|[Classe de CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md)|Exceção que indica um argumento válido|  
  
 Porque `CSimpleException` é uma classe base abstrata, você não pode declarar um objeto de `CSimpleException` diretamente.  Em vez de isso, você deve declarar objetos derivados como aqueles na tabela anterior.  Se você está declarando sua própria classe derivada, use as classes anteriores como um modelo.  
  
 Para obter mais informações, consulte e [manipulação de exceção \(MFC\)](../../mfc/exception-handling-in-mfc.md)de [classe de CException](../../mfc/reference/cexception-class.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 `CSimpleException`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CException](../../mfc/reference/cexception-class.md)   
 [Tratamento de Exceção](../../mfc/exception-handling-in-mfc.md)