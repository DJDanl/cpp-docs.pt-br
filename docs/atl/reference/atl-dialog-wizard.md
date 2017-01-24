---
title: "Assistente da caixa de di&#225;logo de ATL | Microsoft Docs"
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
  - "vc.codewiz.class.atl.dlg.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente da caixa de diálogo de ATL"
  - "Projetos de ATL, adicionando recursos da caixa de diálogo"
ms.assetid: b0b9ace5-83c9-40d3-82c3-eb6293f10583
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente da caixa de di&#225;logo de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Insere de este assistente no projeto que uma caixa de diálogo de ATL objetos, derivada de [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md).  Uma caixa de diálogo derivada de `CAxDialogImpl` pode hospedar controles ActiveX.  
  
 O assistente cria um recurso da caixa de diálogo com **OK** padrão e botões de **Cancelar** .  Você pode editar o recurso da caixa de diálogo e adicionar controles ActiveX usando [Editor de Caixa de Diálogo](../../mfc/dialog-editor.md) no modo de recurso.  
  
 Insere do assistente no arquivo de cabeçalho [mapa de mensagem](../../atl/message-maps-atl.md) e declarações para manipular os eventos padrão de clique.  Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações sobre caixas de diálogo de ATL.  
  
 **Nome curto**  
 Define o nome abreviado para o objeto da caixa de diálogo de ATL.  O nome que você fornece determina o nome da classe e os nomes de arquivos \(.h e .cpp\), a menos que você altere os campos individualmente.  
  
 `Class`  
 Define o nome da classe a ser criada.  Esse nome é baseado no nome que você fornece em **Nome curto**, precedido por “C”, o prefixo típico para um nome de classe.  
  
 **.h file**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha, ou para anexar a declaração de classe para um arquivo existente.  Se você escolher um arquivo existente, o assistente não o salvou o local selecionado até que você tenha **Concluir** no assistente.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
 **.cpp file**  
 Define o nome do arquivo de implementação para a nova classe de objeto.  Por padrão, esse nome é baseado no nome que você fornece em **Nome curto**.  Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha.  O arquivo não é salvo no local selecionado até que você tenha **Concluir** no assistente.  
  
 o assistente não substitui um arquivo.  Se você selecionar o nome de um arquivo existente, quando você clica **Concluir**, o assistente solicita que você indique se a implementação da classe deve ser acrescentada ao conteúdo do arquivo.  Clique **Sim** para anexar o arquivo; clique **Não** para retornar para o assistente e para especificar outro nome de arquivo.  
  
## Consulte também  
 [Caixa de diálogo de ATL](../../atl/reference/adding-an-atl-dialog-box.md)