---
title: "C2813 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2813"
ms.assetid: 6cf2135f-7b82-42d1-909a-5e864308a09c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2813 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não há suporte para \#import \/MP  
  
 C2813 é emitida se um comando de compilador que você especificar o **\/MP** contém a opção de compilador e dois ou mais arquivos de compilação e um ou mais arquivos de[\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva de pré\-processamento. O [\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva gera classes C\+\+ dos tipos na biblioteca de tipos especificada e grava essas classes em dois arquivos de cabeçalho. O [\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva não tem suporte porque se várias unidades de compilação importar a mesma biblioteca de tipos, essas unidades estão em conflito ao tentar gravar os mesmos arquivos de cabeçalho ao mesmo tempo.  
  
 Esse erro de compilador e o **\/MP** opção de compilador são novos no [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)].  
  
## Exemplo  
 O exemplo a seguir gera C2813. Linha de comando na "compilar com:" comentário indica ao compilador para usar o **\/MP** e **\/c** Opções do compilador para compilar vários arquivos. Pelo menos um dos arquivos contém o [\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva. Podemos usar o mesmo arquivo duas vezes para fins de teste, este exemplo.  
  
```  
// C2813.cpp // compile with: /MP /c C2813.cpp C2813.cpp #import "C:\windows\system32\stdole2.tlb"   // C2813 int main() { }  
```