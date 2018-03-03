---
title: "Criando uma caixa de diálogo que os usuários não possam sair | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes, creating
- modal dialog boxes, logon screens
- logon screens
ms.assetid: 54823c27-1658-4388-bd12-0a1ce8f3899e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1b53c233c13ed53f4cf2ccf489da9af90ae15796
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-dialog-box-that-users-cannot-exit"></a>Criando uma caixa de diálogo da qual usuários não possam sair
Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de documento ou aplicativo.  
  
### <a name="to-create-a-dialog-box-that-a-user-cannot-exit"></a>Para criar uma caixa de diálogo que um usuário não pode sair  
  
1.  No **propriedades** painel para a caixa de diálogo, defina o **Menu do sistema** propriedade **false**.  
  
     Isso desabilita o menu de sistema de caixa de diálogo e **fechar** botão.  
  
2.  No formulário de caixa de diálogo, exclua o **Cancelar** e **Okey** botões.  
  
     Em tempo de execução, um usuário não pode sair da caixa de diálogo modal que tem as seguintes características.  
  
 Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo de teste detecta quando ESC está pressionado. (ESC é também conhecido como a chave virtual VK_ESCAPE.) Independentemente de como a caixa de diálogo é projetada para se comportar em tempo de execução, você pode encerrá-lo no modo de teste pressionando ESC.  
  
> [!NOTE]
>  Para aplicativos MFC, para criar uma caixa de diálogo que os usuários não possam sair, você deve substituir o comportamento padrão de `OnOK` e `OnCancel` porque, mesmo que você exclua os botões associados, a caixa de diálogo ainda pode ser descartada, pressionando ENTER ou ESC.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: criar um recurso](../windows/how-to-create-a-resource.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editor de caixa de diálogo](../windows/dialog-editor.md)

