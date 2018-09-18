---
title: Erro de linha de comando D8027 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D8027
dev_langs:
- C++
helpviewer_keywords:
- D8027
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8234835d3bb0545c8a72bf35cfb55b2e18bc7da2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46070373"
---
# <a name="command-line-error-d8027"></a>Erro D8027 (linha de comando)

não é possível executar 'componente'

O compilador não pôde executar o componente determinado compilador ou vinculador.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Não há memória suficiente para carregar o componente. Se NMAKE invocado o compilador, execute o compilador fora o makefile.

1. O sistema operacional atual não pôde executar o componente. Verifique se o caminho aponta para os arquivos executáveis apropriado para seu sistema operacional.

1. O componente estava corrompido. Copiar novamente o componente a partir dos discos de distribuição, usando o programa de instalação.

1. Uma opção foi especificada incorretamente. Por exemplo:

    ```
    cl /B1 file1.c
    ```