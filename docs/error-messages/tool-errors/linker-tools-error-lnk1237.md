---
title: Erro das Ferramentas de Vinculador LNK1237
ms.date: 11/04/2016
f1_keywords:
- LNK1237
helpviewer_keywords:
- LNK1237
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
ms.openlocfilehash: c56b2eb86c7605fb3330d7b1bb01e3235466ede6
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990967"
---
# <a name="linker-tools-error-lnk1237"></a>Erro das Ferramentas de Vinculador LNK1237

durante a geração de código, o compilador introduziu a referência ao símbolo ' Symbol ' definido no módulo ' module ' compilado com/GL

Durante a geração de código, o compilador não deve introduzir símbolos que são resolvidos posteriormente para definições **/GL**compiladas. `symbol` é um símbolo que foi introduzido e posteriormente resolvido para uma definição compilada com **/GL**.

Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).

Para resolver LNK1237, não compile o símbolo com **/GL** ou use [/include (Force Symbol References)](../../build/reference/include-force-symbol-references.md) para forçar uma referência ao símbolo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK1237. Para resolver esse erro, não inicialize a matriz em LNK1237_a. cpp e adicione **/include: __chkstk** ao comando de link.

```cpp
// LNK1237_a.cpp
int main() {
   char c[5000] = {0};
}
```

```cpp
// LNK1237_b.cpp
// compile with: /GS- /GL /c LNK1237_a.cpp
// processor: x86
// post-build command: (lib LNK1237_b.obj /LTCG & link LNK1237_a.obj LNK1237_b.lib /nodefaultlib /entry:main /LTCG)
extern "C" void _chkstk(size_t s) {}
```
