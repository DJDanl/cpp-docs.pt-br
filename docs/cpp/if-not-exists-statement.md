---
title: Instrução __if_not_exists
ms.date: 11/04/2016
f1_keywords:
- __if_not_exists_cpp
helpviewer_keywords:
- __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
ms.openlocfilehash: 1118f9fcca525b2b2d5869fb507ee974d2b0d28f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374134"
---
# <a name="__if_not_exists-statement"></a>Instrução __if_not_exists

A **declaração __if_not_exists** testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_not_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Identificador*|O identificador cuja existência você deseja testar.|
|*Declarações*|Uma ou mais instruções para executar se *o identificador* não existe.|

## <a name="remarks"></a>Comentários

> [!CAUTION]
> Para obter os resultados mais confiáveis, use a **declaração __if_not_exists** sob as seguintes restrições.

- Aplique a **instrução __if_not_exists** apenas a tipos simples, não a modelos.

- Aplique a **__if_not_exists** declaração aos identificadores dentro ou fora de uma classe. Não aplique a **declaração __if_not_exists** às variáveis locais.

- Use a **__if_not_exists** declaração apenas no corpo de uma função. Fora do corpo de uma função, **a** __if_not_exists afirmação pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento da declaração **__if_not_exists** é a [declaração __if_exists.](../cpp/if-exists-statement.md)

## <a name="example"></a>Exemplo

Para obter um exemplo sobre como usar **__if_not_exists,** consulte [__if_exists Statement](../cpp/if-exists-statement.md).

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Declaração de __if_exists](../cpp/if-exists-statement.md)
