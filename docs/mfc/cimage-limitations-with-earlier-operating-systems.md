---
title: "Limita&#231;&#245;es de CImage com sistemas operacionais anteriores | Microsoft Docs"
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
  - "CImage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CImage, limitações"
ms.assetid: 4bedaab8-7dd1-4c91-ab35-b75fb56765b0
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limita&#231;&#245;es de CImage com sistemas operacionais anteriores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Muitas funções de `CImage` funcionam apenas com versões mais novas do windows: Windows 95 e Windows NT 98 ou 4.0, ou Windows 2000.  Este artigo descreve limitações da versão de certos métodos.  
  
 [CImage::PlgBlt](../Topic/CImage::PlgBlt.md) e [CImage::MaskBlt](../Topic/CImage::MaskBlt.md) funcionam apenas com o Windows NT 4.0 ou posterior.  Não funcionarão em aplicativos que executam o Windows 95 e no 98 ou posterior.  
  
 [CImage::AlphaBlend](../Topic/CImage::AlphaBlend.md) e [CImage::TransparentBlt](../Topic/CImage::TransparentBlt.md) funcionam apenas com o Windows 2000 ou posterior e o Windows 98 ou posterior porque você deve estabelecer um vínculo com msimg32.lib para usar esses métodos. \(Essa biblioteca estiver disponível para aplicativos que executam o Windows 2000 ou posterior e o Windows 98 ou posterior.\)  
  
 Você pode incluir `AlphaBlend` e `TransparentBlt` em um aplicativo que é executado no Windows 95 ou Windows NT 4.0 somente se esses métodos nunca são chamado.  Se seu aplicativo incluir esses métodos, e deve ser executado em sistemas operacionais anteriores, você deve usar [\/delayload](../build/reference/delayload-delay-load-import.md) do vinculador para reter a carga de msimg32.lib.  Como seu aplicativo não chama um desses métodos ao executar no Windows NT 4.0 ou Windows 95, não tentará carregar msimg32.lib.  Você pode verificar se o suporte de transparência está disponível por meio do método de `CImage::IsTransparencySupported` .  
  
## Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI#8](../mfc/codesnippet/CPP/cimage-limitations-with-earlier-operating-systems_1.cpp)]  
  
 Para criar um aplicativo que chama esses métodos, insira uma instrução de \#define \_WIN32\_WINNT antes de \#including qualquer cabeçalho do sistema, indicando que a versão do windows for igual a ou maior que 5,0:  
  
 [!code-cpp[NVC_MFCDocViewSDI#9](../mfc/codesnippet/CPP/cimage-limitations-with-earlier-operating-systems_2.h)]  
  
 Se seu aplicativo não precisa executar em um sistema operacional mais antiga do que o Windows 2000 ou Windows 98, você pode vincular diretamente a msimg32.lib sem usar **\/delayload**.  
  
 [CImage::Draw](../Topic/CImage::Draw.md) se comporta de modo diferente quando usado com o Windows 2000 e Windows 98 do que faz com o Windows NT 4.0 ou Windows 95.  
  
 Se você criar seu aplicativo com o \_WIN32\_WINNT definido como um valor menor que 0x0500, **Desenhar** funcionará, mas não tratará a transparência automaticamente nos sistemas que executam o Windows 2000 e Windows 98 e versões posteriores.  
  
 Se você criar seu aplicativo com o \_WIN32\_WINNT definido como 0x0500 ou maior, **Desenhar** tratará a transparência automaticamente nos sistemas que executam o Windows 2000 ou Windows 98 e versões posteriores.  Também funcionará, mas sem suporte de transparência, com o Windows NT 4.0 e Windows 95; porém, você deve usar **\/delayload** para reter a carga de msimg32.LIB, como descrito acima para `AlphaBlend` e `TransparentBlt`.  
  
## Consulte também  
 [Classe de CImage](../atl-mfc-shared/reference/cimage-class.md)