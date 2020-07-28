---
title: Erro do compilador C2129
ms.date: 11/04/2016
f1_keywords:
- C2129
helpviewer_keywords:
- C2129
ms.assetid: 21a8223e-1d22-4baa-9ca1-922b7f751dd0
ms.openlocfilehash: 9cf414200dcfad8ae617e16e111bd26b19a315a6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220425"
---
# <a name="compiler-error-c2129"></a>Erro do compilador C2129

função estática ' function ' declarada mas não definida

É feita uma referência de encaminhamento a uma **`static`** função que nunca é definida.

Uma **`static`** função deve ser definida no escopo do arquivo. Se a função for definida em outro arquivo, ela deverá ser declarada **`extern`** .
