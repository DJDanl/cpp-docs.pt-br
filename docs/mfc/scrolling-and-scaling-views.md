---
title: "Rolando e colocando exibi&#231;&#245;es em escala | Microsoft Docs"
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
  - "manipuladores de mensagens"
  - "lidando com erros, barras de rolagem na classe de exibição"
  - "dimensionando exibições"
  - "barras de rolagem, mensagens"
  - "rolando exibições"
ms.assetid: f98a3421-c336-407e-97ee-dbb2ffd76fbd
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Rolando e colocando exibi&#231;&#245;es em escala
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O oferece suporte às exibições que vá e exibições que são dimensionadas automaticamente ao tamanho da janela do tableau que os exibe.  A classe `CScrollView` oferece suporte aos tipos de exibições.  
  
 Para obter mais informações sobre de rolagem e de escala, consulte a classe [CScrollView](../mfc/reference/cscrollview-class.md)*na referência de MFC*.  Para obter um exemplo de rolagem, consulte [O exemplo rabiscar](../top/visual-cpp-samples.md).  
  
## Que você deseja saber mais?  
  
-   Rolando uma exibição  
  
-   Dimensionando uma exibição  
  
-   [\<caps:sentence id\="tgt8" sentenceid\="f321fcf7c88bc6e3f892ae0fc9b2f0d8" class\="tgtSentence"\>Coordenadas de exibição\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/dd145205)  
  
##  <a name="_core_scrolling_a_view"></a> Rolando uma exibição  
 Vezes o tamanho de um documento é maior que o tamanho sua exibição pode exibir.  Isso pode ocorrer porque os dados de documento aumentam ou o usuário reduz a janela que molda a exibição.  Nesses casos, a exibição deve oferecer suporte à rolagem.  
  
 Qualquer exibição pode tratar mensagens da barra de rolagem em suas funções de membro de `OnHScroll` e de `OnVScroll` .  Você ou pode implementar a manipulação de mensagens da barra de rolagem nessas funções, fazendo com que todo o trabalho você mesmo, ou você pode usar a classe de `CScrollView` para tratar a rolagem para você.  
  
 `CScrollView` faz o seguinte:  
  
-   Gerencia tamanhos da janela e do visor e modos de mapeamento  
  
-   Confirmadas automaticamente em resposta a mensagens da barra de rolagem  
  
 Você pode especificar por quanto para rolar para uma “página” \(quando o usuário clica em um eixo da barra de rolagem\) e uma linha “” \(quando o usuário clica em em uma seta de rolagem\).  Planejar esses valores adequados à natureza da exibição.  Por exemplo, talvez você queira colocar em incrementos de 1 pixels para uma exibição dos gráficos mas em incrementos baseados na linha altura em documentos de texto.  
  
##  <a name="_core_scaling_a_view"></a> Dimensionando uma exibição  
 Quando você deseja que a exibição automaticamente para se ajustar ao tamanho da janela do quadro, você pode usar `CScrollView` para dimensionar em vez de rolagem.  A exibição lógica é alongada ou reduzida para ajustar exatamente à área do cliente da janela.  Uma exibição dimensionada não tem nenhuma barra de rolagem.  
  
## Consulte também  
 [Usando exibições](../mfc/using-views.md)