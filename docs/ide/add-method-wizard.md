---
title: Adicionar Assistente de método | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.method.overview
dev_langs:
- C++
helpviewer_keywords:
- Add Method Wizard [C++]
- methods [C++], adding using wizards
ms.assetid: b9a71b0e-9ecf-40fa-9f86-4200cb23d671
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cc2ebd18640f0ab778cb45252691e63206861d53
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="add-method-wizard"></a>Assistente de Adição de Método
Use este assistente para adicionar um método para uma interface. Dependendo do tipo de projeto ou o tipo de interface à qual você está adicionando um método, o assistente exibe opções diferentes.  
  
## <a name="names"></a>Nomes  
 **Tipo de retorno**  
 O tipo de dados retornado pelo método. `HRESULT` é recomendado para todos os tipos de interface, porque ele fornece uma maneira padrão para retornar erros.  
  
|Tipo de interface|Descrição|  
|--------------------|-----------------|  
|Interface dupla|`HRESULT`. Inalterável.|  
|Interface personalizada|`HRESULT`. Inalterável.|  
|Interface personalizada local|Fornecer seu próprio tipo de retorno ou selecione na lista.|  
|Dispinterface|Fornecer seu próprio tipo de retorno ou selecione na lista.|  
|Dispinterface de controle ActiveX MFC|Se você implementar um método de estoque, o tipo de retorno é definido como o valor apropriado e não pode ser alterado. Se você selecionar um método do **nome do método** lista e clique em **personalizado** em **Selecionar tipo de método**, selecione um tipo de retorno na lista.|  
  
 **Nome do método**  
 Define o nome do método.  
  
|Tipo de interface|Descrição|  
|--------------------|-----------------|  
|Interface dupla ATL, interface personalizada e interface personalizada local|Fornece seu próprio nome de método.|  
|Dispinterface MFC|Fornecer seu próprio nome de método ou selecione um nome de método sugerido na lista. Se você selecionar um nome na lista, o valor apropriado aparece no **tipo de retorno** caixa e ele não pode ser alterado.|  
|Dispinterface de controle ActiveX MFC|Fornecer sua própria ou selecione um dos métodos de estoque [DoClick](../mfc/reference/colecontrol-class.md#doclick) e [atualizar](../mfc/reference/colecontrol-class.md#refresh). Consulte [controles ActiveX MFC: adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md) para obter mais informações.|  
  
 **Tipo de método**  
 Disponível somente para controles ActiveX MFC. Se você fornecer um nome de método no **nome do método** caixa, em vez de selecionar um método na lista, essa caixa fica indisponível.  
  
 Se você selecionar um dos métodos no **nome do método** , selecione a implementação de estoque ou uma implementação personalizada.  
  
|Tipo de método|Descrição|  
|-----------------|-----------------|  
|**Estoque**|O padrão. Insere a implementação das ações do método que você selecionar no **nome do método** lista. **Tipo de retorno** não pode ser alterado se você selecionar **estoque**.|  
|**Personalizado**|Insere uma implementação de stub do método selecionado no **nome do método** lista. Para tipos de método personalizado, você pode fornecer seu próprio tipo de retorno, ou você pode selecionar uma opção do **tipo de retorno** lista.|  
  
 **Nome interno**  
 Disponível para somente métodos personalizados adicionados a um dispinterface MFC. Define o nome usado no mapa de expedição, o arquivo de cabeçalho (. h) e o arquivo de implementação (. cpp). Por padrão, esse nome é o mesmo que **nome do método**. Você pode alterar o nome do método, se você estiver trabalhando com um dispinterface MFC ou se você estiver adicionando um método personalizado para um dispinterface de controle ActiveX do MFC.  
  
|Tipo de interface|Descrição|  
|--------------------|-----------------|  
|Interface dupla ATL, interface personalizada e interface personalizada local|Não disponível|  
|Dispinterface MFC|Defina como o nome do método por padrão. Você pode editar o nome interno.|  
|Dispinterface de controle ActiveX MFC|Você pode definir o nome interno apenas para métodos personalizados. Métodos de estoque não usam um nome interno.|  
  
 **Atributos de parâmetro**  
 Define os atributos adicionais para o parâmetro especificado em **nome do parâmetro**.  
  
|Atributo de parâmetro|Descrição|Combinações permitidas|  
|-------------------------|-----------------|--------------------------|  
|**In**|Indica que o parâmetro é transmitido do procedimento de chamada para o procedimento chamado.|**em** apenas<br /><br /> **em** e **-out**|  
|**Saída**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|**limite** apenas<br /><br /> **em** e **-out**<br /><br /> **out** e **retval**|  
|**retval**|Indica que o parâmetro recebe o valor de retorno do membro.|**retval** e out|  
  
 **Tipo de parâmetro**  
 Define o tipo de dados do parâmetro. Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro para passar pelo seu método. Depois de digitar o nome, você deve clicar em **adicionar** para adicioná-lo à lista de parâmetros que passará por meio de seu método. Se você não fornecer um nome de parâmetro, o assistente ignora quaisquer atributos de parâmetro (ATL) ou **tipo de parâmetro** seleções.  
  
 Depois de clicar em **adicionar**, o nome do parâmetro aparece no **lista de parâmetros**.  
  
 **Observação** se você fornecer um nome de parâmetro e, em seguida, clique em **concluir** antes de clicar em **adicionar**, o parâmetro não for adicionado ao método. Você deve localizar o método e inserir o parâmetro manualmente.  
  
 **Adicionar**  
 Adiciona o parâmetro que você especificar na **nome do parâmetro**e seus atributos de tipo e o parâmetro, a **lista de parâmetros**. Você deve clicar em **adicionar** para adicionar um parâmetro à lista.  
  
 **Removerr**  
 Remove o parâmetro selecionado na **lista de parâmetros** da lista.  
  
 **Lista de parâmetros**  
 Exibe todos os parâmetros e os modificadores e tipos adicionados no momento para o método. Como adicionar parâmetros, o assistente atualiza **lista de parâmetros** para exibir cada parâmetro, com o modificador e tipo.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando um método](../ide/adding-a-method-visual-cpp.md)   
 [Atributos IDL, Assistente de Adição de Método](../ide/idl-attributes-add-method-wizard.md)