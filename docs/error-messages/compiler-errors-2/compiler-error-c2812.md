---
title: Erro do compilador C2812
ms.date: 11/04/2016
f1_keywords:
- C2812
helpviewer_keywords:
- C2812
ms.assetid: 22aadb8c-7232-489d-a3ad-60662dda30a8
ms.openlocfilehash: cec92982646c64e6c5b669df328e4836d4f44df8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202077"
---
# <a name="compiler-error-c2812"></a>Erro do compilador C2812

> Não há suporte para a importação de \#com/CLR: Pure e/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Não há suporte para a [diretiva #import](../../preprocessor/hash-import-directive-cpp.md) com **/CLR: Pure** e **/CLR: safe** porque `#import` requer o uso de bibliotecas de suporte do compilador nativo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2812.

```cpp
// C2812.cpp
// compile with: /clr:pure /c
#import "importlib.tlb"   // C2812
```
