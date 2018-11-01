---
title: Erro fatal C1197
ms.date: 11/04/2016
f1_keywords:
- C1197
helpviewer_keywords:
- C1197
ms.assetid: 22b801b7-e792-41f6-a461-973c03c69f25
ms.openlocfilehash: e1c00a001c807b0cc6a5946b61ca4e9d5dc0167a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604146"
---
# <a name="fatal-error-c1197"></a>Erro fatal C1197

não é possível fazer referência a 'mscorlib.dll_1' como o programa já referenciou 'mscorlib.dll_2'

O compilador é correspondente a uma versão do common language runtime.  No entanto, foi feita uma tentativa para fazer referência a uma versão de um arquivo do common language runtime de uma versão anterior.

Para resolver esse erro, somente os arquivos de referência da versão do common language runtime que acompanha a versão do Visual C++, você estão compilando com.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C1197:

```
// C1197.cpp
// compile with: /clr /c
// processor: x86
#using "C:\Windows\Microsoft.NET\Framework\v1.1.4322\mscorlib.dll"   // C1197
// try the following line instead
// #using "mscorlib.dll"
```