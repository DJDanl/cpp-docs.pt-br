---
title: "Quais t&#233;cnicas de otimiza&#231;&#227;o devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento? | Microsoft Docs"
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
  - "DLLs [C++], otimizando"
  - "otimização [C++], DLLs"
  - "desempenho [C++], DLLs"
ms.assetid: 2f8bbfb5-08b9-4a35-8302-25a1966881b1
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Quais t&#233;cnicas de otimiza&#231;&#227;o devo usar para melhorar o desempenho do aplicativo cliente durante o carregamento?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o DLL é uma DLL normal que está vinculado ao estaticamente MFC, altere\-o para uma DLL normal vinculada dinamicamente ao MFC reduz o tamanho do arquivo.  
  
 Se a DLL tiver um número grande de funções exportadas, use um arquivo .def para exportar as funções \(em vez de usar **\_\_declspec\(dllexport\)**\) e para usar o arquivo .def de [Atributo de NONAME](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) em cada função exportada.  As causas do atributo de NONAME apenas o valor ordinal e não o nome da função ser armazenado na tabela de exportação da DLL, o que reduz o tamanho do arquivo.  
  
 Dlls que são vinculados implicitamente em um aplicativo são carregados quando o aplicativo carrega.  Para melhorar o desempenho ao carregar, tente dividir a DLL na DLL diferentes.  Colocar todas as funções que o aplicativo chamador precisa imediatamente depois da carga em uma DLL e tem o aplicativo de chamada implicitamente vincular a que o DLL.  Coloque as outras funções que o aplicativo de chamada não precisa imediatamente em outro DLL e tiver link do aplicativo explicitamente a que o DLL.  Para obter mais informações, consulte [Determinar qual método usar vinculando](../build/determining-which-linking-method-to-use.md).  
  
## Consulte também  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)