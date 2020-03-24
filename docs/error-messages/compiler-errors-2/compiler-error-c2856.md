---
title: Erro do compilador C2856
ms.date: 11/04/2016
f1_keywords:
- C2856
helpviewer_keywords:
- C2856
ms.assetid: fe616c51-124e-49e3-9dd8-883ec1660680
ms.openlocfilehash: c88610607083ecfaf5f20cd585b479991fa51b44
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201859"
---
# <a name="compiler-error-c2856"></a>Erro do compilador C2856

\#pragma hdrstop não pode estar dentro de um bloco de #if

O `hdrstop` pragma não pode ser colocado dentro do corpo de um bloco de compilação condicional.

Mova a instrução `#pragma hdrstop` para uma área que não esteja contida em um bloco de `#if/#endif`.
