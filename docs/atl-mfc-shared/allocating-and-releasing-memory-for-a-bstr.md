---
title: Alocando e liberando memória para um BSTR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- bstr
dev_langs:
- C++
helpviewer_keywords:
- BSTRs, memory allocation
- memory deallocation, string memory
- memory [C++], releasing
- memory allocation, BSTRs
- memory deallocation, BSTR memory
- strings [C++], releasing
ms.assetid: 98041e29-3442-4a02-b425-7a4a13e9cc84
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 565032ca7ddf64e93716b1c06524bd09a1a46079
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46389389"
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
[SysAllocString](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)<br/>
[SysFreeString](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)

