---
title: '&lt;limites&gt;'
ms.date: 11/04/2016
f1_keywords:
- limits/std::<limits>
- <limits>
helpviewer_keywords:
- limits header
ms.assetid: e07d6379-5b00-4a3d-a789-40d41538b59e
ms.openlocfilehash: c029095d5298048874a7eb6f1a41209d6a6f4779
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413236"
---
# <a name="ltlimitsgt"></a>&lt;limites&gt;

Define a classe de modelo `numeric_limits` e duas enumerações relacionadas a representações de pontos flutuantes e arredondamento.

## <a name="syntax"></a>Sintaxe

```cpp
#include <limits>
```

## <a name="remarks"></a>Comentários

Especializações explícitas a `numeric_limits` classe descrevem muitas propriedades dos tipos fundamentais, incluindo o caractere, inteiro e tipos de ponto flutuante e **bool** que são implementação definida e não fixados pelas as regras da linguagem C++. Propriedades descritas em \<limits> incluem precisão, representações de tamanho mínimo e máximo, arredondamento e erros de tipo de sinalização.

### <a name="enumerations"></a>Enumerações

|||
|-|-|
|[float_denorm_style](../standard-library/limits-enums.md#float_denorm_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para representar um valor de ponto flutuante desnormalizado — um pequeno demais para ser representado como um valor normalizado:|
|[float_round_style](../standard-library/limits-enums.md#float_round_style)|A enumeração descreve os vários métodos que uma implementação pode escolher para fazer o arredondamento de um valor de ponto flutuante para um valor inteiro.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe numeric_limits](../standard-library/numeric-limits-class.md)|A classe de modelo descreve propriedades aritméticas de tipos numéricos internos.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
