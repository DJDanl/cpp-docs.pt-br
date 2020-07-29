---
title: Erro do Compilador C2030
ms.date: 11/04/2016
f1_keywords:
- C2030
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
ms.openlocfilehash: f9090e098d7f523bf7bc12b7fa4d9312f6ca5466
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212898"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030

um destruidor com acessibilidade ' privada protegida ' não pode ser membro de uma classe declarada ' sealed '

Uma classe Windows Runtime declarada como **`sealed`** não pode ter um destruidor privado protegido. Somente destruidores não virtuais públicos virtuais e privados são permitidos em tipos lacrados. Saiba mais em [Classes e structs ref](../../cppcx/ref-classes-and-structs-c-cx.md).

Para corrigir esse erro, altere a acessibilidade do destruidor.
