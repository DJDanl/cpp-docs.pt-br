---
title: "Aviso do compilador (n&#237;vel 3) C4414 | Microsoft Docs"
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
  - "C4414"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4414"
ms.assetid: bc81d3ad-55dc-4a6b-a6f2-ec0ef38347df
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4414
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: ignorando curto funcionando convertido em próximo  
  
 Os saltos curtas gerenciem a instrução compacta que ramificações para um endereço dentro de um intervalo limitado da instrução.  A instrução incluir um deslocamento curto que representa a distância entre o salto e o endereço de destino, a definição de função.  Durante vincular uma função pode ser movida ou sujeita às otimizações de link\- hora que causam a função a ser movida fora do intervalo alcançável de um deslocamento curto.  O compilador deve gerar um registro especial para o salto, o que requer a instrução de jmp para ser NEAR ou DISTANTE.  O compilador fez a conversão.  
  
 Por exemplo, o seguinte código gerenciado C4414:  
  
```  
// C4414.cpp  
// compile with: /W3 /c  
// processor: x86  
int DoParityEven();  
int DoParityOdd();  
unsigned char global;  
int __declspec(naked) DoParityEither()  
{  
   __asm  
   {  
      test global,0  
      jpe SHORT DoParityEven  // C4414  
      jmp SHORT DoParityOdd   // C4414  
   }  
}  
```