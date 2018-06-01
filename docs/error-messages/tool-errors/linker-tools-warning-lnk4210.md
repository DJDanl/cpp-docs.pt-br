---
title: Aviso LNK4210 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4210
dev_langs:
- C++
helpviewer_keywords:
- LNK4210
ms.assetid: db48cff8-a2be-4a77-8d03-552b42c228fa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8700d9ad8eeef177de2f70f616cb0c06ba50670
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34703672"
---
# <a name="linker-tools-warning-lnk4210"></a>Aviso LNK4210 (Ferramentas de Vinculador)

> seção *seção* existe; há pode ser sem tratamento inicializadores e terminadores estáticos

## <a name="remarks"></a>Comentários

Algum código introduziu inicializadores e terminadores estáticos, mas o código de inicialização de biblioteca VCRuntime ou seu equivalente (que precisa executar os inicializadores e terminadores estáticos) não é executado quando o aplicativo for iniciado. Aqui estão alguns exemplos de código que requer inicializadores e terminadores estáticos:

- Variável global de classe com um construtor, destruidor ou tabela de função virtual.

- Variável global inicializado com uma constante de tempo de compilação não.

Para corrigir esse problema, tente um destes procedimentos:

- Remova todo o código com inicializadores estáticos.

- Não use [/NOENTRY](../../build/reference/noentry-no-entry-point.md). Depois de remover /NOENTRY, você também terá que remover [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) da linha de comando do vinculador.

- Se sua compilação usa /MT, adicione libcmt.lib, libvcruntime.lib e libucrt.lib para a linha de comando do vinculador. Se sua compilação usa /MTd, adicione libcmtd.lib, vcruntimed.lib e libucrtd.lib.

- Ao mover de /clr: pure compilação para /clr, remova o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção da linha de vinculador. Isso permite a inicialização do CRT e permite que os inicializadores estáticos ser executado na inicialização do aplicativo. O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

O [/GS](../../build/reference/gs-buffer-security-check.md) opção de compilador requer inicialização pelo `__security_init_cookie` função. Essa inicialização é fornecida por padrão no código de inicialização biblioteca VCRuntime que é executado em `_DllMainCRTStartup`.

- Se o projeto é compilado usando /ENTRY e /ENTRY é passado a uma função diferente de `_DllMainCRTStartup`, deve chamar a função `_CRT_INIT` para inicializar o CRT. Essa chamada sozinha não é suficiente se sua DLL usa /GS, requer os inicializadores estáticos ou é chamado no contexto de código MFC ou do ATL. Consulte [DLLs e Visual C++ comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
