---
title: Aviso LNK4006 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4006
helpviewer_keywords:
- LNK4006
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
ms.openlocfilehash: c81c93a6df8c7eef809f243e3dc56164ea548371
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472222"
---
# <a name="linker-tools-warning-lnk4006"></a>Aviso LNK4006 (Ferramentas de Vinculador)

símbolo já definido no objeto; segunda definição ignorada

O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação. Quando este aviso for encontrado, `symbol` será adicionado duas vezes, mas somente o primeiro formulário será usado.

Você pode obter esse aviso se você tentar mesclar duas bibliotecas de importação em um.

Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. O determinado `symbol` pode ser uma função empacotada, criada ao compilar com [/Gy](../../build/reference/gy-enable-function-level-linking.md). Esse símbolo foi incluído em mais de um arquivo, mas foi alterado entre compilações. Recompilar todos os arquivos que incluem o `symbol`.

1. O determinado `symbol` possam ter sido definidas forma diferente em dois objetos de membro em bibliotecas diferentes.

1. Absoluta definida duas vezes, com um valor diferente em cada definição.

1. Se a mensagem de erro é recebida quando combinando bibliotecas, `symbol` já existe na biblioteca que está sendo adicionada ao.