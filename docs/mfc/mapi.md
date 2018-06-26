---
title: MAPI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messaging [MFC], client applications
- enabling applications for MAPI [MFC]
- MAPI support in MFC
- e-mail [MFC], enabling
- mail [MFC], enabling your application
- MAPI, MFC
- enabling applications for mail [MFC]
ms.assetid: 193449f7-b131-4ab0-9301-8d4f6cd1e7c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1df0d00aa6356fa1741e7f4fc34d8063782da859
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930668"
---
# <a name="mapi"></a>MAPI
Este artigo descreve o Microsoft MAPI Messaging Application Programming Interface () para os desenvolvedores de aplicativos de mensagem do cliente. MFC fornece suporte para um subconjunto de MAPI na classe `CDocument` , mas não encapsula a API do toda. Para obter mais informações, consulte [suporte a MAPI no MFC](../mfc/mapi-support-in-mfc.md).  
  
 MAPI é um conjunto de funções que usam aplicativos habilitados para email e reconhecimento de email para criar, manipular, transferir e armazenar mensagens de email. Ele fornece as ferramentas para definir o conteúdo das mensagens de email de desenvolvedores de aplicativos e oferece flexibilidade no gerenciamento de mensagens de email armazenado. MAPI também fornece uma interface comum que os desenvolvedores de aplicativos podem usar para criar o email e aplicativos habilitados para email independentes do sistema de mensagens subjacente.  
  
 Clientes de mensagens fornecem uma interface humana para interação com o Microsoft Windows Messaging System (WMS). Essa interação normalmente inclui a solicitação de serviços de provedores compatível com MAPI como repositórios de mensagens e listas de endereços.  
  
 Para obter mais informações sobre MAPI, consulte os artigos no guia em Win32 MAPI (Messaging) do SDK do Windows.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Suporte a MAPI no MFC](../mfc/mapi-support-in-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [CDocument::OnFileSendMail](../mfc/reference/cdocument-class.md#onfilesendmail)   
 [CDocument::OnUpdateFileSendMail](../mfc/reference/cdocument-class.md#onupdatefilesendmail)   
 [COleDocument::OnFileSendMail](../mfc/reference/coledocument-class.md#onfilesendmail)

