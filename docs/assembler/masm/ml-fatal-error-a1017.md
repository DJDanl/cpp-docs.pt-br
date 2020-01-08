---
title: Erro fatal A1017 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A1017
helpviewer_keywords:
- A1017
ms.assetid: bef0b312-5431-4e5a-b637-c19919acf01b
ms.openlocfilehash: 523fed26afae5a88c5f154283487d3453a2e48c7
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318053"
---
# <a name="ml-fatal-error-a1017"></a>Erro fatal A1017 (ML)

**nome de arquivo de origem ausente**

ML não pôde localizar um arquivo para montar ou passar para o vinculador.

Esse erro é gerado quando você fornece opções de linha de comando do ML sem especificar um nome de arquivo para agir. Para montar arquivos que não têm uma extensão. asm, use a opção de linha de comando **/ta** .

Esse erro também pode ser gerado invocando ML sem parâmetros se a variável de ambiente ML contiver opções de linha de comando.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
