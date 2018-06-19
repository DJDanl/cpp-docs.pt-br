---
title: 'Contêineres: Notificações de Item do cliente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- notifications [MFC], container client item
- OLE containers [MFC], client-item notifications
- client items and OLE containers
ms.assetid: e1f1c427-01f5-45f2-b496-c5bce3d76340
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2255f28c1250096bfbeb1a9365c57f78e17e20d7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344618"
---
# <a name="containers-client-item-notifications"></a>Contêineres: notificações de item do cliente
Este artigo descreve as funções substituíveis que a estrutura MFC chama quando aplicativos de servidor modificar itens no documento do aplicativo cliente.  
  
 [COleClientItem](../mfc/reference/coleclientitem-class.md) define várias funções substituíveis que são chamadas em resposta a solicitações do aplicativo de componente, que também é chamado para o aplicativo do servidor. Sobre esses substituíveis geralmente atuam como as notificações. Eles informam o aplicativo de contêiner de vários eventos, como ativação de rolagem, ou uma alteração da posição e das alterações feitas pelo usuário ao editar ou manipular o item.  
  
 A estrutura notifica o aplicativo de contêiner de alterações por meio de uma chamada para `COleClientItem::OnChange`, uma função substituível cuja implementação é necessária. Esta função protegida recebe dois argumentos. A primeira Especifica o motivo pelo qual que o servidor mudou o item:  
  
|Notificação|Significado|  
|------------------|-------------|  
|`OLE_CHANGED`|Aparência do item OLE foi alterado.|  
|`OLE_SAVED`|O item OLE foi salvo.|  
|`OLE_CLOSED`|O item OLE foi fechado.|  
|**OLE_RENAMED**|O documento de servidor que contém o item OLE foi renomeado.|  
|`OLE_CHANGED_STATE`|O item OLE foi alterado de um estado para outro.|  
|**OLE_CHANGED_ASPECT**|Aspecto de desenho do item OLE foi alterado pela estrutura.|  
  
 Esses valores são a partir de **OLE_NOTIFICATION** enumeração, que é definida em AFXOLE. H.  
  
 O segundo argumento para essa função especifica como o item foi alterado ou o estado que tiver inserido:  
  
|Quando o primeiro argumento é|Segundo argumento|  
|----------------------------|---------------------|  
|`OLE_SAVED` ou `OLE_CLOSED`|Não é usado.|  
|`OLE_CHANGED`|Especifica a proporção do item OLE que foi alterado.|  
|`OLE_CHANGED_STATE`|Descreve o estado que está sendo inserido (`emptyState`, **loadedState**, `openState`, `activeState`, ou `activeUIState`).|  
  
 Para obter mais informações sobre os estados de um item do cliente pode assumir, consulte [contêineres: Estados de Item do cliente](../mfc/containers-client-item-states.md).  
  
 A estrutura chama `COleClientItem::OnGetItemPosition` quando um item está sendo ativado para edição no local. Implementação é necessária para aplicativos que oferecem suporte a edição no local. O Assistente de aplicativo MFC fornece uma implementação básica, o que atribui as coordenadas do item para o `CRect` objeto que é passado como um argumento para `OnGetItemPosition`.  
  
 Se a posição ou o tamanho do item OLE é alterado durante a edição no local, informações do contêiner sobre retângulos de recorte e a posição do item devem ser atualizadas e o servidor deve receber informações sobre as alterações. A estrutura chama `COleClientItem::OnChangeItemPosition` para essa finalidade. O Assistente de aplicativo MFC fornece uma substituição que chama a função da classe base. Você deve editar a função que o Assistente de aplicativo grava para sua `COleClientItem`-classe derivada para que a função atualiza todas as informações mantidas pelo seu objeto de item do cliente.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: Estados de Item do cliente](../mfc/containers-client-item-states.md)   
 [COleClientItem::OnChangeItemPosition](../mfc/reference/coleclientitem-class.md#onchangeitemposition)

