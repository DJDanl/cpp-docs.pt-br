---
title: Assistente para Adicionar Classe por meio de um Controle ActiveX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.class.axcontrol
dev_langs:
- C++
helpviewer_keywords:
- ActiveX Control Wizard
- Add Class from ActiveX Control Wizard [C++]
ms.assetid: 668d801c-5fb6-4176-9191-5c38995a4713
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7ab96943e47287c9b54753c8d3a1edb868804274
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33336811"
---
# <a name="add-class-from-activex-control-wizard"></a>Assistente para Adicionar Classe de Controle ActiveX
Use este assistente para adicionar uma classe MFC por meio de um controle ActiveX disponível. O assistente cria uma classe para cada interface adicionada por meio do controle ActiveX selecionado.  
  
 **Adicionar Classe por meio de**  
 Especifica o local da biblioteca de tipos, com base na qual a classe é criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Controles ActiveX disponíveis**.|  
|**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está contida em um arquivo. É necessário fornecer o local do arquivo em **Local**.|  
  
 **Controles ActiveX disponíveis**  
 Especifica os controles ActiveX atualmente registrados no sistema. Selecione um controle ActiveX nessa lista para exibir suas interfaces na lista **Interfaces**. Confira [Controles ActiveX MFC: distribuindo controles ActiveX](../mfc/mfc-activex-controls-distributing-activex-controls.md) para obter mais informações sobre como registrar controles ActiveX.  
  
 Se você clicar em **Arquivo** em **Adicionar Classe por meio de**, essa caixa não ficará disponível para alteração.  
  
 **Local**  
 Especifica o local do controle ActiveX. Se você clicar em **Arquivo** em **Adicionar Classe por meio de**, poderá fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.  
  
 Se você clicar em **Registro** em **Adicionar Classe por meio de**, essa caixa não ficará disponível para alteração.  
  
 **Interfaces**  
 Especifica as interfaces no controle ActiveX atualmente selecionado em **Controles ActiveX disponíveis** ou na biblioteca de tipos no arquivo especificado em **Local**.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona a interface atualmente selecionada na lista **Interfaces**. Não disponível se nenhuma interface estiver selecionada.|  
|**>>**|Adiciona todas as interfaces no controle ActiveX atualmente selecionado em **Controles ActiveX disponíveis** ou na biblioteca de tipos no arquivo especificado em **Local**.|  
|**<**|Remove a classe atualmente selecionada na lista **Classes geradas**. Não disponível se nenhuma classe estiver atualmente selecionada na lista **Classes geradas**.|  
|**<\<**|Remove todas as classes da lista **Classes geradas**. Não disponível se a lista **Classes geradas** estiver vazia.|  
  
 **classes geradas**  
 Especifica os nomes de classe a serem gerados com base nas interfaces adicionadas por meio do botão **>** ou **>>**. Clique nessa caixa para selecionar uma classe e, em seguida, use as teclas para cima ou para baixo para rolar a lista, exibindo cada nome de classe na caixa `Class` e cada nome de arquivo na caixa **Arquivo .h** gerada pelo assistente quando você clica em **Concluir**. Selecione apenas uma classe por vez nessa caixa.  
  
 Remova uma classe selecionando-a nessa lista e clicando em **<**. Não é necessário selecionar uma classe na caixa **Classes geradas** para remover todas as classes; se você clicar em **<<**, todas as classes da caixa **Classes geradas** serão removidas.  
  
 `Class`  
 Especifica o nome da classe selecionada na caixa **Classes geradas** adicionada pelo assistente quando você clica em **Concluir**. Edite o nome na caixa `Class`.  
  
 **Arquivo .h**  
 Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.  
  
 O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **Arquivo .cpp**  
 Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.  
  
 O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe por meio de um controle ActiveX](../ide/adding-a-class-from-an-activex-control-visual-cpp.md)   
 [Clientes de automação: usando bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)