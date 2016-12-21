---
title: "Aviso do compilador (n&#237;vel 1) C4067 | Microsoft Docs"
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
  - "C4067"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4067"
ms.assetid: 1d10353e-8cd5-4b01-9184-a06189b965a4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4067
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os tokens inesperados que seguem a política de pré\-processador \- esperou uma nova linha  
  
 O compilador localizadas e ignorado os caracteres adicionais que seguem uma política de pré\-processador.  Esse aviso é exibido apenas na compatibilidade ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\).  
  
```  
// C4067a.cpp  
// compile with: /DX /Za /W1  
#pragma warning(default:4067)  
#if defined(X)  
#else  
#endif v   // C4067  
int main()  
{  
}  
```  
  
### Para resolver esse aviso, tente o seguinte:  
  
1.  Compile com **\/Ze**.  
  
2.  Use delimitadores de comentário:  
  
```  
// C4067b.cpp  
// compile with: /DX /Za /W1  
#if defined(X)  
#else  
#endif  
int main()  
{  
}  
```