---
title: Erro fatal C1197
ms.date: 11/04/2016
f1_keywords:
- C1197
helpviewer_keywords:
- C1197
ms.assetid: 22b801b7-e792-41f6-a461-973c03c69f25
ms.openlocfilehash: 7f698262c73f0b311a92a8940107b552430919bb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747235"
---
# <a name="fatal-error-c1197"></a>Erro fatal C1197

Não é possível referenciar ' mscorlib. dll_1 ' porque o programa já referenciou ' mscorlib. dll_2 '

O compilador é correspondido a uma versão do Common Language Runtime.  No entanto, foi feita uma tentativa de fazer referência a uma versão de um arquivo de Common Language Runtime de uma versão anterior.

Para resolver esse erro, somente os arquivos de referência da versão do Common Language Runtime fornecidos com a versão do Visual C++ com a qual você está compilando.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C1197:

```cpp
// C1197.cpp
// compile with: /clr /c
// processor: x86
#using "C:\Windows\Microsoft.NET\Framework\v1.1.4322\mscorlib.dll"   // C1197
// try the following line instead
// #using "mscorlib.dll"
```
