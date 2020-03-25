---
title: Erro em runtime de C R6030
ms.date: 11/04/2016
f1_keywords:
- R6030
helpviewer_keywords:
- R6030
ms.assetid: 0238a6c3-a033-4046-8adc-f8f99d961153
ms.openlocfilehash: 5d7160623d4e1eb83240c09e637c780fefc0d43d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197113"
---
# <a name="c-runtime-error-r6030"></a>Erro em runtime de C R6030

CRT não inicializado

> [!NOTE]
> Se você encontrar essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. Esse problema é causado com mais frequência por determinados programas de software de segurança, ou raramente, por um bug no programa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Seu software de segurança pode ter instruções específicas para atenuar esse problema. Verifique o site do fornecedor do software de segurança para obter detalhes. Como alternativa, verifique se há versões atualizadas do seu software de segurança ou tente um software de segurança diferente.
> - Use a página **aplicativos e recursos** ou **programas e recursos** no **painel de controle** para reparar ou reinstalar o programa.
> - Verifique **Windows Update** no **painel de controle** para obter atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Contate o fornecedor do aplicativo se o problema persistir.

**Informações para programadores**

Esse erro ocorrerá se você estiver usando o C Runtime (CRT), mas o código de inicialização do CRT não foi executado. É possível obter esse erro se a opção do vinculador [/entry](../../build/reference/entry-entry-point-symbol.md) for usada para substituir o endereço inicial padrão, geralmente **mainCRTStartup**, **wmainCRTStartup** para um console exe, **WinMainCRTStartup** ou **wWinMainCRTStartup** para um exe do Windows ou **_DllMainCRTStartup** para uma dll. A menos que uma das funções acima seja chamada na inicialização, o tempo de execução do C não será inicializado. Essas funções de inicialização são normalmente chamadas por padrão quando você vincula à biblioteca de tempo de execução C e usa os pontos de entrada normais **Main**, **wmain**, **WinMain**ou **DllMain** .

Também é possível obter esse erro quando outro programa usa técnicas de injeção de código para interceptar determinadas chamadas de biblioteca de DLL. Alguns programas de segurança intrusivos usam essa técnica. Em versões do Visual C++ antes do visual Studio 2015, é possível usar uma biblioteca CRT vinculada estaticamente para resolver o problema, mas isso não é recomendado por motivos de segurança e atualizações de aplicativos. Corrigir esse problema pode exigir ação do usuário final.
