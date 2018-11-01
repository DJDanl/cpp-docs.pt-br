---
title: Erro do compilador C2212
ms.date: 11/04/2016
f1_keywords:
- C2212
helpviewer_keywords:
- C2212
ms.assetid: 3fdab304-272c-4d07-bfd4-fad75170e536
ms.openlocfilehash: a632aaf9809cd306354320a21cb03b993d60a95f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50496467"
---
# <a name="compiler-error-c2212"></a>Erro do compilador C2212

'identifier': based não disponível para ponteiros para funções

Ponteiros para funções não podem ser declarados `__based`. Se você precisar de dados com base em código, use o `__declspec` palavra-chave ou o `data_seg` pragma.