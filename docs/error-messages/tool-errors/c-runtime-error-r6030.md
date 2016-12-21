---
title: "R6030 de erro de tempo de execu&#231;&#227;o do C | Microsoft Docs"
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
  - "R6030"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "R6030"
ms.assetid: 0238a6c3-a033-4046-8adc-f8f99d961153
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# R6030 de erro de tempo de execu&#231;&#227;o do C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

CRT não inicializado  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. Esse problema é geralmente causado por certos programas de software de segurança ou, raramente, por um bug no programa.  
>   
>  Você pode tentar estas etapas para corrigir esse erro:  
>   
>  -   Seu software de segurança pode ter instruções específicas para atenuar esse problema. Verifique o site do fornecedor do software sua segurança para obter detalhes. Como alternativa, verifique versões atualizadas do seu software de segurança ou experimente o software de segurança diferentes.  
> -   Use o **os aplicativos e recursos** ou **programas e recursos** página o **Painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **Painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Esse erro ocorre se você estiver usando o C Runtime \(CRT\), mas o código de inicialização do CRT não foi executado. É possível obter esse erro se o vinculador alternar [\/ENTRY](../../build/reference/entry-entry-point-symbol.md) é usada para substituir o padrão Iniciando endereço, geralmente **mainCRTStartup**, **wmainCRTStartup** para um console EXE **WinMainCRTStartup** ou **wWinMainCRTStartup** para um EXE do Windows, ou **dllmaincrtstartup** para uma DLL. A menos que uma das funções acima é chamada na inicialização, o tempo de execução C não será inicializado. Essas funções de inicialização normalmente são chamadas por padrão quando você vincular à biblioteca de tempo de execução do C e use o normal **principal**, **wmain**, **WinMain**, ou **DllMain** pontos de entrada.  
  
 Também é possível obter esse erro quando outro programa usa técnicas de injeção de código para interceptar determinadas chamadas de biblioteca DLL. Alguns programas de segurança intrusivo usam essa técnica. Em versões do Visual C\+\+ antes do Visual Studio 2015, é possível usar uma biblioteca de CRT vinculadas estaticamente para resolver o problema, mas isso não é recomendado por motivos de atualizações de segurança e de aplicativos. Corrigir esse problema pode exigir ação do usuário final.