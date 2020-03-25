---
title: Erro do compilador C2129
ms.date: 11/04/2016
f1_keywords:
- C2129
helpviewer_keywords:
- C2129
ms.assetid: 21a8223e-1d22-4baa-9ca1-922b7f751dd0
ms.openlocfilehash: a3e2268bfc5597668e8689d093a0c2bb7f18e037
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80207279"
---
# <a name="compiler-error-c2129"></a>Erro do compilador C2129

função estática ' function ' declarada mas não definida

Uma referência posterior é feita a uma função `static` que nunca é definida.

Uma função `static` deve ser definida no escopo do arquivo. Se a função for definida em outro arquivo, ela deverá ser declarada `extern`.
