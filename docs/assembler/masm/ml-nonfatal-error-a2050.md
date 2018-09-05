---
title: Erro não fatal de ML A2050 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2050
dev_langs:
- C++
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bd2e0e6c2fc818ef9286fd303c07a26bdd8b4e5a
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43680665"
---
# <a name="ml-nonfatal-error-a2050"></a>Erro não fatal A2050 (ML)

**real ou o número de BCD não permitido**

Um número (real) de ponto flutuante ou uma constante binary coded decimal (BCD) foi usado diferente de como um inicializador de dados.

Um dos seguintes ocorreu:

- Um número real ou um BCD foi usado em uma expressão.

- Um número real foi usado para inicializar uma diretiva diferente de [DWORD](../../assembler/masm/dword.md), [QWORD](../../assembler/masm/qword.md), ou [TBYTE](../../assembler/masm/tbyte.md).

- Um BCD foi usado para inicializar uma diretiva diferente de `TBYTE`.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>