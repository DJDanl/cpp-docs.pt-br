---
title: Aviso LNK4006 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4006
helpviewer_keywords:
- LNK4006
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
ms.openlocfilehash: d949ba259de8e131f6191e757119b4c42effc3d4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194311"
---
# <a name="linker-tools-warning-lnk4006"></a>Aviso LNK4006 (Ferramentas de Vinculador)

símbolo já definido no objeto; segunda definição ignorada

O `symbol` determinado, exibido na sua forma decorada, foi definido por multiplicação. Quando esse aviso for encontrado, `symbol` será adicionado duas vezes, mas apenas seu primeiro formulário será usado.

Você pode receber esse aviso se tentar mesclar duas bibliotecas de importação em uma.

Se você estiver recompilando a biblioteca de tempo de execução do C, poderá ignorar esta mensagem.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. O `symbol` fornecido pode ser uma função empacotada, criada pela compilação com [/GY](../../build/reference/gy-enable-function-level-linking.md). Esse símbolo foi incluído em mais de um arquivo, mas foi alterado entre compilações. Recompile todos os arquivos que incluem o `symbol`.

1. O `symbol` fornecido pode ter sido definido de forma diferente em dois objetos Membros em diferentes bibliotecas.

1. Uma absoluta pode ter sido definida duas vezes, com um valor diferente em cada definição.

1. Se a mensagem de erro for recebida ao combinar bibliotecas, `symbol` já existir na biblioteca que está sendo adicionada ao.
