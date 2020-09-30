---
title: /IDLOUT (nomear arquivos de saída MIDL)
ms.date: 11/04/2016
f1_keywords:
- /idlout
- VC.Project.VCLinkerTool.MergedIDLBaseFileName
helpviewer_keywords:
- MIDL, output file names
- .idl files, path
- MIDL
- /IDLOUT linker option
- IDL files, path
- -IDLOUT linker option
- IDLOUT linker option
ms.assetid: 10d00a6a-85b4-4de1-8732-e422c6931509
ms.openlocfilehash: 8dc26a0564a979c918d1eb1eb85e63e9c73caba0
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506925"
---
# <a name="idlout-name-midl-output-files"></a>/IDLOUT (nomear arquivos de saída MIDL)

```
/IDLOUT:[path\]filename
```

## <a name="parameters"></a>Parâmetros

*path*<br/>
Uma especificação de caminho absoluto ou relativo. Ao especificar um caminho, você afeta apenas o local de um arquivo. idl; todos os outros arquivos são colocados no diretório do projeto.

*nome do arquivo*<br/>
Especifica o nome do arquivo. idl criado pelo compilador MIDL. Nenhuma extensão de arquivo é assumida; Especifique *filename*. idl se você quiser uma extensão. idl.

## <a name="remarks"></a>Comentários

A opção/IDLOUT especifica o nome e a extensão do arquivo. idl.

O compilador MIDL é chamado pelo vinculador MSVC ao vincular projetos que têm o atributo [Module](../../windows/attributes/module-cpp.md) .

/IDLOUT também especifica os nomes de arquivo dos outros arquivos de saída associados ao compilador MIDL:

- *nome do arquivo*. tlb

- *nome de arquivo*_p. c

- *nome de arquivo*_i. c

- *nome do arquivo*. h

*filename* é o parâmetro que você passa para/IDLOUT. Se [/TLBOUT](tlbout-name-dot-tlb-file.md) for especificado, o arquivo. tlb receberá seu nome de/TLBOUT *filename*.

Se você especificar nem/IDLOUT nem/TLBOUT, o vinculador criará vc70. tlb, vc70. idl, vc70_p. c, vc70_i. c e vc70. h.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades **IDL inserida** .

1. Modifique a propriedade **nome do arquivo base IDL de mesclagem** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MergedIDLBaseFileName%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[/IGNOREIDL (não processar atributos no MIDL)](ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/MIDL (especifique as opções de linha de comando MIDL)](midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/attributes/cpp-attributes-com-net.md)
