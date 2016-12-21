---
title: "Erro do Compilador C3172 | Microsoft Docs"
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
  - "C3172"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3172"
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3172
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“module\_name”: não pode especificar atributos diferentes de idl\_module em um projeto  
  
 os atributos de[idl\_module](../../windows/idl-module.md) com o mesmo nome `dllname` mas diferente ou parâmetrosde `version`encontradas em dois dos arquivos em uma compilação.  Somente um atributo exclusivo de `idl_module` pode ser especificado pela compilação.  
  
 Os atributos de `idl_module` idênticos podem ser especificados em mais de um arquivo de código\-fonte.  
  
 Por exemplo, se os seguintes atributos de `idl_module` foram localizados:  
  
```  
// C3172.cpp  
[module(name="MyMod")];  
[ idl_module(name="x", dllname="file.dll", version="1.1") ];  
int main() {}  
```  
  
 Em seguida, e  
  
```  
// C3172b.cpp  
// compile with: C3172.cpp  
// C3172 expected  
[ idl_module(name="x", dllname="file.dll", version="1.0") ];  
```  
  
 o compilador geraria C3172 \(observe os valores diferentes da versão\).