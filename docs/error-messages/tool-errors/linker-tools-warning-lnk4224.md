---
title: Aviso LNK4224 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4224
dev_langs:
- C++
helpviewer_keywords:
- LNK4224
ms.assetid: 8624b70e-0b93-43cf-b457-834d38632d0b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1bdffdf3469cc3a0e5d41b0504b882513d44b63c
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34703981"
---
# <a name="linker-tools-warning-lnk4224"></a>Aviso LNK4224 (Ferramentas de Vinculador)

> *opção* não é suportado; ignorado

## <a name="remarks"></a>Comentários

Uma opção de vinculador obsoleto, inválido foi especificada e ignorada.

Por exemplo, LNK4224 pode ocorrer se uma diretiva /comment aparece em. obj. A diretiva /comment foram adicionada por meio de [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) pragma, usando a opção exestr preterido. Use dumpbin [/All](../../build/reference/all.md) para exibir as diretivas de vinculador em um arquivo. obj.

Se possível, modifique a fonte para o. obj e remova o pragma. Se você ignorar este aviso, é possível que um .executable compilado com **/clr: pure** não funcionará como esperado. O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4224.

```cpp
// LNK4224.cpp
// compile with: /c /Zi
// post-build command: link LNK4224.obj /debug /debugtype:map
int main () {
   return 0;
}
```