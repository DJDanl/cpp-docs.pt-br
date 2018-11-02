---
title: Erro do compilador C2856
ms.date: 11/04/2016
f1_keywords:
- C2856
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
ms.openlocfilehash: 1e515f250c8ab9d1008ded91b99176f1d86d7cd1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499600"
---
# <a name="compiler-error-c2856"></a>Erro do compilador C2856

\#pragma hdrstop não pode ser dentro de um bloco #if

O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.

Mover o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.