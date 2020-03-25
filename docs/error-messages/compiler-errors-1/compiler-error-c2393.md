---
title: Erro do compilador C2393
ms.date: 11/04/2016
f1_keywords:
- C2393
helpviewer_keywords:
- C2393
ms.assetid: 4bd95728-e813-4ce8-844a-c6ebe235ca82
ms.openlocfilehash: cc3c124f1a4daea0f2517a93c6b354b8233aa5e5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205979"
---
# <a name="compiler-error-c2393"></a>Erro do compilador C2393

> '*Symbol*': símbolo Per-AppDomain não pode ser alocado no segmento '*Segment*'

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

O uso de variáveis [AppDomain](../../cpp/appdomain.md) implica que você está compilando com **/CLR: Pure** ou **/CLR: safe**, e uma imagem segura ou pura não pode conter segmentos de dados.

Consulte [/CLR (compilação Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2393. Para corrigir esse problema, não crie um segmento de dados.

```cpp
// C2393.cpp
// compile with: /clr:pure /c
#pragma data_seg("myseg")
int n = 0;   // C2393
```
