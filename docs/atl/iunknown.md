---
title: IUnknown | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IUnknown
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces, base interface
- IUnknown interface
ms.assetid: e6b85472-e54b-4b8c-b19f-4454d6c05a8f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5903cebe5de87ab528dbcfe1769047b7b7ace3ef
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43761908"
---
# <a name="iunknown"></a>IUnknown

[IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) é a interface base de todas as outras interfaces COM.  Essa interface define três métodos: [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)), [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)) permite que um usuário da interface peça o objeto de um ponteiro para outro de suas interfaces. [AddRef](/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) e [versão](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) implementar a interface de contagem de referência.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)   
[IUnknown e herança da Interface](/windows/desktop/com/iunknown-and-interface-inheritance)

