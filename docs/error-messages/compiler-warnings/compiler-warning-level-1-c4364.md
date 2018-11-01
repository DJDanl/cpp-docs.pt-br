---
title: Compilador aviso (nível 1) C4364
ms.date: 11/04/2016
f1_keywords:
- C4364
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
ms.openlocfilehash: db2774b6a73a989b4e9250719f99122826b486fe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643593"
---
# <a name="compiler-warning-level-1-c4364"></a>Compilador aviso (nível 1) C4364

\#usando o assembly 'file' visto anteriormente em location(line_number) sem atributo as_friend; as_friend não aplicado

Um `#using` diretiva foi repetida para um arquivo de metadados especificado, mas o `as_friend` qualificador não foi usado na primeira ocorrência; o compilador ignorará o segundo `as_friend`.

Para obter mais informações, consulte [Assemblies de amigo (C++)](../../dotnet/friend-assemblies-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente.

```
// C4364.cpp
// compile with: /clr /LD
ref class A {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4364.

```
// C4364_b.cpp
// compile with: /clr /W1 /c
#using " C4364.dll"
#using " C4364.dll" as_friend   // C4364
```