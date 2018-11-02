---
title: Erro do compilador C2812
ms.date: 11/04/2016
f1_keywords:
- C2812
helpviewer_keywords:
- C2812
ms.assetid: 22aadb8c-7232-489d-a3ad-60662dda30a8
ms.openlocfilehash: 88b071f38cf41db9c929d25ffd526b3f2b7ca468
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531814"
---
# <a name="compiler-error-c2812"></a>Erro do compilador C2812

> \#Não há suporte para a importação com /clr: pure e /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

[#import diretiva](../../preprocessor/hash-import-directive-cpp.md) não é compatível com **/clr: pure** e **/CLR: safe** porque `#import` requer o uso de bibliotecas de suporte do compilador nativo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2812.

```cpp
// C2812.cpp
// compile with: /clr:pure /c
#import "importlib.tlb"   // C2812
```