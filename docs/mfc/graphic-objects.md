---
title: "Objetos gr&#225;ficos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "HRGN"
  - "HFONT"
  - "HBITMAP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bitmaps [C++], criando em contextos de dispositivo"
  - "pincéis, criando em contexto de dispositivo"
  - "Classe CBitmap, Tipo de identificador HBITMAP"
  - "Classe CBrush, Tipo de identificador HBRUSH"
  - "Classe CFont, Tipo de identificador HFONT"
  - "Classe CPalette, Tipo de identificador HPALETTE"
  - "Classe CPen, Tipo de identificador HPEN"
  - "Classe CRgn, Tipo de identificador HRGN"
  - "contextos de dispositivo, objetos gráficos"
  - "desenho, em contextos de dispositivo"
  - "fontes [C++], criando em contexto de dispositivo"
  - "GDI [C++], classes de objetos gráficos"
  - "Objetos GDI [C++]"
  - "Objetos GDI [C++], classes de objetos gráficos"
  - "objetos gráficos"
  - "objetos gráficos, criando em contexto de dispositivo"
  - "HBITMAP e classe CBitmap"
  - "HBRUSH e classe CBrush"
  - "HFONT e classe CFont"
  - "HPALETTE e classe CPalette"
  - "HPEN"
  - "HRGN"
  - "imagens [C++], objetos gráficos"
  - "memória [C++], contextos de exibição"
  - "MFC, objetos gráficos"
  - "objetos [C++], gráfico"
  - "objetos [C++], objetos gráficos"
  - "pintura e contexto de dispositivo"
  - "objetos de paleta"
  - "paletas, criando em contexto de dispositivo"
  - "objetos de caneta"
  - "canetas, criando em contexto de dispositivo"
  - "objetos de região"
  - "regiões, criando em contexto de dispositivo"
ms.assetid: 41963b25-34b7-4343-8446-34ba516b83ca
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos gr&#225;ficos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Windows fornece uma variedade de ferramentas para usar em contextos de dispositivo de desenho.  Ele fornece as canetas para desenhar linhas, pincéis preenchimento interiores e fontes para desenhar o texto.  MFC fornece classes de objetos gráficos equivalentes para as ferramentas de desenho no Windows.  A tabela a seguir mostra as classes disponíveis e os gráficos do Windows equivalentes tipos de identificador de dispositivo GDI \(interface\).  
  
> [!NOTE]
>  GDI\+ é incluído no Windows XP e está disponível como um redistribuível para Windows NT 4.0 SP6, Windows 2000, Windows 98 e Windows Me.  Para baixar o redistribuível mais recente, consulte  [http:\/\/www.microsoft.com\/msdownload\/platformsdk\/sdkupdate\/psdkredist.htm](http://www.microsoft.com/msdownload/platformsdk/sdkupdate/psdkredist.htm).  Para obter mais informações, consulte a documentação de GDI\+ SDK no MSDN: [http:\/\/msdn.microsoft.com\/library\/default.asp?url\=\/library\/gdicpp\/GDIPlus\/GDIPlus.asp](http://msdn.microsoft.com/library/default.asp?url=/library/gdicpp/GDIPlus/GDIPlus.asp).  
  
 Este artigo explica o uso dessas classes de objeto de gráfico:  
  
### Classes de objetos GDI do Windows  
  
|Classe|Tipo de identificador do Windows|  
|------------|--------------------------------------|  
|[CPen](../Topic/CPen%20Class.md)|`HPEN`|  
|[CBrush](../mfc/reference/cbrush-class.md)|`HBRUSH`|  
|[CFont](../mfc/reference/cfont-class.md)|**HFONT**|  
|[CBitmap](../mfc/reference/cbitmap-class.md)|`HBITMAP`|  
|[CPalette](../mfc/reference/cpalette-class.md)|`HPALETTE`|  
|[CRgn](../mfc/reference/crgn-class.md)|**HRGN**|  
  
> [!NOTE]
>  A classe [CImage](../atl-mfc-shared/reference/cimage-class.md) fornece suporte de bitmap aprimorada.  
  
 Cada classe de objeto de gráfico na biblioteca de classes tem um construtor que permite que você crie objetos gráficos dessa classe, que você, em seguida, deverá inicializar com a função create apropriado, como `CreatePen`.  
  
 Cada classe de objeto de gráfico na biblioteca de classes tem um operador de conversão que irá converter um objeto do MFC para o identificador de janela associado.  O identificador resultante é válido até que o objeto associado desconecta\-lo.  Use o objeto **Desanexar** a função de membro para desanexar o identificador.  
  
 O código a seguir conversões uma `CPen` objeto para um identificador de janela:  
  
 [!code-cpp[NVC_MFCDocViewSDI#5](../mfc/codesnippet/CPP/graphic-objects_1.cpp)]  
  
#### Para criar um objeto gráfico em um contexto de dispositivo  
  
1.  Defina um objeto gráfico no quadro de pilhas.  Inicializar o objeto com a função de criação de tipo específico, como `CreatePen`.  Como alternativa, inicialize o objeto no construtor.  Consulte a discussão sobre [criação de um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md), que fornece código de exemplo.  
  
2.  [Selecione o objeto no contexto de dispositivo atual](../mfc/selecting-a-graphic-object-into-a-device-context.md), salvando o objeto gráfico antigo que foi selecionado antes.  
  
3.  Quando terminar com o objeto gráfico atual, selecione o objeto gráfico antigo volta para o contexto de dispositivo para restaurar seu estado.  
  
4.  Permitir que o objeto gráfico alocado moldura sejam excluídos automaticamente quando o escopo é fechado.  
  
> [!NOTE]
>  Se você usará um objeto gráfico repetidamente, você pode alocá\-la uma vez e selecioná\-lo em um contexto de dispositivo sempre que for necessário.  Certifique\-se de excluir esse tipo de objeto quando você não precisa mais dela.  
  
### Que mais você deseja saber?  
  
-   [Construção de objetos gráficos em um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md)  
  
-   [Exemplo de construção de uma caneta em um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md)  
  
-   [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)  
  
-   [Contextos de dispositivo](../Topic/Device%20Contexts.md)  
  
-   [Limitações de CImage com sistemas operacionais anteriores](../mfc/cimage-limitations-with-earlier-operating-systems.md)  
  
## Consulte também  
 [Objetos de janela](../mfc/window-objects.md)