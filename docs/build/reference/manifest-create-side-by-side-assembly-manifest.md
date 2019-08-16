---
title: /MANIFEST (criar manifesto de assembly lado a lado)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.GenerateManifest
helpviewer_keywords:
- -MANIFEST linker option
- /MANIFEST linker option
- MANIFEST linker option
ms.assetid: 98c52e1e-712c-4f49-b149-4d0a3501b600
ms.openlocfilehash: ea58b43accdd854665fad3b70d7aecbc9eaa0f9e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492789"
---
# <a name="manifest-create-side-by-side-assembly-manifest"></a>/MANIFEST (criar manifesto de assembly lado a lado)

```
/MANIFEST[:{EMBED[,ID=#]|NO}]
```

## <a name="remarks"></a>Comentários

/MANIFEST especifica que o vinculador deve criar um arquivo de manifesto lado a lado. Para obter mais informações sobre arquivos de manifesto, consulte [referência de arquivos de manifesto](/windows/win32/SbsCs/manifest-files-reference).

O padrão é/MANIFEST.

A opção/MANIFEST: EMBED especifica que o vinculador deve inserir o arquivo de manifesto na imagem como um recurso do tipo RT_MANIFEST. O parâmetro `ID` opcional é a ID de recurso a ser usada para o manifesto. Use um valor de 1 para um arquivo executável. Use um valor de 2 para uma DLL para habilitá-lo a especificar dependências privadas. Se o `ID` parâmetro não for especificado, o valor padrão será 2 se a opção/DLL for definida; caso contrário, o valor padrão será 1.

A partir do Visual Studio 2008, os arquivos de manifesto para executáveis contêm uma seção que especifica informações de controle de conta de usuário (UAC). Se você especificar/MANIFEST, mas não especificar [/MANIFESTUAC](manifestuac-embeds-uac-information-in-manifest.md) nem [/dll](dll-build-a-dll.md), um fragmento UAC padrão que tenha o nível de UAC definido como *asInvoker* será inserido no manifesto. Para obter mais informações sobre os níveis de UAC, consulte [/MANIFESTUAC (incorpora informações de UAC no manifesto)](manifestuac-embeds-uac-information-in-manifest.md).

Para alterar o comportamento padrão do UAC, siga um destes:

- Especifique a opção/MANIFESTUAC e defina o nível de UAC para o valor desejado.

- Ou especifique a opção/MANIFESTUAC: NO se você não quiser gerar um fragmento UAC no manifesto.

Se você não especificar/MANIFEST, mas especificar comentários [/MANIFESTDEPENDENCY](manifestdependency-specify-manifest-dependencies.md) , um arquivo de manifesto será criado. Um arquivo de manifesto não será criado se você especificar/MANIFEST: NO.

Se você especificar/MANIFEST, o nome do arquivo de manifesto será o mesmo que o nome do arquivo de saída, mas com. manifest anexado ao nome do arquivo. Por exemplo, se o nome do arquivo de saída for MyFile. exe, o nome do arquivo de manifesto será MyFile. exe. manifest.  Se você especificar/MANIFESTFILE:*Name*, o nome do manifesto será o que você especificar no *nome*.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **Vinculador**.

1. Selecione a página de propriedades do **arquivo de manifesto** .

1. Modifique a propriedade **gerar manifesto** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateManifest%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
