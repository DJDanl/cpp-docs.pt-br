---
title: 'Controles ActiveX MFC: usando páginas de propriedade de estoque'
ms.date: 09/12/2018
f1_keywords:
- CLSID_CPicturePropPage
- CLSID_CColorPropPage
- CLSID_CFontPropPage
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
ms.openlocfilehash: 18e482ca93166246df7569be9babff93d983dfd5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618058"
---
# <a name="mfc-activex-controls-using-stock-property-pages"></a>Controles ActiveX MFC: usando páginas de propriedade de estoque

Este artigo discute as páginas de propriedades de estoque disponíveis para controles ActiveX e como usá-las.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX do MFC: páginas de propriedade](mfc-activex-controls-property-pages.md)

- [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](mfc-activex-controls-adding-another-custom-property-page.md)

O MFC fornece três páginas de propriedades de estoque para uso com controles ActiveX: `CLSID_CColorPropPage` , `CLSID_CFontPropPage` e `CLSID_CPicturePropPage` . Essas páginas exibem uma interface do usuário para propriedades de cor, fonte e imagem de estoque, respectivamente.

Para incorporar essas páginas de propriedades em um controle, adicione suas IDs ao código que inicializa a matriz do controle de IDs de página de propriedades. No exemplo a seguir, esse código, localizado no arquivo de implementação de controle (. CPP), inicializa a matriz para conter todas as três páginas de propriedades de estoque e a página de propriedades padrão (denominada `CMyPropPage` neste exemplo):

[!code-cpp[NVC_MFC_AxOpt#21](codesnippet/cpp/mfc-activex-controls-using-stock-property-pages_1.cpp)]

Observe que a contagem de páginas de propriedades, na macro BEGIN_PROPPAGEIDS, é 4. Isso representa o número de páginas de propriedades com suporte pelo controle ActiveX.

Depois que essas modificações tiverem sido feitas, recompile o projeto. Seu controle agora tem páginas de propriedades para a fonte, a imagem e as propriedades de cor.

> [!NOTE]
> Se as páginas de propriedades de estoque de controle não puderem ser acessadas, talvez seja porque a DLL do MFC (MFCxx. DLL) não foi registrada corretamente com o sistema operacional atual. Isso geralmente resulta da instalação de Visual C++ em um sistema operacional diferente do que está sendo executado no momento.

> [!TIP]
> Se suas páginas de propriedades de estoque não estiverem visíveis (consulte a observação anterior), registre a DLL executando RegSvr32. exe na linha de comando com o nome do caminho completo para a DLL.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: adicionando propriedades de estoque](mfc-activex-controls-adding-stock-properties.md)
