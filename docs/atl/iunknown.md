---
title: IUnknown
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- IUnknown
helpviewer_keywords:
- COM interfaces, base interface
- IUnknown interface
ms.assetid: e6b85472-e54b-4b8c-b19f-4454d6c05a8f
ms.openlocfilehash: 760db28f4016ed529b45c72d25eaabf664642cd2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50430037"
---
# <a name="iunknown"></a>IUnknown

[IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) é a interface base de todas as outras interfaces COM.  Essa interface define três métodos: [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)), [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) permite que um usuário da interface peça o objeto de um ponteiro para outro de suas interfaces. [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) implementar a interface de contagem de referência.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[IUnknown e herança da Interface](/windows/desktop/com/iunknown-and-interface-inheritance)

