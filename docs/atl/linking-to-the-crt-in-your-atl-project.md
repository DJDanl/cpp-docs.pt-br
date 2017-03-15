---
title: "Vincular ao CRT em seu projeto de ATL | Microsoft Docs"
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
  - "DllMainCRTStartup"
  - "wWinMainCRTStartup"
  - "WinMainCRTStartup"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, Biblioteca em tempo de execução de C (CRT)"
  - "CRT, vincular com ATL"
  - "Método de DllMainCRTStartup"
  - "Método de WinMainCRTStartup"
  - "método de wWinMainCRTStartup"
ms.assetid: 650957ae-362c-4ecf-8b03-5d49138e8b5b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vincular ao CRT em seu projeto de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[Bibliotecas em tempo de execução de C](../c-runtime-library/crt-library-features.md) \(CRT\) fornece muitas funções úteis que podem tornar a programação de muito mais fácil durante o desenvolvimento de ATL.  Todos os projetos de ATL links para a biblioteca de CRT.  Você pode ver as vantagens e desvantagens de vincular o método em [Benefícios e troca do método usado para vincular ao CRT](../atl/benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt.md).  
  
## Efeitos de vincular ao CRT na imagem do programa  
 Se você vincula estaticamente ao CRT, o código de CRT é colocado na imagem executável e você não precisa ter o DLL do CRT atual em um sistema para executar a imagem.  Se você vincula dinamicamente ao CRT, as referências ao código no DLL de CRT são colocadas em sua imagem, mas não no próprio código.  Para que a imagem em execução em um determinado sistema, o deve DLL de CRT está presente no sistema.  Mesmo quando você vincula dinamicamente ao CRT, você pode localizar qualquer código que estaticamente pode ser associado \(por exemplo, **DllMainCRTStartup**\).  
  
 Quando você vincula a imagem, você especifica explícita ou implicitamente um ponto de entrada que o sistema operacional chama após em carregar a imagem.  Para uma DLL, o ponto de entrada padrão é **DllMainCRTStartup**.  Para EXE, é **WinMainCRTStartup**.  Você pode substituir a opção com a opção de vinculador de \/ENTRY.  O CRT fornece uma implementação para **DllMainCRTStartup**, **WinMainCRTStartup**, e **wWinMainCRTStartup** \(o ponto de entrada para Unicode EXE\).  Esses construtores fornecidos CRT\- da chamada de pontos de entrada em objetos globais e inicializam outras estruturas de dados que são usadas por algumas funções de CRT.  Esse código de inicialização adiciona sobre 25K à imagem se é estaticamente associado.  Se é associado dinamicamente, a maior parte do código está no DLL, o que seu tamanho da imagem pequena fica.  
  
 Para obter mais informações, consulte o tópico [\/ENTRY \(Símbolo de Ponto de entrada\)](../build/reference/entry-entry-point-symbol.md)de vinculador.  
  
## Opções de otimização  
 Usando a opção \/OPT do vinculador: NOWIN98 mais pode reduzir um controle de ATL 10K por padrão, custas de tempo de carregamento gerados em sistemas Windows 98.  Para obter mais informações sobre vincular opções, consulte [\/OPT \(Otimizações\)](../build/reference/opt-optimizations.md).  
  
## Consulte também  
 [Programando com código de tempo de execução ATL e C](../atl/programming-with-atl-and-c-run-time-code.md)   
 [Comportamento da biblioteca em tempo de execução](../build/run-time-library-behavior.md)