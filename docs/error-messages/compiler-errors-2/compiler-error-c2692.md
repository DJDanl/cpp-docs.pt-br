---
title: Erro do compilador C2692
ms.date: 11/04/2016
f1_keywords:
- C2692
helpviewer_keywords:
- C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
ms.openlocfilehash: a82ee0bead9e4e7a92c16df89eee86288f562de9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216096"
---
# <a name="compiler-error-c2692"></a>Erro do compilador C2692

' function_name ': funções totalmente protótipos necessárias no compilador C com a opção '/CLR '

Ao compilar para código gerenciado do .NET, o compilador C requer declarações de função ANSI. Além disso, se uma função não usar parâmetros, ela deverá declarar explicitamente **`void`** como o tipo de parâmetro.
