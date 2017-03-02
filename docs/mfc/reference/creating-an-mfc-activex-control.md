---
title: Criando um controle ActiveX MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.activex.project
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [C++], creating
- ActiveX controls [C++], creating
ms.assetid: 8bd5a93c-d04d-414e-bb28-163fdc1c0dd5
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: dc15fa22daba1c0946c125068da0c0c206c39333
ms.lasthandoff: 02/25/2017

---
# <a name="creating-an-mfc-activex-control"></a>Criando um controle ActiveX MFC
Programas de controle ActiveX são programas modulares projetados para dar a um tipo específico de funcionalidade a um aplicativo pai. Por exemplo, você pode criar um controle como um botão para uso em uma caixa de diálogo ou barra de ferramentas para uso em uma página da Web.  
  
 A maneira mais fácil de criar um controle ActiveX MFC é usar o [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md).  
  
### <a name="to-create-an-mfc-activex-control-using-the-mfc-activex-control-wizard"></a>Para criar um controle ActiveX do MFC usando o Assistente de controle ActiveX MFC  
  
1.  Siga as instruções no tópico da Ajuda [criando um projeto com um Assistente de aplicativo do Visual C++](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  No **novo projeto** caixa de diálogo, selecione o **controle ActiveX MFC** ícone no painel de modelos para abrir o Assistente de controle ActiveX MFC.  
  
3.  Definir o [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md), [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md), e [controlar configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) usando o Assistente de controle ActiveX MFC.  
  
    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.  
  
4.  Clique em **concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.  
  
 Depois de criar seu projeto, você pode exibir os arquivos criados em **Solution Explorer**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado Readme. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
 Depois de criar seu projeto, você pode usar os assistentes de código para adicionar [funções](../../ide/add-member-function-wizard.md), [variáveis de](../../ide/add-member-variable-wizard.md), [eventos](../../ide/add-event-wizard.md), [propriedades](../../ide/names-add-property-wizard.md), e [métodos](../../ide/add-method-wizard.md). Para obter mais informações sobre como personalizar o controle ActiveX, consulte [controles ActiveX MFC](../../mfc/mfc-activex-controls.md).  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Implantando aplicativos](http://msdn.microsoft.com/en-us/4ff8881d-0daf-47e7-bfe7-774c625031b4)


