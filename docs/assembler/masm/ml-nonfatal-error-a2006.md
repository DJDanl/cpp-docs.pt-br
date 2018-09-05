---
title: Erro não fatal de ML A2006 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2006
dev_langs:
- C++
helpviewer_keywords:
- A2006
ms.assetid: b8a8f096-95df-42b5-85ed-d2530560a84c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f287c6ab46c6af71ba6dc0032f332ce3cc489454
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43677399"
---
# <a name="ml-nonfatal-error-a2006"></a>Erro não fatal A2006 (ML)

**símbolo indefinido: identificador**

Foi feita uma tentativa para usar um símbolo que não foi definido.

Pode ter ocorrido um dos seguintes:

- Um símbolo não foi definido.

- Um campo não era um membro da estrutura especificada.

- Um símbolo foi definido em um arquivo de inclusão não tiver sido incluído.

- Um símbolo externo foi usado sem uma [EXTERN](../../assembler/masm/extern-masm.md) ou [EXTERNDEF](../../assembler/masm/externdef.md) diretiva.

- Um nome de símbolo foi digitado incorretamente.

- Um rótulo de código local foi referenciado fora de seu escopo.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>