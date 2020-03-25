---
title: Erro em runtime de C R6026
ms.date: 11/04/2016
f1_keywords:
- R6026
helpviewer_keywords:
- R6026
ms.assetid: 7ea751f8-fc20-46ab-99ef-84c95ca0b6b4
ms.openlocfilehash: c0f2f6371933d118bf52328726fb2c68907c2666
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197178"
---
# <a name="c-runtime-error-r6026"></a>Erro em runtime de C R6026

Não há espaço suficiente para a inicialização do stdio

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Há vários motivos possíveis para esse erro, mas geralmente ele é causado por uma condição de memória extremamente baixa. Ele também pode ser causado por um bug no aplicativo, por causa da corrupção das bibliotecas C++ visuais que ele usa ou por um driver.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Se o aplicativo estava funcionando antes de uma instalação recente de outro aplicativo ou driver, use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para remover o novo aplicativo ou driver e tente o aplicativo novamente.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft C++ Visual redistribuível.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorre quando não há memória livre suficiente disponível para inicializar o suporte de e/s padrão no tempo de execução C. Esse erro geralmente ocorre na inicialização do aplicativo. Verifique se o aplicativo e os drivers e DLLs que ele carrega não corrompem o heap na inicialização.
