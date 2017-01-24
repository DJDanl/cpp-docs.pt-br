---
title: "Classe de CMultiPageDHtmlDialog | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMultiPageDHtmlDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMultiPageDHtmlDialog"
ms.assetid: 971accc1-824d-4df4-b4c1-b1a20e0f7e4f
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMultiPageDHtmlDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma caixa de diálogo com várias páginas exibe várias páginas HTML seqüencialmente e trata os eventos de cada página.  
  
## Sintaxe  
  
```  
class CMultiPageDHtmlDialog : public CDHtmlDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMultiPageDHtmlDialog::CMultiPageDHtmlDialog](../Topic/CMultiPageDHtmlDialog::CMultiPageDHtmlDialog.md)|Constrói uma um objeto com várias páginas \(estilo assistente\) da caixa de diálogo DHTML.|  
|[CMultiPageDHtmlDialog::~CMultiPageDHtmlDialog](../Topic/CMultiPageDHtmlDialog::~CMultiPageDHtmlDialog.md)|For um objeto com várias páginas da caixa de diálogo DHTML.|  
  
## Comentários  
 O mecanismo para fazer isso é [Mapeamento de evento de DHTML e URL](http://msdn.microsoft.com/pt-br/2a7332f0-79d7-46e4-b816-0a618c46777a), que contém [mapas do evento inseridos](../Topic/BEGIN_EMBED_DHTML_EVENT_MAP.md) para cada página.  
  
## Exemplo  
 Esta caixa de diálogo com várias páginas pressupõe três recursos HTML simples que definem como uma funcionalidade.  A primeira página tem um botão de `Next` , o segundo um botão de **Ant** e de `Next` , e o terceiro um botão de **Ant** .  Quando um dos botões for pressionado, chamadas de função [CDHtmlDialog::LoadFromResource](../Topic/CDHtmlDialog::LoadFromResource.md) de um manipulador para carregar a nova página apropriado.  
  
 As partes pertinentes a declaração de classe \(em CMyMultiPageDlg.h\):  
  
 [!code-cpp[NVC_MFCDocView#181](../../mfc/codesnippet/CPP/cmultipagedhtmldialog-class_1.h)]  
  
 As partes pertinentes a implementação da classe \(em CMyMultipageDlg.cpp\):  
  
 [!code-cpp[NVC_MFCDocView#182](../../mfc/codesnippet/CPP/cmultipagedhtmldialog-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDHtmlSinkHandlerBase2`  
  
 `CDHtmlSinkHandlerBase1`  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `CDHtmlSinkHandler`  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CDHtmlEventSink`  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDHtmlDialog](../Topic/CDHtmlDialog%20Class.md)  
  
 `CMultiPageDHtmlDialog`  
  
## Requisitos  
 **Cabeçalho:** afxdhtml.h  
  
## Consulte também  
 [Classe de CDHtmlDialog](../Topic/CDHtmlDialog%20Class.md)   
 [Multipage DHTML and URL Event Maps \(NIB\)](http://msdn.microsoft.com/pt-br/2a7332f0-79d7-46e4-b816-0a618c46777a)