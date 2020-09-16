---
title: Aviso do compilador (nível 1) C4364
ms.date: 11/04/2016
f1_keywords:
- C4364
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
ms.openlocfilehash: 7f1c71cb3cd6a99d4ed9960032813e7cebca7591
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685073"
---
# <a name="compiler-warning-level-1-c4364"></a>Aviso do compilador (nível 1) C4364

\#usando para o assembly ' file ' visto anteriormente no local (line_number) sem atributo as_friend; as_friend não aplicado

Uma `#using` diretiva foi repetida para um determinado arquivo de metadados, mas o **`as_friend`** qualificador não foi usado na primeira ocorrência; o compilador irá ignorar o segundo **`as_friend`** .

Para obter mais informações, consulte [Friend Assemblies (C++)](../../dotnet/friend-assemblies-cpp.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir cria um componente.

```cpp
// C4364.cpp
// compile with: /clr /LD
ref class A {};
```

O exemplo a seguir gera C4364.

```cpp
// C4364_b.cpp
// compile with: /clr /W1 /c
#using " C4364.dll"
#using " C4364.dll" as_friend   // C4364
```
