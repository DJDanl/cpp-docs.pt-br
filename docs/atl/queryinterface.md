---
title: QueryInterface
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- interfaces, pointers
- interfaces, availability
- QueryInterface method
ms.assetid: 62fce95e-aafa-4187-b50b-e6611b74c3b3
ms.openlocfilehash: 37bb7a8c7fef963f340704561e24e33cc36707f3
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298630"
---
# <a name="queryinterface"></a>QueryInterface

Embora existam mecanismos pelos quais um objeto pode expressar a funcionalidade que ele fornece estaticamente (antes de ser instanciado), o mecanismo de COM fundamental é usar o método `IUnknown` chamado [QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

Cada interface é derivada de `IUnknown`, portanto, cada interface tem uma implementação de `QueryInterface`. Independentemente da implementação, esse método consulta um objeto usando o IID da interface à qual o chamador deseja um ponteiro. Se o objeto der suporte a essa interface, `QueryInterface` recuperará um ponteiro para a interface, enquanto também chama `AddRef`. Caso contrário, ele retornará o código de erro E_NOINTERFACE.

Observe que você deve obedecer às regras de [contagem de referência](../atl/reference-counting.md) em todos os momentos. Se você chamar `Release` em um ponteiro de interface para diminuir a contagem de referência para zero, não deverá usar esse ponteiro novamente. Ocasionalmente, talvez seja necessário obter uma referência fraca a um objeto (ou seja, você pode desejar obter um ponteiro para uma de suas interfaces sem incrementar a contagem de referência), mas não é aceitável fazer isso chamando `QueryInterface` seguido por `Release`. O ponteiro obtido de maneira tal é inválido e não deve ser usado. Isso se torna aparente quando [_ATL_DEBUG_INTERFACES](reference/debugging-and-error-reporting-macros.md#_atl_debug_interfaces) é definido, portanto definir essa macro é uma maneira útil de localizar bugs de contagem de referência.

## <a name="see-also"></a>Veja também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[QueryInterface: navegando em um objeto](/windows/win32/com/queryinterface--navigating-in-an-object)
