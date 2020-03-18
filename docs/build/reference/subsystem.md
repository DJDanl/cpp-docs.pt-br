---
title: /SUBSYSTEM
ms.date: 11/04/2016
f1_keywords:
- /subsystem_editbin
helpviewer_keywords:
- /SUBSYSTEM editbin option
- -SUBSYSTEM editbin option
- SUBSYSTEM editbin option
ms.assetid: 515e4cdf-3cc4-4659-8764-1f2757b49215
ms.openlocfilehash: 708bfcce3e6d6616116bcc08441f374b46914c82
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438867"
---
# <a name="subsystem"></a>/SUBSYSTEM

Especifica o ambiente de execução exigido pela imagem executável.

```
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|
        EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|
        NATIVE|POSIX|WINDOWS|WINDOWSCE}[,major[.minor]]
```

## <a name="remarks"></a>Comentários

Essa opção edita a imagem para indicar qual subsistema o sistema operacional deve invocar para execução.

Você pode especificar qualquer um dos seguintes subsistemas:

**BOOT_APPLICATION**<br/>
Um aplicativo que é executado no ambiente de inicialização do Windows. Para obter mais informações sobre aplicativos de inicialização, consulte [sobre o provedor WMI do BCD](/previous-versions/windows/desktop/bcd/about-bcd).

**MMC**<br/>
Um aplicativo de modo de caractere do Windows. O sistema operacional fornece um console para aplicativos de console.

**EFI_APPLICATION**<br/>
**EFI_BOOT_SERVICE_DRIVER**<br/>
**EFI_ROM**<br/>
**EFI_RUNTIME_DRIVER**<br/>
Imagem EFI (Extensible Firmware Interface)

As opções do subsistema EFI descrevem imagens executáveis que são executadas no ambiente da interface de firmware extensível. Esse ambiente normalmente é fornecido com o hardware e é executado antes do sistema operacional ser carregado. As principais diferenças entre os tipos de imagem EFI são o local da memória em que a imagem é carregada e a ação que é executada quando a chamada à imagem retorna. Uma imagem de EFI_APPLICATION é descarregada quando o controle retorna. Um EFI_BOOT_SERVICE_DRIVER ou EFI_RUNTIME_DRIVER será descarregado somente se o controle retornar com um código de erro. Uma imagem de EFI_ROM é executada a partir da ROM. Para obter mais informações, consulte as especificações no site do [Fórum de EFI unificada](https://www.uefi.org/) .

**FORMA**<br/>
Código que é executado sem um ambiente de subsistema — por exemplo, drivers de dispositivo de modo kernel e processos de sistema nativo. Essa opção geralmente é reservada para recursos de sistema do Windows.

**POSIX**<br/>
Um aplicativo que é executado no subsistema POSIX no Windows.

**WINDOWS**<br/>
Um aplicativo que é executado no ambiente gráfico do Windows. Isso inclui aplicativos de área de trabalho e aplicativos de Plataforma Universal do Windows (UWP).

**WINDOWSCE**<br/>
O subsistema WINDOWSCE indica que o aplicativo deve ser executado em um dispositivo que tenha uma versão do kernel Windows CE. As versões do kernel incluem PocketPC, Windows Mobile, Windows Phone 7, Windows CE V 1.0-6.0 R3 e Windows Embedded Compact 7.

Os valores opcionais `major` e `minor` especificam a versão mínima necessária do subsistema especificado:

- A parte de número inteiro do número de versão — a parte à esquerda da vírgula decimal — é representada por `major`.

- A parte fracionária do número de versão — a parte à direita do ponto decimal — é representada por `minor`.

- Os valores de `major` e `minor` devem ser de 0 a 65.535.

A escolha do subsistema afeta o endereço inicial padrão do programa. Para obter mais informações, consulte [/Entry (símbolo de ponto de entrada)](entry-entry-point-symbol.md), a opção linker/entry:*Function* .

Para obter mais informações, incluindo os valores mínimos e padrão para os números de versão principal e secundária para cada subsistema, consulte a opção vinculador [/Subsystem](subsystem-specify-subsystem.md) .

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
