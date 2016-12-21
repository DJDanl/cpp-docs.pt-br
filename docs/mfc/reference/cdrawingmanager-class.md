---
title: "Classe de CDrawingManager | Microsoft Docs"
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
  - "CDrawingManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDrawingManager"
ms.assetid: 9e4775ca-101b-4aa9-a85a-4d047c701215
caps.latest.revision: 30
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDrawingManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe implementa algoritmos de `CDrawingManager` complexos de desenho.  
  
## Sintaxe  
  
```  
class CDrawingManager : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDrawingManager::CDrawingManager](../Topic/CDrawingManager::CDrawingManager.md)|Constrói um objeto de `CDrawingManager` .|  
|`CDrawingManager::~CDrawingManager`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDrawingManager::CreateBitmap\_32](../Topic/CDrawingManager::CreateBitmap_32.md)|Cria um bitmap independente de 32 bits \(DIB\) que os aplicativos podem gravar diretamente.|  
|[CDrawingManager::DrawAlpha](../Topic/CDrawingManager::DrawAlpha.md)|Exibe bitmaps que têm pixels transparentes ou semitransparent.|  
|[CDrawingManager::DrawRotated](../Topic/CDrawingManager::DrawRotated.md)|Rotaciona um dentro do conteúdo de C.C. de origem o retângulo por 90 graus determinado \+\/\-|  
|[CDrawingManager::DrawEllipse](../Topic/CDrawingManager::DrawEllipse.md)|Desenha uma elipse com cores fornecidas de preenchimento e da borda.|  
|[CDrawingManager::DrawGradientRing](../Topic/CDrawingManager::DrawGradientRing.md)|Desenha um anel e preenchê\-lo com um gradiente de cor.|  
|[CDrawingManager::DrawLine, CDrawingManager::DrawLineA](../Topic/CDrawingManager::DrawLine,%20CDrawingManager::DrawLineA.md)|Desenha uma linha.|  
|[CDrawingManager::DrawRect](../Topic/CDrawingManager::DrawRect.md)|Desenhar um retângulo com cores fornecidas de preenchimento e da borda.|  
|[CDrawingManager::DrawShadow](../Topic/CDrawingManager::DrawShadow.md)|Desenha uma sombra para uma área retangular.|  
|[CDrawingManager::Fill4ColorsGradient](../Topic/CDrawingManager::Fill4ColorsGradient.md)|Preenche uma área retangular com gradientes de duas cores.|  
|[CDrawingManager::FillGradient](../Topic/CDrawingManager::FillGradient.md)|Preenche uma área retangular com um gradiente de cor especificada.|  
|[CDrawingManager::FillGradient2](../Topic/CDrawingManager::FillGradient2.md)|Preenche uma área retangular com um gradiente de cor especificada.  A direção de alteração de cor gradiente é especificada também.|  
|[CDrawingManager::GrayRect](../Topic/CDrawingManager::GrayRect.md)|Preenche um retângulo com uma cor cinza especificada.|  
|[CDrawingManager::HighlightRect](../Topic/CDrawingManager::HighlightRect.md)|Realça uma área retangular.|  
|[CDrawingManager::HLStoRGB\_ONE](../Topic/CDrawingManager::HLStoRGB_ONE.md)|Converte uma cor de uma representação de HLS a uma representação de RGB.|  
|[CDrawingManager::HLStoRGB\_TWO](../Topic/CDrawingManager::HLStoRGB_TWO.md)|Converte uma cor de uma representação de HLS a uma representação de RGB.|  
|[CDrawingManager::HSVtoRGB](../Topic/CDrawingManager::HSVtoRGB.md)|Converte uma cor de uma representação de HSV a uma representação de RGB.|  
|[CDrawingManager::HuetoRGB](../Topic/CDrawingManager::HuetoRGB.md)|Método auxiliar que converte um valor de matiz a um componente vermelho, verde, ou azul.|  
|[CDrawingManager::MirrorRect](../Topic/CDrawingManager::MirrorRect.md)|Inverte uma área retangular.|  
|[CDrawingManager::PixelAlpha](../Topic/CDrawingManager::PixelAlpha.md)|Método auxiliar que determina a cor final para um pixel semitransparent.|  
|[CDrawingManager::PrepareShadowMask](../Topic/CDrawingManager::PrepareShadowMask.md)|Cria um bitmap que pode ser usado como uma sombra.|  
|[CDrawingManager::RGBtoHSL](../Topic/CDrawingManager::RGBtoHSL.md)|Converte uma cor de uma representação RGB a uma representação de HSL.|  
|[CDrawingManager::RGBtoHSV](../Topic/CDrawingManager::RGBtoHSV.md)|Converte uma cor de uma representação RGB a uma representação de HSV.|  
|[CDrawingManager::SetAlphaPixel](../Topic/CDrawingManager::SetAlphaPixel.md)|Método auxiliar de cores um pixel parcialmente transparente em um bitmap.|  
|[CDrawingManager::SetPixel](../Topic/CDrawingManager::SetPixel.md)|Método auxiliar que modificam um único pixel em um bitmap a cor especificada.|  
|[CDrawingManager::SmartMixColors](../Topic/CDrawingManager::SmartMixColors.md)|Combina duas cores com base em uma taxa tornada mais pesado.|  
  
## Comentários  
 A classe de `CDrawingManager` fornece funções para desenhar sombras, gradientes de cor, retângulos e realçadas.  Também executa a Alpha\- combinação.  Você pode usar esta classe para modificar diretamente a interface do usuário do seu aplicativo.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CDrawingManager](../../mfc/reference/cdrawingmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxdrawmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)