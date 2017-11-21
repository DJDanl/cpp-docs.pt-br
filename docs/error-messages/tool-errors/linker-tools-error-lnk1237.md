---
title: Ferramentas de vinculador LNK1237 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1237
dev_langs: C++
helpviewer_keywords: LNK1237
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 43ab77f153b6e53709422a1826a6beee25d65b2a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-error-lnk1237"></a>Erro das Ferramentas de Vinculador LNK1237
durante a geração de código, compilador introduziu referência para o símbolo 'symbol' definido no módulo compilado com /GL ' module'  
  
 Durante a geração de código, o compilador não deve apresentar símbolos que posteriormente são resolvidos para definições de compilação **/GL**. `symbol`é um símbolo que foi introduzido e resolvido posteriormente a uma definição de compilação com **/GL**.  
  
 Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).  
  
 Para resolver LNK1237, não compilar a largura do símbolo **/GL** ou use [/INCLUDE (forçar referências de símbolo)](../../build/reference/include-force-symbol-references.md) para forçar uma referência para o símbolo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1237. Para resolver esse erro, não inicializar a matriz em LNK1237_a.cpp e adicionar **/include: __chkstk** para o comando de link.  
  
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