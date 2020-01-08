---
title: Erro não fatal A2133 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2133
helpviewer_keywords:
- A2133
ms.assetid: 5ba50911-22c8-43b7-90e2-946fc612e05f
ms.openlocfilehash: 1ffdf5fb6577dbd4e24312b3c57a4186173ddcf6
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75312632"
---
# <a name="ml-nonfatal-error-a2133"></a>Erro não fatal A2133 (ML)

**registrar valor substituído por INVOKE**

Um registro foi passado como um argumento para um procedimento, mas o código gerado por [Invoke](invoke.md) para passar outros argumentos destruiu o conteúdo do registro.

Os registros AX, AL, AH, EAX, DX, DL, DH e EDX podem ser usados pelo Assembler para executar a conversão de dados.

Use um registro diferente.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
