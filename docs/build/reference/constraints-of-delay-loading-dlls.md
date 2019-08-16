---
title: Restrições de DLLs de carregamento do atraso
ms.date: 11/04/2016
helpviewer_keywords:
- constraints [C++], delayed loading of DLLs
- delayed loading of DLLs, constraints
- DLLs [C++], constraints
ms.assetid: 0097ff65-550f-4a4e-8ac3-39bf6404f926
ms.openlocfilehash: be5e5eb360f80e0b2ea9682f38f6787044cd3c63
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493067"
---
# <a name="constraints-of-delay-loading-dlls"></a>Restrições de DLLs de carregamento do atraso

Há restrições relativas ao carregamento atrasado de importações.

- Importações de dados não têm suporte. Uma solução alternativa é lidar explicitamente com a importação de dados por conta própria usando o `LoadLibrary` (ou o `GetModuleHandle` se souber que a ajuda de carregamento atrasado carregou a DLL) e o `GetProcAddress`.

- O carregamento atrasado de Kernel32.dll não tem suporte. Essa DLL é necessária para que as rotinas da ajuda de carregamento atrasado realize o carregamento atrasado.

- Não há suporte para a [Associação](binding-imports.md) de pontos de entrada encaminhados.

- O carregamento atrasado de uma DLL pode não resultar no mesmo comportamento do processo, caso haja inicializações por processo que ocorrem no ponto de entrada da DLL carregada com atraso. Outros casos incluem o TLS estático (armazenamento local de thread), declarado usando [_ declspec (thread)](../../cpp/thread.md), que não é tratado quando a dll `LoadLibrary`é carregada por meio de. TLS dinâmico, usando `TlsAlloc`, `TlsFree`, `TlsGetValue` e `TlsSetValue`, ainda está disponível para uso em DLLs estáticas ou com carregamento atrasado.

- Os ponteiros de função estática (global) devem ser reinicializados para as funções importadas após a primeira chamada para a função. Isso acontece porque o primeiro uso do ponteiro de função aponta para a conversão.

- Atualmente, não há como atrasar o carregamento apenas de procedimentos específicos de uma DLL ao usar o mecanismo de importação normal.

- Convenções de chamada personalizadas (como usar códigos e condição em arquiteturas x86) não têm suporte. Além disso, os registros de ponto flutuante não são salvos em nenhuma plataforma. Se suas rotinas de ajuda personalizada ou rotinas de gancho utilizarem tipos de ponto flutuante, elas precisam ser salvas completamente e restaurar o estado do ponto flutuante em máquinas com convenções de chamada de registro com parâmetros de ponto flutuante. Tome cuidado com o carregamento atrasado de CRT DLL caso você chame funções de CRT que consideram parâmetros de ponto flutuante em uma pilha do NDP (processador de dados numéricos) na função de ajuda.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)<br/>
[Função LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw)<br/>
[Função GetModuleHandle](/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew)<br/>
[Função GetProcAddress](/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress)<br/>
[Função TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)<br/>
[Função TlsFree](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree)<br/>
[Função TlsGetValue](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)<br/>
[Função TlsSetValue](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)
