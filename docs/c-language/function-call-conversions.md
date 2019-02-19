---
title: Conversões de função de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- function calls, converting
- function calls, argument type conversions
- functions [C], argument conversions
ms.assetid: 04ea0f81-509a-4913-8b12-0937a81babcf
ms.openlocfilehash: d9f205bbbbac353b57743f8e1211b20fa3d32f05
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152476"
---
# <a name="function-call-conversions"></a>Conversões de função de chamada

O tipo de conversão executado nos argumentos em uma chamada de função depende da presença de um protótipo de função (declaração de encaminhamento) com tipos de argumentos declarados para a função chamada.

Se um protótipo da função estiver presente e incluir tipos de argumentos declarados, o compilador fará a verificação de tipo (consulte [Funções](../c-language/functions-c.md)).

Se nenhum protótipo da função estiver presente, somente as conversões aritméticas comuns serão executadas nos argumentos na chamada da função. Essas conversões são executadas independentemente em cada argumento na chamada. Isso significa que um valor **float** será convertido em **double**; um valor `char` ou **short** será convertido em `int`; e `unsigned char` ou **unsigned short** será convertido em `unsigned int`.

## <a name="see-also"></a>Consulte também

[Conversões de Tipo](../c-language/type-conversions-c.md)
