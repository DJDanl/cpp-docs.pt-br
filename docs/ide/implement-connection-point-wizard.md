---
title: "Assistente de Implementa&#231;&#227;o de Pontos de Conex&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.impl.cp.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Implementação de Pontos de Conexão [C++]"
ms.assetid: c117f6c6-30f0-4adb-82b4-b1f34e0f0fa8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Implementa&#231;&#227;o de Pontos de Conex&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este assistente implementa um ponto de conexão para um objeto COM.  Um objeto conectável \(ou seja, uma fonte\) pode expor um ponto de conexão para suas próprias interfaces ou para qualquer interface de saída.  Visual C\+\+ e Windows oferecem bibliotecas de tipos que possuem interfaces de saída.  Cada interface de saída pode ser implementado por um cliente em um objeto \(ou seja, um coletor\).  
  
 Para obter mais informações, consulte  [Pontos de conexão de ATL](../atl/atl-connection-points.md).  
  
 **Bibliotecas de tipos disponíveis**  
 Exibe as bibliotecas de tipo disponível que contém as definições de interface para o qual você pode implementar pontos de conexão.  Clique no botão de reticências para localizar um arquivo que contém a biblioteca de tipos para usar.  
  
 **Local**  
 Exibe a localização da biblioteca do tipo selecionada no momento o  **as bibliotecas de tipos disponíveis** lista.  
  
 **Interfaces**  
 Exibe as interfaces cujas definições estão contidas na biblioteca do tipo selecionada no momento o  **as bibliotecas de tipos disponíveis** caixa.  
  
|Botão de transferência|Descrição|  
|----------------------------|---------------|  
|**\>**|Adiciona o  **pontos de conexão de implementar** listar o nome da interface selecionado no momento o  **Interfaces** lista.|  
|**\>\>**|Adiciona o  **pontos de conexão de implementar** lista todos os nomes de interface disponíveis no  **Interfaces** lista.|  
|**\<**|Remove o nome da interface selecionado no momento o  **pontos de conexão de implementar** lista.|  
|**\<\<**|Remove todos os nomes listados no momento de interface do  **pontos de conexão de implementar** lista.|  
  
 **Implementar os pontos de conexão**  
 Exibe os nomes das interfaces para o qual você implementa pontos de conexão quando você clica em  **Concluir**.  
  
## Consulte também  
 [Implementando um ponto de conexão](../ide/implementing-a-connection-point-visual-cpp.md)