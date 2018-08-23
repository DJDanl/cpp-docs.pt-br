---
title: Restrições de DLLs de carregamento com atraso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- constraints [C++], delayed loading of DLLs
- delayed loading of DLLs, constraints
- DLLs [C++], constraints
ms.assetid: 0097ff65-550f-4a4e-8ac3-39bf6404f926
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 40774d6307eb9b423ebd4fd303a48acbd87eda24
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42572329"
---
# <a name="constraints-of-delay-loading-dlls"></a>Restrições de DLLs de carregamento do atraso
Há restrições relativas ao carregamento atrasado de importações.  
  
-   Importações de dados não têm suporte. Uma solução alternativa é lidar explicitamente com a importação de dados por conta própria usando o `LoadLibrary` (ou o `GetModuleHandle` se souber que a ajuda de carregamento atrasado carregou a DLL) e o `GetProcAddress`.  
  
-   O carregamento atrasado de Kernel32.dll não tem suporte. Essa DLL é necessária para que as rotinas da ajuda de carregamento atrasado realize o carregamento atrasado.  
  
-   [Associação](../../build/reference/binding-imports.md) da entrada de pontos que são encaminhados não tem suporte.  
  
-   O carregamento atrasado de uma DLL pode não resultar no mesmo comportamento do processo, caso haja inicializações por processo que ocorrem no ponto de entrada da DLL carregada com atraso. Outros casos incluem estático TLS (armazenamento local de thread), declarado usando [__declspec(thread)](../../cpp/thread.md), que não é tratado quando a DLL é carregada por meio de `LoadLibrary`. TLS dinâmico, usando `TlsAlloc`, `TlsFree`, `TlsGetValue` e `TlsSetValue`, ainda está disponível para uso em DLLs estáticas ou com carregamento atrasado.  
  
-   Os ponteiros de função estática (global) devem ser reinicializados para as funções importadas após a primeira chamada para a função. Isso acontece porque o primeiro uso do ponteiro de função aponta para a conversão.  
  
-   Atualmente, não há como atrasar o carregamento apenas de procedimentos específicos de uma DLL ao usar o mecanismo de importação normal.  
  
-   Convenções de chamada personalizadas (como usar códigos e condição em arquiteturas x86) não têm suporte. Além disso, os registros de ponto flutuante não são salvos em nenhuma plataforma. Se suas rotinas de ajuda personalizada ou rotinas de gancho utilizarem tipos de ponto flutuante, elas precisam ser salvas completamente e restaurar o estado do ponto flutuante em máquinas com convenções de chamada de registro com parâmetros de ponto flutuante. Tome cuidado com o carregamento atrasado de CRT DLL caso você chame funções de CRT que consideram parâmetros de ponto flutuante em uma pilha do NDP (processador de dados numéricos) na função de ajuda.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)   
 [Função LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175.aspx)   
 [Função GetModuleHandle](http://msdn.microsoft.com/library/windows/desktop/ms683199.aspx)   
 [Função GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212.aspx)   
 [Função TlsAlloc](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc)   
 [Função TlsFree](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsfree)   
 [Função TlsGetValue](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)   
 [Função TlsSetValue](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)