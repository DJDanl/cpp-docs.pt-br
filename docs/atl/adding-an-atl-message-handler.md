---
title: "Adicionando um manipulador de mensagem de ATL | Microsoft Docs"
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
  - "ATL, manipuladores de mensagem"
  - "ATL, o windows"
  - "manipuladores de mensagem [C++]"
  - "tratamento de mensagens [C++], Manipulador de mensagem de ATL"
  - "windows [C++], ATL"
ms.assetid: cdea38a1-0d9b-4f8d-bbd5-b4f063fb3eeb
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um manipulador de mensagem de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para adicionar um manipulador de mensagem \(uma função de membro que manipula as mensagens do windows\) para um controle, selecione o primeiro controle no modo da classe.  Abrir a janela de **Propriedades** , selecione o ícone de **Mensagens** , e clique no controle suspensa na caixa oposto a mensagem necessário.  Isso adicionará uma declaração para o manipulador de mensagem no arquivo de cabeçalho do controle e uma implementação de esqueleto do manipulador no arquivo de .cpp do controle.  Também adicionará o mapa de mensagem e adicionar uma entrada para o manipulador.  
  
 Adicionar um manipulador de mensagem em ATL é semelhante a adicionar um manipulador de mensagem para uma classe MFC.  Consulte [Adicionando um manipulador de mensagem MFC](../mfc/reference/adding-an-mfc-message-handler.md) para mais informações.  
  
 As condições a seguir se aplicam somente para adicionar um manipulador de mensagem de ATL:  
  
-   Os manipuladores de mensagem seguem a mesma convenção de nomenclatura que o MFC.  
  
-   As novas entradas do mapa de mensagem são adicionadas no mapa principal de mensagem.  O assistente não reconhece mapas alternativas e encadear de mensagem.  
  
## Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)