---
title: Estrutura nothrow_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- nothrow_t
dev_langs:
- C++
helpviewer_keywords:
- nothrow_t class
ms.assetid: dc7d5d42-ed5a-4919-88fe-bbad519b7a1d
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 28ed3502c60b53ac0f4f3f532eadad6f4ef61d17
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="nothrowt-structure"></a>Estrutura nothrow_t

O struct é usado como um parâmetro de função para o operador new para indicar que a função deve retornar um ponteiro nulo para relatar uma falha de alocação, em vez de lançar uma exceção.

## <a name="syntax"></a>Sintaxe

```cpp
struct std::nothrow_t {};
```

## <a name="remarks"></a>Comentários

O struct ajuda o compilador a selecionar a versão correta do construtor. [nothrow](../standard-library/new-functions.md#nothrow) é um sinônimo para objetos do tipo `std::nothrow_t`.

## <a name="example"></a>Exemplo

Consulte [operador new](../standard-library/new-operators.md#op_new) e [operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr) para obter exemplos de como `std::nothrow_t` é usado como um parâmetro de função.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<new>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
