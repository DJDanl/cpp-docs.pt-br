---
title: Como personalizar o botão do aplicativo
ms.date: 09/07/2019
helpviewer_keywords:
- application button [MFC], customizing
ms.assetid: ebb11180-ab20-43df-a234-801feca9eb38
ms.openlocfilehash: 9160e602848adf8dc95c840d702e0b1a1b2f9049
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620034"
---
# <a name="how-to-customize-the-application-button"></a>Como personalizar o botão do aplicativo

Quando você clica no botão aplicativo, um menu de comandos é exibido. Normalmente, o menu contém comandos relacionados a arquivos, como **abrir**, **salvar**, **Imprimir**e **sair**.

![Botão do aplicativo da faixa de da MFC](../mfc/media/application_button.png "Botão do aplicativo da faixa de da MFC")

Para personalizar o botão aplicativo, abra-o na janela **Propriedades** (em **modo de exibição de recursos**), modifique suas propriedades e, em seguida, visualize o controle faixa de faixas.

### <a name="to-open-the-application-button-in-the-properties-window"></a>Para abrir o botão aplicativo no janela Propriedades

1. No Visual Studio, no menu **Exibir** , clique em **modo de exibição de recursos**.

1. Em **modo de exibição de recursos**, clique duas vezes no recurso da faixa de bits para exibi-lo na superfície de design.

1. Na superfície de design, clique com o botão direito do mouse no menu do botão do aplicativo e clique em **Propriedades**.

## <a name="application-button-properties"></a>Propriedades do botão do aplicativo

A tabela a seguir define as propriedades do botão do aplicativo.

|Propriedade|Definição|
|--------------|----------------|
|**Botões**|Contém a coleção de até três botões que aparecem no canto inferior direito do menu do aplicativo.|
|**Legenda**|Especifica o texto do controle. Ao contrário de outros elementos da faixa de tipos, o botão do aplicativo não exibe o texto da legenda. Em vez disso, o texto é usado para acessibilidade.|
|**Imagem HDPI**|Especifica o identificador do ícone do botão de aplicativo de pontos altos por polegada (HDPI). Quando o aplicativo é executado em um monitor de DPI alto, a **imagem HDPI** é usada em vez de **imagem**.|
|**HDPI imagens grandes**|Especifica o identificador das altas imagens grandes de DPI. Quando o aplicativo é executado em um monitor de DPI alto, **HDPI imagens grandes** são usadas em vez de **imagens grandes**.|
|**HDPI imagens pequenas**|Especifica o identificador das imagens pequenas de DPI alta. Quando o aplicativo é executado em um monitor de DPI alto, **HDPI imagens pequenas** são usadas em vez de **imagens pequenas**.|
|**ID**|Especifica o identificador do controle.|
|**Imagem**|Especifica o identificador do ícone do botão do aplicativo. O ícone é um bitmap 26x26 de 32 bits que tem transparência alfa. As partes transparentes do ícone são realçadas quando o botão do aplicativo é clicado ou focalizado.|
|**Chaves**|Especifica a cadeia de caracteres que é exibida quando a navegação de dica de chave está habilitada. A navegação por dicas de tecla é habilitada quando você pressiona ALT.|
|**Imagens grandes**|Especifica o identificador da imagem que contém uma série de ícones de 32x32. Os ícones são usados pelos botões na coleção itens principais.|
|**Itens principais**|Contém uma coleção de itens de menu que aparecem no menu do aplicativo.|
|**Legenda MRU**|Especifica o texto exibido no painel de lista recente.|
|**Imagens pequenas**|Especifica o identificador da imagem que contém uma série de ícones de 16x16. Os ícones são usados pelos botões na coleção de botões.|
|**Utilizá**|Habilita ou desabilita o painel de lista recente. O painel Lista recente é exibido no menu do aplicativo.|
|**Largura**|Especifica a largura em pixels do painel de lista recente.|

O menu do aplicativo não aparece na superfície de design. Para exibi-lo, você deve Visualizar a faixa de opções ou executar o aplicativo.

#### <a name="to-preview-the-ribbon-control"></a>Para visualizar o controle da faixa de faixas

- Na **barra de ferramentas do editor da faixa de faixas**, clique em **testar faixa**de medida.

## <a name="see-also"></a>Consulte também

[Designer de faixa de Ribbon (MFC)](ribbon-designer-mfc.md)
