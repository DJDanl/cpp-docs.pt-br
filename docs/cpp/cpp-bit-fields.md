---
title: "Campos de bit C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "campos de bits"
  - "campos de bits"
  - "campos [C++], bit"
ms.assetid: 6f4b62e3-cc1d-4e5d-bf34-05904104f71a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Campos de bit C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes e as estruturas podem conter membros que ocupam menos armazenamento do que um tipo integral.  Esses membros são especificados como campos de bits.  A sintaxe da especificação de *declarador de membro* para um campo de bits é a seguinte:  
  
## Sintaxe  
  
```  
  
declarator  : constant-expression  
```  
  
## Observações  
 O elemento \(opcional\) `declarator` é o nome pelo qual o membro é acessado no programa.  Deve ser um tipo integral \(incluindo tipos enumerados\).  *constant\-expression* especifica o número de bits que o membro ocupa na estrutura.  Campos de bits anônimos \- ou seja, membros de campos de bits sem identificador \- podem ser usados para preenchimento.  
  
> [!NOTE]
>  Um campo de bits não nomeado de largura 0 força o alinhamento do próximo campo de bits com o próximo limite de `type`, onde `type` é o tipo do membro.  
  
 O exemplo a seguir declara uma estrutura que contém campos de bits:  
  
```  
// bit_fields1.cpp  
// compile with: /LD  
struct Date {  
   unsigned short nWeekDay  : 3;    // 0..7   (3 bits)  
   unsigned short nMonthDay : 6;    // 0..31  (6 bits)  
   unsigned short nMonth    : 5;    // 0..12  (5 bits)  
   unsigned short nYear     : 8;    // 0..100 (8 bits)  
};  
```  
  
 O layout de memória conceitual de um objeto do tipo `Date` é mostrado na figura a seguir.  
  
 ![Gráfico de Layout de memória do objeto de data](../cpp/media/vc38uq1.png "vc38UQ1")  
Layout de memória de um objeto Date  
  
 Observe que `nYear` tem um comprimento de 8 bits e estouraria o limite de palavra do tipo declarado, **unsigned short**.  Em consequência, ele começa no início de um novo **unsigned short**.  Não é necessário que todos os campos de bits caibam em um mesmo objeto do tipo subjacente; novas unidades de armazenamento são alocadas de acordo com o número de bits solicitados na declaração.  
  
 **Específico da Microsoft**  
  
 A ordenação dos dados declarados como campos de bits vai do bit inferior até o superior, como mostra a figura acima.  
  
 **FIM de Específico da Microsoft**  
  
 Se a declaração de uma estrutura inclui um campo não nomeado de comprimento 0, como mostrado no exemplo a seguir,  
  
```  
// bit_fields2.cpp  
// compile with: /LD  
struct Date {  
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)  
   unsigned nMonthDay : 6;    // 0..31  (6 bits)  
   unsigned           : 0;    // Force alignment to next boundary.  
   unsigned nMonth    : 5;    // 0..12  (5 bits)  
   unsigned nYear     : 8;    // 0..100 (8 bits)  
};  
```  
  
 o layout de memória fica conforme ilustrado na figura a seguir.  
  
 ![Campo de bits de comprimento do data objeto Layout 0](../Image/vc38UQ2.png "vc38UQ2")  
Layout do objeto Date com campo de bits de comprimento zero  
  
 O tipo subjacente de um campo de bits deve ser um tipo integral, conforme descrito em [Tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
## Restrições em campos de bits  
 A lista a seguir detalha as operações erradas em campos de bits:  
  
1.  Obtendo o endereço de um campo de bits.  
  
2.  Inicializando uma referência com um campo de bits.  
  
## Consulte também  
 [Classes e structs](../Topic/Classes%20and%20Structs%20\(C++\).md)