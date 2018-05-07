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
ms.openlocfilehash: 7347e8edda7ad8b317d4e6e02dfc9345ac76f269
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk2028"></a>Erro das Ferramentas de Vinculador LNK2028
"exported_function" (decorated_name) referenciado na função "function_containing_function_call" (decorated_name)  
  
 Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícita diferem entre compilações nativo e puras.  
  
## <a name="example"></a>Exemplo  
 Este exemplo de código gera um componente com uma função exportada, nativo, cuja convenção de chamada é implicitamente [cdecl](../../cpp/cdecl.md).  
  
```  
// LNK2028.cpp  
// compile with: /LD  
__declspec(dllexport) int func() {  
   return 3;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a convenção de chamada em **/clr: pure** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2028.  
  
```  
// LNK2028_b.cpp  
// compile with: /clr:pure lnk2028.lib  
// LNK2028 expected  
int func();  
  
int main() {  
   return func();  
}  
```