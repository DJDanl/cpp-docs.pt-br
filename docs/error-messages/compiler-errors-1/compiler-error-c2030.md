---
title: Erro do Compilador C2030
ms.date: 11/04/2016
f1_keywords:
- C2030
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
ms.openlocfilehash: e3f3936e6fd37da16c923cb482f45cec11833b3c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208026"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030

um destruidor com acessibilidade ' privada protegida ' não pode ser membro de uma classe declarada ' sealed '

Uma classe Windows Runtime declarada como `sealed` não pode ter um destruidor privado protegido. Somente destruidores não virtuais públicos virtuais e privados são permitidos em tipos lacrados. Saiba mais em [Classes e structs ref](../../cppcx/ref-classes-and-structs-c-cx.md).

Para corrigir esse erro, altere a acessibilidade do destruidor.
