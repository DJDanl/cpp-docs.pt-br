---
title: "Aviso LNK4253 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4253"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4253"
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4253 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

seção “section1” não mesclada em section2”; “ já mesclada em “section3”  
  
 O múltiplo detectado, o vinculador conflitante solicitações de mesclagem.  O vinculador ignorará uma das solicitações.  
  
 Uma política de **\/MERGE** são encontradas e a seção de `from` já tiver sido mesclada em uma seção diferente devido a uma opção ou a uma política anterior de **\/MERGE** \(ou devido a uma mesclagem implícita do vinculador\).  
  
 Para resolver LNK4253, remover uma das solicitações de mesclagem.  
  
 Ao atingir os computadores x86 e destinos do Windows CE edition \(BRAÇO, MIPS, SH4, e polegar\) com Visual C\+\+, a seção de .CRT agora é somente leitura.  Se seu código depende do comportamento anterior \(seções de .CRT são de leitura\/gravação\), você pode consultar comportamento inesperado.  
  
 Para obter mais informações, consulte,  
  
-   [\/MERGE \(combinar seções\)](../../build/reference/merge-combine-sections.md)  
  
-   [comment](../../preprocessor/comment-c-cpp.md)  
  
## Exemplo  
 No exemplo a seguir, o vinculador for instruído para mesclar duas vezes na seção de `.rdata` , mas em seções diferentes.  O exemplo a seguir produz LNK4253.  
  
```  
// LNK4253.cpp  
// compile with: /W1 /link /merge:.rdata=text2  
// LNK4253 expected  
#pragma comment(linker, "/merge:.rdata=.text")  
int main() {}  
```