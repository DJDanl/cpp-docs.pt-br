---
title: "Estrutura BITMAP | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "BITMAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura BITMAP"
ms.assetid: 05d33b4d-7232-4643-a108-87dda8ff5f22
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura BITMAP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de **BITMAP** define a altura, a largura, o formato de cor, e os valores de bit de um bitmap lógico**.**  
  
## Sintaxe  
  
```  
  
      typedef struct tagBITMAP {  /* bm */  
   int bmType;  
   int bmWidth;  
   int bmHeight;  
   int bmWidthBytes;  
   BYTE bmPlanes;  
   BYTE bmBitsPixel;  
   LPVOID bmBits;  
} BITMAP;  
```  
  
#### Parâmetros  
 *bmType*  
 Especifica o tipo de bitmap.  Para bitmaps lógicos, este membro deve ser 0.  
  
 *bmWidth*  
 Especifica a largura de bitmap em pixels.  A largura deve ser maior que 0.  
  
 *bmHeight*  
 Especifica a altitude de bitmap nas linhas de quadriculação.  A altura deve ser maior que 0.  
  
 *bmWidthBytes*  
 Especifica o número de bytes em cada linha de quadriculação.  Esse valor deve ser um número par desde que a interface de dispositivo \(GDI\) de gráficos supõe que os valores de bit de um bitmap formam uma matriz de valores de inteiro \(2 bytes\).  Ou seja **bmWidthBytes** \* 8 devem ser seguir o múltiplo de 16 maior ou igual ao valor obtido quando o membro de **bmWidth** é multiplicado pelo membro de **bmBitsPixel** .  
  
 *bmPlanes*  
 Especifica o número de planos de cor no bitmap.  
  
 *bmBitsPixel*  
 Especifica o número de bits de cor adjacentes em cada plano necessário definir um x.  
  
 *bmBits*  
 Aponta para o local dos valores de bit para o bitmap.  O membro de **bmBits** deve ser um ponteiro ao passar uma matriz de valores de 1 byte.  
  
## Comentários  
 Os formatos usados no momento de bitmap são monocromáticos e cor.  O bitmap monocromático usa um 1 bit, 1 formato plano.  Cada auditoria é um múltiplo de 16 bits.  
  
 As auditorias são organizados como segue para um bitmap monocromático da altura *em*:  
  
 `Scan 0`  
  
 `Scan 1`  
  
 `.`  
  
 `.`  
  
 `.`  
  
 `Scan n-2`  
  
 `Scan n-1`  
  
 Os pixels em um dispositivo são preto monocromático ou branco.  Se o bit correspondente no bitmap é 1, o x é ativado \(branco\).  Se o bit correspondente no bitmap é 0 pixels, o está desativado \(preto\).  
  
 Todos os dispositivos dão suporte aos bitmaps que têm **RC\_BITBLT** bit definido no índice de **RASTERCAPS** da função de membro de [CDC::GetDeviceCaps](../Topic/CDC::GetDeviceCaps.md) .  
  
 Cada dispositivo tem seu próprio formato exclusivo da cor.  Para transferir um bitmap de um dispositivo para outro, use as funções do windows de [GetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd144879) e de [SetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd162973) .  
  
## Requisitos  
 **Header:** wingdi.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBitmap::CreateBitmapIndirect](../Topic/CBitmap::CreateBitmapIndirect.md)