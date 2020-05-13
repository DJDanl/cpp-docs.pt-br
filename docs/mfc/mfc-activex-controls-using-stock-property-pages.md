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
ms.openlocfilehash: 13a0edb72657c9ffad00dcb909019bdfe4b87e11
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358211"
---
# <a name="mfc-activex-controls-using-stock-property-pages"></a>Controles ActiveX MFC: usando páginas de propriedade de estoque

Este artigo discute as páginas de propriedade de estoque disponíveis para controles ActiveX e como usá-las.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Para obter mais informações sobre o uso de páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)

- [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)

O MFC fornece três páginas de propriedade `CLSID_CColorPropPage`de `CLSID_CFontPropPage`estoque `CLSID_CPicturePropPage`para uso com controles ActiveX: , e . Essas páginas exibem uma interface de usuário para propriedades de cor, fonte e imagem de estoque, respectivamente.

Para incorporar essas páginas de propriedade em um controle, adicione seus IDs ao código que inicializa o conjunto de IDs de página de propriedade do controle. No exemplo a seguir, este código, localizado no arquivo de implementação de controle (. CPP), inicializa a matriz para conter todas as três páginas `CMyPropPage` de propriedade de estoque e a página de propriedade padrão (nomeada neste exemplo):

[!code-cpp[NVC_MFC_AxOpt#21](../mfc/codesnippet/cpp/mfc-activex-controls-using-stock-property-pages_1.cpp)]

Note que a contagem de páginas de propriedade, na BEGIN_PROPPAGEIDS macro, é 4. Isso representa o número de páginas de propriedade suportadas pelo controle ActiveX.

Depois que essas modificações tiverem sido feitas, reconstrua seu projeto. Seu controle agora tem páginas de propriedade para as propriedades de fonte, imagem e cor.

> [!NOTE]
> Se as páginas de propriedade de estoque de controle não puderem ser acessadas, pode ser porque o MFC DLL (MFCxx.DLL) não foi devidamente registrado no sistema operacional atual. Isso geralmente resulta da instalação do Visual C++ em um sistema operacional diferente do que está sendo executado atualmente.

> [!TIP]
> Se as páginas da propriedade de ações não estiverem visíveis (veja nota anterior), registre a DLL executando RegSvr32.exe da linha de comando com o nome completo do caminho para a DLL.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: adicionando propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md)
