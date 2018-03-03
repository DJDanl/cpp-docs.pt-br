---
title: Estrutura NCCALCSIZE_PARAMS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- NCCALCSIZE_PARAMS
dev_langs:
- C++
helpviewer_keywords:
- NCCALCSIZE_PARAMS structure [MFC]
ms.assetid: 3424cd9f-806a-4089-82fb-414187589edf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76a0a16ff0a2c90c6dd6060badc2c79dde1af231
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nccalcsizeparams-structure"></a>Estrutura NCCALCSIZE_PARAMS
O `NCCALCSIZE_PARAMS` estrutura contém informações que um aplicativo pode usar durante o processamento de `WM_NCCALCSIZE` mensagem para calcular o tamanho, posição e conteúdo válido da área cliente de uma janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagNCCALCSIZE_PARAMS {  
    RECT rgrc[3];  
    PWINDOWPOS lppos;  
} NCCALCSIZE_PARAMS;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *rgrc*  
 Especifica uma matriz de retângulos. O primeiro contém novas coordenadas de uma janela que tenha sido movido ou redimensionado. O segundo contém as coordenadas da janela antes que ele foi movido ou redimensionado. A terceira contém as coordenadas da área cliente de uma janela antes que ele foi movido ou redimensionado. Se a janela é uma janela filho, as coordenadas são relativas à área do cliente da janela pai. Se a janela é uma janela de nível superior, as coordenadas são em relação à tela.  
  
 *lppos*  
 Aponta para um [WINDOWPOS](../../mfc/reference/windowpos-structure1.md) estrutura que contém os valores de tamanho e posição especificados na operação que causou a janela a ser movido ou redimensionado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)

