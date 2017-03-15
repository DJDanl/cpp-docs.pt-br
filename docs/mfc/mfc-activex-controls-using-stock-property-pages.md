---
title: "Controles ActiveX MFC: usando p&#225;ginas de propriedade de estoque | Microsoft Docs"
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
  - "CLSID_CPicturePropPage"
  - "CLSID_CColorPropPage"
  - "CLSID_CFontPropPage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CLSID_CColorPropPage"
  - "CLSID_CFontPropPage"
  - "CLSID_CPicturePropPage"
  - "páginas de propriedade de estoque de cores"
  - "fontes, Controles ActiveX"
  - "Controles ActiveX MFC, páginas de propriedade"
  - "páginas de propriedade de estoque de figuras"
  - "propriedades de estoque, páginas de propriedade de estoque"
ms.assetid: 22638d86-ff3e-4124-933e-54b7c2a25968
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: usando p&#225;ginas de propriedade de estoque
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve as páginas de propriedades de estoque disponíveis para controles ActiveX e como usá\-los.  
  
 Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os artigos a seguir:  
  
-   [Controles ActiveX MFC: Páginas de propriedades](../mfc/mfc-activex-controls-property-pages.md)  
  
-   [Controles ActiveX MFC: Adicionando outra página de propriedades personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)  
  
 MFC O fornece três páginas de propriedades de estoque para uso com controles ActiveX: **CLSID\_CColorPropPage**, **CLSID\_CFontPropPage**, e **CLSID\_CPicturePropPage**.  Essas páginas exibem uma interface de usuário para a cor, fonte, e as propriedades de estoque da imagem, respectivamente.  
  
 Para inserir essas páginas de propriedades em um controle, adicione suas IDs ao código que inicializa a matriz de controle de IDs de página de propriedades.  No exemplo a seguir, esse código, localizado no arquivo de implementação de controle \(.CPP\), inicializa a matriz para conter todas as três páginas de propriedades de estoque e a página de propriedades padrão \( `CMyPropPage` nomeado neste exemplo\):  
  
 [!code-cpp[NVC_MFC_AxOpt#21](../mfc/codesnippet/CPP/mfc-activex-controls-using-stock-property-pages_1.cpp)]  
  
 Observe que a contagem de páginas de propriedades, em macro de `BEGIN_PROPPAGEIDS` , será 4.  Isso representa o número de páginas de propriedades suportadas pelo controle ActiveX.  
  
 Depois que essas alterações, recriar seu projeto.  O controle agora tem páginas de propriedades da fonte, a imagem, e as propriedades de cores.  
  
> [!NOTE]
>  Se as páginas de propriedades do estoque de controle não podem ser acessadas, pode ser porque o DLL \(MFC MFCxx.DLL\) não foi registrado corretamente com o sistema operacional atual.  Isso resulta em geral da instalação do Visual C\+\+ em um sistema operacional diferente do que executa no momento.  
  
> [!TIP]
>  Se suas páginas de propriedades de estoque não são visíveis \(consulte a observação anterior\), registre a DLL executando o RegSvr32.exe de linha de comando com o nome de caminho completo para a DLL.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: adicionando propriedades de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Properties.md)