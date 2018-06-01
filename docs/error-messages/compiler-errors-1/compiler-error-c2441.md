---
title: C2441 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2441
dev_langs:
- C++
helpviewer_keywords:
- C2441
ms.assetid: ffbd6573-777a-48dd-892f-5cf4a758dcab
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6d4224d9090f3ace43f61a10c599fafa78d21600
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705274"
---
# <a name="compiler-error-c2441"></a>C2441 de erro do compilador

> '*variável*': um símbolo declarado com __declspec(process) deve ser const em /clr: pure modo

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Por padrão, as variáveis são por domínio de aplicativo em **/clr: pure**. Marcado como uma variável `__declspec(process)` em **/clr: pure** é propensa a erros se modificado em um domínio do aplicativo e de leitura em outro.

Portanto, o compilador aplica por processo ser variáveis `const` em **/clr: puro**, tornando-os de leitura apenas em todos os domínios de aplicativo.

Para obter mais informações, consulte [processo](../../cpp/process.md) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2441.

```cpp
// C2441.cpp
// compile with: /clr:pure /c
__declspec(process) int i;   // C2441
__declspec(process) const int j = 0;   // OK
```