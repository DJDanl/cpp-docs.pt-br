---
title: Erro do compilador C3398
ms.date: 11/04/2016
f1_keywords:
- C3398
helpviewer_keywords:
- C3398
ms.assetid: 26f8c8a4-526f-415b-8047-155c5cd4f180
ms.openlocfilehash: 3b688012009a87c1e3d0db05e47133893daeaf34
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50451058"
---
# <a name="compiler-error-c3398"></a>Erro do compilador C3398

'operator': não é possível converter de 'function_signature' para 'function_pointer'. Expressão fonte deve ser um símbolo de função

Quando o [clrcall](../../cpp/clrcall.md) convenção de chamada não for especificada ao compilar com **/clr**, o compilador gera dois pontos de entrada (endereços) para cada função, um ponto de entrada nativo e um ponto de entrada gerenciado.

Por padrão, o compilador retorna o ponto de entrada nativo, mas há alguns casos em que o ponto de entrada gerenciado for desejado (por exemplo ao atribuir o endereço para um `__clrcall` ponteiro de função). Para o compilador de maneira confiável, escolha o ponto de entrada gerenciado em uma atribuição, o lado direito deve ser um símbolo de função.