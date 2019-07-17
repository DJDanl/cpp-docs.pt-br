---
title: piecewise_contruct_t estrutura
ms.date: 11/04/2016
f1_keywords:
- utility/std::piecewise_contruct_t
helpviewer_keywords:
- piecewise_contruct_t class
- piecewise_contruct_t structure
ms.openlocfilehash: 6a9a6af97ca5c7751d64cd1fa70c9d9eba87da7c
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268358"
---
# <a name="piecewisecontructt-structure"></a>piecewise_contruct_t estrutura

O struct `piecewise_construct_t` é um tipo de estrutura vazia usado para manter o construtor separado e o sobrecarregamento de função. Especificamente, `pair` tem um construtor com `piecewise_construct_t` como o primeiro argumento, seguido por dois `tuple` argumentos.

## <a name="syntax"></a>Sintaxe

```cpp
struct piecewise_construct_t { explicit piecewise_construct_t() = default; };

inline constexpr piecewise_construct_t piecewise_construct{};
```
