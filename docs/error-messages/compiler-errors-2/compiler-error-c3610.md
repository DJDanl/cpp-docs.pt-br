---
title: Erro do compilador C3610 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3610
dev_langs:
- C++
helpviewer_keywords:
- C3610
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b46b3669978ff3735d5a16015ca0a01e65f07ae9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46037847"
---
# <a name="compiler-error-c3610"></a>Erro do compilador C3610

'valuetype': tipo de valor deve ser 'boxed' antes do método 'method' pode ser chamado

Por padrão, um tipo de valor não está no heap gerenciado. Antes de chamar métodos das classes de tempo de execução do .NET, como `Object`, você precisará mover o tipo de valor para o heap gerenciado.

C3610 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
