---
title: Especificando DLLs para carga com atraso
ms.date: 11/04/2016
helpviewer_keywords:
- DELAYLOAD linker option
- delayed loading of DLLs
- delayed loading of DLLs, specifying
- /DELAYLOAD linker option
ms.assetid: 94cbecfe-7a42-40d1-a618-9f2786bac0d8
ms.openlocfilehash: 2b6737abd76c03186881e83bbd2bf286be6ffe2f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57813221"
---
# <a name="specifying-dlls-to-delay-load"></a>Especificando DLLs para carga com atraso

Você pode especificar quais DLLs para atrasar a carga com o [/delayload](delayload-delay-load-import.md):`dllname` a opção de vinculador. Se você não planeja usar sua própria versão de uma função auxiliar, você também deve vincular o programa com delayimp (para aplicativos da área de trabalho) ou dloadhelper.lib (para aplicativos da store).

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

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
