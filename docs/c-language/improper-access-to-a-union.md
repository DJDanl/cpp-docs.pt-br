---
title: Acesso inadequado a uma união
ms.date: 11/04/2016
ms.assetid: b273d984-62a8-4003-9a87-bf0149d3f2dd
ms.openlocfilehash: 9fd7bdc753f6359a8760e58813f9009411c1bf44
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56151059"
---
# <a name="improper-access-to-a-union"></a>Acesso inadequado a uma união

**ANSI 3.3.2.3** Um membro de um objeto de união é acessado usando um membro de um tipo diferente

Se uma união de dois tipos é declarada e um valor é armazenado, mas a união é acessada com o outro tipo, os resultados são não confiáveis.

Por exemplo, uma união de **float** e `int` é declarada. Um valor **float** é armazenado, mas o programa acessa posteriormente o valor como `int`. Nessa situação, o valor dependeria do armazenamento interno de valores **float**. O valor inteiro não seria confiável.

## <a name="see-also"></a>Consulte também

[Estruturas, uniões, enumerações e campos de bit](../c-language/structures-unions-enumerations-and-bit-fields.md)
