---
title: "Erro das Ferramentas de Vinculador LNK2039 | Microsoft Docs"
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
  - "LNK2039"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2039"
ms.assetid: eaa296bd-4901-41f6-8410-6d03ee827144
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2039
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

importando o tipo de classe '\<de referência\>' que está definido em another.obj; deve ser importado ou definida, mas não ambos  
  
 A classe`type` '\<\>' de referência é importada no arquivo especificado de .obj mas também definida em outro arquivo de .obj.  Essa condição pode causar a falha de tempo de execução ou outro comportamento inesperado.  
  
### Para corrigir este erro  
  
1.  Verifique se '`type`' deve ser definido em outro arquivo e na verificação de .obj se deve ser importada do arquivo de .winmd.  
  
2.  Descarte a definição ou a importação.  
  
## Consulte também  
 [Erros e avisos das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-errors-and-warnings.md)   
 [Erro das Ferramentas de Vinculador LNK1332](../../error-messages/tool-errors/linker-tools-error-lnk1332.md)