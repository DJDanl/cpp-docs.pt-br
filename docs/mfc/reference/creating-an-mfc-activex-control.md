---
title: Criando um controle ActiveX do MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.activex.project
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], creating
- ActiveX controls [MFC], creating
ms.assetid: 8bd5a93c-d04d-414e-bb28-163fdc1c0dd5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c29aef2fcee829924021f9352145714a83698d38
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39026771"
---
# <a name="creating-an-mfc-activex-control"></a>Criando um controle ActiveX MFC
Programas de controle ActiveX são programas modulares projetados para dar a um tipo específico de funcionalidade a um aplicativo pai. Por exemplo, você pode criar um controle como um botão para uso em uma caixa de diálogo ou barra de ferramentas para uso em uma página da Web.  
  
 A maneira mais fácil de criar um controle ActiveX do MFC é usar o [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md).  
  
### <a name="to-create-an-mfc-activex-control-using-the-mfc-activex-control-wizard"></a>Para criar um controle ActiveX do MFC usando o Assistente de controle ActiveX MFC  
  
1.  Siga as instruções do tópico da Ajuda [Criando um projeto com um assistente de aplicativo do Visual C++](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  No **novo projeto** caixa de diálogo, selecione o **controle ActiveX do MFC** ícone no painel de modelos para abrir o Assistente de controle de ActiveX do MFC.  
  
3.  Definir sua [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md), [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md), e [controlar as configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) usando o Assistente de controle de ActiveX do MFC.  
  
    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.  
  
4.  Clique em **concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.  
  
 Depois de ter criado seu projeto, você pode exibir os arquivos criados na **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto Readme. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
 Depois de ter criado seu projeto, você pode usar os assistentes de código para adicionar [funções](../../ide/add-member-function-wizard.md), [variáveis](../../ide/add-member-variable-wizard.md), [eventos](../../ide/add-event-wizard.md), [propriedades](../../ide/names-add-property-wizard.md), e [métodos](../../ide/add-method-wizard.md). Para obter mais informações sobre como personalizar o seu controle ActiveX, consulte [controles ActiveX do MFC](../../mfc/mfc-activex-controls.md).  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedades](../../ide/property-pages-visual-cpp.md)   
 [Implantando aplicativos](http://msdn.microsoft.com/4ff8881d-0daf-47e7-bfe7-774c625031b4)

