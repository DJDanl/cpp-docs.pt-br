---
title: "Gerenciamento de mem&#243;ria: exemplos | Microsoft Docs"
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
  - "matrizes [C++], alocando recursos"
  - "matrizes [C++], gerenciamento de memória"
  - "estruturas de dados [C++]"
  - "estruturas de dados [C++], alocando memória"
  - "exemplos [MFC], alocação de memória"
  - "alocação de quadro"
  - "alocação de heap, exemplos"
  - "alocação de memória [C++], matrizes"
  - "alocação de memória [C++], estruturas de dados"
  - "alocação de memória [C++], exemplos"
  - "alocação de memória [C++], Objetos "
  - "MFC [C++], gerenciamento de memória"
  - "objetos [C++], alocando memória"
  - "objetos [C++], alocação de memória"
  - "alocação de memória de estrutura"
  - "tipos [C++], alocação de memória"
ms.assetid: f10240f8-b698-4c83-9288-97a54318930b
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria: exemplos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como o MFC executa alocações de quadro e alocações de heap para cada um dos três tipos típicos de alocação de memória:  
  
-   [Uma matriz de bytes](#_core_allocation_of_an_array_of_bytes)  
  
-   [Uma estrutura de dados](#_core_allocation_of_a_data_structure)  
  
-   [Um objeto](#_core_allocation_of_an_object)  
  
##  <a name="_core_allocation_of_an_array_of_bytes"></a> Alocação de uma matriz de bytes  
  
#### Para alocar uma matriz de bytes no quadro  
  
1.  Define a matriz como mostra o código a seguir.  A matriz é automaticamente excluída e sua memória são recuperadas quando a variável de matriz sai do escopo.  
  
     [!code-cpp[NVC_MFC_Utilities#1](../mfc/codesnippet/CPP/memory-management-examples_1.cpp)]  
  
#### Para alocar uma matriz de bytes \(ou de qualquer tipo de dados primitivo\) no heap  
  
1.  Use o operador de **new** com a sintaxe da matriz mostrada neste exemplo:  
  
     [!code-cpp[NVC_MFC_Utilities#2](../mfc/codesnippet/CPP/memory-management-examples_2.cpp)]  
  
#### Para desalocar as matrizes de heap  
  
1.  Use o operador de **delete** como segue:  
  
     [!code-cpp[NVC_MFC_Utilities#3](../mfc/codesnippet/CPP/memory-management-examples_3.cpp)]  
  
##  <a name="_core_allocation_of_a_data_structure"></a> Alocação de uma estrutura de dados  
  
#### Para atribuir uma estrutura de dados no quadro  
  
1.  Defina a variável da estrutura como segue:  
  
     [!code-cpp[NVC_MFC_Utilities#4](../mfc/codesnippet/CPP/memory-management-examples_4.cpp)]  
  
     A memória ocupada pela estrutura são recuperadas quando sai do escopo.  
  
#### Para atribuir estruturas de dados no heap  
  
1.  Use **new** para atribuir estruturas de dados no heap e em **delete** para desalocar\-los, como mostram os exemplos a seguir:  
  
     [!code-cpp[NVC_MFC_Utilities#5](../mfc/codesnippet/CPP/memory-management-examples_5.cpp)]  
  
##  <a name="_core_allocation_of_an_object"></a> Alocação de um objeto  
  
#### Para atribuir um objeto no quadro  
  
1.  Declare o objeto como segue:  
  
     [!code-cpp[NVC_MFC_Utilities#6](../mfc/codesnippet/CPP/memory-management-examples_6.cpp)]  
  
     O destruidor para o objeto é invocado automaticamente quando o objeto é encerrado seu escopo.  
  
#### Para atribuir um objeto no heap  
  
1.  Use o operador de **new** , que retorna um ponteiro para o objeto, atribuir objetos no heap.  Use o operador de **delete** para excluí\-los.  
  
     Os exemplos do heap e do quadro presumem que o construtor de `CPerson` não utiliza argumentos.  
  
     [!code-cpp[NVC_MFC_Utilities#7](../mfc/codesnippet/CPP/memory-management-examples_7.cpp)]  
  
     Se o argumento para o construtor de `CPerson` é um ponteiro para `char`, a instrução para alocação do quadro é:  
  
     [!code-cpp[NVC_MFC_Utilities#8](../mfc/codesnippet/CPP/memory-management-examples_8.cpp)]  
  
     A instrução da alocação de heap é:  
  
     [!code-cpp[NVC_MFC_Utilities#9](../mfc/codesnippet/CPP/memory-management-examples_9.cpp)]  
  
## Consulte também  
 [Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)