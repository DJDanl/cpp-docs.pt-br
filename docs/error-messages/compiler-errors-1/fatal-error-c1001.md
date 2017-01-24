---
title: "Erro fatal C1001 | Microsoft Docs"
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
  - "C1001"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1001"
ms.assetid: 5736cdb3-22c8-4fad-aa85-d5e0d2b232f4
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1001
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

ERROR INNER de COMPILADOR \(o arquivo do compilador, número de linha\)  
  
 O compilador não pode gerar código correta para uma construção, provavelmente devido à combinação de uma expressão e uma opção de otimização.  Tente remover uma ou mais opções de otimização e recompile a função que contém a linha especificada na mensagem de erro.  
  
 Você provavelmente poderá corrigir o problema removendo uma ou mais opções de otimização.  Para determinar quais opção é culpada, remova as opções um de cada vez e recompilar\-las até que a mensagem de erro parta.  As opções do geralmente são responsáveis **\/Og**, **\/Oi**, e `/Oa`.  Uma vez que você considerar a opção é responsável, você pode desabilitá\-la que usa o pragma de [otimizar](../../preprocessor/optimize.md) em torno da função em que ocorreu o erro e continua a usar a opção para o restante do módulo.  
  
 Base de Dados de Conhecimento Microsoft tem mais informações sobre C1001; consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;134650](http://support.microsoft.com/default.aspx?scid=kb;en-us;134650).  
  
 Tente reescrever a linha em que o erro for relatado, ou várias linhas de código que cercam essa linha.