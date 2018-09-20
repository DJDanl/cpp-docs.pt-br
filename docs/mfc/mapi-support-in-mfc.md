---
title: Suporte a MAPI no MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, MAPI support
- MAPI support in MFC
- CDocument class [MFC], and MAPI
- OnUpdateFileSendMail method [MFC]
- MAPI, MFC
- OnFileSendMail method [MFC]
ms.assetid: cafbecb1-0427-4077-b4b8-159bae5b49b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a3fbc661a870c7adc6e2e5dda5def744fa3e0396
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417003"
---
# <a name="mapi-support-in-mfc"></a>Suporte a MAPI no MFC

MFC fornece suporte para um subconjunto da Microsoft programa Interface MAPI (Messaging Application) na classe `CDocument`. Especificamente, `CDocument` tem funções de membro que determinam se o suporte de email está presente no computador do usuário final e, nesse caso, habilitar um comando de enviar email cuja ID de comando padrão é ID_FILE_SEND_MAIL. A função do manipulador do MFC para esse comando permite que o usuário envie um documento por email.

> [!TIP]
>  Embora o MFC não encapsula todo o conjunto de função MAPI, você pode ainda chamar funções MAPI diretamente, assim como você pode chamar funções da API do Win32 diretamente de programas MFC.

Comando em seu aplicativo fornecendo a enviar email é muito fácil. O MFC fornece a implementação para empacotar um documento (ou seja, um `CDocument`-objeto derivado) como um anexo e enviá-lo como email. Este anexo é equivalente a um comando de salvamento de arquivo que salva (serializa) o conteúdo do documento à mensagem de email. Essa implementação chama o cliente de email no computador do usuário para dar ao usuário a oportunidade de endereço de email e adicionar texto de assunto e a mensagem à mensagem de email. Os usuários veem a interface do usuário do aplicativo mail familiar. Essa funcionalidade é fornecida por duas `CDocument` funções de membro: `OnFileSendMail` e `OnUpdateFileSendMail`.

MAPI precisa ler o arquivo para enviar o anexo. Se o aplicativo mantém seu arquivo de dados aberto durante um `OnFileSendMail` chamada de função, o arquivo deve ser aberto com um modo de compartilhamento que permite que vários processos acessar o arquivo.

> [!NOTE]
>  Uma versão de substituição do `OnFileSendMail` para a classe `COleDocument` corretamente a identificadores de documentos compostos.

#### <a name="to-implement-a-send-mail-command-with-mfc"></a>Para implementar um comando Enviar email com o MFC

1. Use o editor de menu do Visual C++ para adicionar um item de menu cuja ID de comando é ID_FILE_SEND_MAIL.

     Essa ID de comando é fornecido pela estrutura no AFXRES. H. O comando pode ser adicionado a qualquer menu, mas ele geralmente é adicionado para o **arquivo** menu.

1. Adicione manualmente o seguinte ao mapa de mensagem do documento:

     [!code-cpp[NVC_MFCDocView#9](../mfc/codesnippet/cpp/mapi-support-in-mfc_1.cpp)]

    > [!NOTE]
    >  Este mapa de mensagem funciona para um documento derivadas de qualquer uma `CDocument` ou `COleDocument` — ele pega a classe base correta em ambos os casos, mesmo que o mapa da mensagem está em sua classe derivada de documento.

1. Crie seu aplicativo.

Se houver suporte para email, o MFC permite que o item de menu com `OnUpdateFileSendMail` e, subsequentemente, processa o comando com `OnFileSendMail`. Se o suporte de email não estiver disponível, o MFC remove automaticamente o item de menu para que o usuário não o verá.

> [!TIP]
>  Em vez de adicionar manualmente as entradas de mapa de mensagem conforme descritas anteriormente, você pode usar a janela de propriedades de classe para mapear as mensagens para funções. Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

Para obter informações relacionadas, consulte o [MAPI](../mfc/mapi.md) visão geral.

Para obter mais informações sobre o `CDocument` funções de membro que permitem a MAPI, consulte:

- [CDocument::OnFileSendMail](../mfc/reference/cdocument-class.md#onfilesendmail)

- [CDocument::OnUpdateFileSendMail](../mfc/reference/cdocument-class.md#onupdatefilesendmail)

- [COleDocument::OnFileSendMail](../mfc/reference/coledocument-class.md#onfilesendmail)

## <a name="see-also"></a>Consulte também

[MAPI](../mfc/mapi.md)

