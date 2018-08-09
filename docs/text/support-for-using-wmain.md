---
title: Suporte para usar wmain | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- wWinMain
dev_langs:
- C++
helpviewer_keywords:
- wide characters [C++], wmain function
- wWinMain function
- wmain function
ms.assetid: 41213c41-668c-40a4-8a1e-77d9eded720d
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 390f2a11b98a851b5f33b4e0a941a515421d5836
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011611"
---
# <a name="support-for-using-wmain"></a>Suporte para usar wmain
Visual C++ dá suporte para definir um **wmain** função e passar argumentos de caractere largo para seu aplicativo de Unicode. Declarar parâmetros formais para **wmain**, usando um formato semelhante ao `main`. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`. Por exemplo:  
  
```  
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )  
```  
  
> [!NOTE]
>  Usam aplicativos Unicode MFC `wWinMain` como ponto de entrada. Nesse caso, `CWinApp::m_lpCmdLine` é uma cadeia de caracteres Unicode. Certifique-se de definir `wWinMainCRTStartup` com o [/ENTRY](../build/reference/entry-entry-point-symbol.md) a opção de vinculador.  
  
 Se seu programa usa uma `main` função, o ambiente de caractere multibyte é criado pela biblioteca de tempo de execução na inicialização do programa. Uma cópia de caractere amplo do ambiente é criada apenas quando necessário (por exemplo, por uma chamada para as funções `_wgetenv` ou `_wputenv`). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente de cadeia de caracteres largos correspondente é criado. Em seguida, o ambiente é apontado pelo `_wenviron` variável global, que é uma versão de caractere largo do `_environ` variável global. Neste ponto, duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente e são mantidas pelo sistema de tempo de execução durante a vida útil do programa.  
  
 Da mesma forma, se seu programa usar uma função **wmain**, um ambiente de caractere amplo será criado na inicialização do programa e apontado pela variável global `_wenviron`. Um ambiente de MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv` e é indicada pela `_environ` variável global.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para Unicode](../text/support-for-unicode.md)   
 [Resumo de programação Unicode](../text/unicode-programming-summary.md)   
 [Função WinMain](http://msdn.microsoft.com/library/windows/desktop/ms633559)