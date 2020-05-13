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
ms.openlocfilehash: 60d7e88c5ccccac5a1d967a91c8a82dd954d9afc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337341"
---
# <a name="compound-statements-blocks"></a>Instruções compostas (blocos)

Uma instrução composta consiste em zero ou mais declarações incluídas em chaves **({ }**). Uma instrução composta pode ser usada em qualquer lugar em que uma instrução é esperada. As instruções compostas são comumente chamadas de "blocos".

## <a name="syntax"></a>Sintaxe

```
{ [ statement-list ] }
```

## <a name="remarks"></a>Comentários

O exemplo a seguir usa uma declaração composta como parte da *declaração* da **declaração if** (consulte [A Declaração if](../cpp/if-else-statement-cpp.md) para detalhes sobre a sintaxe):

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
> Como uma declaração é uma declaração, uma declaração pode ser uma das declarações da *lista de declarações.* Portanto, os nomes declarados em uma instrução composta, mas não declarados explicitamente como estáticos, têm escopo e vida útil locais (para objetos). Consulte [o escopo](../cpp/scope-visual-cpp.md) para obter detalhes sobre o tratamento de nomes com escopo local.

## <a name="see-also"></a>Confira também

[Visão geral das declarações C++](../cpp/overview-of-cpp-statements.md)
