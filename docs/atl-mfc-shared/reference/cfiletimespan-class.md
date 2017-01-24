---
title: "Classe de CFileTimeSpan | Microsoft Docs"
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
  - "CFileTimeSpan"
  - "ATL.CFileTimeSpan"
  - "ATL::CFileTimeSpan"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFileTimeSpan"
  - "classes compartilhadas, CFileTimeSpan"
ms.assetid: 5856fb39-9c82-4027-8ccf-8760890491ec
caps.latest.revision: 18
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFileTimeSpan
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciar a data relativa e valores de tempo associado a um arquivo.  
  
## Sintaxe  
  
```  
  
class CFileTimeSpan  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTimeSpan::CFileTimeSpan](../Topic/CFileTimeSpan::CFileTimeSpan.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTimeSpan::GetTimeSpan](../Topic/CFileTimeSpan::GetTimeSpan.md)|Chamar esse método para recuperar o intervalo de tempo do objeto de `CFileTimeSpan` .|  
|[CFileTimeSpan::SetTimeSpan](../Topic/CFileTimeSpan::SetTimeSpan.md)|Chamar esse método para definir o intervalo de tempo do objeto de `CFileTimeSpan` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileTimeSpan::operator \-](../Topic/CFileTimeSpan::operator%20-.md)|Executa a subtração em um objeto de `CFileTimeSpan` .|  
|[CFileTimeSpan::operator\! \=](../Topic/CFileTimeSpan::operator%20!=.md)|Compara dois objetos de `CFileTimeSpan` para desigualdade.|  
|[CFileTimeSpan::operator \+](../Topic/CFileTimeSpan::operator%20+.md)|Executa a adição de um objeto de `CFileTimeSpan` .|  
|[CFileTimeSpan::operator \+\=](../Topic/CFileTimeSpan::operator%20+=.md)|Executa a adição de um objeto de `CFileTimeSpan` e atribua o resultado para o objeto atual.|  
|[CFileTimeSpan::operator \<](../Topic/CFileTimeSpan::operator%20%3C.md)|Compara dois objetos de `CFileTimeSpan` para determinar o menos.|  
|[\<\= De CFileTimeSpan::operator](../Topic/CFileTimeSpan::operator%20%3C=.md)|Compara dois objetos de `CFileTimeSpan` para determinar igualdade ou as menos.|  
|[CFileTimeSpan::operator \=](../Topic/CFileTimeSpan::operator%20=.md)|o operador de atribuição.|  
|[CFileTimeSpan::operator \- \=](../Topic/CFileTimeSpan::operator%20-=.md)|Executa a subtração em um objeto de `CFileTimeSpan` e atribua o resultado para o objeto atual.|  
|[\=\= De CFileTimeSpan::operator](../Topic/CFileTimeSpan::operator%20==.md)|Compara dois objetos de `CFileTimeSpan` para igualdade.|  
|[CFileTimeSpan::operator \>](../Topic/CFileTimeSpan::operator%20%3E.md)|Compara dois objetos de `CFileTimeSpan` para determinar o maior.|  
|[\>\= De CFileTimeSpan::operator](../Topic/CFileTimeSpan::operator%20%3E=.md)|Compara dois objetos de `CFileTimeSpan` para determinar igualdade ou maior.|  
  
## Comentários  
 Essa classe fornece métodos para gerenciar os períodos de tempo encontrados geralmente relacionados ao executar operações a relação de quando um arquivo foi criado, sólida acessado ou modificado pela última vez.  Os métodos de essa classe são freqüentemente usados em conjunto com objetos de [classe de CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md) .  
  
## Exemplo  
 Consulte o exemplo para [CFileTime::Millisecond](../Topic/CFileTime::Millisecond.md).  
  
## Requisitos  
 **Cabeçalho:** atltime.h  
  
## Consulte também  
 [FILETIME](http://msdn.microsoft.com/library/windows/desktop/ms724284)   
 [Classe de CFileTime](../../atl-mfc-shared/reference/cfiletime-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)