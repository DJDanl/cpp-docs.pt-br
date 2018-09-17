---
title: -SUBSYSTEM (especificar subsistema) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /subsystem
- VC.Project.VCLinkerTool.SubSystem
- VC.Project.VCLinkerTool.SubSystemVersion
dev_langs:
- C++
helpviewer_keywords:
- /SUBSYSTEM linker option
- SUBSYSTEM linker option
- -SUBSYSTEM linker option
- subsystem specifications
ms.assetid: d7b133cf-cf22-4da8-ab46-6552702c0b9b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75e4612104fdc57fd1442f1a35efbf317a60310d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717087"
---
# <a name="subsystem-specify-subsystem"></a>/SUBSYSTEM (especificar subsistema)

```
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|
            EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|NATIVE|
            POSIX|WINDOWS)
            [,major[.minor]]
```

## <a name="arguments"></a>Arguments

**BOOT_APPLICATION**<br/>
Um aplicativo que é executado no ambiente de inicialização do Windows. Para obter mais informações sobre aplicativos de inicialização, consulte [BCD sobre](/previous-versions/windows/desktop/bcd/about-bcd).

**CONSOLE**<br/>
Aplicativo de modo caractere Win32. O sistema operacional fornece um console para aplicativos de console. Se `main` ou `wmain` está definido para código nativo, `int main(array<String ^> ^)` está definido para código gerenciado, ou você compilar o aplicativo completamente usando `/clr:safe`, CONSOLE é o padrão.

**EFI_APPLICATION**<br/>
**EFI_BOOT_SERVICE_DRIVER**<br/>
**EFI_ROM**<br/>
**EFI_RUNTIME_DRIVER**<br/>
Os subsistemas de Interface de Firmware extensível. Consulte a especificação de EFI para obter mais informações. Para obter exemplos, consulte o site da Intel. A versão mínima de versão e o padrão é 1.0.

**NATIVO**<br/>
Drivers do modo kernel para Windows NT. Essa opção normalmente é reservada para componentes de sistema do Windows. Se [/driver: WDM](../../build/reference/driver-windows-nt-kernel-mode-driver.md) for especificado, NATIVE é o padrão.

**POSIX**<br/>
Aplicativo que é executado com o subsistema POSIX no Windows NT.

**WINDOWS**<br/>
Aplicativo não exige um console, provavelmente porque cria suas próprias janelas para interação com o usuário. Se `WinMain` ou `wWinMain` está definido para código nativo, ou `WinMain(HISTANCE *, HINSTANCE *, char *, int)` ou `wWinMain(HINSTANCE *, HINSTANCE *, wchar_t *, int)` é definido para código gerenciado, o WINDOWS é o padrão.

*principais* e *secundária*<br/>
(Opcional) Especifique a versão mínima necessária do subsistema. Os argumentos são números decimais no intervalo de 0 a 65.535. Consulte os Comentários para obter mais informações. Há não há limites superiores para números de versão.

## <a name="remarks"></a>Comentários

O **/SUBSYSTEM** opção especifica o ambiente para o executável.

A escolha do subsistema afeta o símbolo de ponto de entrada (ou a função de ponto de entrada) que o vinculador selecionará.

O mínimo opcional e o padrão *principais* e *secundárias* números de versão para os subsistemas são da seguinte maneira.

|subsistema|Mínimo|Padrão|
|---------------|-------------|-------------|
|BOOT_APPLICATION|1.0|1.0|
|CONSOLE|5.01 (x86) 5.02 (x64) 6.02 (ARM)|6.00 (x86, x64) 6.02 (ARM)|
|WINDOWS|5.01 (x86) 5.02 (x64) 6.02 (ARM)|6.00 (x86, x64) 6.02 (ARM)|
|NATIVO (com o DRIVER: WDM)|1,00 (x86) 1.10 (x64, ARM)|1,00 (x86) 1.10 (x64, ARM)|
|NATIVO (sem /driver: WDM)|4.00 (x86) 5.02 (x64) 6.02 (ARM)|4.00 (x86) 5.02 (x64) 6.02 (ARM)|
|POSIX|1.0|19.90|
|EFI_APPLICATION, EFI_BOOT_SERVICE_DRIVER, EFI_ROM, EFI_RUNTIME_DRIVER|1.0|1.0|

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Selecione a pasta do vinculador.

1. Selecione o **sistema** página de propriedades.

1. Modificar o `SubSystem` propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SubSystem%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)