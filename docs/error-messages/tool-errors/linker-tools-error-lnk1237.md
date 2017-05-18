---
title: Ferramentas de vinculador LNK1237 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1237
dev_langs:
- C++
helpviewer_keywords:
- LNK1237
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
caps.latest.revision: 13
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
ms.openlocfilehash: 56d140a4538703da1076b8648fb1d0818173d8fa
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1237"></a>Erro das Ferramentas de Vinculador LNK1237
durante a geração de código, o compilador introduzido referência símbolo 'symbol' definido no módulo compilado com /GL ' module'  
  
 Durante a geração de código, o compilador não deve introduzir símbolos que posteriormente são resolvidos para definições de compilação **/GL**. `symbol`é um símbolo que foi introduzido e resolvido posteriormente a uma definição de compilação com **/GL**.  
  
 Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).  
  
 Para resolver LNK1237, não compilar o símbolo com **/GL** ou use [/INCLUDE (forçar referências de símbolo)](../../build/reference/include-force-symbol-references.md) para forçar uma referência para o símbolo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1237. Para resolver esse erro, não inicializar a matriz em LNK1237_a.cpp e adicionar **/ incluem: __chkstk** para o comando de link.  
  
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
