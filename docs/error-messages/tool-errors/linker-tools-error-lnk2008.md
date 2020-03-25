---
title: Erro das Ferramentas de Vinculador LNK2008
ms.date: 11/04/2016
f1_keywords:
- LNK2008
helpviewer_keywords:
- LNK2008
ms.assetid: bbcd83c5-c8ae-439e-a033-63643a5bb373
ms.openlocfilehash: c7794d09f7eeb9dceba7098ca7af90ccf2eeccad
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194818"
---
# <a name="linker-tools-error-lnk2008"></a>Erro das Ferramentas de Vinculador LNK2008

O destino de correção não está alinhado ' symbol_name '

O LINK encontrou um destino de correção no arquivo de objeto que não estava alinhado corretamente.

Esse erro pode ser causado por um alinhamento de separador personalizado (por exemplo, #pragma [Pack](../../preprocessor/pack.md)), modificador de [alinhamento](../../cpp/align-cpp.md) ou usando o código de linguagem do assembly que modifica o alinhamento da bifurcação.

Se o seu código não usar nenhuma das opções acima, isso pode ser causado pelo compilador.
