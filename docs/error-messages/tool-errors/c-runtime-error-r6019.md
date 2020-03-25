---
title: Erro em runtime de C R6019
ms.date: 11/04/2016
f1_keywords:
- R6019
helpviewer_keywords:
- R6019
ms.assetid: 8129923e-7db2-40ee-9602-def9365f8d28
ms.openlocfilehash: b647825b7e856be9dc51a5a652be87a4cc6d0e23
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197256"
---
# <a name="c-runtime-error-r6019"></a>Erro em runtime de C R6019

Não é possível abrir o dispositivo de console

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque tentou acessar o console, mas não tinha permissão suficiente. Há várias razões possíveis para esse erro, mas isso geralmente ocorre porque o programa deve ser executado como administrador ou há um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Execute o programa como administrador.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorre porque o aplicativo chamou uma função de console, mas o sistema operacional não concedeu acesso ao console. Exceto no modo de depuração, as funções de console geralmente não são permitidas em aplicativos Microsoft Store. Se seu aplicativo exigir privilégios de administrador para ser executado, verifique se ele está instalado para ser executado como administrador por padrão.
