---
title: "Classe de CBrush | Microsoft Docs"
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
  - "CBrush"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pincéis, Classe de CBrush"
  - "Classe de CBrush"
ms.assetid: e5ef2c62-dd95-4973-9090-f52f605900e1
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CBrush
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula um pincel de \(GDI\) de interface do dispositivo de elementos gráficos do windows.  
  
## Sintaxe  
  
```  
class CBrush : public CGdiObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBrush::CBrush](../Topic/CBrush::CBrush.md)|Constrói um objeto de `CBrush` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBrush::CreateBrushIndirect](../Topic/CBrush::CreateBrushIndirect.md)|Inicializa um pincel com o estilo, a cor, e o padrão especificado em uma estrutura de [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) .|  
|[CBrush::CreateDIBPatternBrush](../Topic/CBrush::CreateDIBPatternBrush.md)|Inicializa um pincel com um padrão especificado por um bitmap independente \(DIB\).|  
|[CBrush::CreateHatchBrush](../Topic/CBrush::CreateHatchBrush.md)|Inicializa um pincel com o padrão e a cor chocados especificados.|  
|[CBrush::CreatePatternBrush](../Topic/CBrush::CreatePatternBrush.md)|Inicializa um pincel com um padrão especificado por um bitmap.|  
|[CBrush::CreateSolidBrush](../Topic/CBrush::CreateSolidBrush.md)|Inicializa um pincel com a cor sólida especificada.|  
|[CBrush::CreateSysColorBrush](../Topic/CBrush::CreateSysColorBrush.md)|Cria um pincel que é a cor padrão do sistema.|  
|[CBrush::FromHandle](../Topic/CBrush::FromHandle.md)|Retorna um ponteiro para um objeto de `CBrush` quando dado um identificador para um objeto de `HBRUSH` do windows.|  
|[CBrush::GetLogBrush](../Topic/CBrush::GetLogBrush.md)|Obtém uma estrutura de [LOGBRUSH](http://msdn.microsoft.com/library/windows/desktop/dd145035) .|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CBrush::operator HBRUSH](../Topic/CBrush::operator%20HBRUSH.md)|Retorna o identificador do windows anexada ao objeto de `CBrush` .|  
  
## Comentários  
 Para usar um objeto de `CBrush` , construir um objeto de `CBrush` e passe a qualquer função de membro de `CDC` que requer um pincel.  
  
 Pincéis podem ser contínuas, chocadas, ou modeladas.  
  
 Para obter mais informações sobre `CBrush`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CBrush`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos PROPDLG](../../top/visual-cpp-samples.md)   
 [Classe de CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CBitmap](../../mfc/reference/cbitmap-class.md)   
 [CDC Class](../Topic/CDC%20Class.md)