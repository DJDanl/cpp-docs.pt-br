---
title: Erro do compilador C2129
ms.date: 11/04/2016
f1_keywords:
- C2129
helpviewer_keywords:
- C2129
ms.assetid: 21a8223e-1d22-4baa-9ca1-922b7f751dd0
ms.openlocfilehash: e55107419235420d272c738e9d8ef7cf277c11c9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50593447"
---
# <a name="compiler-error-c2129"></a>Erro do compilador C2129

função estática 'function' declarada mas não definida

Uma referência direta é feita para um `static` função nunca é definida.

Um `static` função deve ser definida dentro do escopo de arquivo. Se a função é definida em outro arquivo, ela deve ser declarada `extern`.