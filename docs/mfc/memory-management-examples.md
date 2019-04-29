---
title: 'Gerenciamento de memória: Exemplos'
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
ms.openlocfilehash: 5ed50bfba03f29fdd16e6f615b193109656f3ce6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352158"
---
# <a name="memory-management-examples"></a>Gerenciamento de memória: Exemplos

Este artigo descreve como o MFC realiza a alocações de quadro e alocações de heap para cada um dos três tipos típicos de alocações de memória:

- [Uma matriz de bytes](#_core_allocation_of_an_array_of_bytes)

- [Uma estrutura de dados](#_core_allocation_of_a_data_structure)

- [Um objeto](#_core_allocation_of_an_object)

##  <a name="_core_allocation_of_an_array_of_bytes"></a> Alocação de uma matriz de Bytes

#### <a name="to-allocate-an-array-of-bytes-on-the-frame"></a>Para alocar uma matriz de bytes no quadro

1. Defina a matriz, conforme mostrado pelo código a seguir. A matriz será excluída automaticamente e sua memória recuperada quando a variável de matriz é fechada seu escopo.

   [!code-cpp[NVC_MFC_Utilities#1](../mfc/codesnippet/cpp/memory-management-examples_1.cpp)]

#### <a name="to-allocate-an-array-of-bytes-or-any-primitive-data-type-on-the-heap"></a>Para alocar uma matriz de bytes (ou qualquer tipo de dados primitivo) no heap

1. Use o **novo** operador com a sintaxe de matriz mostrado neste exemplo:

   [!code-cpp[NVC_MFC_Utilities#2](../mfc/codesnippet/cpp/memory-management-examples_2.cpp)]

#### <a name="to-deallocate-the-arrays-from-the-heap"></a>Para desalocar as matrizes do heap

1. Use o **excluir** operador da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#3](../mfc/codesnippet/cpp/memory-management-examples_3.cpp)]

##  <a name="_core_allocation_of_a_data_structure"></a> Alocação de uma estrutura de dados

#### <a name="to-allocate-a-data-structure-on-the-frame"></a>Para alocar uma estrutura de dados no quadro

1. Defina a variável de estrutura, da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#4](../mfc/codesnippet/cpp/memory-management-examples_4.cpp)]

   A memória ocupada pela estrutura é recuperada quando ele sai de seu escopo.

#### <a name="to-allocate-data-structures-on-the-heap"></a>Para alocar estruturas de dados no heap

1. Use **novos** alocar estruturas de dados no heap e **excluir** desalocá-los, conforme mostrado pelos exemplos a seguir:

   [!code-cpp[NVC_MFC_Utilities#5](../mfc/codesnippet/cpp/memory-management-examples_5.cpp)]

##  <a name="_core_allocation_of_an_object"></a> Alocação de um objeto

#### <a name="to-allocate-an-object-on-the-frame"></a>Para alocar um objeto no quadro

1. Declare o objeto da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#6](../mfc/codesnippet/cpp/memory-management-examples_6.cpp)]

   O destruidor do objeto é invocado automaticamente quando o objeto é encerrado em seu escopo.

#### <a name="to-allocate-an-object-on-the-heap"></a>Para alocar um objeto no heap

1. Use o **novo** operador, que retorna um ponteiro para o objeto, para alocar objetos no heap. Use o **excluir** operador excluí-los.

   Os exemplos de heap e o quadro a seguir pressupõem que o `CPerson` construtor não usa nenhum argumento.

   [!code-cpp[NVC_MFC_Utilities#7](../mfc/codesnippet/cpp/memory-management-examples_7.cpp)]

   Se o argumento para o `CPerson` construtor é um ponteiro para **char**, a política de alocação do quadro está:

   [!code-cpp[NVC_MFC_Utilities#8](../mfc/codesnippet/cpp/memory-management-examples_8.cpp)]

   A instrução para alocação de heap é:

   [!code-cpp[NVC_MFC_Utilities#9](../mfc/codesnippet/cpp/memory-management-examples_9.cpp)]

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória: alocação de heap](../mfc/memory-management-heap-allocation.md)
