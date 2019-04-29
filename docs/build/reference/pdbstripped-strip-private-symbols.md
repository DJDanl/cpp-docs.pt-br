---
title: /PDBSTRIPPED (remover símbolos privados)
ms.date: 11/04/2016
f1_keywords:
- /pdbstripped
- VC.Project.VCLinkerTool.StripPrivateSymbols
helpviewer_keywords:
- /PDBSTRIPPED linker option
- -PDBSTRIPPED linker option
- .pdb files, stripping private symbols
- PDB files, stripping private symbols
- PDBSTRIPPED linker option
ms.assetid: 9b9e0070-6a13-4142-8180-19c003fbbd55
ms.openlocfilehash: 3ed36eca727a15a3c70bc51a07cd3c143d7f66da
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320130"
---
# <a name="pdbstripped-strip-private-symbols"></a>/PDBSTRIPPED (remover símbolos privados)

```
/PDBSTRIPPED:pdb_file_name
```

## <a name="arguments"></a>Arguments

*pdb_file_name*<br/>
Um nome especificado pelo usuário para o banco de dados eliminados do programa (PDB) que o vinculador cria.

## <a name="remarks"></a>Comentários

A opção /PDBSTRIPPED cria um segundo arquivo de banco de dados (PDB) do programa quando você compila a imagem do programa com qualquer opção do compilador ou vinculador opções que geram um arquivo PDB ([/Debug](debug-generate-debug-info.md), [/Z7](z7-zi-zi-debug-information-format.md), /Zd, ou /Zi). Este segundo arquivo PDB omite os símbolos que você não desejaria enviar aos seus clientes. O segundo arquivo PDB conterá somente:

- Símbolos públicos

- A lista de arquivos de objeto e as partes do executável para o qual eles contribuem

- Registros de depuração do quadro ponteiro otimização (FPO) usados para percorrer a pilha

O arquivo PDB stripped não conterá:

- Informações de tipo

- Informações de número de linha

- Símbolos de CodeView de arquivo por objeto, como aqueles para funções, variáveis locais e dados estáticos

O arquivo PDB completo ainda será gerado quando você usa /PDBSTRIPPED.

Se você não criar um arquivo PDB, /PDBSTRIPPED será ignorado.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **depurar** página de propriedades.

1. Modificar a **segmentar símbolos privados** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StripPrivateSymbols%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
