---
title: Erro do compilador C2393
ms.date: 11/04/2016
f1_keywords:
- C2393
helpviewer_keywords:
- C2393
ms.assetid: 4bd95728-e813-4ce8-844a-c6ebe235ca82
ms.openlocfilehash: 39ca693aed3f08e7b2df3d687f94d93384393f23
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62302391"
---
# <a name="compiler-error-c2393"></a>Erro do compilador C2393

> '*símbolo*': símbolo per-appdomain não pode ser alocado no segmento '*segmento*'

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

O uso de [appdomain](../../cpp/appdomain.md) variáveis implica que você está compilando com **/clr: pure** ou **/CLR: safe**, e uma imagem pura ou segura não pode conter segmentos de dados.

Ver [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2393. Para corrigir esse problema, não crie um segmento de dados.

```cpp
// C2393.cpp
// compile with: /clr:pure /c
#pragma data_seg("myseg")
int n = 0;   // C2393
```