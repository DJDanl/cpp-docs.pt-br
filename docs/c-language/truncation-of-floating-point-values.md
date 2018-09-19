---
title: Truncamento de valores de ponto flutuante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- floating-point numbers, truncation
ms.assetid: 051a6e22-c636-4af8-9ac4-40160f4affca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b30700b52e7cbbbc295d6050b03283b4b45a0b08
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103809"
---
# <a name="truncation-of-floating-point-values"></a>Truncamento de valores de ponto flutuante

**ANSI 3.2.1.4** A direção de truncamento ou arredondamento quando um número de ponto flutuante é convertido em um número de ponto flutuante mais restrito

Quando ocorre um estouro negativo, o valor de uma variável de ponto flutuante é arredondado para zero. Um estouro pode causar um erro de tempo de execução ou pode gerar um valor imprevisível, dependendo das otimizações especificadas.

## <a name="see-also"></a>Consulte também

[Matemática de ponto flutuante](../c-language/floating-point-math.md)