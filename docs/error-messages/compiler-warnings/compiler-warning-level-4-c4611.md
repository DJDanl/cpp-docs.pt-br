---
title: Compilador aviso (nível 4) C4611
ms.date: 11/04/2016
f1_keywords:
- C4611
helpviewer_keywords:
- C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
ms.openlocfilehash: b799c568d73a081a4d4cf5616f376f3efc9eeffb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62349666"
---
# <a name="compiler-warning-level-4-c4611"></a>Compilador aviso (nível 4) C4611

interação entre 'function' e a destruição de objeto de C++ é não portátil

Em algumas plataformas, funções, que incluem **catch** pode não oferecer suporte a semântica de objeto C++ de destruição quando estiver fora do escopo.

Para evitar comportamento inesperado, evite usar **catch** em funções que têm construtores e destruidores.

Esse aviso é emitido somente uma vez. ver [aviso pragma](../../preprocessor/warning.md).