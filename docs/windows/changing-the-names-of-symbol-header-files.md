---
title: "Alterando os nomes de arquivos de cabe&#231;alho de s&#237;mbolo | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.symbol.changing.header"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de cabeçalho, alterando nomes"
  - "nomes [C++], arquivos de cabeçalho de símbolo"
  - "arquivos de recurso, vários"
  - "Caixa de diálogo Recurso Inclui"
  - "Resource.h"
  - "arquivos de cabeçalho de símbolo"
  - "arquivos de cabeçalho de símbolo, alterando nomes"
  - "símbolos, arquivos de cabeçalho de símbolo"
ms.assetid: b948284a-7899-402e-ab12-9f2c8480ca9d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando os nomes de arquivos de cabe&#231;alho de s&#237;mbolo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Normalmente, todos os símbolos definições são salvas em Resource.h.  No entanto, talvez seja necessário alterar isso incluem o nome do arquivo para que você possa, por exemplo, trabalhar com mais de um arquivo de recurso no mesmo diretório.  
  
### Para alterar o nome do arquivo de cabeçalho de símbolo de recurso  
  
1.  Em [exibição recurso](../windows/resource-view-window.md), clique em seu arquivo. RC e escolha [recurso inclui](../windows/resource-includes-dialog-box.md) no menu de atalho.  
  
    > [!NOTE]
    >  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **arquivo de cabeçalho de símbolo** digite o novo nome para o arquivo de inclusão.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.*  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)