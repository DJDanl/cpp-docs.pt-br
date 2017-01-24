---
title: "__getmainargs, __wgetmainargs | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "__wgetmainargs"
  - "__getmainargs"
apilocation: 
  - "msvcr100.dll"
  - "msvcrt.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcr90.dll"
  - "msvcr120.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__wgetmainargs"
  - "__getmainargs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__wgetmainargs"
  - "__getmainargs"
ms.assetid: f72f54eb-9509-4bdf-8752-40fc49055439
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __getmainargs, __wgetmainargs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Invoca a análise de linha de comando e copia os argumentos de volta de `main()` por ponteiros passados.  
  
## Sintaxe  
  
```cpp  
int __getmainargs(  
    int * _Argc,   
   char *** _Argv,   
   char *** _Env,   
   int _DoWildCard,  
_startupinfo * _StartInfo);  
  
 int __wgetmainargs (  
   int *_Argc,  
   wchar_t ***_Argv,  
   wchar_t ***_Env,  
   int _DoWildCard,  
   _startupinfo * _StartInfo)  
  
```  
  
#### Parâmetros  
 `_Argc`  
 Um inteiro que contém o número de argumentos a seguir em `argv`.  O parâmetro de `argc` sempre é maior ou igual a 1.  
  
 `_Argv`  
 Uma matriz de cadeias de caracteres com encerradas que representam os argumentos de linha de comando inserido pelo usuário do programa.  Por convenção, `argv[0]` é o comando com que o programa é chamado, argv \[1\] é o primeiro argumento de linha de comando, e assim por diante, até o argv \[\] argc, que é sempre NULL.  O primeiro argumento de linha de comando é sempre `argv[1]` e o último é `argv[argc – 1]`.  
  
 `_Env`  
 Uma matriz de cadeias de caracteres que representam as variáveis definidas no ambiente do usuário.  Esta matriz é finalizada por uma entrada NULL.  
  
 `_DoWildCard`  
 Um inteiro que se definido como 1 se expande os curingas os argumentos de linha de comando, ou se definido como 0 não fará nada.  
  
 `_StartInfo`  
 Outras informações a ser passada para a DLL de CRT.  
  
## Valor de Retorno  
 0 se bem\-sucedido; um valor negativo se bem\-sucedida.  
  
## Comentários  
 Use `__getmainargs` em plataformas não todo de caracteres e, `__wgetmainargs` em plataformas de ampla caractere Unicode \(\).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_\_getmainargs|internal.h|  
|\_\_wgetmainargs|internal.h|