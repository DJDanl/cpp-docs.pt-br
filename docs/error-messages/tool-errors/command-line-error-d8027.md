---
title: Erro D8027 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8027
helpviewer_keywords:
- D8027
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
ms.openlocfilehash: d3a7908ec9e7e37d83fd7b928cad2ef256313c40
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526784"
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