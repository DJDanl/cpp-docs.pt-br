---
title: Acesso inadequado a uma união
ms.date: 11/04/2016
ms.assetid: b273d984-62a8-4003-9a87-bf0149d3f2dd
ms.openlocfilehash: 5a804ed80c8f1ac2f5dd9a24f12c67e96e199b6b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227823"
---
# <a name="improper-access-to-a-union"></a>Acesso inadequado a uma união

**ANSI 3.3.2.3** Um membro de um objeto de união é acessado usando um membro de um tipo diferente

Se uma união de dois tipos é declarada e um valor é armazenado, mas a união é acessada com o outro tipo, os resultados são não confiáveis.

Por exemplo, uma União de **`float`** e **`int`** é declarada. Um **`float`** valor é armazenado, mas o programa mais tarde acessa o valor como um **`int`** . Nessa situação, o valor dependeria do armazenamento interno de **`float`** valores. O valor inteiro não seria confiável.

## <a name="see-also"></a>Confira também

[Estruturas, uniões, enumerações e campos de bits](../c-language/structures-unions-enumerations-and-bit-fields.md)
