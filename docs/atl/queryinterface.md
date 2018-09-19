---
title: QueryInterface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- QueryInterface
dev_langs:
- C++
helpviewer_keywords:
- interfaces, pointers
- interfaces, availability
- QueryInterface method
ms.assetid: 62fce95e-aafa-4187-b50b-e6611b74c3b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c361bc9510c610f2004af9f09c061d6f4b8b8cd2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46057438"
---
# <a name="queryinterface"></a>QueryInterface

Embora existam mecanismos pelos quais um objeto pode expressar a funcionalidade que fornece estaticamente (antes que seja instanciado), o mecanismo COM fundamental é usar o `IUnknown` método chamado [QueryInterface](/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q_)).

Cada interface deriva `IUnknown`, portanto, cada interface tem uma implementação de `QueryInterface`. Independentemente da implementação, este método consulta um objeto usando o IID da interface à qual o chamador quiser um ponteiro. Se o objeto der suporte a essa interface `QueryInterface` recupera um ponteiro para a interface, enquanto também chama `AddRef`. Caso contrário, ele retornará o código de erro E_NOINTERFACE.

Observe que você deve respeitar [contagem de referência](../atl/reference-counting.md) regras em todos os momentos. Se você chamar `Release` em um ponteiro de interface para diminuir a contagem de referência como zero, você não deve usar esse ponteiro novamente. Ocasionalmente, talvez você precise obter uma referência fraca em um objeto (ou seja, talvez você queira obter um ponteiro para uma de suas interfaces sem incrementar a contagem de referência), mas não é aceitável para fazer isso chamando `QueryInterface` seguido por `Release`. O ponteiro obtido dessa maneira é inválido e não deve ser usado. Isso mais rapidamente se torna aparente quando [_ATL_DEBUG_INTERFACES](reference/debugging-and-error-reporting-macros.md#_atl_debug_interfaces) for definida, portanto, definir essa macro é uma maneira útil de localização de bugs de contagem de referência.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[QueryInterface: Navegando em um objeto](/windows/desktop/com/queryinterface--navigating-in-an-object)

