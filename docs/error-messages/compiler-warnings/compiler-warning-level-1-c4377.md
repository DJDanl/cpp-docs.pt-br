---
title: Aviso do compilador (nível 1) C4377
ms.date: 11/04/2016
f1_keywords:
- C4377
helpviewer_keywords:
- C4377
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
ms.openlocfilehash: b75b6bee88d0b72e77b32e58ae2f4634a9c30fa0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186992"
---
# <a name="compiler-warning-level-1-c4377"></a>Aviso do compilador (nível 1) C4377

os tipos nativos são privados por padrão; -d1PrivateNativeTypes é preterido

Em versões anteriores, os tipos nativos em assemblies eram públicos por padrão e uma opção de compilador interna e não documentada ( **/d1PrivateNativeTypes**) foi usada para torná-los particulares.

Todos os tipos, nativo e CLR, agora são privados por padrão em um assembly, portanto, **/d1PrivateNativeTypes** não é mais necessário.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4377.

```cpp
// C4377.cpp
// compile with: /clr /d1PrivateNativeTypes /W1
// C4377 warning expected
int main() {}
```
