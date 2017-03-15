---
title: "__readmsr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__readmsr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Registro específico de modelo de leitura"
  - "instrução de suporte a RDMSR"
  - "__readmsr intrínseco"
ms.assetid: 7ab1f8e8-72cb-4ce4-817d-3e728a3c9716
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __readmsr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Gera o `rdmsr` instrução, que lê o registro específico do modelo especificado por `register` e retorna seu valor.  
  
## Sintaxe  
  
```  
__int64 __readmsr(   
   int register   
);  
```  
  
#### Parâmetros  
 \[in\]`register`  
 O registro de modelo específico para ler.  
  
## Valor de retorno  
 O valor de registro especificado.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`__readmsr`|x86,[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Esta função só está disponível no modo kernel e a rotina só está disponível como um intrínseco.  
  
 Para obter mais informações, consulte a documentação da AMD.  
  
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)