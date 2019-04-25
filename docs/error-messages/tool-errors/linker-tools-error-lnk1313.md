---
title: Erro das Ferramentas de Vinculador LNK1313
ms.date: 11/04/2016
f1_keywords:
- LNK1313
helpviewer_keywords:
- LNK1313
ms.assetid: 5df0b72e-bb3f-428c-8d84-6084238f9827
ms.openlocfilehash: 380df2bff305acc47e423d69ea702d77c4eafdfd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160426"
---
# <a name="linker-tools-error-lnk1313"></a>Erro das Ferramentas de Vinculador LNK1313

> módulo ijw/native detectado; não é possível vincular com módulos puros

## <a name="remarks"></a>Comentários

A versão atual do Visual C++ não oferece suporte à vinculação de arquivos. obj de código gerenciado/nativo mistos ou nativos com arquivos. obj compilados com **/clr: pure**.

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

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