---
title: Ferramentas de vinculador LNK1237 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1237
dev_langs:
- C++
helpviewer_keywords:
- LNK1237
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1ffc337d6b1548db4717dc4b87ff8aa25ef92e93
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1237"></a>Erro das Ferramentas de Vinculador LNK1237
durante a geração de código, compilador introduziu referência para o símbolo 'symbol' definido no módulo compilado com /GL ' module'  
  
 Durante a geração de código, o compilador não deve apresentar símbolos que posteriormente são resolvidos para definições de compilação **/GL**. `symbol` é um símbolo que foi introduzido e resolvido posteriormente a uma definição de compilação com **/GL**.  
  
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