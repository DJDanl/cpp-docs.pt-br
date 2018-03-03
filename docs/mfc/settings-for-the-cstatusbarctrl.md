---
title: "Configurações do CStatusBarCtrl | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CStatusBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- status bar controls [MFC], settings
- CStatusBarCtrl class [MFC], settings
ms.assetid: adeba0c3-17f3-435c-b140-a57845e9ce49
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 814c12b13333d589cb568c5c637f0fa34956847e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="settings-for-the-cstatusbarctrl"></a>Configurações do CStatusBarCtrl
A posição padrão de um [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) janela de status é na parte inferior da janela pai, mas você pode especificar o `CCS_TOP` estilo para que ele apareça na parte superior da área cliente da janela pai.  
  
 Você pode especificar o **SBARS_SIZEGRIP** estilo para incluir uma alça de dimensionamento na extremidade direita do `CStatusBarCtrl` janela de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.  
  
> [!NOTE]
>  Se você combinar o `CCS_TOP` e **SBARS_SIZEGRIP** estilos, a alça de dimensionamento resultante não está funcionando, embora o sistema desenha na janela de status.  
  
 O procedimento de janela para a janela de status define automaticamente o tamanho inicial e a posição da janela do controle. A largura é o mesmo da área cliente da janela pai. A altura baseia-se a métrica da fonte selecionada no momento no contexto de dispositivo da janela de status e a largura das bordas da janela.  
  
 O procedimento de janela ajusta automaticamente o tamanho da janela de status sempre que ele recebe um `WM_SIZE` mensagem. Normalmente, quando o tamanho da janela pai for alterada, o pai envia um `WM_SIZE` mensagem para a janela de status.  
  
 Você pode definir a altura mínima da área de desenho de uma janela de status chamando [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight), especificando a altura mínima em pixels. A área de desenho não incluem as bordas da janela.  
  
 Recuperar as larguras das bordas de uma janela de status chamando [GetBorders](../mfc/reference/cstatusbarctrl-class.md#getborders). Essa função de membro inclui o ponteiro para uma matriz de três elementos que recebe a largura da borda horizontal, vertical borda e a borda entre os retângulos.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

