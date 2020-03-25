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
ms.openlocfilehash: 916dce0346bebfc5ff65ca558ae75317a187660a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169533"
---
# <a name="data-directives-and-operators-in-inline-assembly"></a>Diretivas de dados e operadores no assembly embutido

**Seção específica da Microsoft**

Embora um bloco de `__asm` possa fazer referência C++ a tipos de dados e C ou a objetos, ele não pode definir objetos de dados com diretivas ou operadores MASM. Especificamente, você não pode usar as diretivas de definição **DB**, `DW`, **DD**, `DQ`, `DT`e `DF`ou os operadores `DUP` ou **isso**. Estruturas e registros de MASM também estão indisponíveis. O Assembler embutido não aceita as diretivas `STRUC`, `RECORD`, **largura**ou **máscara**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
