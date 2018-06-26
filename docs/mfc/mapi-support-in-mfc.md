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
ms.openlocfilehash: 301e15b11b05f9ccbeaee63aead486f1cc6c405c
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931896"
---
# <a name="mapi-support-in-mfc"></a>Suporte a MAPI no MFC
MFC fornece suporte para um subconjunto da Microsoft programa Interface MAPI (Messaging Application) na classe `CDocument`. Especificamente, `CDocument` tem funções de membro que determinam se o suporte de correio está presente no computador do usuário final e, nesse caso, habilite um comando Enviar email cuja ID de comando padrão é ID_FILE_SEND_MAIL. A função de manipulador do MFC para este comando permite que o usuário enviar um documento por email.  
  
> [!TIP]
>  Embora MFC não encapsula o conjunto de funções MAPI inteiro, você ainda poderá chamar funções MAPI diretamente, assim como você pode chamar funções de API do Win32 diretamente a partir de programas do MFC.  
  
 Comando em seu aplicativo fornecer a enviar email é muito fácil. MFC fornece a implementação para um documento do pacote (isto é, um `CDocument`-objeto derivado) como um anexo e enviá-lo por email. Este anexo é equivalente a um comando de salvamento do arquivo que salva (serializa) o conteúdo do documento para a mensagem de email. Essa implementação chama o cliente de email no computador do usuário para dar ao usuário a oportunidade de endereço de email e adicionar texto de assunto e a mensagem para a mensagem de email. Os usuários veem a interface do usuário do seu aplicativo de email familiar. Essa funcionalidade é fornecida por duas `CDocument` funções de membro: `OnFileSendMail` e `OnUpdateFileSendMail`.  
  
 MAPI precisa ler o arquivo para enviar o anexo. Se o aplicativo mantém seu arquivo de dados aberto durante um `OnFileSendMail` chamada de função, o arquivo precisa ser aberto com um modo de compartilhamento que permite que vários processos acessar o arquivo.  
  
> [!NOTE]
>  Uma versão de substituição do `OnFileSendMail` para a classe `COleDocument` corretamente a identificadores de documentos compostos.  
  
#### <a name="to-implement-a-send-mail-command-with-mfc"></a>Para implementar um comando Enviar email com MFC  
  
1.  Use o editor de menu do Visual C++ para adicionar um item de menu cuja ID de comando é ID_FILE_SEND_MAIL.  
  
     Essa ID de comando é fornecida pelo framework em AFXRES. H. O comando pode ser adicionado a qualquer menu, mas é geralmente adicionado para o **arquivo** menu.  
  
2.  Adicione manualmente o seguinte ao mapa de mensagem do documento:  
  
     [!code-cpp[NVC_MFCDocView#9](../mfc/codesnippet/cpp/mapi-support-in-mfc_1.cpp)]  
  
    > [!NOTE]
    >  Este mapa de mensagem funciona para um documento derivadas do `CDocument` ou `COleDocument` — ela pega a classe base correta em ambos os casos, mesmo que o mapa da mensagem está em sua classe derivada de documento.  
  
3.  Crie seu aplicativo.  
  
 Se houver suporte para email, MFC permite que o item de menu com `OnUpdateFileSendMail` e subsequentemente processa o comando com `OnFileSendMail`. Se não houver suporte para email, MFC remove automaticamente o item de menu para que o usuário não verá-lo.  
  
> [!TIP]
>  Em vez de adicionar manualmente as entradas de mapa de mensagem conforme descritas anteriormente, você pode usar a janela de propriedades de classe para mapear as mensagens para funções. Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).  
  
 Para obter informações relacionadas, consulte o [MAPI](../mfc/mapi.md) visão geral.  
  
 Para obter mais informações sobre o `CDocument` funções de membro que permitem a MAPI, consulte:  
  
-   [CDocument::OnFileSendMail](../mfc/reference/cdocument-class.md#onfilesendmail)  
  
-   [CDocument::OnUpdateFileSendMail](../mfc/reference/cdocument-class.md#onupdatefilesendmail)  
  
-   [COleDocument::OnFileSendMail](../mfc/reference/coledocument-class.md#onfilesendmail)  
  
## <a name="see-also"></a>Consulte também  
 [MAPI](../mfc/mapi.md)

