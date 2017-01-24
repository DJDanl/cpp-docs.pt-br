---
title: "Aplicativos de &#225;rea de trabalho do Windows (Visual C++) | Microsoft Docs"
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
ms.assetid: a020b534-293c-44e2-aa48-516c43ddeb8f
caps.latest.revision: 17
caps.handback.revision: 12
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Aplicativos de &#225;rea de trabalho do Windows (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar um aplicativo de área de trabalho do Windows quando você deseja fazer um aplicativo de desktop nativo que tenha uma interface de usuário baseada na janela e poderão ser executados nas versões do Windows do Windows XP para Windows 10 na área de trabalho do Windows.  
  
 Um *aplicativo de desktop do Windows* \(às vezes chamado no aplicativo de literatura Win32 anterior\) é o termo convencional para um aplicativo que usa loops de mensagem para lidar com mensagens do Windows diretamente em vez de usar uma estrutura como o Microsoft Foundation Classes \(MFC\), a biblioteca ATL \(Active Template\) ou o .NET Framework. Um aplicativo de área de trabalho do Windows em C\+\+ pode usar classes C Runtime \(CRT\) e o modelo Biblioteca STL \(Standard\) e funções, objetos e qualquer uma das funções públicas do Windows, que são conhecidas coletivamente como a API do Windows. Para obter uma introdução aos aplicativos da área de trabalho do Windows em C\+\+, consulte [aprender para programar para o Windows em C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=262281).  
  
 Um aplicativo de área de trabalho do Windows é uma maneira de criar um aplicativo de desktop nativo para Windows; outra maneira é um aplicativo MFC. O MFC é a opção padrão para aplicativos — especialmente aplicativos de tipo de empresa — que têm muitos controles de interface de usuário ou controles de usuário personalizados. MFC fornece classes auxiliares conveniente para serialização, manipulação de texto, impressão e elementos de interface de usuário moderna, como a faixa de opções. Essas classes não estão disponíveis para um aplicativo de desktop do Windows.  
  
## Artigos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Desenvolvimento do Windows](http://go.microsoft.com/fwlink/p/?LinkId=262282)|Contém informações sobre a API do Windows e COM. \(Algumas APIs do Windows e DLLs de terceiros são implementadas como objetos COM\).|  
|[Hilo: Desenvolvendo aplicativos do C\+\+ para Windows 7](http://go.microsoft.com/fwlink/p/?LinkId=262284)|Descreve como criar um aplicativo de desktop Windows cliente rico que usa a animação do Windows e Direct2D para criar uma interface de usuário baseada em carrossel.|  
|[Aplicativos de console](../Topic/Console%20Applications%20in%20Visual%20C++.md)|Contém informações sobre os aplicativos de console. Um aplicativo de console Win32 \(ou Win64\) tem nenhuma janela própria e sem loop de mensagem. Ele é executado na janela do console e de entrada e saída são tratados por meio da linha de comando.|  
|[Visual C\+\+](../top/visual-cpp-in-visual-studio-2015.md)|Descreve os principais recursos do Visual C\+\+ no Visual Studio e links para o restante da documentação do Visual C\+\+.|  
|[Visual C\+\+ Developer Center](http://go.microsoft.com/fwlink/p/?LinkId=252885) no site do MSDN|Contém tutoriais, postagens em blogs e artigos que são relevantes para aplicativos de área de trabalho do Windows.|  
|[Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)|Contém as etapas para configurar seu projeto para compilar usando o SDK do Windows 10.|