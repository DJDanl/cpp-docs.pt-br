---
title: "Assistente de controle de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.control.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de controle de ATL"
  - "Projetos de ATL, adicionando controles"
  - "controles [ATL], adicionando a projetos"
ms.assetid: 991f8e72-ffbc-4382-a4ce-e255acfba5b6
caps.latest.revision: 17
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de controle de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inserções em um projeto de ATL \(ou em um projeto MFC com suporte de ATL\) um controle de ATL.  Você pode usar o assistente para inserir um dos três tipos de controles:  
  
-   Controle padrão  
  
-   Controle composto  
  
-   Controle DHTML  
  
 Além de isso, você pode especificar um controle mínimo, removendo as interfaces da lista de [interfaces](../../atl/reference/interfaces-atl-control-wizard.md) , que são fornecidas como opções para os controles abrir na maioria de contêiner.  Você pode definir as interfaces que você deseja suporte para o controle na página de **Interfaces** do assistente.  
  
## Comentários  
 O script de registro gerado pelo assistente irá registrar seus componentes COM em HKEY\_CURRENT\_USER em vez de HKEY\_LOCAL\_MACHINE.  Para alterar esse comportamento, defina a opção de **Componente do registro para todos os usuários** do assistente de ATL.  
  
## Nomes  
 Especifique os nomes para que o objeto, a interface, e classes sejam adicionadas ao seu projeto.  A exceção de **Nome curto**, todas as caixas outros podem ser alteradas independente.  Se você alterar o texto para **Nome curto**, a alteração é refletida em nomes de todas as caixas restantes na página.  Se você alterar o nome de **Coclass** na seção COM, a alteração é refletida na caixa de **Tipo** , mas o nome e **ProgID** de **Interface** não são alterados.  Este comportamento de nomeação é criado para fazer facilmente todos os nomes de identificação para você enquanto você desenvolve seu controle.  
  
> [!NOTE]
>  **Coclass** é editável somente em controles nonattributed.  Se o projeto tiver atribuído, você não pode editar **Coclass**.  
  
### C\+\+  
 Fornece informações para a classe C\+\+ criada para implementar o objeto.  
  
 **Nome curto**  
 Define o nome abreviado do objeto.  o nome que você fornece determina a classe e os nomes de **Coclass** , o arquivo \(.CPP e. H nomes\), o nome da interface, e os nomes de **Tipo** , a menos que você altere os campos individualmente.  
  
 **Classe**  
 Define o nome da classe que implementa o objeto.  Esse nome é baseado no nome que você fornece em **Nome curto**, precedido por “C”, o prefixo típico para um nome de classe.  
  
 **arquivo .h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha, ou para anexar a declaração de classe para um arquivo existente.  Se você selecionar um arquivo existente, o assistente não o salvou o local selecionado até que você tenha **Concluir**.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
 **arquivo de .cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha.  O arquivo não é salvo no local selecionado até que você tenha **Concluir** no assistente.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a implementação da classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
 **atribuído**  
 Indica se o objeto usa atributos.  Se você estiver adicionando um objeto atribuído a um projeto de ATL, esta opção está selecionada e não disponível alterar.  Isto é, você pode adicionar apenas objetos atribuídos a um projeto criado com suporte do atributo.  
  
 Você pode adicionar um objeto atribuído somente a um projeto de ATL que usa atributos.  Se você selecionar esta opção para um projeto de ATL que não tenha suporte de atributo, o assistente solicita que você especifique se você deseja adicionar suporte do atributo para o projeto.  
  
 Por padrão, alguns objetos que você adicione após você definir essa opção é designado como \(atribuído a caixa de seleção está selecionada.\)  Você pode desmarque esta caixa para adicionar um objeto que não use atributos.  
  
 Consulte [Configurações do aplicativo, assistente de projeto de ATL](../Topic/Application%20Settings,%20ATL%20Project%20Wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para mais informações.  
  
### COM  
 Fornece informações sobre a funcionalidade da para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indica em esta página do assistente que o controle usa atributos, você não pode modificar esta opção porque ATL não inclui o atributo de **coclass** .  
  
 **Interface**  
 Define o nome da interface para o objeto.  Por padrão um nome da interface prepended com “i”.  
  
 **Tipo**  
 Define a descrição do objeto que aparecerá no Registro  
  
 **ProgID**  
 Define o nome recipientes podem usar em vez de CLSID do objeto.  Este campo não é preenchido automaticamente.  Se você não preencher manualmente este campo, o controle pode não estar disponível para outras ferramentas.  Por exemplo, os controles ActiveX que são gerados sem `ProgID` não estão disponíveis na caixa de diálogo de **Inserir controle ActiveX** .  Para obter mais informações sobre a caixa de diálogo, consulte [Caixa de diálogo Inserir Controle ActiveX](../Topic/Insert%20ActiveX%20Control%20Dialog%20Box.md).  
  
## Consulte também  
 [Controle ATL](../../atl/reference/adding-an-atl-control.md)   
 [Adicionando funcionalidade para o controle composto](../../atl/adding-functionality-to-the-composite-control.md)   
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)