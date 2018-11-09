---
title: Constante e mapeamentos de variável global
ms.date: 11/04/2016
f1_keywords:
- _tenviron
- _TEOF
- _tfinddata_t
helpviewer_keywords:
- tfinddatat function
- tenviron function
- TEOF type
- _TEOF type
- generic-text mappings
- _tenviron function
- _tfinddata_t function
ms.assetid: 3af4fd3e-9ed5-4ed9-96fd-7031e5126fd1
ms.openlocfilehash: 0f4e41e652cc1154b3bbc1ae3ca20c143e2745ad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646180"
---
# <a name="constant-and-global-variable-mappings"></a>Constante e mapeamentos de variável global

Esses mapeamentos constantes de texto genérico, de variável global e de tipo padrão são definidos no TCHAR.H e dependem se a constante `_UNICODE` ou `_MBCS` foi definida em seu programa.

### <a name="generic-text-constant-and-global-variable-mappings"></a>Mapeamentos constantes de texto genérico e de variável global

|De texto genérico – nome do objeto|SBCS (_UNICODE, _MBCS não definidos)|_MBCS definido|_UNICODE definido|
|----------------------------------|--------------------------------------------|--------------------|-----------------------|
|`_TEOF`|`EOF`|`EOF`|`WEOF`|
|`_tenviron`|`_environ`|`_environ`|`_wenviron`|
|`_tpgmptr`|`_pgmptr`|`_pgmptr`|`_wpgmptr`|

## <a name="see-also"></a>Consulte também

[Mapeamentos de texto genérico](../c-runtime-library/generic-text-mappings.md)<br/>
[Mapeamentos de tipo de dados](../c-runtime-library/data-type-mappings.md)<br/>
[Mapeamentos de rotina](../c-runtime-library/routine-mappings.md)<br/>
[Um programa de texto genérico de amostra](../c-runtime-library/a-sample-generic-text-program.md)<br/>
[Usando mapeamentos de texto genérico](../c-runtime-library/using-generic-text-mappings.md)