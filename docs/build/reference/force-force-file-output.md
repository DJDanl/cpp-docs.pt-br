---
title: /FORCE (forçar saída de arquivo)
ms.date: 07/19/2019
f1_keywords:
- VC.Project.VCLinkerTool.ForceLink
- /force
helpviewer_keywords:
- FORCE linker option
- file output in linker
- /FORCE linker option
- -FORCE linker option
ms.assetid: b1e9a218-a5eb-4e60-a4a4-65b4be15e5da
ms.openlocfilehash: d1d85174290faa95e73c63a25f7d80c554e83ace
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079626"
---
# <a name="force-force-file-output"></a>/FORCE (forçar saída de arquivo)

```
/FORCE:[MULTIPLE|UNRESOLVED]
```

## <a name="remarks"></a>Comentários

A opção/FORCE informa o vinculador para criar um arquivo. exe válido ou DLL, mesmo que um símbolo seja referenciado, mas não definido ou seja definido de forma multiplicada.

A opção/FORCE pode usar um argumento opcional:

- Use/FORCE: MULTIPLE para criar um arquivo de saída se o LINK encontrar mais de uma definição para um símbolo.

- Use/FORCE: não resolvido para criar um arquivo de saída, independentemente de o LINK localizar um símbolo indefinido. /FORCE: não resolvido será ignorado se o símbolo de ponto de entrada não for resolvido.

/FORCE sem argumentos implica vários e não resolvidos.

Um arquivo criado com essa opção pode não ser executado conforme o esperado. O vinculador não será vinculado incrementalmente quando a opção/FORCE for especificada.

Se um módulo for compilado com **/CLR**, **/Force** não criará uma imagem.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Clique com o botão direito do mouse no projeto em **Gerenciador de soluções** e escolha **Propriedades**.

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção na caixa **Opções adicionais** .

Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
