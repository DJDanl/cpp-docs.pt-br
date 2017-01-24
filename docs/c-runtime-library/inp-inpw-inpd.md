---
title: "_inp, _inpw, _inpd | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_inp"
  - "_inpw"
  - "_inpd"
apilocation: 
  - "msvcrt.dll"
  - "msvcr120.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "inpd"
  - "_inp"
  - "_inpw"
  - "_inpd"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função inp"
  - "Função inpw"
  - "portas, rotinas de e/s"
  - "Função inpd"
  - "Função _inp"
  - "Função _inpd"
  - "E/s [CRT], porta"
  - "Função _inpw"
ms.assetid: 5d9c2e38-fc85-4294-86d5-7282cc02d1b3
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _inp, _inpw, _inpd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Entradas de uma porta, um byte \(`_inp`\), uma palavra \(`_inpw`\), ou uma palavra dupla \(`_inpd`\).  
  
> [!IMPORTANT]
>  Essas funções são obsoletas. A partir do Visual Studio 2015, eles não estão disponíveis no CRT.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no tempo de execução do Windows. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _inp(   
   unsigned short port   
);  
unsigned short _inpw(   
   unsigned short port   
);  
unsigned long _inpd(   
   unsigned short port   
);  
```  
  
#### Parâmetros  
 `port`  
 Número da porta de e\/s.  
  
## Valor de retorno  
 As funções retornam o byte, palavra, ou palavras duplas leiam de `port`. Não há nenhum retorno de erro.  
  
## Comentários  
 O `_inp`, `_inpw`, e `_inpd` funções leiam um byte, uma palavra e uma palavra dupla, respectivamente, a porta de entrada especificada. O valor de entrada pode ser qualquer inteiro curto não assinado no intervalo de 0 a 65.535.  
  
 Como essas funções lida diretamente de uma porta de e\/s, elas não podem ser usadas no código do usuário no Windows NT, Windows 2000, Windows XP e Windows Server 2003.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_inp`|\< conio.h \>|  
|`_inpw`|\< conio.h \>|  
|`_inpd`|\< conio.h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Console e E\/S de porta](../c-runtime-library/console-and-port-i-o.md)   
 [\_outp, \_outpw, \_outpd](../Topic/_outp,%20_outpw,%20_outpd.md)