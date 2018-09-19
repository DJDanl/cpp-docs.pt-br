---
title: Mapeamentos constantes e de variável global | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _tenviron
- _TEOF
- _tfinddata_t
dev_langs:
- C++
helpviewer_keywords:
- tfinddatat function
- tenviron function
- TEOF type
- _TEOF type
- generic-text mappings
- _tenviron function
- _tfinddata_t function
ms.assetid: 3af4fd3e-9ed5-4ed9-96fd-7031e5126fd1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 94cee77f82f850560cc5fe50e13b85c58b7187ad
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077836"
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