---
title: MAPI
ms.date: 11/04/2016
helpviewer_keywords:
- messaging [MFC], client applications
- enabling applications for MAPI [MFC]
- MAPI support in MFC
- e-mail [MFC], enabling
- mail [MFC], enabling your application
- MAPI, MFC
- enabling applications for mail [MFC]
ms.assetid: 193449f7-b131-4ab0-9301-8d4f6cd1e7c4
ms.openlocfilehash: 0008a2bc433401f3e048b6f5a92cded88114d08e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625561"
---
# <a name="mapi"></a>MAPI

Este artigo descreve o Microsoft Messaging Application Programming Interface (MAPI) para desenvolvedores de aplicativos de mensagens do cliente. O MFC fornece suporte para um subconjunto de MAPI na classe `CDocument` , mas não encapsula toda a API. Para obter mais informações, consulte [suporte MAPI no MFC](mapi-support-in-mfc.md).

MAPI é um conjunto de funções que os aplicativos habilitados para email e com reconhecimento de email usam para criar, manipular, transferir e armazenar mensagens de email. Ele fornece aos desenvolvedores de aplicativos as ferramentas para definir a finalidade e o conteúdo de mensagens de email e oferece flexibilidade no gerenciamento de mensagens de email armazenadas. O MAPI também fornece uma interface comum que os desenvolvedores de aplicativos podem usar para criar aplicativos habilitados para email e com reconhecimento de email, independentemente do sistema de mensagens subjacente.

Os clientes de mensagens fornecem uma interface humana para interação com o Microsoft Windows Messaging System (WMS). Essa interação normalmente inclui serviços de solicitação de provedores compatíveis com MAPI, como armazenamentos de mensagens e catálogos de endereços.

Para obter mais informações sobre MAPI, consulte os artigos em guia em mensagens do Win32 (MAPI) do SDK do Windows.

## <a name="in-this-section"></a>Nesta seção

[Suporte MAPI no MFC](mapi-support-in-mfc.md)

## <a name="see-also"></a>Consulte também

[CDocument:: OnFileSendMail](reference/cdocument-class.md#onfilesendmail)<br/>
[CDocument:: OnUpdateFileSendMail](reference/cdocument-class.md#onupdatefilesendmail)<br/>
[COleDocument::OnFileSendMail](reference/coledocument-class.md#onfilesendmail)
