---
title: Suporte para usar wmain | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: wWinMain
dev_langs: C++
helpviewer_keywords:
- wide characters [C++], wmain function
- wWinMain function
- wmain function
ms.assetid: 41213c41-668c-40a4-8a1e-77d9eded720d
caps.latest.revision: "9"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 721915ca5ebbc75b17771dae0804e94aa360177c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="support-for-using-wmain"></a>Suporte para usar wmain
Visual C++ dá suporte para definir um **wmain** função e passar argumentos de caractere largo para seu aplicativo de Unicode. Declarar parâmetros formais para **wmain**, usando um formato semelhante a **principal**. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`. Por exemplo:  
  
```  
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )  
```  
  
> [!NOTE]
>  Usam aplicativos MFC Unicode **wWinMain** como ponto de entrada. Nesse caso, `CWinApp::m_lpCmdLine` é uma cadeia de caracteres Unicode. Certifique-se de definir **wWinMainCRTStartup** com o [/ENTRY](../build/reference/entry-entry-point-symbol.md) opção de vinculador.  
  
 Se seu programa usa uma função **main**, o ambiente de caractere multibyte é criado pela biblioteca em tempo de execução na inicialização do programa. Uma cópia de caractere amplo do ambiente é criada apenas quando necessário (por exemplo, por uma chamada para as funções `_wgetenv` ou `_wputenv`). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se já existir um ambiente de MBCS, um ambiente de cadeia de caracteres largos correspondente é criado. Em seguida, o ambiente é apontado pelo `_wenviron` variável global, que é uma versão de caractere largo do `_environ` variável global. Neste ponto, duas cópias do ambiente (Unicode e MBCS) existem simultaneamente e são mantidas pelo sistema de tempo de execução durante a vida útil do programa.  
  
 Da mesma forma, se seu programa usar uma função **wmain**, um ambiente de caractere amplo será criado na inicialização do programa e apontado pela variável global `_wenviron`. Um ambiente de MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv` e é apontada pelo `_environ` variável global.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a Unicode](../text/support-for-unicode.md)   
 [Resumo de programação Unicode](../text/unicode-programming-summary.md)   
 [Função WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559)