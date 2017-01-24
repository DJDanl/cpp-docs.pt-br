---
title: "Assistente de Adi&#231;&#227;o de M&#233;todo | Microsoft Docs"
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
  - "vc.codewiz.method.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de Adição de Método [C++]"
  - "métodos [C++], adicionando usando assistentes"
ms.assetid: b9a71b0e-9ecf-40fa-9f86-4200cb23d671
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de Adi&#231;&#227;o de M&#233;todo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use este assistente para adicionar um método para uma interface.  Dependendo do tipo de projeto ou tipo de interface ao qual você está adicionando um método, o assistente exibe opções diferentes.  
  
## Nomes  
 **Tipo de retorno**  
 O tipo de dados retornado pelo método.  `HRESULT`é recomendado para todos os tipos de interface, pois oferece uma maneira padrão para retornar erros.  
  
|Tipo de interface|Descrição|  
|-----------------------|---------------|  
|Interface dupla|`HRESULT`.  Inalterável.|  
|Interface personalizada|`HRESULT`.  Inalterável.|  
|Interface personalizada local|Fornecer seu próprio tipo de retorno ou selecione na lista.|  
|Dispinterface|Fornecer seu próprio tipo de retorno ou selecione na lista.|  
|Dispinterface de controle de ActiveX do MFC|Se você implementar um método de ações, o tipo de retorno é definido como o valor apropriado e é inalterável.  Se você selecionar um método a partir o  **nome do método** lista e clique em  **personalizado** em  **Selecione o tipo de método de**, selecione um tipo de retorno da lista.|  
  
 **Nome do Método**  
 Define o nome do método.  
  
|Tipo de interface|Descrição|  
|-----------------------|---------------|  
|Interface dupla da ATL, interface personalizada e interface personalizada local|Fornece seu próprio nome de método.|  
|Dispinterface MFC|Fornecer seu próprio nome de método ou selecione um nome de método sugerido na lista.  Se você selecionar um nome na lista, o valor apropriado aparece no  **tipo de retorno** caixa e é inalterável.|  
|Dispinterface de controle de ActiveX do MFC|Forneça o seu próprio ou selecione um dos métodos ações  [DoClick](../Topic/COleControl::DoClick.md) e  [Atualizar](../Topic/COleControl::Refresh.md).  Consulte  [controles de ActiveX do MFC: adição de métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md) para obter mais informações.|  
  
 **Tipo de método**  
 Disponível somente para controles de ActiveX do MFC.  Se você fornecer um nome de método no  **nome do método** caixa, em vez de selecionar um método da lista, esta caixa está disponível.  
  
 Se você selecionar um dos métodos na  **nome do método** lista, selecione a implementação de estoque ou uma implementação personalizada.  
  
|Tipo de método|Descrição|  
|--------------------|---------------|  
|**Estoque**|O padrão.  Insere a implementação das ações do método selecionado na  **nome do método** lista.  **Tipo de retorno** é inalterável, se você selecionar  **Stock**.|  
|**Personalizado**|Insere uma implementação de stub do método selecionado na  **nome do método** lista.  Para tipos de método personalizado, você pode fornecer seu próprio tipo de retorno, ou você pode selecionar dentre as  **tipo de retorno** lista.|  
  
 **Nome interno**  
 Disponível para apenas métodos personalizados adicionados a um dispinterface MFC.  Define o nome usado no mapa de expedição, o arquivo de cabeçalho \(. h\) e o arquivo de implementação \(CPP\).  Por padrão, esse nome é igual a  **nome do método**.  Você pode alterar o nome do método se você estiver trabalhando com um dispinterface MFC ou se você estiver adicionando um método personalizado para um dispinterface de controle ActiveX do MFC.  
  
|Tipo de interface|Descrição|  
|-----------------------|---------------|  
|Interface dupla da ATL, interface personalizada e interface personalizada local|Não disponível|  
|Dispinterface MFC|Defina como o nome do método por padrão.  Você pode editar o nome interno.|  
|Dispinterface de controle de ActiveX do MFC|Você pode definir o nome interno somente para métodos personalizados.  Métodos de ações não usam um nome interno.|  
  
 **Atributos de parâmetro**  
 Define os atributos adicionais para o parâmetro especificado na  **o nome do parâmetro**.  
  
|Atributo de parâmetro|Descrição|Combinações permitidas|  
|---------------------------|---------------|----------------------------|  
|**Em**|Indica que o parâmetro é passado do procedimento de chamada para o procedimento chamado.|**na** apenas<br /><br /> **in** and **out**|  
|**Check\-out**|Indica que o parâmetro de ponteiro é retornado do procedimento chamado ao procedimento de chamada \(a partir do servidor para o cliente\).|**check\-out**  apenas<br /><br /> **in** and **out**<br /><br /> **check\-out** e  **retval**|  
|**Retval**|Indica que o parâmetro recebe o valor de retorno do membro.|**retval** e out|  
  
 **Tipo de parâmetro**  
 Define o tipo de dados do parâmetro.  Selecione o tipo da lista.  
  
 **Nome do parâmetro**  
 Define o nome de um parâmetro para passar por seu método.  Depois de digitar o nome, você deve clicar em  **Add** para adicioná\-lo à lista de parâmetros que deverão passar pelo seu método.  Se você não fornecer um nome de parâmetro, o assistente ignora quaisquer atributos de parâmetro \(ATL somente\) ou  **tipo de parâmetro** seleções.  
  
 Depois de clicar em  **Add**, o nome do parâmetro aparece no  **lista de parâmetros**.  
  
 **Nota** se você fornecer um nome de parâmetro e, em seguida, clique em  **Concluir** antes de clicar em  **Add**, o parâmetro não é adicionado ao método.  Você deve encontrar o método e inserir o parâmetro manualmente.  
  
 **Add**  
 Adiciona o parâmetro especificado em  **o nome do parâmetro**e seus atributos de tipo e o parâmetro para  **lista de parâmetros**.  Você deve clicar em  **Add** para adicionar um parâmetro à lista.  
  
 **Remove**  
 Remove o parâmetro que você seleciona na  **lista de parâmetros**  da lista.  
  
 **Lista de parâmetros**  
 Exibe todos os parâmetros e seus modificadores e adicionados no momento para o método de tipos.  Conforme você adiciona parâmetros, o assistente atualiza  **lista de parâmetros** para exibir cada parâmetro, com seu tipo e o modificador.  
  
## Consulte também  
 [Adicionando um método](../ide/adding-a-method-visual-cpp.md)   
 [Atributos IDL, Assistente de Adição de Método](../ide/idl-attributes-add-method-wizard.md)