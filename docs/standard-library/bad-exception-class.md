---
title: Classe bad_exception
ms.date: 11/04/2016
f1_keywords:
- exception/std::bad_exception
helpviewer_keywords:
- bad_exception class
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
ms.openlocfilehash: 1795a44d2d31cfbad964b41ef03e4bf65b401352
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246200"
---
# <a name="badexception-class"></a>Classe bad_exception

A classe descreve uma exceção que pode ser gerada de um manipulador inesperado.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_exception : public exception {};

bad_exception();
bad_exception(const bad_exception&);
bad_exception& operator=(const bad_exception&);
const char* what() const override;
```

## <a name="remarks"></a>Comentários

[unexpected](../standard-library/exception-functions.md#unexpected) lançará um `bad_exception`, em vez de encerrar ou em vez de chamar outra função especificada com [set_unexpected](../standard-library/exception-functions.md#set_unexpected) se `bad_exception` estiver incluído na lista de lançamento de uma função.

O valor retornado por `what` é uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.

Para obter uma lista de membros herdados pela classe `bad_exception`, consulte a [Classe exception](../standard-library/exception-class.md).

## <a name="example"></a>Exemplo

Consulte [set_unexpected](../standard-library/exception-functions.md#set_unexpected) para obter um exemplo do uso de [unexpected](../standard-library/exception-functions.md#unexpected) gerando um `bad_exception`.
