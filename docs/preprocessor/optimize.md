---
title: Pragma optimize
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.optimize
- optimize_CPP
helpviewer_keywords:
- pragmas, optimize
- optimize pragma
ms.assetid: cb13c1cc-186a-45bc-bee7-95a8de7381cc
ms.openlocfilehash: 6d7b99b7a72c133d56a209cf42fa9ef670a4a7f9
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220507"
---
# <a name="optimize-pragma"></a>Pragma optimize

Especifica otimizações em uma base de função por função.

## <a name="syntax"></a>Sintaxe

> **#pragma otimizar ("** [ *Optimization-List* ] **",** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

O pragma de **otimização** deve aparecer fora de uma função. Ela entra em vigor na primeira função definida após o pragma ser visto. Os argumentos **on** e **off** ativam opções especificadas na *lista de otimização* .

A *lista de otimização* pode ser zero ou mais parâmetros mostrados na tabela a seguir.

### <a name="parameters-of-the-optimize-pragma"></a>Parâmetros do pragma de otimização

| Parâmetro(s) | Tipo de otimização |
|--------------------|--------------------------|
| **g** | Habilita as otimizações globais. |
| **s** ou **t** | Especifica sequências curtas ou rápidas de código de máquina. |
| **y** | Gera ponteiros de quadro na pilha de programa. |

Esses parâmetros são as mesmas letras usadas com as opções de compilador [/o](../build/reference/o-options-optimize-code.md) . Por exemplo, o pragma a seguir é equivalente à opção de compilador `/Os`:

```cpp
#pragma optimize( "s", on )
```

Usar o pragma de **otimização** com a cadeia de caracteres vazia ( **""** ) é uma forma especial da diretiva:

Quando você usa o parâmetro **off** , ele transforma todas as otimizações, **g**, **s**, **t**e **y**, off.

Quando você usa o parâmetro **on** , ele redefine as otimizações para aquelas que você especificou usando a opção de compilador [/o](../build/reference/o-options-optimize-code.md) .

```cpp
#pragma optimize( "", off )
/* unoptimized code section */
#pragma optimize( "", on )
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
