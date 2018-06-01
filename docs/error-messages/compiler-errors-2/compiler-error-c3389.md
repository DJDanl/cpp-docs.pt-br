---
title: C3389 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3389
dev_langs:
- C++
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b540f87458c75ddf7d57626b6251248652b96213
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704292"
---
# <a name="compiler-error-c3389"></a>C3389 de erro do compilador

> declspec (*palavra-chave*) não pode ser usado com /clr: pure ou /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Um [declspec](../../cpp/declspec.md) modificador usado implica um por estado de processo.  [/CLR: pure](../../build/reference/clr-common-language-runtime-compilation.md) implica um por [appdomain](../../cpp/appdomain.md) estado.  Assim, declarando uma variável com o `keyword` **declspec** modificador e compilar com **/clr: pure** não é permitido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3389:

```cpp
// C3389.cpp
// compile with: /clr:pure /c
__declspec(dllexport) int g2 = 0;   // C3389
```