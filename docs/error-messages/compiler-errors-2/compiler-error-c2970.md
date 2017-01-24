---
title: "Erro do Compilador C2970 | Microsoft Docs"
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
  - "C2970"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2970"
ms.assetid: 21d90348-20d3-438c-b278-efdbfb93a7d2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2970
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: parâmetro “param” do modelo: “arg”: uma expressão que envolve objetos com vinculação interno não pode ser usada como um argumento que não seja do tipo  
  
 Você não pode usar o nome ou o endereço de uma variável estática como um argumento do modelo.  A classe do modelo espera um valor de const que possa ser avaliada em tempo de compilação.  
  
 O seguinte exemplo gera C2970:  
  
```  
// C2970.cpp  
// compile with: /c  
static int si;  
// could declare nonstatic to resolve all errors  
// int si;  
  
template <int i>   
class X {};  
  
template <int *pi>   
class Y {};  
  
X<si> anX;   // C2970 cannot use static variable in templates  
  
// this would also work  
const int i = 10;  
X<i> anX2;  
```