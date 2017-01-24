---
title: "Assistente para Adicionar Classe de Controle ActiveX | Microsoft Docs"
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
  - "vc.codewiz.class.axcontrol"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Controle ActiveX"
  - "Assistente para Adicionar Classe de Controle ActiveX [C++]"
ms.assetid: 668d801c-5fb6-4176-9191-5c38995a4713
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente para Adicionar Classe de Controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use este assistente para adicionar uma classe MFC a partir de um controle de ActiveX disponível.  O assistente cria uma classe para cada interface que você adiciona a partir do controle de ActiveX selecionado.  
  
 **Adicionar classe a partir de**  
 Especifica o local da biblioteca de tipos, a partir do qual a classe é criada.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Registro**|A biblioteca de tipos é registrada no sistema.  Bibliotecas de tipo registradas são listadas na  **ActiveX disponíveis controles**.|  
|**File**|A biblioteca de tipos não necessariamente é registrada no sistema, mas está contida em um arquivo.  Você deve fornecer o local do arquivo em  **local**.|  
  
 **Controles de ActiveX disponíveis**  
 Especifica os controles de ActiveX atualmente registrados no sistema.  Selecione um controle ActiveX nessa lista para exibir suas interfaces na  **Interfaces** lista.  Consulte  [controles de ActiveX do MFC: distribuição de controles de ActiveX](../mfc/mfc-activex-controls-distributing-activex-controls.md) para obter mais informações sobre como registrar os controles de ActiveX.  
  
 Se você clicar em  **arquivo** em  **Adicionar classe de**, esta caixa está disponível para alteração.  
  
 **Local**  
 Especifica o local do controle ActiveX.  Se você clicar em  **arquivo** em  **Adicionar classe de**, você pode fornecer o local do arquivo que contém a biblioteca de tipos.  Para procurar o local do arquivo, clique no botão de reticências.  
  
 Se você clicar em  **registro** em  **Adicionar classe de**, esta caixa está disponível para alteração.  
  
 **Interfaces**  
 Especifica as interfaces no controle ActiveX selecionado no momento  **controles disponíveis ActiveX** ou na biblioteca de tipos no arquivo especificado em  **local**.  
  
|Botão de transferência|Descrição|  
|----------------------------|---------------|  
|**\>**|Adiciona a interface selecionada no momento o  **Interfaces** lista.  Disponível se nenhuma interface for selecionada.|  
|**\>\>**|Adiciona todas as interfaces no controle ActiveX selecionado no momento  **controles disponíveis ActiveX** ou na biblioteca de tipos no arquivo especificado em  **local**.|  
|**\<**|Remove a classe selecionada no momento o  **classes geradas** lista.  Disponível se não há classe selecionada no momento o  **classes geradas** lista.|  
|**\<\<**|Remove todas as classes no  **classes geradas** lista.  Não está disponível se o  **classes geradas** a lista está vazia.|  
  
 **Classes geradas**  
 Especifica os nomes de classe a ser gerado das interfaces adicionadas usando o  **\>** ou  **\>\>** botão.  Você pode clicar esta caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para percorrer a lista, exibindo cada nome de classe a `Class` caixa e o nome na  **. h arquivo** caixa que o assistente gera quando você clica em  **Concluir**.  Você pode selecionar somente uma classe ao mesmo tempo nesta caixa.  
  
 Você pode remover uma classe selecionando\-o nesta lista e clicando em  **\<**.  Você não precisa selecionar uma classe no  **classes geradas**  caixa para remover todas as classes; clicando em  **\<\<**, você remove todas as classes no  **classes geradas**  caixa.  
  
 `Class`  
 Especifica o nome da classe selecionada no  **classes geradas** caixa que o assistente adiciona quando você clica em  **Concluir**.  Você pode editar o nome do `Class` caixa.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto.  Por padrão, esse nome se baseia o nome fornecido na  **classes geradas**.  Clique no botão de reticências para salvar o nome do arquivo para o local de sua preferência ou para acrescentar a declaração de classe para um arquivo existente.  Se você escolher um arquivo existente, o assistente irá não salvá\-lo no local selecionado até que você clique em  **Concluir** no assistente.  
  
 O assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica em  **Concluir**, o assistente solicita que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique em  **Sim** para anexar o arquivo; Clique em  **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto.  Por padrão, esse nome se baseia o nome fornecido na  **classes geradas**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha.  O arquivo não é salvo no local selecionado até você clicar em  **Concluir** no assistente.  
  
 O assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica em  **Concluir**, o assistente solicita que você indique se a implementação da classe deve ser acrescentada ao conteúdo do arquivo.  Clique em  **Sim** para anexar o arquivo; Clique em  **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## Consulte também  
 [Adicionando uma classe a partir de um controle ActiveX](../ide/adding-a-class-from-an-activex-control-visual-cpp.md)   
 [Clientes de automação: usando bibliotecas de tipo](../Topic/Automation%20Clients:%20Using%20Type%20Libraries.md)