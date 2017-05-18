---
title: Ferramentas de vinculador LNK2031 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2031
dev_langs:
- C++
helpviewer_keywords:
- LNK2031
ms.assetid: 18ed4b6e-3e75-443c-bbd8-2f6030dc89ee
caps.latest.revision: 6
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
ms.openlocfilehash: 3131148a5f3582c7f76ae124f9d690b7055475e3
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2031"></a>Erro das Ferramentas de Vinculador LNK2031
não é possível gerar p/invoke para decorated_name "function_declaration"; convenção de chamada faltando nos metadados  
  
 Ao tentar importar uma função nativa em uma imagem pura, lembre-se de que as convenções de chamada implícitas diferem entre compilações puras e nativas. Para obter mais informações sobre imagens puras, consulte [puro e código verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
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
 O exemplo a seguir cria um cliente simples que consome a função nativa. No entanto, a convenção de chamada em **/clr: puro** é [clrcall](../../cpp/clrcall.md). O exemplo a seguir gera LNK2031.  
  
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
 O exemplo a seguir mostra como utilizar a função nativa de uma imagem simples. Observe o explícita **cdecl** especificador de convenção de chamada.  
  
```  
// LNK2031_c.cpp  
// compile with: /clr:pure LNK2031.lib  
extern "C" int __cdecl func();  
  
int main() {  
   return func();  
}  
```
