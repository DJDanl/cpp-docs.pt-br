---
title: /WINMDFILE (Especifica o arquivo winmd)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.GenerateWindowsMetadataFile
ms.assetid: 062b41b3-14d6-432c-a361-fdb66e918931
ms.openlocfilehash: 5d24d1d1aad8442f549dcb1aa4bd6414070c282c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316477"
---
# <a name="winmdfile-specify-winmd-file"></a>/WINMDFILE (Especifica o arquivo winmd)

Especifica o nome de arquivo para o arquivo de saída de metadados de tempo de execução do Windows (. winmd) que é gerado pelo [/WINMD](winmd-generate-windows-metadata.md) a opção de vinculador.

```
/WINMDFILE:filename
```

## <a name="remarks"></a>Comentários

Use o valor especificado na `filename` para substituir o nome do arquivo. winmd padrão (`binaryname`. winmd). Observe que você não adicionar ". winmd" ao `filename`.  Se vários valores são listados na **/WINMDFILE** linha de comando, o último terá precedência.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **vinculador** pasta.

1. Selecione o **metadados do Windows** página de propriedades.

1. No **arquivo de metadados do Windows** , digite o local do arquivo.

## <a name="see-also"></a>Consulte também

[/WINMD (gerar metadados do Windows)](winmd-generate-windows-metadata.md)<br/>
[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
