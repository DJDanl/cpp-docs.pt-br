---
title: Conversões de tipos de ponto flutuante
ms.date: 10/02/2019
helpviewer_keywords:
- converting floating point
- floating-point conversion
ms.assetid: 96804c8e-fa3b-4742-9006-0082ed9e57f2
ms.openlocfilehash: 72d0f95a6e48dcf0a5e8fea3757e85f9a03bf7e4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227888"
---
# <a name="conversions-from-floating-point-types"></a>Conversões de tipos de ponto flutuante

Um valor de ponto flutuante que é convertido em outro tipo de ponto flutuante não passa por nenhuma alteração no valor se o valor original é representável exatamente no tipo de resultado. Se o valor original for numérico, mas não for reapresentável exatamente, o resultado será o maior valor de reapresentável mais próximo ou próximo. Veja [limites em constantes de ponto flutuante](../c-language/limits-on-floating-point-constants.md) para o intervalo de tipos de ponto flutuante.

Um valor de ponto flutuante que é convertido em um tipo integral é truncado primeiro, descartando qualquer valor fracionário. Se esse valor truncado for representável no tipo de resultado, o resultado deverá ser esse valor. Quando não é possível representá-lo, o valor do resultado é indefinido.

**Específico da Microsoft**

Os compiladores da Microsoft usam a representação binary32 do IEEE-754 para **`float`** valores e a representação binary64 para **`long double`** e **`double`** . Como **`long double`** e **`double`** usam a mesma representação, elas têm o mesmo intervalo e precisão.

Quando o compilador converte um **`double`** **`long double`** número de ponto flutuante ou em um **`float`** , ele arredonda o resultado de acordo com os controles de ambiente de ponto flutuante, cujo padrão é "arredondar para mais próximo, amarra até mesmo". Se um valor numérico for muito alto ou muito baixo para ser representado como um **`float`** valor numérico, o resultado da conversão será um infinito positivo ou negativo, de acordo com o sinal do valor original, e uma exceção de estouro será gerada, se habilitado.

Ao converter em tipos inteiros, o resultado de uma conversão para um tipo menor do que **`long`** é o resultado da conversão do valor para **`long`** e, em seguida, a conversão para o tipo de resultado.

Para conversão em tipos inteiros, pelo menos tão grande quanto **`long`** , uma conversão de um valor muito alto ou muito baixo para representar no tipo de resultado pode retornar qualquer um dos seguintes valores:

- O resultado pode ser um *valor de sentinela*, que é o valor representável mais distante de zero. Para tipos assinados, é o menor valor representável (0x800... 0). Para tipos não assinados, é o valor mais alto representável (0xFF... F).

- O resultado pode ser *saturado*, onde os valores muito altos para representar são convertidos para o valor mais alto representável, e valores muito baixos para serem representados são convertidos para o valor representável mais baixo. Um desses dois valores também é usado como o valor de sentinela.

- Para a conversão para **`unsigned long`** ou **`unsigned long long`** , o resultado da conversão de um valor fora do intervalo pode ser um valor diferente do valor mais alto ou mais baixo representável. Se o resultado é um sentinela ou um valor saturado ou não depende das opções do compilador e da arquitetura de destino. Versões futuras do compilador podem retornar um valor saturado ou de sentinela.

**FINAL específico da Microsoft**

A tabela a seguir resume as conversões de tipos flutuantes.

## <a name="table-of-conversions-from-floating-point-types"></a>Tabela de conversões de tipos de ponto flutuante

|De|Para|Método|
|----------|--------|------------|
|**`float`**|**`char`**|Converter em **`long`** ; Converter **`long`** em**`char`**|
|**`float`**|**`short`**|Converter em **`long`** ; Converter **`long`** em**`short`**|
|**`float`**|**`int`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`int`** , o resultado será indefinido.|
|**`float`**|**`long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`long`** , o resultado será indefinido.|
|**`float`**|**`long long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`long long`** , o resultado será indefinido.|
|**`float`**|**`unsigned char`**|Converter em **`long`** ; Converter **`long`** em**`unsigned char`**|
|**`float`**|**`unsigned short`**|Converter em **`long`** ; Converter **`long`** em**`unsigned short`**|
|**`float`**|**`unsigned`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned`** , o resultado será indefinido.|
|**`float`**|**`unsigned long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned long`** , o resultado será indefinido.|
|**`float`**|**`unsigned long long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned long long`** , o resultado será indefinido.|
|**`float`**|**`double`**|Representar como um **`double`** .|
|**`float`**|**`long double`**|Representar como um **`long double`** .|
|**`double`**|**`char`**|Converter em **`float`** ; Converter **`float`** em**`char`**|
|**`double`**|**`short`**|Converter em **`float`** ; Converter **`float`** em**`short`**|
|**`double`**|**`int`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`int`** , o resultado será indefinido.|
|**`double`**|**`long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`long`** , o resultado será indefinido.|
|**`double`**|**`unsigned char`**|Converter em **`long`** ; Converter **`long`** em**`unsigned char`**|
|**`double`**|**`unsigned short`**|Converter em **`long`** ; Converter **`long`** em**`unsigned short`**|
|**`double`**|**`unsigned`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned`** , o resultado será indefinido.|
|**`double`**|**`unsigned long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned long`** , o resultado será indefinido.|
|**`double`**|**`unsigned long long`**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **`unsigned long long`** , o resultado será indefinido.|
|**`double`**|**`float`**|Representar como um **`float`** . Se **`double`** o valor não puder ser representado exatamente como **`float`** , ocorre a perda de precisão. Se o valor for muito grande para ser representado como **`float`** , o resultado será indefinido.|
|**`double`**|**`long double`**|O **`long double`** valor é tratado como **`double`** .|

As conversões de **`long double`** seguem o mesmo método que as conversões do **`double`** .

## <a name="see-also"></a>Confira também

[Conversões de atribuição](../c-language/assignment-conversions.md)
