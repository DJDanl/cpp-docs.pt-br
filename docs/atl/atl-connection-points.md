---
title: "Pontos de conex&#227;o ATL | Microsoft Docs"
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
  - "ATL, pontos de conexão"
  - "pontos de conexão [C++], sobre pontos de conexão"
  - "conexões, pontos de conexão"
ms.assetid: 17d76165-5f83-4f95-b36d-483821c247a1
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pontos de conex&#227;o ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto conectável é aquele que oferece suporte a interfaces de saída.  Uma interface de saída permite que o objeto se comunique com um cliente.  Para cada interface de saída, o objeto conectável expõe um ponto de conexão.  Cada interface de saída é implementada por um cliente em um objeto denominado de um coletor.  
  
 ![Pontos de conexão](../atl/media/vc2zw31.png "vc2ZW31")  
  
 Cada ponto de conexão dá suporte a interface [IConnectionPoint](http://msdn.microsoft.com/library/windows/desktop/ms694318).  O objeto conectável expõe seus pontos de conexão para o cliente por meio da interface [IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857).  
  
## Nesta seção  
 [Classes de Ponto de Conexão de ATL](../atl/atl-connection-point-classes.md)  
 Descreve sucintamente as classes ATL que dão suporte aos pontos de conexão.  
  
 [Adicionando Pontos de Conexão a um Objeto](../atl/adding-connection-points-to-an-object.md)  
 Descreve as etapas usadas para adicionar pontos de conexão para um objeto.  
  
 [Exemplo de Ponto de Conexão de ATL](../atl/atl-connection-point-example.md)  
 Fornece um exemplo da declaração de um ponto de conexão.  
  
## Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)