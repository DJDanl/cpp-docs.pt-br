---
title: Compilador aviso (nível 3) C4023
ms.date: 11/04/2016
f1_keywords:
- C4023
helpviewer_keywords:
- C4023
ms.assetid: 615d5374-d7c1-42eb-acfd-917c053270c8
ms.openlocfilehash: 4d433ff7d6b323fcb8508872d4e755f893a50f5c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402346"
---
# <a name="compiler-warning-level-3-c4023"></a>Compilador aviso (nível 3) C4023

'symbol': ponteiro baseado transmitido para uma função sem protótipo: número do parâmetro

Passando um ponteiro baseado para uma função sem protótipo faz com que o ponteiro para ser normalizados, com resultados imprevisíveis.

Esse aviso pode ser corrigido se você usar funções de protótipo que são passadas ponteiros com base.