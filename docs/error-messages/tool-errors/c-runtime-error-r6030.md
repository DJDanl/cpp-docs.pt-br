---
title: "R6030 de erro de tempo de execução C | Documentos do Microsoft"
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
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 70a117e5a24e9720a0b53b7c446ee1d2f1360091
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6030"></a>R6030 de erro de tempo de execução do C
CRT não inicializado  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Esse problema é geralmente causado por certos programas de software de segurança ou, raramente, por um bug no programa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Seu software de segurança pode ter instruções específicas para atenuar esse problema. Verifique o site do fornecedor do software sua segurança para obter detalhes. Como alternativa, verifique versões atualizadas do seu software de segurança ou experimente o software de segurança diferentes.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre se você estiver usando o C Runtime (CRT), mas o código de inicialização do CRT não foi executado. É possível obter esse erro se o vinculador alternar [/ENTRY](../../build/reference/entry-entry-point-symbol.md) é usada para substituir o padrão Iniciando endereço, geralmente **mainCRTStartup**, **wmainCRTStartup** para um console EXE **WinMainCRTStartup** ou **wWinMainCRTStartup** para um EXE do Windows, ou **dllmaincrtstartup** para uma DLL. A menos que uma das funções acima é chamada na inicialização, o tempo de execução C não será inicializado. Essas funções de inicialização normalmente são chamadas por padrão quando você vincular à biblioteca de tempo de execução do C e usa a interface normal do **principal**, **wmain**, **WinMain**, ou **DllMain** pontos de entrada.  
  
 Também é possível obter esse erro quando outro programa usa técnicas de injeção de código para interceptar determinadas chamadas de biblioteca DLL. Alguns programas de segurança intrusivo usam essa técnica. Em versões do Visual C++ antes do Visual Studio 2015, é possível usar uma biblioteca de CRT vinculadas estaticamente para resolver o problema, mas isso não é recomendado por motivos de atualizações de segurança e de aplicativos. Corrigir esse problema pode exigir ação do usuário final.
