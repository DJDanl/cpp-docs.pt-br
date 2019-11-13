---
title: Aviso do compilador (nível 1) C4364
ms.date: 11/04/2016
f1_keywords:
- C4364
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
ms.openlocfilehash: 716f440cddc3889ec719ef3b295a0d076175be93
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966524"
---
# <a name="compiler-warning-level-1-c4364"></a>Aviso do compilador (nível 1) C4364

\#usando para o assembly ' file ' visto anteriormente no local (line_number) sem atributo as_friend; as_friend não aplicado

Uma diretiva `#using` foi repetida para um determinado arquivo de metadados, mas o qualificador de `as_friend` não foi usado na primeira ocorrência; o compilador irá ignorar a segunda `as_friend`.

Para obter mais informações, consulte [Friend AssembliesC++()](../../dotnet/friend-assemblies-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente.

```cpp
// C4364.cpp
// compile with: /clr /LD
ref class A {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4364.

```cpp
// C4364_b.cpp
// compile with: /clr /W1 /c
#using " C4364.dll"
#using " C4364.dll" as_friend   // C4364
```