---
title: Aviso LNK4210 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4210
helpviewer_keywords:
- LNK4210
ms.assetid: db48cff8-a2be-4a77-8d03-552b42c228fa
ms.openlocfilehash: 75376129ce0033c717a4da3074cee9de132d357d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395060"
---
# <a name="linker-tools-warning-lnk4210"></a>Aviso LNK4210 (Ferramentas de Vinculador)

> seção *seção* existe; lá pode ser sem tratamento inicializadores e terminadores estáticos

## <a name="remarks"></a>Comentários

Algum código introduziu inicializadores e terminadores estáticos, mas o código de inicialização de biblioteca VCRuntime ou seu equivalente (que precisa para executar os inicializadores e terminadores estáticos) não é executado quando o aplicativo é iniciado. Aqui estão alguns exemplos de código que requer inicializadores e terminadores estáticos:

- Variável de classe global com um construtor, destruidor ou tabela de função virtual.

- Variável global inicializado com uma constante de tempo de compilação não.

Para corrigir esse problema, tente um destes procedimentos:

- Remova todo o código com inicializadores estáticos.

- Não use [/NOENTRY](../../build/reference/noentry-no-entry-point.md). Depois de remover /NOENTRY, talvez você também precise remover [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) de sua linha de comando do vinculador.

- Se sua compilação usa /MT, adicione libcmt. lib, libvcruntime e libucrt para sua linha de comando do vinculador. Se sua compilação usa /MTd, adicione lib, Libcmtd. lib e vcruntimed.

- Ao mover do /clr: pure compilação para /clr, remover o [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção da linha de vinculador. Isso permite que a inicialização do CRT e inicializadores estáticos a ser executado na inicialização do aplicativo. O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

O [/GS](../../build/reference/gs-buffer-security-check.md) opção de compilador requer inicialização pelo `__security_init_cookie` função. Essa inicialização é fornecida por padrão em que o código de inicialização da biblioteca VCRuntime é executado em `_DllMainCRTStartup`.

- Se seu projeto é compilado usando /ENTRY e /ENTRY é passado a uma função diferente de `_DllMainCRTStartup`, a função deve chamar `_CRT_INIT` para inicializar o CRT. Essa chamada sozinha não é suficiente se sua DLL usa /GS, requer inicializadores estáticos ou é chamado no contexto de código do MFC ou ATL. Ver [DLLs e Visual C++ comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/linking.md)
