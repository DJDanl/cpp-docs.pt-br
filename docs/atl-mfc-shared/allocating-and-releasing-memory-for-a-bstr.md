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
ms.openlocfilehash: adc3e1efd032bb3e3e45381da24c5a5b59852375
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62216963"
---
# <a name="allocating-and-releasing-memory-for-a-bstr"></a>Alocando e liberando memória para um BSTR

Quando você cria `BSTR`s e passá-los entre os objetos com, você deve tomar cuidado em tratar a memória que eles usam para evitar vazamentos de memória. Quando um `BSTR` permaneça dentro de uma interface, você deve liberar sua memória quando tiver terminado com ele. No entanto, quando um `BSTR` passes fora de uma interface, o objeto receptor assume a responsabilidade para o gerenciamento de memória.

Em geral, as regras para alocar e liberar a memória alocada para `BSTR`s são da seguinte maneira:

- Quando você chama uma função que espera uma `BSTR` argumento, você deve alocar a memória para o `BSTR` antes da chamada e liberá-lo posteriormente. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#192](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_1.cpp)]

   [!code-cpp[NVC_ATLMFC_Utilities#193](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_2.cpp)]

- Quando você chama uma função que retorna um `BSTR`, você deve liberar a cadeia de caracteres. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#194](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_3.cpp)]

   [!code-cpp[NVC_ATLMFC_Utilities#195](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_4.cpp)]

- Quando você implementa uma função que retorna um `BSTR`, alocar a cadeia de caracteres, mas não a libere. O recebimento a função libera a memória. Por exemplo:

   [!code-cpp[NVC_ATLMFC_Utilities#196](../atl-mfc-shared/codesnippet/cpp/allocating-and-releasing-memory-for-a-bstr_5.cpp)]

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[CStringT::AllocSysString](../atl-mfc-shared/reference/cstringt-class.md#allocsysstring)<br/>
[SysAllocString](/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)<br/>
[SysFreeString](/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)
