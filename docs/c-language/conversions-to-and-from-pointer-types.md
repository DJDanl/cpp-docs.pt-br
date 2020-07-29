---
title: Conversões em e de tipos de ponteiro
ms.date: 11/04/2016
helpviewer_keywords:
- pointers, converting
- conversions, pointer
- type casts, involving pointers
- void pointers
ms.assetid: 3facc56f-06d3-4570-b1a2-7d4927b83086
ms.openlocfilehash: 6358216e72f054becf33d18aadb6a3a51bab8363
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218891"
---
# <a name="conversions-to-and-from-pointer-types"></a>Conversões em e de tipos de ponteiro

Um ponteiro para um tipo de valor que pode ser convertido em um ponteiro para um tipo diferente. No entanto, o resultado pode ser indefinido devido aos requisitos de alinhamento e aos tamanhos de tipos diferentes em armazenamento. Um ponteiro para um objeto pode ser convertido em um ponteiro para um objeto cujo tipo exige menos alinhamento de armazenamento ou igualmente restrito, e reconverter sem modificação.

Um ponteiro para **`void`** pode ser convertido de ou para um ponteiro para qualquer tipo, sem restrição ou perda de informações. Se o resultado for reconvertido no tipo original, o ponteiro original será recuperado.

Se um ponteiro é convertido em outro ponteiro do mesmo tipo, mas com qualificadores diferentes ou adicionais, o novo ponteiro é o mesmo que o antigo, com a exceção das restrições impostas pelo novo qualificador.

Um valor de ponteiro pode ser convertido em um valor integral. O caminho de conversão depende do tamanho do ponteiro e do tamanho do tipo integral, de acordo com as seguintes regras:

- Se o tamanho do ponteiro for maior ou igual ao tamanho do tipo integral, o ponteiro se comportará como um valor sem sinal na conversão, mas não poderá ser convertido em um valor flutuante.

- Se o ponteiro for menor que o tipo integral, o ponteiro primeiro será convertido em um ponteiro do mesmo tamanho do tipo integral, e depois convertido no tipo integral.

Inversamente, um tipo integral pode ser convertido em um tipo de ponteiro de acordo com as seguintes regras:

- Se o tipo integral for do mesmo tamanho que o tipo de ponteiro, a conversão faz com que o valor integral seja tratado como um ponteiro (um número inteiro sem sinal).

- Se o tamanho do tipo integral for diferente do tamanho do tipo de ponteiro, o tipo integral é convertido primeiro no tamanho do ponteiro, usando os caminhos de conversão fornecidos nas tabelas [Conversão de tipos integrais com sinal](../c-language/conversions-from-signed-integral-types.md) e [Conversão de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md). Depois é tratado como um valor do ponteiro.

Uma expressão constante integral com valor 0 ou tal conversão de expressão para tipo **`void`** <strong>\*</strong> pode ser convertida por uma conversão de tipo, por atribuição ou por comparação a um ponteiro de qualquer tipo. Isso gera um ponteiro nulo que é igual a outro ponteiro nulo do mesmo tipo, mas esse ponteiro nulo não é igual a nenhum ponteiro para uma função ou a um objeto. Os números inteiros diferentes da constante 0 podem ser convertidos no tipo de ponteiro, mas o resultado não é portátil.

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
