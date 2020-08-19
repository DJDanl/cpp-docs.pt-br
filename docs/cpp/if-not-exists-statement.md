---
title: Instrução __if_not_exists
ms.date: 11/04/2016
f1_keywords:
- __if_not_exists_cpp
helpviewer_keywords:
- __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
ms.openlocfilehash: e99fcee440bd69eabafec693df99d347f3aee828
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560277"
---
# <a name="__if_not_exists-statement"></a>Instrução __if_not_exists

A **`__if_not_exists`** instrução testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_not_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>Parâmetros

*ID*\
O identificador cuja existência você deseja testar.

*instruções*\
Uma ou mais instruções a serem executadas se o *identificador* não existir.

## <a name="remarks"></a>Comentários

> [!CAUTION]
> Para obter os resultados mais confiáveis, use a **`__if_not_exists`** instrução sob as restrições a seguir.

- Aplique a **`__if_not_exists`** instrução somente a tipos simples, não a modelos.

- Aplique a **`__if_not_exists`** instrução aos identificadores dentro ou fora de uma classe. Não aplique a **`__if_not_exists`** instrução a variáveis locais.

- Use a **`__if_not_exists`** instrução somente no corpo de uma função. Fora do corpo de uma função, a **`__if_not_exists`** instrução pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento à **`__if_not_exists`** instrução é a instrução [__if_exists](../cpp/if-exists-statement.md) .

## <a name="example"></a>Exemplo

Para obter um exemplo sobre como usar o **`__if_not_exists`** , consulte [__if_exists instrução](../cpp/if-exists-statement.md).

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução __if_exists](../cpp/if-exists-statement.md)
