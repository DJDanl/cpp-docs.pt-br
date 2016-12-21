---
title: "Assistente da p&#225;gina de propriedades de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.ppg.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Projetos de ATL, adicionando páginas de propriedades"
  - "Assistente da página de propriedades de ATL"
ms.assetid: 6113e325-facd-4f68-b491-144d75209922
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente da p&#225;gina de propriedades de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O assistente [adiciona uma página de propriedades em um projeto de ATL](../Topic/Adding%20an%20ATL%20Property%20Page.md) ou a um projeto MFC com suporte de ATL.  Uma página de propriedades de ATL fornece uma interface de usuário para definir as propriedades \(ou chamar os métodos\) de um ou mais objetos COM.  
  
## Comentários  
 Iniciando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro gerado pelo assistente irá registrar seus componentes COM em **HKEY\_CURRENT\_USER** em vez de **HKEY\_LOCAL\_MACHINE**.  Para alterar esse comportamento, defina a opção de **Componente do registro para todos os usuários** do assistente de ATL.  
  
## Nomes  
 Especifique os nomes para que o objeto, a interface, e classes sejam adicionadas ao seu projeto.  A exceção de **Nome curto**, todas as caixas outros podem ser editadas independente.  Se você alterar o texto para **Nome curto**, a alteração é refletida em nomes de todas as caixas restantes na página.  Se você alterar o nome de **Coclass** na seção COM, a alteração é refletida em **Tipo** e nas caixas de **ProgID** .  Este comportamento de nomeação é criado para fazer facilmente todos os nomes de identificação para você enquanto você desenvolve sua página de propriedades.  
  
> [!NOTE]
>  **Coclass** é editável somente em projetos nonattributed.  Se o projeto tiver atribuído, você não pode editar **Coclass**.  
  
### C\+\+  
 Fornece informações para a classe C\+\+ criada para implementar o objeto.  
  
|||  
|-|-|  
|Termo|Definição|  
|**Nome curto**|Define o nome abreviado do objeto.  O nome que você fornece determina a classe e os nomes de **Coclass** , os nomes de arquivo \(**.cpp** e **.h**\), o nome de **Tipo** , e o **ProgID**, a menos que você altere os campos individualmente.|  
|**Arquivo .h**|Define o nome do arquivo de cabeçalho para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha, ou para anexar a declaração de classe para um arquivo existente.  Se você selecionar um arquivo existente, o assistente não o salvou o local selecionado até que você tenha **Concluir** no assistente.<br /><br /> o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.|  
|**Classe**|Define o nome da classe que implementa o objeto.  Esse nome é baseado no nome que você fornece em **Nome curto**, precedido por “C”, o prefixo típico para um nome de classe.|  
|**Arquivo de .cpp**|Define o nome do arquivo de implementação para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha.  O arquivo não é salvo no local selecionado até que você tenha **Concluir** no assistente.<br /><br /> o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a implementação da classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.|  
|**Atribuído**|Indica se o objeto usa atributos.  Se você estiver adicionando um objeto atribuído a um projeto de ATL, esta opção está selecionada e não disponível alterá\-lo, isto é, pode adicionar apenas objetos atribuídos a um projeto criado com suporte do atributo.<br /><br /> Você pode adicionar um objeto atribuído somente a um projeto de ATL que usa atributos.  Se você selecionar esta opção para um projeto de ATL que não tenha suporte de atributo, o assistente solicita que você especifique se você deseja adicionar suporte do atributo para o projeto.<br /><br /> Por padrão, alguns objetos que você adicione após você definir essa opção é designado como \(atribuído a caixa de seleção está selecionada.\)  Você pode desmarque esta caixa para adicionar um objeto que não use atributos.<br /><br /> Consulte [Configurações do aplicativo, assistente de projeto de ATL](../Topic/Application%20Settings,%20ATL%20Project%20Wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para mais informações.|  
  
### COM  
 Fornece informações sobre a funcionalidade da para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indica em esta página do assistente que a página de propriedades usa atributos, você não pode modificar esta opção porque ATL não inclui o atributo de `coclass` .  
  
 **Tipo**  
 Define a descrição do objeto que aparecerá no Registro  
  
 **ProgID**  
 Define o nome recipientes podem usar em vez de CLSID do objeto.  
  
## Consulte também  
 [Opções, o assistente da página de propriedades de ATL](../../atl/reference/options-atl-property-page-wizard.md)   
 [Cadeias de caracteres, assistente da página de propriedades de ATL](../../atl/reference/strings-atl-property-page-wizard.md)   
 [Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)