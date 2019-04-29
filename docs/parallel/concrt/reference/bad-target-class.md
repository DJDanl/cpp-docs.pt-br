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
ms.openlocfilehash: 04489151cedf1a47aeebd883e76b8d26b51031ef
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62337759"
---
# <a name="badtarget-class"></a>Classe bad_target

Esta classe descreve uma exceção gerada quando um bloco de mensagens é receber um ponteiro para um destino que é inválido para a operação que está sendo executada.

## <a name="syntax"></a>Sintaxe

```
class bad_target : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[bad_target](#ctor)|Sobrecarregado. Constrói um objeto `bad_target`.|

## <a name="remarks"></a>Comentários

Normalmente, essa exceção é lançada por motivos como um destino para tentar consumir uma mensagem que é reservada para um destino diferente ou liberar uma reserva de que ele não mantém.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`bad_target`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> bad_target

Constrói um objeto `bad_target`.

```
explicit _CRTIMP bad_target(_In_z_ const char* _Message) throw();

bad_target() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)
