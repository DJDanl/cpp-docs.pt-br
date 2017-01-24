---
title: "Erro RW2001 (compilador de recurso) | Microsoft Docs"
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
  - "RW2001"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "RW2001"
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro RW2001 (compilador de recurso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Política inválido no arquivo pré\-processado de RC  
  
 O arquivo de RC contém uma política de **\#pragma** .  
  
 Use a política de pré\-processador de **\#ifndef** com a constante de **RC\_INVOKED** que o compilador do recurso define quando processa um arquivo incluir.  Coloque a política de **\#pragma** dentro de um bloco de código que não é processada quando a constante de **RC\_INVOKED** é definida.  O código no bloco é processada somente pelo compilador C\/C\+\+ e não pelo compilador do recurso.  O exemplo de código a seguir demonstra essa técnica:  
  
```  
#ifndef RC_INVOKED  
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler  
#endif  
```  
  
 A política de pré\-processador de **\#pragma** não tem nenhum significado em um arquivo de .RC.  A política de pré\-processador de **\#include** é frequentemente usada em um arquivo de .RC para incluir um arquivo de cabeçalho \(um arquivo de cabeçalho personalizado com base ou de um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos\).  Algumas dessas inclui arquivos contém a política de **\#pragma** .  Como um arquivo de cabeçalho pode incluir outros arquivos de cabeçalho, o arquivo que contém a política de incorretos de **\#pragma** não pode ser óbvio imediatamente.  
  
 A técnica de **\#ifndefRC\_INVOKED** pode controlar incluir arquivos de cabeçalho em arquivos de cabeçalho de base.