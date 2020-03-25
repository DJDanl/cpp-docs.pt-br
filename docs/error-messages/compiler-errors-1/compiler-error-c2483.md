---
title: Erro do compilador C2483
ms.date: 09/15/2017
f1_keywords:
- C2483
helpviewer_keywords:
- C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
ms.openlocfilehash: 20b08c0d2cd89224ed3d3b8b34915deb947b0b4b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205108"
---
# <a name="compiler-error-c2483"></a>Erro do compilador C2483

>'*Identifier*': objeto com Construtor ou destruidor não pode ser declarado como ' thread '

Essa mensagem de erro está obsoleta no Visual Studio 2015 e versões posteriores. Nas versões anteriores, as variáveis declaradas com o atributo `thread` não podem ser inicializadas com um construtor ou outra expressão que requer avaliação em tempo de execução. Uma expressão estática é necessária para inicializar dados de `thread`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2483 em Visual Studio 2013 e em versões anteriores.

```cpp
// C2483.cpp
// compile with: /c
__declspec(thread) struct A {
   A(){}
   ~A(){}
} aa;   // C2483 error

__declspec(thread) struct B {} b;   // OK
```

## <a name="see-also"></a>Confira também

[thread](../../cpp/thread.md)
