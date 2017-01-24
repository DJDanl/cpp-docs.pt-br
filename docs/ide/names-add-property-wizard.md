---
title: "Nomes, Assistente para Adicionar Propriedade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.prop.overview"
dev_langs: 
  - "C++"
ms.assetid: 0453b7ea-89cb-41a1-80a2-d45f61589c0a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Nomes, Assistente para Adicionar Propriedade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use este assistente para adicionar uma propriedade a uma interface.  
  
 **Tipo de propriedade**  
 Define o tipo de propriedade que você está adicionando.  Para dispinterfaces do MFC, fornecer seu próprio tipo ou selecione da lista predefinida.  Se você fornecer uma implementação de estoque de uma propriedade,  **tipo de propriedade**  é definido como o tipo de ações e não está disponível para a alteração.  
  
 **Nome da propriedade**  
 Define o nome da propriedade.  Para dispinterfaces do MFC associados a controles de ActiveX, você pode fornecer seu próprio nome ou você pode selecionar um nome de propriedade das ações da lista predefinida.  Se você fornecer seu próprio nome de propriedade, o  **Stock**  tipo de implementação não está disponível.  Consulte  [Propriedades de ações](../ide/stock-properties.md) para obter uma descrição das propriedades na lista.  
  
|Tipo de interface|Descrição|  
|-----------------------|---------------|  
|Interface dupla da ATL, interface personalizada e interface personalizada local|Forneça um nome de propriedade.|  
|Dispinterface MFC, dispinterface de controle de ActiveX do MFC|Forneça um nome de propriedade ou selecione uma propriedade das ações da lista.  Se você selecionar uma propriedade da lista, o valor apropriado aparece no  **tipo de propriedade** caixa.  Você pode alterar esse tipo, dependendo da seleção em  **tipo de implementação**.|  
  
 **Tipo de retorno**  
 Somente interfaces ATL.  Define o tipo de retorno da propriedade.  Para interfaces duas, `HRESULT` é sempre o tipo de retorno, e essa caixa não está disponível.  Para interfaces personalizadas, você pode selecionar um tipo de retorno da lista.  `HRESULT`é recomendado, pois oferece uma maneira padrão para retornar erros.  
  
 **Nome da variável**  
 Somente dispinterfaces do MFC.  Disponível somente se você especificar  **variável de membro**  em  **tipo de implementação**.  Define o nome da variável de membro ao qual a propriedade está associada.  Por padrão, o nome da variável é definido como m \_*PropertyName*.  Você pode editar este nome.  
  
 **Função de notificação**  
 Somente dispinterfaces do MFC.  Disponível somente se você especificar  **variável de membro**  em  **tipo de implementação**.  Define o nome do notificação função chamada se as alterações de propriedade.  Por padrão, o nome da função de notificação é definido em*PropertyName*Changed.  Você pode editar este nome.  
  
 **Obter a função**  
 Para dispinterfaces do MFC.  Disponível somente se você especificar  **métodos Get\/Set** em  **tipo de implementação**.  Define o nome da função para obter a propriedade.  Por padrão, o nome da função Get é definido para Get*PropertyName*.  Você pode editar este nome.  Se você excluir o nome, a função  [GetNotSupported](../Topic/COleControl::GetNotSupported.md) é inserido no mapa de despacho de interface.  Get*PropertyName* função especifica que a propriedade como legível.  
  
 **Função de conjunto**  
 Somente dispinterfaces do MFC.  Disponível somente se você especificar  **métodos Get\/Set** em  **tipo de implementação**.  Define o nome da função para definir a propriedade.  Por padrão, o nome da função conjunto é definido para o conjunto de*PropertyName*.  Você pode editar este nome.  Se você excluir o nome, a função  [SetNotSupported](../Topic/COleControl::SetNotSupported.md) é inserido no mapa de despacho de interface.  O conjunto de*PropertyName* função especifica que a propriedade é gravável.  
  
 **Tipo de implementação**  
 Somente dispinterfaces do MFC.  Especifica como implementar a propriedade que você está adicionando.  
  
|Tipo de implementação|Descrição|  
|---------------------------|---------------|  
|**Estoque**|Especifica uma implementação de estoque para a propriedade selecionada na  **o nome da propriedade**.  O padrão.  Consulte  [Propriedades de ações](../ide/stock-properties.md) para obter mais informações.<br /><br /> Se você especificar  **Stock**, em seguida,  **tipo de propriedade**,  **tipo de parâmetro**, e  **o nome do parâmetro**  estão esmaecidos.|  
|**Variável de membro**|Especifica que a propriedade é adicionada como uma variável de membro.  Você pode adicionar propriedades personalizadas ou a maioria das propriedades de ações como variáveis de membro.  Não é possível especificar  **variável de membro** para  **legenda**,  **hWnd**, e  **texto** propriedades.<br /><br /> Fornece nomes padrão em  **o nome da variável** e  **a função de notificação**.  Você pode editar este nome.|  
|**Métodos de Get\/Set**|Especifica a propriedade é adicionada como Get*PropertyName* e definir*PropertyName* funções, por padrão.  Esses nomes são exibidos sob  **obter a função** e  **definir a função**.<br /><br /> Você pode alterar o padrão  **tipo de propriedade**, que passa um valor para a função Get.  Você pode especificar parâmetros para o  **obter** e `Set` funções.|  
  
 **Obter a função**  
 Para interfaces ATL.  Define a propriedade como legíveis; ou seja, ele cria o  **obter** método para recuperar esta propriedade do objeto.  Você deve selecionar  **obter**, `Put`, ou ambos.  
  
 **Coloque a função**  
 Somente interfaces ATL.  Define a propriedade gravável; ou seja, ele cria o `Put` método para definir ou "colocar", essa propriedade do objeto.  Você deve selecionar  **obter**, `Put`, ou ambos.  Se você selecionar essa opção, você pode escolher entre as duas formas de implementar o método a seguintes:  
  
|Opção|Descrição|  
|-----------|---------------|  
|**PropPut**|O  [PropPut](../windows/propput.md) função retorna uma cópia do objeto.  Este é o padrão e a maneira mais comum para tornar a propriedade gravável.|  
|**PropPutRef**|O  [PropPutRef](../windows/propputref.md) função retorna uma referência ao objeto, em vez de retornar a cópia do próprio objeto.  Considere usar esta opção para objetos, como, por exemplo, grandes estruturas ou arrays, que podem ter a sobrecarga de inicialização.|  
  
 **Atributos de parâmetro**  
 Somente interfaces ATL.  Define se o parâmetro especificado por  **o nome do parâmetro** é  **na**,  **check\-out**, ambos ou nenhum.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Em**|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|  
|**Limite**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado ao procedimento de chamada \(a partir do servidor para o cliente\).|  
  
 **Tipo de parâmetro**  
 Define o tipo de dados do parâmetro.  Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro que você está adicionando para a propriedade, se a propriedade tiver parâmetros.  Depois de clicar em  **Add**, o nome do parâmetro aparece no  **lista de parâmetros**.  
  
 **Lista de parâmetros**  
 Exibe a lista de atributos a serem adicionados à propriedade.  Cada item na lista consiste no nome do parâmetro, tipo de parâmetro e atributos.  Use  **Add** e  **Remover** para atualizar a lista.  
  
 **Add**  
 Adiciona o parâmetro especificado em  **o nome do parâmetro** e  **tipo de parâmetro** para o  **lista de parâmetros**.  Você deve clicar em  **Add** para adicionar um parâmetro à lista.  
  
 **Remove**  
 Remove o parâmetro que você seleciona na  **lista de parâmetros**.  
  
 **Propriedade padrão**  
 Somente dispinterface MFC.  Define essa propriedade como o padrão para a interface.  Uma interface pode ter a propriedade de apenas um padrão; Depois de especificar a propriedade padrão, de quaisquer outras propriedades que você adiciona à interface, esta caixa está disponível.  
  
## Consulte também  
 [Adicionando uma propriedade](../Topic/Adding%20a%20Property%20\(Visual%20C++\).md)   
 [Atributos IDL, Assistente para Adicionar Propriedade](../ide/idl-attributes-add-property-wizard.md)   
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)