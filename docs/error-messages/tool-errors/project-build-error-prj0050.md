---
title: "Erro PRJ0050 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0050"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0050"
ms.assetid: ceef3b37-0acf-4abd-ac62-aa830b4fa145
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro PRJ0050 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

falha ao registrar saída.Verifique se você possui as permissões apropriadas para modificar o registro.  
  
 O sistema de compilação do Visual C\+\+ não pode registrar a saída de construção \(DLL ou .exe\).  Você precisa estar conectado como um administrador para alterar o Registro.  
  
 Se você estiver criando um .dll, você pode tentar registrar o .dll manualmente usando o regsvr32.exe, isso deve exibir informações sobre como a construção falhou.  
  
 Se você não estiver criando um .dll, verifique no log de compilação para o comando que causa um erro.