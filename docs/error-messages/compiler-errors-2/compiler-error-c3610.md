---
title: Erro do compilador C3610
ms.date: 11/04/2016
f1_keywords:
- C3610
helpviewer_keywords:
- C3610
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
ms.openlocfilehash: 9965e6420171b2ea48c8fb7bacc0a5a37ea2f227
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591038"
---
# <a name="compiler-error-c3610"></a>Erro do compilador C3610

'valuetype': tipo de valor deve ser 'boxed' antes do método 'method' pode ser chamado

Por padrão, um tipo de valor não está no heap gerenciado. Antes de chamar métodos das classes de tempo de execução do .NET, como `Object`, você precisará mover o tipo de valor para o heap gerenciado.

C3610 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**.
