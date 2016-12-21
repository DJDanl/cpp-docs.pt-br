---
title: "Erro das Ferramentas de Vinculador LNK1179 | Microsoft Docs"
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
  - "LNK1179"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1179"
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1179
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

arquivo inválido ou corrompido: COMDAT duplicado “nome de arquivo”  
  
 Um módulo de objeto contém duas ou mais COMDATs com o mesmo nome.  
  
 Esse erro pode ser causado por meio [\/H](../../build/reference/h-restrict-length-of-external-names.md), o que limita o comprimento dos nomes externos, e, [\/Gy](../../build/reference/gy-enable-function-level-linking.md)de empacotamento funções em COMDATs.  
  
## Exemplo  
 No código a seguir, `function1` e `function2` são idênticos nos primeiros oito caracteres.  A compilação com **\/Gy** e **\/H8** gerencie um erro do link.  
  
```  
void function1(void);  
void function2(void);  
  
int main() {  
    function1();  
    function2();  
}  
  
void function1(void) {}  
void function2(void) {}  
```