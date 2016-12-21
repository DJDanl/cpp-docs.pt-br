---
title: "Erro do Compilador C3170 | Microsoft Docs"
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
  - "C3170"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3170"
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3170
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode ter diferentes identificadores do módulo em um projeto  
  
 os atributos de[módulo](../../windows/module-cpp.md) com nomes diferentes encontradas em dois dos arquivos em uma compilação.  Somente um atributo exclusivo de `module` pode ser especificado pela compilação.  
  
 Os atributos de `module` idênticos podem ser especificados em mais de um arquivo de código\-fonte.  
  
 Por exemplo, se os seguintes atributos do módulo foi encontrado:  
  
```  
// C3170.cpp  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];  
int main() {}  
```  
  
 Em seguida, e  
  
```  
// C3170b.cpp  
// compile with: C3170.cpp  
// C3170 expected  
[ module(name="MyModule1", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];  
```  
  
 o compilador geraria C3170 \(observe os nomes diferentes\).