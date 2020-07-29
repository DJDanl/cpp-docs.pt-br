---
title: Erro do compilador C2212
ms.date: 11/04/2016
f1_keywords:
- C2212
helpviewer_keywords:
- C2212
ms.assetid: 3fdab304-272c-4d07-bfd4-fad75170e536
ms.openlocfilehash: c243925548f8c90bdff49421b0d38357b9e677a3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216278"
---
# <a name="compiler-error-c2212"></a>Erro do compilador C2212

' identifier ': não __based disponível para ponteiros para funções

Ponteiros para funções não podem ser declarados **`__based`** . Se você precisar de dados baseados em código, use a **`__declspec`** palavra-chave ou o `data_seg` pragma.
