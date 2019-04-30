---
title: Erro do compilador C2856
ms.date: 11/04/2016
f1_keywords:
- C2856
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
ms.openlocfilehash: 1e515f250c8ab9d1008ded91b99176f1d86d7cd1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406841"
---
# <a name="compiler-error-c2856"></a>Erro do compilador C2856

\#pragma hdrstop não pode ser dentro de um bloco #if

O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.

Mover o `#pragma hdrstop` instrução para uma área que não está contida em um `#if/#endif` bloco.