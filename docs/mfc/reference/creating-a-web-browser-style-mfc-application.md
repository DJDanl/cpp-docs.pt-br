---
title: "Criando um aplicativo MFC no estilo de navegador da Web | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfcweb.project"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MFC, aplicativos da Web"
  - "aplicativos da Web, criando"
  - "navegadores da Web"
  - "navegadores da Web, criando a partir da arquitetura MFC"
ms.assetid: 257f8c03-33c3-428c-832e-0b70aff6168d
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um aplicativo MFC no estilo de navegador da Web
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um aplicativo do silverlight estilo da Web pode acessar informações da Internet \(como HTML ou documentos ativos\) ou de uma intranet, assim como as pastas no sistema de arquivos local e em uma rede.  Derivando a classe da exibição do aplicativo de [CHtmlView](../../mfc/reference/chtmlview-class.md)efetivamente, você cria o aplicativo em um navegador da Web fornecendo a exibição do controle de navegador da web.  
  
### Para criar um aplicativo de navegador da Web com base no documento MFC\/exibir a arquitetura  
  
1.  Siga as instruções em [Criando um aplicativo de MFC](../../mfc/reference/creating-an-mfc-application.md).  
  
2.  Na página de [Tipo de aplicativo](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) do assistente de aplicativo MFC, verifique se a caixa de **Document\/view architecture** está selecionada. \(Você pode escolher **Single document** ou **Vários documentos**, mas não **Dialog based**.\)  
  
3.  Na página de [Classes de revisão gerados](../../mfc/reference/generated-classes-mfc-application-wizard.md) , use o menu suspenso de **Classe Base** para selecionar `CHtmlView`.  
  
4.  Selecionar todas as outras opções que você deseja criado no aplicativo do esqueleto.  
  
5.  Clique em **Concluir**.  
  
 O controle de navegador da web oferece suporte a Web que procura com os hiperlinks e da navegação \(URL\) do localizador de recurso uniforme.  O controle mantém uma lista de histórico que permite que o usuário navegue por sites, pastas, e documentos anteriormente procurados diretos de avanço rápido e inversas.  O controle controla diretamente a navegação, hiperlinks, as listas do histórico, os favoritos, e segurança.  Os aplicativos podem usar o controle de navegador da web como um contêiner do documento ativo para hospedar também documentos ativas.  Portanto, os documentos rica formatados como planilhas do Microsoft Excel ou documentos de palavras podem ser abertos e editado no lugar dentro do controle de navegador da web.  O controle de navegador da web também é um contêiner do controle ActiveX que pode hospedar qualquer controle ActiveX.  
  
> [!NOTE]
>  O controle ActiveX do navegador da web \(e\) em virtude disso `CHtmlView`estão disponíveis apenas para aplicativos executados sob as versões do windows no qual foram instalados Internet Explorer 4.0 ou posterior.  
  
 Como `CHtmlView` implementa apenas o controle de navegador da Web de O, o suporte para imprimir não é igual a outro [CView](../Topic/CView%20Class.md)\- classes derivadas.  Em vez disso, o controle de navegador da web implementa a interface do usuário e a impressão da impressora.  No resultado, `CHtmlView` não oferece suporte à visualização de impressão, e a estrutura não prevê outras funções de suporte de impressão: por exemplo, [CView::OnPreparePrinting](../Topic/CView::OnPreparePrinting.md), [CView::OnBeginPrinting](../Topic/CView::OnBeginPrinting.md), e [CView::OnEndPrinting](../Topic/CView::OnEndPrinting.md), que estão disponíveis em outros aplicativos de MFC.  
  
 `CHtmlView` atua como um wrapper para o controle de navegador da Web, que da o aplicativo uma exibição na Web ou em uma página HTML.  O assistente cria uma substituição para a função de [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) na classe de exibição de navegação, fornecendo um link para o site do Microsoft Visual C\+\+:  
  
```  
void CWebView::OnInitialUpdate()  
{  
   CHtmlView::OnInitialUpdate();  
  
   // TODO: This code navigates to a popular spot on the web.  
   //  change the code to go where you'd like.  
   Navigate2(_T("http://www.msdn.microsoft.com/vstudio/"),NULL,NULL);  
}  
```  
  
 Você pode substituir esse site com um de seus próprios, ou você pode usar a função de membro de [LoadFromResource](../Topic/CHtmlView::LoadFromResource.md) para abrir uma página HTML que reside no script de recursos do projeto como o conteúdo padrão para a exibição.  Por exemplo:  
  
```  
void CWebView::OnInitialUpdate()  
{  
   CHtmlView::OnInitialUpdate();  
  
   // TODO: This code navigates to a popular spot on the web.  
   //  change the code to go where you'd like.  
   LoadFromResource(IDR_HTML1);  
}  
```  
  
## Consulte também  
 [MFC Sample MFCIE](http://msdn.microsoft.com/pt-br/7391aa0c-fca8-4994-a6c9-6c5c7470fba0)   
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)   
 [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md)   
 [Páginas de propriedade](../../ide/property-pages-visual-cpp.md)   
 [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md)   
 [Deploying Applications](http://msdn.microsoft.com/pt-br/4ff8881d-0daf-47e7-bfe7-774c625031b4)