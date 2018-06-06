---
title: C2393 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2393
dev_langs:
- C++
helpviewer_keywords:
- C2393
ms.assetid: 4bd95728-e813-4ce8-844a-c6ebe235ca82
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 057537c8efcf6e827d9ac9aaf36c0eace6d24156
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704024"
---
# <a name="compiler-error-c2393"></a>C2393 de erro do compilador

> '*símbolo*': símbolo per-appdomain não pode ser alocado no segmento '*segmento*'

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

O uso de [appdomain](../../cpp/appdomain.md) variáveis implica que você está compilando com **/clr: pure** ou **/CLR: safe**, e uma imagem confiável ou pura não pode conter segmentos de dados.

Consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2393. Para corrigir esse problema, não crie um segmento de dados.

```cpp
// C2393.cpp
// compile with: /clr:pure /c
#pragma data_seg("myseg")
int n = 0;   // C2393
```