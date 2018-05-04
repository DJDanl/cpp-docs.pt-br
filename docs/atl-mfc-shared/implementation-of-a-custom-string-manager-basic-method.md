---
title: Implementação um Gerenciador de personalizado cadeia de caracteres (método básico) | Microsoft Docs
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
ms.openlocfilehash: 259f9533747b266f0be0a782cdc94c98f167d2d2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="implementation-of-a-custom-string-manager-basic-method"></a>Implementação um Gerenciador de personalizado cadeia de caracteres (método básico)
A maneira mais fácil para personalizar o esquema de alocação de memória para dados de cadeia de caracteres usar o ATL fornecido **CAtlStringMgr** classe mas fornecer sua própria memória rotinas de alocação. O construtor para **CAtlStringMgr** usa um único parâmetro: um ponteiro para um `IAtlMemMgr` objeto. `IAtlMemMgr` é uma classe base abstrata que fornece uma interface genérica para um heap. Usando o `IAtlMemMgr` interface, o **CAtlStringMgr** aloca realoca e libera a memória usada para armazenar dados de cadeia de caracteres. Você pode ou implementar o `IAtlMemMgr` interface por conta própria, ou usar uma das classes de Gerenciador de memória fornecida ATL cinco. Os gerenciadores de memória fornecida ATL simplesmente encapsular recursos existentes de alocação de memória:  
  
-   [CCRTHeap](../atl/reference/ccrtheap-class.md) encapsula as funções de heap padrão do CRT ([malloc](../c-runtime-library/reference/malloc.md), [livre](../c-runtime-library/reference/free.md), e [realloc](../c-runtime-library/reference/realloc.md))  
  
-   [CWin32Heap](../atl/reference/cwin32heap-class.md) encapsula tratar de um heap Win32, usando [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597), [HeapFree](http://msdn.microsoft.com/library/windows/desktop/aa366701), e [HeapRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366704)  
  
-   [CLocalHeap](../atl/reference/clocalheap-class.md) encapsula as APIs do Win32: [LocalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366723), [LocalFree](http://msdn.microsoft.com/library/windows/desktop/aa366730), e [LocalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366742)  
  
-   [CGlobalHeap](../atl/reference/cglobalheap-class.md) encapsula as APIs do Win32: [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574), [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579), e [GlobalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366590).  
  
-   [CComHeap](../atl/reference/ccomheap-class.md) encapsula as APIs do alocador de tarefas COM: [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727), [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722), e [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280)  
  
 Para fins de gerenciamento de memória de cadeia de caracteres, a classe mais úteis é `CWin32Heap` porque ele permite que você criar várias pilhas independentes. Por exemplo, se você quiser usar um heap separado apenas para cadeias de caracteres, você pode fazer o seguinte:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#180](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_1.cpp)]  
  
 Para usar esse gerenciador de cadeia de caracteres privada para gerenciar a memória para um `CString` variável, passe um ponteiro para o Gerenciador de como um parâmetro para o `CString` construtor da variável:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#181](../atl-mfc-shared/codesnippet/cpp/implementation-of-a-custom-string-manager-basic-method_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

