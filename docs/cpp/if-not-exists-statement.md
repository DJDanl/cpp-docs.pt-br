---
title: Instrução __if_not_exists
ms.date: 11/04/2016
f1_keywords:
- __if_not_exists_cpp
helpviewer_keywords:
- __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
ms.openlocfilehash: 845597460cdc0ce83adcbba1f47a78c83735cbf9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183629"
---
# <a name="ifnotexists-statement"></a>Instrução __if_not_exists

O **if_not_exists** instrução testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_not_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*identifier*|O identificador cuja existência você deseja testar.|
|*statements*|Um ou mais instruções a executar se *identificador* não existe.|

## <a name="remarks"></a>Comentários

> [!CAUTION]
>  Para obter os resultados mais confiáveis, use o **if_not_exists** instrução sob as restrições a seguir.

- Aplicar a **if_not_exists** instrução apenas em tipos simples, e não por modelos.

- Aplicar a **if_not_exists** instrução para identificadores dentro ou fora de uma classe. Não se aplicam a **if_not_exists** instrução para variáveis locais.

- Use o **if_not_exists** instrução somente no corpo de uma função. Fora do corpo de uma função, o **if_not_exists** instrução pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento para o **if_not_exists** instrução é a [if_exists](../cpp/if-exists-statement.md) instrução.

## <a name="example"></a>Exemplo

Para obter um exemplo sobre como usar **if_not_exists**, consulte [if_exists instrução](../cpp/if-exists-statement.md).

## <a name="see-also"></a>Consulte também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução __if_exists](../cpp/if-exists-statement.md)