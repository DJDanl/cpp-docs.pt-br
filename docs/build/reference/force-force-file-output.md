---
title: /FORCE (forçar saída de arquivo)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.ForceLink
- /force
helpviewer_keywords:
- FORCE linker option
- file output in linker
- /FORCE linker option
- -FORCE linker option
ms.assetid: b1e9a218-a5eb-4e60-a4a4-65b4be15e5da
ms.openlocfilehash: af7962a4b3b5805e7e0c4d59752254c8ade17f7b
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814300"
---
# <a name="force-force-file-output"></a>/FORCE (forçar saída de arquivo)

```
/FORCE:[MULTIPLE|UNRESOLVED]
```

## <a name="remarks"></a>Comentários

A opção /FORCE informa o vinculador para criar um arquivo válido .exe ou DLL mesmo que um símbolo esteja referenciado mas não definido ou está definido várias vezes.

A opção /FORCE pode ter um argumento opcional:

- Use /Force: Multiple para criar um arquivo de saída se o LINK ache mais de uma definição para um símbolo ou não.

- Use /FORCE: UNRESOLVED para criar um arquivo de saída se LINK localiza um símbolo indefinido. / FORÇAR: não RESOLVIDO será ignorado se o símbolo de ponto de entrada não for resolvido.

/Force sem argumentos implica múltiplo e não resolvido.

Um arquivo criado com essa opção pode não funcionar conforme o esperado. O vinculador não será vinculado incrementalmente quando a opção /FORCE é especificada.

Se um módulo for compilado com **/clr**, **/Force** não criará uma imagem.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
