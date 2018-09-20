---
title: Classe invalid_operation | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- invalid_operation
- CONCRT/concurrency::invalid_operation
- CONCRT/concurrency::invalid_operation::invalid_operation
dev_langs:
- C++
helpviewer_keywords:
- invalid_operation class
ms.assetid: 26ba07dc-fcdf-44cb-b748-a31d35205b52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9e903a3d5e269a273a191fd733ff8813b75b53a5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416897"
---
# <a name="invalidoperation-class"></a>Classe invalid_operation

Esta classe descreve uma exceção gerada quando uma operação inválida é executada, o que não é descrita com mais precisão por outro tipo de exceção gerado pelo tempo de execução de simultaneidade.

## <a name="syntax"></a>Sintaxe

```
class invalid_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
