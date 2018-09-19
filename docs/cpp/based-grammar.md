---
title: gramática based | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43e9074de25d8cb914432123478f5f338ff4ba1e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103757"
---
# <a name="based-grammar"></a>Gramática __based

## <a name="microsoft-specific"></a>Específico da Microsoft

O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).

A única forma de endereçamento baseado aceitável em compilações de 32 bits e 64 bits é "com base em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou 64 bits a uma base de 32 bits ou 64 bits ou com base em **void**.

## <a name="grammar"></a>Gramática

*com base-intervalo-modifier*: **based (***expressão base***)** 

*expressão de base*: *based-variablebased-abstract-declaratorsegment-namesegment-cast*

*variável com base na*: *identificador*

*com base-abstract-declarator*: *abstract-declarator&lt;1}{2&gt;opt&lt;2*

*tipo base*: *nome do tipo*

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Ponteiros com base](../cpp/based-pointers-cpp.md)