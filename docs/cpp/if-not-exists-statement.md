---
title: Instrução __if_not_exists
ms.date: 11/04/2016
f1_keywords:
- __if_not_exists_cpp
helpviewer_keywords:
- __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
ms.openlocfilehash: 7372ac127a7b4dd5c05d58cfecca25f87690b0ae
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178165"
---
# <a name="__if_not_exists-statement"></a>Instrução __if_not_exists

A instrução **__if_not_exists** testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.

## <a name="syntax"></a>Sintaxe

```
__if_not_exists ( identifier ) {
statements
};
```

#### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*identifier*|O identificador cuja existência você deseja testar.|
|*instruções*|Uma ou mais instruções a serem executadas se o *identificador* não existir.|

## <a name="remarks"></a>Comentários

> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução **__if_not_exists** sob as restrições a seguir.

- Aplique a instrução **__if_not_exists** apenas a tipos simples, não a modelos.

- Aplique a instrução **__if_not_exists** aos identificadores dentro ou fora de uma classe. Não aplique a instrução **__if_not_exists** a variáveis locais.

- Use a instrução **__if_not_exists** apenas no corpo de uma função. Fora do corpo de uma função, a instrução **__if_not_exists** pode testar apenas tipos totalmente definidos.

- Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.

O complemento para a instrução **__if_not_exists** é a instrução [__if_exists](../cpp/if-exists-statement.md) .

## <a name="example"></a>Exemplo

Para obter um exemplo sobre como usar **__if_not_exists**, consulte [__if_exists instrução](../cpp/if-exists-statement.md).

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução __if_exists](../cpp/if-exists-statement.md)
