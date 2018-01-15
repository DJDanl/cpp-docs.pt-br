---
title: "Como: personalizar o botão do aplicativo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: application button [MFC], customizing
ms.assetid: ebb11180-ab20-43df-a234-801feca9eb38
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4a4a150985bd5c552b361620df87e34511ef8027
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-customize-the-application-button"></a>Como personalizar o botão do aplicativo
Quando você clica no botão de aplicativo, é exibido um menu de comandos. Normalmente, o menu contém comandos relacionados ao arquivo como **abrir**, **salvar**, **impressão**, e **saída**.  
  
 ![Botão de aplicativo de faixa de opções do MFC](../mfc/media/application_button.png "application_button")  
  
 Para personalizar o botão do aplicativo, abri-lo no **propriedades** janela, modifique suas propriedades e, em seguida, o controle de faixa de opções de visualização.  
  
### <a name="to-open-the-application-button-in-the-properties-window"></a>Para abrir o botão do aplicativo na janela Propriedades  
  
1.  No Visual Studio, no **exibição** menu, clique em **exibição recursos**.  
  
2.  Em **exibição recursos**, clique duas vezes o recurso de faixa de opções para exibi-lo na superfície de design.  
  
3.  Na superfície de design, clique no menu do botão de aplicativo e, em seguida, clique em **propriedades**.  
  
## <a name="application-button-properties"></a>Propriedades de botão do aplicativo  
 A tabela a seguir define as propriedades do botão de aplicativo.  
  
|Propriedade|Definição|  
|--------------|----------------|  
|**Botões**|Contém a coleção de até três botões que aparecem no canto inferior direito do menu do aplicativo.|  
|**Legenda**|Especifica o texto do controle. Diferentemente de outros elementos de faixa de opções, o botão do aplicativo não exibe o texto da legenda. Em vez disso, o texto é usado para acessibilidade.|  
|**Imagem HDPI**|Especifica o identificador da alta pontos por polegada ícone do botão de aplicativo (HDPI). Quando o aplicativo é executado em um monitor DPI alto, **imagem HDPI** é usado em vez de **imagem**.|  
|**Imagens grandes HDPI**|Especifica o identificador de imagens grandes DPI alto. Quando o aplicativo é executado em um monitor DPI alto, **imagens grandes HDPI** é usado em vez de **imagens grandes**.|  
|**Imagens pequenas HDPI**|Especifica o identificador de imagens pequenas DPI alto. Quando o aplicativo é executado em um monitor DPI alto, **imagens pequenas HDPI** é usado em vez de **imagens pequenas**.|  
|**ID**|Especifica o identificador do controle.|  
|**Image**|Especifica o identificador do ícone do botão do aplicativo. O ícone é um bitmap de 26 x 26 de 32 bits com transparência alfa. As partes transparentes do ícone são realçadas quando o botão do aplicativo é clicado ou colocado em cima.|  
|**Chaves**|Especifica a cadeia de caracteres que é exibida quando a navegação de dica de chave está habilitada. Navegação de dica de chave é habilitada quando você pressionar a tecla ALT.|  
|**Imagens grandes**|Especifica o identificador da imagem que contém uma série de ícones de 32 x 32. Os ícones são usados por botões na coleção de itens do principal.|  
|**Itens principais**|Contém uma coleção de itens de menu que aparecem no menu do aplicativo.|  
|**Legenda MRU**|Especifica o texto exibido no painel de lista recente.|  
|**Imagens pequenas**|Especifica o identificador da imagem que contém uma série de ícones de 16 x 16. Os ícones são usados por botões na coleção de botões.|  
|**Use**|Habilita ou desabilita o painel de lista recente. O painel de lista recente aparece no menu do aplicativo.|  
|**Largura**|Especifica a largura em pixels do painel lista recente.|  
  
 O menu de aplicativo não for exibido na superfície de design. Para exibi-lo, você deve visualizar a faixa de opções ou executar o aplicativo.  
  
#### <a name="to-preview-the-ribbon-control"></a>Para visualizar o controle de faixa de opções  
  
-   Sobre o **barra de ferramentas do Editor de faixa de opções**, clique em **faixa de opções de teste**.  
  
## <a name="see-also"></a>Consulte também  
 [Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

