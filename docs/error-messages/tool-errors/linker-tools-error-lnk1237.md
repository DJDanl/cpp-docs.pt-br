---
title: "Erro das Ferramentas de Vinculador LNK1237 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK1237"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1237"
ms.assetid: 8722ffa8-096a-4bb0-85f9-f3aa0e10872a
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1237
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

durante a geração de código, o compilador o introduziu a referência ao símbolo “símbolo” definido no módulo “módulo” compilado com \/GL  
  
 Durante a geração de código, o compilador não deve introduzir símbolos que são resolvidos posteriormente a **\/GL**compilado definições.  `symbol` é um símbolo que é apresentado e resolvido posteriormente para uma definição criada com **\/GL**.  
  
 Para obter mais informações, consulte [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md).  
  
 Para resolver LNK1237, não crie o símbolo **\/GL** nem use [\/INCLUDE \(forçar referências de símbolo\)](../../build/reference/include-force-symbol-references.md) para forçar uma referência ao símbolo.  
  
## Exemplo  
 O exemplo a seguir produz LNK1237.  Para resolver esse erro, não inicializar a matriz em LNK1237\_a.cpp e não adicione **\/include:\_\_chkstk** ao comando do link.  
  
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