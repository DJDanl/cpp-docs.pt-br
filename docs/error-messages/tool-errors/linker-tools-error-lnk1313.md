---
title: Erro das Ferramentas de Vinculador LNK1313
ms.date: 11/04/2016
f1_keywords:
- LNK1313
helpviewer_keywords:
- LNK1313
ms.assetid: 5df0b72e-bb3f-428c-8d84-6084238f9827
ms.openlocfilehash: a2314f160dc6add45547082c7804ec5e2c8f2349
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194857"
---
# <a name="linker-tools-error-lnk1313"></a>Erro das Ferramentas de Vinculador LNK1313

> módulo ijw/native detectado; não é possível vincular com módulos puros

## <a name="remarks"></a>Comentários

A versão atual do Visual C++ não dá suporte à vinculação de arquivos. obj nativos ou nativos gerenciados ou mistos com arquivos. obj compilados com **/CLR: Pure**.

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

## <a name="example"></a>Exemplo

```cpp
// LNK1313.cpp
// compile with: /c /clr:pure
// a pure module
int main() {}
```

## <a name="example"></a>Exemplo

```cpp
// LNK1313_b.cpp
// compile with: /c /clr
// an IJW module
void test(){}
```

## <a name="example"></a>Exemplo

A amostra a seguir irá gerar LNK1313.

```cpp
// LNK1313_c.cpp
// compile with: /link LNK1313.obj LNK1313_b.obj
// LNK1313 warning expected
```
