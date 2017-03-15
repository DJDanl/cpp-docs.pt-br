---
title: "Controles ActiveX MFC: implementa&#231;&#227;o da propriedade avan&#231;ada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX MFC, códigos de erro"
  - "Controles ActiveX MFC, propriedades"
  - "propriedades [MFC], Controles ActiveX"
ms.assetid: ec2e6759-5a8e-41d8-a275-99af8ff6f32e
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: implementa&#231;&#227;o da propriedade avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve os tópicos relacionados ao implementar propriedades avançadas em um controle ActiveX:  
  
-   [Propriedades somente leitura e somente gravação](#_core_read2donly_and_write2donly_properties)  
  
-   [Retornando códigos de erro de uma propriedade](#_core_returning_error_codes_from_a_property)  
  
##  <a name="_core_read2donly_and_write2donly_properties"></a> Propriedades somente leitura e somente gravação  
 O assistente para adicionar a propriedade fornece um método rápido e fácil implementar propriedades somente leitura ou somente gravação para o controle.  
  
#### Para implementar uma propriedade somente leitura ou somente gravação  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
     Isso abre [Assistente de adição de propriedade](../ide/names-add-property-wizard.md).  
  
5.  Na caixa de **Nome da propriedade** , digite o nome da propriedade.  
  
6.  Para **Tipo de Implementação**, clique **Get\/Set Methods**.  
  
7.  Na caixa de **Tipo de propriedade** , selecione o tipo apropriado para a propriedade.  
  
8.  Se você quiser uma propriedade somente leitura, desmarque o nome da função de conjunto.  Se você quiser uma propriedade somente gravação, desmarque o nome da função ser obtido.  
  
9. Clique em **Concluir**.  
  
 Quando você fizer isso, o assistente da propriedade adicionar insere a função `SetNotSupported` ou `GetNotSupported` na entrada do mapa de distribuição no lugar de um conjunto comum ou define a função.  
  
 Se você quiser alterar uma propriedade existente para ser somente leitura ou somente gravação, você pode editar o mapa de expedição manualmente e remover o conjunto desnecessários ou obter a função da classe do controle.  
  
 Se você quiser uma propriedade para ser condicional somente leitura ou somente gravação \(por exemplo, somente quando o controle operar em um modo específico\), você pode fornecer o conjunto ou obter a função, como normal, e chama a função de `SetNotSupported` ou de `GetNotSupported` onde apropriado.  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxUI#29](../mfc/codesnippet/CPP/mfc-activex-controls-advanced-property-implementation_1.cpp)]  
  
 Este exemplo de código a seguir chama `SetNotSupported` se o membro de dados de `m_bReadOnlyMode` é **Verdadeiro**.  Se **Falso**, a propriedade é definida no novo valor.  
  
##  <a name="_core_returning_error_codes_from_a_property"></a> Retornando códigos de erro de uma propriedade  
 Para indicar que ocorreu um erro ao tentar obter ou definir uma propriedade, use a função de `COleControl::ThrowError` , que usa `SCODE` \(código de status\) como um parâmetro.  Você pode usar `SCODE` predefinido ou definir um de seus próprios.  Para obter uma lista de `SCODE`predefinido s as instruções e para definir `SCODE`personalizado s, consulte [Tratar erros no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) nos controles ActiveX de artigo: Tópicos avançados.  
  
 As funções auxiliares existem para a maioria de `SCODE`predefinido comum s, como [COleControl::SetNotSupported](../Topic/COleControl::SetNotSupported.md), [COleControl::GetNotSupported](../Topic/COleControl::GetNotSupported.md), e [COleControl::SetNotPermitted](../Topic/COleControl::SetNotPermitted.md).  
  
> [!NOTE]
>  `ThrowError` parece ser usado apenas como meio de retornar um erro de uma propriedade obtém ou define a função ou um método de automação.  Esses são os únicos hora em que o manipulador de exceção apropriada estiver presente na pilha.  
  
 Para obter mais informações sobre as exceções de relatório em outras áreas de código, consulte [COleControl::FireError](../Topic/COleControl::FireError.md) e a seção [Tratar erros no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) nos controles ActiveX de artigo: Tópicos avançados.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe de COleControl](../mfc/reference/colecontrol-class.md)