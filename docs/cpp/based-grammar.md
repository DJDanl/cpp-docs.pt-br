---
title: Gramática __based
ms.date: 11/04/2016
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
ms.openlocfilehash: a8c923b5a111144c539b5bea1b2f47eb58dd1fbd
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857639"
---
# <a name="__based-grammar"></a>Gramática __based

**Seção específica da Microsoft**

O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).

A única forma de endereçamento com base aceitável em compilações de 32 bits e 64 bits é "baseada em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou de 64 bits para uma base de 32 bits ou de 64 bits ou com base em **void**.

## <a name="grammar"></a>Gramática

*based-range-modifier*: **__based(**  *base-expression*  **)**

*base-expression*: *based-variablebased-abstract-declaratorsegment-namesegment-cast*

*variável com base*: *identificador*

*based-abstract-declarator*: *abstract-declarator*

*tipo base*: *tipo-nome*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Ponteiros com base](../cpp/based-pointers-cpp.md)