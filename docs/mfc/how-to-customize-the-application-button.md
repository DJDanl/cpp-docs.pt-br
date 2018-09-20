---
title: 'Como: personalizar o botão do aplicativo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- application button [MFC], customizing
ms.assetid: ebb11180-ab20-43df-a234-801feca9eb38
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef82904a5c84847f3f0064cba6dee171c960f135
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46401466"
---
# <a name="how-to-customize-the-application-button"></a>Como personalizar o botão do aplicativo

Quando você clica no botão de aplicativo, é exibido um menu de comandos. Normalmente, o menu contém comandos relacionados ao arquivo, como **aberto**, **salve**, **impressão**, e **Exit**.

![Botão de aplicativo de faixa de opções do MFC](../mfc/media/application_button.png "application_button")

Para personalizar o botão do aplicativo, abri-lo na **propriedades** , modifique suas propriedades e, em seguida, o controle de faixa de opções de visualização.

### <a name="to-open-the-application-button-in-the-properties-window"></a>Para abrir o botão do aplicativo na janela Propriedades

1. No Visual Studio, sobre o **modo de exibição** menu, clique em **exibição de recurso**.

1. Na **exibição de recurso**, clique duas vezes no recurso de faixa de opções para exibi-lo na superfície de design.

1. Na superfície de design, clique com botão direito do menu de botão do aplicativo e, em seguida, clique em **propriedades**.

## <a name="application-button-properties"></a>Propriedades do botão de aplicativo

A tabela a seguir define as propriedades do botão de aplicativo.

|Propriedade|Definição|
|--------------|----------------|
|**Botões**|Contém a coleção de até três botões que aparecem no canto inferior direito do menu do aplicativo.|
|**Caption**|Especifica o texto do controle. Diferentemente de outros elementos de faixa de opções, o botão do aplicativo não exibe o texto da legenda. Em vez disso, o texto é usado para acessibilidade.|
|**Imagem HDPI**|Especifica o identificador da alta pontos por polegada ícone do botão de aplicativo (HDPI). Quando o aplicativo é executado em um monitor DPI alta, **imagem HDPI** é usado em vez de **imagem**.|
|**Imagens grandes HDPI**|Especifica o identificador das imagens grandes de DPI alta. Quando o aplicativo é executado em um monitor DPI alta, **imagens grandes HDPI** é usado em vez de **imagens grandes**.|
|**Imagens pequenas HDPI**|Especifica o identificador das imagens pequenas de DPI alta. Quando o aplicativo é executado em um monitor DPI alta, **imagens pequenas HDPI** é usado em vez de **imagens pequenas**.|
|**ID**|Especifica o identificador do controle.|
|**Image**|Especifica o identificador do ícone do botão do aplicativo. O ícone é um bitmap de 26, 26 de 32 bits com transparência alfa. As partes transparentes do ícone são realçadas quando o botão do aplicativo é clicado ou colocado em cima.|
|**Chaves**|Especifica a cadeia de caracteres que é exibida quando a navegação de dica de tecla está habilitada. Navegação de dica de tecla é habilitada quando você pressiona ALT.|
|**Imagens grandes**|Especifica o identificador da imagem que contém uma série de ícones de 32 x 32. Os ícones são usados por botões na coleção de itens de Main.|
|**Itens principais**|Contém uma coleção de itens de menu que aparecem no menu do aplicativo.|
|**Legenda MRU**|Especifica o texto exibido no painel de lista recente.|
|**Imagens pequenas**|Especifica o identificador da imagem que contém uma série de ícones de 16 x 16. Os ícones são usados pelos botões na coleção de botões.|
|**Use**|Habilita ou desabilita o painel de lista recente. O painel de lista recente aparece no menu do aplicativo.|
|**Largura**|Especifica a largura em pixels, do painel lista recente.|

O menu de aplicativo não for exibido na superfície de design. Para exibi-lo, você deve visualizar a faixa de opções ou executar o aplicativo.

#### <a name="to-preview-the-ribbon-control"></a>Para visualizar o controle de faixa de opções

- Sobre o **barra de ferramentas do Editor de faixa de opções**, clique em **faixa de opções de teste**.

## <a name="see-also"></a>Consulte também

[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

