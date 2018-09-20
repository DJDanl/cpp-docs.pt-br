---
title: Estrutura SOCKADDR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- SOCKADDR
dev_langs:
- C++
helpviewer_keywords:
- SOCKADDR structure [MFC]
ms.assetid: df1ed66a-f4b8-43f8-8db8-8c2533d25f68
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ac6e433c0bbc70e6e1caa79599d5388aef49b4c5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435279"
---
# <a name="sockaddr-structure"></a>Estrutura SOCKADDR

O `SOCKADDR` estrutura é usada para armazenar um endereço IP (Internet Protocol) para uma máquina que participam de uma comunicação de soquetes do Windows.

## <a name="syntax"></a>Sintaxe

```
struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};
```

#### <a name="parameters"></a>Parâmetros

*sa_family*<br/>
Família de endereços de soquete.

*sa_data*<br/>
Tamanho máximo de todas as estruturas de endereço de soquete diferentes.

## <a name="remarks"></a>Comentários

Kit do desenvolvedor do Microsoft TCP/IP Sockets só oferece suporte os domínios de endereço da Internet. Para preencher os valores para cada parte de um endereço na verdade, você deve usar o `SOCKADDR_IN` estrutura de dados, que é especificamente para o formato desse endereço. O `SOCKADDR` e o `SOCKADDR_IN` estruturas de dados têm o mesmo tamanho. Você simplesmente converter para alternar entre os tipos de estrutura de dois.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** winsock2.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Estrutura SOCKADDR_IN](../../mfc/reference/sockaddr-in-structure.md)<br/>
[CAsyncSocket::Create](../../mfc/reference/casyncsocket-class.md#create)<br/>
[CSocket::Create](../../mfc/reference/csocket-class.md#create)

