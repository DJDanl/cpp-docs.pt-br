---
title: Classe invalid_operation
ms.date: 11/04/2016
f1_keywords:
- invalid_operation
- CONCRT/concurrency::invalid_operation
- CONCRT/concurrency::invalid_operation::invalid_operation
helpviewer_keywords:
- invalid_operation class
ms.assetid: 26ba07dc-fcdf-44cb-b748-a31d35205b52
ms.openlocfilehash: 8b971a12ff83753546cfea7b90288d1bc43400c0
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341031"
---
# <a name="invalidoperation-class"></a>Classe invalid_operation

Esta classe descreve uma exceção gerada quando uma operação inválida é executada, o que não é descrita com mais precisão por outro tipo de exceção gerado pelo tempo de execução de simultaneidade.

## <a name="syntax"></a>Sintaxe

```
class invalid_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_operation](#ctor)|Sobrecarregado. Constrói um `invalid_operation` objeto.|

## <a name="remarks"></a>Comentários

Os vários métodos que lançam essa exceção geralmente documentará sob quais circunstâncias eles a lançam.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_operation`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> invalid_operation

Constrói um `invalid_operation` objeto.

```
explicit _CRTIMP invalid_operation(_In_z_ const char* _Message) throw();

invalid_operation() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
