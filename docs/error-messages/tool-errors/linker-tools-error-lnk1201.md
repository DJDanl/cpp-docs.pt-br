---
title: "Erro das Ferramentas de Vinculador LNK1201 | Microsoft Docs"
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
  - "LNK1201"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1201"
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1201
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

gravação do erro para programar o base de dados “nome de arquivo”; verifique se há espaço em disco insuficiente, o caminho inválido, ou o privilégio insuficiente  
  
 O LINK não foi possível gravar na base de dados \(PDB\) de programa para o arquivo de saída.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  O arquivo está danificado.  Excluir o arquivo PDB e relink.  
  
2.  Não espaço em disco suficiente para gravar o arquivo.  
  
3.  A unidade não estiver disponível, possivelmente devido a um problema de rede.  
  
4.  O depurador está ativo no programa que você está tentando vincular.  
  
5.  Sem espaço do heap.  Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.