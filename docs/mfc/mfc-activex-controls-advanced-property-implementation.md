---
title: 'Controles ActiveX MFC: Implementação da propriedade de Avançado | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
ms.assetid: ec2e6759-5a8e-41d8-a275-99af8ff6f32e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97b6bbcbcf226d343d8b3cb51f110442e133a379
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-activex-controls-advanced-property-implementation"></a>Controles ActiveX MFC: implementação da propriedade avançada
Este artigo descreve os tópicos relacionados à implementação de propriedades em um controle ActiveX avançadas:  
  
-   [Propriedades somente leitura e somente gravação](#_core_read2donly_and_write2donly_properties)  
  
-   [Retornando códigos de erro a partir de uma propriedade](#_core_returning_error_codes_from_a_property)  
  
##  <a name="_core_read2donly_and_write2donly_properties"></a> Propriedades somente leitura e somente gravação  
 O Assistente para adicionar propriedade fornece um método rápido e fácil para implementar propriedades somente leitura ou somente gravação para o controle.  
  
#### <a name="to-implement-a-read-only-or-write-only-property"></a>Para implementar uma propriedade somente leitura ou somente gravação  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **adicionar propriedade**.  
  
     Isso abre o [Assistente para adição de propriedade](../ide/names-add-property-wizard.md).  
  
5.  No **nome da propriedade** , digite o nome de sua propriedade.  
  
6.  Para **o tipo de implementação**, clique em **métodos Get/Set**.  
  
7.  No **tipo de propriedade** , selecione o tipo apropriado para a propriedade.  
  
8.  Se você quiser uma propriedade somente leitura, desmarque o nome da função de conjunto. Se você quiser uma propriedade somente gravação, desmarque o nome da função Get.  
  
9. Clique em **Finalizar**.  
  
 Quando você fizer isso, o Assistente para adicionar propriedade insere a função `SetNotSupported` ou `GetNotSupported` na entrada de mapa de expedição no lugar de um normal definir ou obter a função.  
  
 Se você quiser alterar uma propriedade existente para ser somente leitura ou somente gravação, você pode editar o mapa de expedição manualmente e remova a função de conjunto ou Get desnecessária da classe de controle.  
  
 Se você quiser uma propriedade a ser condicionalmente somente leitura ou somente gravação (por exemplo, somente quando o controle está operando em um modo específico), você pode fornecer a função Set ou Get, como normal e chamar o `SetNotSupported` ou `GetNotSupported` função quando apropriado. Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxUI#29](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-property-implementation_1.cpp)]  
  
 Este exemplo de código chama `SetNotSupported` se o `m_bReadOnlyMode` é membro de dados **TRUE**. Se **FALSE**, em seguida, a propriedade é definida para o novo valor.  
  
##  <a name="_core_returning_error_codes_from_a_property"></a> Retornando códigos de erro a partir de uma propriedade  
 Para indicar que ocorreu um erro ao tentar obter ou definir uma propriedade, use o `COleControl::ThrowError` função, o que leva um `SCODE` (código de status) como um parâmetro. Você pode usar um modelo predefinido `SCODE` ou definir seu próprio. Para obter uma lista de predefinidos `SCODE`s e instruções para definir personalizado `SCODE`s, consulte [tratamento de erros no controle ActiveX do seu](../mfc/mfc-activex-controls-advanced-topics.md) nos controles do ActiveX artigo: tópicos avançados.  
  
 Existem funções auxiliares para os mais comuns predefinidos `SCODE`s, como [COleControl::SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported), [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported), e [COleControl:: SetNotPermitted](../mfc/reference/colecontrol-class.md#setnotpermitted).  
  
> [!NOTE]
>  `ThrowError` deve ser usado apenas como um meio de retornar um erro de dentro Get da propriedade ou Set função ou um método de automação. Esses são os únicos vezes que o manipulador de exceção apropriada será presentes na pilha.  
  
 Para obter mais informações sobre relatórios de exceções em outras áreas do código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [tratamento de erros no controle ActiveX do seu](../mfc/mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: avançado Tópicos.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe COleControl](../mfc/reference/colecontrol-class.md)
