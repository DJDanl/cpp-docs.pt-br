---
title: Gramática __based
ms.date: 11/04/2016
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
ms.openlocfilehash: 8dec9b0bcc7db25e2ec4c39b9d907922691bfc05
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393942"
---
# <a name="based-grammar"></a>Gramática __based

## <a name="microsoft-specific"></a>Específico da Microsoft

O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).

A única forma de endereçamento baseado aceitável em compilações de 32 bits e 64 bits é "com base em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou 64 bits a uma base de 32 bits ou 64 bits ou com base em **void**.

## <a name="grammar"></a>Gramática

*based-range-modifier*: **__based(**  *base-expression*  **)**

*base-expression*: *based-variablebased-abstract-declaratorsegment-namesegment-cast*

*variável com base na*: *identificador*

*based-abstract-declarator*: *abstract-declarator*

*base-type*: *type-name*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Ponteiros com base](../cpp/based-pointers-cpp.md)