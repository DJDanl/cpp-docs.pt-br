---
title: 'Gerenciamento de memória: Exemplos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- objects [MFC], memory allocation
- data structures [MFC]
- arrays [MFC], allocating resources
- objects [MFC], allocating memory
- data structures [MFC], allocating memory
- examples [MFC], memory allocation
- heap allocation [MFC], examples
- memory allocation [MFC], arrays
- MFC, memory management
- struct memory allocation [MFC]
- types [MFC], memory allocation
- memory allocation [MFC], objects
- memory allocation [MFC], examples
- arrays [MFC], memory management
- frame allocation [MFC]
- memory allocation [MFC], data structures
ms.assetid: f10240f8-b698-4c83-9288-97a54318930b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 84bc2ce7c084f2951d63eee546df3bf70a2ba1fe
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="memory-management-examples"></a>Gerenciamento de memória: exemplos
Este artigo descreve como o MFC executa alocações de quadro e as alocações de heap para cada um dos três tipos típicos de alocações de memória:  
  
-   [Uma matriz de bytes](#_core_allocation_of_an_array_of_bytes)  
  
-   [Uma estrutura de dados](#_core_allocation_of_a_data_structure)  
  
-   [Um objeto](#_core_allocation_of_an_object)  
  
##  <a name="_core_allocation_of_an_array_of_bytes"></a> Alocação de uma matriz de Bytes  
  
#### <a name="to-allocate-an-array-of-bytes-on-the-frame"></a>Para alocar uma matriz de bytes no quadro  
  
1.  Defina a matriz, conforme mostrado pelo código a seguir. A matriz é excluída automaticamente e sua memória recuperada quando a variável de matriz sair do seu escopo.  
  
     [!code-cpp[NVC_MFC_Utilities#1](../mfc/codesnippet/cpp/memory-management-examples_1.cpp)]  
  
#### <a name="to-allocate-an-array-of-bytes-or-any-primitive-data-type-on-the-heap"></a>Para alocar uma matriz de bytes (ou qualquer tipo de dados primitivos) na pilha  
  
1.  Use o **novo** operador com a sintaxe de matriz mostrado neste exemplo:  
  
     [!code-cpp[NVC_MFC_Utilities#2](../mfc/codesnippet/cpp/memory-management-examples_2.cpp)]  
  
#### <a name="to-deallocate-the-arrays-from-the-heap"></a>Para desalocar as matrizes de heap  
  
1.  Use o **excluir** operador da seguinte maneira:  
  
     [!code-cpp[NVC_MFC_Utilities#3](../mfc/codesnippet/cpp/memory-management-examples_3.cpp)]  
  
##  <a name="_core_allocation_of_a_data_structure"></a> Alocação de uma estrutura de dados  
  
#### <a name="to-allocate-a-data-structure-on-the-frame"></a>Para alocar uma estrutura de dados no quadro  
  
1.  Defina a variável de estrutura da seguinte maneira:  
  
     [!code-cpp[NVC_MFC_Utilities#4](../mfc/codesnippet/cpp/memory-management-examples_4.cpp)]  
  
     A memória ocupada pela estrutura é recuperada quando ele sai de seu escopo.  
  
#### <a name="to-allocate-data-structures-on-the-heap"></a>Para alocar estruturas de dados no heap  
  
1.  Use **novo** alocar estruturas de dados no heap e **excluir** desalocá-los, conforme mostrado nos exemplos a seguir:  
  
     [!code-cpp[NVC_MFC_Utilities#5](../mfc/codesnippet/cpp/memory-management-examples_5.cpp)]  
  
##  <a name="_core_allocation_of_an_object"></a> Alocação de um objeto  
  
#### <a name="to-allocate-an-object-on-the-frame"></a>Para alocar um objeto no quadro  
  
1.  Declare o objeto da seguinte maneira:  
  
     [!code-cpp[NVC_MFC_Utilities#6](../mfc/codesnippet/cpp/memory-management-examples_6.cpp)]  
  
     O destruidor para o objeto é invocado automaticamente quando o objeto sai do seu escopo.  
  
#### <a name="to-allocate-an-object-on-the-heap"></a>Para alocar um objeto no heap  
  
1.  Use o **novo** operador, que retorna um ponteiro para o objeto, alocar objetos no heap. Use o **excluir** operador para excluí-los.  
  
     Os exemplos de heap e o quadro a seguir presumem que o `CPerson` construtor não aceita nenhum argumento.  
  
     [!code-cpp[NVC_MFC_Utilities#7](../mfc/codesnippet/cpp/memory-management-examples_7.cpp)]  
  
     Se o argumento para o `CPerson` construtor é um ponteiro para `char`, a instrução para alocação de quadro é:  
  
     [!code-cpp[NVC_MFC_Utilities#8](../mfc/codesnippet/cpp/memory-management-examples_8.cpp)]  
  
     A instrução para alocação de heap é:  
  
     [!code-cpp[NVC_MFC_Utilities#9](../mfc/codesnippet/cpp/memory-management-examples_9.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)

