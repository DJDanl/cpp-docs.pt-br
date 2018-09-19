---
title: Erro das LNK1237 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1237
dev_langs:
- C++
helpviewer_keywords:
- LNK1237
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9ada38fcf3a706f7852f49f60f677fb5dc10d7e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46065290"
---
# <a name="linker-tools-error-lnk1237"></a>Erro das Ferramentas de Vinculador LNK1237

durante a geração de código, compilador introduziu referência ao símbolo 'symbol' definido no módulo 'module' foi compilado com /GL

Durante a geração de código, o compilador não deve introduzir símbolos que posteriormente são resolvidos para definições compiladas **/GL**. `symbol` é um símbolo que foi introduzido e resolvido posteriormente a uma definição de compilados com **/GL**.

Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).

Para resolver das LNK1237, não compilar a largura do símbolo **/GL** ou use [/INCLUDE (forçar referências de símbolo)](../../build/reference/include-force-symbol-references.md) para forçar uma referência ao símbolo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK1237. Para resolver esse erro, não inicializar a matriz em LNK1237_a.cpp e adicione **/include: __chkstk** para o comando de link.

```
// LNK1237_a.cpp
int main() {
   char c[5000] = {0};
}
```

```
// LNK1237_b.cpp
// compile with: /GS- /GL /c LNK1237_a.cpp
// processor: x86
// post-build command: (lib LNK1237_b.obj /LTCG & link LNK1237_a.obj LNK1237_b.lib /nodefaultlib /entry:main /LTCG)
extern "C" void _chkstk(size_t s) {}
```