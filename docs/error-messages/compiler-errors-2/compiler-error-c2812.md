---
title: C2812 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2812
dev_langs:
- C++
helpviewer_keywords:
- C2812
ms.assetid: 22aadb8c-7232-489d-a3ad-60662dda30a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c5469e4f7be3c164cc63fa30f5069009846be48
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705017"
---
# <a name="compiler-error-c2812"></a>C2812 de erro do compilador

> \#Não há suporte para a importação com /clr: pure e /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

[#import diretiva](../../preprocessor/hash-import-directive-cpp.md) não é compatível com **/clr: pure** e **/CLR: safe** porque `#import` requer o uso de bibliotecas de suporte do compilador nativo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2812.

```cpp
// C2812.cpp
// compile with: /clr:pure /c
#import "importlib.tlb"   // C2812
```