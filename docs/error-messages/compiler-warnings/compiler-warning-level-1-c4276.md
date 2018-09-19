---
title: Compilador aviso (nível 1) C4276 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4276
dev_langs:
- C++
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 40a6c85b460e9718a8816598afb016e9c7a493b9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116016"
---
# <a name="compiler-warning-level-1-c4276"></a>Compilador aviso (nível 1) C4276

'function': nenhum protótipo fornecido; assumido sem parâmetros

Quando você toma o endereço de uma função com o [stdcall](../../cpp/stdcall.md) convenção de chamada, você deve fornecer um protótipo para que o compilador possa criar o nome da função decorada. Uma vez que *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, assume a função não tem parâmetros.