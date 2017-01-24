---
title: "Suporte a MAPI no MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDocument, e MAPI"
  - "Suporte a MAPI no MFC"
  - "MAPI, MFC"
  - "MFC, Suporte MAPI"
  - "Método OnFileSendMail"
  - "Método OnUpdateFileSendMail"
ms.assetid: cafbecb1-0427-4077-b4b8-159bae5b49b8
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte a MAPI no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Suporte de fontes MFC para um subconjunto de Interface de aplicativo \(MAPI\) da mensagem do Microsoft na classe **CDocument**.  Especificamente, **CDocument** tem funções de membro que determinam se o suporte de email estiver presente no computador do usuário final e, nesse caso, permite que um comando enviar email cujo ID de comando padrão é **ID\_FILE\_SEND\_MAIL**.  A função de manipulador de MFC deste comando permite que o usuário envia um documento pelo correio eletrônico.  
  
> [!TIP]
>  Embora o MFC não encapsula o conjunto inteiro da função de MAPI estendida, você ainda pode chamar funções de MAPI estendida diretamente, exatamente como você pode chamar funções de API do Win32 diretamente de programas MFC.  
  
 Forneça o comando enviar email em seu aplicativo é muito fácil.  MFC O fornece implementação de pacote um documento \(isto é, **CDocument**\- objeto derivado\) como um anexo e envie como email.  Este anexar é equivalente a um comando save que salva \(\) serializa o conteúdo do documento à mensagem de email.  Essa implementação convida o cliente de email no computador do usuário para dar ao usuário a oportunidade de tratar o email e adicionar o texto do assunto da mensagem e à mensagem de email.  Os usuários consultem a interface de usuário do aplicativo familiar de email.  Essa funcionalidade é fornecida por duas funções de membro de **CDocument** : `OnFileSendMail` e `OnUpdateFileSendMail`.  
  
 MAPI precisa ler o arquivo para enviar o anexo.  Se o aplicativo mantiver o arquivo de dados aberto durante uma chamada de função de `OnFileSendMail` , o arquivo precisa ser aberto com um modo de compartilhamento que permite que vários processos acessar o arquivo.  
  
> [!NOTE]
>  Substituindo uma versão de `OnFileSendMail` da classe `COleDocument` trata corretamente documentos compostos.  
  
#### Para implementar um enviar email de comando com MFC  
  
1.  Use o editor do menu do Visual C\+\+ para adicionar um item de menu cujo ID do comando é **ID\_FILE\_SEND\_MAIL**.  
  
     Essa ID do comando é fornecido pela estrutura. AFXRES.H em.  O comando pode ser adicionado a qualquer menu, mas geralmente é adicionado ao menu de **Arquivo** .  
  
2.  Adicionar manualmente o seguinte no mapa da mensagem do documento:  
  
     [!code-cpp[NVC_MFCDocView#9](../mfc/codesnippet/CPP/mapi-support-in-mfc_1.cpp)]  
  
    > [!NOTE]
    >  Esse mapa de mensagem funciona para um documento derivado de **CDocument** ou de **COleDocument** — pegara a classe base correta em ambos os casos, mesmo que o mapa da mensagem está na sua classe derivada do documento.  
  
3.  Criar seu aplicativo.  
  
 Se o suporte de email estiver disponível, o MFC habilita o item de menu usando `OnUpdateFileSendMail` e processa subsequentemente o comando com `OnFileSendMail`.  Se o suporte de email não estiver disponível, o MFC remove automaticamente o item de menu para que o usuário não visualizará.  
  
> [!TIP]
>  Em vez de registrá\-los manualmente adicionando entradas da mensagem como descrito anteriormente, você pode usar a janela Propriedades da classe para mapear mensagens nas funções.  Para obter mais informações, consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md).  
  
 Para obter informações relacionadas, consulte a seção visão geral de [MAPI](../mfc/mapi.md) .  
  
 Para obter mais informações sobre as funções de membro de **CDocument** que habilitam MAPI estendida, consulte:  
  
-   [CDocument::OnFileSendMail](../Topic/CDocument::OnFileSendMail.md)  
  
-   [CDocument::OnUpdateFileSendMail](../Topic/CDocument::OnUpdateFileSendMail.md)  
  
-   [COleDocument::OnFileSendMail](../Topic/COleDocument::OnFileSendMail.md)  
  
## Consulte também  
 [MAPI](../mfc/mapi.md)