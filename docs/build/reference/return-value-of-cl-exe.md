---
title: "Valor de retorno de cl.exe | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, valor de retorno"
ms.assetid: 7c2d7f33-ee0d-4199-8ef4-75fe2b007670
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Valor de retorno de cl.exe
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O cl.exe retorna zero para êxito \(sem erros\) e um número diferente de zero para outros casos.  
  
 O valor de retorno do cl.exe pode ser útil se você estiver compilando a partir de um arquivo de script, powershell, .cmd ou .bat.  É recomendável capturar a saída do compilador caso haja erros ou avisos, para que você possa resolvê\-los.  
  
 Há muitos possíveis códigos de saída de erro para o cl.exe listá\-los.  Você pode procurar um código de erro nos arquivos winerror.h ou ntstatus.h incluídos no Kit de Desenvolvimento de Software do Windows no diretório %ProgramFiles\(x86\)%\\Windows Kits\\`version`\\Include\\shared\\.  Os códigos de erro retornados em decimal devem ser convertidos em hexadecimal para pesquisa.  Por exemplo, um código de erro \-1073741620 convertido em hexadecimal é 0xC00000CC.  Esse erro é encontrado no ntstatus.h, onde a mensagem correspondente é "Não é possível localizar o nome de recurso compartilhado especificado no servidor remoto.” Para baixar a lista de códigos de erro do Windows, consulte [&#91;MS\-ERREF&#93;: Windows Error Codes](http://msdn.microsoft.com/pt-br/1bc92ddf-b79e-413c-bbaa-99a5281a6c90).  
  
 Você também pode usar o utilitário de pesquisa de erro no Visual Studio para descobrir o que uma mensagem de erro do compilador significa.  Em um shell de comando do Visual Studio, digite **errlook.exe** para iniciar o utilitário; ou, na barra de menus do Visual Studio IDE, escolha **Ferramentas**, **Pesquisa de Erro**.  Digite o valor do erro para encontrar o texto descritivo associado ao erro.  Para obter mais informações, consulte [Referência de ERRLOOK](../../build/reference/errlook-reference.md).  
  
## Comentários  
 Este é um arquivo .bat de exemplo que usa o valor de retorno do cl.exe.  
  
```  
echo off  
cl /W4 t.cpp  
@if ERRORLEVEL == 0 (  
   goto good  
)  
  
@if ERRORLEVEL != 0 (  
   goto bad  
)  
  
:good  
   echo "clean compile"  
   echo %ERRORLEVEL%  
   goto end  
  
:bad  
   echo "error or warning"  
   echo %ERRORLEVEL%  
   goto end  
  
:end  
```  
  
## Consulte também  
 [Sintaxe da linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)