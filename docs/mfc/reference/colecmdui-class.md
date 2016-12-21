---
title: "Classe de COleCmdUI | Microsoft Docs"
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
  - "COleCmdUI"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Documentos ActiveX [C++], o servidor de documento"
  - "Classe de COleCmdUI"
  - "o servidor de docobject"
  - "servidor de objeto de documento"
  - "servidores [C++], Documentos ActiveX"
  - "servidores [C++], objetos de doc"
ms.assetid: a2d5ce08-6657-45d3-8673-2a9f32d50eec
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleCmdUI
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um método para o MFC atualiza o estado dos objetos de interface do usuário relacionados a `IOleCommandTarget`\- recursos e do seu aplicativo.  
  
## Sintaxe  
  
```  
class COleCmdUI : public CCmdUI  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleCmdUI::COleCmdUI](../Topic/COleCmdUI::COleCmdUI.md)|Constrói um objeto de `COleCmdUI` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleCmdUI::Enable](../Topic/COleCmdUI::Enable.md)|Define ou limpa o sinalizador de comando para ativar.|  
|[COleCmdUI::SetCheck](../Topic/COleCmdUI::SetCheck.md)|Define o estado de um comando toggle de ou.|  
|[COleCmdUI::SetText](../Topic/COleCmdUI::SetText.md)|Retorna uma cadeia de caracteres de nome ou o status de texto para um comando.|  
  
## Comentários  
 Em um aplicativo que não esteja ativado para DocObjects, quando o usuário visualiza um menu no aplicativo MFC, processarem notifcations de **UPDATE\_COMMAND\_UI** .  Cada notificação recebe um objeto de [CCmdUI](../Topic/CCmdUI%20Class.md) que pode ser manipulado para refletir o estado de um comando específico.  Em o entanto, quando seu aplicativo é habilitado para DocObjects, as notificações de **UPDATE\_OLE\_COMMAND\_UI** dos processos MFC e usa objetos de `COleCmdUI` .  
  
 `COleCmdUI` permite um DocObject receberá os comandos que são originados na interface do usuário de seu recipiente \(como FileNew, abra, imprimir, e assim por diante\), e permite que um contêiner receberá os comandos que são originados na interface do usuário de DocObject.  Embora `IDispatch` pode ser usado para distribuir os mesmos comandos, `IOleCommandTarget` fornece uma maneira mais simples para consulte e executar como se baseia em um conjunto padrão de comandos geralmente, sem argumentos, e em nenhuma informação de tipo estiver envolvido.  `COleCmdUI` pode ser usado para habilitar, atualizar, e definir outras propriedades de comandos de interface do usuário de DocObject.  Quando você deseja invocar o comando, chame [COleServerDoc::OnExecOleCmd](../Topic/COleServerDoc::OnExecOleCmd.md).  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md).  Consulte também [Primeiras etapas da Internet: documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md) e [documentos ativos](../Topic/Active%20Documents%20on%20the%20Internet.md).  
  
## Hierarquia de herança  
 [CCmdUI](../Topic/CCmdUI%20Class.md)  
  
 `COleCmdUI`  
  
## Requisitos  
 **Cabeçalho:** afxdocobj.h  
  
## Consulte também  
 [Classe de CCmdUI](../Topic/CCmdUI%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)