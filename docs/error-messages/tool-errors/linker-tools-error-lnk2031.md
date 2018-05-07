---
title: Ferramentas de vinculador LNK2031 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2031
dev_langs:
- C++
helpviewer_keywords:
- LNK2031
ms.assetid: 18ed4b6e-3e75-443c-bbd8-2f6030dc89ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 179702b3e162ad9f22fd887d60c5a5c2d0bc8559
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk2031"></a>Erro das Ferramentas de Vinculador LNK2031
não é possível gerar p/invoke para decorated_name "function_declaration"; chamando convenção faltante nos metadados  
  
 Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícita diferem entre compilações nativo e puras. Para obter mais informações sobre imagens puras, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 Este exemplo de código gera um componente com uma função exportada, nativo, cuja convenção de chamada é implicitamente [cdecl](../../cpp/cdecl.md).  
  
```  
// LNK2031.cpp  
// compile with: /LD  
extern "C" {  
   __declspec(dllexport) int func() { return 3; }  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um cliente puro que consome a função nativa. No entanto, a convenção de chamada em **/clr: pure** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2031.  
  
```  
// LNK2031_b.cpp  
// compile with: /clr:pure LNK2031.lib  
// LNK2031 expected  
extern "C" int func();  
  
int main() {  
   return func();  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como utilizar a função nativa de uma imagem pura. Observe o explícita **cdecl** especificador de convenção de chamada.  
  
```  
// LNK2031_c.cpp  
// compile with: /clr:pure LNK2031.lib  
extern "C" int __cdecl func();  
  
int main() {  
   return func();  
}  
```