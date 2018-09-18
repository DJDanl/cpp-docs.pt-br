---
title: Compilador aviso (nível 3) C4023 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4023
dev_langs:
- C++
helpviewer_keywords:
- C4023
ms.assetid: 615d5374-d7c1-42eb-acfd-917c053270c8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fe457f9a6181fa11b34dd615ad4d5b9637c8bddc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045166"
---
# <a name="compiler-warning-level-3-c4023"></a>Compilador aviso (nível 3) C4023

'symbol': ponteiro baseado transmitido para uma função sem protótipo: número do parâmetro

Passando um ponteiro baseado para uma função sem protótipo faz com que o ponteiro para ser normalizados, com resultados imprevisíveis.

Esse aviso pode ser corrigido se você usar funções de protótipo que são passadas ponteiros com base.