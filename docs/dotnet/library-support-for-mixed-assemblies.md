---
title: Suporte de biblioteca para Assemblies mistos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- msvcm90[d].dll
- mixed assemblies [C++], library support
- msvcmrt[d].lib
- libraries [C++], mixed assemblies
ms.assetid: 1229595c-9e9d-414d-b018-b4e4c727576d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9b3bc50416eceac64c134a31a4d7384e33db69b4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="library-support-for-mixed-assemblies"></a>Suporte de biblioteca para assemblies mistos
Visual C++ oferece suporte ao uso da biblioteca padrão C++, a biblioteca de tempo de execução comum (CRT), ATL e MFC para aplicativos compilados com [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md). Isso permite que os aplicativos existentes que usam essas bibliotecas para usar recursos do .NET Framework também.  
  
 Esse suporte apresenta as seguintes bibliotecas de importação e a DLL de novo:  
  
-   Msvcmrt [d]. lib se você compilar com /clr. Assemblies mistos links para essa biblioteca de importação.  
  
-   Msvcm90. [d] dll e. lib de Msvcurt [d] se você compilar com /clr: pure. A DLL é um conjunto misto fornecendo suporte gerenciado do tempo de execução do C (CRT) e faz parte de um assembly gerenciado instalado no cache de assembly global (GAC). Assemblies puros o link para esta biblioteca de importação e terminam associado ao Msvcm90.dll.  
  
 Esse suporte fornece que vários benefícios relacionados ao:  
  
-   A biblioteca padrão C++ e CRT estão disponíveis para código misto e puro. O CRT e biblioteca padrão do C++ fornecidas não são verificáveis; Por fim, as chamadas ainda são roteadas para o mesmo CRT e biblioteca padrão C++ como você está usando no código nativo.  
  
-   Corrija o tratamento de exceção unificada em imagens puros e mistos.  
  
-   Inicialização estática de variáveis de C++ em imagens puras e mistas.  
  
-   Suporte para variáveis per-AppDomain e por processo no código gerenciado.  
  
-   Resolve os problemas de bloqueio do carregador aplicado a mistos DLLs compiladas no Visual Studio 2003 e versões anteriores.  
  
 Além disso, esse suporte apresenta as seguintes limitações:  
  
-   Há suporte para apenas o modelo de DLL do CRT (para código compilado com /clr ou /clr: pure).  
  
-   Você não pode misturar puros e mistos objetos em uma única imagem se esses objetos usam as bibliotecas do Visual C++ (porque todos os objetos devem ser puros em uma imagem simples). Se você fizer isso, você recebe erros de tempo de vinculação.  
  
 Você deve atualizar o tempo de execução de linguagem comum (CLR) para a versão atual que não é garantido que ele funciona com versões anteriores. Criado com essas alterações de código não será executado na versão do CLR 1. x.  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)