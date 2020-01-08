---
title: IUnknown
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- COM interfaces, base interface
- IUnknown interface
ms.assetid: e6b85472-e54b-4b8c-b19f-4454d6c05a8f
ms.openlocfilehash: 6adfbdc59b2a63aa2f2bb39e27139ca977ba9465
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298747"
---
# <a name="iunknown"></a>IUnknown

[IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) é a interface base de todas as outras interfaces com.  Essa interface define três métodos: [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref)e [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release). [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) permite que um usuário de interface solicite ao objeto um ponteiro para outra de suas interfaces. O [AddRef](/windows/win32/api/unknwn/nf-unknwn-iunknown-addref) e o [Release](/windows/win32/api/unknwn/nf-unknwn-iunknown-release) implementam a contagem de referência na interface.

## <a name="see-also"></a>Veja também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[IUnknown e herança de interface](/windows/win32/com/iunknown-and-interface-inheritance)
