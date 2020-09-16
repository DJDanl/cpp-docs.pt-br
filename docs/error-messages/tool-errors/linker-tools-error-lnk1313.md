---
title: Erro das Ferramentas de Vinculador LNK1313
ms.date: 11/04/2016
f1_keywords:
- LNK1313
helpviewer_keywords:
- LNK1313
ms.assetid: 5df0b72e-bb3f-428c-8d84-6084238f9827
ms.openlocfilehash: 03ff61a1f3501b3ea106138e957a657ed064e645
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683436"
---
# <a name="linker-tools-error-lnk1313"></a>Erro das Ferramentas de Vinculador LNK1313

> módulo ijw/native detectado; não é possível vincular com módulos puros

## <a name="remarks"></a>Comentários

A versão atual do Visual C++ não dá suporte à vinculação de arquivos. obj nativos ou nativos gerenciados ou mistos com arquivos. obj compilados com **/CLR: Pure**.

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

## <a name="examples"></a>Exemplos

```cpp
// LNK1313.cpp
// compile with: /c /clr:pure
// a pure module
int main() {}
```

```cpp
// LNK1313_b.cpp
// compile with: /c /clr
// an IJW module
void test(){}
```

A amostra a seguir irá gerar LNK1313.

```cpp
// LNK1313_c.cpp
// compile with: /link LNK1313.obj LNK1313_b.obj
// LNK1313 warning expected
```
