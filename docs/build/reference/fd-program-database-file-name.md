---
title: /Fd (nome do arquivo de banco de dados do programa)
ms.date: 11/04/2016
f1_keywords:
- /FD
- VC.Project.VCCLWCECompilerTool.ProgramDataBaseFileName
- VC.Project.VCCLCompilerTool.ProgramDataBaseFileName
helpviewer_keywords:
- /FD compiler option [C++]
- program database file name [C++]
- -FD compiler option [C++]
- PDB files, creating
- program database compiler option [C++]
- .pdb files, creating
- FD compiler option [C++]
ms.assetid: 3977a9ed-f0ac-45df-bf06-01cedd2ba85a
ms.openlocfilehash: 2c64a4ec0d7799d7bad698808e959d11e87cdc85
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422436"
---
# <a name="fd-program-database-file-name"></a>/Fd (nome do arquivo de banco de dados do programa)

Especifica um nome de arquivo para o arquivo de banco de dados (PDB) do programa criado pelo [/Z7, /Zi, /ZI (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md).

## <a name="syntax"></a>Sintaxe

```
/Fdpathname
```

## <a name="remarks"></a>Comentários

Sem **/Fd**, o nome do arquivo PDB assume como padrão VC*x*0.pdb, onde *x* é a versão principal do Visual C++ em uso.

Se você especificar um nome de caminho que não inclua um nome de arquivo (o caminho termina em barra invertida), o compilador cria um arquivo. PDB chamado VC*x*0. pdb no diretório especificado.

Se você especificar um nome de arquivo que não inclui uma extensão, o compilador usa o. PDB como a extensão.

Essa opção também nomeia o arquivo de estado (. IDB) usado para recompilação mínima e a compilação incremental.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **arquivos de saída** página de propriedades.

1. Modificar a **nome do arquivo de banco de dados de programa** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ProgramDataBaseFileName%2A>.

## <a name="example"></a>Exemplo

Essa linha de comando cria um arquivo. PDB chamado PROG.pdb e um arquivo. IDB chamado PROG.idb:

```
CL /DDEBUG /Zi /FdPROG.PDB PROG.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)
