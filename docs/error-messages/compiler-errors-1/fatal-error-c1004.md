---
title: "Erro fatal C1004 | Microsoft Docs"
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
  - "C1004"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1004"
ms.assetid: dbe034b0-6eb0-41b4-a50c-2fccf9e78ad4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1004
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

fim de arquivo inesperado localizada  
  
 O compilador um chegou ao final de um arquivo de origem sem resolver uma construção.  O código pode estar faltando um dos seguintes elementos:  
  
-   Uma chave de fechamento  
  
-   Um parêntese de fechamento  
  
-   Um marcador de comentário de fechamento \(\*\/\)  
  
-   Um ponto\-e\-vírgula  
  
 Para resolver este erro, verifique se há o seguinte:  
  
-   A unidade de disco padrão tem espaço suficiente para arquivos temporários, que requerem aproximadamente duas vezes mais espaço quanto o arquivo de origem.  
  
-   Uma política de `#if` que seja avaliada como falsa não tem uma política de fechamento de `#endif` .  
  
-   Um arquivo de origem não terminar com um retorno de carro e uma alimentação de linha.  
  
 O seguinte exemplo gera C1004:  
  
```  
// C1004.cpp  
#if TEST  
int main() {}  
// C1004  
```  
  
 Solução possível:  
  
```  
// C1004b.cpp  
#if TEST  
#endif  
  
int main() {}  
```