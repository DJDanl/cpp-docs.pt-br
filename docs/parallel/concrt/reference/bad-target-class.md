---
title: Classe bad_target
ms.date: 11/04/2016
f1_keywords:
- bad_target
- CONCRT/concurrency::bad_target
- CONCRT/concurrency::bad_target::bad_target
helpviewer_keywords:
- bad_target class
ms.assetid: e6dcddbf-9217-4fac-ac7f-7b8b4781d2f5
ms.openlocfilehash: 023607ff142b7fa39165cc9b5280a8e9345a3645
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142852"
---
# <a name="bad_target-class"></a>Classe bad_target

Essa classe descreve uma exceção gerada quando um bloco de mensagens recebe um ponteiro para um destino que é inválido para a operação que está sendo executada.

## <a name="syntax"></a>Sintaxe

```cpp
class bad_target : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[bad_target](#ctor)|Sobrecarregado. Constrói um objeto `bad_target`.|

## <a name="remarks"></a>Comentários

Essa exceção normalmente é lançada por motivos como um destino que tenta consumir uma mensagem que é reservada para um destino diferente ou liberando uma reserva que ela não tem.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`bad_target`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>bad_target

Constrói um objeto `bad_target`.

```cpp
explicit _CRTIMP bad_target(_In_z_ const char* _Message) throw();

bad_target() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)
