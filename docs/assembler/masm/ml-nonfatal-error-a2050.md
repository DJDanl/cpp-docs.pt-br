---
title: Erro não fatal A2050 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2050
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
ms.openlocfilehash: 311aedd0cc739fd862efb0a18cc444b3fb75b165
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316974"
---
# <a name="ml-nonfatal-error-a2050"></a>Erro não fatal A2050 (ML)

**número real ou BCD não permitido**

Uma constante de número de ponto flutuante (real) ou de formato binário codificado (BCD) foi usada além de um inicializador de dados.

Ocorreu um dos seguintes:

- Um número real ou um BCD foi usado em uma expressão.

- Um número real foi usado para inicializar uma diretiva diferente de [DWORD](dword.md), [QWORD](qword.md)ou [Tbyte](tbyte.md).

- Um BCD foi usado para inicializar uma diretiva diferente de `TBYTE`.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
