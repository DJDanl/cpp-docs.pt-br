---
title: "Erro das Ferramentas de Vinculador LNK1312 | Microsoft Docs"
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
  - "LNK1312"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1312"
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1312
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

arquivo inválido ou corrompido: não é possível importar do assembly  
  
 Ao criar um assembly, um arquivo diferente de um módulo ou o assembly criado com **\/clr** foram transmitidos à opção do vinculador de **\/ASSEMBLYMODULE** .  Se você tiver passado um arquivo de objeto a **\/ASSEMBLYMODULE**, transmita apenas o objeto diretamente ao vinculador, em vez de **\/ASSEMBLYMODULE**.  
  
## Exemplo  
 O exemplo a seguir cria o arquivo de .obj.  
  
```  
// LNK1312.cpp  
// compile with: /clr /LD  
public ref class A {  
public:  
   int i;  
};  
```  
  
## Exemplo  
 O exemplo a seguir produz LNK1312.  
  
```  
// LNK1312_b.cpp  
// compile with: /clr /LD /link /assemblymodule:LNK1312.obj  
// LNK1312 error expected  
public ref class M {};  
```