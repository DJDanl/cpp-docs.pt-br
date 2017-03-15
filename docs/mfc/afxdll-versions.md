---
title: "Vers&#245;es AFXDLL | Microsoft Docs"
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
  - "afxdll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Biblioteca AFXDLL"
  - "assistentes de aplicativo [C++], Usos padrão AFXDLL"
  - "Versão de DLL do MFC [C++]"
  - "MFC [C++], Versão AFXDLL"
  - "DLLs MFC [C++], vinculação dinâmica a biblioteca"
  - "Bibliotecas MFC [C++], vinculação dinâmica"
ms.assetid: c078ae8f-85a9-43cb-9ded-c09ca2c45723
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vers&#245;es AFXDLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em vez de criar seu aplicativo estaticamente vinculando às bibliotecas de código em MFC, você pode criar seu aplicativo usar uma das bibliotecas de AFXDLL, que contém o MFC em uma DLL que vários aplicativos em execução pode ser compartilhada.  Para uma tabela de nomes de AFXDLL, consulte [DLL: Convenções de nomenclatura](../build/naming-conventions-for-mfc-dlls.md).  
  
> [!NOTE]
>  Por padrão, o assistente de aplicativo MFC cria um projeto de AFXDLL.  Para usar em vez de vincular estático de código MFC, defina a opção de **Usar MFC em uma Static Library** no assistente de aplicativo MFC.  Vinculação estática não está disponível na edição Standard do Visual C\+\+.  
  
## Consulte também  
 [Versões de biblioteca MFC](../mfc/mfc-library-versions.md)