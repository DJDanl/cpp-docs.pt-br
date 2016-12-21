---
title: "Propriedade do tipo de acelerador | Microsoft Docs"
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
  - "Tipo de propriedade"
  - "VIRTKEY"
ms.assetid: 8c349bc4-e6ad-43fa-959e-f29168af35b8
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Propriedade do tipo de acelerador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Acelerador de  **tipo de** propriedade determina se a combinação de teclas de atalho associada com a identificação do accelerator é uma combinação de teclas virtual ou um valor de chave ASCII\/ANSI:  
  
-   Se o  **tipo de** propriedade é  **ASCII**, o  [modificador](../windows/accelerator-modifier-property.md) só pode ser nenhum ou Alt, ou pode ser um acelerador que usa a tecla CTRL \(especificado precedendo a chave com um ^\).  
  
-   Se o  **tipo de** propriedade é  **VIRTKEY**, qualquer combinação dos valores de chave e modificador é válida.  
  
    > [!NOTE]
    >  Se você quiser inserir um valor na tabela de acelerador e ter o valor a ser tratado como ASCII\/ANSI, basta clicar o tipo da entrada na tabela e selecione ASCII na lista suspensa.  No entanto, se você usar o  **Próxima tecla digitada** comando \(**Editar**  menu\) para especificar a chave, você deve alterar o  **tipo de** propriedade de VIRTKEY para ASCII  *antes de* digitando o código de chave.  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)   
 [Editor de aceleradores](../Topic/Accelerator%20Editor.md)