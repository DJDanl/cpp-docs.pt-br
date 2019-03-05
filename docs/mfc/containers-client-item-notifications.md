---
title: 'Contêineres: Notificações de Item do cliente'
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], container client item
- OLE containers [MFC], client-item notifications
- client items and OLE containers
ms.assetid: e1f1c427-01f5-45f2-b496-c5bce3d76340
ms.openlocfilehash: 583c438820c002a4c192d15358ca98424d02889a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57291048"
---
# <a name="containers-client-item-notifications"></a>Contêineres: Notificações de Item do cliente

Este artigo discute as funções substituíveis que a estrutura MFC chama quando aplicativos de servidor modificarem itens de documento do aplicativo cliente.

[COleClientItem](../mfc/reference/coleclientitem-class.md) define várias funções substituíveis que são chamadas em resposta às solicitações do aplicativo de componente, que também é chamado para o aplicativo de servidor. Sobre esses substituíveis geralmente agem como notificações. Eles informam o aplicativo de contêiner de vários eventos, como a ativação de rolagem, ou uma alteração de posição e as alterações que o usuário faz ao editar ou manipular o item.

O framework notifica seu aplicativo de contêiner de alterações por meio de uma chamada para `COleClientItem::OnChange`, uma função substituível cuja implementação é necessária. Essa função protegida recebe dois argumentos. A primeira Especifica o motivo pelo qual que o servidor mudou o item:

|Notificação|Significado|
|------------------|-------------|
|**OLE_CHANGED**|Aparência do item OLE foi alterado.|
|**OLE_SAVED**|O item OLE foi salvo.|
|**OLE_CLOSED**|O item OLE foi fechado.|
|**OLE_RENAMED**|O documento do servidor que contém o item OLE foi renomeado.|
|**OLE_CHANGED_STATE**|O item OLE foi alterado de um estado para outro.|
|**OLE_CHANGED_ASPECT**|Aspecto do desenho do item OLE foi alterado pela estrutura.|

Esses valores são a partir de **OLE_NOTIFICATION** enumeração, que é definida em AFXOLE. H.

O segundo argumento para essa função especifica como o item foi alterado ou o que estado que ele entrou em:

|Quando o primeiro argumento é|Segundo argumento|
|----------------------------|---------------------|
|**OLE_SAVED** ou **OLE_CLOSED**|Não é usado.|
|**OLE_CHANGED**|Especifica o aspecto do item OLE que foi alterado.|
|**OLE_CHANGED_STATE**|Descreve o estado que está sendo inserido (*emptyState*, *loadedState*, *openState*, *activeState*, ou  *activeUIState*).|

Para obter mais informações sobre os estados de um item do cliente pode supor, consulte [contêineres: Estados de Item do cliente](../mfc/containers-client-item-states.md).

A estrutura chama `COleClientItem::OnGetItemPosition` quando um item está sendo ativado para edição no local. Implementação é necessária para aplicativos que dão suporte à edição in-loco. O Assistente de aplicativo do MFC fornece uma implementação básica, o que atribui as coordenadas do item para o `CRect` objeto que é passado como um argumento para `OnGetItemPosition`.

Se o tamanho ou a posição do item OLE é alterado durante a edição in-loco, informações do contêiner sobre a posição e a retângulos de recorte o item devem ser atualizadas e o servidor deve receber informações sobre as alterações. A estrutura chama `COleClientItem::OnChangeItemPosition` para essa finalidade. O Assistente de aplicativo do MFC fornece uma substituição que chama a função da classe base. Você deve editar a função que o Assistente de aplicativo grava para sua `COleClientItem`-classe derivada, para que a função atualiza todas as informações mantidas pelo seu objeto de item do cliente.

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Contêineres: Estados de Item do cliente](../mfc/containers-client-item-states.md)<br/>
[COleClientItem::OnChangeItemPosition](../mfc/reference/coleclientitem-class.md#onchangeitemposition)
