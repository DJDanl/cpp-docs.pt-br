---
title: Tipos de dados SBCS e MBCS
description: Como representar caracteres únicos e multibyte no tempo de execução do Microsoft C.
ms.topic: conceptual
ms.date: 04/11/2018
f1_keywords:
- MBCS
- SBCS
helpviewer_keywords:
- SBCS and MBCS data types
- data types [C], MBCS and SBCS
ms.assetid: 4c3ef9da-e397-48d4-800e-49dba36db171
ms.openlocfilehash: 27d32ffd079cdc82ab8a799df9d9ec778b546a3b
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590245"
---
# <a name="sbcs-and-mbcs-data-types"></a>Tipos de dados SBCS e MBCS

Qualquer rotina de biblioteca de tempo de execução MBCS da Microsoft que manipula apenas 1 caractere multibyte ou 1 byte de um caractere multibyte espera um **`unsigned int`** argumento (em que 0x00 <= valor de caractere <= 0xFFFF e 0x00 <= valor de byte <= 0xFF). Uma rotina MBCS que manipula bytes ou caracteres multibyte em um contexto de cadeia de caracteres espera que uma cadeia de caracteres multibyte seja representada como um **`unsigned char`** ponteiro.

> [!CAUTION]
> Cada byte de um caractere multibyte pode ser representado em um de 8 bits **`char`** . No entanto, um caractere de byte único SBCS ou MBCS de **`char`** um tipo com um valor maior que 0x7F é negativo. Quando tal caractere é convertido diretamente em um **`int`** ou um **`long`** , o resultado é o sinal estendido pelo compilador e, portanto, pode gerar resultados inesperados.

É melhor representar um byte de um caractere multibyte como 8 bits **`unsigned char`** . Ou, para evitar um resultado negativo, converta um caractere de byte único do tipo **`char`** para um **`unsigned char`** antes de convertê-lo em um **`int`** ou um **`long`** .

Como algumas funções de manipulação de cadeia de caracteres SBCS usam parâmetros (assinados) **`char`** <strong>\*</strong> , um aviso de compilador de incompatibilidade de tipo ocorrerá quando **_MBCS** for definido. Há três maneiras de evitar esse aviso, listados em ordem de eficiência:

1. Use as funções embutidas fortemente tipadas em TCHAR.H. Este é o comportamento padrão.

1. Use as macros diretas em TCHAR.H definindo **_MB_MAP_DIRECT** na linha de comando. Se você fizer isso, você deverá realizar a correspondência de tipos manualmente. Esse é o método mais rápido, mas não é de tipo seguro.

1. Use as funções de biblioteca vinculada estaticamente fortemente tipadas em TCHAR.H. Para fazer isso, defina a constante **_NO_INLINING** na linha de comando. Esse é o método mais lento, no entanto, é o mais fortemente tipado.

## <a name="see-also"></a>Confira também

[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
