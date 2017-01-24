---
title: "Assistente para adicionar classe de Typelib | Microsoft Docs"
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
  - "vc.codewiz.class.typelib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente para Adicionar Classe de TypeLib [C++]"
  - "Interfaces COM, adicionando classes"
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente para adicionar classe de Typelib
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esse assistente para adicionar uma classe de uma biblioteca MFC disponível do tipo.  O assistente cria uma classe para cada interface que você adicionar a biblioteca selecionada do tipo.  
  
 **Add class from**  
 Especifica o local da biblioteca de tipos, que a classe é criada.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Registro**|A biblioteca de tipos é registrada no sistema.  As bibliotecas registradas do tipo são listadas em **Available type libraries**.|  
|**Arquivo**|A biblioteca de tipos não será registrada no sistema mas necessariamente está contida em um arquivo.  Você deve fornecer o local do arquivo em **Local**.|  
  
 **Available type libraries**  
 Lista as bibliotecas de tipo registradas no sistema atualmente.  Selecione uma biblioteca de tipos dessa lista para exibir as interfaces na lista de **Interfaces** .  
  
 Consulte “COM distribuída interior: Digite bibliotecas e integração de CLR” na biblioteca do MSDN para obter mais informações sobre como registrar bibliotecas do tipo.  
  
 **Local**  
 Especifica o local da biblioteca de tipos.  Se você clicar em **Arquivo** em **Adicione a classe de**, você pode fornecer o local do arquivo que contém a biblioteca de tipos.  Para navegue até o local do arquivo, clique no botão de reticências.  
  
 **Interfaces**  
 Lista as interfaces na biblioteca de tipos selecionada na lista de **Available type libraries** .  
  
|Botão de transferência|Descrição|  
|----------------------------|---------------|  
|**\>**|Adiciona a interface selecionada na lista de **Interfaces** .  Esmaecido se nenhuma interface é selecionada.|  
|**\>\>**|Adiciona todas as interfaces na biblioteca de tipos selecionada na lista de **Available type libraries** .|  
|**\<**|Remove a classe selecionada na lista de **Generated classes** .  Esmaecido se nenhuma classe é selecionada na lista de **Generated classes** .|  
|**\<\<**|Remove todas as classes na lista de **Generated classes** .  Esmaecido se a lista de **Generated classes** está vazia.|  
  
 **Generated classes**  
 Especifica os nomes da classe a serem gerados das interfaces unidas usando o botão de **\>** ou de **\>\>** .  Você pode clicar nessa caixa para selecionar uma classe, e depois usa para cima ou para baixo as chaves para rolar pela lista, exibindo cada nome da classe na caixa de `Class` e nome de arquivo na caixa de **Arquivo** que o assistente gerencia quando você clica em **Concluir**.  Você pode selecionar apenas uma classe de cada vez nesta caixa.  
  
 Você pode remover uma classe selecionando\-a na lista e clicando em **\<**.  Você não precisa selecionar uma classe na caixa gerado a partir das classes para remover todas as classes; clicando em **\<\<**, você remove todas as classes na caixa de **Generated classes** .  
  
 `Class`  
 Especifica o nome da classe selecionada na caixa de **Generated classes** que o assistente adiciona quando você clica em **Concluir**.  Você pode editar o nome na caixa de `Class` .  
  
 **Arquivo**  
 Define o nome do arquivo de cabeçalho para a nova classe.  Por padrão, esse nome é baseado no nome que você fornece em **Generated classes**.  Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente.  Se você escolher um arquivo existente, o assistente não o salve no local selecionado até que você clique **Concluir** no assistente.  
  
 O assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clicar em **Concluir**, o assistente solicitará que indica se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique em **Sim** para anexar o arquivo; clique **Não** para retornar ao assistente e para especificar outro nome de arquivo.  
  
## Consulte também  
 [Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)   
 [Clientes de automação: usando bibliotecas de tipo](../Topic/Automation%20Clients:%20Using%20Type%20Libraries.md)