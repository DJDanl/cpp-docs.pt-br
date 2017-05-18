---
title: Ferramentas de vinculador LNK2028 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2028
dev_langs:
- C++
helpviewer_keywords:
- LNK2028
ms.assetid: e2b03293-6066-464d-a050-ce747bcf7f0e
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 25845cd1b0dcba6566ac4ab596a26f4b6bde191b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2028"></a>Erro das Ferramentas de Vinculador LNK2028
"exported_function" (decorated_name) referenciada na função "function_containing_function_call" (decorated_name)  
  
 Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícitas diferem entre compilações puras e nativas.  
  
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
 O exemplo a seguir cria um cliente simples que consome a função nativa. No entanto, a convenção de chamada em **/clr: puro** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2028.  
  
```  
// LNK2028_b.cpp  
// compile with: /clr:pure lnk2028.lib  
// LNK2028 expected  
int func();  
  
int main() {  
   return func();  
}  
```
