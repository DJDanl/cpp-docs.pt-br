---
title: Ferramentas de vinculador LNK2028 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2028
dev_langs:
- C++
helpviewer_keywords:
- LNK2028
ms.assetid: e2b03293-6066-464d-a050-ce747bcf7f0e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9c8eaa03927f51acd3c3d84731e9ef2b282b7c6
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704148"
---
# <a name="linker-tools-error-lnk2028"></a>Erro das Ferramentas de Vinculador LNK2028

"*exported_function*" (*decorated_name*) referenciado na função "*function_containing_function_call*" (*decorated_name*)

## <a name="remarks"></a>Comentários

Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícita diferem entre compilações nativo e puras.

O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

## <a name="example"></a>Exemplo

Este exemplo de código gera um componente com uma função exportada, nativo, cuja convenção de chamada é implicitamente [cdecl](../../cpp/cdecl.md).

```cpp
// LNK2028.cpp
// compile with: /LD
__declspec(dllexport) int func() {
   return 3;
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a convenção de chamada em **/clr: pure** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2028.

```cpp
// LNK2028_b.cpp
// compile with: /clr:pure lnk2028.lib
// LNK2028 expected
int func();

int main() {
   return func();
}
```