---
title: "Assistente do componente de ATL COM+ 1,0 | Microsoft Docs"
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
  - "vc.codewiz.class.atl.mts.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente do componente de ATL COM+ 1,0"
  - "Projetos de ATL, adicionando componentes"
ms.assetid: 11670681-8671-4122-96a4-2e52f8dadce0
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente do componente de ATL COM+ 1,0
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use o assistente para adicionar um objeto ao projeto que oferece suporte a serviços COM\+ 1,0, incluindo transações.  
  
 Você pode especificar se o objeto suporta interfaces duais e automação.  Você também pode indicar suporte para a interface de informações de erro, o controle avançado de objeto, as transações, e a fila de mensagem assíncrono.  
  
## Comentários  
 Iniciando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro gerado pelo assistente irá registrar seus componentes COM em **HKEY\_CURRENT\_USER** em vez de **HKEY\_LOCAL\_MACHINE**.  Para alterar esse comportamento, defina a opção de **Componente do registro para todos os usuários** do assistente de ATL.  
  
## Nomes  
 Especifique os nomes para que o objeto, a interface, e classes sejam adicionadas ao seu projeto.  Com exceção de **Nome curto**, todas as caixas outros podem ser editadas independentemente de outro.  Se você alterar o texto para **Nome curto**, a alteração é refletida em nomes de todas as caixas restantes na página.  Se você alterar o nome de **Coclass** na seção COM, a alteração é refletida em **Tipo** e nas caixas de **ProgID** , mas o nome de **Interface** não muda.  Este comportamento de nomeação é criado para fazer facilmente todos os nomes de identificação para você enquanto você desenvolve seu controle.  
  
 **Nome curto**  
 Define o nome abreviado do objeto.  O nome que você fornece determina os nomes de `Class` e de `Coclass` , os nomes de **.cpp file** e de **.h file** , o nome de **Interface** , os nomes de **Tipo** , e o **ProgID**, a menos que você altere os campos individualmente.  
  
 **arquivo .h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha, ou para anexar a declaração de classe para um arquivo existente.  Se você escolher um arquivo existente, o assistente não o salvou o local selecionado até que você tenha **Concluir** no assistente.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
 **Classe**  
 Define o nome da classe a ser criada.  Esse nome é baseado no nome que você fornece em **Nome curto**, precedido por “C”, o prefixo típico para um nome de classe.  
  
 **arquivo de .cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha.  O arquivo não é salvo no local selecionado até que você tenha **Concluir** no assistente.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a implementação da classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
 **atribuído**  
 Indica se o objeto usa atributos.  Se você estiver adicionando um objeto atribuído a um projeto de ATL, esta opção está selecionada e não disponível alterar.  Isto é, você pode adicionar apenas objetos atribuídos a um projeto criado com suporte do atributo.  
  
 Se você selecionar esta opção para um projeto de ATL que não tenha suporte de atributo, o assistente solicita que você especifique se você deseja adicionar suporte do atributo para o projeto.  
  
 Todos os objetos que você adicionar ao definir esta opção são designados como atribuído por padrão \(a caixa de seleção está selecionada.\)  Você pode desmarque esta caixa para adicionar um objeto que não use atributos.  
  
 Consulte [Configurações do aplicativo, assistente de projeto de ATL](../Topic/Application%20Settings,%20ATL%20Project%20Wizard.md) e [Mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para mais informações.  
  
### COM  
 Fornece informações sobre a funcionalidade da para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indica em esta página do assistente que atributos componentes do usa COM\+ 1,0, você não pode modificar esta opção porque ATL não inclui o atributo de `coclass` .  
  
 **Tipo**  
 Define a descrição do objeto que aparecerá no Registro  
  
 **Interface**  
 Define a interface que você cria para seu objeto.  Essa interface contém seus métodos personalizados.  
  
 **ProgID**  
 Define o nome recipientes podem usar em vez de CLSID do objeto.  
  
## Consulte também  
 [Componente de ATL COM\+ 1,0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)