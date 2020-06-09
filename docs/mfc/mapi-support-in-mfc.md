---
title: Suporte a MAPI no MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, MAPI support
- MAPI support in MFC
- CDocument class [MFC], and MAPI
- OnUpdateFileSendMail method [MFC]
- MAPI, MFC
- OnFileSendMail method [MFC]
ms.assetid: cafbecb1-0427-4077-b4b8-159bae5b49b8
ms.openlocfilehash: 7eff22b2a7b4c838f2967fb5217b9dec96903d0e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625564"
---
# <a name="mapi-support-in-mfc"></a>Suporte a MAPI no MFC

O MFC fornece suporte para um subconjunto da interface de programa de aplicativo (MAPI) do sistema de mensagens da Microsoft na classe `CDocument` . Especificamente, o `CDocument` tem funções de membro que determinam se o suporte a email está presente na máquina do usuário final e, em caso afirmativo, habilita um comando enviar email cuja ID de comando padrão é ID_FILE_SEND_MAIL. A função de manipulador do MFC para esse comando permite que o usuário envie um documento por email.

> [!TIP]
> Embora o MFC não encapsulasse todo o conjunto de funções MAPI, você ainda pode chamar funções MAPI diretamente, assim como você pode chamar funções de API do Win32 diretamente de programas MFC.

É muito fácil fornecer o comando enviar email em seu aplicativo. O MFC fornece a implementação para empacotar um documento (ou seja, um `CDocument` objeto derivado) como um anexo e enviá-lo como email. Esse anexo é equivalente a um comando File Save que salva (serializa) o conteúdo do documento na mensagem de email. Essa implementação chama o cliente de email na máquina do usuário para dar ao usuário a oportunidade de endereçar o email e adicionar o assunto e o texto da mensagem à mensagem de email. Os usuários veem a interface do usuário do seu aplicativo de email familiar. Essa funcionalidade é fornecida por duas `CDocument` funções de membro: `OnFileSendMail` e `OnUpdateFileSendMail` .

MAPI precisa ler o arquivo para enviar o anexo. Se o aplicativo mantiver seu arquivo de dados aberto durante uma `OnFileSendMail` chamada de função, o arquivo precisará ser aberto com um modo de compartilhamento que permite que vários processos acessem o arquivo.

> [!NOTE]
> Uma versão de substituição do `OnFileSendMail` para classe `COleDocument` manipula corretamente os documentos compostos.

#### <a name="to-implement-a-send-mail-command-with-mfc"></a>Para implementar um comando enviar email com o MFC

1. Use o editor de menu Visual C++ para adicionar um item de menu cuja ID de comando seja ID_FILE_SEND_MAIL.

   Essa ID de comando é fornecida pela estrutura em AFXRES. T. O comando pode ser adicionado a qualquer menu, mas normalmente é adicionado ao menu **arquivo** .

1. Adicione manualmente o seguinte ao mapa de mensagens do documento:

   [!code-cpp[NVC_MFCDocView#9](codesnippet/cpp/mapi-support-in-mfc_1.cpp)]

    > [!NOTE]
    >  Esse mapa de mensagens funciona para um documento derivado de `CDocument` ou `COleDocument` — ele pega a classe base correta em ambos os casos, mesmo que o mapa da mensagem esteja em sua classe de documento derivada.

1. Compile seu aplicativo.

Se o suporte a email estiver disponível, o MFC habilitará o item de menu com `OnUpdateFileSendMail` e processará posteriormente o comando com `OnFileSendMail` . Se o suporte a email não estiver disponível, o MFC removerá automaticamente o item de menu para que o usuário não o veja.

> [!TIP]
> Em vez de adicionar manualmente entradas de mapa de mensagem conforme descrito anteriormente, você pode usar o [Assistente de classe](reference/mfc-class-wizard.md) de classe para mapear mensagens para o functions. Para obter mais informações, consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md).

Para obter informações relacionadas, consulte a visão geral do [MAPI](mapi.md) .

Para obter mais informações sobre as `CDocument` funções de membro que habilitam MAPI, consulte:

- [CDocument:: OnFileSendMail](reference/cdocument-class.md#onfilesendmail)

- [CDocument:: OnUpdateFileSendMail](reference/cdocument-class.md#onupdatefilesendmail)

- [COleDocument::OnFileSendMail](reference/coledocument-class.md#onfilesendmail)

## <a name="see-also"></a>Consulte também

[MAPI](mapi.md)
