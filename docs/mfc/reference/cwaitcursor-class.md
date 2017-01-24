---
title: "Classe de CWaitCursor | Microsoft Docs"
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
  - "CWaitCursor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cursores, cursor de espera"
  - "Classe de CWaitCursor"
  - "cursores de espera"
ms.assetid: 5dfae2ff-d7b6-4383-b0ad-91e0868c67b3
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWaitCursor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma maneira da linha mostrar um cursor de espera, que geralmente é exibido como uma ampulheta, quando você faz uma operação longa.  
  
## Sintaxe  
  
```  
class CWaitCursor  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWaitCursor::CWaitCursor](../Topic/CWaitCursor::CWaitCursor.md)|Constrói um objeto de `CWaitCursor` e exibe o cursor de espera.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWaitCursor::Restore](../Topic/CWaitCursor::Restore.md)|Restaura o cursor de espera depois que foi alterado.|  
  
## Comentários  
 `CWaitCursor` não tem uma classe base.  
  
 As boas práticas de programação windows requerem que você exibe um cursor de espera sempre que você está executando uma operação que leva uma quantidade considerável de tempo.  
  
 Para exibir um cursor de espera, define apenas uma variável de `CWaitCursor` antes do código que executa a operação longa.  O construtor do objeto faz automaticamente o cursor de espera a ser exibido.  
  
 Quando o objeto sair do escopo \(no final do bloco no qual o objeto de `CWaitCursor` está declarado\), o destrutor define o cursor para o cursor anterior.  Ou seja o objeto realiza a limpeza necessário automaticamente.  
  
> [!NOTE]
>  Devido a como os construtores e destructors funcionam, os objetos de `CWaitCursor` sempre são declarados como variáveis locais — nunca são declarados como variáveis globais não são atribuiu com **new**.  
  
 Se você executar uma operação que pode causar o cursor seja alterado, como exibir uma caixa de mensagem ou caixa de diálogo, chame a função de membro de [Restaurar](../Topic/CWaitCursor::Restore.md) para restaurar o cursor de espera.  É certo chamar **Restaurar** mesmo quando o cursor de espera é exibido no momento.  
  
 Outra maneira de exibir um cursor de espera é usar a combinação de [CCmdTarget::BeginWaitCursor](../Topic/CCmdTarget::BeginWaitCursor.md), de [CCmdTarget::EndWaitCursor](../Topic/CCmdTarget::EndWaitCursor.md), e talvez de [CCmdTarget::RestoreWaitCursor](../Topic/CCmdTarget::RestoreWaitCursor.md).  Em o entanto, `CWaitCursor` é mais fácil de usar porque você não precisa definir o cursor para o cursor anterior quando você concluiu a operação longa.  
  
> [!NOTE]
>  O MFC define e restaura o cursor usando a função virtual de [CWinApp::DoWaitCursor](../Topic/CWinApp::DoWaitCursor.md) .  Você pode substituir essa função para fornecer um comportamento personalizado.  
  
## Hierarquia de herança  
 `CWaitCursor`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Exemplo  
 [!code-cpp[NVC_MFCWindowing#62](../../mfc/reference/codesnippet/CPP/cwaitcursor-class_1.cpp)]  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CCmdTarget::BeginWaitCursor](../Topic/CCmdTarget::BeginWaitCursor.md)   
 [CCmdTarget::EndWaitCursor](../Topic/CCmdTarget::EndWaitCursor.md)   
 [CCmdTarget::RestoreWaitCursor](../Topic/CCmdTarget::RestoreWaitCursor.md)   
 [CWinApp::DoWaitCursor](../Topic/CWinApp::DoWaitCursor.md)   
 [Como: eu faço Altere o cursor do mouse em um aplicativo da classe da Microsoft foundation?](http://go.microsoft.com/fwlink/?LinkID=128044)