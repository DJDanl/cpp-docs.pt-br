---
title: Erro fatal A1017 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A1017
helpviewer_keywords:
- A1017
ms.assetid: bef0b312-5431-4e5a-b637-c19919acf01b
ms.openlocfilehash: 22a16569364760d0cb1d01011405f7a11dd21cac
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50560817"
---
# <a name="ml-fatal-error-a1017"></a>Erro fatal A1017 (ML)

**nome do arquivo de origem ausentes**

AM não foi possível localizar um arquivo para montar ou passar para o vinculador.

Esse erro é gerado quando você fornecer opções de linha de comando ML sem especificar um nome de arquivo para agir. Para montar arquivos que não têm uma extensão. ASM, use o **/Ta** opção de linha de comando.

Esse erro também pode ser gerado invocando ML sem parâmetros, se a variável de ambiente ML contém opções de linha de comando.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>