---
title: Nomes, Assistente para adicionar propriedade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.prop.overview
dev_langs:
- C++
ms.assetid: 0453b7ea-89cb-41a1-80a2-d45f61589c0a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9c1728dfda3ec29e8df2b7f5480e9bffb161da7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="names-add-property-wizard"></a>Nomes, Assistente para Adicionar Propriedade
Use este assistente para adicionar uma propriedade a uma interface.  
  
 **Tipo de propriedade**  
 Define o tipo de propriedade que você está adicionando. Para dispinterfaces MFC, fornecer seu próprio tipo ou selecione da lista predefinida. Se você fornecer uma implementação de uma propriedade de estoque **tipo de propriedade** é definido como o tipo de ação e não está disponível para a alteração.  
  
 **Nome da propriedade**  
 Define o nome da propriedade. Para dispinterfaces MFC associados com controles ActiveX, você pode fornecer seu próprio nome ou você pode selecionar um nome de propriedade de estoque da lista predefinida. Se você fornecer seu próprio nome de propriedade, o **estoque** tipo de implementação não está disponível. Consulte [propriedades de estoque](../ide/stock-properties.md) para obter uma descrição das propriedades na lista.  
  
|Tipo de interface|Descrição|  
|--------------------|-----------------|  
|Interface dupla ATL, interface personalizada e interface personalizada local|Forneça um nome de propriedade.|  
|Dispinterface MFC, dispinterface de controle ActiveX MFC|Forneça um nome de propriedade ou selecione uma propriedade de estoque na lista. Se você selecionar uma propriedade na lista, o valor apropriado aparece no **tipo de propriedade** caixa. Você pode alterar esse tipo, dependendo da seleção em **implementação do tipo**.|  
  
 **Tipo de retorno**  
 Apenas interfaces ATL. Define o tipo de retorno para a propriedade. Para interfaces duplas, `HRESULT` sempre é o tipo de retorno, e essa caixa fica indisponível. Para interfaces personalizados, você pode selecionar um tipo de retorno na lista. `HRESULT`ainda é recomendável, porque ele fornece uma maneira padrão para retornar erros.  
  
 **Nome da variável**  
 Somente dispinterfaces do MFC. Disponível somente se você especificar **variável membro** em **implementação do tipo**. Define o nome da variável de membro ao qual a propriedade está associada. Por padrão, o nome da variável é definido como m _*PropertyName*. Você pode editar esse nome.  
  
 **Função de notificação**  
 Somente dispinterfaces do MFC. Disponível somente se você especificar **variável membro** em **implementação do tipo**. Define o nome da notificação função chamada se as alterações de propriedade. Por padrão, o nome da função de notificação é definido como ativado*PropertyName*alterado. Você pode editar esse nome.  
  
 **Função Get**  
 Para dispinterfaces do MFC. Disponível somente se você especificar **métodos Get/Set** em **implementação do tipo**. Define o nome da função para obter a propriedade. Por padrão, o nome da função Get é definido como Get*PropertyName*. Você pode editar esse nome. Se você excluir o nome, a função [GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported) é inserido no mapa de expedição de interface. Get*PropertyName* função especifica que a propriedade como legível.  
  
 **Função de conjunto**  
 Somente dispinterfaces do MFC. Disponível somente se você especificar **métodos Get/Set** em **implementação do tipo**. Define o nome da função para definir a propriedade. Por padrão, o nome da função de conjunto é definido como conjunto*PropertyName*. Você pode editar esse nome. Se você excluir o nome, a função [SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported) é inserido no mapa de expedição de interface. O conjunto*PropertyName* função especifica que a propriedade é gravável.  
  
 **Tipo de implementação**  
 Somente dispinterfaces do MFC. Especifica como implementar a propriedade que você está adicionando.  
  
|Tipo de implementação|Descrição|  
|-------------------------|-----------------|  
|**Estoque**|Especifica uma implementação de estoque para a propriedade selecionada em **nome da propriedade**. O padrão. Consulte [propriedades de estoque](../ide/stock-properties.md) para obter mais informações.<br /><br /> Se você especificar **estoque**, em seguida, **tipo de propriedade**, **tipo de parâmetro**, e **nome do parâmetro** estão esmaecidos.|  
|**Variável de membro**|Especifica que a propriedade é adicionada como uma variável de membro. Você pode adicionar propriedades personalizadas ou a maioria das propriedades de estoque como variáveis de membro. Não é possível especificar **variável membro** para **legenda**, **hWnd**, e **texto** propriedades.<br /><br /> Fornece nomes padrão em **nome de variável** e **função notificação**. Você pode editar esse nome.|  
|**Métodos Get/Set**|Especifica a propriedade é adicionada como Get*PropertyName* e defina*PropertyName* funções, por padrão. Esses nomes aparecerão em **obter função** e **função Set**.<br /><br /> Você pode alterar o padrão **tipo de propriedade**, que transmite um valor para a função Get. Você pode especificar parâmetros para o **obter** e `Set` funções.|  
  
 **Função Get**  
 Para interfaces ATL. Define a propriedade como legível; ou seja, ele cria o **obter** método para recuperar esta propriedade do objeto. Você deve selecionar **obter**, `Put`, ou ambos.  
  
 **Colocar a função**  
 Apenas interfaces ATL. Define a propriedade gravável; ou seja, ele cria o `Put` método para definir ou "colocando", essa propriedade do objeto. Você deve selecionar **obter**, `Put`, ou ambos. Se você selecionar essa opção, você pode escolher entre duas maneiras de implementar o método a seguir:  
  
|Opção|Descrição|  
|------------|-----------------|  
|**PropPut**|O [PropPut](../windows/propput.md) função retorna uma cópia do objeto. Este é o padrão e a maneira mais comum para tornar a propriedade gravável.|  
|**PropPutRef**|O [PropPutRef](../windows/propputref.md) função retorna uma referência para o objeto, em vez de retornar a cópia do objeto em si. Considere usar essa opção para objetos, como estruturas grandes ou matrizes, que podem ter a sobrecarga de inicialização.|  
  
 **Atributos de parâmetro**  
 Apenas interfaces ATL. Define se o parâmetro especificado pelo **nome do parâmetro** é **na**, **out**, ambos ou nenhum.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**in**|Indica que o parâmetro é transmitido do procedimento de chamada para o procedimento chamado.|  
|**out**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|  
  
 **Tipo de parâmetro**  
 Define o tipo de dados do parâmetro. Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro que você está adicionando para a propriedade, se a propriedade tem parâmetros. Depois de clicar em **adicionar**, o nome do parâmetro aparece no **lista de parâmetros**.  
  
 **Lista de parâmetros**  
 Exibe a lista de atributos a serem adicionadas à propriedade. Cada item na lista consiste do nome de parâmetro, tipo de parâmetro e atributos. Use **adicionar** e **remover** para atualizar a lista.  
  
 **Adicionar**  
 Adiciona o parâmetro que você especificar na **nome do parâmetro** e **tipo de parâmetro** para o **lista de parâmetros**. Você deve clicar em **adicionar** para adicionar um parâmetro à lista.  
  
 **Removerr**  
 Remove o parâmetro selecionado na **lista de parâmetros**.  
  
 **Propriedade padrão**  
 Dispinterface MFC somente. Define essa propriedade como o padrão para a interface. Uma interface pode ter apenas uma propriedade padrão; Depois de especificar a propriedade padrão, as outras propriedades que você adicionar à interface, essa caixa fica indisponível.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Atributos IDL, Assistente para adicionar propriedade](../ide/idl-attributes-add-property-wizard.md)   
 [Implementando uma Interface](../ide/implementing-an-interface-visual-cpp.md)