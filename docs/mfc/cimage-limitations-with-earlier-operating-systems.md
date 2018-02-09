---
title: "Limitações de CImage com sistemas operacionais anteriores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CImage
dev_langs:
- C++
helpviewer_keywords:
- CImage class [MFC], limitations
ms.assetid: 4bedaab8-7dd1-4c91-ab35-b75fb56765b0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 27046704975bf8f5e28f12acbfa72e860660fdbd
ms.sourcegitcommit: 30ab99c775d99371ed22d1a46598e542012ed8c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/08/2018
---
# <a name="cimage-limitations-with-earlier-operating-systems"></a>Limitações de CImage com sistemas operacionais anteriores
Muitos `CImage` funções funcionam somente com as versões mais recentes do Windows: Windows 95/98 ou Windows NT 4.0 ou Windows 2000. Este artigo descreve as limitações da versão de certos métodos.  
  
 [CImage::PlgBlt](../atl-mfc-shared/reference/cimage-class.md#plgblt) e [CImage::MaskBlt](../atl-mfc-shared/reference/cimage-class.md#maskblt) funcionam com somente o Windows NT 4.0 ou posterior. Elas não funcionarão em aplicativos em execução no Windows 95/98 ou posterior.  
  
 [CImage::AlphaBlend](../atl-mfc-shared/reference/cimage-class.md#alphablend) e [CImage::TransparentBlt](../atl-mfc-shared/reference/cimage-class.md#transparentblt) funcionam com somente o Windows 2000 ou posterior e Windows 98 ou posterior, porque você deve vincular com msimg32.lib usar esses métodos. (Essa biblioteca está disponível apenas para aplicativos que executam o Windows 2000 ou posterior e Windows 98 ou posterior.)  
  
 Você pode incluir `AlphaBlend` e `TransparentBlt` em um aplicativo que é executado no Windows 95 ou Windows NT 4.0 somente se esses métodos nunca serão chamados. Se seu aplicativo incluir esses métodos, e ele deve ser executado em sistemas operacionais anteriores, você deve usar o vinculador [/delayload](../build/reference/delayload-delay-load-import.md) para atrasar o carregamento de msimg32.lib. Desde que o aplicativo não chamar um dos seguintes métodos durante a execução no Windows NT 4.0 ou Windows 95, ele não tentará carregar msimg32.lib. Você pode verificar se o suporte da transparência está disponível com o `CImage::IsTransparencySupported` método.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI#8](../mfc/codesnippet/cpp/cimage-limitations-with-earlier-operating-systems_1.cpp)]  
  
 Para compilar um aplicativo que chama esses métodos, insira um #define a instrução _WIN32_WINNT antes #including quaisquer cabeçalhos de sistema, indicando que a versão do Windows é igual ou maior que 5.0:  
  
 [!code-cpp[NVC_MFCDocViewSDI#9](../mfc/codesnippet/cpp/cimage-limitations-with-earlier-operating-systems_2.h)]  
  
 Se seu aplicativo não precisa executar em um sistema operacional anterior ao Windows 2000 ou Windows 98, você pode vincular diretamente a msimg32.lib sem usar **/delayload**.  
  
 [CImage::Draw](../atl-mfc-shared/reference/cimage-class.md#draw) tem um comportamento diferente quando usado com o Windows 2000 e Windows 98 do que com o Windows NT 4.0 ou Windows 95.  
  
 Se você compilar seu aplicativo com _WIN32_WINNT definido para um valor menor que 0x0500, **desenhar** funcionam, mas ele será não manipulará transparência automaticamente em sistemas que executam o Windows 2000 e Windows 98 ou posterior.  
  
 Se você compilar seu aplicativo com _WIN32_WINNT definido como 0x0500 ou maior, **desenhar** tratará transparência automaticamente em sistemas que executam o Windows 2000 ou Windows 98 ou posterior. Ele também funcionará, mas sem suporte a transparência, com o Windows NT 4.0 e Windows 95; No entanto, você deve usar **/delayload** para atrasar o carregamento de msimg32. LIB, conforme descrito acima para `AlphaBlend` e `TransparentBlt`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CImage](../atl-mfc-shared/reference/cimage-class.md)
