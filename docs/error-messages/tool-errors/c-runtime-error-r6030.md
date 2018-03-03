---
title: "R6030 de erro de tempo de execução C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6030
dev_langs:
- C++
helpviewer_keywords:
- R6030
ms.assetid: 0238a6c3-a033-4046-8adc-f8f99d961153
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7bc7c5db2b486ef051975c0e8d31d6c24ca5aa6a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-runtime-error-r6030"></a>R6030 de erro de tempo de execução do C
CRT não inicializado  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Esse problema geralmente é causado por determinados programas de software de segurança ou raramente, por um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   O software de segurança pode ter instruções específicas para atenuar esse problema. Verifique o site do seu fornecedor de software de segurança para obter detalhes. Como alternativa, versões atualizadas do seu software de segurança, ou tente o software de segurança diferente.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre se você estiver usando o tempo de execução do C (CRT), mas o código de inicialização do CRT não foi executado. É possível receber esse erro se o vinculador alternar [/ENTRY](../../build/reference/entry-entry-point-symbol.md) é usada para substituir o padrão Iniciando endereço, geralmente **mainCRTStartup**, **wmainCRTStartup** para um console EXE, **WinMainCRTStartup** ou **wWinMainCRTStartup** para um EXE do Windows, ou **dllmaincrtstartup** para uma DLL. A menos que uma das funções acima é chamada na inicialização, o tempo de execução do C não será inicializado. Essas funções de inicialização normalmente são chamadas por padrão quando o link para a biblioteca de tempo de execução do C e usar o normal **principal**, **wmain**, **WinMain**, ou  **DllMain** pontos de entrada.  
  
 Também é possível receber esse erro quando outro programa usa técnicas de injeção de código para interceptar determinadas chamadas da biblioteca DLL. Alguns programas de segurança intruso usam esta técnica. Nas versões do Visual C++ antes do Visual Studio 2015, é possível usar uma biblioteca CRT estaticamente vinculada para resolver o problema, mas isso não é recomendado por motivos de atualizações de segurança e aplicativo. Como corrigir esse problema pode exigir ação do usuário final.