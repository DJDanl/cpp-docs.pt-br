---
title: Adicionar classe de Assistente de controle ActiveX | Microsoft Docs
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
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="add-class-from-activex-control-wizard"></a>Assistente para Adicionar Classe de Controle ActiveX
Use este assistente para adicionar uma classe do MFC a partir de um controle ActiveX disponível. O assistente cria uma classe para cada interface que você adicionar a partir do controle ActiveX selecionado.  
  
 **Adicionar classe de**  
 Especifica o local da biblioteca de tipo, do qual a classe é criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Registry**|A biblioteca de tipos é registrada no sistema. Bibliotecas de tipo registradas são listadas na **controles ActiveX disponíveis**.|  
|**Arquivo**|A biblioteca de tipos necessariamente não está registrada no sistema, mas está contida em um arquivo. Você deve fornecer o local do arquivo no **local**.|  
  
 **Controles ActiveX disponíveis**  
 Especifica os controles ActiveX atualmente registrados no sistema. Selecione um controle ActiveX desta lista para exibir suas interfaces no **Interfaces** lista. Consulte [controles ActiveX MFC: distribuindo controles do ActiveX](../mfc/mfc-activex-controls-distributing-activex-controls.md) para obter mais informações sobre como registrar os controles ActiveX.  
  
 Se você clicar em **arquivo** em **Adicionar classe de**, essa caixa fica indisponível para alteração.  
  
 **Local**  
 Especifica o local do controle ActiveX. Se você clicar em **arquivo** em **Adicionar classe de**, você pode fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.  
  
 Se você clicar em **registro** em **Adicionar classe de**, essa caixa fica indisponível para alteração.  
  
 **Interfaces**  
 Especifica as interfaces no controle ActiveX selecionado no momento **controles ActiveX disponíveis** ou na biblioteca de tipos no arquivo especificado no **local**.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona a interface selecionada no momento o **Interfaces** lista. Indisponível se nenhuma interface está selecionada.|  
|**>>**|Adiciona todas as interfaces no controle ActiveX selecionado no momento **controles ActiveX disponíveis** ou na biblioteca de tipos no arquivo especificado no **local**.|  
|**<**|Remove a classe selecionada no momento o **classes geradas** lista. Indisponível se nenhuma classe selecionada no momento o **classes geradas** lista.|  
|**<\<**|Remove todas as classes do **classes geradas** lista. Disponível se o **classes geradas** lista está vazia.|  
  
 **Classes geradas**  
 Especifica os nomes de classe a ser gerado das interfaces adicionadas usando o **>** ou **>>** botão. Você pode clicar nessa caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para rolar a lista, exibindo o nome de cada classe no `Class` caixa e nome de arquivo no **. h arquivo** caixa que o assistente gera quando você clicar em  **Concluir**. Você pode selecionar apenas uma classe em um momento nesta caixa.  
  
 Você pode remover uma classe selecionando-o na lista e clicando em **<**. Não é necessário selecionar uma classe no **classes geradas** caixa para remover todas as classes; clicando **<<**, remova todas as classes a **classes geradas** caixa.  
  
 `Class`  
 Especifica o nome da classe selecionada no **classes geradas** caixa que o assistente adiciona quando você clica em **concluir**. Você pode editar o nome de `Class` caixa.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **classes geradas**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará o local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **classes geradas**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe a partir de um controle ActiveX](../ide/adding-a-class-from-an-activex-control-visual-cpp.md)   
 [Clientes de automação: usando bibliotecas de tipo](../mfc/automation-clients-using-type-libraries.md)