---
title: Classe Lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- msclr::lock
- msclr.lock
- lock
dev_langs:
- C++
helpviewer_keywords:
- lock class
ms.assetid: 5123edd9-6aed-497d-9a0b-f4b6d6c0d666
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7ef0887ca3eec7510717aab21ba4c6c7aba98d25
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380289"
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