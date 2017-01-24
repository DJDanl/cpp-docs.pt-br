---
title: "Estrutura BITMAPINFO | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "BITMAPINFO"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura BITMAPINFO"
ms.assetid: a00caa49-e4df-419f-89a7-ab03c13a1b5b
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura BITMAPINFO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `BITMAPINFO` define as dimensões e informações de cor para um bitmap dispositivo independentemente do windows \(DIB\).  
  
## Sintaxe  
  
```  
typedef struct tagBITMAPINFO {  
   BITMAPINFOHEADER bmiHeader;  
   RGBQUAD bmiColors[1];  
} BITMAPINFO;  
```  
  
#### Parâmetros  
 `bmiHeader`  
 Especifica uma estrutura de [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376) que contém informações sobre as dimensões e o formato da cor de um bitmap dispositivo independente.  
  
 `bmiColors`  
 Especifica uma matriz de [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938) ou os tipos de dados de `DWORD` que definem as cores no bitmap.  
  
## Comentários  
 Um bitmap dispositivo independente consiste em duas partes distintas: uma estrutura de `BITMAPINFO` que descreve as dimensões e as cores de bitmap, e uma matriz de bytes que especifica os pixels no bitmap.  Os bits na matriz são empacotados em conjunto, mas cada linha de auditoria deve ser preenchida com zeros para terminar em um limite de `LONG` .  Se a altura for positivo, a origem de bitmap é o canto inferior esquerdo.  Se a altura for negativo, a origem é o canto superior esquerdo.  
  
 *Um bitmap empacotado* é um bitmap onde a matriz de bytes siga imediatamente a estrutura de `BITMAPINFO` .  Os bitmaps empacotados são referenciadas por um único ponteiro.  
  
 Para obter mais informações sobre a estrutura de `BITMAPINFO` e valores apropriados para membros das estruturas de `BITMAPINFOHEADER` e de `RGBQUAD` , consulte os seguintes tópicos na documentação de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] .  
  
-   [\<caps:sentence id\="tgt11" sentenceid\="b5dd2e8c9cedbac12eb858bd01a029a2" class\="tgtSentence"\>Estrutura de BITMAPINFO\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/dd183375)  
  
-   estrutura de[BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376)  
  
-   estrutura de[RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938)  
  
## Requisitos  
 **Cabeçalho:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBrush::CreateDIBPatternBrush](../Topic/CBrush::CreateDIBPatternBrush.md)   
 [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376)   
 [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938)