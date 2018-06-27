---
title: Adicionar classe de Typelib Assistente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.class.typelib
dev_langs:
- C++
helpviewer_keywords:
- Add Class from TypeLib Wizard [MFC]
- COM interfaces, adding classes
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc26f74de76205041228ce92e29309af1ce8959f
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951667"
---
# <a name="add-class-from-typelib-wizard"></a>Assistente para adicionar classe de Typelib
Use este assistente para adicionar uma classe do MFC de uma biblioteca de tipos disponíveis. O assistente cria uma classe para cada interface que você adicionar a biblioteca de tipos selecionados.  
  
 **Adicionar classe de**  
 Especifica o local da biblioteca de tipos, com base na qual a classe é criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Bibliotecas de tipos disponíveis**.|  
|**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está contida em um arquivo. É necessário fornecer o local do arquivo em **Local**.|  
  
 **Bibliotecas de tipos disponíveis**  
 Lista as bibliotecas de tipo atualmente registradas no sistema. Selecione uma biblioteca de tipos na lista para exibir suas interfaces no **Interfaces** lista.  
  
 Consulte "Dentro de Distributed COM: tipo bibliotecas e linguagem integração" na biblioteca MSDN para obter mais informações sobre o registro de bibliotecas de tipo.  
  
 **Local**  
 Especifica o local da biblioteca de tipos. Se você clicar em **Arquivo** em **Adicionar Classe por meio de**, poderá fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.  
  
 **Interfaces**  
 Lista as interfaces na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** lista.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona a interface atualmente selecionada na lista **Interfaces**. Esmaecido se nenhuma interface está selecionada.|  
|**>>**|Adiciona todas as interfaces na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** lista.|  
|**<**|Remove a classe atualmente selecionada na lista **Classes geradas**. Esmaecido se nenhuma classe selecionada no momento o **classes geradas** lista.|  
|**<\<**|Remove todas as classes da lista **Classes geradas**. Esmaecido se o **classes geradas** lista está vazia.|  
  
 **classes geradas**  
 Especifica os nomes de classe a serem gerados com base nas interfaces adicionadas por meio do botão **>** ou **>>**. Você pode clicar nessa caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para rolar a lista, exibindo o nome de cada classe no **classe** caixa e nome de arquivo no **arquivo** caixa que o assistente gera quando você Clique em **concluir**. Selecione apenas uma classe por vez nessa caixa.  
  
 Remova uma classe selecionando-a nessa lista e clicando em **<**. Você não precisa selecionar uma classe na caixa de classes geradas para remover todas as classes; clicando em **<<**, remova todas as classes de **classes geradas** caixa.  
  
 **Class**  
 Especifica o nome da classe selecionada na caixa **Classes geradas** adicionada pelo assistente quando você clica em **Concluir**. Você pode editar o nome de **classe** caixa.  
  
 **Arquivo**  
 Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.  
  
 O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)   
 [Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)

