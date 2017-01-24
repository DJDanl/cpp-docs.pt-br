---
title: "Erro fatal C1189 | Microsoft Docs"
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
  - "C1189"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1189"
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1189
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\#error: o usuário forneceu a mensagem de erro  
  
 C1189 é gerado pela política de `#error` .  O desenvolvedor que codifica a política especifica o texto da mensagem de erro.  Para obter mais informações, consulte [Diretiva \#error](../../preprocessor/hash-error-directive-c-cpp.md).  
  
 O exemplo a seguir produz C1189.  No exemplo, o desenvolvedor emite uma mensagem de erro personalizada porque o identificador de `_WIN32` não for definido:  
  
```  
// C1189.cpp  
#undef _WIN32  
#if !defined(_WIN32)  
#error _WIN32 must be defined   // C1189  
#endif  
```  
  
 Você também pode consultar este erro quando você cria um projeto de ATL usando a opção de compilador de **\/robust** MIDL.  Use a opção de **\/robust** para criar [!INCLUDE[win2kfamily](../../c-runtime-library/includes/win2kfamily_md.md)] somente e versões posteriores do windows.  Para corrigir esse erro, use um dos seguintes procedimentos:  
  
-   Alterar essa linha no arquivo de dlldatax.c:  
  
```  
#define _WIN32_WINNT 0x0400   // for WinNT 4.0 or Windows 95 with DCOM  
```  
  
 até:  
  
```  
#define _WIN32_WINNT 0x0500   // for WinNT 4.0 or Windows 95 with DCOM  
```  
  
-   Use a página de propriedades de **Avançado** na pasta da página de propriedades de **MIDL** para remover a opção de **\/robust** e especificar a opção de **\/no\_robust** .  Para obter mais informações, consulte [Páginas de propriedade MIDL: avançado](../../ide/midl-property-pages-advanced.md).  
  
## Consulte também  
 [Diretiva \#define](../../preprocessor/hash-define-directive-c-cpp.md)