---
title: "Erro PRJ0009 (compila&#231;&#227;o de projeto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "PRJ0009"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0009"
ms.assetid: 89291778-cda4-495d-983f-ddcc06dfc98b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0009 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não foi possível abrir o log de compilação para gravação.  
  
 **Verifique se o arquivo não está aberto em outro processo e se ele não está protegido contra gravação.**  
  
 Depois de definir a propriedade de **Build Logging** a **Sim** e executando uma criação ou recriação, Visual C\+\+ não pôde abrir o modo da tentativa de logon de compilação.  
  
 Inspecionar **Build Logging** que define abrindo a caixa de diálogo de **Opções** \(no menu de **Ferramentas** , no comando de **Opções** clique em\) e selecionando **VC\+\+ Build** na pasta de **Projetos** .  O arquivo de compilação é chamado BuildLog.htm e no diretório intermediário $ \(IntDir\).  
  
 Razões possíveis para esse erro:  
  
-   Você está executando dois processos do Visual C\+\+ e está tentando\-os criar simultaneamente a mesma configuração do mesmo projeto no.  
  
-   O arquivo de log de compilação é aberto em um processo que impede que o arquivo.  
  
-   O usuário não tem permissão para criar um arquivo.  
  
-   O usuário atual tem acesso de gravação no arquivo BuildLog.htm.