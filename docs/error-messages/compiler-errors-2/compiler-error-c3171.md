---
title: "Erro do Compilador C3171 | Microsoft Docs"
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
  - "C3171"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3171"
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3171
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“módulo”: não pode especificar atributos diferentes do módulo em um projeto  
  
 os atributos de[módulo](../../windows/module-cpp.md) com listas de parâmetros diferentes encontradas em dois dos arquivos em uma compilação.  Somente um atributo exclusivo de `module` pode ser especificado pela compilação.  
  
 Os atributos de `module` idênticos podem ser especificados em mais de um arquivo de código\-fonte.  
  
 Por exemplo, se os seguintes atributos de `module` foram localizados:  
  
```  
// C3171.cpp  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.0") ];  
int main() {}  
```  
  
 Em seguida, e  
  
```  
// C3171b.cpp  
// compile with: C3171.cpp  
// C3171 expected  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.1") ];  
```  
  
 o compilador geraria C3171 \(observe os valores diferentes da versão\).