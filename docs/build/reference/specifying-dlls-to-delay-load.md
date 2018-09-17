---
title: Especificando DLLs para carregamento com atraso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- DELAYLOAD linker option
- delayed loading of DLLs
- delayed loading of DLLs, specifying
- /DELAYLOAD linker option
ms.assetid: 94cbecfe-7a42-40d1-a618-9f2786bac0d8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1e9becc0a686d3add5db140b239f1997f81a45be
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722573"
---
# <a name="specifying-dlls-to-delay-load"></a>Especificando DLLs para carga com atraso

Você pode especificar quais DLLs para atrasar a carga com o [/delayload](../../build/reference/delayload-delay-load-import.md):`dllname` a opção de vinculador. Se você não planeja usar sua própria versão de uma função auxiliar, você também deve vincular o programa com delayimp (para aplicativos da área de trabalho) ou dloadhelper.lib (para aplicativos da store).

Este é um exemplo simples de uma DLL de carregamento com atraso:

```
// cl t.cpp user32.lib delayimp.lib  /link /DELAYLOAD:user32.dll
#include <windows.h>
// uncomment these lines to remove .libs from command line
// #pragma comment(lib, "delayimp")
// #pragma comment(lib, "user32")

int main() {
   // user32.dll will load at this point
   MessageBox(NULL, "Hello", "Hello", MB_OK);
}
```

Compile a versão de depuração do projeto. Percorra o código usando o depurador e você observará que User32. dll é carregada somente quando você fizer a chamada para `MessageBox`.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)