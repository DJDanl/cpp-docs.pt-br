---
title: Classe invalid_oversubscribe_operation | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- invalid_oversubscribe_operation
- CONCRT/concurrency::invalid_oversubscribe_operation
- CONCRT/concurrency::invalid_oversubscribe_operation::invalid_oversubscribe_operation
dev_langs:
- C++
helpviewer_keywords:
- invalid_oversubscribe_operation class
ms.assetid: 0a9c5f08-d5e6-4ad0-90a9-517472b3ac28
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a1728053c7b42afedb4cda9b2dc96a089750a866
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161691"
---
# <a name="invalidoversubscribeoperation-class"></a>Classe invalid_oversubscribe_operation

Esta classe descreve uma exceção gerada quando o `Context::Oversubscribe` método for chamado com o `_BeginOversubscription` parâmetro definido como **falso** sem uma chamada anterior para o `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como **verdadeira**.

## <a name="syntax"></a>Sintaxe

```
class invalid_oversubscribe_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_oversubscribe_operation](#ctor)|Sobrecarregado. Constrói um `invalid_oversubscribe_operation` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_oversubscribe_operation`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> invalid_oversubscribe_operation

Constrói um `invalid_oversubscribe_operation` objeto.

```
explicit _CRTIMP invalid_oversubscribe_operation(_In_z_ const char* _Message) throw();

invalid_oversubscribe_operation() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
