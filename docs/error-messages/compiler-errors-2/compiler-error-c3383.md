---
title: Erro do compilador C3383
ms.date: 11/04/2016
f1_keywords:
- C3383
helpviewer_keywords:
- C3383
ms.assetid: ceb7f725-f417-4dc3-8496-0f413bb76687
ms.openlocfilehash: 38aea188eeac90cd23d9203a53b4e630be2f115b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62367325"
---
# <a name="compiler-error-c3383"></a>Erro do compilador C3383

'operator new' não é suportado com /CLR: safe

O arquivo de saída de um **/CLR: safe** compilação é um arquivo que é comprovadamente fortemente tipado e não há suporte para ponteiros.

Para obter mais informações, consulte

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Problemas de migração de 64 bits do Visual C++ comuns](../../build/common-visual-cpp-64-bit-migration-issues.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3383.

```
// C3383.cpp
// compile with: /clr:safe
int main() {
   char* pCharArray = new char[256];  // C3383
}
```