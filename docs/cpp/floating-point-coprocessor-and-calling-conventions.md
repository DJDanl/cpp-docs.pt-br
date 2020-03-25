---
title: Coprocessador de ponto flutuante e convenções de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- floating-point numbers [C++]
- floating-point coprocessor
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
ms.openlocfilehash: c70dd3b049ca353acc8a504df52b2c61feaf1974
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188589"
---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada

Se você estiver escrevendo rotinas de assembly para o coprocessador de ponto flutuante, você deve preservar a palavra de controle de ponto flutuante e limpar a pilha do coprocessador, a menos que você esteja retornando um valor **flutuante** ou **duplo** (que sua função deve retornar em St (0)).

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
