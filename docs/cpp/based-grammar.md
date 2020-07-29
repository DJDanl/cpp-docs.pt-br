---
title: Gramática __based
ms.date: 11/04/2016
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
ms.openlocfilehash: 539ccef65477bafe2c46ce328bdaf65f52aff1b9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229149"
---
# <a name="__based-grammar"></a>Gramática __based

**Específico da Microsoft**

O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).

A única forma de endereçamento com base aceitável em compilações de 32 bits e 64 bits é "baseada em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou de 64 bits para uma base de 32 bits ou de 64 bits ou com base em **`void`** .

## <a name="grammar"></a>Gramática

*com base em intervalo-modificador*: **__based (**  *expressão base*  **)**

*expressão base*: *com base em variablebased-abstract-declaratorsegment-namesegment-Cast*

*variável com base*: *identificador*

*based-abstract-declarator*: *abstract-declarator*

*tipo base*: *tipo-nome*

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Ponteiros baseados](../cpp/based-pointers-cpp.md)
