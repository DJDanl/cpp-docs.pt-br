---
title: Aviso de ML A4012 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A4012
dev_langs:
- C++
helpviewer_keywords:
- A4012
ms.assetid: 842b1259-9679-4eeb-a02d-672a583a94e5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 083a0cd7687bc182aa9e387d6d575fa718b1b50c
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43682149"
---
# <a name="ml-warning-a4012"></a>Aviso A4012 (ML)

**informações de número de linha para o segmento sem classe 'CODE'**

Havia instruções em um segmento que não tem um nome de classe que termina com "Código". O assembler não gerou informações do CodeView para essas instruções.

CodeView não é possível processar os módulos com o código em segmentos com nomes de classe que não terminam com "Código".

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>