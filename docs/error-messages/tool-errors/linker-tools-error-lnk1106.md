---
title: "Erro das Ferramentas de Vinculador LNK1106 | Microsoft Docs"
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
  - "LNK1106"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1106"
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1106
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

arquivo inválido ou disco por meio do: não pode buscar o local  
  
 A ferramenta não foi possível ler ou gravar em `location` em um arquivo memória mapeado.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Disco cheio.  
  
     Liberar qualquer espaço e links novamente.  
  
2.  Tentativa vincular em uma rede.  
  
     Algumas redes não dão suporte total aos arquivos mapeados por memória usados pelo vinculador.  Experimente links em seu disco local.  
  
3.  Bloco incorreto no disco.  
  
     Embora o hardware do sistema operacional e de disco deveria ter detectado esse tipo de erro, talvez você queira executar um programa disco verificando.  
  
4.  Sem espaço do heap.  
  
     Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.