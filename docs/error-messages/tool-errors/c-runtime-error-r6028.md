---
title: Erro em tempo de execução de C R6028
ms.date: 11/04/2016
f1_keywords:
- R6028
helpviewer_keywords:
- R6028
ms.assetid: 81e99079-4388-4244-a4f7-4641c508871c
ms.openlocfilehash: 4992641c2456f0322b5c52eb907b159904e4c9f0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62380507"
---
# <a name="c-runtime-error-r6028"></a>Erro em tempo de execução de C R6028

não é possível inicializar o heap

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Há muitas razões possíveis para esse erro, mas geralmente é causado por uma condição de memória extremamente baixa, um bug no programa, ou por drivers de hardware com defeito.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para remover o novo aplicativo ou driver e tente novamente o seu aplicativo.
> - Verifique o site do fornecedor do hardware ou **Windows Update** na **painel de controle** para atualizações de software e driver.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre quando o sistema operacional não criou o pool de memória para o aplicativo. Especificamente, o CRT (C Runtime) chamou a função `HeapCreate` do Win32, que retornou NULL indicando uma falha.

Se esse erro ocorrer durante a inicialização do aplicativo, o sistema não poderá atender às solicitações do heap porque drivers com defeito foram carregados. Verifique o site do Windows Update ou do fornecedor de seu hardware para obter os drivers atualizados.