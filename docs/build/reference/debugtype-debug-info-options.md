---
title: /DEBUGTYPE (opções de informações de depuração)
ms.date: 11/04/2016
f1_keywords:
- /debugtype
helpviewer_keywords:
- /DEBUGTYPE linker option
- DEBUGTYPE linker option
- -DEBUGTYPE linker option
ms.assetid: 1ddcb718-7fec-4f92-a319-3f70f04fe742
ms.openlocfilehash: f730e485b7dc29cb8fe98bdcc7ea50f5e8c622d7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676987"
---
# <a name="debugtype-debug-info-options"></a>/DEBUGTYPE (opções de informações de depuração)

A opção /DEBUGTYPE Especifica os tipos de informações de depuração geradas pela opção /DEBUG.

```
/DEBUGTYPE:[CV | PDATA | FIXUP]
```

## <a name="arguments"></a>Arguments

**VC**<br/>
Informa o vinculador para emitir informações de depuração para símbolos, números de linha e outras informações de compilação do objeto no arquivo PDB. Por padrão, essa opção é habilitada quando **/Debug** for especificado e **/DEBUGTYPE** não for especificado.

**PDATA**<br/>
Instrui o vinculador a adicionar entradas de registro. pData e. XData para as informações de fluxo de depuração no arquivo PDB. Por padrão, essa opção é habilitada quando tanto o **/Debug** e **/DRIVER** opções forem especificadas. Se **/DEBUGTYPE:PDATA** é especificado por si só, o vinculador inclui automaticamente os símbolos no arquivo PDB de depuração. Se **/DEBUGTYPE:PDATA, correção** for especificado, o vinculador não incluir símbolos no arquivo PDB de depuração.

**CORREÇÃO**<br/>
Instrui o vinculador a adicionar entradas de tabela de realocação para as informações de fluxo de depuração no arquivo PDB. Por padrão, essa opção é habilitada quando tanto o **/Debug** e **/Profile** opções forem especificadas. Se **/DEBUGTYPE:FIXUP** ou **/DEBUGTYPE:FIXUP, PDATA** for especificado, o vinculador não incluir símbolos no arquivo PDB de depuração.

Argumentos a serem **/DEBUGTYPE** podem ser combinadas em qualquer ordem, separando-os com uma vírgula. O **/DEBUGTYPE** opção e seus argumentos não diferenciam maiusculas de minúsculas.

## <a name="remarks"></a>Comentários

Use o **/DEBUGTYPE** opção para especificar a inclusão de informações de cabeçalho realocação tabela dados ou registro. pData e. XData no fluxo de depuração. Isso faz com que o vinculador a incluir informações sobre o código de modo de usuário que é visível em um depurador de kernel quando significativas no código do modo kernel. Para disponibilizar os símbolos de depuração quando **correção** é especificado, inclua o **CV** argumento.

Para depurar o código no modo de usuário, que é típico para aplicativos, o **/DEBUGTYPE** opção não é necessária. Por padrão, as opções de compilador que especificam a depuração de saída ([/Z7, /Zi, /ZI](../../build/reference/z7-zi-zi-debug-information-format.md)) emite todas as informações necessárias pelo Visual Studio do depurador. Use **/DEBUGTYPE:PDATA** ou **/debugtype: CV, PDATA, correção** para depurar o código que combina os componentes do modo de usuário e o modo de kernel, como um aplicativo de configuração para um driver de dispositivo. Para obter mais informações sobre os depuradores de modo kernel, consulte [depuração ferramentas para Windows (WinDbg, KD, CDB, NTSD.)](/windows-hardware/drivers/debugger/index)

## <a name="see-also"></a>Consulte também

[/DEBUG (gerar informações de depuração)](../../build/reference/debug-generate-debug-info.md)<br/>
[/DRIVER (driver de modo de kernel do Windows NT)](../../build/reference/driver-windows-nt-kernel-mode-driver.md)<br/>
[/PROFILE (criador de perfil de ferramentas de desempenho)](../../build/reference/profile-performance-tools-profiler.md)<br/>
[Ferramentas de depuração para Windows (WinDbg, KD, CDB, NTSD.)](/windows-hardware/drivers/debugger/index)