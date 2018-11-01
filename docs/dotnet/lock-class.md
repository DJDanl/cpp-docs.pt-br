---
title: Classe lock
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- msclr::lock
- msclr.lock
- lock
helpviewer_keywords:
- lock class
ms.assetid: 5123edd9-6aed-497d-9a0b-f4b6d6c0d666
ms.openlocfilehash: 8876810b15a7d2736f2c8ab0ca1f4c6011918a5f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50547128"
---
# <a name="lock-class"></a>Classe lock

Essa classe automatiza a usar um bloqueio para sincronizar o acesso a um objeto de vários threads.  Quando construído adquire o bloqueio e quando destruído versões o bloqueio.

## <a name="syntax"></a>Sintaxe

```
ref class lock;
```

## <a name="remarks"></a>Comentários

`lock` está disponível somente para objetos CLR e só pode ser usado no código do CLR.

Internamente, os usos da classe de bloqueio <xref:System.Threading.Monitor> para sincronizar o acesso. Consulte este tópico para obter mais informações sobre a sincronização.

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<msclr\lock.h >

**Namespace** msclr

## <a name="see-also"></a>Consulte também

[lock](../dotnet/lock.md)<br/>
[Membros lock](../dotnet/lock-members.md)