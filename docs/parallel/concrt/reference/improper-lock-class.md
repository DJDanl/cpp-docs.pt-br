---
title: Classe improper_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- improper_lock
- CONCRT/concurrency::improper_lock
- CONCRT/concurrency::improper_lock::improper_lock
dev_langs:
- C++
helpviewer_keywords:
- improper_lock class
ms.assetid: 8f494942-7748-4a2a-8de2-23414bfe6346
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 655776543a0c368bf5d13719d10b507c941a0fa9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404690"
---
# <a name="improperlock-class"></a>Classe improper_lock

Esta classe descreve uma exceção gerada quando um bloqueio é adquirido incorretamente.

## <a name="syntax"></a>Sintaxe

```
class improper_lock : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[improper_lock](#ctor)|Sobrecarregado. Constrói um `improper_lock exception`.|

## <a name="remarks"></a>Comentários

Normalmente, essa exceção é lançada quando é feita uma tentativa para adquirir um bloqueio de não reentrante recursivamente no mesmo contexto.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`improper_lock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> improper_lock

Constrói um `improper_lock exception`.

```
explicit _CRTIMP improper_lock(_In_z_ const char* _Message) throw();

improper_lock() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe critical_section](critical-section-class.md)<br/>
[Classe reader_writer_lock](reader-writer-lock-class.md)
