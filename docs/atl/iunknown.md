---
title: IUnknown
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- COM interfaces, base interface
- IUnknown interface
ms.assetid: e6b85472-e54b-4b8c-b19f-4454d6c05a8f
ms.openlocfilehash: 9c9faa4cffcdc8e6840dfbbe141cb63f51155ded
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492067"
---
# <a name="iunknown"></a>IUnknown

[IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é a interface base de todas as outras interfaces com.  Essa interface define três métodos: [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)), [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release). [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) permite que um usuário de interface solicite ao objeto um ponteiro para outra de suas interfaces. O [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e o [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) implementam a contagem de referência na interface.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[IUnknown e herança de interface](/windows/win32/com/iunknown-and-interface-inheritance)
