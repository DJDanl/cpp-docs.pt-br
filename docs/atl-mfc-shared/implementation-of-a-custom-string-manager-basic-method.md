---
title: Implementação de uma cadeia de caracteres Gerenciador de personalizada (método básico)
ms.date: 11/04/2016
helpviewer_keywords:
- IAtlStringMgr class, using
ms.assetid: eac5d13e-cbb4-4e82-b01e-f5f2dbcb962a
ms.openlocfilehash: c30c08217a09f600f8801bec9f50c4341e983a6b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62235889"
---
# <a name="implementation-of-a-custom-string-manager-basic-method"></a>Implementação de uma cadeia de caracteres Gerenciador de personalizada (método básico)

A maneira mais fácil de personalizar o esquema de alocação de memória para dados de cadeia de caracteres são usar a ATL fornecido pelo `CAtlStringMgr` classe, mas fornecer sua própria memória rotinas de alocação. O construtor `CAtlStringMgr` usa um único parâmetro: um ponteiro para um `IAtlMemMgr` objeto. `IAtlMemMgr` é uma classe base abstrata que fornece uma interface genérica para um heap. Usando o `IAtlMemMgr` interface, o `CAtlStringMgr` aloca realoca e libera a memória usada para armazenar dados de cadeia de caracteres. Você pode implementar o `IAtlMemMgr` interface por conta própria ou use um dos cinco classes de Gerenciador de memória fornecida pelo ATL. Os gerenciadores de memória fornecida pelo ATL simplesmente encapsulam os recursos existentes de alocação de memória:

- [CCRTHeap](../atl/reference/ccrtheap-class.md) encapsula as funções de heap de CRT padrão ([malloc](../c-runtime-library/reference/malloc.md), [livre](../c-runtime-library/reference/free.md), e [realloc](../c-runtime-library/reference/realloc.md))

- [CWin32Heap](../atl/reference/cwin32heap-class.md) encapsula lidar com um heap do Win32, usando [HeapAlloc](/windows/desktop/api/heapapi/nf-heapapi-heapalloc), [HeapFree](/windows/desktop/api/heapapi/nf-heapapi-heapfree), e [HeapRealloc](/windows/desktop/api/heapapi/nf-heapapi-heaprealloc)

- [CLocalHeap](../atl/reference/clocalheap-class.md) encapsula as APIs do Win32: [LocalAlloc](/windows/desktop/api/winbase/nf-winbase-localalloc), [LocalFree](/windows/desktop/api/winbase/nf-winbase-localfree), e [LocalRealloc](/windows/desktop/api/winbase/nf-winbase-localrealloc)

- [CGlobalHeap](../atl/reference/cglobalheap-class.md) encapsula as APIs do Win32: [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc), [GlobalFree](/windows/desktop/api/winbase/nf-winbase-globalfree), e [GlobalRealloc](/windows/desktop/api/winbase/nf-winbase-globalrealloc).

- [CComHeap](../atl/reference/ccomheap-class.md) encapsula as APIs do alocador de tarefas COM: [CoTaskMemAlloc](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), [CoTaskMemFree](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree), e [CoTaskMemRealloc](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemrealloc)

Para fins de gerenciamento de memória da cadeia de caracteres, a classe mais úteis é `CWin32Heap` porque ele permite que você crie diversos heaps independentes. Por exemplo, se você quisesse usar um heap separado apenas para cadeias de caracteres, você poderia fazer o seguinte:

[!code-cpp[NVC_ATLMFC_Utilities#180](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_1.cpp)]

Para usar esse gerenciador de cadeia de caracteres privados para gerenciar a memória para um `CString` variável, passe um ponteiro para o Gerenciador de como um parâmetro para o `CString` construtor da variável:

[!code-cpp[NVC_ATLMFC_Utilities#181](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_2.cpp)]

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)
