---
title: Erro do Compilador C2030
ms.date: 11/04/2016
f1_keywords:
- C2030
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
ms.openlocfilehash: 217f97d205e1da075277b8b0bc22ff3baab13482
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602170"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030

um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'selada'

Uma classe de tempo de execução do Windows declarado como `sealed` não pode ter um destruidor privado protegido. Somente os destruidores não virtual públicos virtuais e privados são permitidos em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).

Para corrigir esse erro, altere a acessibilidade do destruidor.