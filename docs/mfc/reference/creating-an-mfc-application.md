---
title: Criando um aplicativo MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- applications [MFC]
- MFC, creating applications
- MFC applications
ms.assetid: b8b8aa08-9c49-404c-8078-b42079ac18f0
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e23f1a138bfa6d297c33597b81035a11c1d96c03
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-an-mfc-application"></a>Criando um aplicativo MFC
Um aplicativo MFC é um aplicativo executável para Windows que se baseia na biblioteca Microsoft Foundation Class (MFC). A maneira mais fácil de criar um aplicativo MFC é usar o Assistente de aplicativo do MFC.  
  
> [!IMPORTANT]
>  Não há suporte para projetos MFC em edições Express do Visual Studio.  
  
 Arquivos executáveis do MFC geralmente se encontram em cinco tipos: aplicativos padrão do Windows, caixas de diálogo, aplicativos baseados em formulários, aplicativos de estilo do Explorer e aplicativos de estilo de navegador da Web. Para obter mais informações, consulte:  
  
-   [Usando as Classes para escrever aplicativos do Windows](../../mfc/using-the-classes-to-write-applications-for-windows.md)  
  
-   [Criando e exibindo caixas de diálogo](../../mfc/creating-and-displaying-dialog-boxes.md)  
  
-   [Criando um aplicativo MFC com base em formulários](../../mfc/reference/creating-a-forms-based-mfc-application.md)  
  
-   [Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)  
  
-   [Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)  
  
 O Assistente de aplicativo MFC gera as classes apropriadas e os arquivos para qualquer um desses tipos de aplicativos, dependendo das opções que você seleciona no assistente.  
  
### <a name="to-create-an-mfc-application-using-the-mfc-application-wizard"></a>Para criar um aplicativo MFC usando o Assistente de aplicativo MFC  
  
1.  Siga as instruções no tópico da Ajuda [criando um projeto com um Assistente de aplicativo do Visual C++](../../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  No **novo projeto** caixa de diálogo, selecione **aplicativo MFC** no painel de modelos para abrir o assistente.  
  
3.  Definir as configurações do aplicativo usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md).  
  
    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.  
  
4.  Clique em **concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.  
  
 Quando o projeto é criado, você pode exibir os arquivos criados em **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado Leiame. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md).  
  
## <a name="see-also"></a>Consulte também  
 [Preparação de depuração: Aplicativos de Windows do Visual C++](http://msdn.microsoft.com/en-us/a8bc54de-41a3-464d-9a12-db9bdcbc1ad5)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Implantando aplicativos](http://msdn.microsoft.com/en-us/4ff8881d-0daf-47e7-bfe7-774c625031b4)

