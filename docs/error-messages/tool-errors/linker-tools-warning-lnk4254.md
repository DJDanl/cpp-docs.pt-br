---
title: "Aviso LNK4254 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4254"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4254"
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4254 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

secione “section1” \(deslocamento\) mesclada em “section2” \(deslocamento\) com atributos diferentes  
  
 O conteúdo de uma seção foram mesclados em outra, mas os atributos das duas seções são diferentes.  O programa pode gerar resultados inesperados.  Por exemplo, os dados que você quisesse ser somente leitura agora podem estar em uma seção gravável.  
  
 Para resolver LNK4254, alterar ou remover a solicitação de mesclagem.  
  
 Ao atingir os computadores x86 e destinos do Windows CE edition \(BRAÇO, MIPS, SH4, e polegar\) com Visual C\+\+, a seção de .CRT é somente leitura.  Se seu código depende do comportamento anterior \(seções de .CRT são de leitura\/gravação\), você pode consultar comportamento inesperado.  
  
 Para obter mais informações, consulte,  
  
-   [\/MERGE \(combinar seções\)](../../build/reference/merge-combine-sections.md)  
  
-   [comment](../../preprocessor/comment-c-cpp.md)  
  
## Exemplo  
 O exemplo a seguir produz LNK4254.  
  
```  
// LNK4254.cpp  
// compile with: /W1 /link /WX  
// LNK4254 expected  
#pragma comment(linker, "/merge:.data=.text")  
int main() {}  
```