---
title: Erro do compilador C2692 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2692
dev_langs:
- C++
helpviewer_keywords:
- C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 03a9006889c5853e77b5603484ea9d18f2474241
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088365"
---
# <a name="compiler-error-c2692"></a>Erro do compilador C2692

'function_name': funções totalmente prototipadas são necessárias no compilador C com o ' / clr' opção

Quando a compilação para .NET de código gerenciado, o compilador C requer declarações de função de ANSI. Além disso, se uma função não usa nenhum parâmetro, ele deve declarar explicitamente `void` como o tipo de parâmetro.