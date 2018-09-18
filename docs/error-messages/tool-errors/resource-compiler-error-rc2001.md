---
title: RC2001 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2001
dev_langs:
- C++
helpviewer_keywords:
- RC2001
ms.assetid: 92bfb4c0-1879-4606-bb9f-ef7368707b4a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d75d0f906ba0d7be75ca5177bc1f58bccd226251
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46039966"
---
# <a name="resource-compiler-error-rc2001"></a>Erro RC2001 (compilador de recurso)

Newline em constante

Uma constante de cadeia de caracteres foi retomada em uma segunda linha sem qualquer um, uma barra invertida (**\\**) ou de abertura e fechamento aspas duplas (**"**).

Para interromper uma constante de cadeia de caracteres que é em duas linhas no arquivo de origem, siga um destes procedimentos:

- Finalizar a primeira linha com o caractere de continuação de linha, uma barra invertida.

- Feche a cadeia de caracteres na primeira linha com uma marca de aspas duplas e abra a cadeia de caracteres na próxima linha com outra aspa.

Não é suficiente terminar a primeira linha com \n, a sequência de escape para inserir um caractere de nova linha em uma constante de cadeia de caracteres.