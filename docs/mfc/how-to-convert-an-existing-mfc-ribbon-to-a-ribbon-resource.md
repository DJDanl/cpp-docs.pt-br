---
title: 'Como: Converter uma faixa de opções MFC existente em um recurso de faixa de opções'
ms.date: 11/04/2016
helpviewer_keywords:
- ribbon resource, converting from an MFC ribbon
- MFC ribbon, converting to a ribbon resource
ms.assetid: 324b7ff6-58f9-4691-96a9-9836a79d0fb6
ms.openlocfilehash: b4265a7bf3ebe2c4926f21572d802b75bd525990
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389483"
---
# <a name="how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource"></a>Como: Converter uma faixa de opções MFC existente em um recurso de faixa de opções

Recursos da faixa de opções são mais fáceis de visualizar, modificar e manter que faixas de opções manualmente codificadas. Este tópico descreve como converter uma faixa de opções manualmente codificada em um projeto MFC em um recurso de faixa de opções.

Você deve ter um projeto existente do MFC que tem o código que usa as classes de faixa de opções do MFC, por exemplo, [classe CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md).

### <a name="to-convert-an-mfc-ribbon-to-a-ribbon-resource"></a>Para converter uma faixa de opções do MFC para um recurso de faixa de opções

1. No Visual Studio, em um projeto MFC existente, abra o arquivo de origem em que o `CMFCRibbonBar` objeto é inicializado. Normalmente, o arquivo é mainfrm.cpp. Adicione o seguinte código após o código de inicialização para a faixa de opções.

```
    m_wndRibbonBar.SaveToXMLFile("RibbonOutput.xml");
```

   Salve e feche o arquivo.

1. Compilar e executar o aplicativo do MFC e, em seguida, no bloco de notas, abra RibbonOutput.txt e copie o conteúdo.

1. No Visual Studio, sobre o **Project** menu, clique em **adicionar recurso**. No **adicionar recurso** caixa de diálogo, selecione **faixa de opções** e, em seguida, clique em **New**.

   Visual Studio cria um recurso de faixa de opções e abre no modo de design. A ID do recurso da faixa de opções é IDR_RIBBON1, que é exibido na **exibição de recurso**. A faixa de opções é definida no arquivo XML ribbon1.mfcribbon ms.

1. No Visual Studio, abra ribbon1.mfcribbon ms, excluir seu conteúdo e, em seguida, cole o conteúdo do RibbonOutput.txt, que você copiou anteriormente. Salve e feche ribbon1.mfcribbon ms.

1. Abra novamente o arquivo de origem em que o objeto de CMFCRibbonBar é inicializado (normalmente, mainfrm.cpp) e comente existente código da faixa de opções. Adicione o seguinte código após o código que você comentado.

```
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);
```

1. Compile o projeto e execute o programa.

## <a name="see-also"></a>Consulte também

[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)
