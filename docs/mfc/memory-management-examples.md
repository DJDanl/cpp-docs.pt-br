---
title: 'Gerenciamento de memória: exemplos'
ms.date: 11/04/2016
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
ms.openlocfilehash: 3a1e647175b7b5294e672efbf234e3ae2853e411
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367842"
---
# <a name="memory-management-examples"></a>Gerenciamento de memória: exemplos

Este artigo descreve como o MFC executa alocações de quadros e alocações de pilhas para cada um dos três tipos típicos de alocação de memória:

- [Uma matriz de bytes](#_core_allocation_of_an_array_of_bytes)

- [Uma estrutura de dados](#_core_allocation_of_a_data_structure)

- [Um objeto](#_core_allocation_of_an_object)

## <a name="allocation-of-an-array-of-bytes"></a><a name="_core_allocation_of_an_array_of_bytes"></a>Alocação de uma matriz de bytes

#### <a name="to-allocate-an-array-of-bytes-on-the-frame"></a>Para alocar uma matriz de bytes no quadro

1. Defina a matriz conforme mostrado pelo código a seguir. O array é automaticamente excluído e sua memória recuperada quando a variável matriz sai de seu escopo.

   [!code-cpp[NVC_MFC_Utilities#1](../mfc/codesnippet/cpp/memory-management-examples_1.cpp)]

#### <a name="to-allocate-an-array-of-bytes-or-any-primitive-data-type-on-the-heap"></a>Para alocar uma matriz de bytes (ou qualquer tipo de dados primitivo) no heap

1. Use o **novo** operador com a sintaxe de matriz mostrada neste exemplo:

   [!code-cpp[NVC_MFC_Utilities#2](../mfc/codesnippet/cpp/memory-management-examples_2.cpp)]

#### <a name="to-deallocate-the-arrays-from-the-heap"></a>Para desalocar as matrizes do heap

1. Use o operador **de exclusão** da seguinte forma:

   [!code-cpp[NVC_MFC_Utilities#3](../mfc/codesnippet/cpp/memory-management-examples_3.cpp)]

## <a name="allocation-of-a-data-structure"></a><a name="_core_allocation_of_a_data_structure"></a>Alocação de uma Estrutura de Dados

#### <a name="to-allocate-a-data-structure-on-the-frame"></a>Para alocar uma estrutura de dados no quadro

1. Defina a variável de estrutura da seguinte forma:

   [!code-cpp[NVC_MFC_Utilities#4](../mfc/codesnippet/cpp/memory-management-examples_4.cpp)]

   A memória ocupada pela estrutura é recuperada quando sai de seu escopo.

#### <a name="to-allocate-data-structures-on-the-heap"></a>Para alocar estruturas de dados no heap

1. Use **novas** para alocar estruturas de dados no heap e **excluí-las** para desalocá-las, como mostrado pelos seguintes exemplos:

   [!code-cpp[NVC_MFC_Utilities#5](../mfc/codesnippet/cpp/memory-management-examples_5.cpp)]

## <a name="allocation-of-an-object"></a><a name="_core_allocation_of_an_object"></a>Alocação de um objeto

#### <a name="to-allocate-an-object-on-the-frame"></a>Para alocar um objeto no quadro

1. Declare o objeto da seguinte forma:

   [!code-cpp[NVC_MFC_Utilities#6](../mfc/codesnippet/cpp/memory-management-examples_6.cpp)]

   O destruidor do objeto é automaticamente invocado quando o objeto sai do escopo.

#### <a name="to-allocate-an-object-on-the-heap"></a>Para alocar um objeto no monte

1. Use o **novo** operador, que retorna um ponteiro para o objeto, para alocar objetos no heap. Use o operador **de exclusão** para excluí-los.

   Os exemplos a seguir assumem `CPerson` que o construtor não aceita argumentos.

   [!code-cpp[NVC_MFC_Utilities#7](../mfc/codesnippet/cpp/memory-management-examples_7.cpp)]

   Se o argumento `CPerson` para o construtor for um ponteiro para **char,** a declaração para alocação de quadros é:

   [!code-cpp[NVC_MFC_Utilities#8](../mfc/codesnippet/cpp/memory-management-examples_8.cpp)]

   A declaração para alocação de pilhas é:

   [!code-cpp[NVC_MFC_Utilities#9](../mfc/codesnippet/cpp/memory-management-examples_9.cpp)]

## <a name="see-also"></a>Confira também

[Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)
