---
title: "Aplicativos universais do Windows (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Aplicativos universais do Windows (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Aplicativos universal Windows Platform \(UWP\) incorporam um conjunto de princípios de design que enfatizam interfaces do usuário simples que são centralizadas em torno do conteúdo que se ajusta automaticamente para diferentes tamanhos de tela em dispositivos diferentes. Você pode criar a interface do usuário na marcação XAML e o code\-behind em C\+\+ nativo. Você também pode criar componentes \(DLLs\) que podem ser consumidos por aplicativos UWP que são escritos em outras linguagens. A superfície de API para aplicativos UWP é o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)], que é uma biblioteca bem fatorada que fornece uma ampla variedade de serviços do sistema operacional.  
  
> [!NOTE]
>  Grande parte da documentação do desenvolvimento de aplicativos UWP em C\+\+ está no [Windows Developer Center](http://go.microsoft.com/fwlink/p/?LinkId=255563) site. Alguns dos links neste artigo ir para esse site.  
  
## Aplicativos UWP que usam o C \+ \+ \/ CX  
  
|||  
|-|-|  
|[Referência de linguagem do Visual C\+\+ \(C \+ \+ \/ CX\)](http://go.microsoft.com/fwlink/p/?LinkId=255561)|Descreve o conjunto de extensões que simplificam o consumo de C\+\+ de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] APIs e habilitar tratamento de erro que é baseado em exceções.|  
|[Compilando aplicativos e bibliotecas \(C\+\+\/CX\)](http://go.microsoft.com/fwlink/p/?LinkId=264858)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas de C \+ \+ \/ CX aplicativo ou componente.|  
|[Tutorial: Criar seu primeiro aplicativo da Windows Store usando C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=255556)|Um passo a passo que apresenta os conceitos básicos de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] desenvolvimento de aplicativos em C\+\+. \(Ainda não foi atualizado para o desenvolvimento de UWP no Windows 10.\)|  
|[Roteiro para aplicativos da Windows Store usando C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=255553)|Fornece links para artigos sobre [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] desenvolvimento de aplicativo e o jogo em C\+\+.|  
|[Criando componentes do Tempo de Execução do Windows em C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=255559)|Descreve como criar DLLs que outros [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos e componentes podem consumir.|  
|[Desenvolvimento de jogos](http://go.microsoft.com/fwlink/p/?LinkId=255554)|Descreve como usar DirectX e C\+\+ para criar jogos.|  
  
## [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] Aplicativos que usam o [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\)  
 O [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] fornece as interfaces COM nível baixo por quais ISO C\+\+ código pode acessar o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] em um ambiente livre de exceção. Na maioria dos casos, é recomendável que você use C \+ \+ \/ CX em vez do [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] desenvolvimento de aplicativos. Para obter informações sobre o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)], consulte [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md).  
  
## Consulte também  
 [Visual C\+\+](../top/visual-cpp-in-visual-studio-2015.md)