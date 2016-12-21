---
title: "Implementa&#231;&#227;o de um gerente personalizado de cadeia de caracteres (b&#225;sico m&#233;todo) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IAtlStringMgr, Usando"
ms.assetid: eac5d13e-cbb4-4e82-b01e-f5f2dbcb962a
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementa&#231;&#227;o de um gerente personalizado de cadeia de caracteres (b&#225;sico m&#233;todo)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira mais fácil para personalizar o esquema de alocação de memória para dados de cadeia de caracteres é usar ATL\- forneceu a classe de **CAtlStringMgr** mas fornece seu próprio rotinas de alocação de memória.  O construtor para **CAtlStringMgr** aceita um único parâmetro: um ponteiro para um objeto de `IAtlMemMgr` .  `IAtlMemMgr` é uma classe base abstrata que fornece uma interface genérica a um heap.  Usando a interface de `IAtlMemMgr` , **CAtlStringMgr** atributos, realoca, e libera memória usada para armazenar dados de cadeia de caracteres.  Ou você pode implementar a interface de `IAtlMemMgr` você mesmo, ou use um dos cinco ATL\- forneceu classes gerente de memória.  ATL\- forneceu recursos existentes de alocação de memória de quebra automática de gerentes de memória simplesmente:  
  
-   [CCRTHeap](../atl/reference/ccrtheap-class.md) Envolve as funções do heap de CRT de padrão \([malloc](../c-runtime-library/reference/malloc.md), [livre](../c-runtime-library/reference/free.md), e [realloc](../c-runtime-library/reference/realloc.md)\)  
  
-   [CWin32Heap](../atl/reference/cwin32heap-class.md) Envolve um identificador do heap do Win32, usando [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597), [HeapFree](http://msdn.microsoft.com/library/windows/desktop/aa366701), e [HeapRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366704)  
  
-   [CLocalHeap](../atl/reference/clocalheap-class.md) Envolve APIs do Win32: [LocalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366723), [LocalFree](http://msdn.microsoft.com/library/windows/desktop/aa366730), e [LocalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366742)  
  
-   [CGlobalHeap](../atl/reference/cglobalheap-class.md) Envolve APIs do Win32: [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574), [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579), e [GlobalRealloc](http://msdn.microsoft.com/library/windows/desktop/aa366590).  
  
-   [CComHeap](../atl/reference/ccomheap-class.md) Envolve APIs do distribuidor de tarefa COM: [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727), [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722), e [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280)  
  
 Com o objetivo de gerenciamento de memória de cadeia de caracteres, a classe mais útil é `CWin32Heap` porque ela permite que você crie heaps independente de múltiplos.  Por exemplo, se você quisesse usar um heap separado apenas para cadeias de caracteres, você pode fazer o seguinte:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#180](../atl-mfc-shared/codesnippet/CPP/implementation-of-a-custom-string-manager-basic-method_1.cpp)]  
  
 Para usar o gerenciador particular de cadeia de caracteres para gerenciar a memória para um variável de `CString` , passe um ponteiro para o gerenciador como um parâmetro para o construtor da variável de `CString` :  
  
 [!code-cpp[NVC_ATLMFC_Utilities#181](../atl-mfc-shared/codesnippet/CPP/implementation-of-a-custom-string-manager-basic-method_2.cpp)]  
  
## Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)