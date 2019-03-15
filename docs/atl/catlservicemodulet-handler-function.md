---
title: 'Função catlservicemodulet:: Handler'
ms.date: 11/04/2016
helpviewer_keywords:
- Handler method
ms.assetid: 14db5f2a-be87-4774-a296-445cb6fc7b2e
ms.openlocfilehash: fffdeddce7f3fa27d798ea7abafe85c9a13d9d97
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57815535"
---
# <a name="catlservicemodulethandler-function"></a>Função catlservicemodulet:: Handler

`CAtlServiceModuleT::Handler` é a rotina que o Gerenciador de controle de serviços (SCM) chama para recuperar o status do serviço e dê a ele várias instruções (por exemplo, parar ou pausar). O SCM passa um código de operação para `Handler` para indicar o que o serviço deve fazer. Um serviço do padrão gerado pelo ATL só lida com a instrução stop. Se o SCM passa a instrução stop, o serviço informa ao SCM que o programa está prestes a parar. Em seguida, chama o serviço `PostThreadMessage` para postar uma mensagem para si mesmo. Isso encerra o loop de mensagem e, por fim, o serviço fechará.

Para lidar com mais instruções, você precisará alterar o `m_status` membro de dados inicializado no `CAtlServiceModuleT` construtor. Este membro de dados informa o SCM quais botões devem habilitar quando o serviço é selecionado no aplicativo de painel de controle de serviços.

## <a name="see-also"></a>Consulte também

[Serviços](../atl/atl-services.md)<br/>
[CAtlServiceModuleT::Handler](../atl/reference/catlservicemodulet-class.md#handler)
