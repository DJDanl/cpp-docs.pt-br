---
title: Classe de bad_any_cast
ms.date: 04/04/2019
f1_keywords:
- any/std::bad_any_cast
- any/std::bad_any_cast::what
helpviewer_keywords:
- any/std::bad_any_cast
- any/std::bad_any_cast::what
ms.openlocfilehash: 5172281d1918a8b4ac33bcf412bf4be82b04ef56
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268678"
---
# <a name="badanycast-class"></a>Classe de bad_any_cast

Gerada por uma falha de objetos `any_cast`.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_any_cast
```

### <a name="member-functions"></a>Funções de membro

|||
|-|-|
|[what](#what)|Retorna o tipo.|

## <a name="what"></a> o que

Retorna o tipo.

```cpp
const char* what() const noexcept override;
```
