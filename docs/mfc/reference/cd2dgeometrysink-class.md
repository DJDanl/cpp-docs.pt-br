---
title: "Classe de CD2DGeometrySink | Microsoft Docs"
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
  - "afxrendertarget/CD2DGeometrySink"
  - "CD2DGeometrySink"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DGeometrySink"
ms.assetid: e5e07f41-0343-4ab1-9d6b-8c62ed33c04a
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DGeometrySink
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para ID2D1GeometrySink.  
  
## Sintaxe  
  
```  
class CD2DGeometrySink;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DGeometrySink::CD2DGeometrySink](../Topic/CD2DGeometrySink::CD2DGeometrySink.md)|Constrói um objeto de CD2DGeometrySink do objeto de CD2DPathGeometry.|  
|[CD2DGeometrySink::~CD2DGeometrySink](../Topic/CD2DGeometrySink::~CD2DGeometrySink.md)|O destrutor.  Chamado quando um objeto de coleta de geometria de D2D é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DGeometrySink::AddArc](../Topic/CD2DGeometrySink::AddArc.md)|Adiciona um único arco à geometria de caminho|  
|[CD2DGeometrySink::AddBezier](../Topic/CD2DGeometrySink::AddBezier.md)|Cria uma curva de Bezier cubica entre o ponto atual e o ponto final especificado.|  
|[CD2DGeometrySink::AddBeziers](../Topic/CD2DGeometrySink::AddBeziers.md)|Cria uma seqüência de curvas Bézier cúbicas de e adicioná\-los ao coletor de geometria.|  
|[CD2DGeometrySink::AddLine](../Topic/CD2DGeometrySink::AddLine.md)|Cria um segmento de linha entre o ponto atual e o ponto final especificado e adicioná\-lo ao coletor de geometria.|  
|[CD2DGeometrySink::AddLines](../Topic/CD2DGeometrySink::AddLines.md)|Cria uma seqüência de linhas usando os pontos especificados e adicioná\-los para o coletor de geometria.|  
|[CD2DGeometrySink::AddQuadraticBezier](../Topic/CD2DGeometrySink::AddQuadraticBezier.md)|Cria uma curva de Bezier quadrática entre o ponto atual e o ponto final especificado.|  
|[CD2DGeometrySink::AddQuadraticBeziers](../Topic/CD2DGeometrySink::AddQuadraticBeziers.md)|Adiciona uma seqüência de segmentos quadráticos de Bezier como uma matriz em uma única chamada.|  
|[CD2DGeometrySink::BeginFigure](../Topic/CD2DGeometrySink::BeginFigure.md)|Iniciar uma nova figura no ponto especificado.|  
|[CD2DGeometrySink::Close](../Topic/CD2DGeometrySink::Close.md)|Fecha o coletor de geometria|  
|[CD2DGeometrySink::EndFigure](../Topic/CD2DGeometrySink::EndFigure.md)|Termina a figura atual; opcionalmente, feche\-a.|  
|[CD2DGeometrySink::Get](../Topic/CD2DGeometrySink::Get.md)|Interface de retorna ID2D1GeometrySink|  
|[CD2DGeometrySink::IsValid](../Topic/CD2DGeometrySink::IsValid.md)|Verifica a validade de coleta de geometria|  
|[CD2DGeometrySink::SetFillMode](../Topic/CD2DGeometrySink::SetFillMode.md)|Especifica o método usado para determinar que são pontos dentro da geometria descrita pelo coletor de geometria e pontos que estão fora.|  
|[CD2DGeometrySink::SetSegmentFlags](../Topic/CD2DGeometrySink::SetSegmentFlags.md)|Especifica o traço e join a opções ser aplicado aos novos segmentos adicionados ao coletor de geometria.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DGeometrySink::operator ID2D1GeometrySink\*](../Topic/CD2DGeometrySink::operator%20ID2D1GeometrySink*.md)|Interface de retorna ID2D1GeometrySink|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DGeometrySink::m\_pSink](../Topic/CD2DGeometrySink::m_pSink.md)|Um ponteiro para um ID2D1GeometrySink.|  
  
## Hierarquia de herança  
 [CD2DGeometrySink](../../mfc/reference/cd2dgeometrysink-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)