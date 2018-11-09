---
title: Acesso a argumento
ms.date: 04/04/2018
f1_keywords:
- c.arguments
helpviewer_keywords:
- argument access macros [C++]
- variable-length argument lists
ms.assetid: 7046ae34-a0ec-44f0-815d-3209492a3e19
ms.openlocfilehash: 8107cffa6a2da41c38b116b2e3fe36adf6ac945f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50470402"
---
# <a name="argument-access"></a>Acesso a argumento

As macros **va_arg**, **va_end** e **va_start** fornecem acesso aos argumentos de função quando o número de argumentos é variável. Elas são definidas em \<stdarg.h> para compatibilidade com ANSI/ISO C e em \<varargs.h> para compatibilidade com UNIX System V.

## <a name="argument-access-macros"></a>Macros de acesso a argumento

|Macro|Use|
|-----------|-------------------------------|
|[va_arg](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Recuperar o argumento da lista|
|[va_end](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Reiniciar o ponteiro|
|[va_start](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md)|Definir o ponteiro para o início da lista de argumentos|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)
