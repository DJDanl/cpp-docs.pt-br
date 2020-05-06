---
title: /Fe (nomear arquivo EXE)
ms.date: 11/04/2016
f1_keywords:
- /fe
helpviewer_keywords:
- -Fe compiler option [C++]
- executable files, renaming
- rename file compiler option [C++]
- /Fe compiler option [C++]
- Fe compiler option [C++]
ms.assetid: 49f594fd-5e94-45fe-a1bf-7c9f2abb6437
ms.openlocfilehash: f0bd8f3a96555cc29d06f74fb44a73bbed32889b
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825572"
---
# <a name="fe-name-exe-file"></a>/Fe (nomear arquivo EXE)

Especifica um nome e um diretório para o arquivo. exe ou DLL criado pelo compilador.

## <a name="syntax"></a>Sintaxe

> **/FE**[_nome do caminho_] \
> **/Fe:** _nome de caminho_

### <a name="arguments"></a>Argumentos

*nome*<br/>
O caminho relativo ou absoluto e o nome do arquivo base, ou o caminho relativo ou absoluto para um diretório ou nome de arquivo base a ser usado para o executável gerado.

## <a name="remarks"></a>Comentários

A opção **/FE** permite que você especifique o diretório de saída, o nome do executável de saída ou ambos, para o arquivo executável gerado. Se *PathName* terminar em um separador de caminho (**&#92;**), será presumido especificar somente o diretório de saída. Caso contrário, o último componente do *PathName* é usado como o nome base do arquivo de saída e o restante do *caminho* especifica o diretório de saída. Se *PathName* não tiver nenhum separador de caminho, será presumido especificar o nome do arquivo de saída no diretório atual. O *nome do caminho* deve ser colocado entre aspas duplas (**"**) se contiver caracteres que não podem estar em um caminho curto, como espaços, caracteres estendidos ou componentes de caminho com mais de oito caracteres.

Quando a opção **/FE** não for especificada, ou quando um nome de base de arquivo não for especificado em *PathName*, o compilador fornecerá ao arquivo de saída um nome padrão usando o nome base do primeiro arquivo de origem ou objeto especificado na linha de comando e a extensão. exe ou. dll.

Se você especificar a opção [/c (compilar sem vinculação)](c-compile-without-linking.md) , **/FE** não terá nenhum efeito.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a página de propriedade**geral** do**vinculador** > de **Propriedades** > de configuração.

1. Modifique a propriedade do **arquivo de saída** . Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.

## <a name="example"></a>Exemplo

A linha de comando a seguir compila e vincula todos os arquivos de origem do C no diretório atual. O arquivo executável resultante é chamado PROCESS. exe e é criado no diretório "C:\Users\User Name\repos\My Project\bin".

```
CL /Fe"C:\Users\User Name\repos\My Project\bin\PROCESS" *.C
```

## <a name="example"></a>Exemplo

A linha de comando a seguir cria um arquivo `C:\BIN` executável no com o mesmo nome base do primeiro arquivo de origem no diretório atual:

```
CL /FeC:\BIN\ *.C
```

## <a name="see-also"></a>Confira também

[Opções de arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)<br/>
