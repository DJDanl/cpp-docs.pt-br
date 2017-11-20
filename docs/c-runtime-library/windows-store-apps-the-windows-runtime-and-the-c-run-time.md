---
title: Aplicativos da Windows Store, Windows Runtime e C Run-Time | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 356d6d8d-76ee-4181-9ad0-6f24b2fede38
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b332e392db2ca788d041cb73e73cf42cce85906c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="windows-store-apps-the-windows-runtime-and-the-c-run-time"></a>Aplicativos da Windows Store, Windows Runtime  e C Run-Time
Os aplicativos [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] são programas executados no Windows Runtime que é executado no [!INCLUDE[win8](../build/reference/includes/win8_md.md)].  O Windows Runtime é um ambiente confiável que controla as funções, as variáveis e os recursos que estão disponíveis para um aplicativo [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)]. No entanto, por design, há restrições do Windows Runtime que impedem o uso da maioria dos recursos de biblioteca em tempo de execução do C (CRT) nos aplicativos [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)].  
  
 O Windows Runtime não tem suporte para os seguintes recursos de CRT:  
  
-   A maioria das funções de CRT que estão relacionados à funcionalidade sem suporte.  
  
     Por exemplo, um aplicativo [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] não pode criar um processo usando as famílias de rotinas `exec` e `spawn`.  
  
     Quando uma função CRT não tem suporte em um aplicativo [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)], esse fato é observado em seu artigo de referência.  
  
-   Maioria das funções de caracteres multibyte e cadeia de caracteres.  
  
     No entanto, há suporte para texto ANSI e Unicode.  
  
-   Aplicativos de console e argumentos de linha de comando.  
  
     Entretanto, aplicativos de área de trabalho tradicionais ainda dão suporte ao console e a argumentos de linha de comando.  
  
-   Variáveis de ambiente.  
  
-   O conceito de um diretório de trabalho atual.  
  
-   [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos e DLLs estaticamente vinculados a CRT e criados usando as opções [/MT](../build/reference/md-mt-ld-use-run-time-library.md) ou `/MTd` do compilador.  
  
     Ou seja, um aplicativo que usa uma versão estática multithread do CRT.  
  
-   Um aplicativo que é criado usando a opção do compilador [/MDd](../build/reference/md-mt-ld-use-run-time-library.md).  
  
     Ou seja, uma versão específica de depuração, multithread e DLL do CRT. Não há suporte para este aplicativo no [!INCLUDE[win8_appstore_long](../build/reference/includes/win8_appstore_long_md.md)].  
  
 Para obter uma lista completa das funções de CRT que não estão disponíveis em um aplicativo [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] e sugestões para funções alternativas, consulte [funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="see-also"></a>Consulte também  
 [Compatibilidade](../c-runtime-library/compatibility.md)   
 [Funções CRT sem suporte no Windows Runtime](../c-runtime-library/windows-runtime-unsupported-crt-functions.md)   
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)