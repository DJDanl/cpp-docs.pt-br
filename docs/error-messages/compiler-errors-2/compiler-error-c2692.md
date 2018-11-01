---
title: Erro do compilador C2692
ms.date: 11/04/2016
f1_keywords:
- C2692
helpviewer_keywords:
- C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
ms.openlocfilehash: c469f4944417c9116c7316b01642dd4b370b8c4b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50611153"
---
# <a name="compiler-error-c2692"></a>Erro do compilador C2692

'function_name': funções totalmente prototipadas são necessárias no compilador C com o ' / clr' opção

Quando a compilação para .NET de código gerenciado, o compilador C requer declarações de função de ANSI. Além disso, se uma função não usa nenhum parâmetro, ele deve declarar explicitamente `void` como o tipo de parâmetro.