---
title: "Erro das Ferramentas de Vinculador LNK1107 | Microsoft Docs"
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
  - "LNK1107"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1107"
ms.assetid: a37a893d-5efa-4eba-8f40-6c5518b4b9d0
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1107
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

arquivo inválido ou corrompido: não é possível ler no local  
  
 A ferramenta não foi possível ler o arquivo.  Recrie o arquivo.  
  
 LNK1107 também pode ocorrer se você tentar passar um módulo \(extensão .dll de ou de .netmodule criada com [\/clr: noAssembly](../../build/reference/clr-common-language-runtime-compilation.md) ou [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)\) ao vinculador; passe o arquivo de .obj em vez disso.  
  
 Se você construir o exemplo a seguir:  
  
```  
// LNK1107.cpp  
// compile with: /clr /LD  
public ref class MyClass {  
public:  
   void Test(){}  
};  
```  
  
 e especifique **link LNK1107.dll** na linha de comando, você obterá LNK1107.  Para resolver o erro, especifique **link LNK1107.obj** em vez disso.