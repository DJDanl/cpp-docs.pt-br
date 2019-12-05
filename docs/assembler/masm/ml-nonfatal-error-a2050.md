---
title: Erro não fatal A2050 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2050
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
ms.openlocfilehash: 15c6449ff4207c92dee28120d4f61be641cf01c8
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856571"
---
# <a name="ml-nonfatal-error-a2050"></a>Erro não fatal A2050 (ML)

**número real ou BCD não permitido**

Uma constante de número de ponto flutuante (real) ou de formato binário codificado (BCD) foi usada além de um inicializador de dados.

Ocorreu um dos seguintes:

- Um número real ou um BCD foi usado em uma expressão.

- Um número real foi usado para inicializar uma diretiva diferente de [DWORD](../../assembler/masm/dword.md), [QWORD](../../assembler/masm/qword.md)ou [Tbyte](../../assembler/masm/tbyte.md).

- Um BCD foi usado para inicializar uma diretiva diferente de `TBYTE`.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>