---
title: Referência XDCMake
ms.date: 11/04/2016
f1_keywords:
- xdcmake
helpviewer_keywords:
- xdcmake program
ms.assetid: 14e65747-d000-4343-854b-8393bf01cbac
ms.openlocfilehash: 9970470d1feb471f9e0b8c9284a08337dac7ef0f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335852"
---
# <a name="xdcmake-reference"></a>Referência XDCMake

xdcmake.exe é um programa que compila arquivos .xdc em um arquivo .xml. Um arquivo .xdc é criado pelo compilador MSVC para cada arquivo de código fonte quando o código fonte é compilado com [/doc](doc-process-documentation-comments-c-cpp.md) e quando o arquivo de código fonte contém comentários de documentação marcados com tags XML.

### <a name="to-use-xdcmakeexe-in-the-visual-studio-development-environment"></a>Para usar xdcmake.exe no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a pasta **Propriedades de Configuração**.

1. Clique na página de propriedades de **Comentários de Documento XML**.

> [!NOTE]
> As opções de xdcmake.exe na linha de comando são diferentes das opções exibidas quando xdcmake.exe é usado no ambiente de desenvolvimento (páginas de propriedades). Para obter informações sobre como usar xdcmake.exe no ambiente de desenvolvimento, confira [Páginas de propriedades da Ferramenta de Gerador de Documento XML](xml-document-generator-tool-property-pages.md).

## <a name="syntax"></a>Sintaxe

xdcmake `input_filename options`

## <a name="parameters"></a>Parâmetros

*input_filename*<br/>
O nome dos arquivos .xdc usados como entrada para xdcmake.exe. Especifique um ou mais arquivos .xdc ou use *.xdc para usar todos os arquivos .xdc do diretório atual.

*Opções*<br/>
Nenhum ou mais dos seguintes:

|Opção|Descrição|
|------------|-----------------|
|/?, /help|Exibe a Ajuda de xdcmake.exe.|
|/assembly:*nome do arquivo*|Permite especificar o valor da marcação \<assembly> no arquivo .xml.  Por padrão, o valor da marcação \<assembly> é igual ao nome do arquivo .xml.|
|/nologo|Suprime uma mensagem de direitos autorais.|
|/out:*nome do arquivo*|Permite especificar o nome do arquivo .xml.  Por padrão, o nome do arquivo .xml é o nome do primeiro arquivo .xdc processado por xdcmake.exe.|

## <a name="remarks"></a>Comentários

O Visual Studio invocará xdcmake.exe automaticamente ao compilar um projeto. Você também pode invocar xdcmake.exe na linha de comando.

Confira [Marcas recomendadas para comentários da documentação](recommended-tags-for-documentation-comments-visual-cpp.md) para obter mais informações sobre como adicionar comentários da documentação a arquivos de código-fonte.

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
