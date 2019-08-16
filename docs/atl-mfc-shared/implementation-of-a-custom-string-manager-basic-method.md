---
title: Implementação de um Gerenciador de cadeia de caracteres personalizado (método básico)
ms.date: 11/04/2016
helpviewer_keywords:
- IAtlStringMgr class, using
ms.assetid: eac5d13e-cbb4-4e82-b01e-f5f2dbcb962a
ms.openlocfilehash: 92c1c46f5251980f9cefb55e052e9aff395e0e60
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491308"
---
# <a name="implementation-of-a-custom-string-manager-basic-method"></a>Implementação de um Gerenciador de cadeia de caracteres personalizado (método básico)

A maneira mais fácil de personalizar o esquema de alocação de memória para dados de cadeia de caracteres é usar `CAtlStringMgr` a classe fornecida pela ATL, mas fornecer suas próprias rotinas de alocação de memória. O construtor para `CAtlStringMgr` usa um único parâmetro: um ponteiro para um `IAtlMemMgr` objeto. `IAtlMemMgr`é uma classe base abstrata que fornece uma interface genérica para um heap. Usando a `IAtlMemMgr` interface, o `CAtlStringMgr` aloca, realoca e libera a memória usada para armazenar dados de cadeia de caracteres. Você pode implementar a `IAtlMemMgr` interface por conta própria ou usar uma das cinco classes de Gerenciador de memória fornecidas pela ATL. Os gerenciadores de memória fornecidos pela ATL simplesmente encapsulam os recursos de alocação de memória existentes:

- [CCRTHeap](../atl/reference/ccrtheap-class.md) Encapsula as funções de heap padrão do CRT ([malloc](../c-runtime-library/reference/malloc.md), [Free](../c-runtime-library/reference/free.md)e [realloc](../c-runtime-library/reference/realloc.md))

- [CWin32Heap](../atl/reference/cwin32heap-class.md) Encapsula um identificador de heap do Win32, usando [HeapAlloc](/windows/win32/api/heapapi/nf-heapapi-heapalloc), [HeapFree](/windows/win32/api/heapapi/nf-heapapi-heapfree)e [HeapReAlloc](/windows/win32/api/heapapi/nf-heapapi-heaprealloc)

- [CLocalHeap](../atl/reference/clocalheap-class.md) Encapsula as APIs do Win32: [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc), [LocalFree](/windows/win32/api/winbase/nf-winbase-localfree)e [LocalReAlloc](/windows/win32/api/winbase/nf-winbase-localrealloc)

- [CGlobalHeap](../atl/reference/cglobalheap-class.md) Encapsula as APIs do Win32: [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc), [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree)e [GlobalRealloc](/windows/win32/api/winbase/nf-winbase-globalrealloc).

- [CComHeap](../atl/reference/ccomheap-class.md) Encapsula as APIs de alocador de tarefa COM: [CoTaskMemAlloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc), [CoTaskMemFree](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree)e [CoTaskMemRealloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemrealloc)

Para fins de gerenciamento de memória de cadeia de caracteres, a classe `CWin32Heap` mais útil é porque permite que você crie vários heaps independentes. Por exemplo, se você quisesse usar um heap separado apenas para cadeias de caracteres, você pode fazer o seguinte:

[!code-cpp[NVC_ATLMFC_Utilities#180](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_1.cpp)]

Para usar esse Gerenciador de cadeia de caracteres particular para gerenciar `CString` a memória de uma variável, passe um ponteiro para o Gerenciador como `CString` um parâmetro para o construtor da variável:

[!code-cpp[NVC_ATLMFC_Utilities#181](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_2.cpp)]

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)
