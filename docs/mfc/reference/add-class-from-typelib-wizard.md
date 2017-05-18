---
title: Adicionar classe de Typelib Assistente | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.class.typelib
dev_langs:
- C++
helpviewer_keywords:
- Add Class from TypeLib Wizard [C++]
- COM interfaces, adding classes
ms.assetid: 96152afd-9374-4649-a6ab-b0fa2a5592a3
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bb05453c24f9f3a87e0860c613065ddf5767f392
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="add-class-from-typelib-wizard"></a>Assistente para adicionar classe de Typelib
Use este assistente para adicionar uma classe do MFC de uma biblioteca de tipos disponíveis. O assistente cria uma classe para cada interface que você adicione da biblioteca de tipo selecionado.  
  
 **Adicionar classe**  
 Especifica o local da biblioteca de tipos, da qual a classe é criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Registro**|A biblioteca de tipos está registrada no sistema. Bibliotecas de tipo registradas são listadas na **bibliotecas de tipos disponíveis**.|  
|**Arquivo**|A biblioteca de tipos não necessariamente está registrada no sistema, mas está contida em um arquivo. Você deve fornecer o local do arquivo em **local**.|  
  
 **Bibliotecas de tipos disponíveis**  
 Lista as bibliotecas de tipo registradas atualmente no sistema. Selecione uma biblioteca de tipos nessa lista para exibir suas interfaces de **Interfaces** lista.  
  
 Consulte "Dentro distribuído: tipo de bibliotecas e linguagem integração COM" na biblioteca MSDN para obter mais informações sobre o registro de bibliotecas de tipo.  
  
 **Local**  
 Especifica o local da biblioteca de tipos. Se você clicar em **arquivo** em **Adicionar classe de**, você pode fornecer o local do arquivo que contém a biblioteca de tipos. Para procurar o local do arquivo, clique no botão de reticências.  
  
 **Interfaces**  
 Lista as interfaces na biblioteca do tipo selecionado no momento o **bibliotecas de tipos disponíveis** lista.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona a interface selecionada no momento o **Interfaces** lista. Esmaecido se nenhuma interface for selecionada.|  
|**>>**|Adiciona todas as interfaces na biblioteca do tipo selecionada no momento o **bibliotecas de tipos disponíveis** lista.|  
|**<**|Remove a classe selecionada no momento o **classes geradas** lista. Esmaecido se nenhuma classe selecionado no momento o **classes geradas** lista.|  
|**<\<**|Remove todas as classes de **classes geradas** lista. Esmaecido se o **classes geradas** lista está vazia.|  
  
 **Classes geradas**  
 Especifica os nomes de classe para ser gerado a partir das interfaces adicionadas usando o ** > ** ou ** >> ** botão. Você pode clique nesta caixa para selecionar uma classe e, em seguida, use as teclas ou para baixo para percorrer a lista, exibindo cada nome de classe de `Class` caixa e nome de arquivo no **arquivo** caixa que o assistente gera quando você clica em **concluir**. Você pode selecionar apenas uma classe em um momento nesta caixa.  
  
 Você pode remover uma classe selecionando-a na lista e clicando em ** < **. Você não precisa selecionar uma classe na caixa de classes geradas para remover todas as classes; clicando em ** << **, remova todas as classes no **classes geradas** caixa.  
  
 `Class`  
 Especifica o nome da classe selecionada no **classes geradas** caixa que o assistente adiciona quando você clica em **concluir**. Você pode editar o nome de `Class` caixa.  
  
 **Arquivo**  
 Define o nome do arquivo de cabeçalho para a nova classe. Por padrão, esse nome se baseia o nome fornecido no **classes geradas**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Classe do MFC de uma biblioteca de tipos](../../mfc/reference/adding-an-mfc-class-from-a-type-library.md)   
 [Clientes de automação: Usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)


