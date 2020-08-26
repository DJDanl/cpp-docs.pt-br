---
title: '&lt;limites&gt;'
ms.date: 11/04/2016
f1_keywords:
- limits/std::<limits>
- <limits>
helpviewer_keywords:
- limits header
ms.assetid: e07d6379-5b00-4a3d-a789-40d41538b59e
ms.openlocfilehash: 1527672bd51682bf32c82601ff54a94ea4154a0b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841903"
---
# <a name="ltlimitsgt"></a>&lt;limites&gt;

Define o modelo de classe `numeric_limits` e duas enumerações relacionadas a representações de ponto flutuante e arredondamento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<limits>

**Namespace:** std

## <a name="remarks"></a>Comentários

Especializações explícitas da `numeric_limits` classe descrevem muitas propriedades dos tipos fundamentais, incluindo o caractere, o inteiro e os tipos de ponto flutuante e **`bool`** que são definidos em vez de serem corrigidos pelas regras da linguagem C++. As propriedades descritas em \<limits> incluem precisão, representações de tamanho mínimo e máximo, arredondamento e erros de tipo de sinalização.

## <a name="members"></a>Membros

### <a name="enumerations"></a>Enumerações

|Nome|Descrição|
|-|-|
|[float_denorm_style](../standard-library/limits-enums.md#float_denorm_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para representar um valor de ponto flutuante desnormalizado — um pequeno demais para ser representado como um valor normalizado:|
|[float_round_style](../standard-library/limits-enums.md#float_round_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para fazer o arredondamento de um valor de ponto flutuante para um valor inteiro.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[Classe numeric_limits](../standard-library/numeric-limits-class.md)|O modelo de classe descreve as propriedades aritméticas de tipos numéricos internos.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
