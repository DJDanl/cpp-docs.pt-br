---
title: "Restri&#231;&#245;es de DLLs de carregamento do atraso | Microsoft Docs"
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
  - "restrições [C++], carregamento atrasado de DLLs"
  - "carregamento atrasado de DLLs, restrições"
  - "DLLs [C++], restrições"
ms.assetid: 0097ff65-550f-4a4e-8ac3-39bf6404f926
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Restri&#231;&#245;es de DLLs de carregamento do atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Há restrições relativas ao carregamento atrasado de importações.  
  
-   Importações de dados não têm suporte.  Uma solução alternativa é lidar explicitamente com a importação de dados por conta própria usando o `LoadLibrary` \(ou o `GetModuleHandle` se souber que a ajuda de carregamento atrasado carregou a DLL\) e o `GetProcAddress`.  
  
-   O carregamento atrasado de Kernel32.dll não tem suporte.  Essa DLL é necessária para que as rotinas da ajuda de carregamento atrasado realize o carregamento atrasado.  
  
-   [A associação](../../build/reference/binding-imports.md) de pontos de entrada que são encaminhados não tem suporte.  
  
-   O carregamento atrasado de uma DLL pode não resultar no mesmo comportamento do processo, caso haja inicializações por processo que ocorrem no ponto de entrada da DLL carregada com atraso.  Outros casos incluem TLS \(armazenamento local de thread\) estático, declarado usando [\_\_declspec\(thread\)](../../cpp/thread.md), que não é tratado quando a DLL é carregada por `LoadLibrary`.  TLS dinâmico, usando `TlsAlloc`, `TlsFree`, `TlsGetValue` e `TlsSetValue`, ainda está disponível para uso em DLLs estáticas ou com carregamento atrasado.  
  
-   Os ponteiros de função estática \(global\) devem ser reinicializados para as funções importadas após a primeira chamada para a função.  Isso acontece porque o primeiro uso do ponteiro de função aponta para a conversão.  
  
-   Atualmente, não há como atrasar o carregamento apenas de procedimentos específicos de uma DLL ao usar o mecanismo de importação normal.  
  
-   Convenções de chamada personalizadas \(como usar códigos e condição em arquiteturas x86\) não têm suporte.  Além disso, os registros de ponto flutuante não são salvos em nenhuma plataforma.  Se suas rotinas de ajuda personalizada ou rotinas de gancho utilizarem tipos de ponto flutuante, elas precisam ser salvas completamente e restaurar o estado do ponto flutuante em máquinas com convenções de chamada de registro com parâmetros de ponto flutuante.  Tome cuidado com o carregamento atrasado de CRT DLL caso você chame funções de CRT que consideram parâmetros de ponto flutuante em uma pilha do NDP \(processador de dados numéricos\) na função de ajuda.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)   
 [Função LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175.aspx)   
 [Função GetModuleHandle](http://msdn.microsoft.com/library/windows/desktop/ms683199.aspx)   
 [Função GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212.aspx)   
 [Função TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801.aspx)   
 [Função TlsFree](http://msdn.microsoft.com/library/windows/desktop/ms686804.aspx)   
 [Função TlsGetValue](http://msdn.microsoft.com/library/windows/desktop/ms686812.aspx)   
 [Função TlsSetValue](http://msdn.microsoft.com/library/windows/desktop/ms686818.aspx)