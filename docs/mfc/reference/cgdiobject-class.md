---
title: "Classe de CGdiObject | Microsoft Docs"
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
  - "CGdiObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pincéis, classe base para"
  - "Classe de CGdiObject"
  - "fontes, classe base para"
  - "objetos GDI, classe base para"
  - "paletas, classe base para"
  - "menus, classe base para"
  - "regiões, classe base para"
ms.assetid: 1cba3ba5-3d49-4e43-8293-209299f2f6f4
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CGdiObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma classe base para vários tipos de objetos de \(GDI\) de interface do dispositivo de elementos gráficos do windows como bitmaps, regiões, pincéis, menus, paletas, e fontes.  
  
## Sintaxe  
  
```  
class CGdiObject : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGdiObject::CGdiObject](../Topic/CGdiObject::CGdiObject.md)|Constrói um objeto de `CGdiObject` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGdiObject::Attach](../Topic/CGdiObject::Attach.md)|Anexa um objeto do windows GDI a um objeto de `CGdiObject` .|  
|[CGdiObject::CreateStockObject](../Topic/CGdiObject::CreateStockObject.md)|Recupera uma alça a uma das canetas, pincéis, ou de fontes pré\-definidas predefinidas o windows.|  
|[CGdiObject::DeleteObject](../Topic/CGdiObject::DeleteObject.md)|Exclui o objeto do windows GDI anexado ao objeto de `CGdiObject` de memória liberando qualquer armazenamento do sistema associado ao objeto.|  
|[CGdiObject::DeleteTempMap](../Topic/CGdiObject::DeleteTempMap.md)|Exclui todos os objetos temporários de `CGdiObject` criados por `FromHandle`.|  
|[CGdiObject::Detach](../Topic/CGdiObject::Detach.md)|Dispara um objeto do windows GDI de um objeto de `CGdiObject` e retorna um identificador para o objeto do windows GDI.|  
|[CGdiObject::FromHandle](../Topic/CGdiObject::FromHandle.md)|Retorna um ponteiro para um objeto de `CGdiObject` dado um identificador para um objeto do windows GDI.|  
|[CGdiObject::GetObject](../Topic/CGdiObject::GetObject.md)|Preenche um buffer com dados que descrevem o objeto do windows GDI anexado ao objeto de `CGdiObject` .|  
|[CGdiObject::GetObjectType](../Topic/CGdiObject::GetObjectType.md)|Recupera o tipo de objeto do GDI.|  
|[CGdiObject::GetSafeHandle](../Topic/CGdiObject::GetSafeHandle.md)|Retorna `m_hObject` a menos que `this` é `NULL`, em esse caso `NULL` será retornado.|  
|[CGdiObject::UnrealizeObject](../Topic/CGdiObject::UnrealizeObject.md)|Reinicializa a origem de um pincel ou redefinir uma paleta lógica.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGdiObject::operator\! \=](../Topic/CGdiObject::operator%20!=.md)|Determina se dois objetos de GDI não são logicamente iguais.|  
|[\=\= De CGdiObject::operator](../Topic/CGdiObject::operator%20==.md)|Determina se dois objetos de GDI são logicamente iguais.|  
|[CGdiObject::operator HGDIOBJ](../Topic/CGdiObject::operator%20HGDIOBJ.md)|Recupera `HANDLE` anexado ao objeto do windows GDI.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGdiObject::m\_hObject](../Topic/CGdiObject::m_hObject.md)|`HANDLE` que contém `HBITMAP`, `HPALETTE`, `HRGN`, `HBRUSH`, `HPEN`, ou `HFONT` anexado ao objeto.|  
  
## Comentários  
 Você nunca cria `CGdiObject` diretamente.  Em vez de isso, você cria um objeto de uma de suas classes derivadas, como `CPen` ou `CBrush`.  
  
 Para obter mais informações sobre `CGdiObject`, consulte: [Objetos gráficos](../../mfc/graphic-objects.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CGdiObject`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CBitmap](../../mfc/reference/cbitmap-class.md)   
 [Classe de CBrush](../../mfc/reference/cbrush-class.md)   
 [Classe de CFont](../../mfc/reference/cfont-class.md)   
 [Classe de CPalette](../../mfc/reference/cpalette-class.md)   
 [Classe de CPen](../Topic/CPen%20Class.md)   
 [CRgn Class](../../mfc/reference/crgn-class.md)