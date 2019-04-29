---
title: 'Controles ActiveX MFC: Usando páginas de propriedade de estoque'
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
ms.openlocfilehash: b73a027422cfe9cbf03afece400c1b513cace151
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62239329"
---
# <a name="mfc-activex-controls-using-stock-property-pages"></a>Controles ActiveX MFC: Usando páginas de propriedade de estoque

Este artigo discute as páginas de propriedade de estoque disponíveis para os controles ActiveX e como usá-los.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX MFC: página de propriedades](../mfc/mfc-activex-controls-property-pages.md)

- [Controles ActiveX MFC: adicionar outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)

O MFC fornece três páginas de propriedade de estoque para uso com controles ActiveX: `CLSID_CColorPropPage`, `CLSID_CFontPropPage`, e `CLSID_CPicturePropPage`. Essas páginas exibem uma interface do usuário de estoque cor, fonte e propriedades da imagem, respectivamente.

Para incorporar essas páginas de propriedades em um controle, adicione suas IDs para o código que inicializa a matriz de IDs de página de propriedade do controle. No exemplo a seguir, esse código, localizado no arquivo de implementação de controle (. CPP), inicializa a matriz para conter todos os três páginas de propriedade de estoque e a página de propriedades padrão (denominada `CMyPropPage` neste exemplo):

[!code-cpp[NVC_MFC_AxOpt#21](../mfc/codesnippet/cpp/mfc-activex-controls-using-stock-property-pages_1.cpp)]

Observe que a contagem de páginas de propriedades, na macro BEGIN_PROPPAGEIDS, é 4. Isso representa o número de páginas de propriedade compatível com o controle ActiveX.

Depois de fazer essas modificações, recompile o projeto. Agora, o controle tiver páginas de propriedades para a fonte, imagem e propriedades de cor.

> [!NOTE]
>  Se as páginas de propriedade de estoque de controle não podem ser acessadas, é possível que a DLL do MFC (compartilhadas) não foi registrada corretamente com o sistema operacional atual. Isso geralmente resulta de instalar o Visual C++ em um sistema operacional diferente em execução no momento.

> [!TIP]
>  Se suas páginas de propriedade de estoque não são visíveis (consulte nota anterior), registrar a DLL executando RegSvr32.exe da linha de comando com o nome de caminho completo para a DLL.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX MFC: adicionar propriedades de estoque](../mfc/mfc-activex-controls-adding-stock-properties.md)
