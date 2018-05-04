---
title: Especificando DLLs para carga com atraso | Microsoft Docs
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
ms.openlocfilehash: a7756499ddf24055feb1c540df13fbe8249edf42
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="specifying-dlls-to-delay-load"></a>Especificando DLLs para carga com atraso
Você pode especificar quais DLLs de atraso de carga com o [/delayload](../../build/reference/delayload-delay-load-import.md):`dllname` opção de vinculador. Se você não planeja usar sua própria versão de uma função auxiliar, você também deve vincular seu programa com delayimp.lib (para aplicativos de área de trabalho) ou dloadhelper.lib (para aplicativos da Windows store).  
  
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
  
 Crie a versão de depuração do projeto. Percorrer o código usando o depurador e você observará que User32. dll é carregado apenas quando você fizer a chamada para `MessageBox`.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)