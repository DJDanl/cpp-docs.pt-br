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
ms.openlocfilehash: 52e20c37f3066122a062e3fc9c64ced576b6c302
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167225"
---
# <a name="data-directives-and-operators-in-inline-assembly"></a>Diretivas de dados e operadores no assembly embutido

**Seção específica da Microsoft**

Embora um `__asm` bloco pode fazer referência a objetos e tipos de dados C ou C++, ele não é possível definir objetos de dados com diretivas MASM ou operadores. Especificamente, você não pode usar as diretivas de definição **DB**, `DW`, **DD**, `DQ`, `DT`, e `DF`, ou os operadores `DUP` ou  **Isso**. Registros e estruturas (MASM) não estão disponíveis. O assembler embutido não aceita as diretivas `STRUC`, `RECORD`, **largura**, ou **MÁSCARA**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>