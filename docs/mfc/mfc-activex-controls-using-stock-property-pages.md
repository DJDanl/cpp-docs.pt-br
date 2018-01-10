---
title: "Controles ActiveX MFC: Usando páginas de propriedade de estoque | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CLSID_CPicturePropPage
- CLSID_CColorPropPage
- CLSID_CFontPropPage
dev_langs: C++
helpviewer_keywords:
- picture stock property pages [MFC]
- CLSID_CFontPropPage [MFC]
- color stock property pages [MFC]
- CLSID_CColorPropPage [MFC]
- fonts [MFC], ActiveX controls
- stock properties [MFC], stock property pages
- CLSID_CPicturePropPage [MFC]
- MFC ActiveX controls [MFC], property pages
ms.assetid: 22638d86-ff3e-4124-933e-54b7c2a25968
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ed2d8cd6c852a15c4190c16c049e29577b754ce7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-using-stock-property-pages"></a>Controles ActiveX MFC: usando páginas de propriedade de estoque
Este artigo aborda as páginas de propriedade de estoque disponíveis para controles ActiveX e como usá-los.  
  
 Para obter mais informações sobre como usar páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:  
  
-   [Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)  
  
-   [Controles ActiveX do MFC: adicionando outra página de propriedades personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)  
  
 MFC fornece três páginas de propriedade de estoque para uso com controles ActiveX: **CLSID_CColorPropPage**, **CLSID_CFontPropPage**, e **CLSID_CPicturePropPage**. Essas páginas exibem a interface do usuário de estoque cor, fonte e propriedades da imagem, respectivamente.  
  
 Para incorporar essas páginas de propriedades em um controle, adicione suas IDs para o código que inicializa a matriz de IDs de página de propriedade do controle. No exemplo a seguir, esse código, localizado no arquivo de implementação de controle (. CPP) inicializa a matriz para conter todos os três páginas de propriedade de estoque e a página de propriedades padrão (denominada `CMyPropPage` neste exemplo):  
  
 [!code-cpp[NVC_MFC_AxOpt#21](../mfc/codesnippet/cpp/mfc-activex-controls-using-stock-property-pages_1.cpp)]  
  
 Observe que a contagem de propriedade de páginas, além de `BEGIN_PROPPAGEIDS` macro é 4. Isso representa o número de páginas de propriedades com suporte pelo controle ActiveX.  
  
 Depois que essas modificações foram feitas, recompile o projeto. O controle agora tem páginas de propriedade para propriedades de cor, fonte e imagem.  
  
> [!NOTE]
>  Se as páginas de propriedade de estoque de controle não podem ser acessadas, pode ser porque a DLL do MFC (MFCxx.DLL) não foi registrada corretamente com o sistema operacional atual. Geralmente, isso resulta de instalação do Visual C++ em um sistema operacional diferente em execução no momento.  
  
> [!TIP]
>  Se as páginas de propriedade de estoque não são visíveis (consulte a observação anterior), registrar a DLL executando RegSvr32.exe da linha de comando com o nome de caminho completo para a DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX do MFC: adicionando propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md)

