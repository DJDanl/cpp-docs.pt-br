---
title: Estrutura de LINGER | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- LINGER
dev_langs:
- C++
helpviewer_keywords:
- LINGER structure [MFC]
ms.assetid: 1fb1c5bf-a64e-4a6c-89d6-1734e4fdbb1b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2dda3aab3c4a967c82a699058868edc8fc183984
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386373"
---
# <a name="linger-structure"></a>Estrutura de LINGER

O `LINGER` estrutura é usada para manipular as opções de SO_LINGER e SO_DONTLINGER `CAsyncSocket::GetSockOpt`.

## <a name="syntax"></a>Sintaxe

```
struct linger {
    u_short l_onoff;            // option on/off
    u_short l_linger;           // linger time
};
```

## <a name="remarks"></a>Comentários

Definindo a opção SO_DONTLINGER impede que o bloqueio na função de membro `Close` enquanto aguarda unsent dados a serem enviados. Essa opção é equivalente a definir SO_LINGER com `l_onoff` definido como 0.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** winsock2.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CAsyncSocket::GetSockOpt](../../mfc/reference/casyncsocket-class.md#getsockopt)<br/>
[CAsyncSocket::SetSockOpt](../../mfc/reference/casyncsocket-class.md#setsockopt)

