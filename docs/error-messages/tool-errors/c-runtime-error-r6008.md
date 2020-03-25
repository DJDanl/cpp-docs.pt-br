---
title: Erro em runtime de C R6008
ms.date: 11/04/2016
f1_keywords:
- R6008
helpviewer_keywords:
- R6008
ms.assetid: f0f304fc-709a-4843-bc7e-bad1ae0d1649
ms.openlocfilehash: 214b6548cc7a3b880223503c2f3e9222d64212ca
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197387"
---
# <a name="c-runtime-error-r6008"></a>Erro em runtime de C R6008

Não há espaço suficiente para argumentos

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há vários motivos possíveis para esse erro, mas, muitas vezes, é causado por uma condição de memória extremamente baixa, muita memória usada por variáveis de ambiente ou um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Reduza o número e o tamanho dos argumentos de linha de comando para o aplicativo.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Havia memória suficiente para carregar o programa, mas não há memória suficiente para criar a matriz **argv** . Isso pode ser causado por condições de memória extremamente baixas ou por uso de variável de ambiente ou de linhas de comando incomuns. Considere uma das seguintes soluções:

- Aumente a quantidade de memória disponível para o programa.

- Reduza o número e o tamanho dos argumentos de linha de comando.

- Reduza o tamanho do ambiente removendo variáveis desnecessárias.
