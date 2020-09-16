---
title: Aviso do compilador (nível 1) C4691
ms.date: 11/04/2016
f1_keywords:
- C4691
helpviewer_keywords:
- C4691
ms.assetid: 722133d9-87f6-46c1-9e86-9825453d6999
ms.openlocfilehash: 6a4d1de621983794acfae4de7707ba127df9a1b7
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685561"
---
# <a name="compiler-warning-level-1-c4691"></a>Aviso do compilador (nível 1) C4691

' type ': tipo referenciado era esperado em ' file ' de assembly não referenciado, tipo definido na unidade de tradução atual usado em vez disso

O arquivo de metadados que contém a definição de tipo original não é referenciado e o compilador está usando uma definição de tipo local.

No caso em que você está recompilando o *arquivo*, C4691 pode ser ignorado ou desativado com pragma [Warning](../../preprocessor/warning.md).  Ou seja, se o arquivo que você está compilando for o mesmo que o arquivo em que o compilador espera encontrar a definição de tipo, você poderá ignorar C4691.

No entanto, um comportamento inesperado pode ocorrer se o compilador usar uma definição que não seja do mesmo assembly referenciado nos metadados; Os tipos CLR são digitados não apenas pelo nome do tipo, mas também pelo assembly.  Ou seja, um tipo Z do assembly z.dll é diferente de um tipo Z do assembly y.dll.

## <a name="examples"></a>Exemplos

Este exemplo contém a definição de tipo original.

```cpp
// C4691_a.cpp
// compile with: /clr /LD /W1
public ref class Original_Type {};
```

Este exemplo faz referência a C4691_a.dll e declara um campo do tipo Original_Type.

```cpp
// C4691_b.cpp
// compile with: /clr /LD
#using "C4691_a.dll"
public ref class Client {
public:
   Original_Type^ ot;
};
```

O exemplo a seguir gera C4691.  Observe que este exemplo contém uma definição para Original_Type e não faz referência a C4691a.dll.

Para resolver, referencie o arquivo de metadados que contém a definição de tipo original e remova a declaração e a definição local.

```cpp
// C4691_c.cpp
// compile with: /clr /LD /W1
// C4691 expected

// Uncomment the following line to resolve.
// #using "C4691_a.dll"
#using "C4691_b.dll"

// Delete the following line to resolve.
ref class Original_Type;

public ref class MyClass : Client {};
```
