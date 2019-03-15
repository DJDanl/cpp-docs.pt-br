---
title: /SUBSYSTEM
ms.date: 11/04/2016
f1_keywords:
- /subsystem
helpviewer_keywords:
- /SUBSYSTEM editbin option
- -SUBSYSTEM editbin option
- SUBSYSTEM editbin option
ms.assetid: 515e4cdf-3cc4-4659-8764-1f2757b49215
ms.openlocfilehash: b13313d57226719086cb73584543488f842057c1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820488"
---
# <a name="subsystem"></a>/SUBSYSTEM

Especifica o ambiente de execução que é exigido pela imagem executável.

```
/SUBSYSTEM:{BOOT_APPLICATION|CONSOLE|EFI_APPLICATION|
        EFI_BOOT_SERVICE_DRIVER|EFI_ROM|EFI_RUNTIME_DRIVER|
        NATIVE|POSIX|WINDOWS|WINDOWSCE}[,major[.minor]]
```

## <a name="remarks"></a>Comentários

Essa opção edita a imagem para indicar que o subsistema do sistema operacional deve invocar para execução.

Você pode especificar qualquer um dos seguintes subsistemas:

**BOOT_APPLICATION**<br/>
Um aplicativo que é executado no ambiente de inicialização do Windows. Para obter mais informações sobre aplicativos de inicialização, consulte [sobre o provedor WMI BCD](/previous-versions/windows/desktop/bcd/about-bcd).

**CONSOLE**<br/>
Um aplicativo de modo de caractere do Windows. O sistema operacional fornece um console para aplicativos de console.

**EFI_APPLICATION**<br/>
**EFI_BOOT_SERVICE_DRIVER**<br/>
**EFI_ROM**<br/>
**EFI_RUNTIME_DRIVER**<br/>
Imagem do Extensible Firmware Interface (EFI)

As opções do subsistema EFI descrevem imagens executáveis que são executados no ambiente de Interface de Firmware extensível. Esse ambiente normalmente é fornecido com o hardware e é executado antes que o sistema operacional é carregado. As principais diferenças entre tipos de imagem do EFI são o local da memória que a imagem é carregada e a ação que é executada quando a chamada para a imagem retorna. Uma imagem EFI_APPLICATION é descarregada quando o controle retorna. Um EFI_BOOT_SERVICE_DRIVER ou um EFI_RUNTIME_DRIVER é descarregado somente se o controle retorna com um código de erro. Uma imagem EFI_ROM é executada de ROM. Para obter mais informações, consulte as especificações sobre o [Unified EFI Forum](http://www.uefi.org/) site.

**NATIVO**<br/>
Código que é executado sem um ambiente de subsistema — por exemplo, drivers de dispositivo de modo kernel e processos do sistema nativo. Essa opção normalmente é reservada para recursos de sistema do Windows.

**POSIX**<br/>
Um aplicativo que é executado no subsistema POSIX no Windows.

**WINDOWS**<br/>
Um aplicativo que é executado no ambiente gráfico do Windows. Isso inclui os aplicativos da área de trabalho e aplicativos de plataforma Universal do Windows (UWP).

**WINDOWSCE**<br/>
O subsistema WINDOWSCE indica que o aplicativo destina-se para ser executado em um dispositivo que tem uma versão do kernel do Windows CE. Versões do kernel incluem o PocketPC, Windows Mobile, Windows Phone 7, Windows CE V1.0-6.0R3 e Windows Embedded Compact 7.

Opcional `major` e `minor` valores especificam a versão mínima necessária do subsistema especificado:

- A parte de número inteiro do número de versão — a parte à esquerda do ponto decimal — é representada por `major`.

- A parte fracionária do número de versão — a parte à direita do ponto decimal — é representada por `minor`.

- Os valores de `major` e `minor` deve ser de 0 a 65.535.

A escolha do subsistema afeta o endereço inicial padrão para o programa. Para obter mais informações, consulte [/ENTRY (símbolo de ponto de entrada)](entry-entry-point-symbol.md), o vinculador /ENTRY:*função* opção.

Para obter mais informações, incluindo os valores mínimo e padrão para os números de versão principal e secundária para cada subsistema, consulte o [/SUBSYSTEM](subsystem-specify-subsystem.md) a opção de vinculador.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
