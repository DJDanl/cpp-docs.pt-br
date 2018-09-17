---
title: Outra saída LIB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- Lib
dev_langs:
- C++
helpviewer_keywords:
- output files, LIB
ms.assetid: 656864a6-0b7a-4633-8dc6-ee3b1766d836
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6bd31c0534ae7ff2e7d840ad245be6f66983ea0a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45704230"
---
# <a name="other-lib-output"></a>Outra saída LIB

No modo padrão, você pode usar a opção /LIST para exibir informações sobre a biblioteca resultante. Você pode redirecionar essa saída para um arquivo.

LIB exibe uma mensagem de copyright e de versão e ecoa arquivos de comando, a menos que a opção /NOLOGO é usada.

Quando você digita `lib` com nenhuma outra entrada LIB exibirá uma instrução de uso que resume as suas opções.

Erro e aviso mensagens emitidas por LIB têm o formato LNK*nnnn*. As ferramentas LINK, DUMPBIN e EDITBIN também usam esse intervalo de erros. A Ajuda está disponível selecionando o erro na janela de saída e pressionando F1.

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](../../build/reference/overview-of-lib.md)