---
title: Erro do compilador C2129 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2129
dev_langs:
- C++
helpviewer_keywords:
- C2129
ms.assetid: 21a8223e-1d22-4baa-9ca1-922b7f751dd0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e86515a7d7c8954271578291c4ebcb1a52fc9863
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054279"
---
# <a name="compiler-error-c2129"></a>Erro do compilador C2129

função estática 'function' declarada mas não definida

Uma referência direta é feita para um `static` função nunca é definida.

Um `static` função deve ser definida dentro do escopo de arquivo. Se a função é definida em outro arquivo, ela deve ser declarada `extern`.