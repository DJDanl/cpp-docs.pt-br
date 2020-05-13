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
ms.openlocfilehash: 3024f744407cf33c8dfad8a6f7af736e0f8061ef
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356994"
---
# <a name="mapi-support-in-mfc"></a>Suporte a MAPI no MFC

O MFC fornece suporte para um subconjunto da Interface do Programa `CDocument`de Aplicativos de Mensagens da Microsoft (MAPI) na classe . Especificamente, `CDocument` tem funções de membro que determinam se o suporte de e-mail está presente na máquina do usuário final e, se for o caso, habilitar um comando Send Mail cujo ID de comando padrão está ID_FILE_SEND_MAIL. A função de manipulador MFC para este comando permite que o usuário envie um documento por correio eletrônico.

> [!TIP]
> Embora o MFC não encapsule todo o conjunto de funções MAPI, você ainda pode chamar as funções MAPI diretamente, assim como você pode chamar funções de API Win32 diretamente de programas MFC.

Fornecer o comando Enviar correio em seu aplicativo é muito fácil. O MFC fornece a implementação para `CDocument`empacotar um documento (ou seja, um objeto derivado) como um anexo e enviá-lo como correio. Este anexo é equivalente a um comando File Save que salva (serializa) o conteúdo do documento para a mensagem de e-mail. Esta implementação solicita ao cliente de e-mail na máquina do usuário a oportunidade de abordar o e-mail e adicionar texto de assunto e mensagem à mensagem de e-mail. Os usuários veem a interface de usuário do aplicativo de e-mail familiar. Esta funcionalidade é fornecida `CDocument` por duas `OnFileSendMail` `OnUpdateFileSendMail`funções de membros: e .

A MAPI precisa ler o arquivo para enviar o anexo. Se o aplicativo mantiver seu `OnFileSendMail` arquivo de dados aberto durante uma chamada de função, o arquivo precisa ser aberto com um modo de compartilhamento que permite que vários processos acessem o arquivo.

> [!NOTE]
> Uma versão sobreposta de `OnFileSendMail` classe `COleDocument` lida corretamente com documentos compostos.

#### <a name="to-implement-a-send-mail-command-with-mfc"></a>Para implementar um comando Enviar correio com MFC

1. Use o editor de menus Visual C++ para adicionar um item de menu cujo ID de comando é ID_FILE_SEND_MAIL.

   Este ID de comando é fornecido pela estrutura no AFXRES. H. O comando pode ser adicionado a qualquer menu, mas geralmente é adicionado ao menu **Arquivo.**

1. Adicione manualmente o seguinte ao mapa de mensagens do documento:

   [!code-cpp[NVC_MFCDocView#9](../mfc/codesnippet/cpp/mapi-support-in-mfc_1.cpp)]

    > [!NOTE]
    >  Este mapa de mensagem funciona `CDocument` para `COleDocument` um documento derivado de qualquer um ou — ele capta a classe base correta em ambos os casos, mesmo que o mapa de mensagem esteja na sua classe de documento derivada.

1. Construa sua aplicação.

Se o suporte de e-mail estiver `OnUpdateFileSendMail` disponível, o MFC habilita o item do menu com e, posteriormente, processa o comando com `OnFileSendMail`. Se o suporte de e-mail não estiver disponível, o MFC removerá automaticamente o item do menu para que o usuário não o veja.

> [!TIP]
> Em vez de adicionar manualmente entradas de mapa de mensagem como descrito anteriormente, você pode usar o [Assistente de Classe](reference/mfc-class-wizard.md) de classe para mapear mensagens para funções. Para obter mais informações, consulte ['Mapeamento de mensagens' para funções](../mfc/reference/mapping-messages-to-functions.md).

Para obter informações relacionadas, consulte a visão geral [do MAPI.](../mfc/mapi.md)

Para obter mais `CDocument` informações sobre as funções de membro que habilitam o MAPI, consulte:

- [cdocument::OnFileSendMail](../mfc/reference/cdocument-class.md#onfilesendmail)

- [cdocument::OnUpdateFileSendMail](../mfc/reference/cdocument-class.md#onupdatefilesendmail)

- [COleDocument::OnFileSendMail](../mfc/reference/coledocument-class.md#onfilesendmail)

## <a name="see-also"></a>Confira também

[MAPI](../mfc/mapi.md)
