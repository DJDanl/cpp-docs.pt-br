---
title: Nomes, Assistente de Adição de Propriedade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.prop.overview
dev_langs:
- C++
ms.assetid: 0453b7ea-89cb-41a1-80a2-d45f61589c0a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 17c3fd5cfc86f76fcdc1c301bd92bb1fdfac3b9c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339560"
---
# <a name="names-add-property-wizard"></a>Nomes, Assistente para Adicionar Propriedade
Use este assistente para adicionar uma propriedade a uma interface.  
  
 **Tipo de propriedade**  
 Define o tipo de propriedade que está sendo adicionado. Para dispinterfaces MFC, forneça seu próprio tipo ou selecione um na lista predefinida. Se você fornecer uma implementação de estoque de uma propriedade, **Tipo de propriedade** será definido como o tipo de estoque e não ficará disponível para alteração.  
  
 **Nome da propriedade**  
 Define o nome da propriedade. Para dispinterfaces MFC associadas a controles ActiveX, forneça seu próprio nome ou selecione um nome de propriedade de estoque na lista predefinida. Se você fornecer seu próprio nome de propriedade, o tipo de implementação **Estoque** não ficará disponível. Confira [Propriedades de estoque](../ide/stock-properties.md) para obter uma descrição das propriedades na lista.  
  
|Tipo de interface|Descrição|  
|--------------------|-----------------|  
|Interface dupla ATL, interface personalizada e interface personalizada local|Forneça um nome de propriedade.|  
|Dispinterface MFC, dispinterface MFC do controle ActiveX|Forneça um nome de propriedade ou selecione uma propriedade de estoque na lista. Se você selecionar uma propriedade na lista, o valor apropriado será exibido na caixa **Tipo de propriedade**. Você pode alterar esse tipo, dependendo da seleção em **Tipo de implementação**.|  
  
 **Tipo de retorno**  
 Somente interfaces ATL. Define o tipo de retorno para a propriedade. Para interfaces duplas, `HRESULT` sempre é o tipo de retorno, e essa caixa não fica disponível. Para interfaces personalizadas, selecione um tipo de retorno na lista. `HRESULT` ainda é recomendável, porque fornece uma maneira padrão de retornar erros.  
  
 **Nome da variável**  
 Somente dispinterfaces MFC. Disponível somente se você especificar **Variável de membro** em **Tipo de implementação**. Define o nome da variável de membro ao qual a propriedade está associada. Por padrão, o nome da variável é definido como m_*PropertyName*. É possível editar esse nome.  
  
 **Função de notificação**  
 Somente dispinterfaces MFC. Disponível somente se você especificar **Variável de membro** em **Tipo de implementação**. Define o nome da função de notificação chamada se a propriedade é alterada. Por padrão, o nome da função de notificação é definido como On*PropertyName*Changed. É possível editar esse nome.  
  
 **Função Get**  
 Para dispinterfaces MFC. Disponível somente se você especificar **Métodos Get/Set** em **Tipo de implementação**. Define o nome da função para obter a propriedade. Por padrão, o nome da função Get é definido como Get*PropertyName*. É possível editar esse nome. Se você excluir o nome, a função [GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported) será inserida no mapa de expedição da interface. A função Get*PropertyName* especifica a propriedade como legível.  
  
 **Função Set**  
 Somente dispinterfaces MFC. Disponível somente se você especificar **Métodos Get/Set** em **Tipo de implementação**. Define o nome da função para definir a propriedade. Por padrão, o nome da função Set é definido como Set*PropertyName*. É possível editar esse nome. Se você excluir o nome, a função [SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported) será inserida no mapa de expedição da interface. A função Set*PropertyName* especifica que a propriedade é gravável.  
  
 **Tipo de implementação**  
 Somente dispinterfaces MFC. Especifica como implementar a propriedade que está sendo adicionada.  
  
|Tipo de implementação|Descrição|  
|-------------------------|-----------------|  
|**Estoque**|Especifica uma implementação de estoque para a propriedade selecionada em **Nome da propriedade**. O padrão. Confira [Propriedades de estoque](../ide/stock-properties.md) para obter mais informações.<br /><br /> Se você especificar **Estoque**, as opções **Tipo de propriedade**, **Tipo de parâmetro** e **Nome do parâmetro** ficarão esmaecidas.|  
|**Variável de membro**|Especifica que a propriedade é adicionada como uma variável de membro. Adicione propriedades personalizadas ou a maioria das propriedades de estoque como variáveis de membro. Não é possível especificar **Membro de variável** para as propriedades **Caption**, **hWnd** e **Text**.<br /><br /> Fornece nomes padrão em **Nome da variável** e **Função de notificação**. É possível editar esse nome.|  
|**Métodos Get/Set**|Especifica que a propriedade é adicionada como as funções Get*PropertyName* e Set*PropertyName*, por padrão. Esses nomes são exibidos em **Função Get** e **Função Set**.<br /><br /> Altere o **Tipo de propriedade** padrão, que passa um valor para a função Get. Especifique parâmetros para as funções **Get** e `Set`.|  
  
 **Função Get**  
 Para interfaces ATL. Define a propriedade como legível; ou seja, ela cria o método **Get** para recuperar essa propriedade do objeto. Você precisa selecionar **Get**, `Put` ou ambos.  
  
 **Função Put**  
 Somente interfaces ATL. Define a propriedade gravável; ou seja, ela cria o método `Put` para definição, ou "colocação", dessa propriedade do objeto. Você precisa selecionar **Get**, `Put` ou ambos. Se você selecionar essa opção, poderá escolher uma das duas seguintes maneiras de implementar o método:  
  
|Opção|Descrição|  
|------------|-----------------|  
|**PropPut**|A função [PropPut](../windows/propput.md) retorna uma cópia do objeto. Esse é o padrão e a maneira mais comum para tornar a propriedade gravável.|  
|**PropPutRef**|A função [PropPutRef](../windows/propputref.md) retorna uma referência ao objeto, em vez de retornar a cópia do objeto em si. Considere o uso dessa opção para objetos, como structs ou matrizes grandes, que podem ter a sobrecarga de inicialização.|  
  
 **Atributos de parâmetro**  
 Somente interfaces ATL. Define se o parâmetro especificado pelo **Nome do parâmetro** é **in**, **out**, ambos ou nenhum.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**in**|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|  
|**out**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado para o procedimento de chamada (do servidor para o cliente).|  
  
 **Tipo de parâmetro**  
 Define o tipo de dados do parâmetro. Selecione o tipo na lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro que está adicionado à propriedade, se a propriedade tiver parâmetros. Depois de clicar em **Adicionar**, o nome do parâmetro é exibido em **Lista de parâmetros**.  
  
 **Lista de parâmetros**  
 Exibe a lista de atributos a serem adicionadas à propriedade. Cada item na lista consiste no nome de parâmetro, no tipo de parâmetro e nos atributos. Use **Adicionar** e **Remover** para atualizar a lista.  
  
 **Adicionar**  
 Adiciona o parâmetro especificado em **Nome do parâmetro** e em **Tipo de parâmetro** à **Lista de parâmetros**. Clique em **Adicionar** para adicionar um parâmetro à lista.  
  
 **Removerr**  
 Remove o parâmetro selecionado em **Lista de parâmetros**.  
  
 **Propriedade padrão**  
 Somente dispinterface MFC. Define essa propriedade como o padrão para a interface. Uma interface pode ter apenas uma propriedade padrão; depois de especificar a propriedade padrão, para as outras propriedades adicionadas à interface, essa caixa não fica disponível.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma propriedade](../ide/adding-a-property-visual-cpp.md)   
 [Atributos IDL, Assistente de Adição de Propriedade](../ide/idl-attributes-add-property-wizard.md)   
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)