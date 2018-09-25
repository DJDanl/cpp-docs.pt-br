---
title: Referência de XDCMake | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- xdcmake
dev_langs:
- C++
helpviewer_keywords:
- xdcmake program
ms.assetid: 14e65747-d000-4343-854b-8393bf01cbac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1596722fc5db1c0de183b30bd5d60235cc1665fa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414791"
---
# <a name="xdcmake-reference"></a>Referência XDCMake

xdcmake.exe é um programa que compila arquivos .xdc em um arquivo .xml. Um arquivo .xdc é criado pelo compilador do Visual C++ para cada arquivo de código-fonte quando o código-fonte é compilado com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) e quando o arquivo de código-fonte contém comentários da documentação marcados com marcas XML.

### <a name="to-use-xdcmakeexe-in-the-visual-studio-development-environment"></a>Para usar xdcmake.exe no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

1. Abra a pasta **Propriedades de Configuração**.

1. Clique na página de propriedades de **Comentários de Documento XML**.

> [!NOTE]
>  As opções de xdcmake.exe na linha de comando são diferentes das opções exibidas quando xdcmake.exe é usado no ambiente de desenvolvimento (páginas de propriedades). Para obter informações sobre como usar xdcmake.exe no ambiente de desenvolvimento, confira [Páginas de propriedades da Ferramenta de Gerador de Documento XML](../ide/xml-document-generator-tool-property-pages.md).

## <a name="syntax"></a>Sintaxe

xdcmake `input_filename options`

## <a name="parameters"></a>Parâmetros

*input_filename*<br/>
O nome dos arquivos .xdc usados como entrada para xdcmake.exe. Especifique um ou mais arquivos .xdc ou use *.xdc para usar todos os arquivos .xdc do diretório atual.

*options*<br/>
Nenhum ou mais dos seguintes:

|Opção|Descrição|
|------------|-----------------|
|/?, /help|Exibe a Ajuda de xdcmake.exe.|
|/assembly:*nome do arquivo*|Permite especificar o valor da marcação \<assembly> no arquivo .xml.  Por padrão, o valor da marcação \<assembly> é igual ao nome do arquivo .xml.|
|/nologo|Suprime uma mensagem de direitos autorais.|
|/out:*nome do arquivo*|Permite especificar o nome do arquivo .xml.  Por padrão, o nome do arquivo .xml é o nome do primeiro arquivo .xdc processado por xdcmake.exe.|

## <a name="remarks"></a>Comentários

O Visual Studio invocará xdcmake.exe automaticamente ao compilar um projeto. Você também pode invocar xdcmake.exe na linha de comando.

Confira [Marcas recomendadas para comentários da documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md) para obter mais informações sobre como adicionar comentários da documentação a arquivos de código-fonte.

## <a name="see-also"></a>Consulte também

[Documentação XML](../ide/xml-documentation-visual-cpp.md)