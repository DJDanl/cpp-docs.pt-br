---
title: /WINMD (Gera metadados do Windows
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.GenerateWindowsMetadata
ms.assetid: bcfb4901-411e-4c9e-9f78-23028b6e5fcc
ms.openlocfilehash: 83d22a0114b26f53fa9df9d2470c71cd80465d64
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426674"
---
# <a name="winmd-generate-windows-metadata"></a>/WINMD (Gera metadados do Windows

Habilita a geração de um arquivo de metadados de tempo de execução do Windows (. winmd).

> **/WINMD**\[**:**{**NO**\|**ONLY**}]

## <a name="arguments"></a>Arguments

**/WINMD**<br/>
A configuração padrão para aplicativos da plataforma Universal do Windows. O vinculador gera o arquivo executável binário e o arquivo de metadados. winmd.

**/WINMD:NO**<br/>
O vinculador gera apenas o arquivo executável binário, mas não é um arquivo. winmd.

**/WINMD:ONLY**<br/>
O vinculador gera apenas o arquivo. winmd, mas não o arquivo executável binário.

## <a name="remarks"></a>Comentários

O **/WINMD** a opção de vinculador é usada para aplicativos UWP e componentes de tempo de execução do Windows para controlar a criação de um arquivo de metadados (. winmd) de tempo de execução do Windows. Um arquivo. winmd é um tipo de DLL que contém metadados para tipos de tempo de execução do Windows e, no caso de componentes de tempo de execução, as implementações desses tipos. Os metadados seguem a [ECMA-335](http://www.ecma-international.org/publications/standards/Ecma-335.htm) padrão.

Por padrão, o nome do arquivo de saída tem a forma *binaryname*. winmd. Para especificar um nome de arquivo diferente, use o [/WINMDFILE](../../build/reference/winmdfile-specify-winmd-file.md) opção.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **Windows metadados** página de propriedades.

1. No **gerar metadados do Windows** lista suspensa, selecione a opção desejada.

## <a name="see-also"></a>Consulte também

[Passo a passo: Criando um componente simples em tempo de execução do Windows e chamando-o por JavaScript](/windows/uwp/winrt-components/walkthrough-creating-a-simple-windows-runtime-component-and-calling-it-from-javascript)<br/>
[Introdução à linguagem de definição de Interface do Microsoft 3.0](/uwp/midl-3/intro)<br/>
[/WINMDFILE (especificar arquivo winmd)](winmdfile-specify-winmd-file.md)<br/>
[/WINMDKEYFILE (especificar arquivo de chave winmd)](winmdkeyfile-specify-winmd-key-file.md)<br/>
[/WINMDKEYCONTAINER (especificar contêiner de chave)](winmdkeycontainer-specify-key-container.md)<br/>
[/WINMDDELAYSIGN (assinar parcialmente um winmd)](winmddelaysign-partially-sign-a-winmd.md)<br/>
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
