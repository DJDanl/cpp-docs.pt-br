---
title: Conversões de tipos de ponto flutuante
ms.date: 10/02/2019
helpviewer_keywords:
- converting floating point
- floating-point conversion
ms.assetid: 96804c8e-fa3b-4742-9006-0082ed9e57f2
ms.openlocfilehash: c2f7c25015b36545f969796a1f85d355d715427a
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998706"
---
# <a name="conversions-from-floating-point-types"></a>Conversões de tipos de ponto flutuante

Um valor de ponto flutuante que é convertido em outro tipo de ponto flutuante não passa por nenhuma alteração no valor se o valor original é representável exatamente no tipo de resultado. Se o valor original for numérico, mas não for reapresentável exatamente, o resultado será o maior valor de reapresentável mais próximo ou próximo. Veja [limites em constantes de ponto flutuante](../c-language/limits-on-floating-point-constants.md) para o intervalo de tipos de ponto flutuante.

Um valor de ponto flutuante que é convertido em um tipo integral é truncado primeiro, descartando qualquer valor fracionário. Se esse valor truncado for representável no tipo de resultado, o resultado deverá ser esse valor. Quando não é possível representá-lo, o valor do resultado é indefinido.

**Seção específica da Microsoft**

Os compiladores da Microsoft usam a representação binary32 do IEEE-754 para valores **float** e a representação binary64 para **longos Double** e **Double**. Como **Long duplo** e **duplo** usam a mesma representação, eles têm o mesmo intervalo e precisão.

Quando o compilador converte um número de **ponto flutuante duplo** ou **duplo** em um **float**, ele arredonda o resultado de acordo com os controles de ambiente de ponto flutuante, que, por padrão, é "arredondado para mais próximo, liga para mesmo". Se um valor numérico for muito alto ou muito baixo para ser representado como um valor de **float** numérico, o resultado da conversão será um infinito positivo ou negativo, de acordo com o sinal do valor original, e uma exceção de estouro será gerada, se habilitada.

Ao converter para tipos inteiros, o resultado de uma conversão para um tipo menor que **Long** é o resultado da conversão do valor para **Long**e, em seguida, a conversão para o tipo de resultado.

Para conversão em tipos inteiros pelo menos tão grande quanto **longo**, uma conversão de um valor muito alto ou muito baixo para representar no tipo de resultado pode retornar qualquer um dos seguintes valores:

- O resultado pode ser um *valor de sentinela*, que é o valor representável mais distante de zero. Para tipos assinados, é o menor valor representável (0x800... 0). Para tipos não assinados, é o valor mais alto representável (0xFF... F).

- O resultado pode ser *saturado*, onde os valores muito altos para representar são convertidos para o valor mais alto representável, e valores muito baixos para serem representados são convertidos para o valor representável mais baixo. Um desses dois valores também é usado como o valor de sentinela.

- Para conversão em longo prazo **não** atribuído ou **não assinado**, o resultado da conversão de um valor fora do intervalo pode ser um valor diferente do valor mais alto ou mais baixo representável. Se o resultado é um sentinela ou um valor saturado ou não depende das opções do compilador e da arquitetura de destino. Versões futuras do compilador podem retornar um valor saturado ou de sentinela.

**Fim da seção específica da Microsoft**

A tabela a seguir resume as conversões de tipos flutuantes.

## <a name="table-of-conversions-from-floating-point-types"></a>Tabela de conversões de tipos de ponto flutuante

|De|Para|Método|
|----------|--------|------------|
|**float**|**char**|Converter em **long**; converter **long** em **char**|
|**float**|**short**|Converter em **long**; converter **long** em **short**|
|**float**|**int**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **int**, o resultado será indefinido.|
|**float**|**long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **long**, o resultado será indefinido.|
|**float**|**long long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **longo**, o resultado será indefinido.|
|**float**|**unsigned char**|Converter em **Long**; Converter **longo** em **Char não assinado**|
|**float**|**unsigned short**|Converter em **long**; converter **long** em **unsigned short**|
|**float**|**unsigned**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **não assinado**, o resultado será indefinido.|
|**float**|**unsigned long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **longo sem sinal**, o resultado será indefinido.|
|**float**|**longo longo sem sinal**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **longo e sem sinal**, o resultado será indefinido.|
|**float**|**double**|Representar como **duplo**.|
|**float**|**long double**|Representar como um **longo Duplo**.|
|**double**|**char**|Converter em **float**; converter **float** em **char**|
|**double**|**short**|Converter em **float**; converter **float** em **short**|
|**double**|**int**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **int**, o resultado será indefinido.|
|**double**|**long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **long**, o resultado será indefinido.|
|**double**|**unsigned char**|Converter em **Long**; Converter **longo** em **Char não assinado**|
|**double**|**unsigned short**|Converter em **long**; converter **long** em **unsigned short**|
|**double**|**unsigned**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **não assinado**, o resultado será indefinido.|
|**double**|**unsigned long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **longo sem sinal**, o resultado será indefinido.|
|**double**|**longo longo sem sinal**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **longo e sem sinal**, o resultado será indefinido.|
|**double**|**float**|É representado como um **float**. Se o valor **Double** não puder ser representado exatamente como **float**, ocorrerá a perda de precisão. Se o valor for muito grande para ser representado como **float**, o resultado será indefinido.|
|**double**|**long double**|O valor **long double** é tratado como **double**.|

As conversões de **longo Duplo** seguem o mesmo método que as conversões de **Double**.

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)
