---
title: Gramática __based
ms.date: 11/04/2016
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
ms.openlocfilehash: 149439c82780f12669e5a3180f975c573ed30422
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181402"
---
# <a name="__based-grammar"></a>Gramática __based

**Seção específica da Microsoft**

O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).

A única forma de endereçamento com base aceitável em compilações de 32 bits e 64 bits é "baseada em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou de 64 bits para uma base de 32 bits ou de 64 bits ou com base em **void**.

## <a name="grammar"></a>Gramática

*com base em intervalo-modificador*: **__based (**  *expressão base*  **)**

*expressão base*: *com base em variablebased-abstract-declaratorsegment-namesegment-Cast*

*variável com base*: *identificador*

*based-abstract-declarator*: *abstract-declarator*

*tipo base*: *tipo-nome*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Ponteiros com base](../cpp/based-pointers-cpp.md)
