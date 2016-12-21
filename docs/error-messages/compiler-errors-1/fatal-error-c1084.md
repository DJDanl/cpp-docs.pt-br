---
title: "Erro fatal C1084 | Microsoft Docs"
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
  - "C1084"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1084"
ms.assetid: b2f273ef-3a14-4d5f-8ce0-7a11a0388fe6
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1084
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Mensagem Não é possível ler arquivo do tipo: 'file'  
  
 Esse erro costuma ser resultado de uma falha na chamada à API do sistema interna feita pelo compilador.  A mensagem mostrada quando esse erro é encontrado costuma ser gerada por [\_wcserror\_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md) ou [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351.aspx).  
  
 A reprodução das seguintes etapas pode ajudar a resolver C1084:  
  
-   Verifique se o arquivo especificado existe.  
  
-   Verifique se as permissões apropriadas estão definidas para acessar o arquivo especificado.  
  
-   Verifique se a sintaxe da linha de comando respeita as regras descritas em [Sintaxe da linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md).  
  
-   Verifique se as variáveis de ambiente **TMP** e **TEMP** estão definidas corretamente, além das permissões apropriadas para acessar os diretórios a que essas variáveis de ambiente se referem.  Além disso, verifique se as unidades mencionadas pelas variáveis de ambiente **TMP** e **TEMP** contêm uma quantidade adequada de espaço livre.  
  
-   Se a mensagem indicar "número de arquivo incorreto", o arquivo especificado pode estar sendo fechado em primeiro plano durante a compilação em segundo plano.  
  
 Depois de realizar o diagnóstico acima, realize uma compilação limpa.