---
title: Aviso do compilador (nível 1) C4650
ms.date: 11/04/2016
f1_keywords:
- C4650
helpviewer_keywords:
- C4650
ms.assetid: 3190b3e3-dcd6-4846-939b-f900ab652b2a
ms.openlocfilehash: e57f1d9acba4a8734339f3b8e538120abe542efc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199562"
---
# <a name="compiler-warning-level-1-c4650"></a>Aviso do compilador (nível 1) C4650

informações de depuração não estão no cabeçalho pré-compilado; somente os símbolos globais do cabeçalho estarão disponíveis

O arquivo de cabeçalho pré-compilado não foi compilado com informações de depuração simbólica da Microsoft.

Quando vinculado, o arquivo executável resultante ou biblioteca de vínculo dinâmico não incluirá informações de depuração para os símbolos locais contidos no cabeçalho pré-compilado.

Esse aviso pode ser evitado com a recompilação do arquivo de cabeçalho pré-compilado com a opção de linha de comando [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) .
