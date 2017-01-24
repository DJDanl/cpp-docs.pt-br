---
title: "Erro PRJ0002 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0002"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0002"
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0002 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

resultado de erro retornado de “linha de comando”.  
  
 Um comando, ***command line***, que é formado de entrada de usuário na caixa de diálogo de **Páginas de Propriedades** , não retornou um código de erro mas nenhuma informação será exibida na janela saída.  
  
 A solução para esse erro depende da ferramenta que gerou o erro.  Para MIDL, você obterá uma exibição do que foram criados se \/o \(redireciona a saída\) é definido.  
  
 Um arquivo em lotes, como uma etapa de criação ou um evento personalizado de construção, que não sejam informativos sobre condições de falha também pode ser a razão para esse erro.