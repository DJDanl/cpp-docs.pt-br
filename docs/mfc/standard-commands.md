---
title: "Comandos padr&#227;o | Microsoft Docs"
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
  - "IDs de comando, comandos padrão"
  - "comandos [C++], padrão"
  - "Comandos padrão do menu Editar"
  - "Menu Arquivo"
  - "Ajuda, menus"
  - "identificadores [C++], IDs de comando"
  - "Comandos OLE"
  - "IDs definidos pelo programador [C++]"
  - "IDs de comandos padrão"
  - "comandos padrão"
  - "comandos do menu Exibir"
  - "comandos do menu Janela"
ms.assetid: 88cf3ab4-79b3-4ac6-9365-8ac561036fbf
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Comandos padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A estrutura define muitas mensagens padrão do comando.  As IDs para esses comandos assumem normalmente o formulário:  
  
 **ID\_** *Source\_Item*  
  
 onde *a origem* é geralmente um nome de menu e *um item* é um item de menu.  Por exemplo, a ID de comando para o novo comando no menu arquivo é `ID_FILE_NEW`.  As IDs padrão de comando são mostrados em negrito na documentação do.  As IDs Programador\- definidos são mostrados em uma fonte que é diferente de texto ao redor.  
  
 O seguinte é uma lista de alguns dos comandos os mais importantes com suporte:  
  
 *Comandos de menu arquivo*  
 Novo, abrir, fechar, salvar, salvar como, configuração de página, configuração de cópia seguro, copie, a visualização de impressão, saída, e arquivos mais\-recente\- usados.  
  
 *Editar comandos de menu*  
 Limpar, desmarque todas, cópia, divisão, localizar, pasta, reprodução, substituição, selecione todas, desfazer\-lo, e refazê\-lo.  
  
 *Exibir comandos de menu*  
 Barra de ferramentas e a barra de status.  
  
 *Comandos de menu da janela*  
 Novo, organizar, se conecta, organize o horizontal, vertical lado a lado, e a divisão.  
  
 *Comandos de menu ajuda*  
 Índice, usando a ajuda, e cerca de.  
  
 *Comandos OLE \(menu editar\)*  
 O novo objeto de inserção, edição Links, link de pasta, cole o especial, e o objeto *typename* \(comandos do verbo\).  
  
 A estrutura fornece vários níveis de suporte para esses comandos.  Alguns comandos têm suporte apenas definidos como IDs de comando, enquanto outros tenham suporte com implementações completas.  Por exemplo, a estrutura implementa o comando aberto no menu arquivo criando um novo objeto de documento, exibindo uma caixa de diálogo aberta, e abrindo e ler o arquivo.  Em contraste, você deve implementar comandos no menu editar você mesmo, desde que os comandos como **ID\_EDIT\_COPY** dependem da natureza de dados que você está copiando.  
  
 Para obter mais informações sobre os comandos com suporte e o nível de implementação fornecido, consulte [Observação 22 técnica](../mfc/tn022-standard-commands-implementation.md).  Os comandos de padrão são definidos no arquivo. AFXRES.H.  
  
## Consulte também  
 [Objetos de interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)