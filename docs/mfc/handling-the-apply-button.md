---
title: "Manipulando o bot&#227;o Aplicar | Microsoft Docs"
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
  - "Botão Aplicar na folha de propriedades"
  - "folhas de propriedade, Botão Aplicar"
ms.assetid: 7e977015-59b8-406f-b545-aad0bfd8d55b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando o bot&#227;o Aplicar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As folhas de propriedades têm um recurso que as caixas de diálogo padrão não faz: Permite que o usuário aplica alterações feitas antes de desligar a folha de propriedades.  Isso é feito usando o botão de aplicação.  Este artigo descreve métodos que você pode usar para implementar corretamente esse recurso.  
  
 As caixas de diálogo modais aplicam geralmente as configurações em um objeto externo quando o usuário clicar em OK para fechar a caixa de diálogo.  O mesmo é válido para uma folha de propriedades: Quando o usuário clicar em OK, as novas configurações na planilha da propriedade entram em vigor.  
  
 No entanto, talvez você queira permitir que o usuário salvar configurações sem ter que fechar a caixa de diálogo de folha de propriedades.  Essa é a função do botão ser aplicado.  O botão aplicar aplica as configurações atuais em todas as páginas de propriedades no objeto externo, ao contrário de aplicar apenas as configurações atuais da página atualmente ativo.  
  
 Por padrão, o botão será desabilitado ser aplicado sempre.  Você deve escrever o código para habilitar o botão ser aplicado nos momentos apropriados, e você deve escrever o código para implementar o efeito Apply, conforme explicado abaixo.  
  
 Se você não desejar oferecer funcionalidade se aplicar ao usuário, não é necessário remover o botão ser aplicado.  Você pode permitir que você desabilitado, como são comuns entre os aplicativos que usam o suporte padrão de folha de propriedade está disponível em versões futuras do windows.  
  
 Para informar uma página como sendo alterado e habilitar o botão aplicados, chame **CPropertyPage::SetModified\( TRUE \)**.  Se qualquer uma das páginas subordinados a alteração, o botão aplicar permanecerá habilitado, independentemente da página atualmente ativo esteve alterada.  
  
 Você deve chamar [CPropertyPage::SetModified](../Topic/CPropertyPage::SetModified.md) sempre que o usuário altere qualquer configuração na página.  Uma maneira de detectar quando um usuário altera uma configuração na página é implementar manipuladores de notificação de alteração para cada um dos controles na página de propriedades, como **EN\_CHANGE** ou **BN\_CLICKED**.  
  
 Para implementar o efeito do botão ser aplicada, a folha de propriedade deve informar o proprietário, ou qualquer outro objeto no aplicativo externo, aplicar as configurações atuais nas páginas de propriedades.  Ao mesmo tempo, a folha de propriedade deve desabilitar o botão aplicar chamando **CPropertyPage::SetModified\( FALSE \)** para todas as páginas que foram suas alterações no objeto externo.  
  
 Para obter um exemplo desse processo, consulte o exemplo [PROPDLG](../top/visual-cpp-samples.md)gerais de MFC.  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)