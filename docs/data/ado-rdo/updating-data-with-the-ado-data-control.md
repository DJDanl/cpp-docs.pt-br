---
title: "Atualizando dados com o controle de dados ADO | Microsoft Docs"
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
  - "ADO [C++], associação de dados"
  - "ADO [C++], controles de dados"
ms.assetid: 8bec34b9-93dd-4872-b023-55ac011ccff5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando dados com o controle de dados ADO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os dados de controle de dados ADO podem ser somente leitura ou modificáveis.  
  
### Para criar um aplicativo que modifica dados usando o controle de dados ADO  
  
1.  Defina a propriedade de **CursorLocation** de controle de dados ADO.  As opções são:  
  
    -   O lado do servidor  
  
    -   O lado do cliente  
  
2.  Defina a propriedade de **LockType** de controle de dados ADO.  A simultaneidade otimista é recomendada.  
  
3.  Defina a propriedade de **CursorType** de controle de dados ADO.  As opções são:  
  
    -   Cursor controlado por conjunto de chaves  
  
    -   Cursor dinâmico  
  
    -   Cursor estático  
  
     Verifique se o provedor OLE DB oferecer suporte à opção escolhida.  
  
4.  Definir as propriedades associadas a dados de controle, conforme necessário, para permitir o updateability.  Observe que alguns controles não permitem atualizar.  
  
 Para obter mais informações sobre essas propriedades, consulte a documentação do ADO.  
  
## Consulte também  
 [Associação de dados ADO](../../data/ado-rdo/ado-databinding.md)   
 [Usando vinculação de dados ADO no Visual C\+\+](../../data/ado-rdo/using-ado-databinding-in-visual-cpp.md)