---
title: "Arquivos de entrada LIB | Microsoft Docs"
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
  - "Lib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de entrada, LIB"
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de entrada LIB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os arquivos de entrada esperados por LIB dependem do modo no qual o está sendo usado, conforme mostrado na seguinte tabela.  
  
|Modo|Entrada|  
|----------|-------------|  
|Opção \(criação ou modificação de uma biblioteca\)|Os arquivos do objeto de COFF \(.obj\), bibliotecas de COFF \(.lib\), o objeto de 32 bits \(OMF\) de formato do modelo de objeto \(.obj arquivo\)|  
|Extraindo um membro com \/EXTRACT|Biblioteca de COFF \(.lib\)|  
|Criando uma biblioteca do arquivo de importação e exportação com \/DEF|o do arquivo .def definição \(\), arquivos do objeto de COFF \(.obj\), bibliotecas de COFF \(.lib\), o objeto de 32 bits de OMF \(\) .obj arquivos|  
  
> [!NOTE]
>  As bibliotecas de OMF criadas pela versão de 16 bits de LIB não podem ser usadas como entrada para a versão de 32 bits de LIB.  
  
## Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)