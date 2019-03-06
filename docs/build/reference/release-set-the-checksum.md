---
title: /RELEASE (definir a soma de verificação)
ms.date: 11/04/2016
f1_keywords:
- /release
- VC.Project.VCLinkerTool.SetChecksum
helpviewer_keywords:
- -RELEASE linker option
- /RELEASE linker option
- checksum setting
- RELEASE linker option
ms.assetid: 93bcadf4-29ac-4824-914b-6997e3751d22
ms.openlocfilehash: 9192768f711da721cfef65314573d78caa8c2442
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426635"
---
# <a name="release-set-the-checksum"></a>/RELEASE (definir a soma de verificação)

```
/RELEASE
```

## <a name="remarks"></a>Comentários

A opção /RELEASE define a soma de verificação no cabeçalho de um arquivo .exe.

O sistema operacional exige a soma de verificação para drivers de dispositivo. Defina a soma de verificação para versões de lançamento, drivers de dispositivo para garantir a compatibilidade com futuros sistemas operacionais.

A opção /RELEASE é definida por padrão quando o [/Subsystem: Native](../../build/reference/subsystem-specify-subsystem.md) opção for especificada.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **definir soma de verificação** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SetChecksum%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
