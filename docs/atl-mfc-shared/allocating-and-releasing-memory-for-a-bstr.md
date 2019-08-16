---
title: Alocando e liberando memória para um BSTR
ms.date: 11/04/2016
f1_keywords:
- bstr
helpviewer_keywords:
- BSTRs, memory allocation
- memory deallocation, string memory
- memory [C++], releasing
- memory allocation, BSTRs
- memory deallocation, BSTR memory
- strings [C++], releasing
ms.assetid: 98041e29-3442-4a02-b425-7a4a13e9cc84
ms.openlocfilehash: a7a82acff959d18dcadd3a2c8516a20d60a617d3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491407"
---
# <a name="allocating-and-releasing-memory-for-a-bstr"></a>Alocando e liberando memória para um BSTR

Ao criar `BSTR`s e passá-los entre objetos com, você deve cuidar do tratamento da memória que eles usam para evitar vazamentos de memória. Quando um `BSTR` permanece em uma interface, você deve liberar sua memória quando terminar. No entanto, `BSTR` quando um passa de uma interface, o objeto receptor assume a responsabilidade por seu gerenciamento de memória.

Em geral, as regras para alocar e liberar memória alocada para `BSTR`s são as seguintes:

- Ao chamar uma função que espera um `BSTR` argumento, você deve alocar a memória para o `BSTR` antes da chamada e liberá-lo posteriormente. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#192](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_1.cpp)]

   [!code-cpp[NVC_ATLMFC_Utilities#193](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_2.cpp)]

- Quando você chama uma função que retorna um `BSTR`, você deve liberar a cadeia de caracteres por conta própria. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#194](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_3.cpp)]

   [!code-cpp[NVC_ATLMFC_Utilities#195](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_4.cpp)]

- Quando você implementa uma função que retorna um `BSTR`, aloque a cadeia de caracteres, mas não a libera. O recebimento da função libera a memória. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#196](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_5.cpp)]

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[CStringT::AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring)<br/>
[SysAllocString](/windows/win32/api/oleauto/nf-oleauto-sysallocstring)<br/>
[SysFreeString](/windows/win32/api/oleauto/nf-oleauto-sysfreestring)
