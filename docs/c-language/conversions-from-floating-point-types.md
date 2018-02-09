---
title: "Conversões de tipos de ponto flutuante | Microsoft Docs"
ms.custom: 
ms.date: 01/29/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- converting floating point
- floating-point conversion
ms.assetid: 96804c8e-fa3b-4742-9006-0082ed9e57f2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 80e84ba9a78f78fd93d7bd7fedbcbfaf168a7ec2
ms.sourcegitcommit: 30ab99c775d99371ed22d1a46598e542012ed8c6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/03/2018
---
# <a name="conversions-from-floating-point-types"></a>Conversões de tipos de ponto flutuante

Um valor **float** convertido em **double** ou **long double** ou um valor **double** convertido em **long double** não sofre nenhuma alteração no valor. Um valor **double** convertido em um valor **float** é representado exatamente, se possível. A precisão poderá ser perdida se o valor não puder ser representado exatamente. Se o resultado for fora do intervalo, o comportamento será indefinido. Consulte [Limites em constantes de ponto flutuante](../c-language/limits-on-floating-point-constants.md) para ver o intervalo de tipos de ponto flutuante.

Um valor flutuante é convertido em um valor integral. Para isso, primeiro converta **long**, o valor **long** no valor completo específico. A parte decimal do valor flutuante é rejeitada na conversão para **long**. Se o resultado for ainda muito grande para caber em **long**, o resultado da conversão será indefinido.

**Seção específica da Microsoft**

Ao converter um número de ponto flutuante de **double** ou **long double** em um número de ponto flutuante menor, o valor da variável de ponto flutuante será truncado para zero quando um estouro negativo ocorrer. Um estouro causa um erro em tempo de execução. Observe que o compilador C da Microsoft mapeia o tipo **long double** para o **double**.

**Fim da seção específica da Microsoft**

A tabela a seguir resume as conversões de tipos flutuantes.

## <a name="conversions-from-floating-point-types"></a>Conversões de tipos de ponto flutuante

|De|Para|Método|
|----------|--------|------------|
|**float**|**char**|Converter em **long**; converter **long** em **char**|
|**float**|**short**|Converter em **long**; converter **long** em **short**|
|**float**|**long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **long**, o resultado será indefinido.|
|**float**|**unsigned short**|Converter em **long**; converter **long** em **unsigned short**|
|**float**|**unsigned long**|Converter em **long**; converter **long** em **unsigned long**|
|**float**|**double**|Representação de alteração interna|
|**float**|**long double**|Representação de alteração interna|
|**double**|**char**|Converter em **float**; converter **float** em **char**|
|**double**|**short**|Converter em **float**; converter **float** em **short**|
|**double**|**long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **long**, o resultado será indefinido.|
|**double**|**unsigned short**|Converter em **long**; converter **long** em **unsigned short**|
|**double**|**unsigned long**|Converter em **long**; converter **long** em **unsigned long**|
|**double**|**float**|É representado como um **float**. Se o valor **double** não pode ser representado exatamente como **float**, ocorre perda de precisão. Se o valor for muito grande para ser representado como **float**, o resultado será indefinido.|
|**long double**|**char**|Converter em **float**; converter **float** em **char**|
|**long double**|**short**|Converter em **float**; converter **float** em **short**|
|**long double**|**long**|Truncar no ponto decimal. Se o resultado for muito grande para ser representado como **long**, o resultado será indefinido.|
|**long double**|**unsigned short**|Converter em **long**; converter **long** em **unsigned short**|
|**long double**|**unsigned long**|Converter em **long**; converter **long** em **unsigned long**|
|**long double**|**float**|É representado como um **float**. Se o valor **double** não pode ser representado exatamente como **float**, ocorre perda de precisão. Se o valor for muito grande para ser representado como **float**, o resultado será indefinido.|
|**long double**|**double**|O valor **long double** é tratado como **double**.|

As conversões dos valores **float**, **double** ou **long double** em **unsigned long** não são precisas se o valor que está sendo convertido for maior que o valor máximo positivo **long**.

## <a name="see-also"></a>Consulte também

[Conversões de atribuição](../c-language/assignment-conversions.md)  
