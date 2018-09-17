---
title: -MANIFEST (criar manifesto do Assembly lado a lado) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.GenerateManifest
dev_langs:
- C++
helpviewer_keywords:
- -MANIFEST linker option
- /MANIFEST linker option
- MANIFEST linker option
ms.assetid: 98c52e1e-712c-4f49-b149-4d0a3501b600
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 468c41fe9cda752dd2727e6c9ec5d29781ef113d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710405"
---
# <a name="manifest-create-side-by-side-assembly-manifest"></a>/MANIFEST (criar manifesto de assembly lado a lado)

```
/MANIFEST[:{EMBED[,ID=#]|NO}]
```

## <a name="remarks"></a>Comentários

/Manifest Especifica que o vinculador deve criar um arquivo de manifesto lado a lado. Para obter mais informações sobre arquivos de manifesto, consulte [referência de arquivos de manifesto](/windows/desktop/SbsCs/manifest-files-reference).

O padrão é anexe.

O anexe: Inserir opção especifica que o vinculador deve incorporar o arquivo de manifesto da imagem como um recurso do tipo RT_MANIFEST. Opcional `ID` parâmetro é a ID de recurso a ser usado para o manifesto. Use um valor de 1 para um arquivo executável. Use um valor de 2 para uma DLL para habilitá-lo para especificar dependências privadas. Se o `ID` parâmetro não for especificado, o valor padrão é 2 se a opção /DLL estiver definida; caso contrário, o valor padrão é 1.

Começando com o Visual Studio 2008, os arquivos de manifesto para executáveis contêm uma seção que especifica as informações de controle de conta de usuário (UAC). Se você especificar anexe mas especificar nenhum deles [/MANIFESTUAC](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md) nem [/DLL](../../build/reference/dll-build-a-dll.md), um fragmento do UAC padrão que tem o conjunto de nível de UAC para *asInvoker* é inserida no manifesto. Para obter mais informações sobre os níveis de UAC, consulte [/MANIFESTUAC (insere informações UAC no manifesto)](../../build/reference/manifestuac-embeds-uac-information-in-manifest.md).

Para alterar o comportamento padrão para o UAC, siga um destes procedimentos:

- Especifique a opção /MANIFESTUAC e defina o nível UAC para o valor desejado.

- Ou especifique a opção /MANIFESTUAC: no se não desejar gerar um fragmento do UAC no manifesto.

Se você não especificar anexe, mas especificar [/MANIFESTDEPENDENCY](../../build/reference/manifestdependency-specify-manifest-dependencies.md) comentários, um arquivo de manifesto é criado. Um arquivo de manifesto não é criado se você especificar /MANIFEST:NO.

Se você especificar anexe, o nome do arquivo de manifesto é o mesmo que o nome do seu arquivo de saída, mas com. manifest acrescentado ao nome do arquivo. Por exemplo, se o nome do arquivo de saída for MyFile.exe, o nome do arquivo de manifesto é MyFile.exe.manifest.  Se você especificar /MANIFESTFILE:*nome*, o nome do manifesto é o que você especificar na *nome*.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **o arquivo de manifesto** página de propriedades.

1. Modificar a **gerar manifesto** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateManifest%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)