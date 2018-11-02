---
title: Compilador aviso (nível 1) C4691
ms.date: 11/04/2016
f1_keywords:
- C4691
helpviewer_keywords:
- C4691
ms.assetid: 722133d9-87f6-46c1-9e86-9825453d6999
ms.openlocfilehash: c194e19c8766b67eb7deef32e7228564cda5f1e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519685"
---
# <a name="compiler-warning-level-1-c4691"></a>Compilador aviso (nível 1) C4691

'type': tipo referenciado era esperado no assembly não referenciado 'file', tipo definido na unidade de tradução atual usada em vez disso

O arquivo de metadados que contém a definição de tipo original não é referenciado, e o compilador está usando uma definição de tipo local.

No caso em que você está recriando *arquivo*, pode ser ignorado ou desativado com pragma C4691 [aviso](../../preprocessor/warning.md).  Ou seja, se o arquivo que você está criando é o mesmo que o arquivo em que o compilador espera encontrar a definição de tipo, você pode ignorar C4691.

No entanto, um comportamento inesperado pode ocorrer se o compilador usa uma definição que não seja do mesmo assembly que é referenciado em metadados. Tipos CLR são tipados não apenas pelo nome do tipo, mas também pelo assembly.  Ou seja, um tipo Z do assembly z.dll é diferente de um tipo Z do assembly y.dll.

## <a name="example"></a>Exemplo

Este exemplo contém a definição do tipo original.

```
// C4691_a.cpp
// compile with: /clr /LD /W1
public ref class Original_Type {};
```

## <a name="example"></a>Exemplo

Este exemplo faz referência a C4691_a.dll e declara um campo do tipo Original_Type.

```
// C4691_b.cpp
// compile with: /clr /LD
#using "C4691_a.dll"
public ref class Client {
public:
   Original_Type^ ot;
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4691.  Observe que este exemplo contém uma definição para Original_Type e não faz referência a C4691a.dll.

Para resolver, fazer referência ao arquivo de metadados que contém a definição de tipo original e remova a declaração de local e a definição.

```
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