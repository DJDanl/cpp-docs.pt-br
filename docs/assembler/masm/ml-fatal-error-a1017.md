---
title: Erro fatal A1017 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A1017
helpviewer_keywords:
- A1017
ms.assetid: bef0b312-5431-4e5a-b637-c19919acf01b
ms.openlocfilehash: 6fb0835cca135fc994866dc2453734d7b3012a64
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856820"
---
# <a name="ml-fatal-error-a1017"></a>Erro fatal A1017 (ML)

**nome de arquivo de origem ausente**

ML não pôde localizar um arquivo para montar ou passar para o vinculador.

Esse erro é gerado quando você fornece opções de linha de comando do ML sem especificar um nome de arquivo para agir. Para montar arquivos que não têm uma extensão. asm, use a opção de linha de comando **/ta** .

Esse erro também pode ser gerado invocando ML sem parâmetros se a variável de ambiente ML contiver opções de linha de comando.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>