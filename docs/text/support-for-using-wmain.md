---
title: "Suporte para usar wmain | Microsoft Docs"
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
  - "wWinMain"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caracteres largos [C++], função wmain"
  - "função wmain"
  - "Função wWinMain"
ms.assetid: 41213c41-668c-40a4-8a1e-77d9eded720d
caps.latest.revision: 9
caps.handback.revision: 9
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Suporte para usar wmain
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Suporte do Visual C\+\+ que definem uma função de **wmain** e que passam argumentos de ampla caractere no seu aplicativo Unicode.  Você declara parâmetros formais a **wmain**, usando um formato semelhante a **main**.  Você pode então a argumentos ampla de caracteres e, opcionalmente, um ponteiro de ambiente ampla de caracteres ao programa.  Os parâmetros de `argv` e de `envp` a **wmain** são do tipo `wchar_t*`.  Por exemplo:  
  
```  
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )  
```  
  
> [!NOTE]
>  Os aplicativos MFC Unicode usam **wWinMain** como o ponto de entrada.  Nesse caso, `CWinApp::m_lpCmdLine` é uma cadeia de caracteres Unicode.  Defina **wWinMainCRTStartup** com a opção do vinculador de [\/ENTRY](../build/reference/entry-entry-point-symbol.md) .  
  
 Se seu programa usa uma função de **main** , o ambiente de multibyte\- caractere é criado pela biblioteca de tempo de execução na inicialização do programa.  Uma cópia ampla de caracteres de ambiente é criada apenas quando necessário \(por exemplo, por uma chamada às funções de `_wgetenv` ou de `_wputenv` \).  Na primeira chamada a `_wputenv`, ou na primeira chamada a `_wgetenv` se um ambiente de MBCS já existir, um ambiente correspondente da cadeia de caracteres de ampla caractere é criado.  No ambiente é apontado pela variável global de `_wenviron` , que é uma versão ampla de caracteres da variável global de `_environ` .  Neste momento, duas cópias de ambiente \(MBCS e Unicode\) existem simultaneamente e são mantidas pelo sistema de tempo de execução ao longo de vida do programa.  
  
 Da mesma forma, se seu programa usa uma função de **wmain** , um ambiente de ampla caractere é criado na inicialização do programa e apontado pela variável global de `_wenviron` .  Um ambiente de MBCS ASCII \(\) é criado na primeira chamada a `_putenv` ou a `getenv` e apontado pela variável global de `_environ` .  
  
## Consulte também  
 [Suporte para Unicode](../text/support-for-unicode.md)   
 [Resumo de programação Unicode](../text/unicode-programming-summary.md)   
 [Função de WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559)