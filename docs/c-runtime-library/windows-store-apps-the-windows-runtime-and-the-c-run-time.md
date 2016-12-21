---
title: "Windows Store Apps, the Windows Runtime, and the C Run-Time | Microsoft Docs"
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
ms.assetid: 356d6d8d-76ee-4181-9ad0-6f24b2fede38
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Windows Store Apps, the Windows Runtime, and the C Run-Time
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] os aplicativos são programas que são executados no [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] que é executado em [!INCLUDE[win8](../build/includes/win8_md.md)].  O [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] é um ambiente confiável que controla as funções, variáveis e recursos que estão disponíveis para um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo.  No entanto, por design, [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] restrições impedir o uso da maioria dos recursos de biblioteca de tempo de execução do C \(CRT\) do [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos.  
  
 O [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] não suporta os seguintes recursos de CRT:  
  
-   A maioria das funções de CRT relacionados à funcionalidade sem suporte.  
  
     Por exemplo, um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo não pode criar um processo usando o `exec` e `spawn` famílias de rotinas.  
  
     Quando uma função de CRT não é suportada em um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] app, que o fato é indicado em seu artigo de referência.  
  
-   Funções de caractere e de seqüência de caracteres multibyte mais.  
  
     No entanto, há suporte para texto ANSI e Unicode.  
  
-   Os aplicativos de console e os argumentos de linha de comando.  
  
     No entanto, aplicativos de desktop tradicionais ainda oferece suporte a console e os argumentos de linha de comando.  
  
-   Variáveis de ambiente.  
  
-   O conceito de um diretório de trabalho atual.  
  
-   [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos e DLLs estaticamente vinculadas a CRT e criados usando o [\/MT](../build/reference/md-mt-ld-use-run-time-library.md) ou `/MTd` Opções do compilador.  
  
     Ou seja, um aplicativo que usa uma versão estática multithread do CRT.  
  
-   Um aplicativo criado usando o [\/MDd](../build/reference/md-mt-ld-use-run-time-library.md) opção de compilador.  
  
     Ou seja, uma depuração multithread e versão específica de DLL do CRT.  Um aplicativo não é compatível com o [!INCLUDE[win8_appstore_long](../build/reference/includes/win8_appstore_long_md.md)].  
  
 Para obter uma lista completa das funções de CRT que não estão disponíveis em um [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativo e sugestões para funções alternativas, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)   
 [Funções CRT não suportadas de Tempo de Execução do Windows](../Topic/Windows%20Runtime%20Unsupported%20CRT%20Functions.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)