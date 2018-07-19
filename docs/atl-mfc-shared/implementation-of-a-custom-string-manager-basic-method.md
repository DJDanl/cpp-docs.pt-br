---
title: Implementação de uma cadeia de caracteres Gerenciador de personalizada (método básico) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- IAtlStringMgr class, using
ms.assetid: eac5d13e-cbb4-4e82-b01e-f5f2dbcb962a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c393489b8b4d0353ae37a21132f66e0618b3b794
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37884578"
---
# <a name="implementation-of-a-custom-string-manager-basic-method"></a>Implementação de uma cadeia de caracteres Gerenciador de personalizada (método básico)
A maneira mais fácil de personalizar o esquema de alocação de memória para dados de cadeia de caracteres são usar a ATL fornecido pelo `CAtlStringMgr` classe, mas fornecer sua própria memória rotinas de alocação. O construtor `CAtlStringMgr` usa um único parâmetro: um ponteiro para um `IAtlMemMgr` objeto. `IAtlMemMgr` é uma classe base abstrata que fornece uma interface genérica para um heap. Usando o `IAtlMemMgr` interface, o `CAtlStringMgr` aloca realoca e libera a memória usada para armazenar dados de cadeia de caracteres. Você pode implementar o `IAtlMemMgr` interface por conta própria ou use um dos cinco classes de Gerenciador de memória fornecida pelo ATL. Os gerenciadores de memória fornecida pelo ATL simplesmente encapsulam os recursos existentes de alocação de memória:  
  
-   [CCRTHeap](../atl/reference/ccrtheap-class.md) encapsula as funções de heap de CRT padrão ([malloc](../c-runtime-library/reference/malloc.md), [livre](../c-runtime-library/reference/free.md), e [realloc](../c-runtime-library/reference/realloc.md))  
  
-   [CWin32Heap](../atl/reference/cwin32heap-class.md) encapsula lidar com um heap do Win32, usando [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597), [HeapFree](http://msdn.microsoft.com/library/windows/desktop/aa366701), e [HeapRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366704)  
  
-   [CLocalHeap](../atl/reference/clocalheap-class.md) encapsula as APIs do Win32: [LocalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366723), [LocalFree](http://msdn.microsoft.com/library/windows/desktop/aa366730), e [LocalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366742)  
  
-   [CGlobalHeap](../atl/reference/cglobalheap-class.md) encapsula as APIs do Win32: [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574), [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579), e [GlobalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366590).  
  
-   [CComHeap](../atl/reference/ccomheap-class.md) encapsula as APIs do alocador de tarefas COM: [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727), [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722), e [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280)  
  
 Para fins de gerenciamento de memória da cadeia de caracteres, a classe mais úteis é `CWin32Heap` porque ele permite que você crie diversos heaps independentes. Por exemplo, se você quisesse usar um heap separado apenas para cadeias de caracteres, você poderia fazer o seguinte:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#180](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_1.cpp)]  
  
 Para usar esse gerenciador de cadeia de caracteres privados para gerenciar a memória para um `CString` variável, passe um ponteiro para o Gerenciador de como um parâmetro para o `CString` construtor da variável:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#181](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

