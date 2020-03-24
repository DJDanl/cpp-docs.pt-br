---
title: Erro D8027 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D8027
helpviewer_keywords:
- D8027
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
ms.openlocfilehash: 42341507dfc2d3da02639dd28ab1265783452388
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196879"
---
# <a name="command-line-error-d8027"></a>Erro D8027 (linha de comando)

Não é possível executar ' Component '

O compilador não pôde executar o componente de compilador ou vinculador fornecido.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Não há memória suficiente para carregar o componente. Se NMAKE invocar o compilador, execute o compilador fora do makefile.

1. O sistema operacional atual não pôde executar o componente. Verifique se o caminho aponta para os arquivos executáveis apropriados para o seu sistema operacional.

1. O componente foi corrompido. Recopie o componente dos discos de distribuição usando o programa de instalação.

1. Uma opção foi especificada incorretamente. Por exemplo:

    ```
    cl /B1 file1.c
    ```
