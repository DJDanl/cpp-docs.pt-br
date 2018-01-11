---
title: "Manipulando o botão Aplicar | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Apply button in property sheet
- property sheets, Apply button
ms.assetid: 7e977015-59b8-406f-b545-aad0bfd8d55b
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d72186d3b3d29613007291396aa07ba4060a726a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handling-the-apply-button"></a>Manipulando o botão Aplicar
Folhas de propriedade tem um recurso que caixas de diálogo padrão não: eles permitem que o usuário aplicar as alterações feitas antes de fechar a folha de propriedades. Isso é feito usando o botão Aplicar. Este artigo descreve métodos que você pode usar para implementar esse recurso corretamente.  
  
 Caixas de diálogo modais geralmente apliquem as configurações para um objeto externo quando o usuário clica Okey para fechar a caixa de diálogo. O mesmo é verdadeiro para uma folha de propriedades: quando o usuário clica Okey, as novas configurações na folha de propriedades entram em vigor.  
  
 No entanto, você talvez queira permitir que o usuário salvar as configurações sem fechar a caixa de diálogo da folha de propriedade. Essa é a função do botão Aplicar. O botão Aplicar aplica as configurações atuais em todas as páginas de propriedade para o objeto externo, em vez de aplicar somente as configurações atuais da página ativa no momento.  
  
 Por padrão, o botão Aplicar sempre fica desabilitado. Você deve escrever código para habilitar o botão Aplicar nos momentos apropriados, e você deve escrever código para implementar o efeito de aplicar, conforme explicado a seguir.  
  
 Se você não desejar oferecer a funcionalidade de aplicar ao usuário, não é necessário remover o botão Aplicar. Você pode deixá-la desabilitada, pois serão comuns entre os aplicativos que usam o suporte de folha de propriedade padrão disponível em versões futuras do Windows.  
  
 Para relatar uma página como sendo modificadas e habilitar o botão Aplicar, chame **CPropertyPage::SetModified (TRUE)**. Se houver páginas do relatório de tabela que está sendo modificado, o botão Aplicar permanecerá habilitado, independentemente se a página ativa no momento foi modificada.  
  
 Você deve chamar [CPropertyPage::SetModified](../mfc/reference/cpropertypage-class.md#setmodified) sempre que o usuário altera as configurações na página. Uma maneira de detectar quando um usuário altera uma configuração na página é implementar manipuladores de notificação de alteração para cada um dos controles na página de propriedades, como **EN_CHANGE** ou **BN_CLICKED**.  
  
 Para implementar o efeito do botão Aplicar, a folha de propriedades deve informar o seu proprietário ou algum outro objeto externo do aplicativo, para aplicar as configurações atuais nas páginas de propriedades. Ao mesmo tempo, a folha de propriedades deve desabilitar o botão Aplicar chamando **CPropertyPage::SetModified (FALSE)** para todas as páginas que são aplicadas as suas modificações para o objeto externo.  
  
 Para obter um exemplo desse processo, consulte o exemplo de MFC geral [PROPDLG](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)

