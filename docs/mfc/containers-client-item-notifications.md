---
title: "Cont&#234;ineres: notifica&#231;&#245;es de item do cliente | Microsoft Docs"
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
  - "itens de cliente e contêineres OLE"
  - "notificações, item cliente de contêiner"
  - "Contêineres OLE, notificações de item cliente"
ms.assetid: e1f1c427-01f5-45f2-b496-c5bce3d76340
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: notifica&#231;&#245;es de item do cliente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve as funções substituível que a estrutura de MFC chama quando os aplicativos de servidor são itens no documento do aplicativo cliente.  
  
 [COleClientItem](../mfc/reference/coleclientitem-class.md) define várias funções substituível que são chamadas em resposta a solicitações de aplicativo componente, que também é chamado do aplicativo de servidor.  Esses overridables geralmente atuam como notificações.  Informam o aplicativo de contêineres de vários eventos, como rolagem, a ativação, ou alteração de posição, e as alterações que o usuário faz ao editar ou não para manipular o item.  
  
 A estrutura notifica o aplicativo de contêiner das alterações com uma chamada a `COleClientItem::OnChange`, uma função substituível cuja implementação é necessária.  Esta função protegida recebe dois argumentos.  O primeiro especifica o motivo pelo qual o servidor modificou o item:  
  
|Notificação|Significado|  
|-----------------|-----------------|  
|`OLE_CHANGED`|A aparência OLE do item foi alterada.|  
|`OLE_SAVED`|O item OLE foi salvo.|  
|`OLE_CLOSED`|O item OLE foi fechado.|  
|**OLE\_RENAMED**|O documento do servidor que contém o item OLE foi renomeado.|  
|`OLE_CHANGED_STATE`|O item OLE foi alterada de um estado para outro.|  
|**OLE\_CHANGED\_ASPECT**|O aspecto OLE de descompasso de item foi alterado pela estrutura.|  
  
 Estes são valores de enumeração de **OLE\_NOTIFICATION** , que é definida em AFXOLE.H.  
  
 O segundo argumento para a função especifica como o item foi alterado ou estado que fez logon:  
  
|Quando o primeiro argumento for|Segundo argumento|  
|-------------------------------------|-----------------------|  
|`OLE_SAVED` ou `OLE_CLOSED`|Não é usado.|  
|`OLE_CHANGED`|Especifica o aspecto de item OLE que foi alterado.|  
|`OLE_CHANGED_STATE`|Descreve o estado que está sendo registrado \(`emptyState`, **loadedState**, `openState`, `activeState`, ou `activeUIState`\).|  
  
 Para obter mais informações sobre os estados que um item do cliente pode assumir, consulte [Contêiner: Estados de cliente item](../mfc/containers-client-item-states.md).  
  
 A estrutura chama `COleClientItem::OnGetItemPosition` quando um item está sendo alternado para o edição no local.  A implementação é necessária para os aplicativos que dão suporte ao editar no local.  O assistente de aplicativo MFC fornece uma implementação básica, que atribui as coordenadas do item ao objeto de `CRect` que é passado como um argumento a `OnGetItemPosition`.  
  
 Se a posição OLE ou o tamanho de um item são alteradas durante o editar no local, as informações do contêiner sobre os retângulos da posição e o recuo do item deve ser atualizada e o servidor deve receber informações sobre as alterações.  A estrutura chama `COleClientItem::OnChangeItemPosition` para essa finalidade.  O assistente de aplicativo MFC fornece uma substituição que chama a função da classe base.  Você deve editar a função que o assistente de aplicativo para escrever seu `COleClientItem`\- classe derivada de forma que a função atualiza todas as informações mantidas pelo objeto de cliente item.  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: estados de item do cliente](../mfc/containers-client-item-states.md)   
 [COleClientItem::OnChangeItemPosition](../Topic/COleClientItem::OnChangeItemPosition.md)