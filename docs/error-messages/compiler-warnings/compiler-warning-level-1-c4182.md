---
title: Compilador aviso (nível 1) C4182
ms.date: 11/04/2016
f1_keywords:
- C4182
helpviewer_keywords:
- C4182
ms.assetid: 8970f3c6-e2dd-407e-b2ec-964360eb8b43
ms.openlocfilehash: 49e3e2f62b4be50d14cb8da3d776b4640be7160c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391628"
---
# <a name="compiler-warning-level-1-c4182"></a>Compilador aviso (nível 1) C4182

\#incluir o nível de aninhamento é 'number' profundo; possível recursão infinita

O compilador ficou sem espaço suficiente no heap devido ao número de aninhada incluem arquivos. Um arquivo de inclusão está aninhado quando ela está incluída, de outro arquivo de inclusão.

Esta mensagem é informativa e precede o erro [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md).