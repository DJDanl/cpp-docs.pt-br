---
title: '&lt;limites&gt;'
ms.date: 11/04/2016
f1_keywords:
- limits/std::<limits>
- <limits>
helpviewer_keywords:
- limits header
ms.assetid: e07d6379-5b00-4a3d-a789-40d41538b59e
ms.openlocfilehash: 3ad740975cfff4f65f9e1c800a709cfaca3367db
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687815"
---
# <a name="ltlimitsgt"></a>&lt;limites&gt;

Define o modelo de classe `numeric_limits` e duas enumerações relacionadas a representações de ponto flutuante e arredondamento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<limits>

**Namespace:** std

## <a name="remarks"></a>Comentários

Especializações explícitas da classe `numeric_limits` descrevem muitas propriedades dos tipos fundamentais, incluindo o caractere, o inteiro e os tipos de ponto flutuante e **bool** que são definidos em vez de serem corrigidos pelas regras do C++ idioma. Propriedades descritas em \<limits> incluem precisão, representações de tamanho mínimo e máximo, arredondamento e erros de tipo de sinalização.

## <a name="members"></a>Membros

### <a name="enumerations"></a>Enumerações

|||
|-|-|
|[float_denorm_style](../standard-library/limits-enums.md#float_denorm_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para representar um valor de ponto flutuante desnormalizado — um pequeno demais para ser representado como um valor normalizado:|
|[float_round_style](../standard-library/limits-enums.md#float_round_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para fazer o arredondamento de um valor de ponto flutuante para um valor inteiro.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe numeric_limits](../standard-library/numeric-limits-class.md)|O modelo de classe descreve as propriedades aritméticas de tipos numéricos internos.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
