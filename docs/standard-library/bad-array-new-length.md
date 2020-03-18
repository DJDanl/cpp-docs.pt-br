---
title: Classe bad_array_new_length
ms.date: 11/04/2016
f1_keywords:
- new/std::bad_array_new_length
helpviewer_keywords:
- bad_alloc class
ms.assetid: 6429a8e6-5a49-4907-8d56-f4a4ec8131d0
ms.openlocfilehash: c4f4f58f7b28960bbacf695a675fbe4f20a54192
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443708"
---
# <a name="bad_array_new_length-class"></a>Classe bad_array_new_length

A classe descreve uma exceção lançada para indicar que uma solicitação de alocação não teve sucesso devido a um tamanho de matriz menor que zero ou maior que seu limite.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_array_new_length : public bad_alloc {
    public: bad_array_new_length() noexcept;
    const char* what() const noexcept override;
};
```

## <a name="remarks"></a>Comentários

O valor retornado por `what` é uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** \<novo >

## <a name="see-also"></a>Consulte também

[classe de exceção](../standard-library/exception-class.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
