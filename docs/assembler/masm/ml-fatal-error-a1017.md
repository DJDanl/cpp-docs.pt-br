---
title: Erro Fatal de ML A1017 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1017
dev_langs:
- C++
helpviewer_keywords:
- A1017
ms.assetid: bef0b312-5431-4e5a-b637-c19919acf01b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb98eab68da417526a75beaa57870ce906c85a8d
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43688553"
---
# <a name="ml-fatal-error-a1017"></a>Erro fatal A1017 (ML)

**nome do arquivo de origem ausentes**

AM não foi possível localizar um arquivo para montar ou passar para o vinculador.

Esse erro é gerado quando você fornecer opções de linha de comando ML sem especificar um nome de arquivo para agir. Para montar arquivos que não têm uma extensão. ASM, use o **/Ta** opção de linha de comando.

Esse erro também pode ser gerado invocando ML sem parâmetros, se a variável de ambiente ML contém opções de linha de comando.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>