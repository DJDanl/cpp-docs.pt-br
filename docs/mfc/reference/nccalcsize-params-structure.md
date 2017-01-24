---
title: "Estrutura NCCALCSIZE_PARAMS | Microsoft Docs"
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
  - "NCCALCSIZE_PARAMS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura NCCALCSIZE_PARAMS"
ms.assetid: 3424cd9f-806a-4089-82fb-414187589edf
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura NCCALCSIZE_PARAMS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `NCCALCSIZE_PARAMS` estrutura contém informações que um aplicativo pode usar durante o processamento de `WM_NCCALCSIZE` mensagem para calcular o tamanho, posição e conteúdo válido da área do cliente de uma janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    typedef struct tagNCCALCSIZE_PARAMS {  
    RECT rgrc[3];  
    PWINDOWPOS lppos;  
} NCCALCSIZE_PARAMS;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *rgrc*  
 Especifica uma matriz dos retângulos. O primeiro contém as novas coordenadas de uma janela que tenha sido movido ou redimensionado. O segundo contém as coordenadas da janela antes que ele foi movido ou redimensionado. A terceira contém as coordenadas da área do cliente de uma janela antes que ele foi movido ou redimensionado. Se a janela é uma janela filho, as coordenadas são em relação a área cliente da janela pai. Se a janela é uma janela de nível superior, as coordenadas são em relação à tela.  
  
 *lppos*  
 Aponta para um [WINDOWPOS](../../mfc/reference/windowpos-structure1.md) estrutura que contém os valores de tamanho e posição especificados na operação que causou a janela a ser movido ou redimensionado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnNcCalcSize](../Topic/CWnd%20Class.md#OnNcCalcSize)

