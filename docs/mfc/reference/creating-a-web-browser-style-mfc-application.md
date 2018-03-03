---
title: Criando um aplicativo MFC no estilo de navegador da Web | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfcweb.project
dev_langs:
- C++
helpviewer_keywords:
- MFC, Web applications
- Web browsers, creating from MFC architecture
- Web browsers
- Web applications [MFC], creating
ms.assetid: 257f8c03-33c3-428c-832e-0b70aff6168d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b7b886f2f1eeed327c2f07f1776777771a5d6ad6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-web-browser-style-mfc-application"></a>Criando um aplicativo MFC no estilo de navegador da Web
Um aplicativo de estilo de navegador da Web pode acessar informações da Internet (como HTML ou documentos ativos) ou uma intranet, como também pastas no sistema de arquivos local e em uma rede. Derivando a classe de exibição do aplicativo de [CHtmlView](../../mfc/reference/chtmlview-class.md), tornar o aplicativo um navegador da Web, fornecendo a exibição com o controle WebBrowser.  
  
### <a name="to-create-a-web-browser-application-based-on-the-mfc-documentview-architecture"></a>Para criar um aplicativo de navegador da Web com base na arquitetura de documento/exibição MFC  
  
1.  Siga as instruções na [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, verifique se o **arquitetura de documento/exibição** está selecionada. (Você pode escolher a **único documento** ou **vários documentos**, mas não **caixa de diálogo com base em**.)  
  
3.  Sobre o [Classes geradas de revisão](../../mfc/reference/generated-classes-mfc-application-wizard.md) página, use o **classe Base** menu suspenso para selecionar `CHtmlView`.  
  
4.  Selecione as outras opções desejadas incorporadas ao aplicativo de esqueleto.  
  
5.  Clique em **Finalizar**.  
  
 O controle WebBrowser dá suporte à navegação na Web por meio de hiperlinks e navegação de URL Uniform Resource Locator (). O controle mantém uma lista de histórico que permite que o usuário navegar para a frente e para trás ao longo anteriormente navegado sites, pastas e documentos. O controle diretamente manipula a navegação, hiperlinks, listas de histórico, Favoritos e segurança. Aplicativos podem usar o controle WebBrowser como um contêiner de documento ativo para documentos ativos host também. Portanto, os documentos com formatação, como planilhas do Microsoft Excel ou documentos do Word podem ser abertos e editados diretamente de dentro do controle WebBrowser. O controle WebBrowser também é um contêiner de controle ActiveX que pode hospedar qualquer controle ActiveX.  
  
> [!NOTE]
>  O controle WebBrowser ActiveX (e, portanto, `CHtmlView`) está disponível somente para aplicativos que executam versões do Windows no qual o Internet Explorer 4.0 ou posterior foi instalado.  
  
 Porque `CHtmlView` simplesmente implementa o controle de navegador da Web Microsoft, o suporte para impressão não é semelhante a outros [CView](../../mfc/reference/cview-class.md)-classes derivadas. Em vez disso, o controle WebBrowser implementa a interface de usuário de impressora e impressão. Como resultado, `CHtmlView` does não dá suporte a visualização de impressão, e não fornece a estrutura para outras funções de suporte de impressão: por exemplo, [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting), [CView::OnBeginPrinting](../../mfc/reference/cview-class.md#onbeginprinting), e [CView::OnEndPrinting](../../mfc/reference/cview-class.md#onendprinting), que estão disponíveis em outros aplicativos MFC.  
  
 `CHtmlView`atua como um wrapper para o controle de navegador da Web, que fornece uma exibição em uma Web ou uma página HTML de seu aplicativo. O assistente cria uma substituição para o [OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) função na classe de exibição, fornecendo um link de navegação para o site do Microsoft Visual C++:  
  
```  
void CWebView::OnInitialUpdate()  
{  
    CHtmlView::OnInitialUpdate();

 *// TODO: This code navigates to a popular spot on the web. *//  change the code to go where you'd like.  
    Navigate2(_T("http://www.msdn.microsoft.com/vstudio/"),
    NULL,
    NULL);

} 
```  
  
 Você pode substituir este site com seu próprio, ou você pode usar o [LoadFromResource](../../mfc/reference/chtmlview-class.md#loadfromresource) a função de membro para abrir uma página HTML que reside no script de recurso do projeto, como o conteúdo padrão para o modo de exibição. Por exemplo:  
  
```  
void CWebView::OnInitialUpdate()  
{  
    CHtmlView::OnInitialUpdate();

 *// TODO: This code navigates to a popular spot on the web. *//  change the code to go where you'd like.  
    LoadFromResource(IDR_HTML1);

} 
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](http://msdn.microsoft.com/en-us/7391aa0c-fca8-4994-a6c9-6c5c7470fba0)   
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)   
 [Trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md)   
 [Implantando aplicativos](http://msdn.microsoft.com/en-us/4ff8881d-0daf-47e7-bfe7-774c625031b4)

