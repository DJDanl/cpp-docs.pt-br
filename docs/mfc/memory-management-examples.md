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
ms.openlocfilehash: 0568b3abbcd5776eab4d0ab9748bcbcd79c2a84b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228603"
---
# <a name="memory-management-examples"></a>Gerenciamento de memória: exemplos

Este artigo descreve como o MFC executa alocações de quadros e alocações de heap para cada um dos três tipos típicos de alocações de memória:

- [Uma matriz de bytes](#_core_allocation_of_an_array_of_bytes)

- [Uma estrutura de dados](#_core_allocation_of_a_data_structure)

- [Um objeto](#_core_allocation_of_an_object)

## <a name="allocation-of-an-array-of-bytes"></a><a name="_core_allocation_of_an_array_of_bytes"></a>Alocação de uma matriz de bytes

#### <a name="to-allocate-an-array-of-bytes-on-the-frame"></a>Para alocar uma matriz de bytes no quadro

1. Defina a matriz conforme mostrado pelo código a seguir. A matriz é excluída automaticamente e sua memória recuperada quando a variável de matriz sai de seu escopo.

   [!code-cpp[NVC_MFC_Utilities#1](codesnippet/cpp/memory-management-examples_1.cpp)]

#### <a name="to-allocate-an-array-of-bytes-or-any-primitive-data-type-on-the-heap"></a>Para alocar uma matriz de bytes (ou qualquer tipo de dados primitivo) no heap

1. Use o **`new`** operador com a sintaxe de matriz mostrada neste exemplo:

   [!code-cpp[NVC_MFC_Utilities#2](codesnippet/cpp/memory-management-examples_2.cpp)]

#### <a name="to-deallocate-the-arrays-from-the-heap"></a>Para desalocar as matrizes do heap

1. Use o **`delete`** operador da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#3](codesnippet/cpp/memory-management-examples_3.cpp)]

## <a name="allocation-of-a-data-structure"></a><a name="_core_allocation_of_a_data_structure"></a>Alocação de uma estrutura de dados

#### <a name="to-allocate-a-data-structure-on-the-frame"></a>Para alocar uma estrutura de dados no quadro

1. Defina a variável de estrutura da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#4](codesnippet/cpp/memory-management-examples_4.cpp)]

   A memória ocupada pela estrutura é recuperada quando sai do seu escopo.

#### <a name="to-allocate-data-structures-on-the-heap"></a>Para alocar estruturas de dados no heap

1. Use **`new`** para alocar estruturas de dados no heap e **`delete`** desalocá-las, conforme mostrado pelos exemplos a seguir:

   [!code-cpp[NVC_MFC_Utilities#5](codesnippet/cpp/memory-management-examples_5.cpp)]

## <a name="allocation-of-an-object"></a><a name="_core_allocation_of_an_object"></a>Alocação de um objeto

#### <a name="to-allocate-an-object-on-the-frame"></a>Para alocar um objeto no quadro

1. Declare o objeto da seguinte maneira:

   [!code-cpp[NVC_MFC_Utilities#6](codesnippet/cpp/memory-management-examples_6.cpp)]

   O destruidor do objeto é invocado automaticamente quando o objeto sai do seu escopo.

#### <a name="to-allocate-an-object-on-the-heap"></a>Para alocar um objeto no heap

1. Use o **`new`** operador, que retorna um ponteiro para o objeto, para alocar objetos no heap. Use o **`delete`** operador para excluí-los.

   Os exemplos de heap e de quadro a seguir pressupõem que o `CPerson` Construtor não aceite nenhum argumento.

   [!code-cpp[NVC_MFC_Utilities#7](codesnippet/cpp/memory-management-examples_7.cpp)]

   Se o argumento para o `CPerson` Construtor for um ponteiro para **`char`** , a instrução para alocação de quadros será:

   [!code-cpp[NVC_MFC_Utilities#8](codesnippet/cpp/memory-management-examples_8.cpp)]

   A instrução para alocação de heap é:

   [!code-cpp[NVC_MFC_Utilities#9](codesnippet/cpp/memory-management-examples_9.cpp)]

## <a name="see-also"></a>Confira também

[Gerenciamento de memória: alocação de heap](memory-management-heap-allocation.md)
