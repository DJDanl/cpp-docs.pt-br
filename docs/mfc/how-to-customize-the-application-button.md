---
title: "Como personalizar o bot&#227;o do aplicativo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "botão de aplicativo, personalizando"
ms.assetid: ebb11180-ab20-43df-a234-801feca9eb38
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como personalizar o bot&#227;o do aplicativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você clica no botão de aplicativo, um menu de comandos será exibido.  Normalmente, o menu contém comandos relacionadas como **Abrir**, **Salvar**, **Imprimir**, e **Sair**.  
  
 ![Botão de aplicativo de faixa de opções do MFC](../mfc/media/application_button.png "Application\_Button")  
  
 Para personalizar o botão do aplicativo, abra\-o na janela de **Propriedades** , modifique\-o suas propriedades, e visualizá\-lo no controle de fita.  
  
### Para abrir o aplicativo botão na janela Propriedades  
  
1.  No Visual Studio, no menu de **Exibir** , clique em **Modo de Exibição de Recurso**.  
  
2.  Em **Modo de Exibição de Recurso**, clique duas vezes no recurso de fita para exibi\-lo na superfície de design.  
  
3.  Na superfície de design, clique com o botão direito do mouse no menu do botão do aplicativo e clique em **Propriedades**.  
  
## Propriedades do botão de aplicativo  
 A tabela a seguir define as propriedades do botão do aplicativo.  
  
|Propriedade|Definição|  
|-----------------|---------------|  
|**Botões**|Contém a coleção de até três botões que aparecem no canto inferior direito no menu do aplicativo.|  
|**Legenda**|Especifica o texto do controle.  Ao contrário de outros elementos da faixa de opções, no botão de aplicativo não exibe o texto da legenda.  Em vez disso, o texto será usado para facilitar o uso.|  
|**Imagem de HDPI**|Especifica o identificador de pontos altos o ícone do botão de aplicativo \(HDPI\) de centímetro.  Quando o aplicativo executa em um monitor alto de DPI, **Imagem HDPI** será usado em vez de **Imagem**.|  
|**Grandes imagens de HDPI**|Especifica o identificador de grandes imagens de alta DPI.  Quando o aplicativo executa em um monitor alto de DPI, **Imagens Grandes HDPI** será usado em vez de **Imagens Grandes**.|  
|**Pequenas imagens de HDPI**|Especifica o identificador das pequenas imagens de alta DPI.  Quando o aplicativo executa em um monitor alto de DPI, **Imagens Pequenas HDPI** será usado em vez de **Imagens Pequenas**.|  
|**ID**|Especifica o identificador do controle.|  
|**Image**|Especifica o identificador do ícone do botão do aplicativo.  O ícone é um bitmap 26x26 de 32 bits que tem a transparência alfa.  As partes do ícone transparentes são realçadas quando o botão de aplicativo é clicado ou focalizado em.|  
|**Chaves**|Especifica a cadeia de caracteres que será exibida quando a navegação de chave dica é habilitada.  a navegação de chave dica é habilitada quando você pressiona ALT.|  
|**Imagens grandes**|Especifica o identificador da imagem que contém uma série de ícones 32x32.  Os ícones são usados pelos botões na coleção principal dos itens.|  
|**Itens principais**|Contém uma coleção de itens de menu que aparecem no menu do aplicativo.|  
|**Legenda de MRU**|Especifica o texto exibido no painel recente da lista.|  
|**Pequenas imagens**|Especifica o identificador da imagem que contém uma série de ícones 16x16.  Os ícones são usados pelos botões na coleção dos botões.|  
|**Uso**|Habilita ou desabilita o painel recente da lista.  O painel recente da lista aparece no menu do aplicativo.|  
|**Width**|Especifica a largura em pixels do painel recente da lista.|  
  
 O menu do aplicativo não aparece na superfície de design.  Para exibi\-lo, visualize a fita ou executar o aplicativo.  
  
#### Para visualizar o controle de fita  
  
-   Em **Barra de ferramentas do editor da Faixa De Opções**, clique em **Faixa de Opções de Teste**.  
  
## Consulte também  
 [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md)