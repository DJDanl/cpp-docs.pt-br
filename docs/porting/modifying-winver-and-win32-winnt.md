---
title: "Modificando WINVER e _WIN32_WINNT | Microsoft Docs"
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
helpviewer_keywords: 
  - "_WIN32_WINNT em um projeto Visual C++ atualizado"
  - "WINVER em um projeto Visual C++ atualizado"
ms.assetid: 6a1f1d66-ae0e-48a7-81c3-524d8e8f3447
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modificando WINVER e _WIN32_WINNT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ não oferece mais suporte para Windows 95, Windows 98, Windows ME, Windows NT ou Windows 2000. Se seu **WINVER** ou **\_WIN32\_WINNT** macros são atribuídas a uma dessas versões do Windows, você deve modificar as macros. Quando você atualiza um projeto que foi criado usando uma versão anterior do Visual C\+\+, você pode ver erros de compilação relacionados para o **WINVER** ou **\_WIN32\_WINNT** macros se eles forem atribuídos a uma versão do Windows que não é mais suportado.  
  
## Comentários  
 Para modificar as macros, em um arquivo de cabeçalho \(por exemplo, targetver.h que está incluído quando você cria um projeto que tem como alvo Windows\), adicione as seguintes linhas.  
  
```  
#define WINVER 0x0A00 #define _WIN32_WINNT 0x0A00  
```  
  
 Destina\-se o sistema operacional Windows 10. Esses valores são listados no arquivo de cabeçalho do Windows SDKDDKVer.h, que também define as macros para cada versão do Windows. Você deve adicionar o \#define a instrução antes de incluir SDKDDKVer.h. Aqui estão as linhas da versão do Windows 10 do SDKDDKVer.h que codificar os valores para cada versão do Windows:  
  
```  
// // _WIN32_WINNT version constants // #define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0 #define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000 #define _WIN32_WINNT_WINXP                  0x0501 // Windows XP #define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003 #define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista #define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista #define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008 #define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista #define _WIN32_WINNT_WIN7                   0x0601 // Windows 7 #define _WIN32_WINNT_WIN8                   0x0602 // Windows 8 #define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1 #define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10 #define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10  
```  
  
 Se você não vir que todas essas versões do Windows listadas em uma cópia do SDKDDKVer.h que você está olhando, você provavelmente está usando uma versão mais antiga do SDK do Windows. Por padrão, projetos de Win32 em [!INCLUDE[vs_dev14](../mfc/includes/vs_dev14_md.md)] usar o SDK do Windows 8.1. Para usar o SDK do Windows 10, consulte [Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md).  
  
> [!NOTE]
>  Valores não são garantia de funcionar se você incluir cabeçalhos MFC internos em seu aplicativo.  
  
 Você também pode definir essa macro usando o **\/D** opção de compilador. Para obter mais informações, consulte [\/D \(definições de pré\-processador\)](../build/reference/d-preprocessor-definitions.md).  
  
 Para obter mais informações sobre os significados dessas macros, consulte [usando os cabeçalhos do Windows](http://msdn.microsoft.com/library/windows/desktop/aa383745).  
  
## Consulte também  
 [Alterações anteriores do produto](http://msdn.microsoft.com/pt-br/91fa1713-0778-4b6b-82f7-0fe0a23ab1db)