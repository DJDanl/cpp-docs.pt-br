---
title: Páginas de propriedade da ferramenta geradora de documento XML
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCXDCMakeTool.ValidateIntelliSense
- VC.Project.VCXDCMakeTool.SuppressStartupBanner
- VC.Project.VCXDCMakeTool.DocumentLibraryDependencies
- VC.Project.VCXDCMakeTool.OutputDocumentFile
- VC.Project.VCXDCMakeTool.AdditionalDocumentFiles
ms.assetid: 645912b5-197a-4c36-ba58-64df09444ca0
ms.openlocfilehash: c99677d7fc53ae3343e15e54997fe0101322fbcf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316152"
---
# <a name="xml-document-generator-tool-property-pages"></a>Páginas de propriedade da ferramenta geradora de documento XML

A página de propriedades da Ferramenta de Gerador de Documento XML expõe a funcionalidade de xdcmake.exe. xdcmake.exe mescla arquivos .xdc em um arquivo .xml quando o código-fonte contém comentários da documentação e a opção [/doc (Processar Comentários da Documentação) (C/C++)](doc-process-documentation-comments-c-cpp.md) é especificada. Confira [Marcas recomendadas para comentários da documentação](recommended-tags-for-documentation-comments-visual-cpp.md) para obter informações sobre como adicionar comentários da documentação ao código-fonte.

> [!NOTE]
>  As opções de xdcmake.exe no ambiente de desenvolvimento (páginas de propriedades) são diferentes das opções exibidas quando xdcmake.exe é usado na linha de comando. Para obter informações sobre como usar xdcmake.exe na linha de comando, confira [Referência de XDCMake](xdcmake-reference.md).

## <a name="uielement-list"></a>Lista UIElement

- **Suprimir Faixa de Inicialização**

   Suprime uma mensagem de direitos autorais.

- **Arquivos de Documento Adicionais**

   Diretórios adicionais nos quais você deseja que o sistema de projeto procure arquivos .xdc. O xdcmake sempre procurará arquivos .xdc gerados pelo projeto. Podem ser especificados vários diretórios.

- **Arquivo de Documento de Saída**

   O nome e o local de diretório do arquivo de saída .xml. Ver [macros comuns para compilar comandos e propriedades](common-macros-for-build-commands-and-properties.md) para obter informações sobre como usar macros para especificar locais de diretório.

- **Dependências de biblioteca de documentos**

   Se o projeto tem uma dependência de um projeto .lib na solução, você pode processar arquivos .xdc do projeto .lib nos arquivos .xml do projeto atual.

## <a name="see-also"></a>Consulte também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)