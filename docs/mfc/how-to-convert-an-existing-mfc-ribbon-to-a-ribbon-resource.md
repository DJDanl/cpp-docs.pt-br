---
title: Como converter uma faixa de opções MFC existente em um recurso da faixa de opções
ms.date: 11/04/2016
helpviewer_keywords:
- ribbon resource, converting from an MFC ribbon
- MFC ribbon, converting to a ribbon resource
ms.assetid: 324b7ff6-58f9-4691-96a9-9836a79d0fb6
ms.openlocfilehash: 56f36c977453d338b9e9bbd2462c1a8830ffe258
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620068"
---
# <a name="how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource"></a>Como converter uma faixa de opções MFC existente em um recurso da faixa de opções

Os recursos da faixa de faixas são mais fáceis de Visualizar, modificar e manter do que as faixas de faixa codificadas manualmente. Este tópico descreve como converter uma faixa de faixas codificada manualmente em um projeto do MFC em um recurso da faixa de faixas.

Você deve ter um projeto MFC existente que tenha um código que usa as classes de faixa de da MFC, por exemplo, a [classe CMFCRibbonBar](reference/cmfcribbonbar-class.md).

### <a name="to-convert-an-mfc-ribbon-to-a-ribbon-resource"></a>Para converter uma faixa de faixas do MFC em um recurso da faixa de faixas

1. No Visual Studio, em um projeto existente do MFC, abra o arquivo de origem onde o `CMFCRibbonBar` objeto é inicializado. Normalmente, o arquivo é MainFrm. cpp. Adicione o código a seguir após o código de inicialização para a faixa de opções.

```
    m_wndRibbonBar.SaveToXMLFile("RibbonOutput.xml");
```

   Salve e feche o arquivo.

1. Compile e execute o aplicativo MFC e, em seguida, no bloco de notas, abra RibbonOutput. txt e copie seu conteúdo.

1. No Visual Studio, no menu **projeto** , clique em **Adicionar recurso**. Na caixa de diálogo **Adicionar recurso** , selecione **faixa** de opções e clique em **novo**.

   O Visual Studio cria um recurso de faixa de faixas e o abre no modo de exibição de design. A ID do recurso da faixa de faixas é IDR_RIBBON1, que é exibida em **modo de exibição de recursos**. A faixa de faixas é definida no arquivo XML Ribbon1. mfcribbon-MS.

1. No Visual Studio, abra Ribbon1. mfcribbon-MS, exclua seu conteúdo e, em seguida, Cole o conteúdo de RibbonOutput. txt que você copiou anteriormente. Salve e feche Ribbon1. mfcribbon-MS.

1. Novamente Abra o arquivo de origem em que o objeto CMFCRibbonBar é inicializado (normalmente, MainFrm. cpp) e comente o código da faixa de Ribbon existente. Adicione o código a seguir após o código que você comentou.

```
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);
```

1. Compile o projeto e execute o programa.

## <a name="see-also"></a>Consulte também

[Designer de faixa de Ribbon (MFC)](ribbon-designer-mfc.md)
