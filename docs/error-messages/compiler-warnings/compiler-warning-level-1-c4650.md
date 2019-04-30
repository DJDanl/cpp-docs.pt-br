---
title: Compilador aviso (nível 1) C4650
ms.date: 11/04/2016
f1_keywords:
- C4650
helpviewer_keywords:
- C4650
ms.assetid: 3190b3e3-dcd6-4846-939b-f900ab652b2a
ms.openlocfilehash: ea3f1b6e792239692960e74c8360c6c3a1323815
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393526"
---
# <a name="compiler-warning-level-1-c4650"></a>Compilador aviso (nível 1) C4650

informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis

O arquivo de cabeçalho pré-compilado não foi compilado com informações de depuração simbólicas de Microsoft.

Quando vinculado, o arquivo executável ou dynamic-link library resultante não incluirá informações de depuração para símbolos locais contido no cabeçalho pré-compilado.

Esse aviso pode ser evitado ao recompilar o arquivo de cabeçalho pré-compilado com o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção de linha de comando.