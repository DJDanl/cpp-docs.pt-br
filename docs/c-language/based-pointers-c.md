---
title: Ponteiros baseados (C)
ms.date: 11/04/2016
helpviewer_keywords:
- __based keyword [C]
- based pointers
- pointers, based
- based addressing
ms.assetid: b5446920-89e0-4e2f-91f3-1f2a769a08e8
ms.openlocfilehash: d1ef1ec98d718e408621f5303e809d09020d5719
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87190241"
---
# <a name="based-pointers-c"></a>Ponteiros baseados (C)

**Específico da Microsoft**

[__based (referência do C++)](../cpp/based-pointers-cpp.md)

Para os compiladores C de 32 bits e de 64 bits da Microsoft, um ponteiro baseado é um deslocamento de 32 bits ou de 64 bits a partir de um base de ponteiro de 32 bits ou de 64 bits. O endereçamento baseado é útil para controlar as seções nas quais os objetos são alocados, diminuindo assim o tamanho do arquivo executável e aumentando a velocidade de execução. Em geral, o formato para especificar um ponteiro baseado é

> *Declarador* de *tipo* **__based (** *base* **)**

A variante "ponteiro de base" do endereçamento baseado permite especifica um ponteiro como base. O ponteiro baseado, portanto, é um deslocamento para a seção de memória que começa no início do ponteiro no qual ele é baseado. Ponteiros baseados em endereços de ponteiro são a única forma da **`__based`** palavra-chave válida em compilações de 32 bits e 64 bits. Nessas compilações, ele são deslocamentos de 32 bits ou de 64 bits a partir de uma base de 32 bits ou de 64 bits.

Um uso para ponteiros baseados em ponteiros é para identificadores persistentes que contêm ponteiros. Uma lista vinculada que consiste em ponteiros baseados em um ponteiro pode ser salva em disco e depois ser recarregada em outro local na memória, com os ponteiros permanecendo válidos.

O exemplo a seguir mostra um ponteiro com base em um ponteiro.

```C
void *vpBuffer;

struct llist_t
{
    void __based( vpBuffer ) *vpData;
    struct llist_t __based( vpBuffer ) *llNext;
};
```

O ponteiro `vpBuffer` é atribuído ao endereço da memória alocada em algum momento posterior no programa. A lista vinculada é realocada em relação ao valor de `vpBuffer`.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declaradores e declarações de variáveis](../c-language/declarators-and-variable-declarations.md)
