---
title: Adicionar classe de Typelib Assistente | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.class.typelib
dev_langs: C++
helpviewer_keywords:
- Add Class from TypeLib Wizard [MFC]
- COM interfaces, adding classes
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a4aad89b6f3227cac59b6429cc67975db3dad424
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="add-class-from-typelib-wizard"></a>Assistente para adicionar classe de Typelib
Use este assistente para adicionar uma classe do MFC de uma biblioteca de tipos disponíveis. O assistente cria uma classe para cada interface que você adicionar a biblioteca de tipos selecionados.  
  
 **Adicionar classe de**  
 Especifica o local da biblioteca de tipo, do qual a classe é criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Registry**|A biblioteca de tipos é registrada no sistema. Bibliotecas de tipo registradas são listadas na **bibliotecas de tipo disponível**.|  
|**Arquivo**|A biblioteca de tipos necessariamente não está registrada no sistema, mas está contida em um arquivo. Você deve fornecer o local do arquivo no **local**.|  
  
 **Bibliotecas de tipo disponível**  
 Lista as bibliotecas de tipo atualmente registradas no sistema. Selecione uma biblioteca de tipos na lista para exibir suas interfaces no **Interfaces** lista.  
  
 Consulte "Dentro de Distributed COM: tipo bibliotecas e linguagem integração" na biblioteca MSDN para obter mais informações sobre o registro de bibliotecas de tipo.  
  
 **Local**  
 Especifica o local da biblioteca de tipos. Se você clicar em **arquivo** em **Adicionar classe de**, você pode fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.  
  
 **Interfaces**  
 Lista as interfaces na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** lista.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona a interface selecionada no momento o **Interfaces** lista. Esmaecido se nenhuma interface está selecionada.|  
|**>>**|Adiciona todas as interfaces na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** lista.|  
|**<**|Remove a classe selecionada no momento o **classes geradas** lista. Esmaecido se nenhuma classe selecionada no momento o **classes geradas** lista.|  
|**<\<**|Remove todas as classes do **classes geradas** lista. Esmaecido se o **classes geradas** lista está vazia.|  
  
 **Classes geradas**  
 Especifica os nomes de classe a ser gerado das interfaces adicionadas usando o  **>**  ou  **>>**  botão. Você pode clicar nessa caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para rolar a lista, exibindo o nome de cada classe no `Class` caixa e nome de arquivo no **arquivo** caixa que o assistente gera quando você clicar em  **Concluir**. Você pode selecionar apenas uma classe em um momento nesta caixa.  
  
 Você pode remover uma classe selecionando-o na lista e clicando em  **<** . Você não precisa selecionar uma classe na caixa de classes geradas para remover todas as classes; clicando em  **<<** , remova todas as classes de **classes geradas** caixa.  
  
 `Class`  
 Especifica o nome da classe selecionada no **classes geradas** caixa que o assistente adiciona quando você clica em **concluir**. Você pode editar o nome de `Class` caixa.  
  
 **Arquivo**  
 Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome é baseado no nome que você fornecer em **classes geradas**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará o local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)   
 [Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)

