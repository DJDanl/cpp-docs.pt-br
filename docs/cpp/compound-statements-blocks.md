---
title: Instruções compostas (blocos)
ms.date: 11/04/2016
f1_keywords:
- '}'
- '{'
helpviewer_keywords:
- blocks, about blocks
- compound statements
ms.assetid: 23855939-7430-498e-8936-0c70055ea701
ms.openlocfilehash: a06a3d9ce887150ba3333e8e9e874ab337f8b4df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221803"
---
# <a name="compound-statements-blocks"></a>Instruções compostas (blocos)

Uma instrução composta consiste em zero ou mais instruções entre chaves (**{}**). Uma instrução composta pode ser usada em qualquer lugar em que uma instrução é esperada. As instruções compostas são comumente chamadas de "blocos".

## <a name="syntax"></a>Sintaxe

```
{ [ statement-list ] }
```

## <a name="remarks"></a>Comentários

O exemplo a seguir usa uma instrução composta como parte da *instrução* da **`if`** instrução (consulte [a instrução If](../cpp/if-else-statement-cpp.md) para obter detalhes sobre a sintaxe):

```cpp
if( Amount > 100 )
{
    cout << "Amount was too large to handle\n";
    Alert();
}
else
{
    Balance -= Amount;
}
```

> [!NOTE]
> Como uma declaração é uma instrução, uma declaração pode ser uma das instruções na *lista*de instruções. Portanto, os nomes declarados em uma instrução composta, mas não declarados explicitamente como estáticos, têm escopo e vida útil locais (para objetos). Consulte [escopo](../cpp/scope-visual-cpp.md) para obter detalhes sobre o tratamento de nomes com escopo local.

## <a name="see-also"></a>Confira também

[Visão geral das instruções do C++](../cpp/overview-of-cpp-statements.md)
