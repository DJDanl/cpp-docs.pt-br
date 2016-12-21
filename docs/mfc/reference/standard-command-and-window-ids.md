---
title: "Comando padr&#227;o e IDs do Windows | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "comando padrão e IDs do Windows"
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
caps.latest.revision: 13
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Comando padr&#227;o e IDs do Windows
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classes do Microsoft define um número padrão de IDs de comando e a janela em Afxres.h.  Essas IDs são usados com mais frequência nos editores de recursos e da janela Propriedades mapear mensagens às funções do manipulador.  Todos os comandos padrão têm um prefixo de **ID\_** .  Por exemplo, quando você usa o editor no menu, normalmente você associa o item de menu aberto de Arquivo padrão para a ID de comando de `ID_FILE_OPEN`  
  
 Para a maioria de comandos padrão, o código do aplicativo não precisa fazer referência a ID de comando, porque a estrutura própria trata os comandos pelos mapas de mensagem em suas classes principais de estrutura \(`CWinThread`, `CWinApp`, `CView`, **CDocument**, e assim por diante\).  
  
 Além de IDs padrão de comando, vários outros de IDs padrão são definidos que têm um prefixo de **AFX\_ID**.  Essas IDs incluem IDs padrão da janela **AFX\_IDW\_**prefixo \(\), IDs de cadeia de caracteres \(prefixo **AFX\_IDS\_**\), e vários outros tipos.  
  
 As IDs que começam com o prefixo de **AFX\_ID** são usadas raramente por programadores, mas por você poderá precisar consultar essas IDs para substituir a estrutura função que também fazem referência a **AFX\_ID**S.  
  
 As IDs não estão documentados individualmente nesta referência.  Você pode encontrar mais informações sobre eles em observações técnicas [20](../../mfc/tn020-id-naming-and-numbering-conventions.md), [21](../../mfc/tn021-command-and-message-routing.md), e [22](../../mfc/tn022-standard-commands-implementation.md).  
  
> [!NOTE]
>  O arquivo de cabeçalho Afxres.h é incluído indiretamente em Afxwin.h.  Você deve explicitamente incluir a instrução a seguir no arquivo de script de recurso do aplicativo \(.rc\):  
  
 [!code-cpp[NVC_MFC_Utilities#47](../../mfc/codesnippet/CPP/standard-command-and-window-ids_1.h)]  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)