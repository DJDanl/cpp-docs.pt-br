---
title: 'Contêineres: notificações de item do cliente'
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], container client item
- OLE containers [MFC], client-item notifications
- client items and OLE containers
ms.assetid: e1f1c427-01f5-45f2-b496-c5bce3d76340
ms.openlocfilehash: 54b1b2a64685b00fb265e0f80c1f6ad878a7da85
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623012"
---
# <a name="containers-client-item-notifications"></a>Contêineres: notificações de item do cliente

Este artigo discute as funções substituíveis que a estrutura MFC chama quando aplicativos de servidor modificam itens no documento do seu aplicativo cliente.

[COleClientItem](reference/coleclientitem-class.md) define várias funções substituíveis que são chamadas em resposta a solicitações do aplicativo de componente, que também é chamado de aplicativo de servidor. Esses substituíveis geralmente agem como notificações. Eles informam o aplicativo de contêiner de vários eventos, como rolagem, ativação ou uma alteração de posição, e alterações que o usuário faz ao editar ou, de outra forma, manipular o item.

A estrutura notifica seu aplicativo de contêiner sobre as alterações por meio de uma chamada para `COleClientItem::OnChange` , uma função substituível cuja implementação é necessária. Essa função protegida recebe dois argumentos. A primeira especifica o motivo pelo qual o servidor alterou o item:

|Notificação|Significado|
|------------------|-------------|
|**OLE_CHANGED**|A aparência do item OLE foi alterada.|
|**OLE_SAVED**|O item OLE foi salvo.|
|**OLE_CLOSED**|O item OLE foi fechado.|
|**OLE_RENAMED**|O documento do servidor que contém o item OLE foi renomeado.|
|**OLE_CHANGED_STATE**|O item OLE foi alterado de um estado para outro.|
|**OLE_CHANGED_ASPECT**|O aspecto de desenho do item OLE foi alterado pela estrutura.|

Esses valores são da enumeração **OLE_NOTIFICATION** , que é definida em Afxole. T.

O segundo argumento para essa função especifica como o item foi alterado ou qual estado foi inserido:

|Quando o primeiro argumento é|Segundo argumento|
|----------------------------|---------------------|
|**OLE_SAVED** ou **OLE_CLOSED**|Não é usado.|
|**OLE_CHANGED**|Especifica o aspecto do item OLE que foi alterado.|
|**OLE_CHANGED_STATE**|Descreve o estado que está sendo inserido (*emptyState*, *LoadedFile*, *OpenState*, *ActiveState*ou *activeUIState*).|

Para obter mais informações sobre os Estados que um item de cliente pode assumir, consulte [contêineres: Estados de item de cliente](containers-client-item-states.md).

A estrutura chama `COleClientItem::OnGetItemPosition` quando um item está sendo ativado para edição in-loco. A implementação é necessária para aplicativos que dão suporte à edição in-loco. O assistente de aplicativo do MFC fornece uma implementação básica, que atribui as coordenadas do item ao `CRect` objeto que é passado como um argumento para `OnGetItemPosition` .

Se a posição ou o tamanho de um item OLE for alterado durante a edição in-loco, as informações do contêiner sobre a posição do item e os retângulos de recorte deverão ser atualizados e o servidor deverá receber informações sobre as alterações. A estrutura chama `COleClientItem::OnChangeItemPosition` essa finalidade. O assistente de aplicativo do MFC fornece uma substituição que chama a função da classe base. Você deve editar a função que o assistente de aplicativo grava para sua `COleClientItem` classe derivada, de forma que a função atualize todas as informações mantidas pelo seu objeto de item de cliente.

## <a name="see-also"></a>Consulte também

[Contêineres](containers.md)<br/>
[Contêineres: estados de item do cliente](containers-client-item-states.md)<br/>
[COleClientItem:: OnChangeItemPosition](reference/coleclientitem-class.md#onchangeitemposition)
