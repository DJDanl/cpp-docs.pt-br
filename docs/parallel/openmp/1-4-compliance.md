---
title: 1.4 conformidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 662ad260-b9a1-43b7-b269-ef6ff0714e05
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1a332d8fb5de172c363c6f9c1bebba65d6fa0ff8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381810"
---
# <a name="14-compliance"></a>1.4 Conformidade

É uma implementação da API de C/C++ do OpenMP *compatível com o OpenMP* se ele reconhece e preserva a semântica de todos os elementos dessa especificação, conforme dispostos em capítulos 1, 2, 3, 4, e o Apêndice C. apêndices A, B, D, E e F destinam-se informações fins apenas e não fazem parte da especificação. Implementações que incluam somente um subconjunto da API não são compatíveis com o OpenMP.

O OpenMP C e C++ API é uma extensão para o idioma base que é compatível com uma implementação. Se o idioma base não oferece suporte a um constructo de linguagem ou a extensão que aparece neste documento, a implementação de OpenMP não é necessário para dar suporte a ele.

Todas as funções da biblioteca C e C++ padrão e funções internas (ou seja, funções das quais o compilador não tem conhecimento específico) deve ser thread-safe. Uso não sincronizado de funções thread-safe por threads diferentes dentro de uma região paralela não produz um comportamento indefinido. No entanto, o comportamento não pode ser igual uma região de serial. (É um exemplo de uma função de geração de número aleatório.)

A API de C/C++ do OpenMP Especifica que determinado comportamento *definido pela implementação.* Uma implementação em conformidade do OpenMP é necessária para definir e documentar seu comportamento nesses casos. Ver [Apêndice E](../../parallel/openmp/e-implementation-defined-behaviors-in-openmp-c-cpp.md), página 97, para obter uma lista de comportamentos definidos por implementação.