---
title: "Criando uma caixa de di&#225;logo da qual usu&#225;rios n&#227;o possam sair | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "caixas de diálogo, criando"
  - "caixas de diálogo modal, telas de logon"
  - "telas de logon"
ms.assetid: 54823c27-1658-4388-bd12-0a1ce8f3899e
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando uma caixa de di&#225;logo da qual usu&#225;rios n&#227;o possam sair
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de documento ou aplicativo.  
  
### Para criar uma caixa de diálogo que um usuário não pode sair  
  
1.  No **propriedades** painel para a caixa de diálogo, defina o **Menu sistema** propriedade **false**.  
  
     Isso desabilita o menu de sistema de caixa de diálogo e **Fechar** botão.  
  
2.  No formulário de caixa de diálogo, exclua o **Cancelar** e **OK** botões.  
  
     Em tempo de execução, um usuário não pode sair da caixa de diálogo modal que possui as seguintes características.  
  
 Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo de teste detecta quando ESC é pressionada. \(ESC é também conhecido como a chave virtual VK\_ESCAPE.\) Não importa como a caixa de diálogo é projetada para se comportar em tempo de execução, você pode encerrá\-lo no modo de teste pressionando ESC.  
  
> [!NOTE]
>  Para aplicativos do MFC para criar uma caixa de diálogo que os usuários não podem sair, você deve substituir o comportamento padrão de `OnOK`e `OnCancel` porque, mesmo que você exclua os botões associados, a caixa de diálogo ainda pode ser descartada, pressionando ENTER ou ESC.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos de área de trabalho](../Topic/Resources%20in%20Desktop%20Apps.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Como criar um recurso](../windows/how-to-create-a-resource.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editor de Caixa de Diálogo](../mfc/dialog-editor.md)