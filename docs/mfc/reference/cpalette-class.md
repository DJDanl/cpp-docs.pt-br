---
title: "Classe de CPalette | Microsoft Docs"
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
  - "CPalette"
  - "HPALETTE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "paletas de cores, MFC"
  - "Classe de CPalette"
  - "HPALETTE"
ms.assetid: 8cd95498-53ed-4852-85e1-70e522541114
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPalette
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula uma paleta de cores do windows.  
  
## Sintaxe  
  
```  
class CPalette : public CGdiObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPalette::CPalette](../Topic/CPalette::CPalette.md)|Constrói um objeto de `CPalette` sem a paleta anexado do windows.  Você deve inicializar o objeto de `CPalette` com uma das funções de membro de inicialização antes que possa ser usado.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPalette::AnimatePalette](../Topic/CPalette::AnimatePalette.md)|Substitui entradas em paleta lógica identificada pelo objeto de `CPalette` .  O aplicativo não precisa atualizar sua área cliente, como o windows mapeiam as novas entradas em paleta do sistema imediatamente.|  
|[CPalette::CreateHalftonePalette](../Topic/CPalette::CreateHalftonePalette.md)|Cria uma paleta de intervalo mínimo para o contexto de dispositivo e anexá\-la ao objeto de `CPalette` .|  
|[CPalette::CreatePalette](../Topic/CPalette::CreatePalette.md)|Cria uma paleta de cores do windows e anexá\-la ao objeto de `CPalette` .|  
|[CPalette::FromHandle](../Topic/CPalette::FromHandle.md)|Retorna um ponteiro para um objeto de `CPalette` quando dado um identificador para um objeto de paleta do windows.|  
|[CPalette::GetEntryCount](../Topic/CPalette::GetEntryCount.md)|Retorna o número de entradas de paleta em uma paleta lógica.|  
|[CPalette::GetNearestPaletteIndex](../Topic/CPalette::GetNearestPaletteIndex.md)|Retorna o índice de entrada em paleta lógica que melhor corresponde a um valor de cor.|  
|[CPalette::GetPaletteEntries](../Topic/CPalette::GetPaletteEntries.md)|Recupera um intervalo de entradas de paleta em uma paleta lógica.|  
|[CPalette::ResizePalette](../Topic/CPalette::ResizePalette.md)|Altera o tamanho de paleta lógica especificada pelo objeto de `CPalette` para o número especificado de entradas.|  
|[CPalette::SetPaletteEntries](../Topic/CPalette::SetPaletteEntries.md)|Definir valores e sinalizadores de cor RGB em um intervalo de entradas em uma paleta lógica.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPalette::operator HPALETTE](../Topic/CPalette::operator%20HPALETTE.md)|Retorna `HPALETTE` anexado a `CPalette`.|  
  
## Comentários  
 Uma paleta fornece uma interface entre um aplicativo e um dispositivo de saída de cor \(como um dispositivo de vídeo\).  A interface permite o aplicativo tirar proveito total dos recursos de cor do dispositivo de saída fortemente sem interferir com cores exibidas por outros aplicativos.  O windows usa a paleta lógica do aplicativo \(uma lista de cores necessárias\) e a paleta do sistema \(que define cores disponíveis\) para determinar as cores usadas.  
  
 Um objeto de `CPalette` fornece funções de membro para manipular a paleta chamado pelo objeto.  Construir um objeto de `CPalette` e use as funções de membro para criar a paleta real, um objeto de \(GDI\) de interface do dispositivo de elementos gráficos, e para manipular suas entradas e outras propriedades.  
  
 Para obter mais informações sobre como usar `CPalette`, consulte [objetos gráficos](../../mfc/graphic-objects.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CGdiObject](../../mfc/reference/cgdiobject-class.md)  
  
 `CPalette`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC exemplos DIBLOOK](../../top/visual-cpp-samples.md)   
 [Classe de CGdiObject](../../mfc/reference/cgdiobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CPalette::GetPaletteEntries](../Topic/CPalette::GetPaletteEntries.md)   
 [CPalette::SetPaletteEntries](../Topic/CPalette::SetPaletteEntries.md)