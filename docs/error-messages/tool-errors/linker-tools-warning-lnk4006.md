---
title: "Aviso LNK4006 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4006"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4006"
ms.assetid: 3a637d17-1676-4ea6-bd8b-290137d28d3b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4006 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo já definido no objeto; segunda definição ignorada  
  
 `symbol`determinado, exibido em sua forma decorado, multiplica foi definido.  Quando esse aviso for encontrado, `symbol` será adicionado duas vezes, mas apenas o primeiro formulário será usado.  
  
 Você pode obter esse aviso se você tenta mesclar dois liberais de importação em um.  
  
 Se você estiver recompilando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  `symbol` determinado pode ser reunido uma função criada, compilando com [\/Gy](../../build/reference/gy-enable-function-level-linking.md).  Esse símbolo foi incluído em mais de um arquivo mas alterado entre as compilações.  Recompilar todos os arquivos que incluem `symbol`.  
  
2.  `symbol` determinado pode ter sido definido de forma diferente em dois objetos de membro em bibliotecas diferentes.  
  
3.  Um absoluta pode ter sido definido duas vezes, com um valor diferente em cada definição.  
  
4.  Se a mensagem de erro é recebida ao combinar bibliotecas, `symbol` já existe na biblioteca que está sendo adicionada.