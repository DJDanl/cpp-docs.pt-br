---
title: Suporte para usar wmain
ms.date: 11/04/2016
f1_keywords:
- wWinMain
helpviewer_keywords:
- wide characters [C++], wmain function
- wWinMain function
- wmain function
ms.assetid: 41213c41-668c-40a4-8a1e-77d9eded720d
ms.openlocfilehash: 4af389c00f6065df631f891dadcb0b2f350f984d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491193"
---
# <a name="support-for-using-wmain"></a>Suporte para usar wmain

O C++ Visual dá suporte à definição de uma função **wmain** e à passagem de argumentos de caracteres largos para seu aplicativo Unicode. Declare parâmetros formais para **wmain**, usando um formato semelhante a `main`. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`. Por exemplo:

```cpp
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )
```

> [!NOTE]
> Os aplicativos do MFC `wWinMain` Unicode usam como o ponto de entrada. Nesse caso, `CWinApp::m_lpCmdLine` é uma cadeia de caracteres Unicode. Certifique-se de `wWinMainCRTStartup` definir com a opção de vinculador [/entry](../build/reference/entry-entry-point-symbol.md) .

Se seu programa usa uma função **main**, o ambiente de caractere multibyte é criado pela biblioteca em tempo de execução na inicialização do programa. Uma cópia de caractere amplo do ambiente é criada apenas quando necessário (por exemplo, por uma chamada para as funções `_wgetenv` ou `_wputenv`). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente de cadeia de caracteres largo correspondente será criado. Em seguida, o ambiente é apontado `_wenviron` pela variável global, que é uma versão `_environ` de caractere largo da variável global. Neste ponto, duas cópias do ambiente (MBCS e Unicode) existem simultaneamente e são mantidas pelo sistema de tempo de execução durante toda a vida útil do programa.

Da mesma forma, se seu programa usar uma função **wmain**, um ambiente de caractere amplo será criado na inicialização do programa e apontado pela variável global `_wenviron`. Um ambiente MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv` e `_environ` é apontado pela variável global.

## <a name="see-also"></a>Consulte também

[Suporte para Unicode](../text/support-for-unicode.md)<br/>
[Resumo de programação Unicode](../text/unicode-programming-summary.md)<br/>
[Função WinMain](/windows/win32/api/winbase/nf-winbase-winmain)
