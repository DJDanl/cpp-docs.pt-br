---
title: "Classe de CSize | Microsoft Docs"
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
  - "CSize"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSize"
  - "dimensões"
  - "dimensões, MFC"
  - "TAMANHO"
ms.assetid: fb2cf85a-0bc1-46f8-892b-309c108b52ae
caps.latest.revision: 20
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSize
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Semelhante a estrutura de [TAMANHO](http://msdn.microsoft.com/library/windows/desktop/dd145106) do windows, que implementa uma coordenada relativo ou uma posição.  
  
## Sintaxe  
  
```  
class CSize : public tagSIZE  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSize::CSize](../Topic/CSize::CSize.md)|Constrói um objeto de `CSize` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSize::operator \-](../Topic/CSize::operator%20-.md)|Subtrai dois tamanhos.|  
|[CSize::operator\! \=](../Topic/CSize::operator%20!=.md)|Verifica para desigualdade entre `CSize` e um tamanho.|  
|[CSize::operator \+](../Topic/CSize::operator%20+.md)|Adiciona dois tamanhos.|  
|[CSize::operator \+\=](../Topic/CSize::operator%20+=.md)|Adiciona um tamanho para `CSize`.|  
|[CSize::operator \- \=](../Topic/CSize::operator%20-=.md)|Subtrai um tamanho de `CSize`.|  
|[\=\= De CSize::operator](../Topic/CSize::operator%20==.md)|Verifica para igualdade entre `CSize` e um tamanho.|  
  
## Comentários  
 Essa classe é derivada da estrutura de **TAMANHO** .  Isso significa que você pode passar `CSize` em um parâmetro que chamem para **TAMANHO** e que os membros de dados de estrutura de **TAMANHO** sejam acessíveis membros de dados de `CSize`.  
  
 Membros de **cx** e de **cy** de **TAMANHO** \(e `CSize`\) são públicos.  Além de isso, implementa `CSize` funções de membro para manipular a estrutura de **TAMANHO** .  
  
> [!NOTE]
>  Para obter mais informações sobre as classes utilitárias compartilhadas \(como `CSize`\), consulte [classes compartilhadas](../../atl-mfc-shared/atl-mfc-shared-classes.md).  
  
## Hierarquia de herança  
 `tagSIZE`  
  
 `CSize`  
  
## Requisitos  
 **Cabeçalho:** atltypes.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRect](../../atl-mfc-shared/reference/crect-class.md)   
 [Classe de CPoint](../Topic/CPoint%20Class.md)