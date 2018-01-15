---
title: Tipos de DLLs | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC DLLs [C++], types
- DLLs [C++], types
- DLLs [C++], MFC
ms.assetid: f6a30db9-6138-4b2c-90cc-a17855e499a6
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 47ce4a9264a59f88f22cd40bc3b6d6620c9702c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="kinds-of-dlls"></a>Tipos de DLLs
Este tópico fornece informações para ajudá-lo a determinar o tipo da DLL para compilar.  
  
##  <a name="_core_the_different_kinds_of_dlls_available_with_visual_c.2b2b"></a>Diferentes tipos de DLLs disponíveis  
 Usando o Visual C++, você pode criar DLLs Win32 em C ou C++ que não usam a biblioteca Microsoft Foundation Class (MFC). Você pode criar um projeto de DLL não - MFC com o Assistente de aplicativo Win32.  
  
 A biblioteca do MFC está disponível, em qualquer bibliotecas de link estático ou em um número de DLLs, com o Assistente de DLL do MFC. Se a DLL está usando MFC, Visual C++ dá suporte a três cenários de desenvolvimento de DLL diferentes:  
  
-   Criar uma DLL MFC regular que estaticamente vincula MFC  
  
-   Criar uma DLL MFC regular que dinamicamente vincula MFC  
  
-   Criar uma DLL de extensão do MFC, que vincular dinamicamente sempre MFC  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [DLLs não MFC: visão geral](../build/non-mfc-dlls-overview.md)  
  
-   [DLLs normais do MFC vinculado estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente a MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [DLLs de extensão do MFC: visão geral](../build/extension-dlls-overview.md)  
  
-   [Que tipo de DLL para usar](#_core_which_kind_of_dll_to_use)  
  
##  <a name="_core_which_kind_of_dll_to_use"></a>O tipo de DLL para uso  
 Se a DLL não usar MFC, use o Visual C++ para criar uma não - MFC Win32 DLL. Vinculando a DLL para MFC (estática ou dinâmica) ocupa muito espaço em disco e de memória. Você não deve vincular a MFC, a menos que a DLL realmente usa MFC.  
  
 Se sua DLL usará MFC e será usado por aplicativos MFC ou não MFC, você deve criar uma DLL MFC regular vinculada dinamicamente a MFC ou uma DLL MFC regular que se vincula estaticamente ao MFC. Na maioria dos casos, você provavelmente desejará usar uma DLL MFC regular vinculada dinamicamente a MFC, porque o tamanho do arquivo da DLL será muito menor e a economia na memória usa a versão compartilhada do MFC pode ser significativa. Se você vincular estaticamente ao MFC, o tamanho do arquivo de sua DLL será maior e potencialmente ocupam memória extra porque ele carrega sua própria cópia do código de biblioteca do MFC.  
  
 Criar uma DLL que vincula dinamicamente a MFC é mais rápido do que criar uma DLL que se vincula estaticamente ao MFC porque ele não é necessário vincular MFC em si. Isso é especialmente verdadeiro em compilações de depuração em que o vinculador deve compactar as informações de depuração. Por meio da vinculação com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro da sua DLL.  
  
 Uma desvantagem vincular dinamicamente a MFC é que você deve distribuir o Mfcx0.dll de DLLs compartilhadas e Msvcrxx.dll (ou arquivos similares) com sua DLL. As DLLs MFC são redistribuíveis gratuitamente, mas você ainda deve instalar as DLLs em seu programa de instalação. Além disso, você deve enviar Msvcrxx.dll, que contém a biblioteca de tempo de execução C que é usada pelo seu programa e as DLLs MFC próprios.  
  
 Se sua DLL somente será usado por arquivos executáveis do MFC, você terá a opção de criar uma DLL MFC regular ou uma DLL de extensão do MFC. Se sua DLL implementa reutilizáveis classes derivadas de classes MFC existentes ou você precisa passar objetos derivados de MFC entre o aplicativo e a DLL, você deve criar uma DLL de extensão do MFC.  
  
 Se sua DLL vincula dinamicamente a MFC, as DLLs MFC pode ser redistribuídas com sua DLL. Essa arquitetura é particularmente útil para o compartilhamento de biblioteca de classes entre vários arquivos executáveis para economizar espaço em disco e minimizar o uso de memória.  
  
 Antes da versão 4.0, tipos de Visual C++ apenas dois com suporte de DLLs que usado MFC: USRDLLs e AFXDLLs. DLLs normais do MFC vinculado estaticamente ao MFC têm as mesmas características como o USRDLL anterior. DLLs de extensão do MFC com as mesmas características como os AFXDLLs anteriores.  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [DLLs não MFC: visão geral](../build/non-mfc-dlls-overview.md)  
  
-   [DLLs normais do MFC vinculado estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente a MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [DLLs de extensão do MFC: visão geral](../build/extension-dlls-overview.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)