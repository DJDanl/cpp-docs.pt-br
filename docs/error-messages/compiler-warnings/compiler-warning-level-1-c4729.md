---
title: Compilador aviso (nível 1) C4729
ms.date: 11/04/2016
f1_keywords:
- C4729
helpviewer_keywords:
- C4729
ms.assetid: 36a0151f-f258-48d9-9444-ae6d41ff70a4
ms.openlocfilehash: f5f93cadd97eefe0d6c6da97be99ec5fd82ece24
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386389"
---
# <a name="compiler-warning-level-1-c4729"></a>Compilador aviso (nível 1) C4729

avisos baseados em função muito grande para um gráfico de fluxo

Esse aviso é gerado quando uma função é muito grande para ser compilado com a verificação confiável para situações que geram um aviso. Esse aviso só é gerado quando o [/Od](../../build/reference/od-disable-debug.md) opção de compilador usada.

Para resolver este aviso, divida a função em funções menores.