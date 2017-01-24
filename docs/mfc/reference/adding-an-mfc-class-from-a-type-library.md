---
title: "Adicionando uma classe do MFC de uma biblioteca de tipos | Microsoft Docs"
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
  - "classes [C++], adicionando MFC"
  - "MFC, adicionando classes de bibliotecas de tipo"
  - "bibliotecas de tipo, adicionando classes MFC de"
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma classe do MFC de uma biblioteca de tipos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use este assistente para criar uma classe de MFC de uma interface em uma biblioteca disponível do tipo.  Você pode adicionar uma classe de MFC a [Aplicativo de MFC](../../mfc/reference/creating-an-mfc-application.md), a [DLL FROM MFC](../../mfc/reference/creating-an-mfc-dll-project.md), ou a [Controle ActiveX de MFC](../../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisa criar seu projeto de MFC com a automação habilitada para adicionar uma classe de uma biblioteca de tipos.  
  
 Uma biblioteca de tipos contém uma descrição binária das interfaces expostas por um componente, definindo os métodos junto com seus parâmetros e tipos de retorno.  A biblioteca de tipos deve ser registrada para que apareça na lista de **Available type libraries** na classe adicionar o assistente de Typelib.  Consulte “COM distribuída interior: Digite bibliotecas e integração de CLR” na biblioteca do MSDN para obter mais informações.  
  
### Para adicionar um MFC classe de uma biblioteca de tipos  
  
1.  Em **Gerenciador de Soluções** ou em [Exibição da classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com o botão direito do mouse no nome de projeto para o qual você deseja adicionar a classe.  
  
2.  No menu de atalho, clique **Adicionar**, e clique em **Adicionar Classe**.  
  
3.  Na caixa de diálogo de [Adicione a classe](../../ide/add-class-dialog-box.md) , no painel modelos, clique em **Classe MFC a Partir de TypeLib**, e clique em **Abrir** para exibir [Adicione a classe do assistente de Typelib](../../mfc/reference/add-class-from-typelib-wizard.md).  
  
 No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos.  Também, você pode adicionar classes de mais de uma biblioteca de tipos em uma única sessão do assistente.  
  
 O assistente cria uma classe derivada, MFC de [COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md), porque cada interface que você adicionar a biblioteca selecionada do tipo.  `COleDispatchDriver` implementa o lado do cliente de automação OLE.  
  
## Consulte também  
 [Clientes de automação](../../mfc/automation-clients.md)   
 [Clientes de automação: usando bibliotecas de tipo](../Topic/Automation%20Clients:%20Using%20Type%20Libraries.md)