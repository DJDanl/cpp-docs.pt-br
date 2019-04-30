---
title: Compilador aviso (nível 4) C4233
ms.date: 10/25/2017
f1_keywords:
- C4233
helpviewer_keywords:
- C4233
ms.assetid: 9aa51fc6-8ef3-43b5-bafb-c9333cf60de3
ms.openlocfilehash: 361e00b7361aab51ea077d7e248503f3654e5e58
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401053"
---
# <a name="compiler-warning-level-4-c4233"></a>Compilador aviso (nível 4) C4233

> extensão não padrão usada: '*palavra-chave*' palavra-chave só tem suportada em C++, não em C

O compilador compilou seu código-fonte como C em vez de C++, e você usou uma palavra-chave só é válida em C++. O compilador compila seu arquivo de origem como C se a extensão do arquivo de origem. c ou usar [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md).

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para transformar C4233 em um problema de aviso de nível 4, adicione esta linha ao seu arquivo de código de origem:

```cpp
#pragma warning(4:4233)
```
