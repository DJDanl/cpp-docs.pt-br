---
title: "Classe de CFont | Microsoft Docs"
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
  - "CFont"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFont"
  - "fontes, Classes MFC"
  - "GDI, classes de fonte"
ms.assetid: 3fad6bfe-d6ce-4ab9-967a-5ce0aa102800
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFont
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma fonte de \(GDI\) de interface do dispositivo de elementos gráficos do windows e fornece funções de membro para manipular a fonte.  
  
## Sintaxe  
  
```  
class CFont : public CGdiObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFont::CFont](../Topic/CFont::CFont.md)|Constrói um objeto de `CFont` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFont::CreateFont](../Topic/CFont::CreateFont.md)|Inicializa `CFont` com as características específicas.|  
|[CFont::CreateFontIndirect](../Topic/CFont::CreateFontIndirect.md)|Inicializa um objeto de `CFont` com as características fornecidas em uma estrutura de `LOGFONT` .|  
|[CFont::CreatePointFont](../Topic/CFont::CreatePointFont.md)|Inicializa `CFont` com a altura especificada, medidas nos décimos de um ponto, e o carácter tipo.|  
|[CFont::CreatePointFontIndirect](../Topic/CFont::CreatePointFontIndirect.md)|Mesmo que `CreateFontIndirect` exceto que a altura da fonte é medido nos décimos de um ponto em vez de unidades lógicas.|  
|[CFont::FromHandle](../Topic/CFont::FromHandle.md)|Retornar um ponteiro para um objeto de `CFont` quando determinado o windows **HFONT**.|  
|[CFont::GetLogFont](../Topic/CFont::GetLogFont.md)|Preenche `LOGFONT` com informações sobre a fonte lógica anexada ao objeto de `CFont` .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFont::operator HFONT](../Topic/CFont::operator%20HFONT.md)|Retorna o identificador da fonte do windows GDI anexada ao objeto de `CFont` .|  
  
## Comentários  
 Para usar um objeto de `CFont` , construir um objeto de `CFont` e anexar uma fonte do windows com [CreateFont](../Topic/CFont::CreateFont.md)a ela, [CreateFontIndirect](../Topic/CFont::CreateFontIndirect.md), [CreatePointFont](../Topic/CFont::CreatePointFont.md), ou [CreatePointFontIndirect](../Topic/CFont::CreatePointFontIndirect.md), e então usar as funções de membro de objeto para manipular a fonte.  
  
 Funções de `CreatePointFont` e de `CreatePointFontIndirect` são geralmente mais fácil de usar que `CreateFont` ou `CreateFontIndirect` desde que tornam a conversão para a altura da fonte de um ponto tamanho das unidades lógicas automaticamente.  
  
 Para obter mais informações sobre `CFont`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CFont`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos HIERSVR](../../top/visual-cpp-samples.md)   
 [Classe de CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)