---
title: Erro RC2001 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2001
helpviewer_keywords:
- RC2001
ms.assetid: 92bfb4c0-1879-4606-bb9f-ef7368707b4a
ms.openlocfilehash: 35042687b798b53857becdedba57861bd4f41a05
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191711"
---
# <a name="resource-compiler-error-rc2001"></a>Erro RC2001 (compilador de recurso)

nova linha em constante

Uma constante de cadeia de caracteres continuou em uma segunda linha sem uma barra invertida ( **\\** ) ou aspas duplas de fechamento e abertura ( **"** ).

Para interromper uma constante de cadeia de caracteres que está em duas linhas no arquivo de origem, siga um destes procedimentos:

- Terminar a primeira linha com o caractere de continuação de linha, uma barra invertida.

- Feche a cadeia de caracteres na primeira linha com aspas duplas e abra a cadeia de caracteres na linha seguinte com outra aspa.

Não é suficiente finalizar a primeira linha com \n, a sequência de escape para inserir um caractere de linha nova em uma constante de cadeia de caracteres.
