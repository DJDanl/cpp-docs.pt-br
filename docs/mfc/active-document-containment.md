---
title: "Conten&#231;&#227;o de documento ativa | Microsoft Docs"
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
  - "contêineres de documentos ativos [C++], sobre contêineres de documentos ativos"
  - "documentos ativos [C++], contêineres"
  - "contêineres [C++], documento ativo"
  - "MFC [C++], Suporte COM"
  - "COM MFC [C++], contenção de documentos ativos"
ms.assetid: b8dfa74b-75ce-47df-b75e-fc87b7f7d687
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conten&#231;&#227;o de documento ativa
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A retenção ativa do documento é uma tecnologia que fornece um único quadro onde trabalhar com documentos, em vez de forçar para criar e usar vários aplicativo molda para cada tipo de documento.  Difere da tecnologia OLE básica de trabalho do com objetos inseridos em um documento composto no qual apenas uma única parte de conteúdo pode estar ativa.  A retenção ativa do documento, você ativar um documento inteiro \(isto é, um aplicativo inteiro, inclusive associados menus, barras de ferramentas, e assim por diante\) dentro do contexto de um único quadro.  
  
 A tecnologia ativa de retenção de documentos foi desenvolvida originalmente para o Microsoft Office que implementa a pasta do Office.  No entanto, a tecnologia é flexível ao contêiner ativas do documento diferentes da pasta do Office e pode dar suporte a servidores diferentes de documentos do Office e aplicativos e compatíveis.  
  
 O aplicativo que hospeda documentos ativos é chamado [contêiner do documento ativo](../mfc/active-document-containers.md).  Exemplos de tais contêiner é a pasta ou Microsoft Internet Explorer do Microsoft Office.  
  
 A retenção ativa do documento é implementada como um conjunto de extensões dos documentos OLE, a tecnologia composta do documento OLE.  As extensões são as interfaces adicionais que permite que um objeto inserível, in\-loco representa um documento inteiro em vez de uma única parte de conteúdo inserido.  Como documentos com OLE, a retenção ativa do documento usa um contêiner que fornece o espaço de exibição para documentos ativas, e os servidores que fornecem os recursos para os documentos ativas próprios da interface do usuário e de manipulação.  
  
 [servidor ativo do documento](../mfc/active-document-servers.md) é um aplicativo \(como word, Excel, ou o Powerpoint\) que oferece suporte a uma ou mais classes ativas do documento, onde cada próprio objeto oferece suporte às interfaces de extensão que permitem que o objeto é ativado em um contêiner apropriado.  
  
 [documento ativo](../Topic/Active%20Documents.md) \(fornecido de um servidor ativo do documento como word ou Excel\) é essencialmente um documento completo convencional, que será inserido como um objeto em outro contêiner ativa do documento.  Diferentemente dos objetos inseridos, os documentos ativas têm controle total sobre as páginas, e a interface completa do aplicativo \(com todos os comandos e ferramentas subjacentes\) está disponível ao usuário para editá\-las.  
  
 Um documento ativo é considerado melhor distinguindo a de um objeto inserido OLE do padrão.  Depois de convenção um objeto OLE, inserida é um que é exibido na página do documento que possui a, e o documento é gerenciada por um contêiner OLE.  O contêiner armazena os dados inseridos do objeto com o restante do documento.  No entanto, os objetos inseridos são delimitados sem controlam a página em que aparecem.  
  
 Os usuários de um aplicativo de contêiner ativa de documentos podem criar documentos ativas \(seções chamados na pasta do Office\) que usam seus aplicativos favoritos \(fornecidos esses aplicativos é o documento ativo habilitado\), porém os usuários podem gerenciar o projeto resultante como uma única entidade, que pode ser chamada exclusivamente, salvo, impresso, e assim por diante.  Da mesma forma, um usuário de um navegador da Internet pode controlar a rede inteira, bem como os sistemas de arquivos locais, como uma entidade de armazenamento único documento com a capacidade de procurar documentos no armazenamento de um único local.  
  
## Programas de exemplo  
  
-   O exemplo de [MFCBIND](../top/visual-cpp-samples.md) ilustra a implementação de um aplicativo de contêiner ativa do documento.  
  
## Consulte também  
 [MFC COM](../mfc/mfc-com.md)