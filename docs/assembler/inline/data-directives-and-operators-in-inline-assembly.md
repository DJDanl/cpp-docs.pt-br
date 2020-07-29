---
title: Diretivas de dados e operadores no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- data directives [C++]
- __asm keyword [C++], referencing limitations
- MASM (Microsoft Macro Assembler), directives
- directives [C++], MASM
- MASM (Microsoft Macro Assembler), structures
- operators [MASM]
- inline assembly, operators
- inline assembly, data directives
- MASM (Microsoft Macro Assembler), operators
- structures [C++], MASM
ms.assetid: fb7410c7-156a-4131-bcfc-211aa70533e3
ms.openlocfilehash: bcacb0cdd26181da3cf80a582866c1e30567d043
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192347"
---
# <a name="data-directives-and-operators-in-inline-assembly"></a>Diretivas de dados e operadores no assembly embutido

**Específico da Microsoft**

Embora um **`__asm`** bloco possa fazer referência a objetos e tipos de dados C ou C++, ele não pode definir objetos de dados com diretivas ou operadores MASM. Especificamente, você não pode usar as diretivas de definição **DB**, `DW` **DD**, `DQ` , `DT` , e `DF` , ou os operadores `DUP` ou **isso**. Estruturas e registros de MASM também estão indisponíveis. O Assembler embutido não aceita as diretivas `STRUC` , a `RECORD` **largura**ou a **máscara**.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando o idioma do assembly em blocos de __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
