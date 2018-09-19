---
title: _com_ptr_t::Detach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a7f2f44df96ca339e5d8e4b251b5f2d259cb606b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092135"
---
# <a name="comptrtdetach"></a>_com_ptr_t::Detach

**Seção específica da Microsoft**

Extrai e retorna o ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
Interface* Detach( ) throw( );
```

## <a name="remarks"></a>Comentários

Extrai e retorna o ponteiro de interface encapsulado e, em seguida, limpa o armazenamento de ponteiro encapsulado como NULL. Isso remove o ponteiro de interface do encapsulamento. Cabe a você chamar `Release` no ponteiro de interface retornado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)