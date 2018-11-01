---
title: Erro RC2001 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2001
helpviewer_keywords:
- RC2001
ms.assetid: 92bfb4c0-1879-4606-bb9f-ef7368707b4a
ms.openlocfilehash: f4755e04a744d94636b4b37aaf727e0d733008ef
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602105"
---
# <a name="resource-compiler-error-rc2001"></a>Erro RC2001 (compilador de recurso)

Newline em constante

Uma constante de cadeia de caracteres foi retomada em uma segunda linha sem qualquer um, uma barra invertida (**\\**) ou de abertura e fechamento aspas duplas (**"**).

Para interromper uma constante de cadeia de caracteres que é em duas linhas no arquivo de origem, siga um destes procedimentos:

- Finalizar a primeira linha com o caractere de continuação de linha, uma barra invertida.

- Feche a cadeia de caracteres na primeira linha com uma marca de aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa.

Não é suficiente terminar a primeira linha com \n, a sequência de escape para inserir um caractere de nova linha em uma constante de cadeia de caracteres.